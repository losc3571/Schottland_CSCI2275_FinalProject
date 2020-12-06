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
    char c = word.at(0);
    string start(1,c);
    vertex *temp = findVertexStarting(start);
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