#include <stdio.h>
#include <stdlib.h>

#define Max 100

typedef int item;
struct Stack{
	int Top;
	item SN[Max];
};

void Init_NX(Stack &s){
	s.Top=0;
}
int Isempty_NX(Stack s){
	return (s.Top==0);
}
int Isfull_NX(Stack s){
	return (s.Top==Max);
}
// them
void Push_NX(Stack &s, item x){
	if(!Isfull_NX(s)){
		s.SN[s.Top]=x;
		s.Top++;
	}
}
// xoa
int Pop_NX(Stack &s, item &x){
	if(!Isempty_NX(s)){
		x=s.SN[s.Top];
		s.Top--;
		return x;
	}
}
// them k
//int Push_NX_k(Stack s, item x){
//	if(!Isfull_NX(s)){
//		for(int i=0;i<s.SN[Max];i++){
//			s.SN[i+1]=s.SN[i];
//		}
//		s.SN[i+1]=x;
//		s.Top++;
//	}else{
//		printf("Danh sach day khong the them");
//		return 0;
//	}
//	return s;
//}
// xoa k
//void Pop_NX_K(Stack &s){
//	Stack ms;
//	Init_NX(ms);
//	int i,k;
//	item x;
//	printf("\t\nNhap vi tri can xoa: ");
//	scanf("%d",&k);
//	for(i = s.Top;i>k;i--)
//	{
//		Pop_NX(s,x);
//		Push_NX(ms,x);
//	}
//	Pop_NX(s,x);
//	for(i=ms.Top;i>0;i--){
//		Pop_NX(ms,x);
//		Push_NX(s,x);
//	}
//	printf("Ngan xep sau khi sao khoi vi tri k:\n");
//	Output_NX(s);
//}
// nhap
void Input_NX(Stack &s){
	int n;
	item x;
	do{
		printf("Nhap so phan tu ngan xep (<%d): ",Max);
		scanf("%d",&n);
	}while(n>Max || n<1);
	for(int i = 0;i<n;i++){
		printf("Nhap phan tu thu %d: ",i+1);
		scanf("%d",&x);
		Push_NX(s,x);
	}
}
// hien
void Output_NX(Stack s){
	for(int i=s.Top-1;i>0;i--){
		printf("%d ",s.SN[i]);
		printf("\n");
	}
}
int main(){
	Stack S, ms;
//	Init_NX(S);
	Input_NX(S);
	Output_NX(S);
	
	item x;
	printf("Nhap phan tu can them: ");
	scanf("%d",&x);
	Push_NX(S,x);
	Output_NX(S);
	printf("Ngan xep sau khi xoa:\n");
	Pop_NX(S,x);
	Output_NX(S);
	//Pop_NX_K(s);
	
	return 0;
}
