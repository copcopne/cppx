#include <iostream>
using namespace std;

int main() {
    int sobotest;
    cout <<"nhap so bo test: ";
    cin >> sobotest;
    for (int i = 1; i <= sobotest; i++) {
        int N, firstDigit, lastDigit, n_t;
        cin >> N;
        n_t = N;
        while (n_t >= 10) {
            n_t /= 10;
        }
        firstDigit = n_t;
        lastDigit = N % 10;
        if (firstDigit == lastDigit) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}