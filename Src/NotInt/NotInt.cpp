#include "NotInt.h"

int   NotInt::not_int_counter = 0;
FILE* NotInt::not_int_output          = nullptr;

const char* NodePrototype = "Node%d_%d[fillcolor = \"#B1FF9F\", label = \"<i> id: %d | <v> val: %d \"]\n";
const char* EdgePrototype = "Node%d_%d->Node%d_%d\n";
//===============================CONSTRUCTORS===============================

NotInt::NotInt()
{
    operation_count = 0;
    operation_count++;
    NotInt::not_int_counter++;
    id    = not_int_counter;
    value = rand();

    printf("STD CTOR, value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
}

NotInt::NotInt(int new_value)
{
    operation_count = 0;
    operation_count++;
    NotInt::not_int_counter++;
    id    = not_int_counter;
    value = new_value;
    printf("CTOR, value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
}

NotInt::NotInt(const NotInt& other)
{
    operation_count = 0;
    operation_count++;
    NotInt::not_int_counter++;
    id    = not_int_counter;
    value = other.value;
    printf("CTOR(const NotInt&), value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
}

//=================================ARITHMETIC===================================

NotInt& NotInt::operator++()
{
    operation_count++;
    value++;
    printf("operator++, value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return *this;
}

NotInt& NotInt::operator--()
{
    operation_count++;
    value--;
    printf("operator++, value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return *this;
}

NotInt NotInt::operator+()
{
    operation_count++;
    printf("operator+() id = %d\n", id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return *this;
}

NotInt NotInt::operator-()
{
    operation_count++;
    printf("operator-() id = %d\n", id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return -value;
}

NotInt NotInt::operator~()
{
    operation_count++;
    printf("operator~() id = %d\n", id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return ~value;
}

NotInt NotInt::operator+(const NotInt& other)
{
    operation_count++;
    printf("operator+(const NotInt&) id = %d\n", id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return value + other.value;
}
    
NotInt NotInt::operator-(const NotInt& other)
{
    operation_count++;
    printf("operator-(const NotInt&) id = %d\n", id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return value - other.value;
}

NotInt NotInt::operator/(const NotInt& other)
{
    operation_count++;
    printf("operator/(const NotInt&) id = %d\n", id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return value / other.value;
}

NotInt NotInt::operator*(const NotInt& other)
{
    operation_count++;
    printf("operator*(const NotInt&) id = %d\n", id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return value * other.value;
}

NotInt NotInt::operator%(const NotInt& other)
{
    operation_count++;
    printf("operator%(const NotInt&) id = %d\n", id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return value % other.value;
}

NotInt NotInt::operator&(const NotInt& other)
{
    operation_count++;
    printf("operator&(const NotInt&) id = %d\n", id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return value & other.value;
}

NotInt NotInt::operator|(const NotInt& other)
{
    operation_count++;
    printf("operator|(const NotInt&) id = %d\n", id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return value | other.value;
}

NotInt NotInt::operator^(const NotInt& other)
{
    operation_count++;
    printf("operator^(const NotInt&) id = %d\n", id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return value ^ other.value;
}

NotInt NotInt::operator<<(const NotInt& other)
{
    operation_count++;
    printf("operator<<(const NotInt&) id = %d\n", id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return value << other.value;
}

NotInt NotInt::operator>>(const NotInt& other)
{
    operation_count++;
    printf("operator>>(const NotInt&) id = %d\n", id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return value >> other.value;
}

//=====================================LOGICAL==================================

bool NotInt::operator||(const NotInt& other)
{
    operation_count++;
    printf("operator||(const NotInt& id = %d\n", id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return value || other.value;;
}

bool NotInt::operator&&(const NotInt& other)
{
    operation_count++;
    printf("operator||(const NotInt& id = %d\n", id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return value && other.value;;
}

bool NotInt::operator!()
{
    operation_count++;
    printf("operator!(const NotInt& id = %d\n", id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return !value;
}

//====================================COMPARISON================================

bool NotInt::operator==(const NotInt& other)
{
    operation_count++;
    printf("operator==(const NotInt& id = %d\n", id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return value == other.value;
}

bool NotInt::operator!=(const NotInt& other)
{
    operation_count++;
    printf("operator==(const NotInt& id = %d\n", id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return value != other.value;
}

bool NotInt::operator<(const NotInt& other)
{
    operation_count++;
    printf("operator<(const NotInt& id = %d\n", id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return value < other.value;
}
    
bool NotInt::operator>(const NotInt& other)
{
    operation_count++;
    printf("operator>(const NotInt& id = %d\n", id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return value > other.value;
}

bool NotInt::operator<=(const NotInt& other)
{
    operation_count++;
    printf("operator<=(const NotInt& id = %d\n", id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return value <= other.value;
}

bool NotInt::operator>=(const NotInt& other)
{
    operation_count++;
    printf("operator>=(const NotInt& id = %d\n", id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return value >= other.value;
}

    //=================================ASSIGNMENT===============================

NotInt& NotInt::operator=(int new_value)
{
    operation_count++;
    value = new_value;
    printf("operator= int, value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return *this;
}

NotInt& NotInt::operator=(const NotInt& other)
{
    operation_count++;
    value = other.value;
    printf("operator= const NotInt&, value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return *this;
}

NotInt& NotInt::operator+=(const NotInt& other)
{
    operation_count++;
    value += other.value;
    printf("operator+=(const NotInt&, value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return *this;
}

NotInt& NotInt::operator-=(const NotInt& other)
{
    operation_count++;
    value -= other.value;
    printf("operator-=(const NotInt&, value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return *this;
}

NotInt& NotInt::operator/=(const NotInt& other)
{
    operation_count++;
    value /= other.value;
    printf("operator/=(const NotInt&, value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return *this;
}

NotInt& NotInt::operator%=(const NotInt& other)
{
    operation_count++;
    value %= other.value;
    printf("operator%=(const NotInt&, value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return *this;
}

NotInt& NotInt::operator*=(const NotInt& other)
{
    operation_count++;
    value *= other.value;
    printf("operator*=(const NotInt&, value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return *this;
}

NotInt& NotInt::operator&=(const NotInt& other)
{
    operation_count++;
    value &= other.value;
    printf("operator&=(const NotInt&, value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return *this;
}

NotInt& NotInt::operator|=(const NotInt& other)
{
    operation_count++;
    value |= other.value;
    printf("operator|=(const NotInt&, value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return *this;
}

NotInt& NotInt::operator^=(const NotInt& other)
{
    operation_count++;
    value ^= other.value;
    printf("operator^=(const NotInt&, value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return *this;
}

NotInt& NotInt::operator>>=(const NotInt& other)
{
    operation_count++;
    value >>= other.value;
    printf("operator>>=(const NotInt&, value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return *this;
}

NotInt& NotInt::operator<<=(const NotInt& other)
{
    operation_count++;
    value <<= other.value;
    printf("operator<<=(const NotInt&, value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return *this;
}

    //===================================OTHER==================================

NotInt& NotInt::operator[](const NotInt& index)
{
    operation_count++;
    printf("operator[%d](const NotInt&, value = %d id = %d\n", index.value, value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return *this;
}

NotInt& NotInt::operator()()
{
    operation_count++;
    printf("operator()(const NotInt&, value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return *this;
}

NotInt& NotInt::operator->()
{
    operation_count++;
    printf("operator->(const NotInt&, value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return *this;
}

NotInt& NotInt::operator*()
{
    operation_count++;
    printf("operator*(const NotInt&, value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, id, value);
    return *this;
}

NotInt::~NotInt()
{
    operation_count++;
    printf("STD DTOR, value = %d id = %d\n", value, id);
}
