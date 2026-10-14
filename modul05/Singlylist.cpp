#include "Singlylist.h"

// create
void createList(List &L){
    L.first = Nil;
}

// alokasi memori
address alokasi(infotype x){
    address p = new ElmList;
    p->info = x;
    p->next = Nil;
    return p;
}

// Dealokasi  memori
void dealokasi(address &P){
    delete P;
    P = Nil;
}

// insert first
void insertFirst(List &L, address P){
    P->next = L.first;
    L.first = P;
}   

// print info
void printInfo(List L){
    address P = L.first;
    cout << "List : ";
    while(P != Nil){
        cout << P->info << " ";
        if (P->next != Nil) {cout << "-> ";}
        P = P->next;
    }
    cout << " -> " << endl;
}

// Searching
address findElm(List L, infotype X){
    address P = L.first;
    while(P != Nil){
        if (P->info == X){ // jika ketemu
            return P;
        }
        P = P->next;
    }
    return Nil; // ketika tidak ketemnu
}

// delete first
void delFirst(List &L, address &P) {
    if (L.first != Nil) {
        P = L.first;
        L.first = P->next;
        P->next = Nil; 
        dealokasi(P);  
    }
}

void delLast(List &L, address &P) {
    if (L.first != Nil) {
        if (L.first->next == Nil) {
            P = L.first;
            L.first = Nil;
        } else {
            address prec = Nil;
            address last = L.first;
            while (last->next != Nil) {
                prec = last;
                last = last->next;
            }
            P = last;
            prec->next = Nil; 
        }
        dealokasi(P);
    }
}

void delAfter(List &L, address &P, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next; 
        P->next = Nil;
        dealokasi(P);
    }
}

int nbElmList(List L) {
    int count = 0;
    address P = L.first;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

int hitungTotalInfo(List L) {
    int total = 0;
    address P = L.first;
    while (P != Nil) {
        total += P->info;
        P = P->next;
    }
    return total;
}