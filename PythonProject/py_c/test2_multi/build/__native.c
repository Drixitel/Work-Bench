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
    {"do_something", (PyCFunction)CPyPy_do_something, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {"fib_C", (PyCFunction)CPyPy_fib_C, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
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

PyObject *CPyDef_do_something(CPyTagged cpy_r_seconds) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject **cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject **cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    cpy_r_r0 = CPyStatics[3]; /* 'Sleeping ' */
    cpy_r_r1 = CPyTagged_Str(cpy_r_seconds);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("mod.py", "do_something", 4, CPyStatic_globals);
        goto CPyL9;
    }
    cpy_r_r2 = CPyStatics[4]; /* ' second...' */
    cpy_r_r3 = CPyStr_Build(3, cpy_r_r0, cpy_r_r1, cpy_r_r2);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("mod.py", "do_something", 4, CPyStatic_globals);
        goto CPyL9;
    }
    cpy_r_r4 = CPyModule_builtins;
    cpy_r_r5 = CPyStatics[5]; /* 'print' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("mod.py", "do_something", 4, CPyStatic_globals);
        goto CPyL10;
    }
    PyObject *cpy_r_r7[1] = {cpy_r_r3};
    cpy_r_r8 = (PyObject **)&cpy_r_r7;
    cpy_r_r9 = _PyObject_Vectorcall(cpy_r_r6, cpy_r_r8, 1, 0);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("mod.py", "do_something", 4, CPyStatic_globals);
        goto CPyL10;
    } else
        goto CPyL11;
CPyL4: ;
    CPy_DECREF(cpy_r_r3);
    cpy_r_r10 = CPyModule_time;
    cpy_r_r11 = CPyStatics[6]; /* 'sleep' */
    cpy_r_r12 = CPyObject_GetAttr(cpy_r_r10, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("mod.py", "do_something", 5, CPyStatic_globals);
        goto CPyL9;
    }
    CPyTagged_INCREF(cpy_r_seconds);
    cpy_r_r13 = CPyTagged_StealAsObject(cpy_r_seconds);
    PyObject *cpy_r_r14[1] = {cpy_r_r13};
    cpy_r_r15 = (PyObject **)&cpy_r_r14;
    cpy_r_r16 = _PyObject_Vectorcall(cpy_r_r12, cpy_r_r15, 1, 0);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("mod.py", "do_something", 5, CPyStatic_globals);
        goto CPyL12;
    } else
        goto CPyL13;
CPyL6: ;
    CPy_DECREF(cpy_r_r13);
    cpy_r_r17 = CPyStatics[7]; /* 'Done Sleeping...' */
    cpy_r_r18 = CPyTagged_Str(cpy_r_seconds);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("mod.py", "do_something", 6, CPyStatic_globals);
        goto CPyL9;
    }
    cpy_r_r19 = CPyStr_Build(2, cpy_r_r17, cpy_r_r18);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("mod.py", "do_something", 6, CPyStatic_globals);
        goto CPyL9;
    }
    return cpy_r_r19;
CPyL9: ;
    cpy_r_r20 = NULL;
    return cpy_r_r20;
CPyL10: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL9;
CPyL11: ;
    CPy_DECREF(cpy_r_r9);
    goto CPyL4;
CPyL12: ;
    CPy_DecRef(cpy_r_r13);
    goto CPyL9;
CPyL13: ;
    CPy_DECREF(cpy_r_r16);
    goto CPyL6;
}

PyObject *CPyPy_do_something(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"seconds", 0};
    static CPyArg_Parser parser = {"O:do_something", kwlist, 0};
    PyObject *obj_seconds;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_seconds)) {
        return NULL;
    }
    CPyTagged arg_seconds;
    if (likely(PyLong_Check(obj_seconds)))
        arg_seconds = CPyTagged_BorrowFromObject(obj_seconds);
    else {
        CPy_TypeError("int", obj_seconds); goto fail;
    }
    PyObject *retval = CPyDef_do_something(arg_seconds);
    return retval;
fail: ;
    CPy_AddTraceback("mod.py", "do_something", 3, CPyStatic_globals);
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
        CPy_AddTraceback("mod.py", "fib_C", 12, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r6 = CPyTagged_Subtract(cpy_r_n, 2);
    cpy_r_r7 = CPyDef_fib_C(cpy_r_r6);
    CPyTagged_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r7 == CPY_INT_TAG)) {
        CPy_AddTraceback("mod.py", "fib_C", 12, CPyStatic_globals);
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
    CPy_AddTraceback("mod.py", "fib_C", 8, CPyStatic_globals);
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
    char cpy_r_r15;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[8]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("mod.py", "<module>", -1, CPyStatic_globals);
        goto CPyL5;
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
    cpy_r_r10 = CPyStatics[13]; /* (('time', 'time', 'time'),) */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyStatics[10]; /* 'mod.py' */
    cpy_r_r13 = CPyStatics[11]; /* '<module>' */
    cpy_r_r14 = CPyImport_ImportMany(cpy_r_r10, cpy_r_r7, cpy_r_r11, cpy_r_r12, cpy_r_r13, cpy_r_r9);
    if (!cpy_r_r14) goto CPyL5;
    return 1;
CPyL5: ;
    cpy_r_r15 = 2;
    return cpy_r_r15;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_mod = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_time = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[14];
const char * const CPyLit_Str[] = {
    "\a\tSleeping \n second...\005print\005sleep\020Done Sleeping...\bbuiltins\004time",
    "\002\006mod.py\b<module>",
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
const int CPyLit_Tuple[] = {2, 3, 9, 9, 9, 1, 12};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_mod_internal = NULL;
CPyModule *CPyModule_mod;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_time;
PyObject *CPyDef_do_something(CPyTagged cpy_r_seconds);
PyObject *CPyPy_do_something(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
CPyTagged CPyDef_fib_C(CPyTagged cpy_r_n);
PyObject *CPyPy_fib_C(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);
