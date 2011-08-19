#include "util.h"

static unsigned short *videomem = (unsigned short*) 0xb8000;
static unsigned int line = 0;
static unsigned int pos = 0;

void clear() {
    int i;
    for (i = 0; i < (80 * 25); i++) {
        videomem[i] = (unsigned char) ' ' | 0x0700;
    }
    pos = 0;
    line = 0;
}

void write(char *cp) {
    char *str = cp, *ch;
    for (ch = str; *ch; ch++) {
        if (*ch == 10) {
            line++;
            pos = 0;
        } else {
            put(*ch);
        }
    }
}

void put(char c) {
    if (pos >= 80) {
        pos = 0;
        line++;
    }

    if (line >= 25) {
        scroll();
    }

    videomem[(80 * line) + pos] = (unsigned char) c | 0x0700;
    pos++;
}

void scroll() {
    int x, y;
    for (y = 0; y < 25; y++) {
        for (x = 0; x < 80; x++) {
            videomem[(y * 80) + x] = videomem[((y + 1) * 80) + x];
        }
    }
    line--;
}
