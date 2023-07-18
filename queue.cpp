#include <iostream>
using namespace std;
struct node {
    int info;
    node* link;  
};
node* front, *rear;
void init() {
    front = NULL;
    rear = NULL;
}
void push(int x) {
    node* p = new node;
    p->info=x;
    p->link=NULL;
    if(rear == NULL)
        front = p;
    else
        rear->link = p;
    rear = p;
}
void pop(int& x) {
    if(front!=NULL) {
        node* p = front;
        x = p->info;
        front=front->link;
        if(front == NULL) 
            rear == NULL;
        delete p;
    }
}
void processList() {
    node*p = front;
    while(p!= NULL) {
        cout <<p->info<<'\n';
        p= p->link;
    }
}
int main() {
    int temp{};
    init();
    push(5);
    push(10);
    push(15);
    push(20);
    processList();
    pop(temp);
    processList();
}