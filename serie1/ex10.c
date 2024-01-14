#include<stdio.h>
int main(){

int N ,vide ,etoile;

printf("Saisir le nombre de colone!");
scanf("%d",&N);
vide = N-1;



for(int i=0 ; i<N ;i++){
for(int j=0 ; j<vide-i; j++)printf(" ");
for(int j=1 ; j<=2*i+1 ; j++){
		
	if(j == 1  || j==2*i+1 || i == N-1)
	{ 
	
		printf("*",j);
	}
	else
		printf(" ");
	
	}
printf("\n");
}

return 0 ;
}