# 📘 Panduan Praktikum Struktur Data - Modul 04
## Singly Linked List (Bagian Pertama)

Halo Praktikan! 👋
Selamat datang di Modul 04. Mulai hari ini, kita resmi meninggalkan array statis dan masuk ke dunia **Struktur Data Dinamis**. Jika kalian paham Pointer di Modul 2, kalian akan selamat. Jika belum, **wajib** buka kembali catatan Modul 2 kalian!

### 🎯 Tujuan Pembelajaran
1. Memahami konsep Linked List dan perbedaannya dengan Array.
2. Menguasai manajemen memori dinamis (`new` dan `delete`).
3. Mengimplementasikan operasi dasar Singly Linked List: Insert, Delete, dan View.

---

##  1. Apa itu Singly Linked List (SLL)?
Bayangkan sebuah **Kereta Api**:
* **Node (Simpul/Elemen)**: Adalah gerbong kereta. Setiap gerbong membawa barang (`info`) dan memiliki kait (`next`) untuk menyambung ke gerbong berikutnya.
* **First (Head)**: Adalah lokomotif (gerbong paling depan). Jika kamu kehilangan lokomotif, kamu kehilangan seluruh keretanya!
* **NULL (Nil)**: Adalah ujung kereta. Menandakan tidak ada gerbong lagi di belakangnya.
* **Singly**: Artinya kereta ini hanya bisa berjalan **satu arah** (maju). Tidak bisa mundur.

### Array vs Linked List
| Fitur | Array | Linked List |
| :--- | :--- | :--- |
| **Ukuran** | Statis (ditentukan di awal, tidak bisa berubah) | Dinamis (tumbuh/mengecil sesuai kebutuhan) |
| **Memori** | Berurutan (kontigu) | Tersebar (diakses via pointer) |
| **Akses** | Cepat via indeks (`arr[5]`) | Harus ditelusuri dari awal (`first -> next -> next...`) |

---

##  2. Struktur Data & Manajemen Memori

Sebelum masuk ke operasi, kita harus definisikan "Gerbong" dan "Keretanya" di file `.h`.

```cpp
// Singlylist.h
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#define Nil NULL

typedef int infotype; // Tipe data isi (bisa diganti struct mahasiswa, dll)

// Definisi Node (Gerbong)
typedef struct ElmList* address;
struct ElmList {
    infotype info;
    address next;
};

// Definisi List (Kereta)
struct List {
    address first;
};

// Prototype Primitif
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
// ... (tambahkan prototype insert, delete, print)

#endif
```

### ⚙️ Manajemen Memori (Wajib Hafal!)
1. **CreateList**: Menginisialisasi kereta kosong.
   ```cpp
   void createList(List &L) { L.first = Nil; }
   ```
2. **Alokasi (`new`)**: Memesan gerbong baru di memori.
   ```cpp
   address alokasi(infotype x) {
       address P = new ElmList; // Pesan memori
       P->info = x;             // Isi barang
       P->next = Nil;           // Kaitnya belum nyambung ke mana-mana
       return P;
   }
   ```
3. **Dealokasi (`delete`)**: Menghancurkan gerbong dan mengembalikan memori ke sistem.
   ```cpp
   void dealokasi(address &P) {
       delete P;
       P = Nil; // Penting! Agar tidak jadi Dangling Pointer
   }
   ```

---

## ➕ 3. Operasi Insert (Penyisipan)
*Aturan Emas Insert: **Sambungkan kait node baru DULU, baru putuskan/ubah kait node lama.***

### A. Insert First (Masuk paling depan)
1. Kaitkan `next` node baru (`P`) ke `first` list saat ini.
2. Ubah `first` list agar menunjuk ke node baru (`P`).
```cpp
void insertFirst(List &L, address P) {
    P->next = L.first; // 1. Kaitkan dulu
    L.first = P;       // 2. Baru geser first
}
```

### B. Insert Last (Masuk paling belakang)
1. Cari node paling belakang (node yang `next`-nya `Nil`).
2. Kaitkan `next` node terakhir ke node baru (`P`).
```cpp
void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P; // Jika list kosong, P jadi first
    } else {
        address last = L.first;
        while (last->next != Nil) { // Telusuri sampai ujung
            last = last->next;
        }
        last->next = P; // Kaitkan
    }
}
```

### C. Insert After (Masuk setelah node tertentu `Prec`)
1. Kaitkan `next` node baru (`P`) ke `next`-nya `Prec`.
2. Ubah `next`-nya `Prec` agar menunjuk ke node baru (`P`).
```cpp
void insertAfter(List &L, address P, address Prec) {
    P->next = Prec->next; // 1. Kaitkan P ke successor Prec
    Prec->next = P;       // 2. Prec menunjuk ke P
}
```

---

## ➖ 4. Operasi Delete (Penghapusan)
*Aturan Emas Delete: **Simpan alamat node yang mau dihapus ke variabel sementara (P), putuskan rantai list, baru `dealokasi(P)`.***

### A. Delete First
1. Simpan `L.first` ke `P`.
2. Geser `L.first` ke node berikutnya.
3. Putuskan `next` milik `P`, lalu `dealokasi(P)`.
```cpp
void deleteFirst(List &L, address &P) {
    P = L.first;
    L.first = P->next;
    P->next = Nil;
    dealokasi(P);
}
```

### B. Delete Last (Tingkat Kesulitan: 🔥)
Kalian **tidak bisa** langsung ke node terakhir. Kalian harus mencari **node sebelum terakhir** (Predecessor) untuk memutus rantainya.
```cpp
void deleteLast(List &L, address &P) {
    address prec = Nil;
    address last = L.first;
    
    // Cari node terakhir dan node sebelum terakhir
    while (last->next != Nil) {
        prec = last;
        last = last->next;
    }
    
    if (prec == Nil) { // Hanya ada 1 elemen
        L.first = Nil;
    } else {
        prec->next = Nil; // Putus rantai
    }
    P = last;
    dealokasi(P);
}
```

### C. Delete After
```cpp
void deleteAfter(List &L, address &P, address Prec) {
    P = Prec->next;
    Prec->next = P->next; // Putus rantai, sambungkan Prec ke successor P
    P->next = Nil;
    dealokasi(P);
}
```

---

## 🖥️ 5. View (Menampilkan Isi List)
Gunakan perulangan `while` untuk menelusuri list dari `first` sampai `Nil`.
```cpp
void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " -> ";
        P = P->next;
    }
    cout << "Nil" << endl;
}
```

---

##  6. Tugas Latihan (Wajib Dikerjakan)
Buatlah ADT Singly Linked List dengan spesifikasi berikut:
* **File**: `Singlylist.h`, `Singlylist.cpp`, `main.cpp`
* **Tipe Data**: `infotype` = `int`
* **Fungsi yang wajib ada**:
  1. `createList`
  2. `alokasi`
  3. `dealokasi`
  4. `printInfo`
  5. `insertFirst`

**Uji Coba di `main.cpp`:**
```cpp
int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);  insertFirst(L, P1);
    P2 = alokasi(0);  insertFirst(L, P2);
    P3 = alokasi(8);  insertFirst(L, P3);
    P4 = alokasi(12); insertFirst(L, P4);
    P5 = alokasi(9);  insertFirst(L, P5);

    printInfo(L); // Output seharusnya: 9 -> 12 -> 8 -> 0 -> 2 -> Nil
    return 0;
}
```

---

##  7. Troubleshooting & Common Bugs (Baca Ini Sebelum Bertanya!)

1. **Segmentation Fault (Segfault) / Program Crash**
   * **Penyebab:** Kalian mencoba mengakses `P->next` atau `P->info` padahal `P` bernilai `NULL` (Nil).
   * **Solusi:** Selalu cek `if (P != Nil)` sebelum mengakses isi pointer.
2. **Infinite Loop saat `printInfo`**
   * **Penyebab:** Saat Insert, kalian lupa memutus/menyambungkan pointer dengan benar, sehingga terjadi *circular reference* (node A menunjuk ke B, B menunjuk ke A).
   * **Solusi:** Gambar skema pointer di kertas sebelum coding.
3. **Data Hilang / List Terpotong**
   * **Penyebab:** Pada `insertFirst`, kalian mengubah `L.first = P` **sebelum** `P->next = L.first`. Akibatnya, alamat list lama hilang selamanya (Memory Leak).
   * **Solusi:** Ingat aturan: **Sambungkan node baru DULU, baru geser pointer list.**
4. **Memory Leak**
   * **Penyebab:** Menghapus node dari list tapi lupa memanggil `delete` (dealokasi). Memori RAM akan penuh jika program berjalan lama.

---
