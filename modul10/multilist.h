#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#define Nil NULL

typedef int infotypeanak;
typedef int infotypeinduk;

typedef struct elemen_list_induk* address;
typedef struct elemen_list_anak* address_anak;

// --- STRUKTUR ANAK ---
struct elemen_list_anak {
    infotypeanak info;
    address_anak next;
    address_anak prev;
};

struct listanak {
    address_anak first;
    address_anak last;
};

// --- STRUKTUR INDUK ---
struct elemen_list_induk {
    infotypeinduk info; // Diperbaiki dari infotypeanak agar logis
    listanak lanak;
    address next;
    address prev;
};

struct listinduk {
    address first;
    address last;
};

// --- PROTOTYPE FUNGSI INDUK ---
void CreateList(listinduk &L);
address alokasi(infotypeinduk x);
void dealokasi(address &P);
void insertFirst(listinduk &L, address P);
void insertLast(listinduk &L, address P);
void delFirst(listinduk &L, address &P);
void delLast(listinduk &L, address &P);
void delAll(listinduk &L);
void printInfo(listinduk L);

void CreateListAnak(listanak &L);
address_anak alokasiAnak(infotypeanak x);
void dealokasiAnak(address_anak &P);
void insertLastAnak(listanak &L, address_anak P);
void delAllAnak(listanak &L);
void printInfoAnak(listanak L);

#endif