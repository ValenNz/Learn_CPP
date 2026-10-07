#include <iostream>

using namespace std;

int main() {
    int n, negatif, positif;
    
    cin >> n;
    negatif = 0;
    positif = 0;
    
    while (n != 0) {
        if (n < 0) {
            negatif++;
        } else {
            positif++;
        }
        cin >> n;
    }

    cout << negatif << " " << positif;

    if (positif < negatif) {
        cout << " negatif";
    } else if (positif > negatif) {
        cout << " positif";
    } else if (positif == negatif) {
        cout << " imbang";
    }
}
