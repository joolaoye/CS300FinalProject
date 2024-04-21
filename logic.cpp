#include "logic.h"
#include <QDebug>

#include <fstream>
#include <cctype>

Logic::Logic(QObject *parent)
    : QObject{parent}, placeholder("null")
{
    this->initialize();
}

QString Logic::output()
{
    return placeholder;
}

void Logic::callMe()
{
    qDebug() << "Called";
}

bool Logic::isNumber(QString input)
{
    for (char letter : input.toStdString()) {
        if (!isdigit(letter)) {
            return false;
        }
    }

    return true;
}

void Logic::initialize()
{

    std::ifstream fin("test.txt");

    std::string line;
    int pos = 1;


    while (std::getline(fin, line)) {
        if (pos % 2 ) {
            oddContainer.push_back(line);
        }

        else {
            evenContainer.push_back(line);
        }

        pos++;
    }

    fin.close();
}

void Logic::setOutput(QString string)
{
    placeholder = string;
    emit outputChanged();
}
