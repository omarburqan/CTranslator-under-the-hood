#include "shelf.h"


void createShelf(Shelf* const shelf){
	size_t i ;
	for (i=0 ; i < NUM_BOXES ; i++) {
		create_Box(&shelf->boxes[i]);
	}
}
void setBox(Shelf* const shelf,int index, const Box* const dims){
	if (index >= NUM_BOXES || index < 0)
		return;
    shelf->boxes[index]=*dims;
}
double shelf_getVolume(Shelf* const shelf) {
	double res = 0;
	size_t i = 0;
	for (i=0 ; i < NUM_BOXES ; i++) {
		res+= getVolume(&shelf->boxes[i]);
	}
	return res;
}
Box* const getBox(Shelf* const shelf,int index){
	return &shelf->boxes[index];
}
void shelf_print(Shelf* const shelf){
	printf("%s %f\n", message, shelf_getVolume(shelf) );
}
int getNumBoxes(){
	return (int)NUM_BOXES;
}
void setMessage(const char* msg){
	message = msg;
}
void destroy_shelf(Shelf* const shelf){
	int i ;
	for (i = NUM_BOXES-1 ; i >= 0 ; i--) {
		destroy_Box(&shelf->boxes[i]);
	}

}


