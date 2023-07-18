#include <iostream>
using namespace std;
struct node {
    int info;
    node* link;
};
node* sp;
void init() {
    sp = NULL;
}
void push(int x) {
    node*p = new node;
    p->info = x;
    p->link = sp;
    sp = p;
}
void pop(int& x) {
    if(sp != NULL) {
        node* q = sp;
        x = q->info;
        sp=sp->link;
        delete q;
    }
}
void processList() {
    node * p = sp;
    while(p!=NULL) {
        cout <<p->info <<'\t';
        p= p->link;
    }
    cout <<'\n';
}
int main() {
    int x{};
    init();
    push(5);
    push(10);
    push(15);
    processList();
    pop(x);
    processList();
}