// cay nhi phan tim kiem
//##########################//
//        LY A Sú		   	//
//#########################//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef int item;
struct TKNode{
	item Data;
	TKNode*Left;
	TKNode*Right;
};

typedef TKNode* TimKiem;
//
void KhoiTao_TK(TimKiem &T){
	T = NULL;
}
// 

TimKiem Xacdinh_Contrai(TimKiem CT){
	if(CT != NULL)
		return CT->Left;
	else
		return NULL;
}
//
TimKiem Xacdinh_Conphai(TimKiem CP){
	if(CP != NULL)
		return CP->Right;
	else
		return NULL;
}
// Duyet Dau
void Duyet_Tiento(TimKiem T){
	printf("%d ",T->Data);
	if(Xacdinh_Contrai(T) != NULL)
		Duyet_Tiento(Xacdinh_Contrai(T));
	if(Xacdinh_Conphai(T) != NULL)
		Duyet_Tiento(Xacdinh_Conphai(T));
}
// Duyet Giua
void Duyet_Trungto(TimKiem T){
	if(Xacdinh_Contrai(T) != NULL)
		Duyet_Trungto(Xacdinh_Contrai(T));
	printf("%d ",T->Data);
	if(Xacdinh_Conphai(T) != NULL)
		Duyet_Trungto(Xacdinh_Conphai(T));
}
// Duyet Cuoi
void Duyet_Hauto(TimKiem T){
	if(Xacdinh_Contrai(T) != NULL)
		Duyet_Hauto(Xacdinh_Contrai(T));
	if(Xacdinh_Conphai(T) != NULL)
		Duyet_Hauto(Xacdinh_Conphai(T));
	printf("%d ",T->Data);
}
// them 1 khoa vao cay
void Them_TKNode(TimKiem *T, item x){
	if(*T == NULL){
		(*T) = (TKNode*)malloc(sizeof(TKNode));
		(*T)->Data = x;
		(*T)->Left = NULL;
		(*T)->Right = NULL;
	}
	else
	{
		if(x<(*T)->Data)
			Them_TKNode(&(*T)->Left,x);
		else
		if(x>(*T)->Data)
			Them_TKNode(&(*T)->Right,x);
	}
}
// nhap
void Nhap_TKNode(TimKiem *T){
	int x;
	printf("Nhap vao cac phan tu trong cay nhi phan tim kiem.\n");
	printf("Nhap (0) de ket thuc nhap\n");
	do{
		printf("Node = ");
		scanf("%d",&x);
		if(x != 0)
			Them_TKNode(&*T,x);
	}while(x != 0);
}

// tim
int Tim_Khoa_K(TimKiem T, item x){
	if(T == NULL){
		return 0;
	}	
	else
	{
		if(T->Data == x){
			return 1;
		}
		else
		{
			if(T->Data<x){
				return Tim_Khoa_K(T->Right,x);
			}
			else
			{
				return Tim_Khoa_K(T->Left,x);
			}
		}
	}	
}

// them k
TKNode* Them_Node_k(TKNode* T, int k)
{
    if (T == NULL)
    {
        TKNode* node = (TKNode*)malloc(sizeof(TKNode));
        node->Left = node->Right = NULL;
        node->Data = k;
        return node;
    }
    if (k<T->Data)
        T->Left = Them_Node_k(T->Left,k);
    else if (k>T->Data)
        T->Right = Them_Node_k(T->Right,k);
    return T;
}

// xoa k
int Lay_giatri_conlai( TKNode* T)
{
    while ( T->Left != NULL )
        T = T->Left;
    return T->Data;
}
 
TKNode* Xoa_NPTK(TKNode* T,int h)
{
    if (T == NULL)
        return T;
    if (h<T->Data)
        T->Left = Xoa_NPTK(T->Left,h);
    else if (h>T->Data)
        T->Right = Xoa_NPTK( T->Right,h);
    else
    {
        // T->Data == h, Dieu kien xoa node
        if (T->Left == NULL)
        {
            TKNode* T_m = T->Right;
            free(T);
            return T_m;
        }
        if (T->Right == NULL)
        {
            TKNode* T_m = T->Left;
            free(T);
            return T_m;
        }
        T->Data = Lay_giatri_conlai(T->Right);
        T->Right = Xoa_NPTK(T->Right, T->Data);
    }
    return T;
}

int main(){
	TimKiem Tm;
	KhoiTao_TK(Tm);

	Nhap_TKNode(&Tm);
		
	int chon;
    printf("\n\t\t=== MOI BAN CHON ===");
    printf("\n1: Duyet theo Tien to");
    printf("\n2: Duyet theo Trung to");
    printf("\n3: Duyet theo Hau to");
    printf("\n4: Tim kiem 1 dinh co khoa x trong cay");
    printf("\n5: Them 1 khoa vao trong cay");
    printf("\n----Y 6 em lam them-----");
    printf("\n6: xoa 1 khoa khoi cay");
    printf("\n7: Thoat");
    
    do
    {
        printf("\nBan chon: ");
        scanf("%d",&chon);
    switch (chon)
    {
        case 1:
        	{
            	printf("Gia tri cua cay duyet theo Tien to: ");
				Duyet_Tiento(Tm);
            	break;
        	}
        case 2:
        	{
       		 	printf("Gia tri cua cay duyet theo Trung to: ");
				Duyet_Trungto(Tm);	
            	break;
			}
		case 3:
        	{
				printf("Gia tri cua cay duyet theo Hau to: ");
				Duyet_Hauto(Tm);	
            	break;
			}
        case 4:
	        {
	        	int c;
				printf("Nhap phan tu can tim: ");
				scanf("%d",&c);
				if(Tim_Khoa_K(Tm,c) == 0){
					printf("Phan tu %d Khong co trong cay nhi phan tim kiem.!\n",c);
				}	
				else
				{
					printf("phan tu %d co trong cay nhi phan tim kien.\n",c);
				}
	            break;
	        }
        case 5:
	        {
	            int k;
	            printf("Nhap gia tri can them: ");
	            scanf("%d",&k);
	            TKNode* P = Tm;
	            printf("\n===SAU KHI THEM===\n");
	            printf("Gia tri cua cay duyet theo Tien to: ");
				Duyet_Tiento(Them_Node_k(P,k));
				printf("\nGia tri cua cay duyet theo Trung to: ");
				Duyet_Trungto(Them_Node_k(P,k));
				printf("\nGia tri cua cay duyet theo Hau to: ");
				Duyet_Hauto(Them_Node_k(P,k));
	            break;
	        }
	    case 6:
	        {
	            int h;
	            printf("Nhap gia tri can xoa: ");
	            scanf("%d",&h);
	            TKNode* P = Tm;
	            printf("\n===SAU KHI XOA===\n");
	            printf("Gia tri cua cay duyet theo Tien to: ");
				Duyet_Tiento(Xoa_NPTK(P,h));
				printf("\nGia tri cua cay duyet theo Trung to: ");
				Duyet_Trungto(Xoa_NPTK(P,h));
				printf("\nGia tri cua cay duyet theo Hau to: ");
				Duyet_Hauto(Xoa_NPTK(P,h));
	            break;
	        }
        case 7: break;
    }
    }while (chon !=7);
	return 0;
}


