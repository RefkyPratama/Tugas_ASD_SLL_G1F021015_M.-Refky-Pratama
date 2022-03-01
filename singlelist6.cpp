#include<iostream>

using namespace std;

struct sendal{
	string merekProduk,jenisSendal;
	int ukuran,hargaBarang;
	
	sendal *next;
	
};

sendal *head, *tail, *cur, *new_value, *del, *after;


void createSingleLinkedList(string merekProduk, string jenisSendal, int uK, int harga){
	head = new sendal();
	head->merekProduk = merekProduk;
	head->jenisSendal = jenisSendal;
	head->ukuran= uK;
	head->hargaBarang= harga;
	head->next = NULL;
	tail = head;
	
}

int countSingleLinkedList(){
	cur = head;
	int NO = 0;
	while(cur != NULL){
		NO++;
		cur = cur->next;
	}
	return NO;
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

void removeMiddle(int posisi){
	if ( posisi < 1 || posisi > countSingleLinkedList() ){
		cout << "Posisi Diluar jangkauan " << endl;
	}else if( posisi == 1 || posisi == countSingleLinkedList() ){
		cout << "Posisi bukan posisi tengah " << endl;
	} else {
	int NO = 1;
	cur = head;
	while (NO <= posisi){
		if (NO == posisi -1){
			after = cur;
		}
		if (NO == posisi){
			del = cur;
		}
		cur = cur->next;
		NO++;
	}
	after->next = cur;
	delete del;
	}
}

void printSingleLinkedList(){
	cout << "Nomor data ada : " << countSingleLinkedList() << endl;
	cur = head;
	while(cur != NULL){
		cout << "Merek Sepatu : "<< cur->merekProduk <<endl;
		cout << "Jenis Sepatu : "<< cur->jenisSendal <<endl;
		cout << "Ukuran Sepatu : "<< cur->ukuran <<endl;
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
	
	addMiddle("ANDO", "Sendal Gunung", 38, 30000, 2);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	addMiddle("ARDILES", "Casual", 40, 40000, 2);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	removeMiddle(2);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
}
