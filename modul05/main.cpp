#include <iostream>
#include "Singlylist.h"

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    address PFound = Nil;
    address PDeleted = Nil;

    createList(L);
    cout << "=== MODUL 5: SINGLY LINKED LIST ===" << endl;

    P1 = alokasi(2);  insertFirst(L, P1);
    P2 = alokasi(0);  insertFirst(L, P2);
    P3 = alokasi(8);  insertFirst(L, P3);
    P4 = alokasi(12); insertFirst(L, P4);
    P5 = alokasi(9);  insertFirst(L, P5);

    cout << "\n[1] Hasil Insert First (9, 12, 8, 0, 2):" << endl;
    printInfo(L);
    cout << "Jumlah Elemen: " << nbElmList(L) << endl;

    cout << "\n[2] Mencari elemen dengan info = 8..." << endl;
    PFound = findElm(L, 8);
    if (PFound != Nil) {
        cout << ">> DITEMUKAN! Alamat: " << PFound 
             << ", Info: " << PFound->info << endl;
    } else {
        cout << ">> TIDAK DITEMUKAN!" << endl;
    }

    cout << "\n[3] Menghitung Total Info Seluruh Elemen:" << endl;
    int total = hitungTotalInfo(L);
    cout << ">> Rumus: 9 + 12 + 8 + 0 + 2 = " << total << endl;

    cout << "\n[4] Tes Delete First (Menghapus 9):" << endl;
    delFirst(L, PDeleted);
    printInfo(L);

    cout << "\n[5] Tes Delete Last (Menghapus 2):" << endl;
    delLast(L, PDeleted);
    printInfo(L);

    return 0;
}