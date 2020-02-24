#include "Error_Checking.h"
#include <limits.h>

int CinErrorCheck (string prompt, string Error_Message, pair<int,int> bound, bool repeat, int errorReturn) {
    int UserInput;
    do {
        // Get user input
        cout << prompt;
        cin >> UserInput;


        if (cin.fail()) {
            cerr << Error_Message << endl;
            cin.ignore(INT_MAX, '\n');
            cin.clear();
            continue;
        }

        if ((UserInput >= bound.first) && (UserInput <= bound.second)) {
            return UserInput;

        } else {
            cerr << Error_Message << endl;
            continue;
        }
    } while (repeat);
    return errorReturn;
}