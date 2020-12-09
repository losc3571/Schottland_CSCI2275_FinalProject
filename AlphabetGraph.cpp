#include "AlphabetGraph.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

AlphabetGraph::AlphabetGraph(){

}

AlphabetGraph::~AlphabetGraph(){
    //dtor
}

void AlphabetGraph::buildGraph(){
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    startingLetter.clear();
    //Add each letter of alphabet to startingLetter vectore
    for(int i = 0; i < alphabet.length(); i++){
        vertex *temp = new vertex;
        temp->name = alphabet.at(i);
        startingLetter.push_back(*temp);
    }
}

void AlphabetGraph::addWord(string word){
    if (word == ""){
        return;
    }
    char c = word.at(0);
    string start(1,c);
    vertex *temp = findVertexStarting(start);
    for(int i = 1; i < word.length(); i++){
                 vertex *temp2 = findNextVertex(temp, word.at(i));
                 temp = temp2;
         }
    //Add special node
    addFinishNode(temp);
}

vertex *AlphabetGraph::findVertexStarting(string name){
    for(int i = 0; i< startingLetter.size(); i++){
        if(startingLetter[i].name == name ){
            return &startingLetter[i];
        }
    }
    return NULL;
}

vertex *AlphabetGraph::findNextVertex(vertex *temp, char a){
    string letter(1,a);
    for(int i = 0; i < temp->adj.size(); i++){
        if(temp->adj[i].v->name == letter){
            temp->adj[i].weight+=1;
            return temp->adj[i].v;
        }
    }
    vertex *temp2 = new vertex;
    temp2->name = letter;
    addEdge(temp, temp2, 1);
    return temp2;
}

void AlphabetGraph::addEdge(vertex *a, vertex *b, int weight){
    adjVertex *temp = new adjVertex;
    temp->v = b;
    temp->weight = weight;
    //Only need one way edges because acts like tree
    a->adj.push_back(*temp);
}

void AlphabetGraph::addFinishNode(vertex *finish){
    vertex *temp = new vertex;
    for(int i = 0; i < finish->adj.size(); i++){
        if(finish->adj[i].v->name == ""){
            finish->adj[i].weight+=1;
            return;
        }
    }
    temp->name = "";
    addEdge(finish, temp, 1);
}

string AlphabetGraph::guessWord(string word){
    string result = word;
    if (word == ""){
        return "";
    }
    //Parse current guess into letters
    char c = word.at(0);
    string start(1,c);
    vertex *temp = findVertexStarting(start);
    if (temp == NULL){
        cout << "Error, check guess" << endl;
        return "";
    }
    //This loop moves through tree so that guess starts from vertex
    //based off of the letters that the user has already entered
    for(int i = 1; i < word.length(); i++){
        char nex = word.at(i);
        string next(1,nex);  
        bool found = false;
        for(int j = 0; j < temp->adj.size(); j++){
            if (temp->adj[j].v->name == next){
                temp = temp->adj[j].v;
                found = true;
                break;
            }
        }
        if (found == false){
            cout << "Unable to find any words" << endl;
            return "";
        }
    }
    //This loop adds letters to guess
    while(temp->name != ""){
        int biggestI = 0;
        int biggest = 0;
        for (int i = 0; i < temp->adj.size(); i++){
            if(temp->adj[i].weight > biggestI){
                biggest = i;
                biggestI = temp->adj[i].weight;
            }
        }
        //Fix this
        if (temp->adj.size() == 0){
            cout << "I don't know any words that start with this letter. The guess will be blank" << endl;
            return "";
        }
        
        result += temp->adj[biggest].v->name;
        temp = temp->adj[biggest].v;
    }
    return result;
}

void AlphabetGraph::printMostCommonOfLetter(std::string letter){
    string result = letter;
    vertex *temp = findVertexStarting(letter);
    if (temp == NULL){
        cout << "Character not recognized, remember to use lowercase letters." << endl;
        return;
    }
    while(temp->name != ""){
        int biggestI = 0;
        int biggest = 0;
        for (int i = 0; i < temp->adj.size(); i++){
            if(temp->adj[i].weight > biggestI){
                biggest = i;
                biggestI = temp->adj[i].weight;
            }
        }
        //Fix this
        if (temp->adj.size() == 0){
            cout << "I don't know any words that start with this letter." << endl;
            return;
        }
        
        result += temp->adj[biggest].v->name;
        temp = temp->adj[biggest].v;
    }
    cout << "The most common word starting with " << letter << " is " << result << "." << endl;
}

void AlphabetGraph::randomWord(){
    //Keep in mind that random will repeat the same thing
    //unless you give it a new seed
    int a = rand() % startingLetter.size();
    string result;
    vertex *temp = &startingLetter[a];
    result += temp->name;
    while (temp->name != ""){
        if(temp->adj.size() == 0){
            randomWord();
            return;
        }
        int b = rand() % temp->adj.size();
        result += temp->adj[b].v->name;
        temp = temp->adj[b].v;
    }
    cout << "Your random word is " << result << "." << endl;
}

void AlphabetGraph::clearGraph(){
    //Clears nodes to a null node
    for(int i = 0; i < startingLetter.size(); i++){
        vertex *a = new vertex;
        startingLetter[i] = *a;
    }
}

void AlphabetGraph::printNumberOfNodes(){
    //Iterates through each node recursively 
    int num = 0;
    for(int i = 0; i < startingLetter.size(); i++){
       num++;
       printNumberOfNodesHelper(&startingLetter[i], num);
    }
    cout << "The total number of nodes is " << num << endl;
}
int AlphabetGraph::printNumberOfNodesHelper(vertex *root, int &total){
    if(root->adj.size() == 0){
        return 1;
    }
    for(int i = 0; i < root->adj.size(); i++){
        printNumberOfNodesHelper(root->adj[i].v, total);
        (*&total)++;
    }
    return 1;
}

void AlphabetGraph::displayStart(){
    for(int i = 0; i < startingLetter.size(); i++){
        cout << startingLetter[i].name << endl;
    }
}