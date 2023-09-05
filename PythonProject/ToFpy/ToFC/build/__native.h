#ifndef MYPYC_NATIVE_H
#define MYPYC_NATIVE_H
#include <Python.h>
#include <CPy.h>
#ifndef MYPYC_DECLARED_tuple_T2OO
#define MYPYC_DECLARED_tuple_T2OO
typedef struct tuple_T2OO {
    PyObject *f0;
    PyObject *f1;
} tuple_T2OO;
#endif

#ifndef MYPYC_DECLARED_tuple_T3OOO
#define MYPYC_DECLARED_tuple_T3OOO
typedef struct tuple_T3OOO {
    PyObject *f0;
    PyObject *f1;
    PyObject *f2;
} tuple_T3OOO;
#endif

#ifndef MYPYC_DECLARED_tuple_T5OOOOO
#define MYPYC_DECLARED_tuple_T5OOOOO
typedef struct tuple_T5OOOOO {
    PyObject *f0;
    PyObject *f1;
    PyObject *f2;
    PyObject *f3;
    PyObject *f4;
} tuple_T5OOOOO;
#endif

#ifndef MYPYC_DECLARED_tuple_T6OOOOOO
#define MYPYC_DECLARED_tuple_T6OOOOOO
typedef struct tuple_T6OOOOOO {
    PyObject *f0;
    PyObject *f1;
    PyObject *f2;
    PyObject *f3;
    PyObject *f4;
    PyObject *f5;
} tuple_T6OOOOOO;
#endif

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_c;
    PyObject *_q;
    PyObject *_n_1;
    PyObject *_n_2;
    PyObject *_T3z;
    PyObject *_T1z;
    PyObject *_T4z;
    PyObject *_T1_radius;
    PyObject *_T4_radius;
    PyObject *_T1_width;
    PyObject *_T4_width;
    PyObject *_T1top;
    PyObject *_T4top;
    PyObject *_T1_corner_radius;
    PyObject *_T4_corner_radius;
    PyObject *_T1_corner_center;
    PyObject *_T4_corner_center;
    PyObject *_PMT1_center;
    PyObject *_PMT4_center;
    PyObject *_xPMT4;
    PyObject *_yPMT4;
    PyObject *_xPMT1;
    PyObject *_yPMT1;
    PyObject *_PMT1_radius;
    PyObject *_PMT4_radius;
    PyObject *_n_dynodes;
    PyObject *_V;
    PyObject *_E_per_electron;
    PyObject *_QE;
    PyObject *_sigma_smoothing;
    PyObject *_t_initial;
    PyObject *_particle_init_angle_range;
    PyObject *_particle_gen_area;
    PyObject *_particle_gen_z;
    PyObject *_mean_free_path_scints;
    PyObject *_photons_produced_per_MeV;
    PyObject *_pr_of_scintillation;
    PyObject *_max_simulated_reflections;
    PyObject *_pmt_electron_travel_time;
    PyObject *_artificial_gain;
    PyObject *_max_pmt_current_output;
    PyObject *_pr_absorption;
    PyObject *_seperation_time;
    PyObject *_output_bin_width;
    PyObject *_num_particles;
    PyObject *_CMOS_thresh;
    PyObject *_reemission_angle_factor;
    PyObject *_T1_prop_dist;
    PyObject *_T4_prop_dist;
    PyObject *_T1_endpoint_dist;
    PyObject *_T4_endpoint_dist;
    PyObject *_T1_prop_times;
    PyObject *_T4_prop_times;
    PyObject *_T1_interactions;
    PyObject *_T4_interactions;
    PyObject *_T1_part_ids;
    PyObject *_T4_part_ids;
    PyObject *_signals;
    PyObject *_output_times;
    PyObject *_signals_channelT1;
    PyObject *_signals_channelT4;
    PyObject *_output_times_channelT1;
    PyObject *_output_times_channelT4;
    PyObject *_FinalToF;
} modTof___SimulationObject;

#endif
