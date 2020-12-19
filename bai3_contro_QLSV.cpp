#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char Ho_Ten[30], Lop[20], Gioi_Tinh[5];
	float DTK;
}SinhVien;

struct List{
	SinhVien sv[100];
	int size;
}L;

void Input(){
	do{
		printf("Nhap so luong sinh vien: ");
		scanf("%d",&L.size);
	}while(L.size<0 || L.size>100);
	
	for(int i=0;i<L.size;i++){
		printf("\n\t\tNhap sinh vien thu %d\n",i+1);
		printf("Nhap ho va ten: ");
		fflush(stdin);
		gets(L.sv[i].Ho_Ten);
		printf("Nhap lop: ");
		fflush(stdin);
		gets(L.sv[i].Lop);
		printf("Nhap gioi tinh: ");
		fflush(stdin);
		gets(L.sv[i].Gioi_Tinh);
		printf("Nhap diem Tong ket: ");
		scanf("%f",&L.sv[i].DTK);
	}
}
void Output(){
	printf("\n\t\t---DANH SACH SINH VIEN LA---\n");
	printf("%-30s%-15s%-15s%-5s\n","Ho va ten","Lop","Gioi tinh","DTK");
	for(int i=0;i<L.size;i++){
		printf("%-30s%-15s%-15s%-5.2f\n",L.sv[i].Ho_Ten,L.sv[i].Lop,L.sv[i].Gioi_Tinh,L.sv[i].DTK);
	}
}
int Insert_SV_k(SinhVien x, int k){
	
	if(k>0 && k<=L.size){
		for(int i=L.size;i>=k;i--){
			L.sv[i] = L.sv[i-1];
		}
		L.size++;
		L.sv[k-1]=x;
		return 1;
	}
	printf("Khong them duoc...!\n");
	return -1;
}

int Delete_SV_k(int k){
	if(k>0 && k<=L.size){
		for(int i=k;i<=L.size;i++){
			L.sv[i-1] = L.sv[i];
		}
		L.size--;
		return 1;
	}
	printf("Xoa khong thanh cong..!");
	return -1;
}

int DTK_lonhon_5(){
	int d=0;
	for(int i=0;i<L.size;i++){
		if(L.sv[i].DTK>5) d=d+1;
	}
	if(d>0){
		printf("So sinh vien co (DTK>5) la: %d",d);
	} else{
		printf("Khong co sinh vien nao co (DTK>5).");
	}
}

int main(){
	SinhVien x;
	Input();
	
	int lua_chon;
	printf("\n\t\t--MOI BAN CHON CAC PHEP TOAN DUOI DAY---");
	printf("\n1: Hien thi danh sach sinh vien vua nhap");
	printf("\n2: Them mot sinh vien vao vi tri K trong danh sach");
	printf("\n3: Xoa mot sinh vien khoi vi tri k trong danh sach");
	printf("\n4: Den so sinh vien co (DTK>5)");
	printf("\n5: Thoat");
	do{
		printf("\n Moi ban chon: ");
		scanf("%d",&lua_chon);
		
		switch(lua_chon){
			case 1:{
				Output();
				break;
			}
			case 2:{
				int k;
				printf(" Nhap vi tri can them: ");
				scanf("%d",&k);
				printf("\nNhap ho va ten: ");
				fflush(stdin);
				gets(x.Ho_Ten);
				printf("Nhap lop: ");
				fflush(stdin);
				gets(x.Lop);
				printf("Nhap gioi tinh: ");
				fflush(stdin);
				gets(x.Gioi_Tinh);
				printf("Nhap diem Tong ket: ");
				scanf("%f",&x.DTK);
				Insert_SV_k(x,k);
				Output();
				break;
			}
			case 3:{
				int k;
				printf(" Nhap vi tri can xao: ");
				scanf("%d",&k);
				Delete_SV_k(k);
				Output();
				break;
			}
			case 4:{
				DTK_lonhon_5();
				break;
			}
			case 5: break;
		}
	}while(lua_chon!=5);
	return 0;
}
