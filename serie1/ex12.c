#include<stdio.h>
int main(){

int i  ,j, t;

printf("la taille ");
scanf("%d",&t);
if(t%2 == 0)
t = t-1;
for(i=0 ; i<t ;i++){
for(j=0 ;j<t;j++){
if(j==0 || j ==t-1 ||i==0 || i==t-1)
printf(" *");
else if(j == i  || j==t-i-1)//t=6  + + + + + + 
printf(" +");
else if (j == t/2 )
printf(" -");
else if (i == t/2)
printf(" |");
else
printf("  ");
}

printf("\n");
}

return 0;
}