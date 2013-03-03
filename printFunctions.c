/////////////////////////////////////////////////////////////
//                                                         //
//  This file holds the print functions that output the    //
//  partitions and processes as well as the status table.  //
//                                                         //
/////////////////////////////////////////////////////////////

#include "header.h"

////////////////////////////////////////////////////////////
//                                                        //
//  printPartitionList                                    //
//                                                        //
//  Prints a list of the partitions with their sizes      //
//  and waste.                                            //
//                                                        //
//  variables:                                            //
//  current:  pointer to the current partition            //
//                                                        //
////////////////////////////////////////////////////////////
void printPartitionList(struct partition *head)
{
	
	struct partition *current;
	current = head;
	
	while(current != NULL)
	{
		printf("Partition Size: %d Waste: %d\n", current->size, current->waste + 1);
		
		current = current->next;
	}
		
}

////////////////////////////////////////////////////////////
//                                                        //
//  printProcessList                                      //
//                                                        //
//  Prints a list of the processes with their sizes       //
//                                                        //
//  variables:                                            //
//  current:  pointer to the current process              //
//                                                        //
////////////////////////////////////////////////////////////
void printProcessList(struct process *head)
{
	
	struct process *current;
	current = head;
	
	while(current != NULL)
	{
		printf("Process Size: %d\n", current->size);
		
		current = current->next;
	}
		
}

////////////////////////////////////////////////////////////
//                                                        //
//  printStatus                                           //
//                                                        //
//  Prints a formatted table that shows the current       //
//  state of partitions                                   //
//                                                        //
//  variables:                                            //
//  currPart:  pointer to the current partition           //
//  i:  counter                                           //
//  partitions:  number of partitions                     //
//  cycle:  the current cycle of our allocation process   //
//                                                        //
////////////////////////////////////////////////////////////
void printStatus(struct partition *head, int partitions, int cycle)
{
	
	// Variable Declarations
	struct partition *currPart;
	currPart = head;
	int i;
	
	// Print which cycle we are on
	printf("Cycle [%d]\n", cycle);
	
	printf("       ");
	
	// Set up the columns
	for(i = 1; i <= partitions; i++)
	{
		printf("hole[%d]\t", i);
	}
	
	// Fill each row with sizes
	printf("\nSize   ");
	while(currPart != NULL)
	{
		printf("%d\t", currPart->size);
		currPart = currPart->next;
	}
	
	currPart = head;
	
	// Fill each row with wastes
	printf("\nWaste  ");
	while(currPart != NULL)
	{
		if(currPart->waste == -1)
		{
			printf("%d\t", currPart->waste + 1);
		}
		else
		{
			printf("%d\t", currPart->waste);
		}
		
		currPart = currPart->next;
	}
	
	printf("\n------------------------------------\n");
	
}