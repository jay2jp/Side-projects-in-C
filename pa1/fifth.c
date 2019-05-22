#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main(int argc, char ** argv[]){
	FILE * datapad;
	char filename[20];
	strcpy(filename,argv[1]);
	datapad = fopen(filename,"r");
	int dim1;
	int dim2;
	char line[20];
	fgets(line,sizeof(line),datapad);
	//printf("%s \n",line);
	sscanf(line,"%d %d", &dim1,&dim2);
	int mat1[dim1][dim2];
	int mat2[dim1][dim2];
	int count = 0;
	int prot =0;
	int rot =0;
	while(count<dim1){
		char reader[30];
		fgets(reader,28,datapad);
		int total=0;
		int n;
		int i;
		rot = 0;
		//printf("%s\n",reader);
		char cpt[30];
			strcpy(cpt,reader);
		while(total< 30){
			//sscanf(reader+total,"%*[^0123456789]%d%n",&i,&n);
			if(isdigit(reader[total])){
				int ins = reader[total]-'0';
				//printf("%c \n",reader[total]);
				//printf("%d \n", ins);
				mat1[prot][rot]=ins;
				rot = rot+1;
				//printf("%d \n",rot);
				if(rot == dim2){
					//printf("change");
					prot = prot+1;
					rot = 0;
				}
				if(prot == dim1){
					break;
				}
			}
			total = total+1;
			

		}
		if(rot == dim2){
			prot = prot+1;
			rot = 0;
		}
		if(prot == dim1){
			break;
		}
		count = count+1;

	}

	// mat 1 done 
	int cunt = 0;
	int rews = 0;
	int culs = 0;
	while(cunt<dim1+1){
		char reader[30];
		fgets(reader,28,datapad);
		int total = 0;
		int n;
		int i;
		culs = 0;
		//printf("%s\n", reader);
		while(total<30){
			if(isdigit(reader[total])){
				int ins = reader[total]-'0';
				mat2[rews][culs]=ins;
				culs = culs+1;
				if(culs == dim2){
					rews=rews+1;
					culs=0;
				}
				if(rews == dim1){
					break;
				}
			}
			total = total+1;
		}
		if(culs==dim2){
			rews = rews+1;
			culs = 0;
		}
		if(rews == dim1){
			break;
		}
		cunt = cunt+1;
	}

	// matrix 2 time 
	//printf("%d \n",dim1);
	// maths time
	int mat3[dim1][dim2];
	int lest = 0;
	int selc = 0;
	int bk = 0;
	while(bk<dim1){
		int d1 = mat1[selc][lest];
		int d2 = mat2[selc][lest];
		int fins = d1+d2;
		mat3[selc][lest] = fins;
		if(lest == dim2){
			lest = 0;
			selc = selc+1;
		}
		if(selc == dim2){
			break;
		}
		lest = lest+1;

	}
	// print time
	int ch = 0;
	int dc = 0;
	int rc = 0;
	int finl = 0;
	int zim =dim1*dim2;
	while(rc < dim1){
		if(ch == dim2-1){
			printf("%d \n",mat3[rc][dc]);
			ch =0;
		}else{
			printf("%d ",mat3[rc][dc]  );
		ch = ch+1;
		}
		if(dc == dim2){
			rc = rc+1;
			dc = 0;
		}
		if(rc == dim1){
			break;
		}
		dc = dc+1;
		finl = finl+1;
		if(finl == zim){
			break;
		}
	}


	//sscanf(line,"%d %d",&dim1,&dim2);
	//printf("%d %d \n",dim1,dim2);
}