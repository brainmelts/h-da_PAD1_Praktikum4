// Craps Simulation
// Autor: Suayb Yurdakul
// Datum: 2018-12-06

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>
using namespace std;

enum Status { CONTINUE, WON, LOST };
unsigned int rollDice();

unsigned const int iterations = 10000000;
unsigned int wlTotal[100][2];
unsigned int rollAmount = 0;
unsigned int totalRolls = 0;
unsigned int averageGameLength = 0;

int main() {
    unsigned int myPoint = 0;
    Status gameStatus = CONTINUE;

    srand(static_cast<unsigned int>(time(NULL)));

    for (unsigned int i = 0; i < iterations; i++) {
        rollAmount = 0;

        unsigned int sumOfDice = rollDice();

        switch (sumOfDice) {
        case 7:
        case 11:
            gameStatus = WON;
            break;
        case 2:
        case 3:
        case 12:
            gameStatus = LOST;
            break;
        default:
            gameStatus = CONTINUE;
            myPoint = sumOfDice;
            break;
        }

        while (CONTINUE == gameStatus) {
            sumOfDice = rollDice();

            if (sumOfDice == myPoint) gameStatus = WON;
            else if (sumOfDice == 7) gameStatus = LOST;
        }

        if (WON == gameStatus) wlTotal[rollAmount][0]++;
        else wlTotal[rollAmount][1]++;
    }


    cout << "Würfe\tGewonnen\tVerloren\tChance" << endl;

    for (unsigned int i = 0; i < 100; i++) {
        unsigned int won = wlTotal[i][0];
        unsigned int lost = wlTotal[i][1];

        if ((won > 0) || (lost > 0)) {
            totalRolls += i * (won + lost);

            double quota = static_cast<double>(won) / static_cast<double>(won + lost);
            cout << i << "\t" << won << "\t\t" << lost << "\t\t" << quota << endl;
        }
    }

    averageGameLength = ceil(static_cast<double>(totalRolls) / static_cast<double>(iterations));
    cout << "\nIn " << iterations << " Spielen wird durchschnittlich " << averageGameLength << " Mal gewürfelt.\n";

    return 0;
}

unsigned int rollDice() {
    unsigned int die1 = 1 + rand() % 6;
    unsigned int die2 = 1 + rand() % 6;
    unsigned int sum = die1 + die2;

    rollAmount++;

    return sum;
}
