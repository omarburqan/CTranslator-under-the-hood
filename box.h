#ifndef _BOX_H_
#define _BOX_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Box
{
	double width;
    double height;
    double length;       
}Box;
	
	void create_Box(Box* const);
	void create_Box1(Box* const,double dim);
    void create_Box2(Box* const,double l, double w, double h);
    void copyBox( Box* const,const Box* const); 
    
    void destroy_Box(const Box* const);

    double getWidth (const Box* const) ;
    double getLength(const Box* const) ;
    double getHeight(const Box* const) ;
    double getVolume(const Box* const) ;
    
    void print(Box*) ;
    
    Box* const multiplySQ(Box* const,double mult);
    
    
	Box  multiplyKrd(const Box* const box, double mult);
	Box  multiplydKr(double mult, const Box* const box);
	int equal(const Box* const lhs, const Box* const rhs);
	int not_equal(const Box* const lhs, const Box* const rhs);


#endif /* _BOX_H_ */
