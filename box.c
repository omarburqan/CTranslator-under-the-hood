#include "box.h"

void create_Box(Box* const box){
	create_Box1(box,1);
}
void create_Box1(Box* const box,double dim){
    if(!box)
    	return ;
    create_Box2(box,dim,dim,dim);
}
void create_Box2(Box* const box,double l, double w, double h){
	
    if(!box)
    	return ;
    box->width = w;
    box->height = h;
    box->length = l;
 	print(box);
}
void copyBox(Box* const box1,const Box* const box2){
	create_Box2(box1,box2->length,box2->width,box2->height);
}

void destroy_Box(const Box* const box){
    printf("Box destructor, %f x %f x %f\n", box->width, box->height, box->length);
}

double getWidth(const Box* const box) {
	return box->width;
}
double getLength(const Box* const box) {
	return box->length;
}
double getHeight(const Box* const box) {
	return box->height;
}
double getVolume(const Box* const box) {
	double temp ;
	temp = (box->width * box->length * box->height);
	return temp;
}

void print(Box* box) {
    printf("Box: %f x %f x %f\n", box->length, box->width, box->height); 
}

Box* const multiplySQ(Box* const box,double mult){
	box->width *= mult;
    box->height *= mult;
    box->length *= mult;
    return box;
}
Box multiplyKrd(const Box* const box, double mult){
	Box result;
	copyBox(&result,box);
	multiplySQ(&result,mult);
	return result;
}
Box multiplydKr(double mult, const Box* const box){
	return multiplyKrd(box,mult);
}
int equal(const Box* const lhs, const Box* const rhs){
	return lhs->width == rhs->width && lhs->height == rhs->height && lhs->length == rhs->length;
}
int not_equal(const Box* const lhs, const Box* const rhs){
	return !(equal(lhs,rhs));
}




