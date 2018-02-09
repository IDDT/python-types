#include <Python.h>


extern PyTypeObject I8_Type;
extern PyTypeObject I8ARR_Type;



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

    // Basic types ready.
    if (PyType_Ready(&I8_Type) < 0) { return NULL; }

    // Arrays ready.
    if (PyType_Ready(&I8ARR_Type) < 0) { return NULL; }

    // Creating module.
    PyObject* m;
    m = PyModule_Create(&T_Module);
    if (m == NULL) { return NULL; }

    // Basic types incref.
    Py_INCREF(&I8_Type);
    PyModule_AddObject(m, "i8", (PyObject *)&I8_Type);

    // Arrays incref.
    Py_INCREF(&I8ARR_Type);
    PyModule_AddObject(m, "i8arr", (PyObject *)&I8ARR_Type);
    
    return m;
}
