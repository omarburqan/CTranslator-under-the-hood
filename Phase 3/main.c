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
void doPrePostChecker()
{
    printf("\n--- start doPrePostChecker() ---\n\n");
    PrePostChecker check;
    Ctor_PrePostChecker(&check);
	printThisSymbolUsingFunc_PPC();
   	printThisSymbolDirectly_PPC();
   	printDollarSymbolByCastDirectly_PPC();
   	printDollarSymbolByScopeDirectly();
   	printDollarSymbolByCastUsingFunc_PPC();
   	printDollarSymbolByScopeUsingFunc_PPC();
   	
    printf("\n--- end doPrePostChecker() ---\n\n");
	Dtor_PrePostChecker(&check);
}
void runAsPrePostHashFixerRef(const PrePostHashFixer* const pp)
{
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");
    
    print_PrePostHashFixer_int_char(pp,123,'#');

    printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}
void runAsPrePostDollarFixerRef(const PrePostDollarFixer* const pp)
{
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");
	
    print_PrePostDollarFixer_int_char(pp,123,'$');

    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}
void runAsPrePostDollarFixerObj(const PrePostDollarFixer* const pp)
{
    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");

    print_PrePostDollarFixer_int_char(pp,123,'$');

    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
}
void doMultiplier()
{
    printf("\n--- start doMultiplier() ---\n\n");

    Multiplier m1;
    Ctor_Multiplier(&m1,3);
    Multiplier m2;
    Ctor_Multiplier(&m2,5);
    Multiplier m3 = m1;
    Multiplier m4=m2;

    print_Multiplier(&m1,"abc ");
    print_Multiplier(&m2,"abc ");
    print_Multiplier(&m3,"abc ");
	print_Multiplier(&m4,"abc ");
	

    printf("\n--- end doMultiplier() ---\n\n");
    Dtor_Multiplier(&m1);
    Dtor_Multiplier(&m2);
    Dtor_Multiplier(&m3);
    Dtor_Multiplier(&m4);
}
int main()
{
	printf("\n--- Start main() ---\n\n");

    doPrePostFixer();
    doPrePostDollarFixer();
    doPrePostFloatDollarFixer();
    doPrePostChecker();

    PrePostHashFixer hfix;
	Ctor_PrePostHashFixer(&hfix,4);
    runAsPrePostHashFixerRef(&hfix);
    runAsPrePostDollarFixerRef(&hfix);
    runAsPrePostDollarFixerObj(&hfix);
    runAsPrePostHashFixerRef(&hfix);

    doMultiplier();

    /*doFormatterArray();
    doFormatterPtrs();
    doFormatterDynamicArray();*/

    printf("\n--- End main() ---\n\n");
	Dtor_PrePostHashFixer(&hfix);
	return 0;
}

