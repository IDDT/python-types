#pragma once
#include <Python.h>


typedef struct {
    PyObject_HEAD // Don't put semicolon here.
    int8_t value; // Actual value.
} I8;


#define TP_TYPEDEF I8

#define TP_NAME  "t.i8"
#define TP_DOC   "tp_doc for i8"

#define ITEM_TYPE    int8_t
#define ITEM_PRI_FMT PRId8

#define CHECK(x) ((x)->ob_type == &I8_Type)
#define GET_VALUE(x) (((I8 *)(x))->value)