#include <stdio.h> 
#include <string.h>
#include<stdlib.h>
int main(int argc, char **argv){

if (argv[1] == NULL){
	printf("error\n");
	exit(1);
}

char* inputstr;
int input;

char dinput[20];
strcpy(dinput,argv[1]);
//printf("%s",dinput);

sscanf(dinput,"%d",&input);
//int c = scanf("%d", &input);

if(input % 2 == 0){
// its even
printf("even \n");
}
else if(input % 2 != 0){
// its odd
printf("odd \n");
}





}
