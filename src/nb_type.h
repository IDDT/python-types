// Type functions.



static void
tp_dealloc(TP_TDEF* self) {
    Py_TYPE(self)->tp_free((PyObject*)self);
}


// __new__
static PyObject *
tp_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
    TP_TDEF *self;
    self = (TP_TDEF *)type->tp_alloc(type, 0);
    if (self != NULL) {
        self->value = 0;
    }
    return (PyObject *)self;
}


// __init__
static int
tp_init(TP_TDEF *self, PyObject *args) {
    if (! PyArg_ParseTuple(args, PY_FORMAT, &self->value)) {
        return -1;
    }
    return 0;
}


// __repr__
static PyObject *
tp_repr(TP_TDEF *self) {
    char output[50];
    sprintf(output, "%" TP_FORMAT, self->value);
    return Py_BuildValue("s", output);
}


// __hash__
static Py_hash_t
tp_hash(TP_TDEF *self) {
    Py_hash_t output = -1; // -1 on error. 
    // The behavior is similar to python native int and float.
    if (self->value != -1) {
        output = self->value;
    } else {
        output = -2;
    }
    return output;
}