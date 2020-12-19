#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef int item;

struct Queue{
    int Front, Rear;
    item Data[N];
    int count;
};
 
void Init (Queue &Q); //khoi tao Queue rong
int Isempty(Queue Q); //kiem tra Queue rong
int Isfull(Queue Q); //kiem tra Queue day
void them(Queue &Q, item x); //them phan tu vao cuoi hang doi
int xoa(Queue &Q); //Loai bo phan tu khoi dau hang doi
//int Qfront (Queue Q); //xem thong tin phan tu dau hang doi 
//void Them_Circular(Queue &Q, item x); //them phan tu vao cuoi hang doi vong
//int Xoa_Circular(Queue &Q); //Loai bo phan tu khoi dau hang doi vong
void Nhap(Queue &Q); //Nhap 
void Xuat(Queue Q); //Xuat 

 // khoi tao hang doi rong
void Init(Queue &Q){
    Q.Front = 0;
    Q.Rear = -1;
    Q.count = 0;
}

//kiem tra hang doi rong
int Isempty(Queue Q){
    if (Q.count == 0)
        return 1;
    return 0;
}

//kiem tra hang doi day
int Isfull(Queue Q){
    if (Q.count == N)
        return 1;
    return 0;
}

//nhap hang doi
void Nhap(Queue &Q)
{
    int n;
    item x;
    do
    {
        printf("Nhap so phan tu cua hang doi (<%d) :",N);
        scanf("%d",&n);
    } while (n>N || n<1);
    for (int i=0; i<n; i++)
    {
        printf("Nhap phan tu thu %d : ", i+1);
        scanf("%d",&x);
        them(Q,x);
    }
}

// xuat hang doi
void Xuat(Queue Q)
{
    if (Isempty(Q)) printf("Hang doi rong !");
    else
    {
        for (int i=Q.Front; i<=Q.Rear; i++)
        //for (int i=Q.Front, j=0; j<Q.count; j++, i = (i++) % N) //hang vong
            printf("%d   ",Q.Data[i]);
        printf("\n");
    }
}

//them phan tu vao cuoi hang doi
void them(Queue &Q, item x){
    if (Isfull(Q)) printf("Hang doi day !");
    else
    { 
        Q.Data[++Q.Rear] = x;
        Q.count++;
    }
}

//xoa phan tu khoi dau hang doi
int xoa(Queue &Q){
    if (Isempty(Q)) printf("Hang doi rong !");
    else
    {
        item x = Q.Data[Q.Front];
        for (int i=Q.Front; i<Q.Rear; i++) //di chuyen cac phan tu ve dau hang
            Q.Data[i] = Q.Data[i+1];
        Q.Rear--; // giam vi tri phan tu cuoi xuong
        Q.count--;//giam so phan tu xuong
        return x; //tra ve phan tu lay ra
    }
}

int main(){

	Queue Q;
    Init(Q);
    Nhap(Q);
	
	int chon;
    printf("\n\t\t Moi ban chon :");
    printf("\n1: Them 1 phan tu vao cuoi hang");
    printf("\n2: Xoa 1 phan tu ra khoi dau hang ");
  //  printf("\n3: them phan tu o vi tri K bat ky");
  //  printf("\n4: xoa phan tu o vi tri K bat ky");
  // printf("\n5: Thoat");
    
    do
    {
        printf("\nBan chon: ");
        scanf("%d",&chon);
    switch (chon)
    {
        case 1:
       	{
       		item x;
            printf ("Nhap phan tu can chen vao hang doi: ");
            scanf("%d",&x);
            them(Q,x);
            printf ("Sao khi them la: ");
        	Xuat(Q);
            break;
		}
        case 2:
        {
        	xoa(Q);
        	printf ("Sao khi xoa: ");
        	Xuat(Q);
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {	
            break;
        }
        case 5: break;
    }
    }while (chon !=5);
	return 0;
 }
