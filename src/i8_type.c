#include <Python.h>
#include "i8_typedef.h"


extern PyNumberMethods I8_as_number;




static void
I8_dealloc(I8* self) {
    Py_TYPE(self)->tp_free((PyObject*)self);
}


// __new__
static PyObject *
I8_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
    I8 *self;
    self = (I8 *)type->tp_alloc(type, 0);
    if (self != NULL) {
        self->value = 0;
    }
    return (PyObject *)self;
}


// __init__
static int
I8_init(I8 *self, PyObject *args) {
    if (! PyArg_ParseTuple(args, "L", &self->value)) {
        return -1;
    }
    return 0;
}


// __repr__
static PyObject *
I8_repr(I8 *self) {
    char output[5];
    sprintf(output, "%" PRId8, self->value);
    return Py_BuildValue("s", output);
}


// __hash__
static Py_hash_t
I8_hash(I8 *self) {
    Py_hash_t output = -1; // -1 on error. 
    // Following behavior is similar to python native int and float.
    if (self->value != -1) {
        output = self->value;
    } else {
        output = -2;
    }
    return output;
}


PyTypeObject 
I8_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "t.i8",                                     /* tp_name */
    sizeof(I8),                                 /* tp_basicsize */
    0,                                          /* tp_itemsize */
    (destructor)I8_dealloc,                     /* tp_dealloc */
    0,                                          /* tp_print */
    0,                                          /* tp_getattr */
    0,                                          /* tp_setattr */
    0,                                          /* tp_reserved */
    (reprfunc)I8_repr,                          /* tp_repr */
    &I8_as_number,                              /* tp_as_number */
    0,                                          /* tp_as_sequence */
    0,                                          /* tp_as_mapping */
    (hashfunc)I8_hash,                          /* tp_hash  */
    0,                                          /* tp_call */
    0,                                          /* tp_str */
    0,                                          /* tp_getattro */
    0,                                          /* tp_setattro */
    0,                                          /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "tp_doc for i8",                            /* tp_doc */
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
    (initproc)I8_init,                          /* tp_init */
    0,                                          /* tp_alloc */
    I8_new,                                     /* tp_new */
};