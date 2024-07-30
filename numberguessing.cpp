#include<bits/stdc++.h>  

using namespace std;

//play the number guessing game
void playNumberGuessingGame() {
    int lowerBound = 1;
    int upperBound = 100;
    int numberToGuess, userGuess;

    // random number generator
    std::srand(static_cast<unsigned int>(std::time(0))); 
    numberToGuess = std::rand() % upperBound + lowerBound;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I have chosen a number between " << lowerBound << " and " << upperBound << ".\n";
    cout << "Try to guess it!\n";

    int attempts = 0; //  count the number of attempts
    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        // Check if the user's guess is correct
        if (userGuess < numberToGuess) {
            cout << "Your guess is too low. Try again.\n";
        } else if (userGuess > numberToGuess) {
            cout << "Your guess is too high. Try again.\n";
        } else {
            cout << "Congratulations! You guessed the correct number: " << numberToGuess << "!\n";
            cout << "It took you " << attempts << " attempts.\n";
        }
    } while (userGuess != numberToGuess);
}

int main() {
    char playAgain = 'Y';

    do {
        playNumberGuessingGame();
        cout << "Would you like to play again? (Y/N): ";
        cin >> playAgain;
        playAgain = toupper(playAgain); 
    } while (playAgain == 'Y');

    cout << "Thank you for playing the Number Guessing Game!See you soon \n";
    return 0;
}
