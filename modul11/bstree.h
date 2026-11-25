#ifndef BSTREE_H_INCLUDED
#define BSTREE_H_INCLUDED

#include <iostream>
#include <algorithm> 
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct Node* address;

struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void dealokasi(address &P);

void insertNode(address &root, infotype x);
address findNode(infotype x, address root);

void printInorder(address root);
void printPreorder(address root);
void printPostorder(address root);

int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root);

#endif 