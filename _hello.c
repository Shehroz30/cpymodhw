#include <Python.h>

static PyObject* _hello(PyObject* self, PyObject *args) {
   PyObject* name;
   if (!PyArg_ParseTuple(args, "U", &name)) {
       return NULL; 
   }
   PyObject *ret = PyUnicode_FromFormat("hello %U", name);

   return ret;
}

static struct PyMethodDef methods[] = {
    {"hello", (PyCFunction)_hello, METH_VARARGS},
    {NULL, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT, 
    "_hello",
    NULL, 
    -1, 
    methods
};

PyMODINIT_FUNC PyInit__hello(void) {
    return PyModule_Create(&module);
}
