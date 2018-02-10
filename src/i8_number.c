#include "i8_typedef.h"


extern PyTypeObject I8_Type;




// Custom creator.
static PyObject *
I8_create(int8_t initial_value) {
    I8 *obj = NULL;
    obj = PyObject_NEW(I8, &I8_Type);
    if (obj != NULL)
      obj->value = initial_value;
    return (PyObject *)obj;
}




//Number functions.
static PyObject * 
nb_add(PyObject *o1, PyObject *o2) {
    int8_t v1 = GET_VALUE(o1);
    int8_t v2 = GET_VALUE(o2);
    return I8_create(v1 + v2);
}

static PyObject * 
nb_substract(PyObject *o1, PyObject *o2) {
    int8_t v1 = GET_VALUE(o1);
    int8_t v2 = GET_VALUE(o2);
    return I8_create(v1 - v2);
}

static PyObject * 
nb_multiply(PyObject *o1, PyObject *o2) {
    int8_t v1 = GET_VALUE(o1);
    int8_t v2 = GET_VALUE(o2);
    return I8_create(v1 * v2);
}

static PyObject * 
nb_negative(PyObject *o) {
    I8 *obj = (I8 *)o;
    obj->value = -obj->value;
    return (PyObject *)obj;
}

static PyObject * 
nb_inplace_add(PyObject *o1, PyObject *o2) {
    I8 *oo1 = (I8 *)o1;
    I8 *oo2 = (I8 *)o2;
    oo1->value = oo1->value + oo2->value;
    return (PyObject *)oo1;
}

static PyObject * 
nb_inplace_subtract(PyObject *o1, PyObject *o2) {
    I8 *oo1 = (I8 *)o1;
    I8 *oo2 = (I8 *)o2;
    oo1->value = oo1->value - oo2->value;
    return (PyObject *)oo1;
}

static PyObject * 
nb_inplace_multiply(PyObject *o1, PyObject *o2) {
    I8 *oo1 = (I8 *)o1;
    I8 *oo2 = (I8 *)o2;
    oo1->value = oo1->value * oo2->value;
    return (PyObject *)oo1;
}

static PyObject * 
nb_floor_divide(PyObject *o1, PyObject *o2) {
    I8 *oo1 = (I8 *)o1;
    I8 *oo2 = (I8 *)o2;
    return I8_create(oo1->value / oo2->value);
}




PyNumberMethods
I8_as_number = {
    nb_add,                       // binaryfunc nb_add;
    nb_substract,                 // binaryfunc nb_subtract;
    nb_multiply,                  // binaryfunc nb_multiply;
    0,                            // binaryfunc nb_remainder;
    0,                            // binaryfunc nb_divmod;
    0,                            // ternaryfunc nb_power;
    nb_negative,                  // unaryfunc nb_negative;
    0,                            // unaryfunc nb_positive;
    0,                            // unaryfunc nb_absolute;
    0,                            // inquiry nb_bool;
    0,                            // unaryfunc nb_invert;
    0,                            // binaryfunc nb_lshift;
    0,                            // binaryfunc nb_rshift;
    0,                            // binaryfunc nb_and;
    0,                            // binaryfunc nb_xor;
    0,                            // binaryfunc nb_or;
    0,                            // unaryfunc nb_int;
    0,                            // void *nb_reserved;
    0,                            // unaryfunc nb_float;

    nb_inplace_add,               // binaryfunc nb_inplace_add;
    nb_inplace_subtract,          // binaryfunc nb_inplace_subtract;
    nb_inplace_multiply,          // binaryfunc nb_inplace_multiply;
    0,                            // binaryfunc nb_inplace_remainder;
    0,                            // ternaryfunc nb_inplace_power;
    0,                            // binaryfunc nb_inplace_lshift;
    0,                            // binaryfunc nb_inplace_rshift;
    0,                            // binaryfunc nb_inplace_and;
    0,                            // binaryfunc nb_inplace_xor;
    0,                            // binaryfunc nb_inplace_or;

    nb_floor_divide,              // binaryfunc nb_floor_divide;
    0,                            // binaryfunc nb_true_divide;
    0,                            // binaryfunc nb_inplace_floor_divide;
    0,                            // binaryfunc nb_inplace_true_divide;

    0,                            // unaryfunc nb_index;

    0,                            // binaryfunc nb_matrix_multiply;
    0,                            // binaryfunc nb_inplace_matrix_multiply;
};
