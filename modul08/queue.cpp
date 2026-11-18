#include "queue.h"

void CreateQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = Nil; 
}

bool isEmptyQueue(Queue Q) {
    return Q.tail == Nil;
}

bool isFullQueue(Queue Q) {
    return Q.tail == MaxEl - 1;
}

void enqueue(Queue &Q, infotype x) {
    if (!isFullQueue(Q)) {
        if (isEmptyQueue(Q)) {
            Q.head = 0; 
        }
        Q.tail++;
        Q.info[Q.tail] = x;
    } else {
        cout << "[ERROR] Queue Penuh! Tidak bisa Enqueue." << endl;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -999; 
    if (!isEmptyQueue(Q)) {
        x = Q.info[Q.head];
        
        for (int i = Q.head; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }
        
        Q.tail--;
        
        if (Q.tail == Nil) {
            Q.head = 0;
        }
    } else {
        cout << "[ERROR] Queue Kosong! Tidak bisa Dequeue." << endl;
    }
    return x;
}

void printInfo(Queue Q) {
    cout << " " << Q.head << "  " << Q.tail << "\t | Queue info: ";
    if (isEmptyQueue(Q)) {
        cout << "Kosong";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}