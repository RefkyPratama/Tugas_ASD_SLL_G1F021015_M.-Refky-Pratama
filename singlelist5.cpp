#include<iostream>

using namespace std;

struct sendal{
	string merekProduk,jenisSendal;
	int ukuran,hargaBarang;
	
	sendal *next;
	
};

sendal *head,*tail,*cur,*new_value;

void createSingleLinkedList(string merekProduk, string jenisSendal, int uK, int harga){
	head = new sendal();
	head->merekProduk = merekProduk;
	head->jenisSendal = jenisSendal;
	head->ukuran= uK;
	head->hargaBarang= harga;
	head->next = NULL;
	tail = head;
	
}

void addFirst(string merekProduk, string jenisSendal, int uK, int harga){
	new_value = new sendal();
	new_value->merekProduk = merekProduk;
	new_value->jenisSendal = jenisSendal;
	new_value->ukuran = uK;
	new_value->hargaBarang = harga;
	new_value->next = head;
	head = new_value;
}

void addMiddle(string merekProduk, string jenisSendal, int uK, int harga, int posisi){
	new_value = new sendal();
	new_value->merekProduk = merekProduk;
	new_value->jenisSendal = jenisSendal;
	new_value->ukuran = uK;
	new_value->hargaBarang = harga;
	
	cur = head;
	int NO = 1;
	while(NO < posisi - 1 ){
		cur = cur->next;
		NO++;
	}
	
	new_value->next = cur->next;
	cur->next = new_value;
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
	
	addFirst("SWALLOW", "Casual", 42, 12000);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	addMiddle("ANDO", "casual", 38, 30000, 2);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
}
