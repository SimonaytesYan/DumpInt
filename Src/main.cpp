#include <stdio.h>

#include "NotInt/NotInt.h"

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
    printf("====================\n");
    printf("max(1, 2) = %d\n", max(1, 2).value);
    printf("====================\n");
    
    printf("\n====================\n");
    printf("sum(3, 4) = %d\n", sum(3, 4).value);
    printf("====================\n");
    
    printf("\n====================\n");
    printf("sum(10, 20, 30) = %d\n", sum(10, 20, 30).value);
    printf("====================\n");
}