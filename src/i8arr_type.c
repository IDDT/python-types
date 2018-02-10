#include "i8arr_typedef.h"


extern PySequenceMethods I8ARR_as_sequence;




static void
I8ARR_dealloc(I8ARR* self) {
    // Release memory.
    free(self->arr);
    // Release object.
    Py_TYPE(self)->tp_free((PyObject*)self);
}


// __new__
static PyObject *
I8ARR_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
    I8ARR *self;
    self = (I8ARR *)type->tp_alloc(type, 0);
    if (self != NULL) {
        self->arr = 0;
    }
    return (PyObject *)self;
}


// __init__
static int
I8ARR_init(I8ARR *self, PyObject *args) {

    // Parsing object.
    PyObject* obj;
    if (!PyArg_ParseTuple(args, "O", &obj)) {
        return -1;
    }

    // Parse sequence.
    PyObject* seq = PySequence_Fast(obj, "expected a sequence");
    Py_ssize_t len = PySequence_Length(seq);
    if (len == -1) {
        return -1;
    }

    // Set length of the object. Useful for sys.getsizeof().
    Py_SIZE(self) = len;

    // Allocate memory.
    self->arr = malloc(len * sizeof(int8_t));
    PyObject* item;
    for (Py_ssize_t i = 0; i < len; i++) {
        item = PySequence_Fast_GET_ITEM(seq, i);
        self->arr[i] = PyLong_AsLong(item);            // returns -1 on error. raises TypeError in python.
        // check PyErr_Occurred()
    }

    // Decrease reference counts for manually created objects.
    Py_DECREF(obj); 
    Py_DECREF(seq);

    return 0;
}


// __repr__
static PyObject *
I8ARR_repr(I8ARR *self) {

    // Get length.
    size_t len = Py_SIZE(self);

    // Init string with terminator for strcat.
    char output[100] = "\0";
    strcat(output, "([");

    // 10 or less items in the array.
    if (len <= 10) {
        for (size_t i = 0; i < len; i++) {
            // 4 chars for int8 + terminator.
            char temp[5];
            if (i != len - 1) {
                sprintf(temp, "%" PRId8 ", ", self->arr[i]);
            } else {
                sprintf(temp, "%" PRId8, self->arr[i]);
            }
            strcat(output, temp);
        }
    }

    // 10 or more items in the array.
    else {
        // First 4 numbers.
        for (size_t i = 0; i < 4; i++) {
            // 4 chars for int8 + terminator.
            char temp[5];
            sprintf(temp, "%" PRId8 ", ", self->arr[i]);
            strcat(output, temp);
        }
        strcat(output, "... ");
        // Last 4 numbers.
        for (size_t i = len - 5; i < len; i++) {
            // 4 chars for int8 + terminator.
            char temp[5];
            if (i != len - 1) {
                sprintf(temp, "%" PRId8 ", ", self->arr[i]);
            } else {
                sprintf(temp, "%" PRId8, self->arr[i]);
            }
            strcat(output, temp);
        }
    }

    strcat(output, "], i8arr)");
    return Py_BuildValue("s", output);
}


//
PyTypeObject 
I8ARR_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "t.i8arr",                                  /* tp_name */
    sizeof(I8ARR),                              /* tp_basicsize */
    sizeof(int8_t),                             /* tp_itemsize */
    (destructor)I8ARR_dealloc,                  /* tp_dealloc */
    0,                                          /* tp_print */
    0,                                          /* tp_getattr */
    0,                                          /* tp_setattr */
    0,                                          /* tp_reserved */
    (reprfunc)I8ARR_repr,                       /* tp_repr */
    0,                                          /* tp_as_number */
    &I8ARR_as_sequence,                         /* tp_as_sequence */
    0,                                          /* tp_as_mapping */
    0,                                          /* tp_hash  */
    0,                                          /* tp_call */
    0,                                          /* tp_str */
    0,                                          /* tp_getattro */
    0,                                          /* tp_setattro */
    0,                                          /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,   /* tp_flags */
    "tp_doc for i8arr",                         /* tp_doc */
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
    (initproc)I8ARR_init,                       /* tp_init */
    0,                                          /* tp_alloc */
    I8ARR_new,                                  /* tp_new */
};