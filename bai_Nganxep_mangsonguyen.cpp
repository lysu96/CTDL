#include <stdlib.h>
#include <stdio.h>
 
#define Max 100 
typedef int item; 
struct Stack
{
    int Top; 
    item Data[Max];
};
 
void Init (Stack &S); 
int Isempty(Stack S); 
int Isfull(Stack S); 
void Push(Stack &S, item x); 
//int Top_Data(Stack S); 
int Pop(Stack &S, item &x); 
void Pop_K(Stack &S);
void Input (Stack &S); 
void Output(Stack S); 
 
void Init (Stack &S)
{
    S.Top = 0;
}
 
int Isempty(Stack S)
{
    return (S.Top == 0);
}
 
int Isfull(Stack S)
{
    return (S.Top == Max);
}
 
void Push(Stack &S, item x)
{
    if (!Isfull(S))
    {
        S.Data[S.Top] = x;
        S.Top ++;
    }
}
 
//int Top_Data(Stack S) //Lay phan tu o dau ngan xep nhung khong xoa
//{
//    return S.Data[S.Top-1];
//}

 // xoa 
int Pop(Stack &S, item &x)
{
    if (!Isempty(S))
    {
    	x = S.Data[S.Top];
        S.Top --;
        return x;
    }
}
// xoa vi tri k
void Pop_K(Stack &S){
	Stack ms;
	Init(ms);
	int i,k;
	item x;
	printf("\t\nNhap vi tri can xoa: ");
	scanf("%d",&k);
	for(i = S.Top;i>k;i--)
	{
		Pop(S,x);
		Push(ms,x);	
	}
	Pop(S,x);
	Push(ms,x);
	for(i=ms.Top;i>0;i--){
		Pop(ms,x);
		Push(S,x);
	}
	printf("Ngan xep sau khi sao khoi vi tri k\n");
	Output(S);
}

// Them vao vi tri k
void Push_K(Stack &S){
	Stack ms;
	Init(ms);
	int i,k,gt;
	item x;
	printf("\t\nNhap gia tri can Them: ");
	scanf("%d",&gt);
	printf("\t\nNhap vi tri can Them: ");
	scanf("%d",&k);
	for(i = S.Top;i>=k;i--)
	{
		Pop(S,x);
		Push(ms,x);
	}
	Push(S,gt);
	for(i=ms.Top;i>0;i--){
		Pop(ms,x);
		Push(S,x);
	}
	printf("Ngan xep sau khi sao khoi vi tri k\n");
	Output(S);
}

void Input (Stack &S)
{
    int n;
    item x;
    do
    {
        printf("Nhap so phan tu cua Ngan xep (<%d) :",Max);
        scanf("%d",&n);
    } while (n>Max || n<1);
    for (int i=0; i<n; i++)
    {
        printf("Nhap phan tu thu %d : ", i+1);
        scanf("%d",&x);
        Push(S,x);
    }
}
 
void Output(Stack S)
{
    for (int i=S.Top-1; i>=0; i--)
        printf("%d\n",S.Data[i]);
}
 
int main()
{
    Stack S;
    Init(S);
    Input(S);
    printf("\n");
    Output(S);
 
    int lua_chon;
    printf("Moi ban chon phep toan voi DS LKD:");
    printf("\n1: Them phan tu vao ngan xep");
    printf("\n2: Xoa phan tu trong ngan xep");
    printf("\n3: Them phan tu vao vi tri k trong ngan xep");
    printf("\n4: Xoa phan tu vao vi tri k trong ngan xep");
    printf("\n5: Thoat");
    do
    {
        printf("\nBan chon: ");
        scanf("%d",&lua_chon);
        switch (lua_chon)
        {
            case 1:
            {
                item x;
                printf ("Nhap phan tu can them vao Ngan xep: ");
                scanf("%d",&x);
                Push(S,x);
                printf ("Ngan xep sau khi Them\n\n");
                Output(S);
                break;
            }
            case 2:
            {
            	item x;
                Pop(S,x);
                printf ("Ngan xep sau khi xoa\n\n");
                Output(S);
                break;
            }
            case 3:
            {
                Push_K(S);
                break;
            }
            case 4:
            {
                Pop_K(S);
                break;
            }
            case 5: break;
        }
    }while (lua_chon !=5);
    return 0;
}
