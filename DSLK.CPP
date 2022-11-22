#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
	// dulieu
	int data;
	// lien ket link
	node *next; // con tro luu dia chi

};
node *makenode(int x){
	node *newnode = new node;
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
// duyet danh sach lien ket
void duyet(node *head){
	while(head != NULL){
		cout << head->data << ' ';
		head = head->next; // di chuyen node hien tai sang node ke tiep
	}
}
int SZ(node *head){ // dem kich thuoc
	int dem = 0;
	while(head != NULL){
		++dem;
		head = head->next;
	}
	return dem;
}
// them node : dau, cuoi, giua
void themdau(node *&head, int x){
	node *newnode = makenode(x);
	// cho node moi luu dia chi node dau tien torng danh sach lien ket
	newnode->next = head;
	head = newnode; 
}
// them cuoi
void themcuoi(node *&head, int x){
	node *newnode = makenode(x);
	if(head == NULL){
		head = newnode;
		return;
	}
	node *tmp = head;
	while(tmp->next != NULL){
		tmp = tmp->next;
	}
	// tmp la node cuoi cung trong dslk
	tmp->next = newnode;
}
// them giua
void themgiua(node *&head, int x, int k){
	node *newnode = makenode(x);
	node *tmp = head;
	int n = SZ(head);
	if(k < 1 || k > n)
		return; // vi tri 0 hop le
	if(k == 1){
		themdau(head, x);
		return;
	}
	for(int i = 1; i <= k - 2; i++){
		tmp = tmp->next;
	}
	newnode->next = tmp->next;
	tmp->next = newnode;
}
// xoa dau, xoa giua , xoa cuoi;
void xoadau(node *&head,){
	if(head = NULL) return;
	node *firstnode = head;
	head = head->next;
	delete firstnode;
}
void xoacuoi(node *&head){
	if(head = NULL) return;
	node *tmp = head;
	if(head->next == NULL){
		// co 1 node
		delete head;
		head = NULL;
	}
	while(tmp->next->next != NULL){
		tmp = tmp->next;
	}
	node *lastnode = tmp->next;
	tmp->next = NULL;
	delete lastnode;
}
void xoagiua(node *&head, int k){
	int n = SZ(head);
	if(k < 1 || k > n) return;
	if(k == 1){
		xoadau(head); return;
	}
	node *tmp = head;
	for(int i = 1; i <= k - 2; i++){
		tmp = tmp->next;
	}
	node *knode = tmp->next; // node thu k
	tmp->next = tmp->next->next;
	delete knode;
}
int main(){
	

}