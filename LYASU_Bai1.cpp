//+++++++++++++++++++++++++++//
//        LY A Sú		   	/+/
//++++++++++++++++++++++++++//

#include <stdio.h>
#include <stdlib.h>

#define N 100
// khai bao danh sach
typedef int Item;
struct List{
	Item mangSN[N];
	int khichthuoc;
	
};

// khoi tao
void Tao_List(List &L);
int Isempty(List L);
int Isfull(List L);
int Them_k(List &L, int k);
void Xoa_k(List &L, int k);
void Xoa_x(List &L, Item x, int v);
int Tim_k(List L, Item x);

// tao danh sach rong
void Tao_List(List &L){
	L.khichthuoc = 0; // danh sach rong
}
// kiem tra rong
int Isempty (List L)
{
    return (L.khichthuoc==NULL);
}
// kiem tra day
int Isfull(List L){
	return (L.khichthuoc==N);
}
// nhap mang
void nhapMang(List &L){
	printf("Nhap so luong phan tu danh sach: ");
	scanf("%d", &L.khichthuoc);	
	for(int i = 0;i<L.khichthuoc;i++){
		printf("nhap phan tu thu %d: ", i+1);
		scanf("%d", &L.mangSN[i]);
	}
}
// xuat mang
void xuatMang(List L){
	for(int i=0;i<L.khichthuoc;i++){
		printf("%d ", L.mangSN[i]);
	}
}
// them
int Them_k(List &L, Item x, int k) //chen x vao vi tri k trong danh sach
{ 
    int i=0;
    
    if(Isfull(L)){
    	printf("Danh sach day khong the them !");
		return 0;
	} else{
    	if(k<0||k>L.khichthuoc){
    		printf("\nVi tri them khong hop le.!");
			return 0;	
		} else{
    		for (i = L.khichthuoc;i>=k;i--){
    			L.mangSN[i] = L.mangSN[i-1];
			}
			L.mangSN[k-1] = x;
			++L.khichthuoc;
		}
	}
    		
}

// tim vi tri
int Tim(List L, Item x){
	for(int i=0;i<L.khichthuoc;i++){
		if(L.mangSN[i] == x){
			return i+1;
		}
	}
	return 0;
}

// xoa phan tu x
int Xoa_x(List &L, Item x){
	if(L.khichthuoc==0){
		printf("danh sach rong.");
		return 0;
	}
    printf ("Nhap phan tu can xoa: ");
	scanf ("%d",&x);
    int v = Tim(L,x);
//	printf("\n\t v = %d", v);
    if(!v){
   		printf("\n Khong tim thay %d", v);
   		return 0;
	}
	do{
		for(int i=v-1;i<L.khichthuoc-1;i++){
			L.mangSN[i] = L.mangSN[i+1];
		}
		--L.khichthuoc;
		v=Tim(L,x);
	}while(v);
	return 1;
	
}

// dem so phan tu chan le am duong
// so chan
void dem_ptsc(List L, Item x){
	int sc=0;
	for(int i = 0;i<L.khichthuoc;i++){
		if(L.mangSN[i]%2==0 && L.mangSN[i]>=1){
			sc++;
		}
	}
	if(sc>0){
		printf("\n\t co %d so chan ",sc);
	} else{
		printf("\n\t Danh sach khong co so chan .!");
	}
}

// so le
void dem_ptsl(List L, Item x){
	int sl=0;
	for(int i = 0;i<L.khichthuoc;i++){
		if(L.mangSN[i]%2!=0 && L.mangSN[i]>=1){
			sl++;
		}
	}
	if(sl>0){
		printf("\n\t co %d so le ",sl);
	} else{
		printf("\n\t Danh sach khong co so le .!");
	}

}

// so duong
void dem_ptsd(List L, Item x){
	int sd=0;
	for(int i = 0;i<L.khichthuoc;i++){
		if(L.mangSN[i]>=1){
			sd++;
		}
	}
	if(sd>0){
		printf("\n\t co %d so duong ",sd);
	} else{
		printf("\n\t Danh sach khong co so duong nao.!");
	}

}

// so am
void dem_ptsa(List L, Item x){
	int sa=0;
	for(int i = 0;i<L.khichthuoc;i++){
		if(L.mangSN[i]<=-1){
			sa++;
		}
	}
	if(sa>0){
		printf("\n\t co %d so am ",sa);
	} else{
		printf("\n\t Danh sach khong co so am nao .!");
	}

}

// tinh trung binh cong cua cac phan tu trong mang
float TBCmang(List L){
	int TBCmang=0;
	for(int i=0;i<L.khichthuoc;i++){
		TBCmang += L.mangSN[i];	
	}
	return (float)TBCmang/L.khichthuoc;
}

// tinh trung binh cong so duong
float TBCsoduong(List L){
	int dem=0,TBCsoduong=0;
	for(int i=0;i<L.khichthuoc;i++){
		if(L.mangSN[i]>=1){
			dem++;
			TBCsoduong += L.mangSN[i];
		}	
	}
	return (float)TBCsoduong/dem++;
}
// tinh trung binh cong so am
float TBCsoam(List L){
	int dem=0,TBCsoam=0;
	for(int i=0;i<L.khichthuoc;i++){
		if(L.mangSN[i]<=-1){
			dem++;
			TBCsoam += L.mangSN[i];
		}	
	}
	return (float)TBCsoam/dem++;
}
// tinh trung binh cong so chan
float TBCsochan(List L){
	int dem=0,TBCsochan=0;
	for(int i=0;i<L.khichthuoc;i++){
		if(L.mangSN[i]%2==0 && L.mangSN[i]>=1){
			dem++;
			TBCsochan += L.mangSN[i];
		}	
	}
	return (float)TBCsochan/dem++;
}
// tinh trung binh cong so le
float TBCsole(List L){
	int dem=0,TBCsole=0;
	for(int i=0;i<L.khichthuoc;i++){
		if(L.mangSN[i]%2!=0 && L.mangSN[i]>=1){
			dem++;
			TBCsole += L.mangSN[i];
		}	
	}
	return (float)TBCsole/dem++;
}
int main(){
	List l;
	Tao_List(l);

	nhapMang(l);
	printf("\n\t Mang danh sach vua nhap la: ");
	xuatMang(l);
	
	int chon;
    printf("\n\t\t Moi ban chon :");
    printf("\n1: Hien thi danh sach");
    printf("\n2: Them phan tu x vao danh sach");
    printf("\n3: Xoa phan tu x trong danh sach");
    printf("\n4: Tim kiem 1 phan tu trong danh sach");
    printf("\n5: Den so phan tu chan le am duong");
    printf("\n6: Tinh trung binh cong cua mang");
    printf("\n7: Tinh trung binh cong cua cac so chan,le,am,duong");
    printf("\n8: Thoat");
    
    do
    {
        printf("\nBan chon: ");
        scanf("%d",&chon);
    switch (chon)
    {
        case 1:
        	{
        		printf ("\t\t");
            	xuatMang(l);
            	break;
        	}
        case 2:
        	{
        		Item x;
            	int k;
            	printf ("Nhap phan tu can them vao danh sach: ");
            	scanf("%d",&x);
            	printf ("Nhap vi tri can them: ");
            	scanf ("%d",&k);
            	Them_k(l,x,k);
            	printf ("\n\t\tDanh sach sau khi them: ");
            	xuatMang(l);
            break;
			}
        case 3:
        {
        	Item x;
        	Xoa_x(l,x);
            printf ("\n\t Danh sach sau khi xoa: ");
            xuatMang(l);
            break;
        }
        case 4:
        {
            Item x;
            printf ("Moi ban nhap vao phan tu can tim: ");
            scanf("%d",&x);
            int k=Tim(l,x);
            if (k) printf ("Tim thay %d trong danh sach tai vi tri thu: %d",x,k);
            else printf ("Khong tim thay %d trong danh sach !",x);
            break;
        }
        case 5:
        {
        	Item x;
        	dem_ptsc(l,x);
			dem_ptsl(l,x);
			dem_ptsd(l,x);
			dem_ptsa(l,x);
            break;
        }
		case 6:
		{
			
			printf ("\tTrung binh cong cua mang la: %0.2f",TBCmang(l));
			break;
		}
		case 7:
		{
			printf ("\tTrung binh cong cua so chan la: %0.2f\n",TBCsochan(l));
			printf ("\tTrung binh cong cua so le la: %0.2f\n",TBCsole(l));
			printf ("\tTrung binh cong cua so duong la: %0.2f\n",TBCsoduong(l));
			printf ("\tTrung binh cong cua so am la: %0.2f",TBCsoam(l));
			break;
		}
        case 8: break;
    }
    }while (chon !=8);
	return 0;
}
