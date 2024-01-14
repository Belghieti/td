#include<stdio.h>
int main(){

int prix_intial,prix_final,remise;
printf("Saisir le prix Intial!\n");
scanf("%d",&prix_intial);
if(prix_intial >=0 && prix_intial <100){
remise = prix_intial*0.3;
prix_final = prix_intial-remise;
printf("Prix initial : %d remise :%d prix_final : %d \n",prix_intial,remise,prix_final);
}else if(prix_intial >=100 && prix_intial <=200){
remise = prix_intial*0.4;
prix_final = prix_intial-remise;
printf("Prix initial : %d remise :%d prix_final : %d \n",prix_intial,remise,prix_final);
}else  if( prix_intial >200){
remise = prix_intial*0.5;
prix_final = prix_intial-remise;
printf("Prix initial : %d remise :%d prix_final : %d \n",prix_intial,remise,prix_final);
}else{printf("votre choix invalide!!");}


return 0 ;
}