#ifndef SYM_NOT_INT
#define SYM_NOT_INT

#include <stdio.h>
#include <stdlib.h>

class NotInt
{
    public :
    int value;

    //===============================CONSTRUCTORS===============================

    NotInt()
    {
        value = rand();
        printf("STD CTOR, value = %d\n", value);
    }

    NotInt(int new_value)
    {
        value = new_value;
        printf("CTOR, value = %d\n", value);
    }

    NotInt(const NotInt& other)
    {
        value = other.value;
        printf("CTOR(const NotInt&), value = %d\n", value);
    }

    //===============================ARITHMETIC=================================

    NotInt& operator++()
    {
        value++;
        printf("operator++, value = %d\n", value);
        return *this;
    }

    NotInt& operator--()
    {
        value--;
        printf("operator++, value = %d\n", value);
        return *this;
    }

    NotInt operator+()
    {
        printf("operator+()\n");
        return *this;
    }

    NotInt operator-()
    {
        printf("operator-()\n");
        return -value;
    }

    NotInt operator~()
    {
        printf("operator~()\n");
        return ~value;
    }

    NotInt operator+(const NotInt& other)
    {
        printf("operator+(const NotInt&)\n");
        return value + other.value;
    }
    
    NotInt operator-(const NotInt& other)
    {
        printf("operator-(const NotInt&)\n");
        return value - other.value;
    }

    NotInt operator/(const NotInt& other)
    {
        printf("operator/(const NotInt&)\n");
        return value / other.value;
    }

    NotInt operator*(const NotInt& other)
    {
        printf("operator*(const NotInt&)\n");
        return value * other.value;
    }

    NotInt operator%(const NotInt& other)
    {
        printf("operator%(const NotInt&)\n");
        return value % other.value;
    }

    NotInt operator&(const NotInt& other)
    {
        printf("operator&(const NotInt&)\n");
        return value & other.value;
    }

    NotInt operator|(const NotInt& other)
    {
        printf("operator|(const NotInt&)\n");
        return value | other.value;
    }

    NotInt operator^(const NotInt& other)
    {
        printf("operator^(const NotInt&)\n");
        return value ^ other.value;
    }

    NotInt operator<<(const NotInt& other)
    {
        printf("operator<<(const NotInt&)\n");
        return value << other.value;
    }

    NotInt operator>>(const NotInt& other)
    {
        printf("operator>>(const NotInt&)\n");
        return value >> other.value;
    }

    //==================================LOGICAL=================================

    bool operator||(const NotInt& other)
    {
        printf("operator||(const NotInt&\n");
        return value || other.value;;
    }

    bool operator&&(const NotInt& other)
    {
        printf("operator||(const NotInt&\n");
        return value && other.value;;
    }

    bool operator!()
    {
        printf("operator!(const NotInt&\n");
        return !value;
    }

    //=================================COMPARISON===============================

    bool operator==(const NotInt& other)
    {
        printf("operator==(const NotInt&\n");
        return value == other.value;
    }

    bool operator!=(const NotInt& other)
    {
        printf("operator==(const NotInt&\n");
        return value != other.value;
    }

    bool operator<(const NotInt& other)
    {
        printf("operator<(const NotInt&\n");
        return value < other.value;
    }
    
    bool operator>(const NotInt& other)
    {
        printf("operator>(const NotInt&\n");
        return value > other.value;
    }

    bool operator<=(const NotInt& other)
    {
        printf("operator<=(const NotInt&\n");
        return value <= other.value;
    }

    bool operator>=(const NotInt& other)
    {
        printf("operator>=(const NotInt&\n");
        return value >= other.value;
    }

    //=================================ASSIGNMENT===============================

    NotInt& operator=(int new_value)
    {
        value = new_value;
        printf("operator= int, value = %d\n", value);
        return *this;
    }

    NotInt& operator=(const NotInt& other)
    {
        value = other.value;

        printf("operator= const NotInt&, value = %d\n", value);
        return *this;
    }

    NotInt& operator+=(const NotInt& other)
    {
        value += other.value;
        printf("operator+=(const NotInt&, value = %d\n", value);
        return *this;
    }

    NotInt& operator-=(const NotInt& other)
    {
        value -= other.value;
        printf("operator-=(const NotInt&, value = %d\n", value);
        return *this;
    }

    NotInt& operator/=(const NotInt& other)
    {
        value /= other.value;
        printf("operator/=(const NotInt&, value = %d\n", value);
        return *this;
    }

    NotInt& operator%=(const NotInt& other)
    {
        value %= other.value;
        printf("operator%=(const NotInt&, value = %d\n", value);
        return *this;
    }

    NotInt& operator*=(const NotInt& other)
    {
        value *= other.value;
        printf("operator*=(const NotInt&, value = %d\n", value);
        return *this;
    }

    NotInt& operator&=(const NotInt& other)
    {
        value &= other.value;
        printf("operator&=(const NotInt&, value = %d\n", value);
        return *this;
    }

    NotInt& operator|=(const NotInt& other)
    {
        value |= other.value;
        printf("operator|=(const NotInt&, value = %d\n", value);
        return *this;
    }

    NotInt& operator^=(const NotInt& other)
    {
        value ^= other.value;
        printf("operator^=(const NotInt&, value = %d\n", value);
        return *this;
    }

    NotInt& operator>>=(const NotInt& other)
    {
        value >>= other.value;
        printf("operator>>=(const NotInt&, value = %d\n", value);
        return *this;
    }

    NotInt& operator<<=(const NotInt& other)
    {
        value <<= other.value;
        printf("operator<<=(const NotInt&, value = %d\n", value);
        return *this;
    }

    //===================================OTHER==================================

    NotInt& operator[](const NotInt& index)
    {
        printf("operator[%d](const NotInt&, value = %d\n", index.value, value);
        return *this;
    }

    NotInt& operator()()
    {
        printf("operator()(const NotInt&, value = %d\n", value);
        return *this;
    }

    NotInt& operator->()
    {
        printf("operator()(const NotInt&, value = %d\n", value);
        return *this;
    }

    ~NotInt()
    {
        printf("STD DTOR, value = %d\n", value);
    }
};

#endif //SYM_NOT_INT