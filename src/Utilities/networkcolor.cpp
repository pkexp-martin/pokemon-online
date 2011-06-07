#include "networkcolor.h"

QColor::QColor(Qt::GlobalColor color)
{
    static const unsigned short global_colors[] = {
       255, 255, 255,
       0,   0,   0,
       0,   0,   0,
       255, 255, 255,
       128, 128, 128,
       160, 160, 164,
       192, 192, 192,
       255,   0,   0,
         0, 255,   0,
         0,   0, 255,
         0, 255, 255,
       255,   0, 255,
       255, 255,   0,
       128,   0,   0,
         0, 128,   0,
         0,   0, 128,
         0, 128, 128,
       128,   0, 128,
       128, 128,   0,
         0,   0,   0
    };
    alpha_value = 255 *0x101;
    red_value = (color*3) * 0x101;
    blue_value = (color*3+1) * 0x101;
    green_value = (color*3+2) * 0x101;
}


QString QColor::name() const
{
    QString s;
    s.sprintf("#%02x%02x%02x", red_value, green_value, blue_value);
    return s;
}

void QColor::setFromString(const QString &s)
{
    if (s[0] == QChar('#')) {
        alpha_value = 255;
	red_value = s.mid(1,2).toInt(0, 16);
	green_value = s.mid(3,2).toInt(0, 16);
	blue_value = s.mid(5,2).toInt(0, 16);
    }
}
	

QDataStream & operator<< (QDataStream & stream, const QColor & c)
{
    stream << c.color_spec << c.alpha_value << c.red_value 
        << c.green_value << c.blue_value << c.pad_value;
    return stream;
}
QDataStream & operator>> (QDataStream & stream, QColor & c)
{
    stream >> c.color_spec >> c.alpha_value >> c.red_value 
        >> c.green_value >> c.blue_value >> c.pad_value;
    return stream;
}
