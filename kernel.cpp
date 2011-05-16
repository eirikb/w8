#include "console.h"
#include "operators.h"
#include "v8/include/v8.h"

using namespace v8;

int main(void) {
    HandleScope handle_scope;
    Console console;
    console.clear();
    console.write("Welcome to w8...\n");
}
