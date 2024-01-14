#include<stdio.h>
int main(){

int s, nbr;

printf("Saisir 5 nbre<100: \n");
for(int i=0 ;i<5;i++){scanf("%d",&nbr);if(nbr>=0 && nbr<=100){if(nbr%2==0)printf("le carre est %d \n",nbr*nbr);s=s+nbr;
printf("Le nbre total d'entree est %d\n",s);}else {printf("Vous depasse 100");break;}
}

return 0 ;
}
