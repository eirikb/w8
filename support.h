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

/*
   extern "C" void __cxa_pure_virtual() { while(1); }
   void* __dso_handle = (void*) &__dso_handle;
   extern "C" void __cxa_guard_release() { }
   extern "C" void __cxa_guard_acquire() { }
 */
