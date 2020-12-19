#include <stdio.h>
#include <math.h>
#include <string.h>

struct SinhVien{
	char Hoten[30], Lop[15], SBD[5];
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
	printf("Nhap SBD: ");
	fflush(stdin);
	gets(sv.SBD);
	printf("Nhap DTB: ");
	scanf("%f",&sv.DTB);
}
void xuat_sv(SINHVIEN sv){
	printf("\n\t\t\t Ho va ten: %s", sv.Hoten);
	printf("\n\t\t\t Lop: %s", sv.Lop);
	printf("\n\t\t\t SBD: %s", sv.SBD);
	printf("\n\t\t\t DTB: %0.2f", sv.DTB);
}
// nhieu sv
void nhaps_sv(SINHVIEN mangsv[], int n){
	for(int i=0;i<n;i++){
		printf("\nNhap sinh vien thu %d",i+1);
		nhap_sv(mangsv[i]);
	}
}
void xuats_sv(SINHVIEN mangsv[], int n){
	for(int i=0;i<n;i++){
		printf("\n\n\t\t -----Thong tin sinh vien vua nhap thu %d-----",i+1);
		xuat_sv(mangsv[i]);
	}
}
// tim kiem sv theo DTB
void timkiem_sv(SINHVIEN mangsv[], int n){
	float diem;
	int svt = 1, sai;
	printf("\n Nhap DTB can tim: ");
	scanf("%f", &diem);
	for(int i=0;i<n;i++){
		if(mangsv[i].DTB == diem){
			printf("\n\n\t\t -----Sinh vien co (DTB = %0.2f)thu %d la-----",diem,svt++);
			xuat_sv(mangsv[i]);	
		}
	}
}
// hoan vi doi cho
void hoanvi_sv(SINHVIEN &sv1, SINHVIEN &sv2 ){
	SINHVIEN temp;
	temp = sv1;
	sv1 = sv2;
	sv2 = temp;
}
// sap xep sinh vien theo DTB giam dan neu tang dan thi: mangsv[i].DTB >= mangsv[j].DTB
void sapxep_sv(SINHVIEN mangsv[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(mangsv[i].DTB <= mangsv[j].DTB){
				hoanvi_sv(mangsv[i],mangsv[j]);
			}
		}
	}
}
// xep loai sinh vien
void xetloai_sv(SINHVIEN mangsv[], int n){
	int svt = 1;
	for(int i=0;i<n;i++){
		if(mangsv[i].DTB >= 8.00){
			printf("\n\n\t\t -----Danh sach sinh vien xep loai gioi-----");
			xuat_sv(mangsv[i]);	
		}
		else if(mangsv[i].DTB >= 6.50){
			printf("\n\n\t\t -----Danh sach sinh vien xep loai kha-----");
			xuat_sv(mangsv[i]);	
		}
		else if(mangsv[i].DTB >= 5.00){
			printf("\n\n\t\t -----Danh sach sinh vien xep loai TB-----");
			xuat_sv(mangsv[i]);
		}
		else{
			printf("\n\n\t\t -----Danh sach sinh vien xep loai yeu-----");
			xuat_sv(mangsv[i]);
		}
	}
}
// them sinh moi sinh vien
void them_sv(SINHVIEN mangsv[], SINHVIEN them, int &n, int vitrithem){
	for(int i=n-1;i>=vitrithem;i--){
		if(vitrithem<0){
			vitrithem = 0;	
		} else if(vitrithem>n){
			vitrithem = n;
		}else{
			mangsv[i+1] = mangsv[i];
		}
	}
	mangsv[vitrithem] = them;
	n++;
}
// xoa sinh vien
void xoa_sv(SINHVIEN mangsv[], int &n, int vitricanxoa){
	for(int i=vitricanxoa+1;i<n;i++){
		mangsv[i-1] = mangsv[i];
	}
	n--;
}

int main(){
	SINHVIEN mangsv[100];
	int n;
	do{
		printf("Nhap so luong sinh vien: ");
		scanf("%d", &n);
	}while(n>100);
	
	nhaps_sv(mangsv,n);
	xuats_sv(mangsv,n);
	timkiem_sv(mangsv,n);
	
	printf("\nDanh sach xem loai sinh vien ");
	xetloai_sv(mangsv,n);

	SINHVIEN them;
	int vitrithem;
	printf("\n Nhap vi tri can them: ");
	scanf("%d", &vitrithem);
	nhap_sv(them);
	them_sv(mangsv,them,n,vitrithem);
	printf("\nDanh sach sinh vien sau khi them ");
	xuats_sv(mangsv,n);
	
	printf("\nDanh sach sinh vien sao khi sap xep ");
	sapxep_sv(mangsv,n);
	xetloai_sv(mangsv,n);
	
	int vitricanxoa;
	printf("\n Nhap vi tri can xoa: ");
	scanf("%d", &vitricanxoa);
	xoa_sv(mangsv,n,vitricanxoa);
	printf("\nDanh sach sinh vien sau khi xoa ");
	xuats_sv(mangsv,n);
	return 0;
}

