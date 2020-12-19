#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100

// nhap 1 ptu
void nhappt(int &n){
	scanf("%d", &n);
}
void xuatpt(int n){
	printf("%d ", n);
}
// nhap mang
void nhapMang(int mang[], int &n){
	for(int i=0; i<n;i++){
		printf(" Nhap phan tu %d: ",i+1);
		nhappt(mang[i]);
	}
}
// xuat mang
void xuatMang(int mang[], int &n){
	for(int i=0; i<n;i++){
		xuatpt(mang[i]);
	}
}

// them pt
void thempt(int mang[], int &n, int x, int k){
	int i=0;

	if(n>=N){
		printf("\n danh sach day..! khong the them ");
	}else{	
		if(x<0){
			x=0;
		}else if(x>n){
			x=n;
		}
	
		for(i=n;i>x;i--){
			mang[i]=mang[i-1];
		}
		mang[x]=k;
		++n;
	}
}
// xoa
void xoa_k(int mang[], int &n, int x){
	for(int i=x-1;i<n-1;i++){
		mang[i]=mang[i+1];		
	}
	--n;
}

// sapxep
//--hoan vi--
void hoanvi(int &A, int &B){
	int temp;
	A=temp;
	B = A;
	temp = B;	
}
void sap_xep(int mang[], int n){
	int temp;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(mang[i]>=mang[j]){
				temp = mang[i];
                mang[i] = mang[j];
                mang[j] = temp;
			}
		}
	}
}

// gop mang
void gop_mang(int mangA[], int &n, int mangB[], int b, int mangC[], int c)
{
 n=b+c; 
 for(int i=0;i<n;i++)
  {
   if(i<n) 
     mangA[i]=mangB[i];
   else{
   	mangA[i]=mangC[i-n];
   }
  }
  xuatMang(mangA,n);
}

// tach mang: am, chan, le
void tach_mang(int mang[],int mangA[],int mangB[],int mangC[], int n){

	int h=0, l=0, j=0;
	for(int i=0;i<n;i++){
		if(mang[i]<0){

			mangA[h] = mang[i];
			h++;
		}else if(mang[i]%2==0){
			
			mangB[l] = mang[i];
			l++;
		}
		else{
			mangC[j] = mang[i];
			j++;	
		}
	}
	printf("\n\tmang so am: ");
	xuatMang(mangA,h);
	printf("\n\tmang so chan: ");
	xuatMang(mangB,l);
	printf("\n\tmang so le: ");
	xuatMang(mangC,j);
	
	// gop mang
	printf("\n\tmang sau khi gop la: ");
	gop_mang(mangA,h,mangB,l,mangC,j);
}



//tim kiem vi tri
void tim_kiem(int mang[], int n){
	int x, i=0;
	printf("\nnhap vi tri can tim: ");
	scanf("%d", &x);
	for(i=x-1;i<n;i++){
		mang[i+1]=mang[i];
		
	}
	printf("\n\tgia tri tai vi tri %d la: ",x);
	xuatpt(mang[i]);
}

int main(){
	int n;
	int mang[N], mang1[N], mang2[N], mang3[N];
	do{
		printf(" Nhap so luong phan tu: ");
		scanf("%d", &n);
	}while(n>N || n<=0);
	printf("\n");
	// nhap xuat
	nhapMang(mang,n);
	printf("\n\tmang vua nhap la: ");
	xuatMang(mang,n);

	// them
	int x, k;
	printf("\n NHap vi tri can them: ");
	scanf("%d", &x);
	printf(" Nhap gia tri can them: ");
	scanf("%d", &k);
	thempt(mang,n,x,k);
	printf("\n\tmang sao khi them la: ");
	xuatMang(mang,n);
	
	// xoa
	printf("\n Nhap vi tri muon xoa: ");
	scanf("%d", &x);
	xoa_k(mang,n,x);
	printf("\n\tmang sao khi xoa la: ");
	xuatMang(mang,n);
		
	// sap xep
	printf("\n\tmang sao khi sap xep la: ");
	sap_xep(mang,n);	
	xuatMang(mang,n);
	
	// tach mang am, chan, le
	printf("\n\nmang sao khi tach la: ");
	tach_mang(mang,mang1,mang2,mang3,n);
	
	// gop mang
	
	// tim pt tai vi tri
	tim_kiem(mang,n);

	return 0;
}
