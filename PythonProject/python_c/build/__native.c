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
    {"fib_C", (PyCFunction)CPyPy_fib_C, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "fib",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyMODINIT_FUNC PyInit_fib(void)
{
    PyObject* modname = NULL;
    if (CPyModule_fib_internal) {
        Py_INCREF(CPyModule_fib_internal);
        return CPyModule_fib_internal;
    }
    CPyModule_fib_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_fib_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_fib_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_fib_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_fib_internal;
    fail:
    Py_CLEAR(CPyModule_fib_internal);
    Py_CLEAR(modname);
    return NULL;
}

CPyTagged CPyDef_fib_C(CPyTagged cpy_r_n) {
    int64_t cpy_r_r0;
    char cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    CPyTagged cpy_r_r4;
    CPyTagged cpy_r_r5;
    CPyTagged cpy_r_r6;
    CPyTagged cpy_r_r7;
    CPyTagged cpy_r_r8;
    CPyTagged cpy_r_r9;
    cpy_r_r0 = cpy_r_n & 1;
    cpy_r_r1 = cpy_r_r0 != 0;
    if (!cpy_r_r1) goto CPyL2;
    cpy_r_r2 = CPyTagged_IsLt_(2, cpy_r_n);
    if (cpy_r_r2) {
        goto CPyL4;
    } else
        goto CPyL3;
CPyL2: ;
    cpy_r_r3 = (Py_ssize_t)cpy_r_n <= (Py_ssize_t)2;
    if (!cpy_r_r3) goto CPyL4;
CPyL3: ;
    CPyTagged_INCREF(cpy_r_n);
    return cpy_r_n;
CPyL4: ;
    cpy_r_r4 = CPyTagged_Subtract(cpy_r_n, 4);
    cpy_r_r5 = CPyDef_fib_C(cpy_r_r4);
    CPyTagged_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r5 == CPY_INT_TAG)) {
        CPy_AddTraceback("fib.py", "fib_C", 21, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r6 = CPyTagged_Subtract(cpy_r_n, 2);
    cpy_r_r7 = CPyDef_fib_C(cpy_r_r6);
    CPyTagged_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r7 == CPY_INT_TAG)) {
        CPy_AddTraceback("fib.py", "fib_C", 21, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r8 = CPyTagged_Add(cpy_r_r5, cpy_r_r7);
    CPyTagged_DECREF(cpy_r_r5);
    CPyTagged_DECREF(cpy_r_r7);
    return cpy_r_r8;
CPyL7: ;
    cpy_r_r9 = CPY_INT_TAG;
    return cpy_r_r9;
CPyL8: ;
    CPyTagged_DecRef(cpy_r_r5);
    goto CPyL7;
}

PyObject *CPyPy_fib_C(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"n", 0};
    static CPyArg_Parser parser = {"O:fib_C", kwlist, 0};
    PyObject *obj_n;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_n)) {
        return NULL;
    }
    CPyTagged arg_n;
    if (likely(PyLong_Check(obj_n)))
        arg_n = CPyTagged_BorrowFromObject(obj_n);
    else {
        CPy_TypeError("int", obj_n); goto fail;
    }
    CPyTagged retval = CPyDef_fib_C(arg_n);
    if (retval == CPY_INT_TAG) {
        return NULL;
    }
    PyObject *retbox = CPyTagged_StealAsObject(retval);
    return retbox;
fail: ;
    CPy_AddTraceback("fib.py", "fib_C", 17, CPyStatic_globals);
    return NULL;
}

char CPyDef___top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r5;
    void *cpy_r_r7;
    void *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    double cpy_r_r19;
    char cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    int32_t cpy_r_r24;
    char cpy_r_r25;
    PyObject *cpy_r_r26;
    CPyTagged cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    double cpy_r_r32;
    char cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    double cpy_r_r38;
    char cpy_r_r39;
    double cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject **cpy_r_r47;
    PyObject *cpy_r_r48;
    char cpy_r_r49;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[3]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("fib.py", "<module>", -1, CPyStatic_globals);
        goto CPyL20;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_time;
    PyObject **cpy_r_r6[1] = {cpy_r_r5};
    cpy_r_r7 = (void *)&cpy_r_r6;
    int64_t cpy_r_r8[1] = {1};
    cpy_r_r9 = (void *)&cpy_r_r8;
    cpy_r_r10 = CPyStatics[11]; /* (('time', 'time', 'time'),) */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyStatics[5]; /* 'fib.py' */
    cpy_r_r13 = CPyStatics[6]; /* '<module>' */
    cpy_r_r14 = CPyImport_ImportMany(cpy_r_r10, cpy_r_r7, cpy_r_r11, cpy_r_r12, cpy_r_r13, cpy_r_r9);
    if (!cpy_r_r14) goto CPyL20;
    cpy_r_r15 = CPyModule_time;
    cpy_r_r16 = CPyStatics[7]; /* 'perf_counter' */
    cpy_r_r17 = CPyObject_GetAttr(cpy_r_r15, cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("fib.py", "<module>", 27, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r18 = _PyObject_Vectorcall(cpy_r_r17, 0, 0, 0);
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("fib.py", "<module>", 27, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r19 = PyFloat_AsDouble(cpy_r_r18);
    if (cpy_r_r19 == -1.0 && PyErr_Occurred()) {
        cpy_r_r19 = -113.0;
    }
    CPy_DECREF(cpy_r_r18);
    cpy_r_r20 = cpy_r_r19 == -113.0;
    if (unlikely(cpy_r_r20)) goto CPyL8;
CPyL7: ;
    cpy_r_r21 = CPyStatic_globals;
    cpy_r_r22 = CPyStatics[8]; /* 't0' */
    cpy_r_r23 = PyFloat_FromDouble(cpy_r_r19);
    cpy_r_r24 = CPyDict_SetItem(cpy_r_r21, cpy_r_r22, cpy_r_r23);
    CPy_DECREF(cpy_r_r23);
    cpy_r_r25 = cpy_r_r24 >= 0;
    if (unlikely(!cpy_r_r25)) {
        CPy_AddTraceback("fib.py", "<module>", 27, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL9;
CPyL8: ;
    cpy_r_r26 = PyErr_Occurred();
    if (unlikely(cpy_r_r26 != NULL)) {
        CPy_AddTraceback("fib.py", "<module>", 27, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL7;
CPyL9: ;
    cpy_r_r27 = CPyDef_fib_C(64);
    if (unlikely(cpy_r_r27 == CPY_INT_TAG)) {
        CPy_AddTraceback("fib.py", "<module>", 29, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL21;
CPyL10: ;
    cpy_r_r28 = CPyModule_time;
    cpy_r_r29 = CPyStatics[7]; /* 'perf_counter' */
    cpy_r_r30 = CPyObject_GetAttr(cpy_r_r28, cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("fib.py", "<module>", 30, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r31 = _PyObject_Vectorcall(cpy_r_r30, 0, 0, 0);
    CPy_DECREF(cpy_r_r30);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("fib.py", "<module>", 30, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r32 = PyFloat_AsDouble(cpy_r_r31);
    if (cpy_r_r32 == -1.0 && PyErr_Occurred()) {
        cpy_r_r32 = -113.0;
    }
    CPy_DECREF(cpy_r_r31);
    cpy_r_r33 = cpy_r_r32 == -113.0;
    if (unlikely(cpy_r_r33)) goto CPyL14;
CPyL13: ;
    cpy_r_r34 = CPyStatic_globals;
    cpy_r_r35 = CPyStatics[8]; /* 't0' */
    cpy_r_r36 = CPyDict_GetItem(cpy_r_r34, cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("fib.py", "<module>", 30, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL15;
CPyL14: ;
    cpy_r_r37 = PyErr_Occurred();
    if (unlikely(cpy_r_r37 != NULL)) {
        CPy_AddTraceback("fib.py", "<module>", 30, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL13;
CPyL15: ;
    cpy_r_r38 = PyFloat_AsDouble(cpy_r_r36);
    if (cpy_r_r38 == -1.0 && PyErr_Occurred()) {
        cpy_r_r38 = -113.0;
    }
    CPy_DECREF(cpy_r_r36);
    cpy_r_r39 = cpy_r_r38 == -113.0;
    if (unlikely(cpy_r_r39)) goto CPyL17;
CPyL16: ;
    cpy_r_r40 = cpy_r_r32 - cpy_r_r38;
    cpy_r_r41 = CPyModule_builtins;
    cpy_r_r42 = CPyStatics[9]; /* 'print' */
    cpy_r_r43 = CPyObject_GetAttr(cpy_r_r41, cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("fib.py", "<module>", 30, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL18;
CPyL17: ;
    cpy_r_r44 = PyErr_Occurred();
    if (unlikely(cpy_r_r44 != NULL)) {
        CPy_AddTraceback("fib.py", "<module>", 30, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL16;
CPyL18: ;
    cpy_r_r45 = PyFloat_FromDouble(cpy_r_r40);
    PyObject *cpy_r_r46[1] = {cpy_r_r45};
    cpy_r_r47 = (PyObject **)&cpy_r_r46;
    cpy_r_r48 = _PyObject_Vectorcall(cpy_r_r43, cpy_r_r47, 1, 0);
    CPy_DECREF(cpy_r_r43);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("fib.py", "<module>", 30, CPyStatic_globals);
        goto CPyL22;
    } else
        goto CPyL23;
CPyL19: ;
    CPy_DECREF(cpy_r_r45);
    return 1;
CPyL20: ;
    cpy_r_r49 = 2;
    return cpy_r_r49;
CPyL21: ;
    CPyTagged_DECREF(cpy_r_r27);
    goto CPyL10;
CPyL22: ;
    CPy_DecRef(cpy_r_r45);
    goto CPyL20;
CPyL23: ;
    CPy_DECREF(cpy_r_r48);
    goto CPyL19;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_fib = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_time = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[12];
const char * const CPyLit_Str[] = {
    "\a\bbuiltins\004time\006fib.py\b<module>\fperf_counter\002t0\005print",
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
const int CPyLit_Tuple[] = {2, 3, 4, 4, 4, 1, 10};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_fib_internal = NULL;
CPyModule *CPyModule_fib;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_time;
CPyTagged CPyDef_fib_C(CPyTagged cpy_r_n);
PyObject *CPyPy_fib_C(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);
