#include "polymorphism.h"

#include <stdio.h>
#include <stdlib.h>

void Ctor_TextFormatter(TextFormatter* const this){
	this->m_TextFormatter_vtable.dtor_TextFormatter = Dtor_TextFormatter;	
	this->m_TextFormatter_vtable.print = NULL;
}
void Dtor_TextFormatter(TextFormatter* const this)  {
	
}
/****************************************/
static int next_id = 0;

static int getId(){
	return next_id++;
}
/**************************************/
void Ctor_DefaultTextFormatter(DefaultTextFormatter* const this){
	Ctor_TextFormatter(&this->m_textFormatter);
	this->m_textFormatter.m_TextFormatter_vtable.print = print_DefaultTextFormatter_text;
	*((int*)&this->m_id) = getId();
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->m_id);
}
void copyCtor_DefaultTextFormatter( DefaultTextFormatter* const this,const DefaultTextFormatter* const other){
	this->m_textFormatter = other->m_textFormatter;
	*((int*)&this->m_id) = other->m_id;
    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->m_id, this->m_id);
}
DefaultTextFormatter* const copyOperator_DefaultTextFormatter_equal(const DefaultTextFormatter* const other){
	DefaultTextFormatter* new_DefaultTextFormatter;
	new_DefaultTextFormatter->m_textFormatter = other->m_textFormatter;
	*((int*)&new_DefaultTextFormatter->m_id) = other->m_id;
    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->m_id, new_DefaultTextFormatter->m_id);
	return new_DefaultTextFormatter;
}
void Dtor_DefaultTextFormatter(DefaultTextFormatter* const this){
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->m_id);
    Dtor_TextFormatter(&this->m_textFormatter);
}
void print_DefaultTextFormatter_text(const void* const this,const char* text){
	printFunc("[DefaultTextFormatter::print(const char*)]");    
    printf("%s\n", text);	
}
DefaultTextFormatter* generateFormatterArray(){
	size_t i =0;
	size_t max = 3;
	DefaultTextFormatter* new_array = malloc(sizeof(DefaultTextFormatter)*3);
	while (i<max){
		Ctor_DefaultTextFormatter(&new_array[i++]);
	}
	return new_array;
}
/***********************************************/
void Ctor_PrePostFixer(PrePostFixer* const this,const char* prefix, const char* postfix){
	Ctor_DefaultTextFormatter(&this->m_PrePostFixer_vtable.m_DefaultTextFormatter);
	this->m_PrePostFixer_vtable.m_DefaultTextFormatter.
							m_textFormatter.m_TextFormatter_vtable.print = print_PrePostFixer;
		
	/* init pointer to inline virtual functions */
	
	this->pre = prefix;
	this->post = postfix;
    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
}
void Dtor_PrePostFixer(PrePostFixer* const this){
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
	Dtor_DefaultTextFormatter(&this->m_PrePostFixer_vtable.m_DefaultTextFormatter);
}
void print_PrePostFixer(const void* const this,const char* text){
	printFunc("[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n",((PrePostFixer*)this)->pre, text, ((PrePostFixer*)this)->post);	
}
/************************************************/


void Ctor_PrePostDollarFixer(PrePostDollarFixer* const this, const char* prefix , const char* postfix){
	Ctor_PrePostFixer(&this->m_PrePostFixer,prefix,postfix);
	
	this->m_PrePostFixer.m_PrePostFixer_vtable.m_print = print_PrePostDollarFixer_long_char ;
    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", getPrefix_PrePostFixer(&this->m_PrePostFixer), 
    															getPostfix_PrePostFixer(&this->m_PrePostFixer));
   															
}

void copyCtor_PrePostDollarFixer(PrePostDollarFixer* const this,const PrePostDollarFixer* const other){
    Ctor_DefaultTextFormatter(&this->m_PrePostFixer.m_PrePostFixer_vtable.m_DefaultTextFormatter);
	this->m_PrePostFixer.m_PrePostFixer_vtable.m_DefaultTextFormatter.
							m_textFormatter.m_TextFormatter_vtable.print = print_PrePostFixer;			
	this->m_PrePostFixer.m_PrePostFixer_vtable.m_print = print_PrePostDollarFixer_long_char ;		
	/* init pointer to inline virtual functions */
	this->m_PrePostFixer.pre = other->m_PrePostFixer.pre;
	this->m_PrePostFixer.post = other->m_PrePostFixer.post;
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", getPrefix_PrePostFixer(&this->m_PrePostFixer) ,
																	 getPostfix_PrePostFixer(&this->m_PrePostFixer));
}

void Dtor_PrePostDollarFixer(PrePostDollarFixer* const this){
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", getPrefix_PrePostFixer(&this->m_PrePostFixer),
    															getPostfix_PrePostFixer(&this->m_PrePostFixer));
    Dtor_PrePostFixer(&this->m_PrePostFixer);
    
}
void print_PrePostDollarFixer_int_char(const PrePostDollarFixer* const this,int num, char symbol){
	printFunc("[PrePostDollarFixer::print(int, char)]"); 
    printf("-->\n");
	
    print_PrePostDollarFixer_long_char(this,(long)(num), symbol);
}

void print_PrePostDollarFixer_long_char(const void* const this,long num, char symbol){
	printFunc("[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");

    print_num_PrePostFixer_long_char((&((PrePostDollarFixer*)this)->m_PrePostFixer),num, symbol);
}

void print_PrePostDollarFixer_double_char(const PrePostDollarFixer* const this,double num, char symbol){
	printFunc("[PrePostDollarFixer::print(double, char)]"); 
    printf("%s%c%f%s\n", getPrefix_PrePostFixer(&this->m_PrePostFixer), symbol,num, 
    										getPostfix_PrePostFixer(&this->m_PrePostFixer));
}
/***********************************/











