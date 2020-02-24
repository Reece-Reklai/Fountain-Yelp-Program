#include <string>
#include <iostream>

using namespace std;


int CinErrorCheck (string prompt, string Error_Message, pair<int,int> bound, bool repeat = true, int errorReturn = -1);
/* 
    Parameters:
        prompt - what is printed at start
        Error_Message - what is printed if user input is invalid
        bound - range of values the user can input.
        repeat - flag to decide if the prompt is to be repeated again.
        errorReturn - if the function is run once, and the user's input is invalid the function will return this value.

    Return:
        Whatever value the user inputs, if it is valid, will be returned.


*/