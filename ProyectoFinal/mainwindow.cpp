#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene( );
    ui->graphicsView->setScene(scene);
    prot = new Player( );
    scene->addItem(prot->jugador);
    BackGround( );                                      //Configuramos el fondo del escenario

    walls = new Obstacles( );
    Passengers( );
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

void MainWindow :: keyPressEvent(QKeyEvent *event){
    prot->keyPressEvent(event,1);
    if(Impact(prot->jugador)) prot->keyPressEvent(event,-1);            //Si el jugador impacta con algun obstaculo retrocede el paso dado
}

