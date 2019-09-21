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

/*****************************************/

void Ctor_PrePostHashFixer(PrePostHashFixer* const this,int precision){
	Ctor_PrePostDollarFixer(&this->m_PrePostDollarFixer,"===> ", " <===");
	this->m_PrePostHashFixer_precision = precision;
	
    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", 
    	getPrefix_PrePostFixer(&this->m_PrePostDollarFixer.m_PrePostFixer)
      , getPostfix_PrePostFixer(&this->m_PrePostDollarFixer.m_PrePostFixer) , 
    	this->m_PrePostHashFixer_precision);   
}

void Dtor_PrePostHashFixer(PrePostHashFixer* const this){
	Dtor_PrePostDollarFixer(&this->m_PrePostDollarFixer);
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", getPrefix_PrePostFixer(&this->m_PrePostDollarFixer.m_PrePostFixer), 
   															getPostfix_PrePostFixer(&this->m_PrePostDollarFixer.m_PrePostFixer));
}

void print_PrePostHashFixer_int_char(const PrePostHashFixer* const this,int num, char symbol){
	printFunc("[PrePostHashFixer::print(int, char)]"); 
    printf("-->\n");
    print_PrePostHashFixer_double_char(this,(double)(num), symbol);

}

void print_PrePostHashFixer_long_char(const PrePostHashFixer* const this,long num, char symbol){
	printFunc("[PrePostHashFixer::print(long, char)]"); 
    printf("-->\n");
    print_PrePostHashFixer_double_char(this,(double)(num), symbol);
}

/*************************************************/

void Ctor_PrePostFloatDollarFixer(PrePostFloatDollarFixer* const this,const char* prefix, const char* postfix){
	Ctor_PrePostDollarFixer(&this->m_PrePostDollarFixer,prefix,postfix);
    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", getPrefix_PrePostFixer(&this->m_PrePostDollarFixer.m_PrePostFixer), 
   															getPostfix_PrePostFixer(&this->m_PrePostDollarFixer.m_PrePostFixer));
}

void Dtor_PrePostFloatDollarFixer(PrePostFloatDollarFixer* const this){
	Dtor_PrePostDollarFixer(&this->m_PrePostDollarFixer);
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", getPrefix_PrePostFixer(&this->m_PrePostDollarFixer.m_PrePostFixer), 
   															getPostfix_PrePostFixer(&this->m_PrePostDollarFixer.m_PrePostFixer));
}

void print_PrePostFloatDollarFixer_num(const PrePostFloatDollarFixer* const this,float num){
	printFunc("[PrePostFloatDollarFixer::print(float)]");
    printf("-->\n");
    print_PrePostFloatDollarFixer_float_char(this,num, DEFAULT_SYMBOL_PrePostFloatDollarFixer);
}

void print_PrePostFloatDollarFixer_float_char(const PrePostFloatDollarFixer* const this,float num, char symbol){
	printFunc("[PrePostFloatDollarFixer::print(float, char)]"); 	
	printf("%s%c%.2f%s\n", getPrefix_PrePostFixer(&this->m_PrePostDollarFixer.m_PrePostFixer), symbol, num, 
							getPostfix_PrePostFixer(&this->m_PrePostDollarFixer.m_PrePostFixer));
}

/*******************************************************/

void Ctor_PrePostChecker(PrePostChecker* const this){
	Ctor_PrePostFloatDollarFixer(&this->m_PrePostFloatDollarFixer,"[[[[ ", " ]]]]");
	printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", getPrefix_PrePostFixer(&this->m_PrePostFloatDollarFixer.m_PrePostDollarFixer.m_PrePostFixer), getPostfix_PrePostFixer(&this->m_PrePostFloatDollarFixer.m_PrePostDollarFixer.m_PrePostFixer));
}

void Dtor_PrePostChecker(PrePostChecker* const this){
	Dtor_PrePostFloatDollarFixer(&this->m_PrePostFloatDollarFixer);
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", getPrefix_PrePostFixer(&this->m_PrePostFloatDollarFixer.m_PrePostDollarFixer.m_PrePostFixer), getPostfix_PrePostFixer(&this->m_PrePostFloatDollarFixer.m_PrePostDollarFixer.m_PrePostFixer));
}

void printThisSymbolUsingFunc_PPC(const PrePostChecker* const this){
	printFunc("[PrePostChecker::printThisSymbolUsingFunc()]");

    printf("Default symbol is %c\n", getDefaultSymbol_PrePostFloatDollarFixer());
}

void printThisSymbolDirectly_PPC(const PrePostChecker* const this){
	printFunc("[PrePostChecker::printThisSymbolDirectly()]");

    printf("Default symbol is %c\n", DEFAULT_SYMBOL_PrePostFloatDollarFixer);
}

void printDollarSymbolByCastUsingFunc_PPC(const PrePostChecker* const this){
	printFunc("[PrePostChecker::printDollarSymbolByCastUsingFunc()]");

    printf("Default symbol is %c\n", getDefaultSymbol_PrePostDollarFixer());
}
void printDollarSymbolByScopeUsingFunc_PPC(const PrePostChecker* const this){
	printFunc("[PrePostChecker::printDollarSymbolByCastDirectly()]");

    printf("Default symbol is %c\n", DEFAULT_SYMBOL_PrePostDollarFixer);
}
void printDollarSymbolByCastDirectly_PPC(const PrePostChecker* const this){
	printFunc("[PrePostChecker::printDollarSymbolByCastDirectly()]");

    printf("Default symbol is %c\n", DEFAULT_SYMBOL_PrePostDollarFixer);
}
void printDollarSymbolByScopeDirectly(const PrePostChecker* const this){
	printFunc("[PrePostChecker::printDollarSymbolByScopeDirectly()]");

    printf("Default symbol is %c\n", DEFAULT_SYMBOL_PrePostDollarFixer);
}



