#ifndef VIDEO_H
#define VIDEO_H

class Console
{
    public:
        Console();
        ~Console();
        void clear();
        void write(char *cp);
        void put(char c);
        void nl();
    private:
        unsigned short *videomem;
        unsigned int line;
        unsigned int pos;
};

#endif
