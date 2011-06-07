#ifndef NETWORKCOLOR_H
#define NETWORKCOLOR_H
#include <QDataStream>


/*
 * Dummy for saving them at the server
 */
class QColor {
public:
    inline QColor() {}
    inline QColor(const QString &aname) {
        setFromString(aname);
    }

    inline QColor(const char *aname) {
        setFromString(QString(aname));
    }

    QColor(Qt::GlobalColor);

    QString name() const;

private:

    void setFromString(const QString &);

    qint8 color_spec;
    quint16 alpha_value;
    quint16 red_value;
    quint16 green_value;
    quint16 blue_value;
    quint16 pad_value;

    friend QDataStream &operator<<(QDataStream &, const QColor &);
    friend QDataStream &operator>>(QDataStream &, QColor &);

};

#endif
