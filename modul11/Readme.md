# 📘 Panduan Praktikum Struktur Data - Modul 11
## Pendampingan & Konsultasi Tugas Besar

Halo Praktikan! 👋
Selamat datang di Modul 11. Tidak seperti modul sebelumnya, hari ini kita **tidak akan mempelajari materi baru**. Modul 11 adalah sesi khusus **Pendampingan Tugas Besar**. 

Ini adalah waktu kalian untuk menunjukkan progres proyek akhir kalian, meminta *review* kode, dan memperbaiki *bug* sebelum pengumpulan akhir.

### 🎯 Tujuan Sesi Ini
1. Memastikan struktur proyek Tugas Besar sudah sesuai kaidah ADT dan *good practice*.
2. Melakukan *debugging* bersama asisten jika terdapat *error* atau *memory leak*.
3. Memastikan logika struktur data yang digunakan (Linked List, Stack, Queue, Tree, atau Graph) sudah tepat guna.

---

## 📁 1. Struktur Folder Proyek yang Baik
Sebelum datang ke meja asisten, pastikan folder proyek kalian rapi. Asisten akan menolak mereview kode yang berantakan. Struktur yang direkomendasikan:

```text
TugasBesar_KelompokX/
│
├── include/            # Berisi semua file Header (.h)
│   ├── mahasiswa.h
│   ├── linkedlist.h
│   └── stack.h
│
├── src/                # Berisi semua file Body/Implementasi (.cpp)
│   ├── mahasiswa.cpp
│   ├── linkedlist.cpp
│   └── stack.cpp
│
├── main.cpp            # File utama (Driver Program)
├── README.md           # Penjelasan cara compile & run proyek
└── data.txt            # (Opsional) File input/output eksternal