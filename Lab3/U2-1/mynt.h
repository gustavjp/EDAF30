#ifndef MYNT_H
#define MYNT_H

enum Myntsida {krona, klave};

class Mynt
{
public:
    Mynt();
    void kasta();
    void visa();
    Myntsida uppsida();
private:
    Myntsida sida;
};

#endif // MYNT_H
