#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "=== MODUL 12: BINARY SEARCH TREE ===" << endl;
    
    address root = Nil;


    cout << "\n[1] Memasukkan data ke dalam BST..." << endl;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6); 
    insertNode(root, 7);

    cout << "\n[2] Hasil Traversal:" << endl;
    cout << "In-Order  : ";
    printInorder(root);
    cout << endl;

    cout << "Pre-Order : ";
    printPreorder(root);
    cout << endl;

    cout << "Post-Order: ";
    printPostorder(root);
    cout << endl;

    cout << "\n[3] Analisis Tree:" << endl;
    cout << "Jumlah Node : " << hitungJumlahNode(root) << endl;
    cout << "Total Info  : " << hitungTotalInfo(root) << endl;
    cout << "Kedalaman   : " << hitungKedalaman(root) << endl;

    cout << "\n[4] Tes Pencarian (Find Node):" << endl;
    address hasilCari = findNode(4, root);
    if (hasilCari != Nil) {
        cout << "Node dengan info 4 DITEMUKAN!" << endl;
    } else {
        cout << "Node dengan info 4 TIDAK DITEMUKAN!" << endl;
    }

    return 0;
}