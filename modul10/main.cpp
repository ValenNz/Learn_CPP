#include <iostream>
#include "multilist.h"

using namespace std;

int main() {
    listinduk L;
    CreateList(L);

    cout << "=== MODUL 10: MULTI LINKED LIST ===" << endl;

    address P1 = alokasi(101); 
    insertLast(L, P1);

    address P2 = alokasi(102); 
    insertLast(L, P2);

    address_anak A1 = alokasiAnak(1001);
    insertLastAnak(P1->lanak, A1);
    
    address_anak A2 = alokasiAnak(1002); 
    insertLastAnak(P1->lanak, A2);

    address_anak A3 = alokasiAnak(2001);
    insertLastAnak(P2->lanak, A3);

    cout << "\n[1] Kondisi Awal Multi List:" << endl;
    printInfo(L);

    cout << "\n[2] Menghapus Induk pertama (101)..." << endl;
    address PDeleted;
    delFirst(L, PDeleted);

    cout << "\n[3] Kondisi Setelah Delete First Induk:" << endl;
    printInfo(L);

    delAll(L);
    cout << "\n[4] Semua memori berhasil dibersihkan (delAll)." << endl;

    return 0;
}