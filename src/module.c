#include <Python.h>


extern PyTypeObject INT8_Type;
extern PyTypeObject ARRAY_INT8_Type;



static PyModuleDef
T_Module = {
    PyModuleDef_HEAD_INIT,
    "t",
    "Docstring for 't' module.",
    -1,
    NULL, NULL, NULL, NULL, NULL
};




// Module initialization. Name must be as "PyInit_{module_name}".
PyMODINIT_FUNC
PyInit_t(void) {

    PyObject* m;

    if (PyType_Ready(&INT8_Type) < 0) {
        return NULL;
    }

    if (PyType_Ready(&ARRAY_INT8_Type) < 0) {
        return NULL;
    }

    m = PyModule_Create(&T_Module);
    if (m == NULL) {
        return NULL;
    }

    Py_INCREF(&INT8_Type);
    PyModule_AddObject(m, "int8", (PyObject *)&INT8_Type);
    Py_INCREF(&ARRAY_INT8_Type);
    PyModule_AddObject(m, "int8array", (PyObject *)&ARRAY_INT8_Type);
    return m;
}
