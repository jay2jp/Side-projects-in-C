#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include<math.h>
struct cache{
	int size;
	char* associate;
	char* policy;
	int blocksize;
	char* tracefile; 
	// just keeps all the characteristics of the simulated cache 
};
struct lrunode{
	char data[30]; // some hex number
	int cycles; // keeps age 
	struct lrunode* next;
	int strt;
};
struct nrunode{
	char data[30]; // hex
	int use; // one or zero
	struct nrunode* next;
	int strt;
};
struct fifonode{
	char data[30];
	struct fifonode* next;
	int cycles;
	//this one is position based 
	int strt;
};
void nru(struct cache* data, int reads, int writes, int hits, int misses){
	int lim = data->size;
	int div = data->blocksize;
	int num = lim/div;
	struct nrunode* cac [num];
	int laud = 0;
	while(laud<num){
		struct nrunode* meat = NULL;
		meat = (struct nrunode*) malloc(sizeof(struct nrunode));
		strcpy(meat->data,"");
		meat->use = 0;
		cac[laud] = meat;
		laud++;
	}
	char* filename = data->tracefile;
	FILE *file = fopen(filename,"r");
	char line[30];
	char three [30];
	while(fgets(line,sizeof line,file) != NULL){
		//printf("mydude\n");
		//printf("%s \n", line);
		int gim = strlen(line);
		//printf("del\n");
		if(gim<6){
			printf("Memory reads: %d \n", reads);
		printf("Memory writes: %d \n", writes);
 		
 		printf("Cache hits: %d \n",hits);
 		printf("Cache misses %d \n", misses);

			break;
		}
		char* one = strtok(line," ");
		char* two = strtok(NULL," ");
		char three[30];
		strcpy(three,strtok(NULL," "));
	//	printf("delta\n");
		if(strcmp(two,"W")== 0){
			int count = 0;
			int chk = 0;
			int counts = 0;
			int peper = 0;
			//("lard\n");
			while(count<num){
				if(strcmp(cac[count]->data,"") != 0){
					if(strcmp(cac[count]->data,three)==0){
						hits++;
						writes++;
						int wild = count;
						while(wild<num){
							cac[wild]->use = 1;
							wild++;
						}
						break;
					}
				}
				//printf("slard\n");
				if(strcmp(cac[count]->data,"") == 0 && peper == 0){
					//printf("delsa\n");
					struct nrunode* flip = NULL;
					flip = (struct nrunode*) malloc(sizeof(struct nrunode));
					//printf("fuck");
					strcpy(flip->data,three);
					flip->use = 0;
					cac[count] = flip;
					misses++; 
					reads++;
					writes++;
					peper = 1;
				}else{
				 //printf("break?\n");
					cac[count]->use = 1;
				}
				//printf("tech \n");
				count++;
				//printf("%d\n", count);
			}
			//printf("toasted\n");
			if(count == num && peper == 0){
				//printf("yout shouldngt be here \n");
			//	printf("dex\n");
				count = 0;
				int max = 0;
				while(count<num){
					if(cac[count]->use ==1){
						struct nrunode* clip = NULL;
						clip = (struct nrunode*) malloc(sizeof(struct nrunode));
						strcpy(clip->data,three);
						//clip->data = three;
						clip->use = 0;
						cac[count] = clip;
						reads++;
						misses++;
						writes++;
						break;
						//printf("jext\n");


					}
					count++;
				}
			

			}
			//printf("toast\n");

		}else{
			//reads 
			int spoon = 0;
			int check = 0;
			while(spoon<num){
			//	printf("baron \n");
				if(strcmp(cac[spoon]->data,"")!=0){
					if(strcmp(cac[spoon]->data,three) == 0){
						check = 1;

					}
				}
				cac[spoon]->use = 1;
				spoon++;
			}
			if(check == 1){
				hits++;
			}else{
				misses++;
				reads++;
			}
		}
		//printf("endlp\n");
	}
}

void fifo(struct cache* data, int reads, int writes, int hits, int misses){


	int lim = data->size;
	int div = data->blocksize;
	int num = lim/div;
	struct lrunode* cac [num];
	int laud = 0;
	while(laud<num){
		struct lrunode* meat = NULL;
		meat = (struct lrunode*) malloc(sizeof(struct lrunode));
		//meat->data = NULL;
		strcpy(meat->data,"");
		meat->cycles = 0;
		cac[laud] = meat;
		laud++;
	}
	char* filename = data->tracefile;
	FILE *file = fopen(filename,"r");
	char line[30];
	char three [30];
	while(fgets(line,sizeof line,file) != NULL){
		//printf("%s \n", line);
		int gim = strlen(line);
		if(gim<6){
			//printf("am i here\n");
		printf("Memory reads: %d \n", reads);
		printf("Memory writes: %d \n", writes);
 		
 		printf("Cache hits: %d \n",hits);
 		printf("Cache misses %d \n", misses);


			break;
		}
		//printf("%s this is the data before assignment\n", three );
		char tree[30];
		strcpy(tree,three);

		char* one = strtok(line," ");
		char* two = strtok(NULL," ");
		char three[30];
		
		 strcpy(three,strtok(NULL," "));
		
		//printf("%s pack\n", pack);
		//strcpy(three,pack);
		//printf("tree, %s \n", tree);
//
		//printf("sloth\n");
		
		if(strcmp(two,"W") == 0){
	//printf("this is the first thing in the array %s \n"	,	cac[0]->data);
			int count = 0;
			int chk = 0;
			int counts=0;
		while( counts < num){
				//printf("%s \n",cac[counts]->data);
				counts++;
			}
			//("sloth2\n");
			//printf("this is a list print \n");
			
			count = 0;
			int peper = 0;
			while(count<num){
				if(strcmp(cac[count]->data,"") != 0){
					if(strcmp(cac[count]->data,three)==0){
					// hit
						//printf("slothit\n");
						
					hits++;
					writes++;
					int wild = count;
					while(wild<num){
						cac[wild]->cycles = cac[wild]->cycles++;
						wild++;
					}
					break;

				}
				}
				
				if(strcmp(cac[count]->data,"") == 0 && peper == 0){
					// shits empty insert 
					struct lrunode* flip = NULL;
					flip = (struct lrunode*) malloc(sizeof(struct lrunode));
					strcpy(flip->data,three);
					flip->cycles = 0;
					cac[count] = flip;
					misses++;
					reads++;
					writes++;
					//printf("inserted \n");
					//printf("sloth3\n");
					peper = 1;
					//break;



				}else{
					cac[count]->cycles = cac[count]->cycles+1;

				}
				count++;

			}
			/*
			if(count != num){
				int shirt = count;
				while(shirt<num){
					cac[shirt]->cycles = cac[shirt]->cycles+1;
					shirt++;
				}

			}
			*/
			if(count == num && peper == 0){
				// shits full 
				count = 0;
				int max = 0;

				while(count<num){
									if(cac[count]->cycles > max){
										max = cac[count]->cycles;
									}
									count++;

				}
				count = 0;
				while(count<num){
					if(cac[count]->cycles == max){
						// replacement time 

						struct lrunode* rep = NULL;
						rep = (struct lrunode*) malloc(sizeof(struct lrunode));
						strcpy(rep->data,three);
						rep->cycles = 0;

						cac[count]= rep;
						misses++;
					reads++;
					writes++;
						break;
					}
					count++;
				}
				//printf("sloth3\n");

			
		}
		//printf("after check \n");
		int zuc = 0;
		while(zuc<num){
			//printf("%s \n ",cac[zuc]->data);
			zuc++;
		}
	}else{
		// 
		//printf("read \n");
		int spoon = 0;
		int check = 0;
		while(spoon<num){
			if( strcmp(cac[spoon]->data,"") != 0){
				if(strcmp(cac[spoon]->data,three)==0){
					
					check = 1;
				}
				
							}
							cac[spoon]->cycles = cac[spoon]->cycles+1;
							spoon++;
		}
		if(check  == 1 ){
			//printf("time hit \n");
			hits++;
		}else{
			misses++;
			reads++;
		}
		//printf("end read \n");
	}

 }


}


void lru(struct cache* data, int reads1, int writes1, int hits1, int misses1){
	int reads = 0;
	int writes = 0;
	int hits = 0;
	int misses = 0;
	int lim = data->size;
	int div = data->blocksize;
	int num = lim/div;
	struct lrunode* cac [num];
	int laud = 0;
	while(laud<num){
		struct lrunode* meat = NULL;
		meat = (struct lrunode*) malloc(sizeof(struct lrunode));
		//meat->data = NULL;
		strcpy(meat->data,"");
		meat->cycles = 0;
		cac[laud] = meat;
		laud++;
	}
	char* filename = data->tracefile;
	FILE *file = fopen(filename,"r");
	char line[30];
	char three [30];
	while(fgets(line,sizeof line,file) != NULL){
		//printf("%s \n", line);
		int gim = strlen(line);
		if(gim<6){
			//printf("am i here\n");
		printf("Memory reads: %d \n", reads);
		printf("Memory writes: %d \n", writes);
 		
 		printf("Cache hits: %d \n",hits);
 		printf("Cache misses %d \n", misses);


			break;
		}
		//printf("%s this is the data before assignment\n", three );
		char tree[30];
		strcpy(tree,three);

		char* one = strtok(line," ");
		char* two = strtok(NULL," ");
		char three[30];
		
		 strcpy(three,strtok(NULL," "));
		
		//printf("%s pack\n", pack);
		//strcpy(three,pack);
		//printf("tree, %s \n", tree);
//
		//printf("sloth\n");
		
		if(strcmp(two,"W") == 0){
	//printf("this is the first thing in the array %s \n"	,	cac[0]->data);
			int count = 0;
			int chk = 0;
			int counts=0;
		while( counts < num){
				//printf("%s \n",cac[counts]->data);
				counts++;
			}
			//("sloth2\n");
			//printf("this is a list print \n");
			
			count = 0;
			int peper = 0;
			while(count<num){
				if(strcmp(cac[count]->data,"") != 0){
					if(strcmp(cac[count]->data,three)==0){
					// hit
						//printf("slothit\n");
						cac[count]->cycles = 0;
					hits++;
					writes++;
					int wild = count;
					while(wild<num){
						cac[wild]->cycles = cac[wild]->cycles++;
						wild++;
					}
					break;

				}
				}
				
				if(strcmp(cac[count]->data,"") == 0 && peper == 0){
					// shits empty insert 
					struct lrunode* flip = NULL;
					flip = (struct lrunode*) malloc(sizeof(struct lrunode));
					strcpy(flip->data,three);
					flip->cycles = 0;
					cac[count] = flip;
					misses++;
					reads++;
					writes++;
					//printf("inserted \n");
					//printf("sloth3\n");
					peper = 1;
					//break;



				}else{
					cac[count]->cycles = cac[count]->cycles+1;

				}
				count++;

			}
			/*
			if(count != num){
				int shirt = count;
				while(shirt<num){
					cac[shirt]->cycles = cac[shirt]->cycles+1;
					shirt++;
				}

			}
			*/
			if(count == num && peper == 0){
				// shits full 
				count = 0;
				int max = 0;

				while(count<num){
									if(cac[count]->cycles > max){
										max = cac[count]->cycles;
									}
									count++;

				}
				count = 0;
				while(count<num){
					if(cac[count]->cycles == max){
						// replacement time 

						struct lrunode* rep = NULL;
						rep = (struct lrunode*) malloc(sizeof(struct lrunode));
						strcpy(rep->data,three);
						rep->cycles = 0;

						cac[count]= rep;
						misses++;
					reads++;
					writes++;
						break;
					}
					count++;
				}
				//printf("sloth3\n");

			
		}
		//printf("after check \n");
		int zuc = 0;
		while(zuc<num){
			//printf("%s \n ",cac[zuc]->data);
			zuc++;
		}
	}else{
		// 
		//printf("read \n");
		int spoon = 0;
		int check = 0;
		while(spoon<num){
			if( strcmp(cac[spoon]->data,"") != 0){
				if(strcmp(cac[spoon]->data,three)==0){
					cac[spoon]->cycles = -1;
					check = 1;
				}
				
							}
							cac[spoon]->cycles = cac[spoon]->cycles+1;
							spoon++;
		}
		if(check  == 1 ){
			//printf("time hit \n");
			hits++;
		}else{
			misses++;
			reads++;
		}
		//printf("end read \n");
	}

 }

}








int main(int argc, char **argv){
	//printf("hello");
// things to check is assoc: n is a power of 2 
 	// block size is a power of 2;
 	// check if cache file is a power of 2 
 	//  for fifo just make the blocks into a queue because you delete the first one in to make space for incoming units

 	// for lru you should make a linked list that goes thru the nodes that keep cycles of not used and maintatins order based on that constant remember to malloc
 	//  for nru you want to create a node similar to nru and just have ones and zeros to see if it was used recently, 1 means it wasnt used recently
 	//  also for nru when looking for space the first 1 encounterd gets deleted to make space for the new block
 	// make sure that you include a read and write counter 
 	//  aslo include hits and miss counters because that is really what matters. 
 	//  also consider changing the hex falues to decimal values for ur own program unless you want to do a string compare
 	// check the power of 2 shit before you run any of the methods 
 	// strcmp
 	// things i learned in office hours
 	// a write makes a miss, a hit , and a write 
 	// a read makes a hit or a miss and hit and a read 
//printf("rllynigga");
	// ./first <cache size><associativity><cache policy><block size><trace file>
char *cachesize =argv[1];

//printf("bro");
 	char * init = argv[1];
 	//printf("rllynigga");
 	int step = strlen(init);
 	int p = 0;
 	int d = 0;
 	int z = 0;
 	char zta[4][14];
//printf("rllynigga");
 	/*
 	while(step>p){
 		char gel[14];
 		if(init[p] == ' '){
 			d = 0;
 			//zta[z]= gel;
 			strcpy(zta[z],gel);
 			z=z+1;
 			strcpy(gel,"");
 			// gel = "";
 			p = p+1;
 			continue;


 		}else{
 			gel[d]= init[p];

 		}
 		p = p+1;
 		d = d+1;
 		// so 
 	}
	*/
	 	struct cache*  cash = NULL;
 	cash = (struct cache*) malloc(sizeof(struct cache));
 	//int sizer = atoi(argv[1]);
 	cash->size = atoi(argv[1]);
 	cash->associate = argv[2];
 	cash->policy =  argv[3];
 	cash->blocksize = atoi(argv[4]);
 	cash->tracefile = argv[5];
 int reads = 0; 
  int writes = 0;
  int hits = 0;
  int misses = 0;
 	if(strcmp(cash->policy,"lru")==0){
 		printf("wrd \n");
 		lru(cash,reads,writes,hits,misses);
 		
 	}
 	if(strcmp(cash->policy,"nru")==0){
 			nru(cash,reads,writes,hits,misses);
 	}
 	if(strcmp(cash->policy,"fifo")==0){
 			fifo(cash,reads,writes,hits,misses);
 	}

 	// need to check if this is base 2 
 	return 0;

 }