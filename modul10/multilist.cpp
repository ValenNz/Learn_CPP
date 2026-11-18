#include "multilist.h"

void CreateListAnak(listanak &L) {
    L.first = Nil;
    L.last = Nil;
}

address_anak alokasiAnak(infotypeanak x) {
    address_anak P = new elemen_list_anak;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasiAnak(address_anak &P) {
    delete P;
    P = Nil;
}

void insertLastAnak(listanak &L, address_anak P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void delAllAnak(listanak &L) {
    address_anak P = L.first;
    while (P != Nil) {
        address_anak nextNode = P->next;
        dealokasiAnak(P);
        P = nextNode;
    }
    CreateListAnak(L);
}

void printInfoAnak(listanak L) {
    address_anak P = L.first;
    while (P != Nil) {
        cout << "  -> Anak: " << P->info << endl;
        P = P->next;
    }
}

void CreateList(listinduk &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotypeinduk x) {
    address P = new elemen_list_induk;
    P->info = x;
    CreateListAnak(P->lanak);
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delAllAnak(P->lanak); 
    delete P;
    P = Nil;
}

void insertFirst(listinduk &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast(listinduk &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void delFirst(listinduk &L, address &P) {
    if (L.first != Nil) {
        P = L.first;
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.first = P->next;
            L.first->prev = Nil;
        }
        dealokasi(P); 
    }
}

void delLast(listinduk &L, address &P) {
    if (L.first != Nil) {
        P = L.last;
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.last = P->prev;
            L.last->next = Nil;
        }
        dealokasi(P);
    }
}

void delAll(listinduk &L) {
    address P = L.first;
    while (P != Nil) {
        address nextNode = P->next;
        dealokasi(P);
        P = nextNode;
    }
    CreateList(L);
}

void printInfo(listinduk L) {
    address P = L.first;
    int idx = 1;
    while (P != Nil) {
        cout << "Induk ke-" << idx << " (Info: " << P->info << "):" << endl;
        printInfoAnak(P->lanak);
        P = P->next;
        idx++;
    }
}