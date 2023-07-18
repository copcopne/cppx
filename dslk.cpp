#include <iostream>
using namespace std;
struct node {
    int info;
    node *link;
};
node *head;
void init() {
    head = NULL;
}
void process_list() {
    node *p;
    p= head;
    while(p != NULL) {
        cout << p->info << endl;
        p = p->link;
    }
}
node* search(int x) {
    node *p = head;
    while((p != NULL) && (p->info != x)) 
        p = p->link;
    return p;
}
node insert_first(int x) {
    node *p = new node;
    p->info = x;
    p->link = head;
    head = p;
}
node insert_last(int x) {
    node *p = new node;
    p->info = x;
    p->link = NULL;
    if(head == NULL) // khong co phan tu cuoi cung
        head = p;
    else {
        node *q = head;
        while(q->link != NULL)
            q = q->link;
        q->link = p;
    }
}
int main() {
    node *p = new node;
    init();
    insert_first(5);
    insert_first(10);
    insert_first(15);
    process_list();
    delete p;
    
}