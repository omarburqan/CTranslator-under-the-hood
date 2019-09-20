#ifndef __POLYMORPHISM_H__
#define __POLYMORPHISM_H__


#define printFunc(fname) printf("%-60s | ", (const char*) fname)

typedef struct TextFormatter TextFormatter;

typedef void (*print_textFormatter_ptr)(const char* ) ; 
typedef void (*Dtor_ptr)(TextFormatter* const) ;

typedef struct TextFormatter_function{
	Dtor_ptr dtor_TextFormatter;
	print_textFormatter_ptr print_TextFormatter;
}TextFormatter_function;

struct TextFormatter{
	TextFormatter_function m_TextFormatter_function;
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

void print_DefaultTextFormatter_text(const char* text);

DefaultTextFormatter* generateFormatterArray();

/************ PrePostFixer ********************/
typedef void(*print_PrePostFixer_Long_Char)(long num, char symbol);
typedef void(*getDefaultSymbol_PrePostFixer)();

typedef struct {
	DefaultTextFormatter m_DefaultTextFormatter;
	print_PrePostFixer_Long_Char m_print;
	getDefaultSymbol_PrePostFixer m_getDefaultSymbol;
}PrePostFixer_function;

typedef struct{

	PrePostFixer_function m_PrePostFixer_function;
	const char* pre;
    const char* post;
}PrePostFixer;

void Ctor_PrePostFixer(PrePostFixer* const,const char* prefix, const char* postfix);

void Dtor_PrePostFixer(PrePostFixer* const);





/*
class PrePostFixer
{
public:
    

    virtual void print(const char* text) const;
    virtual void print(long num, char symbol = '\0') const;

    virtual char getDefaultSymbol() const;

protected:
    const char* getPrefix() const;
    const char* getPostfix() const;

private:
    void print_num(long num) const;
    void print_num(long num, char symbol) const;

};
*/

#endif /* __POLYMORPHISM_H__ */
