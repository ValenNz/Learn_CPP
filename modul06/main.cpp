#include <iostream>
#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5, PDeleted = Nil;

    createList(L);
    cout << "=== MODUL 6: DOUBLY LINKED LIST ===" << endl;

    P1 = alokasi(10); insertFirst(L, P1);
    P2 = alokasi(20); insertFirst(L, P2);
    cout << "\n[1] Setelah Insert First (20, 10):" << endl;
    printInfo(L);
    printInfoReverse(L);

    P3 = alokasi(30); insertLast(L, P3);
    P4 = alokasi(40); insertLast(L, P4);
    cout << "\n[2] Setelah Insert Last (30, 40):" << endl;
    printInfo(L);

    P5 = alokasi(25); 
    insertAfter(L, P5, P2); // P2 berisi 20
    cout << "\n[3] Setelah Insert After 25 (setelah 20):" << endl;
    printInfo(L);

    cout << "\n[4] Delete First (Menghapus 20):" << endl;
    deleteFirst(L, PDeleted);
    printInfo(L);

    cout << "\n[5] Delete Last (Menghapus 40):" << endl;
    deleteLast(L, PDeleted);
    printInfo(L);

    cout << "\n[6] Delete After (Menghapus setelah 10, yaitu 25):" << endl;
    deleteAfter(L, PDeleted, P1); // P1 berisi 10
    printInfo(L);
    printInfoReverse(L);

    return 0;
}
