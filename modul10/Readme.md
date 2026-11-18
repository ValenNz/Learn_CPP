# 📘 Panduan Praktikum Struktur Data - Modul 10
## Multi Linked List

Halo Praktikan! 👋
Selamat datang di Modul 10. Di modul ini, kita akan mempelajari **Multi Linked List**. 
Bayangkan struktur ini seperti sebuah **Perusahaan**: 
- **List Induk**: Mewakili Departemen (misal: HRD, IT, Keuangan).
- **List Anak**: Mewakili Karyawan yang bekerja di departemen tersebut.

Setiap elemen Induk memiliki "kantong" tersendiri yang berisi List Anak. Jika Departemen (Induk) dibubarkan, maka semua Karyawan (Anak) di dalamnya juga harus dihapus dari memori.

### 🎯 Tujuan Pembelajaran
1. Memahami konsep Multi Linked List (Hubungan Induk-Anak).
2. Mengimplementasikan operasi Insert dan Delete pada List Induk dan List Anak.
3. **Penting:** Memahami bahwa menghapus Node Induk **WAJIB** diawali dengan menghapus seluruh Node Anak yang melekat padanya untuk mencegah *Memory Leak*.

---

## 🧠 1. Struktur Data Multi Linked List
Berdasarkan modul (Program 46), kita membutuhkan dua set struktur: satu untuk Anak, satu untuk Induk.