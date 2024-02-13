#ifndef SYM_NOT_INT
#define SYM_NOT_INT

#include <stdio.h>
#include <stdlib.h>

class NotInt
{
    public :
    static int   not_int_counter;
    static int   bin_operation_cnt;
    static FILE* not_int_output;
    
    const char* color;
    int         value;
    int         operation_count;
    int         id;

    //===============================CONSTRUCTORS===============================

    NotInt();
    NotInt(int new_value);
    NotInt(const NotInt&  other);
    NotInt(NotInt&& other);

    //===============================ARITHMETIC=================================

    /* All binary arithmetic operations is better to do, using assignments. 
     * For example, instead of using + you should use +=. */

    //==================================LOGICAL=================================

    bool operator||(const NotInt& other);
    bool operator&&(const NotInt& other);
    bool operator!();

    //=================================COMPARISON===============================

    bool operator==(const NotInt& other);
    bool operator!=(const NotInt& other);
    bool operator<(const NotInt& other);
    bool operator>(const NotInt& other);
    bool operator<=(const NotInt& other);
    bool operator>=(const NotInt& other);

    //=================================ASSIGNMENT===============================

    NotInt& operator=  (const NotInt& other);
    NotInt& operator=  (NotInt&& other);
    NotInt& operator=  (int new_value);
    
    NotInt& operator+= (const NotInt& other);
    NotInt& operator-= (const NotInt& other);
    NotInt& operator/= (const NotInt& other);
    NotInt& operator%= (const NotInt& other);
    NotInt& operator*= (const NotInt& other);
    NotInt& operator&= (const NotInt& other);
    NotInt& operator|= (const NotInt& other);
    NotInt& operator^= (const NotInt& other);
    NotInt& operator>>=(const NotInt& other);
    NotInt& operator<<=(const NotInt& other);

    //===================================OTHER==================================

    ~NotInt();
};

#endif //SYM_NOT_INT