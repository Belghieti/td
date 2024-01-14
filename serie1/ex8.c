#include<stdio.h>

int main(){
int nbr;
printf("Question a):\n");
printf("Saisi un nbre: \n");
scanf("%d",&nbr);
for(int i=0 ; i<nbr ;i++){
for(int j=nbr-i ;j>0;j--)printf("%d",j);
printf("\n");
}

printf("Question b):\n");
printf("Saisi un nbre: \n");
scanf("%d",&nbr);
for(int i=0 ; i<=nbr ;i++){
for(int j =0 ;j<=i;j++)printf(" ");
for(int j=0 ; j<nbr-i ;j++)printf("%d",i);
printf("\n");
}
return 0;
}