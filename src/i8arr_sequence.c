#include "i8arr_typedef.h"




Py_ssize_t 
sq_length(PyObject *obj) {
    return I8ARR_size(obj);
}


PyObject *
sq_item(PyObject *obj, Py_ssize_t index) {

    PyObject *output = NULL;

    ssize_t length = I8ARR_size(obj);
    if (index < 0) {
        index += length;
    }

    if ((index >= 0) && (index < length)) {
        // Output as Python int.
        output = Py_BuildValue("i", I8ARR_array(obj)[index]);
    } else {
        PyErr_SetString(PyExc_IndexError, "Index out of range.");
    }

    return output;
}


PySequenceMethods I8ARR_as_sequence = {
    sq_length,      // lenfunc              sq_length;          __len__
    0,              // binaryfunc           sq_concat;          __add__
    0,              // ssizeargfunc         sq_repeat;          __mul__
    sq_item,        // ssizeargfunc         sq_item;            __getitem__
    0,              // void                 *was_sq_slice;      __getslice__
    0,              // ssizeobjargproc      sq_ass_item;        __setitem__
    0,              // void                 *was_sq_ass_slice;  __setslice__
    0,              // objobjproc           sq_contains;        in
    0,              // binaryfunc           sq_inplace_concat;  o1 += o2
    0,              // ssizeargfunc         sq_inplace_repeat;
};
