#include "Koin.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/

Koin::Koin(double value) : value(value), next(nullptr), softForked(false) {}

Koin::Koin(const Koin& rhs) : value(rhs.value), next(rhs.next), softForked(false) {}

Koin& Koin::operator=(const Koin& rhs) {
    if (this == &rhs)
        return *this;
    value = rhs.value;
    next = rhs.next;
    softForked = false;
    return *this;
}

Koin::~Koin() {}

double Koin::getValue() const {
    return value;
}

Koin* Koin::getNext() const {
    return next;
}

void Koin::setNext(Koin *next) {
    this -> next = next;
}

bool Koin::getSoftForked() const {
    return softForked;
}

void Koin::setSoftForked(bool p) {
    softForked = p;
}

bool Koin::operator==(const Koin& rhs) const {
    if (this == &rhs)
        return true;
    const Koin* temp_this(this);
    const Koin* temp_rhs(&rhs);
    while (temp_this != nullptr && temp_rhs != nullptr &&
          (temp_this -> getValue() + Utilizer::doubleSensitivity() >= temp_rhs -> getValue()
        && temp_this -> getValue() - Utilizer::doubleSensitivity() <= temp_rhs -> getValue())) {
        temp_this = temp_this -> getNext();
        temp_rhs = temp_rhs -> getNext(); 
    }
    if (temp_this == nullptr && temp_rhs == nullptr)
        return true;
    return false;
}

bool Koin::operator!=(const Koin& rhs) const {
    return !(*this == rhs);
}

Koin& Koin::operator*=(int multiplier) {
    value *= multiplier;
    return *this;
}

Koin& Koin::operator/=(int divisor) {
    value /= divisor;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Koin& koin) {
    os.precision(Utilizer::koinPrintPrecision());
    os << std::fixed;
    const  Koin* p(&koin);
    while (p != nullptr) {
        os << (p -> getValue()) << "--";
        p = p -> getNext();
    }
    os << "|";
    return os;
}
