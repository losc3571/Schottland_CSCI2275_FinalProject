# Schottland_CSCI2275_FinalProject

Project Summary: This program will try to guess a word you are thinking of based off of the first however many letters you give it. It does this by taking a large piece of text
		 and recording in this text how often certain letters are to come after others. The text I included to train it is the Hemingway edit we used in a previous assignment but 
		 any sufficiently large text could be used as a command line argument. When this text is inputted, a tree is created for each starting letter in the alphabet. The branches include all 
		 of the possible next letters and how likely they are to occur. Then, the program pops up a menu allowing you to guess words. You enter in a guess and the program will follow the highest
	         weighted branches down from your guess to return the most likely word. Every time you guess, the program asks to find the actual word that you were thinking of. This word is added to a queue.
		 When you select the dequeue words to train algorithm option, all the words in the queue are dequeued and the weights in the tree are updated based on words you used. In this way the tree can 
		 learn words and then be more likely to guess them next time you enter the beginning of them. 

How to run: To run this program in VSCode, download the file into a folder. Then open the folder in VSCode and open a terminal. In the terminal navigate to the filepath and use the command 
	    g++ -std=c++11 -o FinalProject FinalProject.cpp AlphabetGraph.cpp Queue.cpp to compile the code. Then run the code using either ./FinalProject for Linux/MacOS or .\FinalProject for Windows terminal.
	    Add to this the name of the text file you want to use to initially set the tree weights. You don't have to use Hemingway_edit.txt but if you choose another file you have to format it to take out 
	    all special characters and change all letters to lowercase. 

Dependencies: Not applicable

System Requirements: This program should run on MacOS/Linux or Windows and there are no special requirements.

Team Members: Logan Schottland

Contributors: 

Open Issues/Bugs:     

