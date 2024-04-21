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
    void generateRandomMovie( QString );
    bool isNumber( QString );

private slots:
    void initialize();
    void setOutput( QString );
    void randomizeMovie( std::vector<std::string>& );

private:
    QString placeholder;
    std::vector<std::string> oddContainer;
    std::vector<std::string> evenContainer;
};

#endif // LOGIC_H
