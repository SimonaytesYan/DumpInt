#include "NotInt.h"

int   NotInt::not_int_counter   = 0;
int   NotInt::bin_operation_cnt = 0;
FILE* NotInt::not_int_output    = nullptr;

const char* green_color = "#44FF44";
const char* blue_color  = "#4444FF";
const char* red_color   = "#FF4444";

const char* NodePrototype          = "Node%d_%d[fillcolor = \"%s\", label = \"<i> id: %d | <v> val: %d \"]\n";
const char* OperationNodePrototype = "Node%d_%d[label = \"%s\", shape = oval]\n";
const char* EdgePrototype          = "Node%d_%d->Node%d_%d\n";

const char* EdgeBinPrototype   = "Node%d_%d->NodeBin%d\n";
const char* BinEdgePrototype   = "NodeBin%d->Node%d_%d\n";
const char* BinOpNodePrototype = "NodeBin%d[label = \"%s\", shape = oval]\n";

#define ADD_BINARY_OPER_NODE(operation)                                                                             \
    NotInt::bin_operation_cnt++;                                                                                    \
    fprintf(NotInt::not_int_output, BinOpNodePrototype, bin_operation_cnt, operation);                              \
                                                                                                                    \
    fprintf(NotInt::not_int_output, EdgeBinPrototype, id,       operation_count,       bin_operation_cnt);          \
    fprintf(NotInt::not_int_output, EdgeBinPrototype, other.id, other.operation_count, bin_operation_cnt);          \
    fprintf(NotInt::not_int_output, BinEdgePrototype, bin_operation_cnt, not_int_counter + 1, 1);


#define ADD_OPERATION_NODE(operation)                                                               \
    fprintf(NotInt::not_int_output, OperationNodePrototype, id, operation_count, operation);        \
    fprintf(NotInt::not_int_output, EdgePrototype, id, operation_count - 1, id, operation_count);   \
    fprintf(NotInt::not_int_output, NodePrototype, id, ++operation_count, color, id, value);        \
    fprintf(NotInt::not_int_output, EdgePrototype, id, operation_count - 1, id, operation_count);   

//const char* EdgePrototype = "Node%d_%d->Node%d_%d[label=\"%s\"]\n"
// fprintf(NotInt::not_int_output, EdgePrototype, id, operation_count - 1, id, operation_count);

//===============================CONSTRUCTORS===============================

NotInt::NotInt()
{
    color = blue_color;
    operation_count = 0;
    operation_count++;
    NotInt::not_int_counter++;
    id    = not_int_counter;
    value = rand();

    printf("STD CTOR, value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, color, id, value);
}

NotInt::NotInt(int new_value)
{
    color = blue_color;
    operation_count = 0;
    operation_count++;
    NotInt::not_int_counter++;
    id    = not_int_counter;
    value = new_value;

    printf("CTOR, value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, NodePrototype, id, operation_count, color, id, value);

    char ctor_name[30] = {};
    sprintf(ctor_name, "ctor(%d)", new_value);

    fprintf(NotInt::not_int_output, OperationNodePrototype, id, operation_count - 1, ctor_name);
    fprintf(NotInt::not_int_output, EdgePrototype, id, operation_count - 1, id, operation_count);
}

NotInt::NotInt(const NotInt& other)
{
    color = red_color;
    operation_count = 0;
    operation_count++;
    NotInt::not_int_counter++;
    id    = not_int_counter;
    value = other.value;

    printf("CTOR(const NotInt&), value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, OperationNodePrototype, id, operation_count, "ctor(NotInt&)");
    fprintf(NotInt::not_int_output, EdgePrototype, other.id, other.operation_count, id, operation_count);

    fprintf(NotInt::not_int_output, NodePrototype, id, ++operation_count, color, id, value);
    fprintf(NotInt::not_int_output, EdgePrototype, id, operation_count - 1, id, operation_count);
}

NotInt::NotInt(NotInt&& other)
{
    color = green_color;
    operation_count = 0;
    operation_count++;
    NotInt::not_int_counter++;
    id    = not_int_counter;
    value = other.value;

    printf("CTOR(const NotInt&), value = %d id = %d\n", value, id);
    fprintf(NotInt::not_int_output, OperationNodePrototype, id, operation_count, "ctor(NotInt&&)");
    fprintf(NotInt::not_int_output, EdgePrototype, other.id, other.operation_count, id, operation_count);

    fprintf(NotInt::not_int_output, NodePrototype, id, ++operation_count, color, id, value);
    fprintf(NotInt::not_int_output, EdgePrototype, id, operation_count - 1, id, operation_count);
}

//=================================ARITHMETIC===================================

NotInt& NotInt::operator++()
{
    operation_count++;
    value++;
    printf("operator++, value = %d id = %d\n", value, id);
    ADD_OPERATION_NODE("++");
    return *this;
}

NotInt& NotInt::operator--()
{
    operation_count++;
    value--;
    printf("operator++, value = %d id = %d\n", value, id);
    ADD_OPERATION_NODE("--");
    return *this;
}

NotInt NotInt::operator+()
{
    operation_count++;
    printf("operator+() id = %d\n", id);
    ADD_OPERATION_NODE("+()");
    return *this;
}

NotInt NotInt::operator-()
{
    operation_count++;
    printf("operator-() id = %d\n", id);
    ADD_OPERATION_NODE("-()");
    return -value;
}

NotInt NotInt::operator~()
{
    operation_count++;
    printf("operator~() id = %d\n", id);
    ADD_OPERATION_NODE("~");
    return ~value;
}

NotInt NotInt::operator+(const NotInt& other)
{
    operation_count++;
    printf("operator+(const NotInt&) id = %d\n", id);

    ADD_OPERATION_NODE("+other");
    ADD_BINARY_OPER_NODE("+");
    
    return value + other.value;
}
    
NotInt NotInt::operator-(const NotInt& other)
{
    operation_count++;
    printf("operator-(const NotInt&) id = %d\n", id);
    ADD_OPERATION_NODE("-(other)");
    ADD_BINARY_OPER_NODE("-");
    return value - other.value;
}

NotInt NotInt::operator/(const NotInt& other)
{
    operation_count++;
    printf("operator/(const NotInt&) id = %d\n", id);
    ADD_OPERATION_NODE("/(other)");
    ADD_BINARY_OPER_NODE("/");
    return value / other.value;
}

NotInt NotInt::operator*(const NotInt& other)
{
    operation_count++;
    printf("operator*(const NotInt&) id = %d\n", id);
    ADD_OPERATION_NODE("*(other)");
    ADD_BINARY_OPER_NODE("*");
    return value * other.value;
}

NotInt NotInt::operator%(const NotInt& other)
{
    operation_count++;
    printf("operator%(const NotInt&) id = %d\n", id);
    ADD_OPERATION_NODE("%(other)");
    ADD_BINARY_OPER_NODE("%s");
    return value % other.value;
}

NotInt NotInt::operator&(const NotInt& other)
{
    operation_count++;
    printf("operator&(const NotInt&) id = %d\n", id);
    ADD_OPERATION_NODE("&(other)");
    ADD_BINARY_OPER_NODE("&");
    return value & other.value;
}

NotInt NotInt::operator|(const NotInt& other)
{
    operation_count++;
    printf("operator|(const NotInt&) id = %d\n", id);
    ADD_OPERATION_NODE("|(other)");
    ADD_BINARY_OPER_NODE("|");
    return value | other.value;
}

NotInt NotInt::operator^(const NotInt& other)
{
    operation_count++;
    printf("operator^(const NotInt&) id = %d\n", id);
    ADD_OPERATION_NODE("^(other)");
    ADD_BINARY_OPER_NODE("^");
    return value ^ other.value;
}

NotInt NotInt::operator<<(const NotInt& other)
{
    operation_count++;
    printf("operator<<(const NotInt&) id = %d\n", id);
    ADD_OPERATION_NODE("<<(other)");
    ADD_BINARY_OPER_NODE("<<");
    return value << other.value;
}

NotInt NotInt::operator>>(const NotInt& other)
{
    operation_count++;
    printf("operator>>(const NotInt&) id = %d\n", id);
    ADD_OPERATION_NODE(">>(other)");
    ADD_BINARY_OPER_NODE(">>");
    return value >> other.value;
}

//=====================================LOGICAL==================================

bool NotInt::operator||(const NotInt& other)
{
    operation_count++;
    printf("operator||(const NotInt& id = %d\n", id);
    ADD_OPERATION_NODE("||(other)"); 
    return value || other.value;;
}

bool NotInt::operator&&(const NotInt& other)
{
    operation_count++;
    printf("operator||(const NotInt& id = %d\n", id);
    ADD_OPERATION_NODE("&&(other)");
    return value && other.value;;
}

bool NotInt::operator!()
{
    operation_count++;
    printf("operator!(const NotInt& id = %d\n", id);
    ADD_OPERATION_NODE("!");
    return !value;
}

//====================================COMPARISON================================

bool NotInt::operator==(const NotInt& other)
{
    operation_count++;
    printf("operator==(const NotInt& id = %d\n", id);
    ADD_OPERATION_NODE("==(other)");
    return value == other.value;
}

bool NotInt::operator!=(const NotInt& other)
{
    operation_count++;
    printf("operator==(const NotInt& id = %d\n", id);
    ADD_OPERATION_NODE("!(other)");
    return value != other.value;
}

bool NotInt::operator<(const NotInt& other)
{
    operation_count++;
    printf("operator<(const NotInt& id = %d\n", id);
    ADD_OPERATION_NODE("<(other)")

    return value < other.value;
}
    
bool NotInt::operator>(const NotInt& other)
{
    operation_count++;
    printf("operator>(const NotInt& id = %d\n", id);
    ADD_OPERATION_NODE(">(other)")
    return value > other.value;
}

bool NotInt::operator<=(const NotInt& other)
{
    operation_count++;
    printf("operator<=(const NotInt& id = %d\n", id);
    ADD_OPERATION_NODE("<=(other)");
    return value <= other.value;
}

bool NotInt::operator>=(const NotInt& other)
{
    operation_count++;
    printf("operator>=(const NotInt& id = %d\n", id);
    ADD_OPERATION_NODE(">=(other)");
    return value >= other.value;
}

//===================================ASSIGNMENT=================================

NotInt& NotInt::operator=(int new_value)
{
    operation_count++;
    value = new_value;
    printf("operator= int, value = %d id = %d\n", value, id);
    ADD_OPERATION_NODE("=(int)");
    return *this;
}

NotInt& NotInt::operator=(const NotInt& other)
{
    operation_count++;
    value = other.value;
    printf("operator= const NotInt&, value = %d id = %d\n", value, id);
    ADD_OPERATION_NODE("=(NotInt&)");
    return *this;
}

NotInt& NotInt::operator=(NotInt&& other)
{
    operation_count++;
    value = other.value;
    printf("operator= const NotInt&&, value = %d id = %d\n", value, id);
    ADD_OPERATION_NODE("=(NotInt&&)");
    return *this;
}

NotInt& NotInt::operator+=(const NotInt& other)
{
    operation_count++;
    value += other.value;
    printf("operator+=(const NotInt&, value = %d id = %d\n", value, id);
    ADD_OPERATION_NODE("+=(NotInt)");
    return *this;
}

NotInt& NotInt::operator-=(const NotInt& other)
{
    operation_count++;
    value -= other.value;
    printf("operator-=(const NotInt&, value = %d id = %d\n", value, id);
    ADD_OPERATION_NODE("-=(NotInt)");
    return *this;
}

NotInt& NotInt::operator/=(const NotInt& other)
{
    operation_count++;
    value /= other.value;
    printf("operator/=(const NotInt&, value = %d id = %d\n", value, id);
    ADD_OPERATION_NODE("/=(NotInt)");
    return *this;
}

NotInt& NotInt::operator%=(const NotInt& other)
{
    operation_count++;
    value %= other.value;
    printf("operator%=(const NotInt&, value = %d id = %d\n", value, id);
    ADD_OPERATION_NODE("%=(NotInt)");
    return *this;
}

NotInt& NotInt::operator*=(const NotInt& other)
{
    operation_count++;
    value *= other.value;
    printf("operator*=(const NotInt&, value = %d id = %d\n", value, id);
    ADD_OPERATION_NODE("*=(NotInt)");
    return *this;
}

NotInt& NotInt::operator&=(const NotInt& other)
{
    operation_count++;
    value &= other.value;
    printf("operator&=(const NotInt&, value = %d id = %d\n", value, id);
    ADD_OPERATION_NODE("&=(NotInt)");
    return *this;
}

NotInt& NotInt::operator|=(const NotInt& other)
{
    operation_count++;
    value |= other.value;
    printf("operator|=(const NotInt&, value = %d id = %d\n", value, id);
    ADD_OPERATION_NODE("|=(NotInt)");
    return *this;
}

NotInt& NotInt::operator^=(const NotInt& other)
{
    operation_count++;
    value ^= other.value;
    printf("operator^=(const NotInt&, value = %d id = %d\n", value, id);
    ADD_OPERATION_NODE("^=(NotInt)");
    return *this;
}

NotInt& NotInt::operator>>=(const NotInt& other)
{
    operation_count++;
    value >>= other.value;
    printf("operator>>=(const NotInt&, value = %d id = %d\n", value, id);
    ADD_OPERATION_NODE(">>=(NotInt)");
    return *this;
}

NotInt& NotInt::operator<<=(const NotInt& other)
{
    operation_count++;
    value <<= other.value;
    printf("operator<<=(const NotInt&, value = %d id = %d\n", value, id);
    ADD_OPERATION_NODE("<<=(NotInt)");
    return *this;
}

    //===================================OTHER==================================

NotInt& NotInt::operator[](const NotInt& index)
{
    operation_count++;
    printf("operator[%d](const NotInt&, value = %d id = %d\n", index.value, value, id);
    ADD_OPERATION_NODE("[]");
    return *this;
}

NotInt& NotInt::operator()()
{
    operation_count++;
    printf("operator()(const NotInt&, value = %d id = %d\n", value, id);
    ADD_OPERATION_NODE("()");
    return *this;
}

NotInt& NotInt::operator->()
{
    operation_count++;
    printf("operator->(const NotInt&, value = %d id = %d\n", value, id);
    ADD_OPERATION_NODE("->");
    return *this;
}

NotInt& NotInt::operator*()
{
    operation_count++;
    printf("operator*(const NotInt&, value = %d id = %d\n", value, id);
    ADD_OPERATION_NODE("*()");
    return *this;
}

NotInt::~NotInt()
{
    operation_count++;
    printf("STD DTOR, value = %d id = %d\n", value, id);
    
    //ADD_OPERATION_NODE("dtor")
    fprintf(NotInt::not_int_output, OperationNodePrototype, id, operation_count, "dtor");
    fprintf(NotInt::not_int_output, EdgePrototype, id, operation_count - 1, id, operation_count);
}
