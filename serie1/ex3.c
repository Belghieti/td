#include<stdio.h>

int main(){

float paye ;
int nbre_feuile;

printf("Saisir le nbr de feuile\n");
scanf("%d",&nbre_feuile);
if( nbre_feuile>=0 && nbre_feuile <= 10){
paye =nbre_feuile*1;
printf("la somme est : %.2f dh",paye);
}else if( nbre_feuile>10 && nbre_feuile <= 20){
paye =nbre_feuile*0.6;
printf("la somme est : %.2f dh",paye);
}else if( nbre_feuile<0){
printf("Impossible!!");
}else{
paye =nbre_feuile*0.4;
printf("la somme est : %.2f dh",paye);
}
return 0 ;
}