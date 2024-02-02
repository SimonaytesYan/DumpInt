#include <stdio.h>

#include "NotInt/NotInt.h"

const char kCommandPrototype[] = "dot GraphLog -o log.png -T png";

NotInt max(NotInt a, NotInt b)
{
    if (a < b)
        return b;
    return a;
}

NotInt sum(NotInt a, NotInt b, NotInt c)
{
    return a + b + c;
}

NotInt f(NotInt a)
{
    return a;
}

NotInt sum(NotInt a, NotInt b)
{
    return f(a) + f(b);
}

int main()
{
    FILE* output = fopen("GraphLog", "w");
    fprintf(output, "digraph G{\n"
                    "rankdir = LR;\n"
                    "node[shape = record, fontsize = 14, style=filled];\n"
                    "splines = ortho\n");

    NotInt::not_int_output = output;

    printf("====================\n");
    printf("max(1, 2) = %d\n", max(1, 2).value);
    printf("====================\n");
    
    printf("\n====================\n");
    printf("sum(3, 4) = %d\n", sum(3, 4).value);
    printf("====================\n");
    
    printf("\n====================\n");
    printf("sum(10, 20, 30) = %d\n", sum(10, 20, 30).value);
    printf("====================\n");

    fprintf(output, "}\n");
    fclose(output);

    system(kCommandPrototype);      //Generate .png log
}