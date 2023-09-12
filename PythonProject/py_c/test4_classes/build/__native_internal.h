#ifndef MYPYC_NATIVE_INTERNAL_H
#define MYPYC_NATIVE_INTERNAL_H
#include <Python.h>
#include <CPy.h>
#include "__native.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[22];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_mod_internal;
extern CPyModule *CPyModule_mod;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_numpy;
extern CPyModule *CPyModule_typing;
extern CPyModule *CPyModule_numpy___typing;
extern PyTypeObject *CPyType_Bag;
extern PyObject *CPyDef_Bag(void);
extern char CPyDef_Bag_____init__(PyObject *cpy_r_self);
extern PyObject *CPyPy_Bag_____init__(PyObject *self, PyObject *args, PyObject *kw);
extern char CPyDef_Bag___add(PyObject *cpy_r_self, PyObject *cpy_r_x);
extern PyObject *CPyPy_Bag___add(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_Bag___addtwice(PyObject *cpy_r_self, PyObject *cpy_r_x);
extern PyObject *CPyPy_Bag___addtwice(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
