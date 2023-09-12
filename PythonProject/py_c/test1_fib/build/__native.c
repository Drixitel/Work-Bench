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
    {"fib_vanilla", (PyCFunction)CPyPy_fib_vanilla, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "fib_normal_withC",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyMODINIT_FUNC PyInit_fib_normal_withC(void)
{
    PyObject* modname = NULL;
    if (CPyModule_fib_normal_withC_internal) {
        Py_INCREF(CPyModule_fib_normal_withC_internal);
        return CPyModule_fib_normal_withC_internal;
    }
    CPyModule_fib_normal_withC_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_fib_normal_withC_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_fib_normal_withC_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_fib_normal_withC_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_fib_normal_withC_internal;
    fail:
    Py_CLEAR(CPyModule_fib_normal_withC_internal);
    Py_CLEAR(modname);
    return NULL;
}

PyObject *CPyDef_fib_vanilla(PyObject *cpy_r_n) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    int32_t cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    cpy_r_r0 = CPyStatics[10]; /* 1 */
    cpy_r_r1 = PyObject_RichCompare(cpy_r_n, cpy_r_r0, 1);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("fib_normal_withC.py", "fib_vanilla", 13, CPyStatic_globals);
        goto CPyL10;
    }
    cpy_r_r2 = PyObject_IsTrue(cpy_r_r1);
    CPy_DECREF(cpy_r_r1);
    cpy_r_r3 = cpy_r_r2 >= 0;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("fib_normal_withC.py", "fib_vanilla", 13, CPyStatic_globals);
        goto CPyL10;
    }
    cpy_r_r4 = cpy_r_r2;
    if (!cpy_r_r4) goto CPyL4;
    CPy_INCREF(cpy_r_n);
    return cpy_r_n;
CPyL4: ;
    cpy_r_r5 = CPyStatics[11]; /* 2 */
    cpy_r_r6 = PyNumber_Subtract(cpy_r_n, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("fib_normal_withC.py", "fib_vanilla", 16, CPyStatic_globals);
        goto CPyL10;
    }
    cpy_r_r7 = CPyDef_fib_vanilla(cpy_r_r6);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("fib_normal_withC.py", "fib_vanilla", 16, CPyStatic_globals);
        goto CPyL10;
    }
    cpy_r_r8 = CPyStatics[10]; /* 1 */
    cpy_r_r9 = PyNumber_Subtract(cpy_r_n, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("fib_normal_withC.py", "fib_vanilla", 16, CPyStatic_globals);
        goto CPyL11;
    }
    cpy_r_r10 = CPyDef_fib_vanilla(cpy_r_r9);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("fib_normal_withC.py", "fib_vanilla", 16, CPyStatic_globals);
        goto CPyL11;
    }
    cpy_r_r11 = PyNumber_Add(cpy_r_r7, cpy_r_r10);
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("fib_normal_withC.py", "fib_vanilla", 16, CPyStatic_globals);
        goto CPyL10;
    }
    return cpy_r_r11;
CPyL10: ;
    cpy_r_r12 = NULL;
    return cpy_r_r12;
CPyL11: ;
    CPy_DecRef(cpy_r_r7);
    goto CPyL10;
}

PyObject *CPyPy_fib_vanilla(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"n", 0};
    static CPyArg_Parser parser = {"O:fib_vanilla", kwlist, 0};
    PyObject *obj_n;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_n)) {
        return NULL;
    }
    PyObject *arg_n = obj_n;
    PyObject *retval = CPyDef_fib_vanilla(arg_n);
    return retval;
fail: ;
    CPy_AddTraceback("fib_normal_withC.py", "fib_vanilla", 12, CPyStatic_globals);
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
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    double cpy_r_r33;
    char cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    double cpy_r_r39;
    char cpy_r_r40;
    double cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject **cpy_r_r48;
    PyObject *cpy_r_r49;
    char cpy_r_r50;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[3]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("fib_normal_withC.py", "<module>", -1, CPyStatic_globals);
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
    cpy_r_r10 = CPyStatics[14]; /* (('time', 'time', 'time'),) */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyStatics[5]; /* 'fib_normal_withC.py' */
    cpy_r_r13 = CPyStatics[6]; /* '<module>' */
    cpy_r_r14 = CPyImport_ImportMany(cpy_r_r10, cpy_r_r7, cpy_r_r11, cpy_r_r12, cpy_r_r13, cpy_r_r9);
    if (!cpy_r_r14) goto CPyL20;
    cpy_r_r15 = CPyModule_time;
    cpy_r_r16 = CPyStatics[7]; /* 'perf_counter' */
    cpy_r_r17 = CPyObject_GetAttr(cpy_r_r15, cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("fib_normal_withC.py", "<module>", 24, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r18 = _PyObject_Vectorcall(cpy_r_r17, 0, 0, 0);
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("fib_normal_withC.py", "<module>", 24, CPyStatic_globals);
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
        CPy_AddTraceback("fib_normal_withC.py", "<module>", 24, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL9;
CPyL8: ;
    cpy_r_r26 = PyErr_Occurred();
    if (unlikely(cpy_r_r26 != NULL)) {
        CPy_AddTraceback("fib_normal_withC.py", "<module>", 24, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL7;
CPyL9: ;
    cpy_r_r27 = CPyStatics[12]; /* 32 */
    cpy_r_r28 = CPyDef_fib_vanilla(cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("fib_normal_withC.py", "<module>", 25, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL21;
CPyL10: ;
    cpy_r_r29 = CPyModule_time;
    cpy_r_r30 = CPyStatics[7]; /* 'perf_counter' */
    cpy_r_r31 = CPyObject_GetAttr(cpy_r_r29, cpy_r_r30);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("fib_normal_withC.py", "<module>", 29, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r32 = _PyObject_Vectorcall(cpy_r_r31, 0, 0, 0);
    CPy_DECREF(cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("fib_normal_withC.py", "<module>", 29, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r33 = PyFloat_AsDouble(cpy_r_r32);
    if (cpy_r_r33 == -1.0 && PyErr_Occurred()) {
        cpy_r_r33 = -113.0;
    }
    CPy_DECREF(cpy_r_r32);
    cpy_r_r34 = cpy_r_r33 == -113.0;
    if (unlikely(cpy_r_r34)) goto CPyL14;
CPyL13: ;
    cpy_r_r35 = CPyStatic_globals;
    cpy_r_r36 = CPyStatics[8]; /* 't0' */
    cpy_r_r37 = CPyDict_GetItem(cpy_r_r35, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("fib_normal_withC.py", "<module>", 29, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL15;
CPyL14: ;
    cpy_r_r38 = PyErr_Occurred();
    if (unlikely(cpy_r_r38 != NULL)) {
        CPy_AddTraceback("fib_normal_withC.py", "<module>", 29, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL13;
CPyL15: ;
    cpy_r_r39 = PyFloat_AsDouble(cpy_r_r37);
    if (cpy_r_r39 == -1.0 && PyErr_Occurred()) {
        cpy_r_r39 = -113.0;
    }
    CPy_DECREF(cpy_r_r37);
    cpy_r_r40 = cpy_r_r39 == -113.0;
    if (unlikely(cpy_r_r40)) goto CPyL17;
CPyL16: ;
    cpy_r_r41 = cpy_r_r33 - cpy_r_r39;
    cpy_r_r42 = CPyModule_builtins;
    cpy_r_r43 = CPyStatics[9]; /* 'print' */
    cpy_r_r44 = CPyObject_GetAttr(cpy_r_r42, cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("fib_normal_withC.py", "<module>", 29, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL18;
CPyL17: ;
    cpy_r_r45 = PyErr_Occurred();
    if (unlikely(cpy_r_r45 != NULL)) {
        CPy_AddTraceback("fib_normal_withC.py", "<module>", 29, CPyStatic_globals);
        goto CPyL20;
    } else
        goto CPyL16;
CPyL18: ;
    cpy_r_r46 = PyFloat_FromDouble(cpy_r_r41);
    PyObject *cpy_r_r47[1] = {cpy_r_r46};
    cpy_r_r48 = (PyObject **)&cpy_r_r47;
    cpy_r_r49 = _PyObject_Vectorcall(cpy_r_r44, cpy_r_r48, 1, 0);
    CPy_DECREF(cpy_r_r44);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("fib_normal_withC.py", "<module>", 29, CPyStatic_globals);
        goto CPyL22;
    } else
        goto CPyL23;
CPyL19: ;
    CPy_DECREF(cpy_r_r46);
    return 1;
CPyL20: ;
    cpy_r_r50 = 2;
    return cpy_r_r50;
CPyL21: ;
    CPy_DECREF(cpy_r_r28);
    goto CPyL10;
CPyL22: ;
    CPy_DecRef(cpy_r_r46);
    goto CPyL20;
CPyL23: ;
    CPy_DECREF(cpy_r_r49);
    goto CPyL19;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_fib_normal_withC = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_time = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[15];
const char * const CPyLit_Str[] = {
    "\a\bbuiltins\004time\023fib_normal_withC.py\b<module>\fperf_counter\002t0\005print",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "\0031\0002\00032",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {2, 3, 4, 4, 4, 1, 13};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_fib_normal_withC_internal = NULL;
CPyModule *CPyModule_fib_normal_withC;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_time;
PyObject *CPyDef_fib_vanilla(PyObject *cpy_r_n);
PyObject *CPyPy_fib_vanilla(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);
