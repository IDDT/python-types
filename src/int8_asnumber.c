#include <Python.h>
#include "int8_typedef.h"


extern PyTypeObject INT8_Type;




// Custom creator.
static PyObject *
INT8_create(int8_t initial_value) {
    INT8 *obj = NULL;
    obj = PyObject_NEW(INT8, &INT8_Type);
    if (obj != NULL)
      obj->value = initial_value;
    return (PyObject *)obj;
}




//Number functions.
static PyObject * 
INT8_add(PyObject *o1, PyObject *o2) {
    INT8 *oo1 = (INT8 *)o1;
    INT8 *oo2 = (INT8 *)o2;
    return INT8_create(oo1->value + oo2->value);
}

static PyObject * 
INT8_substract(PyObject *o1, PyObject *o2) {
    INT8 *oo1 = (INT8 *)o1;
    INT8 *oo2 = (INT8 *)o2;
    return INT8_create(oo1->value - oo2->value);
}

static PyObject * 
INT8_multiply(PyObject *o1, PyObject *o2) {
    INT8 *oo1 = (INT8 *)o1;
    INT8 *oo2 = (INT8 *)o2;
    return INT8_create(oo1->value * oo2->value);
}

static PyObject * 
INT8_negative(PyObject *o) {
    INT8 *obj = (INT8 *)o;
    obj->value = -obj->value;
    return (PyObject *)obj;
}

static PyObject * 
INT8_inplace_add(PyObject *o1, PyObject *o2) {
    INT8 *oo1 = (INT8 *)o1;
    INT8 *oo2 = (INT8 *)o2;
    oo1->value = oo1->value + oo2->value;
    return (PyObject *)oo1;
}

static PyObject * 
INT8_inplace_subtract(PyObject *o1, PyObject *o2) {
    INT8 *oo1 = (INT8 *)o1;
    INT8 *oo2 = (INT8 *)o2;
    oo1->value = oo1->value - oo2->value;
    return (PyObject *)oo1;
}

static PyObject * 
INT8_inplace_multiply(PyObject *o1, PyObject *o2) {
    INT8 *oo1 = (INT8 *)o1;
    INT8 *oo2 = (INT8 *)o2;
    oo1->value = oo1->value * oo2->value;
    return (PyObject *)oo1;
}

static PyObject * 
INT8_floor_divide(PyObject *o1, PyObject *o2) {
    INT8 *oo1 = (INT8 *)o1;
    INT8 *oo2 = (INT8 *)o2;
    return INT8_create(oo1->value / oo2->value);
}




PyNumberMethods
INT8_as_number = {
    INT8_add,                       // binaryfunc nb_add;
    INT8_substract,                 // binaryfunc nb_subtract;
    INT8_multiply,                  // binaryfunc nb_multiply;
    0,                              // binaryfunc nb_remainder;
    0,                              // binaryfunc nb_divmod;
    0,                              // ternaryfunc nb_power;
    INT8_negative,                  // unaryfunc nb_negative;
    0,                              // unaryfunc nb_positive;
    0,                              // unaryfunc nb_absolute;
    0,                              // inquiry nb_bool;
    0,                              // unaryfunc nb_invert;
    0,                              // binaryfunc nb_lshift;
    0,                              // binaryfunc nb_rshift;
    0,                              // binaryfunc nb_and;
    0,                              // binaryfunc nb_xor;
    0,                              // binaryfunc nb_or;
    0,                              // unaryfunc nb_int;
    0,                              // void *nb_reserved;
    0,                              // unaryfunc nb_float;

    INT8_inplace_add,               // binaryfunc nb_inplace_add;
    INT8_inplace_subtract,          // binaryfunc nb_inplace_subtract;
    INT8_inplace_multiply,          // binaryfunc nb_inplace_multiply;
    0,                              // binaryfunc nb_inplace_remainder;
    0,                              // ternaryfunc nb_inplace_power;
    0,                              // binaryfunc nb_inplace_lshift;
    0,                              // binaryfunc nb_inplace_rshift;
    0,                              // binaryfunc nb_inplace_and;
    0,                              // binaryfunc nb_inplace_xor;
    0,                              // binaryfunc nb_inplace_or;

    INT8_floor_divide,              // binaryfunc nb_floor_divide;
    0,                              // binaryfunc nb_true_divide;
    0,                              // binaryfunc nb_inplace_floor_divide;
    0,                              // binaryfunc nb_inplace_true_divide;

    0,                              // unaryfunc nb_index;

    0,                              // binaryfunc nb_matrix_multiply;
    0,                              // binaryfunc nb_inplace_matrix_multiply;
};
