#include <stdio.h>
#include "module_a.h"
#include "../utils/convert.h"
void PrintUpperCass(char _letter)
{
    char upper = ConvertUpper(_letter);
    printf("%c\n", upper);

}
