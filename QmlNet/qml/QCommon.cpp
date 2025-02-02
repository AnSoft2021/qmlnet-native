#include <QmlNet/qml/QCommon.h>
#include <QFontDatabase>
#include <QtGlobal>
#include <QString>
#include <QmlNetUtilities.h>

extern "C" {

Q_DECL_EXPORT uchar qt_putenv(const char* name, const char* value)
{
    if(value == nullptr) {
        if(qunsetenv(name)) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if(qputenv(name, value)) {
            return 1;
        } else {
            return 0;
        }
    }
}

Q_DECL_EXPORT QmlNetStringContainer* qt_getenv(const char* name)
{
    QByteArray result = qgetenv(name);
    if(result.isNull()) {
        return nullptr;
    }
    QString string = QString(result);
    return createString(string);
}

Q_DECL_EXPORT QmlNetStringContainer* qt_version() {
    QString version(qVersion());
    return createString(version);
}

Q_DECL_EXPORT int qt_addApplicationFont(const char *name)
{
    return QFontDatabase::addApplicationFont(name);
}

}
