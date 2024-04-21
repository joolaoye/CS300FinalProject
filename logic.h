// Header for the logic (Backend)

#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>
#include <QtQml>

#include <string>   // Included for C++ Strings
#include <vector>   // Included for vector

class Logic : public QObject
{
    Q_OBJECT

    // output string to display the surprise movie
    Q_PROPERTY(QString output READ output WRITE setOutput NOTIFY outputChanged FINAL)
public:
    explicit Logic(QObject *parent = nullptr);

    /**
     * Retrieves the value of output
    */
    QString output();
signals:
    /**
     * Notifies output when placeholder is updayted
    */
    void outputChanged();
public slots:
    /**
     * Generates a random movie from either the odd or even container
     * depending on the input number
     * @param input The user entry
    */
    void generateRandomMovie( QString );

    /**
     * Checks if a string is a number
     * @param input The user entry
    */
    bool isNumber( QString );

private slots:
    /**
     * Loads in the file with movie names and populates both
     * even and odd containers with the movie name
    */
    void initialize();

    /**
     * Sets the value of the output
     * @param string A movie name to be displayed
    */
    void setOutput( QString );

    /**
     * Sets the value of output to a randomly generated movie from the input container
     * @param container Either the odd or even containers containing movies
    */
    void randomizeMovie( std::vector<std::string>& );

private:
    QString placeholder;
    std::vector<std::string> oddContainer;
    std::vector<std::string> evenContainer;
};

#endif // LOGIC_H
