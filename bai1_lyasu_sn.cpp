#include <stdio.h>
#include <stdlib.h>

typedef int item;
typedef struct Node{
	item Data;
	Node *next;
};
typedef Node *List;

void Init(List &L);
int Isempty(List L);
int Size(List L);
Node *Make_node(Node *p, item x);
void Insert_first_sn(List &L, item x);
void Insert_k_ns(List &L, item x, int k);
int Seach(List L, item x);
void Delete_first(List &L, item &x);
void Delete_k(List &L, item x, int k);
void Delete_last(List &L, item &x);
int Cout_Negative_elements(List L, item x);
float Average_l(List L, item x);
void Input_integer(List &L);
void Output_integer(List L);

void Init(List &L){
	L==NULL;
}

int Isempty(List L){
	return(L==NULL);
}

int Size(List L){
	Node *P=L;
    int i=0; 
    while (P!=NULL)
    {
        i++;
        P=P->next; 
    }
    return i;
}

Node *Make_node(Node *p, item x){
	p = (Node *) malloc (sizeof(Node));
	p = p->next;
	p->Data = x;
	return p;
}

void Insert_first_sn(List &L, item x){
	Node *p;
	p = Make_node(p,x);
	p->next = L;
	L = p;
}

void Insert_k_ns(List &L, item x, int k){
	Node *P, *Q = L; 
    int i=1;
    if (k<1 || k> Size(L)+1) printf("Vi tri chen khong hop le !"); //kiem tra dieu kien
    else
    {
        P = Make_node(P,x); //tao 1 Node P
        if (k == 1) Insert_first_sn(L,x); //chen vao vi tri dau tien
        else //chen vao k != 1
        {
            while (Q != NULL && i != k-1) //duyet den vi tri k-1
            {
                i++;
                Q = Q->next;
            }
            P->next = Q->next; 
            Q->next = P;
        }
    }
}

int Seach(List L, item x){
	Node *p = L;
	int i=1;
	while(p!=NULL && p->Data!=x){
		p = p->next;
		i++;
	}
	if(p!=NULL) return i;
	else return 0;
}

void Delete_first(List &L, item &x){
	x = L->Data;
	L = L->next;
}

void Delete_k(List &L, item x, int k){
	Node *p=L;
	int i=1;
	if(k<1 && k>Size(L)) printf("Vi tri xoa khong hop le.!");
	else{
		if(k==1) Delete_first(L,x);
		else{
			while(p!=NULL && i!=k){
				p=p->next;
				i++;
			}
			p->next = p->next->next;
		}
	}
}
void Delete_last(List &L, item &x){
	Node *p=L;
	x = p->Data;
	int i = 0;
	while(p->next != NULL){
		p = p->next;
		i++;	
	}
	p->next = NULL;
	L = p;
	
}

int Cout_Negative_elements(List L, item x){
	Node *p = L;
	int cout=0;
	for(int i = 1;i<Size(L);i++){
		if(p->Data <= -1){
			cout++;
		}
	}
	if(cout!=0){
		return cout;
	}
	else
	{
		return 0;
	}
}

float Average_l(List L, item x){
	Node *p = L;
	int s=0, i = 1;
	while(p!=NULL){
		s += p->Data;
		p=p->next;
		i++;
	}
	return(s/Size(L));
}

void Input_integer(List &L){
	int i=0; 
    item x;
    printf ("Nhap (0) de ket thuc lenh nhap\n");
    do
    {
        i++;
        printf ("Nhap phan tu thu %d : ",i);
        scanf("%d",&x);
        if (x != 0) Insert_k_ns(L,x,Size(L)+1);
    } while(x != 0);
}

void Output_integer(List L){
	Node *p = L;
	while(p!=NULL){
		printf("%5d",p->Data);
		p = p->next;
	}
	printf("\n");
}
int main(){
	List l;
	Init(l);
	Input_integer(l);
	Output_integer(l);
	
	int lua_chon;
    printf("MOI BAN LUA CHON CAC PHEP TOAN:");
    printf("\n1: Them mot phan tu vao dau danh sach");
    printf("\n2: Them mot phan tu vao vi tri k bat ky trong danh sach");
    printf("\n3: Den so phan tu am trong danh sach");
    printf("\n4: xoa phan tu o cuoi danh sach");
    printf("\n5: Tinh trung binh cong cua cac so trong danh sach");
    printf("\n6: Thoat");
    do
    {
        printf("\nBan chon: ");
        scanf("%d",&lua_chon);
    switch (lua_chon)
    {
        case 1:
		{
			item x;
			printf("nhap phan tu can them: ");
			scanf("%d",&x);
			Insert_first_sn(l,x);
			printf("\t\tDanh sach sau khi them: ");
			Output_integer(l);
			
		}
        case 2:
        {
            item x;
            int k;
            printf ("Nhap phan tu can them vao danh sach: ");
            scanf("%d",&x);
            printf ("Nhap vi tri can them: ");
            scanf ("%d",&k);
            Insert_k_ns(l,x,k);
            printf ("Danh sach sau khi them: ");
            Output_integer(l);
            break;
        }
        case 3:
        {
            item x;
            int am = Cout_Negative_elements(l,x);
            if(am == 0){
            	printf("khong tim thay phan tu nao am");
			}else{
				printf ("DS sau khi them: %d",am);
			}
            break;
        }
        case 4:
        {
        	item x;
        	Delete_last(l,x);
        	printf("\t\tDanh sach sau khi xoa: ");
            Output_integer(l);
            break;
        }
        case 5:
        {
        	item x;
        	printf("\nTrung binh cong cua danh sach la: %f",Average_l(l,x));
            break;
        }
        case 6: break;
    }
    }while (lua_chon !=6);
	return 0;
}

