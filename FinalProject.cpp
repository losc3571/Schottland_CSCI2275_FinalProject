#include "AlphabetGraph.h"
#include "Queue.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>


using namespace std;


//Create condition for if don't have the letter
int main(int argc, char *argv[]){
    ifstream myFileStream;
    myFileStream.open(argv[1]);
    string line;
    //Check if file is open
    AlphabetGraph myGraph;
    myGraph.buildGraph();
    if(!myFileStream){
        cout << "Could not open file" << endl;
        return 0;
    }
    while(getline(myFileStream, line)){
        stringstream ss(line);
        string temp1; 
         while(getline(ss, temp1, ' ')){
             myGraph.addWord(temp1);
        }  
    }
    //Create queue to store guessed words and update weights.
    Queue myQ(100);

    //Bring up menu where user can enter in letters and have words guessed
    string guess;
    int choice;
    bool exit = false;
    string dmenu = "======Main Menu=====\n"
					"1. Add to Guess\n"
					"2. Make Guess\n"
                    "3. Clear Word\n"
                    "4. Dequeue Words to Train Guesser\n"
                    "5. Quit\n";
    cout << dmenu << endl;

    while (cin >> choice)
    {
        // flush the newlines and other characters
        cin.clear();
        cin.ignore();
        switch (choice) {
            case 1:
            {   
                string let;
                cin >> let;
                guess += let;
                cout << "The current letters are: " << guess << endl;
                break;
            }
            
            case 2:
            {
                string correct;
                string attempt = myGraph.guessWord(guess);
                cout << "My guess is " << attempt << endl;
                cout << "Is this correct? Type y/n" << endl;
                cin >> correct;
                if(correct == "y" || correct == "Y"){
                    myQ.enqueue(attempt);
                }
                else if (correct == "n" || correct == "N"){
                    string intended;
                    cout << "Please enter the word you were thinking of ";
                    cin >> intended;
                    myQ.enqueue(intended);
                }
                guess = "";
                break;
            }
            case 3:
            {
                guess = "";
                break;
            }
            case 4:{
                while(!myQ.queueIsEmpty()){
                    myGraph.addWord(myQ.dequeue());
                }
                cout << "Words added to tree " << endl;
                break;
            }
            case 5: 
            {
                exit = true;
                break;
            }
        }
        
        if (exit) {
            break;
        }

        cout << dmenu << endl;
    } 

    myQ.printQueue();
    return 0;
}
