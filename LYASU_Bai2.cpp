#include <stdio.h>
#include <math.h>
#include <string.h>

struct SinhVien{
	char Hoten[30], Lop[15];
	float DTB;
};
typedef struct SinhVien SINHVIEN;
// 1 sv
void nhap_sv(SINHVIEN &sv){
	fflush(stdin);
//	rewind(stdin);
	printf("\nNhap ho va ten: ");
	fflush(stdin);
	gets(sv.Hoten);
	printf("Nhap lop: ");
	fflush(stdin);
	gets(sv.Lop);
	printf("Nhap DTB: ");
	scanf("%f",&sv.DTB);
}
void xuat_sv(SINHVIEN sv){
	printf("\t%-30s%-15s%-5.2f\n",sv.Hoten,sv.Lop,sv.DTB);
}
// nhieu sv
void nhaps_sv(SINHVIEN mangsv[], int n){
	for(int i=0;i<n;i++){
		printf("\nNhap sinh vien thu %d",i+1);
		nhap_sv(mangsv[i]);
	}
}
void xuats_sv(SINHVIEN mangsv[], int n){
	printf("\t%-30s%-15s%-5s\n","Ho va ten","Lop","DTB");
	for(int i=0;i<n;i++){
		xuat_sv(mangsv[i]);
	}
}

// them sinh moi sinh vien
void them_sv(SINHVIEN mangsv[], SINHVIEN them, int &n, int vitrithem){
	if(vitrithem>0 && vitrithem<=n){
		printf("\n\t\t---DANH SACH SINH VIEN SAU KHI THEM LA---\n");
		for(int i=n;i>=vitrithem;i--){
			mangsv[i] = mangsv[i-1];
		}
		mangsv[vitrithem-1] = them;
		n++;
	}else{
		printf("Khong them duoc...!\n");
	}
}

// xoa sinh vien
void xoa_sv(SINHVIEN mangsv[], int &n){
	for(int i=0;i<=n;i++){
		if(mangsv[i].DTB<5){
			mangsv[i-1] = mangsv[i];	
		}
	}
	n--;
	xuats_sv(mangsv,n);
}

// tim kiem sv theo Ten
void timkiem_sv(SINHVIEN mangsv[], int n){
	char ten[30];
	printf("\n Nhap Ten sinh vien can tim: ");
	fflush(stdin);
	gets(ten);
	printf("\n\t\t--- SINH VIEN VUA TIM LA---\n");
	for(int i=0;i<n;i++){
		if(mangsv[i].Hoten == ten){
			printf("\t%-30s%-15s%-5.2f\n",mangsv[i].Hoten,mangsv[i].Lop,mangsv[i].DTB);	
		}else{
			printf("\n\tkhong tim thay sinh vien co ten la: %s ",ten);
		}
	}
}

// den so sinh vien co DTB<5
void den_SV_DTB(SINHVIEN mangsv[], int n){
	int dem=0;
	for(int i=0;i<n;i++){
		if(mangsv[i].DTB<5){
			dem++;
		}
	}
	if(dem>0){
		printf("\t co %d so sinh co (DTB<5)\n",dem);
	} else{
		printf("\t Khong co sinh vien nao co (DTB<5) !\n");
	}
}

int main(){
	SINHVIEN mangsv[100];
	int n;
	do{
		printf("Nhap so luong sinh vien: ");
		scanf("%d", &n);
	}while(n>100);
	nhaps_sv(mangsv,n);
	//
	int lua_chon;
	printf("\n\t\t--MOI BAN CHON CAC PHEP TOAN DUOI DAY---");
	printf("\n1: Hien thi danh sach sinh vien vua nhap");
	printf("\n2: Them mot sinh vien vao vi tri K trong danh sach");
	printf("\n3: Loai bo danh sach tat ca sinh vien co (DTB<5)");
	printf("\n4: tim kiem sinh vien trong danh sach theo ten");
	printf("\n5: Den so sinh vien co (DTK<5)");
	printf("\n6: Thoat");
	do{
		printf("\n Moi ban chon: ");
		scanf("%d",&lua_chon);
		
		switch(lua_chon){
			case 1:{
				printf("\n\t\t---DANH SACH SINH VIEN LA---\n");
				xuats_sv(mangsv,n);
				break;
			}
			case 2:{
				SINHVIEN them;
				int vitrithem;
				printf("\n Nhap vi tri can them: ");
				scanf("%d", &vitrithem);
				nhap_sv(them);
				them_sv(mangsv,them,n,vitrithem);
				xuats_sv(mangsv,n);
				break;
			}
			case 3:{
				printf("\n\t\t---DANH SACH SINH VIEN SAU KHI LOAI BO SINH VIEN CO (DTB<5) LA---\n");
				xoa_sv(mangsv,n);
				break;
			}
			case 4:{
				timkiem_sv(mangsv,n);
				break;
			}
			case 5:{
				den_SV_DTB(mangsv,n);
				break;
			}
			case 6: break;
		}
	}while(lua_chon!=6);
	return 0;
}

