#pragma once
#include <Python.h>


typedef struct {
    PyObject_VAR_HEAD // Variable length object.
    int8_t *arr;      // Array.
    // Use Py_SIZE(I8ARR) to set and access the length of the object. 
} I8ARR;


#define I8ARR_check(x)  ((x)->ob_type == &I8ARR_Type)
#define I8ARR_array(x)  (((I8ARR *)(x))->value)