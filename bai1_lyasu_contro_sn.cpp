#include<stdio.h>
#include<stdlib.h>
typedef int item; 
typedef struct Node 
{
    item Data; 
    Node *next;
};
typedef Node *List; 
 
void Init (List &L); 
int len (List L);
Node *Make_Node (Node *P, item x);
void Insert_first (List &L, item x);
void Insert_k (List &L, item x, int k);
void Input (List &L);
void Output (List L);
int Search (List L, item x); 
void Del_frist (List &L, item &x);
void Del_k (List &L, item &x, int k); 
void Delete_last(List &L, item &x);
void Cout_Negative_elements(List L, item x);
float Average_l(List L, item x);
 
void Init (List &L) 
{
    L=NULL;
}
 
int Isempty (List L)
{
    return (L==NULL);
}
 
int len (List L) 
{
    Node *P=L; 
    int i=0; 
    while (P!=NULL) //trong khi P chua tro den NULL (cuoi danh sach thi lam)
    {
        i++; 
        P=P->next; 
    }
    return i;
}
 
Node *Make_Node (Node *P, item x)  
{
    P = (Node *) malloc (sizeof (Node)); 
    P->next = NULL; 
    P->Data = x; 
    return P; 
}

//Chen x vao vi tri dau tien trong danh sach
void Insert_first (List &L, item x)  
{
    Node *P; 
    P = Make_Node(P,x); 
    P->next = L; 
    L = P; 
}
 
 //chen x vao vi tri k trong danh sach
void Insert_k (List &L, item x, int k) 
{
    Node *P, *Q = L; 
    int i=1;
    if (k<1 || k> len(L)+1) printf("Vi tri chen khong hop le !"); 
    else
    {
        P = Make_Node(P,x); 
        if (k == 1) Insert_first(L,x); 
        else //chen vao k != 1
        {
            while (Q != NULL && i != k-1)
            {
                i++;
                Q = Q->next;
            }
            P->next = Q->next; 
            Q->next = P;
        }
    }
}
 
//tim x trong danh sach
int Search (List L, item x)
{
    Node *P=L; 
    int i=1;
    while (P != NULL && P->Data != x) //duyet danh sach den khi tim thay hoac ket thuc danh sach
    {
        P = P->next;
        i++;
    }
    if (P != NULL) return i; 
    else return 0; 
}

//Xoa phan tu dau tien
void Del_frist (List &L, item &x) 
{
    x = L->Data;
    L = L->next; 
}

//Xoa Node k trong danh sach
void Del_k (List &L, item &x, int k) 
{
    Node *P=L;
    int i=1;
    if (k<1 || k>len(L)) printf("Vi tri xoa khong hop le !");
    else
    {
        if (k==1) Del_frist(L,x); 
        else //xoa vi tri k != 1
        {
            while (P != NULL && i != k-1) //duyet den vi tri k-1
            {
                P=P->next;
                i++;
            }
            P->next = P->next->next; 
        }
    }
}
 // xoa cuoi
 void Delete_last(List &L, item &x){
	Node *p=L;
	while(p->next->next != NULL){
		p = p->next;	
	}
	p->next = NULL;
}
 // den so am
 void Cout_Negative_elements(List L, item x){
 	Node *P=L; 
    int i, cout=0;
    for(i=1;i<len(L);i++){
    	if(P->Data < 1){
    		cout++;
		}
		P = P->next;
	}
	if(cout>0){
		printf("\t\tCo %d so am",cout);
	}
	else
	{
		printf("\t\tKhong co so am nao trong danh sach\n");
	}
}
//tinh tong
float Average_l(List L, item x){
	Node *p = L;
	int s=0;
	while(p!=NULL){
		s += p->Data;
		p=p->next;
	}
	return(s);
}

//nhap danh sach
void Input (List &L) 
{
    int i=0; 
    item x;
    printf ("Nhap (0) de ket thuc lenh nhap\n");
    do
    {
        i++;
        printf ("Nhap phan tu thu %d : ",i);
        scanf("%d",&x);
        if (x != 0) Insert_k(L,x,len(L)+1);
    } while(x != 0); //nhap 0 de ket thuc
}
 
//xuat danh sach
void Output (List L) 
{
    Node *P=L;
    while (P != NULL)
    {
        printf("%5d",P->Data);
        P = P->next;
    }
    printf("\n");
}
 
int main()
{
    List L;
    Init(L);
    Input(L);
    Output(L);
 
    int lua_chon;
    printf("MOI BAN LUA CHON CAC PHEP TOAN SAU:");
    printf("\n1: Tinh do dai danh sach");
    printf("\n2: Tim mot phan tu trong danh sach");
    printf("\n3: Them phan tu x vao vi tri dau danh sach");
    printf("\n4: Them phan tu x vao vi tri k trong danh sach");
    printf("\n5: Xoa phan tu ra khoi vi tri dau danh sach");
    printf("\n6: Xoa phan tu tai vi tri k trong danh sach");
    printf("\n7: Den so phan tu am trong danh sach");
    printf("\n8: xoa phan tu o cuoi danh sach");
    printf("\n9: Tinh trung binh cong cua cac so trong danh sach");
    printf("\n10: Thoat");
    do
    {
        printf("\nBan chon: ");
        scanf("%d",&lua_chon);
    switch (lua_chon)
    {
        case 1: printf ("Do dai DS la: %d.",len(L));break;
        case 2:
        {
            item x;
            printf ("Moi ban nhap vao phan tu can tim: ");
            scanf("%d",&x);
            int k=Search(L,x);
            if (k) printf ("Tim thay %d trong DS tai vi tri thu: %d",x,k);
            else printf ("Khong tim thay %d trong danh sach !",x);
            break;
        }
        case 3:
        {
            item x;
            printf ("Nhap phan tu can them vao DS: ");
            scanf("%d",&x);
            Insert_first(L,x);
            printf ("DS sau khi them:\n");
            Output(L);
            break;
        }
        case 4:
        {
            item x;
            int k;
            printf ("Nhap phan tu can them vao DS: ");
            scanf("%d",&x);
            printf ("Nhap vi tri can them: ");
            scanf ("%d",&k);
            Insert_k (L,x,k);
            printf ("DS sau khi them:\n");
            Output(L);
            break;
        }
        case 5:
        {
            item x;
            Del_frist(L,x);
            printf ("DS sau khi xoa:\n");
            Output(L);
            break;
        }
        case 6:
        {
            int k;
            item x;
            printf ("Nhap vi tri can xoa: ");
            scanf ("%d",&k);
            Del_k (L,x,k);
            printf ("DS sau khi xoa:\n");
            Output(L);
            break;
        }
        case 7:
        {
            item x;
            Cout_Negative_elements(L,x);
            break;
        }
        case 8:
        {
        	item x;
        	Delete_last(L,x);
        	printf("\t\tDanh sach sau khi xoa: ");
            Output(L);
            break;
        }
        case 9:
        {
        	item x;
        	printf("\nTrung binh cong cua danh sach la: %0.2f",Average_l(L,x)/len(L));
            break;
        }
        case 10: break;
    }
    }while (lua_chon !=10);
    return 0;
}
