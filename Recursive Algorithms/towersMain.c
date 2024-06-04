#include <stdlib.h>
#include <stdio.h>
#include "towers.h"

int main(int argc, char **argv)
{
    int i;
    int n;
    int from;
    int dest;

    if(argc == 1){
       n = 3;
       from = 1;
       dest = 2;
       towers(n, from, dest);
    }
    else if (argc == 2){
       n = atoi(argv[1]);
       towers(n, 1, 2);
    }
    else if (argc == 4){
       n = atoi(argv[1]);
       from = atoi(argv[2]);
       dest = atoi(argv[3]);
       if ((from == dest) || (from < 1 || from > 3) || (dest < 1 || dest > 3)){
 	   printf("Invalid Tower");
	exit(1);
       }
    towers(n, from, dest);
    }
    exit(0);
}

