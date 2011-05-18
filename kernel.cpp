#include "v8/include/v8.h"
extern "C" {
    #include "util.h"
}

using namespace v8;

int main(void) {
    clear();
    write("Like a boss\n");
    //HandleScope handle_scope;
    return 0;
}
