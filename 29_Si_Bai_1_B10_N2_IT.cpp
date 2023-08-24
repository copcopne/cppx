#include <iostream>
#include <fstream>
using namespace std;
const int MAX = 100;
char dinh[MAX];
int n{};
int a[MAX][MAX];
struct node {
    int info;
    node* link;
};
node* front,* rear, *sp;
void init_29_Si_Bai_1_B10_N2_IT() {
    front = NULL;
    rear = NULL;
    sp = NULL;
}
void PushQ_29_Si_Bai_1_B10_N2_IT(int x) {
    node* p = new node;
    p->info = x;
    p->link = NULL;
    if (rear == NULL)
        front = p;
    else
        rear->link = p;
    rear = p;
}
void PopQ_29_Si_Bai_1_B10_N2_IT(int& x) {
    if (front != NULL) {
        node* p = front;
        x = p->info;
        front = front->link;
        if (front == NULL)
            rear == NULL;
        delete p;
    }
}
void PushS_29_Si_Bai_1_B10_N2_IT(int x) {
    node* p = new node;
    p->info = x;
    p->link = sp;
    sp = p;
}
void PopS_29_Si_Bai_1_B10_N2_IT(int& x) {
    if (sp != NULL) {
        node* q = sp;
        x = q->info;
        sp = sp->link;
        delete q;
    }
}
void nhap_29_Si_Bai_1_B10_N2_IT() { // nhap ma tran
    do {
        cout << "Nhap so luong dinh cua do thi: ";
        cin >> n;
    } while (n <= 0 || n > MAX);
    cout << "Nhap ten cac dinh cua do thi theo thu tu: ";
    for (int i{}; i < n; ++i) {
        cin >> dinh[i];
    }
    for (int i{}; i < n; ++i) {
        cout << "Nhap (1/0) cua cac dinh voi dinh " << dinh[i] << ": ";
        for (int j{}; j < n; ++j) {
            cin >> a[i][j];
        }
    }
}
void xuat_29_Si_Bai_1_B10_N2_IT() { // xuat ma tran
    cout << " \t";
    for (int i{}; i < n; ++i) {
        cout << dinh[i] << "\t";
    }
    cout << '\n';
    for (int i{}; i < n; ++i) {
        cout << dinh[i] << '\t';
        for (int j{}; j < n; ++j) {
            cout << a[i][j] << '\t';
        }
        cout << '\n';
    }
}
void docFile_29_Si_Bai_1_B10_N2_IT() { // doc file
    ifstream in;
    in.open("dothi.txt");
    if (!in.is_open()) {
        cout << "Khong doc duoc file!\n";
    }
    else {
        in >> n;
        for (int i{}; i < n; ++i)
            in >> dinh[i];
        for (int i{}; i < n; ++i)
            for (int j{}; j < n; ++j)
                in >> a[i][j];
        cout << "Doc file thanh cong!\n";
        in.close();
    }
}
int C[MAX], bfs[MAX];
int nbfs{};
// duyet BFS (queue)
void InitC_29_Si_Bai_1_B10_N2_IT() {
	for (int i{}; i < n; ++i) // n la so dinh cua do thi
		C[i] = 1;
}
void BFS_29_Si_Bai_1_B10_N2_IT(int v) { // v la dinh bat dau
	int w, p;
	PushQ_29_Si_Bai_1_B10_N2_IT(v);
	C[v] = 0;
	while (front != NULL) {
		PopQ_29_Si_Bai_1_B10_N2_IT(p);
		bfs[nbfs] = p;
        nbfs++;
        for (w = 0; w < n; ++w) {
            if (C[w] && a[p][w] == 1) {
                PushQ_29_Si_Bai_1_B10_N2_IT(w);
                C[w] = 0;
            }
        }
	}
}
void outputBFS_29_Si_Bai_1_B10_N2_IT() {
    for (int i{}; i < nbfs; ++i) // n la so dinh cua do thi
        cout << bfs[i] << " ";
    cout << '\n';
}
// duyet DFS (stack)
int dfs[MAX];
int ndfs{};
void DFS_29_Si_Bai_1_B10_N2_IT(int s) {
    PushS_29_Si_Bai_1_B10_N2_IT(s);
    dfs[ndfs] = s;
    ndfs++;
    C[s] = 0;
    int v{ -1 }, u{ s };
    while (sp != NULL) {
        if (v == n)
            PopS_29_Si_Bai_1_B10_N2_IT(u);
        for (v = 0;v<n;++v) 
            if (a[u][v] != 0 && C[v] == 1) {
                PushS_29_Si_Bai_1_B10_N2_IT(u);
                PushS_29_Si_Bai_1_B10_N2_IT(v);
                dfs[ndfs] = v;
                ndfs++;
                C[v] = 0;
                u = v;
                break;
            }
    }
}
void outputDFS_29_Si_Bai_1_B10_N2_IT() {
    for (int i{}; i < ndfs; ++i)
        cout << dfs[i] << " ";
    cout << '\n';
}

int main() {
    init_29_Si_Bai_1_B10_N2_IT();
    nhap_29_Si_Bai_1_B10_N2_IT();
    xuat_29_Si_Bai_1_B10_N2_IT();
    InitC_29_Si_Bai_1_B10_N2_IT();
    BFS_29_Si_Bai_1_B10_N2_IT(0);
    outputBFS_29_Si_Bai_1_B10_N2_IT();
    system("pause");
}