//This program is made to output the text of all the files/folders in the user's specified input
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

//This version will create a file with the file names, "Filenames.txt"
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
            cout << "You have reached " << directory;
            cout << "\nOutputting directory list:\n";

            //Listing the files/folders in the directory
            system("dir /b");
            system("dir /b > filenames.txt");
            system("clip < filenames.txt");
            //system("del /f filenames.txt");
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
