#ifndef MYPYC_NATIVE_INTERNAL_H
#define MYPYC_NATIVE_INTERNAL_H
#include <Python.h>
#include <CPy.h>
#include "__native.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[287];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_modTof_internal;
extern CPyModule *CPyModule_modTof;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_numpy;
extern CPyModule *CPyModule_pandas;
extern CPyModule *CPyModule_tqdm;
extern CPyModule *CPyModule_random;
extern CPyModule *CPyModule_time;
extern CPyModule *CPyModule_datetime;
extern CPyModule *CPyModule_multiprocessing;
extern CPyModule *CPyModule_gc;
extern CPyModule *CPyModule_scipy___stats;
extern CPyModule *CPyModule_os;
extern PyTypeObject *CPyType_Simulation;
extern PyObject *CPyDef_Simulation(void);
extern char CPyDef_Simulation_____init__(PyObject *cpy_r_self);
extern PyObject *CPyPy_Simulation_____init__(PyObject *self, PyObject *args, PyObject *kw);
extern PyObject *CPyDef_Simulation___round_to_sig(PyObject *cpy_r_self, PyObject *cpy_r_x);
extern PyObject *CPyPy_Simulation___round_to_sig(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Simulation___normalize(PyObject *cpy_r_self, PyObject *cpy_r_x);
extern PyObject *CPyPy_Simulation___normalize(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Simulation___lg_condition(PyObject *cpy_r_self, PyObject *cpy_r_corner_pt, PyObject *cpy_r_scint_corner, PyObject *cpy_r_scint_num);
extern PyObject *CPyPy_Simulation___lg_condition(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Simulation___scint_condition(PyObject *cpy_r_self, PyObject *cpy_r_corner_pt, PyObject *cpy_r_scint_radius, PyObject *cpy_r_scint_num);
extern PyObject *CPyPy_Simulation___scint_condition(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Simulation___distance_circle(PyObject *cpy_r_self, PyObject *cpy_r_u, PyObject *cpy_r_o, PyObject *cpy_r_center, PyObject *cpy_r_radius, PyObject *cpy_r_quadrant);
extern PyObject *CPyPy_Simulation___distance_circle(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Simulation___distance_plane(PyObject *cpy_r_self, PyObject *cpy_r_u, PyObject *cpy_r_o, PyObject *cpy_r_plane, PyObject *cpy_r_dim);
extern PyObject *CPyPy_Simulation___distance_plane(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Simulation___distance_solver(PyObject *cpy_r_self, PyObject *cpy_r_u, PyObject *cpy_r_o, PyObject *cpy_r_center, PyObject *cpy_r_radius, PyObject *cpy_r_plane_z, PyObject *cpy_r_corner_center, PyObject *cpy_r_corner_radius, PyObject *cpy_r_pmt_center, PyObject *cpy_r_pmt_radius);
extern PyObject *CPyPy_Simulation___distance_solver(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Simulation___photon_interaction(PyObject *cpy_r_self, PyObject *cpy_r_u, PyObject *cpy_r_n);
extern PyObject *CPyPy_Simulation___photon_interaction(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Simulation___n_vec_calculate(PyObject *cpy_r_self, PyObject *cpy_r_o, PyObject *cpy_r_scint_plane, PyObject *cpy_r_light_guide_planes, PyObject *cpy_r_corner_center, PyObject *cpy_r_corner_radius);
extern PyObject *CPyPy_Simulation___n_vec_calculate(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Simulation___particle_path(PyObject *cpy_r_self, PyObject *cpy_r_t, PyObject *cpy_r_phi_range_deg, PyObject *cpy_r_T1_z, PyObject *cpy_r_T1_width, PyObject *cpy_r_T4_z, PyObject *cpy_r_T4_width, PyObject *cpy_r_T1_radius, PyObject *cpy_r_T4_radius, PyObject *cpy_r_T1_corner, PyObject *cpy_r_T4_corner, PyObject *cpy_r_mean_free_path, PyObject *cpy_r_photons_per_E, PyObject *cpy_r_prob_scint);
extern PyObject *CPyPy_Simulation___particle_path(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Simulation___scintillator_monte_carlo(PyObject *cpy_r_self, PyObject *cpy_r_o, PyObject *cpy_r_notabsorbed, PyObject *cpy_r_scint_radius, PyObject *cpy_r_scint_plane, PyObject *cpy_r_light_guide_planes, PyObject *cpy_r_pmt_center, PyObject *cpy_r_pmt_radius, PyObject *cpy_r_corner_center, PyObject *cpy_r_corner_radius, PyObject *cpy_r_N_max, PyObject *cpy_r_t, PyObject *cpy_r_keepdata);
extern PyObject *CPyPy_Simulation___scintillator_monte_carlo(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Simulation___photontoElectrons(PyObject *cpy_r_self, PyObject *cpy_r_photons);
extern PyObject *CPyPy_Simulation___photontoElectrons(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Simulation___particle_task(PyObject *cpy_r_self, PyObject *cpy_r_mult);
extern PyObject *CPyPy_Simulation___particle_task(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Simulation___scint_taskT1(PyObject *cpy_r_self, PyObject *cpy_r_xpoint, PyObject *cpy_r_ypoint, PyObject *cpy_r_zpoint, PyObject *cpy_r_time_i);
extern PyObject *CPyPy_Simulation___scint_taskT1(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Simulation___scint_taskT4(PyObject *cpy_r_self, PyObject *cpy_r_xpoint, PyObject *cpy_r_ypoint, PyObject *cpy_r_zpoint, PyObject *cpy_r_time_i);
extern PyObject *CPyPy_Simulation___scint_taskT4(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Simulation___run(PyObject *cpy_r_self, PyObject *cpy_r_arg, PyObject *cpy_r_kwargs);
extern PyObject *CPyPy_Simulation___run(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Simulation___time_at_thresh(PyObject *cpy_r_self, PyObject *cpy_r_rawtime, PyObject *cpy_r_rawVoltage, PyObject *cpy_r_num, PyObject *cpy_r_thresh, PyObject *cpy_r_ch);
extern PyObject *CPyPy_Simulation___time_at_thresh(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Simulation___ToF_finalize(PyObject *cpy_r_self, PyObject *cpy_r_tofch1, PyObject *cpy_r_tofch4, PyObject *cpy_r_time_limit);
extern PyObject *CPyPy_Simulation___ToF_finalize(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Simulation___calc_ToF(PyObject *cpy_r_self, PyObject *cpy_r_filedate, PyObject *cpy_r_filenum);
extern PyObject *CPyPy_Simulation___calc_ToF(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef_Simulation___save_ToF(PyObject *cpy_r_self, PyObject *cpy_r_filename);
extern PyObject *CPyPy_Simulation___save_ToF(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
