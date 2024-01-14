#include<stdio.h>
int main(){


char sex ;
int age;

printf(" votre sex ( F / H  ):\n");
scanf(" %c",&sex);
printf(" votre age :\n");
scanf("%d",&age);
switch(sex){

case 'H' :	if(  age >= 20 ){
		printf("vous este imposable\n");
		}else {printf("vous n'este pas  imposable\n");}
		break;
case 'h' :	if(  age >= 20 ){
		printf("vous este imposable\n");
		}else {printf("vous n'este pas  imposable\n");}
		break;
case 'F' :	if(  age >= 18 && age <= 35 ){
		printf("vous este imposable\n");
		}else {printf("vous n'este pas  imposable\n");}
		break;
case 'f' :	if(  age >= 18 && age <= 35){
		printf("vous este imposable\n");
		}else {printf("vous n'este pas  imposable\n");}
		break;

default : printf("vous n'avez pas saisir le bon choix !!!");

}



return 0;
}