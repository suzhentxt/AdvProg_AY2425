#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;

/***
    Returns:
        number (int) : random number in range 1-100
***/
int generateRandomNumber() {
    // Generate a random number between 1 and 100 (inclusive)
    return rand() % 100 + 1;
}

/***
    Returns:
        number (int) : the number that the player guessed
***/
int getPlayerGuess() {
    int guess;
    cout << "Enter your guess (1-100): ";
    cin >> guess;
    return guess;
}

/***
    Args:
        number (int): answer number from player
        randomNumber (int): the true number
    Returns:
        answer (string) : answer of computer after checking result
***/
string getAnswer(int number, int randomNumber) {
    if (number > randomNumber) {
        return "Your number is higher.";
    } else if (number < randomNumber) {
        return "Your number is lower.";
    } else {
        return "Congratulation! You win.";
    }
}

/***
    Args:
        answer (string): answer from computer after comparing numbers
    Returns:
        result (bool) : true if the player guessed correctly, false otherwise
***/
bool checkSuccess(string answer) {
    // Check if the answer indicates a win
    return answer == "Congratulation! You win.";
}

/***
    Args:
        isContinued (char): player's choice
    Returns:
        result (bool) : true if the player wants to continue playing, false otherwise
***/
bool checkContinuePlaying(char isContinued) {
    // Continue playing if the player's input is 'Y' or 'y'
    return isContinued == 'Y' || isContinued == 'y';
}

/***
    Returns:
        isContinued (char) : player's choice (continue playing or not)
***/
char getPlayerOpinion() {
    char op;
    cout << "Do you want to continue playing? (Y/N): ";
    cin >> op;
    return op;
}

void playGuessIt() {
    int randomNumber = generateRandomNumber();
    int number;
    string answer;
    
    do {
        number = getPlayerGuess();
        answer = getAnswer(number, randomNumber);
        cout << answer << endl;
    } while (!checkSuccess(answer));
}

int run() {
    srand(time(0));
    char isContinued;
    do {
        playGuessIt();
        isContinued = getPlayerOpinion();
    } while (checkContinuePlaying(isContinued));
    return 0;
}
