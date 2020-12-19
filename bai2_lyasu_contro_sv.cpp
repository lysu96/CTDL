#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sinh_Vien{
	char Hoten[30], Lop[15], SDB[10];
	float DTB;
};

struct Node{
	Sinh_Vien Thongtin_SV;
	Node *next;
};

typedef  Node *List;

void Init(List &L){
	L=NULL;
}

int Isempty(List L){
	return (L==NULL);
}

Node *Make_node(Node *p, Sinh_Vien x){
	p = (Node *) malloc(sizeof(Node));
    p->next = NULL;
    p->Thongtin_SV = x;
    return p;
}

int Size_sv(List L){
	Node *p = L;
    int i = 0;
    while (p != NULL)
	{
        i++;
        p = p->next;
    }
    return i;
}

// them dau
void Insert_fisrt_sv(List &L, Sinh_Vien sv){
	Node *p;
	p = Make_node(p,sv);
	p->next = L;
	L = p;
}

// them vao vi tri k
void insert_K_sv(List &L, Sinh_Vien sv, int k) {
    Node *P, *q = L;
    int i = 1;
    if (k < 1 || k > Size_sv(L) + 1) printf("Vi tri chen khong hop le !");
    else {
        P = Make_node(P, sv);
        if (k == 1) Insert_fisrt_sv(L, sv);
        else {
            while (q != NULL && i != k - 1) 
			{
                i++;
                q = q->next;
            }
            P->next = q->next;
            q->next = P;
        }
    }
}

// den sv DTB>5.0
void Cout_DTB_sv(List L, Sinh_Vien sv){
	Node *p=L;
	int cout=0;
	for(int i=1;i<Size_sv(L);i++){
		if(p->Thongtin_SV.DTB >= 5){
			cout++;
		}
		p = p->next;
	}
	if(cout>0){
		printf("\t\tCo %d sinh vien co(DTB>=5)",cout);
	} else{
		printf("\t\tkhong co sinh vien nao co (DTB>=5)");
	}
}

void Input_sv(List &L){
	Sinh_Vien sv;
	bool stop_sv = true;
	printf("\n\t\t==== Nhap thong tin sinh vien ====");
	do{
		printf("\n Nhap chu (stop) cho ho ten de dung nhap\n");
		printf("\nNhap Ho ten: ");
		fflush(stdin);
		gets(sv.Hoten);
		if(!strcmp(sv.Hoten, "stop")){
			stop_sv = false;
		}
		if(stop_sv){
			printf("Nhap lop: ");
			fflush(stdin);
			gets(sv.Lop);
			printf("Nhap SBD: ");
			fflush(stdin);
			gets(sv.SDB);
			printf("Nhap DTB: ");
			scanf("%f",&sv.DTB);
			insert_K_sv(L,sv,Size_sv(L)+1);
		}
		
	}while(stop_sv);

}

void Output_sv(List L){
	Node *p = L;
	printf("%-30s%-15s%-15s%-5s\n","Ho va ten","Lop","DBD","DTB");
	while(p != NULL){
		printf("%-30s%-15s%-15s%-5.2f%\n",p->Thongtin_SV.Hoten,p->Thongtin_SV.Lop,p->Thongtin_SV.SDB,p->Thongtin_SV.DTB);
		p = p->next;
	}
}

int main(){
	List L;
	Init(L);
	Input_sv(L);
	printf("\n\t\t===DANH SACH SINH VIEN VUA NHAP LA====\n");
	Output_sv(L);
	
	int chon;
	printf("\n1: Them sinh vien vao dau danh sach");
	printf("\n2: Den so sinh vien co (DTB>=5)");
	printf("\n3: Thoat");
	
	do{
		printf("\nMoi chon: ");
		scanf("%d",&chon);
		
		switch(chon){
			case 1:
				{
					Sinh_Vien sv;
					printf("Nhap thong tin sinh vien can them\n");
					printf("\nNhap Ho ten: ");
					fflush(stdin);
					gets(sv.Hoten);
					printf("Nhap lop: ");
					fflush(stdin);
					gets(sv.Lop);
					printf("Nhap SBD: ");
					fflush(stdin);
					gets(sv.SDB);
					printf("Nhap DTB: ");
					scanf("%f",&sv.DTB);
					Insert_fisrt_sv(L,sv);
					printf("\n\t\t===DANH SACH SINH VIEN SAU KHI THEM LA====\n");
					Output_sv(L);
					break;
				}
			case 2:
				{
					Sinh_Vien sv;
					Cout_DTB_sv(L,sv);	
				}
			case 3: break;
		}
	}while(chon!=3);
}

