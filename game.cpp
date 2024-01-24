#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Game::Game(int)
{
    cout << "Give maximium value: " << endl;
    cin >> maxNumber;
    cout << "GAME CONSTRUCTOR: object initialized with " << maxNumber << " as maximium value" << endl;
}

Game::~Game()
{
    cout << "GAME DESTRUCTOR: object cleared from stack memory" << endl;
}

void Game::play()
{

    srand(time(0));
    int randomNumber = rand() % maxNumber + 1;

    cout << "Give your guess between 1 - 10" << endl;

    while (playerGuess != randomNumber)
    {
        numOfGuesses++;
        cin >> playerGuess;
        cout << endl;

        if (playerGuess > maxNumber) {
            cout << "Your guess is larger than the biggest possible value" << endl;
        }

        if (playerGuess < 1) {
            cout << "Your guess is smaller than the lowest possible value" << endl;
        }

        if (playerGuess > randomNumber && playerGuess <= maxNumber) {
            cout << "Your guess is too big" << endl;
        }

        if (playerGuess < randomNumber && playerGuess > 0) {
            cout << "Your guess is too small" << endl;
        }

        else if (playerGuess == randomNumber && playerGuess > 0 && playerGuess <= maxNumber) {
            printGameResult();
        }
    }
}


void Game::printGameResult()
{
    cout << "You guessed the right answer = " << randomNumber << "with " << numOfGuesses << " guesses" << endl;
}
