#include <iostream>
using namespace std;
const int MAX = 100;
struct stack {
    int a[MAX];
    int top;
};
void init(stack& s) {
    s.top = -1;
}
void push(stack& s, int x) {
    s.top++;
    s.a[s.top] = x;
    //s.a[++s.top] = x;
}
int pop(stack& s) {
    return s.a[s.top--];
}
void processList(stack& s) {
    for(int i{s.top};i >=0;--i) 
        cout <<s.a[i] <<'\n';
}
int main () {
    stack s;
    init(s);
    push(s,5);
    push(s,10);
    push(s,15);
    processList(s);
    cout <<"Lay 1 phan tu trong stack: ";
    int x = pop(s);
    cout <<x <<'\n';
    processList(s);

}