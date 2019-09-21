#include "polymorphism.h"

void doPrePostFixer()
{
    printf("\n--- start doPrePostFixer() ---\n\n");
	PrePostFixer angleBrackets;
	Ctor_PrePostFixer(&angleBrackets,"<<< ", " >>>");
	print_PrePostFixer(&angleBrackets,"Hello World!");
	print_PrePostFixer_Long_Char((&angleBrackets),((long)-777),'\0');
	print_PrePostFixer_Long_Char((&angleBrackets),((long)350),'#');
	print_PrePostFixer_Long_Char((&angleBrackets),((long)3.14),'\0');
   
    printf("\n--- end doPrePostFixer() ---\n\n");
    Dtor_PrePostFixer(&angleBrackets);
}
void doPrePostDollarFixer()
{
    printf("\n--- start doPrePostDollarFixer() ---\n\n");
    
   	PrePostDollarFixer asterisks;
   	Ctor_PrePostDollarFixer(&asterisks,"***** ", " *****");
	print_PrePostDollarFixer_int_char(&asterisks,-777,DEFAULT_SYMBOL_PrePostDollarFixer);
	print_PrePostDollarFixer_int_char(&asterisks,350, '#');
	print_PrePostDollarFixer_double_char(&asterisks,3.14f, DEFAULT_SYMBOL_PrePostDollarFixer);
    printf("\n--- end doPrePostDollarFixer() ---\n\n");
    Dtor_PrePostDollarFixer(&asterisks);
}
void doPrePostFloatDollarFixer()
{
    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
	PrePostFloatDollarFixer hashes;
	Ctor_PrePostDollarFixer(&hashes,"### ", " ###");
	print_PrePostFloatDollarFixer_num(&hashes,-777);
	print_PrePostFloatDollarFixer_float_char(&hashes,350, '#');
	print_PrePostFloatDollarFixer_num(&hashes,3.14f);
	PrePostDollarFixer hashes2;
	Ctor_PrePostDollarFixer(&hashes2,"### ", " ###");
	print_PrePostFloatDollarFixer_num(&hashes,7.5);
	print_PrePostFloatDollarFixer_num(&hashes,100);
    printf("\n--- end doPrePostFloatDollarFixer() ---\n\n");
    Dtor_PrePostFloatDollarFixer(&hashes);
    Dtor_PrePostFloatDollarFixer(&hashes2);
}

int main()
{
	printf("\n--- Start main() ---\n\n");

    doPrePostFixer();
    doPrePostDollarFixer();
    doPrePostFloatDollarFixer();
    /*doPrePostChecker();

    PrePostHashFixer hfix;
    runAsPrePostFixerRef(hfix);
    runAsPrePostDollarFixerRef(hfix);
    runAsPrePostDollarFixerObj(hfix);
    runAsPrePostHashFixerRef(hfix);

    doMultiplier();

    doFormatterArray();
    doFormatterPtrs();
    doFormatterDynamicArray();*/

    printf("\n--- End main() ---\n\n");
	
	return 0;
}

