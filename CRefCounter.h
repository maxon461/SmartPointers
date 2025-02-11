// CRefCounter.h
#ifndef CREFCOUNTER_H
#define CREFCOUNTER_H

class CRefCounter {
public:
    CRefCounter() : i_count(0) {}
    int iAdd() { return(++i_count); }
    int iDec() { return(--i_count); }
    int iGet() { return(i_count); }
private:
    int i_count;
};

#endif