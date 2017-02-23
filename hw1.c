/*
* Assignment: Programming Assignment 1
* Class: CSC 6320
* Date: 2/6/17
* Author: Daniel Burkhart
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

pid_t pid, pid1;
int num;

int splitProcesses(void);
void calculateChildProcess(void);
void parentProcess(void);

/**
* Main function that serves as entry point to program
*/
int main(int argc, char *argv[]) {

	if (argc == 1) {
		fprintf(stderr,"Usage: ./a.out <starting value>\n");
		return -1;
	}
	
	num = atoi(argv[1]);
	
	if(num <= 0){
		fprintf(stderr,"Cannot perform algorithm on anything below 1.\n");
		return -1;
	} else{	
		splitProcesses();
	}

	return 0;
}

/**
* Function that is used to create two processes
*/
int splitProcesses(void){
	pid = fork();

	if(pid <0){
		fprintf(stderr, "Fork Failed");
		return 1;
	} else if(pid == 0){
		calculateChildProcess();
	} else{
		parentProcess();
	}
	return 0;
}

/**
* Function that calculate collatz conjecture
* and prints out pid and pid1 information
*/ 
void calculateChildProcess(void){
	pid1 = getpid();
	printf("child: pid = %d \n", pid);
	printf("child: pid1 = %d \n", pid1);

	printf("%d,", num);

	while(num != 1){			
		if(num %2 == 0){
			num = num / 2;
		} else if(num %2 == 1){
			num = 3 * num +1;
		}
		printf("%d,", num);
	}
	
	printf("\n");
}

/**
* Function that prints out parent process information
*/
void parentProcess(void){
	pid1 = getpid();
	printf("parent: pid = %d \n", pid);
	printf("parent: pid1 = %d \n", pid1);
	wait(NULL);
}
