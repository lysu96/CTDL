#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinhVien
{
	char HoTen[30];
	char Lop[30];
	char GioiTinh[5];
	char HanhKiem[15];
};

struct Node {
    SinhVien data;
    Node *next;
};
typedef Node *List;
 
void Init(List &L) 
{
    L = NULL;
}
 
Node *make_Node(Node *P, SinhVien x) 
{
    P = (Node *) malloc(sizeof(Node));
    P->next = NULL;
    P->data = x;
    return P;
}
 
int len(List L) {
 
    Node *P = L;
    int i = 0;
    while (P != NULL)
	{
        i++;
        P = P->next;
    }
    return i;
}
 
void insert_First(List &L, SinhVien sv) {
    Node *P;
    P = make_Node(P, sv);
    P->next = L;
    L = P;
}
 
void insertK(List &L, SinhVien sv, int k) {
    Node *P;
    int i = 1;
    if (k < 1 || k > len(L) + 1) printf("Vi tri chen khong hop le !");
    else {
        P = make_Node(P, sv);
        if (k == 1) insert_First(L, sv);
        else {
            while (L != NULL && i != k - 1) 
			{
                i++;
                L = L->next;
            }
            P->next = L->next;
            L->next = P;
        }
    }
}

void inPut(List &L)
{
	SinhVien sv; 
	bool temp= true;
	printf("\n\n\t\t Nhap Thong tin sinh vien:");
	do
	{
	
		printf("\nHo ten sinh vien(dung khi ho ten la finish): ");
		gets(sv.HoTen);
		if (!strcmp(sv.HoTen, "finish")) 
		{
            temp = false;
        }
        if(temp)
        {
		printf("Lop: ");
		gets(sv.Lop);
		printf("Gioi tinh:");
		gets(sv.GioiTinh);
		printf("Hanh kiem: ");
		gets(sv.HanhKiem);
		insertK(L, sv, len(L) + 1);
		}
	}
	while (temp);
}

void outPut(List L) {
//    Node *P = L;
//    while (P != NULL) {
//        printf("Ten sinh vien: %s\n  Lop: %s\n GioiTinh:%s\n  Hanh kiem: %s\n", P->data.HoTen, P->data.Lop, P->data. GioiTinh, P->data.HanhKiem);
//        P = P->next;
//    }
    
    Node *p = L;
	printf("%-30s%-15s%-15s%-5s\n","Ho va ten","Lop","Gioi Tinh","Hanh kiem");
	while(p != NULL){
		printf("%-30s%-15s%-15s%-5s%\n",p->data.HoTen, p->data.Lop, p->data. GioiTinh, p->data.HanhKiem);
		p = p->next;
	}
}

void in_Hanh_Kiem_Tot(List L) {
    Node *P = L;
    while (P != NULL) {
        if (!strcmp(P->data.HanhKiem, "tot")) {
            printf("Ten sinh vien: %s\n Lop: %s\n Goi tinh:%s\n  Hanh kiem: %s\n", P->data.HoTen, P->data.Lop, P->data.GioiTinh, P->data.HanhKiem);
        }
        P = P->next;
    }
}

int main() 
{
    system("cls");
	int a;
	List Lsv;
    Init(Lsv);
    
    inPut(Lsv);
    outPut(Lsv);
    SinhVien sv;
    printf("\nDanh sach sinh vien can chen:\n ");
    printf("Nhap ten sinh vien: ");
    gets(sv.HoTen);
    printf("Nhap lop: ");
    gets(sv.Lop);
    printf("Nhap goi tinh: ");
    gets(sv.GioiTinh);
    printf("Nhap hanh kiem: ");
    gets(sv.HanhKiem);
    printf("Nhap vi tri can chen: ");
    scanf("%d", &a);
    insertK(Lsv, sv, a);
    printf("\nDanh sach sv sau khi chen la:\n ");
    outPut(Lsv);
    printf("\n\nDanh sach sv co hanh kiem tot la: \n");
    in_Hanh_Kiem_Tot(Lsv);
    return 0;
}

