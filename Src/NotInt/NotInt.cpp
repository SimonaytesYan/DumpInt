#include "NotInt.h"

int NotInt::not_int_counter = 0;

//===============================CONSTRUCTORS===============================

NotInt::NotInt()
{
    NotInt::not_int_counter++;
    id    = not_int_counter;
    value = rand();
    printf("STD CTOR, value = %d id = %d\n", value, id);
}

NotInt::NotInt(int new_value)
{
    NotInt::not_int_counter++;
    id    = not_int_counter;
    value = new_value;
    printf("CTOR, value = %d id = %d\n", value, id);
}

NotInt::NotInt(const NotInt& other)
{
    NotInt::not_int_counter++;
    id    = not_int_counter;
    value = other.value;
    printf("CTOR(const NotInt&), value = %d id = %d\n", value, id);
}

//=================================ARITHMETIC===================================

NotInt& NotInt::operator++()
{
    value++;
    printf("operator++, value = %d id = %d\n", value, id);
    return *this;
}

NotInt& NotInt::operator--()
{
    value--;
    printf("operator++, value = %d id = %d\n", value, id);
    return *this;
}

NotInt NotInt::operator+()
{
    printf("operator+() id = %d\n", id);
    return *this;
}

NotInt NotInt::operator-()
{
    printf("operator-() id = %d\n", id);
    return -value;
}

NotInt NotInt::operator~()
{
    printf("operator~() id = %d\n", id);
    return ~value;
}

NotInt NotInt::operator+(const NotInt& other)
{
    printf("operator+(const NotInt&) id = %d\n", id);
    return value + other.value;
}
    
NotInt NotInt::operator-(const NotInt& other)
{
    printf("operator-(const NotInt&) id = %d\n", id);
    return value - other.value;
}

NotInt NotInt::operator/(const NotInt& other)
{
    printf("operator/(const NotInt&) id = %d\n", id);
    return value / other.value;
}

NotInt NotInt::operator*(const NotInt& other)
{
    printf("operator*(const NotInt&) id = %d\n", id);
    return value * other.value;
}

NotInt NotInt::operator%(const NotInt& other)
{
    printf("operator%(const NotInt&) id = %d\n", id);
    return value % other.value;
}

NotInt NotInt::operator&(const NotInt& other)
{
    printf("operator&(const NotInt&) id = %d\n", id);
    return value & other.value;
}

NotInt NotInt::operator|(const NotInt& other)
{
    printf("operator|(const NotInt&) id = %d\n", id);
    return value | other.value;
}

NotInt NotInt::operator^(const NotInt& other)
{
    printf("operator^(const NotInt&) id = %d\n", id);
    return value ^ other.value;
}

NotInt NotInt::operator<<(const NotInt& other)
{
    printf("operator<<(const NotInt&) id = %d\n", id);
    return value << other.value;
}

NotInt NotInt::operator>>(const NotInt& other)
{
    printf("operator>>(const NotInt&) id = %d\n", id);
    return value >> other.value;
}

//=====================================LOGICAL==================================

bool NotInt::operator||(const NotInt& other)
{
    printf("operator||(const NotInt& id = %d\n", id);
    return value || other.value;;
}

bool NotInt::operator&&(const NotInt& other)
{
    printf("operator||(const NotInt& id = %d\n", id);
    return value && other.value;;
}

bool NotInt::operator!()
{
    printf("operator!(const NotInt& id = %d\n", id);
    return !value;
}

//====================================COMPARISON================================

bool NotInt::operator==(const NotInt& other)
{
    printf("operator==(const NotInt& id = %d\n", id);
    return value == other.value;
}

bool NotInt::operator!=(const NotInt& other)
{
    printf("operator==(const NotInt& id = %d\n", id);
    return value != other.value;
}

bool NotInt::operator<(const NotInt& other)
{
    printf("operator<(const NotInt& id = %d\n", id);
    return value < other.value;
}
    
bool NotInt::operator>(const NotInt& other)
{
    printf("operator>(const NotInt& id = %d\n", id);
    return value > other.value;
}

bool NotInt::operator<=(const NotInt& other)
{
    printf("operator<=(const NotInt& id = %d\n", id);
    return value <= other.value;
}

bool NotInt::operator>=(const NotInt& other)
{
    printf("operator>=(const NotInt& id = %d\n", id);
    return value >= other.value;
}

    //=================================ASSIGNMENT===============================

NotInt& NotInt::operator=(int new_value)
{
    value = new_value;
    printf("operator= int, value = %d id = %d\n", value, id);
    return *this;
}

NotInt& NotInt::operator=(const NotInt& other)
{
    value = other.value;
    printf("operator= const NotInt&, value = %d id = %d\n", value, id);
    return *this;
}

NotInt& NotInt::operator+=(const NotInt& other)
{
    value += other.value;
    printf("operator+=(const NotInt&, value = %d id = %d\n", value, id);
    return *this;
}

NotInt& NotInt::operator-=(const NotInt& other)
{
    value -= other.value;
    printf("operator-=(const NotInt&, value = %d id = %d\n", value, id);
    return *this;
}

NotInt& NotInt::operator/=(const NotInt& other)
{
    value /= other.value;
    printf("operator/=(const NotInt&, value = %d id = %d\n", value, id);
    return *this;
}

NotInt& NotInt::operator%=(const NotInt& other)
{
    value %= other.value;
    printf("operator%=(const NotInt&, value = %d id = %d\n", value, id);
    return *this;
}

NotInt& NotInt::operator*=(const NotInt& other)
{
    value *= other.value;
    printf("operator*=(const NotInt&, value = %d id = %d\n", value, id);
    return *this;
}

NotInt& NotInt::operator&=(const NotInt& other)
{
    value &= other.value;
    printf("operator&=(const NotInt&, value = %d id = %d\n", value, id);
    return *this;
}

NotInt& NotInt::operator|=(const NotInt& other)
{
    value |= other.value;
    printf("operator|=(const NotInt&, value = %d id = %d\n", value, id);
    return *this;
}

NotInt& NotInt::operator^=(const NotInt& other)
{
    value ^= other.value;
    printf("operator^=(const NotInt&, value = %d id = %d\n", value, id);
    return *this;
}

NotInt& NotInt::operator>>=(const NotInt& other)
{
    value >>= other.value;
    printf("operator>>=(const NotInt&, value = %d id = %d\n", value, id);
    return *this;
}

NotInt& NotInt::operator<<=(const NotInt& other)
{
    value <<= other.value;
    printf("operator<<=(const NotInt&, value = %d id = %d\n", value, id);
    return *this;
}

    //===================================OTHER==================================

NotInt& NotInt::operator[](const NotInt& index)
{
    printf("operator[%d](const NotInt&, value = %d id = %d\n", index.value, value, id);
    return *this;
}

NotInt& NotInt::operator()()
{
    printf("operator()(const NotInt&, value = %d id = %d\n", value, id);
    return *this;
}

NotInt& NotInt::operator->()
{
    printf("operator->(const NotInt&, value = %d id = %d\n", value, id);
    return *this;
}

NotInt& NotInt::operator*()
{
    printf("operator*(const NotInt&, value = %d id = %d\n", value, id);
    return *this;
}

NotInt::~NotInt()
{
    printf("STD DTOR, value = %d id = %d\n", value, id);
}
