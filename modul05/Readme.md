# 📘 Panduan Praktikum Struktur Data - Modul 05
## Singly Linked List (Bagian Kedua): Searching, Delete, & Operasi Lanjutan

Halo Praktikan! 👋
Selamat datang di Modul 05. Di modul ini, kita akan melengkapi operasi dasar Singly Linked List (SLL). Kita tidak hanya bisa menambahkan data lagi, tapi kita bisa **mencari (Searching)**, **menghapus (Delete)**, dan **memanipulasi** list secara utuh.

### 🎯 Tujuan Pembelajaran
1. Mengimplementasikan algoritma pencarian (*Searching*) pada Linked List.
2. Menguasai operasi penghapusan (*Delete*) dengan aman tanpa *Memory Leak*.
3. Memahami operasi manipulasi list seperti menghitung jumlah elemen dan menjumlahkan nilai.

---

## 🔍 1. Konsep Searching (Pencarian)
Sebelum kita bisa menghapus atau menyisipkan data di tengah list (*Insert After / Delete After*), kita harus tahu **di mana** data itu berada. 
* **`findElm`**: Mencari node berdasarkan **isinya (info)**. Mengembalikan `address` node jika ketemu, atau `NULL` jika tidak.
* **`fFindElm`**: Mencari node berdasarkan **alamat memorinya**. Mengembalikan `true`/`false`.
* **`findBefore`**: Mencari node yang berada **tepat sebelum** node target. (Sangat berguna untuk operasi Delete!).

---

## ✂️ 2. Konsep Delete (Penghapusan)
⚠️ **ATURAN EMAS DELETE:** 
1. **Tandai** node yang mau dihapus (simpan di pointer `P`).
2. **Putus rantai** list agar tidak terputus (sambungkan node sebelum dan sesudahnya).
3. **Dealokasi** (hapus dari memori) node `P`.
*Jangan pernah langsung `delete P` sebelum memutus rantai, atau list Anda akan hancur (Segfault)!*

---

##  3. IMPLEMENTASI FULL CODE (Wajib Dipahami!)

Berikut adalah kode lengkap untuk menyelesaikan seluruh Latihan Modul 5. Silakan buat 3 file berikut di folder `modul05` Anda.

### 📄 File 1: `Singlylist.h` (Deklarasi ADT)
```cpp
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

// Definisi Tipe Data
typedef int infotype;
typedef struct ElmList* address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

// Prototype Primitif Dasar
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);

// Prototype Searching
address findElm(List L, infotype X);

// Prototype Delete
void delFirst(List &L, address &P);
void delLast(List &L, address &P);
void delAfter(List &L, address &P, address Prec);

// Prototype Tambahan untuk Latihan
int nbElmList(List L);          // Menghitung jumlah elemen
int hitungTotalInfo(List L);    // Menjumlahkan semua nilai info

#endif // SINGLYLIST_H_INCLUDED
```

###  File 2: `Singlylist.cpp` (Implementasi Logika)
```cpp
#include "Singlylist.h"

// 1. CREATE LIST
void createList(List &L) {
    L.first = Nil;
}

// 2. ALOKASI MEMORI
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

// 3. DEALOKASI MEMORI
void dealokasi(address &P) {
    delete P;
    P = Nil; // Mencegah Dangling Pointer
}

// 4. INSERT FIRST
void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

// 5. PRINT INFO (VIEW)
void printInfo(List L) {
    address P = L.first;
    cout << "List: ";
    while (P != Nil) {
        cout << P->info;
        if (P->next != Nil) cout << " -> ";
        P = P->next;
    }
    cout << " -> Nil" << endl;
}

// 6. SEARCHING (FIND ELM)
address findElm(List L, infotype X) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == X) {
            return P; // Ketemu! Kembalikan alamatnya
        }
        P = P->next;
    }
    return Nil; // Tidak ketemu
}

// 7. DELETE FIRST
void delFirst(List &L, address &P) {
    if (L.first != Nil) {
        P = L.first;
        L.first = P->next;
        P->next = Nil; // Putus rantai
        dealokasi(P);  // Hapus dari memori
    }
}

// 8. DELETE LAST
void delLast(List &L, address &P) {
    if (L.first != Nil) {
        if (L.first->next == Nil) {
            // Jika cuma ada 1 elemen
            P = L.first;
            L.first = Nil;
        } else {
            // Cari node terakhir dan node sebelum terakhir
            address prec = Nil;
            address last = L.first;
            while (last->next != Nil) {
                prec = last;
                last = last->next;
            }
            P = last;
            prec->next = Nil; // Putus rantai
        }
        dealokasi(P);
    }
}

// 9. DELETE AFTER
void delAfter(List &L, address &P, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next; // Sambungkan Prec ke node setelah P
        P->next = Nil;
        dealokasi(P);
    }
}

// 10. MENGHITUNG JUMLAH ELEMEN
int nbElmList(List L) {
    int count = 0;
    address P = L.first;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

// 11. MENGHITUNG TOTAL INFO (SOAL LATIHAN NO. 4)
int hitungTotalInfo(List L) {
    int total = 0;
    address P = L.first;
    while (P != Nil) {
        total += P->info;
        P = P->next;
    }
    return total;
}
```

### 📄 File 3: `main.cpp` (Program Utama / Driver)
```cpp
#include <iostream>
#include "Singlylist.h"

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    address PFound = Nil;
    address PDeleted = Nil;

    // 1. Inisialisasi List
    createList(L);
    cout << "=== MODUL 5: SINGLY LINKED LIST ===" << endl;

    // 2. Insert Data (Sesuai Soal Latihan)
    P1 = alokasi(2);  insertFirst(L, P1);
    P2 = alokasi(0);  insertFirst(L, P2);
    P3 = alokasi(8);  insertFirst(L, P3);
    P4 = alokasi(12); insertFirst(L, P4);
    P5 = alokasi(9);  insertFirst(L, P5);

    cout << "\n[1] Hasil Insert First (9, 12, 8, 0, 2):" << endl;
    printInfo(L);
    cout << "Jumlah Elemen: " << nbElmList(L) << endl;

    // 3. Searching (Mencari Elemen 8)
    cout << "\n[2] Mencari elemen dengan info = 8..." << endl;
    PFound = findElm(L, 8);
    if (PFound != Nil) {
        cout << ">> DITEMUKAN! Alamat: " << PFound 
             << ", Info: " << PFound->info << endl;
    } else {
        cout << ">> TIDAK DITEMUKAN!" << endl;
    }

    // 4. Menghitung Total Info (Soal Latihan No. 4)
    cout << "\n[3] Menghitung Total Info Seluruh Elemen:" << endl;
    int total = hitungTotalInfo(L);
    cout << ">> Rumus: 9 + 12 + 8 + 0 + 2 = " << total << endl;

    // 5. Bonus: Tes Delete First
    cout << "\n[4] Tes Delete First (Menghapus 9):" << endl;
    delFirst(L, PDeleted);
    printInfo(L);

    // 6. Bonus: Tes Delete Last
    cout << "\n[5] Tes Delete Last (Menghapus 2):" << endl;
    delLast(L, PDeleted);
    printInfo(L);

    return 0;
}
```

---

## 📝 4. Penjelasan Output Latihan
Jika Anda menjalankan kode di atas, output yang akan muncul di terminal adalah:

```text
=== MODUL 5: SINGLY LINKED LIST ===

[1] Hasil Insert First (9, 12, 8, 0, 2):
List: 9 -> 12 -> 8 -> 0 -> 2 -> Nil
Jumlah Elemen: 5

[2] Mencari elemen dengan info = 8...
>> DITEMUKAN! Alamat: 0x55a1b2c3d450, Info: 8

[3] Menghitung Total Info Seluruh Elemen:
>> Rumus: 9 + 12 + 8 + 0 + 2 = 31

[4] Tes Delete First (Menghapus 9):
List: 12 -> 8 -> 0 -> 2 -> Nil

[5] Tes Delete Last (Menghapus 2):
List: 12 -> 8 -> 0 -> Nil
```

---

## 🚨 5. Troubleshooting & Common Bugs

1. **Program Crash (Segmentation Fault) saat Delete**
   * **Penyebab:** Anda mencoba melakukan `delLast` atau `delAfter` pada list yang kosong, atau pointer `Prec` yang dikirim bernilai `NULL`.
   * **Solusi:** Selalu tambahkan kondisi `if (L.first != Nil)` atau `if (Prec != Nil)` sebelum melakukan operasi delete.
2. **Infinite Loop saat Searching**
   * **Penyebab:** Lupa menulis `P = P->next;` di dalam blok `while`.
   * **Solusi:** Pastikan pointer selalu bergerak maju menuju `Nil`.
3. **Total Info Salah (Tidak 31)**
   * **Penyebab:** Variabel `total` tidak diinisialisasi dengan `0` sebelum perulangan (`int total = 0;`).
   * **Solusi:** Selalu inisialisasi variabel penampung jumlah/total dengan 0.

---

## ⚠️ PERINGATAN PENTING DARI ASISTEN
Sesuai peraturan laboratorium, **DILARANG KERAS menggunakan AI untuk mengerjakan Tugas Pendahuluan (TP) dan Jurnal Praktikum**. 
* Gunakan kode di atas **hanya** sebagai referensi untuk memahami alur logika Searching dan Delete.
* Jika terindikasi menggunakan AI untuk TP/Jurnal, nilai akan langsung **0**.

**Tips Asisten:** Untuk fungsi `delLast`, menggambar skema pointer di kertas adalah cara tercepat untuk memahaminya. Ingat, Anda butuh **dua** pointer (`prec` dan `last`) untuk melacak node terakhir! Semangat Praktikumnya! 🚀
