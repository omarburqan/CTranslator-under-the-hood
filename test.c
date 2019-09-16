#include "test.h"
static Box largeBox;
static Box box99;
static Box box88;

void thisFunc()
{		
    printf("\n--- thisFunc() ---\n\n"); 
    static int isdeclared_99 = 0;
	if(!isdeclared_99){
		create_Box2(&box99,99, 99, 99);
		isdeclared_99 = 1;
	}
    multiplySQ(&box99,10);
}
void thatFunc()
{
    printf("\n--- thatFunc() ---\n\n");
    static int isdeclared_88 = 0;
	if(!isdeclared_88){ 
    	create_Box2(&box99,88, 88, 88);
    	isdeclared_88 = 1;
	}
    multiplySQ(&box88,10);
}

void doBoxes()
{
	Box b1;
 	Box b2;
 	Box b3;
 	Box b4;
 	
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

void doShelves()
{
    Box aBox;
    Box temp;
    Box temp2;
    Shelf aShelf;
    
    printf("\n--- start doShelves() ---\n\n");
	create_Box1(&aBox,5);
	createShelf(&aShelf);


    shelf_print(&aShelf);

    setBox(&aShelf,1, &largeBox);
    setBox(&aShelf,0, &aBox);
    shelf_print(&aShelf);
    
    setMessage("This is the total volume on the shelf:");
	shelf_print(&aShelf);

    setMessage("Shelf's volume:");
	shelf_print(&aShelf);
	
	create_Box2(&temp,2,4,6);
    setBox(&aShelf,1, &temp);
    destroy_Box(&temp);
	create_Box1(&temp2,2);
    setBox(&aShelf,2, &temp2);
    destroy_Box(&temp2);
	shelf_print(&aShelf);
	

    printf("\n--- end doShelves() ---\n\n");
    destroy_shelf(&aShelf);
	destroy_Box(&aBox);
}



void test(){
 	create_Box2(&largeBox,10,20,30);
    printf("\n--- Start main() ---\n\n");

    doBoxes();
    
	thisFunc();
    thisFunc();
    thisFunc();
    doShelves();
    
    printf("\n--- End main() ---\n\n");
    destroy_Box(&box99);
	destroy_Box(&largeBox);
    

}

