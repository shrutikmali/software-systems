/*
============================================================================
Name : 29
Author : Shrutik Mali
Description : Write a program to get maximum and minimum real time priority.
Date: 4 Sep 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <linux/types.h>

int main() {
	int pid = getpid();
	int scheduler = sched_getscheduler(pid);
	printf("Current priority is: ");
	switch(scheduler) {
		case 0:
			printf("Normal\n");
			break;
		case 1:
			printf("FIFO\n");
			break;
		case 2:
			printf("Round Robin\n");
			break;
		case 3:
			printf("Batch\n");
			break;
		case 5:
			printf("Idle\n");
			break;
		case 6:
			printf("Deadline\n");
			break;
		default:
			printf("Unknown\n");
			break;
	}
	printf("Enter 0 to change to Normal\n");
	printf("Enter 1 to change to FIFO\n");
	printf("Enter 2 to change to Round Robin\n");
	printf("Enter 3 to change to Batch\n");
	printf("Enter 5 to change to Idle\n");
	printf("Enter 6 to change to Deadline\n");
	printf("Enter -1 to quit\n");
	int option;
	scanf("%d", &option);
	
	int my_sched;
	struct sched_param param;
	param.sched_priority = 99;
	
	switch(option) {
		case -1:
			return 0;
		case 0:
			//my_sched.sched_priority = SCHED_NORMAL;
			my_sched = 0;
			break;
		case 1:
			//my_sched.sched_priority = SCHED_FIFO;
			my_sched = 1;
			break;
		case 2:
			//my_sched.sched_priority = SCHED_RR;
			my_sched = 2;
			break;
		case 3:
			//my_sched.sched_priority = SCHED_BATCH;
			my_sched = 3;
			break;
		case 5:
			//my_sched.sched_priority = SCHED_IDLE;
			my_sched = 5;
			break;
		case 6:
			//my_sched.sched_priority = SCHED_DEADLINE;
			my_sched = 6;
			break;
		default:
			printf("Unknown, exiting\n");
			return 0;
	}
	
	int result = sched_setscheduler(pid, my_sched, &param);
	if(result != 0) {
		printf("Error occurred\n");
		return -1;
	}
	printf("Scheduler changed to: \n");
	scheduler = sched_getscheduler(pid);
	printf("Current scheduler is: ");
	switch(scheduler) {
		case 0:
			printf("Normal\n");
			break;
		case 1:
			printf("FIFO\n");
			break;
		case 2:
			printf("Round Robin\n");
			break;
		case 3:
			printf("Batch\n");
			break;
		case 5:
			printf("Idle\n");
			break;
		case 6:
			printf("Deadline\n");
			break;
		default:
			printf("Unknown\n");
			break;
	}
	
	return 0;
}
