#include <iostream>
using namespace std;
constexpr int MAX = 100;
int main() {
    int a[MAX] {};
    int phanTu{};
    do {
    cout <<"Nhap so luong phan tu(>0): ";
    cin >> phanTu;
    } while(phanTu < 0);
    for(int i{};i<phanTu;++i) {
        cout <<"Nhap phan tu thu [" <<i <<"] :";
        cin >>a[i];
    }
    for(int i{};i<phanTu;++i) {
        cout <<a[i] <<"\t";
    }
    cout <<"Nhap x can tim: ";
    int x{}; cin >>x;
    for(int i{};i<phanTu;++i) {
        if(a[i] == x && i==0)
            cout <<"Tim thay x o vi tri dau la: "<<i<<"\n";
        else if(a[i] == x && i == (phanTu - 1))
            cout <<"Tim thay x o vi tri cuoi la: "<<i<<'\n';
        else if(a[i] == x)
            cout <<"Tim thay x o vi tri thu: "<<i<<'\n';
    }
}
