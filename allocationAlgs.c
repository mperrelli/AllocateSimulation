/////////////////////////////////////////////////////////////
//                                                         //
//  This file holds the allocation algorithms              //
//                                                         //
/////////////////////////////////////////////////////////////

#include "header.h"

/////////////////////////////////////////////////////////////
//                                                         //
//  Best fit algorithm                                     //
//                                                         //
//  Allocates the processes using the best fit algorithm   //
//  In this case we just sort the processes and partitions //
//  and then use the first fit algorthm, as it delivers    //
//  the same result                                        //
//                                                         //
/////////////////////////////////////////////////////////////
void allocate_bestFit(struct process *procHead, struct partition *partHead, int partitions)
{
	
	sortProcesses(procHead);
	sortPartitions(partHead);
	allocate_firstFit(procHead, partHead, partitions);
	
}

////////////////////////////////////////////////////////////
//                                                        //
//  First fit algorithm                                   //
//                                                        //
//  Allocates the processes using the first fit algorithm //
//  by looking at the first process and finding the       //
//  first partition it fits into                          //
//                                                        //
//  Variables:                                            //
//  currProcess: pointer to the current process           //
//  currPartition: pointer to the current partition       //
//  cycle:  counter to track the current cycle of         //
//          allocation                                    //
//  allocated:  either 0 or 1, tells us if we found a     //
//              slot for the process or not               //
//                                                        //
////////////////////////////////////////////////////////////
void allocate_firstFit(struct process *procHead, struct partition *partHead, int partitions)
{
	
	// Variable Declarations
	struct process *currProcess;
	struct partition *currPartition;
	currProcess = procHead;
	currPartition = partHead;
	int cycle = 0, allocated = 0;

	// We deal with one process at a time in order of which they were put in
	while(currProcess != NULL)
	{
		allocated = 0;
		// Loop through our partitions until we reach the end of the list or
		// the currProcess is allocated.
		while(currPartition != NULL && allocated == 0)
		{
			// If the current process fits into the current partition and there
			// isn't already a process in that partition, then allocate.
			if(currProcess->size <= currPartition->size && currPartition->waste == -1)
			{
				currPartition->waste = currPartition->size - currProcess->size;
				allocated = 1;
			}
			
			currPartition = currPartition->next;
		}
		
		// If we cant find a partiton that the current process fits into 
		// we output an error message.
		if(allocated == 0)
		{
			printf("Could not place process of size %d into any partitions!\n", currProcess->size);
		}
		
		// Update which cycle we are on, advance to the next process
		// and print the status of our partitions.
		cycle++;
		currProcess = currProcess->next;
		printStatus(partHead, partitions, cycle);
	}
	
}