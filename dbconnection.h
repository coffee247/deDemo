#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QObject>
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QFile>
#include "myerror.h"
#include <QJsonObject>
#include <QJsonDocument>

class dbconnection : public QObject
{
    Q_OBJECT
public:
    explicit dbconnection(QString driver, QObject *parent = nullptr);
    QSqlDatabase conn;

signals:

};

#endif // DBCONNECTION_H
