#include<stdio.h>

int main(){
int a , b ;float res ;
char opr ;

printf("Saisir  les deux nbrs :");

scanf("%d%d",&a,&b);

printf("saisir l'operation:");
scanf(" %c",&opr);

switch(opr){
	case '*':res=a*b; printf("le produit de %d*%d=%.2f\n",a,b,res);
		break;
	case '+':res=a+b; printf("la somme de %d+%d=%.2f\n",a,b,res);
		break;
	case '-':res=a-b; printf("la soustraction de %d-%d=%.2f\n",a,b,res);
		break;
	case '/':if(b!= 0)
		{res=(float)a/b; printf("la division de %d/%d=%.2f\n",a,b,res);}
		printf("Pas division sur 0   (! ");
		break;
	default:printf("Votre choix n'est pas valide!!");
}

return 0;
}