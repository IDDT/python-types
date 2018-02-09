#pragma once
#include <Python.h>


typedef struct {
    PyObject_HEAD // Don't put semicolon here.
    int8_t value; // Actual value.
} I8;


#define I8_check(x)  ((x)->ob_type == &I8_Type)
#define I8_value(x)  (((I8 *)(x))->value)