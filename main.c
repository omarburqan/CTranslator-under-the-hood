#include "box.h"
#include "inheirtance.h"


void doMaterials()
{
    Materials mat;
    struct MatTest { Materials mat; Material_t mat_t; };
    Material_t mat1;
    Material_t mat2;
    printf("\n--- Start doMaterials() ---\n\n");
    

    printf("Size of Materials: %lu\n", sizeof(Materials));
    printf("Size of mat: %lu\n", sizeof(mat));
    printf("Size of Materials::Types: %lu\n", sizeof(Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));
	

    
    printf("Size of Materials + Material_t: %lu\n", sizeof(struct MatTest ));

	
    
    create_material_t(&mat1,OTHER);

    create_material_t(&mat2,METAL);

    printf("\n--- End doMaterials() ---\n\n");
}

void doPhysicalBox()
{
	PhysicalBox pb1;
	PhysicalBox pb2;
	PhysicalBox pb3;
	PhysicalBox pb4 ;
    printf("\n--- Start doPhysicalBox() ---\n\n");
	
    create_PhysicalBox_d3_t(&pb1,8, 6, 4,PLASTIC);
    create_PhysicalBox_t(&pb2, WOOD);
    create_PhysicalBox_d3(&pb3,7, 7, 7);

	printf("\npb4 is copy-constructed from pb1\n");

    copy_physBox(&pb4,&pb1);

    physical_print(&pb4);
    physical_print(&pb1);
	
    printf("pb4 %s pb1\n", physBox_equal(&pb4,&pb1) ? "equals" : "does not equal");

    printf("\npb4 is copy-assigned from pb3\n");
    copy_physBox(&pb4,&pb3);
    physical_print(&pb4);
    physical_print(&pb3);
    printf("pb4 %s pb3\n", physBox_equal(&pb4,&pb3)  ? "equals" : "does not equal");
	
    printf("\n--- End doPhysicalBox() ---\n\n");
    destroy_PhysicalBox(&pb4);
    destroy_PhysicalBox(&pb3);
    destroy_PhysicalBox(&pb2);
    destroy_PhysicalBox(&pb1);
    


}

void doWeightBox()
{
	WeightBox pw1;
	WeightBox pw2;
	WeightBox pw3;
	WeightBox pw4 ;
    printf("\n--- Start doWeightBox() ---\n\n");

     create_WeightBox_d4(&pw1,8, 6, 4, 25);
     create_WeightBox_d4(&pw2,1, 2, 3,0.0);
     create_WeightBox_d4(&pw3,10, 20, 30, 15);
    
    printf("\npw4 is copy-constructed from pw1\n");
	copy_WeightBox(&pw4 , &pw1);
    weight_print(&pw4);
    weight_print(&pw1);
    printf("pw4 %s pw1\n", wBox_equal(&pw4,&pw1) ? "equals" : "does not equal");

    printf("\npw4 is copy-assigned from pw3\n");
    copy_assignWeightbox(&pw4,&pw3);

    weight_print(&pw4);
    weight_print(&pw3);
    printf("pw4 %s pw3\n",wBox_equal(&pw4,&pw3) ? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");

    destroy_WeightBox(&pw4);
    destroy_WeightBox(&pw3);
    destroy_WeightBox(&pw2);
    destroy_WeightBox(&pw1);

}





int main()
{
    printf("\n--- Start main() ---\n\n");

    doMaterials();

    doPhysicalBox();

    doWeightBox();

    printf("\n--- End main() ---\n\n");
	return 0;
}

