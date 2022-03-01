#include<iostream>

using namespace std;

struct sendal{
	string merekProduk,jenisSendal;
	int ukuran,hargaBarang;
	
	sendal *next;
	
};

sendal *head, *tail, *cur, *new_value, *del;


void createSingleLinkedList(string merekProduk, string jenisSendal, int uK, int harga){
	head = new sendal();
	head->merekProduk = merekProduk;
	head->jenisSendal = jenisSendal;
	head->ukuran = uK;
	head->hargaBarang = harga;
	head->next = NULL;
	tail = head;
	
}

void addLast(string merekProduk, string jenisSendal, int uK, int harga){
	new_value = new sendal();
	new_value->merekProduk = merekProduk;
	new_value->jenisSendal = jenisSendal;
	new_value->ukuran = uK;
	new_value->hargaBarang = harga;
	new_value->next = NULL;
	tail->next = new_value;
	tail= new_value;
}

void removeLast(){
	del = tail;
	cur = head;
	while(cur->next != tail){
		cur = cur->next;
	}
	tail= cur;
	tail->next =NULL;
	delete del;
}

void printSingleLinkedList(){
	cur = head;
	while(cur != NULL){
		cout << "Merek Sendal : "<< cur->merekProduk <<endl;
		cout << "Jenis Sendal : "<< cur->jenisSendal <<endl;
		cout << "Ukuran Sendal : "<< cur->ukuran <<endl;
		cout << "Harga Sendal : "<< cur->hargaBarang <<endl;
		
		cur = cur->next;
	}
}

int main(){
	
	createSingleLinkedList("EIGER", "Sendal Gunung", 43, 50000);
	
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	addLast("SWALLOW", "Casual", 42, 12000);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	removeLast();
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
}
