

#include <stdlib.h>
#include <stdio.h>
 
typedef int item; //kieu du lieu
struct Node
{
    item Data;
    Node * Next;
};
struct Queue
{
    Node * Front, *Rear; //Node dau va Node cuoi
    int count;
};
 
void Init (Queue &Q); //khoi tao hang doi rong
int Isempty(Queue Q); //kiem tra hang doi rong
void Them(Queue &Q, item x); //them phan tu vao cuoi hang doi
int Xoa(Queue &Q, item &x); //Loai bo phan tu khoi dau hang doi
void Them_k(Queue &Q,item x);// them vao vi tri k bat ky
int Xoa_k(Queue &Q,item x);// xoa vi tri k bat ky
int Qfront (Queue Q); //xem thong tin phan tu dau hang doi 
Node *MakeNode(item x); //tao 1 Node
void Nhap(Queue &Q); //Nhap 
void Xuat(Queue Q); //Xuat 
 
void Init(Queue &Q)
{
    Q.Front = Q.Rear = NULL;
    Q.count = 0;
}

//kiem tra hang doi rong
int Isempty (Queue Q)
{
    if (Q.count == 0) //so phan tu = 0 => rong
        return 1;
    return 0;
}

//tao 1 Node
Node *MakeNode(item x)
{
    Node *P = (Node*) malloc(sizeof(Node));
    P->Next = NULL;
    P->Data = x;
    return P;
}

//them phan tu vao cuoi hang doi
void Them(Queue &Q, item x)
{
    Node *P = MakeNode(x); //Neu Q rong
    if (Isempty(Q))
    {
        Q.Front = Q.Rear = P; //dau va cuoi deu tro den P
    }
    else //Khong rong
    { 
        Q.Rear->Next = P;
        Q.Rear = P;
    }
    Q.count ++ ; //tang so phan tu len
}

//xoa phan tu khoi dau hang doi
int Xoa(Queue &Q, item &x)
{
    if (Isempty(Q)) 
    {
        printf("Hang doi rong !");
        return 0;
    }
    else
    {
        item x = Q.Front->Data;
        if (Q.count == 1) //neu co 1 phan tu
            Init(Q);
        else
            Q.Front = Q.Front->Next;
        Q.count --;
        return x; //tra ve phan tu lay ra
    }
}

// them vao vi tri k bat ky
void Them_k(Queue &Q, item x){
	int k;
	printf ("Nhap vi tri can them: ");
    scanf("%d",&k);
    
    Node *P = MakeNode(x);
    Queue q ;
    Init(q);
    
    if(Isempty(Q)){
    	Q.Front = Q.Rear = P;	
	}
	else
	{
		if(k<0||k>Q.count){
			printf("\nVi tri them khong hop le.!\n");
		}
		else
		{
			for(int i=1;i<=k;i++){
				Xoa(Q,x);
				Them(q,x);
			}
			Them(Q,x);
			for(int i = 1;i<=q.count;i++){
				Them(Q,x);
				Xoa(q,x);
			}
		}
	}
	Q.count ++ ;
}

// xoa vi tri k bat ky

//nhap hang doi
void Nhap(Queue &Q)
{
    int i=0; 
    item x;
    printf ("Nhap 0 de ket thuc nhap.\n");
    do
    {
        i++;
        printf ("Nhap phan tu thu %d : ",i);
        scanf("%d",&x);
        if (x != 0) Them(Q,x);
    } while(x != 0); //nhap 0 de ket thuc
}
 
void Xuat(Queue Q)
{
    Node *P = Q.Front;
    while (P != NULL)
    {
        printf("%d   ",P->Data);
        P = P->Next;
    }
    printf("\n");
}
 
int main()
{
    Queue Q;
    Init(Q);
    Nhap(Q);
 
    int lua_chon;
    printf("\n\t\tMoi ban lua chon");
    printf("\n1: Hien thi hang doi");
    printf("\n2: Them phan tu vao hang doi");
    printf("\n3: Xoa phan tu trong hang doi");
//    printf("\n4: Them phan tu vao vi tri k bat ky");
//    printf("\n5: Xoa phan tu khoi vi tri k bat ky");
//    printf("\n6: Thoat");
    do
    {
        printf("\nBan chon: ");
        scanf("%d",&lua_chon);
        switch (lua_chon)
        {
            case 1:
            {
            	Xuat(Q);
            	break;
            }
            case 2:
            {
                item x;
                printf ("Nhap phan tu can chen vao Hang doi: ");
                scanf("%d",&x);
                Them(Q,x);
                Xuat(Q);
                break;
            }
            case 3:
            {
            	item x;
                Xoa(Q,x);
                Xuat(Q);
                break;
            }
            case 4: 
            {
            	item x;
                printf ("Nhap phan tu can chen vao Hang doi: ");
                scanf("%d",&x);
                Them_k(Q,x);
                Xuat(Q);
                break;
            }
            case 5: 
            {
            	item x;
                Xoa(Q,x);
                break;
            }
            case 6: break;
        }
    }while (lua_chon !=6);
    return 0;
}
