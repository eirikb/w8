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
