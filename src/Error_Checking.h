#include <string>
#include <iostream>

using namespace std;


int CinErrorCheck (string prompt, string Error_Message, string out_of_range_Message, pair<int,int> bound, bool repeat = true, int errorReturn = -1);
/* 
    Parameters:
        prompt - what is printed at start
        Error_Message - what is printed if user inputs is not an integer
        out_of_range_Message - What is
        bound - range of values the user can input.
        repeat - flag to decide if the prompt is to be repeated again.
        errorReturn - if the function is run once, and the user's input is invalid the function will return this value.

    Return:
        Whatever value the user inputs, if it is valid, will be returned.


*/