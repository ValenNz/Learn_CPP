#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    cout << "=== MODUL 7: STACK (REPRESENTASI ARRAY) ===" << endl;

    cout << "\n[1] Operasi Dasar Push & Pop:" << endl;
    push(S, 3);
    push(S, 4);
    push(S, 8);
    cout << "Setelah push 3, 4, 8: "; printInfo(S);

    cout << "Elemen yang di-pop: " << pop(S) << endl; 
    
    push(S, 2);
    push(S, 3);
    cout << "Setelah pop, lalu push 2, 3: "; printInfo(S);

    cout << "Elemen yang di-pop: " << pop(S) << endl; 
    
    push(S, 9);
    cout << "Setelah pop, lalu push 9: "; printInfo(S);

    cout << "\n[2] Membalik Isi Stack:" << endl;
    cout << "Sebelum dibalik: "; printInfo(S);
    balikStack(S);
    cout << "Setelah dibalik: "; printInfo(S);

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


    cout << "\n[4] Operasi Get Input Stream:" << endl;
    Stack S3;
    CreateStack(S3);
    
    getInputStream(S3);
    
    cout << "Isi Stack dari input stream (Top ke Bottom): ";
    printInfo(S3);

    return 0;
}
