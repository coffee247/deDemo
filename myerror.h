#ifndef MYERROR_H
#define MYERROR_H

#include <QObject>
#include <QString>

class MyError : public QObject
{
    Q_OBJECT
public:
    explicit MyError(QObject *parent = nullptr);
    QString Message();
    void SetMessage(QString Msg);

signals:

protected:
    QString mMessage;

};

#endif // MYERROR_H
