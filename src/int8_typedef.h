#pragma once
#include <Python.h>


typedef struct {
    PyObject_HEAD // Don't put semicolon here.
    int8_t value; // Actual value.
} INT8;


#define INT8_check(x)  ((x)->ob_type == &INT8_Type)
#define INT8_value(x)  (((INT8 *)(x))->value)