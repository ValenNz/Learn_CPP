#include <iostream>

using namespace std;

int main()
{
    int n, terbesar, nGenap;
    nGenap = 0;
    cin >> n;
    terbesar = 0;
    while (n != 0){
        if (n % 2 == 0){
            nGenap++;
            if (terbesar < n){
                terbesar = n;
            }
        }
        cin >> n;
    }
    cout << nGenap << " " << terbesar;
}
