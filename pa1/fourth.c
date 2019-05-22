#include<stdio.h>
#include<string.h>
#include<stdlib.h>

 int main(int argc , char *argv[]){
	int hashtable[2000] = {NULL};
	if(hashtable[0] == NULL){
		//printf("you got it \n");
	}
	
	// initialized an array for the hash table
	// need to determine mod function
	// im just going to mod by 7 
	FILE *bank;
	FILE *dank;
	//char filename[20] = argv[1];
	//scanf("%s",filename);
	bank = fopen(argv[1],"r");
	// bank is now the bank of shit that needs to be processed
	if(bank == NULL){
		printf("error");
		return 1;
	}
	char c;
	dank = bank;
	int bounty =0;
	for(c = getc(dank); c!= EOF; c = getc(dank)){
		if(c=='\n'){
			bounty = bounty+1;
		}

	}
	bank = fopen(argv[1],"r");
	int count =0;
	char line[22];
		while(line != NULL){
			if(count>bounty-1){
				break;
			}
			count = count+1;
			fgets(line,20,bank);
			char cs;
			cs = line[0];
			//printf("%c \n",cs);
			if(line[0] == 'i'){

				// insert code
				int data;
				sscanf(line,"i     %d",&data);
				// now data has stuff i can work with 
				int key;
				key = data % 7;
				// mod 7 is the function to create the key
				if(hashtable[key]== NULL){
					hashtable[key]= data;
					//printf("%d \n",data);
					int test = hashtable[key];
					//("%d \n",test);
					printf("inserted \n");
				}else{
					int counter;
					counter = key;
					int check = 0;
					int checkr = 0;
					while(hashtable[counter] != NULL){
						if(hashtable[counter] == data){
							// found a duplicate break here and declare duplicate
							check = 1;
							break;
						}
						counter = counter+1;
						// should terminate when it reaches a opening
					}
					if(check == 0){
					hashtable[counter]=data;
					printf("inserted \n");	
					}else{
						printf("duplicate \n");
					}
					


				}


			}else if(line[0] == 's'){
				int data;
				sscanf(line,"s	%d",&data);
				int key  = data % 7;
				if(hashtable[key] == data){
					// found it on first try nice
					printf("present \n");
				}else{
					int counter;
					counter = 0 ;
					int check = 0;
					while(counter < 2001){
						if(hashtable[counter]== data){
							// found
							check = 1;
							break;

						}
						counter = counter+1;
					}
					if(check != 0){
						printf("absent \n");
					}else{
						printf("present \n");
					}
				}

				// search code 
			}else{
				printf("error \n");
				

				// thats some noise 
			}
		}
		return 0;
		// made int so i can catch null files 

}