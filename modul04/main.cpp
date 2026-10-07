#include "Singlylist.h"

int main() {
    List L;
    address P1 = Nil, P2 = Nil, P3 = Nil, P4 = Nil, P5 = Nil;
    
    createList(L);

    P1 = alokasi(2);  insertFirst(L, P1);
    P2 = alokasi(0);  insertLast(L, P2);
    P3 = alokasi(8);  insertAfter(L, P3, P2);
    P4 = alokasi(12); insertFirst(L, P4);
    P5 = alokasi(9);  insertFirst(L, P5);

    cout << "Isi List: ";
    printInfo(L);

    return 0;
}