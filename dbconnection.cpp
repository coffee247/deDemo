#include "dbconnection.h"

dbconnection::dbconnection(QString driver, QObject *parent) : QObject(parent)
{

    QString fileToOpen = ":/includes/configs/dbconfig.json";
    QFile jsonConfigFile(fileToOpen);

    QSqlDatabase db = QSqlDatabase::addDatabase(driver);
    this->conn = db;

    // Attempt to open dbconfig.json
    try{
    if (!jsonConfigFile.open(QIODevice::ReadOnly)){
        MyError * cErr = new MyError(this);
        cErr->SetMessage("Failed to open dbconfig.json (mainwindow.cpp)");
        throw cErr;
    }
    else {
        qDebug() << "dbconfig.json did open";
         QByteArray dbConfigData = jsonConfigFile.readAll();

         QJsonDocument loadDoc(QJsonDocument::fromJson(dbConfigData));
         db.setPort(loadDoc.object().value("db_Port").toDouble());
         db.setHostName(loadDoc.object().value("db_Host").toString());
         db.setUserName(loadDoc.object().value("db_root_User").toString());
         db.setDatabaseName(loadDoc.object().value("db_Name").toString());
         db.setPassword(loadDoc.object().value("db_root_PWD").toString());


    }
    }
    // Catch errors if dbconfig fails to open
    catch(MyError *theError){
        qDebug() << theError->Message();
        delete theError;
    }
    catch(...){
        qDebug() << "An unknown error occurred while attempting to open dbconfig.json";
    }


}
