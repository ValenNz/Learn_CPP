#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    cout << "=== MODUL 14: GRAPH TIDAK BERARAH ===" << endl;

    InsertNode(G, 'D');
    InsertNode(G, 'C');
    InsertNode(G, 'B');
    InsertNode(G, 'A');

    adrNode nodeA = FindNode(G, 'A');
    adrNode nodeB = FindNode(G, 'B');
    adrNode nodeC = FindNode(G, 'C');
    adrNode nodeD = FindNode(G, 'D');

    ConnectNode(nodeA, nodeB);
    ConnectNode(nodeA, nodeC);
    ConnectNode(nodeB, nodeD);
    ConnectNode(nodeC, nodeD);

    PrintInfoGraph(G);

    cout << "\n[1] Hasil Penelusuran DFS (Mulai dari A): ";
    ResetVisited(G); 
    PrintDFS(nodeA);
    cout << endl;

    cout << "\n[2] Hasil Penelusuran BFS (Mulai dari A): ";
    ResetVisited(G); 
    PrintBFS(nodeA);
    cout << endl;

    return 0;
}