////////////////////////////////////////////////////////////
//                                                        //
//  Matthew Perrelli                   Operating Systems  //
//                                                        //
//  This program simulates how on OS would allocate       //
//  processes to fixed memory partitions using            //
//  the First Fit and Best Fit algorithms                 //
//                                                        //
////////////////////////////////////////////////////////////

#include "header.h"

////////////////////////////////////////////////////////////
//                                                        //
//  Main                                                  //
//                                                        //
//  The main function sets up the linked lists for        //
//  partitions and processes by having the user input     //
//  the information. Next we have the user select an      //
//  algorithm to use as the allocation method.            //
//                                                        //
//  Variables:                                            //
//  partitions, processes:  total number of processes     //
//                          and partitions                //
//  algorithm:  Stores which algorithm to use             //
//  i:  counter                                           //
//  currPartition, partitionHead: partition pointers      //
//  currProcess, processHead: process pointers            //
//                                                        //
////////////////////////////////////////////////////////////
int main()
{
	
	// Variable Declarations
	int partitions, processes, i, algorithm;
	struct partition *currPartition, *partitionHead;
	struct process *currProcess, *processHead;
	
	// Allocate space to the intial nodes in the lists
	partitionHead = (struct partition*)malloc(sizeof(struct partition));
	processHead = (struct process*)malloc(sizeof(struct process));
	
	// Point the current pointers to the heads of each list
	currPartition = partitionHead;
	currProcess = processHead;
	
	// read in the number of partitions and then for each partition
	// ask the user for the size.
	printf("Number of partitions: ");
	scanf("%d", &partitions);
	
	for(i = 1; i <= partitions; i++)
	{
		
		printf("Size of partition [%d]: ", i);
		scanf("%d", &currPartition->size);
		
		currPartition->waste = -1;
		
		if(i == partitions)
		{
			currPartition->next = NULL;
		}
		else{
			currPartition->next = (struct partition *)malloc(sizeof(struct partition));
			currPartition = currPartition->next;
		}
	}
	
	currPartition = partitionHead;
	
	// read in the number of processes and then for each process
	// ask the user for the size.
	printf("Number of processes: ");
	scanf("%d", &processes);
	
	for(i = 1; i <= processes; i++)
	{
		
		printf("Memory requiered for process [%d]: ", i);
		scanf("%d", &currProcess->size);
		
		if(i == processes)
		{
			currProcess->next = NULL;
		}
		else{
			currProcess->next = (struct process *)malloc(sizeof(struct process));
			currProcess = currProcess->next;
		}
	}
	
	currProcess = processHead;
	
	// Print the initial list of processes and partitions
	printf("\nInitial Partitions and processes\n");
	printf("------------------------------------\n");
	printPartitionList(partitionHead);
	printf("\n");
	printProcessList(processHead);
	printf("\n");
	
	// Get the algorithm the user wishes to use
	printf("Select an allocation scheme.\n Enter [1] for First Fit or [2] for Best Fit: ");
	scanf("%d", &algorithm);
	
	// Apply an algorithm based on input
	switch(algorithm)
	{
		case 1:
			allocate_firstFit(processHead, partitionHead, partitions);
			break;
			
		case 2:
			allocate_bestFit(processHead, partitionHead, partitions);
			break;
			
		default:
			printf("Something went wrong\n");
	}


	return 0;
	
}