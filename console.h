#ifndef CONSOLE_H
#define CONSOLE_H

class Console {
    public:
        Console();
        ~Console();
        void clear();
        void write(char *cp);
        void writeInt(int num);
        void put(char c);
        void scroll();
        void nl();
    private:
        unsigned short *videomem;
        unsigned int line;
        unsigned int pos;
};

#endif
