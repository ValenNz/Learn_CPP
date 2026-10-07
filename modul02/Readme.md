# 📘 Panduan Praktikum Struktur Data - Modul 02
## Pengenalan Bahasa C++ (Bagian Kedua): Array, Pointer, dan Fungsi

Halo Praktikan! 👋
Selamat datang di Modul 02. Jika Modul 01 adalah fondasi, maka Modul 02 adalah **jantung** dari mata kuliah Struktur Data. Pemahaman kalian tentang **Pointer** dan **Manajemen Memori** di modul ini akan menentukan apakah kalian akan mudah atau kesulitan di modul-modul selanjutnya (Linked List, Tree, Graph).

### 🎯 Tujuan Pembelajaran
1. Memahami konsep Array (1D, 2D, dan Multi-dimensi).
2. Memahami konsep Memori, Alamat (Address), dan Pointer.
3. Mengimplementasikan Fungsi dan Prosedur.
4. Memahami perbedaan krusial antara *Call by Value*, *Call by Pointer*, dan *Call by Reference*.

---

## 📊 1. Array (Larik)
Array adalah kumpulan data dengan nama yang sama dan tipe data yang sama, yang disimpan di lokasi memori yang berurutan.

### ⚠️ Aturan Emas Array di C++
*   **Indeks dimulai dari 0**, bukan 1!
*   Jika Anda mendeklarasikan `int arr[5];`, maka indeks yang valid adalah `0, 1, 2, 3, 4`. Mengakses `arr[5]` akan menyebabkan *error* atau *undefined behavior*.

### Jenis Array
1.  **Array 1 Dimensi:** Seperti sebuah baris/daftar.
    ```cpp
    int nilai[5] = {90, 85, 70, 80, 95};
    cout << nilai[0]; // Output: 90
    ```
2.  **Array 2 Dimensi:** Seperti sebuah tabel (baris dan kolom) atau matriks.
    ```cpp
    int matriks[2][3] = { {1, 2, 3}, {4, 5, 6} };
    cout << matriks[1][2]; // Output: 6 (Baris ke-1, Kolom ke-2)
    ```
3.  **Array Multi-Dimensi:** Array dengan dimensi lebih dari dua (jarang dipakai di dasar struktur data, tapi tetap ada).

---

##  2. Pointer & Manajemen Memori (SANGAT PENTING!)
Ini adalah materi paling krusial di Struktur Data. Pointer adalah variabel yang **menyimpan alamat memori** dari variabel lain.

### Konsep Dasar Memori
Bayangkan RAM sebagai deretan loker (array 1D raksasa). Setiap loker punya nomor unik yang disebut **Alamat (Address)**.
*   Saat Anda membuat `int x = 10;`, OS akan mencari loker kosong, menaruh angka `10` di dalamnya, dan memberi nomor alamat (misal: `0x7ffd123`).

### Operator Wajib Hafal
1.  **`&` (Address-of):** Mengambil alamat memori dari suatu variabel.
2.  **`*` (Dereference/Pointer declaration):** Mengambil nilai yang ada di dalam alamat memori yang ditunjuk pointer.

```cpp
int x = 10;
int *p; // Deklarasi pointer p yang menunjuk ke tipe data int

p = &x; // p sekarang menyimpan alamat dari x (misal: 0x7ffd123)

cout << x;   // Output: 10 (Nilai x)
cout << &x;  // Output: 0x7ffd123 (Alamat x)
cout << p;   // Output: 0x7ffd123 (Isi p adalah alamat x)
cout << *p;  // Output: 10 (Nilai yang ditunjuk oleh p)
```

### Pointer dan Array
Nama array sebenarnya adalah **pointer konstan** yang menunjuk ke elemen pertama array.
```cpp
int arr[3] = {10, 20, 30};
int *p = arr; // p menunjuk ke arr[0]

cout << *p;      // Output: 10
cout << *(p+1);  // Output: 20 (Pointer arithmetic, geser 1 alamat)
```

### Pointer dan String
Hati-hati dengan perbedaan ini:
```cpp
char pesan1[] = "Halo"; // Array of char. Boleh diubah isinya.
char *pesan2 = "Halo";  // Pointer to string literal. TIDAK BOLEH diubah isinya (Read-only).
```

---

## ⚙️ 3. Fungsi (Function) & Prosedur
*   **Fungsi:** Blok kode yang melakukan tugas dan **mengembalikan nilai** (return value).
*   **Prosedur:** Di C++, prosedur adalah fungsi yang bertipe `void` (tidak mengembalikan nilai).

```cpp
// Fungsi
int tambah(int a, int b) {
    return a + b;
}

// Prosedur
void sapa() {
    cout << "Halo Praktikan!" << endl;
}
```

---

## 🔄 4. Cara Melewatkan Parameter (Parameter Passing)
Ini adalah alasan utama mengapa kita belajar Pointer. Bagaimana cara mengubah nilai variabel asli dari dalam fungsi?

### A. Call by Value (Secara Nilai)
*   **Konsep:** Nilai variabel **disalin (copy)** ke parameter fungsi.
*   **Efek:** Mengubah parameter di dalam fungsi **TIDAK AKAN** mengubah variabel asli.
```cpp
void tukarNilai(int a, int b) {
    int temp = a; a = b; b = temp;
}
// Variabel asli di main() TIDAK AKAN TUKAR.
```

### B. Call by Pointer (Secara Pointer)
*   **Konsep:** Yang dikirim ke fungsi adalah **alamat memori** variabel asli.
*   **Efek:** Mengubah nilai di dalam fungsi **AKAN** mengubah variabel asli.
```cpp
void tukarPointer(int *a, int *b) {
    int temp = *a; 
    *a = *b; 
    *b = temp;
}
// Pemanggilan: tukarPointer(&x, &y);
// Variabel asli di main() AKAN TUKAR.
```

### C. Call by Reference (Secara Referensi)
*   **Konsep:** Mirip dengan pointer, tapi syntax lebih bersih. Menggunakan operator `&` pada parameter.
*   **Efek:** Mengubah nilai di dalam fungsi **AKAN** mengubah variabel asli.
```cpp
void tukarRef(int &a, int &b) {
    int temp = a; a = b; b = temp;
}
// Pemanggilan: tukarRef(x, y); (Tidak perlu pakai &)
// Variabel asli di main() AKAN TUKAR.
```

> 💡 **Tips Asisten:** Di Struktur Data, kita hampir selalu menggunakan **Call by Pointer** atau **Call by Reference** saat memodifikasi struktur data (seperti menambah node di Linked List), karena kita perlu mengubah data aslinya, bukan salinannya!

---

## 📝 5. Tugas & Latihan Mandiri
Cobalah kerjakan di Code::Blocks untuk menguji pemahaman:

1.  **Eksperimen Memori:** Buat program yang mendeklarasikan 1 variabel `int`, 1 array `int[3]`, dan 1 pointer. Print alamat memori (`&`) dari ketiganya. Amati pola alamat memorinya.
2.  **Kasus Tukar (Wajib Paham):** Buat 3 fungsi berbeda untuk menukar dua variabel (menggunakan *Value*, *Pointer*, dan *Reference*). Panggil ketiganya di `main()` dan buktikan mana yang berhasil mengubah nilai asli dan mana yang tidak.
3.  **Manipulasi Array dengan Pointer:** Buat sebuah array 1 dimensi berisi 5 bilangan bulat. Buatlah fungsi yang menerima pointer array tersebut, lalu kalikan semua elemen di dalam array dengan 2 menggunakan pointer arithmetic (tanpa menggunakan tanda kurung siku `[]`).

---

## 🚨 Troubleshooting & Kesalahan Umum (Common Bugs)
1.  **Segmentation Fault (Segfault):** 
    *   *Penyebab:* Mengakses alamat memori yang tidak diizinkan, atau menggunakan pointer yang belum diinisialisasi (dangling pointer / null pointer).
    *   *Solusi:* Pastikan pointer selalu menunjuk ke alamat yang valid sebelum di-dereference (`*p`).
2.  **Lupa tanda `&` saat Call by Pointer:**
    *   *Error:* Memanggil `tukarPointer(x, y)` padahal fungsinya `tukarPointer(int *a, int *b)`.
    *   *Solusi:* Ingat, fungsi butuh alamat, jadi panggil dengan `tukarPointer(&x, &y)`.
3.  **Infinite Loop pada Array:**
    *   *Penyebab:* Menggunakan `<=` pada ukuran array. `for(int i=0; i<=5; i++)` pada array ukuran 5 akan mengakses indeks 5 yang tidak valid.
    *   *Solusi:* Selalu gunakan `<` ukuran array.

