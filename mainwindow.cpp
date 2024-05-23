#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene( );
    ui->graphicsView->setScene(scene);
    QPixmap img("C:/Users/juanj/Desktop/Proyecto Final/Images/carnet.png");
    ui->carnet->setPixmap(img);
    //QPixmap img2("C:/Users/juanj/Desktop/Proyecto Final/Images/sopa.png");
    //ui->eat->icon( ).addPixmap(img2);
    prot = new Player( );
    ui->totalsopa->setText(QChar(prot->sopa + 48));
    scene->addItem(prot->jugador);
    BackGround( );                                      //Configuramos el fondo del escenario

    walls = new Obstacles( );
    Passengers( );

    connect(prot->energCons, SIGNAL(timeout()),this,SLOT(TiredInt( )));
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
        prot->energCons->start(1000);
        qDebug( ) << "Empezo!";
    }
}


void MainWindow::on_eat_released( )
{
    if(prot->sopa > 0){
        prot->Eat( );
        ActBars( );
    }else ui->messages->setText("No tienes mas sopita disponible!");

    if(prot->energia > 60 && (prot ->energCons->isActive( ))) prot->energCons->stop( );
}

