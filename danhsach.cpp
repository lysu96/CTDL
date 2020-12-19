#include <stdio.h>
#include <stdlib.h>
// 
#define N 100
typedef int item;

typedef struct{
	item Elems[N]; //Mang kieu DL la item
	int size; // kich thuoc cua mang danh sach
}List;

void Init(List *L); //Khoi tao danh sach rong
void Input(List *L); // nhap phan tu cho danh sach
void Output(List L); // Xuat phan tu cua danh sach
void Insert_k(List *L); // them pt dsach
void Edit_k(List *L); // sua pt danh sach
void Delete_k(List *L); // xoa pt dsach
void Seach_k(List L); // vi tri so phan tu k

int isEmpty(List L); // kiem tra danh sach co rong hay khong
int isFull(List L); // kiem tra danh sach co day hay kong

void Init(List *L){
	(*L).size = 0; // danh sach rong
}

void Input(List *L){
	printf("Nhap so luong phan tu danh sach: ");
	scanf("%d", &(*L).size);
	for(int i = 0;i<(*L).size;i++){
		printf("nhap phan tu thu %d: ", i+1);
		scanf("%d", &(*L).Elems[i]);
	}
}

void Output(List L){
	for(int i=0;i<L.size;i++){
		printf("%d ", L.Elems[i]);
	}
}

void Seach_k(List L){
	int k;
	printf("\nnhap phan tu k can tim: ");
	scanf("%d", &k);
	for(int i=0;i<L.size;i++){
		if(L.Elems[i] == k){
			printf("Phan tu %d o vi tri: %d",k, i+1);
		}
	}
}

void Insert_k(List *L){
	int k, x;
	printf("\nNhap vi tri can them: ");
	scanf("%d", &k);
	if((*L).size >= N){
		printf("\nDanh sach day.! Khong the them");	
	}
	else{
		if(k < 0){
			k = 0;
		}else if(k > (*L).size){
			k = (*L).size;	
		}
		printf("Nhap so moi can them: ");
		scanf("%d", &x);
		for(int i = (*L).size;i>k;i--){
			(*L).Elems[i] = (*L).Elems[i-1];
		}
		(*L).Elems[k] = x;
		++(*L).size;
	}
}

void Edit_k(List *L){
	int k, x;
	printf("\nNhap gia tri can sua: ");
	scanf("%d", &k);
	printf("Nhap so moi: ");
	scanf("%d", &x);
	for(int i=0;i<(*L).size;i++){
		if((*L).Elems[i] == k){
			(*L).Elems[i] = x;
		}
	}
}

void Delete_k(List *L){
	int x;
	printf("\nNhap vi tri can xoa: ");
	scanf("%d", &x);
	if((*L).size==0){
		printf("danh sach rong.");
	}
	else if(x>(*L).size-1 || x<0){
		printf("vi tri xoa khong hop le");
	}
	else{
		for(int i=x;i<(*L).size-1;i++){
			(*L).Elems[i] = (*L).Elems[i+1];
		}
		--(*L).size;
	}
}

int main(){
	List danhsach;
	Init(&danhsach);
	Input(&danhsach);
	printf("Danh sach phan tu vua nhap la: \n");
	Output(danhsach);
	printf("\n");
	
	Seach_k(danhsach);
	Insert_k(&danhsach);
	printf("\nDanh sach sao khi them la: \n");
	Output(danhsach);
	printf("\n");
	
	Edit_k(&danhsach);
	printf("\nDanh sach sao khi sua la: \n");
	Output(danhsach);
	printf("\n");
	
	Delete_k(&danhsach);
	printf("\nDanh sach sao khi xoa la: \n");
	Output(danhsach);
	
	return 0;
}
