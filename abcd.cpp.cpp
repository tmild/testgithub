#include<iostream>
using namespace std;
struct Node{
	int Data;
	Node* next;
};

struct Queue{
	Node* Dau;
	Node* Cuoi;
};

Node* newNode(int n);
void newQueue(Queue& Q);
int count(Queue Q);
void addLast(Queue& Q);
void takeFirst(Queue Q);
void delFirst(Queue& Q);
void inQueue(Queue& Q);
void outQueue(Queue Q);

int main(){
	Queue Q;
	newQueue(Q);
	cout << "1. Khoi tao du lieu cho ngan xep: \n";
	inQueue(Q);
	outQueue(Q);
	
	cout << "\n\n2. Them mot phan tu vao cuoi ngan xep: \n";
	cout << "Nhap phan tu thu " << count(Q) + 1 << ": ";
	addLast(Q);
	outQueue(Q);
	
	cout << "\n\n3. Lay mot phan tu ra khoi ngan xep: \n";
	takeFirst(Q);
				if(Q.Dau == NULL){
				}
				else {
					delFirst(Q);
					outQueue(Q);
				}
	
	cout << "\n\n4. Hien thi du lieu co trong ngan xep: \n";
	outQueue(Q);
}

//hàm tạo mode mởi
Node* newNode(int n){
	Node* p = new Node;
	p->Data = n;
	p->next = NULL;
	return p;
}

//hàm tạo hàng đợi mới
void newQueue(Queue& Q){
	Q.Dau = NULL;
	Q.Cuoi = NULL;
}

//hàm đếm số phần tử của hàng đợi
int count(Queue Q){
	int dem = 0;
	Node* p = Q.Dau;
	while(p != NULL){
		dem++;
		p = p->next;
	}
	return dem;
}

//hàm thêm phần tử vào hàng đợi
void addLast(Queue& Q){
	int n; cin >> n;
	Node* p = newNode(n);
	if (Q.Dau == NULL){
		Q.Dau = p;
		Q.Cuoi = p;
	}else {
		Q.Cuoi->next = p;
		Q.Cuoi = p;
	}
}

//hàm lấy phân tử đầu hàng đợi
void takeFirst(Queue Q){
	if(Q.Dau == NULL) cout << "\nHang doi rong!";
	else cout << "Phan tu dau tien co gia tri: " << Q.Dau->Data;
}

//hàm xóa phần tử đầu hàng đợi
void delFirst(Queue& Q){
	if (Q.Dau == NULL) cout << "\nHang doi rong!";
	else {
		Q.Dau = Q.Dau->next;
	}
}

//hàm nhập hàng đợi
void inQueue(Queue& Q){
	int n; cout << "\nNhap so phan tu cua hang doi: "; cin >> n;
	for (int i = 1; i <= n ; i++){
		cout << "Nhap phan tu thu " << i << ": ";
		addLast(Q);
	}
}

//hàm xuất hàng đợi
void outQueue(Queue Q){
	Node* p = Q.Dau;
	if (Q.Dau == NULL) cout << "\nHang doi rong!";
	else {
		cout << "\nHang doi sau khi nhap va xu ly: ";
		while(p != NULL){
			cout << p->Data << " ";
			p = p->next;
		}
	}
}
