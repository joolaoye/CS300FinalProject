#include "logic.h"
#include <QDebug>

#include <fstream>
#include <cctype>
#include <random>


Logic::Logic(QObject *parent)
    : QObject{parent}, placeholder("null")
{
    this->initialize();
}

QString Logic::output()
{
    return this->placeholder;
}

void Logic::generateRandomMovie(QString input)
{
    int number = input.toInt();

    if (number % 2 && !this->oddContainer.empty()) {
        randomizeMovie(this->oddContainer);
    }

    else if (!(number % 2) && !this->evenContainer.empty()) {
        randomizeMovie(this->evenContainer);
    }

    else if (!this->oddContainer.empty()) {
        randomizeMovie(this->oddContainer);
    }

    else if (!this->evenContainer.empty()) {
        randomizeMovie(this->evenContainer);
    }

    else {
        this->setOutput("No other available films”");
    }
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
            this->oddContainer.push_back(line);
        }

        else {
            this->evenContainer.push_back(line);
        }

        pos++;
    }

    fin.close();
}

void Logic::setOutput(QString string)
{
    this->placeholder = string;
    emit this->outputChanged();
}

void Logic::randomizeMovie(std::vector<std::string>& container)
{
    int upperBound = container.size();

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(0, container.size() - 1);
    int randomNumber = dis(gen);

    qDebug() << randomNumber;

    QString str = QString::fromUtf8(container[randomNumber].c_str());

    this->setOutput(str);

    std::string temp = container[upperBound - 1];
    container[randomNumber] = temp;

    container.pop_back();

}
