#include <stdio.h>

int main(){
	int a[5]={-1,3,5,9,10};
	int b[5];
	int c[5];
	int n, j =0, h=0;
	printf("nhap n: ");
	do{
		scanf("%d ", &n);
	}while(n>5);
	
	for(int i=0;i<n;i++){
		printf("mang a %d: = %d \n",i,a[i]);	
		printf("mang b %d: = %d \n",i,b[i]);		
			
		if(a[i]>0){
			b[j]=a[i];
			j++;
		}else{
			c[h]=a[i];
			h++;
		}
		printf("\n");
		printf("mang b %d: = %d \n",i,b[i]);
		printf("mang c %d: = %d \n",i,c[i]);
		
	}
	
	return 0;
}
