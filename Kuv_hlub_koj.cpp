#include <stdio.h>
#include <stdlib.h>

void Hlub(){
	int mid=20,y1=5,y2=35,t1=-1,t2=1;
	int y3=12,y4=28;
	////
	for(int i=1;i<=y1;i++)printf(" ");printf("v");
	for(int i=y1+1;i<=y3-2;i++)printf("v");
	for(int i=y3+2;i<=y4+2;i++)printf(" ");printf("v");
	for(int i=y4;i<=y2-3;i++)printf("v");printf("\n");
	////
	while(1){
		for(int i=1;i<=y1-1;i++)printf(" ");printf("v");
		if(y3>y4){
			for(int i=y1+1;i<=y2-1;i++)printf(" ");printf("v");	
		}else{
			if(y1<y3){
				for(int i=y1+1;i<=y3-1;i++)printf(" ");printf("v");
			}
			if(y3<y4){
				for(int i=y3+1;i<=y4-1;i++)printf(" ");printf("v");
			}			
			if(y4<y2){
				for(int i=y4+1;i<=y2-1;i++)printf(" ");printf("v");
			}
			y3+=1;y4-=1;
		}	
		printf("\n");
		y1+=t1;y2+=t2;
		if(y1==0){
			t1=1;t2=-1;
			y1+=t1;y2+=t2;
		}
		if(y1==y2) {
			for(int i=1;i<=y1-1;i++)printf(" ");printf("v");
			break;	
		}
	}
}

int main(){
	int xaiv;
	printf("\n1: Hlub");
	printf("\n2: tsi Hlub");
	
	do{
		printf("\n\n Koj puag hlub kuv: ");
		scanf("%d",&xaiv);
	
		switch(xaiv){
			case 1:{
				printf("\n\tKuv hlub koj og ''\n");
				Hlub();
				break;
			}
			case 2:{
				break;
			}
			case 3: break;
		}
	}while(xaiv!=3);
	return 0;
}
