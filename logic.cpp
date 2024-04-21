#include "logic.h"
#include <QDebug>

#include <fstream>  // Included for file handling operations
#include <cctype>   // Included for isdigit()
#include <random>   // Included for generating a random number


/**
* Populates the odd and even containers with movie names from the file
*/
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

    // If the input from the user is odd and the odd container is non-empty
    if (number % 2 && !this->oddContainer.empty()) {
        randomizeMovie(this->oddContainer);
    }

    // If the input from the user is even and the even container is non-empty
    else if (!(number % 2) && !this->evenContainer.empty()) {
        randomizeMovie(this->evenContainer);
    }

    // If the input from the user is even, but the even container is empty and odd container is not empty
    else if (!this->oddContainer.empty()) {
        randomizeMovie(this->oddContainer);
    }

    // If the input from the user is odd, but the odd container is empty and even container is not empty
    else if (!this->evenContainer.empty()) {
        randomizeMovie(this->evenContainer);
    }

    // If both containers are empty
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
    // Open the input file containing the movies
    std::ifstream fin("test.txt");

    std::string line;
    int pos = 1;

    // While the end of the file is not reached
    while (std::getline(fin, line)) {
        // If the pointer is odd
        if (pos % 2 ) {
            this->oddContainer.push_back(line); // Add the movie to the odd container
        }

        else {
            this->evenContainer.push_back(line); // Add the movie to the even container
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

    // Generate random number within the bounds of the container
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(0, container.size() - 1);
    int randomNumber = dis(gen);

    // Get a random movie from the container
    QString str = QString::fromUtf8(container[randomNumber].c_str());

    // Set the value of output with the random movie
    this->setOutput(str);

    // Remove the random movie from the container
    std::string temp = container[upperBound - 1];
    container[randomNumber] = temp;
    container.pop_back();

}
