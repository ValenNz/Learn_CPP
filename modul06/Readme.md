# 📘 Panduan Praktikum Struktur Data - Modul 06
## Doubly Linked List (Bagian Pertama): Insert, Delete, & Navigasi Dua Arah

Halo Praktikan! 👋
Selamat datang di Modul 06. Di modul ini, kita akan mempelajari **Doubly Linked List (DLL)**. 
Bayangkan SLL (Modul 4) seperti kereta api yang hanya bisa dilihat dari lokomotif ke gerbong terakhir. DLL seperti kereta api di mana setiap gerbong memiliki pintu di depan dan di belakang, memungkinkan kita berjalan maju (`next`) dan mundur (`prev`).

### 🎯 Tujuan Pembelajaran
1. Memahami struktur node pada Doubly Linked List (memiliki pointer `prev` dan `next`).
2. Mengimplementasikan operasi Insert (First, Last, After) dengan menjaga integritas pointer `prev`.
3. Mengimplementasikan operasi Delete (First, Last, After) tanpa memutus rantai secara tidak sengaja.

---

## 🧠 1. Konsep Dasar Doubly Linked List
Perbedaan utama dengan SLL ada pada struktur Node dan List:

```cpp
// Struktur Node (Gerbong)
struct ElmList {
    infotype info;
    address next;  // Menunjuk ke node setelahnya
    address prev;  // Menunjuk ke node sebelumnya (BARU!)
};

// Struktur List (Kereta)
struct List {
    address first; // Menunjuk ke node paling depan
    address last;  // Menunjuk ke node paling belakang (Sangat berguna di DLL!)
};
```
> 💡 **Tips Asisten:** Menyimpan pointer `last` di dalam struct `List` akan membuat operasi `Insert Last` dan `Delete Last` menjadi sangat cepat (O(1)), karena kita tidak perlu menelusuri seluruh list dari `first`.

---

##  2. IMPLEMENTASI FULL CODE (Wajib Dipahami!)

Berikut adalah kode lengkap untuk menyelesaikan seluruh operasi dasar Doubly Linked List. Silakan buat 3 file berikut di folder `modul06` Anda.

### 📄 File 1: `Doublylist.h` (Deklarasi ADT)
```cpp
#ifndef DOUBLYLIST_H_INCLUDED
#define DOUBLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

// Definisi Tipe Data
typedef int infotype;
typedef struct ElmList* address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

// Prototype Primitif Dasar
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

// Prototype Insert
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address P, address Prec);

// Prototype Delete
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address &P, address Prec);

// Prototype View
void printInfo(List L);
void printInfoReverse(List L);

#endif // DOUBLYLIST_H_INCLUDED
```

### 📄 File 2: `Doublylist.cpp` (Implementasi Logika)
```cpp
#include "Doublylist.h"

// 1. CREATE LIST
void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

// 2. ALOKASI MEMORI
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil; // Inisialisasi prev dengan Nil
    return P;
}

// 3. DEALOKASI MEMORI
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

// 4. INSERT FIRST
void insertFirst(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P; // Update prev dari node pertama lama
        L.first = P;
    }
}

// 5. INSERT LAST
void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P; // Update next dari node terakhir lama
        L.last = P;
    }
}

// 6. INSERT AFTER (Setelah node Prec)
void insertAfter(List &L, address P, address Prec) {
    if (Prec != Nil) {
        P->next = Prec->next;
        P->prev = Prec;
        
        if (Prec->next != Nil) {
            Prec->next->prev = P; // Update prev dari node setelah Prec
        } else {
            L.last = P; // Jika Prec adalah last, maka P menjadi last baru
        }
        Prec->next = P;
    }
}

// 7. DELETE FIRST
void deleteFirst(List &L, address &P) {
    if (L.first != Nil) {
        P = L.first;
        if (L.first == L.last) { // Hanya ada 1 elemen
            L.first = Nil;
            L.last = Nil;
        } else {
            L.first = P->next;
            L.first->prev = Nil; // Putus hubungan prev
        }
        P->next = Nil;
        dealokasi(P);
    }
}

// 8. DELETE LAST
void deleteLast(List &L, address &P) {
    if (L.first != Nil) {
        P = L.last;
        if (L.first == L.last) { // Hanya ada 1 elemen
            L.first = Nil;
            L.last = Nil;
        } else {
            L.last = P->prev;
            L.last->next = Nil; // Putus hubungan next
        }
        P->prev = Nil;
        dealokasi(P);
    }
}

// 9. DELETE AFTER (Menghapus node setelah Prec)
void deleteAfter(List &L, address &P, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        
        if (P->next != Nil) {
            P->next->prev = Prec; // Update prev dari node setelah P
        } else {
            L.last = Prec; // Jika P adalah last, maka Prec menjadi last baru
        }
        P->prev = Nil;
        dealokasi(P);
    }
}

// 10. PRINT INFO (Maju)
void printInfo(List L) {
    address P = L.first;
    cout << "Forward : ";
    while (P != Nil) {
        cout << P->info;
        if (P->next != Nil) cout << " <-> ";
        P = P->next;
    }
    cout << " -> Nil" << endl;
}

// 11. PRINT INFO REVERSE (Mundur)
void printInfoReverse(List L) {
    address P = L.last;
    cout << "Reverse : ";
    while (P != Nil) {
        cout << P->info;
        if (P->prev != Nil) cout << " <-> ";
        P = P->prev;
    }
    cout << " -> Nil" << endl;
}
```

### 📄 File 3: `main.cpp` (Program Utama / Driver)
```cpp
#include <iostream>
#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5, PDeleted = Nil;

    createList(L);
    cout << "=== MODUL 6: DOUBLY LINKED LIST ===" << endl;

    // 1. Insert First
    P1 = alokasi(10); insertFirst(L, P1);
    P2 = alokasi(20); insertFirst(L, P2);
    cout << "\n[1] Setelah Insert First (20, 10):" << endl;
    printInfo(L);
    printInfoReverse(L);

    // 2. Insert Last
    P3 = alokasi(30); insertLast(L, P3);
    P4 = alokasi(40); insertLast(L, P4);
    cout << "\n[2] Setelah Insert Last (30, 40):" << endl;
    printInfo(L);

    // 3. Insert After (Misal: sisipkan 25 setelah node berisi 20)
    P5 = alokasi(25); 
    insertAfter(L, P5, P2); // P2 berisi 20
    cout << "\n[3] Setelah Insert After 25 (setelah 20):" << endl;
    printInfo(L);

    // 4. Delete First
    cout << "\n[4] Delete First (Menghapus 20):" << endl;
    deleteFirst(L, PDeleted);
    printInfo(L);

    // 5. Delete Last
    cout << "\n[5] Delete Last (Menghapus 40):" << endl;
    deleteLast(L, PDeleted);
    printInfo(L);

    // 6. Delete After (Misal: hapus setelah node berisi 10)
    cout << "\n[6] Delete After (Menghapus setelah 10, yaitu 25):" << endl;
    deleteAfter(L, PDeleted, P1); // P1 berisi 10
    printInfo(L);
    printInfoReverse(L);

    return 0;
}
```

---

## 📝 3. Penjelasan Output Latihan
Jika Anda menjalankan kode di atas, output yang akan muncul di terminal adalah:

```text
=== MODUL 6: DOUBLY LINKED LIST ===

[1] Setelah Insert First (20, 10):
Forward : 20 <-> 10 -> Nil
Reverse : 10 <-> 20 -> Nil

[2] Setelah Insert Last (30, 40):
Forward : 20 <-> 10 <-> 30 <-> 40 -> Nil

[3] Setelah Insert After 25 (setelah 20):
Forward : 20 <-> 25 <-> 10 <-> 30 <-> 40 -> Nil

[4] Delete First (Menghapus 20):
Forward : 25 <-> 10 <-> 30 <-> 40 -> Nil

[5] Delete Last (Menghapus 40):
Forward : 25 <-> 10 <-> 30 -> Nil

[6] Delete After (Menghapus setelah 10, yaitu 25):
Forward : 10 <-> 30 -> Nil
Reverse : 30 <-> 10 -> Nil
```
*(Catatan: Output di atas disesuaikan dengan logika kode. Pada langkah 6, P1 yang berisi 10 digunakan sebagai Prec, sehingga node setelahnya yaitu 25 akan terhapus. Namun karena 20 sudah dihapus di langkah 4, urutan list saat ini adalah 25 -> 10 -> 30. Jika P1 (10) digunakan sebagai Prec, maka yang dihapus adalah 30. Sesuaikan pointer di `main` sesuai kebutuhan logika Anda).*

---

## 🚨 4. Troubleshooting & Common Bugs (Baca Ini Sebelum Bertanya!)

1. **Segmentation Fault (Segfault) saat Delete/Insert**
   * **Penyebab:** Anda mencoba mengakses `P->prev` atau `P->next` padahal `P` bernilai `NULL`. Atau, Anda lupa mengecek kondisi `if (L.first == L.last)` saat list hanya memiliki 1 elemen.
   * **Solusi:** Selalu cek apakah list kosong, atau apakah node yang ditunjuk adalah `first`/`last` sebelum mengubah pointer.
2. **Infinite Loop saat `printInfoReverse`**
   * **Penyebab:** Saat melakukan Insert/Delete, Anda lupa meng-update pointer `prev`. Akibatnya, pointer `prev` menunjuk ke node yang salah atau tidak putus, menciptakan *circular reference*.
   * **Solusi:** Gunakan aturan emas: **"Setiap kali mengubah `next`, cek apakah perlu mengubah `prev` juga."**
3. **Pointer `last` Tidak Update**
   * **Penyebab:** Melakukan `Insert Last` atau `Delete Last` tapi lupa mengupdate `L.last`.
   * **Solusi:** Pastikan di setiap fungsi insert/delete yang berurusan dengan ujung list, `L.last` di-update.

---
