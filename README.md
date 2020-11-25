# Schottland_CSCI2275_FinalProject

Description:
This program will try to guess words based off of the few first letters or letter. You will feed in text to set the weights of paths in the tree.
from there you will be able to enter in an amount of letters. The program will use how often the letters you fed it led to different words in the test
text to predict what word it thinks that you are guessing. In order to store this I will use a modified tree. The tree will have a root of the first letter you enter. 
The children will be all of the letter of the alphabet. Each child will have a weight and the tree will go to the child with the highest weight. I will probably limit the program to shorter words of 4 or 5 letters because more letters quickly increases the tree size since each node will have 26 children. The data structures used will be a tree/graph and a linked list to hold the guessed word. 
