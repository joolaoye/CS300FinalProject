#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>
#include <QtQml>
#include <QDebug>

#include <string>
#include <vector>

class Logic : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString output READ output WRITE setOutput NOTIFY outputChanged FINAL)
public:
    explicit Logic(QObject *parent = nullptr);
    QString output();
signals:
    void outputChanged();
public slots:
    void callMe();
    bool isNumber( QString );
    void setOutput( QString );

private slots:
    void initialize();

private:
    QString placeholder;
    std::vector<std::string> oddContainer;
    std::vector<std::string> evenContainer;
};

#endif // LOGIC_H
