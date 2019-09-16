#include "inheirtance.h"

static const char* Materials_getName(Types type)
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    return names[type];
}
void Materials_ctor(Materials * const self){
	

}
void Materials_cpyctor(Materials * const self,const Materials * const other){
	

}
/********************MATERIAL_T***************************/


void create_material_t(Material_t* const mt,Types type) { 
	mt->m_type = type;
	printf("Material created, set to %s\n", name(mt)); 
}

const char* name(const Material_t* const mt) {
	return Materials_getName(mt->m_type); 
}
/*************PYSHICAL BOX*****************/

void create_PhysicalBox_d3(PhysicalBox* const phys,double l, double w, double h){
	create_Box2(&phys->box,l,w,h);
	create_material_t(&(phys->m_material),OTHER);
	physical_print(phys);
}

void create_PhysicalBox_d3_t(PhysicalBox* const phys,double l, double w, double h,Types type){
	create_Box2(&phys->box,l,w,h);
	create_material_t(&(phys->m_material),type);
	physical_print(phys);
}

void create_PhysicalBox_t(PhysicalBox* const phys,Types type){
	create_material_t(&(phys->m_material),type);
	create_Box(&phys->box);
	physical_print(phys);
}

void destroy_PhysicalBox(PhysicalBox* const phys){
	destroy_Box(&phys->box);
    printf("PhysicalBox dtor, %f x %f x %f, %s; ", getLength(&phys->box), getWidth(&phys->box), 
    									getHeight(&phys->box),name(&phys->m_material));
    									
}
void copy_physBox( PhysicalBox* const phys, const PhysicalBox* const other){
	create_PhysicalBox_d3_t(phys,other->box.length,other->box.width,other->box.height,other->m_material.m_type);

}
Types phys_getMaterial(const PhysicalBox* const phys){
	return phys->m_material.m_type;
}

void physical_print(const PhysicalBox* const phys){
	printf("PhysicalBox, made of %s; ", name(&phys->m_material));
    print(&phys->box);
}
int physBox_equal(const PhysicalBox* const lhs, const PhysicalBox* const rhs){
	return equal(&lhs->box ,&rhs->box) && (phys_getMaterial(lhs)==phys_getMaterial(rhs));

}

int physBox_not_equal(const PhysicalBox* const lhs, const PhysicalBox* const rhs){
	return not_equal(&lhs->box ,&rhs->box) && !(phys_getMaterial(lhs)==phys_getMaterial(rhs)); 

}
/********** weight box *************/
void create_WeightBox_d4(WeightBox* const wBox,double l, double w, double h, double wgt){
	wBox->m_weight=wgt;
	create_Box2(&wBox->m_box,l,w,h);
	weight_print(wBox);

}
void copy_WeightBox( WeightBox* const wBox,const WeightBox* const other){
	wBox->m_box=other->m_box;
	wBox->m_weight=other->m_weight;
	weight_print(wBox);
}

void destroy_WeightBox(const WeightBox* const wBox){
	destroy_Box(&wBox->m_box);
	printf("Destructing WeightBox; ");
    weight_print(wBox);
}

void copy_assignWeightbox(WeightBox* const wBox,const WeightBox* const other){
	copy_WeightBox(wBox,other);	

}

double getWeight_weightBox(const WeightBox* const wBox) {
	return wBox->m_weight;
}

void weight_print(const WeightBox* const wBox){
	printf("WeightBox, weight: %f; ", wBox->m_weight);
    print(&wBox->m_box);

}
int wBox_equal(const WeightBox* const lhs, const WeightBox* const rhs){
	return equal(&lhs->m_box ,&rhs->m_box) && (getWeight_weightBox(lhs)==getWeight_weightBox(rhs));
}

int wBox_not_equal(const WeightBox* const lhs, const WeightBox* const rhs){
	return !wBox_equal(lhs,rhs);
}







