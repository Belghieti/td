#include<stdio.h>

int main(){

int nbr ,som=0 ,compt=0,som_positive=0 ,min=0,min_positive = 0; 

printf("Saisir les nombres");
scanf("%d",&nbr);
min =nbr;
min_positive = nbr;
while(nbr!=999){

som=som+nbr;
compt++;
if(nbr < min )min=nbr;

if(nbr>=0){
som_positive = som_positive+nbr;if(nbr <= min_positive )min_positive=nbr;
}
scanf("%d",&nbr);

}

printf("le nbre totale de la suite :%d\n",compt);
printf("la somme des valeur de la suite :%d\n",som);
printf("le minumum : %d\n",min);
printf("la somme des valeur strictement positive:%d\n",som_positive);
printf("le minumum des valeur strictement positive:%d",min_positive);
return 0;
}