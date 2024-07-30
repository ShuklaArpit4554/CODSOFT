#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int randomNumber = rand() % 100 + 1;
    int guess;

    cout << "Guess the number between 1 and 100 : ";

    while (true) {
        cin >> guess;

        if (guess > randomNumber) {
            cout << "Too high! Try again: ";
        } else if (guess < randomNumber) {
            cout << "Too low! Try again: ";
        } else {
            cout << "Congratulations! You've guessed the correct number." << endl;
            break;
        }
    }

    return 0;
}
