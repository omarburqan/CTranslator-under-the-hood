#include "test.h"


void doBoxes()
{
	Box b1;
 	Box b2;
 	Box b3;
 	Box b4 ;
 	
    printf("\n--- Start doBoxes() ---\n\n");
    
    create_Box1(&b1,3);
    create_Box2(&b2,4, 5, 6);

    printf("b1 volume: %f\n",getVolume(&b1) );
    printf("b2 volume: %f\n", getVolume(&b2));

    multiplySQ(&b1,1.5);
    multiplySQ(&b2,0.5);

    printf("b1 volume: %f\n",getVolume(&b1) );
    printf("b2 volume: %f\n", getVolume(&b2));
   
	copyBox(&b3,&b2);
    b4 = multiplydKr(3,&b2);

    printf("b3 %s b4\n", equal(&b3,&b4) ? "equals" : "does not equal");

    multiplySQ(&b3,1.5);
    multiplySQ(&b4,0.5);
    
    printf("Now, b3 %s b4\n", equal(&b3,&b4) ? "equals" : "does not equal");
    printf("\n--- End doBoxes() ---\n\n");
    
    destroy_Box(&b1);
    destroy_Box(&b2);
    destroy_Box(&b3);
    destroy_Box(&b4);
}


void test(){

    printf("\n--- Start main() ---\n\n");

    doBoxes();
/*
   thisFunc();
    thisFunc();
    thisFunc();

    doShelves();
*/
    printf("\n--- End main() ---\n\n");

    

}

