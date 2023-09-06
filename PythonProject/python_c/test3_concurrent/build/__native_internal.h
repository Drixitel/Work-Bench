#ifndef MYPYC_NATIVE_INTERNAL_H
#define MYPYC_NATIVE_INTERNAL_H
#include <Python.h>
#include <CPy.h>
#include "__native.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[6];
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
extern CPyModule *CPyModule_random;
extern PyObject *CPyDef_f(PyObject *cpy_r_x);
extern PyObject *CPyPy_f(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern CPyTagged CPyDef_simulate(CPyTagged cpy_r_x, double cpy_r_p);
extern PyObject *CPyPy_simulate(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern CPyTagged CPyDef_run_simulation(PyObject *cpy_r_nums);
extern PyObject *CPyPy_run_simulation(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
