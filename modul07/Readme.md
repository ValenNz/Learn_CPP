# 📘 Panduan Praktikum Struktur Data - Modul 07
## STACK (Tumpukan) - Representasi Array

Halo Praktikan! 👋
Selamat datang di Modul 07. Hari ini kita akan mempelajari **Stack**. Bayangkan Stack seperti tumpukan piring di restoran: piring yang terakhir kali ditaruh di atas tumpukan (Last In) adalah piring yang pertama kali diambil (First Out). Ini disebut prinsip **LIFO**.

Di modul ini, kita akan fokus mengimplementasikan Stack menggunakan **Representasi Tabel (Array)**, yang lebih sederhana manajemen memorinya dibandingkan pointer, tetapi memiliki batas kapasitas maksimal.

### 🎯 Tujuan Pembelajaran
1. Memahami konsep LIFO (Last In First Out).
2. Mengimplementasikan ADT Stack menggunakan Array.
3. Menguasai operasi dasar: `Push` (masuk), `Pop` (keluar), dan manipulasi Stack.

---

## 🧠 1. Konsep Dasar Stack (Array)
Dalam representasi array, Stack memiliki dua komponen utama:
1. **Array `info`**: Tempat menyimpan data.
2. **Integer `Top`**: Penunjuk indeks elemen paling atas. 
   - Jika Stack kosong, `Top = -1`.
   - Setiap kali `Push`, `Top` bertambah 1 (`Top++`).
   - Setiap kali `Pop`, `Top` berkurang 1 (`Top--`).

---

## 💻 2. IMPLEMENTASI FULL CODE (Wajib Dipahami!)

Berikut adalah kode lengkap untuk menyelesaikan **seluruh latihan Modul 7** (Termasuk `balikStack`, `pushAscending`, dan `getInputStream`). Silakan buat 3 file berikut di folder `modul07` Anda.

### 📄 File 1: `stack.h` (Deklarasi ADT)
```cpp
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

#define MaxEl 20  // Kapasitas maksimal stack
#define Nil -1    // Indikator stack kosong

typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int Top;
};

// Prototype Primitif Dasar
void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);

// Prototype Fungsi Tambahan (Sesuai Latihan Modul 7)
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif // STACK_H_INCLUDED
```

### 📄 File 2: `stack.cpp` (Implementasi Logika)
```cpp
#include "stack.h"

// 1. CREATE STACK
void CreateStack(Stack &S) {
    S.Top = Nil; // -1 menandakan stack kosong
}

// 2. CEK KOSONG
bool isEmpty(Stack S) {
    return S.Top == Nil;
}

// 3. CEK PENUH
bool isFull(Stack S) {
    return S.Top == MaxEl - 1;
}

// 4. PUSH (Masukkan elemen)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.Top++;
        S.info[S.Top] = x;
    } else {
        cout << "[ERROR] Stack Penuh! Tidak bisa Push." << endl;
    }
}

// 5. POP (Keluarkan elemen)
infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.Top];
        S.Top--;
        return x;
    } else {
        cout << "[ERROR] Stack Kosong! Tidak bisa Pop." << endl;
        return -999; // Nilai dummy untuk error
    }
}

// 6. PRINT INFO (Menampilkan isi stack dari atas ke bawah)
void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong." << endl;
        return;
    }
    cout << "Isi Stack (Top ke Bottom): ";
    for (int i = S.Top; i >= 0; i--) {
        cout << S.info[i];
        if (i > 0) cout << " | ";
    }
    cout << endl;
}

// 7. BALIK STACK (Reverse)
// Karena ini representasi array, cara paling efisien adalah menukar elemen array secara langsung.
void balikStack(Stack &S) {
    int i = 0;
    int j = S.Top;
    while (i < j) {
        infotype temp = S.info[i];
        S.info[i] = S.info[j];
        S.info[j] = temp;
        i++;
        j--;
    }
}

// 8. PUSH ASCENDING
// Memasukkan elemen sedemikian rupa sehingga stack tetap terurut menaik (kecil di bawah, besar di atas).
void pushAscending(Stack &S, infotype x) {
    Stack temp;
    CreateStack(temp);

    // Pindahkan elemen yang lebih besar dari x ke stack sementara
    while (!isEmpty(S) && S.info[S.Top] > x) {
        push(temp, pop(S));
    }

    // Masukkan elemen x ke posisi yang tepat
    push(S, x);

    // Kembalikan elemen dari stack sementara ke stack utama
    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

// 9. GET INPUT STREAM
// Membaca input karakter dari user hingga tombol Enter ditekan.
void getInputStream(Stack &S) {
    char c;
    cout << "Masukkan karakter (akhiri dengan Enter): ";
    
    // cin.get() membaca karakter satu per satu, termasuk spasi
    while ((c = cin.get()) != '\n') {
        if (!isFull(S)) {
            push(S, (int)c); // Cast char ke int sesuai infotype
        } else {
            cout << "\n[ERROR] Stack Penuh! Input terpotong." << endl;
            break;
        }
    }
}
```

### 📄 File 3: `main.cpp` (Program Utama / Driver)
```cpp
#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    cout << "=== MODUL 7: STACK (REPRESENTASI ARRAY) ===" << endl;

    // ==========================================
    // LATIHAN 1: Operasi Dasar Push & Pop
    // ==========================================
    cout << "\n[1] Operasi Dasar Push & Pop:" << endl;
    push(S, 3);
    push(S, 4);
    push(S, 8);
    cout << "Setelah push 3, 4, 8: "; printInfo(S);

    cout << "Elemen yang di-pop: " << pop(S) << endl; // Seharusnya 8
    
    push(S, 2);
    push(S, 3);
    cout << "Setelah pop, lalu push 2, 3: "; printInfo(S);

    cout << "Elemen yang di-pop: " << pop(S) << endl; // Seharusnya 3
    
    push(S, 9);
    cout << "Setelah pop, lalu push 9: "; printInfo(S);

    // ==========================================
    // LATIHAN 1 (Lanjut): Balik Stack
    // ==========================================
    cout << "\n[2] Membalik Isi Stack:" << endl;
    cout << "Sebelum dibalik: "; printInfo(S);
    balikStack(S);
    cout << "Setelah dibalik: "; printInfo(S);

    // ==========================================
    // LATIHAN 2: Push Ascending
    // ==========================================
    cout << "\n[3] Operasi Push Ascending:" << endl;
    Stack S2;
    CreateStack(S2);
    
    cout << "Pushing: 3, 4, 8, 2, 3, 9 secara ascending..." << endl;
    pushAscending(S2, 3);
    pushAscending(S2, 4);
    pushAscending(S2, 8);
    pushAscending(S2, 2);
    pushAscending(S2, 3);
    pushAscending(S2, 9);
    
    cout << "Hasil akhir stack (harus terurut dari Top=terbesar): "; 
    printInfo(S2);

    // ==========================================
    // LATIHAN 3: Get Input Stream
    // ==========================================
    cout << "\n[4] Operasi Get Input Stream:" << endl;
    Stack S3;
    CreateStack(S3);
    
    getInputStream(S3);
    
    cout << "Isi Stack dari input stream (Top ke Bottom): ";
    printInfo(S3);

    return 0;
}
```

---

## 📝 3. Penjelasan Logika Kode "Tricky"

1. **`pushAscending`**: 
   Bagaimana cara menyisipkan angka di tengah tumpukan agar tetap urut? Kita tidak bisa langsung menyisipkan. 
   * **Solusi**: Kita buat Stack sementara (`temp`). Kita `pop` elemen dari Stack utama yang **lebih besar** dari angka yang mau dimasukkan, lalu kita `push` ke `temp`. Setelah posisi yang tepat ditemukan, kita `push` angka baru tersebut. Terakhir, kita `pop` semua isi `temp` dan `push` kembali ke Stack utama.
2. **`balikStack`**: 
   Karena kita menggunakan **Array**, cara paling efisien (O(N)) adalah menukar elemen array secara langsung menggunakan dua pointer (`i` dari bawah, `j` dari `Top`). Ini jauh lebih aman dan cepat daripada mencoba membalik menggunakan operasi Stack murni yang rumit.
3. **`getInputStream`**: 
   Fungsi `cin.get()` sangat powerful karena ia membaca **setiap karakter**, termasuk spasi, hingga mendeteksi karakter newline (`\n` atau tombol Enter). Kita casting `(int)c` karena `infotype` kita definisikan sebagai `integer`, sehingga yang disimpan di stack adalah nilai ASCII dari karakter tersebut.

---

## 🚨 4. Troubleshooting & Common Bugs

1. **Stack Overflow (Program Crash / Data Rusak)**
   * **Penyebab:** Melakukan `push` saat `isFull(S)` bernilai `true`, tetapi kode tidak mengeceknya.
   * **Solusi:** Selalu bungkus operasi `push` dengan `if (!isFull(S))`.
2. **Stack Underflow (Muncul angka aneh seperti -858993460)**
   * **Penyebab:** Melakukan `pop` saat `isEmpty(S)` bernilai `true`. Program mengambil nilai dari indeks `-1` atau memori sampah.
   * **Solusi:** Selalu bungkus operasi `pop` dengan `if (!isEmpty(S))`.
3. **`Top` Tidak Sinkron**
   * **Penyebab:** Lupa melakukan `S.Top++` saat push, atau `S.Top--` saat pop.
   * **Solusi:** Pastikan urutan operasi di `push` adalah: Naikkan `Top` dulu, baru isi datanya. Di `pop`: Ambil datanya dulu, baru turunkan `Top`.

---

## ⚠️ PERINGATAN PENTING DARI ASISTEN
Sesuai peraturan laboratorium (Halaman iii, Poin 10.f), **DILARANG KERAS menggunakan AI untuk mengerjakan Tugas Pendahuluan (TP) dan Jurnal Praktikum**. 
* Gunakan kode di atas **hanya** sebagai referensi untuk memahami alur logika Stack.
* Jika terindikasi menggunakan AI untuk TP/Jurnal, nilai akan langsung **0** atau dikurangi minimal 50%.

**Tips Asisten:** Saat debugging, mintalah praktikan untuk mencetak nilai `S.Top` setiap kali setelah `push` atau `pop`. Jika nilai `Top` tidak bergerak sesuai harapan, di situlah letak bug-nya! Semangat Praktikumnya! 🚀