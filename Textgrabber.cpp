//This program is made to output the filenames of all the files/folders in the given folder
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm> //transform

using std::cin;
using std::cout;
using std::string;
void cls(HANDLE hConsole);

int main(){
    string directory;
    string directoryCheck;

    //Informing the user how this program works
    cout << "This program outputs the names of the files in the directory you input\n";
    cout << "At any point you can exit this program by inputting: \"quit\", \"q\", or \"exit\"\n\n";

    for(;;){
        //Asking for input and explaining the function of the program
        std::cout << "Please input your desired destination: ";

        //Getting user's input
        getline(cin, directory);
        directoryCheck = directory; //temp copy needed to edit

        //Going to user's requested directory
        LPSTR userRequestedDir = const_cast<char *>(directory.c_str());

        //if directory input is valid, directoryChanged will be 1, otherwise it'll be 0
        int directoryChanged = SetCurrentDirectory(userRequestedDir);

        //Converts the string to upper case for our other else if cases
        std::transform(directoryCheck.begin(), directoryCheck.end(), directoryCheck.begin(), ::toupper);

        //Valid directory
        if(directoryChanged){
            //Telling user what occurred
            cout << "Copied file names from \"" << directory << "\"";
            cout << "\nOutputting directory list:\n\n";

            system("dir /b"); //print out file names
            system("dir /b |clip"); //copy to clipboard

            /*
                Other commands:
                dir /b /s |clip         //Copy all file names to clipboard including file paths
                dir /b |clip            //Copy all files names, not including the path
                dir /b > filenames.txt  //Create a txt file with the file names
                clip < filenames.txt    //Copy the contents of the txt file
                del /f filenames.txt    //Delete the file
            */

            //Changes the folder in use
            string defaultDirectory = "C:\\";
            LPSTR userRequestedDir = const_cast<char *>(defaultDirectory.c_str());
            directoryChanged = SetCurrentDirectory(userRequestedDir);
        }
        //Exits program when user request for it
        else if(directoryCheck == "EXIT" || directoryCheck == "Q" || directoryCheck == "QUIT"){
            cout << "The program has ended";
            exit(1);
        }
        //Clears the console
        else if(directoryCheck == "CLC" || directoryCheck == "CLEAR"){
            HANDLE hStdout;
            hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
            cls(hStdout);
        }
        //Because directoryChanged is 0, it in an invalid directory
        else{
            cout << "\"" << directory << "\"" << " is and invalid directory\n";
        }

        cout << "\n";
    }
}

//Clearing console without system commands
void cls(HANDLE hConsole){
   COORD coordScreen = {0, 0};    // home for the cursor
   DWORD cCharsWritten;
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   DWORD dwConSize;

    // Get the number of character cells in the current buffer.

   if(!GetConsoleScreenBufferInfo(hConsole, &csbi))
      return;
   dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

   // Fill the entire screen with blanks.

   if(!FillConsoleOutputCharacter(hConsole, (TCHAR) ' ',
      dwConSize, coordScreen, &cCharsWritten))
      return;

   // Get the current text attribute.

   if(!GetConsoleScreenBufferInfo( hConsole, &csbi))
      return;

   // Set the buffer's attributes accordingly.

   if(!FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
      dwConSize, coordScreen, &cCharsWritten))
      return;

   // Put the cursor at its home coordinates.

   SetConsoleCursorPosition(hConsole, coordScreen);
}
