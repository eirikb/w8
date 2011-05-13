#include "console.h"

void malloc(size_t size) 
{
}

void free(void *p)
{
}


void *operator new(size_t size)
{
        malloc(size);
}
 
void *operator new[](size_t size)
{
        malloc(size);
}
 
void operator delete(void *p)
{
        free(p);
}
 
void operator delete[](void *p)
{
        free(p);
}

int main(void)
{
    Console console = new Console();
    console.write("Hello, world!");
    console.nl();
    console.write("Welcome to w8...");
}
