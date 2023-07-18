#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
Node* head;
void init_Si_Bai_Mau_1_N2_B2() {
	head = NULL;
}
void themDau_Si_Bai_Mau_1_N2_B2(int x) {
	Node* p = new Node;
	p->value = x;
	p->next = head;
	head = p;
}
void themCuoi_Si_Bai_Mau_1_N2_B2(int x) {
	Node* p = new Node;
	p->value = x;
	p->next = NULL;
	if (head == NULL) {
		head = p;
	}
	else {
		Node* last = head;
		while (last->next != NULL)
			last = last->next;
		last->next = p;
	}
}
void themSau_Si_Bai_Mau_1_N2_B2(int x, int y) {
	Node* p = new Node;
	p->value = x;
	p->next = NULL;
	Node* q = head;
	while (q->next != NULL && q->value != y)
		q = q->next;
	p->next = q->next;
	q->next = p;
}
void xoaHet_Si_Bai_Mau_1_N2_B2() {
	while (head != NULL) {
		Node* p = head;
		head = p->next;
		p->next = NULL;
		delete p;
	}
}
void output_Si_Bai_Mau_1_N2_B2() {
	Node* p = head;
	while (p != NULL) {
		cout << p->value << '\t';
		p = p->next;
	}
}
Node* tim_Si_Bai_Mau_1_N2_B2(int x) {
	Node* q = head;
	while (q != NULL && q->value != x)
		q = q->next;
	return q;
}
int main() {
	init_Si_Bai_Mau_1_N2_B2();
	themCuoi_Si_Bai_Mau_1_N2_B2(77);
	themDau_Si_Bai_Mau_1_N2_B2(88);
	themDau_Si_Bai_Mau_1_N2_B2(99);
	themDau_Si_Bai_Mau_1_N2_B2(5);
	themDau_Si_Bai_Mau_1_N2_B2(10);
	themDau_Si_Bai_Mau_1_N2_B2(15);
	output_Si_Bai_Mau_1_N2_B2();
	cout << "\nthem 3 sau ptu 99\n";
	themSau_Si_Bai_Mau_1_N2_B2(3, 99);
	output_Si_Bai_Mau_1_N2_B2();
	if (tim_Si_Bai_Mau_1_N2_B2(4))
		cout << "tim thay 4 trong danh sach\n";
	else cout << "\nkhong tim thay 4 trong danh sach\n";
	if (tim_Si_Bai_Mau_1_N2_B2(77))
		cout << "tim thay 77 trong danh sach\n";
	else cout << "khong tim thay 77 trong danh sach\n";
	cout << "xoa het danh sach\n";
	cout << "danh sach sau khi xoa: ";
	xoaHet_Si_Bai_Mau_1_N2_B2();
	output_Si_Bai_Mau_1_N2_B2();
	return 0;
}