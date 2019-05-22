#include <stdio.h>
#include<stdlib.h>
#include<string.h>
main(int argc, char*argv[]){
	if(argv[1] == NULL){
		printf("error\n");
		exit(1);
	}
	int input;
	char sen[100];
	strcpy(sen,argv[1]);
	sscanf(sen,"%d",&input);
	//printf("%d\n",input);
	//int ger = input % 2;
	//printf("%d \n", ger);


	if(sen == NULL){
		printf("error \n");
	}else{
		if (input == 2){
			printf("yes \n");

		}else if(input % 2 == 0){
			printf("no \n");
		}else{
			int start =2;
			int check =0;
			while( start < input){
				if(input % start == 0){
					printf("no \n");
					check =1;
					break;
				}
				start = start+1;
			}
			if(check == 0){
				printf("yes \n");
			}

		}
	}
}