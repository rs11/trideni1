//
//  TData.c
//  bpc2a-project-template
//
//  Created by: Petr Petyovsky on 18/04/14.
//  $Id: TData.c 110 2014-04-18 13:30:23Z petyovsky $
//

#include <stdio.h>
#include <stdlib.h>
#include "TData.h"


int CreateData(struct TData *aData, unsigned long aSize)
	{
	if(aData->iSize && aData->iValue)
		{
		fprintf(stderr, "Error: Data structure isn't empty. Dealloc it before new allocation!\n");
		return(ERR_DATA_NOT_EMPTY);
		}

	if (aData->iSize || aData->iValue)
		{
		fprintf(stderr, "Error: Data structure is inconsistent!\n");
		return(ERR_DATA_INCONSISTENT);
		}

	if(!aSize)
		{
		fprintf(stderr, "Error: Data array size cannot be a zero!\n");
		return(ERR_DATA_ZERO_ARRAY_SIZE);
		}
	
	aData->iValue = (double *)calloc(aSize, sizeof(aData->iValue[0]));
	if(!aData->iValue)
		{
		fprintf(stderr, "Error: No memory for allocation!\n");
		return(ERR_DATA_NO_MEMORY);
		}
	aData->iSize = aSize;
	
	return(0);
	} /* CreateData() */

int DestroyData(struct TData *aData)
	{
	if(!aData->iSize && !aData->iValue)
		{
		fprintf(stderr, "Error: Data structure already dealocated!\n");
		return(ERR_DATA_ALREADY_DEALLOCATED);
		}

	if(!aData->iSize || !aData->iValue)
		{
		fprintf(stderr, "Error: Data structure is inconsistent!\n");
		return(ERR_DATA_INCONSISTENT);
		}
	
	free(aData->iValue);
	
	aData->iValue = NULL;
	aData->iSize = 0;
	
	return(0);
	} /* DestroyData() */
