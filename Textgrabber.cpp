//This program is made to output the filenames of all the files/folders in the given folder
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main(){
    string directory;

    //Informing the user how this program works
    cout << "This program outputs the names of the files in the directory you input\n";
    cout << "At any point you can exit this program by inputting: \"quit\", \"q\", or \"exit\"\n\n";

    do{
        //Asking for input and explaining the function of the program
        std::cout << "Please input your desired destination: ";

        //Getting user's input
        getline(cin, directory);

        //Going to user's requested directory
        LPSTR userRequestedDir = const_cast<char *>(directory.c_str());

        //if directory input is valid, directoryChanged will be 1, otherwise it'll be 0
        int directoryChanged = SetCurrentDirectory(userRequestedDir);

        //Valid directory
        if(directoryChanged){
            //Telling user what occurred
            cout << "Copied file names from \"" << directory << "\"";
            //cout << "\nOutputting directory list:\n";

            //Listing the files/folders in the directory
            //system("dir /b"); //print out the results
            system("dir /b |clip"); //copy to clipboard

            /*
                Other commands:
                dir /b /s |clip //Copy all file names to clipboard including file paths
                dir /b |clip //Copy all files names, not including the path
            */

            //Going back to the default directory
            string defaultDirectory = "C:\\";
            LPSTR userRequestedDir = const_cast<char *>(defaultDirectory.c_str());
        }

        //Exits program when user request for it
        else if(directory == "exit" || directory == "q" || directory == "quit"){
            cout << "The program has ended";
            exit(1);
        }

        //Because directoryChanged is 0, it in an invalid directory
        else{
            cout << "\"" << directory << "\"" << " is and invalid directory\n";
        }

        cout << "\n";
    }while (true);
}
