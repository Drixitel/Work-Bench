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

static int
Bag_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return 0;
}
static PyObject *Bag_setup(PyTypeObject *type);
PyObject *CPyDef_Bag(void);

static PyObject *
Bag_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_Bag) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = Bag_setup(type);
    if (self == NULL)
        return NULL;
    PyObject *ret = CPyPy_Bag_____init__(self, args, kwds);
    if (ret == NULL)
        return NULL;
    return self;
}

static int
Bag_traverse(mod___BagObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->_data);
    if (CPyTagged_CheckLong(self->_x)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_x));
    }
    return 0;
}

static int
Bag_clear(mod___BagObject *self)
{
    Py_CLEAR(self->_data);
    if (CPyTagged_CheckLong(self->_x)) {
        CPyTagged __tmp = self->_x;
        self->_x = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    return 0;
}

static void
Bag_dealloc(mod___BagObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, Bag_dealloc)
    Bag_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem Bag_vtable[3];
static bool
CPyDef_Bag_trait_vtable_setup(void)
{
    CPyVTableItem Bag_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_Bag_____init__,
        (CPyVTableItem)CPyDef_Bag___add,
        (CPyVTableItem)CPyDef_Bag___addtwice,
    };
    memcpy(Bag_vtable, Bag_vtable_scratch, sizeof(Bag_vtable));
    return 1;
}

static PyObject *
Bag_get_data(mod___BagObject *self, void *closure);
static int
Bag_set_data(mod___BagObject *self, PyObject *value, void *closure);
static PyObject *
Bag_get_x(mod___BagObject *self, void *closure);
static int
Bag_set_x(mod___BagObject *self, PyObject *value, void *closure);

static PyGetSetDef Bag_getseters[] = {
    {"data",
     (getter)Bag_get_data, (setter)Bag_set_data,
     NULL, NULL},
    {"x",
     (getter)Bag_get_x, (setter)Bag_set_x,
     NULL, NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef Bag_methods[] = {
    {"__init__",
     (PyCFunction)CPyPy_Bag_____init__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"add",
     (PyCFunction)CPyPy_Bag___add,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"addtwice",
     (PyCFunction)CPyPy_Bag___addtwice,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_Bag_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "Bag",
    .tp_new = Bag_new,
    .tp_dealloc = (destructor)Bag_dealloc,
    .tp_traverse = (traverseproc)Bag_traverse,
    .tp_clear = (inquiry)Bag_clear,
    .tp_getset = Bag_getseters,
    .tp_methods = Bag_methods,
    .tp_init = Bag_init,
    .tp_basicsize = sizeof(mod___BagObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_Bag_template = &CPyType_Bag_template_;

static PyObject *
Bag_setup(PyTypeObject *type)
{
    mod___BagObject *self;
    self = (mod___BagObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = Bag_vtable;
    self->_x = CPY_INT_TAG;
    return (PyObject *)self;
}

PyObject *CPyDef_Bag(void)
{
    PyObject *self = Bag_setup(CPyType_Bag);
    if (self == NULL)
        return NULL;
    char res = CPyDef_Bag_____init__(self);
    if (res == 2) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
Bag_get_data(mod___BagObject *self, void *closure)
{
    if (unlikely(self->_data == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'data' of 'Bag' undefined");
        return NULL;
    }
    CPy_INCREF(self->_data);
    PyObject *retval = self->_data;
    return retval;
}

static int
Bag_set_data(mod___BagObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Bag' object attribute 'data' cannot be deleted");
        return -1;
    }
    if (self->_data != NULL) {
        CPy_DECREF(self->_data);
    }
    PyObject *tmp;
    if (likely(PyList_Check(value)))
        tmp = value;
    else {
        CPy_TypeError("list", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->_data = tmp;
    return 0;
}

static PyObject *
Bag_get_x(mod___BagObject *self, void *closure)
{
    if (unlikely(self->_x == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'x' of 'Bag' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->_x);
    PyObject *retval = CPyTagged_StealAsObject(self->_x);
    return retval;
}

static int
Bag_set_x(mod___BagObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Bag' object attribute 'x' cannot be deleted");
        return -1;
    }
    if (self->_x != CPY_INT_TAG) {
        CPyTagged_DECREF(self->_x);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->_x = tmp;
    return 0;
}
static PyMethodDef module_methods[] = {
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
    Py_CLEAR(CPyType_Bag);
    return NULL;
}

char CPyDef_Bag_____init__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    cpy_r_r0 = PyList_New(0);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("mod.py", "__init__", 7, CPyStatic_globals);
        goto CPyL2;
    }
    ((mod___BagObject *)cpy_r_self)->_data = cpy_r_r0;
    ((mod___BagObject *)cpy_r_self)->_x = 6;
    return 1;
CPyL2: ;
    cpy_r_r1 = 2;
    return cpy_r_r1;
}

PyObject *CPyPy_Bag_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "", "__init__", kwlist)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Bag))
        arg_self = obj_self;
    else {
        CPy_TypeError("mod.Bag", obj_self); 
        goto fail;
    }
    char retval = CPyDef_Bag_____init__(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("mod.py", "__init__", 6, CPyStatic_globals);
    return NULL;
}

char CPyDef_Bag___add(PyObject *cpy_r_self, PyObject *cpy_r_x) {
    PyObject *cpy_r_r0;
    int32_t cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    cpy_r_r0 = ((mod___BagObject *)cpy_r_self)->_data;
    CPy_INCREF(cpy_r_r0);
    cpy_r_r1 = PyList_Append(cpy_r_r0, cpy_r_x);
    CPy_DECREF(cpy_r_r0);
    cpy_r_r2 = cpy_r_r1 >= 0;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("mod.py", "add", 11, CPyStatic_globals);
        goto CPyL2;
    }
    return 1;
CPyL2: ;
    cpy_r_r3 = 2;
    return cpy_r_r3;
}

PyObject *CPyPy_Bag___add(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"x", 0};
    static CPyArg_Parser parser = {"O:add", kwlist, 0};
    PyObject *obj_x;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_x)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Bag))
        arg_self = obj_self;
    else {
        CPy_TypeError("mod.Bag", obj_self); 
        goto fail;
    }
    PyObject *arg_x;
    arg_x = obj_x;
    if (arg_x != NULL) goto __LL1;
    if (PyBool_Check(obj_x))
        arg_x = obj_x;
    else {
        arg_x = NULL;
    }
    if (arg_x != NULL) goto __LL1;
    if (PyLong_Check(obj_x))
        arg_x = obj_x;
    else {
        arg_x = NULL;
    }
    if (arg_x != NULL) goto __LL1;
    if (CPyFloat_Check(obj_x))
        arg_x = obj_x;
    else {
        arg_x = NULL;
    }
    if (arg_x != NULL) goto __LL1;
    if (PyUnicode_Check(obj_x))
        arg_x = obj_x;
    else {
        arg_x = NULL;
    }
    if (arg_x != NULL) goto __LL1;
    if (PyBytes_Check(obj_x) || PyByteArray_Check(obj_x))
        arg_x = obj_x;
    else {
        arg_x = NULL;
    }
    if (arg_x != NULL) goto __LL1;
    CPy_TypeError("union[object, bool, int, float, str, bytes]", obj_x); 
    goto fail;
__LL1: ;
    char retval = CPyDef_Bag___add(arg_self, arg_x);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("mod.py", "add", 10, CPyStatic_globals);
    return NULL;
}

char CPyDef_Bag___addtwice(PyObject *cpy_r_self, PyObject *cpy_r_x) {
    char cpy_r_r0;
    char cpy_r_r1;
    char cpy_r_r2;
    cpy_r_r0 = CPyDef_Bag___add(cpy_r_self, cpy_r_x);
    if (unlikely(cpy_r_r0 == 2)) {
        CPy_AddTraceback("mod.py", "addtwice", 14, CPyStatic_globals);
        goto CPyL3;
    }
    cpy_r_r1 = CPyDef_Bag___add(cpy_r_self, cpy_r_x);
    if (unlikely(cpy_r_r1 == 2)) {
        CPy_AddTraceback("mod.py", "addtwice", 15, CPyStatic_globals);
        goto CPyL3;
    }
    return 1;
CPyL3: ;
    cpy_r_r2 = 2;
    return cpy_r_r2;
}

PyObject *CPyPy_Bag___addtwice(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"x", 0};
    static CPyArg_Parser parser = {"O:addtwice", kwlist, 0};
    PyObject *obj_x;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_x)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Bag))
        arg_self = obj_self;
    else {
        CPy_TypeError("mod.Bag", obj_self); 
        goto fail;
    }
    PyObject *arg_x;
    arg_x = obj_x;
    if (arg_x != NULL) goto __LL2;
    if (PyBool_Check(obj_x))
        arg_x = obj_x;
    else {
        arg_x = NULL;
    }
    if (arg_x != NULL) goto __LL2;
    if (PyLong_Check(obj_x))
        arg_x = obj_x;
    else {
        arg_x = NULL;
    }
    if (arg_x != NULL) goto __LL2;
    if (CPyFloat_Check(obj_x))
        arg_x = obj_x;
    else {
        arg_x = NULL;
    }
    if (arg_x != NULL) goto __LL2;
    if (PyUnicode_Check(obj_x))
        arg_x = obj_x;
    else {
        arg_x = NULL;
    }
    if (arg_x != NULL) goto __LL2;
    if (PyBytes_Check(obj_x) || PyByteArray_Check(obj_x))
        arg_x = obj_x;
    else {
        arg_x = NULL;
    }
    if (arg_x != NULL) goto __LL2;
    CPy_TypeError("union[object, bool, int, float, str, bytes]", obj_x); 
    goto fail;
__LL2: ;
    char retval = CPyDef_Bag___addtwice(arg_self, arg_x);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("mod.py", "addtwice", 13, CPyStatic_globals);
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
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    char cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    int32_t cpy_r_r32;
    char cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    int32_t cpy_r_r36;
    char cpy_r_r37;
    char cpy_r_r38;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[3]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("mod.py", "<module>", -1, CPyStatic_globals);
        goto CPyL12;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_numpy;
    PyObject **cpy_r_r6[1] = {cpy_r_r5};
    cpy_r_r7 = (void *)&cpy_r_r6;
    int64_t cpy_r_r8[1] = {1};
    cpy_r_r9 = (void *)&cpy_r_r8;
    cpy_r_r10 = CPyStatics[19]; /* (('numpy', 'numpy', 'np'),) */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyStatics[6]; /* 'mod.py' */
    cpy_r_r13 = CPyStatics[7]; /* '<module>' */
    cpy_r_r14 = CPyImport_ImportMany(cpy_r_r10, cpy_r_r7, cpy_r_r11, cpy_r_r12, cpy_r_r13, cpy_r_r9);
    if (!cpy_r_r14) goto CPyL12;
    cpy_r_r15 = CPyStatics[20]; /* ('Union', 'List') */
    cpy_r_r16 = CPyStatics[10]; /* 'typing' */
    cpy_r_r17 = CPyStatic_globals;
    cpy_r_r18 = CPyImport_ImportFromMany(cpy_r_r16, cpy_r_r15, cpy_r_r15, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("mod.py", "<module>", 2, CPyStatic_globals);
        goto CPyL12;
    }
    CPyModule_typing = cpy_r_r18;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r18);
    cpy_r_r19 = CPyStatics[21]; /* ('ArrayLike',) */
    cpy_r_r20 = CPyStatics[12]; /* 'numpy.typing' */
    cpy_r_r21 = CPyStatic_globals;
    cpy_r_r22 = CPyImport_ImportFromMany(cpy_r_r20, cpy_r_r19, cpy_r_r19, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("mod.py", "<module>", 3, CPyStatic_globals);
        goto CPyL12;
    }
    CPyModule_numpy___typing = cpy_r_r22;
    CPy_INCREF(CPyModule_numpy___typing);
    CPy_DECREF(cpy_r_r22);
    cpy_r_r23 = NULL;
    cpy_r_r24 = CPyStatics[13]; /* 'mod' */
    cpy_r_r25 = (PyObject *)CPyType_Bag_template;
    cpy_r_r26 = CPyType_FromTemplate(cpy_r_r25, cpy_r_r23, cpy_r_r24);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("mod.py", "<module>", 5, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r27 = CPyDef_Bag_trait_vtable_setup();
    if (unlikely(cpy_r_r27 == 2)) {
        CPy_AddTraceback("mod.py", "<module>", -1, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r28 = CPyStatics[14]; /* '__mypyc_attrs__' */
    cpy_r_r29 = CPyStatics[15]; /* 'data' */
    cpy_r_r30 = CPyStatics[16]; /* 'x' */
    cpy_r_r31 = PyTuple_Pack(2, cpy_r_r29, cpy_r_r30);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("mod.py", "<module>", 5, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r32 = PyObject_SetAttr(cpy_r_r26, cpy_r_r28, cpy_r_r31);
    CPy_DECREF(cpy_r_r31);
    cpy_r_r33 = cpy_r_r32 >= 0;
    if (unlikely(!cpy_r_r33)) {
        CPy_AddTraceback("mod.py", "<module>", 5, CPyStatic_globals);
        goto CPyL13;
    }
    CPyType_Bag = (PyTypeObject *)cpy_r_r26;
    CPy_INCREF(CPyType_Bag);
    cpy_r_r34 = CPyStatic_globals;
    cpy_r_r35 = CPyStatics[17]; /* 'Bag' */
    cpy_r_r36 = CPyDict_SetItem(cpy_r_r34, cpy_r_r35, cpy_r_r26);
    CPy_DECREF(cpy_r_r26);
    cpy_r_r37 = cpy_r_r36 >= 0;
    if (unlikely(!cpy_r_r37)) {
        CPy_AddTraceback("mod.py", "<module>", 5, CPyStatic_globals);
        goto CPyL12;
    }
    return 1;
CPyL12: ;
    cpy_r_r38 = 2;
    return cpy_r_r38;
CPyL13: ;
    CPy_DecRef(cpy_r_r26);
    goto CPyL12;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_mod = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_numpy = Py_None;
    CPyModule_typing = Py_None;
    CPyModule_numpy___typing = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[22];
const char * const CPyLit_Str[] = {
    "\t\bbuiltins\005numpy\002np\006mod.py\b<module>\005Union\004List\006typing\tArrayLike",
    "\006\fnumpy.typing\003mod\017__mypyc_attrs__\004data\001x\003Bag",
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
const int CPyLit_Tuple[] = {4, 3, 4, 4, 5, 1, 18, 2, 8, 9, 1, 11};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_mod_internal = NULL;
CPyModule *CPyModule_mod;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_numpy;
CPyModule *CPyModule_typing;
CPyModule *CPyModule_numpy___typing;
PyTypeObject *CPyType_Bag;
PyObject *CPyDef_Bag(void);
char CPyDef_Bag_____init__(PyObject *cpy_r_self);
PyObject *CPyPy_Bag_____init__(PyObject *self, PyObject *args, PyObject *kw);
char CPyDef_Bag___add(PyObject *cpy_r_self, PyObject *cpy_r_x);
PyObject *CPyPy_Bag___add(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_Bag___addtwice(PyObject *cpy_r_self, PyObject *cpy_r_x);
PyObject *CPyPy_Bag___addtwice(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);
