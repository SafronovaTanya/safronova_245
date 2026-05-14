#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>

void bill(char *arg)
{
    void (*real_bill)(char *);
    real_bill = dlsym(RTLD_NEXT, "bill");
    printf("bill is called\n");
    real_bill(arg);
}

void sam(char *arg, double val)
{
    void (*real_sam)(char *, double);
    real_sam = dlsym(RTLD_NEXT, "sam");
    printf("sam is called\n");
    real_sam(arg, val);
}
