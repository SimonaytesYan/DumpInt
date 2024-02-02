#include "NotInt.h"

//===============================CONSTRUCTORS===============================

NotInt::NotInt()
{
    value = rand();
    printf("STD CTOR, value = %d\n", value);
}

NotInt::NotInt(int new_value)
{
    value = new_value;
    printf("CTOR, value = %d\n", value);
}

NotInt::NotInt(const NotInt& other)
{
    value = other.value;
    printf("CTOR(const NotInt&), value = %d\n", value);
}

//=================================ARITHMETIC===================================

NotInt& NotInt::operator++()
{
    value++;
    printf("operator++, value = %d\n", value);
    return *this;
}

NotInt& NotInt::operator--()
{
    value--;
    printf("operator++, value = %d\n", value);
    return *this;
}

NotInt NotInt::operator+()
{
    printf("operator+()\n");
    return *this;
}

NotInt NotInt::operator-()
{
    printf("operator-()\n");
    return -value;
}

NotInt NotInt::operator~()
{
    printf("operator~()\n");
    return ~value;
}

NotInt NotInt::operator+(const NotInt& other)
{
    printf("operator+(const NotInt&)\n");
    return value + other.value;
}
    
NotInt NotInt::operator-(const NotInt& other)
{
    printf("operator-(const NotInt&)\n");
    return value - other.value;
}

NotInt NotInt::operator/(const NotInt& other)
{
    printf("operator/(const NotInt&)\n");
    return value / other.value;
}

NotInt NotInt::operator*(const NotInt& other)
{
    printf("operator*(const NotInt&)\n");
    return value * other.value;
}

NotInt NotInt::operator%(const NotInt& other)
{
    printf("operator%(const NotInt&)\n");
    return value % other.value;
}

NotInt NotInt::operator&(const NotInt& other)
{
    printf("operator&(const NotInt&)\n");
    return value & other.value;
}

NotInt NotInt::operator|(const NotInt& other)
{
    printf("operator|(const NotInt&)\n");
    return value | other.value;
}

NotInt NotInt::operator^(const NotInt& other)
{
    printf("operator^(const NotInt&)\n");
    return value ^ other.value;
}

NotInt NotInt::operator<<(const NotInt& other)
{
    printf("operator<<(const NotInt&)\n");
    return value << other.value;
}

NotInt NotInt::operator>>(const NotInt& other)
{
    printf("operator>>(const NotInt&)\n");
    return value >> other.value;
}

//=====================================LOGICAL==================================

bool NotInt::operator||(const NotInt& other)
{
    printf("operator||(const NotInt&\n");
    return value || other.value;;
}

bool NotInt::operator&&(const NotInt& other)
{
    printf("operator||(const NotInt&\n");
    return value && other.value;;
}

bool NotInt::operator!()
{
    printf("operator!(const NotInt&\n");
    return !value;
}

//====================================COMPARISON================================

bool NotInt::operator==(const NotInt& other)
{
    printf("operator==(const NotInt&\n");
    return value == other.value;
}

bool NotInt::operator!=(const NotInt& other)
{
    printf("operator==(const NotInt&\n");
    return value != other.value;
}

bool NotInt::operator<(const NotInt& other)
{
    printf("operator<(const NotInt&\n");
    return value < other.value;
}
    
bool NotInt::operator>(const NotInt& other)
{
    printf("operator>(const NotInt&\n");
    return value > other.value;
}

bool NotInt::operator<=(const NotInt& other)
{
    printf("operator<=(const NotInt&\n");
    return value <= other.value;
}

bool NotInt::operator>=(const NotInt& other)
{
    printf("operator>=(const NotInt&\n");
    return value >= other.value;
}

    //=================================ASSIGNMENT===============================

NotInt& NotInt::operator=(int new_value)
{
    value = new_value;
    printf("operator= int, value = %d\n", value);
    return *this;
}

NotInt& NotInt::operator=(const NotInt& other)
{
    value = other.value;
    printf("operator= const NotInt&, value = %d\n", value);
    return *this;
}

NotInt& NotInt::operator+=(const NotInt& other)
{
    value += other.value;
    printf("operator+=(const NotInt&, value = %d\n", value);
    return *this;
}

NotInt& NotInt::operator-=(const NotInt& other)
{
    value -= other.value;
    printf("operator-=(const NotInt&, value = %d\n", value);
    return *this;
}

NotInt& NotInt::operator/=(const NotInt& other)
{
    value /= other.value;
    printf("operator/=(const NotInt&, value = %d\n", value);
    return *this;
}

NotInt& NotInt::operator%=(const NotInt& other)
{
    value %= other.value;
    printf("operator%=(const NotInt&, value = %d\n", value);
    return *this;
}

NotInt& NotInt::operator*=(const NotInt& other)
{
    value *= other.value;
    printf("operator*=(const NotInt&, value = %d\n", value);
    return *this;
}

NotInt& NotInt::operator&=(const NotInt& other)
{
    value &= other.value;
    printf("operator&=(const NotInt&, value = %d\n", value);
    return *this;
}

NotInt& NotInt::operator|=(const NotInt& other)
{
    value |= other.value;
    printf("operator|=(const NotInt&, value = %d\n", value);
    return *this;
}

NotInt& NotInt::operator^=(const NotInt& other)
{
    value ^= other.value;
    printf("operator^=(const NotInt&, value = %d\n", value);
    return *this;
}

NotInt& NotInt::operator>>=(const NotInt& other)
{
    value >>= other.value;
    printf("operator>>=(const NotInt&, value = %d\n", value);
    return *this;
}

NotInt& NotInt::operator<<=(const NotInt& other)
{
    value <<= other.value;
    printf("operator<<=(const NotInt&, value = %d\n", value);
    return *this;
}

    //===================================OTHER==================================

NotInt& NotInt::operator[](const NotInt& index)
{
    printf("operator[%d](const NotInt&, value = %d\n", index.value, value);
    return *this;
}

NotInt& NotInt::operator()()
{
    printf("operator()(const NotInt&, value = %d\n", value);
    return *this;
}

NotInt& NotInt::operator->()
{
    printf("operator()(const NotInt&, value = %d\n", value);
    return *this;
}

NotInt::~NotInt()
{
    printf("STD DTOR, value = %d\n", value);
}
