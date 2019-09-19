#ifndef _INHERITANCE_H__
#define _INHERITANCE_H__

#include "box.h"

typedef enum 
{
    PLASTIC,
    METAL,
    WOOD,
    PAPER,
    OTHER
}Types;

typedef struct { char __unused__; } Materials;

static const char* Materials_getName(Types type);

/********   material_t   ********/

typedef struct Material_t
{
	/*Materials m_material;*/
    Types m_type;
}Material_t;

void create_material_t(Material_t* const,Types); 

const char* name(const Material_t* const); 

/********* pyshical box ***********************/

typedef struct PhysicalBox{
    Material_t m_material;
	Box box;

}PhysicalBox;

void create_PhysicalBox_d3(PhysicalBox* const,double l, double w, double h);

void create_PhysicalBox_d3_t(PhysicalBox* const,double l, double w, double h,Types);

void create_PhysicalBox_t(PhysicalBox* const,Types);

void destroy_PhysicalBox(PhysicalBox* const);

void copy_physBox( PhysicalBox* const, const PhysicalBox* const);

Types phys_getMaterial(const PhysicalBox* const);

void physical_print(const PhysicalBox* const);

int physBox_equal(const PhysicalBox* const, const PhysicalBox* const);

int physBox_not_equal(const PhysicalBox* const, const PhysicalBox* const);

/**************** weightBox ****************/
typedef struct WeightBox{
	double m_weight;
	Box m_box;
}WeightBox;

void create_WeightBox_d4(WeightBox* const,double l, double w, double h, double wgt);

void copy_WeightBox(WeightBox* const,const WeightBox* const);

void destroy_WeightBox(const WeightBox* const);

void copy_assignWeightbox(WeightBox* const,const WeightBox* const other);

double getWeight_weightBox(const WeightBox* const) ;

void weight_print(const WeightBox* const );

int wBox_equal(const WeightBox* const, const WeightBox* const);

int wBox_not_equal(const WeightBox* const, const WeightBox* const);


#endif /* _INHERITANCE_H__ */
