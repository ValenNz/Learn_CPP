#include "bstree.h"

// 1. ALOKASI MEMORI
address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

// 2. DEALOKASI MEMORI
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

// 3. INSERT NODE (Rekursif)
// Aturan BST: Kiri lebih kecil, Kanan lebih besar
void insertNode(address &root, infotype x) {
    if (root == Nil) {
        // Jika posisi kosong, isi dengan node baru
        root = alokasi(x);
    } else {
        if (x < root->info) {
            // Jika lebih kecil, masuk ke subtree kiri
            insertNode(root->left, x);
        } else if (x > root->info) {
            // Jika lebih besar, masuk ke subtree kanan
            insertNode(root->right, x);
        }
        // Jika x == root->info, kita abaikan (tidak boleh ada duplikat di BST standar)
    }
}

// 4. FIND NODE (Rekursif)
address findNode(infotype x, address root) {
    if (root == Nil || root->info == x) {
        return root; // Ketemu atau tidak ada di tree
    }
    if (x < root->info) {
        return findNode(x, root->left);
    }
    return findNode(x, root->right);
}

// 5. TRAVERSAL: IN-ORDER (Kiri - Root - Kanan) -> Menghasilkan data terurut
void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " ";
        printInorder(root->right);
    }
}

// 6. TRAVERSAL: PRE-ORDER (Root - Kiri - Kanan)
void printPreorder(address root) {
    if (root != Nil) {
        cout << root->info << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

// 7. TRAVERSAL: POST-ORDER (Kiri - Kanan - Root)
void printPostorder(address root) {
    if (root != Nil) {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->info << " ";
    }
}

// 8. HITUNG JUMLAH NODE (Rekursif)
int hitungJumlahNode(address root) {
    if (root == Nil) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

// 9. HITUNG TOTAL INFO (Rekursif)
int hitungTotalInfo(address root) {
    if (root == Nil) return 0;
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

// 10. HITUNG KEDALAMAN / HEIGHT (Rekursif)
// Kedalaman leaf = 0, empty tree = -1
int hitungKedalaman(address root) {
    if (root == Nil) return -1;
    int leftDepth = hitungKedalaman(root->left);
    int rightDepth = hitungKedalaman(root->right);
    return 1 + max(leftDepth, rightDepth);
}