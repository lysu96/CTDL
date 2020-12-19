// cay nhi phan
//##########################//
//        LY A Sú		   	//
//#########################//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct NpNode{
	int Data;
	NpNode* Left;
	NpNode* Right;
};
typedef NpNode *Nhiphan;

void Khoitao_NP(Nhiphan &np){
	np == NULL;
}

NpNode* Tao_Node(NpNode*p,int x){
	p = (NpNode*)malloc(sizeof(NpNode));
	p->Data = x;
	p->Left = p->Right = NULL;
	return p;
}

// nhap 
NpNode *Nhap_NP(NpNode*p, int x){
	printf("Node = ");
	scanf("%d",&x);
	if(x==0)
		return NULL;
	p = Tao_Node(p,x);
	printf("\tNhap Con trai node %d\n",x);
	p->Left = Nhap_NP(p,x);
	printf("\tNhap Con phai node %d\n",x);
	p->Right = Nhap_NP(p,x);
	
	return p;
}
// duyet truoc
void Duyet_Truoc(Nhiphan np){
	NpNode *D = np;
	if(D != NULL){
		printf("%d ",D->Data);
		Duyet_Truoc(D->Left);
		Duyet_Truoc(D->Right);
	}
}
// duyet giua
void Duyet_Giua(Nhiphan np){
	NpNode *D = np;
	if(D != NULL){
		Duyet_Giua(D->Left);
		printf("%d ",D->Data);
		Duyet_Giua(D->Right);
	}
}
// duyet cuoi
void Duyet_Cuoi(Nhiphan np){
	NpNode *D = np;
	if(D != NULL){
		Duyet_Cuoi(D->Left);
		Duyet_Cuoi(D->Right);
		printf("%d ",D->Data);
	}
}

int main(){
	NpNode *N;
	Khoitao_NP(N);
	
	int x;
	Nhiphan n;
	n = Nhap_NP(N,x);
	
	printf("\nGia tri cua cay duyet theo truoc: ");
	Duyet_Truoc(n);
	printf("\nGia tri cua cay duyet theo Giua: ");
	Duyet_Giua(n);
	printf("\nGia tri cua cay duyet theo cuoi: ");
	Duyet_Cuoi(n);
	return 0;
}
