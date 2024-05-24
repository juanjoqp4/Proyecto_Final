#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene( );
    traveltime = new QTimer( );
    travelstop = new QTimer( );

    ui->graphicsView->setScene(scene);
    QPixmap img("C:/Users/juanj/Desktop/Proyecto Final/Images/carnet.png");
    ui->carnet->setPixmap(img);

    prot = new Player( );
    ui->totalsopa->setText(QChar(prot->sopa + 48));
    scene->addItem(prot->jugador);
    BackGround( );                                      //Configuramos el fondo del escenario

    walls = new Obstacles( );
    for(int i = 0; i < walls->chairs.length( ); i++) scene->addItem(walls->chairs[i]);
    Passengers( );

    ui->ActualStation->setText("Estacion: " + stations[actStation]);
    ui->NextStation->setText("Proxima Estacion: " + stations[actStation + 1]);

    travelstop->start(10000);
    connect(prot->energCons, SIGNAL(timeout()),this,SLOT(TiredInt( )));
    connect(travelstop, SIGNAL(timeout()),this,SLOT(Travel( )));
    connect(traveltime, SIGNAL(timeout()),this,SLOT(Board( )));
}

MainWindow::~MainWindow( )
{
    delete ui;
}

void MainWindow::BackGround( )
{
    QImage img("C:/Users/juanj/Desktop/Proyecto Final/Images/fondo.png");
    QBrush fondo(img);
    ui->graphicsView->setGeometry(-15,-5,540,620);
    ui->graphicsView->setSceneRect(0,0,999, 999);
    ui->graphicsView->scale(0.5,0.6);
    ui->graphicsView->setBackgroundBrush(fondo);

    stations = {"La Estrella", "Sabaneta", "Itagüi", "Envigado", "Ayurá", "Aguacatala", "Poblado", "Industriales"};
}

void MainWindow::Passengers( )
{

}

bool MainWindow::Impact(QGraphicsPixmapItem *person)
{
    if(person->pos( ).x( ) + 15 > 755) return true;
    if(person->pos( ).x( ) + 15 < 150) return true;
    if(person->pos( ).y( ) + 15 > 800) return true;
    if(person->pos( ).y( ) + 15 < 140) return true;

    for(int i = 0; i < walls->chairs.length( ); i++){
        if(person->collidesWithItem(walls->chairs.at(i))){
            //qDebug( ) << walls->chairs.at(i);
            return true;
        }
    }

    for(int i = 0; i < walls->passengers.length( ); i++){
        if(person->collidesWithItem(walls->passengers.at(i))){
            //qDebug( ) << walls->chairs.at(i);
            return true;
        }
    }
    return false;
}

void MainWindow::ActBars()
{
    ui->EnergyBar->setValue(prot->energia);
    ui->HamBar->setValue(prot->hambre);
    ui->EstresBar->setValue(prot->estres);
    ui->CivismBar->setValue(prot->civismo);
    ui->totalsopa->setText(QChar(prot->sopa + 48));
    ui->moneyled->display(prot->dinero);
}

void MainWindow::Travel()
{
    travelstop->stop();
    traveltime->start(15000);
    sell = false;
    QIcon icon("C:/Users/juanj/Desktop/Proyecto Final/Images/x.png");
    ui->buysopa->setIcon(icon);

    // Actualizar la estación actual
    if (direction == 1 && actStation < stations.length() - 1) {
        actStation++;
    } else if (direction == 0 && actStation > 0) {
        actStation--;
    }

    // Cambiar la dirección si se llega a los extremos
    if (actStation == stations.length() - 1) {
        direction = 0;
    } else if (actStation == 0) {
        direction = 1;
        day++;
    }

    ui->ActualStation->setText("Estacion: En recorrido...");
    //ui->NextStation->setText("Proxima Estacion: " + stations[actStation + (direction == 1 ? 1 : -1)]);
}

void MainWindow::Board()
{
    ui->numbofdays->display(day);
    traveltime->stop();
    travelstop->start(5000);
    sell = true;
    QIcon icon("C:/Users/juanj/Desktop/Proyecto Final/Images/sopa.png");

    ui->buysopa->setIcon(icon);
    ui->ActualStation->setText("Estacion: " + stations[actStation]);

    // Ajustar la próxima estación
    int nextStationIndex = actStation + (direction == 1 ? 1 : -1);
    if (nextStationIndex >= 0 && nextStationIndex < stations.length()) {
        ui->NextStation->setText("Proxima Estacion: " + stations[nextStationIndex]);
    } else {
        ui->NextStation->setText("Proxima Estacion: N/A");
    }
}


void MainWindow::TiredInt()
{
    prot->Tired( );
    ActBars( );
}

void MainWindow :: keyPressEvent(QKeyEvent *event){
    if(prot->energia > 0){
        prot->keyPressEvent(event,1);
        ui->EnergyBar->setValue(prot->energia);
        if(Impact(prot->jugador)) prot->keyPressEvent(event,-1);            //Si el jugador impacta con algun obstaculo retrocede el paso dado
    }else if(prot->energia == 0) ui->messages->setText("Tomese la sopita mijo!");

    if(prot->energia < 60 && (prot->energCons->isActive( ) == false)){
        prot->energCons->start(1500);
        //qDebug( ) << "Empezo!";
    }
}


void MainWindow::on_eat_released( )
{
    if(prot->sopa > 0){
        prot->Eat( );
        ActBars( );
    }else{
        ui->messages->setText("No tienes mas sopita disponible!");
    }
    if(prot->energia > 60 && (prot ->energCons->isActive( ))) prot->energCons->stop( );
}


void MainWindow::on_buysopa_released()
{
    if(sell == true){
        if(prot->sopa < 5){
            prot->Buy( );
            ActBars( );
        }else ui->messages->setText("Mucha sopita!");
    }else ui->messages->setText("No puedes comprar!");
}

