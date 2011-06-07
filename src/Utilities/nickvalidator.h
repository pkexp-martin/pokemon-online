#ifndef OTHERWIDGETS_H
#define OTHERWIDGETS_H

#include <QObject>

class QValidator : public QObject
{
    Q_OBJECT
public:
    QValidator(QObject *parent);

    enum State { Invalid, Intermediate, Acceptable };

};

/* validator for the nicks */
class QNickValidator : public QValidator
{
    Q_OBJECT
public:
    QNickValidator(QObject *parent);

    bool isBegEndChar(QChar ch) const;
    void fixup(QString &input) const;
    State validate(QString &input, int &pos) const;
    State validate(const QString &input) const;
};

#endif // OTHERWIDGETS_H
