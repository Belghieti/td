#include<stdio.h>

int compteur=0,nbr;

int main(){

printf("Saisir un nombre ..!");
scanf("%d",&nbr);
for(int i = 1 ; i<=nbr ; i++){
if(nbr%i==0)compteur++;
}
if(compteur==2)printf("%d est premier",nbr);else printf("%d n'est pas premier",nbr);
return 0;
}