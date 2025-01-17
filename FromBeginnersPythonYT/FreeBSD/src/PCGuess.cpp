#include<iostream>
#include<cstdlib>
using std::cout;
using std::cin;
using std::string;
using std::to_string;
using std::system;
using std::cerr;
using std::exception;
using std::tolower;
using std::stoi;

int main(int argc, char* argv[]) {

    try {

        int max, pcguess, user_number, low, high;
        char feedback;

        // If no argument or too many show usage, help and error:
        if (argc <= 1 || argc > 3) {
            cout << "Usage: PCGuess.exe <number>\n";
            cout << "Example: PCGuess.exe 43" << "\n";
            return -1; // returning false to indicate an error
        }

        if (strcmp(argv[1],"-n") == 0)
            user_number = stoi(argv[2]);
        else
            user_number = stoi(argv[1]);

        time_t nTime;
        srand((unsigned)time(&nTime));

        max = high = 1000;
        high = high - 1;
        low = 1;

        feedback = ' ';

        if (user_number <= 0 || user_number > max)
        {
            cout << "Wrong number. Numbers allowed between 1 and " + to_string(max) + ".\n";

             return -1;
        }

        cout << "\033[2J\033[1;1H";

        while (feedback != 'c')
        {
            cout << "Guessing between " + to_string(low) + " and " + to_string(high) + ".\n";

            pcguess = arc4random() % (high - low) + low;

            cout << "Is " + to_string(pcguess) + " too high (H), too low (L), or correct (C)? \n";
            cin >> feedback;
            feedback = tolower(feedback);

            if (feedback == 'l')
                low = ++pcguess;
            else if (feedback == 'h')
                high = --pcguess;

            // No more possibilities high and low are the same
            if (low == high) {
                cout << "Number must be " + to_string(low) + "!\n";
                return 0;
            }
        }
        cout << "Yes, congrats. You have guessed the number " + to_string(user_number) + " correctly!";

        getc(stdin);

    }

    catch (exception& e) {
        cerr << e.what() << "\n";
    }

    return 0;
}
