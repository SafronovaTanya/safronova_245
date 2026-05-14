#include <stdio.h>
#include <math.h>

void sam(char *arg, double val)
{
    printf("sam: you passed %s, pow2 is %f\n", arg, pow(val, 2.0));
}
