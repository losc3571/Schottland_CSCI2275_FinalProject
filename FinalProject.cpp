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
    AlphabetGraph myGraph;
    myGraph.buildGraph();
    //Check if file is open
    if(!myFileStream){
        cout << "Could not open file" << endl;
        return 0;
    }
    //Add all words from text into tree
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
                    "5. Print Most Common Word Starting with a Letter\n"
                    "6. Print Random Word\n"
                    "7. See Currently Queued Words\n"
                    "8. Quit\n";
    cout << dmenu << endl;

    while (cin >> choice)
    {
        // flush the newlines and other characters
        cin.clear();
        cin.ignore();
        switch (choice) {
            case 1:
            {   
                //This will add letters to a guess to be made
                string let;
                cin >> let;
                guess += let;
                cout << "The current letters are: " << guess << endl;
                break;
            }
            
            case 2:
            {
                //This will make a guess using the graph
                string correct;
                string attempt = myGraph.guessWord(guess);
                cout << "My guess is " << attempt << endl;
                //Asking if the guess is correct is used to know what word the user was actually thinking of 
                //so that when they dequeue to train tree later it will train the tree based off of the words
                //they were actually thinking of
                cout << "Is this correct? Type y/n" << endl;
                cin >> correct;
                if(correct == "y" || correct == "Y"){
                    //Enqueue to train with becaue it was correct
                    myQ.enqueue(attempt);
                }
                else if (correct == "n" || correct == "N"){
                    //Enqueues what user was actually thinking of so that the program can learn this word for subsequent attempts
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
                //Clears word manually
                guess = "";
                break;
            }
            case 4:{
                //Adds words recently guessed into the tree and updates weights
                //Tree dynamically adjusts based on users guesses
                while(!myQ.queueIsEmpty()){
                    myGraph.addWord(myQ.dequeue());
                }
                cout << "Words added to tree " << endl;
                break;
            }
            case 5: 
            {
                //Prints most common word in tree starting with certain letter
                string let; 
                cout << "Enter a letter " ;
                cin >> let; 
                myGraph.printMostCommonOfLetter(let);
                let = "";
                break;
            }
            case 6:{
                //Prints random word in tree
                myGraph.randomWord();
                break;
            }
            case 7:{
                //Prints words in queue to be added to tree upon dequeue
                myQ.printCurrentlyQueuedWords();
                break;
            }
            case 8:{
                exit = true;
                break;
            }
            
        }
        
        if (exit) {
            break;
        }

        cout << dmenu << endl;
    } 
    //Uncomment this line to print total number of nodes upon quitting program
    //myGraph.printNumberOfNodes();
    return 0;
}
