#include <ctype.h>
#include "apc.h"

int validate(char **argv)
{
    /* Operator validation */
    char op = argv[2][0];
    if (!(op == '+' || op == '-' || op == 'x' || op == '/'))
        return FAILURE;

    /* Operand validation */
    for (int i = 1; i <= 3; i = i+2)
    {
        char *p = argv[i];

        /* Allow negative numbers */
        if (*p == '-')
            p++;

        /* Empty operand check */
        if (*p == '\0')
            return FAILURE;

        /* Digit-only check */
        while (*p)
        {
            if (!isdigit(*p))
                return FAILURE;
            p++;
        }
    }

    return SUCCESS;
}
