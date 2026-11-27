#include "graph.h"

void CreateGraph(Graph &G) {
    G.First = Nil;
}

adrNode AllocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = Nil;
    P->Next = Nil;
    return P;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = AllocateNode(X);
    if (G.First == Nil) {
        G.First = P;
    } else {
        P->Next = G.First;
        G.First = P;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode P = G.First;
    while (P != Nil) {
        if (P->info == X) {
            return P;
        }
        P = P->Next;
    }
    return Nil;
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 == Nil || N2 == Nil) return;

    adrEdge E1 = new ElmEdge;
    E1->Node = N2;
    E1->Next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = new ElmEdge;
    E2->Node = N1;
    E2->Next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.First;
    cout << "=== ISI GRAPH ===" << endl;
    while (P != Nil) {
        cout << "Node [" << P->info << "] terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != Nil) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
    cout << "=================" << endl;
}

void ResetVisited(Graph G) {
    adrNode P = G.First;
    while (P != Nil) {
        P->visited = 0;
        P = P->Next;
    }
}

void PrintDFS(adrNode N) {
    if (N == Nil) return;
    
    N->visited = 1;
    cout << N->info << " "; 

    adrEdge E = N->firstEdge;
    while (E != Nil) {
        if (E->Node->visited == 0) {
            PrintDFS(E->Node); 
        }
        E = E->Next;
    }
}

void PrintBFS(adrNode start) {
    if (start == Nil) return;

    adrNode queue[100]; 
    int front = 0, rear = 0;

    start->visited = 1;
    queue[rear++] = start; 

    while (front < rear) {
        adrNode curr = queue[front++]; 
        cout << curr->info << " ";

        adrEdge E = curr->firstEdge;
        while (E != Nil) {
            if (E->Node->visited == 0) {
                E->Node->visited = 1;
                queue[rear++] = E->Node; 
            }
            E = E->Next;
        }
    }
}