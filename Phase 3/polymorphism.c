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
	this->m_PrePostFixer_vtable.m_DefaultTextFormatter.m_textFormatter.m_TextFormatter_vtable.print = print_PrePostFixer;
	/*this->m_PrePostFixer_vtable.m_print = print_PrePostFixer_Long_Char*/;
	/* init pointer to virtual functions */
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
















