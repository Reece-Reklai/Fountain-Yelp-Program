#include "Error_Checking.h"

int main () {
    CinErrorCheck ("Type an awesome Number from 0 to 10: ", "Bad Number!", "Enter a number in range.", {0,10});

    return 0;
}