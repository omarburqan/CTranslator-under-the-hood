#ifndef __POLYMORPHISM_H__
#define __POLYMORPHISM_H__

#define printFunc(fname) printf("%-60s | ", (const char*) fname)

typedef struct TextFormatter TextFormatter;

typedef void (*print_textFormatter_ptr)(const void* const,const char* ) ; 
typedef void (*Dtor_ptr)(TextFormatter* const) ;

typedef struct {
	Dtor_ptr dtor_TextFormatter;
	print_textFormatter_ptr print;
}TextFormatter_vtable;

struct TextFormatter{
	TextFormatter_vtable m_TextFormatter_vtable;
};

void Ctor_TextFormatter(TextFormatter* const);	

void Dtor_TextFormatter(TextFormatter* const);    

/********** DefaultTextFormatter::Idere ************/

static int next_id;
  
static int getId();
 
/*********** DefaultTextFormatter *************/
typedef struct{
	TextFormatter m_textFormatter;
    const int m_id;
}DefaultTextFormatter;

void Ctor_DefaultTextFormatter(DefaultTextFormatter* const);

void copyCtor_DefaultTextFormatter(DefaultTextFormatter* const,const DefaultTextFormatter* const);

DefaultTextFormatter* const copyOperator_DefaultTextFormatter_equal(const DefaultTextFormatter* const);

void Dtor_DefaultTextFormatter();

void print_DefaultTextFormatter_text(const void* const,const char* text);

DefaultTextFormatter* generateFormatterArray();

/************ PrePostFixer ********************/
typedef void(*print_PrePostFixer_Long_Char_ptr)(const void* const,long num, char symbol);
typedef void(*getDefaultSymbol_PrePostFixer)(const void* const);

typedef struct {
	DefaultTextFormatter m_DefaultTextFormatter;
	print_PrePostFixer_Long_Char_ptr m_print;
	getDefaultSymbol_PrePostFixer m_getDefaultSymbol;
}PrePostFixer_vtable;

typedef struct{

	PrePostFixer_vtable m_PrePostFixer_vtable;
	const char* pre;
    const char* post;
}PrePostFixer;

void Ctor_PrePostFixer(PrePostFixer* const,const char* prefix, const char* postfix);

void Dtor_PrePostFixer(PrePostFixer* const);

void print_PrePostFixer(const void* const,const char* text);

#define print_PrePostFixer_Long_Char(this,num,symbol) \
	printFunc("[PrePostFixer::print(long, char)]"); \
    printf("-->\n") ;\
    if (symbol)    \
        print_num(num, symbol);\
    else \
        print_num(num); 
        
#define getDefaultSymbol_PrePostFixer(this) return '\0';

#define getPrefix_PrePostFixer(this) return this->pre

#define getPostfix_PrePostFixer(this) return this->pre

#define print_num_PrePostFixer_long(num) \
	printFunc("[PrePostFixer::print_num(long)]"); \
    printf("%s%ld%s\n", pre, num, post);
    

#define print_num_PrePostFixer_long_char(num,symbol) \
	printFunc("[PrePostFixer::print_num(long, char)]"); \
    printf("%s%c%ld%s\n", pre, symbol, num, post);
    
    

#endif /* __POLYMORPHISM_H__ */
