#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define min(X,Y) ((X) < (Y) ? (X) : (Y))
#define max(X,Y) ((X) > (Y) ? (X) : (Y))

int** multiply_matrices(int**, int**, int, int, int, int);
void freeAll(int**, int, int);
void writeMatrix(FILE *fout, int **matrix, int m, int n);

double startTime, stopTime;

int main(int argc, char** argv){
	FILE* fin;
	FILE* fout;
		fin = fopen(argv[1], "r");
	
	/* read the file */
	int m1 = 0;
	int n1 = 0;
	int m2 = 0;
	int n2 = 0;
	int i = 0;
	int j = 0;
	if(fscanf(fin, "%d %d", &m1, &n1) != 2) {
		printf("error\n");
		return 0;
	}
	int** array1 = (int**) malloc(m1 * sizeof(int*));
	for(i = 0; i<m1; i++){
		array1[i] = (int*) malloc(m1*sizeof(int));
		for(j = 0; j < n1; j ++) {
			if(fscanf(fin, "%d", &array1[i][j]) != 1) {
				printf("error\n");
				return 0;
			}
			if(j == n1 - 1) {
				fscanf(fin, "\n");
			} else {
				fscanf(fin, " ");
			}
		}

	}
		fscanf(fin, "\n");
	if(fscanf(fin, "%d %d", &m2, &n2) != 2) {
		printf("error\n");
		return 0;
	}
	int** array2 = (int**) malloc(m2 * sizeof(int*));
	for(i = 0; i<m2; i++){
			array2[i] = (int*) malloc(n2 * sizeof(int));
			for(j = 0; j < n2; j ++) {
			if(fscanf(fin, "%d", &array2[i][j]) != 1) {
				printf("error\n");
				return 0;
			}
			if(j == n2 - 1) {
				fscanf(fin, "\n");
			} else {
				fscanf(fin, " ");
			}
		}

	}
	fclose(fin);
	if(m2 != n1){
		printf("error\n");
		return 0;
	}
	startTime = clock();
	int** product = multiply_matrices(array1, array2, m1, n1, m2, n2);
	stopTime = clock();
	
	printf("%d * %d; SEQUENTIAL; %f secs\n", m1, n2, (stopTime-startTime)/CLOCKS_PER_SEC);
	
	fout = fopen("mymatrix_result.txt", "w");
	writeMatrix(fout, product, m1, n2);
	fclose(fout);
	
	freeAll(array1, m1, n1);
	freeAll(array2, m2, n2);
	freeAll(product, m1, n2);
	
	//print_matrix(product, m1, n2);
	return 0;



}
int** multiply_matrices(int** matrix1, int** matrix2, int m1, int n1, int m2, int n2) {
	if(n1 != m2) {
		printf("error\n");
		return NULL;
	}
	
	int i = 0;
	int j = 0;
	int k = 0;
	int** product = (int**) malloc(m1 * sizeof(int*));
		//int skelly = matrix1[400][370]* matrix2[400][370];
				//printf(" sdfs%d \n", skelly);
	
	//for(i = 0; i < m1; i ++) {
	//}
//	printf("%d\n", n1);
	//int count = 0;5
	
	
	for(i = 0; i<m1; i++){
		product[i] = (int*) malloc(n2 * sizeof(int));
		for(j = 0; j<n1; j++){
			product[i][j] = 0;
		}
	}
	/*
	int clem =0;
	int flem = 0;
	//int k = 0;
	int r = 0;
	for(i = 0; i<m1;i = i+2){
		for(j= 0; j<n2;j = j+2){
			for(clem = 0; clem<m1;clem = clem+1){
				for(flem = i; flem<min(i+2,m1); flem = flem+1){
					r = 0;
					for(k = j; k<min(j+2,m1); k = k+1){
					product[i][j]  += matrix1[i][k] * matrix2[k][j];

					}
				}
			}
		}

	}
 	*/
	for(i = 0; i < m1; i ++) {
		//product[i] = (int*) malloc(n2 * sizeof(int));
		int chg = 0;
		j = 0;
		k =0;
		 while(j<n2){
		 	/*
		 	if(chg == 0){
		 		product[i][j] = 0;
		 	}
			
			*/
			if(k == n1 ){
				//chg = 0;
				k = 0;
				//printf("%d\n", j);
				j++;
			}
				
				 product[i][j]  += matrix1[i][k] * matrix2[k][j];
				
				//printf("%d \n", product[i][j]);
			k++;
			chg = 1;
 			/*
			if(k == n1-1){
				//printf("we out");
				//count++;

				chg = 0;
			}
			*/
			
		} 
	}
	

	//printf("%d \n", count);
	/*
		int** product2 = (int**) malloc(m1 * sizeof(int*));
	
	for(i = 0; i < m1; i ++) {
		product2[i] = (int*) malloc(n2 * sizeof(int));
	}
	
	for(i = 0; i < m1; i ++) {
		for(j = 0; j < n2; j ++) {
			product2[i][j] = 0;
			for(k = 0; k < n1; k ++) {
				product2[i][j] += matrix1[i][k] * matrix2[k][j];
				//printf("%d\n",product[i][j]);
				
					printf("%d 	%d \n", product[i][j],product2[i][j]);
					//break;
				
			}
		}

	}
	/*
	int count = 0;
for(i = 0; i < m1; i ++) {
		for(j = 0; j < n2; j ++) {
if (product[i][j]!=product2[i][j]){
	//printf("not the same");
	count++;
	//printf("%d \n", count);
}


		}
	}
	printf("%d \n", count);



*/
	return product;
}

void freeAll(int **matrix, int m, int n) {
	int i;
	for (i=0; i<m; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

void writeMatrix(FILE *fout, int **matrix, int m, int n) {
	int i,j;

	for(i=0; i<m; i++) {     
		for(j=0; j<n; j++)  
			fprintf(fout,"%d ",matrix[i][j]); 
		putc('\n',fout);
   }
}
