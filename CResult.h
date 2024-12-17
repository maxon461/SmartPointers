#ifndef CRESULT_H
#define CRESULT_H

#include <vector>
#include <stdexcept>
#include "CError.h"

using namespace std;

template <typename T, typename E>
class CResult {
public:
    CResult(const T& cValue);

    CResult(E* pcError);

    CResult(vector<E*>& vErrors);

    CResult(const CResult<T, E>& cOther);

    ~CResult();

    static CResult<T, E> cOk(const T& cValue);
    static CResult<T, E> cFail(E* pcError);
    static CResult<T, E> cFail(vector<E*>& vErrors);

    CResult<T, E>& operator=(const CResult<T, E>& cOther);

    bool bIsSuccess() const;

    T cGetValue() const;

    const vector<E*>& vGetErrors() const;

private:
    T *pc_value;
    vector<E*> v_errors;
};

template <typename E>
class CResult<void, E> {
public:
    CResult();

    CResult(E* pcError);

    CResult(vector<E*>& vErrors);

    CResult(const CResult<void, E>& cOther);

    ~CResult();

    static CResult<void, E> cOk();
    static CResult<void, E> cFail(E* pcError);
    static CResult<void, E> cFail(vector<E*>& vErrors);

    CResult<void, E>& operator=(const CResult<void, E>& cOther);

    bool bIsSuccess() const;

    const vector<E*>& vGetErrors() const;

private:
    vector<E*> v_errors;
};

#include "CResult.tpp"

#endif // CRESULT_H