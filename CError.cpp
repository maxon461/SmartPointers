#include "CError.h"

CError::CError(const string& description) : m_description(description) {}

string CError::getDescription() const {
    return m_description;
}