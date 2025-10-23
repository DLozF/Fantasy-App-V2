#include <iostream>
#include <cmath>
#include "FantasyBack.h"
#include <fstream>


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

    welcomeMessage();

    // get player A info2
    std::cout << "Enter Player A: ";
    std::getline(std::cin, playerA.name);
    std::cout << "\nEnter points for Player A from Week 1 - 6, if injured input x " << std::endl;

    for (int i = 0; i < 6; i++)
    {
        std::cout << "Week " << (i + 1) << ": ";

        std::string line;                   // line is the string of the value inputted
        std::getline(std::cin, line);
        if (line == "x")
        {
            playerA.pointsArr[i] = missed;          // marks which week was missed
        }
        else
        {
            playerA.pointsArr[i] = std::stod(line);     // converts values(strings) into doubles
        }
    }

    // get Player B info
    std::cout << "\nEnter Player B: ";
    std::getline(std::cin, playerB.name);
    std::cout << "\nEnter points for Player B from Week 1 - 6, if injured input x " << std::endl;

    for (int i = 0; i < 6; i++)
    {
        std::cout << "Week " << (i + 1) << ": ";

        std::string line;
        std::getline(std::cin, line);
        if (line == "x")
        {
            playerB.pointsArr[i] = missed;
        }
        else
        {
            playerB.pointsArr[i] = std::stod(line);     // line is string, turns vars from line(strings) to double
        }
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