#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int converter(char input[]){
	





	
	int count = 2; 
	double length = sizeof(input)/sizeof(int);
	int len = strlen(input);
	double element = 0;
	double base = 16;
	double dult = 16;

	while(count<length-2){
		if(isdigit(input[count])){
			double process = input[count]-'0';
			int i = 0;

			double addative = process * pow(base,count);
			element = element+addative;

		}else{
			// its a letter
			char complex = input[count];
			double process = 0;
			if(complex == 'a'){
				process = 10;
			}else if(complex == 'b'){
				process = 11;
			}else if(complex == 'c'){
				process = 12;
			}else if(complex == 'd'){
				process = 13;
			}else if(complex == 'e'){
				process =14;

			}else if(complex == 'f'){
				process = 15;
			}
			double addative = process * pow(base,count);
			element = element+addative;
		}
		count = count + 1;


	}
//	char *cole;
//	long cbase = strtol(input,0,0);
//	element = cbase;
	/*
	printf("1\n");
	printf("%s\n",input);
	long cbase = strtol(input,NULL,16);
	printf("%ld\n",cbase );
	element = cbase;
	*/
	return element;
	


};
typedef struct node{
	char val[17] ;
	struct node * next;
};

int linecounter(char *filename){
	FILE *datapad = fopen(filename,"r");
	int use = 0;
	int fc = 0;
	fc = fc+1;
	char sh[15];
	while((use = fgets(sh,15,datapad)) != EOF){
		if(use == '\n'){
			fc = fc+1;
		}
	}
	fclose(datapad);
	return fc;


};
 // gives how long the file is so i can know how many elements need to be in the string array for duplicate checks 
int filecount(char *filename){
	//linecounter attempt 2
	FILE *datapad;
	datapad = fopen(filename,"r");
	char looper[17];
	int checkz = 0;
	int count;
	//fgets(looper,14,datapad);
	//printf("%s", looper);
	fscanf(datapad,"%s",looper);
	printf("%s", looper);
//	printf("micro\n");
	printf("%s\n",looper);
	while(!feof(datapad)){
		//printf("macro\n");
		//fgets(looper,15,datapad);
		fscanf(datapad,"%s",looper);
		if(looper == NULL){
			checkz = 1;
		
			}
			count = count+1;
}
fclose(datapad);
return count;
};
main(int argc , char** argv){
	//printf("sucess\n");
	char *file;
	FILE *hexbank;
	file= argv[1];
	//printf("sucess\n");
	//int lines = filecount(*file); // this makes a segmentation fault 
	FILE *datapad;
	datapad = fopen(file,"r");
	int lines = 0;
	char looper[17];
	while(!feof(datapad)){
		fscanf(datapad,"%s",looper);
		lines = lines+1;

	}
	fclose(datapad);
//	printf("sucess\n");
	// number of lines made
	// minus one to account for the [0] set; 
	struct node hash[1000] = {NULL}; 
	long dupcheck[lines-1];
	memset(dupcheck,-1,sizeof(dupcheck));
	int moot = lines-1;
	//memset(dupcheck,-1,moot*sizeof(int));
		// put the decimal results in here so u can check for dups 
	hexbank = fopen(file,"r");
	if(hexbank == NULL){
		printf("error\n");
		
	}
	char hex[16]; 
	int count = 0;
	int nodup = 0;
	while(count<lines*2){
		//printf("lines  = %d \n",lines);
		//printf("count = %d \n", count);
		
		fgets(hex,16,hexbank);
		int burn  = strlen(hex);
		long po = strtoul(hex,NULL,16);
		//printf("burn  = %d \n", burn);
		
		if(po == 0){
		if(burn < 3){
			//printf("uhere\n");
			count = count+1;
			continue;
		}
		}
		
		if(count%2 == 1){
			count = count+1;
			continue;
		}
		//printf("hex = %s\n", hex);
		//double generated = converter(hex);
		long generated = strtoul(hex,NULL,16);

		//printf("generated=%d\n",generated);
		//printf("%d\n",generated);
		int dant = 0;
		int check = 0;
		while(dant<lines-1){
			//printf("are you here\n");
			if(generated == dupcheck[dant]){
				//printf("is error in duplicate \n");
				// found a duplicate 
				//printf("so u got here\n");
				check =1;
				break;
			}
			//printf("you must be here\n");

			if(dupcheck[dant] == -1){
				//printf("please\n");
				dupcheck[dant]= generated; 
				break;
				//printf("get here \n");
				// dup checker addecd 
			}
			//printf("end loop\n");
			dant = dant+1;
		}
		// ok so it gets past this loop now
		//printf("ur here now\n");
		if(check == 1){
			// wat do
			//nodup = nodup-1;
			count = count+1;
			continue; 
			// should start the loop over with a new hex

		}else{
			nodup = nodup+1;
			//printf("%d\n",nodup);
		}
			int key =0;
			if(generated>0){
				key = generated%1000;
			}else{
				int bur = generated%1000;
				bur =  bur*-1;
				key = bur;
			}
		// if ur here its not a duplicate and is good to be inserted
		struct node *DU;
		 DU = (struct node *) malloc(sizeof(struct node));
		//DU->val = hex;
		 strcpy(DU->val,hex);
		DU->next = NULL;
	//	printf("word\n");
		// node is no initialized going to initialize the hash table now.
		//int key  =  generated/1000;
		struct node *fan;
		fan = (struct node*) malloc(sizeof(struct node));
		//printf("shwerd\n");
		//printf("%d\n",key);
		memcpy(&fan,&hash[key],sizeof(hash[key])); // here is our fault
	//	printf("hotter \n");
		if(fan == NULL){
			//hash[key] = DU;
			memcpy(&hash[key],&DU,sizeof(DU));
			//hash[key]->val = DU->val;
			//hash[key]->next = DU->next;
		}else{
			// linked listing time 
			struct node *place;
		    place = (struct node *) malloc(sizeof(struct node));
		    memcpy(&place,&hash[key],sizeof(hash[key]));
			//place = hash[key];
			DU->next = place;
			memcpy(&hash[key],&DU,sizeof(DU));
			//hash[key]= DU;
			/*
			struct node *turns;
			turns = hash[key];
			struct node trav = (struct node *) malloc(sizeof(struct node));
			trav->data = NULL;
			trav->next = turns;
			trav = trav->next
			while(trav->next != NULL){
				trav =  trav->next;
			}
			trav->next = DU;
			// now re insert turns 
			hash[key] = turns;
			*/

		}


		//printf("lines = %d \n", lines);
		count = count+1;
		//printf("count  = %d\n",count);
		////if(count > 4){
			//break;
	//	}
	}
//nodup = nodup-1;
printf("%d\n",nodup);



}


