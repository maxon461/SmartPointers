#ifndef CRESULT_TPP
#define CRESULT_TPP

#include "CResult.h"

template <typename T, typename E>
CResult<T, E>::CResult(const T& cValue) : pc_value(new T(cValue)), v_errors() {}

template <typename T, typename E>
CResult<T, E>::CResult(E* pcError) : pc_value(nullptr) {
    v_errors.push_back(pcError);
}

template <typename T, typename E>
CResult<T, E>::CResult(vector<E*>& vErrors) : pc_value(nullptr), v_errors(vErrors) {}

template <typename T, typename E>
CResult<T, E>::CResult(const CResult<T, E>& cOther) {
    pc_value = cOther.pc_value ? new T(*cOther.pc_value) : nullptr;

    for(auto error : cOther.v_errors) {
        v_errors.push_back(new E(*error));
    }
}

template <typename T, typename E>
CResult<T, E>::~CResult() {
    delete pc_value;

    for(auto error : v_errors) {
        delete error;
    }
}

template <typename T, typename E>
CResult<T, E> CResult<T, E>::cOk(const T& cValue) {
    return CResult(cValue);
}

template <typename T, typename E>
CResult<T, E> CResult<T, E>::cFail(E* pcError) {
    return CResult(pcError);
}

template <typename T, typename E>
CResult<T, E> CResult<T, E>::cFail(vector<E*>& vErrors) {
    return CResult(vErrors);
}

template <typename T, typename E>
CResult<T, E>& CResult<T, E>::operator=(const CResult<T, E>& cOther) {
    if (this != &cOther) {
        delete pc_value;
        for(auto error : v_errors) {
            delete error;
        }
        v_errors.clear();

        pc_value = cOther.pc_value ? new T(*cOther.pc_value) : nullptr;

        for(auto error : cOther.v_errors) {
            v_errors.push_back(new E(*error));
        }
    }
    return *this;
}

template <typename T, typename E>
bool CResult<T, E>::bIsSuccess() const {
    return v_errors.empty();
}

template <typename T, typename E>
T CResult<T, E>::cGetValue()  const{
    if (!bIsSuccess()) {
        throw runtime_error("Cannot get value - operation failed");
    }
    return *pc_value;
}

template <typename T, typename E>
const vector<E*>& CResult<T, E>::vGetErrors() const{
    return v_errors;
}


template <typename E>
CResult<void, E>::CResult() {}

template <typename E>
CResult<void, E>::CResult(E* pcError) {
    v_errors.push_back(pcError);
}

template <typename E>
CResult<void, E>::CResult(vector<E*>& vErrors) : v_errors(vErrors) {}

template <typename E>
CResult<void, E>::CResult(const CResult<void, E>& cOther) {
    for(auto error : cOther.v_errors) {
        v_errors.push_back(new E(*error));
    }
}

template <typename E>
CResult<void, E>::~CResult() {
    for(auto error : v_errors) {
        delete error;
    }
}

template <typename E>
CResult<void, E> CResult<void, E>::cOk() {
    return CResult();
}

template <typename E>
CResult<void, E> CResult<void, E>::cFail(E* pcError) {
    return CResult(pcError);
}

template <typename E>
CResult<void, E> CResult<void, E>::cFail(vector<E*>& vErrors) {
    return CResult(vErrors);
}

template <typename E>
CResult<void, E>& CResult<void, E>::operator=(const CResult<void, E>& cOther) {
    if (this != &cOther) {
        for(auto error : v_errors) {
            delete error;
        }
        v_errors.clear();

        for(auto error : cOther.v_errors) {
            v_errors.push_back(new E(*error));
        }
    }
    return *this;
}

template <typename E>
bool CResult<void, E>::bIsSuccess() const {
    return v_errors.empty();
}

template <typename E>
const vector<E*>& CResult<void, E>::vGetErrors() const {
    return v_errors;
}

#endif