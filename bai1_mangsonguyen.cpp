//##########################//
//        LY A Sú		   	//
//#########################//

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

// xoa vi tri
void Xoa_k(List &L, int k){
	if(L.khichthuoc==0){
		printf("danh sach rong.");
	}
	else{
		for(int i=k-1;i<L.khichthuoc-1;i++){
			L.mangSN[i] = L.mangSN[i+1];
		}
		--L.khichthuoc;
	}
}

//// tim k
//int Tim_k(List L, Item x){
//	for(int i=0;i<L.khichthuoc;i++){
//		if(L.mangSN[i] == x){
//			return L.mangSN[i];
//		}
//	}
//}

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


int main(){
	List l;
	Tao_List(l);

	nhapMang(l);
	printf("\n\t Mang danh sach vua nhap la: ");
	xuatMang(l);
	
	int chon;
    printf("\n\t\t Moi ban chon :");
    printf("\n1: Kiem tra DS rong");
    printf("\n2: Them phan tu x vao danh sach");
    printf("\n3: xoa phan tu tai vi tri x trong danh sach");
    printf("\n4: Xoa phan tu x trong danh sach");
    printf("\n5: Tim kiem 1 phan tu trong danh sach");
    printf("\n6: Den so phan tu chan le am duong");
    printf("\n7: Thoat");
    
    do
    {
        printf("\nBan chon: ");
        scanf("%d",&chon);
    switch (chon)
    {
        case 1:
        	{
            	if (Isempty(l)) printf("Danh sach rong !");
            	else printf ("Danh sach khong rong !");
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
            	printf ("\n\t\t\tDanh sach sau khi them: ");
            	xuatMang(l);
            break;
			}
		case 3:
        	{
        		int k;
            	printf ("Nhap phan vi tri can xoa: ");
            	scanf ("%d",&k);
            	if(k<1||k>l.khichthuoc){
            		printf("\nVi tri xoa khong hop le.!");
				}else{
					Xoa_k(l,k);
		            printf ("\n\t Danh sach sau khi xoa: ");
		            xuatMang(l);
				}
            	int t = Tim(l,k);
            	printf("vitrixoa: ",t);
					
            break;
			}
        case 4:
        {
        	Item x;
        	Xoa_x(l,x);
            printf ("\n\t Danh sach sau khi xoa: ");
            xuatMang(l);
            break;
        }
        case 5:
        {
            Item x;
            printf ("Moi ban nhap vao phan tu can tim: ");
            scanf("%d",&x);
            int k=Tim(l,x);
            if (k) printf ("Tim thay %d trong danh sach tai vi tri thu: %d",x,k);
            else printf ("Khong tim thay %d trong danh sach !",x);
            break;
        }
        case 6:
        {
        	Item x;
        	dem_ptsc(l,x);
			dem_ptsl(l,x);
			dem_ptsd(l,x);
			dem_ptsa(l,x);
            break;
        }
        case 7: break;
    }
    }while (chon !=7);
	return 0;
}
