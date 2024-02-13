#include <stdio.h>

#include "NotInt/NotInt.h"

const char kCommandPrototype[] = "dot GraphLog%d.log -o log%d.png -T png";

NotInt max(NotInt a, NotInt b)
{
    if (a < b)
        return b;
    return a;
}

NotInt f(NotInt a)
{
    return a;
}

NotInt sum(NotInt a, NotInt b)
{
    return f(a) + f(b);
}

NotInt sum(NotInt a, NotInt b, NotInt c)
{
    return a + b + c;
}

void StartGraphicDump()
{
    static int dump_counter = 0;
    dump_counter++;

    char file_name[100];
    sprintf(file_name, "GraphLog%d.log", dump_counter);

    NotInt::not_int_output = fopen(file_name, "w");
    fprintf(NotInt::not_int_output, "digraph G{\n"
                                    //"rankdir = LR;\n"
                                    "node[shape = record, fontsize = 14, style=filled];\n"
                                    "splines = ortho\n");
}

void EndGraphicDump()
{
    static int dump_counter = 0;
    dump_counter++;

    fprintf(NotInt::not_int_output, "}\n");
    fclose(NotInt::not_int_output);

    char command[100];
    sprintf(command, kCommandPrototype, dump_counter, dump_counter);
    system(command);      //Generate .png log
}

int main()
{
    StartGraphicDump();
    printf("====================\n");
    printf("max(1, 2) = %d\n", max(1, 2).value);
    printf("====================\n");
    EndGraphicDump();

    StartGraphicDump();
    printf("\n====================\n");
    printf("sum(3, 4) = %d\n", sum(3, 4).value);
    printf("====================\n");
    EndGraphicDump();
    
    StartGraphicDump();
    printf("\n====================\n");
    printf("sum(10, 20, 30) = %d\n", sum(10, 20, 30).value);
    printf("====================\n");
    EndGraphicDump();
}