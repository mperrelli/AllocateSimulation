/////////////////////////////////////////////////////////////
//                                                         //
//  This file holds the sort functions                     //
//                                                         //
/////////////////////////////////////////////////////////////

#include "header.h"

////////////////////////////////////////////////////////////
//                                                        //
//  sortPartitions                                        //
//                                                        //
//  Selection sort of the partitions                      //
//                                                        //
//  Variables:                                            //
//  sorted, current:  pointers to partitions              //
//  temp:  a temp variable to hold a size while we swap   //
//                                                        //
////////////////////////////////////////////////////////////
void sortPartitions(struct partition *head)
{
	
	struct partition *sorted, *current;
	sorted = head;
	current = sorted;
	int temp;
	
	while(sorted != NULL)
	{
		while(current != NULL)
		{
			if(current->size < sorted->size)
			{
				temp = current->size;
				current->size = sorted->size;
				sorted->size = temp;
			}
			
			current = current->next;
		}
		
		sorted = sorted->next;
		current = sorted;
	}
	
}

////////////////////////////////////////////////////////////
//                                                        //
//  sortProcesses                                         //
//                                                        //
//  Selection sort of the processes                       //
//                                                        //
//  Variables:                                            //
//  sorted, current:  pointers to processes               //
//  temp:  a temp variable to hold a size while we swap   //
//                                                        //
////////////////////////////////////////////////////////////
void sortProcesses(struct process *head)
{
	
	struct process *sorted, *current;
	sorted = head;
	current = sorted;
	int temp;
	
	while(sorted != NULL)
	{
		while(current != NULL)
		{
			if(current->size < sorted->size)
			{
				temp = current->size;
				current->size = sorted->size;
				sorted->size = temp;
			}
			
			current = current->next;
		}
		
		sorted = sorted->next;
		current = sorted;
	}
	
}