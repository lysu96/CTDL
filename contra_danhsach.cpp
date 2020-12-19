#include <stdio.h>
#include <stdlib.h>

#define N 100;

//=====================Khai bao===============//

// khai bao cau truc 1 cai node
struct Node{
	int Data; // du lieu chua trong node
	struct Node *contro_next; // con tro
};
typedef struct Node NODE; // thay the "struct Node" = NODE

// khai bao cau truc danh sach lien ket
struct List{
	NODE *nodeDau; // node quan ly dau danh sach
	NODE *nodeCuoi; // node quan ly cuoi danh sach
};
typedef struct List LIST;

//===================khoi tao=================//

//khoi tao danh sach
void Khoitao_danhsach(LIST &L){
	
	L.nodeDau = NULL;
	L.nodeCuoi = NULL;
}

// kiem tra danh sach rong
int isEmpty(LIST L){
	return (L.nodeDau==NULL);
}

//khoi tao 1 node
NODE *KhoitaoNode(int n){
	NODE *p = new NODE; // cap phat bo nho cho p
	if(p==NULL){
		printf("\n khong du bo nho de cap phap");
		return NULL;
	}
	p->Data=n; // truyen gia tri n vao cho Data
	p->contro_next=NULL; // chua lien ket den node nao het nen contro_next -> Null
	return p; // tra ve node p vua khoi tao
}

// them 1 node vao dau danh sach
void Them_1_node_vaodau(LIST &L, NODE *p){
	// danh sach rong
	if(isEmpty){
		L.nodeDau = L.nodeCuoi = p; // danh sach rong nodeDau cung chinh la nodeCuoi
	} else{
		p->contro_next = L.nodeDau; // con tro cua node dau "p" lien ket den node dau "nodeDau"
		L.nodeDau = p; // cap nhap lai danh sach node dau chinh la node p
	}
}

// them 1 node vao cuoi danh sach
void Them_1_node_cuoi(LIST &L, NODE *p){
	// danh sach rong
	if(isEmpty){
		L.nodeDau = L.nodeCuoi = p; // danh sach rong nodeDau cung chinh la nodeCuoi
	} else{
		L.nodeCuoi->contro_next = p; //cho con tro "contro_next" lien ket den voi node p
		L.nodeCuoi = p; // cap nhap lai p la node cuoi
	}
} 

// xuat
void xuat(LIST L){
//	for(NODE *k=L.nodeDau;k!=NULL;k=k->contro_next){
//		printf("%5d",k->Data);
//	}
	
	NODE *p=L.nodeDau;
	while(p !=NULL){
		printf("%d ", p->Data);
		p=p->contro_next;
	}	
}
int main(){
	LIST L;
	Khoitao_danhsach(L); // khoi tao danh sach lien ket don
	
	int n;
	printf("Nhap so luong node: ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		printf("\n Nhap gia tri so nguyen: ");
		scanf("%d", &x);
		
		NODE *p = KhoitaoNode(x); // khoi tao 1 node so nguyen
		Them_1_node_vaodau(L,p); // them node p vao dau danh sach lien ket don
	}
	printf("\n\t Danh sach lien ket don vua nhap la: ");
	xuat(L);
	
	return 0;
}
