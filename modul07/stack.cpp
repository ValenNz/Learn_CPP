#include "stack.h"

void CreateStack(Stack &S) {
    S.Top = Nil; 
}

bool isEmpty(Stack S) {
    return S.Top == Nil;
}

bool isFull(Stack S) {
    return S.Top == MaxEl - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.Top++;
        S.info[S.Top] = x;
    } else {
        cout << "[ERROR] Stack Penuh! Tidak bisa Push." << endl;
    }
}

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
//  1 2 3 4 5 

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
// 1 2 3 4 5
// 5 4 3 2 1

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    CreateStack(temp);

    while (!isEmpty(S) && S.info[S.Top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}


void getInputStream(Stack &S) {
    char c;
    cout << "Masukkan karakter (akhiri dengan Enter): ";
    
    while ((c = cin.get()) != '\n') {
        if (!isFull(S)) {
            push(S, (int)c); 
        } else {
            cout << "\n[ERROR] Stack Penuh! Input terpotong." << endl;
            break;
        }
    }
}
