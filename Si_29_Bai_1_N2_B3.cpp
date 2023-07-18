#include <iostream>
using namespace std;
struct node {
	int value;
	node* prev;
	node* link;
};
struct ds_Kep {
	node* head;
	node* tail;
};
void init_Si_29_Bai_1_N2_B3(ds_Kep &k) {
	k.head = NULL;
	k.tail = NULL;
}
node* createNode(int x) {
	node* p = new node;
	p->value = x;
	p->link = NULL;
	p->prev = NULL;
	return p;
}
void output_Si_29_Bai_1_N2_B3(ds_Kep& k) {
	node* p = k.head;
	while (p != NULL) {
		cout << p->value << '\t';
		p = p->link;
	}
	cout << '\n';
}
void output1_Si_29_Bai_1_N2_B3(ds_Kep& k) {
	node* p = k.tail;
	while (p != NULL) {
		cout << p->value << '\t';
		p = p->prev;
	}
	cout << '\n';
}
void count_Si_29_Bai_1_N2_B3(ds_Kep& k) //dem so phan tu
{
	int c{}, countEven{};
	node* p = k.head;
	while (p != NULL) {
		c++;
		if (p->value % 2 == 0)
			countEven++;
		p = p->link;
	}
	cout << "danh sach dang co: " << c << " phan tu\n";
	cout << "danh sach cac ptu chan la: " << countEven << " phan tu\n";
}
void themDau_Si_29_Bai_1_N2_B3(ds_Kep& k, int x) {
	node* p = new node;
	p->value = x;
	p->prev = NULL;
	p->link = NULL;
	if (k.head == NULL) {
		k.head = k.tail = p;
	}
	else {
		p->link = k.head;
		k.head->prev = p;
		k.head = p;
	}
}
void themCuoi_Si_29_Bai_1_N2_B3(ds_Kep& k, int x) {
	node* p = new node;
	p->value = x;
	p->link = NULL;
	p->prev = NULL;
	if (k.head == NULL) {
		k.head = k.tail = p;
	}
	else {
		p->prev = k.tail;
		k.tail->link = p;
		k.tail = p;
	}
}
void themSau_Si_29_Bai_1_N2_B3(ds_Kep& k, int v, int x) //them x sau nut v
{
	node* p = k.head;
	while (p != NULL && p->value != v) //tim vi tri nut v
		p = p->link;
	node* q = new node; //khoi tao nut
	q->value = x; //gan gia tri x vao nut
	q->prev = p; //noi nut moi khoi tao sau vi tri nut v
	q->link = p->link; //noi nut moi khoi tao truoc vi tri nut tiep theo cua v
	p->link->prev = q; // noi nut v voi nut q
	p->link = q; //xoa lien ket ban dau cua nut v
}
void xoaDau_Si_29_Bai_1_N2_B3(ds_Kep& k) {
	if (k.head != NULL) //kiem tra neu danh sach khong co phan tu
	{
		node* p = k.head;
		if (p->link == NULL) //kiem tra neu danh sach chi co 1 phan tu
		{
			k.head = NULL;
			k.tail = NULL;
		}
		else {
			k.head = p->link;
			p->link->prev = NULL;
			p->link = NULL;
		}
		delete(p);
	}
}
void xoaCuoi_Si_29_Bai_1_N2_B3(ds_Kep& k) {
	if (k.head != NULL) //kiem tra neu danh sach khong co phan tu
	{
		node* x = k.tail;
		if (x->prev == NULL) //kiem tra neu danh sach chi co 1 phan tu
		{
			k.head = NULL;
			k.tail = NULL;
		}
		else
		{
			k.tail = x->prev;
			x->prev->link = NULL;
			x->link = NULL;
		}
		delete (x);
	}
}
void xoaSau_Si_29_Bai_1_N2_B3(ds_Kep& k, int v) // xoa sau nut v 
{
	if (k.head != NULL) // kiem tra neu co ton tai danh sach
	{
		node* n = k.head; // khoi tao nut
		while (n != NULL && n->value != v) //tim vi tri nut v
			n = n->link;
		if (n->link == NULL) // kiem tra neu nut v la nut cuoi
		{
			cout << "khong the xoa sau nut " << v << '\n';
			return;
		}
		else 
			if (n->link->link == NULL) { // kiem tra neu nut v la nut ke cuoi
				xoaCuoi_Si_29_Bai_1_N2_B3(k);
			}
			else {
				n = n->link; // di chuyen den nut can xoa
				n->link->prev = n->prev; // thay doi lien ket voi nut phia sau
				n->prev->link = n->link; // thay doi lien ket voi nut phia truoc
				n->prev = NULL; // xoa lien ket truoc cua nut can xoa
				n->link = NULL; // xoa lien ket sau cua nut can xoa
			}
		delete(n); // xoa nut
	}
}
void xoaSauGPT_Si_29_Bai_1_N2_B3(ds_Kep& k, int v) {
    if (k.head != NULL) { // Check if the list is not empty
        node* n = k.head; // Initialize the node
        while (n != NULL && n->value != v) // Find the position of the node with value v
            n = n->link;
        if (n == NULL || n->link == NULL) { // If the node is not found or it is the last node
            cout << "Cannot delete the node after " << v << '\n';
            return;
        }
        else {
            node* q = n->link; // Store the node to be deleted in a temporary variable
            n->link = q->link; // Update the next pointer of the previous node
            if (q->link != NULL)
                q->link->prev = n; // Update the previous pointer of the next node
            if (q == k.tail)
                k.tail = n; // Update the tail pointer if the last node is deleted
            delete q; // Delete the temporary node
        }
    }
}
node* search_Si_29_Bai_1_N2_B3(ds_Kep& k, int x) {
	node* q = k.head; //khoi tao nut
	while (q != NULL && q->value != x) // kiem tra, cho nut chay tu dau den khi gap nut co gia tri bang x
		q = q->link;
	return q; // return vi tri cua nut, neu khong tim thay thi return NULL
}
int main() {
	ds_Kep a;
	init_Si_29_Bai_1_N2_B3(a);
	themDau_Si_29_Bai_1_N2_B3(a, 5);
	themCuoi_Si_29_Bai_1_N2_B3(a, 66);
	themSau_Si_29_Bai_1_N2_B3(a, 5,88);
	themDau_Si_29_Bai_1_N2_B3(a, 6);
	themCuoi_Si_29_Bai_1_N2_B3(a, 77);
	themSau_Si_29_Bai_1_N2_B3(a, 6, 10);
	output_Si_29_Bai_1_N2_B3(a);
	// count_Si_29_Bai_1_N2_B3(a);
	// int val = 5;
	// if (search_Si_29_Bai_1_N2_B3(a, val))
	// 	cout << "tim thay " << val << " trong danh sach\n";
	// else
	// 	cout << " khong tim thay " << val << " trong danh sach\n";
	// cout << "xuat ds tu phai qua trai\n";
	// output1_Si_29_Bai_1_N2_B3(a);
	// cout << "xoa dau\n=====\n";
	// xoaDau_Si_29_Bai_1_N2_B3(a);
	// output_Si_29_Bai_1_N2_B3(a);
	// cout << "xoa cuoi\n=====\n";
	// xoaCuoi_Si_29_Bai_1_N2_B3(a);
	// output_Si_29_Bai_1_N2_B3(a);
	// count_Si_29_Bai_1_N2_B3(a);
	cout <<"xoa sau so 5\n";
	xoaSauGPT_Si_29_Bai_1_N2_B3(a,66);
	output_Si_29_Bai_1_N2_B3(a);
	return 0;
}