static int free_mem = 10000;

void *my_alloc(unsigned int s) {
    free_mem = free_mem + 0x1000;
    int *mem = &(free_mem);
    return mem;
}

void my_free(void *p) {
}

void *operator new(unsigned int s) {
    return my_alloc(s);
}

void operator delete(void *p) {
    return my_free(p);
}

void *operator new[](unsigned int s) {
    return my_alloc(s);
}

void operator delete[](void *p) {
    return my_free(p);
}

extern "C" void __cxa_pure_virtual() { }
extern "C" void __umoddi3() { }
extern "C" void __udivdi3() { }
extern "C" void __dso_handle() { }
extern "C" void __cxa_guard_release() { }
extern "C" void __cxa_guard_acquire() { }
extern "C" void __divdi3() { }
