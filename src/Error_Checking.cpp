#include "Error_Checking.h"
#include <climits>

int CinErrorCheck(string prompt, string Error_Message,
                  string out_of_range_Message, pair<int, int> bound,
                  bool repeat, int errorReturn) {
    int UserInput;
    do {
        // Get user input
        cout << prompt;
        cin >> UserInput;

        if (cin.fail()) {
            cerr << Error_Message << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        } else if ((UserInput >= bound.first) && (UserInput <= bound.second)) {
            return UserInput;

        } else {
            cerr << out_of_range_Message << endl;
        }
    } while (repeat);
    return errorReturn;
}