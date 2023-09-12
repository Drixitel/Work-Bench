#include "init.c"
#include "getargs.c"
#include "getargsfast.c"
#include "int_ops.c"
#include "float_ops.c"
#include "str_ops.c"
#include "bytes_ops.c"
#include "list_ops.c"
#include "dict_ops.c"
#include "set_ops.c"
#include "tuple_ops.c"
#include "exc_ops.c"
#include "misc_ops.c"
#include "generic_ops.c"
#include "__native.h"
#include "__native_internal.h"
static PyMethodDef module_methods[] = {
    {"f", (PyCFunction)CPyPy_f, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"simulate", (PyCFunction)CPyPy_simulate, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"run_simulation", (PyCFunction)CPyPy_run_simulation, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "mod",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyMODINIT_FUNC PyInit_mod(void)
{
    PyObject* modname = NULL;
    if (CPyModule_mod_internal) {
        Py_INCREF(CPyModule_mod_internal);
        return CPyModule_mod_internal;
    }
    CPyModule_mod_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_mod_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_mod_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_mod_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_mod_internal;
    fail:
    Py_CLEAR(CPyModule_mod_internal);
    Py_CLEAR(modname);
    return NULL;
}

PyObject *CPyDef_f(PyObject *cpy_r_x) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    cpy_r_r0 = PyNumber_Multiply(cpy_r_x, cpy_r_x);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("mod.py", "f", 2, CPyStatic_globals);
        goto CPyL2;
    }
    return cpy_r_r0;
CPyL2: ;
    cpy_r_r1 = NULL;
    return cpy_r_r1;
}

PyObject *CPyPy_f(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"x", 0};
    static CPyArg_Parser parser = {"O:f", kwlist, 0};
    PyObject *obj_x;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_x)) {
        return NULL;
    }
    PyObject *arg_x = obj_x;
    PyObject *retval = CPyDef_f(arg_x);
    return retval;
fail: ;
    CPy_AddTraceback("mod.py", "f", 1, CPyStatic_globals);
    return NULL;
}

CPyTagged CPyDef_simulate(CPyTagged cpy_r_x, double cpy_r_p) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    int32_t cpy_r_r10;
    char cpy_r_r11;
    CPyTagged cpy_r_s;
    CPyTagged cpy_r_r;
    int64_t cpy_r_r12;
    char cpy_r_r13;
    int64_t cpy_r_r14;
    char cpy_r_r15;
    char cpy_r_r16;
    char cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    double cpy_r_r22;
    char cpy_r_r23;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    CPyTagged cpy_r_r26;
    CPyTagged cpy_r_r27;
    CPyTagged cpy_r_r28;
    cpy_r_r0 = CPyStatic_globals;
    cpy_r_r1 = CPyModule_random;
    cpy_r_r2 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r3 = cpy_r_r1 != cpy_r_r2;
    if (cpy_r_r3) goto CPyL3;
    cpy_r_r4 = CPyStatics[3]; /* 'random' */
    cpy_r_r5 = PyImport_Import(cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("mod.py", "simulate", 6, CPyStatic_globals);
        goto CPyL18;
    }
    CPyModule_random = cpy_r_r5;
    CPy_INCREF(CPyModule_random);
    CPy_DECREF(cpy_r_r5);
CPyL3: ;
    cpy_r_r6 = CPyStatics[3]; /* 'random' */
    cpy_r_r7 = PyImport_GetModuleDict();
    cpy_r_r8 = CPyStatics[3]; /* 'random' */
    cpy_r_r9 = CPyDict_GetItem(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("mod.py", "simulate", 6, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_r10 = CPyDict_SetItem(cpy_r_r0, cpy_r_r6, cpy_r_r9);
    CPy_DECREF(cpy_r_r9);
    cpy_r_r11 = cpy_r_r10 >= 0;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("mod.py", "simulate", 6, CPyStatic_globals);
        goto CPyL18;
    }
    cpy_r_s = 0;
    cpy_r_r = 0;
CPyL6: ;
    cpy_r_r12 = cpy_r_s & 1;
    cpy_r_r13 = cpy_r_r12 != 0;
    if (cpy_r_r13) goto CPyL8;
    cpy_r_r14 = cpy_r_x & 1;
    cpy_r_r15 = cpy_r_r14 != 0;
    if (!cpy_r_r15) goto CPyL9;
CPyL8: ;
    cpy_r_r16 = CPyTagged_IsLt_(cpy_r_s, cpy_r_x);
    if (cpy_r_r16) {
        goto CPyL10;
    } else
        goto CPyL19;
CPyL9: ;
    cpy_r_r17 = (Py_ssize_t)cpy_r_s < (Py_ssize_t)cpy_r_x;
    if (!cpy_r_r17) goto CPyL19;
CPyL10: ;
    cpy_r_r18 = CPyModule_random;
    cpy_r_r19 = CPyStatics[3]; /* 'random' */
    cpy_r_r20 = CPyObject_GetAttr(cpy_r_r18, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("mod.py", "simulate", 18, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r21 = _PyObject_Vectorcall(cpy_r_r20, 0, 0, 0);
    CPy_DECREF(cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("mod.py", "simulate", 18, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r22 = PyFloat_AsDouble(cpy_r_r21);
    if (cpy_r_r22 == -1.0 && PyErr_Occurred()) {
        cpy_r_r22 = -113.0;
    }
    CPy_DECREF(cpy_r_r21);
    cpy_r_r23 = cpy_r_r22 == -113.0;
    if (unlikely(cpy_r_r23)) goto CPyL14;
CPyL13: ;
    cpy_r_r24 = cpy_r_r22 < cpy_r_p;
    if (cpy_r_r24) {
        goto CPyL15;
    } else
        goto CPyL16;
CPyL14: ;
    cpy_r_r25 = PyErr_Occurred();
    if (unlikely(cpy_r_r25 != NULL)) {
        CPy_AddTraceback("mod.py", "simulate", 18, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL13;
CPyL15: ;
    cpy_r_r26 = CPyTagged_Add(cpy_r_s, 2);
    CPyTagged_DECREF(cpy_r_s);
    cpy_r_s = cpy_r_r26;
CPyL16: ;
    cpy_r_r27 = CPyTagged_Add(cpy_r_r, 2);
    CPyTagged_DECREF(cpy_r_r);
    cpy_r_r = cpy_r_r27;
    goto CPyL6;
CPyL17: ;
    return cpy_r_r;
CPyL18: ;
    cpy_r_r28 = CPY_INT_TAG;
    return cpy_r_r28;
CPyL19: ;
    CPyTagged_DECREF(cpy_r_s);
    goto CPyL17;
CPyL20: ;
    CPyTagged_DecRef(cpy_r_s);
    CPyTagged_DecRef(cpy_r_r);
    goto CPyL18;
}

PyObject *CPyPy_simulate(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"x", "p", 0};
    static CPyArg_Parser parser = {"OO:simulate", kwlist, 0};
    PyObject *obj_x;
    PyObject *obj_p;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_x, &obj_p)) {
        return NULL;
    }
    CPyTagged arg_x;
    if (likely(PyLong_Check(obj_x)))
        arg_x = CPyTagged_BorrowFromObject(obj_x);
    else {
        CPy_TypeError("int", obj_x); goto fail;
    }
    double arg_p;
    arg_p = PyFloat_AsDouble(obj_p);
    if (arg_p == -1.0 && PyErr_Occurred()) {
        arg_p = -113.0;
    }
    CPyTagged retval = CPyDef_simulate(arg_x, arg_p);
    if (retval == CPY_INT_TAG) {
        return NULL;
    }
    PyObject *retbox = CPyTagged_StealAsObject(retval);
    return retbox;
fail: ;
    CPy_AddTraceback("mod.py", "simulate", 4, CPyStatic_globals);
    return NULL;
}

CPyTagged CPyDef_run_simulation(PyObject *cpy_r_nums) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    CPyTagged cpy_r_r8;
    CPyTagged cpy_r_r9;
    cpy_r_r0 = CPyStatic_globals;
    cpy_r_r1 = CPyStatics[4]; /* 'simulate' */
    cpy_r_r2 = CPyDict_GetItem(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("mod.py", "run_simulation", 28, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r3 = PyList_New(0);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("mod.py", "run_simulation", 28, CPyStatic_globals);
        goto CPyL9;
    }
    cpy_r_r4 = CPyList_Extend(cpy_r_r3, cpy_r_nums);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("mod.py", "run_simulation", 28, CPyStatic_globals);
        goto CPyL10;
    } else
        goto CPyL11;
CPyL3: ;
    cpy_r_r5 = PyList_AsTuple(cpy_r_r3);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("mod.py", "run_simulation", 28, CPyStatic_globals);
        goto CPyL9;
    }
    cpy_r_r6 = PyDict_New();
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("mod.py", "run_simulation", 28, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r7 = PyObject_Call(cpy_r_r2, cpy_r_r5, cpy_r_r6);
    CPy_DECREF(cpy_r_r2);
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("mod.py", "run_simulation", 28, CPyStatic_globals);
        goto CPyL8;
    }
    if (likely(PyLong_Check(cpy_r_r7)))
        cpy_r_r8 = CPyTagged_FromObject(cpy_r_r7);
    else {
        CPy_TypeError("int", cpy_r_r7); cpy_r_r8 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r8 == CPY_INT_TAG)) {
        CPy_AddTraceback("mod.py", "run_simulation", 28, CPyStatic_globals);
        goto CPyL8;
    }
    return cpy_r_r8;
CPyL8: ;
    cpy_r_r9 = CPY_INT_TAG;
    return cpy_r_r9;
CPyL9: ;
    CPy_DecRef(cpy_r_r2);
    goto CPyL8;
CPyL10: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r3);
    goto CPyL8;
CPyL11: ;
    CPy_DECREF(cpy_r_r4);
    goto CPyL3;
CPyL12: ;
    CPy_DecRef(cpy_r_r2);
    CPy_DecRef(cpy_r_r5);
    goto CPyL8;
}

PyObject *CPyPy_run_simulation(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"nums", 0};
    static CPyArg_Parser parser = {"O:run_simulation", kwlist, 0};
    PyObject *obj_nums;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_nums)) {
        return NULL;
    }
    PyObject *arg_nums;
    if (likely(PyList_Check(obj_nums)))
        arg_nums = obj_nums;
    else {
        CPy_TypeError("list", obj_nums); 
        goto fail;
    }
    CPyTagged retval = CPyDef_run_simulation(arg_nums);
    if (retval == CPY_INT_TAG) {
        return NULL;
    }
    PyObject *retbox = CPyTagged_StealAsObject(retval);
    return retbox;
fail: ;
    CPy_AddTraceback("mod.py", "run_simulation", 26, CPyStatic_globals);
    return NULL;
}

char CPyDef___top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[5]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("mod.py", "<module>", -1, CPyStatic_globals);
        goto CPyL4;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    return 1;
CPyL4: ;
    cpy_r_r5 = 2;
    return cpy_r_r5;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_mod = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_random = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[6];
const char * const CPyLit_Str[] = {
    "\003\006random\bsimulate\bbuiltins",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {0};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_mod_internal = NULL;
CPyModule *CPyModule_mod;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_random;
PyObject *CPyDef_f(PyObject *cpy_r_x);
PyObject *CPyPy_f(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
CPyTagged CPyDef_simulate(CPyTagged cpy_r_x, double cpy_r_p);
PyObject *CPyPy_simulate(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
CPyTagged CPyDef_run_simulation(PyObject *cpy_r_nums);
PyObject *CPyPy_run_simulation(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);
