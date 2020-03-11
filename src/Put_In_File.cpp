#include <fstream>
#include <string>

using namespace std;

void Put_In_File (string File_Name, string content) {
    // Purpose:
    //  To take information, and add it to an existing file.
    // Parameters:
    //  File_Name - Name of the file being written to.
    //  content   - The information being added to the file.
    // Method:
    //  
    // Return:
    //  

    ofstream Outfile;

    Outfile.open (File_Name, ios_base::app);

    Outfile << '\n' << content;

    return ;
}