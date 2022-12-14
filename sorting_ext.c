#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "sorting.h"

int *pylist_to_int_array(PyObject *list) {
    Py_ssize_t len = PyList_Size(list);
    int *arr = (int*) malloc(sizeof(int)*len);
    for(Py_ssize_t i = 0; i < len; ++i)
        arr[i] = (int)PyLong_AsLong(PyList_GetItem(list, i));
    return arr;
}

PyObject *int_array_to_pylist(int *arr, Py_ssize_t len) {
    PyObject* out_list = PyList_New(len);
    for (Py_ssize_t i = 0; i < len; ++i)
        PyList_SetItem(out_list, i, PyLong_FromLong((long) arr[i]));
    return out_list;
}

static PyObject *sorting_bubble_sort(PyObject *self, PyObject *args) {
    PyObject *list;
    if (!PyArg_ParseTuple(args, "O", &list))
        return NULL;
    int *arr = pylist_to_int_array(list);
    Py_ssize_t len = PyList_Size(list);
    bubble_sort(arr, len);
    PyObject *out_list = int_array_to_pylist(arr, len);
    return out_list;
}

static PyObject *sorting_quick_sort(PyObject *self, PyObject *args) {
    PyObject *list;
    if (!PyArg_ParseTuple(args, "O", &list))
        return NULL;
    int *arr = pylist_to_int_array(list);
    Py_ssize_t len = PyList_Size(list);
    quick_sort(arr, len);
    PyObject *out_list = int_array_to_pylist(arr, len);
    return out_list;
}

static PyMethodDef sortingMethods[] = {
    {
        "bubble_sort",
        sorting_bubble_sort,
        METH_VARARGS,
        "Sort using the Bubble sort algorithm"
    },
    {
        "quick_sort",
        sorting_quick_sort,
        METH_VARARGS,
        "Sort using Quick sort algorithm"
    },
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef sortingmodule = {
    PyModuleDef_HEAD_INIT,
    "sorting",
    "A soring module written in C with a Python interface",
    -1,
    sortingMethods
};

PyMODINIT_FUNC
PyInit_sorting(void) {
    return PyModule_Create(&sortingmodule);
}


