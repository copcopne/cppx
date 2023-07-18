#include <iostream>
using namespace std;
struct node {
    int info;
    node* previous;
    node* link;
};
node *first, *last;
void init() {
    first = NULL;
    last = NULL;
}
void progressList() {
    node* p = first;
    while(p != NULL) {
        cout << p->info <<'\t';
        p = p->link;
    }
}
void progressListBeginLast() {
    node* p = last;
    while(p != NULL) {
        cout << p->info <<'\t';
        p = p->previous;
    }
}
node* search(int x) {
    node* p = first;
    while(p != NULL && p->info != x)
        p = p->link;
    return p;
}
void insertFirst(int x) {
    node* p = new node;
    p->previous = NULL;
    p->link = first;
    p->info = x;
    if(first != NULL)
        first->previous = p;
    else
        last = p;
    first = p;
}
void insertLast(int x) {
    node* p = new node;
    p->info = x;
    p->link = NULL;
    p->previous = last;
    if(last != NULL)
        last->link = p;
    else
        first = p;
    last = p;
}
node* add(int x, int y) /*Them y sau x*/ {
    node* p = first;
    while(p != NULL && p->info != x)
        p = p->link;
    node* q = new node;
    q->info = y;
    q->previous = p;
    q->link = p->link;
    p->link->previous = q;
    p->link = q;
}
void xoaDau() {

}
void xoaCuoi() {

}
void xoaSau(int x) {

}
void xoaAll() {
    
}
int main() {
    init();
    insertFirst(15);
    insertLast(25);
    insertFirst(10);
    add(15,20);
    progressList();
    cout <<"\nNhap so can tim: ";
    int abc{}; cin >> abc;
    if(search(abc))
        cout <<"Tim thay " << abc << " trong danh sach\n";
    else cout <<"Khong tim thay " << abc << " trong danh sach\n";
}