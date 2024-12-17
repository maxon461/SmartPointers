#ifndef CERROR_H
#define CERROR_H

#include <string>

using namespace std;

class CError {
public:
    CError(const string& description);

    string getDescription() const;

private:
    string m_description;
};

#endif // CERROR_H