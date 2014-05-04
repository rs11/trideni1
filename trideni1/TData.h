//
//  TData.h
//  bpc2a-project-template
//
//  Created by: Petr Petyovsky on 18/04/14.
//  $Id: TData.h 110 2014-04-18 13:30:23Z petyovsky $
//

#ifndef __TDATA_H__
#define __TDATA_H__

#define ERR_DATA_NOT_EMPTY		 		1
#define ERR_DATA_INCONSISTENT			2
#define ERR_DATA_ZERO_ARRAY_SIZE		3
#define ERR_DATA_NO_MEMORY				4
#define ERR_DATA_ALREADY_DEALLOCATED	5

struct TData
	{
	unsigned long iSize;
	double *iValue;
	};

int CreateData(struct TData *aData, unsigned long aSize);
int DestroyData(struct TData *aData);

#endif /* __TDATA_H__ */
