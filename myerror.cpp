#include "myerror.h"


/*!
 * \brief MyError::MyError default constructor for creating MyError instances
 * \param parent the object that created the instance
 */
MyError::MyError(QObject *parent) : QObject(parent)
{
}

/*!
 * \brief MyError::Message a method to get the error message stored in an instance of MyError
 * \return mMessage a QString value
 */
QString MyError::Message()
{
    return mMessage;
}

/*!
 * \brief MyError::SetMessage  a method to set the error message for an instance of MyError
 * \param Msg the message value
 */
void MyError::SetMessage(QString Msg)
{
    this->mMessage = Msg;
}
