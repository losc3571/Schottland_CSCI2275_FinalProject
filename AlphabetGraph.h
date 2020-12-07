#ifndef ALPHABETGRAPH_H
#define ALPHABETGRAPH_H
#include <vector> 
#include <iostream> 
#include <string>

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    std::string name;
    std::vector<adjVertex> adj;
};

class AlphabetGraph
{
    public:
        AlphabetGraph();  
        ~AlphabetGraph(); 
        void addEdge(vertex *a, vertex *b, int weight);
        void addVertex(std::string name);
        void printMostCommonOfLetter(std::string letter);//Prints most common word of letter
        void displayStart(); //debug - print out starting nodes 
        void buildGraph();//Starts graph by filling start letters with each letter of the alphabet
        std::string guessWord(std::string start);
        void addWord(std::string word);
        void randomWord();//Prints random word
        void clearGraph();//Clear all nodes in graph
        void printNumberOfNodes(); //prints total number of nodes
    protected:
    private:
        std::vector<vertex> startingLetter; 
        vertex *findVertexStarting(std::string name); //Loop through startingLetter and find name
        vertex *findNextVertex(vertex *temp, char a); //Find vertex with a from temp
        void addFinishNode(vertex *finish); //Adds a special node at end of word to designate that it is the end of a word
        int printNumberOfNodesHelper(vertex *root, int &total); 
        
};

#endif //ALPHABETGRAPH_H
