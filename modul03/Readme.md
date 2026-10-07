# 📘 Panduan Praktikum Struktur Data - Modul 03
## Abstract Data Type (ADT) & Pemrograman Modular

Halo Praktikan! 👋
Selamat datang di Modul 03. Jika Modul 1 & 2 adalah tentang "bagaimana menulis kode", Modul 3 adalah tentang **"bagaimana menulis kode yang baik, rapi, dan terstruktur"**. 

Pemahaman kalian tentang ADT di modul ini adalah **kunci mutlak** untuk memahami Linked List (Modul 4), Stack (Modul 7), Queue (Modul 8), dan seterusnya.

### 🎯 Tujuan Pembelajaran
1. Memahami konsep Abstract Data Type (ADT) sebagai gabungan antara **TIPE DATA** dan **OPERASI (PRIMITIF)**.
2. Mampu memisahkan kode program menjadi 3 file terstruktur: Header (`.h`), Body (`.cpp`), dan Main (`main.cpp`).
3. Mengimplementasikan operasi dasar ADT seperti Konstruktor, Selector, dan Destruktor.

---

## 🏗️ 1. Apa itu Abstract Data Type (ADT)?
Secara sederhana, ADT adalah **Tipe Data + Sekumpulan Operasi (Primitif)** yang berlaku untuk tipe data tersebut. 

Bayangkan sebuah **Mobil**:
* **Tipe Data (Struct)**: Adalah cetak biru mobil (ada roda, mesin, setir).
* **Primitif (Fungsi/Prosedur)**: Adalah cara mengoperasikannya (misal: `starterMesin()`, `injakRem()`, `bukaPintu()`).

Dalam ADT, kita tidak peduli *bagaimana* mesin bekerja di dalamnya (abstrak), kita hanya peduli *cara menggunakannya* (interface).

### Jenis-Jenis Primitif dalam ADT
Dalam praktikum, nama fungsi biasanya mengikuti konvensi ini:
1. **Konstruktor/Kreator**: Membentuk/menginisialisasi objek. (Contoh: `createList()`, `alokasi()`).
2. **Selector**: Mengambil/membaca nilai dari dalam objek. (Contoh: `getInfo()`, `isEmpty()`).
3. **Modifier**: Mengubah nilai di dalam objek. (Contoh: `updateInfo()`).
4. **Destruktor/Dealokator**: Menghancurkan objek dan mengembalikan memori. (Contoh: `dealokasi()`, `deleteAll()`).

---

## 📁 2. Struktur 3 File (Wajib Dipahami!)
Dalam ADT, kita **DILARANG** menumpuk semua kode di satu file `main.cpp`. Kita harus memisahkannya menjadi 3 file:

| File | Peran | Analogi | Isi |
| :--- | :--- |--- | :--- |
| **`nama.h`** | Header / Deklarasi | **Menu Restoran** | Berisi definisi `struct`, `#ifndef` (include guard), dan *prototype* fungsi/prosedur. **Tidak berisi kode implementasi.** |
| **`nama.cpp`** | Body / Implementasi | **Dapur Restoran** | Berisi kode asli (logika) dari fungsi-fungsi yang dideklarasikan di `.h`. Wajib `#include "nama.h"`. |
| **`main.cpp`** | Driver Program | **Ruang Makan** | Berisi `int main()`. Hanya memanggil fungsi yang sudah disediakan. Wajib `#include "nama.h"`. |

---

## 💻 3. Contoh Implementasi ADT (Studi Kasus: Mahasiswa)

Mari kita lihat contoh ADT untuk data Mahasiswa yang memiliki NIM, Nilai 1, dan Nilai 2, serta fungsi untuk menghitung rata-rata.

### 📄 File 1: `mahasiswa.h` (Deklarasi)
```cpp
#ifndef MAHASISWA_H_INCLUDED // Include Guard (Mencegah deklarasi ganda)
#define MAHASISWA_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

// 1. Definisi Tipe Data
struct Mahasiswa {
    string nim;
    float nilai1, nilai2;
};

// 2. Prototype Primitif (Hanya deklarasi, diakhiri titik koma)
void inputMhs(Mahasiswa &m);       // Menggunakan & (Call by Reference) agar nilai berubah
float hitungRata2(Mahasiswa m);    // Call by Value, karena hanya membaca

#endif // MAHASISWA_H_INCLUDED
```
> ⚠️ **Penting:** `#ifndef`, `#define`, dan `#endif` disebut **Include Guard**. Ini wajib ada di setiap file `.h` untuk mencegah *error* "redefinition" saat file di-include berkali-kali.

### 📄 File 2: `mahasiswa.cpp` (Implementasi)
```cpp
#include "mahasiswa.h" // Wajib include header-nya sendiri

// Implementasi prosedur input (Call by Reference)
void inputMhs(Mahasiswa &m) {
    cout << "Input NIM: ";
    cin >> m.nim;
    cout << "Input Nilai 1: ";
    cin >> m.nilai1;
    cout << "Input Nilai 2: ";
    cin >> m.nilai2;
}

// Implementasi fungsi hitung (Call by Value)
float hitungRata2(Mahasiswa m) {
    return (m.nilai1 + m.nilai2) / 2.0;
}
```

### 📄 File 3: `main.cpp` (Program Utama)
```cpp
#include <iostream>
#include "mahasiswa.h" // Include header untuk bisa pakai struct dan fungsinya

using namespace std;

int main() {
    Mahasiswa mhsBaru; // Membuat objek
    
    // Memanggil primitif
    inputMhs(mhsBaru); 
    
    cout << "Rata-rata nilai " << mhsBaru.nim << " adalah: " 
         << hitungRata2(mhsBaru) << endl;
         
    return 0;
}
```

---

## 🚨 4. Troubleshooting & Kesalahan Umum (Common Bugs)

1. **Error: `undefined reference to 'nama_fungsi'`**
   * **Penyebab:** Kamu membuat file `.cpp` tapi lupa menambahkannya ke dalam *Build Target* di Code::Blocks, atau lupa menyimpan file sebelum di-compile.
   * **Solusi:** Klik kanan pada file `.cpp` di panel kiri > Properties > Centang **Compile file** dan **Link file** (atau pastikan "all in build target" dicentang saat membuat file).

2. **Error: `redefinition of 'struct ...'`**
   * **Penyebab:** Lupa menggunakan *Include Guard* (`#ifndef ... #define ... #endif`) di file `.h`, atau tidak sengaja menulis `struct` dua kali.
   * **Solusi:** Pastikan format include guard sudah benar di paling atas dan paling bawah file `.h`.

3. **Nilai di `main.cpp` tidak berubah setelah diproses di fungsi**
   * **Penyebab:** Lupa menggunakan *Call by Reference* (`&`) pada parameter fungsi yang seharusnya mengubah data.
   * **Solusi:** Ubah `void ubahData(Mahasiswa m)` menjadi `void ubahData(Mahasiswa &m)`.

4. **File `.h` tidak ditemukan (`No such file or directory`)**
   * **Penyebab:** Salah penulisan nama file atau file `.h` dan `.cpp` tidak berada di folder yang sama.
   * **Solusi:** Gunakan tanda kutip `""` untuk file lokal (contoh: `#include "mahasiswa.h"`), **bukan** tanda `< >` (contoh: `#include <mahasiswa.h>`). Tanda `< >` hanya untuk library bawaan seperti `<iostream>`.

---