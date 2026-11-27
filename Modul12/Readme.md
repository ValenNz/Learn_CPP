# 📘 Panduan Praktikum Struktur Data - Modul 14
## GRAPH (Graf) - Representasi Multilist & Penelusuran (DFS/BFS)

Halo Praktikan! 👋
Selamat datang di Modul 14. Di modul ini, kita akan mempelajari Graph. Bayangkan Graph seperti peta kota: **Node (Simpul)** adalah kotanya, dan **Edge (Sisi)** adalah jalan yang menghubungkan kota-kota tersebut.

### 🎯 Tujuan Pembelajaran
1. Memahami konsep Graph Tidak Berarah (Undirected Graph).
2. Mengimplementasikan ADT Graph menggunakan representasi Multilist (Pointer).
3. Menguasai algoritma penelusuran Graph: **DFS (Depth First Search)** dan **BFS (Breadth First Search)**.

---

## 🧠 1. Konsep Dasar & Koreksi Typo PDF
Sebelum masuk ke kode, ada **TYPO (kesalahan ketik)** di PDF Modul 14 halaman 110 yang harus kalian perhatikan:
> *"Type adrEdge: pointer to ElmNode"* ❌ (SALAH)
> Seharusnya: *"Type adrEdge: pointer to ElmEdge"* ✅ (BENAR)

**Struktur Data Graph (Multilist):**
Setiap Node memiliki `firstEdge` yang menunjuk ke daftar Edge-nya. Setiap Edge menunjuk ke `Node` tujuan. Karena ini **Graph Tidak Berarah**, jika A terhubung ke B, maka B juga harus terhubung ke A.

---

## 💻 2. IMPLEMENTASI FULL CODE (Latihan 14.3)

Silakan buat 3 file berikut di folder `modul14` Anda.