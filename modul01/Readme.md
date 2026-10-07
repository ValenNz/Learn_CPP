# 📘 Panduan Praktikum Struktur Data - Modul 01
## Code::Blocks IDE & Pengenalan Bahasa C++ (Bagian Pertama)

Halo Praktikan! 👋 
Selamat datang di praktikum Struktur Data. Modul ini adalah fondasi utama kalian sebelum masuk ke materi struktur data yang lebih kompleks (seperti Pointer, Linked List, dll). 

### 🎯 Tujuan Pembelajaran
1. Mengenal dan mampu menggunakan IDE **Code::Blocks**.
2. Memahami struktur dasar, tipe data, variabel, dan konstanta pada C++.
3. Menguasai operasi Input/Output, Operator, Kondisional, dan Perulangan.
4. Memahami konsep dasar `struct` dan blok program (fungsi).

---

## 🛠️ 1. Pengenalan Code::Blocks IDE
Code::Blocks adalah IDE gratis dan *open-source* yang akan kita gunakan. 

### ⚠️ Shortcut & Istilah Wajib Tahu
Banyak praktikan terjebak di sini. Hafalkan perbedaan istilah berikut:
*   **Build (Ctrl + F9):** Mengompilasi kode menjadi program. *Program tidak akan jalan jika belum di-build.*
*   **Run (Ctrl + F10):** Menjalankan program yang sudah di-build.
*   **Build and Run (F9):** Melakukan Build dan Run secara berurutan (Paling sering digunakan).
*   **Clean:** Jika program error aneh atau tidak mau di-run padahal kode sudah benar, klik kanan pada Project > **Clean**. Ini akan menghapus file build lama.

### 📁 Struktur Project & Class
*   **Membuat Project:** `File > New > Projects > Console application`.
*   **Menambah File (.cpp/.h):** `File > New > File > C/C++ source`. 
    *   *PENTING:* Jangan lupa centang **"all in build target"** (Debug & Release) saat membuat file baru, atau program tidak akan ter-kompilasi!

---

## 💻 2. Dasar Pemrograman C++

### Struktur Dasar Program
```cpp
#include <iostream> // Library untuk Input/Output
using namespace std; // Agar tidak perlu menulis std::cout terus menerus

int main() {
    // Kode program ditulis di sini
    cout << "Hello, Struktur Data!" << endl;
    return 0;
}
```

### Variabel & Tipe Data Dasar
*   **Integer (`int`):** Bilangan bulat (contoh: `10`, `-5`).
*   **Float/Double:** Bilangan desimal (contoh: `3.14`). `double` lebih presisi.
*   **Char:** Satu karakter (contoh: `'A'`, `'z'`).
*   **String:** Kumpulan karakter (contoh: `"Telkom University"`). *Butuh `#include <string>`*.

**Aturan Penamaan Variabel (Identifier):**
*   Harus diawali huruf atau underscore (`_`).
*   Tidak boleh ada spasi (gunakan `nama_mahasiswa` atau `namaMahasiswa`).
*   **Case-Sensitive:** `Nilai` dan `nilai` adalah dua variabel berbeda.

### Konstanta
Nilai yang tidak bisa diubah selama program berjalan.
```cpp
const float PHI = 3.14;
// PHI = 3.15; // ❌ ERROR: Tidak bisa diubah!
```

---

## ⌨️ 3. Input & Output

### Output (`cout`)
```cpp
int umur = 18;
cout << "Umur saya adalah " << umur << " tahun" << endl;
```
*   `endl` atau `\n` digunakan untuk membuat baris baru (Enter).

### Input (`cin`)
```cpp
int umur;
cout << "Masukkan umur: ";
cin >> umur; // Tanda >> mengarah ke variabel
```

### Escape Sequence (Karakter Khusus)
*   `\n` : Baris baru
*   `\t` : Tab (spasi panjang)
*   `\\` : Menampilkan tanda backslash `\`
*   `\"` : Menampilkan tanda kutip `"`

---

## ➕ 4. Operator & Pemodifikasi Tipe

### Operator Aritmatika & Assignment
*   Dasar: `+`, `-`, `*`, `/`, `%` (Modulus/Sisa bagi).
*   Assignment: `+=`, `-=`, `*=`, `/=`. (Contoh: `x += 5` sama dengan `x = x + 5`).

### ⚠️ Increment & Decrement (PENTING!)
Sering keluar di soal/ujian. Perhatikan perbedaannya:
```cpp
int r = 10;
int s;

// Pre-increment (++r): Nilai r ditambah DULU, baru diproses
s = 10 + (++r); 
// r menjadi 11, s = 10 + 11 = 21

int r2 = 10;
int s2;
// Post-increment (r2++): Nilai r2 diproses DULU, baru ditambah
s2 = 10 + (r2++); 
// s2 = 10 + 10 = 20, barulah setelah itu r2 menjadi 11
```

### Operator `sizeof`
Digunakan untuk melihat ukuran memori (dalam byte) suatu tipe data.
```cpp
cout << "Ukuran int: " << sizeof(int) << " byte" << endl;
```

### Pemodifikasi Tipe
*   `unsigned`: Hanya menerima nilai positif (kapasitas positif jadi 2x lipat).
*   `long`: Memperbesar kapasitas memori (contoh: `long int`).

---

## 🔀 5. Kondisional & Perulangan

### Kondisional (Percabangan)
1.  **If - Else**
    ```cpp
    if (nilai >= 80) {
        cout << "A";
    } else if (nilai >= 70) {
        cout << "B";
    } else {
        cout << "C";
    }
    ```
2.  **Switch - Case** (Cocok untuk menu pilihan)
    ```cpp
    switch(pilihan) {
        case 1: cout << "Menu 1"; break;
        case 2: cout << "Menu 2"; break;
        default: cout << "Pilihan salah";
    }
    ```

### Perulangan (Looping)
*   **For:** Digunakan ketika jumlah perulangan **sudah diketahui**.
    ```cpp
    for(int i = 0; i < 5; i++) { cout << i; }
    ```
*   **While:** Digunakan ketika jumlah perulangan **belum diketahui**, cek kondisi di **awal**.
*   **Do-While:** Minimal perulangan terjadi **1 kali**, cek kondisi di **akhir**.

---

## 📦 6. Struktur Data (`struct`)
`struct` digunakan untuk mengelompokkan beberapa variabel dengan tipe data berbeda menjadi satu kesatuan.
```cpp
struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    Mahasiswa mhs1;
    mhs1.nama = "Budi";
    mhs1.nim = "10123001";
    mhs1.ipk = 3.85;
    
    cout << mhs1.nama << " memiliki IPK " << mhs1.ipk;
}
```

---

## 📝 7. Tugas & Latihan Mandiri
Cobalah kerjakan soal berikut di Code::Blocks untuk menguji pemahamanmu:

1.  **Kalkulator Sederhana:** Buat program yang meminta input 2 bilangan `float`, lalu outputkan hasil penjumlahan, pengurangan, perkalian, dan pembagiannya.
2.  **Konversi Angka ke Teks:** Buat program yang menerima input angka bulat (0 - 100), lalu outputkan bentuk teksnya (Contoh: input `79`, output `Tujuh Puluh Sembilan`). *Hint: Gunakan Switch-Case atau If-Else bertingkat*.
3.  **Manipulasi Struct:** Buat struct `Tanggal` (tgl, bulan, tahun) dan struct `DataRekam` (nama, tgl_lahir). Input data dan tampilkan menggunakan format yang rapi.

---

## 🚨 Troubleshooting Umum (Baca Ini Kalau Error!)
1.  **Error: "semicolon expected"** ➡️ Cek baris sebelumnya, kemungkinan lupa tanda `;`.
2.  **Program tidak mau di-Run / Tombol Run abu-abu** ➡️ Pastikan kamu sudah melakukan **Build** (Ctrl+F9) atau **Build and Run** (F9).
3.  **File .cpp tidak terdeteksi saat Build** ➡️ Klik kanan file `.cpp` di panel kiri > Properties > Centang **Compile file** dan **Link file** / atau pastikan saat membuat file kamu mencentang **all in build target**.
4.  **Lupa hapus file praktikum di Lab** ➡️ Sesuai peraturan, akan ada pengurangan nilai jurnal 20%. Selalu hapus file di komputer lab sebelum keluar!

---
*️ **PERINGATAN PENTING DARI ASISTEN:** 
Sesuai peraturan laboratorium, **DILARANG KERAS menggunakan AI untuk mengerjakan Tugas Pendahuluan (TP) dan Jurnal Praktikum**. Gunakan modul ini hanya sebagai bahan belajar dan referensi pemahaman konsep. Jika terindikasi menggunakan AI untuk TP/Jurnal, nilai akan langsung **0**.*

**Selamat Belajar & Good Luck Praktikumnya! 🚀**