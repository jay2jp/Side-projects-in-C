 #include <sys/time.h>
#define PAGE_SIZE 8192
#define TOTAL_MEM_SIZE (4096 * 1024)
#define L1_CACHE_LINE_SIZE 64
#define NUM_PAGES 1024
#define MAX_GUESS 128*1024
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<sys/time.h>

      main(int argc, char *argv[]) {
        int in = 7;
            int boys[in];
    int zed = 0;
   // int starttime = clock();

    for(zed = 0;zed < in; zed++){
        boys[zed] = zed;
    }
    //int stoptime = clock;
    float total_time;
    register int *a, *b, i, num_cache_lines_guess, num_iter, k, l;
    struct timeval t1, t2;

/*
    if(argc < 2) {
        printf("Usage: %s guesesed \n", argv[0]);
        exit(1);
    }
*/
    num_cache_lines_guess = atoi(argv[1]);
    b = a = (void *) sbrk(TOTAL_MEM_SIZE);

    /* Touch all pages */
    for(k = 0; k < TOTAL_MEM_SIZE/PAGE_SIZE; k++, a += 2048)
        *a = 1;

    num_iter = TOTAL_MEM_SIZE / (num_cache_lines_guess * L1_CACHE_LINE_SIZE); 

          gettimeofday(&t1,0);

    for(a = b,k = 0; k < num_iter; k++, a = b) {

        /* Each iteration in the loop accesses one cache line */
        for(l = 0; l < num_cache_lines_guess; l++,a += 8)
            i = *a;
    }

    gettimeofday(&t2,0);

    total_time = ((t2.tv_sec-t1.tv_sec)*1000000 + (t2.tv_usec-t1.tv_usec));
    printf("bytes in cache %d : %f microseconds\n",
    num_cache_lines_guess * L1_CACHE_LINE_SIZE, total_time/num_iter);

    }