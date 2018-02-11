#include <Python.h>



typedef struct {
    PyObject_HEAD // Static value. Don't put semicolon here.
    int8_t value; // Actual value holder.
} I8;

PyTypeObject I8_Type;



#define TP_TDEF I8
#define TP_TYPE I8_Type

#define TP           int8_t // Core type.
#define TP_FORMAT    PRId8  // Print macro.

#define TP_NAME    "t.i8"		   // Type name.
#define TP_DOC     "tp_doc for i8" // Docstring.

#define PY_FORMAT "i"    // Python format to use for parse tuple.
#define PY_PARSER void

#define TP_CHECK(x) ((x)->ob_type == &TP_TYPE)
#define TP_VALUE(x) (((TP_TDEF *)(x))->value)



#include "nb_as_number.h"
#include "nb_type.h"



PyTypeObject 
I8_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    TP_NAME,                                    /* tp_name */
    sizeof(TP_TDEF),                            /* tp_basicsize */
    0,                                          /* tp_itemsize */
    (destructor)tp_dealloc,                     /* tp_dealloc */
    0,                                          /* tp_print */
    0,                                          /* tp_getattr */
    0,                                          /* tp_setattr */
    0,                                          /* tp_reserved */
    (reprfunc)tp_repr,                          /* tp_repr */
    &tp_as_number,                              /* tp_as_number */
    0,                                          /* tp_as_sequence */
    0,                                          /* tp_as_mapping */
    (hashfunc)tp_hash,                          /* tp_hash  */
    0,                                          /* tp_call */
    0,                                          /* tp_str */
    0,                                          /* tp_getattro */
    0,                                          /* tp_setattro */
    0,                                          /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
    TP_DOC,                                     /* tp_doc */
    0,                                          /* tp_traverse */
    0,                                          /* tp_clear */
    0,                                          /* tp_richcompare */
    0,                                          /* tp_weaklistoffset */
    0,                                          /* tp_iter */
    0,                                          /* tp_iternext */
    0,                                          /* tp_methods */
    0,                                          /* tp_members */
    0,                                          /* tp_getset */
    0,                                          /* tp_base */
    0,                                          /* tp_dict */
    0,                                          /* tp_descr_get */
    0,                                          /* tp_descr_set */
    0,                                          /* tp_dictoffset */
    (initproc)tp_init,                          /* tp_init */
    0,                                          /* tp_alloc */
    tp_new,                                     /* tp_new */
};