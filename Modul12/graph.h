#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmEdge {
    adrNode Node;   
    adrEdge Next; 
};

struct ElmNode {
    infoGraph info;
    int visited;    
    adrEdge firstEdge; 
    adrNode Next;  
};

struct Graph {
    adrNode First;
};

void CreateGraph(Graph &G);
adrNode AllocateNode(infoGraph X);
void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

void ResetVisited(Graph G);
void PrintDFS(adrNode N);
void PrintBFS(adrNode start);

#endif