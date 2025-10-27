#include <iostream>
#include <cmath>
#include "FantasyBack.h"
#include <fstream>
#include <map>
#include <sstream>
#include <string>


// Function implementations

void welcomeMessage()
{
    std::cout << "Hello! Welcome. " << std::endl;
}

int checkGamesPlayed(double pointsArr[6])
{
    int gamesPlayed = 0;    //starts at 0

    for (int i = 0; i < 6; i++)
    {
        if (pointsArr[i] != missed)
        {
            gamesPlayed++;      // counts all the games played
        }
    }

    return gamesPlayed;
}

double calculateAverage(double pointsArr[6])
{
    double averagePoints = 0.0;
    double totalPoints = 0.0;
    int gamesPlayed = checkGamesPlayed(pointsArr); // assigns gamesPlayed the value that the function "checkGamesPlayed" returned
    for (int i = 0; i < 6; i++)
    {
        if (pointsArr[i] != missed)
        {
            totalPoints = totalPoints + pointsArr[i];
        }
    }

    if (gamesPlayed == 0)
    {
        return 0.0;
    }

    averagePoints = totalPoints / gamesPlayed;

    return averagePoints;    // calculated average
}

double sumPoints(double pointsArr[6])
{
    double totalPoints = 0;
    for (int i = 0; i < 6; i++)
    {
        if (pointsArr[i] != missed)
        {
            totalPoints = totalPoints + pointsArr[i];
        }
    }

    return totalPoints;
}

double roundOff(double value, int places)
{
    return round(value * pow(10.0, places)) / pow(10.0, places);
}




// Main function
int main()
{
    // declare player structs
    Player playerA;
    Player playerB;


    // declared map players
    std::map<std::string, std::string>people;

    //open playersData.txt and read everything into infile
    std::ifstream infile("playerData.txt");


    std::string fileLine;

    if (!infile) {
        std::cout << "File is not open!";
    }
    else {
        while (std::getline(infile, fileLine)) {
            std::stringstream ss(fileLine);     // declaring the string stream (NOTHING HAPPENING YET)
            std::string playerName;
            std::string playerScore;


            if (std::getline(ss, playerName, ',') && std::getline(ss, playerScore)) {
                people[playerName] = playerScore;


            }
        }
        infile.close();
    }


    std::ofstream outfile("playerData.txt", std::ios::app);

    welcomeMessage();       // welcome message



    // get player A info

    std::cout << "Enter Player A: ";
    std::getline(std::cin, playerA.name);

    if (people.count(playerA.name) == 0) {
        std::cout << playerA.name <<  " is not in Database!" << std::endl;
        std::cout << "Enter Player A points week 1 - 6, if missed game, input x " << std::endl;

        std::string scoreCollector;
        scoreCollector = "";

        for (int i = 0; i < 6; i++) {
            std::cout << "Week " << (i + 1) << ": ";
            std::string line;

            std::getline(std::cin, line);
            scoreCollector += line + " ";         // adds line of every week to scoreCollector

            if (line == "x") {
                playerA.pointsArr[i] = missed;
            }
            else {
                playerA.pointsArr[i] = std::stod(line);
                // line is turned from a str to a double and stored into array
            }
        }
        outfile << playerA.name << "," << scoreCollector << std::endl;      // name , score endl
        people[playerA.name] = scoreCollector;

    }
    else if (people.count(playerA.name) == 1) {
        int counter = -1;

        std::cout << playerA.name << " was found! " << std::endl;

        std::stringstream ss(people[playerA.name]);

        std::string tempScore;
        double totalScore = 0;

        while (ss >> tempScore) {
            // ss reads from map and stores into tempScore
            counter++;
            if (tempScore == "x") {
                playerA.pointsArr[counter] = missed;
            }
            else {

                playerA.pointsArr[counter] = std::stod(tempScore);
            }
        }
    }
    else {
         std::cout << "ERROR" << std::endl;
    }

    // for (int i = 0; i < 6; i++)
    // {
    //     std::cout << "Week " << (i + 1) << ": ";
    //
    //     std::string line;                   // line is the string of the value inputted
    //     std::getline(std::cin, line);
    //     if (line == "x")
    //     {
    //         playerA.pointsArr[i] = missed;          // marks which week was missed
    //     }
    //     else
    //     {
    //         playerA.pointsArr[i] = std::stod(line);     // converts values(strings) into doubles
    //     }
    // }


    // Get Player B info

    std::cout << "Enter Player B: ";
    std::getline(std::cin, playerB.name);


    if (people.count(playerB.name) == 0) {
        std::cout << playerB.name << " is not in Database!" << std::endl;
        std::cout << "Enter Player B points week 1 - 6, if missed game, input x " << std::endl;

        std::string scoreCollector;
        scoreCollector = "";

        for (int i = 0; i < 6; i++) {
            std::cout << "Week " << (i + 1) << ": ";
            std::string line;

            std::getline(std::cin, line);
            scoreCollector += line + " ";         // adds line of every week to scoreCollector

            if (line == "x") {
                playerB.pointsArr[i] = missed;
            }
            else {
                playerB.pointsArr[i] = std::stod(line);
                // line is turned from a str to a double and stored into array
            }
        }
        outfile << playerB.name << "," << scoreCollector << std::endl;      // name , score endl
        people[playerB.name] = scoreCollector;

    }
    else if (people.count(playerB.name) == 1) {
        int counter = -1;

        std::cout << playerB.name << " was found! " << std::endl;

        std::stringstream ss(people[playerB.name]);

        std::string tempScore;
        double totalScore = 0;

        while (ss >> tempScore) {
            // ss reads from map and stores into tempScore
            counter++;
            if (tempScore == "x") {
                playerB.pointsArr[counter] = missed;
            }
            else {

                playerB.pointsArr[counter] = std::stod(tempScore);
            }
        }
    }
    else {
        std::cout << "ERROR" << std::endl;
    }





    playerA.averagePoints = calculateAverage(playerA.pointsArr);
    playerB.averagePoints = calculateAverage(playerB.pointsArr);

    playerA.totalPoints = sumPoints(playerA.pointsArr);
    playerB.totalPoints = sumPoints(playerB.pointsArr);

    std::cout << "\nTotal Points: " << std::endl;
    std::cout << playerA.name << ": " << roundOff(playerA.totalPoints, 2) << std::endl;
    std::cout << playerB.name << ": " << roundOff(playerB.totalPoints, 2) << std::endl;

    std::cout << "\nAverage Points: " << std::endl;
    std::cout << playerA.name << ": " << roundOff(playerA.averagePoints, 2) << std::endl;
    std::cout << playerB.name << ": " << roundOff(playerB.averagePoints, 2) << std::endl;

    if (playerA.averagePoints > playerB.averagePoints)
    {
        std::cout << "You should start " << playerA.name;
    }
    else if (playerA.averagePoints < playerB.averagePoints)
    {
        std::cout << "You should start " << playerB.name;
    }
    else
    {
        std::cout << "Start whichever";
    }

    return 0;
}