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
        int isAdjacent(std::string v1, std::string v2);
        void displayEdges();
        void buildGraph();
        std::string guessWord(std::string start);
        void addWord(std::string word);
    protected:
    private:
        std::vector<vertex> startingLetter  ; 
        vertex *findVertexStarting(std::string name);
        vertex *findNextVertex(vertex *temp, char a);
        void DFSLabel(std::string person, int ID);
        void addFinishNode(vertex *finish);
        
};

#endif //ALPHABETGRAPH_H
