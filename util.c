#include "util.h"

static unsigned short *videomem = (unsigned short*) 0xb8000;
static unsigned int line = 0;
static unsigned int pos = 0;

int strlen(char *s) {
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}

void reverse(char *s) {
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(unsigned int n, char *s) {
    int i;

    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    s[i++] = 0;
    reverse(s);
}

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
            nl();
        } else {
            put(*ch);
        }
    }
}

void writeInt(int num) {
    int i, n, neg_flag;
    char buf[12];

    neg_flag = num < 0;
    if (neg_flag)
        num = ~num + 1;

    itoa(num, buf);

    n = strlen(buf);
    if (neg_flag)
        put('-');
    for (i = 0; i < n; i++)
        put(buf[i]);
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

void nl() {
    pos = 0;
    line++;
}
