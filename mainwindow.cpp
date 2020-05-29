#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbconnection.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    /*!
     * \brief myconn
     */
    dbconnection *myconn = new dbconnection("QPSQL");


    if (!myconn->conn.open()){
            qDebug() << "fail";
    }
    else {
        qDebug() << "success" << myconn->conn.hostName();

    }

    /*!
     * \brief quitAction Defines behavior for responding to user desire to "Quit"
     */
    QAction * quitAction = new QAction("Quit");
    connect(quitAction,&QAction::triggered,[=](){
        myconn->conn.close();  // close the database connection
        QApplication::quit();  // terminate the Application entirely
    });

    /*!
     * \brief fileMenu adds a "File" menu to menubar
     */
    QMenu * fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(quitAction); // add quitAction to file menu

}

MainWindow::~MainWindow()
{
    delete ui;
}

