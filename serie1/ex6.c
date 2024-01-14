#include<stdio.h>

int main(){
int nbr,i ;


printf("Saisir un nombre entier");
scanf("%d",&nbr);
if(nbr%2==0){
for(i=0 ;i<=nbr;i=i+2){if(i==0)continue;printf("%d  ",i);}

}
return 0 ;
}