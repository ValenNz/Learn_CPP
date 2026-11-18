# 📘 Panduan Praktikum Struktur Data - Modul 08
## QUEUE (Antrean) - Representasi Array

Halo Praktikan! 👋
Selamat datang di Modul 08. Hari ini kita akan mempelajari **Queue**. Bayangkan Queue seperti antrean di loket tiket atau kasir: orang yang pertama kali datang (First In) adalah orang yang pertama kali dilayani dan keluar dari antrean (First Out). Ini disebut prinsip **FIFO**.

Di modul ini, kita akan fokus mengimplementasikan Queue menggunakan **Representasi Tabel (Array)**. Tantangan utamanya adalah mengelola indeks `Head` (depan) dan `Tail` (belakang) agar tidak terjadi *memory shift* yang tidak efisien atau antrean yang "penuh semu".

### 🎯 Tujuan Pembelajaran
1. Memahami konsep FIFO (First In First Out).
2. Mengimplementasikan ADT Queue menggunakan Array.
3. Menguasai 3 mekanisme pengelolaan indeks Queue: Alternatif 1 (Head Diam), Alternatif 2 (Head & Tail Bergerak), dan Alternatif 3 (Circular Queue).

---

## 🧠 1. Konsep Dasar Queue (Array)
Dalam representasi array, Queue memiliki komponen utama:
1. **Array `info`**: Tempat menyimpan data.
2. **Integer `Head`**: Penunjuk indeks elemen paling depan (yang akan keluar).
3. **Integer `Tail`**: Penunjuk indeks elemen paling belakang (yang baru masuk).

---

## 💻 2. IMPLEMENTASI FULL CODE (Latihan Utama: Alternatif 1)
Sesuai latihan Modul 8.5 No. 1, kita akan membuat implementasi dengan **Mekanisme Alternatif 1** (Head diam di indeks 0, Tail bergerak, dan saat `dequeue` semua elemen digeser ke kiri).

Silakan buat 3 file berikut di folder `modul08` Anda.

### 📄 File 1: `queue.h` (Deklarasi ADT)
```cpp
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>
using namespace std;

#define MaxEl 5       // Kapasitas maksimal queue sesuai latihan
#define Nil -1        // Indikator queue kosong (menggunakan -1 agar sesuai index 0-based C++)

typedef int infotype;

struct Queue {
    infotype info[MaxEl];
    int head;
    int tail;
};

// Prototype Primitif
void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif // QUEUE_H_INCLUDED