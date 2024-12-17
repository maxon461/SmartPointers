// CSmartPointer.h
#ifndef CSMARTPOINTER_H
#define CSMARTPOINTER_H

#include "CRefCounter.h"

template <typename T>
class CSmartPointer {
public:
    CSmartPointer(T* pcPointer = nullptr) {
        pc_pointer = pcPointer;
        pc_counter = new CRefCounter();
        pc_counter->iAdd();
    }

    CSmartPointer(const CSmartPointer<T>& pcOther) {
        pc_pointer = pcOther.pc_pointer;
        pc_counter = pcOther.pc_counter;
        pc_counter->iAdd();
    }

    CSmartPointer<T>& operator=(const CSmartPointer<T>& pcOther) {
        if (this != &pcOther) {
            if (pc_counter->iDec() == 0) {
                delete pc_pointer;
                delete pc_counter;
            }

            pc_pointer = pcOther.pc_pointer;
            pc_counter = pcOther.pc_counter;
            pc_counter->iAdd();
        }
        return *this;
    }

    ~CSmartPointer() {
        if (pc_counter->iDec() == 0) {
            delete pc_pointer;
            delete pc_counter;
        }
    }

    T& operator*() { return(*pc_pointer); }
    T* operator->() { return(pc_pointer); }

private:
    CRefCounter* pc_counter;
    T* pc_pointer;
};

#endif