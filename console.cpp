#include "console.h"
#include "utility.h"

Console::Console() {
    pos = 0;
    line = 0;
    videomem = (unsigned short*) 0xb8000;
}

Console::~Console() {
}

void Console::clear() {
    unsigned int i;
    for (i = 0; i < (80 * 25); i++) {
        videomem[i] = (unsigned char) ' ' | 0x0700;
    }
    pos = 0;
    line = 0;
}

void Console::write(char *cp) {
    char *str = cp, *ch;

    for (ch = str; *ch; ch++) {
        if (*ch == 10) {
            nl();
        } else {
            put(*ch);
        }
    }
}

void Console::writeInt(int num) {
    int i, n, neg_flag;
    char buf[12];

    neg_flag = num < 0;
    if (neg_flag)
        num = ~num + 1;

    Utility::itoa(num, buf);

    n = Utility::strlen(buf);
    if (neg_flag)
        put('-');
    for (i = 0; i < n; i++)
        put(buf[i]);
}

void Console::put(char c) {
    if (pos >= 80) {
        pos = 0;
        line++;
    }

    if (line >= 25) {
        clear();
    }

    videomem[(80 * line) + pos] = (unsigned char) c | 0x0700;
    pos++;
}

void Console::nl() {
    pos = 0;
    line++;
}
