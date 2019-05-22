#include<unistd.h>
#include<stdio.h>
#include <time.h>
#include<sys/time.h>
#include<strings.h>
#include<math.h>
main(){
	struct timeval t1,t2,t3;
	double max = pow(2,53);
	int check = 32768/8; 
	// 2048
	// use 16384 for 248 machines 
	double arr[check];
	arr[1] = max;
	int i =0;
	for(i = 1; i< check; i++){
		max  = max/2;
		arr[i] = max;


	}
double arr2[check];
	//int glock = clock();
	gettimeofday(&t1,0);
	for( i = check; i>0; i-- ){
		double kek = arr[i];
	double rob = kek/2;
	arr2[i] = rob;
		//int stock  = clock();
		gettimeofday(&t2,0);
		int parttime  = ((t2.tv_sec-t1.tv_sec)*1000000 + (t2.tv_usec-t1.tv_usec));
		//int szech = stock - glock;
		printf("acess time %d array size %d \n", parttime, i);


	}
	//int sock = clock();
	gettimeofday(&t3,0);
	int ttime = ((t3.tv_sec-t1.tv_sec)*1000000 + (t3.tv_usec-t1.tv_usec));
	//int	gun = sock - glock;
	printf("final time %d \n", ttime);



}