static int free_mem = 0x100000;

void *malloc(unsigned int s) {
    free_mem = free_mem + 0x1000;
    int *mem = &(free_mem);
    return mem;
}

void free(void *p) {
}

__extension__ typedef int __guard __attribute__((mode (__DI__)));

void* __dso_handle = (void*) &__dso_handle;

extern "C" void __cxa_pure_virtual() { 
    while(1); 
}

extern "C" int __cxa_guard_acquire(__guard *g) { 
    return !*(char *)(g); 
}

extern "C" void __cxa_guard_release (__guard *g) {
    *(char *)g = 1;
}

extern "C" void __cxa_guard_abort (__guard *) {
}

void *operator new(unsigned int s) {
    return malloc(s);
}

void operator delete(void *p) {
    return free(p);
}

void *operator new[](unsigned int s) {
    return malloc(s);
}

void operator delete[](void *p) {
    return free(p);
}
