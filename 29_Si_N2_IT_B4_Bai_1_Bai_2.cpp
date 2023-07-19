#include <iostream>
using namespace std;
const int MAX = 3;
const int MAX2 = 100;

// bai 1
struct stack {
	int a[MAX];
	int top;
};
void init_29_Si_N2_IT_B4_Bai_1(stack& s) {
	s.top = -1;
}
bool isEmpty_29_Si_N2_IT_B4_Bai_1(stack& s) {
	return s.top < 0; //neu stack rong thi tra ve true
}
bool isFull_29_Si_N2_IT_B4_Bai_1(stack& s) {
	return s.top >= MAX - 1; //neu stack day thi tra ve true
}
void push_29_Si_N2_IT_B4_Bai_1(stack& s, int x) {
	s.a[++s.top] = x;
}
int pop_29_Si_N2_IT_B4_Bai_1(stack& s) {
	return s.a[s.top--];
}
void processList_29_Si_N2_IT_B4_Bai_1(stack& s)/*xuat danh sach tu day stack*/ {
	cout << "==========Danh sach stack==========\n";
	for (int i{ 0 }; i <= s.top; ++i)
		cout << s.a[i] << '\t';
	cout << "\n===================================\n";
}
int menu_29_Si_N2_IT_B4_Bai_1() {
	int choice{};
	system("cls");
	//in menu
	cout << "1. Kiem tra stack rong\n";
	cout << "2. Kiem tra stack day\n";
	cout << "3. Them mot phan tu vao stack\n";
	cout << "4. Xoa mot phan tu trong stack\n";
	cout << "5. Xuat cac phan tu trong stack\n";
	cout << "6. Chuyen so thap phan sang nhi phan\n";
	cout << "7. Thoat\n";
	cout << ">";
	cin >> choice;
	return choice;
}

// bai 2
int b[MAX2];
int top2;
void init_29_Si_N2_IT_B4_Bai_2() // khoi tao stack dung de doi so thap phan sang nhi phan
{
	top2 = -1;
}
void push_29_Si_N2_IT_B4_Bai_2(int x) {
	b[++top2] = x;
}
void popSoNhiPhan_29_Si_N2_IT_B4_Bai_2() {
	while(top2 >= 0) //kiem tra neu stack co phan tu
	  cout << b[top2--]; //in phan tu trong stack theo thu tu tu day stack len
	cout << '\n';
}
void doiSo_29_Si_N2_IT_B4_Bai_2(int so) {
	cout << so << " tu he 10 sang he 2 la: "; // hien thi
	while (so != 0)  // kiem tra neu so chua chuyen doi xong
	{
		push_29_Si_N2_IT_B4_Bai_2(so % 2); // dua phan du phep chia 2 vao stack
			so /= 2; // gan so moi
	}
	popSoNhiPhan_29_Si_N2_IT_B4_Bai_2(); // in so nhi phan
}

int main() {
	stack s;
	init_29_Si_N2_IT_B4_Bai_1(s);
	init_29_Si_N2_IT_B4_Bai_2();
	int value{};
	int popV{}; //bien tam dung de luu gia tri khi pop stack
	int soThapPhan{};
	while (true) {
		switch (menu_29_Si_N2_IT_B4_Bai_1()) {
		case 1: // kiem tra neu stack rong
			if (isEmpty_29_Si_N2_IT_B4_Bai_1(s))
				cout << "==========\nStack rong\n==========\n";
			else
				cout << "==========\nStack co phan tu\n==========\n";
			system("pause");
			break;
		case 2: // kiem tra neu stack day
			if (isFull_29_Si_N2_IT_B4_Bai_1(s))
				cout << "==========\nStack day\n==========\n";
			else
				cout << "==========\nStack chua day\n==========\n";
			system("pause");
			break;
		case 3: // them phan tu vao stack
			if(isFull_29_Si_N2_IT_B4_Bai_1(s)) // kiem tra neu stack day
				cout << "==========\nStack day nen khong the them\n==========\n"; 
			else {
				cout << "==========\nNhap phan tu muon them vao stack: ";
				cin >> value;
				push_29_Si_N2_IT_B4_Bai_1(s, value);
				cout << "==========\nThem thanh cong\n==========\n";
			}
			system("pause");
			break;
		case 4: // xoa phan tu trong stack
			if(isEmpty_29_Si_N2_IT_B4_Bai_1(s)) // kiem tra neu stack co phan tu
				cout << "==========\nStack rong nen khong the xoa\n==========\n"; 
			else {
				popV = pop_29_Si_N2_IT_B4_Bai_1(s);
				cout << "==========\nXoa thanh cong\n==========\n";
			}
			system("pause");
			break;
		case 5: // in stack
			processList_29_Si_N2_IT_B4_Bai_1(s); // in stack
			system("pause");
			break;
		case 6: // doi so thap phan thanh nhi phan( bai 2)
			cout << "==============================\nNhap so can chuyen doi: ";
			cin >> soThapPhan;
			doiSo_29_Si_N2_IT_B4_Bai_2(soThapPhan);
			system("pause");
			break;
		case 7:
			cout << "==========\nBan da chon thoat!\n==========\n";
			system("pause");
			return 0;
		default:
			cout << "Khong hop le, vui long nhap lai!\n";
			system("pause");
			break;
		}
	}
	return 0;
}