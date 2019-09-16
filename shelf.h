#ifndef _SHELF_H_
#define _SHELF_H_

#include "box.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_BOXES 3
#define DEF_MSG "The total volume held on the shelf is"

typedef struct Shelf
{
    Box boxes[NUM_BOXES];
    
}Shelf;

static const char* message = DEF_MSG;

void createShelf(Shelf* const );
void setBox(Shelf* const shelf,int index, const Box* const dims);
double shelf_getVolume(Shelf* const shelf) ;
Box* const getBox(Shelf* const,int index);
void shelf_print(Shelf* const);

int getNumBoxes();
void setMessage(const char* msg);
void destroy_shelf(Shelf* const );
	
#endif /* _SHELF_H_ */
