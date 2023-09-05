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
Simulation_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return 0;
}
static PyObject *Simulation_setup(PyTypeObject *type);
PyObject *CPyDef_Simulation(void);

static PyObject *
Simulation_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_Simulation) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = Simulation_setup(type);
    if (self == NULL)
        return NULL;
    PyObject *ret = CPyPy_Simulation_____init__(self, args, kwds);
    if (ret == NULL)
        return NULL;
    return self;
}

static int
Simulation_traverse(modTof___SimulationObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->_c);
    Py_VISIT(self->_q);
    Py_VISIT(self->_n_1);
    Py_VISIT(self->_n_2);
    Py_VISIT(self->_T3z);
    Py_VISIT(self->_T1z);
    Py_VISIT(self->_T4z);
    Py_VISIT(self->_T1_radius);
    Py_VISIT(self->_T4_radius);
    Py_VISIT(self->_T1_width);
    Py_VISIT(self->_T4_width);
    Py_VISIT(self->_T1top);
    Py_VISIT(self->_T4top);
    Py_VISIT(self->_T1_corner_radius);
    Py_VISIT(self->_T4_corner_radius);
    Py_VISIT(self->_T1_corner_center);
    Py_VISIT(self->_T4_corner_center);
    Py_VISIT(self->_PMT1_center);
    Py_VISIT(self->_PMT4_center);
    Py_VISIT(self->_xPMT4);
    Py_VISIT(self->_yPMT4);
    Py_VISIT(self->_xPMT1);
    Py_VISIT(self->_yPMT1);
    Py_VISIT(self->_PMT1_radius);
    Py_VISIT(self->_PMT4_radius);
    Py_VISIT(self->_n_dynodes);
    Py_VISIT(self->_V);
    Py_VISIT(self->_E_per_electron);
    Py_VISIT(self->_QE);
    Py_VISIT(self->_sigma_smoothing);
    Py_VISIT(self->_t_initial);
    Py_VISIT(self->_particle_init_angle_range);
    Py_VISIT(self->_particle_gen_area);
    Py_VISIT(self->_particle_gen_z);
    Py_VISIT(self->_mean_free_path_scints);
    Py_VISIT(self->_photons_produced_per_MeV);
    Py_VISIT(self->_pr_of_scintillation);
    Py_VISIT(self->_max_simulated_reflections);
    Py_VISIT(self->_pmt_electron_travel_time);
    Py_VISIT(self->_artificial_gain);
    Py_VISIT(self->_max_pmt_current_output);
    Py_VISIT(self->_pr_absorption);
    Py_VISIT(self->_seperation_time);
    Py_VISIT(self->_output_bin_width);
    Py_VISIT(self->_num_particles);
    Py_VISIT(self->_CMOS_thresh);
    Py_VISIT(self->_reemission_angle_factor);
    Py_VISIT(self->_T1_prop_dist);
    Py_VISIT(self->_T4_prop_dist);
    Py_VISIT(self->_T1_endpoint_dist);
    Py_VISIT(self->_T4_endpoint_dist);
    Py_VISIT(self->_T1_prop_times);
    Py_VISIT(self->_T4_prop_times);
    Py_VISIT(self->_T1_interactions);
    Py_VISIT(self->_T4_interactions);
    Py_VISIT(self->_T1_part_ids);
    Py_VISIT(self->_T4_part_ids);
    Py_VISIT(self->_signals);
    Py_VISIT(self->_output_times);
    Py_VISIT(self->_signals_channelT1);
    Py_VISIT(self->_signals_channelT4);
    Py_VISIT(self->_output_times_channelT1);
    Py_VISIT(self->_output_times_channelT4);
    Py_VISIT(self->_FinalToF);
    return 0;
}

static int
Simulation_clear(modTof___SimulationObject *self)
{
    Py_CLEAR(self->_c);
    Py_CLEAR(self->_q);
    Py_CLEAR(self->_n_1);
    Py_CLEAR(self->_n_2);
    Py_CLEAR(self->_T3z);
    Py_CLEAR(self->_T1z);
    Py_CLEAR(self->_T4z);
    Py_CLEAR(self->_T1_radius);
    Py_CLEAR(self->_T4_radius);
    Py_CLEAR(self->_T1_width);
    Py_CLEAR(self->_T4_width);
    Py_CLEAR(self->_T1top);
    Py_CLEAR(self->_T4top);
    Py_CLEAR(self->_T1_corner_radius);
    Py_CLEAR(self->_T4_corner_radius);
    Py_CLEAR(self->_T1_corner_center);
    Py_CLEAR(self->_T4_corner_center);
    Py_CLEAR(self->_PMT1_center);
    Py_CLEAR(self->_PMT4_center);
    Py_CLEAR(self->_xPMT4);
    Py_CLEAR(self->_yPMT4);
    Py_CLEAR(self->_xPMT1);
    Py_CLEAR(self->_yPMT1);
    Py_CLEAR(self->_PMT1_radius);
    Py_CLEAR(self->_PMT4_radius);
    Py_CLEAR(self->_n_dynodes);
    Py_CLEAR(self->_V);
    Py_CLEAR(self->_E_per_electron);
    Py_CLEAR(self->_QE);
    Py_CLEAR(self->_sigma_smoothing);
    Py_CLEAR(self->_t_initial);
    Py_CLEAR(self->_particle_init_angle_range);
    Py_CLEAR(self->_particle_gen_area);
    Py_CLEAR(self->_particle_gen_z);
    Py_CLEAR(self->_mean_free_path_scints);
    Py_CLEAR(self->_photons_produced_per_MeV);
    Py_CLEAR(self->_pr_of_scintillation);
    Py_CLEAR(self->_max_simulated_reflections);
    Py_CLEAR(self->_pmt_electron_travel_time);
    Py_CLEAR(self->_artificial_gain);
    Py_CLEAR(self->_max_pmt_current_output);
    Py_CLEAR(self->_pr_absorption);
    Py_CLEAR(self->_seperation_time);
    Py_CLEAR(self->_output_bin_width);
    Py_CLEAR(self->_num_particles);
    Py_CLEAR(self->_CMOS_thresh);
    Py_CLEAR(self->_reemission_angle_factor);
    Py_CLEAR(self->_T1_prop_dist);
    Py_CLEAR(self->_T4_prop_dist);
    Py_CLEAR(self->_T1_endpoint_dist);
    Py_CLEAR(self->_T4_endpoint_dist);
    Py_CLEAR(self->_T1_prop_times);
    Py_CLEAR(self->_T4_prop_times);
    Py_CLEAR(self->_T1_interactions);
    Py_CLEAR(self->_T4_interactions);
    Py_CLEAR(self->_T1_part_ids);
    Py_CLEAR(self->_T4_part_ids);
    Py_CLEAR(self->_signals);
    Py_CLEAR(self->_output_times);
    Py_CLEAR(self->_signals_channelT1);
    Py_CLEAR(self->_signals_channelT4);
    Py_CLEAR(self->_output_times_channelT1);
    Py_CLEAR(self->_output_times_channelT4);
    Py_CLEAR(self->_FinalToF);
    return 0;
}

static void
Simulation_dealloc(modTof___SimulationObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, Simulation_dealloc)
    Simulation_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem Simulation_vtable[21];
static bool
CPyDef_Simulation_trait_vtable_setup(void)
{
    CPyVTableItem Simulation_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_Simulation_____init__,
        (CPyVTableItem)CPyDef_Simulation___round_to_sig,
        (CPyVTableItem)CPyDef_Simulation___normalize,
        (CPyVTableItem)CPyDef_Simulation___lg_condition,
        (CPyVTableItem)CPyDef_Simulation___scint_condition,
        (CPyVTableItem)CPyDef_Simulation___distance_circle,
        (CPyVTableItem)CPyDef_Simulation___distance_plane,
        (CPyVTableItem)CPyDef_Simulation___distance_solver,
        (CPyVTableItem)CPyDef_Simulation___photon_interaction,
        (CPyVTableItem)CPyDef_Simulation___n_vec_calculate,
        (CPyVTableItem)CPyDef_Simulation___particle_path,
        (CPyVTableItem)CPyDef_Simulation___scintillator_monte_carlo,
        (CPyVTableItem)CPyDef_Simulation___photontoElectrons,
        (CPyVTableItem)CPyDef_Simulation___particle_task,
        (CPyVTableItem)CPyDef_Simulation___scint_taskT1,
        (CPyVTableItem)CPyDef_Simulation___scint_taskT4,
        (CPyVTableItem)CPyDef_Simulation___run,
        (CPyVTableItem)CPyDef_Simulation___time_at_thresh,
        (CPyVTableItem)CPyDef_Simulation___ToF_finalize,
        (CPyVTableItem)CPyDef_Simulation___calc_ToF,
        (CPyVTableItem)CPyDef_Simulation___save_ToF,
    };
    memcpy(Simulation_vtable, Simulation_vtable_scratch, sizeof(Simulation_vtable));
    return 1;
}

static PyObject *
Simulation_get_c(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_c(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_q(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_q(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_n_1(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_n_1(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_n_2(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_n_2(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T3z(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T3z(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T1z(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T1z(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T4z(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T4z(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T1_radius(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T1_radius(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T4_radius(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T4_radius(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T1_width(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T1_width(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T4_width(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T4_width(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T1top(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T1top(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T4top(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T4top(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T1_corner_radius(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T1_corner_radius(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T4_corner_radius(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T4_corner_radius(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T1_corner_center(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T1_corner_center(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T4_corner_center(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T4_corner_center(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_PMT1_center(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_PMT1_center(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_PMT4_center(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_PMT4_center(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_xPMT4(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_xPMT4(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_yPMT4(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_yPMT4(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_xPMT1(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_xPMT1(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_yPMT1(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_yPMT1(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_PMT1_radius(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_PMT1_radius(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_PMT4_radius(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_PMT4_radius(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_n_dynodes(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_n_dynodes(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_V(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_V(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_E_per_electron(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_E_per_electron(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_QE(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_QE(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_sigma_smoothing(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_sigma_smoothing(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_t_initial(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_t_initial(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_particle_init_angle_range(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_particle_init_angle_range(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_particle_gen_area(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_particle_gen_area(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_particle_gen_z(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_particle_gen_z(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_mean_free_path_scints(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_mean_free_path_scints(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_photons_produced_per_MeV(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_photons_produced_per_MeV(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_pr_of_scintillation(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_pr_of_scintillation(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_max_simulated_reflections(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_max_simulated_reflections(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_pmt_electron_travel_time(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_pmt_electron_travel_time(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_artificial_gain(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_artificial_gain(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_max_pmt_current_output(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_max_pmt_current_output(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_pr_absorption(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_pr_absorption(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_seperation_time(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_seperation_time(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_output_bin_width(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_output_bin_width(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_num_particles(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_num_particles(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_CMOS_thresh(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_CMOS_thresh(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_reemission_angle_factor(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_reemission_angle_factor(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T1_prop_dist(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T1_prop_dist(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T4_prop_dist(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T4_prop_dist(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T1_endpoint_dist(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T1_endpoint_dist(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T4_endpoint_dist(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T4_endpoint_dist(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T1_prop_times(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T1_prop_times(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T4_prop_times(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T4_prop_times(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T1_interactions(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T1_interactions(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T4_interactions(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T4_interactions(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T1_part_ids(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T1_part_ids(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_T4_part_ids(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_T4_part_ids(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_signals(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_signals(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_output_times(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_output_times(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_signals_channelT1(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_signals_channelT1(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_signals_channelT4(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_signals_channelT4(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_output_times_channelT1(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_output_times_channelT1(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_output_times_channelT4(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_output_times_channelT4(modTof___SimulationObject *self, PyObject *value, void *closure);
static PyObject *
Simulation_get_FinalToF(modTof___SimulationObject *self, void *closure);
static int
Simulation_set_FinalToF(modTof___SimulationObject *self, PyObject *value, void *closure);

static PyGetSetDef Simulation_getseters[] = {
    {"c",
     (getter)Simulation_get_c, (setter)Simulation_set_c,
     NULL, NULL},
    {"q",
     (getter)Simulation_get_q, (setter)Simulation_set_q,
     NULL, NULL},
    {"n_1",
     (getter)Simulation_get_n_1, (setter)Simulation_set_n_1,
     NULL, NULL},
    {"n_2",
     (getter)Simulation_get_n_2, (setter)Simulation_set_n_2,
     NULL, NULL},
    {"T3z",
     (getter)Simulation_get_T3z, (setter)Simulation_set_T3z,
     NULL, NULL},
    {"T1z",
     (getter)Simulation_get_T1z, (setter)Simulation_set_T1z,
     NULL, NULL},
    {"T4z",
     (getter)Simulation_get_T4z, (setter)Simulation_set_T4z,
     NULL, NULL},
    {"T1_radius",
     (getter)Simulation_get_T1_radius, (setter)Simulation_set_T1_radius,
     NULL, NULL},
    {"T4_radius",
     (getter)Simulation_get_T4_radius, (setter)Simulation_set_T4_radius,
     NULL, NULL},
    {"T1_width",
     (getter)Simulation_get_T1_width, (setter)Simulation_set_T1_width,
     NULL, NULL},
    {"T4_width",
     (getter)Simulation_get_T4_width, (setter)Simulation_set_T4_width,
     NULL, NULL},
    {"T1top",
     (getter)Simulation_get_T1top, (setter)Simulation_set_T1top,
     NULL, NULL},
    {"T4top",
     (getter)Simulation_get_T4top, (setter)Simulation_set_T4top,
     NULL, NULL},
    {"T1_corner_radius",
     (getter)Simulation_get_T1_corner_radius, (setter)Simulation_set_T1_corner_radius,
     NULL, NULL},
    {"T4_corner_radius",
     (getter)Simulation_get_T4_corner_radius, (setter)Simulation_set_T4_corner_radius,
     NULL, NULL},
    {"T1_corner_center",
     (getter)Simulation_get_T1_corner_center, (setter)Simulation_set_T1_corner_center,
     NULL, NULL},
    {"T4_corner_center",
     (getter)Simulation_get_T4_corner_center, (setter)Simulation_set_T4_corner_center,
     NULL, NULL},
    {"PMT1_center",
     (getter)Simulation_get_PMT1_center, (setter)Simulation_set_PMT1_center,
     NULL, NULL},
    {"PMT4_center",
     (getter)Simulation_get_PMT4_center, (setter)Simulation_set_PMT4_center,
     NULL, NULL},
    {"xPMT4",
     (getter)Simulation_get_xPMT4, (setter)Simulation_set_xPMT4,
     NULL, NULL},
    {"yPMT4",
     (getter)Simulation_get_yPMT4, (setter)Simulation_set_yPMT4,
     NULL, NULL},
    {"xPMT1",
     (getter)Simulation_get_xPMT1, (setter)Simulation_set_xPMT1,
     NULL, NULL},
    {"yPMT1",
     (getter)Simulation_get_yPMT1, (setter)Simulation_set_yPMT1,
     NULL, NULL},
    {"PMT1_radius",
     (getter)Simulation_get_PMT1_radius, (setter)Simulation_set_PMT1_radius,
     NULL, NULL},
    {"PMT4_radius",
     (getter)Simulation_get_PMT4_radius, (setter)Simulation_set_PMT4_radius,
     NULL, NULL},
    {"n_dynodes",
     (getter)Simulation_get_n_dynodes, (setter)Simulation_set_n_dynodes,
     NULL, NULL},
    {"V",
     (getter)Simulation_get_V, (setter)Simulation_set_V,
     NULL, NULL},
    {"E_per_electron",
     (getter)Simulation_get_E_per_electron, (setter)Simulation_set_E_per_electron,
     NULL, NULL},
    {"QE",
     (getter)Simulation_get_QE, (setter)Simulation_set_QE,
     NULL, NULL},
    {"sigma_smoothing",
     (getter)Simulation_get_sigma_smoothing, (setter)Simulation_set_sigma_smoothing,
     NULL, NULL},
    {"t_initial",
     (getter)Simulation_get_t_initial, (setter)Simulation_set_t_initial,
     NULL, NULL},
    {"particle_init_angle_range",
     (getter)Simulation_get_particle_init_angle_range, (setter)Simulation_set_particle_init_angle_range,
     NULL, NULL},
    {"particle_gen_area",
     (getter)Simulation_get_particle_gen_area, (setter)Simulation_set_particle_gen_area,
     NULL, NULL},
    {"particle_gen_z",
     (getter)Simulation_get_particle_gen_z, (setter)Simulation_set_particle_gen_z,
     NULL, NULL},
    {"mean_free_path_scints",
     (getter)Simulation_get_mean_free_path_scints, (setter)Simulation_set_mean_free_path_scints,
     NULL, NULL},
    {"photons_produced_per_MeV",
     (getter)Simulation_get_photons_produced_per_MeV, (setter)Simulation_set_photons_produced_per_MeV,
     NULL, NULL},
    {"pr_of_scintillation",
     (getter)Simulation_get_pr_of_scintillation, (setter)Simulation_set_pr_of_scintillation,
     NULL, NULL},
    {"max_simulated_reflections",
     (getter)Simulation_get_max_simulated_reflections, (setter)Simulation_set_max_simulated_reflections,
     NULL, NULL},
    {"pmt_electron_travel_time",
     (getter)Simulation_get_pmt_electron_travel_time, (setter)Simulation_set_pmt_electron_travel_time,
     NULL, NULL},
    {"artificial_gain",
     (getter)Simulation_get_artificial_gain, (setter)Simulation_set_artificial_gain,
     NULL, NULL},
    {"max_pmt_current_output",
     (getter)Simulation_get_max_pmt_current_output, (setter)Simulation_set_max_pmt_current_output,
     NULL, NULL},
    {"pr_absorption",
     (getter)Simulation_get_pr_absorption, (setter)Simulation_set_pr_absorption,
     NULL, NULL},
    {"seperation_time",
     (getter)Simulation_get_seperation_time, (setter)Simulation_set_seperation_time,
     NULL, NULL},
    {"output_bin_width",
     (getter)Simulation_get_output_bin_width, (setter)Simulation_set_output_bin_width,
     NULL, NULL},
    {"num_particles",
     (getter)Simulation_get_num_particles, (setter)Simulation_set_num_particles,
     NULL, NULL},
    {"CMOS_thresh",
     (getter)Simulation_get_CMOS_thresh, (setter)Simulation_set_CMOS_thresh,
     NULL, NULL},
    {"reemission_angle_factor",
     (getter)Simulation_get_reemission_angle_factor, (setter)Simulation_set_reemission_angle_factor,
     NULL, NULL},
    {"T1_prop_dist",
     (getter)Simulation_get_T1_prop_dist, (setter)Simulation_set_T1_prop_dist,
     NULL, NULL},
    {"T4_prop_dist",
     (getter)Simulation_get_T4_prop_dist, (setter)Simulation_set_T4_prop_dist,
     NULL, NULL},
    {"T1_endpoint_dist",
     (getter)Simulation_get_T1_endpoint_dist, (setter)Simulation_set_T1_endpoint_dist,
     NULL, NULL},
    {"T4_endpoint_dist",
     (getter)Simulation_get_T4_endpoint_dist, (setter)Simulation_set_T4_endpoint_dist,
     NULL, NULL},
    {"T1_prop_times",
     (getter)Simulation_get_T1_prop_times, (setter)Simulation_set_T1_prop_times,
     NULL, NULL},
    {"T4_prop_times",
     (getter)Simulation_get_T4_prop_times, (setter)Simulation_set_T4_prop_times,
     NULL, NULL},
    {"T1_interactions",
     (getter)Simulation_get_T1_interactions, (setter)Simulation_set_T1_interactions,
     NULL, NULL},
    {"T4_interactions",
     (getter)Simulation_get_T4_interactions, (setter)Simulation_set_T4_interactions,
     NULL, NULL},
    {"T1_part_ids",
     (getter)Simulation_get_T1_part_ids, (setter)Simulation_set_T1_part_ids,
     NULL, NULL},
    {"T4_part_ids",
     (getter)Simulation_get_T4_part_ids, (setter)Simulation_set_T4_part_ids,
     NULL, NULL},
    {"signals",
     (getter)Simulation_get_signals, (setter)Simulation_set_signals,
     NULL, NULL},
    {"output_times",
     (getter)Simulation_get_output_times, (setter)Simulation_set_output_times,
     NULL, NULL},
    {"signals_channelT1",
     (getter)Simulation_get_signals_channelT1, (setter)Simulation_set_signals_channelT1,
     NULL, NULL},
    {"signals_channelT4",
     (getter)Simulation_get_signals_channelT4, (setter)Simulation_set_signals_channelT4,
     NULL, NULL},
    {"output_times_channelT1",
     (getter)Simulation_get_output_times_channelT1, (setter)Simulation_set_output_times_channelT1,
     NULL, NULL},
    {"output_times_channelT4",
     (getter)Simulation_get_output_times_channelT4, (setter)Simulation_set_output_times_channelT4,
     NULL, NULL},
    {"FinalToF",
     (getter)Simulation_get_FinalToF, (setter)Simulation_set_FinalToF,
     NULL, NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef Simulation_methods[] = {
    {"__init__",
     (PyCFunction)CPyPy_Simulation_____init__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"round_to_sig",
     (PyCFunction)CPyPy_Simulation___round_to_sig,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"normalize",
     (PyCFunction)CPyPy_Simulation___normalize,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"lg_condition",
     (PyCFunction)CPyPy_Simulation___lg_condition,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"scint_condition",
     (PyCFunction)CPyPy_Simulation___scint_condition,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"distance_circle",
     (PyCFunction)CPyPy_Simulation___distance_circle,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"distance_plane",
     (PyCFunction)CPyPy_Simulation___distance_plane,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"distance_solver",
     (PyCFunction)CPyPy_Simulation___distance_solver,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"photon_interaction",
     (PyCFunction)CPyPy_Simulation___photon_interaction,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"n_vec_calculate",
     (PyCFunction)CPyPy_Simulation___n_vec_calculate,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"particle_path",
     (PyCFunction)CPyPy_Simulation___particle_path,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"scintillator_monte_carlo",
     (PyCFunction)CPyPy_Simulation___scintillator_monte_carlo,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"photontoElectrons",
     (PyCFunction)CPyPy_Simulation___photontoElectrons,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"particle_task",
     (PyCFunction)CPyPy_Simulation___particle_task,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"scint_taskT1",
     (PyCFunction)CPyPy_Simulation___scint_taskT1,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"scint_taskT4",
     (PyCFunction)CPyPy_Simulation___scint_taskT4,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"run",
     (PyCFunction)CPyPy_Simulation___run,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"time_at_thresh",
     (PyCFunction)CPyPy_Simulation___time_at_thresh,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"ToF_finalize",
     (PyCFunction)CPyPy_Simulation___ToF_finalize,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"calc_ToF",
     (PyCFunction)CPyPy_Simulation___calc_ToF,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"save_ToF",
     (PyCFunction)CPyPy_Simulation___save_ToF,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_Simulation_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "Simulation",
    .tp_new = Simulation_new,
    .tp_dealloc = (destructor)Simulation_dealloc,
    .tp_traverse = (traverseproc)Simulation_traverse,
    .tp_clear = (inquiry)Simulation_clear,
    .tp_getset = Simulation_getseters,
    .tp_methods = Simulation_methods,
    .tp_init = Simulation_init,
    .tp_basicsize = sizeof(modTof___SimulationObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_Simulation_template = &CPyType_Simulation_template_;

static PyObject *
Simulation_setup(PyTypeObject *type)
{
    modTof___SimulationObject *self;
    self = (modTof___SimulationObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = Simulation_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_Simulation(void)
{
    PyObject *self = Simulation_setup(CPyType_Simulation);
    if (self == NULL)
        return NULL;
    char res = CPyDef_Simulation_____init__(self);
    if (res == 2) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
Simulation_get_c(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_c == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'c' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_c);
    PyObject *retval = self->_c;
    return retval;
}

static int
Simulation_set_c(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'c' cannot be deleted");
        return -1;
    }
    if (self->_c != NULL) {
        CPy_DECREF(self->_c);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_c = tmp;
    return 0;
}

static PyObject *
Simulation_get_q(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_q == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'q' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_q);
    PyObject *retval = self->_q;
    return retval;
}

static int
Simulation_set_q(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'q' cannot be deleted");
        return -1;
    }
    if (self->_q != NULL) {
        CPy_DECREF(self->_q);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_q = tmp;
    return 0;
}

static PyObject *
Simulation_get_n_1(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_n_1 == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'n_1' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_n_1);
    PyObject *retval = self->_n_1;
    return retval;
}

static int
Simulation_set_n_1(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'n_1' cannot be deleted");
        return -1;
    }
    if (self->_n_1 != NULL) {
        CPy_DECREF(self->_n_1);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_n_1 = tmp;
    return 0;
}

static PyObject *
Simulation_get_n_2(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_n_2 == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'n_2' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_n_2);
    PyObject *retval = self->_n_2;
    return retval;
}

static int
Simulation_set_n_2(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'n_2' cannot be deleted");
        return -1;
    }
    if (self->_n_2 != NULL) {
        CPy_DECREF(self->_n_2);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_n_2 = tmp;
    return 0;
}

static PyObject *
Simulation_get_T3z(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T3z == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T3z' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T3z);
    PyObject *retval = self->_T3z;
    return retval;
}

static int
Simulation_set_T3z(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T3z' cannot be deleted");
        return -1;
    }
    if (self->_T3z != NULL) {
        CPy_DECREF(self->_T3z);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T3z = tmp;
    return 0;
}

static PyObject *
Simulation_get_T1z(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T1z == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T1z' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T1z);
    PyObject *retval = self->_T1z;
    return retval;
}

static int
Simulation_set_T1z(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T1z' cannot be deleted");
        return -1;
    }
    if (self->_T1z != NULL) {
        CPy_DECREF(self->_T1z);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T1z = tmp;
    return 0;
}

static PyObject *
Simulation_get_T4z(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T4z == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T4z' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T4z);
    PyObject *retval = self->_T4z;
    return retval;
}

static int
Simulation_set_T4z(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T4z' cannot be deleted");
        return -1;
    }
    if (self->_T4z != NULL) {
        CPy_DECREF(self->_T4z);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T4z = tmp;
    return 0;
}

static PyObject *
Simulation_get_T1_radius(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T1_radius == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T1_radius' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T1_radius);
    PyObject *retval = self->_T1_radius;
    return retval;
}

static int
Simulation_set_T1_radius(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T1_radius' cannot be deleted");
        return -1;
    }
    if (self->_T1_radius != NULL) {
        CPy_DECREF(self->_T1_radius);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T1_radius = tmp;
    return 0;
}

static PyObject *
Simulation_get_T4_radius(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T4_radius == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T4_radius' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T4_radius);
    PyObject *retval = self->_T4_radius;
    return retval;
}

static int
Simulation_set_T4_radius(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T4_radius' cannot be deleted");
        return -1;
    }
    if (self->_T4_radius != NULL) {
        CPy_DECREF(self->_T4_radius);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T4_radius = tmp;
    return 0;
}

static PyObject *
Simulation_get_T1_width(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T1_width == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T1_width' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T1_width);
    PyObject *retval = self->_T1_width;
    return retval;
}

static int
Simulation_set_T1_width(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T1_width' cannot be deleted");
        return -1;
    }
    if (self->_T1_width != NULL) {
        CPy_DECREF(self->_T1_width);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T1_width = tmp;
    return 0;
}

static PyObject *
Simulation_get_T4_width(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T4_width == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T4_width' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T4_width);
    PyObject *retval = self->_T4_width;
    return retval;
}

static int
Simulation_set_T4_width(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T4_width' cannot be deleted");
        return -1;
    }
    if (self->_T4_width != NULL) {
        CPy_DECREF(self->_T4_width);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T4_width = tmp;
    return 0;
}

static PyObject *
Simulation_get_T1top(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T1top == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T1top' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T1top);
    PyObject *retval = self->_T1top;
    return retval;
}

static int
Simulation_set_T1top(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T1top' cannot be deleted");
        return -1;
    }
    if (self->_T1top != NULL) {
        CPy_DECREF(self->_T1top);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T1top = tmp;
    return 0;
}

static PyObject *
Simulation_get_T4top(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T4top == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T4top' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T4top);
    PyObject *retval = self->_T4top;
    return retval;
}

static int
Simulation_set_T4top(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T4top' cannot be deleted");
        return -1;
    }
    if (self->_T4top != NULL) {
        CPy_DECREF(self->_T4top);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T4top = tmp;
    return 0;
}

static PyObject *
Simulation_get_T1_corner_radius(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T1_corner_radius == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T1_corner_radius' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T1_corner_radius);
    PyObject *retval = self->_T1_corner_radius;
    return retval;
}

static int
Simulation_set_T1_corner_radius(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T1_corner_radius' cannot be deleted");
        return -1;
    }
    if (self->_T1_corner_radius != NULL) {
        CPy_DECREF(self->_T1_corner_radius);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T1_corner_radius = tmp;
    return 0;
}

static PyObject *
Simulation_get_T4_corner_radius(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T4_corner_radius == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T4_corner_radius' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T4_corner_radius);
    PyObject *retval = self->_T4_corner_radius;
    return retval;
}

static int
Simulation_set_T4_corner_radius(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T4_corner_radius' cannot be deleted");
        return -1;
    }
    if (self->_T4_corner_radius != NULL) {
        CPy_DECREF(self->_T4_corner_radius);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T4_corner_radius = tmp;
    return 0;
}

static PyObject *
Simulation_get_T1_corner_center(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T1_corner_center == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T1_corner_center' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T1_corner_center);
    PyObject *retval = self->_T1_corner_center;
    return retval;
}

static int
Simulation_set_T1_corner_center(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T1_corner_center' cannot be deleted");
        return -1;
    }
    if (self->_T1_corner_center != NULL) {
        CPy_DECREF(self->_T1_corner_center);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T1_corner_center = tmp;
    return 0;
}

static PyObject *
Simulation_get_T4_corner_center(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T4_corner_center == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T4_corner_center' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T4_corner_center);
    PyObject *retval = self->_T4_corner_center;
    return retval;
}

static int
Simulation_set_T4_corner_center(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T4_corner_center' cannot be deleted");
        return -1;
    }
    if (self->_T4_corner_center != NULL) {
        CPy_DECREF(self->_T4_corner_center);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T4_corner_center = tmp;
    return 0;
}

static PyObject *
Simulation_get_PMT1_center(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_PMT1_center == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'PMT1_center' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_PMT1_center);
    PyObject *retval = self->_PMT1_center;
    return retval;
}

static int
Simulation_set_PMT1_center(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'PMT1_center' cannot be deleted");
        return -1;
    }
    if (self->_PMT1_center != NULL) {
        CPy_DECREF(self->_PMT1_center);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_PMT1_center = tmp;
    return 0;
}

static PyObject *
Simulation_get_PMT4_center(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_PMT4_center == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'PMT4_center' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_PMT4_center);
    PyObject *retval = self->_PMT4_center;
    return retval;
}

static int
Simulation_set_PMT4_center(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'PMT4_center' cannot be deleted");
        return -1;
    }
    if (self->_PMT4_center != NULL) {
        CPy_DECREF(self->_PMT4_center);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_PMT4_center = tmp;
    return 0;
}

static PyObject *
Simulation_get_xPMT4(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_xPMT4 == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'xPMT4' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_xPMT4);
    PyObject *retval = self->_xPMT4;
    return retval;
}

static int
Simulation_set_xPMT4(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'xPMT4' cannot be deleted");
        return -1;
    }
    if (self->_xPMT4 != NULL) {
        CPy_DECREF(self->_xPMT4);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_xPMT4 = tmp;
    return 0;
}

static PyObject *
Simulation_get_yPMT4(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_yPMT4 == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'yPMT4' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_yPMT4);
    PyObject *retval = self->_yPMT4;
    return retval;
}

static int
Simulation_set_yPMT4(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'yPMT4' cannot be deleted");
        return -1;
    }
    if (self->_yPMT4 != NULL) {
        CPy_DECREF(self->_yPMT4);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_yPMT4 = tmp;
    return 0;
}

static PyObject *
Simulation_get_xPMT1(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_xPMT1 == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'xPMT1' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_xPMT1);
    PyObject *retval = self->_xPMT1;
    return retval;
}

static int
Simulation_set_xPMT1(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'xPMT1' cannot be deleted");
        return -1;
    }
    if (self->_xPMT1 != NULL) {
        CPy_DECREF(self->_xPMT1);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_xPMT1 = tmp;
    return 0;
}

static PyObject *
Simulation_get_yPMT1(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_yPMT1 == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'yPMT1' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_yPMT1);
    PyObject *retval = self->_yPMT1;
    return retval;
}

static int
Simulation_set_yPMT1(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'yPMT1' cannot be deleted");
        return -1;
    }
    if (self->_yPMT1 != NULL) {
        CPy_DECREF(self->_yPMT1);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_yPMT1 = tmp;
    return 0;
}

static PyObject *
Simulation_get_PMT1_radius(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_PMT1_radius == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'PMT1_radius' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_PMT1_radius);
    PyObject *retval = self->_PMT1_radius;
    return retval;
}

static int
Simulation_set_PMT1_radius(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'PMT1_radius' cannot be deleted");
        return -1;
    }
    if (self->_PMT1_radius != NULL) {
        CPy_DECREF(self->_PMT1_radius);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_PMT1_radius = tmp;
    return 0;
}

static PyObject *
Simulation_get_PMT4_radius(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_PMT4_radius == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'PMT4_radius' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_PMT4_radius);
    PyObject *retval = self->_PMT4_radius;
    return retval;
}

static int
Simulation_set_PMT4_radius(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'PMT4_radius' cannot be deleted");
        return -1;
    }
    if (self->_PMT4_radius != NULL) {
        CPy_DECREF(self->_PMT4_radius);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_PMT4_radius = tmp;
    return 0;
}

static PyObject *
Simulation_get_n_dynodes(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_n_dynodes == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'n_dynodes' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_n_dynodes);
    PyObject *retval = self->_n_dynodes;
    return retval;
}

static int
Simulation_set_n_dynodes(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'n_dynodes' cannot be deleted");
        return -1;
    }
    if (self->_n_dynodes != NULL) {
        CPy_DECREF(self->_n_dynodes);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_n_dynodes = tmp;
    return 0;
}

static PyObject *
Simulation_get_V(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_V == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'V' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_V);
    PyObject *retval = self->_V;
    return retval;
}

static int
Simulation_set_V(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'V' cannot be deleted");
        return -1;
    }
    if (self->_V != NULL) {
        CPy_DECREF(self->_V);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_V = tmp;
    return 0;
}

static PyObject *
Simulation_get_E_per_electron(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_E_per_electron == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'E_per_electron' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_E_per_electron);
    PyObject *retval = self->_E_per_electron;
    return retval;
}

static int
Simulation_set_E_per_electron(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'E_per_electron' cannot be deleted");
        return -1;
    }
    if (self->_E_per_electron != NULL) {
        CPy_DECREF(self->_E_per_electron);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_E_per_electron = tmp;
    return 0;
}

static PyObject *
Simulation_get_QE(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_QE == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'QE' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_QE);
    PyObject *retval = self->_QE;
    return retval;
}

static int
Simulation_set_QE(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'QE' cannot be deleted");
        return -1;
    }
    if (self->_QE != NULL) {
        CPy_DECREF(self->_QE);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_QE = tmp;
    return 0;
}

static PyObject *
Simulation_get_sigma_smoothing(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_sigma_smoothing == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'sigma_smoothing' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_sigma_smoothing);
    PyObject *retval = self->_sigma_smoothing;
    return retval;
}

static int
Simulation_set_sigma_smoothing(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'sigma_smoothing' cannot be deleted");
        return -1;
    }
    if (self->_sigma_smoothing != NULL) {
        CPy_DECREF(self->_sigma_smoothing);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_sigma_smoothing = tmp;
    return 0;
}

static PyObject *
Simulation_get_t_initial(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_t_initial == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 't_initial' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_t_initial);
    PyObject *retval = self->_t_initial;
    return retval;
}

static int
Simulation_set_t_initial(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 't_initial' cannot be deleted");
        return -1;
    }
    if (self->_t_initial != NULL) {
        CPy_DECREF(self->_t_initial);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_t_initial = tmp;
    return 0;
}

static PyObject *
Simulation_get_particle_init_angle_range(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_particle_init_angle_range == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'particle_init_angle_range' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_particle_init_angle_range);
    PyObject *retval = self->_particle_init_angle_range;
    return retval;
}

static int
Simulation_set_particle_init_angle_range(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'particle_init_angle_range' cannot be deleted");
        return -1;
    }
    if (self->_particle_init_angle_range != NULL) {
        CPy_DECREF(self->_particle_init_angle_range);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_particle_init_angle_range = tmp;
    return 0;
}

static PyObject *
Simulation_get_particle_gen_area(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_particle_gen_area == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'particle_gen_area' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_particle_gen_area);
    PyObject *retval = self->_particle_gen_area;
    return retval;
}

static int
Simulation_set_particle_gen_area(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'particle_gen_area' cannot be deleted");
        return -1;
    }
    if (self->_particle_gen_area != NULL) {
        CPy_DECREF(self->_particle_gen_area);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_particle_gen_area = tmp;
    return 0;
}

static PyObject *
Simulation_get_particle_gen_z(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_particle_gen_z == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'particle_gen_z' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_particle_gen_z);
    PyObject *retval = self->_particle_gen_z;
    return retval;
}

static int
Simulation_set_particle_gen_z(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'particle_gen_z' cannot be deleted");
        return -1;
    }
    if (self->_particle_gen_z != NULL) {
        CPy_DECREF(self->_particle_gen_z);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_particle_gen_z = tmp;
    return 0;
}

static PyObject *
Simulation_get_mean_free_path_scints(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_mean_free_path_scints == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'mean_free_path_scints' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_mean_free_path_scints);
    PyObject *retval = self->_mean_free_path_scints;
    return retval;
}

static int
Simulation_set_mean_free_path_scints(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'mean_free_path_scints' cannot be deleted");
        return -1;
    }
    if (self->_mean_free_path_scints != NULL) {
        CPy_DECREF(self->_mean_free_path_scints);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_mean_free_path_scints = tmp;
    return 0;
}

static PyObject *
Simulation_get_photons_produced_per_MeV(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_photons_produced_per_MeV == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'photons_produced_per_MeV' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_photons_produced_per_MeV);
    PyObject *retval = self->_photons_produced_per_MeV;
    return retval;
}

static int
Simulation_set_photons_produced_per_MeV(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'photons_produced_per_MeV' cannot be deleted");
        return -1;
    }
    if (self->_photons_produced_per_MeV != NULL) {
        CPy_DECREF(self->_photons_produced_per_MeV);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_photons_produced_per_MeV = tmp;
    return 0;
}

static PyObject *
Simulation_get_pr_of_scintillation(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_pr_of_scintillation == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'pr_of_scintillation' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_pr_of_scintillation);
    PyObject *retval = self->_pr_of_scintillation;
    return retval;
}

static int
Simulation_set_pr_of_scintillation(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'pr_of_scintillation' cannot be deleted");
        return -1;
    }
    if (self->_pr_of_scintillation != NULL) {
        CPy_DECREF(self->_pr_of_scintillation);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_pr_of_scintillation = tmp;
    return 0;
}

static PyObject *
Simulation_get_max_simulated_reflections(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_max_simulated_reflections == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'max_simulated_reflections' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_max_simulated_reflections);
    PyObject *retval = self->_max_simulated_reflections;
    return retval;
}

static int
Simulation_set_max_simulated_reflections(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'max_simulated_reflections' cannot be deleted");
        return -1;
    }
    if (self->_max_simulated_reflections != NULL) {
        CPy_DECREF(self->_max_simulated_reflections);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_max_simulated_reflections = tmp;
    return 0;
}

static PyObject *
Simulation_get_pmt_electron_travel_time(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_pmt_electron_travel_time == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'pmt_electron_travel_time' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_pmt_electron_travel_time);
    PyObject *retval = self->_pmt_electron_travel_time;
    return retval;
}

static int
Simulation_set_pmt_electron_travel_time(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'pmt_electron_travel_time' cannot be deleted");
        return -1;
    }
    if (self->_pmt_electron_travel_time != NULL) {
        CPy_DECREF(self->_pmt_electron_travel_time);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_pmt_electron_travel_time = tmp;
    return 0;
}

static PyObject *
Simulation_get_artificial_gain(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_artificial_gain == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'artificial_gain' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_artificial_gain);
    PyObject *retval = self->_artificial_gain;
    return retval;
}

static int
Simulation_set_artificial_gain(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'artificial_gain' cannot be deleted");
        return -1;
    }
    if (self->_artificial_gain != NULL) {
        CPy_DECREF(self->_artificial_gain);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_artificial_gain = tmp;
    return 0;
}

static PyObject *
Simulation_get_max_pmt_current_output(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_max_pmt_current_output == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'max_pmt_current_output' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_max_pmt_current_output);
    PyObject *retval = self->_max_pmt_current_output;
    return retval;
}

static int
Simulation_set_max_pmt_current_output(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'max_pmt_current_output' cannot be deleted");
        return -1;
    }
    if (self->_max_pmt_current_output != NULL) {
        CPy_DECREF(self->_max_pmt_current_output);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_max_pmt_current_output = tmp;
    return 0;
}

static PyObject *
Simulation_get_pr_absorption(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_pr_absorption == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'pr_absorption' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_pr_absorption);
    PyObject *retval = self->_pr_absorption;
    return retval;
}

static int
Simulation_set_pr_absorption(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'pr_absorption' cannot be deleted");
        return -1;
    }
    if (self->_pr_absorption != NULL) {
        CPy_DECREF(self->_pr_absorption);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_pr_absorption = tmp;
    return 0;
}

static PyObject *
Simulation_get_seperation_time(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_seperation_time == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'seperation_time' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_seperation_time);
    PyObject *retval = self->_seperation_time;
    return retval;
}

static int
Simulation_set_seperation_time(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'seperation_time' cannot be deleted");
        return -1;
    }
    if (self->_seperation_time != NULL) {
        CPy_DECREF(self->_seperation_time);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_seperation_time = tmp;
    return 0;
}

static PyObject *
Simulation_get_output_bin_width(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_output_bin_width == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'output_bin_width' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_output_bin_width);
    PyObject *retval = self->_output_bin_width;
    return retval;
}

static int
Simulation_set_output_bin_width(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'output_bin_width' cannot be deleted");
        return -1;
    }
    if (self->_output_bin_width != NULL) {
        CPy_DECREF(self->_output_bin_width);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_output_bin_width = tmp;
    return 0;
}

static PyObject *
Simulation_get_num_particles(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_num_particles == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'num_particles' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_num_particles);
    PyObject *retval = self->_num_particles;
    return retval;
}

static int
Simulation_set_num_particles(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'num_particles' cannot be deleted");
        return -1;
    }
    if (self->_num_particles != NULL) {
        CPy_DECREF(self->_num_particles);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_num_particles = tmp;
    return 0;
}

static PyObject *
Simulation_get_CMOS_thresh(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_CMOS_thresh == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'CMOS_thresh' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_CMOS_thresh);
    PyObject *retval = self->_CMOS_thresh;
    return retval;
}

static int
Simulation_set_CMOS_thresh(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'CMOS_thresh' cannot be deleted");
        return -1;
    }
    if (self->_CMOS_thresh != NULL) {
        CPy_DECREF(self->_CMOS_thresh);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_CMOS_thresh = tmp;
    return 0;
}

static PyObject *
Simulation_get_reemission_angle_factor(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_reemission_angle_factor == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'reemission_angle_factor' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_reemission_angle_factor);
    PyObject *retval = self->_reemission_angle_factor;
    return retval;
}

static int
Simulation_set_reemission_angle_factor(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'reemission_angle_factor' cannot be deleted");
        return -1;
    }
    if (self->_reemission_angle_factor != NULL) {
        CPy_DECREF(self->_reemission_angle_factor);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_reemission_angle_factor = tmp;
    return 0;
}

static PyObject *
Simulation_get_T1_prop_dist(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T1_prop_dist == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T1_prop_dist' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T1_prop_dist);
    PyObject *retval = self->_T1_prop_dist;
    return retval;
}

static int
Simulation_set_T1_prop_dist(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T1_prop_dist' cannot be deleted");
        return -1;
    }
    if (self->_T1_prop_dist != NULL) {
        CPy_DECREF(self->_T1_prop_dist);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T1_prop_dist = tmp;
    return 0;
}

static PyObject *
Simulation_get_T4_prop_dist(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T4_prop_dist == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T4_prop_dist' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T4_prop_dist);
    PyObject *retval = self->_T4_prop_dist;
    return retval;
}

static int
Simulation_set_T4_prop_dist(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T4_prop_dist' cannot be deleted");
        return -1;
    }
    if (self->_T4_prop_dist != NULL) {
        CPy_DECREF(self->_T4_prop_dist);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T4_prop_dist = tmp;
    return 0;
}

static PyObject *
Simulation_get_T1_endpoint_dist(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T1_endpoint_dist == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T1_endpoint_dist' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T1_endpoint_dist);
    PyObject *retval = self->_T1_endpoint_dist;
    return retval;
}

static int
Simulation_set_T1_endpoint_dist(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T1_endpoint_dist' cannot be deleted");
        return -1;
    }
    if (self->_T1_endpoint_dist != NULL) {
        CPy_DECREF(self->_T1_endpoint_dist);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T1_endpoint_dist = tmp;
    return 0;
}

static PyObject *
Simulation_get_T4_endpoint_dist(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T4_endpoint_dist == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T4_endpoint_dist' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T4_endpoint_dist);
    PyObject *retval = self->_T4_endpoint_dist;
    return retval;
}

static int
Simulation_set_T4_endpoint_dist(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T4_endpoint_dist' cannot be deleted");
        return -1;
    }
    if (self->_T4_endpoint_dist != NULL) {
        CPy_DECREF(self->_T4_endpoint_dist);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T4_endpoint_dist = tmp;
    return 0;
}

static PyObject *
Simulation_get_T1_prop_times(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T1_prop_times == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T1_prop_times' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T1_prop_times);
    PyObject *retval = self->_T1_prop_times;
    return retval;
}

static int
Simulation_set_T1_prop_times(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T1_prop_times' cannot be deleted");
        return -1;
    }
    if (self->_T1_prop_times != NULL) {
        CPy_DECREF(self->_T1_prop_times);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T1_prop_times = tmp;
    return 0;
}

static PyObject *
Simulation_get_T4_prop_times(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T4_prop_times == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T4_prop_times' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T4_prop_times);
    PyObject *retval = self->_T4_prop_times;
    return retval;
}

static int
Simulation_set_T4_prop_times(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T4_prop_times' cannot be deleted");
        return -1;
    }
    if (self->_T4_prop_times != NULL) {
        CPy_DECREF(self->_T4_prop_times);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T4_prop_times = tmp;
    return 0;
}

static PyObject *
Simulation_get_T1_interactions(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T1_interactions == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T1_interactions' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T1_interactions);
    PyObject *retval = self->_T1_interactions;
    return retval;
}

static int
Simulation_set_T1_interactions(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T1_interactions' cannot be deleted");
        return -1;
    }
    if (self->_T1_interactions != NULL) {
        CPy_DECREF(self->_T1_interactions);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T1_interactions = tmp;
    return 0;
}

static PyObject *
Simulation_get_T4_interactions(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T4_interactions == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T4_interactions' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T4_interactions);
    PyObject *retval = self->_T4_interactions;
    return retval;
}

static int
Simulation_set_T4_interactions(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T4_interactions' cannot be deleted");
        return -1;
    }
    if (self->_T4_interactions != NULL) {
        CPy_DECREF(self->_T4_interactions);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T4_interactions = tmp;
    return 0;
}

static PyObject *
Simulation_get_T1_part_ids(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T1_part_ids == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T1_part_ids' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T1_part_ids);
    PyObject *retval = self->_T1_part_ids;
    return retval;
}

static int
Simulation_set_T1_part_ids(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T1_part_ids' cannot be deleted");
        return -1;
    }
    if (self->_T1_part_ids != NULL) {
        CPy_DECREF(self->_T1_part_ids);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T1_part_ids = tmp;
    return 0;
}

static PyObject *
Simulation_get_T4_part_ids(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_T4_part_ids == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'T4_part_ids' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_T4_part_ids);
    PyObject *retval = self->_T4_part_ids;
    return retval;
}

static int
Simulation_set_T4_part_ids(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'T4_part_ids' cannot be deleted");
        return -1;
    }
    if (self->_T4_part_ids != NULL) {
        CPy_DECREF(self->_T4_part_ids);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_T4_part_ids = tmp;
    return 0;
}

static PyObject *
Simulation_get_signals(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_signals == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'signals' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_signals);
    PyObject *retval = self->_signals;
    return retval;
}

static int
Simulation_set_signals(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'signals' cannot be deleted");
        return -1;
    }
    if (self->_signals != NULL) {
        CPy_DECREF(self->_signals);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_signals = tmp;
    return 0;
}

static PyObject *
Simulation_get_output_times(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_output_times == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'output_times' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_output_times);
    PyObject *retval = self->_output_times;
    return retval;
}

static int
Simulation_set_output_times(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'output_times' cannot be deleted");
        return -1;
    }
    if (self->_output_times != NULL) {
        CPy_DECREF(self->_output_times);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_output_times = tmp;
    return 0;
}

static PyObject *
Simulation_get_signals_channelT1(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_signals_channelT1 == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'signals_channelT1' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_signals_channelT1);
    PyObject *retval = self->_signals_channelT1;
    return retval;
}

static int
Simulation_set_signals_channelT1(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'signals_channelT1' cannot be deleted");
        return -1;
    }
    if (self->_signals_channelT1 != NULL) {
        CPy_DECREF(self->_signals_channelT1);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_signals_channelT1 = tmp;
    return 0;
}

static PyObject *
Simulation_get_signals_channelT4(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_signals_channelT4 == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'signals_channelT4' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_signals_channelT4);
    PyObject *retval = self->_signals_channelT4;
    return retval;
}

static int
Simulation_set_signals_channelT4(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'signals_channelT4' cannot be deleted");
        return -1;
    }
    if (self->_signals_channelT4 != NULL) {
        CPy_DECREF(self->_signals_channelT4);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_signals_channelT4 = tmp;
    return 0;
}

static PyObject *
Simulation_get_output_times_channelT1(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_output_times_channelT1 == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'output_times_channelT1' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_output_times_channelT1);
    PyObject *retval = self->_output_times_channelT1;
    return retval;
}

static int
Simulation_set_output_times_channelT1(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'output_times_channelT1' cannot be deleted");
        return -1;
    }
    if (self->_output_times_channelT1 != NULL) {
        CPy_DECREF(self->_output_times_channelT1);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_output_times_channelT1 = tmp;
    return 0;
}

static PyObject *
Simulation_get_output_times_channelT4(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_output_times_channelT4 == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'output_times_channelT4' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_output_times_channelT4);
    PyObject *retval = self->_output_times_channelT4;
    return retval;
}

static int
Simulation_set_output_times_channelT4(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'output_times_channelT4' cannot be deleted");
        return -1;
    }
    if (self->_output_times_channelT4 != NULL) {
        CPy_DECREF(self->_output_times_channelT4);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_output_times_channelT4 = tmp;
    return 0;
}

static PyObject *
Simulation_get_FinalToF(modTof___SimulationObject *self, void *closure)
{
    if (unlikely(self->_FinalToF == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'FinalToF' of 'Simulation' undefined");
        return NULL;
    }
    CPy_INCREF(self->_FinalToF);
    PyObject *retval = self->_FinalToF;
    return retval;
}

static int
Simulation_set_FinalToF(modTof___SimulationObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Simulation' object attribute 'FinalToF' cannot be deleted");
        return -1;
    }
    if (self->_FinalToF != NULL) {
        CPy_DECREF(self->_FinalToF);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_FinalToF = tmp;
    return 0;
}
static PyMethodDef module_methods[] = {
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "modTof",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyMODINIT_FUNC PyInit_modTof(void)
{
    PyObject* modname = NULL;
    if (CPyModule_modTof_internal) {
        Py_INCREF(CPyModule_modTof_internal);
        return CPyModule_modTof_internal;
    }
    CPyModule_modTof_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_modTof_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_modTof_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_modTof_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_modTof_internal;
    fail:
    Py_CLEAR(CPyModule_modTof_internal);
    Py_CLEAR(modname);
    Py_CLEAR(CPyType_Simulation);
    return NULL;
}

char CPyDef_Simulation_____init__(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
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
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    CPyPtr cpy_r_r31;
    CPyPtr cpy_r_r32;
    CPyPtr cpy_r_r33;
    CPyPtr cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    CPyPtr cpy_r_r43;
    CPyPtr cpy_r_r44;
    CPyPtr cpy_r_r45;
    CPyPtr cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    CPyPtr cpy_r_r56;
    CPyPtr cpy_r_r57;
    CPyPtr cpy_r_r58;
    CPyPtr cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    CPyPtr cpy_r_r69;
    CPyPtr cpy_r_r70;
    CPyPtr cpy_r_r71;
    CPyPtr cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject **cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject **cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject **cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject **cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject **cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject **cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject **cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject **cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_r137;
    PyObject *cpy_r_r138;
    PyObject *cpy_r_r139;
    PyObject *cpy_r_r140;
    PyObject *cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    PyObject *cpy_r_r144;
    PyObject *cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject *cpy_r_r149;
    PyObject **cpy_r_r151;
    PyObject *cpy_r_r152;
    PyObject *cpy_r_r153;
    PyObject *cpy_r_r154;
    PyObject *cpy_r_r155;
    PyObject *cpy_r_r156;
    PyObject *cpy_r_r157;
    PyObject *cpy_r_r158;
    PyObject *cpy_r_r159;
    PyObject *cpy_r_r160;
    PyObject *cpy_r_r161;
    PyObject *cpy_r_r162;
    PyObject *cpy_r_r163;
    PyObject *cpy_r_r164;
    PyObject *cpy_r_r165;
    PyObject *cpy_r_r166;
    PyObject *cpy_r_r167;
    PyObject *cpy_r_r168;
    PyObject *cpy_r_r169;
    PyObject *cpy_r_r170;
    PyObject *cpy_r_r171;
    PyObject *cpy_r_r172;
    PyObject *cpy_r_r173;
    PyObject *cpy_r_r174;
    PyObject *cpy_r_r175;
    PyObject *cpy_r_r176;
    PyObject *cpy_r_r177;
    PyObject *cpy_r_r178;
    PyObject *cpy_r_r179;
    PyObject *cpy_r_r180;
    PyObject **cpy_r_r182;
    PyObject *cpy_r_r183;
    PyObject *cpy_r_r184;
    PyObject *cpy_r_r185;
    PyObject *cpy_r_r186;
    PyObject *cpy_r_r187;
    PyObject **cpy_r_r189;
    PyObject *cpy_r_r190;
    PyObject *cpy_r_r191;
    PyObject *cpy_r_r192;
    PyObject *cpy_r_r193;
    PyObject *cpy_r_r194;
    PyObject **cpy_r_r196;
    PyObject *cpy_r_r197;
    PyObject *cpy_r_r198;
    PyObject *cpy_r_r199;
    PyObject *cpy_r_r200;
    PyObject *cpy_r_r201;
    PyObject *cpy_r_r202;
    PyObject *cpy_r_r203;
    PyObject **cpy_r_r205;
    PyObject *cpy_r_r206;
    PyObject *cpy_r_r207;
    PyObject *cpy_r_r208;
    PyObject *cpy_r_r209;
    PyObject *cpy_r_r210;
    PyObject *cpy_r_r211;
    PyObject **cpy_r_r213;
    PyObject *cpy_r_r214;
    PyObject *cpy_r_r215;
    PyObject *cpy_r_r216;
    PyObject *cpy_r_r217;
    PyObject *cpy_r_r218;
    PyObject *cpy_r_r219;
    PyObject **cpy_r_r221;
    PyObject *cpy_r_r222;
    PyObject *cpy_r_r223;
    PyObject *cpy_r_r224;
    PyObject *cpy_r_r225;
    PyObject *cpy_r_r226;
    PyObject *cpy_r_r227;
    PyObject *cpy_r_r228;
    PyObject **cpy_r_r230;
    PyObject *cpy_r_r231;
    PyObject *cpy_r_r232;
    PyObject *cpy_r_r233;
    PyObject *cpy_r_r234;
    PyObject *cpy_r_r235;
    PyObject *cpy_r_r236;
    PyObject *cpy_r_r237;
    PyObject **cpy_r_r239;
    PyObject *cpy_r_r240;
    PyObject *cpy_r_r241;
    PyObject *cpy_r_r242;
    PyObject *cpy_r_r243;
    PyObject *cpy_r_r244;
    PyObject *cpy_r_r245;
    PyObject **cpy_r_r247;
    PyObject *cpy_r_r248;
    PyObject *cpy_r_r249;
    PyObject *cpy_r_r250;
    PyObject *cpy_r_r251;
    PyObject *cpy_r_r252;
    PyObject *cpy_r_r253;
    PyObject *cpy_r_r254;
    PyObject **cpy_r_r256;
    PyObject *cpy_r_r257;
    PyObject *cpy_r_r258;
    PyObject *cpy_r_r259;
    PyObject *cpy_r_r260;
    PyObject *cpy_r_r261;
    PyObject **cpy_r_r263;
    PyObject *cpy_r_r264;
    PyObject *cpy_r_r265;
    PyObject *cpy_r_r266;
    PyObject *cpy_r_r267;
    PyObject *cpy_r_r268;
    PyObject *cpy_r_r269;
    PyObject *cpy_r_r270;
    PyObject **cpy_r_r272;
    PyObject *cpy_r_r273;
    char cpy_r_r274;
    cpy_r_r0 = PyFloat_FromDouble(0.018974177215189875);
    ((modTof___SimulationObject *)cpy_r_self)->_c = cpy_r_r0;
    cpy_r_r1 = PyFloat_FromDouble(1.60217663e-19);
    ((modTof___SimulationObject *)cpy_r_self)->_q = cpy_r_r1;
    cpy_r_r2 = PyFloat_FromDouble(1.000293);
    ((modTof___SimulationObject *)cpy_r_self)->_n_1 = cpy_r_r2;
    cpy_r_r3 = PyFloat_FromDouble(1.58);
    ((modTof___SimulationObject *)cpy_r_self)->_n_2 = cpy_r_r3;
    cpy_r_r4 = CPyStatics[244]; /* 0 */
    CPy_INCREF(cpy_r_r4);
    ((modTof___SimulationObject *)cpy_r_self)->_T3z = cpy_r_r4;
    cpy_r_r5 = PyFloat_FromDouble(33.782);
    ((modTof___SimulationObject *)cpy_r_self)->_T1z = cpy_r_r5;
    cpy_r_r6 = PyFloat_FromDouble(-28.07297);
    ((modTof___SimulationObject *)cpy_r_self)->_T4z = cpy_r_r6;
    cpy_r_r7 = CPyStatics[245]; /* 13 */
    CPy_INCREF(cpy_r_r7);
    ((modTof___SimulationObject *)cpy_r_self)->_T1_radius = cpy_r_r7;
    cpy_r_r8 = CPyStatics[246]; /* 18 */
    CPy_INCREF(cpy_r_r8);
    ((modTof___SimulationObject *)cpy_r_self)->_T4_radius = cpy_r_r8;
    cpy_r_r9 = PyFloat_FromDouble(0.5);
    ((modTof___SimulationObject *)cpy_r_self)->_T1_width = cpy_r_r9;
    cpy_r_r10 = CPyStatics[247]; /* 1 */
    CPy_INCREF(cpy_r_r10);
    ((modTof___SimulationObject *)cpy_r_self)->_T4_width = cpy_r_r10;
    cpy_r_r11 = ((modTof___SimulationObject *)cpy_r_self)->_T1z;
    CPy_INCREF(cpy_r_r11);
    cpy_r_r12 = ((modTof___SimulationObject *)cpy_r_self)->_T1_width;
    CPy_INCREF(cpy_r_r12);
    cpy_r_r13 = PyNumber_Add(cpy_r_r11, cpy_r_r12);
    CPy_DECREF(cpy_r_r11);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 46, CPyStatic_globals);
        goto CPyL71;
    }
    ((modTof___SimulationObject *)cpy_r_self)->_T1top = cpy_r_r13;
    cpy_r_r14 = ((modTof___SimulationObject *)cpy_r_self)->_T4z;
    CPy_INCREF(cpy_r_r14);
    cpy_r_r15 = ((modTof___SimulationObject *)cpy_r_self)->_T4_width;
    CPy_INCREF(cpy_r_r15);
    cpy_r_r16 = PyNumber_Add(cpy_r_r14, cpy_r_r15);
    CPy_DECREF(cpy_r_r14);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 47, CPyStatic_globals);
        goto CPyL71;
    }
    ((modTof___SimulationObject *)cpy_r_self)->_T4top = cpy_r_r16;
    cpy_r_r17 = ((modTof___SimulationObject *)cpy_r_self)->_T1_width;
    CPy_INCREF(cpy_r_r17);
    cpy_r_r18 = CPyStatics[248]; /* 4 */
    cpy_r_r19 = PyNumber_Multiply(cpy_r_r17, cpy_r_r18);
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 48, CPyStatic_globals);
        goto CPyL71;
    }
    ((modTof___SimulationObject *)cpy_r_self)->_T1_corner_radius = cpy_r_r19;
    cpy_r_r20 = ((modTof___SimulationObject *)cpy_r_self)->_T4_width;
    CPy_INCREF(cpy_r_r20);
    cpy_r_r21 = CPyStatics[248]; /* 4 */
    cpy_r_r22 = PyNumber_Multiply(cpy_r_r20, cpy_r_r21);
    CPy_DECREF(cpy_r_r20);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 49, CPyStatic_globals);
        goto CPyL71;
    }
    ((modTof___SimulationObject *)cpy_r_self)->_T4_corner_radius = cpy_r_r22;
    cpy_r_r23 = ((modTof___SimulationObject *)cpy_r_self)->_T1_radius;
    CPy_INCREF(cpy_r_r23);
    cpy_r_r24 = ((modTof___SimulationObject *)cpy_r_self)->_T1_corner_radius;
    CPy_INCREF(cpy_r_r24);
    cpy_r_r25 = PyNumber_Subtract(cpy_r_r23, cpy_r_r24);
    CPy_DECREF(cpy_r_r23);
    CPy_DECREF(cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 50, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r26 = ((modTof___SimulationObject *)cpy_r_self)->_T1_corner_radius;
    CPy_INCREF(cpy_r_r26);
    cpy_r_r27 = ((modTof___SimulationObject *)cpy_r_self)->_T1_radius;
    CPy_INCREF(cpy_r_r27);
    cpy_r_r28 = PyNumber_Subtract(cpy_r_r26, cpy_r_r27);
    CPy_DECREF(cpy_r_r26);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 50, CPyStatic_globals);
        goto CPyL72;
    }
    cpy_r_r29 = ((modTof___SimulationObject *)cpy_r_self)->_T1_radius;
    CPy_INCREF(cpy_r_r29);
    cpy_r_r30 = PyList_New(3);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 50, CPyStatic_globals);
        goto CPyL73;
    }
    cpy_r_r31 = (CPyPtr)&((PyListObject *)cpy_r_r30)->ob_item;
    cpy_r_r32 = *(CPyPtr *)cpy_r_r31;
    *(PyObject * *)cpy_r_r32 = cpy_r_r25;
    cpy_r_r33 = cpy_r_r32 + 8;
    *(PyObject * *)cpy_r_r33 = cpy_r_r28;
    cpy_r_r34 = cpy_r_r32 + 16;
    *(PyObject * *)cpy_r_r34 = cpy_r_r29;
    ((modTof___SimulationObject *)cpy_r_self)->_T1_corner_center = cpy_r_r30;
    cpy_r_r35 = ((modTof___SimulationObject *)cpy_r_self)->_T4_corner_radius;
    CPy_INCREF(cpy_r_r35);
    cpy_r_r36 = ((modTof___SimulationObject *)cpy_r_self)->_T4_radius;
    CPy_INCREF(cpy_r_r36);
    cpy_r_r37 = PyNumber_Subtract(cpy_r_r35, cpy_r_r36);
    CPy_DECREF(cpy_r_r35);
    CPy_DECREF(cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 51, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r38 = ((modTof___SimulationObject *)cpy_r_self)->_T4_radius;
    CPy_INCREF(cpy_r_r38);
    cpy_r_r39 = ((modTof___SimulationObject *)cpy_r_self)->_T4_corner_radius;
    CPy_INCREF(cpy_r_r39);
    cpy_r_r40 = PyNumber_Subtract(cpy_r_r38, cpy_r_r39);
    CPy_DECREF(cpy_r_r38);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 51, CPyStatic_globals);
        goto CPyL74;
    }
    cpy_r_r41 = ((modTof___SimulationObject *)cpy_r_self)->_T4_radius;
    CPy_INCREF(cpy_r_r41);
    cpy_r_r42 = PyList_New(3);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 51, CPyStatic_globals);
        goto CPyL75;
    }
    cpy_r_r43 = (CPyPtr)&((PyListObject *)cpy_r_r42)->ob_item;
    cpy_r_r44 = *(CPyPtr *)cpy_r_r43;
    *(PyObject * *)cpy_r_r44 = cpy_r_r37;
    cpy_r_r45 = cpy_r_r44 + 8;
    *(PyObject * *)cpy_r_r45 = cpy_r_r40;
    cpy_r_r46 = cpy_r_r44 + 16;
    *(PyObject * *)cpy_r_r46 = cpy_r_r41;
    ((modTof___SimulationObject *)cpy_r_self)->_T4_corner_center = cpy_r_r42;
    cpy_r_r47 = ((modTof___SimulationObject *)cpy_r_self)->_T1_radius;
    CPy_INCREF(cpy_r_r47);
    cpy_r_r48 = PyFloat_FromDouble(2.0);
    cpy_r_r49 = PyNumber_Subtract(cpy_r_r47, cpy_r_r48);
    CPy_DECREF(cpy_r_r47);
    CPy_DECREF(cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 52, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r50 = ((modTof___SimulationObject *)cpy_r_self)->_T1_radius;
    CPy_INCREF(cpy_r_r50);
    cpy_r_r51 = PyNumber_Negative(cpy_r_r50);
    CPy_DECREF(cpy_r_r50);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 52, CPyStatic_globals);
        goto CPyL76;
    }
    cpy_r_r52 = PyFloat_FromDouble(2.0);
    cpy_r_r53 = PyNumber_Add(cpy_r_r51, cpy_r_r52);
    CPy_DECREF(cpy_r_r51);
    CPy_DECREF(cpy_r_r52);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 52, CPyStatic_globals);
        goto CPyL76;
    }
    cpy_r_r54 = ((modTof___SimulationObject *)cpy_r_self)->_T1z;
    CPy_INCREF(cpy_r_r54);
    cpy_r_r55 = PyList_New(3);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 52, CPyStatic_globals);
        goto CPyL77;
    }
    cpy_r_r56 = (CPyPtr)&((PyListObject *)cpy_r_r55)->ob_item;
    cpy_r_r57 = *(CPyPtr *)cpy_r_r56;
    *(PyObject * *)cpy_r_r57 = cpy_r_r49;
    cpy_r_r58 = cpy_r_r57 + 8;
    *(PyObject * *)cpy_r_r58 = cpy_r_r53;
    cpy_r_r59 = cpy_r_r57 + 16;
    *(PyObject * *)cpy_r_r59 = cpy_r_r54;
    ((modTof___SimulationObject *)cpy_r_self)->_PMT1_center = cpy_r_r55;
    cpy_r_r60 = ((modTof___SimulationObject *)cpy_r_self)->_T4_radius;
    CPy_INCREF(cpy_r_r60);
    cpy_r_r61 = PyNumber_Negative(cpy_r_r60);
    CPy_DECREF(cpy_r_r60);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 53, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r62 = PyFloat_FromDouble(2.0);
    cpy_r_r63 = PyNumber_Add(cpy_r_r61, cpy_r_r62);
    CPy_DECREF(cpy_r_r61);
    CPy_DECREF(cpy_r_r62);
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 53, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r64 = ((modTof___SimulationObject *)cpy_r_self)->_T4_radius;
    CPy_INCREF(cpy_r_r64);
    cpy_r_r65 = PyFloat_FromDouble(2.0);
    cpy_r_r66 = PyNumber_Subtract(cpy_r_r64, cpy_r_r65);
    CPy_DECREF(cpy_r_r64);
    CPy_DECREF(cpy_r_r65);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 53, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r67 = ((modTof___SimulationObject *)cpy_r_self)->_T4z;
    CPy_INCREF(cpy_r_r67);
    cpy_r_r68 = PyList_New(3);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 53, CPyStatic_globals);
        goto CPyL79;
    }
    cpy_r_r69 = (CPyPtr)&((PyListObject *)cpy_r_r68)->ob_item;
    cpy_r_r70 = *(CPyPtr *)cpy_r_r69;
    *(PyObject * *)cpy_r_r70 = cpy_r_r63;
    cpy_r_r71 = cpy_r_r70 + 8;
    *(PyObject * *)cpy_r_r71 = cpy_r_r66;
    cpy_r_r72 = cpy_r_r70 + 16;
    *(PyObject * *)cpy_r_r72 = cpy_r_r67;
    ((modTof___SimulationObject *)cpy_r_self)->_PMT4_center = cpy_r_r68;
    cpy_r_r73 = CPyModule_numpy;
    cpy_r_r74 = CPyStatics[3]; /* 'radians' */
    cpy_r_r75 = CPyObject_GetAttr(cpy_r_r73, cpy_r_r74);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 54, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r76 = CPyStatics[249]; /* 110 */
    PyObject *cpy_r_r77[1] = {cpy_r_r76};
    cpy_r_r78 = (PyObject **)&cpy_r_r77;
    cpy_r_r79 = _PyObject_Vectorcall(cpy_r_r75, cpy_r_r78, 1, 0);
    CPy_DECREF(cpy_r_r75);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 54, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r80 = CPyModule_numpy;
    cpy_r_r81 = CPyStatics[4]; /* 'cos' */
    cpy_r_r82 = CPyObject_GetAttr(cpy_r_r80, cpy_r_r81);
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 54, CPyStatic_globals);
        goto CPyL80;
    }
    PyObject *cpy_r_r83[1] = {cpy_r_r79};
    cpy_r_r84 = (PyObject **)&cpy_r_r83;
    cpy_r_r85 = _PyObject_Vectorcall(cpy_r_r82, cpy_r_r84, 1, 0);
    CPy_DECREF(cpy_r_r82);
    if (unlikely(cpy_r_r85 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 54, CPyStatic_globals);
        goto CPyL80;
    }
    CPy_DECREF(cpy_r_r79);
    cpy_r_r86 = PyFloat_FromDouble(9.5);
    cpy_r_r87 = PyNumber_Multiply(cpy_r_r86, cpy_r_r85);
    CPy_DECREF(cpy_r_r86);
    CPy_DECREF(cpy_r_r85);
    if (unlikely(cpy_r_r87 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 54, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r88 = PyFloat_FromDouble(2.54);
    cpy_r_r89 = PyNumber_Multiply(cpy_r_r87, cpy_r_r88);
    CPy_DECREF(cpy_r_r87);
    CPy_DECREF(cpy_r_r88);
    if (unlikely(cpy_r_r89 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 54, CPyStatic_globals);
        goto CPyL71;
    }
    ((modTof___SimulationObject *)cpy_r_self)->_xPMT4 = cpy_r_r89;
    cpy_r_r90 = CPyModule_numpy;
    cpy_r_r91 = CPyStatics[3]; /* 'radians' */
    cpy_r_r92 = CPyObject_GetAttr(cpy_r_r90, cpy_r_r91);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 55, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r93 = CPyStatics[249]; /* 110 */
    PyObject *cpy_r_r94[1] = {cpy_r_r93};
    cpy_r_r95 = (PyObject **)&cpy_r_r94;
    cpy_r_r96 = _PyObject_Vectorcall(cpy_r_r92, cpy_r_r95, 1, 0);
    CPy_DECREF(cpy_r_r92);
    if (unlikely(cpy_r_r96 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 55, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r97 = CPyModule_numpy;
    cpy_r_r98 = CPyStatics[5]; /* 'sin' */
    cpy_r_r99 = CPyObject_GetAttr(cpy_r_r97, cpy_r_r98);
    if (unlikely(cpy_r_r99 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 55, CPyStatic_globals);
        goto CPyL81;
    }
    PyObject *cpy_r_r100[1] = {cpy_r_r96};
    cpy_r_r101 = (PyObject **)&cpy_r_r100;
    cpy_r_r102 = _PyObject_Vectorcall(cpy_r_r99, cpy_r_r101, 1, 0);
    CPy_DECREF(cpy_r_r99);
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 55, CPyStatic_globals);
        goto CPyL81;
    }
    CPy_DECREF(cpy_r_r96);
    cpy_r_r103 = PyFloat_FromDouble(9.5);
    cpy_r_r104 = PyNumber_Multiply(cpy_r_r103, cpy_r_r102);
    CPy_DECREF(cpy_r_r103);
    CPy_DECREF(cpy_r_r102);
    if (unlikely(cpy_r_r104 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 55, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r105 = PyFloat_FromDouble(2.54);
    cpy_r_r106 = PyNumber_Multiply(cpy_r_r104, cpy_r_r105);
    CPy_DECREF(cpy_r_r104);
    CPy_DECREF(cpy_r_r105);
    if (unlikely(cpy_r_r106 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 55, CPyStatic_globals);
        goto CPyL71;
    }
    ((modTof___SimulationObject *)cpy_r_self)->_yPMT4 = cpy_r_r106;
    cpy_r_r107 = CPyStatics[250]; /* -45 */
    cpy_r_r108 = CPyModule_numpy;
    cpy_r_r109 = CPyStatics[3]; /* 'radians' */
    cpy_r_r110 = CPyObject_GetAttr(cpy_r_r108, cpy_r_r109);
    if (unlikely(cpy_r_r110 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 56, CPyStatic_globals);
        goto CPyL71;
    }
    PyObject *cpy_r_r111[1] = {cpy_r_r107};
    cpy_r_r112 = (PyObject **)&cpy_r_r111;
    cpy_r_r113 = _PyObject_Vectorcall(cpy_r_r110, cpy_r_r112, 1, 0);
    CPy_DECREF(cpy_r_r110);
    if (unlikely(cpy_r_r113 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 56, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r114 = CPyModule_numpy;
    cpy_r_r115 = CPyStatics[4]; /* 'cos' */
    cpy_r_r116 = CPyObject_GetAttr(cpy_r_r114, cpy_r_r115);
    if (unlikely(cpy_r_r116 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 56, CPyStatic_globals);
        goto CPyL82;
    }
    PyObject *cpy_r_r117[1] = {cpy_r_r113};
    cpy_r_r118 = (PyObject **)&cpy_r_r117;
    cpy_r_r119 = _PyObject_Vectorcall(cpy_r_r116, cpy_r_r118, 1, 0);
    CPy_DECREF(cpy_r_r116);
    if (unlikely(cpy_r_r119 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 56, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_DECREF(cpy_r_r113);
    cpy_r_r120 = PyFloat_FromDouble(8.0);
    cpy_r_r121 = PyNumber_Multiply(cpy_r_r120, cpy_r_r119);
    CPy_DECREF(cpy_r_r120);
    CPy_DECREF(cpy_r_r119);
    if (unlikely(cpy_r_r121 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 56, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r122 = PyFloat_FromDouble(2.54);
    cpy_r_r123 = PyNumber_Multiply(cpy_r_r121, cpy_r_r122);
    CPy_DECREF(cpy_r_r121);
    CPy_DECREF(cpy_r_r122);
    if (unlikely(cpy_r_r123 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 56, CPyStatic_globals);
        goto CPyL71;
    }
    ((modTof___SimulationObject *)cpy_r_self)->_xPMT1 = cpy_r_r123;
    cpy_r_r124 = CPyStatics[250]; /* -45 */
    cpy_r_r125 = CPyModule_numpy;
    cpy_r_r126 = CPyStatics[3]; /* 'radians' */
    cpy_r_r127 = CPyObject_GetAttr(cpy_r_r125, cpy_r_r126);
    if (unlikely(cpy_r_r127 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 57, CPyStatic_globals);
        goto CPyL71;
    }
    PyObject *cpy_r_r128[1] = {cpy_r_r124};
    cpy_r_r129 = (PyObject **)&cpy_r_r128;
    cpy_r_r130 = _PyObject_Vectorcall(cpy_r_r127, cpy_r_r129, 1, 0);
    CPy_DECREF(cpy_r_r127);
    if (unlikely(cpy_r_r130 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 57, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r131 = CPyModule_numpy;
    cpy_r_r132 = CPyStatics[5]; /* 'sin' */
    cpy_r_r133 = CPyObject_GetAttr(cpy_r_r131, cpy_r_r132);
    if (unlikely(cpy_r_r133 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 57, CPyStatic_globals);
        goto CPyL83;
    }
    PyObject *cpy_r_r134[1] = {cpy_r_r130};
    cpy_r_r135 = (PyObject **)&cpy_r_r134;
    cpy_r_r136 = _PyObject_Vectorcall(cpy_r_r133, cpy_r_r135, 1, 0);
    CPy_DECREF(cpy_r_r133);
    if (unlikely(cpy_r_r136 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 57, CPyStatic_globals);
        goto CPyL83;
    }
    CPy_DECREF(cpy_r_r130);
    cpy_r_r137 = PyFloat_FromDouble(8.0);
    cpy_r_r138 = PyNumber_Multiply(cpy_r_r137, cpy_r_r136);
    CPy_DECREF(cpy_r_r137);
    CPy_DECREF(cpy_r_r136);
    if (unlikely(cpy_r_r138 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 57, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r139 = PyFloat_FromDouble(2.54);
    cpy_r_r140 = PyNumber_Multiply(cpy_r_r138, cpy_r_r139);
    CPy_DECREF(cpy_r_r138);
    CPy_DECREF(cpy_r_r139);
    if (unlikely(cpy_r_r140 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 57, CPyStatic_globals);
        goto CPyL71;
    }
    ((modTof___SimulationObject *)cpy_r_self)->_yPMT1 = cpy_r_r140;
    cpy_r_r141 = PyFloat_FromDouble(2.3);
    ((modTof___SimulationObject *)cpy_r_self)->_PMT1_radius = cpy_r_r141;
    cpy_r_r142 = PyFloat_FromDouble(2.3);
    ((modTof___SimulationObject *)cpy_r_self)->_PMT4_radius = cpy_r_r142;
    cpy_r_r143 = CPyStatics[251]; /* 8 */
    CPy_INCREF(cpy_r_r143);
    ((modTof___SimulationObject *)cpy_r_self)->_n_dynodes = cpy_r_r143;
    cpy_r_r144 = ((modTof___SimulationObject *)cpy_r_self)->_n_dynodes;
    CPy_INCREF(cpy_r_r144);
    cpy_r_r145 = CPyModule_numpy;
    cpy_r_r146 = CPyStatics[6]; /* 'linspace' */
    cpy_r_r147 = CPyObject_GetAttr(cpy_r_r145, cpy_r_r146);
    if (unlikely(cpy_r_r147 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 62, CPyStatic_globals);
        goto CPyL84;
    }
    cpy_r_r148 = CPyStatics[252]; /* 150 */
    cpy_r_r149 = CPyStatics[253]; /* 850 */
    PyObject *cpy_r_r150[3] = {cpy_r_r148, cpy_r_r149, cpy_r_r144};
    cpy_r_r151 = (PyObject **)&cpy_r_r150;
    cpy_r_r152 = _PyObject_Vectorcall(cpy_r_r147, cpy_r_r151, 3, 0);
    CPy_DECREF(cpy_r_r147);
    if (unlikely(cpy_r_r152 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 62, CPyStatic_globals);
        goto CPyL84;
    }
    CPy_DECREF(cpy_r_r144);
    ((modTof___SimulationObject *)cpy_r_self)->_V = cpy_r_r152;
    cpy_r_r153 = CPyStatics[254]; /* 20 */
    CPy_INCREF(cpy_r_r153);
    ((modTof___SimulationObject *)cpy_r_self)->_E_per_electron = cpy_r_r153;
    cpy_r_r154 = CPyStatics[247]; /* 1 */
    CPy_INCREF(cpy_r_r154);
    ((modTof___SimulationObject *)cpy_r_self)->_QE = cpy_r_r154;
    cpy_r_r155 = CPyStatics[255]; /* 400 */
    CPy_INCREF(cpy_r_r155);
    ((modTof___SimulationObject *)cpy_r_self)->_sigma_smoothing = cpy_r_r155;
    cpy_r_r156 = CPyStatics[244]; /* 0 */
    CPy_INCREF(cpy_r_r156);
    ((modTof___SimulationObject *)cpy_r_self)->_t_initial = cpy_r_r156;
    cpy_r_r157 = CPyStatics[256]; /* 40 */
    CPy_INCREF(cpy_r_r157);
    ((modTof___SimulationObject *)cpy_r_self)->_particle_init_angle_range = cpy_r_r157;
    cpy_r_r158 = ((modTof___SimulationObject *)cpy_r_self)->_T1_radius;
    CPy_INCREF(cpy_r_r158);
    ((modTof___SimulationObject *)cpy_r_self)->_particle_gen_area = cpy_r_r158;
    cpy_r_r159 = ((modTof___SimulationObject *)cpy_r_self)->_T1z;
    CPy_INCREF(cpy_r_r159);
    cpy_r_r160 = ((modTof___SimulationObject *)cpy_r_self)->_T1_width;
    CPy_INCREF(cpy_r_r160);
    cpy_r_r161 = PyNumber_Add(cpy_r_r159, cpy_r_r160);
    CPy_DECREF(cpy_r_r159);
    CPy_DECREF(cpy_r_r160);
    if (unlikely(cpy_r_r161 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 70, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r162 = CPyStatics[257]; /* 2 */
    cpy_r_r163 = PyNumber_Add(cpy_r_r161, cpy_r_r162);
    CPy_DECREF(cpy_r_r161);
    if (unlikely(cpy_r_r163 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 70, CPyStatic_globals);
        goto CPyL71;
    }
    ((modTof___SimulationObject *)cpy_r_self)->_particle_gen_z = cpy_r_r163;
    cpy_r_r164 = PyFloat_FromDouble(0.00024);
    ((modTof___SimulationObject *)cpy_r_self)->_mean_free_path_scints = cpy_r_r164;
    cpy_r_r165 = CPyStatics[258]; /* 10 */
    CPy_INCREF(cpy_r_r165);
    ((modTof___SimulationObject *)cpy_r_self)->_photons_produced_per_MeV = cpy_r_r165;
    cpy_r_r166 = PyFloat_FromDouble(0.8);
    ((modTof___SimulationObject *)cpy_r_self)->_pr_of_scintillation = cpy_r_r166;
    cpy_r_r167 = CPyStatics[256]; /* 40 */
    CPy_INCREF(cpy_r_r167);
    ((modTof___SimulationObject *)cpy_r_self)->_max_simulated_reflections = cpy_r_r167;
    cpy_r_r168 = CPyStatics[244]; /* 0 */
    CPy_INCREF(cpy_r_r168);
    ((modTof___SimulationObject *)cpy_r_self)->_pmt_electron_travel_time = cpy_r_r168;
    cpy_r_r169 = CPyStatics[247]; /* 1 */
    CPy_INCREF(cpy_r_r169);
    ((modTof___SimulationObject *)cpy_r_self)->_artificial_gain = cpy_r_r169;
    cpy_r_r170 = PyFloat_FromDouble(0.08);
    ((modTof___SimulationObject *)cpy_r_self)->_max_pmt_current_output = cpy_r_r170;
    cpy_r_r171 = PyFloat_FromDouble(0.1);
    ((modTof___SimulationObject *)cpy_r_self)->_pr_absorption = cpy_r_r171;
    cpy_r_r172 = PyFloat_FromDouble(100000.0);
    ((modTof___SimulationObject *)cpy_r_self)->_seperation_time = cpy_r_r172;
    cpy_r_r173 = CPyStatics[259]; /* 100 */
    CPy_INCREF(cpy_r_r173);
    ((modTof___SimulationObject *)cpy_r_self)->_output_bin_width = cpy_r_r173;
    cpy_r_r174 = CPyStatics[247]; /* 1 */
    CPy_INCREF(cpy_r_r174);
    ((modTof___SimulationObject *)cpy_r_self)->_num_particles = cpy_r_r174;
    cpy_r_r175 = PyFloat_FromDouble(1.5);
    ((modTof___SimulationObject *)cpy_r_self)->_CMOS_thresh = cpy_r_r175;
    cpy_r_r176 = PyFloat_FromDouble(0.9);
    ((modTof___SimulationObject *)cpy_r_self)->_reemission_angle_factor = cpy_r_r176;
    cpy_r_r177 = CPyStatics[7]; /* '######################################################' */
    cpy_r_r178 = CPyModule_builtins;
    cpy_r_r179 = CPyStatics[8]; /* 'print' */
    cpy_r_r180 = CPyObject_GetAttr(cpy_r_r178, cpy_r_r179);
    if (unlikely(cpy_r_r180 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 86, CPyStatic_globals);
        goto CPyL71;
    }
    PyObject *cpy_r_r181[1] = {cpy_r_r177};
    cpy_r_r182 = (PyObject **)&cpy_r_r181;
    cpy_r_r183 = _PyObject_Vectorcall(cpy_r_r180, cpy_r_r182, 1, 0);
    CPy_DECREF(cpy_r_r180);
    if (unlikely(cpy_r_r183 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 86, CPyStatic_globals);
        goto CPyL71;
    } else
        goto CPyL85;
CPyL48: ;
    cpy_r_r184 = CPyStatics[9]; /* 'Generated Apparatus Simulation with following defaults' */
    cpy_r_r185 = CPyModule_builtins;
    cpy_r_r186 = CPyStatics[8]; /* 'print' */
    cpy_r_r187 = CPyObject_GetAttr(cpy_r_r185, cpy_r_r186);
    if (unlikely(cpy_r_r187 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 87, CPyStatic_globals);
        goto CPyL71;
    }
    PyObject *cpy_r_r188[1] = {cpy_r_r184};
    cpy_r_r189 = (PyObject **)&cpy_r_r188;
    cpy_r_r190 = _PyObject_Vectorcall(cpy_r_r187, cpy_r_r189, 1, 0);
    CPy_DECREF(cpy_r_r187);
    if (unlikely(cpy_r_r190 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 87, CPyStatic_globals);
        goto CPyL71;
    } else
        goto CPyL86;
CPyL50: ;
    cpy_r_r191 = CPyStatics[7]; /* '######################################################' */
    cpy_r_r192 = CPyModule_builtins;
    cpy_r_r193 = CPyStatics[8]; /* 'print' */
    cpy_r_r194 = CPyObject_GetAttr(cpy_r_r192, cpy_r_r193);
    if (unlikely(cpy_r_r194 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 88, CPyStatic_globals);
        goto CPyL71;
    }
    PyObject *cpy_r_r195[1] = {cpy_r_r191};
    cpy_r_r196 = (PyObject **)&cpy_r_r195;
    cpy_r_r197 = _PyObject_Vectorcall(cpy_r_r194, cpy_r_r196, 1, 0);
    CPy_DECREF(cpy_r_r194);
    if (unlikely(cpy_r_r197 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 88, CPyStatic_globals);
        goto CPyL71;
    } else
        goto CPyL87;
CPyL52: ;
    cpy_r_r198 = CPyStatics[10]; /* 'PARTICLE: Mean Free Path =' */
    cpy_r_r199 = ((modTof___SimulationObject *)cpy_r_self)->_mean_free_path_scints;
    CPy_INCREF(cpy_r_r199);
    cpy_r_r200 = CPyStatics[11]; /* 'cm' */
    cpy_r_r201 = CPyModule_builtins;
    cpy_r_r202 = CPyStatics[8]; /* 'print' */
    cpy_r_r203 = CPyObject_GetAttr(cpy_r_r201, cpy_r_r202);
    if (unlikely(cpy_r_r203 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 89, CPyStatic_globals);
        goto CPyL88;
    }
    PyObject *cpy_r_r204[3] = {cpy_r_r198, cpy_r_r199, cpy_r_r200};
    cpy_r_r205 = (PyObject **)&cpy_r_r204;
    cpy_r_r206 = _PyObject_Vectorcall(cpy_r_r203, cpy_r_r205, 3, 0);
    CPy_DECREF(cpy_r_r203);
    if (unlikely(cpy_r_r206 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 89, CPyStatic_globals);
        goto CPyL88;
    } else
        goto CPyL89;
CPyL54: ;
    CPy_DECREF(cpy_r_r199);
    cpy_r_r207 = CPyStatics[12]; /* ('PARTICLE: Time Seperation between sequential Particles '
                                    'if simulation more than 1 =') */
    cpy_r_r208 = ((modTof___SimulationObject *)cpy_r_self)->_seperation_time;
    CPy_INCREF(cpy_r_r208);
    cpy_r_r209 = CPyModule_builtins;
    cpy_r_r210 = CPyStatics[8]; /* 'print' */
    cpy_r_r211 = CPyObject_GetAttr(cpy_r_r209, cpy_r_r210);
    if (unlikely(cpy_r_r211 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 90, CPyStatic_globals);
        goto CPyL90;
    }
    PyObject *cpy_r_r212[2] = {cpy_r_r207, cpy_r_r208};
    cpy_r_r213 = (PyObject **)&cpy_r_r212;
    cpy_r_r214 = _PyObject_Vectorcall(cpy_r_r211, cpy_r_r213, 2, 0);
    CPy_DECREF(cpy_r_r211);
    if (unlikely(cpy_r_r214 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 90, CPyStatic_globals);
        goto CPyL90;
    } else
        goto CPyL91;
CPyL56: ;
    CPy_DECREF(cpy_r_r208);
    cpy_r_r215 = CPyStatics[13]; /* 'SCINT:    Probability of Scintillaton =' */
    cpy_r_r216 = ((modTof___SimulationObject *)cpy_r_self)->_pr_of_scintillation;
    CPy_INCREF(cpy_r_r216);
    cpy_r_r217 = CPyModule_builtins;
    cpy_r_r218 = CPyStatics[8]; /* 'print' */
    cpy_r_r219 = CPyObject_GetAttr(cpy_r_r217, cpy_r_r218);
    if (unlikely(cpy_r_r219 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 91, CPyStatic_globals);
        goto CPyL92;
    }
    PyObject *cpy_r_r220[2] = {cpy_r_r215, cpy_r_r216};
    cpy_r_r221 = (PyObject **)&cpy_r_r220;
    cpy_r_r222 = _PyObject_Vectorcall(cpy_r_r219, cpy_r_r221, 2, 0);
    CPy_DECREF(cpy_r_r219);
    if (unlikely(cpy_r_r222 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 91, CPyStatic_globals);
        goto CPyL92;
    } else
        goto CPyL93;
CPyL58: ;
    CPy_DECREF(cpy_r_r216);
    cpy_r_r223 = CPyStatics[14]; /* 'PMT:      Quantum Efficiency is set to' */
    cpy_r_r224 = ((modTof___SimulationObject *)cpy_r_self)->_QE;
    CPy_INCREF(cpy_r_r224);
    cpy_r_r225 = CPyStatics[15]; /* 'by default to keep more pulses' */
    cpy_r_r226 = CPyModule_builtins;
    cpy_r_r227 = CPyStatics[8]; /* 'print' */
    cpy_r_r228 = CPyObject_GetAttr(cpy_r_r226, cpy_r_r227);
    if (unlikely(cpy_r_r228 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 92, CPyStatic_globals);
        goto CPyL94;
    }
    PyObject *cpy_r_r229[3] = {cpy_r_r223, cpy_r_r224, cpy_r_r225};
    cpy_r_r230 = (PyObject **)&cpy_r_r229;
    cpy_r_r231 = _PyObject_Vectorcall(cpy_r_r228, cpy_r_r230, 3, 0);
    CPy_DECREF(cpy_r_r228);
    if (unlikely(cpy_r_r231 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 92, CPyStatic_globals);
        goto CPyL94;
    } else
        goto CPyL95;
CPyL60: ;
    CPy_DECREF(cpy_r_r224);
    cpy_r_r232 = CPyStatics[16]; /* 'PMT:      Energy per Photoelectron is set to' */
    cpy_r_r233 = ((modTof___SimulationObject *)cpy_r_self)->_E_per_electron;
    CPy_INCREF(cpy_r_r233);
    cpy_r_r234 = CPyStatics[17]; /* 'by best estimation' */
    cpy_r_r235 = CPyModule_builtins;
    cpy_r_r236 = CPyStatics[8]; /* 'print' */
    cpy_r_r237 = CPyObject_GetAttr(cpy_r_r235, cpy_r_r236);
    if (unlikely(cpy_r_r237 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 93, CPyStatic_globals);
        goto CPyL96;
    }
    PyObject *cpy_r_r238[3] = {cpy_r_r232, cpy_r_r233, cpy_r_r234};
    cpy_r_r239 = (PyObject **)&cpy_r_r238;
    cpy_r_r240 = _PyObject_Vectorcall(cpy_r_r237, cpy_r_r239, 3, 0);
    CPy_DECREF(cpy_r_r237);
    if (unlikely(cpy_r_r240 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 93, CPyStatic_globals);
        goto CPyL96;
    } else
        goto CPyL97;
CPyL62: ;
    CPy_DECREF(cpy_r_r233);
    cpy_r_r241 = CPyStatics[18]; /* 'PMT:      Artificial Gain on Output Current =' */
    cpy_r_r242 = ((modTof___SimulationObject *)cpy_r_self)->_artificial_gain;
    CPy_INCREF(cpy_r_r242);
    cpy_r_r243 = CPyModule_builtins;
    cpy_r_r244 = CPyStatics[8]; /* 'print' */
    cpy_r_r245 = CPyObject_GetAttr(cpy_r_r243, cpy_r_r244);
    if (unlikely(cpy_r_r245 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 94, CPyStatic_globals);
        goto CPyL98;
    }
    PyObject *cpy_r_r246[2] = {cpy_r_r241, cpy_r_r242};
    cpy_r_r247 = (PyObject **)&cpy_r_r246;
    cpy_r_r248 = _PyObject_Vectorcall(cpy_r_r245, cpy_r_r247, 2, 0);
    CPy_DECREF(cpy_r_r245);
    if (unlikely(cpy_r_r248 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 94, CPyStatic_globals);
        goto CPyL98;
    } else
        goto CPyL99;
CPyL64: ;
    CPy_DECREF(cpy_r_r242);
    cpy_r_r249 = CPyStatics[19]; /* 'OUTPUT:   Binning Width for PWL output file =' */
    cpy_r_r250 = ((modTof___SimulationObject *)cpy_r_self)->_output_bin_width;
    CPy_INCREF(cpy_r_r250);
    cpy_r_r251 = CPyStatics[20]; /* 'ps' */
    cpy_r_r252 = CPyModule_builtins;
    cpy_r_r253 = CPyStatics[8]; /* 'print' */
    cpy_r_r254 = CPyObject_GetAttr(cpy_r_r252, cpy_r_r253);
    if (unlikely(cpy_r_r254 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 95, CPyStatic_globals);
        goto CPyL100;
    }
    PyObject *cpy_r_r255[3] = {cpy_r_r249, cpy_r_r250, cpy_r_r251};
    cpy_r_r256 = (PyObject **)&cpy_r_r255;
    cpy_r_r257 = _PyObject_Vectorcall(cpy_r_r254, cpy_r_r256, 3, 0);
    CPy_DECREF(cpy_r_r254);
    if (unlikely(cpy_r_r257 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 95, CPyStatic_globals);
        goto CPyL100;
    } else
        goto CPyL101;
CPyL66: ;
    CPy_DECREF(cpy_r_r250);
    cpy_r_r258 = CPyStatics[21]; /* ('\n'
                                    'Run with .run() function given optional arguments '
                                    'below') */
    cpy_r_r259 = CPyModule_builtins;
    cpy_r_r260 = CPyStatics[8]; /* 'print' */
    cpy_r_r261 = CPyObject_GetAttr(cpy_r_r259, cpy_r_r260);
    if (unlikely(cpy_r_r261 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 96, CPyStatic_globals);
        goto CPyL71;
    }
    PyObject *cpy_r_r262[1] = {cpy_r_r258};
    cpy_r_r263 = (PyObject **)&cpy_r_r262;
    cpy_r_r264 = _PyObject_Vectorcall(cpy_r_r261, cpy_r_r263, 1, 0);
    CPy_DECREF(cpy_r_r261);
    if (unlikely(cpy_r_r264 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 96, CPyStatic_globals);
        goto CPyL71;
    } else
        goto CPyL102;
CPyL68: ;
    cpy_r_r265 = CPyStatics[22]; /* "integer n particles, 'delta_t' =" */
    cpy_r_r266 = ((modTof___SimulationObject *)cpy_r_self)->_seperation_time;
    CPy_INCREF(cpy_r_r266);
    cpy_r_r267 = CPyStatics[23]; /* 'ps particle time seperation' */
    cpy_r_r268 = CPyModule_builtins;
    cpy_r_r269 = CPyStatics[8]; /* 'print' */
    cpy_r_r270 = CPyObject_GetAttr(cpy_r_r268, cpy_r_r269);
    if (unlikely(cpy_r_r270 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 97, CPyStatic_globals);
        goto CPyL103;
    }
    PyObject *cpy_r_r271[3] = {cpy_r_r265, cpy_r_r266, cpy_r_r267};
    cpy_r_r272 = (PyObject **)&cpy_r_r271;
    cpy_r_r273 = _PyObject_Vectorcall(cpy_r_r270, cpy_r_r272, 3, 0);
    CPy_DECREF(cpy_r_r270);
    if (unlikely(cpy_r_r273 == NULL)) {
        CPy_AddTraceback("modTof.py", "__init__", 97, CPyStatic_globals);
        goto CPyL103;
    } else
        goto CPyL104;
CPyL70: ;
    CPy_DECREF(cpy_r_r266);
    return 1;
CPyL71: ;
    cpy_r_r274 = 2;
    return cpy_r_r274;
CPyL72: ;
    CPy_DecRef(cpy_r_r25);
    goto CPyL71;
CPyL73: ;
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r28);
    CPy_DecRef(cpy_r_r29);
    goto CPyL71;
CPyL74: ;
    CPy_DecRef(cpy_r_r37);
    goto CPyL71;
CPyL75: ;
    CPy_DecRef(cpy_r_r37);
    CPy_DecRef(cpy_r_r40);
    CPy_DecRef(cpy_r_r41);
    goto CPyL71;
CPyL76: ;
    CPy_DecRef(cpy_r_r49);
    goto CPyL71;
CPyL77: ;
    CPy_DecRef(cpy_r_r49);
    CPy_DecRef(cpy_r_r53);
    CPy_DecRef(cpy_r_r54);
    goto CPyL71;
CPyL78: ;
    CPy_DecRef(cpy_r_r63);
    goto CPyL71;
CPyL79: ;
    CPy_DecRef(cpy_r_r63);
    CPy_DecRef(cpy_r_r66);
    CPy_DecRef(cpy_r_r67);
    goto CPyL71;
CPyL80: ;
    CPy_DecRef(cpy_r_r79);
    goto CPyL71;
CPyL81: ;
    CPy_DecRef(cpy_r_r96);
    goto CPyL71;
CPyL82: ;
    CPy_DecRef(cpy_r_r113);
    goto CPyL71;
CPyL83: ;
    CPy_DecRef(cpy_r_r130);
    goto CPyL71;
CPyL84: ;
    CPy_DecRef(cpy_r_r144);
    goto CPyL71;
CPyL85: ;
    CPy_DECREF(cpy_r_r183);
    goto CPyL48;
CPyL86: ;
    CPy_DECREF(cpy_r_r190);
    goto CPyL50;
CPyL87: ;
    CPy_DECREF(cpy_r_r197);
    goto CPyL52;
CPyL88: ;
    CPy_DecRef(cpy_r_r199);
    goto CPyL71;
CPyL89: ;
    CPy_DECREF(cpy_r_r206);
    goto CPyL54;
CPyL90: ;
    CPy_DecRef(cpy_r_r208);
    goto CPyL71;
CPyL91: ;
    CPy_DECREF(cpy_r_r214);
    goto CPyL56;
CPyL92: ;
    CPy_DecRef(cpy_r_r216);
    goto CPyL71;
CPyL93: ;
    CPy_DECREF(cpy_r_r222);
    goto CPyL58;
CPyL94: ;
    CPy_DecRef(cpy_r_r224);
    goto CPyL71;
CPyL95: ;
    CPy_DECREF(cpy_r_r231);
    goto CPyL60;
CPyL96: ;
    CPy_DecRef(cpy_r_r233);
    goto CPyL71;
CPyL97: ;
    CPy_DECREF(cpy_r_r240);
    goto CPyL62;
CPyL98: ;
    CPy_DecRef(cpy_r_r242);
    goto CPyL71;
CPyL99: ;
    CPy_DECREF(cpy_r_r248);
    goto CPyL64;
CPyL100: ;
    CPy_DecRef(cpy_r_r250);
    goto CPyL71;
CPyL101: ;
    CPy_DECREF(cpy_r_r257);
    goto CPyL66;
CPyL102: ;
    CPy_DECREF(cpy_r_r264);
    goto CPyL68;
CPyL103: ;
    CPy_DecRef(cpy_r_r266);
    goto CPyL71;
CPyL104: ;
    CPy_DECREF(cpy_r_r273);
    goto CPyL70;
}

PyObject *CPyPy_Simulation_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "", "__init__", kwlist)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    char retval = CPyDef_Simulation_____init__(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("modTof.py", "__init__", 29, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Simulation___round_to_sig(PyObject *cpy_r_self, PyObject *cpy_r_x) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject **cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject **cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject **cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject **cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    cpy_r_r0 = CPyModule_numpy;
    cpy_r_r1 = CPyStatics[24]; /* 'abs' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("modTof.py", "round_to_sig", 105, CPyStatic_globals);
        goto CPyL9;
    }
    PyObject *cpy_r_r3[1] = {cpy_r_x};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = _PyObject_Vectorcall(cpy_r_r2, cpy_r_r4, 1, 0);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("modTof.py", "round_to_sig", 105, CPyStatic_globals);
        goto CPyL9;
    }
    cpy_r_r6 = CPyModule_numpy;
    cpy_r_r7 = CPyStatics[25]; /* 'log10' */
    cpy_r_r8 = CPyObject_GetAttr(cpy_r_r6, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("modTof.py", "round_to_sig", 105, CPyStatic_globals);
        goto CPyL10;
    }
    PyObject *cpy_r_r9[1] = {cpy_r_r5};
    cpy_r_r10 = (PyObject **)&cpy_r_r9;
    cpy_r_r11 = _PyObject_Vectorcall(cpy_r_r8, cpy_r_r10, 1, 0);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("modTof.py", "round_to_sig", 105, CPyStatic_globals);
        goto CPyL10;
    }
    CPy_DECREF(cpy_r_r5);
    cpy_r_r12 = CPyModule_numpy;
    cpy_r_r13 = CPyStatics[26]; /* 'floor' */
    cpy_r_r14 = CPyObject_GetAttr(cpy_r_r12, cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("modTof.py", "round_to_sig", 105, CPyStatic_globals);
        goto CPyL11;
    }
    PyObject *cpy_r_r15[1] = {cpy_r_r11};
    cpy_r_r16 = (PyObject **)&cpy_r_r15;
    cpy_r_r17 = _PyObject_Vectorcall(cpy_r_r14, cpy_r_r16, 1, 0);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("modTof.py", "round_to_sig", 105, CPyStatic_globals);
        goto CPyL11;
    }
    CPy_DECREF(cpy_r_r11);
    cpy_r_r18 = (PyObject *)&PyLong_Type;
    PyObject *cpy_r_r19[1] = {cpy_r_r17};
    cpy_r_r20 = (PyObject **)&cpy_r_r19;
    cpy_r_r21 = _PyObject_Vectorcall(cpy_r_r18, cpy_r_r20, 1, 0);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("modTof.py", "round_to_sig", 105, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_DECREF(cpy_r_r17);
    cpy_r_r22 = PyNumber_Negative(cpy_r_r21);
    CPy_DECREF(cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("modTof.py", "round_to_sig", 105, CPyStatic_globals);
        goto CPyL9;
    }
    return cpy_r_r22;
CPyL9: ;
    cpy_r_r23 = NULL;
    return cpy_r_r23;
CPyL10: ;
    CPy_DecRef(cpy_r_r5);
    goto CPyL9;
CPyL11: ;
    CPy_DecRef(cpy_r_r11);
    goto CPyL9;
CPyL12: ;
    CPy_DecRef(cpy_r_r17);
    goto CPyL9;
}

PyObject *CPyPy_Simulation___round_to_sig(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"x", 0};
    static CPyArg_Parser parser = {"O:round_to_sig", kwlist, 0};
    PyObject *obj_x;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_x)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *arg_x = obj_x;
    PyObject *retval = CPyDef_Simulation___round_to_sig(arg_self, arg_x);
    return retval;
fail: ;
    CPy_AddTraceback("modTof.py", "round_to_sig", 104, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Simulation___normalize(PyObject *cpy_r_self, PyObject *cpy_r_x) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    cpy_r_r0 = CPyModule_numpy;
    cpy_r_r1 = CPyStatics[27]; /* 'linalg' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("modTof.py", "normalize", 109, CPyStatic_globals);
        goto CPyL5;
    }
    cpy_r_r3 = CPyStatics[28]; /* 'norm' */
    cpy_r_r4 = CPyObject_GetAttr(cpy_r_r2, cpy_r_r3);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("modTof.py", "normalize", 109, CPyStatic_globals);
        goto CPyL5;
    }
    PyObject *cpy_r_r5[1] = {cpy_r_x};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = _PyObject_Vectorcall(cpy_r_r4, cpy_r_r6, 1, 0);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("modTof.py", "normalize", 109, CPyStatic_globals);
        goto CPyL5;
    }
    cpy_r_r8 = PyNumber_InPlaceTrueDivide(cpy_r_x, cpy_r_r7);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("modTof.py", "normalize", 109, CPyStatic_globals);
        goto CPyL5;
    }
    cpy_r_x = cpy_r_r8;
    return cpy_r_x;
CPyL5: ;
    cpy_r_r9 = NULL;
    return cpy_r_r9;
}

PyObject *CPyPy_Simulation___normalize(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"x", 0};
    static CPyArg_Parser parser = {"O:normalize", kwlist, 0};
    PyObject *obj_x;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_x)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *arg_x = obj_x;
    PyObject *retval = CPyDef_Simulation___normalize(arg_self, arg_x);
    return retval;
fail: ;
    CPy_AddTraceback("modTof.py", "normalize", 108, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Simulation___lg_condition(PyObject *cpy_r_self, PyObject *cpy_r_corner_pt, PyObject *cpy_r_scint_corner, PyObject *cpy_r_scint_num) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_ret;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    int32_t cpy_r_r23;
    char cpy_r_r24;
    char cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    cpy_r_r0 = CPyStatics[244]; /* 0 */
    cpy_r_r1 = PyObject_GetItem(cpy_r_corner_pt, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 114, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r2 = CPyStatics[244]; /* 0 */
    cpy_r_r3 = PyObject_RichCompare(cpy_r_r1, cpy_r_r2, 4);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 114, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r4 = CPyStatics[244]; /* 0 */
    cpy_r_r5 = PyObject_GetItem(cpy_r_corner_pt, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 114, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r6 = CPyStatics[244]; /* 0 */
    cpy_r_r7 = PyObject_GetItem(cpy_r_scint_corner, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 114, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r8 = PyObject_RichCompare(cpy_r_r5, cpy_r_r7, 0);
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 114, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r9 = PyNumber_And(cpy_r_r3, cpy_r_r8);
    CPy_DECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 114, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r10 = CPyStatics[247]; /* 1 */
    cpy_r_r11 = PyObject_GetItem(cpy_r_corner_pt, cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 114, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r12 = CPyStatics[244]; /* 0 */
    cpy_r_r13 = PyObject_RichCompare(cpy_r_r11, cpy_r_r12, 0);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 114, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r14 = PyNumber_And(cpy_r_r9, cpy_r_r13);
    CPy_DECREF(cpy_r_r9);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 114, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r15 = CPyStatics[247]; /* 1 */
    cpy_r_r16 = PyObject_GetItem(cpy_r_corner_pt, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 114, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r17 = CPyStatics[247]; /* 1 */
    cpy_r_r18 = PyObject_GetItem(cpy_r_scint_corner, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 114, CPyStatic_globals);
        goto CPyL36;
    }
    cpy_r_r19 = PyObject_RichCompare(cpy_r_r16, cpy_r_r18, 4);
    CPy_DECREF(cpy_r_r16);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 114, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r20 = PyNumber_And(cpy_r_r14, cpy_r_r19);
    CPy_DECREF(cpy_r_r14);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 114, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_ret = cpy_r_r20;
    cpy_r_r21 = CPyStatics[248]; /* 4 */
    cpy_r_r22 = PyObject_RichCompare(cpy_r_scint_num, cpy_r_r21, 2);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 115, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r23 = PyObject_IsTrue(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    cpy_r_r24 = cpy_r_r23 >= 0;
    if (unlikely(!cpy_r_r24)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 115, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r25 = cpy_r_r23;
    if (cpy_r_r25) {
        goto CPyL38;
    } else
        goto CPyL30;
CPyL16: ;
    cpy_r_r26 = CPyStatics[244]; /* 0 */
    cpy_r_r27 = PyObject_GetItem(cpy_r_corner_pt, cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 116, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r28 = CPyStatics[244]; /* 0 */
    cpy_r_r29 = PyObject_RichCompare(cpy_r_r27, cpy_r_r28, 4);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 116, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r30 = CPyStatics[244]; /* 0 */
    cpy_r_r31 = PyObject_GetItem(cpy_r_corner_pt, cpy_r_r30);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 116, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r32 = CPyStatics[244]; /* 0 */
    cpy_r_r33 = PyObject_GetItem(cpy_r_scint_corner, cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 116, CPyStatic_globals);
        goto CPyL40;
    }
    cpy_r_r34 = PyObject_RichCompare(cpy_r_r31, cpy_r_r33, 0);
    CPy_DECREF(cpy_r_r31);
    CPy_DECREF(cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 116, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r35 = PyNumber_And(cpy_r_r29, cpy_r_r34);
    CPy_DECREF(cpy_r_r29);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 116, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r36 = CPyStatics[247]; /* 1 */
    cpy_r_r37 = PyObject_GetItem(cpy_r_corner_pt, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 116, CPyStatic_globals);
        goto CPyL41;
    }
    cpy_r_r38 = CPyStatics[244]; /* 0 */
    cpy_r_r39 = PyObject_RichCompare(cpy_r_r37, cpy_r_r38, 0);
    CPy_DECREF(cpy_r_r37);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 116, CPyStatic_globals);
        goto CPyL41;
    }
    cpy_r_r40 = PyNumber_And(cpy_r_r35, cpy_r_r39);
    CPy_DECREF(cpy_r_r35);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 116, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r41 = CPyStatics[247]; /* 1 */
    cpy_r_r42 = PyObject_GetItem(cpy_r_corner_pt, cpy_r_r41);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 116, CPyStatic_globals);
        goto CPyL42;
    }
    cpy_r_r43 = CPyStatics[247]; /* 1 */
    cpy_r_r44 = PyObject_GetItem(cpy_r_scint_corner, cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 116, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_r45 = PyObject_RichCompare(cpy_r_r42, cpy_r_r44, 4);
    CPy_DECREF(cpy_r_r42);
    CPy_DECREF(cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 116, CPyStatic_globals);
        goto CPyL42;
    }
    cpy_r_r46 = PyNumber_And(cpy_r_r40, cpy_r_r45);
    CPy_DECREF(cpy_r_r40);
    CPy_DECREF(cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("modTof.py", "lg_condition", 116, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_ret = cpy_r_r46;
CPyL30: ;
    return cpy_r_ret;
CPyL31: ;
    cpy_r_r47 = NULL;
    return cpy_r_r47;
CPyL32: ;
    CPy_DecRef(cpy_r_r3);
    goto CPyL31;
CPyL33: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r5);
    goto CPyL31;
CPyL34: ;
    CPy_DecRef(cpy_r_r9);
    goto CPyL31;
CPyL35: ;
    CPy_DecRef(cpy_r_r14);
    goto CPyL31;
CPyL36: ;
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r16);
    goto CPyL31;
CPyL37: ;
    CPy_DecRef(cpy_r_ret);
    goto CPyL31;
CPyL38: ;
    CPy_DECREF(cpy_r_ret);
    goto CPyL16;
CPyL39: ;
    CPy_DecRef(cpy_r_r29);
    goto CPyL31;
CPyL40: ;
    CPy_DecRef(cpy_r_r29);
    CPy_DecRef(cpy_r_r31);
    goto CPyL31;
CPyL41: ;
    CPy_DecRef(cpy_r_r35);
    goto CPyL31;
CPyL42: ;
    CPy_DecRef(cpy_r_r40);
    goto CPyL31;
CPyL43: ;
    CPy_DecRef(cpy_r_r40);
    CPy_DecRef(cpy_r_r42);
    goto CPyL31;
}

PyObject *CPyPy_Simulation___lg_condition(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"corner_pt", "scint_corner", "scint_num", 0};
    static CPyArg_Parser parser = {"OOO:lg_condition", kwlist, 0};
    PyObject *obj_corner_pt;
    PyObject *obj_scint_corner;
    PyObject *obj_scint_num;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_corner_pt, &obj_scint_corner, &obj_scint_num)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *arg_corner_pt = obj_corner_pt;
    PyObject *arg_scint_corner = obj_scint_corner;
    PyObject *arg_scint_num = obj_scint_num;
    PyObject *retval = CPyDef_Simulation___lg_condition(arg_self, arg_corner_pt, arg_scint_corner, arg_scint_num);
    return retval;
fail: ;
    CPy_AddTraceback("modTof.py", "lg_condition", 113, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Simulation___scint_condition(PyObject *cpy_r_self, PyObject *cpy_r_corner_pt, PyObject *cpy_r_scint_radius, PyObject *cpy_r_scint_num) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject **cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_ret;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    int32_t cpy_r_r23;
    char cpy_r_r24;
    char cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject **cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject **cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = CPyStatics[244]; /* 0 */
    cpy_r_r2 = CPyStatics[257]; /* 2 */
    cpy_r_r3 = PySlice_New(cpy_r_r1, cpy_r_r2, cpy_r_r0);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_condition", 121, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r4 = PyObject_GetItem(cpy_r_corner_pt, cpy_r_r3);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_condition", 121, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r5 = CPyStatics[257]; /* 2 */
    cpy_r_r6 = CPyNumber_Power(cpy_r_r4, cpy_r_r5);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_condition", 121, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r7 = CPyModule_numpy;
    cpy_r_r8 = CPyStatics[29]; /* 'sum' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_condition", 121, CPyStatic_globals);
        goto CPyL22;
    }
    PyObject *cpy_r_r10[1] = {cpy_r_r6};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = _PyObject_Vectorcall(cpy_r_r9, cpy_r_r11, 1, 0);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_condition", 121, CPyStatic_globals);
        goto CPyL22;
    }
    CPy_DECREF(cpy_r_r6);
    cpy_r_r13 = CPyModule_numpy;
    cpy_r_r14 = CPyStatics[30]; /* 'sqrt' */
    cpy_r_r15 = CPyObject_GetAttr(cpy_r_r13, cpy_r_r14);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_condition", 121, CPyStatic_globals);
        goto CPyL23;
    }
    PyObject *cpy_r_r16[1] = {cpy_r_r12};
    cpy_r_r17 = (PyObject **)&cpy_r_r16;
    cpy_r_r18 = _PyObject_Vectorcall(cpy_r_r15, cpy_r_r17, 1, 0);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_condition", 121, CPyStatic_globals);
        goto CPyL23;
    }
    CPy_DECREF(cpy_r_r12);
    cpy_r_r19 = ((modTof___SimulationObject *)cpy_r_self)->_T1_radius;
    CPy_INCREF(cpy_r_r19);
    cpy_r_r20 = PyObject_RichCompare(cpy_r_r18, cpy_r_r19, 0);
    CPy_DECREF(cpy_r_r18);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_condition", 121, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_ret = cpy_r_r20;
    cpy_r_r21 = CPyStatics[248]; /* 4 */
    cpy_r_r22 = PyObject_RichCompare(cpy_r_scint_num, cpy_r_r21, 2);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_condition", 122, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r23 = PyObject_IsTrue(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    cpy_r_r24 = cpy_r_r23 >= 0;
    if (unlikely(!cpy_r_r24)) {
        CPy_AddTraceback("modTof.py", "scint_condition", 122, CPyStatic_globals);
        goto CPyL24;
    }
    cpy_r_r25 = cpy_r_r23;
    if (cpy_r_r25) {
        goto CPyL25;
    } else
        goto CPyL20;
CPyL11: ;
    cpy_r_r26 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r27 = CPyStatics[244]; /* 0 */
    cpy_r_r28 = CPyStatics[257]; /* 2 */
    cpy_r_r29 = PySlice_New(cpy_r_r27, cpy_r_r28, cpy_r_r26);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_condition", 123, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r30 = PyObject_GetItem(cpy_r_corner_pt, cpy_r_r29);
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_condition", 123, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r31 = CPyStatics[257]; /* 2 */
    cpy_r_r32 = CPyNumber_Power(cpy_r_r30, cpy_r_r31);
    CPy_DECREF(cpy_r_r30);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_condition", 123, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r33 = CPyModule_numpy;
    cpy_r_r34 = CPyStatics[29]; /* 'sum' */
    cpy_r_r35 = CPyObject_GetAttr(cpy_r_r33, cpy_r_r34);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_condition", 123, CPyStatic_globals);
        goto CPyL26;
    }
    PyObject *cpy_r_r36[1] = {cpy_r_r32};
    cpy_r_r37 = (PyObject **)&cpy_r_r36;
    cpy_r_r38 = _PyObject_Vectorcall(cpy_r_r35, cpy_r_r37, 1, 0);
    CPy_DECREF(cpy_r_r35);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_condition", 123, CPyStatic_globals);
        goto CPyL26;
    }
    CPy_DECREF(cpy_r_r32);
    cpy_r_r39 = CPyModule_numpy;
    cpy_r_r40 = CPyStatics[30]; /* 'sqrt' */
    cpy_r_r41 = CPyObject_GetAttr(cpy_r_r39, cpy_r_r40);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_condition", 123, CPyStatic_globals);
        goto CPyL27;
    }
    PyObject *cpy_r_r42[1] = {cpy_r_r38};
    cpy_r_r43 = (PyObject **)&cpy_r_r42;
    cpy_r_r44 = _PyObject_Vectorcall(cpy_r_r41, cpy_r_r43, 1, 0);
    CPy_DECREF(cpy_r_r41);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_condition", 123, CPyStatic_globals);
        goto CPyL27;
    }
    CPy_DECREF(cpy_r_r38);
    cpy_r_r45 = ((modTof___SimulationObject *)cpy_r_self)->_T4_radius;
    CPy_INCREF(cpy_r_r45);
    cpy_r_r46 = PyObject_RichCompare(cpy_r_r44, cpy_r_r45, 0);
    CPy_DECREF(cpy_r_r44);
    CPy_DECREF(cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_condition", 123, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_ret = cpy_r_r46;
CPyL20: ;
    return cpy_r_ret;
CPyL21: ;
    cpy_r_r47 = NULL;
    return cpy_r_r47;
CPyL22: ;
    CPy_DecRef(cpy_r_r6);
    goto CPyL21;
CPyL23: ;
    CPy_DecRef(cpy_r_r12);
    goto CPyL21;
CPyL24: ;
    CPy_DecRef(cpy_r_ret);
    goto CPyL21;
CPyL25: ;
    CPy_DECREF(cpy_r_ret);
    goto CPyL11;
CPyL26: ;
    CPy_DecRef(cpy_r_r32);
    goto CPyL21;
CPyL27: ;
    CPy_DecRef(cpy_r_r38);
    goto CPyL21;
}

PyObject *CPyPy_Simulation___scint_condition(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"corner_pt", "scint_radius", "scint_num", 0};
    static CPyArg_Parser parser = {"OOO:scint_condition", kwlist, 0};
    PyObject *obj_corner_pt;
    PyObject *obj_scint_radius;
    PyObject *obj_scint_num;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_corner_pt, &obj_scint_radius, &obj_scint_num)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *arg_corner_pt = obj_corner_pt;
    PyObject *arg_scint_radius = obj_scint_radius;
    PyObject *arg_scint_num = obj_scint_num;
    PyObject *retval = CPyDef_Simulation___scint_condition(arg_self, arg_corner_pt, arg_scint_radius, arg_scint_num);
    return retval;
fail: ;
    CPy_AddTraceback("modTof.py", "scint_condition", 120, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Simulation___distance_circle(PyObject *cpy_r_self, PyObject *cpy_r_u, PyObject *cpy_r_o, PyObject *cpy_r_center, PyObject *cpy_r_radius, PyObject *cpy_r_quadrant) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_cond;
    int32_t cpy_r_r9;
    char cpy_r_r10;
    char cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_D;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject **cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject **cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_bigDelta;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject **cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_magDsq;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject **cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_magDeltasq;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject **cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_DdotDelta;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    int32_t cpy_r_r63;
    char cpy_r_r64;
    char cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject **cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_sqrt_term;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_b_term;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_rootA;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_rootB;
    PyObject *cpy_r_r85;
    char cpy_r_r86;
    char cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject **cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject **cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    int32_t cpy_r_r101;
    char cpy_r_r102;
    char cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject **cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject **cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    int32_t cpy_r_r120;
    char cpy_r_r121;
    char cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject **cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject **cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    if (cpy_r_quadrant != NULL) goto CPyL73;
    cpy_r_r0 = 0 ? Py_True : Py_False;
    CPy_INCREF(cpy_r_r0);
    cpy_r_quadrant = cpy_r_r0;
CPyL2: ;
    cpy_r_r1 = CPyModule_numpy;
    cpy_r_r2 = CPyStatics[31]; /* 'dot' */
    cpy_r_r3 = CPyObject_GetAttr(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 131, CPyStatic_globals);
        goto CPyL74;
    }
    PyObject *cpy_r_r4[2] = {cpy_r_u, cpy_r_o};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = _PyObject_Vectorcall(cpy_r_r3, cpy_r_r5, 2, 0);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 131, CPyStatic_globals);
        goto CPyL74;
    }
    cpy_r_r7 = CPyStatics[244]; /* 0 */
    cpy_r_r8 = PyObject_RichCompare(cpy_r_r6, cpy_r_r7, 0);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 131, CPyStatic_globals);
        goto CPyL74;
    }
    cpy_r_cond = cpy_r_r8;
    cpy_r_r9 = PyObject_IsTrue(cpy_r_cond);
    cpy_r_r10 = cpy_r_r9 >= 0;
    if (unlikely(!cpy_r_r10)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 131, CPyStatic_globals);
        goto CPyL75;
    }
    cpy_r_r11 = cpy_r_r9;
    if (!cpy_r_r11) goto CPyL9;
    cpy_r_r12 = CPyStatics[260]; /* -1 */
    cpy_r_r13 = PyNumber_Multiply(cpy_r_u, cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 132, CPyStatic_globals);
        goto CPyL75;
    }
    cpy_r_r14 = cpy_r_r13;
    goto CPyL10;
CPyL9: ;
    CPy_INCREF(cpy_r_u);
    cpy_r_r14 = cpy_r_u;
CPyL10: ;
    cpy_r_D = cpy_r_r14;
    cpy_r_r15 = CPyModule_numpy;
    cpy_r_r16 = CPyStatics[32]; /* 'array' */
    cpy_r_r17 = CPyObject_GetAttr(cpy_r_r15, cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 133, CPyStatic_globals);
        goto CPyL76;
    }
    PyObject *cpy_r_r18[1] = {cpy_r_o};
    cpy_r_r19 = (PyObject **)&cpy_r_r18;
    cpy_r_r20 = _PyObject_Vectorcall(cpy_r_r17, cpy_r_r19, 1, 0);
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 133, CPyStatic_globals);
        goto CPyL76;
    }
    cpy_r_r21 = CPyModule_numpy;
    cpy_r_r22 = CPyStatics[32]; /* 'array' */
    cpy_r_r23 = CPyObject_GetAttr(cpy_r_r21, cpy_r_r22);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 133, CPyStatic_globals);
        goto CPyL77;
    }
    PyObject *cpy_r_r24[1] = {cpy_r_center};
    cpy_r_r25 = (PyObject **)&cpy_r_r24;
    cpy_r_r26 = _PyObject_Vectorcall(cpy_r_r23, cpy_r_r25, 1, 0);
    CPy_DECREF(cpy_r_r23);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 133, CPyStatic_globals);
        goto CPyL77;
    }
    cpy_r_r27 = PyNumber_Subtract(cpy_r_r20, cpy_r_r26);
    CPy_DECREF(cpy_r_r20);
    CPy_DECREF(cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 133, CPyStatic_globals);
        goto CPyL76;
    }
    cpy_r_bigDelta = cpy_r_r27;
    cpy_r_r28 = CPyModule_numpy;
    cpy_r_r29 = CPyStatics[27]; /* 'linalg' */
    cpy_r_r30 = CPyObject_GetAttr(cpy_r_r28, cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 134, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r31 = CPyStatics[28]; /* 'norm' */
    cpy_r_r32 = CPyObject_GetAttr(cpy_r_r30, cpy_r_r31);
    CPy_DECREF(cpy_r_r30);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 134, CPyStatic_globals);
        goto CPyL78;
    }
    PyObject *cpy_r_r33[1] = {cpy_r_D};
    cpy_r_r34 = (PyObject **)&cpy_r_r33;
    cpy_r_r35 = _PyObject_Vectorcall(cpy_r_r32, cpy_r_r34, 1, 0);
    CPy_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 134, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r36 = CPyStatics[257]; /* 2 */
    cpy_r_r37 = CPyNumber_Power(cpy_r_r35, cpy_r_r36);
    CPy_DECREF(cpy_r_r35);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 134, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_magDsq = cpy_r_r37;
    cpy_r_r38 = CPyModule_numpy;
    cpy_r_r39 = CPyStatics[27]; /* 'linalg' */
    cpy_r_r40 = CPyObject_GetAttr(cpy_r_r38, cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 135, CPyStatic_globals);
        goto CPyL79;
    }
    cpy_r_r41 = CPyStatics[28]; /* 'norm' */
    cpy_r_r42 = CPyObject_GetAttr(cpy_r_r40, cpy_r_r41);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 135, CPyStatic_globals);
        goto CPyL79;
    }
    PyObject *cpy_r_r43[1] = {cpy_r_bigDelta};
    cpy_r_r44 = (PyObject **)&cpy_r_r43;
    cpy_r_r45 = _PyObject_Vectorcall(cpy_r_r42, cpy_r_r44, 1, 0);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 135, CPyStatic_globals);
        goto CPyL79;
    }
    cpy_r_r46 = CPyStatics[257]; /* 2 */
    cpy_r_r47 = CPyNumber_Power(cpy_r_r45, cpy_r_r46);
    CPy_DECREF(cpy_r_r45);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 135, CPyStatic_globals);
        goto CPyL79;
    }
    cpy_r_magDeltasq = cpy_r_r47;
    cpy_r_r48 = CPyModule_numpy;
    cpy_r_r49 = CPyStatics[31]; /* 'dot' */
    cpy_r_r50 = CPyObject_GetAttr(cpy_r_r48, cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 136, CPyStatic_globals);
        goto CPyL80;
    }
    PyObject *cpy_r_r51[2] = {cpy_r_D, cpy_r_bigDelta};
    cpy_r_r52 = (PyObject **)&cpy_r_r51;
    cpy_r_r53 = _PyObject_Vectorcall(cpy_r_r50, cpy_r_r52, 2, 0);
    CPy_DECREF(cpy_r_r50);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 136, CPyStatic_globals);
        goto CPyL80;
    }
    CPy_DECREF(cpy_r_D);
    CPy_DECREF(cpy_r_bigDelta);
    cpy_r_DdotDelta = cpy_r_r53;
    cpy_r_r54 = CPyStatics[257]; /* 2 */
    cpy_r_r55 = CPyNumber_Power(cpy_r_DdotDelta, cpy_r_r54);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 137, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r56 = CPyStatics[257]; /* 2 */
    cpy_r_r57 = CPyNumber_Power(cpy_r_radius, cpy_r_r56);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 137, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r58 = PyNumber_Subtract(cpy_r_magDeltasq, cpy_r_r57);
    CPy_DECREF(cpy_r_r57);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 137, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r59 = PyNumber_Multiply(cpy_r_magDsq, cpy_r_r58);
    CPy_DECREF(cpy_r_r58);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 137, CPyStatic_globals);
        goto CPyL82;
    }
    cpy_r_r60 = PyNumber_Subtract(cpy_r_r55, cpy_r_r59);
    CPy_DECREF(cpy_r_r55);
    CPy_DECREF(cpy_r_r59);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 137, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r61 = CPyStatics[244]; /* 0 */
    cpy_r_r62 = PyObject_RichCompare(cpy_r_r60, cpy_r_r61, 0);
    CPy_DECREF(cpy_r_r60);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 137, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r63 = PyObject_IsTrue(cpy_r_r62);
    CPy_DECREF(cpy_r_r62);
    cpy_r_r64 = cpy_r_r63 >= 0;
    if (unlikely(!cpy_r_r64)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 137, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r65 = cpy_r_r63;
    if (cpy_r_r65) {
        goto CPyL83;
    } else
        goto CPyL34;
CPyL33: ;
    cpy_r_r66 = CPyStatics[259]; /* 100 */
    CPy_INCREF(cpy_r_r66);
    return cpy_r_r66;
CPyL34: ;
    cpy_r_r67 = CPyStatics[257]; /* 2 */
    cpy_r_r68 = CPyNumber_Power(cpy_r_DdotDelta, cpy_r_r67);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 139, CPyStatic_globals);
        goto CPyL81;
    }
    cpy_r_r69 = CPyStatics[257]; /* 2 */
    cpy_r_r70 = CPyNumber_Power(cpy_r_radius, cpy_r_r69);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 139, CPyStatic_globals);
        goto CPyL84;
    }
    cpy_r_r71 = PyNumber_Subtract(cpy_r_magDeltasq, cpy_r_r70);
    CPy_DECREF(cpy_r_magDeltasq);
    CPy_DECREF(cpy_r_r70);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 139, CPyStatic_globals);
        goto CPyL85;
    }
    cpy_r_r72 = PyNumber_Multiply(cpy_r_magDsq, cpy_r_r71);
    CPy_DECREF(cpy_r_r71);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 139, CPyStatic_globals);
        goto CPyL85;
    }
    cpy_r_r73 = PyNumber_Subtract(cpy_r_r68, cpy_r_r72);
    CPy_DECREF(cpy_r_r68);
    CPy_DECREF(cpy_r_r72);
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 139, CPyStatic_globals);
        goto CPyL86;
    }
    cpy_r_r74 = CPyModule_numpy;
    cpy_r_r75 = CPyStatics[30]; /* 'sqrt' */
    cpy_r_r76 = CPyObject_GetAttr(cpy_r_r74, cpy_r_r75);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 139, CPyStatic_globals);
        goto CPyL87;
    }
    PyObject *cpy_r_r77[1] = {cpy_r_r73};
    cpy_r_r78 = (PyObject **)&cpy_r_r77;
    cpy_r_r79 = _PyObject_Vectorcall(cpy_r_r76, cpy_r_r78, 1, 0);
    CPy_DECREF(cpy_r_r76);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 139, CPyStatic_globals);
        goto CPyL87;
    }
    CPy_DECREF(cpy_r_r73);
    cpy_r_r80 = PyNumber_TrueDivide(cpy_r_r79, cpy_r_magDsq);
    CPy_DECREF(cpy_r_r79);
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 139, CPyStatic_globals);
        goto CPyL86;
    }
    cpy_r_sqrt_term = cpy_r_r80;
    cpy_r_r81 = PyNumber_Negative(cpy_r_DdotDelta);
    CPy_DECREF(cpy_r_DdotDelta);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 140, CPyStatic_globals);
        goto CPyL88;
    }
    cpy_r_r82 = PyNumber_TrueDivide(cpy_r_r81, cpy_r_magDsq);
    CPy_DECREF(cpy_r_r81);
    CPy_DECREF(cpy_r_magDsq);
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 140, CPyStatic_globals);
        goto CPyL89;
    }
    cpy_r_b_term = cpy_r_r82;
    cpy_r_r83 = PyNumber_Subtract(cpy_r_b_term, cpy_r_sqrt_term);
    if (unlikely(cpy_r_r83 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 141, CPyStatic_globals);
        goto CPyL90;
    }
    cpy_r_rootA = cpy_r_r83;
    cpy_r_r84 = PyNumber_Add(cpy_r_b_term, cpy_r_sqrt_term);
    CPy_DECREF(cpy_r_b_term);
    CPy_DECREF(cpy_r_sqrt_term);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 142, CPyStatic_globals);
        goto CPyL91;
    }
    cpy_r_rootB = cpy_r_r84;
    cpy_r_r85 = 0 ? Py_True : Py_False;
    cpy_r_r86 = cpy_r_quadrant == cpy_r_r85;
    CPy_DECREF(cpy_r_quadrant);
    cpy_r_r87 = cpy_r_r86 ^ 1;
    if (cpy_r_r87) {
        goto CPyL92;
    } else
        goto CPyL61;
CPyL47: ;
    cpy_r_r88 = CPyModule_numpy;
    cpy_r_r89 = CPyStatics[24]; /* 'abs' */
    cpy_r_r90 = CPyObject_GetAttr(cpy_r_r88, cpy_r_r89);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 144, CPyStatic_globals);
        goto CPyL93;
    }
    PyObject *cpy_r_r91[1] = {cpy_r_rootA};
    cpy_r_r92 = (PyObject **)&cpy_r_r91;
    cpy_r_r93 = _PyObject_Vectorcall(cpy_r_r90, cpy_r_r92, 1, 0);
    CPy_DECREF(cpy_r_r90);
    if (unlikely(cpy_r_r93 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 144, CPyStatic_globals);
        goto CPyL93;
    }
    cpy_r_r94 = CPyModule_numpy;
    cpy_r_r95 = CPyStatics[24]; /* 'abs' */
    cpy_r_r96 = CPyObject_GetAttr(cpy_r_r94, cpy_r_r95);
    if (unlikely(cpy_r_r96 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 144, CPyStatic_globals);
        goto CPyL94;
    }
    PyObject *cpy_r_r97[1] = {cpy_r_rootB};
    cpy_r_r98 = (PyObject **)&cpy_r_r97;
    cpy_r_r99 = _PyObject_Vectorcall(cpy_r_r96, cpy_r_r98, 1, 0);
    CPy_DECREF(cpy_r_r96);
    if (unlikely(cpy_r_r99 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 144, CPyStatic_globals);
        goto CPyL94;
    }
    cpy_r_r100 = PyObject_RichCompare(cpy_r_r93, cpy_r_r99, 4);
    CPy_DECREF(cpy_r_r93);
    CPy_DECREF(cpy_r_r99);
    if (unlikely(cpy_r_r100 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 144, CPyStatic_globals);
        goto CPyL93;
    }
    cpy_r_r101 = PyObject_IsTrue(cpy_r_r100);
    CPy_DECREF(cpy_r_r100);
    cpy_r_r102 = cpy_r_r101 >= 0;
    if (unlikely(!cpy_r_r102)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 144, CPyStatic_globals);
        goto CPyL93;
    }
    cpy_r_r103 = cpy_r_r101;
    if (cpy_r_r103) {
        goto CPyL95;
    } else
        goto CPyL96;
CPyL54: ;
    cpy_r_r104 = CPyModule_numpy;
    cpy_r_r105 = CPyStatics[24]; /* 'abs' */
    cpy_r_r106 = CPyObject_GetAttr(cpy_r_r104, cpy_r_r105);
    if (unlikely(cpy_r_r106 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 144, CPyStatic_globals);
        goto CPyL97;
    }
    PyObject *cpy_r_r107[1] = {cpy_r_rootA};
    cpy_r_r108 = (PyObject **)&cpy_r_r107;
    cpy_r_r109 = _PyObject_Vectorcall(cpy_r_r106, cpy_r_r108, 1, 0);
    CPy_DECREF(cpy_r_r106);
    if (unlikely(cpy_r_r109 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 144, CPyStatic_globals);
        goto CPyL97;
    }
    CPy_DECREF(cpy_r_rootA);
    cpy_r_r110 = cpy_r_r109;
    goto CPyL60;
CPyL57: ;
    cpy_r_r111 = CPyModule_numpy;
    cpy_r_r112 = CPyStatics[24]; /* 'abs' */
    cpy_r_r113 = CPyObject_GetAttr(cpy_r_r111, cpy_r_r112);
    if (unlikely(cpy_r_r113 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 144, CPyStatic_globals);
        goto CPyL98;
    }
    PyObject *cpy_r_r114[1] = {cpy_r_rootB};
    cpy_r_r115 = (PyObject **)&cpy_r_r114;
    cpy_r_r116 = _PyObject_Vectorcall(cpy_r_r113, cpy_r_r115, 1, 0);
    CPy_DECREF(cpy_r_r113);
    if (unlikely(cpy_r_r116 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 144, CPyStatic_globals);
        goto CPyL98;
    }
    CPy_DECREF(cpy_r_rootB);
    cpy_r_r110 = cpy_r_r116;
CPyL60: ;
    return cpy_r_r110;
CPyL61: ;
    cpy_r_r117 = CPyStatics[244]; /* 0 */
    cpy_r_r118 = PyObject_RichCompare(cpy_r_rootA, cpy_r_r117, 0);
    if (unlikely(cpy_r_r118 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 145, CPyStatic_globals);
        goto CPyL99;
    }
    cpy_r_r119 = PyNumber_And(cpy_r_r118, cpy_r_cond);
    CPy_DECREF(cpy_r_r118);
    CPy_DECREF(cpy_r_cond);
    if (unlikely(cpy_r_r119 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 145, CPyStatic_globals);
        goto CPyL93;
    }
    cpy_r_r120 = PyObject_IsTrue(cpy_r_r119);
    CPy_DECREF(cpy_r_r119);
    cpy_r_r121 = cpy_r_r120 >= 0;
    if (unlikely(!cpy_r_r121)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 145, CPyStatic_globals);
        goto CPyL93;
    }
    cpy_r_r122 = cpy_r_r120;
    if (cpy_r_r122) {
        goto CPyL100;
    } else
        goto CPyL101;
CPyL65: ;
    cpy_r_r123 = CPyModule_numpy;
    cpy_r_r124 = CPyStatics[24]; /* 'abs' */
    cpy_r_r125 = CPyObject_GetAttr(cpy_r_r123, cpy_r_r124);
    if (unlikely(cpy_r_r125 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 145, CPyStatic_globals);
        goto CPyL97;
    }
    PyObject *cpy_r_r126[1] = {cpy_r_rootA};
    cpy_r_r127 = (PyObject **)&cpy_r_r126;
    cpy_r_r128 = _PyObject_Vectorcall(cpy_r_r125, cpy_r_r127, 1, 0);
    CPy_DECREF(cpy_r_r125);
    if (unlikely(cpy_r_r128 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 145, CPyStatic_globals);
        goto CPyL97;
    }
    CPy_DECREF(cpy_r_rootA);
    cpy_r_r129 = cpy_r_r128;
    goto CPyL71;
CPyL68: ;
    cpy_r_r130 = CPyModule_numpy;
    cpy_r_r131 = CPyStatics[24]; /* 'abs' */
    cpy_r_r132 = CPyObject_GetAttr(cpy_r_r130, cpy_r_r131);
    if (unlikely(cpy_r_r132 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 145, CPyStatic_globals);
        goto CPyL98;
    }
    PyObject *cpy_r_r133[1] = {cpy_r_rootB};
    cpy_r_r134 = (PyObject **)&cpy_r_r133;
    cpy_r_r135 = _PyObject_Vectorcall(cpy_r_r132, cpy_r_r134, 1, 0);
    CPy_DECREF(cpy_r_r132);
    if (unlikely(cpy_r_r135 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_circle", 145, CPyStatic_globals);
        goto CPyL98;
    }
    CPy_DECREF(cpy_r_rootB);
    cpy_r_r129 = cpy_r_r135;
CPyL71: ;
    return cpy_r_r129;
CPyL72: ;
    cpy_r_r136 = NULL;
    return cpy_r_r136;
CPyL73: ;
    CPy_INCREF(cpy_r_quadrant);
    goto CPyL2;
CPyL74: ;
    CPy_DecRef(cpy_r_quadrant);
    goto CPyL72;
CPyL75: ;
    CPy_DecRef(cpy_r_quadrant);
    CPy_DecRef(cpy_r_cond);
    goto CPyL72;
CPyL76: ;
    CPy_DecRef(cpy_r_quadrant);
    CPy_DecRef(cpy_r_cond);
    CPy_DecRef(cpy_r_D);
    goto CPyL72;
CPyL77: ;
    CPy_DecRef(cpy_r_quadrant);
    CPy_DecRef(cpy_r_cond);
    CPy_DecRef(cpy_r_D);
    CPy_DecRef(cpy_r_r20);
    goto CPyL72;
CPyL78: ;
    CPy_DecRef(cpy_r_quadrant);
    CPy_DecRef(cpy_r_cond);
    CPy_DecRef(cpy_r_D);
    CPy_DecRef(cpy_r_bigDelta);
    goto CPyL72;
CPyL79: ;
    CPy_DecRef(cpy_r_quadrant);
    CPy_DecRef(cpy_r_cond);
    CPy_DecRef(cpy_r_D);
    CPy_DecRef(cpy_r_bigDelta);
    CPy_DecRef(cpy_r_magDsq);
    goto CPyL72;
CPyL80: ;
    CPy_DecRef(cpy_r_quadrant);
    CPy_DecRef(cpy_r_cond);
    CPy_DecRef(cpy_r_D);
    CPy_DecRef(cpy_r_bigDelta);
    CPy_DecRef(cpy_r_magDsq);
    CPy_DecRef(cpy_r_magDeltasq);
    goto CPyL72;
CPyL81: ;
    CPy_DecRef(cpy_r_quadrant);
    CPy_DecRef(cpy_r_cond);
    CPy_DecRef(cpy_r_magDsq);
    CPy_DecRef(cpy_r_magDeltasq);
    CPy_DecRef(cpy_r_DdotDelta);
    goto CPyL72;
CPyL82: ;
    CPy_DecRef(cpy_r_quadrant);
    CPy_DecRef(cpy_r_cond);
    CPy_DecRef(cpy_r_magDsq);
    CPy_DecRef(cpy_r_magDeltasq);
    CPy_DecRef(cpy_r_DdotDelta);
    CPy_DecRef(cpy_r_r55);
    goto CPyL72;
CPyL83: ;
    CPy_DECREF(cpy_r_quadrant);
    CPy_DECREF(cpy_r_cond);
    CPy_DECREF(cpy_r_magDsq);
    CPy_DECREF(cpy_r_magDeltasq);
    CPy_DECREF(cpy_r_DdotDelta);
    goto CPyL33;
CPyL84: ;
    CPy_DecRef(cpy_r_quadrant);
    CPy_DecRef(cpy_r_cond);
    CPy_DecRef(cpy_r_magDsq);
    CPy_DecRef(cpy_r_magDeltasq);
    CPy_DecRef(cpy_r_DdotDelta);
    CPy_DecRef(cpy_r_r68);
    goto CPyL72;
CPyL85: ;
    CPy_DecRef(cpy_r_quadrant);
    CPy_DecRef(cpy_r_cond);
    CPy_DecRef(cpy_r_magDsq);
    CPy_DecRef(cpy_r_DdotDelta);
    CPy_DecRef(cpy_r_r68);
    goto CPyL72;
CPyL86: ;
    CPy_DecRef(cpy_r_quadrant);
    CPy_DecRef(cpy_r_cond);
    CPy_DecRef(cpy_r_magDsq);
    CPy_DecRef(cpy_r_DdotDelta);
    goto CPyL72;
CPyL87: ;
    CPy_DecRef(cpy_r_quadrant);
    CPy_DecRef(cpy_r_cond);
    CPy_DecRef(cpy_r_magDsq);
    CPy_DecRef(cpy_r_DdotDelta);
    CPy_DecRef(cpy_r_r73);
    goto CPyL72;
CPyL88: ;
    CPy_DecRef(cpy_r_quadrant);
    CPy_DecRef(cpy_r_cond);
    CPy_DecRef(cpy_r_magDsq);
    CPy_DecRef(cpy_r_sqrt_term);
    goto CPyL72;
CPyL89: ;
    CPy_DecRef(cpy_r_quadrant);
    CPy_DecRef(cpy_r_cond);
    CPy_DecRef(cpy_r_sqrt_term);
    goto CPyL72;
CPyL90: ;
    CPy_DecRef(cpy_r_quadrant);
    CPy_DecRef(cpy_r_cond);
    CPy_DecRef(cpy_r_sqrt_term);
    CPy_DecRef(cpy_r_b_term);
    goto CPyL72;
CPyL91: ;
    CPy_DecRef(cpy_r_quadrant);
    CPy_DecRef(cpy_r_cond);
    CPy_DecRef(cpy_r_rootA);
    goto CPyL72;
CPyL92: ;
    CPy_DECREF(cpy_r_cond);
    goto CPyL47;
CPyL93: ;
    CPy_DecRef(cpy_r_rootA);
    CPy_DecRef(cpy_r_rootB);
    goto CPyL72;
CPyL94: ;
    CPy_DecRef(cpy_r_rootA);
    CPy_DecRef(cpy_r_rootB);
    CPy_DecRef(cpy_r_r93);
    goto CPyL72;
CPyL95: ;
    CPy_DECREF(cpy_r_rootB);
    goto CPyL54;
CPyL96: ;
    CPy_DECREF(cpy_r_rootA);
    goto CPyL57;
CPyL97: ;
    CPy_DecRef(cpy_r_rootA);
    goto CPyL72;
CPyL98: ;
    CPy_DecRef(cpy_r_rootB);
    goto CPyL72;
CPyL99: ;
    CPy_DecRef(cpy_r_cond);
    CPy_DecRef(cpy_r_rootA);
    CPy_DecRef(cpy_r_rootB);
    goto CPyL72;
CPyL100: ;
    CPy_DECREF(cpy_r_rootB);
    goto CPyL65;
CPyL101: ;
    CPy_DECREF(cpy_r_rootA);
    goto CPyL68;
}

PyObject *CPyPy_Simulation___distance_circle(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"u", "o", "center", "radius", "quadrant", 0};
    static CPyArg_Parser parser = {"OOOO|O:distance_circle", kwlist, 0};
    PyObject *obj_u;
    PyObject *obj_o;
    PyObject *obj_center;
    PyObject *obj_radius;
    PyObject *obj_quadrant = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_u, &obj_o, &obj_center, &obj_radius, &obj_quadrant)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *arg_u = obj_u;
    PyObject *arg_o = obj_o;
    PyObject *arg_center = obj_center;
    PyObject *arg_radius = obj_radius;
    PyObject *arg_quadrant;
    if (obj_quadrant == NULL) {
        arg_quadrant = NULL;
    } else {
        arg_quadrant = obj_quadrant; 
    }
    PyObject *retval = CPyDef_Simulation___distance_circle(arg_self, arg_u, arg_o, arg_center, arg_radius, arg_quadrant);
    return retval;
fail: ;
    CPy_AddTraceback("modTof.py", "distance_circle", 130, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Simulation___distance_plane(PyObject *cpy_r_self, PyObject *cpy_r_u, PyObject *cpy_r_o, PyObject *cpy_r_plane, PyObject *cpy_r_dim) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    int32_t cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    int32_t cpy_r_r8;
    char cpy_r_r9;
    char cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_d_plane;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject **cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    cpy_r_r0 = CPyStatics[257]; /* 2 */
    cpy_r_r1 = PyObject_RichCompare(cpy_r_dim, cpy_r_r0, 2);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_plane", 149, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r2 = PyObject_IsTrue(cpy_r_r1);
    CPy_DECREF(cpy_r_r1);
    cpy_r_r3 = cpy_r_r2 >= 0;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("modTof.py", "distance_plane", 149, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r4 = cpy_r_r2;
    if (!cpy_r_r4) goto CPyL12;
    cpy_r_r5 = PyObject_GetItem(cpy_r_u, cpy_r_dim);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_plane", 150, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r6 = CPyStatics[244]; /* 0 */
    cpy_r_r7 = PyObject_RichCompare(cpy_r_r5, cpy_r_r6, 0);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_plane", 150, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r8 = PyObject_IsTrue(cpy_r_r7);
    CPy_DECREF(cpy_r_r7);
    cpy_r_r9 = cpy_r_r8 >= 0;
    if (unlikely(!cpy_r_r9)) {
        CPy_AddTraceback("modTof.py", "distance_plane", 150, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r10 = cpy_r_r8;
    if (!cpy_r_r10) goto CPyL9;
    cpy_r_r11 = CPyStatics[244]; /* 0 */
    cpy_r_r12 = PyObject_GetItem(cpy_r_plane, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_plane", 150, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r13 = cpy_r_r12;
    goto CPyL11;
CPyL9: ;
    cpy_r_r14 = CPyStatics[247]; /* 1 */
    cpy_r_r15 = PyObject_GetItem(cpy_r_plane, cpy_r_r14);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_plane", 150, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r13 = cpy_r_r15;
CPyL11: ;
    cpy_r_d_plane = cpy_r_r13;
    goto CPyL13;
CPyL12: ;
    CPy_INCREF(cpy_r_plane);
    cpy_r_d_plane = cpy_r_plane;
CPyL13: ;
    cpy_r_r16 = PyObject_GetItem(cpy_r_o, cpy_r_dim);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_plane", 153, CPyStatic_globals);
        goto CPyL21;
    }
    cpy_r_r17 = PyNumber_Subtract(cpy_r_d_plane, cpy_r_r16);
    CPy_DECREF(cpy_r_d_plane);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_plane", 153, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r18 = PyObject_GetItem(cpy_r_u, cpy_r_dim);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_plane", 153, CPyStatic_globals);
        goto CPyL22;
    }
    cpy_r_r19 = PyNumber_TrueDivide(cpy_r_r17, cpy_r_r18);
    CPy_DECREF(cpy_r_r17);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_plane", 153, CPyStatic_globals);
        goto CPyL20;
    }
    cpy_r_r20 = CPyModule_numpy;
    cpy_r_r21 = CPyStatics[24]; /* 'abs' */
    cpy_r_r22 = CPyObject_GetAttr(cpy_r_r20, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_plane", 153, CPyStatic_globals);
        goto CPyL23;
    }
    PyObject *cpy_r_r23[1] = {cpy_r_r19};
    cpy_r_r24 = (PyObject **)&cpy_r_r23;
    cpy_r_r25 = _PyObject_Vectorcall(cpy_r_r22, cpy_r_r24, 1, 0);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_plane", 153, CPyStatic_globals);
        goto CPyL23;
    }
    CPy_DECREF(cpy_r_r19);
    return cpy_r_r25;
CPyL20: ;
    cpy_r_r26 = NULL;
    return cpy_r_r26;
CPyL21: ;
    CPy_DecRef(cpy_r_d_plane);
    goto CPyL20;
CPyL22: ;
    CPy_DecRef(cpy_r_r17);
    goto CPyL20;
CPyL23: ;
    CPy_DecRef(cpy_r_r19);
    goto CPyL20;
}

PyObject *CPyPy_Simulation___distance_plane(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"u", "o", "plane", "dim", 0};
    static CPyArg_Parser parser = {"OOOO:distance_plane", kwlist, 0};
    PyObject *obj_u;
    PyObject *obj_o;
    PyObject *obj_plane;
    PyObject *obj_dim;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_u, &obj_o, &obj_plane, &obj_dim)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *arg_u = obj_u;
    PyObject *arg_o = obj_o;
    PyObject *arg_plane = obj_plane;
    PyObject *arg_dim = obj_dim;
    PyObject *retval = CPyDef_Simulation___distance_plane(arg_self, arg_u, arg_o, arg_plane, arg_dim);
    return retval;
fail: ;
    CPy_AddTraceback("modTof.py", "distance_plane", 148, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Simulation___distance_solver(PyObject *cpy_r_self, PyObject *cpy_r_u, PyObject *cpy_r_o, PyObject *cpy_r_center, PyObject *cpy_r_radius, PyObject *cpy_r_plane_z, PyObject *cpy_r_corner_center, PyObject *cpy_r_corner_radius, PyObject *cpy_r_pmt_center, PyObject *cpy_r_pmt_radius) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_dcircle;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_dplane_z;
    PyObject *cpy_r_r4;
    int32_t cpy_r_r5;
    char cpy_r_r6;
    char cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_dist;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_temp_o;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_PMT_cond;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
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
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    int32_t cpy_r_r41;
    char cpy_r_r42;
    char cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_dplanex;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_dplaney;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_dplanez;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_dcorner;
    PyObject *cpy_r_r53;
    CPyPtr cpy_r_r54;
    CPyPtr cpy_r_r55;
    CPyPtr cpy_r_r56;
    CPyPtr cpy_r_r57;
    CPyPtr cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject **cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_light_guide_dist;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    int32_t cpy_r_r93;
    char cpy_r_r94;
    char cpy_r_r95;
    PyObject *cpy_r_r96;
    tuple_T2OO cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    int32_t cpy_r_r128;
    char cpy_r_r129;
    char cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_r137;
    PyObject *cpy_r_r138;
    PyObject *cpy_r_r139;
    PyObject *cpy_r_r140;
    CPyPtr cpy_r_r141;
    CPyPtr cpy_r_r142;
    CPyPtr cpy_r_r143;
    CPyPtr cpy_r_r144;
    CPyPtr cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject **cpy_r_r150;
    PyObject *cpy_r_r151;
    PyObject *cpy_r_r152;
    PyObject *cpy_r_r153;
    PyObject *cpy_r_r154;
    PyObject *cpy_r_r155;
    PyObject *cpy_r_r156;
    PyObject *cpy_r_r157;
    PyObject *cpy_r_r158;
    PyObject *cpy_r_r159;
    PyObject *cpy_r_r160;
    PyObject *cpy_r_r161;
    PyObject *cpy_r_r162;
    PyObject *cpy_r_r163;
    PyObject *cpy_r_r164;
    PyObject *cpy_r_r165;
    PyObject *cpy_r_r166;
    PyObject *cpy_r_r167;
    PyObject *cpy_r_r168;
    PyObject *cpy_r_r169;
    PyObject *cpy_r_r170;
    PyObject *cpy_r_r171;
    PyObject *cpy_r_r172;
    PyObject *cpy_r_r173;
    PyObject *cpy_r_r174;
    PyObject *cpy_r_r175;
    PyObject *cpy_r_r176;
    PyObject *cpy_r_r177;
    PyObject *cpy_r_r178;
    PyObject *cpy_r_r179;
    int32_t cpy_r_r180;
    char cpy_r_r181;
    char cpy_r_r182;
    PyObject *cpy_r_r183;
    tuple_T2OO cpy_r_r184;
    PyObject *cpy_r_r185;
    tuple_T2OO cpy_r_r186;
    PyObject *cpy_r_r187;
    PyObject *cpy_r_r188;
    cpy_r_r0 = NULL;
    cpy_r_r1 = CPyDef_Simulation___distance_circle(cpy_r_self, cpy_r_u, cpy_r_o, cpy_r_center, cpy_r_radius, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 158, CPyStatic_globals);
        goto CPyL108;
    }
    cpy_r_dcircle = cpy_r_r1;
    cpy_r_r2 = CPyStatics[257]; /* 2 */
    cpy_r_r3 = CPyDef_Simulation___distance_plane(cpy_r_self, cpy_r_u, cpy_r_o, cpy_r_plane_z, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 159, CPyStatic_globals);
        goto CPyL109;
    }
    cpy_r_dplane_z = cpy_r_r3;
    cpy_r_r4 = PyObject_RichCompare(cpy_r_dcircle, cpy_r_dplane_z, 4);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 160, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r5 = PyObject_IsTrue(cpy_r_r4);
    CPy_DECREF(cpy_r_r4);
    cpy_r_r6 = cpy_r_r5 >= 0;
    if (unlikely(!cpy_r_r6)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 160, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r7 = cpy_r_r5;
    if (cpy_r_r7) {
        goto CPyL111;
    } else
        goto CPyL112;
CPyL5: ;
    cpy_r_r8 = cpy_r_dplane_z;
    goto CPyL7;
CPyL6: ;
    cpy_r_r8 = cpy_r_dcircle;
CPyL7: ;
    cpy_r_dist = cpy_r_r8;
    cpy_r_r9 = PyNumber_Multiply(cpy_r_dist, cpy_r_u);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 161, CPyStatic_globals);
        goto CPyL113;
    }
    cpy_r_r10 = PyNumber_Add(cpy_r_o, cpy_r_r9);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 161, CPyStatic_globals);
        goto CPyL113;
    }
    cpy_r_temp_o = cpy_r_r10;
    cpy_r_r11 = 0 ? Py_True : Py_False;
    CPy_INCREF(cpy_r_r11);
    cpy_r_PMT_cond = cpy_r_r11;
    cpy_r_r12 = CPyStatics[244]; /* 0 */
    cpy_r_r13 = PyObject_GetItem(cpy_r_pmt_center, cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 163, CPyStatic_globals);
        goto CPyL114;
    }
    cpy_r_r14 = CPyStatics[244]; /* 0 */
    cpy_r_r15 = PyObject_RichCompare(cpy_r_r13, cpy_r_r14, 4);
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 163, CPyStatic_globals);
        goto CPyL114;
    }
    cpy_r_r16 = CPyStatics[244]; /* 0 */
    cpy_r_r17 = PyObject_GetItem(cpy_r_temp_o, cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 163, CPyStatic_globals);
        goto CPyL115;
    }
    cpy_r_r18 = CPyStatics[244]; /* 0 */
    cpy_r_r19 = PyObject_RichCompare(cpy_r_r17, cpy_r_r18, 4);
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 163, CPyStatic_globals);
        goto CPyL115;
    }
    cpy_r_r20 = PyNumber_And(cpy_r_r15, cpy_r_r19);
    CPy_DECREF(cpy_r_r15);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 163, CPyStatic_globals);
        goto CPyL114;
    }
    cpy_r_r21 = CPyStatics[247]; /* 1 */
    cpy_r_r22 = PyObject_GetItem(cpy_r_temp_o, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 163, CPyStatic_globals);
        goto CPyL116;
    }
    cpy_r_r23 = CPyStatics[244]; /* 0 */
    cpy_r_r24 = PyObject_RichCompare(cpy_r_r22, cpy_r_r23, 0);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 163, CPyStatic_globals);
        goto CPyL116;
    }
    cpy_r_r25 = PyNumber_And(cpy_r_r20, cpy_r_r24);
    CPy_DECREF(cpy_r_r20);
    CPy_DECREF(cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 163, CPyStatic_globals);
        goto CPyL114;
    }
    cpy_r_r26 = CPyStatics[244]; /* 0 */
    cpy_r_r27 = PyObject_GetItem(cpy_r_temp_o, cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 163, CPyStatic_globals);
        goto CPyL117;
    }
    cpy_r_r28 = CPyStatics[257]; /* 2 */
    cpy_r_r29 = CPyNumber_Power(cpy_r_r27, cpy_r_r28);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 163, CPyStatic_globals);
        goto CPyL117;
    }
    cpy_r_r30 = CPyStatics[247]; /* 1 */
    cpy_r_r31 = PyObject_GetItem(cpy_r_temp_o, cpy_r_r30);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 163, CPyStatic_globals);
        goto CPyL118;
    }
    cpy_r_r32 = CPyStatics[257]; /* 2 */
    cpy_r_r33 = CPyNumber_Power(cpy_r_r31, cpy_r_r32);
    CPy_DECREF(cpy_r_r31);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 163, CPyStatic_globals);
        goto CPyL118;
    }
    cpy_r_r34 = PyNumber_Add(cpy_r_r29, cpy_r_r33);
    CPy_DECREF(cpy_r_r29);
    CPy_DECREF(cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 163, CPyStatic_globals);
        goto CPyL117;
    }
    cpy_r_r35 = CPyStatics[257]; /* 2 */
    cpy_r_r36 = CPyNumber_Power(cpy_r_radius, cpy_r_r35);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 163, CPyStatic_globals);
        goto CPyL119;
    }
    cpy_r_r37 = CPyStatics[247]; /* 1 */
    cpy_r_r38 = PyNumber_Subtract(cpy_r_r36, cpy_r_r37);
    CPy_DECREF(cpy_r_r36);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 163, CPyStatic_globals);
        goto CPyL119;
    }
    cpy_r_r39 = PyObject_RichCompare(cpy_r_r34, cpy_r_r38, 5);
    CPy_DECREF(cpy_r_r34);
    CPy_DECREF(cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 163, CPyStatic_globals);
        goto CPyL117;
    }
    cpy_r_r40 = PyNumber_And(cpy_r_r25, cpy_r_r39);
    CPy_DECREF(cpy_r_r25);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 163, CPyStatic_globals);
        goto CPyL114;
    }
    cpy_r_r41 = PyObject_IsTrue(cpy_r_r40);
    CPy_DECREF(cpy_r_r40);
    cpy_r_r42 = cpy_r_r41 >= 0;
    if (unlikely(!cpy_r_r42)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 163, CPyStatic_globals);
        goto CPyL114;
    }
    cpy_r_r43 = cpy_r_r41;
    if (cpy_r_r43) {
        goto CPyL120;
    } else
        goto CPyL58;
CPyL28: ;
    cpy_r_r44 = CPyStatics[244]; /* 0 */
    cpy_r_r45 = CPyDef_Simulation___distance_plane(cpy_r_self, cpy_r_u, cpy_r_o, cpy_r_radius, cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 164, CPyStatic_globals);
        goto CPyL121;
    }
    cpy_r_dplanex = cpy_r_r45;
    cpy_r_r46 = PyNumber_Negative(cpy_r_radius);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 165, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r47 = CPyStatics[247]; /* 1 */
    cpy_r_r48 = CPyDef_Simulation___distance_plane(cpy_r_self, cpy_r_u, cpy_r_o, cpy_r_r46, cpy_r_r47);
    CPy_DECREF(cpy_r_r46);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 165, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_dplaney = cpy_r_r48;
    cpy_r_r49 = CPyStatics[257]; /* 2 */
    cpy_r_r50 = CPyDef_Simulation___distance_plane(cpy_r_self, cpy_r_u, cpy_r_o, cpy_r_plane_z, cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 166, CPyStatic_globals);
        goto CPyL123;
    }
    cpy_r_dplanez = cpy_r_r50;
    cpy_r_r51 = 1 ? Py_True : Py_False;
    cpy_r_r52 = CPyDef_Simulation___distance_circle(cpy_r_self, cpy_r_u, cpy_r_o, cpy_r_corner_center, cpy_r_corner_radius, cpy_r_r51);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 167, CPyStatic_globals);
        goto CPyL124;
    }
    cpy_r_dcorner = cpy_r_r52;
    cpy_r_r53 = PyList_New(4);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 168, CPyStatic_globals);
        goto CPyL125;
    }
    cpy_r_r54 = (CPyPtr)&((PyListObject *)cpy_r_r53)->ob_item;
    cpy_r_r55 = *(CPyPtr *)cpy_r_r54;
    *(PyObject * *)cpy_r_r55 = cpy_r_dplanex;
    cpy_r_r56 = cpy_r_r55 + 8;
    *(PyObject * *)cpy_r_r56 = cpy_r_dplaney;
    cpy_r_r57 = cpy_r_r55 + 16;
    *(PyObject * *)cpy_r_r57 = cpy_r_dplanez;
    cpy_r_r58 = cpy_r_r55 + 24;
    *(PyObject * *)cpy_r_r58 = cpy_r_dcorner;
    cpy_r_r59 = CPyModule_numpy;
    cpy_r_r60 = CPyStatics[33]; /* 'min' */
    cpy_r_r61 = CPyObject_GetAttr(cpy_r_r59, cpy_r_r60);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 168, CPyStatic_globals);
        goto CPyL126;
    }
    PyObject *cpy_r_r62[1] = {cpy_r_r53};
    cpy_r_r63 = (PyObject **)&cpy_r_r62;
    cpy_r_r64 = _PyObject_Vectorcall(cpy_r_r61, cpy_r_r63, 1, 0);
    CPy_DECREF(cpy_r_r61);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 168, CPyStatic_globals);
        goto CPyL126;
    }
    CPy_DECREF(cpy_r_r53);
    cpy_r_light_guide_dist = cpy_r_r64;
    cpy_r_r65 = PyNumber_Multiply(cpy_r_light_guide_dist, cpy_r_u);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 169, CPyStatic_globals);
        goto CPyL127;
    }
    cpy_r_r66 = PyNumber_Add(cpy_r_o, cpy_r_r65);
    CPy_DECREF(cpy_r_r65);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 169, CPyStatic_globals);
        goto CPyL127;
    }
    cpy_r_temp_o = cpy_r_r66;
    cpy_r_r67 = CPyStatics[257]; /* 2 */
    cpy_r_r68 = PyObject_GetItem(cpy_r_temp_o, cpy_r_r67);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 171, CPyStatic_globals);
        goto CPyL128;
    }
    cpy_r_r69 = CPyStatics[244]; /* 0 */
    cpy_r_r70 = PyObject_GetItem(cpy_r_plane_z, cpy_r_r69);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 171, CPyStatic_globals);
        goto CPyL129;
    }
    cpy_r_r71 = PyFloat_FromDouble(0.01);
    cpy_r_r72 = PyNumber_Add(cpy_r_r70, cpy_r_r71);
    CPy_DECREF(cpy_r_r70);
    CPy_DECREF(cpy_r_r71);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 171, CPyStatic_globals);
        goto CPyL129;
    }
    cpy_r_r73 = PyObject_RichCompare(cpy_r_r68, cpy_r_r72, 0);
    CPy_DECREF(cpy_r_r68);
    CPy_DECREF(cpy_r_r72);
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 171, CPyStatic_globals);
        goto CPyL128;
    }
    cpy_r_r74 = CPyStatics[244]; /* 0 */
    cpy_r_r75 = PyObject_GetItem(cpy_r_temp_o, cpy_r_r74);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 171, CPyStatic_globals);
        goto CPyL130;
    }
    cpy_r_r76 = CPyStatics[244]; /* 0 */
    cpy_r_r77 = PyObject_GetItem(cpy_r_pmt_center, cpy_r_r76);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 171, CPyStatic_globals);
        goto CPyL131;
    }
    cpy_r_r78 = PyNumber_Subtract(cpy_r_r75, cpy_r_r77);
    CPy_DECREF(cpy_r_r75);
    CPy_DECREF(cpy_r_r77);
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 171, CPyStatic_globals);
        goto CPyL130;
    }
    cpy_r_r79 = CPyStatics[257]; /* 2 */
    cpy_r_r80 = CPyNumber_Power(cpy_r_r78, cpy_r_r79);
    CPy_DECREF(cpy_r_r78);
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 171, CPyStatic_globals);
        goto CPyL130;
    }
    cpy_r_r81 = CPyStatics[247]; /* 1 */
    cpy_r_r82 = PyObject_GetItem(cpy_r_temp_o, cpy_r_r81);
    CPy_DECREF(cpy_r_temp_o);
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 171, CPyStatic_globals);
        goto CPyL132;
    }
    cpy_r_r83 = CPyStatics[247]; /* 1 */
    cpy_r_r84 = PyObject_GetItem(cpy_r_pmt_center, cpy_r_r83);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 171, CPyStatic_globals);
        goto CPyL133;
    }
    cpy_r_r85 = PyNumber_Subtract(cpy_r_r82, cpy_r_r84);
    CPy_DECREF(cpy_r_r82);
    CPy_DECREF(cpy_r_r84);
    if (unlikely(cpy_r_r85 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 171, CPyStatic_globals);
        goto CPyL132;
    }
    cpy_r_r86 = CPyStatics[257]; /* 2 */
    cpy_r_r87 = CPyNumber_Power(cpy_r_r85, cpy_r_r86);
    CPy_DECREF(cpy_r_r85);
    if (unlikely(cpy_r_r87 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 171, CPyStatic_globals);
        goto CPyL132;
    }
    cpy_r_r88 = PyNumber_Add(cpy_r_r80, cpy_r_r87);
    CPy_DECREF(cpy_r_r80);
    CPy_DECREF(cpy_r_r87);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 171, CPyStatic_globals);
        goto CPyL134;
    }
    cpy_r_r89 = CPyStatics[257]; /* 2 */
    cpy_r_r90 = CPyNumber_Power(cpy_r_pmt_radius, cpy_r_r89);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 171, CPyStatic_globals);
        goto CPyL135;
    }
    cpy_r_r91 = PyObject_RichCompare(cpy_r_r88, cpy_r_r90, 1);
    CPy_DECREF(cpy_r_r88);
    CPy_DECREF(cpy_r_r90);
    if (unlikely(cpy_r_r91 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 171, CPyStatic_globals);
        goto CPyL134;
    }
    cpy_r_r92 = PyNumber_And(cpy_r_r73, cpy_r_r91);
    CPy_DECREF(cpy_r_r73);
    CPy_DECREF(cpy_r_r91);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 171, CPyStatic_globals);
        goto CPyL127;
    }
    cpy_r_r93 = PyObject_IsTrue(cpy_r_r92);
    CPy_DECREF(cpy_r_r92);
    cpy_r_r94 = cpy_r_r93 >= 0;
    if (unlikely(!cpy_r_r94)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 171, CPyStatic_globals);
        goto CPyL127;
    }
    cpy_r_r95 = cpy_r_r93;
    if (cpy_r_r95) {
        goto CPyL136;
    } else
        goto CPyL57;
CPyL56: ;
    cpy_r_r96 = 1 ? Py_True : Py_False;
    CPy_INCREF(cpy_r_r96);
    cpy_r_PMT_cond = cpy_r_r96;
CPyL57: ;
    cpy_r_r97.f0 = cpy_r_light_guide_dist;
    cpy_r_r97.f1 = cpy_r_PMT_cond;
    CPy_INCREF(cpy_r_r97.f0);
    CPy_INCREF(cpy_r_r97.f1);
    CPy_DECREF(cpy_r_light_guide_dist);
    CPy_DECREF(cpy_r_PMT_cond);
    cpy_r_r98 = PyTuple_New(2);
    if (unlikely(cpy_r_r98 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp1 = cpy_r_r97.f0;
    PyTuple_SET_ITEM(cpy_r_r98, 0, __tmp1);
    PyObject *__tmp2 = cpy_r_r97.f1;
    PyTuple_SET_ITEM(cpy_r_r98, 1, __tmp2);
    return cpy_r_r98;
CPyL58: ;
    cpy_r_r99 = CPyStatics[244]; /* 0 */
    cpy_r_r100 = PyObject_GetItem(cpy_r_pmt_center, cpy_r_r99);
    if (unlikely(cpy_r_r100 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 174, CPyStatic_globals);
        goto CPyL114;
    }
    cpy_r_r101 = CPyStatics[244]; /* 0 */
    cpy_r_r102 = PyObject_RichCompare(cpy_r_r100, cpy_r_r101, 0);
    CPy_DECREF(cpy_r_r100);
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 174, CPyStatic_globals);
        goto CPyL114;
    }
    cpy_r_r103 = CPyStatics[244]; /* 0 */
    cpy_r_r104 = PyObject_GetItem(cpy_r_temp_o, cpy_r_r103);
    if (unlikely(cpy_r_r104 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 174, CPyStatic_globals);
        goto CPyL137;
    }
    cpy_r_r105 = CPyStatics[244]; /* 0 */
    cpy_r_r106 = PyObject_RichCompare(cpy_r_r104, cpy_r_r105, 0);
    CPy_DECREF(cpy_r_r104);
    if (unlikely(cpy_r_r106 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 174, CPyStatic_globals);
        goto CPyL137;
    }
    cpy_r_r107 = PyNumber_And(cpy_r_r102, cpy_r_r106);
    CPy_DECREF(cpy_r_r102);
    CPy_DECREF(cpy_r_r106);
    if (unlikely(cpy_r_r107 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 174, CPyStatic_globals);
        goto CPyL114;
    }
    cpy_r_r108 = CPyStatics[247]; /* 1 */
    cpy_r_r109 = PyObject_GetItem(cpy_r_temp_o, cpy_r_r108);
    if (unlikely(cpy_r_r109 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 174, CPyStatic_globals);
        goto CPyL138;
    }
    cpy_r_r110 = CPyStatics[244]; /* 0 */
    cpy_r_r111 = PyObject_RichCompare(cpy_r_r109, cpy_r_r110, 4);
    CPy_DECREF(cpy_r_r109);
    if (unlikely(cpy_r_r111 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 174, CPyStatic_globals);
        goto CPyL138;
    }
    cpy_r_r112 = PyNumber_And(cpy_r_r107, cpy_r_r111);
    CPy_DECREF(cpy_r_r107);
    CPy_DECREF(cpy_r_r111);
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 174, CPyStatic_globals);
        goto CPyL114;
    }
    cpy_r_r113 = CPyStatics[244]; /* 0 */
    cpy_r_r114 = PyObject_GetItem(cpy_r_temp_o, cpy_r_r113);
    if (unlikely(cpy_r_r114 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 174, CPyStatic_globals);
        goto CPyL139;
    }
    cpy_r_r115 = CPyStatics[257]; /* 2 */
    cpy_r_r116 = CPyNumber_Power(cpy_r_r114, cpy_r_r115);
    CPy_DECREF(cpy_r_r114);
    if (unlikely(cpy_r_r116 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 174, CPyStatic_globals);
        goto CPyL139;
    }
    cpy_r_r117 = CPyStatics[247]; /* 1 */
    cpy_r_r118 = PyObject_GetItem(cpy_r_temp_o, cpy_r_r117);
    CPy_DECREF(cpy_r_temp_o);
    if (unlikely(cpy_r_r118 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 174, CPyStatic_globals);
        goto CPyL140;
    }
    cpy_r_r119 = CPyStatics[257]; /* 2 */
    cpy_r_r120 = CPyNumber_Power(cpy_r_r118, cpy_r_r119);
    CPy_DECREF(cpy_r_r118);
    if (unlikely(cpy_r_r120 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 174, CPyStatic_globals);
        goto CPyL140;
    }
    cpy_r_r121 = PyNumber_Add(cpy_r_r116, cpy_r_r120);
    CPy_DECREF(cpy_r_r116);
    CPy_DECREF(cpy_r_r120);
    if (unlikely(cpy_r_r121 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 174, CPyStatic_globals);
        goto CPyL141;
    }
    cpy_r_r122 = CPyStatics[257]; /* 2 */
    cpy_r_r123 = CPyNumber_Power(cpy_r_radius, cpy_r_r122);
    if (unlikely(cpy_r_r123 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 174, CPyStatic_globals);
        goto CPyL142;
    }
    cpy_r_r124 = CPyStatics[247]; /* 1 */
    cpy_r_r125 = PyNumber_Subtract(cpy_r_r123, cpy_r_r124);
    CPy_DECREF(cpy_r_r123);
    if (unlikely(cpy_r_r125 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 174, CPyStatic_globals);
        goto CPyL142;
    }
    cpy_r_r126 = PyObject_RichCompare(cpy_r_r121, cpy_r_r125, 5);
    CPy_DECREF(cpy_r_r121);
    CPy_DECREF(cpy_r_r125);
    if (unlikely(cpy_r_r126 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 174, CPyStatic_globals);
        goto CPyL141;
    }
    cpy_r_r127 = PyNumber_And(cpy_r_r112, cpy_r_r126);
    CPy_DECREF(cpy_r_r112);
    CPy_DECREF(cpy_r_r126);
    if (unlikely(cpy_r_r127 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 174, CPyStatic_globals);
        goto CPyL143;
    }
    cpy_r_r128 = PyObject_IsTrue(cpy_r_r127);
    CPy_DECREF(cpy_r_r127);
    cpy_r_r129 = cpy_r_r128 >= 0;
    if (unlikely(!cpy_r_r129)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 174, CPyStatic_globals);
        goto CPyL143;
    }
    cpy_r_r130 = cpy_r_r128;
    if (cpy_r_r130) {
        goto CPyL144;
    } else
        goto CPyL107;
CPyL77: ;
    cpy_r_r131 = PyNumber_Negative(cpy_r_radius);
    if (unlikely(cpy_r_r131 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 175, CPyStatic_globals);
        goto CPyL121;
    }
    cpy_r_r132 = CPyStatics[244]; /* 0 */
    cpy_r_r133 = CPyDef_Simulation___distance_plane(cpy_r_self, cpy_r_u, cpy_r_o, cpy_r_r131, cpy_r_r132);
    CPy_DECREF(cpy_r_r131);
    if (unlikely(cpy_r_r133 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 175, CPyStatic_globals);
        goto CPyL121;
    }
    cpy_r_dplanex = cpy_r_r133;
    cpy_r_r134 = CPyStatics[247]; /* 1 */
    cpy_r_r135 = CPyDef_Simulation___distance_plane(cpy_r_self, cpy_r_u, cpy_r_o, cpy_r_radius, cpy_r_r134);
    if (unlikely(cpy_r_r135 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 176, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_dplaney = cpy_r_r135;
    cpy_r_r136 = CPyStatics[257]; /* 2 */
    cpy_r_r137 = CPyDef_Simulation___distance_plane(cpy_r_self, cpy_r_u, cpy_r_o, cpy_r_plane_z, cpy_r_r136);
    if (unlikely(cpy_r_r137 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 177, CPyStatic_globals);
        goto CPyL123;
    }
    cpy_r_dplanez = cpy_r_r137;
    cpy_r_r138 = 1 ? Py_True : Py_False;
    cpy_r_r139 = CPyDef_Simulation___distance_circle(cpy_r_self, cpy_r_u, cpy_r_o, cpy_r_corner_center, cpy_r_corner_radius, cpy_r_r138);
    if (unlikely(cpy_r_r139 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 178, CPyStatic_globals);
        goto CPyL124;
    }
    cpy_r_dcorner = cpy_r_r139;
    cpy_r_r140 = PyList_New(4);
    if (unlikely(cpy_r_r140 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 179, CPyStatic_globals);
        goto CPyL125;
    }
    cpy_r_r141 = (CPyPtr)&((PyListObject *)cpy_r_r140)->ob_item;
    cpy_r_r142 = *(CPyPtr *)cpy_r_r141;
    *(PyObject * *)cpy_r_r142 = cpy_r_dplanex;
    cpy_r_r143 = cpy_r_r142 + 8;
    *(PyObject * *)cpy_r_r143 = cpy_r_dplaney;
    cpy_r_r144 = cpy_r_r142 + 16;
    *(PyObject * *)cpy_r_r144 = cpy_r_dplanez;
    cpy_r_r145 = cpy_r_r142 + 24;
    *(PyObject * *)cpy_r_r145 = cpy_r_dcorner;
    cpy_r_r146 = CPyModule_numpy;
    cpy_r_r147 = CPyStatics[33]; /* 'min' */
    cpy_r_r148 = CPyObject_GetAttr(cpy_r_r146, cpy_r_r147);
    if (unlikely(cpy_r_r148 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 179, CPyStatic_globals);
        goto CPyL145;
    }
    PyObject *cpy_r_r149[1] = {cpy_r_r140};
    cpy_r_r150 = (PyObject **)&cpy_r_r149;
    cpy_r_r151 = _PyObject_Vectorcall(cpy_r_r148, cpy_r_r150, 1, 0);
    CPy_DECREF(cpy_r_r148);
    if (unlikely(cpy_r_r151 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 179, CPyStatic_globals);
        goto CPyL145;
    }
    CPy_DECREF(cpy_r_r140);
    cpy_r_light_guide_dist = cpy_r_r151;
    cpy_r_r152 = PyNumber_Multiply(cpy_r_light_guide_dist, cpy_r_u);
    if (unlikely(cpy_r_r152 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 180, CPyStatic_globals);
        goto CPyL127;
    }
    cpy_r_r153 = PyNumber_Add(cpy_r_o, cpy_r_r152);
    CPy_DECREF(cpy_r_r152);
    if (unlikely(cpy_r_r153 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 180, CPyStatic_globals);
        goto CPyL127;
    }
    cpy_r_temp_o = cpy_r_r153;
    cpy_r_r154 = CPyStatics[257]; /* 2 */
    cpy_r_r155 = PyObject_GetItem(cpy_r_temp_o, cpy_r_r154);
    if (unlikely(cpy_r_r155 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 182, CPyStatic_globals);
        goto CPyL128;
    }
    cpy_r_r156 = CPyStatics[244]; /* 0 */
    cpy_r_r157 = PyObject_GetItem(cpy_r_plane_z, cpy_r_r156);
    if (unlikely(cpy_r_r157 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 182, CPyStatic_globals);
        goto CPyL146;
    }
    cpy_r_r158 = PyFloat_FromDouble(0.01);
    cpy_r_r159 = PyNumber_Add(cpy_r_r157, cpy_r_r158);
    CPy_DECREF(cpy_r_r157);
    CPy_DECREF(cpy_r_r158);
    if (unlikely(cpy_r_r159 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 182, CPyStatic_globals);
        goto CPyL146;
    }
    cpy_r_r160 = PyObject_RichCompare(cpy_r_r155, cpy_r_r159, 0);
    CPy_DECREF(cpy_r_r155);
    CPy_DECREF(cpy_r_r159);
    if (unlikely(cpy_r_r160 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 182, CPyStatic_globals);
        goto CPyL128;
    }
    cpy_r_r161 = CPyStatics[244]; /* 0 */
    cpy_r_r162 = PyObject_GetItem(cpy_r_temp_o, cpy_r_r161);
    if (unlikely(cpy_r_r162 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 182, CPyStatic_globals);
        goto CPyL147;
    }
    cpy_r_r163 = CPyStatics[244]; /* 0 */
    cpy_r_r164 = PyObject_GetItem(cpy_r_pmt_center, cpy_r_r163);
    if (unlikely(cpy_r_r164 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 182, CPyStatic_globals);
        goto CPyL148;
    }
    cpy_r_r165 = PyNumber_Subtract(cpy_r_r162, cpy_r_r164);
    CPy_DECREF(cpy_r_r162);
    CPy_DECREF(cpy_r_r164);
    if (unlikely(cpy_r_r165 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 182, CPyStatic_globals);
        goto CPyL147;
    }
    cpy_r_r166 = CPyStatics[257]; /* 2 */
    cpy_r_r167 = CPyNumber_Power(cpy_r_r165, cpy_r_r166);
    CPy_DECREF(cpy_r_r165);
    if (unlikely(cpy_r_r167 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 182, CPyStatic_globals);
        goto CPyL147;
    }
    cpy_r_r168 = CPyStatics[247]; /* 1 */
    cpy_r_r169 = PyObject_GetItem(cpy_r_temp_o, cpy_r_r168);
    CPy_DECREF(cpy_r_temp_o);
    if (unlikely(cpy_r_r169 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 182, CPyStatic_globals);
        goto CPyL149;
    }
    cpy_r_r170 = CPyStatics[247]; /* 1 */
    cpy_r_r171 = PyObject_GetItem(cpy_r_pmt_center, cpy_r_r170);
    if (unlikely(cpy_r_r171 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 182, CPyStatic_globals);
        goto CPyL150;
    }
    cpy_r_r172 = PyNumber_Subtract(cpy_r_r169, cpy_r_r171);
    CPy_DECREF(cpy_r_r169);
    CPy_DECREF(cpy_r_r171);
    if (unlikely(cpy_r_r172 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 182, CPyStatic_globals);
        goto CPyL149;
    }
    cpy_r_r173 = CPyStatics[257]; /* 2 */
    cpy_r_r174 = CPyNumber_Power(cpy_r_r172, cpy_r_r173);
    CPy_DECREF(cpy_r_r172);
    if (unlikely(cpy_r_r174 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 182, CPyStatic_globals);
        goto CPyL149;
    }
    cpy_r_r175 = PyNumber_Add(cpy_r_r167, cpy_r_r174);
    CPy_DECREF(cpy_r_r167);
    CPy_DECREF(cpy_r_r174);
    if (unlikely(cpy_r_r175 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 182, CPyStatic_globals);
        goto CPyL151;
    }
    cpy_r_r176 = CPyStatics[257]; /* 2 */
    cpy_r_r177 = CPyNumber_Power(cpy_r_pmt_radius, cpy_r_r176);
    if (unlikely(cpy_r_r177 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 182, CPyStatic_globals);
        goto CPyL152;
    }
    cpy_r_r178 = PyObject_RichCompare(cpy_r_r175, cpy_r_r177, 1);
    CPy_DECREF(cpy_r_r175);
    CPy_DECREF(cpy_r_r177);
    if (unlikely(cpy_r_r178 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 182, CPyStatic_globals);
        goto CPyL151;
    }
    cpy_r_r179 = PyNumber_And(cpy_r_r160, cpy_r_r178);
    CPy_DECREF(cpy_r_r160);
    CPy_DECREF(cpy_r_r178);
    if (unlikely(cpy_r_r179 == NULL)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 182, CPyStatic_globals);
        goto CPyL127;
    }
    cpy_r_r180 = PyObject_IsTrue(cpy_r_r179);
    CPy_DECREF(cpy_r_r179);
    cpy_r_r181 = cpy_r_r180 >= 0;
    if (unlikely(!cpy_r_r181)) {
        CPy_AddTraceback("modTof.py", "distance_solver", 182, CPyStatic_globals);
        goto CPyL127;
    }
    cpy_r_r182 = cpy_r_r180;
    if (cpy_r_r182) {
        goto CPyL153;
    } else
        goto CPyL106;
CPyL105: ;
    cpy_r_r183 = 1 ? Py_True : Py_False;
    CPy_INCREF(cpy_r_r183);
    cpy_r_PMT_cond = cpy_r_r183;
CPyL106: ;
    cpy_r_r184.f0 = cpy_r_light_guide_dist;
    cpy_r_r184.f1 = cpy_r_PMT_cond;
    CPy_INCREF(cpy_r_r184.f0);
    CPy_INCREF(cpy_r_r184.f1);
    CPy_DECREF(cpy_r_light_guide_dist);
    CPy_DECREF(cpy_r_PMT_cond);
    cpy_r_r185 = PyTuple_New(2);
    if (unlikely(cpy_r_r185 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp3 = cpy_r_r184.f0;
    PyTuple_SET_ITEM(cpy_r_r185, 0, __tmp3);
    PyObject *__tmp4 = cpy_r_r184.f1;
    PyTuple_SET_ITEM(cpy_r_r185, 1, __tmp4);
    return cpy_r_r185;
CPyL107: ;
    cpy_r_r186.f0 = cpy_r_dist;
    cpy_r_r186.f1 = cpy_r_PMT_cond;
    CPy_INCREF(cpy_r_r186.f0);
    CPy_INCREF(cpy_r_r186.f1);
    CPy_DECREF(cpy_r_dist);
    CPy_DECREF(cpy_r_PMT_cond);
    cpy_r_r187 = PyTuple_New(2);
    if (unlikely(cpy_r_r187 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp5 = cpy_r_r186.f0;
    PyTuple_SET_ITEM(cpy_r_r187, 0, __tmp5);
    PyObject *__tmp6 = cpy_r_r186.f1;
    PyTuple_SET_ITEM(cpy_r_r187, 1, __tmp6);
    return cpy_r_r187;
CPyL108: ;
    cpy_r_r188 = NULL;
    return cpy_r_r188;
CPyL109: ;
    CPy_DecRef(cpy_r_dcircle);
    goto CPyL108;
CPyL110: ;
    CPy_DecRef(cpy_r_dcircle);
    CPy_DecRef(cpy_r_dplane_z);
    goto CPyL108;
CPyL111: ;
    CPy_DECREF(cpy_r_dcircle);
    goto CPyL5;
CPyL112: ;
    CPy_DECREF(cpy_r_dplane_z);
    goto CPyL6;
CPyL113: ;
    CPy_DecRef(cpy_r_dist);
    goto CPyL108;
CPyL114: ;
    CPy_DecRef(cpy_r_dist);
    CPy_DecRef(cpy_r_temp_o);
    CPy_DecRef(cpy_r_PMT_cond);
    goto CPyL108;
CPyL115: ;
    CPy_DecRef(cpy_r_dist);
    CPy_DecRef(cpy_r_temp_o);
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_r15);
    goto CPyL108;
CPyL116: ;
    CPy_DecRef(cpy_r_dist);
    CPy_DecRef(cpy_r_temp_o);
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_r20);
    goto CPyL108;
CPyL117: ;
    CPy_DecRef(cpy_r_dist);
    CPy_DecRef(cpy_r_temp_o);
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_r25);
    goto CPyL108;
CPyL118: ;
    CPy_DecRef(cpy_r_dist);
    CPy_DecRef(cpy_r_temp_o);
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r29);
    goto CPyL108;
CPyL119: ;
    CPy_DecRef(cpy_r_dist);
    CPy_DecRef(cpy_r_temp_o);
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_r25);
    CPy_DecRef(cpy_r_r34);
    goto CPyL108;
CPyL120: ;
    CPy_DECREF(cpy_r_dist);
    CPy_DECREF(cpy_r_temp_o);
    goto CPyL28;
CPyL121: ;
    CPy_DecRef(cpy_r_PMT_cond);
    goto CPyL108;
CPyL122: ;
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_dplanex);
    goto CPyL108;
CPyL123: ;
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_dplanex);
    CPy_DecRef(cpy_r_dplaney);
    goto CPyL108;
CPyL124: ;
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_dplanex);
    CPy_DecRef(cpy_r_dplaney);
    CPy_DecRef(cpy_r_dplanez);
    goto CPyL108;
CPyL125: ;
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_dplanex);
    CPy_DecRef(cpy_r_dplaney);
    CPy_DecRef(cpy_r_dplanez);
    CPy_DecRef(cpy_r_dcorner);
    goto CPyL108;
CPyL126: ;
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_r53);
    goto CPyL108;
CPyL127: ;
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_light_guide_dist);
    goto CPyL108;
CPyL128: ;
    CPy_DecRef(cpy_r_temp_o);
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_light_guide_dist);
    goto CPyL108;
CPyL129: ;
    CPy_DecRef(cpy_r_temp_o);
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_light_guide_dist);
    CPy_DecRef(cpy_r_r68);
    goto CPyL108;
CPyL130: ;
    CPy_DecRef(cpy_r_temp_o);
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_light_guide_dist);
    CPy_DecRef(cpy_r_r73);
    goto CPyL108;
CPyL131: ;
    CPy_DecRef(cpy_r_temp_o);
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_light_guide_dist);
    CPy_DecRef(cpy_r_r73);
    CPy_DecRef(cpy_r_r75);
    goto CPyL108;
CPyL132: ;
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_light_guide_dist);
    CPy_DecRef(cpy_r_r73);
    CPy_DecRef(cpy_r_r80);
    goto CPyL108;
CPyL133: ;
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_light_guide_dist);
    CPy_DecRef(cpy_r_r73);
    CPy_DecRef(cpy_r_r80);
    CPy_DecRef(cpy_r_r82);
    goto CPyL108;
CPyL134: ;
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_light_guide_dist);
    CPy_DecRef(cpy_r_r73);
    goto CPyL108;
CPyL135: ;
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_light_guide_dist);
    CPy_DecRef(cpy_r_r73);
    CPy_DecRef(cpy_r_r88);
    goto CPyL108;
CPyL136: ;
    CPy_DECREF(cpy_r_PMT_cond);
    goto CPyL56;
CPyL137: ;
    CPy_DecRef(cpy_r_dist);
    CPy_DecRef(cpy_r_temp_o);
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_r102);
    goto CPyL108;
CPyL138: ;
    CPy_DecRef(cpy_r_dist);
    CPy_DecRef(cpy_r_temp_o);
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_r107);
    goto CPyL108;
CPyL139: ;
    CPy_DecRef(cpy_r_dist);
    CPy_DecRef(cpy_r_temp_o);
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_r112);
    goto CPyL108;
CPyL140: ;
    CPy_DecRef(cpy_r_dist);
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_r112);
    CPy_DecRef(cpy_r_r116);
    goto CPyL108;
CPyL141: ;
    CPy_DecRef(cpy_r_dist);
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_r112);
    goto CPyL108;
CPyL142: ;
    CPy_DecRef(cpy_r_dist);
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_r112);
    CPy_DecRef(cpy_r_r121);
    goto CPyL108;
CPyL143: ;
    CPy_DecRef(cpy_r_dist);
    CPy_DecRef(cpy_r_PMT_cond);
    goto CPyL108;
CPyL144: ;
    CPy_DECREF(cpy_r_dist);
    goto CPyL77;
CPyL145: ;
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_r140);
    goto CPyL108;
CPyL146: ;
    CPy_DecRef(cpy_r_temp_o);
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_light_guide_dist);
    CPy_DecRef(cpy_r_r155);
    goto CPyL108;
CPyL147: ;
    CPy_DecRef(cpy_r_temp_o);
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_light_guide_dist);
    CPy_DecRef(cpy_r_r160);
    goto CPyL108;
CPyL148: ;
    CPy_DecRef(cpy_r_temp_o);
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_light_guide_dist);
    CPy_DecRef(cpy_r_r160);
    CPy_DecRef(cpy_r_r162);
    goto CPyL108;
CPyL149: ;
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_light_guide_dist);
    CPy_DecRef(cpy_r_r160);
    CPy_DecRef(cpy_r_r167);
    goto CPyL108;
CPyL150: ;
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_light_guide_dist);
    CPy_DecRef(cpy_r_r160);
    CPy_DecRef(cpy_r_r167);
    CPy_DecRef(cpy_r_r169);
    goto CPyL108;
CPyL151: ;
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_light_guide_dist);
    CPy_DecRef(cpy_r_r160);
    goto CPyL108;
CPyL152: ;
    CPy_DecRef(cpy_r_PMT_cond);
    CPy_DecRef(cpy_r_light_guide_dist);
    CPy_DecRef(cpy_r_r160);
    CPy_DecRef(cpy_r_r175);
    goto CPyL108;
CPyL153: ;
    CPy_DECREF(cpy_r_PMT_cond);
    goto CPyL105;
}

PyObject *CPyPy_Simulation___distance_solver(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"u", "o", "center", "radius", "plane_z", "corner_center", "corner_radius", "pmt_center", "pmt_radius", 0};
    static CPyArg_Parser parser = {"OOOOOOOOO:distance_solver", kwlist, 0};
    PyObject *obj_u;
    PyObject *obj_o;
    PyObject *obj_center;
    PyObject *obj_radius;
    PyObject *obj_plane_z;
    PyObject *obj_corner_center;
    PyObject *obj_corner_radius;
    PyObject *obj_pmt_center;
    PyObject *obj_pmt_radius;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_u, &obj_o, &obj_center, &obj_radius, &obj_plane_z, &obj_corner_center, &obj_corner_radius, &obj_pmt_center, &obj_pmt_radius)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *arg_u = obj_u;
    PyObject *arg_o = obj_o;
    PyObject *arg_center = obj_center;
    PyObject *arg_radius = obj_radius;
    PyObject *arg_plane_z = obj_plane_z;
    PyObject *arg_corner_center = obj_corner_center;
    PyObject *arg_corner_radius = obj_corner_radius;
    PyObject *arg_pmt_center = obj_pmt_center;
    PyObject *arg_pmt_radius = obj_pmt_radius;
    PyObject *retval = CPyDef_Simulation___distance_solver(arg_self, arg_u, arg_o, arg_center, arg_radius, arg_plane_z, arg_corner_center, arg_corner_radius, arg_pmt_center, arg_pmt_radius);
    return retval;
fail: ;
    CPy_AddTraceback("modTof.py", "distance_solver", 157, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Simulation___photon_interaction(PyObject *cpy_r_self, PyObject *cpy_r_u, PyObject *cpy_r_n) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject **cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_u_r;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject **cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    int32_t cpy_r_r18;
    char cpy_r_r19;
    char cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_v;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject **cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject **cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject **cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject **cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject **cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_theta;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject **cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_inside_sqrt;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject **cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_sqrt_term;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject **cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject **cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject **cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_Rs;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject **cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject **cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_r137;
    PyObject *cpy_r_r138;
    PyObject **cpy_r_r140;
    PyObject *cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    PyObject *cpy_r_Rp;
    PyObject *cpy_r_r144;
    PyObject *cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject *cpy_r_r149;
    PyObject *cpy_r_r150;
    PyObject *cpy_r_r151;
    PyObject *cpy_r_r152;
    PyObject *cpy_r_r153;
    int32_t cpy_r_r154;
    char cpy_r_r155;
    char cpy_r_r156;
    PyObject *cpy_r_r157;
    PyObject *cpy_r_r158;
    tuple_T2OO cpy_r_r159;
    PyObject *cpy_r_r160;
    PyObject *cpy_r_r161;
    PyObject *cpy_r_r162;
    PyObject *cpy_r_r163;
    PyObject *cpy_r_r164;
    PyObject *cpy_r_r165;
    PyObject *cpy_r_r166;
    PyObject *cpy_r_r167;
    PyObject *cpy_r_r168;
    int32_t cpy_r_r169;
    char cpy_r_r170;
    char cpy_r_r171;
    PyObject *cpy_r_r172;
    PyObject *cpy_r_r173;
    tuple_T2OO cpy_r_r174;
    PyObject *cpy_r_r175;
    PyObject *cpy_r_r176;
    PyObject *cpy_r_r177;
    PyObject *cpy_r_r178;
    double cpy_r_r179;
    char cpy_r_r180;
    double cpy_r_r181;
    PyObject *cpy_r_r182;
    PyObject *cpy_r_r183;
    PyObject *cpy_r_r184;
    PyObject *cpy_r_r185;
    PyObject *cpy_r_r186;
    PyObject *cpy_r_r187;
    PyObject *cpy_r_r188;
    double cpy_r_r189;
    char cpy_r_r190;
    double cpy_r_r191;
    PyObject *cpy_r_r192;
    PyObject *cpy_r_r193;
    PyObject *cpy_r_r194;
    PyObject *cpy_r_r195;
    PyObject *cpy_r_r196;
    PyObject **cpy_r_r198;
    PyObject *cpy_r_r199;
    PyObject *cpy_r_theta_new;
    PyObject *cpy_r_r200;
    PyObject *cpy_r_r201;
    PyObject *cpy_r_r202;
    double cpy_r_r203;
    char cpy_r_r204;
    double cpy_r_r205;
    PyObject *cpy_r_r206;
    PyObject *cpy_r_r207;
    PyObject *cpy_r_r208;
    PyObject *cpy_r_r209;
    PyObject *cpy_r_r210;
    double cpy_r_r211;
    char cpy_r_r212;
    PyObject *cpy_r_r213;
    PyObject *cpy_r_r214;
    PyObject *cpy_r_r215;
    PyObject *cpy_r_r216;
    PyObject *cpy_r_r217;
    PyObject **cpy_r_r219;
    PyObject *cpy_r_r220;
    PyObject *cpy_r_phi_new;
    PyObject *cpy_r_r221;
    PyObject *cpy_r_r222;
    PyObject *cpy_r_r223;
    PyObject **cpy_r_r225;
    PyObject *cpy_r_r226;
    PyObject *cpy_r_r227;
    PyObject *cpy_r_r228;
    PyObject *cpy_r_r229;
    PyObject **cpy_r_r231;
    PyObject *cpy_r_r232;
    PyObject *cpy_r_r233;
    PyObject *cpy_r_r234;
    PyObject *cpy_r_r235;
    PyObject *cpy_r_r236;
    PyObject **cpy_r_r238;
    PyObject *cpy_r_r239;
    PyObject *cpy_r_r240;
    PyObject *cpy_r_r241;
    PyObject *cpy_r_r242;
    PyObject **cpy_r_r244;
    PyObject *cpy_r_r245;
    PyObject *cpy_r_r246;
    PyObject *cpy_r_r247;
    PyObject *cpy_r_r248;
    PyObject *cpy_r_r249;
    PyObject **cpy_r_r251;
    PyObject *cpy_r_r252;
    PyObject *cpy_r_r253;
    CPyPtr cpy_r_r254;
    CPyPtr cpy_r_r255;
    CPyPtr cpy_r_r256;
    CPyPtr cpy_r_r257;
    PyObject *cpy_r_r258;
    PyObject *cpy_r_r259;
    PyObject *cpy_r_r260;
    PyObject **cpy_r_r262;
    PyObject *cpy_r_r263;
    PyObject *cpy_r_r264;
    PyObject *cpy_r_new_u;
    PyObject *cpy_r_r265;
    PyObject *cpy_r_r266;
    PyObject *cpy_r_r267;
    PyObject *cpy_r_r268;
    PyObject *cpy_r_r269;
    tuple_T2OO cpy_r_r270;
    PyObject *cpy_r_r271;
    PyObject *cpy_r_r272;
    cpy_r_r0 = CPyModule_numpy;
    cpy_r_r1 = CPyStatics[31]; /* 'dot' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 199, CPyStatic_globals);
        goto CPyL119;
    }
    PyObject *cpy_r_r3[2] = {cpy_r_u, cpy_r_n};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = _PyObject_Vectorcall(cpy_r_r2, cpy_r_r4, 2, 0);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 199, CPyStatic_globals);
        goto CPyL119;
    }
    cpy_r_r6 = CPyStatics[257]; /* 2 */
    cpy_r_r7 = PyNumber_Multiply(cpy_r_r6, cpy_r_r5);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 199, CPyStatic_globals);
        goto CPyL119;
    }
    cpy_r_r8 = PyNumber_Multiply(cpy_r_r7, cpy_r_n);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 199, CPyStatic_globals);
        goto CPyL119;
    }
    cpy_r_r9 = PyNumber_Subtract(cpy_r_u, cpy_r_r8);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 199, CPyStatic_globals);
        goto CPyL119;
    }
    cpy_r_u_r = cpy_r_r9;
    cpy_r_r10 = CPyModule_numpy;
    cpy_r_r11 = CPyStatics[31]; /* 'dot' */
    cpy_r_r12 = CPyObject_GetAttr(cpy_r_r10, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 200, CPyStatic_globals);
        goto CPyL120;
    }
    PyObject *cpy_r_r13[2] = {cpy_r_u, cpy_r_n};
    cpy_r_r14 = (PyObject **)&cpy_r_r13;
    cpy_r_r15 = _PyObject_Vectorcall(cpy_r_r12, cpy_r_r14, 2, 0);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 200, CPyStatic_globals);
        goto CPyL120;
    }
    cpy_r_r16 = CPyStatics[244]; /* 0 */
    cpy_r_r17 = PyObject_RichCompare(cpy_r_r15, cpy_r_r16, 0);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 200, CPyStatic_globals);
        goto CPyL120;
    }
    cpy_r_r18 = PyObject_IsTrue(cpy_r_r17);
    CPy_DECREF(cpy_r_r17);
    cpy_r_r19 = cpy_r_r18 >= 0;
    if (unlikely(!cpy_r_r19)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 200, CPyStatic_globals);
        goto CPyL120;
    }
    cpy_r_r20 = cpy_r_r18;
    if (!cpy_r_r20) goto CPyL12;
    cpy_r_r21 = CPyStatics[260]; /* -1 */
    cpy_r_r22 = PyNumber_Multiply(cpy_r_u, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 200, CPyStatic_globals);
        goto CPyL120;
    }
    cpy_r_r23 = cpy_r_r22;
    goto CPyL13;
CPyL12: ;
    CPy_INCREF(cpy_r_u);
    cpy_r_r23 = cpy_r_u;
CPyL13: ;
    cpy_r_v = cpy_r_r23;
    cpy_r_r24 = CPyModule_numpy;
    cpy_r_r25 = CPyStatics[34]; /* 'cross' */
    cpy_r_r26 = CPyObject_GetAttr(cpy_r_r24, cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 201, CPyStatic_globals);
        goto CPyL121;
    }
    PyObject *cpy_r_r27[2] = {cpy_r_v, cpy_r_n};
    cpy_r_r28 = (PyObject **)&cpy_r_r27;
    cpy_r_r29 = _PyObject_Vectorcall(cpy_r_r26, cpy_r_r28, 2, 0);
    CPy_DECREF(cpy_r_r26);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 201, CPyStatic_globals);
        goto CPyL121;
    }
    CPy_DECREF(cpy_r_v);
    cpy_r_r30 = CPyModule_numpy;
    cpy_r_r31 = CPyStatics[27]; /* 'linalg' */
    cpy_r_r32 = CPyObject_GetAttr(cpy_r_r30, cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 201, CPyStatic_globals);
        goto CPyL122;
    }
    cpy_r_r33 = CPyStatics[28]; /* 'norm' */
    cpy_r_r34 = CPyObject_GetAttr(cpy_r_r32, cpy_r_r33);
    CPy_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 201, CPyStatic_globals);
        goto CPyL122;
    }
    PyObject *cpy_r_r35[1] = {cpy_r_r29};
    cpy_r_r36 = (PyObject **)&cpy_r_r35;
    cpy_r_r37 = _PyObject_Vectorcall(cpy_r_r34, cpy_r_r36, 1, 0);
    CPy_DECREF(cpy_r_r34);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 201, CPyStatic_globals);
        goto CPyL122;
    }
    CPy_DECREF(cpy_r_r29);
    cpy_r_r38 = CPyModule_numpy;
    cpy_r_r39 = CPyStatics[27]; /* 'linalg' */
    cpy_r_r40 = CPyObject_GetAttr(cpy_r_r38, cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 201, CPyStatic_globals);
        goto CPyL123;
    }
    cpy_r_r41 = CPyStatics[28]; /* 'norm' */
    cpy_r_r42 = CPyObject_GetAttr(cpy_r_r40, cpy_r_r41);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 201, CPyStatic_globals);
        goto CPyL123;
    }
    PyObject *cpy_r_r43[1] = {cpy_r_u};
    cpy_r_r44 = (PyObject **)&cpy_r_r43;
    cpy_r_r45 = _PyObject_Vectorcall(cpy_r_r42, cpy_r_r44, 1, 0);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 201, CPyStatic_globals);
        goto CPyL123;
    }
    cpy_r_r46 = CPyModule_numpy;
    cpy_r_r47 = CPyStatics[27]; /* 'linalg' */
    cpy_r_r48 = CPyObject_GetAttr(cpy_r_r46, cpy_r_r47);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 201, CPyStatic_globals);
        goto CPyL124;
    }
    cpy_r_r49 = CPyStatics[28]; /* 'norm' */
    cpy_r_r50 = CPyObject_GetAttr(cpy_r_r48, cpy_r_r49);
    CPy_DECREF(cpy_r_r48);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 201, CPyStatic_globals);
        goto CPyL124;
    }
    PyObject *cpy_r_r51[1] = {cpy_r_n};
    cpy_r_r52 = (PyObject **)&cpy_r_r51;
    cpy_r_r53 = _PyObject_Vectorcall(cpy_r_r50, cpy_r_r52, 1, 0);
    CPy_DECREF(cpy_r_r50);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 201, CPyStatic_globals);
        goto CPyL124;
    }
    cpy_r_r54 = PyNumber_Multiply(cpy_r_r45, cpy_r_r53);
    CPy_DECREF(cpy_r_r45);
    CPy_DECREF(cpy_r_r53);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 201, CPyStatic_globals);
        goto CPyL123;
    }
    cpy_r_r55 = PyNumber_TrueDivide(cpy_r_r37, cpy_r_r54);
    CPy_DECREF(cpy_r_r37);
    CPy_DECREF(cpy_r_r54);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 201, CPyStatic_globals);
        goto CPyL120;
    }
    cpy_r_r56 = CPyModule_numpy;
    cpy_r_r57 = CPyStatics[35]; /* 'arcsin' */
    cpy_r_r58 = CPyObject_GetAttr(cpy_r_r56, cpy_r_r57);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 201, CPyStatic_globals);
        goto CPyL125;
    }
    PyObject *cpy_r_r59[1] = {cpy_r_r55};
    cpy_r_r60 = (PyObject **)&cpy_r_r59;
    cpy_r_r61 = _PyObject_Vectorcall(cpy_r_r58, cpy_r_r60, 1, 0);
    CPy_DECREF(cpy_r_r58);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 201, CPyStatic_globals);
        goto CPyL125;
    }
    CPy_DECREF(cpy_r_r55);
    cpy_r_theta = cpy_r_r61;
    cpy_r_r62 = ((modTof___SimulationObject *)cpy_r_self)->_n_1;
    CPy_INCREF(cpy_r_r62);
    cpy_r_r63 = ((modTof___SimulationObject *)cpy_r_self)->_n_2;
    CPy_INCREF(cpy_r_r63);
    cpy_r_r64 = PyNumber_TrueDivide(cpy_r_r62, cpy_r_r63);
    CPy_DECREF(cpy_r_r62);
    CPy_DECREF(cpy_r_r63);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 202, CPyStatic_globals);
        goto CPyL126;
    }
    cpy_r_r65 = CPyModule_numpy;
    cpy_r_r66 = CPyStatics[5]; /* 'sin' */
    cpy_r_r67 = CPyObject_GetAttr(cpy_r_r65, cpy_r_r66);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 202, CPyStatic_globals);
        goto CPyL127;
    }
    PyObject *cpy_r_r68[1] = {cpy_r_theta};
    cpy_r_r69 = (PyObject **)&cpy_r_r68;
    cpy_r_r70 = _PyObject_Vectorcall(cpy_r_r67, cpy_r_r69, 1, 0);
    CPy_DECREF(cpy_r_r67);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 202, CPyStatic_globals);
        goto CPyL127;
    }
    cpy_r_r71 = PyNumber_Multiply(cpy_r_r64, cpy_r_r70);
    CPy_DECREF(cpy_r_r64);
    CPy_DECREF(cpy_r_r70);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 202, CPyStatic_globals);
        goto CPyL126;
    }
    cpy_r_r72 = CPyStatics[257]; /* 2 */
    cpy_r_r73 = CPyNumber_Power(cpy_r_r71, cpy_r_r72);
    CPy_DECREF(cpy_r_r71);
    if (unlikely(cpy_r_r73 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 202, CPyStatic_globals);
        goto CPyL126;
    }
    cpy_r_inside_sqrt = cpy_r_r73;
    cpy_r_r74 = CPyStatics[247]; /* 1 */
    cpy_r_r75 = PyNumber_Subtract(cpy_r_r74, cpy_r_inside_sqrt);
    CPy_DECREF(cpy_r_inside_sqrt);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 203, CPyStatic_globals);
        goto CPyL126;
    }
    cpy_r_r76 = CPyModule_numpy;
    cpy_r_r77 = CPyStatics[30]; /* 'sqrt' */
    cpy_r_r78 = CPyObject_GetAttr(cpy_r_r76, cpy_r_r77);
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 203, CPyStatic_globals);
        goto CPyL128;
    }
    PyObject *cpy_r_r79[1] = {cpy_r_r75};
    cpy_r_r80 = (PyObject **)&cpy_r_r79;
    cpy_r_r81 = _PyObject_Vectorcall(cpy_r_r78, cpy_r_r80, 1, 0);
    CPy_DECREF(cpy_r_r78);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 203, CPyStatic_globals);
        goto CPyL128;
    }
    CPy_DECREF(cpy_r_r75);
    cpy_r_sqrt_term = cpy_r_r81;
    cpy_r_r82 = ((modTof___SimulationObject *)cpy_r_self)->_n_1;
    CPy_INCREF(cpy_r_r82);
    cpy_r_r83 = CPyModule_numpy;
    cpy_r_r84 = CPyStatics[4]; /* 'cos' */
    cpy_r_r85 = CPyObject_GetAttr(cpy_r_r83, cpy_r_r84);
    if (unlikely(cpy_r_r85 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 204, CPyStatic_globals);
        goto CPyL129;
    }
    PyObject *cpy_r_r86[1] = {cpy_r_theta};
    cpy_r_r87 = (PyObject **)&cpy_r_r86;
    cpy_r_r88 = _PyObject_Vectorcall(cpy_r_r85, cpy_r_r87, 1, 0);
    CPy_DECREF(cpy_r_r85);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 204, CPyStatic_globals);
        goto CPyL129;
    }
    cpy_r_r89 = PyNumber_Multiply(cpy_r_r82, cpy_r_r88);
    CPy_DECREF(cpy_r_r82);
    CPy_DECREF(cpy_r_r88);
    if (unlikely(cpy_r_r89 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 204, CPyStatic_globals);
        goto CPyL130;
    }
    cpy_r_r90 = ((modTof___SimulationObject *)cpy_r_self)->_n_2;
    CPy_INCREF(cpy_r_r90);
    cpy_r_r91 = PyNumber_Multiply(cpy_r_r90, cpy_r_sqrt_term);
    CPy_DECREF(cpy_r_r90);
    if (unlikely(cpy_r_r91 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 204, CPyStatic_globals);
        goto CPyL131;
    }
    cpy_r_r92 = PyNumber_Subtract(cpy_r_r89, cpy_r_r91);
    CPy_DECREF(cpy_r_r89);
    CPy_DECREF(cpy_r_r91);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 204, CPyStatic_globals);
        goto CPyL130;
    }
    cpy_r_r93 = ((modTof___SimulationObject *)cpy_r_self)->_n_1;
    CPy_INCREF(cpy_r_r93);
    cpy_r_r94 = CPyModule_numpy;
    cpy_r_r95 = CPyStatics[4]; /* 'cos' */
    cpy_r_r96 = CPyObject_GetAttr(cpy_r_r94, cpy_r_r95);
    if (unlikely(cpy_r_r96 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 204, CPyStatic_globals);
        goto CPyL132;
    }
    PyObject *cpy_r_r97[1] = {cpy_r_theta};
    cpy_r_r98 = (PyObject **)&cpy_r_r97;
    cpy_r_r99 = _PyObject_Vectorcall(cpy_r_r96, cpy_r_r98, 1, 0);
    CPy_DECREF(cpy_r_r96);
    if (unlikely(cpy_r_r99 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 204, CPyStatic_globals);
        goto CPyL132;
    }
    cpy_r_r100 = PyNumber_Multiply(cpy_r_r93, cpy_r_r99);
    CPy_DECREF(cpy_r_r93);
    CPy_DECREF(cpy_r_r99);
    if (unlikely(cpy_r_r100 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 204, CPyStatic_globals);
        goto CPyL133;
    }
    cpy_r_r101 = ((modTof___SimulationObject *)cpy_r_self)->_n_2;
    CPy_INCREF(cpy_r_r101);
    cpy_r_r102 = PyNumber_Multiply(cpy_r_r101, cpy_r_sqrt_term);
    CPy_DECREF(cpy_r_r101);
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 204, CPyStatic_globals);
        goto CPyL134;
    }
    cpy_r_r103 = PyNumber_Add(cpy_r_r100, cpy_r_r102);
    CPy_DECREF(cpy_r_r100);
    CPy_DECREF(cpy_r_r102);
    if (unlikely(cpy_r_r103 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 204, CPyStatic_globals);
        goto CPyL133;
    }
    cpy_r_r104 = PyNumber_TrueDivide(cpy_r_r92, cpy_r_r103);
    CPy_DECREF(cpy_r_r92);
    CPy_DECREF(cpy_r_r103);
    if (unlikely(cpy_r_r104 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 204, CPyStatic_globals);
        goto CPyL130;
    }
    cpy_r_r105 = CPyModule_numpy;
    cpy_r_r106 = CPyStatics[24]; /* 'abs' */
    cpy_r_r107 = CPyObject_GetAttr(cpy_r_r105, cpy_r_r106);
    if (unlikely(cpy_r_r107 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 204, CPyStatic_globals);
        goto CPyL135;
    }
    PyObject *cpy_r_r108[1] = {cpy_r_r104};
    cpy_r_r109 = (PyObject **)&cpy_r_r108;
    cpy_r_r110 = _PyObject_Vectorcall(cpy_r_r107, cpy_r_r109, 1, 0);
    CPy_DECREF(cpy_r_r107);
    if (unlikely(cpy_r_r110 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 204, CPyStatic_globals);
        goto CPyL135;
    }
    CPy_DECREF(cpy_r_r104);
    cpy_r_r111 = CPyStatics[257]; /* 2 */
    cpy_r_r112 = CPyNumber_Power(cpy_r_r110, cpy_r_r111);
    CPy_DECREF(cpy_r_r110);
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 204, CPyStatic_globals);
        goto CPyL130;
    }
    cpy_r_Rs = cpy_r_r112;
    cpy_r_r113 = ((modTof___SimulationObject *)cpy_r_self)->_n_1;
    CPy_INCREF(cpy_r_r113);
    cpy_r_r114 = PyNumber_Multiply(cpy_r_r113, cpy_r_sqrt_term);
    CPy_DECREF(cpy_r_r113);
    if (unlikely(cpy_r_r114 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 205, CPyStatic_globals);
        goto CPyL136;
    }
    cpy_r_r115 = ((modTof___SimulationObject *)cpy_r_self)->_n_2;
    CPy_INCREF(cpy_r_r115);
    cpy_r_r116 = CPyModule_numpy;
    cpy_r_r117 = CPyStatics[4]; /* 'cos' */
    cpy_r_r118 = CPyObject_GetAttr(cpy_r_r116, cpy_r_r117);
    if (unlikely(cpy_r_r118 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 205, CPyStatic_globals);
        goto CPyL137;
    }
    PyObject *cpy_r_r119[1] = {cpy_r_theta};
    cpy_r_r120 = (PyObject **)&cpy_r_r119;
    cpy_r_r121 = _PyObject_Vectorcall(cpy_r_r118, cpy_r_r120, 1, 0);
    CPy_DECREF(cpy_r_r118);
    if (unlikely(cpy_r_r121 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 205, CPyStatic_globals);
        goto CPyL137;
    }
    cpy_r_r122 = PyNumber_Multiply(cpy_r_r115, cpy_r_r121);
    CPy_DECREF(cpy_r_r115);
    CPy_DECREF(cpy_r_r121);
    if (unlikely(cpy_r_r122 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 205, CPyStatic_globals);
        goto CPyL138;
    }
    cpy_r_r123 = PyNumber_Subtract(cpy_r_r114, cpy_r_r122);
    CPy_DECREF(cpy_r_r114);
    CPy_DECREF(cpy_r_r122);
    if (unlikely(cpy_r_r123 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 205, CPyStatic_globals);
        goto CPyL136;
    }
    cpy_r_r124 = ((modTof___SimulationObject *)cpy_r_self)->_n_1;
    CPy_INCREF(cpy_r_r124);
    cpy_r_r125 = PyNumber_Multiply(cpy_r_r124, cpy_r_sqrt_term);
    CPy_DECREF(cpy_r_r124);
    CPy_DECREF(cpy_r_sqrt_term);
    if (unlikely(cpy_r_r125 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 205, CPyStatic_globals);
        goto CPyL139;
    }
    cpy_r_r126 = ((modTof___SimulationObject *)cpy_r_self)->_n_2;
    CPy_INCREF(cpy_r_r126);
    cpy_r_r127 = CPyModule_numpy;
    cpy_r_r128 = CPyStatics[4]; /* 'cos' */
    cpy_r_r129 = CPyObject_GetAttr(cpy_r_r127, cpy_r_r128);
    if (unlikely(cpy_r_r129 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 205, CPyStatic_globals);
        goto CPyL140;
    }
    PyObject *cpy_r_r130[1] = {cpy_r_theta};
    cpy_r_r131 = (PyObject **)&cpy_r_r130;
    cpy_r_r132 = _PyObject_Vectorcall(cpy_r_r129, cpy_r_r131, 1, 0);
    CPy_DECREF(cpy_r_r129);
    if (unlikely(cpy_r_r132 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 205, CPyStatic_globals);
        goto CPyL140;
    }
    CPy_DECREF(cpy_r_theta);
    cpy_r_r133 = PyNumber_Multiply(cpy_r_r126, cpy_r_r132);
    CPy_DECREF(cpy_r_r126);
    CPy_DECREF(cpy_r_r132);
    if (unlikely(cpy_r_r133 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 205, CPyStatic_globals);
        goto CPyL141;
    }
    cpy_r_r134 = PyNumber_Add(cpy_r_r125, cpy_r_r133);
    CPy_DECREF(cpy_r_r125);
    CPy_DECREF(cpy_r_r133);
    if (unlikely(cpy_r_r134 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 205, CPyStatic_globals);
        goto CPyL142;
    }
    cpy_r_r135 = PyNumber_TrueDivide(cpy_r_r123, cpy_r_r134);
    CPy_DECREF(cpy_r_r123);
    CPy_DECREF(cpy_r_r134);
    if (unlikely(cpy_r_r135 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 205, CPyStatic_globals);
        goto CPyL143;
    }
    cpy_r_r136 = CPyModule_numpy;
    cpy_r_r137 = CPyStatics[24]; /* 'abs' */
    cpy_r_r138 = CPyObject_GetAttr(cpy_r_r136, cpy_r_r137);
    if (unlikely(cpy_r_r138 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 205, CPyStatic_globals);
        goto CPyL144;
    }
    PyObject *cpy_r_r139[1] = {cpy_r_r135};
    cpy_r_r140 = (PyObject **)&cpy_r_r139;
    cpy_r_r141 = _PyObject_Vectorcall(cpy_r_r138, cpy_r_r140, 1, 0);
    CPy_DECREF(cpy_r_r138);
    if (unlikely(cpy_r_r141 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 205, CPyStatic_globals);
        goto CPyL144;
    }
    CPy_DECREF(cpy_r_r135);
    cpy_r_r142 = CPyStatics[257]; /* 2 */
    cpy_r_r143 = CPyNumber_Power(cpy_r_r141, cpy_r_r142);
    CPy_DECREF(cpy_r_r141);
    if (unlikely(cpy_r_r143 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 205, CPyStatic_globals);
        goto CPyL143;
    }
    cpy_r_Rp = cpy_r_r143;
    cpy_r_r144 = CPyModule_numpy;
    cpy_r_r145 = CPyStatics[36]; /* 'random' */
    cpy_r_r146 = CPyObject_GetAttr(cpy_r_r144, cpy_r_r145);
    if (unlikely(cpy_r_r146 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 207, CPyStatic_globals);
        goto CPyL145;
    }
    cpy_r_r147 = CPyStatics[36]; /* 'random' */
    cpy_r_r148 = CPyObject_GetAttr(cpy_r_r146, cpy_r_r147);
    CPy_DECREF(cpy_r_r146);
    if (unlikely(cpy_r_r148 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 207, CPyStatic_globals);
        goto CPyL145;
    }
    cpy_r_r149 = _PyObject_Vectorcall(cpy_r_r148, 0, 0, 0);
    CPy_DECREF(cpy_r_r148);
    if (unlikely(cpy_r_r149 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 207, CPyStatic_globals);
        goto CPyL145;
    }
    cpy_r_r150 = PyNumber_Add(cpy_r_Rs, cpy_r_Rp);
    CPy_DECREF(cpy_r_Rs);
    CPy_DECREF(cpy_r_Rp);
    if (unlikely(cpy_r_r150 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 207, CPyStatic_globals);
        goto CPyL146;
    }
    cpy_r_r151 = CPyStatics[257]; /* 2 */
    cpy_r_r152 = PyNumber_TrueDivide(cpy_r_r150, cpy_r_r151);
    CPy_DECREF(cpy_r_r150);
    if (unlikely(cpy_r_r152 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 207, CPyStatic_globals);
        goto CPyL146;
    }
    cpy_r_r153 = PyObject_RichCompare(cpy_r_r149, cpy_r_r152, 0);
    CPy_DECREF(cpy_r_r149);
    CPy_DECREF(cpy_r_r152);
    if (unlikely(cpy_r_r153 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 207, CPyStatic_globals);
        goto CPyL120;
    }
    cpy_r_r154 = PyObject_IsTrue(cpy_r_r153);
    CPy_DECREF(cpy_r_r153);
    cpy_r_r155 = cpy_r_r154 >= 0;
    if (unlikely(!cpy_r_r155)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 207, CPyStatic_globals);
        goto CPyL120;
    }
    cpy_r_r156 = cpy_r_r154;
    if (!cpy_r_r156) goto CPyL74;
    cpy_r_r157 = CPyDef_Simulation___normalize(cpy_r_self, cpy_r_u_r);
    CPy_DECREF(cpy_r_u_r);
    if (unlikely(cpy_r_r157 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 208, CPyStatic_globals);
        goto CPyL119;
    }
    cpy_r_r158 = 1 ? Py_True : Py_False;
    cpy_r_r159.f0 = cpy_r_r157;
    cpy_r_r159.f1 = cpy_r_r158;
    CPy_INCREF(cpy_r_r159.f0);
    CPy_INCREF(cpy_r_r159.f1);
    CPy_DECREF(cpy_r_r157);
    cpy_r_r160 = PyTuple_New(2);
    if (unlikely(cpy_r_r160 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp7 = cpy_r_r159.f0;
    PyTuple_SET_ITEM(cpy_r_r160, 0, __tmp7);
    PyObject *__tmp8 = cpy_r_r159.f1;
    PyTuple_SET_ITEM(cpy_r_r160, 1, __tmp8);
    return cpy_r_r160;
CPyL74: ;
    cpy_r_r161 = CPyModule_numpy;
    cpy_r_r162 = CPyStatics[36]; /* 'random' */
    cpy_r_r163 = CPyObject_GetAttr(cpy_r_r161, cpy_r_r162);
    if (unlikely(cpy_r_r163 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 210, CPyStatic_globals);
        goto CPyL120;
    }
    cpy_r_r164 = CPyStatics[36]; /* 'random' */
    cpy_r_r165 = CPyObject_GetAttr(cpy_r_r163, cpy_r_r164);
    CPy_DECREF(cpy_r_r163);
    if (unlikely(cpy_r_r165 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 210, CPyStatic_globals);
        goto CPyL120;
    }
    cpy_r_r166 = _PyObject_Vectorcall(cpy_r_r165, 0, 0, 0);
    CPy_DECREF(cpy_r_r165);
    if (unlikely(cpy_r_r166 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 210, CPyStatic_globals);
        goto CPyL120;
    }
    cpy_r_r167 = ((modTof___SimulationObject *)cpy_r_self)->_pr_absorption;
    CPy_INCREF(cpy_r_r167);
    cpy_r_r168 = PyObject_RichCompare(cpy_r_r166, cpy_r_r167, 0);
    CPy_DECREF(cpy_r_r166);
    CPy_DECREF(cpy_r_r167);
    if (unlikely(cpy_r_r168 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 210, CPyStatic_globals);
        goto CPyL120;
    }
    cpy_r_r169 = PyObject_IsTrue(cpy_r_r168);
    CPy_DECREF(cpy_r_r168);
    cpy_r_r170 = cpy_r_r169 >= 0;
    if (unlikely(!cpy_r_r170)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 210, CPyStatic_globals);
        goto CPyL120;
    }
    cpy_r_r171 = cpy_r_r169;
    if (!cpy_r_r171) goto CPyL147;
    cpy_r_r172 = CPyDef_Simulation___normalize(cpy_r_self, cpy_r_u_r);
    CPy_DECREF(cpy_r_u_r);
    if (unlikely(cpy_r_r172 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 211, CPyStatic_globals);
        goto CPyL119;
    }
    cpy_r_r173 = 0 ? Py_True : Py_False;
    cpy_r_r174.f0 = cpy_r_r172;
    cpy_r_r174.f1 = cpy_r_r173;
    CPy_INCREF(cpy_r_r174.f0);
    CPy_INCREF(cpy_r_r174.f1);
    CPy_DECREF(cpy_r_r172);
    cpy_r_r175 = PyTuple_New(2);
    if (unlikely(cpy_r_r175 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp9 = cpy_r_r174.f0;
    PyTuple_SET_ITEM(cpy_r_r175, 0, __tmp9);
    PyObject *__tmp10 = cpy_r_r174.f1;
    PyTuple_SET_ITEM(cpy_r_r175, 1, __tmp10);
    return cpy_r_r175;
CPyL82: ;
    cpy_r_r176 = CPyModule_numpy;
    cpy_r_r177 = CPyStatics[37]; /* 'pi' */
    cpy_r_r178 = CPyObject_GetAttr(cpy_r_r176, cpy_r_r177);
    if (unlikely(cpy_r_r178 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 213, CPyStatic_globals);
        goto CPyL119;
    }
    cpy_r_r179 = PyFloat_AsDouble(cpy_r_r178);
    if (cpy_r_r179 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r178); cpy_r_r179 = -113.0;
    }
    CPy_DECREF(cpy_r_r178);
    cpy_r_r180 = cpy_r_r179 == -113.0;
    if (unlikely(cpy_r_r180)) goto CPyL85;
CPyL84: ;
    cpy_r_r181 = -cpy_r_r179;
    cpy_r_r182 = PyFloat_FromDouble(cpy_r_r181);
    cpy_r_r183 = CPyStatics[257]; /* 2 */
    cpy_r_r184 = PyNumber_TrueDivide(cpy_r_r182, cpy_r_r183);
    CPy_DECREF(cpy_r_r182);
    if (unlikely(cpy_r_r184 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 213, CPyStatic_globals);
        goto CPyL119;
    } else
        goto CPyL86;
CPyL85: ;
    cpy_r_r185 = PyErr_Occurred();
    if (unlikely(cpy_r_r185 != NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 213, CPyStatic_globals);
        goto CPyL119;
    } else
        goto CPyL84;
CPyL86: ;
    cpy_r_r186 = CPyModule_numpy;
    cpy_r_r187 = CPyStatics[37]; /* 'pi' */
    cpy_r_r188 = CPyObject_GetAttr(cpy_r_r186, cpy_r_r187);
    if (unlikely(cpy_r_r188 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 213, CPyStatic_globals);
        goto CPyL148;
    }
    cpy_r_r189 = PyFloat_AsDouble(cpy_r_r188);
    if (cpy_r_r189 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r188); cpy_r_r189 = -113.0;
    }
    CPy_DECREF(cpy_r_r188);
    cpy_r_r190 = cpy_r_r189 == -113.0;
    if (unlikely(cpy_r_r190)) goto CPyL89;
CPyL88: ;
    cpy_r_r191 = cpy_r_r189 / 2.0;
    cpy_r_r192 = PyFloat_FromDouble(cpy_r_r191);
    cpy_r_r193 = CPyModule_random;
    cpy_r_r194 = CPyStatics[38]; /* 'uniform' */
    cpy_r_r195 = CPyObject_GetAttr(cpy_r_r193, cpy_r_r194);
    if (unlikely(cpy_r_r195 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 213, CPyStatic_globals);
        goto CPyL149;
    } else
        goto CPyL90;
CPyL89: ;
    cpy_r_r196 = PyErr_Occurred();
    if (unlikely(cpy_r_r196 != NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 213, CPyStatic_globals);
        goto CPyL148;
    } else
        goto CPyL88;
CPyL90: ;
    PyObject *cpy_r_r197[2] = {cpy_r_r184, cpy_r_r192};
    cpy_r_r198 = (PyObject **)&cpy_r_r197;
    cpy_r_r199 = _PyObject_Vectorcall(cpy_r_r195, cpy_r_r198, 2, 0);
    CPy_DECREF(cpy_r_r195);
    if (unlikely(cpy_r_r199 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 213, CPyStatic_globals);
        goto CPyL149;
    }
    CPy_DECREF(cpy_r_r184);
    CPy_DECREF(cpy_r_r192);
    cpy_r_theta_new = cpy_r_r199;
    cpy_r_r200 = CPyModule_numpy;
    cpy_r_r201 = CPyStatics[37]; /* 'pi' */
    cpy_r_r202 = CPyObject_GetAttr(cpy_r_r200, cpy_r_r201);
    if (unlikely(cpy_r_r202 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 214, CPyStatic_globals);
        goto CPyL150;
    }
    cpy_r_r203 = PyFloat_AsDouble(cpy_r_r202);
    if (cpy_r_r203 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r202); cpy_r_r203 = -113.0;
    }
    CPy_DECREF(cpy_r_r202);
    cpy_r_r204 = cpy_r_r203 == -113.0;
    if (unlikely(cpy_r_r204)) goto CPyL94;
CPyL93: ;
    cpy_r_r205 = -cpy_r_r203;
    cpy_r_r206 = PyFloat_FromDouble(cpy_r_r205);
    cpy_r_r207 = CPyModule_numpy;
    cpy_r_r208 = CPyStatics[37]; /* 'pi' */
    cpy_r_r209 = CPyObject_GetAttr(cpy_r_r207, cpy_r_r208);
    if (unlikely(cpy_r_r209 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 214, CPyStatic_globals);
        goto CPyL151;
    } else
        goto CPyL95;
CPyL94: ;
    cpy_r_r210 = PyErr_Occurred();
    if (unlikely(cpy_r_r210 != NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 214, CPyStatic_globals);
        goto CPyL150;
    } else
        goto CPyL93;
CPyL95: ;
    cpy_r_r211 = PyFloat_AsDouble(cpy_r_r209);
    if (cpy_r_r211 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r209); cpy_r_r211 = -113.0;
    }
    CPy_DECREF(cpy_r_r209);
    cpy_r_r212 = cpy_r_r211 == -113.0;
    if (unlikely(cpy_r_r212)) goto CPyL97;
CPyL96: ;
    cpy_r_r213 = CPyModule_random;
    cpy_r_r214 = CPyStatics[38]; /* 'uniform' */
    cpy_r_r215 = CPyObject_GetAttr(cpy_r_r213, cpy_r_r214);
    if (unlikely(cpy_r_r215 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 214, CPyStatic_globals);
        goto CPyL151;
    } else
        goto CPyL98;
CPyL97: ;
    cpy_r_r216 = PyErr_Occurred();
    if (unlikely(cpy_r_r216 != NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 214, CPyStatic_globals);
        goto CPyL151;
    } else
        goto CPyL96;
CPyL98: ;
    cpy_r_r217 = PyFloat_FromDouble(cpy_r_r211);
    PyObject *cpy_r_r218[2] = {cpy_r_r206, cpy_r_r217};
    cpy_r_r219 = (PyObject **)&cpy_r_r218;
    cpy_r_r220 = _PyObject_Vectorcall(cpy_r_r215, cpy_r_r219, 2, 0);
    CPy_DECREF(cpy_r_r215);
    if (unlikely(cpy_r_r220 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 214, CPyStatic_globals);
        goto CPyL152;
    }
    CPy_DECREF(cpy_r_r206);
    CPy_DECREF(cpy_r_r217);
    cpy_r_phi_new = cpy_r_r220;
    cpy_r_r221 = CPyModule_numpy;
    cpy_r_r222 = CPyStatics[5]; /* 'sin' */
    cpy_r_r223 = CPyObject_GetAttr(cpy_r_r221, cpy_r_r222);
    if (unlikely(cpy_r_r223 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 215, CPyStatic_globals);
        goto CPyL153;
    }
    PyObject *cpy_r_r224[1] = {cpy_r_phi_new};
    cpy_r_r225 = (PyObject **)&cpy_r_r224;
    cpy_r_r226 = _PyObject_Vectorcall(cpy_r_r223, cpy_r_r225, 1, 0);
    CPy_DECREF(cpy_r_r223);
    if (unlikely(cpy_r_r226 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 215, CPyStatic_globals);
        goto CPyL153;
    }
    cpy_r_r227 = CPyModule_numpy;
    cpy_r_r228 = CPyStatics[4]; /* 'cos' */
    cpy_r_r229 = CPyObject_GetAttr(cpy_r_r227, cpy_r_r228);
    if (unlikely(cpy_r_r229 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 215, CPyStatic_globals);
        goto CPyL154;
    }
    PyObject *cpy_r_r230[1] = {cpy_r_theta_new};
    cpy_r_r231 = (PyObject **)&cpy_r_r230;
    cpy_r_r232 = _PyObject_Vectorcall(cpy_r_r229, cpy_r_r231, 1, 0);
    CPy_DECREF(cpy_r_r229);
    if (unlikely(cpy_r_r232 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 215, CPyStatic_globals);
        goto CPyL154;
    }
    cpy_r_r233 = PyNumber_Multiply(cpy_r_r226, cpy_r_r232);
    CPy_DECREF(cpy_r_r226);
    CPy_DECREF(cpy_r_r232);
    if (unlikely(cpy_r_r233 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 215, CPyStatic_globals);
        goto CPyL153;
    }
    cpy_r_r234 = CPyModule_numpy;
    cpy_r_r235 = CPyStatics[5]; /* 'sin' */
    cpy_r_r236 = CPyObject_GetAttr(cpy_r_r234, cpy_r_r235);
    if (unlikely(cpy_r_r236 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 215, CPyStatic_globals);
        goto CPyL155;
    }
    PyObject *cpy_r_r237[1] = {cpy_r_phi_new};
    cpy_r_r238 = (PyObject **)&cpy_r_r237;
    cpy_r_r239 = _PyObject_Vectorcall(cpy_r_r236, cpy_r_r238, 1, 0);
    CPy_DECREF(cpy_r_r236);
    if (unlikely(cpy_r_r239 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 215, CPyStatic_globals);
        goto CPyL155;
    }
    cpy_r_r240 = CPyModule_numpy;
    cpy_r_r241 = CPyStatics[5]; /* 'sin' */
    cpy_r_r242 = CPyObject_GetAttr(cpy_r_r240, cpy_r_r241);
    if (unlikely(cpy_r_r242 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 215, CPyStatic_globals);
        goto CPyL156;
    }
    PyObject *cpy_r_r243[1] = {cpy_r_theta_new};
    cpy_r_r244 = (PyObject **)&cpy_r_r243;
    cpy_r_r245 = _PyObject_Vectorcall(cpy_r_r242, cpy_r_r244, 1, 0);
    CPy_DECREF(cpy_r_r242);
    if (unlikely(cpy_r_r245 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 215, CPyStatic_globals);
        goto CPyL156;
    }
    CPy_DECREF(cpy_r_theta_new);
    cpy_r_r246 = PyNumber_Multiply(cpy_r_r239, cpy_r_r245);
    CPy_DECREF(cpy_r_r239);
    CPy_DECREF(cpy_r_r245);
    if (unlikely(cpy_r_r246 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 215, CPyStatic_globals);
        goto CPyL157;
    }
    cpy_r_r247 = CPyModule_numpy;
    cpy_r_r248 = CPyStatics[4]; /* 'cos' */
    cpy_r_r249 = CPyObject_GetAttr(cpy_r_r247, cpy_r_r248);
    if (unlikely(cpy_r_r249 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 215, CPyStatic_globals);
        goto CPyL158;
    }
    PyObject *cpy_r_r250[1] = {cpy_r_phi_new};
    cpy_r_r251 = (PyObject **)&cpy_r_r250;
    cpy_r_r252 = _PyObject_Vectorcall(cpy_r_r249, cpy_r_r251, 1, 0);
    CPy_DECREF(cpy_r_r249);
    if (unlikely(cpy_r_r252 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 215, CPyStatic_globals);
        goto CPyL158;
    }
    CPy_DECREF(cpy_r_phi_new);
    cpy_r_r253 = PyList_New(3);
    if (unlikely(cpy_r_r253 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 215, CPyStatic_globals);
        goto CPyL159;
    }
    cpy_r_r254 = (CPyPtr)&((PyListObject *)cpy_r_r253)->ob_item;
    cpy_r_r255 = *(CPyPtr *)cpy_r_r254;
    *(PyObject * *)cpy_r_r255 = cpy_r_r233;
    cpy_r_r256 = cpy_r_r255 + 8;
    *(PyObject * *)cpy_r_r256 = cpy_r_r246;
    cpy_r_r257 = cpy_r_r255 + 16;
    *(PyObject * *)cpy_r_r257 = cpy_r_r252;
    cpy_r_r258 = CPyModule_numpy;
    cpy_r_r259 = CPyStatics[32]; /* 'array' */
    cpy_r_r260 = CPyObject_GetAttr(cpy_r_r258, cpy_r_r259);
    if (unlikely(cpy_r_r260 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 215, CPyStatic_globals);
        goto CPyL160;
    }
    PyObject *cpy_r_r261[1] = {cpy_r_r253};
    cpy_r_r262 = (PyObject **)&cpy_r_r261;
    cpy_r_r263 = _PyObject_Vectorcall(cpy_r_r260, cpy_r_r262, 1, 0);
    CPy_DECREF(cpy_r_r260);
    if (unlikely(cpy_r_r263 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 215, CPyStatic_globals);
        goto CPyL160;
    }
    CPy_DECREF(cpy_r_r253);
    cpy_r_r264 = CPyDef_Simulation___normalize(cpy_r_self, cpy_r_r263);
    CPy_DECREF(cpy_r_r263);
    if (unlikely(cpy_r_r264 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 215, CPyStatic_globals);
        goto CPyL119;
    }
    cpy_r_new_u = cpy_r_r264;
    cpy_r_r265 = ((modTof___SimulationObject *)cpy_r_self)->_reemission_angle_factor;
    CPy_INCREF(cpy_r_r265);
    cpy_r_r266 = PyNumber_Multiply(cpy_r_r265, cpy_r_new_u);
    CPy_DECREF(cpy_r_r265);
    CPy_DECREF(cpy_r_new_u);
    if (unlikely(cpy_r_r266 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 216, CPyStatic_globals);
        goto CPyL119;
    }
    cpy_r_r267 = PyNumber_Add(cpy_r_r266, cpy_r_n);
    CPy_DECREF(cpy_r_r266);
    if (unlikely(cpy_r_r267 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 216, CPyStatic_globals);
        goto CPyL119;
    }
    cpy_r_u_r = cpy_r_r267;
    cpy_r_r268 = CPyDef_Simulation___normalize(cpy_r_self, cpy_r_u_r);
    CPy_DECREF(cpy_r_u_r);
    if (unlikely(cpy_r_r268 == NULL)) {
        CPy_AddTraceback("modTof.py", "photon_interaction", 217, CPyStatic_globals);
        goto CPyL119;
    }
    cpy_r_r269 = 1 ? Py_True : Py_False;
    cpy_r_r270.f0 = cpy_r_r268;
    cpy_r_r270.f1 = cpy_r_r269;
    CPy_INCREF(cpy_r_r270.f0);
    CPy_INCREF(cpy_r_r270.f1);
    CPy_DECREF(cpy_r_r268);
    cpy_r_r271 = PyTuple_New(2);
    if (unlikely(cpy_r_r271 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp11 = cpy_r_r270.f0;
    PyTuple_SET_ITEM(cpy_r_r271, 0, __tmp11);
    PyObject *__tmp12 = cpy_r_r270.f1;
    PyTuple_SET_ITEM(cpy_r_r271, 1, __tmp12);
    return cpy_r_r271;
CPyL119: ;
    cpy_r_r272 = NULL;
    return cpy_r_r272;
CPyL120: ;
    CPy_DecRef(cpy_r_u_r);
    goto CPyL119;
CPyL121: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_v);
    goto CPyL119;
CPyL122: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_r29);
    goto CPyL119;
CPyL123: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_r37);
    goto CPyL119;
CPyL124: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_r37);
    CPy_DecRef(cpy_r_r45);
    goto CPyL119;
CPyL125: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_r55);
    goto CPyL119;
CPyL126: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_theta);
    goto CPyL119;
CPyL127: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_r64);
    goto CPyL119;
CPyL128: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_r75);
    goto CPyL119;
CPyL129: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_sqrt_term);
    CPy_DecRef(cpy_r_r82);
    goto CPyL119;
CPyL130: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_sqrt_term);
    goto CPyL119;
CPyL131: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_sqrt_term);
    CPy_DecRef(cpy_r_r89);
    goto CPyL119;
CPyL132: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_sqrt_term);
    CPy_DecRef(cpy_r_r92);
    CPy_DecRef(cpy_r_r93);
    goto CPyL119;
CPyL133: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_sqrt_term);
    CPy_DecRef(cpy_r_r92);
    goto CPyL119;
CPyL134: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_sqrt_term);
    CPy_DecRef(cpy_r_r92);
    CPy_DecRef(cpy_r_r100);
    goto CPyL119;
CPyL135: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_sqrt_term);
    CPy_DecRef(cpy_r_r104);
    goto CPyL119;
CPyL136: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_sqrt_term);
    CPy_DecRef(cpy_r_Rs);
    goto CPyL119;
CPyL137: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_sqrt_term);
    CPy_DecRef(cpy_r_Rs);
    CPy_DecRef(cpy_r_r114);
    CPy_DecRef(cpy_r_r115);
    goto CPyL119;
CPyL138: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_sqrt_term);
    CPy_DecRef(cpy_r_Rs);
    CPy_DecRef(cpy_r_r114);
    goto CPyL119;
CPyL139: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_Rs);
    CPy_DecRef(cpy_r_r123);
    goto CPyL119;
CPyL140: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_Rs);
    CPy_DecRef(cpy_r_r123);
    CPy_DecRef(cpy_r_r125);
    CPy_DecRef(cpy_r_r126);
    goto CPyL119;
CPyL141: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_Rs);
    CPy_DecRef(cpy_r_r123);
    CPy_DecRef(cpy_r_r125);
    goto CPyL119;
CPyL142: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_Rs);
    CPy_DecRef(cpy_r_r123);
    goto CPyL119;
CPyL143: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_Rs);
    goto CPyL119;
CPyL144: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_Rs);
    CPy_DecRef(cpy_r_r135);
    goto CPyL119;
CPyL145: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_Rs);
    CPy_DecRef(cpy_r_Rp);
    goto CPyL119;
CPyL146: ;
    CPy_DecRef(cpy_r_u_r);
    CPy_DecRef(cpy_r_r149);
    goto CPyL119;
CPyL147: ;
    CPy_DECREF(cpy_r_u_r);
    goto CPyL82;
CPyL148: ;
    CPy_DecRef(cpy_r_r184);
    goto CPyL119;
CPyL149: ;
    CPy_DecRef(cpy_r_r184);
    CPy_DecRef(cpy_r_r192);
    goto CPyL119;
CPyL150: ;
    CPy_DecRef(cpy_r_theta_new);
    goto CPyL119;
CPyL151: ;
    CPy_DecRef(cpy_r_theta_new);
    CPy_DecRef(cpy_r_r206);
    goto CPyL119;
CPyL152: ;
    CPy_DecRef(cpy_r_theta_new);
    CPy_DecRef(cpy_r_r206);
    CPy_DecRef(cpy_r_r217);
    goto CPyL119;
CPyL153: ;
    CPy_DecRef(cpy_r_theta_new);
    CPy_DecRef(cpy_r_phi_new);
    goto CPyL119;
CPyL154: ;
    CPy_DecRef(cpy_r_theta_new);
    CPy_DecRef(cpy_r_phi_new);
    CPy_DecRef(cpy_r_r226);
    goto CPyL119;
CPyL155: ;
    CPy_DecRef(cpy_r_theta_new);
    CPy_DecRef(cpy_r_phi_new);
    CPy_DecRef(cpy_r_r233);
    goto CPyL119;
CPyL156: ;
    CPy_DecRef(cpy_r_theta_new);
    CPy_DecRef(cpy_r_phi_new);
    CPy_DecRef(cpy_r_r233);
    CPy_DecRef(cpy_r_r239);
    goto CPyL119;
CPyL157: ;
    CPy_DecRef(cpy_r_phi_new);
    CPy_DecRef(cpy_r_r233);
    goto CPyL119;
CPyL158: ;
    CPy_DecRef(cpy_r_phi_new);
    CPy_DecRef(cpy_r_r233);
    CPy_DecRef(cpy_r_r246);
    goto CPyL119;
CPyL159: ;
    CPy_DecRef(cpy_r_r233);
    CPy_DecRef(cpy_r_r246);
    CPy_DecRef(cpy_r_r252);
    goto CPyL119;
CPyL160: ;
    CPy_DecRef(cpy_r_r253);
    goto CPyL119;
}

PyObject *CPyPy_Simulation___photon_interaction(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"u", "n", 0};
    static CPyArg_Parser parser = {"OO:photon_interaction", kwlist, 0};
    PyObject *obj_u;
    PyObject *obj_n;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_u, &obj_n)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *arg_u = obj_u;
    PyObject *arg_n = obj_n;
    PyObject *retval = CPyDef_Simulation___photon_interaction(arg_self, arg_u, arg_n);
    return retval;
fail: ;
    CPy_AddTraceback("modTof.py", "photon_interaction", 198, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Simulation___n_vec_calculate(PyObject *cpy_r_self, PyObject *cpy_r_o, PyObject *cpy_r_scint_plane, PyObject *cpy_r_light_guide_planes, PyObject *cpy_r_corner_center, PyObject *cpy_r_corner_radius) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    int32_t cpy_r_r5;
    char cpy_r_r6;
    char cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    CPyPtr cpy_r_r12;
    CPyPtr cpy_r_r13;
    CPyPtr cpy_r_r14;
    CPyPtr cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject **cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    int32_t cpy_r_r27;
    char cpy_r_r28;
    char cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    CPyPtr cpy_r_r34;
    CPyPtr cpy_r_r35;
    CPyPtr cpy_r_r36;
    CPyPtr cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject **cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    int32_t cpy_r_r49;
    char cpy_r_r50;
    char cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    CPyPtr cpy_r_r61;
    CPyPtr cpy_r_r62;
    CPyPtr cpy_r_r63;
    CPyPtr cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject **cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    int32_t cpy_r_r76;
    char cpy_r_r77;
    char cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    CPyPtr cpy_r_r88;
    CPyPtr cpy_r_r89;
    CPyPtr cpy_r_r90;
    CPyPtr cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject **cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    int32_t cpy_r_r109;
    char cpy_r_r110;
    char cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    CPyPtr cpy_r_r118;
    CPyPtr cpy_r_r119;
    CPyPtr cpy_r_r120;
    CPyPtr cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject **cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    cpy_r_r0 = CPyStatics[257]; /* 2 */
    cpy_r_r1 = PyObject_GetItem(cpy_r_o, cpy_r_r0);
    if (unlikely(cpy_r_r1 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 221, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r2 = CPyStatics[244]; /* 0 */
    cpy_r_r3 = PyObject_GetItem(cpy_r_scint_plane, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 221, CPyStatic_globals);
        goto CPyL63;
    }
    cpy_r_r4 = PyObject_RichCompare(cpy_r_r1, cpy_r_r3, 2);
    CPy_DECREF(cpy_r_r1);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 221, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r5 = PyObject_IsTrue(cpy_r_r4);
    CPy_DECREF(cpy_r_r4);
    cpy_r_r6 = cpy_r_r5 >= 0;
    if (unlikely(!cpy_r_r6)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 221, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r7 = cpy_r_r5;
    if (!cpy_r_r7) goto CPyL9;
    cpy_r_r8 = CPyStatics[247]; /* 1 */
    cpy_r_r9 = PyList_New(3);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 222, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r10 = CPyStatics[244]; /* 0 */
    cpy_r_r11 = CPyStatics[244]; /* 0 */
    cpy_r_r12 = (CPyPtr)&((PyListObject *)cpy_r_r9)->ob_item;
    cpy_r_r13 = *(CPyPtr *)cpy_r_r12;
    CPy_INCREF(cpy_r_r10);
    *(PyObject * *)cpy_r_r13 = cpy_r_r10;
    cpy_r_r14 = cpy_r_r13 + 8;
    CPy_INCREF(cpy_r_r11);
    *(PyObject * *)cpy_r_r14 = cpy_r_r11;
    cpy_r_r15 = cpy_r_r13 + 16;
    CPy_INCREF(cpy_r_r8);
    *(PyObject * *)cpy_r_r15 = cpy_r_r8;
    cpy_r_r16 = CPyModule_numpy;
    cpy_r_r17 = CPyStatics[32]; /* 'array' */
    cpy_r_r18 = CPyObject_GetAttr(cpy_r_r16, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 222, CPyStatic_globals);
        goto CPyL64;
    }
    PyObject *cpy_r_r19[1] = {cpy_r_r9};
    cpy_r_r20 = (PyObject **)&cpy_r_r19;
    cpy_r_r21 = _PyObject_Vectorcall(cpy_r_r18, cpy_r_r20, 1, 0);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 222, CPyStatic_globals);
        goto CPyL64;
    }
    CPy_DECREF(cpy_r_r9);
    return cpy_r_r21;
CPyL9: ;
    cpy_r_r22 = CPyStatics[257]; /* 2 */
    cpy_r_r23 = PyObject_GetItem(cpy_r_o, cpy_r_r22);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 223, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r24 = CPyStatics[247]; /* 1 */
    cpy_r_r25 = PyObject_GetItem(cpy_r_scint_plane, cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 223, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r26 = PyObject_RichCompare(cpy_r_r23, cpy_r_r25, 2);
    CPy_DECREF(cpy_r_r23);
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 223, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r27 = PyObject_IsTrue(cpy_r_r26);
    CPy_DECREF(cpy_r_r26);
    cpy_r_r28 = cpy_r_r27 >= 0;
    if (unlikely(!cpy_r_r28)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 223, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r29 = cpy_r_r27;
    if (!cpy_r_r29) goto CPyL18;
    cpy_r_r30 = CPyStatics[260]; /* -1 */
    cpy_r_r31 = PyList_New(3);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 224, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r32 = CPyStatics[244]; /* 0 */
    cpy_r_r33 = CPyStatics[244]; /* 0 */
    cpy_r_r34 = (CPyPtr)&((PyListObject *)cpy_r_r31)->ob_item;
    cpy_r_r35 = *(CPyPtr *)cpy_r_r34;
    CPy_INCREF(cpy_r_r32);
    *(PyObject * *)cpy_r_r35 = cpy_r_r32;
    cpy_r_r36 = cpy_r_r35 + 8;
    CPy_INCREF(cpy_r_r33);
    *(PyObject * *)cpy_r_r36 = cpy_r_r33;
    cpy_r_r37 = cpy_r_r35 + 16;
    CPy_INCREF(cpy_r_r30);
    *(PyObject * *)cpy_r_r37 = cpy_r_r30;
    cpy_r_r38 = CPyModule_numpy;
    cpy_r_r39 = CPyStatics[32]; /* 'array' */
    cpy_r_r40 = CPyObject_GetAttr(cpy_r_r38, cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 224, CPyStatic_globals);
        goto CPyL66;
    }
    PyObject *cpy_r_r41[1] = {cpy_r_r31};
    cpy_r_r42 = (PyObject **)&cpy_r_r41;
    cpy_r_r43 = _PyObject_Vectorcall(cpy_r_r40, cpy_r_r42, 1, 0);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 224, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_DECREF(cpy_r_r31);
    return cpy_r_r43;
CPyL18: ;
    cpy_r_r44 = CPyStatics[244]; /* 0 */
    cpy_r_r45 = PyObject_GetItem(cpy_r_o, cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 225, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r46 = CPyStatics[244]; /* 0 */
    cpy_r_r47 = PyObject_GetItem(cpy_r_light_guide_planes, cpy_r_r46);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 225, CPyStatic_globals);
        goto CPyL67;
    }
    cpy_r_r48 = PyObject_RichCompare(cpy_r_r45, cpy_r_r47, 2);
    CPy_DECREF(cpy_r_r45);
    CPy_DECREF(cpy_r_r47);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 225, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r49 = PyObject_IsTrue(cpy_r_r48);
    CPy_DECREF(cpy_r_r48);
    cpy_r_r50 = cpy_r_r49 >= 0;
    if (unlikely(!cpy_r_r50)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 225, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r51 = cpy_r_r49;
    if (!cpy_r_r51) goto CPyL31;
    cpy_r_r52 = CPyStatics[244]; /* 0 */
    cpy_r_r53 = PyObject_GetItem(cpy_r_light_guide_planes, cpy_r_r52);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 226, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r54 = CPyStatics[244]; /* 0 */
    cpy_r_r55 = PyObject_GetItem(cpy_r_light_guide_planes, cpy_r_r54);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 226, CPyStatic_globals);
        goto CPyL68;
    }
    cpy_r_r56 = PyNumber_Absolute(cpy_r_r55);
    CPy_DECREF(cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 226, CPyStatic_globals);
        goto CPyL68;
    }
    cpy_r_r57 = PyNumber_TrueDivide(cpy_r_r53, cpy_r_r56);
    CPy_DECREF(cpy_r_r53);
    CPy_DECREF(cpy_r_r56);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 226, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r58 = PyList_New(3);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 226, CPyStatic_globals);
        goto CPyL69;
    }
    cpy_r_r59 = CPyStatics[244]; /* 0 */
    cpy_r_r60 = CPyStatics[244]; /* 0 */
    cpy_r_r61 = (CPyPtr)&((PyListObject *)cpy_r_r58)->ob_item;
    cpy_r_r62 = *(CPyPtr *)cpy_r_r61;
    CPy_INCREF(cpy_r_r59);
    *(PyObject * *)cpy_r_r62 = cpy_r_r59;
    cpy_r_r63 = cpy_r_r62 + 8;
    *(PyObject * *)cpy_r_r63 = cpy_r_r57;
    cpy_r_r64 = cpy_r_r62 + 16;
    CPy_INCREF(cpy_r_r60);
    *(PyObject * *)cpy_r_r64 = cpy_r_r60;
    cpy_r_r65 = CPyModule_numpy;
    cpy_r_r66 = CPyStatics[32]; /* 'array' */
    cpy_r_r67 = CPyObject_GetAttr(cpy_r_r65, cpy_r_r66);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 226, CPyStatic_globals);
        goto CPyL70;
    }
    PyObject *cpy_r_r68[1] = {cpy_r_r58};
    cpy_r_r69 = (PyObject **)&cpy_r_r68;
    cpy_r_r70 = _PyObject_Vectorcall(cpy_r_r67, cpy_r_r69, 1, 0);
    CPy_DECREF(cpy_r_r67);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 226, CPyStatic_globals);
        goto CPyL70;
    }
    CPy_DECREF(cpy_r_r58);
    return cpy_r_r70;
CPyL31: ;
    cpy_r_r71 = CPyStatics[247]; /* 1 */
    cpy_r_r72 = PyObject_GetItem(cpy_r_o, cpy_r_r71);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 227, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r73 = CPyStatics[247]; /* 1 */
    cpy_r_r74 = PyObject_GetItem(cpy_r_light_guide_planes, cpy_r_r73);
    if (unlikely(cpy_r_r74 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 227, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r75 = PyObject_RichCompare(cpy_r_r72, cpy_r_r74, 2);
    CPy_DECREF(cpy_r_r72);
    CPy_DECREF(cpy_r_r74);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 227, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r76 = PyObject_IsTrue(cpy_r_r75);
    CPy_DECREF(cpy_r_r75);
    cpy_r_r77 = cpy_r_r76 >= 0;
    if (unlikely(!cpy_r_r77)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 227, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r78 = cpy_r_r76;
    if (!cpy_r_r78) goto CPyL44;
    cpy_r_r79 = CPyStatics[247]; /* 1 */
    cpy_r_r80 = PyObject_GetItem(cpy_r_light_guide_planes, cpy_r_r79);
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 228, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r81 = CPyStatics[247]; /* 1 */
    cpy_r_r82 = PyObject_GetItem(cpy_r_light_guide_planes, cpy_r_r81);
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 228, CPyStatic_globals);
        goto CPyL72;
    }
    cpy_r_r83 = PyNumber_Absolute(cpy_r_r82);
    CPy_DECREF(cpy_r_r82);
    if (unlikely(cpy_r_r83 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 228, CPyStatic_globals);
        goto CPyL72;
    }
    cpy_r_r84 = PyNumber_TrueDivide(cpy_r_r80, cpy_r_r83);
    CPy_DECREF(cpy_r_r80);
    CPy_DECREF(cpy_r_r83);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 228, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r85 = PyList_New(3);
    if (unlikely(cpy_r_r85 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 228, CPyStatic_globals);
        goto CPyL73;
    }
    cpy_r_r86 = CPyStatics[244]; /* 0 */
    cpy_r_r87 = CPyStatics[244]; /* 0 */
    cpy_r_r88 = (CPyPtr)&((PyListObject *)cpy_r_r85)->ob_item;
    cpy_r_r89 = *(CPyPtr *)cpy_r_r88;
    *(PyObject * *)cpy_r_r89 = cpy_r_r84;
    cpy_r_r90 = cpy_r_r89 + 8;
    CPy_INCREF(cpy_r_r86);
    *(PyObject * *)cpy_r_r90 = cpy_r_r86;
    cpy_r_r91 = cpy_r_r89 + 16;
    CPy_INCREF(cpy_r_r87);
    *(PyObject * *)cpy_r_r91 = cpy_r_r87;
    cpy_r_r92 = CPyModule_numpy;
    cpy_r_r93 = CPyStatics[32]; /* 'array' */
    cpy_r_r94 = CPyObject_GetAttr(cpy_r_r92, cpy_r_r93);
    if (unlikely(cpy_r_r94 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 228, CPyStatic_globals);
        goto CPyL74;
    }
    PyObject *cpy_r_r95[1] = {cpy_r_r85};
    cpy_r_r96 = (PyObject **)&cpy_r_r95;
    cpy_r_r97 = _PyObject_Vectorcall(cpy_r_r94, cpy_r_r96, 1, 0);
    CPy_DECREF(cpy_r_r94);
    if (unlikely(cpy_r_r97 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 228, CPyStatic_globals);
        goto CPyL74;
    }
    CPy_DECREF(cpy_r_r85);
    return cpy_r_r97;
CPyL44: ;
    cpy_r_r98 = CPyStatics[244]; /* 0 */
    cpy_r_r99 = PyObject_GetItem(cpy_r_o, cpy_r_r98);
    if (unlikely(cpy_r_r99 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 229, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r100 = CPyStatics[244]; /* 0 */
    cpy_r_r101 = PyObject_GetItem(cpy_r_corner_center, cpy_r_r100);
    if (unlikely(cpy_r_r101 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 229, CPyStatic_globals);
        goto CPyL75;
    }
    cpy_r_r102 = PyObject_RichCompare(cpy_r_r99, cpy_r_r101, 5);
    CPy_DECREF(cpy_r_r99);
    CPy_DECREF(cpy_r_r101);
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 229, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r103 = CPyStatics[247]; /* 1 */
    cpy_r_r104 = PyObject_GetItem(cpy_r_o, cpy_r_r103);
    if (unlikely(cpy_r_r104 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 229, CPyStatic_globals);
        goto CPyL76;
    }
    cpy_r_r105 = CPyStatics[247]; /* 1 */
    cpy_r_r106 = PyObject_GetItem(cpy_r_corner_center, cpy_r_r105);
    if (unlikely(cpy_r_r106 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 229, CPyStatic_globals);
        goto CPyL77;
    }
    cpy_r_r107 = PyObject_RichCompare(cpy_r_r104, cpy_r_r106, 1);
    CPy_DECREF(cpy_r_r104);
    CPy_DECREF(cpy_r_r106);
    if (unlikely(cpy_r_r107 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 229, CPyStatic_globals);
        goto CPyL76;
    }
    cpy_r_r108 = PyNumber_And(cpy_r_r102, cpy_r_r107);
    CPy_DECREF(cpy_r_r102);
    CPy_DECREF(cpy_r_r107);
    if (unlikely(cpy_r_r108 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 229, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r109 = PyObject_IsTrue(cpy_r_r108);
    CPy_DECREF(cpy_r_r108);
    cpy_r_r110 = cpy_r_r109 >= 0;
    if (unlikely(!cpy_r_r110)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 229, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r111 = cpy_r_r109;
    if (!cpy_r_r111) goto CPyL56;
    cpy_r_r112 = PyNumber_Subtract(cpy_r_o, cpy_r_corner_center);
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 230, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r113 = CPyDef_Simulation___normalize(cpy_r_self, cpy_r_r112);
    CPy_DECREF(cpy_r_r112);
    if (unlikely(cpy_r_r113 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 230, CPyStatic_globals);
        goto CPyL62;
    }
    return cpy_r_r113;
CPyL56: ;
    cpy_r_r114 = PyList_New(3);
    if (unlikely(cpy_r_r114 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 232, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r115 = CPyStatics[244]; /* 0 */
    cpy_r_r116 = CPyStatics[244]; /* 0 */
    cpy_r_r117 = CPyStatics[244]; /* 0 */
    cpy_r_r118 = (CPyPtr)&((PyListObject *)cpy_r_r114)->ob_item;
    cpy_r_r119 = *(CPyPtr *)cpy_r_r118;
    CPy_INCREF(cpy_r_r115);
    *(PyObject * *)cpy_r_r119 = cpy_r_r115;
    cpy_r_r120 = cpy_r_r119 + 8;
    CPy_INCREF(cpy_r_r116);
    *(PyObject * *)cpy_r_r120 = cpy_r_r116;
    cpy_r_r121 = cpy_r_r119 + 16;
    CPy_INCREF(cpy_r_r117);
    *(PyObject * *)cpy_r_r121 = cpy_r_r117;
    cpy_r_r122 = CPyModule_numpy;
    cpy_r_r123 = CPyStatics[32]; /* 'array' */
    cpy_r_r124 = CPyObject_GetAttr(cpy_r_r122, cpy_r_r123);
    if (unlikely(cpy_r_r124 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 232, CPyStatic_globals);
        goto CPyL78;
    }
    PyObject *cpy_r_r125[1] = {cpy_r_r114};
    cpy_r_r126 = (PyObject **)&cpy_r_r125;
    cpy_r_r127 = _PyObject_Vectorcall(cpy_r_r124, cpy_r_r126, 1, 0);
    CPy_DECREF(cpy_r_r124);
    if (unlikely(cpy_r_r127 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 232, CPyStatic_globals);
        goto CPyL78;
    }
    CPy_DECREF(cpy_r_r114);
    cpy_r_r128 = PyNumber_Subtract(cpy_r_o, cpy_r_r127);
    CPy_DECREF(cpy_r_r127);
    if (unlikely(cpy_r_r128 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 232, CPyStatic_globals);
        goto CPyL62;
    }
    cpy_r_r129 = CPyDef_Simulation___normalize(cpy_r_self, cpy_r_r128);
    CPy_DECREF(cpy_r_r128);
    if (unlikely(cpy_r_r129 == NULL)) {
        CPy_AddTraceback("modTof.py", "n_vec_calculate", 232, CPyStatic_globals);
        goto CPyL62;
    }
    return cpy_r_r129;
CPyL62: ;
    cpy_r_r130 = NULL;
    return cpy_r_r130;
CPyL63: ;
    CPy_DecRef(cpy_r_r1);
    goto CPyL62;
CPyL64: ;
    CPy_DecRef(cpy_r_r9);
    goto CPyL62;
CPyL65: ;
    CPy_DecRef(cpy_r_r23);
    goto CPyL62;
CPyL66: ;
    CPy_DecRef(cpy_r_r31);
    goto CPyL62;
CPyL67: ;
    CPy_DecRef(cpy_r_r45);
    goto CPyL62;
CPyL68: ;
    CPy_DecRef(cpy_r_r53);
    goto CPyL62;
CPyL69: ;
    CPy_DecRef(cpy_r_r57);
    goto CPyL62;
CPyL70: ;
    CPy_DecRef(cpy_r_r58);
    goto CPyL62;
CPyL71: ;
    CPy_DecRef(cpy_r_r72);
    goto CPyL62;
CPyL72: ;
    CPy_DecRef(cpy_r_r80);
    goto CPyL62;
CPyL73: ;
    CPy_DecRef(cpy_r_r84);
    goto CPyL62;
CPyL74: ;
    CPy_DecRef(cpy_r_r85);
    goto CPyL62;
CPyL75: ;
    CPy_DecRef(cpy_r_r99);
    goto CPyL62;
CPyL76: ;
    CPy_DecRef(cpy_r_r102);
    goto CPyL62;
CPyL77: ;
    CPy_DecRef(cpy_r_r102);
    CPy_DecRef(cpy_r_r104);
    goto CPyL62;
CPyL78: ;
    CPy_DecRef(cpy_r_r114);
    goto CPyL62;
}

PyObject *CPyPy_Simulation___n_vec_calculate(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"o", "scint_plane", "light_guide_planes", "corner_center", "corner_radius", 0};
    static CPyArg_Parser parser = {"OOOOO:n_vec_calculate", kwlist, 0};
    PyObject *obj_o;
    PyObject *obj_scint_plane;
    PyObject *obj_light_guide_planes;
    PyObject *obj_corner_center;
    PyObject *obj_corner_radius;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_o, &obj_scint_plane, &obj_light_guide_planes, &obj_corner_center, &obj_corner_radius)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *arg_o = obj_o;
    PyObject *arg_scint_plane = obj_scint_plane;
    PyObject *arg_light_guide_planes = obj_light_guide_planes;
    PyObject *arg_corner_center = obj_corner_center;
    PyObject *arg_corner_radius = obj_corner_radius;
    PyObject *retval = CPyDef_Simulation___n_vec_calculate(arg_self, arg_o, arg_scint_plane, arg_light_guide_planes, arg_corner_center, arg_corner_radius);
    return retval;
fail: ;
    CPy_AddTraceback("modTof.py", "n_vec_calculate", 220, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Simulation___particle_path(PyObject *cpy_r_self, PyObject *cpy_r_t, PyObject *cpy_r_phi_range_deg, PyObject *cpy_r_T1_z, PyObject *cpy_r_T1_width, PyObject *cpy_r_T4_z, PyObject *cpy_r_T4_width, PyObject *cpy_r_T1_radius, PyObject *cpy_r_T4_radius, PyObject *cpy_r_T1_corner, PyObject *cpy_r_T4_corner, PyObject *cpy_r_mean_free_path, PyObject *cpy_r_photons_per_E, PyObject *cpy_r_prob_scint) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    double cpy_r_r3;
    char cpy_r_r4;
    double cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject **cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_theta;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    double cpy_r_r18;
    char cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    double cpy_r_r24;
    char cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    double cpy_r_r38;
    char cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    double cpy_r_r44;
    char cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject **cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_phi;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_maxdist;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_round_const;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject **cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject **cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    tuple_T3OOO cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject **cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_o;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject **cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject **cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject **cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject **cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject **cpy_r_r123;
    PyObject *cpy_r_r124;
    tuple_T3OOO cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject *cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject **cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject *cpy_r_r136;
    PyObject *cpy_r_u;
    PyObject *cpy_r_r137;
    PyObject *cpy_r_r138;
    CPyPtr cpy_r_r139;
    CPyPtr cpy_r_r140;
    PyObject *cpy_r_photons;
    PyObject *cpy_r_r141;
    CPyPtr cpy_r_r142;
    CPyPtr cpy_r_r143;
    PyObject *cpy_r_points;
    PyObject *cpy_r_r144;
    CPyPtr cpy_r_r145;
    CPyPtr cpy_r_r146;
    PyObject *cpy_r_times;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject *cpy_r_cur_o;
    PyObject *cpy_r_r149;
    PyObject *cpy_r_r150;
    PyObject *cpy_r_r151;
    PyObject *cpy_r_r152;
    PyObject *cpy_r_next_o;
    PyObject *cpy_r_r153;
    PyObject *cpy_r_inside_scint;
    PyObject *cpy_r_r154;
    PyObject *cpy_r_missed;
    PyObject *cpy_r_r155;
    PyObject *cpy_r_r156;
    PyObject *cpy_r_r157;
    int32_t cpy_r_r158;
    char cpy_r_r159;
    char cpy_r_r160;
    int32_t cpy_r_r161;
    char cpy_r_r162;
    char cpy_r_r163;
    int32_t cpy_r_r164;
    char cpy_r_r165;
    char cpy_r_r166;
    PyObject *cpy_r_r167;
    PyObject *cpy_r_r168;
    PyObject *cpy_r_r169;
    double cpy_r_r170;
    char cpy_r_r171;
    double cpy_r_r172;
    PyObject *cpy_r_r173;
    PyObject *cpy_r_r174;
    PyObject *cpy_r_r175;
    PyObject *cpy_r_r176;
    PyObject *cpy_r_r177;
    PyObject *cpy_r_r178;
    PyObject **cpy_r_r180;
    PyObject *cpy_r_r181;
    PyObject *cpy_r_r182;
    PyObject *cpy_r_r183;
    PyObject *cpy_r_r184;
    double cpy_r_r185;
    char cpy_r_r186;
    PyObject *cpy_r_r187;
    PyObject *cpy_r_r188;
    PyObject *cpy_r_r189;
    PyObject *cpy_r_r190;
    double cpy_r_r191;
    char cpy_r_r192;
    PyObject *cpy_r_r193;
    PyObject *cpy_r_r194;
    PyObject *cpy_r_r195;
    PyObject *cpy_r_r196;
    PyObject *cpy_r_r197;
    PyObject *cpy_r_r198;
    PyObject *cpy_r_r199;
    PyObject *cpy_r_r200;
    PyObject *cpy_r_r201;
    PyObject *cpy_r_r202;
    PyObject *cpy_r_r203;
    PyObject *cpy_r_r204;
    double cpy_r_r205;
    char cpy_r_r206;
    PyObject *cpy_r_r207;
    PyObject *cpy_r_r208;
    PyObject *cpy_r_r209;
    PyObject *cpy_r_r210;
    double cpy_r_r211;
    char cpy_r_r212;
    PyObject *cpy_r_r213;
    PyObject *cpy_r_r214;
    PyObject *cpy_r_r215;
    PyObject *cpy_r_r216;
    PyObject *cpy_r_r217;
    PyObject *cpy_r_r218;
    PyObject *cpy_r_r219;
    PyObject *cpy_r_r220;
    PyObject *cpy_r_r221;
    PyObject *cpy_r_r222;
    PyObject *cpy_r_r223;
    PyObject *cpy_r_r224;
    PyObject **cpy_r_r226;
    PyObject *cpy_r_r227;
    PyObject *cpy_r_r228;
    PyObject *cpy_r_r229;
    PyObject *cpy_r_r230;
    PyObject *cpy_r_r231;
    PyObject *cpy_r_r232;
    PyObject *cpy_r_r233;
    PyObject *cpy_r_r234;
    PyObject *cpy_r_r235;
    PyObject *cpy_r_r236;
    PyObject *cpy_r_r237;
    PyObject *cpy_r_r238;
    PyObject *cpy_r_r239;
    PyObject *cpy_r_r240;
    PyObject **cpy_r_r242;
    PyObject *cpy_r_r243;
    PyObject *cpy_r_r244;
    PyObject *cpy_r_r245;
    PyObject *cpy_r_r246;
    PyObject *cpy_r_r247;
    PyObject **cpy_r_r249;
    PyObject *cpy_r_r250;
    PyObject *cpy_r_r251;
    PyObject *cpy_r_r252;
    PyObject *cpy_r_r253;
    PyObject *cpy_r_r254;
    tuple_T3OOO cpy_r_r255;
    PyObject *cpy_r_r256;
    PyObject *cpy_r_r257;
    PyObject *cpy_r_r258;
    PyObject *cpy_r_r259;
    PyObject **cpy_r_r261;
    PyObject *cpy_r_r262;
    PyObject *cpy_r_r263;
    PyObject *cpy_r_r264;
    PyObject *cpy_r_r265;
    PyObject **cpy_r_r267;
    PyObject *cpy_r_r268;
    PyObject *cpy_r_r269;
    PyObject *cpy_r_r270;
    PyObject *cpy_r_r271;
    PyObject **cpy_r_r273;
    PyObject *cpy_r_r274;
    PyObject *cpy_r_r275;
    PyObject *cpy_r_r276;
    PyObject *cpy_r_r277;
    PyObject *cpy_r_r278;
    PyObject **cpy_r_r280;
    PyObject *cpy_r_r281;
    PyObject *cpy_r_r282;
    PyObject *cpy_r_r283;
    PyObject *cpy_r_r284;
    PyObject **cpy_r_r286;
    PyObject *cpy_r_r287;
    PyObject *cpy_r_r288;
    PyObject *cpy_r_r289;
    PyObject *cpy_r_r290;
    PyObject *cpy_r_r291;
    PyObject **cpy_r_r293;
    PyObject *cpy_r_r294;
    tuple_T3OOO cpy_r_r295;
    PyObject *cpy_r_r296;
    PyObject *cpy_r_r297;
    PyObject *cpy_r_r298;
    PyObject *cpy_r_r299;
    PyObject *cpy_r_r300;
    PyObject *cpy_r_r301;
    PyObject *cpy_r_r302;
    PyObject **cpy_r_r304;
    PyObject *cpy_r_r305;
    PyObject *cpy_r_r306;
    PyObject *cpy_r_r307;
    PyObject *cpy_r_r308;
    PyObject *cpy_r_r309;
    PyObject *cpy_r_r310;
    PyObject *cpy_r_r311;
    PyObject *cpy_r_r312;
    PyObject *cpy_r_r313;
    PyObject *cpy_r_r314;
    CPyPtr cpy_r_r315;
    CPyPtr cpy_r_r316;
    PyObject *cpy_r_r317;
    CPyPtr cpy_r_r318;
    CPyPtr cpy_r_r319;
    PyObject *cpy_r_r320;
    CPyPtr cpy_r_r321;
    CPyPtr cpy_r_r322;
    PyObject *cpy_r_r323;
    PyObject *cpy_r_r324;
    PyObject *cpy_r_r325;
    PyObject *cpy_r_r326;
    PyObject *cpy_r_r327;
    PyObject *cpy_r_r328;
    PyObject *cpy_r_r329;
    PyObject *cpy_r_r330;
    PyObject *cpy_r_r331;
    PyObject *cpy_r_r332;
    PyObject *cpy_r_r333;
    PyObject *cpy_r_r334;
    PyObject *cpy_r_r335;
    PyObject *cpy_r_r336;
    PyObject *cpy_r_r337;
    PyObject *cpy_r_r338;
    PyObject *cpy_r_r339;
    PyObject **cpy_r_r341;
    PyObject *cpy_r_r342;
    PyObject *cpy_r_distT1;
    PyObject *cpy_r_r343;
    PyObject *cpy_r_r344;
    PyObject *cpy_r_r345;
    PyObject *cpy_r_r346;
    PyObject *cpy_r_r347;
    PyObject *cpy_r_r348;
    PyObject *cpy_r_r349;
    PyObject *cpy_r_r350;
    PyObject *cpy_r_r351;
    PyObject *cpy_r_r352;
    PyObject **cpy_r_r354;
    PyObject *cpy_r_r355;
    PyObject *cpy_r_distT4;
    PyObject *cpy_r_r356;
    PyObject *cpy_r_r357;
    PyObject *cpy_r_r358;
    int32_t cpy_r_r359;
    char cpy_r_r360;
    char cpy_r_r361;
    PyObject *cpy_r_r362;
    PyObject *cpy_r_dist;
    PyObject *cpy_r_r363;
    PyObject *cpy_r_r364;
    PyObject *cpy_r_r365;
    PyObject *cpy_r_r366;
    PyObject *cpy_r_check;
    PyObject *cpy_r_r367;
    PyObject *cpy_r_r368;
    PyObject *cpy_r_r369;
    PyObject *cpy_r_r370;
    PyObject *cpy_r_r371;
    PyObject *cpy_r_inside_T1;
    PyObject *cpy_r_r372;
    PyObject *cpy_r_r373;
    PyObject *cpy_r_r374;
    PyObject *cpy_r_r375;
    PyObject *cpy_r_r376;
    PyObject *cpy_r_inside_T4;
    PyObject *cpy_r_r377;
    PyObject *cpy_r_r378;
    PyObject *cpy_r_r379;
    int32_t cpy_r_r380;
    char cpy_r_r381;
    char cpy_r_r382;
    PyObject *cpy_r_r383;
    PyObject *cpy_r_scint_cond;
    int32_t cpy_r_r384;
    char cpy_r_r385;
    char cpy_r_r386;
    PyObject *cpy_r_r387;
    PyObject *cpy_r_r388;
    PyObject *cpy_r_r389;
    PyObject *cpy_r_r390;
    PyObject *cpy_r_r391;
    PyObject *cpy_r_r392;
    PyObject *cpy_r_r393;
    PyObject *cpy_r_r394;
    PyObject *cpy_r_r395;
    PyObject *cpy_r_r396;
    PyObject *cpy_r_r397;
    PyObject *cpy_r_r398;
    PyObject *cpy_r_r399;
    PyObject *cpy_r_r400;
    PyObject *cpy_r_r401;
    PyObject *cpy_r_r402;
    PyObject *cpy_r_r403;
    PyObject *cpy_r_r404;
    PyObject **cpy_r_r406;
    PyObject *cpy_r_r407;
    PyObject *cpy_r_phot;
    PyObject *cpy_r_r408;
    PyObject *cpy_r_r409;
    PyObject *cpy_r_r410;
    PyObject *cpy_r_r411;
    PyObject *cpy_r_r412;
    PyObject *cpy_r_r413;
    PyObject *cpy_r_r414;
    int32_t cpy_r_r415;
    char cpy_r_r416;
    char cpy_r_r417;
    PyObject *cpy_r_r418;
    PyObject *cpy_r_r419;
    PyObject *cpy_r_r420;
    PyObject *cpy_r_r421;
    PyObject *cpy_r_r422;
    PyObject *cpy_r_r423;
    PyObject *cpy_r_r424;
    PyObject *cpy_r_r425;
    PyObject *cpy_r_r426;
    PyObject *cpy_r_r427;
    PyObject *cpy_r_r428;
    PyObject *cpy_r_r429;
    PyObject *cpy_r_r430;
    PyObject *cpy_r_r431;
    PyObject *cpy_r_r432;
    PyObject *cpy_r_r433;
    tuple_T5OOOOO cpy_r_r434;
    PyObject *cpy_r_r435;
    PyObject *cpy_r_r436;
    tuple_T5OOOOO cpy_r_r437;
    PyObject *cpy_r_r438;
    PyObject *cpy_r_r439;
    PyObject *cpy_r_r440;
    CPyPtr cpy_r_r441;
    CPyPtr cpy_r_r442;
    CPyPtr cpy_r_r443;
    CPyTagged cpy_r_r444;
    CPyPtr cpy_r_r445;
    int64_t cpy_r_r446;
    CPyTagged cpy_r_r447;
    char cpy_r_r448;
    PyObject *cpy_r_r449;
    PyObject *cpy_r_r450;
    PyObject *cpy_r_r451;
    char cpy_r_r452;
    PyObject *cpy_r_Tbottom;
    PyObject *cpy_r_r453;
    char cpy_r_r454;
    PyObject *cpy_r_Ttop;
    PyObject *cpy_r_r455;
    char cpy_r_r456;
    PyObject *cpy_r_Tradius;
    PyObject *cpy_r_r457;
    char cpy_r_r458;
    PyObject *cpy_r_Tcorner;
    PyObject *cpy_r_r459;
    char cpy_r_r460;
    PyObject *cpy_r_num;
    PyObject *cpy_r_r461;
    char cpy_r_r462;
    PyObject *cpy_r_r463;
    PyObject *cpy_r_r464;
    PyObject *cpy_r_r465;
    PyObject *cpy_r_r466;
    PyObject *cpy_r_r467;
    PyObject *cpy_r_r468;
    PyObject *cpy_r_r469;
    PyObject *cpy_r_r470;
    PyObject *cpy_r_r471;
    PyObject *cpy_r_r472;
    PyObject *cpy_r_r473;
    int32_t cpy_r_r474;
    char cpy_r_r475;
    char cpy_r_r476;
    PyObject *cpy_r_r477;
    PyObject *cpy_r_r478;
    PyObject *cpy_r_r479;
    PyObject *cpy_r_r480;
    PyObject *cpy_r_r481;
    PyObject *cpy_r_r482;
    PyObject *cpy_r_r483;
    PyObject *cpy_r_r484;
    PyObject *cpy_r_r485;
    PyObject *cpy_r_r486;
    PyObject *cpy_r_r487;
    PyObject *cpy_r_r488;
    PyObject *cpy_r_r489;
    PyObject *cpy_r_r490;
    PyObject **cpy_r_r492;
    PyObject *cpy_r_r493;
    PyObject *cpy_r_r494;
    PyObject *cpy_r_r495;
    PyObject *cpy_r_r496;
    PyObject *cpy_r_r497;
    PyObject *cpy_r_r498;
    PyObject *cpy_r_r499;
    PyObject *cpy_r_r500;
    int32_t cpy_r_r501;
    char cpy_r_r502;
    char cpy_r_r503;
    PyObject *cpy_r_r504;
    PyObject *cpy_r_r505;
    PyObject *cpy_r_r506;
    PyObject *cpy_r_r507;
    PyObject *cpy_r_r508;
    PyObject *cpy_r_r509;
    PyObject *cpy_r_r510;
    PyObject *cpy_r_r511;
    PyObject *cpy_r_r512;
    PyObject *cpy_r_r513;
    PyObject *cpy_r_r514;
    PyObject *cpy_r_r515;
    PyObject *cpy_r_r516;
    PyObject *cpy_r_r517;
    PyObject *cpy_r_r518;
    PyObject *cpy_r_r519;
    PyObject *cpy_r_r520;
    PyObject *cpy_r_r521;
    PyObject *cpy_r_r522;
    PyObject *cpy_r_r523;
    PyObject *cpy_r_r524;
    PyObject *cpy_r_r525;
    CPyTagged cpy_r_r526;
    PyObject *cpy_r_r527;
    PyObject *cpy_r_r528;
    PyObject *cpy_r_r529;
    PyObject *cpy_r_r530;
    PyObject *cpy_r_r531;
    PyObject *cpy_r_r532;
    PyObject **cpy_r_r534;
    PyObject *cpy_r_r535;
    PyObject *cpy_r_r536;
    PyObject *cpy_r_r537;
    PyObject *cpy_r_r538;
    PyObject *cpy_r_r539;
    PyObject *cpy_r_r540;
    PyObject *cpy_r_r541;
    PyObject *cpy_r_r542;
    PyObject *cpy_r_r543;
    PyObject *cpy_r_r544;
    PyObject *cpy_r_r545;
    PyObject *cpy_r_r546;
    PyObject *cpy_r_r547;
    PyObject **cpy_r_r549;
    PyObject *cpy_r_r550;
    PyObject *cpy_r_r551;
    PyObject *cpy_r_r552;
    PyObject *cpy_r_r553;
    PyObject *cpy_r_r554;
    PyObject *cpy_r_r555;
    PyObject *cpy_r_r556;
    PyObject *cpy_r_r557;
    PyObject *cpy_r_r558;
    PyObject *cpy_r_r559;
    PyObject *cpy_r_r560;
    PyObject *cpy_r_r561;
    PyObject *cpy_r_r562;
    PyObject *cpy_r_r563;
    PyObject *cpy_r_r564;
    PyObject *cpy_r_r565;
    PyObject *cpy_r_r566;
    PyObject *cpy_r_r567;
    PyObject **cpy_r_r569;
    PyObject *cpy_r_r570;
    PyObject *cpy_r_r571;
    tuple_T3OOO cpy_r_r572;
    PyObject *cpy_r_r573;
    PyObject *cpy_r_r574;
    cpy_r_r0 = CPyModule_numpy;
    cpy_r_r1 = CPyStatics[37]; /* 'pi' */
    cpy_r_r2 = CPyObject_GetAttr(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 251, CPyStatic_globals);
        goto CPyL287;
    }
    cpy_r_r3 = PyFloat_AsDouble(cpy_r_r2);
    if (cpy_r_r3 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r2); cpy_r_r3 = -113.0;
    }
    CPy_DECREF(cpy_r_r2);
    cpy_r_r4 = cpy_r_r3 == -113.0;
    if (unlikely(cpy_r_r4)) goto CPyL3;
CPyL2: ;
    cpy_r_r5 = 2.0 * cpy_r_r3;
    cpy_r_r6 = PyFloat_FromDouble(cpy_r_r5);
    cpy_r_r7 = CPyModule_random;
    cpy_r_r8 = CPyStatics[38]; /* 'uniform' */
    cpy_r_r9 = CPyObject_GetAttr(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 251, CPyStatic_globals);
        goto CPyL288;
    } else
        goto CPyL4;
CPyL3: ;
    cpy_r_r10 = PyErr_Occurred();
    if (unlikely(cpy_r_r10 != NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 251, CPyStatic_globals);
        goto CPyL287;
    } else
        goto CPyL2;
CPyL4: ;
    cpy_r_r11 = CPyStatics[244]; /* 0 */
    PyObject *cpy_r_r12[2] = {cpy_r_r11, cpy_r_r6};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = _PyObject_Vectorcall(cpy_r_r9, cpy_r_r13, 2, 0);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 251, CPyStatic_globals);
        goto CPyL288;
    }
    CPy_DECREF(cpy_r_r6);
    cpy_r_theta = cpy_r_r14;
    cpy_r_r15 = CPyModule_numpy;
    cpy_r_r16 = CPyStatics[37]; /* 'pi' */
    cpy_r_r17 = CPyObject_GetAttr(cpy_r_r15, cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 252, CPyStatic_globals);
        goto CPyL289;
    }
    cpy_r_r18 = PyFloat_AsDouble(cpy_r_r17);
    if (cpy_r_r18 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r17); cpy_r_r18 = -113.0;
    }
    CPy_DECREF(cpy_r_r17);
    cpy_r_r19 = cpy_r_r18 == -113.0;
    if (unlikely(cpy_r_r19)) goto CPyL8;
CPyL7: ;
    cpy_r_r20 = CPyModule_numpy;
    cpy_r_r21 = CPyStatics[37]; /* 'pi' */
    cpy_r_r22 = CPyObject_GetAttr(cpy_r_r20, cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 252, CPyStatic_globals);
        goto CPyL289;
    } else
        goto CPyL9;
CPyL8: ;
    cpy_r_r23 = PyErr_Occurred();
    if (unlikely(cpy_r_r23 != NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 252, CPyStatic_globals);
        goto CPyL289;
    } else
        goto CPyL7;
CPyL9: ;
    cpy_r_r24 = PyFloat_AsDouble(cpy_r_r22);
    if (cpy_r_r24 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r22); cpy_r_r24 = -113.0;
    }
    CPy_DECREF(cpy_r_r22);
    cpy_r_r25 = cpy_r_r24 == -113.0;
    if (unlikely(cpy_r_r25)) goto CPyL11;
CPyL10: ;
    cpy_r_r26 = PyFloat_FromDouble(cpy_r_r24);
    cpy_r_r27 = PyNumber_Multiply(cpy_r_phi_range_deg, cpy_r_r26);
    CPy_DECREF(cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 252, CPyStatic_globals);
        goto CPyL289;
    } else
        goto CPyL12;
CPyL11: ;
    cpy_r_r28 = PyErr_Occurred();
    if (unlikely(cpy_r_r28 != NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 252, CPyStatic_globals);
        goto CPyL289;
    } else
        goto CPyL10;
CPyL12: ;
    cpy_r_r29 = CPyStatics[261]; /* 180 */
    cpy_r_r30 = PyNumber_TrueDivide(cpy_r_r27, cpy_r_r29);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 252, CPyStatic_globals);
        goto CPyL289;
    }
    cpy_r_r31 = CPyStatics[257]; /* 2 */
    cpy_r_r32 = PyNumber_TrueDivide(cpy_r_r30, cpy_r_r31);
    CPy_DECREF(cpy_r_r30);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 252, CPyStatic_globals);
        goto CPyL289;
    }
    cpy_r_r33 = PyFloat_FromDouble(cpy_r_r18);
    cpy_r_r34 = PyNumber_Subtract(cpy_r_r33, cpy_r_r32);
    CPy_DECREF(cpy_r_r33);
    CPy_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 252, CPyStatic_globals);
        goto CPyL289;
    }
    cpy_r_r35 = CPyModule_numpy;
    cpy_r_r36 = CPyStatics[37]; /* 'pi' */
    cpy_r_r37 = CPyObject_GetAttr(cpy_r_r35, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 252, CPyStatic_globals);
        goto CPyL290;
    }
    cpy_r_r38 = PyFloat_AsDouble(cpy_r_r37);
    if (cpy_r_r38 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r37); cpy_r_r38 = -113.0;
    }
    CPy_DECREF(cpy_r_r37);
    cpy_r_r39 = cpy_r_r38 == -113.0;
    if (unlikely(cpy_r_r39)) goto CPyL18;
CPyL17: ;
    cpy_r_r40 = CPyModule_numpy;
    cpy_r_r41 = CPyStatics[37]; /* 'pi' */
    cpy_r_r42 = CPyObject_GetAttr(cpy_r_r40, cpy_r_r41);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 252, CPyStatic_globals);
        goto CPyL290;
    } else
        goto CPyL19;
CPyL18: ;
    cpy_r_r43 = PyErr_Occurred();
    if (unlikely(cpy_r_r43 != NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 252, CPyStatic_globals);
        goto CPyL290;
    } else
        goto CPyL17;
CPyL19: ;
    cpy_r_r44 = PyFloat_AsDouble(cpy_r_r42);
    if (cpy_r_r44 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r42); cpy_r_r44 = -113.0;
    }
    CPy_DECREF(cpy_r_r42);
    cpy_r_r45 = cpy_r_r44 == -113.0;
    if (unlikely(cpy_r_r45)) goto CPyL21;
CPyL20: ;
    cpy_r_r46 = PyFloat_FromDouble(cpy_r_r44);
    cpy_r_r47 = PyNumber_Multiply(cpy_r_phi_range_deg, cpy_r_r46);
    CPy_DECREF(cpy_r_r46);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 252, CPyStatic_globals);
        goto CPyL290;
    } else
        goto CPyL22;
CPyL21: ;
    cpy_r_r48 = PyErr_Occurred();
    if (unlikely(cpy_r_r48 != NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 252, CPyStatic_globals);
        goto CPyL290;
    } else
        goto CPyL20;
CPyL22: ;
    cpy_r_r49 = CPyStatics[261]; /* 180 */
    cpy_r_r50 = PyNumber_TrueDivide(cpy_r_r47, cpy_r_r49);
    CPy_DECREF(cpy_r_r47);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 252, CPyStatic_globals);
        goto CPyL290;
    }
    cpy_r_r51 = CPyStatics[257]; /* 2 */
    cpy_r_r52 = PyNumber_TrueDivide(cpy_r_r50, cpy_r_r51);
    CPy_DECREF(cpy_r_r50);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 252, CPyStatic_globals);
        goto CPyL290;
    }
    cpy_r_r53 = PyFloat_FromDouble(cpy_r_r38);
    cpy_r_r54 = PyNumber_Add(cpy_r_r53, cpy_r_r52);
    CPy_DECREF(cpy_r_r53);
    CPy_DECREF(cpy_r_r52);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 252, CPyStatic_globals);
        goto CPyL290;
    }
    cpy_r_r55 = CPyModule_random;
    cpy_r_r56 = CPyStatics[38]; /* 'uniform' */
    cpy_r_r57 = CPyObject_GetAttr(cpy_r_r55, cpy_r_r56);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 252, CPyStatic_globals);
        goto CPyL291;
    }
    PyObject *cpy_r_r58[2] = {cpy_r_r34, cpy_r_r54};
    cpy_r_r59 = (PyObject **)&cpy_r_r58;
    cpy_r_r60 = _PyObject_Vectorcall(cpy_r_r57, cpy_r_r59, 2, 0);
    CPy_DECREF(cpy_r_r57);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 252, CPyStatic_globals);
        goto CPyL291;
    }
    CPy_DECREF(cpy_r_r34);
    CPy_DECREF(cpy_r_r54);
    cpy_r_phi = cpy_r_r60;
    cpy_r_r61 = CPyModule_numpy;
    cpy_r_r62 = CPyStatics[36]; /* 'random' */
    cpy_r_r63 = CPyObject_GetAttr(cpy_r_r61, cpy_r_r62);
    if (unlikely(cpy_r_r63 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 253, CPyStatic_globals);
        goto CPyL292;
    }
    cpy_r_r64 = CPyStatics[36]; /* 'random' */
    cpy_r_r65 = CPyObject_GetAttr(cpy_r_r63, cpy_r_r64);
    CPy_DECREF(cpy_r_r63);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 253, CPyStatic_globals);
        goto CPyL292;
    }
    cpy_r_r66 = _PyObject_Vectorcall(cpy_r_r65, 0, 0, 0);
    CPy_DECREF(cpy_r_r65);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 253, CPyStatic_globals);
        goto CPyL292;
    }
    cpy_r_r67 = ((modTof___SimulationObject *)cpy_r_self)->_particle_gen_area;
    CPy_INCREF(cpy_r_r67);
    cpy_r_r68 = PyNumber_Multiply(cpy_r_r66, cpy_r_r67);
    CPy_DECREF(cpy_r_r66);
    CPy_DECREF(cpy_r_r67);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 253, CPyStatic_globals);
        goto CPyL292;
    }
    cpy_r_maxdist = cpy_r_r68;
    cpy_r_r69 = CPyDef_Simulation___round_to_sig(cpy_r_self, cpy_r_mean_free_path);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 254, CPyStatic_globals);
        goto CPyL293;
    }
    cpy_r_round_const = cpy_r_r69;
    cpy_r_r70 = CPyModule_numpy;
    cpy_r_r71 = CPyStatics[4]; /* 'cos' */
    cpy_r_r72 = CPyObject_GetAttr(cpy_r_r70, cpy_r_r71);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 255, CPyStatic_globals);
        goto CPyL294;
    }
    PyObject *cpy_r_r73[1] = {cpy_r_theta};
    cpy_r_r74 = (PyObject **)&cpy_r_r73;
    cpy_r_r75 = _PyObject_Vectorcall(cpy_r_r72, cpy_r_r74, 1, 0);
    CPy_DECREF(cpy_r_r72);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 255, CPyStatic_globals);
        goto CPyL294;
    }
    cpy_r_r76 = PyNumber_Multiply(cpy_r_maxdist, cpy_r_r75);
    CPy_DECREF(cpy_r_r75);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 255, CPyStatic_globals);
        goto CPyL294;
    }
    cpy_r_r77 = CPyModule_numpy;
    cpy_r_r78 = CPyStatics[5]; /* 'sin' */
    cpy_r_r79 = CPyObject_GetAttr(cpy_r_r77, cpy_r_r78);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 255, CPyStatic_globals);
        goto CPyL295;
    }
    PyObject *cpy_r_r80[1] = {cpy_r_theta};
    cpy_r_r81 = (PyObject **)&cpy_r_r80;
    cpy_r_r82 = _PyObject_Vectorcall(cpy_r_r79, cpy_r_r81, 1, 0);
    CPy_DECREF(cpy_r_r79);
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 255, CPyStatic_globals);
        goto CPyL295;
    }
    cpy_r_r83 = PyNumber_Multiply(cpy_r_maxdist, cpy_r_r82);
    CPy_DECREF(cpy_r_maxdist);
    CPy_DECREF(cpy_r_r82);
    if (unlikely(cpy_r_r83 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 255, CPyStatic_globals);
        goto CPyL296;
    }
    cpy_r_r84 = ((modTof___SimulationObject *)cpy_r_self)->_particle_gen_z;
    CPy_INCREF(cpy_r_r84);
    cpy_r_r85.f0 = cpy_r_r76;
    cpy_r_r85.f1 = cpy_r_r83;
    cpy_r_r85.f2 = cpy_r_r84;
    CPy_INCREF(cpy_r_r85.f0);
    CPy_INCREF(cpy_r_r85.f1);
    CPy_INCREF(cpy_r_r85.f2);
    CPy_DECREF(cpy_r_r76);
    CPy_DECREF(cpy_r_r83);
    CPy_DECREF(cpy_r_r84);
    cpy_r_r86 = CPyModule_numpy;
    cpy_r_r87 = CPyStatics[39]; /* 'float64' */
    cpy_r_r88 = CPyObject_GetAttr(cpy_r_r86, cpy_r_r87);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 255, CPyStatic_globals);
        goto CPyL297;
    }
    cpy_r_r89 = PyTuple_New(3);
    if (unlikely(cpy_r_r89 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp13 = cpy_r_r85.f0;
    PyTuple_SET_ITEM(cpy_r_r89, 0, __tmp13);
    PyObject *__tmp14 = cpy_r_r85.f1;
    PyTuple_SET_ITEM(cpy_r_r89, 1, __tmp14);
    PyObject *__tmp15 = cpy_r_r85.f2;
    PyTuple_SET_ITEM(cpy_r_r89, 2, __tmp15);
    PyObject *cpy_r_r90[1] = {cpy_r_r89};
    cpy_r_r91 = (PyObject **)&cpy_r_r90;
    cpy_r_r92 = _PyObject_Vectorcall(cpy_r_r88, cpy_r_r91, 1, 0);
    CPy_DECREF(cpy_r_r88);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 255, CPyStatic_globals);
        goto CPyL298;
    }
    CPy_DECREF(cpy_r_r89);
    cpy_r_o = cpy_r_r92;
    cpy_r_r93 = CPyModule_numpy;
    cpy_r_r94 = CPyStatics[4]; /* 'cos' */
    cpy_r_r95 = CPyObject_GetAttr(cpy_r_r93, cpy_r_r94);
    if (unlikely(cpy_r_r95 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 256, CPyStatic_globals);
        goto CPyL299;
    }
    PyObject *cpy_r_r96[1] = {cpy_r_theta};
    cpy_r_r97 = (PyObject **)&cpy_r_r96;
    cpy_r_r98 = _PyObject_Vectorcall(cpy_r_r95, cpy_r_r97, 1, 0);
    CPy_DECREF(cpy_r_r95);
    if (unlikely(cpy_r_r98 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 256, CPyStatic_globals);
        goto CPyL299;
    }
    cpy_r_r99 = CPyModule_numpy;
    cpy_r_r100 = CPyStatics[5]; /* 'sin' */
    cpy_r_r101 = CPyObject_GetAttr(cpy_r_r99, cpy_r_r100);
    if (unlikely(cpy_r_r101 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 256, CPyStatic_globals);
        goto CPyL300;
    }
    PyObject *cpy_r_r102[1] = {cpy_r_phi};
    cpy_r_r103 = (PyObject **)&cpy_r_r102;
    cpy_r_r104 = _PyObject_Vectorcall(cpy_r_r101, cpy_r_r103, 1, 0);
    CPy_DECREF(cpy_r_r101);
    if (unlikely(cpy_r_r104 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 256, CPyStatic_globals);
        goto CPyL300;
    }
    cpy_r_r105 = PyNumber_Multiply(cpy_r_r98, cpy_r_r104);
    CPy_DECREF(cpy_r_r98);
    CPy_DECREF(cpy_r_r104);
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 256, CPyStatic_globals);
        goto CPyL299;
    }
    cpy_r_r106 = CPyModule_numpy;
    cpy_r_r107 = CPyStatics[5]; /* 'sin' */
    cpy_r_r108 = CPyObject_GetAttr(cpy_r_r106, cpy_r_r107);
    if (unlikely(cpy_r_r108 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 256, CPyStatic_globals);
        goto CPyL301;
    }
    PyObject *cpy_r_r109[1] = {cpy_r_theta};
    cpy_r_r110 = (PyObject **)&cpy_r_r109;
    cpy_r_r111 = _PyObject_Vectorcall(cpy_r_r108, cpy_r_r110, 1, 0);
    CPy_DECREF(cpy_r_r108);
    if (unlikely(cpy_r_r111 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 256, CPyStatic_globals);
        goto CPyL301;
    }
    CPy_DECREF(cpy_r_theta);
    cpy_r_r112 = CPyModule_numpy;
    cpy_r_r113 = CPyStatics[5]; /* 'sin' */
    cpy_r_r114 = CPyObject_GetAttr(cpy_r_r112, cpy_r_r113);
    if (unlikely(cpy_r_r114 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 256, CPyStatic_globals);
        goto CPyL302;
    }
    PyObject *cpy_r_r115[1] = {cpy_r_phi};
    cpy_r_r116 = (PyObject **)&cpy_r_r115;
    cpy_r_r117 = _PyObject_Vectorcall(cpy_r_r114, cpy_r_r116, 1, 0);
    CPy_DECREF(cpy_r_r114);
    if (unlikely(cpy_r_r117 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 256, CPyStatic_globals);
        goto CPyL302;
    }
    cpy_r_r118 = PyNumber_Multiply(cpy_r_r111, cpy_r_r117);
    CPy_DECREF(cpy_r_r111);
    CPy_DECREF(cpy_r_r117);
    if (unlikely(cpy_r_r118 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 256, CPyStatic_globals);
        goto CPyL303;
    }
    cpy_r_r119 = CPyModule_numpy;
    cpy_r_r120 = CPyStatics[4]; /* 'cos' */
    cpy_r_r121 = CPyObject_GetAttr(cpy_r_r119, cpy_r_r120);
    if (unlikely(cpy_r_r121 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 256, CPyStatic_globals);
        goto CPyL304;
    }
    PyObject *cpy_r_r122[1] = {cpy_r_phi};
    cpy_r_r123 = (PyObject **)&cpy_r_r122;
    cpy_r_r124 = _PyObject_Vectorcall(cpy_r_r121, cpy_r_r123, 1, 0);
    CPy_DECREF(cpy_r_r121);
    if (unlikely(cpy_r_r124 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 256, CPyStatic_globals);
        goto CPyL304;
    }
    CPy_DECREF(cpy_r_phi);
    cpy_r_r125.f0 = cpy_r_r105;
    cpy_r_r125.f1 = cpy_r_r118;
    cpy_r_r125.f2 = cpy_r_r124;
    CPy_INCREF(cpy_r_r125.f0);
    CPy_INCREF(cpy_r_r125.f1);
    CPy_INCREF(cpy_r_r125.f2);
    CPy_DECREF(cpy_r_r105);
    CPy_DECREF(cpy_r_r118);
    CPy_DECREF(cpy_r_r124);
    cpy_r_r126 = CPyModule_numpy;
    cpy_r_r127 = CPyStatics[39]; /* 'float64' */
    cpy_r_r128 = CPyObject_GetAttr(cpy_r_r126, cpy_r_r127);
    if (unlikely(cpy_r_r128 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 256, CPyStatic_globals);
        goto CPyL305;
    }
    cpy_r_r129 = CPyModule_numpy;
    cpy_r_r130 = CPyStatics[32]; /* 'array' */
    cpy_r_r131 = CPyObject_GetAttr(cpy_r_r129, cpy_r_r130);
    if (unlikely(cpy_r_r131 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 256, CPyStatic_globals);
        goto CPyL306;
    }
    cpy_r_r132 = PyTuple_New(3);
    if (unlikely(cpy_r_r132 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp16 = cpy_r_r125.f0;
    PyTuple_SET_ITEM(cpy_r_r132, 0, __tmp16);
    PyObject *__tmp17 = cpy_r_r125.f1;
    PyTuple_SET_ITEM(cpy_r_r132, 1, __tmp17);
    PyObject *__tmp18 = cpy_r_r125.f2;
    PyTuple_SET_ITEM(cpy_r_r132, 2, __tmp18);
    PyObject *cpy_r_r133[2] = {cpy_r_r132, cpy_r_r128};
    cpy_r_r134 = (PyObject **)&cpy_r_r133;
    cpy_r_r135 = CPyStatics[264]; /* ('dtype',) */
    cpy_r_r136 = _PyObject_Vectorcall(cpy_r_r131, cpy_r_r134, 1, cpy_r_r135);
    CPy_DECREF(cpy_r_r131);
    if (unlikely(cpy_r_r136 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 256, CPyStatic_globals);
        goto CPyL307;
    }
    CPy_DECREF(cpy_r_r132);
    CPy_DECREF(cpy_r_r128);
    cpy_r_u = cpy_r_r136;
    cpy_r_r137 = PyList_New(1);
    if (unlikely(cpy_r_r137 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 258, CPyStatic_globals);
        goto CPyL308;
    }
    cpy_r_r138 = CPyStatics[244]; /* 0 */
    cpy_r_r139 = (CPyPtr)&((PyListObject *)cpy_r_r137)->ob_item;
    cpy_r_r140 = *(CPyPtr *)cpy_r_r139;
    CPy_INCREF(cpy_r_r138);
    *(PyObject * *)cpy_r_r140 = cpy_r_r138;
    cpy_r_photons = cpy_r_r137;
    cpy_r_r141 = PyList_New(1);
    if (unlikely(cpy_r_r141 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 259, CPyStatic_globals);
        goto CPyL309;
    }
    cpy_r_r142 = (CPyPtr)&((PyListObject *)cpy_r_r141)->ob_item;
    cpy_r_r143 = *(CPyPtr *)cpy_r_r142;
    *(PyObject * *)cpy_r_r143 = cpy_r_o;
    cpy_r_points = cpy_r_r141;
    cpy_r_r144 = PyList_New(1);
    if (unlikely(cpy_r_r144 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 260, CPyStatic_globals);
        goto CPyL310;
    }
    cpy_r_r145 = (CPyPtr)&((PyListObject *)cpy_r_r144)->ob_item;
    cpy_r_r146 = *(CPyPtr *)cpy_r_r145;
    CPy_INCREF(cpy_r_t);
    *(PyObject * *)cpy_r_r146 = cpy_r_t;
    cpy_r_times = cpy_r_r144;
    cpy_r_r147 = CPyStatics[260]; /* -1 */
    cpy_r_r148 = PyObject_GetItem(cpy_r_points, cpy_r_r147);
    if (unlikely(cpy_r_r148 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 261, CPyStatic_globals);
        goto CPyL311;
    }
    cpy_r_cur_o = cpy_r_r148;
    cpy_r_r149 = PyNumber_Multiply(cpy_r_mean_free_path, cpy_r_u);
    if (unlikely(cpy_r_r149 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 262, CPyStatic_globals);
        goto CPyL312;
    }
    cpy_r_r150 = PyNumber_Add(cpy_r_cur_o, cpy_r_r149);
    CPy_DECREF(cpy_r_r149);
    if (unlikely(cpy_r_r150 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 262, CPyStatic_globals);
        goto CPyL312;
    }
    cpy_r_r151 = CPyStatics[41]; /* 'round' */
    cpy_r_r152 = CPyObject_CallMethodObjArgs(cpy_r_r150, cpy_r_r151, cpy_r_round_const, NULL);
    CPy_DECREF(cpy_r_r150);
    if (unlikely(cpy_r_r152 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 262, CPyStatic_globals);
        goto CPyL312;
    }
    cpy_r_next_o = cpy_r_r152;
    cpy_r_r153 = 0 ? Py_True : Py_False;
    CPy_INCREF(cpy_r_r153);
    cpy_r_inside_scint = cpy_r_r153;
    cpy_r_r154 = CPyStatics[244]; /* 0 */
    CPy_INCREF(cpy_r_r154);
    cpy_r_missed = cpy_r_r154;
    goto CPyL313;
CPyL63: ;
    cpy_r_r155 = CPyStatics[257]; /* 2 */
    cpy_r_r156 = PyObject_GetItem(cpy_r_next_o, cpy_r_r155);
    if (unlikely(cpy_r_r156 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 265, CPyStatic_globals);
        goto CPyL314;
    }
    cpy_r_r157 = PyObject_RichCompare(cpy_r_r156, cpy_r_T4_z, 5);
    CPy_DECREF(cpy_r_r156);
    if (unlikely(cpy_r_r157 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 265, CPyStatic_globals);
        goto CPyL314;
    }
    cpy_r_r158 = PyObject_IsTrue(cpy_r_r157);
    CPy_DECREF(cpy_r_r157);
    cpy_r_r159 = cpy_r_r158 >= 0;
    if (unlikely(!cpy_r_r159)) {
        CPy_AddTraceback("modTof.py", "particle_path", 265, CPyStatic_globals);
        goto CPyL314;
    }
    cpy_r_r160 = cpy_r_r158;
    if (!cpy_r_r160) goto CPyL315;
    cpy_r_r161 = PyObject_IsTrue(cpy_r_inside_scint);
    cpy_r_r162 = cpy_r_r161 >= 0;
    if (unlikely(!cpy_r_r162)) {
        CPy_AddTraceback("modTof.py", "particle_path", 263, CPyStatic_globals);
        goto CPyL314;
    }
    cpy_r_r163 = cpy_r_r161;
    if (cpy_r_r163) {
        goto CPyL203;
    } else
        goto CPyL316;
CPyL69: ;
    cpy_r_r164 = PyObject_IsTrue(cpy_r_missed);
    cpy_r_r165 = cpy_r_r164 >= 0;
    if (unlikely(!cpy_r_r165)) {
        CPy_AddTraceback("modTof.py", "particle_path", 264, CPyStatic_globals);
        goto CPyL317;
    }
    cpy_r_r166 = cpy_r_r164;
    if (cpy_r_r166) {
        goto CPyL318;
    } else
        goto CPyL140;
CPyL71: ;
    cpy_r_r167 = CPyModule_numpy;
    cpy_r_r168 = CPyStatics[37]; /* 'pi' */
    cpy_r_r169 = CPyObject_GetAttr(cpy_r_r167, cpy_r_r168);
    if (unlikely(cpy_r_r169 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 268, CPyStatic_globals);
        goto CPyL319;
    }
    cpy_r_r170 = PyFloat_AsDouble(cpy_r_r169);
    if (cpy_r_r170 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r169); cpy_r_r170 = -113.0;
    }
    CPy_DECREF(cpy_r_r169);
    cpy_r_r171 = cpy_r_r170 == -113.0;
    if (unlikely(cpy_r_r171)) goto CPyL74;
CPyL73: ;
    cpy_r_r172 = 2.0 * cpy_r_r170;
    cpy_r_r173 = PyFloat_FromDouble(cpy_r_r172);
    cpy_r_r174 = CPyModule_random;
    cpy_r_r175 = CPyStatics[38]; /* 'uniform' */
    cpy_r_r176 = CPyObject_GetAttr(cpy_r_r174, cpy_r_r175);
    if (unlikely(cpy_r_r176 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 268, CPyStatic_globals);
        goto CPyL320;
    } else
        goto CPyL75;
CPyL74: ;
    cpy_r_r177 = PyErr_Occurred();
    if (unlikely(cpy_r_r177 != NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 268, CPyStatic_globals);
        goto CPyL319;
    } else
        goto CPyL73;
CPyL75: ;
    cpy_r_r178 = CPyStatics[244]; /* 0 */
    PyObject *cpy_r_r179[2] = {cpy_r_r178, cpy_r_r173};
    cpy_r_r180 = (PyObject **)&cpy_r_r179;
    cpy_r_r181 = _PyObject_Vectorcall(cpy_r_r176, cpy_r_r180, 2, 0);
    CPy_DECREF(cpy_r_r176);
    if (unlikely(cpy_r_r181 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 268, CPyStatic_globals);
        goto CPyL320;
    }
    CPy_DECREF(cpy_r_r173);
    cpy_r_theta = cpy_r_r181;
    cpy_r_r182 = CPyModule_numpy;
    cpy_r_r183 = CPyStatics[37]; /* 'pi' */
    cpy_r_r184 = CPyObject_GetAttr(cpy_r_r182, cpy_r_r183);
    if (unlikely(cpy_r_r184 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 269, CPyStatic_globals);
        goto CPyL321;
    }
    cpy_r_r185 = PyFloat_AsDouble(cpy_r_r184);
    if (cpy_r_r185 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r184); cpy_r_r185 = -113.0;
    }
    CPy_DECREF(cpy_r_r184);
    cpy_r_r186 = cpy_r_r185 == -113.0;
    if (unlikely(cpy_r_r186)) goto CPyL79;
CPyL78: ;
    cpy_r_r187 = CPyModule_numpy;
    cpy_r_r188 = CPyStatics[37]; /* 'pi' */
    cpy_r_r189 = CPyObject_GetAttr(cpy_r_r187, cpy_r_r188);
    if (unlikely(cpy_r_r189 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 269, CPyStatic_globals);
        goto CPyL321;
    } else
        goto CPyL80;
CPyL79: ;
    cpy_r_r190 = PyErr_Occurred();
    if (unlikely(cpy_r_r190 != NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 269, CPyStatic_globals);
        goto CPyL321;
    } else
        goto CPyL78;
CPyL80: ;
    cpy_r_r191 = PyFloat_AsDouble(cpy_r_r189);
    if (cpy_r_r191 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r189); cpy_r_r191 = -113.0;
    }
    CPy_DECREF(cpy_r_r189);
    cpy_r_r192 = cpy_r_r191 == -113.0;
    if (unlikely(cpy_r_r192)) goto CPyL82;
CPyL81: ;
    cpy_r_r193 = PyFloat_FromDouble(cpy_r_r191);
    cpy_r_r194 = PyNumber_Multiply(cpy_r_phi_range_deg, cpy_r_r193);
    CPy_DECREF(cpy_r_r193);
    if (unlikely(cpy_r_r194 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 269, CPyStatic_globals);
        goto CPyL321;
    } else
        goto CPyL83;
CPyL82: ;
    cpy_r_r195 = PyErr_Occurred();
    if (unlikely(cpy_r_r195 != NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 269, CPyStatic_globals);
        goto CPyL321;
    } else
        goto CPyL81;
CPyL83: ;
    cpy_r_r196 = CPyStatics[261]; /* 180 */
    cpy_r_r197 = PyNumber_TrueDivide(cpy_r_r194, cpy_r_r196);
    CPy_DECREF(cpy_r_r194);
    if (unlikely(cpy_r_r197 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 269, CPyStatic_globals);
        goto CPyL321;
    }
    cpy_r_r198 = CPyStatics[257]; /* 2 */
    cpy_r_r199 = PyNumber_TrueDivide(cpy_r_r197, cpy_r_r198);
    CPy_DECREF(cpy_r_r197);
    if (unlikely(cpy_r_r199 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 269, CPyStatic_globals);
        goto CPyL321;
    }
    cpy_r_r200 = PyFloat_FromDouble(cpy_r_r185);
    cpy_r_r201 = PyNumber_Subtract(cpy_r_r200, cpy_r_r199);
    CPy_DECREF(cpy_r_r200);
    CPy_DECREF(cpy_r_r199);
    if (unlikely(cpy_r_r201 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 269, CPyStatic_globals);
        goto CPyL321;
    }
    cpy_r_r202 = CPyModule_numpy;
    cpy_r_r203 = CPyStatics[37]; /* 'pi' */
    cpy_r_r204 = CPyObject_GetAttr(cpy_r_r202, cpy_r_r203);
    if (unlikely(cpy_r_r204 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 269, CPyStatic_globals);
        goto CPyL322;
    }
    cpy_r_r205 = PyFloat_AsDouble(cpy_r_r204);
    if (cpy_r_r205 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r204); cpy_r_r205 = -113.0;
    }
    CPy_DECREF(cpy_r_r204);
    cpy_r_r206 = cpy_r_r205 == -113.0;
    if (unlikely(cpy_r_r206)) goto CPyL89;
CPyL88: ;
    cpy_r_r207 = CPyModule_numpy;
    cpy_r_r208 = CPyStatics[37]; /* 'pi' */
    cpy_r_r209 = CPyObject_GetAttr(cpy_r_r207, cpy_r_r208);
    if (unlikely(cpy_r_r209 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 269, CPyStatic_globals);
        goto CPyL322;
    } else
        goto CPyL90;
CPyL89: ;
    cpy_r_r210 = PyErr_Occurred();
    if (unlikely(cpy_r_r210 != NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 269, CPyStatic_globals);
        goto CPyL322;
    } else
        goto CPyL88;
CPyL90: ;
    cpy_r_r211 = PyFloat_AsDouble(cpy_r_r209);
    if (cpy_r_r211 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r209); cpy_r_r211 = -113.0;
    }
    CPy_DECREF(cpy_r_r209);
    cpy_r_r212 = cpy_r_r211 == -113.0;
    if (unlikely(cpy_r_r212)) goto CPyL92;
CPyL91: ;
    cpy_r_r213 = PyFloat_FromDouble(cpy_r_r211);
    cpy_r_r214 = PyNumber_Multiply(cpy_r_phi_range_deg, cpy_r_r213);
    CPy_DECREF(cpy_r_r213);
    if (unlikely(cpy_r_r214 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 269, CPyStatic_globals);
        goto CPyL322;
    } else
        goto CPyL93;
CPyL92: ;
    cpy_r_r215 = PyErr_Occurred();
    if (unlikely(cpy_r_r215 != NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 269, CPyStatic_globals);
        goto CPyL322;
    } else
        goto CPyL91;
CPyL93: ;
    cpy_r_r216 = CPyStatics[261]; /* 180 */
    cpy_r_r217 = PyNumber_TrueDivide(cpy_r_r214, cpy_r_r216);
    CPy_DECREF(cpy_r_r214);
    if (unlikely(cpy_r_r217 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 269, CPyStatic_globals);
        goto CPyL322;
    }
    cpy_r_r218 = CPyStatics[257]; /* 2 */
    cpy_r_r219 = PyNumber_TrueDivide(cpy_r_r217, cpy_r_r218);
    CPy_DECREF(cpy_r_r217);
    if (unlikely(cpy_r_r219 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 269, CPyStatic_globals);
        goto CPyL322;
    }
    cpy_r_r220 = PyFloat_FromDouble(cpy_r_r205);
    cpy_r_r221 = PyNumber_Add(cpy_r_r220, cpy_r_r219);
    CPy_DECREF(cpy_r_r220);
    CPy_DECREF(cpy_r_r219);
    if (unlikely(cpy_r_r221 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 269, CPyStatic_globals);
        goto CPyL322;
    }
    cpy_r_r222 = CPyModule_random;
    cpy_r_r223 = CPyStatics[38]; /* 'uniform' */
    cpy_r_r224 = CPyObject_GetAttr(cpy_r_r222, cpy_r_r223);
    if (unlikely(cpy_r_r224 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 269, CPyStatic_globals);
        goto CPyL323;
    }
    PyObject *cpy_r_r225[2] = {cpy_r_r201, cpy_r_r221};
    cpy_r_r226 = (PyObject **)&cpy_r_r225;
    cpy_r_r227 = _PyObject_Vectorcall(cpy_r_r224, cpy_r_r226, 2, 0);
    CPy_DECREF(cpy_r_r224);
    if (unlikely(cpy_r_r227 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 269, CPyStatic_globals);
        goto CPyL323;
    }
    CPy_DECREF(cpy_r_r201);
    CPy_DECREF(cpy_r_r221);
    cpy_r_phi = cpy_r_r227;
    cpy_r_r228 = CPyModule_numpy;
    cpy_r_r229 = CPyStatics[36]; /* 'random' */
    cpy_r_r230 = CPyObject_GetAttr(cpy_r_r228, cpy_r_r229);
    if (unlikely(cpy_r_r230 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 270, CPyStatic_globals);
        goto CPyL324;
    }
    cpy_r_r231 = CPyStatics[36]; /* 'random' */
    cpy_r_r232 = CPyObject_GetAttr(cpy_r_r230, cpy_r_r231);
    CPy_DECREF(cpy_r_r230);
    if (unlikely(cpy_r_r232 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 270, CPyStatic_globals);
        goto CPyL324;
    }
    cpy_r_r233 = _PyObject_Vectorcall(cpy_r_r232, 0, 0, 0);
    CPy_DECREF(cpy_r_r232);
    if (unlikely(cpy_r_r233 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 270, CPyStatic_globals);
        goto CPyL324;
    }
    cpy_r_r234 = PyNumber_Multiply(cpy_r_r233, cpy_r_T1_radius);
    CPy_DECREF(cpy_r_r233);
    if (unlikely(cpy_r_r234 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 270, CPyStatic_globals);
        goto CPyL324;
    }
    cpy_r_r235 = CPyStatics[257]; /* 2 */
    cpy_r_r236 = PyNumber_TrueDivide(cpy_r_r234, cpy_r_r235);
    CPy_DECREF(cpy_r_r234);
    if (unlikely(cpy_r_r236 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 270, CPyStatic_globals);
        goto CPyL324;
    }
    cpy_r_maxdist = cpy_r_r236;
    cpy_r_r237 = CPyDef_Simulation___round_to_sig(cpy_r_self, cpy_r_mean_free_path);
    if (unlikely(cpy_r_r237 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 271, CPyStatic_globals);
        goto CPyL325;
    }
    cpy_r_round_const = cpy_r_r237;
    cpy_r_r238 = CPyModule_numpy;
    cpy_r_r239 = CPyStatics[4]; /* 'cos' */
    cpy_r_r240 = CPyObject_GetAttr(cpy_r_r238, cpy_r_r239);
    if (unlikely(cpy_r_r240 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 272, CPyStatic_globals);
        goto CPyL326;
    }
    PyObject *cpy_r_r241[1] = {cpy_r_theta};
    cpy_r_r242 = (PyObject **)&cpy_r_r241;
    cpy_r_r243 = _PyObject_Vectorcall(cpy_r_r240, cpy_r_r242, 1, 0);
    CPy_DECREF(cpy_r_r240);
    if (unlikely(cpy_r_r243 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 272, CPyStatic_globals);
        goto CPyL326;
    }
    cpy_r_r244 = PyNumber_Multiply(cpy_r_maxdist, cpy_r_r243);
    CPy_DECREF(cpy_r_r243);
    if (unlikely(cpy_r_r244 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 272, CPyStatic_globals);
        goto CPyL326;
    }
    cpy_r_r245 = CPyModule_numpy;
    cpy_r_r246 = CPyStatics[5]; /* 'sin' */
    cpy_r_r247 = CPyObject_GetAttr(cpy_r_r245, cpy_r_r246);
    if (unlikely(cpy_r_r247 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 272, CPyStatic_globals);
        goto CPyL327;
    }
    PyObject *cpy_r_r248[1] = {cpy_r_theta};
    cpy_r_r249 = (PyObject **)&cpy_r_r248;
    cpy_r_r250 = _PyObject_Vectorcall(cpy_r_r247, cpy_r_r249, 1, 0);
    CPy_DECREF(cpy_r_r247);
    if (unlikely(cpy_r_r250 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 272, CPyStatic_globals);
        goto CPyL327;
    }
    cpy_r_r251 = PyNumber_Multiply(cpy_r_maxdist, cpy_r_r250);
    CPy_DECREF(cpy_r_maxdist);
    CPy_DECREF(cpy_r_r250);
    if (unlikely(cpy_r_r251 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 272, CPyStatic_globals);
        goto CPyL328;
    }
    cpy_r_r252 = PyNumber_Add(cpy_r_T1_z, cpy_r_T1_width);
    if (unlikely(cpy_r_r252 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 272, CPyStatic_globals);
        goto CPyL329;
    }
    cpy_r_r253 = CPyStatics[257]; /* 2 */
    cpy_r_r254 = PyNumber_Add(cpy_r_r252, cpy_r_r253);
    CPy_DECREF(cpy_r_r252);
    if (unlikely(cpy_r_r254 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 272, CPyStatic_globals);
        goto CPyL329;
    }
    cpy_r_r255.f0 = cpy_r_r244;
    cpy_r_r255.f1 = cpy_r_r251;
    cpy_r_r255.f2 = cpy_r_r254;
    CPy_INCREF(cpy_r_r255.f0);
    CPy_INCREF(cpy_r_r255.f1);
    CPy_INCREF(cpy_r_r255.f2);
    CPy_DECREF(cpy_r_r244);
    CPy_DECREF(cpy_r_r251);
    CPy_DECREF(cpy_r_r254);
    cpy_r_r256 = CPyModule_numpy;
    cpy_r_r257 = CPyStatics[39]; /* 'float64' */
    cpy_r_r258 = CPyObject_GetAttr(cpy_r_r256, cpy_r_r257);
    if (unlikely(cpy_r_r258 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 272, CPyStatic_globals);
        goto CPyL330;
    }
    cpy_r_r259 = PyTuple_New(3);
    if (unlikely(cpy_r_r259 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp19 = cpy_r_r255.f0;
    PyTuple_SET_ITEM(cpy_r_r259, 0, __tmp19);
    PyObject *__tmp20 = cpy_r_r255.f1;
    PyTuple_SET_ITEM(cpy_r_r259, 1, __tmp20);
    PyObject *__tmp21 = cpy_r_r255.f2;
    PyTuple_SET_ITEM(cpy_r_r259, 2, __tmp21);
    PyObject *cpy_r_r260[1] = {cpy_r_r259};
    cpy_r_r261 = (PyObject **)&cpy_r_r260;
    cpy_r_r262 = _PyObject_Vectorcall(cpy_r_r258, cpy_r_r261, 1, 0);
    CPy_DECREF(cpy_r_r258);
    if (unlikely(cpy_r_r262 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 272, CPyStatic_globals);
        goto CPyL331;
    }
    CPy_DECREF(cpy_r_r259);
    cpy_r_o = cpy_r_r262;
    cpy_r_r263 = CPyModule_numpy;
    cpy_r_r264 = CPyStatics[4]; /* 'cos' */
    cpy_r_r265 = CPyObject_GetAttr(cpy_r_r263, cpy_r_r264);
    if (unlikely(cpy_r_r265 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 273, CPyStatic_globals);
        goto CPyL332;
    }
    PyObject *cpy_r_r266[1] = {cpy_r_theta};
    cpy_r_r267 = (PyObject **)&cpy_r_r266;
    cpy_r_r268 = _PyObject_Vectorcall(cpy_r_r265, cpy_r_r267, 1, 0);
    CPy_DECREF(cpy_r_r265);
    if (unlikely(cpy_r_r268 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 273, CPyStatic_globals);
        goto CPyL332;
    }
    cpy_r_r269 = CPyModule_numpy;
    cpy_r_r270 = CPyStatics[5]; /* 'sin' */
    cpy_r_r271 = CPyObject_GetAttr(cpy_r_r269, cpy_r_r270);
    if (unlikely(cpy_r_r271 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 273, CPyStatic_globals);
        goto CPyL333;
    }
    PyObject *cpy_r_r272[1] = {cpy_r_phi};
    cpy_r_r273 = (PyObject **)&cpy_r_r272;
    cpy_r_r274 = _PyObject_Vectorcall(cpy_r_r271, cpy_r_r273, 1, 0);
    CPy_DECREF(cpy_r_r271);
    if (unlikely(cpy_r_r274 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 273, CPyStatic_globals);
        goto CPyL333;
    }
    cpy_r_r275 = PyNumber_Multiply(cpy_r_r268, cpy_r_r274);
    CPy_DECREF(cpy_r_r268);
    CPy_DECREF(cpy_r_r274);
    if (unlikely(cpy_r_r275 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 273, CPyStatic_globals);
        goto CPyL332;
    }
    cpy_r_r276 = CPyModule_numpy;
    cpy_r_r277 = CPyStatics[5]; /* 'sin' */
    cpy_r_r278 = CPyObject_GetAttr(cpy_r_r276, cpy_r_r277);
    if (unlikely(cpy_r_r278 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 273, CPyStatic_globals);
        goto CPyL334;
    }
    PyObject *cpy_r_r279[1] = {cpy_r_theta};
    cpy_r_r280 = (PyObject **)&cpy_r_r279;
    cpy_r_r281 = _PyObject_Vectorcall(cpy_r_r278, cpy_r_r280, 1, 0);
    CPy_DECREF(cpy_r_r278);
    if (unlikely(cpy_r_r281 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 273, CPyStatic_globals);
        goto CPyL334;
    }
    CPy_DECREF(cpy_r_theta);
    cpy_r_r282 = CPyModule_numpy;
    cpy_r_r283 = CPyStatics[5]; /* 'sin' */
    cpy_r_r284 = CPyObject_GetAttr(cpy_r_r282, cpy_r_r283);
    if (unlikely(cpy_r_r284 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 273, CPyStatic_globals);
        goto CPyL335;
    }
    PyObject *cpy_r_r285[1] = {cpy_r_phi};
    cpy_r_r286 = (PyObject **)&cpy_r_r285;
    cpy_r_r287 = _PyObject_Vectorcall(cpy_r_r284, cpy_r_r286, 1, 0);
    CPy_DECREF(cpy_r_r284);
    if (unlikely(cpy_r_r287 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 273, CPyStatic_globals);
        goto CPyL335;
    }
    cpy_r_r288 = PyNumber_Multiply(cpy_r_r281, cpy_r_r287);
    CPy_DECREF(cpy_r_r281);
    CPy_DECREF(cpy_r_r287);
    if (unlikely(cpy_r_r288 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 273, CPyStatic_globals);
        goto CPyL336;
    }
    cpy_r_r289 = CPyModule_numpy;
    cpy_r_r290 = CPyStatics[4]; /* 'cos' */
    cpy_r_r291 = CPyObject_GetAttr(cpy_r_r289, cpy_r_r290);
    if (unlikely(cpy_r_r291 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 273, CPyStatic_globals);
        goto CPyL337;
    }
    PyObject *cpy_r_r292[1] = {cpy_r_phi};
    cpy_r_r293 = (PyObject **)&cpy_r_r292;
    cpy_r_r294 = _PyObject_Vectorcall(cpy_r_r291, cpy_r_r293, 1, 0);
    CPy_DECREF(cpy_r_r291);
    if (unlikely(cpy_r_r294 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 273, CPyStatic_globals);
        goto CPyL337;
    }
    CPy_DECREF(cpy_r_phi);
    cpy_r_r295.f0 = cpy_r_r275;
    cpy_r_r295.f1 = cpy_r_r288;
    cpy_r_r295.f2 = cpy_r_r294;
    CPy_INCREF(cpy_r_r295.f0);
    CPy_INCREF(cpy_r_r295.f1);
    CPy_INCREF(cpy_r_r295.f2);
    CPy_DECREF(cpy_r_r275);
    CPy_DECREF(cpy_r_r288);
    CPy_DECREF(cpy_r_r294);
    cpy_r_r296 = CPyModule_numpy;
    cpy_r_r297 = CPyStatics[39]; /* 'float64' */
    cpy_r_r298 = CPyObject_GetAttr(cpy_r_r296, cpy_r_r297);
    if (unlikely(cpy_r_r298 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 273, CPyStatic_globals);
        goto CPyL338;
    }
    cpy_r_r299 = CPyModule_numpy;
    cpy_r_r300 = CPyStatics[32]; /* 'array' */
    cpy_r_r301 = CPyObject_GetAttr(cpy_r_r299, cpy_r_r300);
    if (unlikely(cpy_r_r301 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 273, CPyStatic_globals);
        goto CPyL339;
    }
    cpy_r_r302 = PyTuple_New(3);
    if (unlikely(cpy_r_r302 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp22 = cpy_r_r295.f0;
    PyTuple_SET_ITEM(cpy_r_r302, 0, __tmp22);
    PyObject *__tmp23 = cpy_r_r295.f1;
    PyTuple_SET_ITEM(cpy_r_r302, 1, __tmp23);
    PyObject *__tmp24 = cpy_r_r295.f2;
    PyTuple_SET_ITEM(cpy_r_r302, 2, __tmp24);
    PyObject *cpy_r_r303[2] = {cpy_r_r302, cpy_r_r298};
    cpy_r_r304 = (PyObject **)&cpy_r_r303;
    cpy_r_r305 = CPyStatics[264]; /* ('dtype',) */
    cpy_r_r306 = _PyObject_Vectorcall(cpy_r_r301, cpy_r_r304, 1, cpy_r_r305);
    CPy_DECREF(cpy_r_r301);
    if (unlikely(cpy_r_r306 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 273, CPyStatic_globals);
        goto CPyL340;
    }
    CPy_DECREF(cpy_r_r302);
    CPy_DECREF(cpy_r_r298);
    cpy_r_u = cpy_r_r306;
    cpy_r_r307 = CPyStatics[42]; /* 'clear' */
    cpy_r_r308 = CPyObject_CallMethodObjArgs(cpy_r_photons, cpy_r_r307, NULL);
    CPy_DECREF(cpy_r_photons);
    if (unlikely(cpy_r_r308 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 274, CPyStatic_globals);
        goto CPyL341;
    } else
        goto CPyL342;
CPyL130: ;
    cpy_r_r309 = CPyStatics[42]; /* 'clear' */
    cpy_r_r310 = CPyObject_CallMethodObjArgs(cpy_r_points, cpy_r_r309, NULL);
    CPy_DECREF(cpy_r_points);
    if (unlikely(cpy_r_r310 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 274, CPyStatic_globals);
        goto CPyL343;
    } else
        goto CPyL344;
CPyL131: ;
    cpy_r_r311 = CPyStatics[42]; /* 'clear' */
    cpy_r_r312 = CPyObject_CallMethodObjArgs(cpy_r_times, cpy_r_r311, NULL);
    CPy_DECREF(cpy_r_times);
    if (unlikely(cpy_r_r312 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 274, CPyStatic_globals);
        goto CPyL345;
    } else
        goto CPyL346;
CPyL132: ;
    cpy_r_r313 = PyList_New(1);
    if (unlikely(cpy_r_r313 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 275, CPyStatic_globals);
        goto CPyL345;
    }
    cpy_r_r314 = CPyStatics[244]; /* 0 */
    cpy_r_r315 = (CPyPtr)&((PyListObject *)cpy_r_r313)->ob_item;
    cpy_r_r316 = *(CPyPtr *)cpy_r_r315;
    CPy_INCREF(cpy_r_r314);
    *(PyObject * *)cpy_r_r316 = cpy_r_r314;
    cpy_r_photons = cpy_r_r313;
    cpy_r_r317 = PyList_New(1);
    if (unlikely(cpy_r_r317 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 276, CPyStatic_globals);
        goto CPyL347;
    }
    cpy_r_r318 = (CPyPtr)&((PyListObject *)cpy_r_r317)->ob_item;
    cpy_r_r319 = *(CPyPtr *)cpy_r_r318;
    *(PyObject * *)cpy_r_r319 = cpy_r_o;
    cpy_r_points = cpy_r_r317;
    cpy_r_r320 = PyList_New(1);
    if (unlikely(cpy_r_r320 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 277, CPyStatic_globals);
        goto CPyL348;
    }
    cpy_r_r321 = (CPyPtr)&((PyListObject *)cpy_r_r320)->ob_item;
    cpy_r_r322 = *(CPyPtr *)cpy_r_r321;
    CPy_INCREF(cpy_r_t);
    *(PyObject * *)cpy_r_r322 = cpy_r_t;
    cpy_r_times = cpy_r_r320;
    cpy_r_r323 = CPyStatics[260]; /* -1 */
    cpy_r_r324 = PyObject_GetItem(cpy_r_points, cpy_r_r323);
    if (unlikely(cpy_r_r324 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 278, CPyStatic_globals);
        goto CPyL349;
    }
    cpy_r_cur_o = cpy_r_r324;
    cpy_r_r325 = PyNumber_Multiply(cpy_r_mean_free_path, cpy_r_u);
    if (unlikely(cpy_r_r325 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 279, CPyStatic_globals);
        goto CPyL350;
    }
    cpy_r_r326 = PyNumber_Add(cpy_r_cur_o, cpy_r_r325);
    CPy_DECREF(cpy_r_r325);
    if (unlikely(cpy_r_r326 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 279, CPyStatic_globals);
        goto CPyL350;
    }
    cpy_r_r327 = CPyStatics[41]; /* 'round' */
    cpy_r_r328 = CPyObject_CallMethodObjArgs(cpy_r_r326, cpy_r_r327, cpy_r_round_const, NULL);
    CPy_DECREF(cpy_r_r326);
    if (unlikely(cpy_r_r328 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 279, CPyStatic_globals);
        goto CPyL350;
    }
    cpy_r_next_o = cpy_r_r328;
    cpy_r_r329 = 0 ? Py_True : Py_False;
    CPy_INCREF(cpy_r_r329);
    cpy_r_missed = cpy_r_r329;
CPyL140: ;
    cpy_r_r330 = PyNumber_Add(cpy_r_T1_z, cpy_r_T1_width);
    if (unlikely(cpy_r_r330 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 281, CPyStatic_globals);
        goto CPyL317;
    }
    cpy_r_r331 = CPyStatics[257]; /* 2 */
    cpy_r_r332 = PyObject_GetItem(cpy_r_cur_o, cpy_r_r331);
    if (unlikely(cpy_r_r332 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 281, CPyStatic_globals);
        goto CPyL351;
    }
    cpy_r_r333 = PyNumber_Subtract(cpy_r_r330, cpy_r_r332);
    CPy_DECREF(cpy_r_r330);
    CPy_DECREF(cpy_r_r332);
    if (unlikely(cpy_r_r333 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 281, CPyStatic_globals);
        goto CPyL317;
    }
    cpy_r_r334 = CPyStatics[257]; /* 2 */
    cpy_r_r335 = PyObject_GetItem(cpy_r_u, cpy_r_r334);
    if (unlikely(cpy_r_r335 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 281, CPyStatic_globals);
        goto CPyL352;
    }
    cpy_r_r336 = PyNumber_TrueDivide(cpy_r_r333, cpy_r_r335);
    CPy_DECREF(cpy_r_r333);
    CPy_DECREF(cpy_r_r335);
    if (unlikely(cpy_r_r336 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 281, CPyStatic_globals);
        goto CPyL317;
    }
    cpy_r_r337 = CPyModule_numpy;
    cpy_r_r338 = CPyStatics[24]; /* 'abs' */
    cpy_r_r339 = CPyObject_GetAttr(cpy_r_r337, cpy_r_r338);
    if (unlikely(cpy_r_r339 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 281, CPyStatic_globals);
        goto CPyL353;
    }
    PyObject *cpy_r_r340[1] = {cpy_r_r336};
    cpy_r_r341 = (PyObject **)&cpy_r_r340;
    cpy_r_r342 = _PyObject_Vectorcall(cpy_r_r339, cpy_r_r341, 1, 0);
    CPy_DECREF(cpy_r_r339);
    if (unlikely(cpy_r_r342 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 281, CPyStatic_globals);
        goto CPyL353;
    }
    CPy_DECREF(cpy_r_r336);
    cpy_r_distT1 = cpy_r_r342;
    cpy_r_r343 = PyNumber_Add(cpy_r_T4_z, cpy_r_T4_width);
    if (unlikely(cpy_r_r343 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 282, CPyStatic_globals);
        goto CPyL354;
    }
    cpy_r_r344 = CPyStatics[257]; /* 2 */
    cpy_r_r345 = PyObject_GetItem(cpy_r_cur_o, cpy_r_r344);
    if (unlikely(cpy_r_r345 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 282, CPyStatic_globals);
        goto CPyL355;
    }
    cpy_r_r346 = PyNumber_Subtract(cpy_r_r343, cpy_r_r345);
    CPy_DECREF(cpy_r_r343);
    CPy_DECREF(cpy_r_r345);
    if (unlikely(cpy_r_r346 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 282, CPyStatic_globals);
        goto CPyL354;
    }
    cpy_r_r347 = CPyStatics[257]; /* 2 */
    cpy_r_r348 = PyObject_GetItem(cpy_r_u, cpy_r_r347);
    if (unlikely(cpy_r_r348 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 282, CPyStatic_globals);
        goto CPyL356;
    }
    cpy_r_r349 = PyNumber_TrueDivide(cpy_r_r346, cpy_r_r348);
    CPy_DECREF(cpy_r_r346);
    CPy_DECREF(cpy_r_r348);
    if (unlikely(cpy_r_r349 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 282, CPyStatic_globals);
        goto CPyL354;
    }
    cpy_r_r350 = CPyModule_numpy;
    cpy_r_r351 = CPyStatics[24]; /* 'abs' */
    cpy_r_r352 = CPyObject_GetAttr(cpy_r_r350, cpy_r_r351);
    if (unlikely(cpy_r_r352 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 282, CPyStatic_globals);
        goto CPyL357;
    }
    PyObject *cpy_r_r353[1] = {cpy_r_r349};
    cpy_r_r354 = (PyObject **)&cpy_r_r353;
    cpy_r_r355 = _PyObject_Vectorcall(cpy_r_r352, cpy_r_r354, 1, 0);
    CPy_DECREF(cpy_r_r352);
    if (unlikely(cpy_r_r355 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 282, CPyStatic_globals);
        goto CPyL357;
    }
    CPy_DECREF(cpy_r_r349);
    cpy_r_distT4 = cpy_r_r355;
    cpy_r_r356 = CPyStatics[257]; /* 2 */
    cpy_r_r357 = PyObject_GetItem(cpy_r_next_o, cpy_r_r356);
    if (unlikely(cpy_r_r357 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 283, CPyStatic_globals);
        goto CPyL358;
    }
    cpy_r_r358 = PyObject_RichCompare(cpy_r_r357, cpy_r_T1_z, 0);
    CPy_DECREF(cpy_r_r357);
    if (unlikely(cpy_r_r358 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 283, CPyStatic_globals);
        goto CPyL358;
    }
    cpy_r_r359 = PyObject_IsTrue(cpy_r_r358);
    CPy_DECREF(cpy_r_r358);
    cpy_r_r360 = cpy_r_r359 >= 0;
    if (unlikely(!cpy_r_r360)) {
        CPy_AddTraceback("modTof.py", "particle_path", 283, CPyStatic_globals);
        goto CPyL358;
    }
    cpy_r_r361 = cpy_r_r359;
    if (cpy_r_r361) {
        goto CPyL359;
    } else
        goto CPyL360;
CPyL158: ;
    cpy_r_r362 = cpy_r_distT4;
    goto CPyL160;
CPyL159: ;
    cpy_r_r362 = cpy_r_distT1;
CPyL160: ;
    cpy_r_dist = cpy_r_r362;
    cpy_r_r363 = PyNumber_Multiply(cpy_r_dist, cpy_r_u);
    if (unlikely(cpy_r_r363 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 284, CPyStatic_globals);
        goto CPyL361;
    }
    cpy_r_r364 = PyNumber_Add(cpy_r_cur_o, cpy_r_r363);
    CPy_DECREF(cpy_r_r363);
    if (unlikely(cpy_r_r364 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 284, CPyStatic_globals);
        goto CPyL361;
    }
    cpy_r_r365 = CPyStatics[41]; /* 'round' */
    cpy_r_r366 = CPyObject_CallMethodObjArgs(cpy_r_r364, cpy_r_r365, cpy_r_round_const, NULL);
    CPy_DECREF(cpy_r_r364);
    if (unlikely(cpy_r_r366 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 284, CPyStatic_globals);
        goto CPyL361;
    }
    cpy_r_check = cpy_r_r366;
    cpy_r_r367 = CPyStatics[247]; /* 1 */
    cpy_r_r368 = CPyDef_Simulation___scint_condition(cpy_r_self, cpy_r_check, cpy_r_T1_radius, cpy_r_r367);
    if (unlikely(cpy_r_r368 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 285, CPyStatic_globals);
        goto CPyL362;
    }
    cpy_r_r369 = CPyStatics[247]; /* 1 */
    cpy_r_r370 = CPyDef_Simulation___lg_condition(cpy_r_self, cpy_r_check, cpy_r_T1_corner, cpy_r_r369);
    if (unlikely(cpy_r_r370 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 285, CPyStatic_globals);
        goto CPyL363;
    }
    cpy_r_r371 = PyNumber_Or(cpy_r_r368, cpy_r_r370);
    CPy_DECREF(cpy_r_r368);
    CPy_DECREF(cpy_r_r370);
    if (unlikely(cpy_r_r371 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 285, CPyStatic_globals);
        goto CPyL362;
    }
    cpy_r_inside_T1 = cpy_r_r371;
    cpy_r_r372 = CPyStatics[248]; /* 4 */
    cpy_r_r373 = CPyDef_Simulation___scint_condition(cpy_r_self, cpy_r_check, cpy_r_T4_radius, cpy_r_r372);
    if (unlikely(cpy_r_r373 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 286, CPyStatic_globals);
        goto CPyL364;
    }
    cpy_r_r374 = CPyStatics[248]; /* 4 */
    cpy_r_r375 = CPyDef_Simulation___lg_condition(cpy_r_self, cpy_r_check, cpy_r_T4_corner, cpy_r_r374);
    if (unlikely(cpy_r_r375 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 286, CPyStatic_globals);
        goto CPyL365;
    }
    cpy_r_r376 = PyNumber_Or(cpy_r_r373, cpy_r_r375);
    CPy_DECREF(cpy_r_r373);
    CPy_DECREF(cpy_r_r375);
    if (unlikely(cpy_r_r376 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 286, CPyStatic_globals);
        goto CPyL364;
    }
    cpy_r_inside_T4 = cpy_r_r376;
    cpy_r_r377 = CPyStatics[257]; /* 2 */
    cpy_r_r378 = PyObject_GetItem(cpy_r_check, cpy_r_r377);
    CPy_DECREF(cpy_r_check);
    if (unlikely(cpy_r_r378 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 287, CPyStatic_globals);
        goto CPyL366;
    }
    cpy_r_r379 = PyObject_RichCompare(cpy_r_r378, cpy_r_T1_z, 0);
    CPy_DECREF(cpy_r_r378);
    if (unlikely(cpy_r_r379 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 287, CPyStatic_globals);
        goto CPyL366;
    }
    cpy_r_r380 = PyObject_IsTrue(cpy_r_r379);
    CPy_DECREF(cpy_r_r379);
    cpy_r_r381 = cpy_r_r380 >= 0;
    if (unlikely(!cpy_r_r381)) {
        CPy_AddTraceback("modTof.py", "particle_path", 287, CPyStatic_globals);
        goto CPyL366;
    }
    cpy_r_r382 = cpy_r_r380;
    if (cpy_r_r382) {
        goto CPyL367;
    } else
        goto CPyL368;
CPyL173: ;
    cpy_r_r383 = cpy_r_inside_T4;
    goto CPyL175;
CPyL174: ;
    cpy_r_r383 = cpy_r_inside_T1;
CPyL175: ;
    cpy_r_scint_cond = cpy_r_r383;
    cpy_r_r384 = PyObject_IsTrue(cpy_r_scint_cond);
    CPy_DECREF(cpy_r_scint_cond);
    cpy_r_r385 = cpy_r_r384 >= 0;
    if (unlikely(!cpy_r_r385)) {
        CPy_AddTraceback("modTof.py", "particle_path", 287, CPyStatic_globals);
        goto CPyL361;
    }
    cpy_r_r386 = cpy_r_r384;
    if (cpy_r_r386) {
        goto CPyL369;
    } else
        goto CPyL370;
CPyL177: ;
    cpy_r_r387 = ((modTof___SimulationObject *)cpy_r_self)->_c;
    CPy_INCREF(cpy_r_r387);
    cpy_r_r388 = PyNumber_TrueDivide(cpy_r_dist, cpy_r_r387);
    CPy_DECREF(cpy_r_r387);
    if (unlikely(cpy_r_r388 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 291, CPyStatic_globals);
        goto CPyL371;
    }
    cpy_r_r389 = PyNumber_InPlaceAdd(cpy_r_t, cpy_r_r388);
    CPy_DECREF(cpy_r_t);
    CPy_DECREF(cpy_r_r388);
    if (unlikely(cpy_r_r389 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 291, CPyStatic_globals);
        goto CPyL372;
    }
    cpy_r_t = cpy_r_r389;
    cpy_r_r390 = CPyStatics[43]; /* 'append' */
    cpy_r_r391 = CPyObject_CallMethodObjArgs(cpy_r_times, cpy_r_r390, cpy_r_t, NULL);
    if (unlikely(cpy_r_r391 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 292, CPyStatic_globals);
        goto CPyL371;
    } else
        goto CPyL373;
CPyL180: ;
    cpy_r_r392 = CPyStatics[260]; /* -1 */
    cpy_r_r393 = PyObject_GetItem(cpy_r_points, cpy_r_r392);
    if (unlikely(cpy_r_r393 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 293, CPyStatic_globals);
        goto CPyL371;
    }
    cpy_r_r394 = PyNumber_Multiply(cpy_r_dist, cpy_r_u);
    CPy_DECREF(cpy_r_dist);
    if (unlikely(cpy_r_r394 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 293, CPyStatic_globals);
        goto CPyL374;
    }
    cpy_r_r395 = PyNumber_Add(cpy_r_r393, cpy_r_r394);
    CPy_DECREF(cpy_r_r393);
    CPy_DECREF(cpy_r_r394);
    if (unlikely(cpy_r_r395 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 293, CPyStatic_globals);
        goto CPyL375;
    }
    cpy_r_r396 = PyNumber_Multiply(cpy_r_mean_free_path, cpy_r_u);
    if (unlikely(cpy_r_r396 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 293, CPyStatic_globals);
        goto CPyL376;
    }
    cpy_r_r397 = PyNumber_Add(cpy_r_r395, cpy_r_r396);
    CPy_DECREF(cpy_r_r395);
    CPy_DECREF(cpy_r_r396);
    if (unlikely(cpy_r_r397 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 293, CPyStatic_globals);
        goto CPyL375;
    }
    cpy_r_r398 = CPyStatics[43]; /* 'append' */
    cpy_r_r399 = CPyObject_CallMethodObjArgs(cpy_r_points, cpy_r_r398, cpy_r_r397, NULL);
    CPy_DECREF(cpy_r_r397);
    if (unlikely(cpy_r_r399 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 293, CPyStatic_globals);
        goto CPyL375;
    } else
        goto CPyL377;
CPyL186: ;
    cpy_r_r400 = CPyModule_numpy;
    cpy_r_r401 = CPyStatics[36]; /* 'random' */
    cpy_r_r402 = CPyObject_GetAttr(cpy_r_r400, cpy_r_r401);
    if (unlikely(cpy_r_r402 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 294, CPyStatic_globals);
        goto CPyL375;
    }
    cpy_r_r403 = CPyStatics[44]; /* 'poisson' */
    cpy_r_r404 = CPyObject_GetAttr(cpy_r_r402, cpy_r_r403);
    CPy_DECREF(cpy_r_r402);
    if (unlikely(cpy_r_r404 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 294, CPyStatic_globals);
        goto CPyL375;
    }
    PyObject *cpy_r_r405[1] = {cpy_r_photons_per_E};
    cpy_r_r406 = (PyObject **)&cpy_r_r405;
    cpy_r_r407 = _PyObject_Vectorcall(cpy_r_r404, cpy_r_r406, 1, 0);
    CPy_DECREF(cpy_r_r404);
    if (unlikely(cpy_r_r407 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 294, CPyStatic_globals);
        goto CPyL375;
    }
    cpy_r_phot = cpy_r_r407;
    cpy_r_r408 = CPyModule_numpy;
    cpy_r_r409 = CPyStatics[36]; /* 'random' */
    cpy_r_r410 = CPyObject_GetAttr(cpy_r_r408, cpy_r_r409);
    if (unlikely(cpy_r_r410 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 295, CPyStatic_globals);
        goto CPyL378;
    }
    cpy_r_r411 = CPyStatics[36]; /* 'random' */
    cpy_r_r412 = CPyObject_GetAttr(cpy_r_r410, cpy_r_r411);
    CPy_DECREF(cpy_r_r410);
    if (unlikely(cpy_r_r412 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 295, CPyStatic_globals);
        goto CPyL378;
    }
    cpy_r_r413 = _PyObject_Vectorcall(cpy_r_r412, 0, 0, 0);
    CPy_DECREF(cpy_r_r412);
    if (unlikely(cpy_r_r413 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 295, CPyStatic_globals);
        goto CPyL378;
    }
    cpy_r_r414 = PyObject_RichCompare(cpy_r_r413, cpy_r_prob_scint, 0);
    CPy_DECREF(cpy_r_r413);
    if (unlikely(cpy_r_r414 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 295, CPyStatic_globals);
        goto CPyL378;
    }
    cpy_r_r415 = PyObject_IsTrue(cpy_r_r414);
    CPy_DECREF(cpy_r_r414);
    cpy_r_r416 = cpy_r_r415 >= 0;
    if (unlikely(!cpy_r_r416)) {
        CPy_AddTraceback("modTof.py", "particle_path", 295, CPyStatic_globals);
        goto CPyL378;
    }
    cpy_r_r417 = cpy_r_r415;
    if (!cpy_r_r417) goto CPyL379;
    cpy_r_r418 = CPyStatics[43]; /* 'append' */
    cpy_r_r419 = CPyObject_CallMethodObjArgs(cpy_r_photons, cpy_r_r418, cpy_r_phot, NULL);
    CPy_DECREF(cpy_r_phot);
    if (unlikely(cpy_r_r419 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 295, CPyStatic_globals);
        goto CPyL375;
    } else
        goto CPyL380;
CPyL196: ;
    cpy_r_r420 = CPyStatics[43]; /* 'append' */
    cpy_r_r421 = CPyStatics[244]; /* 0 */
    cpy_r_r422 = CPyObject_CallMethodObjArgs(cpy_r_photons, cpy_r_r420, cpy_r_r421, NULL);
    if (unlikely(cpy_r_r422 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 296, CPyStatic_globals);
        goto CPyL375;
    } else
        goto CPyL381;
CPyL197: ;
    cpy_r_r423 = CPyStatics[260]; /* -1 */
    cpy_r_r424 = PyObject_GetItem(cpy_r_points, cpy_r_r423);
    if (unlikely(cpy_r_r424 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 297, CPyStatic_globals);
        goto CPyL375;
    }
    cpy_r_cur_o = cpy_r_r424;
    cpy_r_r425 = PyNumber_Multiply(cpy_r_mean_free_path, cpy_r_u);
    if (unlikely(cpy_r_r425 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 298, CPyStatic_globals);
        goto CPyL382;
    }
    cpy_r_r426 = PyNumber_Add(cpy_r_cur_o, cpy_r_r425);
    CPy_DECREF(cpy_r_r425);
    if (unlikely(cpy_r_r426 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 298, CPyStatic_globals);
        goto CPyL382;
    }
    cpy_r_r427 = CPyStatics[41]; /* 'round' */
    cpy_r_r428 = CPyObject_CallMethodObjArgs(cpy_r_r426, cpy_r_r427, cpy_r_round_const, NULL);
    CPy_DECREF(cpy_r_r426);
    if (unlikely(cpy_r_r428 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 298, CPyStatic_globals);
        goto CPyL382;
    }
    cpy_r_next_o = cpy_r_r428;
    cpy_r_r429 = 1 ? Py_True : Py_False;
    CPy_INCREF(cpy_r_r429);
    cpy_r_inside_scint = cpy_r_r429;
    goto CPyL203;
CPyL202: ;
    cpy_r_r430 = 1 ? Py_True : Py_False;
    CPy_INCREF(cpy_r_r430);
    cpy_r_missed = cpy_r_r430;
    cpy_r_r431 = 0 ? Py_True : Py_False;
    CPy_INCREF(cpy_r_r431);
    cpy_r_inside_scint = cpy_r_r431;
    goto CPyL63;
CPyL203: ;
    cpy_r_r432 = PyNumber_Add(cpy_r_T1_z, cpy_r_T1_width);
    if (unlikely(cpy_r_r432 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 306, CPyStatic_globals);
        goto CPyL314;
    }
    cpy_r_r433 = CPyStatics[247]; /* 1 */
    cpy_r_r434.f0 = cpy_r_T1_z;
    cpy_r_r434.f1 = cpy_r_r432;
    cpy_r_r434.f2 = cpy_r_T1_radius;
    cpy_r_r434.f3 = cpy_r_T1_corner;
    cpy_r_r434.f4 = cpy_r_r433;
    CPy_INCREF(cpy_r_r434.f0);
    CPy_INCREF(cpy_r_r434.f1);
    CPy_INCREF(cpy_r_r434.f2);
    CPy_INCREF(cpy_r_r434.f3);
    CPy_INCREF(cpy_r_r434.f4);
    CPy_DECREF(cpy_r_r432);
    cpy_r_r435 = PyNumber_Add(cpy_r_T4_z, cpy_r_T4_width);
    if (unlikely(cpy_r_r435 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 306, CPyStatic_globals);
        goto CPyL383;
    }
    cpy_r_r436 = CPyStatics[248]; /* 4 */
    cpy_r_r437.f0 = cpy_r_T4_z;
    cpy_r_r437.f1 = cpy_r_r435;
    cpy_r_r437.f2 = cpy_r_T4_radius;
    cpy_r_r437.f3 = cpy_r_T4_corner;
    cpy_r_r437.f4 = cpy_r_r436;
    CPy_INCREF(cpy_r_r437.f0);
    CPy_INCREF(cpy_r_r437.f1);
    CPy_INCREF(cpy_r_r437.f2);
    CPy_INCREF(cpy_r_r437.f3);
    CPy_INCREF(cpy_r_r437.f4);
    CPy_DECREF(cpy_r_r435);
    cpy_r_r438 = PyList_New(2);
    if (unlikely(cpy_r_r438 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 306, CPyStatic_globals);
        goto CPyL384;
    }
    cpy_r_r439 = PyTuple_New(5);
    if (unlikely(cpy_r_r439 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp25 = cpy_r_r434.f0;
    PyTuple_SET_ITEM(cpy_r_r439, 0, __tmp25);
    PyObject *__tmp26 = cpy_r_r434.f1;
    PyTuple_SET_ITEM(cpy_r_r439, 1, __tmp26);
    PyObject *__tmp27 = cpy_r_r434.f2;
    PyTuple_SET_ITEM(cpy_r_r439, 2, __tmp27);
    PyObject *__tmp28 = cpy_r_r434.f3;
    PyTuple_SET_ITEM(cpy_r_r439, 3, __tmp28);
    PyObject *__tmp29 = cpy_r_r434.f4;
    PyTuple_SET_ITEM(cpy_r_r439, 4, __tmp29);
    cpy_r_r440 = PyTuple_New(5);
    if (unlikely(cpy_r_r440 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp30 = cpy_r_r437.f0;
    PyTuple_SET_ITEM(cpy_r_r440, 0, __tmp30);
    PyObject *__tmp31 = cpy_r_r437.f1;
    PyTuple_SET_ITEM(cpy_r_r440, 1, __tmp31);
    PyObject *__tmp32 = cpy_r_r437.f2;
    PyTuple_SET_ITEM(cpy_r_r440, 2, __tmp32);
    PyObject *__tmp33 = cpy_r_r437.f3;
    PyTuple_SET_ITEM(cpy_r_r440, 3, __tmp33);
    PyObject *__tmp34 = cpy_r_r437.f4;
    PyTuple_SET_ITEM(cpy_r_r440, 4, __tmp34);
    cpy_r_r441 = (CPyPtr)&((PyListObject *)cpy_r_r438)->ob_item;
    cpy_r_r442 = *(CPyPtr *)cpy_r_r441;
    *(PyObject * *)cpy_r_r442 = cpy_r_r439;
    cpy_r_r443 = cpy_r_r442 + 8;
    *(PyObject * *)cpy_r_r443 = cpy_r_r440;
    cpy_r_r444 = 0;
CPyL207: ;
    cpy_r_r445 = (CPyPtr)&((PyVarObject *)cpy_r_r438)->ob_size;
    cpy_r_r446 = *(int64_t *)cpy_r_r445;
    cpy_r_r447 = cpy_r_r446 << 1;
    cpy_r_r448 = (Py_ssize_t)cpy_r_r444 < (Py_ssize_t)cpy_r_r447;
    if (cpy_r_r448) {
        goto CPyL385;
    } else
        goto CPyL386;
CPyL208: ;
    cpy_r_r449 = CPyList_GetItemUnsafe(cpy_r_r438, cpy_r_r444);
    cpy_r_r450 = PyObject_GetIter(cpy_r_r449);
    CPy_DECREF(cpy_r_r449);
    if (unlikely(cpy_r_r450 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 306, CPyStatic_globals);
        goto CPyL387;
    }
    cpy_r_r451 = PyIter_Next(cpy_r_r450);
    if (cpy_r_r451 == NULL) {
        goto CPyL388;
    } else
        goto CPyL212;
CPyL210: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r452 = 0;
    if (unlikely(!cpy_r_r452)) {
        CPy_AddTraceback("modTof.py", "particle_path", 306, CPyStatic_globals);
        goto CPyL287;
    }
    CPy_Unreachable();
CPyL212: ;
    cpy_r_Tbottom = cpy_r_r451;
    cpy_r_r453 = PyIter_Next(cpy_r_r450);
    if (cpy_r_r453 == NULL) {
        goto CPyL389;
    } else
        goto CPyL215;
CPyL213: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r454 = 0;
    if (unlikely(!cpy_r_r454)) {
        CPy_AddTraceback("modTof.py", "particle_path", 306, CPyStatic_globals);
        goto CPyL287;
    }
    CPy_Unreachable();
CPyL215: ;
    cpy_r_Ttop = cpy_r_r453;
    cpy_r_r455 = PyIter_Next(cpy_r_r450);
    if (cpy_r_r455 == NULL) {
        goto CPyL390;
    } else
        goto CPyL218;
CPyL216: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r456 = 0;
    if (unlikely(!cpy_r_r456)) {
        CPy_AddTraceback("modTof.py", "particle_path", 306, CPyStatic_globals);
        goto CPyL287;
    }
    CPy_Unreachable();
CPyL218: ;
    cpy_r_Tradius = cpy_r_r455;
    cpy_r_r457 = PyIter_Next(cpy_r_r450);
    if (cpy_r_r457 == NULL) {
        goto CPyL391;
    } else
        goto CPyL221;
CPyL219: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r458 = 0;
    if (unlikely(!cpy_r_r458)) {
        CPy_AddTraceback("modTof.py", "particle_path", 306, CPyStatic_globals);
        goto CPyL287;
    }
    CPy_Unreachable();
CPyL221: ;
    cpy_r_Tcorner = cpy_r_r457;
    cpy_r_r459 = PyIter_Next(cpy_r_r450);
    if (cpy_r_r459 == NULL) {
        goto CPyL392;
    } else
        goto CPyL224;
CPyL222: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r460 = 0;
    if (unlikely(!cpy_r_r460)) {
        CPy_AddTraceback("modTof.py", "particle_path", 306, CPyStatic_globals);
        goto CPyL287;
    }
    CPy_Unreachable();
CPyL224: ;
    cpy_r_num = cpy_r_r459;
    cpy_r_r461 = PyIter_Next(cpy_r_r450);
    CPy_DECREF(cpy_r_r450);
    if (cpy_r_r461 == NULL) {
        goto CPyL227;
    } else
        goto CPyL393;
CPyL225: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r462 = 0;
    if (unlikely(!cpy_r_r462)) {
        CPy_AddTraceback("modTof.py", "particle_path", 306, CPyStatic_globals);
        goto CPyL287;
    }
    CPy_Unreachable();
CPyL227: ;
    cpy_r_r463 = CPyStatics[257]; /* 2 */
    cpy_r_r464 = PyObject_GetItem(cpy_r_next_o, cpy_r_r463);
    if (unlikely(cpy_r_r464 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 307, CPyStatic_globals);
        goto CPyL394;
    }
    cpy_r_r465 = PyObject_RichCompare(cpy_r_r464, cpy_r_Ttop, 1);
    CPy_DECREF(cpy_r_r464);
    if (unlikely(cpy_r_r465 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 307, CPyStatic_globals);
        goto CPyL394;
    }
    cpy_r_r466 = CPyStatics[257]; /* 2 */
    cpy_r_r467 = PyObject_GetItem(cpy_r_next_o, cpy_r_r466);
    if (unlikely(cpy_r_r467 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 307, CPyStatic_globals);
        goto CPyL395;
    }
    cpy_r_r468 = PyObject_RichCompare(cpy_r_r467, cpy_r_Tbottom, 5);
    CPy_DECREF(cpy_r_r467);
    if (unlikely(cpy_r_r468 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 307, CPyStatic_globals);
        goto CPyL395;
    }
    cpy_r_r469 = PyNumber_And(cpy_r_r465, cpy_r_r468);
    CPy_DECREF(cpy_r_r465);
    CPy_DECREF(cpy_r_r468);
    if (unlikely(cpy_r_r469 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 307, CPyStatic_globals);
        goto CPyL394;
    }
    cpy_r_r470 = CPyDef_Simulation___scint_condition(cpy_r_self, cpy_r_next_o, cpy_r_Tradius, cpy_r_num);
    if (unlikely(cpy_r_r470 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 307, CPyStatic_globals);
        goto CPyL396;
    }
    cpy_r_r471 = CPyDef_Simulation___lg_condition(cpy_r_self, cpy_r_next_o, cpy_r_Tcorner, cpy_r_num);
    if (unlikely(cpy_r_r471 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 307, CPyStatic_globals);
        goto CPyL397;
    }
    cpy_r_r472 = PyNumber_Or(cpy_r_r470, cpy_r_r471);
    CPy_DECREF(cpy_r_r470);
    CPy_DECREF(cpy_r_r471);
    if (unlikely(cpy_r_r472 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 307, CPyStatic_globals);
        goto CPyL396;
    }
    cpy_r_r473 = PyNumber_And(cpy_r_r469, cpy_r_r472);
    CPy_DECREF(cpy_r_r469);
    CPy_DECREF(cpy_r_r472);
    if (unlikely(cpy_r_r473 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 307, CPyStatic_globals);
        goto CPyL394;
    }
    cpy_r_inside_scint = cpy_r_r473;
CPyL237: ;
    cpy_r_r474 = PyObject_IsTrue(cpy_r_inside_scint);
    cpy_r_r475 = cpy_r_r474 >= 0;
    if (unlikely(!cpy_r_r475)) {
        CPy_AddTraceback("modTof.py", "particle_path", 263, CPyStatic_globals);
        goto CPyL398;
    }
    cpy_r_r476 = cpy_r_r474;
    if (cpy_r_r476) {
        goto CPyL399;
    } else
        goto CPyL400;
CPyL239: ;
    cpy_r_r477 = ((modTof___SimulationObject *)cpy_r_self)->_c;
    CPy_INCREF(cpy_r_r477);
    cpy_r_r478 = PyNumber_TrueDivide(cpy_r_mean_free_path, cpy_r_r477);
    CPy_DECREF(cpy_r_r477);
    if (unlikely(cpy_r_r478 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 310, CPyStatic_globals);
        goto CPyL401;
    }
    cpy_r_r479 = PyNumber_InPlaceAdd(cpy_r_t, cpy_r_r478);
    CPy_DECREF(cpy_r_t);
    CPy_DECREF(cpy_r_r478);
    if (unlikely(cpy_r_r479 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 310, CPyStatic_globals);
        goto CPyL402;
    }
    cpy_r_t = cpy_r_r479;
    cpy_r_r480 = CPyStatics[43]; /* 'append' */
    cpy_r_r481 = CPyObject_CallMethodObjArgs(cpy_r_times, cpy_r_r480, cpy_r_t, NULL);
    if (unlikely(cpy_r_r481 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 311, CPyStatic_globals);
        goto CPyL401;
    } else
        goto CPyL403;
CPyL242: ;
    cpy_r_r482 = PyNumber_Multiply(cpy_r_mean_free_path, cpy_r_u);
    if (unlikely(cpy_r_r482 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 312, CPyStatic_globals);
        goto CPyL401;
    }
    cpy_r_r483 = PyNumber_Add(cpy_r_cur_o, cpy_r_r482);
    CPy_DECREF(cpy_r_cur_o);
    CPy_DECREF(cpy_r_r482);
    if (unlikely(cpy_r_r483 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 312, CPyStatic_globals);
        goto CPyL404;
    }
    cpy_r_r484 = CPyStatics[43]; /* 'append' */
    cpy_r_r485 = CPyObject_CallMethodObjArgs(cpy_r_points, cpy_r_r484, cpy_r_r483, NULL);
    CPy_DECREF(cpy_r_r483);
    if (unlikely(cpy_r_r485 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 312, CPyStatic_globals);
        goto CPyL404;
    } else
        goto CPyL405;
CPyL245: ;
    cpy_r_r486 = CPyModule_numpy;
    cpy_r_r487 = CPyStatics[36]; /* 'random' */
    cpy_r_r488 = CPyObject_GetAttr(cpy_r_r486, cpy_r_r487);
    if (unlikely(cpy_r_r488 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 313, CPyStatic_globals);
        goto CPyL404;
    }
    cpy_r_r489 = CPyStatics[44]; /* 'poisson' */
    cpy_r_r490 = CPyObject_GetAttr(cpy_r_r488, cpy_r_r489);
    CPy_DECREF(cpy_r_r488);
    if (unlikely(cpy_r_r490 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 313, CPyStatic_globals);
        goto CPyL404;
    }
    PyObject *cpy_r_r491[1] = {cpy_r_photons_per_E};
    cpy_r_r492 = (PyObject **)&cpy_r_r491;
    cpy_r_r493 = _PyObject_Vectorcall(cpy_r_r490, cpy_r_r492, 1, 0);
    CPy_DECREF(cpy_r_r490);
    if (unlikely(cpy_r_r493 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 313, CPyStatic_globals);
        goto CPyL404;
    }
    cpy_r_phot = cpy_r_r493;
    cpy_r_r494 = CPyModule_numpy;
    cpy_r_r495 = CPyStatics[36]; /* 'random' */
    cpy_r_r496 = CPyObject_GetAttr(cpy_r_r494, cpy_r_r495);
    if (unlikely(cpy_r_r496 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 314, CPyStatic_globals);
        goto CPyL406;
    }
    cpy_r_r497 = CPyStatics[36]; /* 'random' */
    cpy_r_r498 = CPyObject_GetAttr(cpy_r_r496, cpy_r_r497);
    CPy_DECREF(cpy_r_r496);
    if (unlikely(cpy_r_r498 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 314, CPyStatic_globals);
        goto CPyL406;
    }
    cpy_r_r499 = _PyObject_Vectorcall(cpy_r_r498, 0, 0, 0);
    CPy_DECREF(cpy_r_r498);
    if (unlikely(cpy_r_r499 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 314, CPyStatic_globals);
        goto CPyL406;
    }
    cpy_r_r500 = PyObject_RichCompare(cpy_r_r499, cpy_r_prob_scint, 0);
    CPy_DECREF(cpy_r_r499);
    if (unlikely(cpy_r_r500 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 314, CPyStatic_globals);
        goto CPyL406;
    }
    cpy_r_r501 = PyObject_IsTrue(cpy_r_r500);
    CPy_DECREF(cpy_r_r500);
    cpy_r_r502 = cpy_r_r501 >= 0;
    if (unlikely(!cpy_r_r502)) {
        CPy_AddTraceback("modTof.py", "particle_path", 314, CPyStatic_globals);
        goto CPyL406;
    }
    cpy_r_r503 = cpy_r_r501;
    if (!cpy_r_r503) goto CPyL407;
    cpy_r_r504 = CPyStatics[43]; /* 'append' */
    cpy_r_r505 = CPyObject_CallMethodObjArgs(cpy_r_photons, cpy_r_r504, cpy_r_phot, NULL);
    CPy_DECREF(cpy_r_phot);
    if (unlikely(cpy_r_r505 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 314, CPyStatic_globals);
        goto CPyL404;
    } else
        goto CPyL408;
CPyL255: ;
    cpy_r_r506 = CPyStatics[43]; /* 'append' */
    cpy_r_r507 = CPyStatics[244]; /* 0 */
    cpy_r_r508 = CPyObject_CallMethodObjArgs(cpy_r_photons, cpy_r_r506, cpy_r_r507, NULL);
    if (unlikely(cpy_r_r508 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 315, CPyStatic_globals);
        goto CPyL404;
    } else
        goto CPyL409;
CPyL256: ;
    cpy_r_r509 = CPyStatics[260]; /* -1 */
    cpy_r_r510 = PyObject_GetItem(cpy_r_points, cpy_r_r509);
    if (unlikely(cpy_r_r510 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 316, CPyStatic_globals);
        goto CPyL404;
    }
    cpy_r_cur_o = cpy_r_r510;
    cpy_r_r511 = PyNumber_Multiply(cpy_r_mean_free_path, cpy_r_u);
    if (unlikely(cpy_r_r511 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 317, CPyStatic_globals);
        goto CPyL401;
    }
    cpy_r_r512 = PyNumber_Add(cpy_r_cur_o, cpy_r_r511);
    CPy_DECREF(cpy_r_r511);
    if (unlikely(cpy_r_r512 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 317, CPyStatic_globals);
        goto CPyL401;
    }
    cpy_r_r513 = CPyStatics[41]; /* 'round' */
    cpy_r_r514 = CPyObject_CallMethodObjArgs(cpy_r_r512, cpy_r_r513, cpy_r_round_const, NULL);
    CPy_DECREF(cpy_r_r512);
    if (unlikely(cpy_r_r514 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 317, CPyStatic_globals);
        goto CPyL401;
    }
    cpy_r_next_o = cpy_r_r514;
    cpy_r_r515 = CPyStatics[257]; /* 2 */
    cpy_r_r516 = PyObject_GetItem(cpy_r_next_o, cpy_r_r515);
    if (unlikely(cpy_r_r516 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 318, CPyStatic_globals);
        goto CPyL394;
    }
    cpy_r_r517 = PyObject_RichCompare(cpy_r_r516, cpy_r_Ttop, 1);
    CPy_DECREF(cpy_r_r516);
    if (unlikely(cpy_r_r517 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 318, CPyStatic_globals);
        goto CPyL394;
    }
    cpy_r_r518 = CPyStatics[257]; /* 2 */
    cpy_r_r519 = PyObject_GetItem(cpy_r_next_o, cpy_r_r518);
    if (unlikely(cpy_r_r519 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 318, CPyStatic_globals);
        goto CPyL410;
    }
    cpy_r_r520 = PyObject_RichCompare(cpy_r_r519, cpy_r_Tbottom, 5);
    CPy_DECREF(cpy_r_r519);
    if (unlikely(cpy_r_r520 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 318, CPyStatic_globals);
        goto CPyL410;
    }
    cpy_r_r521 = PyNumber_And(cpy_r_r517, cpy_r_r520);
    CPy_DECREF(cpy_r_r517);
    CPy_DECREF(cpy_r_r520);
    if (unlikely(cpy_r_r521 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 318, CPyStatic_globals);
        goto CPyL394;
    }
    cpy_r_r522 = CPyDef_Simulation___scint_condition(cpy_r_self, cpy_r_next_o, cpy_r_Tradius, cpy_r_num);
    if (unlikely(cpy_r_r522 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 318, CPyStatic_globals);
        goto CPyL411;
    }
    cpy_r_r523 = CPyDef_Simulation___lg_condition(cpy_r_self, cpy_r_next_o, cpy_r_Tcorner, cpy_r_num);
    if (unlikely(cpy_r_r523 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 318, CPyStatic_globals);
        goto CPyL412;
    }
    cpy_r_r524 = PyNumber_Or(cpy_r_r522, cpy_r_r523);
    CPy_DECREF(cpy_r_r522);
    CPy_DECREF(cpy_r_r523);
    if (unlikely(cpy_r_r524 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 318, CPyStatic_globals);
        goto CPyL411;
    }
    cpy_r_r525 = PyNumber_And(cpy_r_r521, cpy_r_r524);
    CPy_DECREF(cpy_r_r521);
    CPy_DECREF(cpy_r_r524);
    if (unlikely(cpy_r_r525 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 318, CPyStatic_globals);
        goto CPyL394;
    }
    cpy_r_inside_scint = cpy_r_r525;
    goto CPyL237;
CPyL270: ;
    cpy_r_r526 = cpy_r_r444 + 2;
    cpy_r_r444 = cpy_r_r526;
    goto CPyL207;
CPyL271: ;
    cpy_r_r527 = CPyModule_numpy;
    cpy_r_r528 = CPyStatics[39]; /* 'float64' */
    cpy_r_r529 = CPyObject_GetAttr(cpy_r_r527, cpy_r_r528);
    if (unlikely(cpy_r_r529 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 320, CPyStatic_globals);
        goto CPyL413;
    }
    cpy_r_r530 = CPyModule_numpy;
    cpy_r_r531 = CPyStatics[32]; /* 'array' */
    cpy_r_r532 = CPyObject_GetAttr(cpy_r_r530, cpy_r_r531);
    if (unlikely(cpy_r_r532 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 320, CPyStatic_globals);
        goto CPyL414;
    }
    PyObject *cpy_r_r533[2] = {cpy_r_times, cpy_r_r529};
    cpy_r_r534 = (PyObject **)&cpy_r_r533;
    cpy_r_r535 = CPyStatics[264]; /* ('dtype',) */
    cpy_r_r536 = _PyObject_Vectorcall(cpy_r_r532, cpy_r_r534, 1, cpy_r_r535);
    CPy_DECREF(cpy_r_r532);
    if (unlikely(cpy_r_r536 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 320, CPyStatic_globals);
        goto CPyL414;
    }
    CPy_DECREF(cpy_r_times);
    CPy_DECREF(cpy_r_r529);
    cpy_r_r537 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r538 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r539 = CPyStatics[247]; /* 1 */
    cpy_r_r540 = PySlice_New(cpy_r_r539, cpy_r_r537, cpy_r_r538);
    if (unlikely(cpy_r_r540 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 320, CPyStatic_globals);
        goto CPyL415;
    }
    cpy_r_r541 = PyObject_GetItem(cpy_r_r536, cpy_r_r540);
    CPy_DECREF(cpy_r_r536);
    CPy_DECREF(cpy_r_r540);
    if (unlikely(cpy_r_r541 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 320, CPyStatic_globals);
        goto CPyL416;
    }
    cpy_r_r542 = CPyModule_numpy;
    cpy_r_r543 = CPyStatics[39]; /* 'float64' */
    cpy_r_r544 = CPyObject_GetAttr(cpy_r_r542, cpy_r_r543);
    if (unlikely(cpy_r_r544 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 320, CPyStatic_globals);
        goto CPyL417;
    }
    cpy_r_r545 = CPyModule_numpy;
    cpy_r_r546 = CPyStatics[32]; /* 'array' */
    cpy_r_r547 = CPyObject_GetAttr(cpy_r_r545, cpy_r_r546);
    if (unlikely(cpy_r_r547 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 320, CPyStatic_globals);
        goto CPyL418;
    }
    PyObject *cpy_r_r548[2] = {cpy_r_points, cpy_r_r544};
    cpy_r_r549 = (PyObject **)&cpy_r_r548;
    cpy_r_r550 = CPyStatics[264]; /* ('dtype',) */
    cpy_r_r551 = _PyObject_Vectorcall(cpy_r_r547, cpy_r_r549, 1, cpy_r_r550);
    CPy_DECREF(cpy_r_r547);
    if (unlikely(cpy_r_r551 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 320, CPyStatic_globals);
        goto CPyL418;
    }
    CPy_DECREF(cpy_r_points);
    CPy_DECREF(cpy_r_r544);
    cpy_r_r552 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r553 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r554 = CPyStatics[247]; /* 1 */
    cpy_r_r555 = PySlice_New(cpy_r_r554, cpy_r_r552, cpy_r_r553);
    if (unlikely(cpy_r_r555 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 320, CPyStatic_globals);
        goto CPyL419;
    }
    cpy_r_r556 = PyObject_GetItem(cpy_r_r551, cpy_r_r555);
    CPy_DECREF(cpy_r_r551);
    CPy_DECREF(cpy_r_r555);
    if (unlikely(cpy_r_r556 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 320, CPyStatic_globals);
        goto CPyL420;
    }
    cpy_r_r557 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r558 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r559 = CPyStatics[247]; /* 1 */
    cpy_r_r560 = PySlice_New(cpy_r_r559, cpy_r_r557, cpy_r_r558);
    if (unlikely(cpy_r_r560 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 320, CPyStatic_globals);
        goto CPyL421;
    }
    cpy_r_r561 = PyObject_GetItem(cpy_r_photons, cpy_r_r560);
    CPy_DECREF(cpy_r_photons);
    CPy_DECREF(cpy_r_r560);
    if (unlikely(cpy_r_r561 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 320, CPyStatic_globals);
        goto CPyL422;
    }
    cpy_r_r562 = CPyModule_numpy;
    cpy_r_r563 = CPyStatics[39]; /* 'float64' */
    cpy_r_r564 = CPyObject_GetAttr(cpy_r_r562, cpy_r_r563);
    if (unlikely(cpy_r_r564 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 320, CPyStatic_globals);
        goto CPyL423;
    }
    cpy_r_r565 = CPyModule_numpy;
    cpy_r_r566 = CPyStatics[32]; /* 'array' */
    cpy_r_r567 = CPyObject_GetAttr(cpy_r_r565, cpy_r_r566);
    if (unlikely(cpy_r_r567 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 320, CPyStatic_globals);
        goto CPyL424;
    }
    PyObject *cpy_r_r568[2] = {cpy_r_r561, cpy_r_r564};
    cpy_r_r569 = (PyObject **)&cpy_r_r568;
    cpy_r_r570 = CPyStatics[264]; /* ('dtype',) */
    cpy_r_r571 = _PyObject_Vectorcall(cpy_r_r567, cpy_r_r569, 1, cpy_r_r570);
    CPy_DECREF(cpy_r_r567);
    if (unlikely(cpy_r_r571 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_path", 320, CPyStatic_globals);
        goto CPyL424;
    }
    CPy_DECREF(cpy_r_r561);
    CPy_DECREF(cpy_r_r564);
    cpy_r_r572.f0 = cpy_r_r541;
    cpy_r_r572.f1 = cpy_r_r556;
    cpy_r_r572.f2 = cpy_r_r571;
    CPy_INCREF(cpy_r_r572.f0);
    CPy_INCREF(cpy_r_r572.f1);
    CPy_INCREF(cpy_r_r572.f2);
    CPy_DECREF(cpy_r_r541);
    CPy_DECREF(cpy_r_r556);
    CPy_DECREF(cpy_r_r571);
    cpy_r_r573 = PyTuple_New(3);
    if (unlikely(cpy_r_r573 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp35 = cpy_r_r572.f0;
    PyTuple_SET_ITEM(cpy_r_r573, 0, __tmp35);
    PyObject *__tmp36 = cpy_r_r572.f1;
    PyTuple_SET_ITEM(cpy_r_r573, 1, __tmp36);
    PyObject *__tmp37 = cpy_r_r572.f2;
    PyTuple_SET_ITEM(cpy_r_r573, 2, __tmp37);
    return cpy_r_r573;
CPyL287: ;
    cpy_r_r574 = NULL;
    return cpy_r_r574;
CPyL288: ;
    CPy_DecRef(cpy_r_r6);
    goto CPyL287;
CPyL289: ;
    CPy_DecRef(cpy_r_theta);
    goto CPyL287;
CPyL290: ;
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_r34);
    goto CPyL287;
CPyL291: ;
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_r34);
    CPy_DecRef(cpy_r_r54);
    goto CPyL287;
CPyL292: ;
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    goto CPyL287;
CPyL293: ;
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_maxdist);
    goto CPyL287;
CPyL294: ;
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_maxdist);
    CPy_DecRef(cpy_r_round_const);
    goto CPyL287;
CPyL295: ;
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_maxdist);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_r76);
    goto CPyL287;
CPyL296: ;
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_r76);
    goto CPyL287;
CPyL297: ;
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_r85.f0);
    CPy_DecRef(cpy_r_r85.f1);
    CPy_DecRef(cpy_r_r85.f2);
    goto CPyL287;
CPyL298: ;
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_r89);
    goto CPyL287;
CPyL299: ;
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    goto CPyL287;
CPyL300: ;
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_r98);
    goto CPyL287;
CPyL301: ;
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_r105);
    goto CPyL287;
CPyL302: ;
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_r105);
    CPy_DecRef(cpy_r_r111);
    goto CPyL287;
CPyL303: ;
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_r105);
    goto CPyL287;
CPyL304: ;
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_r105);
    CPy_DecRef(cpy_r_r118);
    goto CPyL287;
CPyL305: ;
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_r125.f0);
    CPy_DecRef(cpy_r_r125.f1);
    CPy_DecRef(cpy_r_r125.f2);
    goto CPyL287;
CPyL306: ;
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_r125.f0);
    CPy_DecRef(cpy_r_r125.f1);
    CPy_DecRef(cpy_r_r125.f2);
    CPy_DecRef(cpy_r_r128);
    goto CPyL287;
CPyL307: ;
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_r128);
    CPy_DecRef(cpy_r_r132);
    goto CPyL287;
CPyL308: ;
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_u);
    goto CPyL287;
CPyL309: ;
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    goto CPyL287;
CPyL310: ;
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    goto CPyL287;
CPyL311: ;
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    goto CPyL287;
CPyL312: ;
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    goto CPyL287;
CPyL313: ;
    CPy_INCREF(cpy_r_t);
    goto CPyL63;
CPyL314: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_inside_scint);
    CPy_DecRef(cpy_r_missed);
    goto CPyL287;
CPyL315: ;
    CPy_DECREF(cpy_r_t);
    CPy_DECREF(cpy_r_round_const);
    CPy_DECREF(cpy_r_u);
    CPy_DECREF(cpy_r_cur_o);
    CPy_DECREF(cpy_r_next_o);
    CPy_DECREF(cpy_r_inside_scint);
    CPy_DECREF(cpy_r_missed);
    goto CPyL271;
CPyL316: ;
    CPy_DECREF(cpy_r_inside_scint);
    goto CPyL69;
CPyL317: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    goto CPyL287;
CPyL318: ;
    CPy_DECREF(cpy_r_round_const);
    CPy_DECREF(cpy_r_u);
    CPy_DECREF(cpy_r_cur_o);
    CPy_DECREF(cpy_r_next_o);
    CPy_DECREF(cpy_r_missed);
    goto CPyL71;
CPyL319: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    goto CPyL287;
CPyL320: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_r173);
    goto CPyL287;
CPyL321: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    goto CPyL287;
CPyL322: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_r201);
    goto CPyL287;
CPyL323: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_r201);
    CPy_DecRef(cpy_r_r221);
    goto CPyL287;
CPyL324: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    goto CPyL287;
CPyL325: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_maxdist);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    goto CPyL287;
CPyL326: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_maxdist);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    goto CPyL287;
CPyL327: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_maxdist);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_r244);
    goto CPyL287;
CPyL328: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_r244);
    goto CPyL287;
CPyL329: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_r244);
    CPy_DecRef(cpy_r_r251);
    goto CPyL287;
CPyL330: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_r255.f0);
    CPy_DecRef(cpy_r_r255.f1);
    CPy_DecRef(cpy_r_r255.f2);
    goto CPyL287;
CPyL331: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_r259);
    goto CPyL287;
CPyL332: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    goto CPyL287;
CPyL333: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_r268);
    goto CPyL287;
CPyL334: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_r275);
    goto CPyL287;
CPyL335: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_r275);
    CPy_DecRef(cpy_r_r281);
    goto CPyL287;
CPyL336: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_r275);
    goto CPyL287;
CPyL337: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_r275);
    CPy_DecRef(cpy_r_r288);
    goto CPyL287;
CPyL338: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_r295.f0);
    CPy_DecRef(cpy_r_r295.f1);
    CPy_DecRef(cpy_r_r295.f2);
    goto CPyL287;
CPyL339: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_r295.f0);
    CPy_DecRef(cpy_r_r295.f1);
    CPy_DecRef(cpy_r_r295.f2);
    CPy_DecRef(cpy_r_r298);
    goto CPyL287;
CPyL340: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_r298);
    CPy_DecRef(cpy_r_r302);
    goto CPyL287;
CPyL341: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    goto CPyL287;
CPyL342: ;
    CPy_DECREF(cpy_r_r308);
    goto CPyL130;
CPyL343: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_times);
    goto CPyL287;
CPyL344: ;
    CPy_DECREF(cpy_r_r310);
    goto CPyL131;
CPyL345: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_u);
    goto CPyL287;
CPyL346: ;
    CPy_DECREF(cpy_r_r312);
    goto CPyL132;
CPyL347: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    goto CPyL287;
CPyL348: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    goto CPyL287;
CPyL349: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    goto CPyL287;
CPyL350: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    goto CPyL287;
CPyL351: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_r330);
    goto CPyL287;
CPyL352: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_r333);
    goto CPyL287;
CPyL353: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_r336);
    goto CPyL287;
CPyL354: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_distT1);
    goto CPyL287;
CPyL355: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_distT1);
    CPy_DecRef(cpy_r_r343);
    goto CPyL287;
CPyL356: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_distT1);
    CPy_DecRef(cpy_r_r346);
    goto CPyL287;
CPyL357: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_distT1);
    CPy_DecRef(cpy_r_r349);
    goto CPyL287;
CPyL358: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_distT1);
    CPy_DecRef(cpy_r_distT4);
    goto CPyL287;
CPyL359: ;
    CPy_DECREF(cpy_r_distT1);
    goto CPyL158;
CPyL360: ;
    CPy_DECREF(cpy_r_distT4);
    goto CPyL159;
CPyL361: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_dist);
    goto CPyL287;
CPyL362: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_dist);
    CPy_DecRef(cpy_r_check);
    goto CPyL287;
CPyL363: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_dist);
    CPy_DecRef(cpy_r_check);
    CPy_DecRef(cpy_r_r368);
    goto CPyL287;
CPyL364: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_dist);
    CPy_DecRef(cpy_r_check);
    CPy_DecRef(cpy_r_inside_T1);
    goto CPyL287;
CPyL365: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_dist);
    CPy_DecRef(cpy_r_check);
    CPy_DecRef(cpy_r_inside_T1);
    CPy_DecRef(cpy_r_r373);
    goto CPyL287;
CPyL366: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_dist);
    CPy_DecRef(cpy_r_inside_T1);
    CPy_DecRef(cpy_r_inside_T4);
    goto CPyL287;
CPyL367: ;
    CPy_DECREF(cpy_r_inside_T1);
    goto CPyL173;
CPyL368: ;
    CPy_DECREF(cpy_r_inside_T4);
    goto CPyL174;
CPyL369: ;
    CPy_DECREF(cpy_r_cur_o);
    CPy_DECREF(cpy_r_next_o);
    goto CPyL177;
CPyL370: ;
    CPy_DECREF(cpy_r_missed);
    CPy_DECREF(cpy_r_dist);
    goto CPyL202;
CPyL371: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_dist);
    goto CPyL287;
CPyL372: ;
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_dist);
    goto CPyL287;
CPyL373: ;
    CPy_DECREF(cpy_r_r391);
    goto CPyL180;
CPyL374: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_r393);
    goto CPyL287;
CPyL375: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_missed);
    goto CPyL287;
CPyL376: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_r395);
    goto CPyL287;
CPyL377: ;
    CPy_DECREF(cpy_r_r399);
    goto CPyL186;
CPyL378: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_phot);
    goto CPyL287;
CPyL379: ;
    CPy_DECREF(cpy_r_phot);
    goto CPyL196;
CPyL380: ;
    CPy_DECREF(cpy_r_r419);
    goto CPyL197;
CPyL381: ;
    CPy_DECREF(cpy_r_r422);
    goto CPyL197;
CPyL382: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_missed);
    goto CPyL287;
CPyL383: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_inside_scint);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_r434.f0);
    CPy_DecRef(cpy_r_r434.f1);
    CPy_DecRef(cpy_r_r434.f2);
    CPy_DecRef(cpy_r_r434.f3);
    CPy_DecRef(cpy_r_r434.f4);
    goto CPyL287;
CPyL384: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_inside_scint);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_r434.f0);
    CPy_DecRef(cpy_r_r434.f1);
    CPy_DecRef(cpy_r_r434.f2);
    CPy_DecRef(cpy_r_r434.f3);
    CPy_DecRef(cpy_r_r434.f4);
    CPy_DecRef(cpy_r_r437.f0);
    CPy_DecRef(cpy_r_r437.f1);
    CPy_DecRef(cpy_r_r437.f2);
    CPy_DecRef(cpy_r_r437.f3);
    CPy_DecRef(cpy_r_r437.f4);
    goto CPyL287;
CPyL385: ;
    CPy_DECREF(cpy_r_inside_scint);
    goto CPyL208;
CPyL386: ;
    CPy_DECREF(cpy_r_r438);
    goto CPyL63;
CPyL387: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_r438);
    goto CPyL287;
CPyL388: ;
    CPy_DECREF(cpy_r_t);
    CPy_DECREF(cpy_r_round_const);
    CPy_DECREF(cpy_r_u);
    CPy_DECREF(cpy_r_photons);
    CPy_DECREF(cpy_r_points);
    CPy_DECREF(cpy_r_times);
    CPy_DECREF(cpy_r_cur_o);
    CPy_DECREF(cpy_r_next_o);
    CPy_DECREF(cpy_r_missed);
    CPy_DECREF(cpy_r_r438);
    CPy_DECREF(cpy_r_r450);
    goto CPyL210;
CPyL389: ;
    CPy_DECREF(cpy_r_t);
    CPy_DECREF(cpy_r_round_const);
    CPy_DECREF(cpy_r_u);
    CPy_DECREF(cpy_r_photons);
    CPy_DECREF(cpy_r_points);
    CPy_DECREF(cpy_r_times);
    CPy_DECREF(cpy_r_cur_o);
    CPy_DECREF(cpy_r_next_o);
    CPy_DECREF(cpy_r_missed);
    CPy_DECREF(cpy_r_r438);
    CPy_DECREF(cpy_r_r450);
    CPy_DECREF(cpy_r_Tbottom);
    goto CPyL213;
CPyL390: ;
    CPy_DECREF(cpy_r_t);
    CPy_DECREF(cpy_r_round_const);
    CPy_DECREF(cpy_r_u);
    CPy_DECREF(cpy_r_photons);
    CPy_DECREF(cpy_r_points);
    CPy_DECREF(cpy_r_times);
    CPy_DECREF(cpy_r_cur_o);
    CPy_DECREF(cpy_r_next_o);
    CPy_DECREF(cpy_r_missed);
    CPy_DECREF(cpy_r_r438);
    CPy_DECREF(cpy_r_r450);
    CPy_DECREF(cpy_r_Tbottom);
    CPy_DECREF(cpy_r_Ttop);
    goto CPyL216;
CPyL391: ;
    CPy_DECREF(cpy_r_t);
    CPy_DECREF(cpy_r_round_const);
    CPy_DECREF(cpy_r_u);
    CPy_DECREF(cpy_r_photons);
    CPy_DECREF(cpy_r_points);
    CPy_DECREF(cpy_r_times);
    CPy_DECREF(cpy_r_cur_o);
    CPy_DECREF(cpy_r_next_o);
    CPy_DECREF(cpy_r_missed);
    CPy_DECREF(cpy_r_r438);
    CPy_DECREF(cpy_r_r450);
    CPy_DECREF(cpy_r_Tbottom);
    CPy_DECREF(cpy_r_Ttop);
    CPy_DECREF(cpy_r_Tradius);
    goto CPyL219;
CPyL392: ;
    CPy_DECREF(cpy_r_t);
    CPy_DECREF(cpy_r_round_const);
    CPy_DECREF(cpy_r_u);
    CPy_DECREF(cpy_r_photons);
    CPy_DECREF(cpy_r_points);
    CPy_DECREF(cpy_r_times);
    CPy_DECREF(cpy_r_cur_o);
    CPy_DECREF(cpy_r_next_o);
    CPy_DECREF(cpy_r_missed);
    CPy_DECREF(cpy_r_r438);
    CPy_DECREF(cpy_r_r450);
    CPy_DECREF(cpy_r_Tbottom);
    CPy_DECREF(cpy_r_Ttop);
    CPy_DECREF(cpy_r_Tradius);
    CPy_DECREF(cpy_r_Tcorner);
    goto CPyL222;
CPyL393: ;
    CPy_DECREF(cpy_r_t);
    CPy_DECREF(cpy_r_round_const);
    CPy_DECREF(cpy_r_u);
    CPy_DECREF(cpy_r_photons);
    CPy_DECREF(cpy_r_points);
    CPy_DECREF(cpy_r_times);
    CPy_DECREF(cpy_r_cur_o);
    CPy_DECREF(cpy_r_next_o);
    CPy_DECREF(cpy_r_missed);
    CPy_DECREF(cpy_r_r438);
    CPy_DECREF(cpy_r_Tbottom);
    CPy_DECREF(cpy_r_Ttop);
    CPy_DECREF(cpy_r_Tradius);
    CPy_DECREF(cpy_r_Tcorner);
    CPy_DECREF(cpy_r_num);
    CPy_DECREF(cpy_r_r461);
    goto CPyL225;
CPyL394: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_r438);
    CPy_DecRef(cpy_r_Tbottom);
    CPy_DecRef(cpy_r_Ttop);
    CPy_DecRef(cpy_r_Tradius);
    CPy_DecRef(cpy_r_Tcorner);
    CPy_DecRef(cpy_r_num);
    goto CPyL287;
CPyL395: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_r438);
    CPy_DecRef(cpy_r_Tbottom);
    CPy_DecRef(cpy_r_Ttop);
    CPy_DecRef(cpy_r_Tradius);
    CPy_DecRef(cpy_r_Tcorner);
    CPy_DecRef(cpy_r_num);
    CPy_DecRef(cpy_r_r465);
    goto CPyL287;
CPyL396: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_r438);
    CPy_DecRef(cpy_r_Tbottom);
    CPy_DecRef(cpy_r_Ttop);
    CPy_DecRef(cpy_r_Tradius);
    CPy_DecRef(cpy_r_Tcorner);
    CPy_DecRef(cpy_r_num);
    CPy_DecRef(cpy_r_r469);
    goto CPyL287;
CPyL397: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_r438);
    CPy_DecRef(cpy_r_Tbottom);
    CPy_DecRef(cpy_r_Ttop);
    CPy_DecRef(cpy_r_Tradius);
    CPy_DecRef(cpy_r_Tcorner);
    CPy_DecRef(cpy_r_num);
    CPy_DecRef(cpy_r_r469);
    CPy_DecRef(cpy_r_r470);
    goto CPyL287;
CPyL398: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_inside_scint);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_r438);
    CPy_DecRef(cpy_r_Tbottom);
    CPy_DecRef(cpy_r_Ttop);
    CPy_DecRef(cpy_r_Tradius);
    CPy_DecRef(cpy_r_Tcorner);
    CPy_DecRef(cpy_r_num);
    goto CPyL287;
CPyL399: ;
    CPy_DECREF(cpy_r_next_o);
    CPy_DECREF(cpy_r_inside_scint);
    goto CPyL239;
CPyL400: ;
    CPy_DECREF(cpy_r_Tbottom);
    CPy_DECREF(cpy_r_Ttop);
    CPy_DECREF(cpy_r_Tradius);
    CPy_DECREF(cpy_r_Tcorner);
    CPy_DECREF(cpy_r_num);
    goto CPyL270;
CPyL401: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_r438);
    CPy_DecRef(cpy_r_Tbottom);
    CPy_DecRef(cpy_r_Ttop);
    CPy_DecRef(cpy_r_Tradius);
    CPy_DecRef(cpy_r_Tcorner);
    CPy_DecRef(cpy_r_num);
    goto CPyL287;
CPyL402: ;
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_r438);
    CPy_DecRef(cpy_r_Tbottom);
    CPy_DecRef(cpy_r_Ttop);
    CPy_DecRef(cpy_r_Tradius);
    CPy_DecRef(cpy_r_Tcorner);
    CPy_DecRef(cpy_r_num);
    goto CPyL287;
CPyL403: ;
    CPy_DECREF(cpy_r_r481);
    goto CPyL242;
CPyL404: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_r438);
    CPy_DecRef(cpy_r_Tbottom);
    CPy_DecRef(cpy_r_Ttop);
    CPy_DecRef(cpy_r_Tradius);
    CPy_DecRef(cpy_r_Tcorner);
    CPy_DecRef(cpy_r_num);
    goto CPyL287;
CPyL405: ;
    CPy_DECREF(cpy_r_r485);
    goto CPyL245;
CPyL406: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_phot);
    CPy_DecRef(cpy_r_r438);
    CPy_DecRef(cpy_r_Tbottom);
    CPy_DecRef(cpy_r_Ttop);
    CPy_DecRef(cpy_r_Tradius);
    CPy_DecRef(cpy_r_Tcorner);
    CPy_DecRef(cpy_r_num);
    goto CPyL287;
CPyL407: ;
    CPy_DECREF(cpy_r_phot);
    goto CPyL255;
CPyL408: ;
    CPy_DECREF(cpy_r_r505);
    goto CPyL256;
CPyL409: ;
    CPy_DECREF(cpy_r_r508);
    goto CPyL256;
CPyL410: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_r438);
    CPy_DecRef(cpy_r_Tbottom);
    CPy_DecRef(cpy_r_Ttop);
    CPy_DecRef(cpy_r_Tradius);
    CPy_DecRef(cpy_r_Tcorner);
    CPy_DecRef(cpy_r_num);
    CPy_DecRef(cpy_r_r517);
    goto CPyL287;
CPyL411: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_r438);
    CPy_DecRef(cpy_r_Tbottom);
    CPy_DecRef(cpy_r_Ttop);
    CPy_DecRef(cpy_r_Tradius);
    CPy_DecRef(cpy_r_Tcorner);
    CPy_DecRef(cpy_r_num);
    CPy_DecRef(cpy_r_r521);
    goto CPyL287;
CPyL412: ;
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_round_const);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_cur_o);
    CPy_DecRef(cpy_r_next_o);
    CPy_DecRef(cpy_r_missed);
    CPy_DecRef(cpy_r_r438);
    CPy_DecRef(cpy_r_Tbottom);
    CPy_DecRef(cpy_r_Ttop);
    CPy_DecRef(cpy_r_Tradius);
    CPy_DecRef(cpy_r_Tcorner);
    CPy_DecRef(cpy_r_num);
    CPy_DecRef(cpy_r_r521);
    CPy_DecRef(cpy_r_r522);
    goto CPyL287;
CPyL413: ;
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    goto CPyL287;
CPyL414: ;
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_r529);
    goto CPyL287;
CPyL415: ;
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_r536);
    goto CPyL287;
CPyL416: ;
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    goto CPyL287;
CPyL417: ;
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_r541);
    goto CPyL287;
CPyL418: ;
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_r541);
    CPy_DecRef(cpy_r_r544);
    goto CPyL287;
CPyL419: ;
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_r541);
    CPy_DecRef(cpy_r_r551);
    goto CPyL287;
CPyL420: ;
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_r541);
    goto CPyL287;
CPyL421: ;
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_r541);
    CPy_DecRef(cpy_r_r556);
    goto CPyL287;
CPyL422: ;
    CPy_DecRef(cpy_r_r541);
    CPy_DecRef(cpy_r_r556);
    goto CPyL287;
CPyL423: ;
    CPy_DecRef(cpy_r_r541);
    CPy_DecRef(cpy_r_r556);
    CPy_DecRef(cpy_r_r561);
    goto CPyL287;
CPyL424: ;
    CPy_DecRef(cpy_r_r541);
    CPy_DecRef(cpy_r_r556);
    CPy_DecRef(cpy_r_r561);
    CPy_DecRef(cpy_r_r564);
    goto CPyL287;
}

PyObject *CPyPy_Simulation___particle_path(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"t", "phi_range_deg", "T1_z", "T1_width", "T4_z", "T4_width", "T1_radius", "T4_radius", "T1_corner", "T4_corner", "mean_free_path", "photons_per_E", "prob_scint", 0};
    static CPyArg_Parser parser = {"OOOOOOOOOOOOO:particle_path", kwlist, 0};
    PyObject *obj_t;
    PyObject *obj_phi_range_deg;
    PyObject *obj_T1_z;
    PyObject *obj_T1_width;
    PyObject *obj_T4_z;
    PyObject *obj_T4_width;
    PyObject *obj_T1_radius;
    PyObject *obj_T4_radius;
    PyObject *obj_T1_corner;
    PyObject *obj_T4_corner;
    PyObject *obj_mean_free_path;
    PyObject *obj_photons_per_E;
    PyObject *obj_prob_scint;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_t, &obj_phi_range_deg, &obj_T1_z, &obj_T1_width, &obj_T4_z, &obj_T4_width, &obj_T1_radius, &obj_T4_radius, &obj_T1_corner, &obj_T4_corner, &obj_mean_free_path, &obj_photons_per_E, &obj_prob_scint)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *arg_t = obj_t;
    PyObject *arg_phi_range_deg = obj_phi_range_deg;
    PyObject *arg_T1_z = obj_T1_z;
    PyObject *arg_T1_width = obj_T1_width;
    PyObject *arg_T4_z = obj_T4_z;
    PyObject *arg_T4_width = obj_T4_width;
    PyObject *arg_T1_radius = obj_T1_radius;
    PyObject *arg_T4_radius = obj_T4_radius;
    PyObject *arg_T1_corner = obj_T1_corner;
    PyObject *arg_T4_corner = obj_T4_corner;
    PyObject *arg_mean_free_path = obj_mean_free_path;
    PyObject *arg_photons_per_E = obj_photons_per_E;
    PyObject *arg_prob_scint = obj_prob_scint;
    PyObject *retval = CPyDef_Simulation___particle_path(arg_self, arg_t, arg_phi_range_deg, arg_T1_z, arg_T1_width, arg_T4_z, arg_T4_width, arg_T1_radius, arg_T4_radius, arg_T1_corner, arg_T4_corner, arg_mean_free_path, arg_photons_per_E, arg_prob_scint);
    return retval;
fail: ;
    CPy_AddTraceback("modTof.py", "particle_path", 250, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Simulation___scintillator_monte_carlo(PyObject *cpy_r_self, PyObject *cpy_r_o, PyObject *cpy_r_notabsorbed, PyObject *cpy_r_scint_radius, PyObject *cpy_r_scint_plane, PyObject *cpy_r_light_guide_planes, PyObject *cpy_r_pmt_center, PyObject *cpy_r_pmt_radius, PyObject *cpy_r_corner_center, PyObject *cpy_r_corner_radius, PyObject *cpy_r_N_max, PyObject *cpy_r_t, PyObject *cpy_r_keepdata) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_track_history;
    int32_t cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    tuple_T2OO cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject **cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject **cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_endpoint_dist;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    double cpy_r_r27;
    char cpy_r_r28;
    double cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject **cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_theta;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    double cpy_r_r42;
    char cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject **cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_phi;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_PMT_hit_condition;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_total_dist;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_dt;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject **cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject **cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject **cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject **cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject **cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    CPyPtr cpy_r_r89;
    CPyPtr cpy_r_r90;
    CPyPtr cpy_r_r91;
    CPyPtr cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject **cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_u;
    int32_t cpy_r_r99;
    char cpy_r_r100;
    char cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    CPyPtr cpy_r_r115;
    CPyPtr cpy_r_r116;
    CPyPtr cpy_r_r117;
    CPyPtr cpy_r_r118;
    CPyPtr cpy_r_r119;
    CPyPtr cpy_r_r120;
    CPyPtr cpy_r_r121;
    CPyPtr cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    tuple_T2OO cpy_r_r128;
    PyObject *cpy_r_r129;
    char cpy_r_r130;
    int32_t cpy_r_r131;
    char cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_i;
    PyObject *cpy_r_r134;
    int32_t cpy_r_r135;
    char cpy_r_r136;
    char cpy_r_r137;
    PyObject *cpy_r_r138;
    PyObject *cpy_r_r139;
    PyObject *cpy_r_r140;
    char cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject *cpy_r_r143;
    int32_t cpy_r_r144;
    char cpy_r_r145;
    char cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject *cpy_r_r149;
    PyObject *cpy_r_r150;
    PyObject *cpy_r_r151;
    CPyPtr cpy_r_r152;
    CPyPtr cpy_r_r153;
    CPyPtr cpy_r_r154;
    CPyPtr cpy_r_r155;
    PyObject *cpy_r_r156;
    PyObject *cpy_r_r157;
    PyObject *cpy_r_r158;
    PyObject **cpy_r_r160;
    PyObject *cpy_r_r161;
    PyObject *cpy_r_r162;
    PyObject *cpy_r_r163;
    PyObject *cpy_r_r164;
    char cpy_r_r165;
    PyObject *cpy_r_ds;
    PyObject *cpy_r_r166;
    char cpy_r_r167;
    PyObject *cpy_r_r168;
    char cpy_r_r169;
    PyObject *cpy_r_r170;
    PyObject *cpy_r_r171;
    PyObject *cpy_r_r172;
    PyObject *cpy_r_r173;
    char cpy_r_r174;
    PyObject *cpy_r_x;
    PyObject *cpy_r_r175;
    char cpy_r_r176;
    PyObject *cpy_r_y;
    PyObject *cpy_r_r177;
    char cpy_r_r178;
    PyObject *cpy_r_z;
    PyObject *cpy_r_r179;
    char cpy_r_r180;
    PyObject *cpy_r_r181;
    PyObject *cpy_r_r182;
    PyObject *cpy_r_r183;
    PyObject *cpy_r_r184;
    PyObject *cpy_r_r185;
    PyObject *cpy_r_r186;
    PyObject *cpy_r_r187;
    PyObject *cpy_r_r188;
    PyObject *cpy_r_r189;
    PyObject *cpy_r_r190;
    PyObject *cpy_r_r191;
    PyObject **cpy_r_r193;
    PyObject *cpy_r_r194;
    PyObject *cpy_r_r195;
    PyObject *cpy_r_r196;
    PyObject *cpy_r_r197;
    PyObject *cpy_r_r198;
    PyObject *cpy_r_r199;
    PyObject **cpy_r_r201;
    PyObject *cpy_r_r202;
    PyObject *cpy_r_r203;
    PyObject *cpy_r_r204;
    PyObject *cpy_r_r205;
    PyObject *cpy_r_r206;
    int32_t cpy_r_r207;
    char cpy_r_r208;
    char cpy_r_r209;
    PyObject *cpy_r_r210;
    PyObject *cpy_r_r211;
    PyObject *cpy_r_r212;
    PyObject **cpy_r_r214;
    PyObject *cpy_r_r215;
    PyObject *cpy_r_r216;
    PyObject *cpy_r_r217;
    CPyPtr cpy_r_r218;
    CPyPtr cpy_r_r219;
    CPyPtr cpy_r_r220;
    CPyPtr cpy_r_r221;
    PyObject *cpy_r_r222;
    PyObject *cpy_r_r223;
    PyObject *cpy_r_r224;
    PyObject **cpy_r_r226;
    PyObject *cpy_r_r227;
    PyObject *cpy_r_r228;
    PyObject *cpy_r_r229;
    PyObject *cpy_r_r230;
    PyObject **cpy_r_r232;
    PyObject *cpy_r_r233;
    PyObject *cpy_r_r234;
    PyObject *cpy_r_r235;
    PyObject *cpy_r_r236;
    PyObject *cpy_r_r237;
    PyObject *cpy_r_n;
    PyObject *cpy_r_r238;
    PyObject *cpy_r_r239;
    PyObject *cpy_r_r240;
    char cpy_r_r241;
    PyObject *cpy_r_r242;
    char cpy_r_r243;
    PyObject *cpy_r_r244;
    char cpy_r_r245;
    int32_t cpy_r_r246;
    char cpy_r_r247;
    char cpy_r_r248;
    PyObject *cpy_r_r249;
    PyObject *cpy_r_r250;
    PyObject *cpy_r_r251;
    PyObject *cpy_r_r252;
    PyObject *cpy_r_r253;
    PyObject *cpy_r_r254;
    PyObject *cpy_r_r255;
    CPyPtr cpy_r_r256;
    CPyPtr cpy_r_r257;
    CPyPtr cpy_r_r258;
    CPyPtr cpy_r_r259;
    CPyPtr cpy_r_r260;
    CPyPtr cpy_r_r261;
    CPyPtr cpy_r_r262;
    CPyPtr cpy_r_r263;
    PyObject *cpy_r_r264;
    PyObject *cpy_r_r265;
    char cpy_r_r266;
    int32_t cpy_r_r267;
    char cpy_r_r268;
    PyObject *cpy_r_r269;
    PyObject *cpy_r_r270;
    int32_t cpy_r_r271;
    char cpy_r_r272;
    char cpy_r_r273;
    PyObject *cpy_r_r274;
    int32_t cpy_r_r275;
    char cpy_r_r276;
    char cpy_r_r277;
    PyObject *cpy_r_r278;
    PyObject *cpy_r_r279;
    PyObject *cpy_r_r280;
    PyObject *cpy_r_r281;
    PyObject *cpy_r_r282;
    PyObject *cpy_r_r283;
    PyObject *cpy_r_r284;
    PyObject *cpy_r_r285;
    PyObject *cpy_r_r286;
    tuple_T2OO cpy_r_r287;
    PyObject *cpy_r_r288;
    char cpy_r_r289;
    PyObject *cpy_r_r290;
    PyObject *cpy_r_r291;
    char cpy_r_r292;
    tuple_T3OOO cpy_r_r293;
    PyObject *cpy_r_r294;
    PyObject *cpy_r_r295;
    tuple_T6OOOOOO cpy_r_r296;
    PyObject *cpy_r_r297;
    PyObject *cpy_r_r298;
    cpy_r_r0 = NULL;
    cpy_r_track_history = cpy_r_r0;
    cpy_r_r1 = PyObject_IsTrue(cpy_r_keepdata);
    cpy_r_r2 = cpy_r_r1 >= 0;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 323, CPyStatic_globals);
        goto CPyL157;
    }
    cpy_r_r3 = cpy_r_r1;
    if (cpy_r_r3) {
        goto CPyL158;
    } else
        goto CPyL6;
CPyL2: ;
    cpy_r_r4 = CPyStatics[247]; /* 1 */
    cpy_r_r5 = PyNumber_Add(cpy_r_N_max, cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 324, CPyStatic_globals);
        goto CPyL156;
    }
    cpy_r_r6 = CPyStatics[262]; /* 7 */
    cpy_r_r7.f0 = cpy_r_r5;
    cpy_r_r7.f1 = cpy_r_r6;
    CPy_INCREF(cpy_r_r7.f0);
    CPy_INCREF(cpy_r_r7.f1);
    CPy_DECREF(cpy_r_r5);
    cpy_r_r8 = CPyModule_numpy;
    cpy_r_r9 = CPyStatics[45]; /* 'zeros' */
    cpy_r_r10 = CPyObject_GetAttr(cpy_r_r8, cpy_r_r9);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 324, CPyStatic_globals);
        goto CPyL159;
    }
    cpy_r_r11 = PyTuple_New(2);
    if (unlikely(cpy_r_r11 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp38 = cpy_r_r7.f0;
    PyTuple_SET_ITEM(cpy_r_r11, 0, __tmp38);
    PyObject *__tmp39 = cpy_r_r7.f1;
    PyTuple_SET_ITEM(cpy_r_r11, 1, __tmp39);
    PyObject *cpy_r_r12[1] = {cpy_r_r11};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = _PyObject_Vectorcall(cpy_r_r10, cpy_r_r13, 1, 0);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 324, CPyStatic_globals);
        goto CPyL160;
    }
    CPy_DECREF(cpy_r_r11);
    cpy_r_track_history = cpy_r_r14;
CPyL6: ;
    cpy_r_r15 = PyNumber_Subtract(cpy_r_o, cpy_r_pmt_center);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 325, CPyStatic_globals);
        goto CPyL157;
    }
    cpy_r_r16 = CPyModule_numpy;
    cpy_r_r17 = CPyStatics[27]; /* 'linalg' */
    cpy_r_r18 = CPyObject_GetAttr(cpy_r_r16, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 325, CPyStatic_globals);
        goto CPyL161;
    }
    cpy_r_r19 = CPyStatics[28]; /* 'norm' */
    cpy_r_r20 = CPyObject_GetAttr(cpy_r_r18, cpy_r_r19);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 325, CPyStatic_globals);
        goto CPyL161;
    }
    PyObject *cpy_r_r21[1] = {cpy_r_r15};
    cpy_r_r22 = (PyObject **)&cpy_r_r21;
    cpy_r_r23 = _PyObject_Vectorcall(cpy_r_r20, cpy_r_r22, 1, 0);
    CPy_DECREF(cpy_r_r20);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 325, CPyStatic_globals);
        goto CPyL161;
    }
    CPy_DECREF(cpy_r_r15);
    cpy_r_endpoint_dist = cpy_r_r23;
    cpy_r_r24 = CPyModule_numpy;
    cpy_r_r25 = CPyStatics[37]; /* 'pi' */
    cpy_r_r26 = CPyObject_GetAttr(cpy_r_r24, cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 326, CPyStatic_globals);
        goto CPyL162;
    }
    cpy_r_r27 = PyFloat_AsDouble(cpy_r_r26);
    if (cpy_r_r27 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r26); cpy_r_r27 = -113.0;
    }
    CPy_DECREF(cpy_r_r26);
    cpy_r_r28 = cpy_r_r27 == -113.0;
    if (unlikely(cpy_r_r28)) goto CPyL13;
CPyL12: ;
    cpy_r_r29 = 2.0 * cpy_r_r27;
    cpy_r_r30 = PyFloat_FromDouble(cpy_r_r29);
    cpy_r_r31 = CPyModule_random;
    cpy_r_r32 = CPyStatics[38]; /* 'uniform' */
    cpy_r_r33 = CPyObject_GetAttr(cpy_r_r31, cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 326, CPyStatic_globals);
        goto CPyL163;
    } else
        goto CPyL14;
CPyL13: ;
    cpy_r_r34 = PyErr_Occurred();
    if (unlikely(cpy_r_r34 != NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 326, CPyStatic_globals);
        goto CPyL162;
    } else
        goto CPyL12;
CPyL14: ;
    cpy_r_r35 = CPyStatics[244]; /* 0 */
    PyObject *cpy_r_r36[2] = {cpy_r_r35, cpy_r_r30};
    cpy_r_r37 = (PyObject **)&cpy_r_r36;
    cpy_r_r38 = _PyObject_Vectorcall(cpy_r_r33, cpy_r_r37, 2, 0);
    CPy_DECREF(cpy_r_r33);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 326, CPyStatic_globals);
        goto CPyL163;
    }
    CPy_DECREF(cpy_r_r30);
    cpy_r_theta = cpy_r_r38;
    cpy_r_r39 = CPyModule_numpy;
    cpy_r_r40 = CPyStatics[37]; /* 'pi' */
    cpy_r_r41 = CPyObject_GetAttr(cpy_r_r39, cpy_r_r40);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 327, CPyStatic_globals);
        goto CPyL164;
    }
    cpy_r_r42 = PyFloat_AsDouble(cpy_r_r41);
    if (cpy_r_r42 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r41); cpy_r_r42 = -113.0;
    }
    CPy_DECREF(cpy_r_r41);
    cpy_r_r43 = cpy_r_r42 == -113.0;
    if (unlikely(cpy_r_r43)) goto CPyL18;
CPyL17: ;
    cpy_r_r44 = CPyModule_random;
    cpy_r_r45 = CPyStatics[38]; /* 'uniform' */
    cpy_r_r46 = CPyObject_GetAttr(cpy_r_r44, cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 327, CPyStatic_globals);
        goto CPyL164;
    } else
        goto CPyL19;
CPyL18: ;
    cpy_r_r47 = PyErr_Occurred();
    if (unlikely(cpy_r_r47 != NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 327, CPyStatic_globals);
        goto CPyL164;
    } else
        goto CPyL17;
CPyL19: ;
    cpy_r_r48 = CPyStatics[244]; /* 0 */
    cpy_r_r49 = PyFloat_FromDouble(cpy_r_r42);
    PyObject *cpy_r_r50[2] = {cpy_r_r48, cpy_r_r49};
    cpy_r_r51 = (PyObject **)&cpy_r_r50;
    cpy_r_r52 = _PyObject_Vectorcall(cpy_r_r46, cpy_r_r51, 2, 0);
    CPy_DECREF(cpy_r_r46);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 327, CPyStatic_globals);
        goto CPyL165;
    }
    CPy_DECREF(cpy_r_r49);
    cpy_r_phi = cpy_r_r52;
    cpy_r_r53 = 0 ? Py_True : Py_False;
    CPy_INCREF(cpy_r_r53);
    cpy_r_PMT_hit_condition = cpy_r_r53;
    cpy_r_r54 = CPyStatics[244]; /* 0 */
    CPy_INCREF(cpy_r_r54);
    cpy_r_total_dist = cpy_r_r54;
    cpy_r_r55 = CPyStatics[244]; /* 0 */
    CPy_INCREF(cpy_r_r55);
    cpy_r_dt = cpy_r_r55;
    cpy_r_r56 = CPyModule_numpy;
    cpy_r_r57 = CPyStatics[5]; /* 'sin' */
    cpy_r_r58 = CPyObject_GetAttr(cpy_r_r56, cpy_r_r57);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 331, CPyStatic_globals);
        goto CPyL166;
    }
    PyObject *cpy_r_r59[1] = {cpy_r_phi};
    cpy_r_r60 = (PyObject **)&cpy_r_r59;
    cpy_r_r61 = _PyObject_Vectorcall(cpy_r_r58, cpy_r_r60, 1, 0);
    CPy_DECREF(cpy_r_r58);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 331, CPyStatic_globals);
        goto CPyL166;
    }
    cpy_r_r62 = CPyModule_numpy;
    cpy_r_r63 = CPyStatics[4]; /* 'cos' */
    cpy_r_r64 = CPyObject_GetAttr(cpy_r_r62, cpy_r_r63);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 331, CPyStatic_globals);
        goto CPyL167;
    }
    PyObject *cpy_r_r65[1] = {cpy_r_theta};
    cpy_r_r66 = (PyObject **)&cpy_r_r65;
    cpy_r_r67 = _PyObject_Vectorcall(cpy_r_r64, cpy_r_r66, 1, 0);
    CPy_DECREF(cpy_r_r64);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 331, CPyStatic_globals);
        goto CPyL167;
    }
    cpy_r_r68 = PyNumber_Multiply(cpy_r_r61, cpy_r_r67);
    CPy_DECREF(cpy_r_r61);
    CPy_DECREF(cpy_r_r67);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 331, CPyStatic_globals);
        goto CPyL166;
    }
    cpy_r_r69 = CPyModule_numpy;
    cpy_r_r70 = CPyStatics[5]; /* 'sin' */
    cpy_r_r71 = CPyObject_GetAttr(cpy_r_r69, cpy_r_r70);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 331, CPyStatic_globals);
        goto CPyL168;
    }
    PyObject *cpy_r_r72[1] = {cpy_r_phi};
    cpy_r_r73 = (PyObject **)&cpy_r_r72;
    cpy_r_r74 = _PyObject_Vectorcall(cpy_r_r71, cpy_r_r73, 1, 0);
    CPy_DECREF(cpy_r_r71);
    if (unlikely(cpy_r_r74 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 331, CPyStatic_globals);
        goto CPyL168;
    }
    cpy_r_r75 = CPyModule_numpy;
    cpy_r_r76 = CPyStatics[5]; /* 'sin' */
    cpy_r_r77 = CPyObject_GetAttr(cpy_r_r75, cpy_r_r76);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 331, CPyStatic_globals);
        goto CPyL169;
    }
    PyObject *cpy_r_r78[1] = {cpy_r_theta};
    cpy_r_r79 = (PyObject **)&cpy_r_r78;
    cpy_r_r80 = _PyObject_Vectorcall(cpy_r_r77, cpy_r_r79, 1, 0);
    CPy_DECREF(cpy_r_r77);
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 331, CPyStatic_globals);
        goto CPyL169;
    }
    CPy_DECREF(cpy_r_theta);
    cpy_r_r81 = PyNumber_Multiply(cpy_r_r74, cpy_r_r80);
    CPy_DECREF(cpy_r_r74);
    CPy_DECREF(cpy_r_r80);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 331, CPyStatic_globals);
        goto CPyL170;
    }
    cpy_r_r82 = CPyModule_numpy;
    cpy_r_r83 = CPyStatics[4]; /* 'cos' */
    cpy_r_r84 = CPyObject_GetAttr(cpy_r_r82, cpy_r_r83);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 331, CPyStatic_globals);
        goto CPyL171;
    }
    PyObject *cpy_r_r85[1] = {cpy_r_phi};
    cpy_r_r86 = (PyObject **)&cpy_r_r85;
    cpy_r_r87 = _PyObject_Vectorcall(cpy_r_r84, cpy_r_r86, 1, 0);
    CPy_DECREF(cpy_r_r84);
    if (unlikely(cpy_r_r87 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 331, CPyStatic_globals);
        goto CPyL171;
    }
    CPy_DECREF(cpy_r_phi);
    cpy_r_r88 = PyList_New(3);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 331, CPyStatic_globals);
        goto CPyL172;
    }
    cpy_r_r89 = (CPyPtr)&((PyListObject *)cpy_r_r88)->ob_item;
    cpy_r_r90 = *(CPyPtr *)cpy_r_r89;
    *(PyObject * *)cpy_r_r90 = cpy_r_r68;
    cpy_r_r91 = cpy_r_r90 + 8;
    *(PyObject * *)cpy_r_r91 = cpy_r_r81;
    cpy_r_r92 = cpy_r_r90 + 16;
    *(PyObject * *)cpy_r_r92 = cpy_r_r87;
    cpy_r_r93 = CPyModule_numpy;
    cpy_r_r94 = CPyStatics[32]; /* 'array' */
    cpy_r_r95 = CPyObject_GetAttr(cpy_r_r93, cpy_r_r94);
    if (unlikely(cpy_r_r95 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 331, CPyStatic_globals);
        goto CPyL173;
    }
    PyObject *cpy_r_r96[1] = {cpy_r_r88};
    cpy_r_r97 = (PyObject **)&cpy_r_r96;
    cpy_r_r98 = _PyObject_Vectorcall(cpy_r_r95, cpy_r_r97, 1, 0);
    CPy_DECREF(cpy_r_r95);
    if (unlikely(cpy_r_r98 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 331, CPyStatic_globals);
        goto CPyL173;
    }
    CPy_DECREF(cpy_r_r88);
    cpy_r_u = cpy_r_r98;
    cpy_r_r99 = PyObject_IsTrue(cpy_r_keepdata);
    cpy_r_r100 = cpy_r_r99 >= 0;
    if (unlikely(!cpy_r_r100)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 323, CPyStatic_globals);
        goto CPyL174;
    }
    cpy_r_r101 = cpy_r_r99;
    if (!cpy_r_r101) goto CPyL49;
    cpy_r_r102 = CPyStatics[244]; /* 0 */
    cpy_r_r103 = PyObject_GetItem(cpy_r_o, cpy_r_r102);
    if (unlikely(cpy_r_r103 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 332, CPyStatic_globals);
        goto CPyL174;
    }
    cpy_r_r104 = CPyStatics[247]; /* 1 */
    cpy_r_r105 = PyObject_GetItem(cpy_r_o, cpy_r_r104);
    if (unlikely(cpy_r_r105 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 332, CPyStatic_globals);
        goto CPyL175;
    }
    cpy_r_r106 = CPyStatics[257]; /* 2 */
    cpy_r_r107 = PyObject_GetItem(cpy_r_o, cpy_r_r106);
    if (unlikely(cpy_r_r107 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 332, CPyStatic_globals);
        goto CPyL176;
    }
    cpy_r_r108 = CPyStatics[244]; /* 0 */
    cpy_r_r109 = PyObject_GetItem(cpy_r_u, cpy_r_r108);
    if (unlikely(cpy_r_r109 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 332, CPyStatic_globals);
        goto CPyL177;
    }
    cpy_r_r110 = CPyStatics[247]; /* 1 */
    cpy_r_r111 = PyObject_GetItem(cpy_r_u, cpy_r_r110);
    if (unlikely(cpy_r_r111 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 332, CPyStatic_globals);
        goto CPyL178;
    }
    cpy_r_r112 = CPyStatics[257]; /* 2 */
    cpy_r_r113 = PyObject_GetItem(cpy_r_u, cpy_r_r112);
    if (unlikely(cpy_r_r113 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 332, CPyStatic_globals);
        goto CPyL179;
    }
    cpy_r_r114 = PyList_New(7);
    if (unlikely(cpy_r_r114 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 332, CPyStatic_globals);
        goto CPyL180;
    }
    cpy_r_r115 = (CPyPtr)&((PyListObject *)cpy_r_r114)->ob_item;
    cpy_r_r116 = *(CPyPtr *)cpy_r_r115;
    *(PyObject * *)cpy_r_r116 = cpy_r_r103;
    cpy_r_r117 = cpy_r_r116 + 8;
    *(PyObject * *)cpy_r_r117 = cpy_r_r105;
    cpy_r_r118 = cpy_r_r116 + 16;
    *(PyObject * *)cpy_r_r118 = cpy_r_r107;
    cpy_r_r119 = cpy_r_r116 + 24;
    *(PyObject * *)cpy_r_r119 = cpy_r_r109;
    cpy_r_r120 = cpy_r_r116 + 32;
    *(PyObject * *)cpy_r_r120 = cpy_r_r111;
    cpy_r_r121 = cpy_r_r116 + 40;
    *(PyObject * *)cpy_r_r121 = cpy_r_r113;
    cpy_r_r122 = cpy_r_r116 + 48;
    CPy_INCREF(cpy_r_notabsorbed);
    *(PyObject * *)cpy_r_r122 = cpy_r_notabsorbed;
    cpy_r_r123 = CPyStatics[244]; /* 0 */
    cpy_r_r124 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r125 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r126 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r127 = PySlice_New(cpy_r_r124, cpy_r_r125, cpy_r_r126);
    if (unlikely(cpy_r_r127 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", -1, CPyStatic_globals);
        goto CPyL181;
    }
    cpy_r_r128.f0 = cpy_r_r123;
    cpy_r_r128.f1 = cpy_r_r127;
    CPy_INCREF(cpy_r_r128.f0);
    CPy_INCREF(cpy_r_r128.f1);
    CPy_DECREF(cpy_r_r127);
    cpy_r_r129 = PyTuple_New(2);
    if (unlikely(cpy_r_r129 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp40 = cpy_r_r128.f0;
    PyTuple_SET_ITEM(cpy_r_r129, 0, __tmp40);
    PyObject *__tmp41 = cpy_r_r128.f1;
    PyTuple_SET_ITEM(cpy_r_r129, 1, __tmp41);
    if (cpy_r_track_history == NULL) {
        goto CPyL182;
    } else
        goto CPyL48;
CPyL46: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"track_history\" referenced before assignment");
    cpy_r_r130 = 0;
    if (unlikely(!cpy_r_r130)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 332, CPyStatic_globals);
        goto CPyL156;
    }
    CPy_Unreachable();
CPyL48: ;
    cpy_r_r131 = PyObject_SetItem(cpy_r_track_history, cpy_r_r129, cpy_r_r114);
    CPy_DECREF(cpy_r_r129);
    CPy_DECREF(cpy_r_r114);
    cpy_r_r132 = cpy_r_r131 >= 0;
    if (unlikely(!cpy_r_r132)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 332, CPyStatic_globals);
        goto CPyL174;
    }
CPyL49: ;
    cpy_r_r133 = CPyStatics[244]; /* 0 */
    CPy_INCREF(cpy_r_r133);
    cpy_r_i = cpy_r_r133;
    goto CPyL183;
CPyL50: ;
    cpy_r_r134 = PyObject_RichCompare(cpy_r_i, cpy_r_N_max, 0);
    if (unlikely(cpy_r_r134 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 334, CPyStatic_globals);
        goto CPyL184;
    }
    cpy_r_r135 = PyObject_Not(cpy_r_PMT_hit_condition);
    cpy_r_r136 = cpy_r_r135 >= 0;
    if (unlikely(!cpy_r_r136)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 334, CPyStatic_globals);
        goto CPyL185;
    }
    cpy_r_r137 = cpy_r_r135;
    cpy_r_r138 = cpy_r_r137 ? Py_True : Py_False;
    cpy_r_r139 = PyNumber_And(cpy_r_r134, cpy_r_r138);
    CPy_DECREF(cpy_r_r134);
    if (unlikely(cpy_r_r139 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 334, CPyStatic_globals);
        goto CPyL184;
    }
    cpy_r_r140 = 1 ? Py_True : Py_False;
    cpy_r_r141 = cpy_r_notabsorbed == cpy_r_r140;
    CPy_DECREF(cpy_r_notabsorbed);
    cpy_r_r142 = cpy_r_r141 ? Py_True : Py_False;
    cpy_r_r143 = PyNumber_And(cpy_r_r139, cpy_r_r142);
    CPy_DECREF(cpy_r_r139);
    if (unlikely(cpy_r_r143 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 334, CPyStatic_globals);
        goto CPyL186;
    }
    cpy_r_r144 = PyObject_IsTrue(cpy_r_r143);
    CPy_DECREF(cpy_r_r143);
    cpy_r_r145 = cpy_r_r144 >= 0;
    if (unlikely(!cpy_r_r145)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 334, CPyStatic_globals);
        goto CPyL186;
    }
    cpy_r_r146 = cpy_r_r144;
    if (cpy_r_r146) {
        goto CPyL187;
    } else
        goto CPyL188;
CPyL56: ;
    cpy_r_r147 = CPyStatics[244]; /* 0 */
    cpy_r_r148 = PyObject_GetItem(cpy_r_scint_plane, cpy_r_r147);
    if (unlikely(cpy_r_r148 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 335, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r149 = PyList_New(3);
    if (unlikely(cpy_r_r149 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 335, CPyStatic_globals);
        goto CPyL190;
    }
    cpy_r_r150 = CPyStatics[244]; /* 0 */
    cpy_r_r151 = CPyStatics[244]; /* 0 */
    cpy_r_r152 = (CPyPtr)&((PyListObject *)cpy_r_r149)->ob_item;
    cpy_r_r153 = *(CPyPtr *)cpy_r_r152;
    CPy_INCREF(cpy_r_r150);
    *(PyObject * *)cpy_r_r153 = cpy_r_r150;
    cpy_r_r154 = cpy_r_r153 + 8;
    CPy_INCREF(cpy_r_r151);
    *(PyObject * *)cpy_r_r154 = cpy_r_r151;
    cpy_r_r155 = cpy_r_r153 + 16;
    *(PyObject * *)cpy_r_r155 = cpy_r_r148;
    cpy_r_r156 = CPyModule_numpy;
    cpy_r_r157 = CPyStatics[32]; /* 'array' */
    cpy_r_r158 = CPyObject_GetAttr(cpy_r_r156, cpy_r_r157);
    if (unlikely(cpy_r_r158 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 335, CPyStatic_globals);
        goto CPyL191;
    }
    PyObject *cpy_r_r159[1] = {cpy_r_r149};
    cpy_r_r160 = (PyObject **)&cpy_r_r159;
    cpy_r_r161 = _PyObject_Vectorcall(cpy_r_r158, cpy_r_r160, 1, 0);
    CPy_DECREF(cpy_r_r158);
    if (unlikely(cpy_r_r161 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 335, CPyStatic_globals);
        goto CPyL191;
    }
    CPy_DECREF(cpy_r_r149);
    cpy_r_r162 = CPyDef_Simulation___distance_solver(cpy_r_self, cpy_r_u, cpy_r_o, cpy_r_r161, cpy_r_scint_radius, cpy_r_scint_plane, cpy_r_corner_center, cpy_r_corner_radius, cpy_r_pmt_center, cpy_r_pmt_radius);
    CPy_DECREF(cpy_r_r161);
    if (unlikely(cpy_r_r162 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 335, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r163 = PyObject_GetIter(cpy_r_r162);
    CPy_DECREF(cpy_r_r162);
    if (unlikely(cpy_r_r163 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 335, CPyStatic_globals);
        goto CPyL189;
    }
    cpy_r_r164 = PyIter_Next(cpy_r_r163);
    if (cpy_r_r164 == NULL) {
        goto CPyL192;
    } else
        goto CPyL65;
CPyL63: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r165 = 0;
    if (unlikely(!cpy_r_r165)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 335, CPyStatic_globals);
        goto CPyL156;
    }
    CPy_Unreachable();
CPyL65: ;
    cpy_r_ds = cpy_r_r164;
    cpy_r_r166 = PyIter_Next(cpy_r_r163);
    if (cpy_r_r166 == NULL) {
        goto CPyL193;
    } else
        goto CPyL68;
CPyL66: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r167 = 0;
    if (unlikely(!cpy_r_r167)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 335, CPyStatic_globals);
        goto CPyL156;
    }
    CPy_Unreachable();
CPyL68: ;
    cpy_r_PMT_hit_condition = cpy_r_r166;
    cpy_r_r168 = PyIter_Next(cpy_r_r163);
    CPy_DECREF(cpy_r_r163);
    if (cpy_r_r168 == NULL) {
        goto CPyL71;
    } else
        goto CPyL194;
CPyL69: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r169 = 0;
    if (unlikely(!cpy_r_r169)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 335, CPyStatic_globals);
        goto CPyL156;
    }
    CPy_Unreachable();
CPyL71: ;
    cpy_r_r170 = PyNumber_Multiply(cpy_r_ds, cpy_r_u);
    if (unlikely(cpy_r_r170 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 336, CPyStatic_globals);
        goto CPyL195;
    }
    cpy_r_r171 = PyNumber_Add(cpy_r_o, cpy_r_r170);
    CPy_DECREF(cpy_r_o);
    CPy_DECREF(cpy_r_r170);
    if (unlikely(cpy_r_r171 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 336, CPyStatic_globals);
        goto CPyL196;
    }
    cpy_r_r172 = PyObject_GetIter(cpy_r_r171);
    CPy_DECREF(cpy_r_r171);
    if (unlikely(cpy_r_r172 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 336, CPyStatic_globals);
        goto CPyL196;
    }
    cpy_r_r173 = PyIter_Next(cpy_r_r172);
    if (cpy_r_r173 == NULL) {
        goto CPyL197;
    } else
        goto CPyL77;
CPyL75: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r174 = 0;
    if (unlikely(!cpy_r_r174)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 336, CPyStatic_globals);
        goto CPyL156;
    }
    CPy_Unreachable();
CPyL77: ;
    cpy_r_x = cpy_r_r173;
    cpy_r_r175 = PyIter_Next(cpy_r_r172);
    if (cpy_r_r175 == NULL) {
        goto CPyL198;
    } else
        goto CPyL80;
CPyL78: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r176 = 0;
    if (unlikely(!cpy_r_r176)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 336, CPyStatic_globals);
        goto CPyL156;
    }
    CPy_Unreachable();
CPyL80: ;
    cpy_r_y = cpy_r_r175;
    cpy_r_r177 = PyIter_Next(cpy_r_r172);
    if (cpy_r_r177 == NULL) {
        goto CPyL199;
    } else
        goto CPyL83;
CPyL81: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r178 = 0;
    if (unlikely(!cpy_r_r178)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 336, CPyStatic_globals);
        goto CPyL156;
    }
    CPy_Unreachable();
CPyL83: ;
    cpy_r_z = cpy_r_r177;
    cpy_r_r179 = PyIter_Next(cpy_r_r172);
    CPy_DECREF(cpy_r_r172);
    if (cpy_r_r179 == NULL) {
        goto CPyL86;
    } else
        goto CPyL200;
CPyL84: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r180 = 0;
    if (unlikely(!cpy_r_r180)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 336, CPyStatic_globals);
        goto CPyL156;
    }
    CPy_Unreachable();
CPyL86: ;
    cpy_r_r181 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r182 = CPyStatics[244]; /* 0 */
    cpy_r_r183 = CPyStatics[257]; /* 2 */
    cpy_r_r184 = PySlice_New(cpy_r_r182, cpy_r_r183, cpy_r_r181);
    if (unlikely(cpy_r_r184 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 337, CPyStatic_globals);
        goto CPyL201;
    }
    cpy_r_r185 = PyObject_GetItem(cpy_r_u, cpy_r_r184);
    CPy_DECREF(cpy_r_r184);
    if (unlikely(cpy_r_r185 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 337, CPyStatic_globals);
        goto CPyL201;
    }
    cpy_r_r186 = PyNumber_Multiply(cpy_r_ds, cpy_r_r185);
    CPy_DECREF(cpy_r_r185);
    if (unlikely(cpy_r_r186 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 337, CPyStatic_globals);
        goto CPyL201;
    }
    cpy_r_r187 = CPyModule_numpy;
    cpy_r_r188 = CPyStatics[27]; /* 'linalg' */
    cpy_r_r189 = CPyObject_GetAttr(cpy_r_r187, cpy_r_r188);
    if (unlikely(cpy_r_r189 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 337, CPyStatic_globals);
        goto CPyL202;
    }
    cpy_r_r190 = CPyStatics[28]; /* 'norm' */
    cpy_r_r191 = CPyObject_GetAttr(cpy_r_r189, cpy_r_r190);
    CPy_DECREF(cpy_r_r189);
    if (unlikely(cpy_r_r191 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 337, CPyStatic_globals);
        goto CPyL202;
    }
    PyObject *cpy_r_r192[1] = {cpy_r_r186};
    cpy_r_r193 = (PyObject **)&cpy_r_r192;
    cpy_r_r194 = _PyObject_Vectorcall(cpy_r_r191, cpy_r_r193, 1, 0);
    CPy_DECREF(cpy_r_r191);
    if (unlikely(cpy_r_r194 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 337, CPyStatic_globals);
        goto CPyL202;
    }
    CPy_DECREF(cpy_r_r186);
    cpy_r_r195 = PyNumber_InPlaceAdd(cpy_r_total_dist, cpy_r_r194);
    CPy_DECREF(cpy_r_total_dist);
    CPy_DECREF(cpy_r_r194);
    if (unlikely(cpy_r_r195 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 337, CPyStatic_globals);
        goto CPyL203;
    }
    cpy_r_total_dist = cpy_r_r195;
    cpy_r_r196 = PyNumber_Subtract(cpy_r_z, cpy_r_scint_plane);
    if (unlikely(cpy_r_r196 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 338, CPyStatic_globals);
        goto CPyL201;
    }
    cpy_r_r197 = CPyModule_numpy;
    cpy_r_r198 = CPyStatics[24]; /* 'abs' */
    cpy_r_r199 = CPyObject_GetAttr(cpy_r_r197, cpy_r_r198);
    if (unlikely(cpy_r_r199 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 338, CPyStatic_globals);
        goto CPyL204;
    }
    PyObject *cpy_r_r200[1] = {cpy_r_r196};
    cpy_r_r201 = (PyObject **)&cpy_r_r200;
    cpy_r_r202 = _PyObject_Vectorcall(cpy_r_r199, cpy_r_r201, 1, 0);
    CPy_DECREF(cpy_r_r199);
    if (unlikely(cpy_r_r202 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 338, CPyStatic_globals);
        goto CPyL204;
    }
    CPy_DECREF(cpy_r_r196);
    cpy_r_r203 = CPyStatics[46]; /* 'any' */
    cpy_r_r204 = CPyObject_CallMethodObjArgs(cpy_r_r202, cpy_r_r203, NULL);
    CPy_DECREF(cpy_r_r202);
    if (unlikely(cpy_r_r204 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 338, CPyStatic_globals);
        goto CPyL201;
    }
    cpy_r_r205 = PyFloat_FromDouble(1e-05);
    cpy_r_r206 = PyObject_RichCompare(cpy_r_r204, cpy_r_r205, 0);
    CPy_DECREF(cpy_r_r204);
    CPy_DECREF(cpy_r_r205);
    if (unlikely(cpy_r_r206 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 338, CPyStatic_globals);
        goto CPyL201;
    }
    cpy_r_r207 = PyObject_IsTrue(cpy_r_r206);
    CPy_DECREF(cpy_r_r206);
    cpy_r_r208 = cpy_r_r207 >= 0;
    if (unlikely(!cpy_r_r208)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 338, CPyStatic_globals);
        goto CPyL201;
    }
    cpy_r_r209 = cpy_r_r207;
    if (!cpy_r_r209) goto CPyL103;
    cpy_r_r210 = CPyModule_numpy;
    cpy_r_r211 = CPyStatics[24]; /* 'abs' */
    cpy_r_r212 = CPyObject_GetAttr(cpy_r_r210, cpy_r_r211);
    if (unlikely(cpy_r_r212 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 338, CPyStatic_globals);
        goto CPyL201;
    }
    PyObject *cpy_r_r213[1] = {cpy_r_z};
    cpy_r_r214 = (PyObject **)&cpy_r_r213;
    cpy_r_r215 = _PyObject_Vectorcall(cpy_r_r212, cpy_r_r214, 1, 0);
    CPy_DECREF(cpy_r_r212);
    if (unlikely(cpy_r_r215 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 338, CPyStatic_globals);
        goto CPyL201;
    }
    cpy_r_r216 = cpy_r_r215;
    goto CPyL104;
CPyL103: ;
    CPy_INCREF(cpy_r_z);
    cpy_r_r216 = cpy_r_z;
CPyL104: ;
    cpy_r_r217 = PyList_New(3);
    if (unlikely(cpy_r_r217 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 338, CPyStatic_globals);
        goto CPyL205;
    }
    cpy_r_r218 = (CPyPtr)&((PyListObject *)cpy_r_r217)->ob_item;
    cpy_r_r219 = *(CPyPtr *)cpy_r_r218;
    CPy_INCREF(cpy_r_x);
    *(PyObject * *)cpy_r_r219 = cpy_r_x;
    cpy_r_r220 = cpy_r_r219 + 8;
    CPy_INCREF(cpy_r_y);
    *(PyObject * *)cpy_r_r220 = cpy_r_y;
    cpy_r_r221 = cpy_r_r219 + 16;
    *(PyObject * *)cpy_r_r221 = cpy_r_r216;
    cpy_r_r222 = CPyModule_numpy;
    cpy_r_r223 = CPyStatics[32]; /* 'array' */
    cpy_r_r224 = CPyObject_GetAttr(cpy_r_r222, cpy_r_r223);
    if (unlikely(cpy_r_r224 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 338, CPyStatic_globals);
        goto CPyL206;
    }
    PyObject *cpy_r_r225[1] = {cpy_r_r217};
    cpy_r_r226 = (PyObject **)&cpy_r_r225;
    cpy_r_r227 = _PyObject_Vectorcall(cpy_r_r224, cpy_r_r226, 1, 0);
    CPy_DECREF(cpy_r_r224);
    if (unlikely(cpy_r_r227 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 338, CPyStatic_globals);
        goto CPyL206;
    }
    CPy_DECREF(cpy_r_r217);
    cpy_r_o = cpy_r_r227;
    cpy_r_r228 = CPyModule_numpy;
    cpy_r_r229 = CPyStatics[24]; /* 'abs' */
    cpy_r_r230 = CPyObject_GetAttr(cpy_r_r228, cpy_r_r229);
    if (unlikely(cpy_r_r230 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 339, CPyStatic_globals);
        goto CPyL207;
    }
    PyObject *cpy_r_r231[1] = {cpy_r_ds};
    cpy_r_r232 = (PyObject **)&cpy_r_r231;
    cpy_r_r233 = _PyObject_Vectorcall(cpy_r_r230, cpy_r_r232, 1, 0);
    CPy_DECREF(cpy_r_r230);
    if (unlikely(cpy_r_r233 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 339, CPyStatic_globals);
        goto CPyL207;
    }
    CPy_DECREF(cpy_r_ds);
    cpy_r_r234 = ((modTof___SimulationObject *)cpy_r_self)->_c;
    CPy_INCREF(cpy_r_r234);
    cpy_r_r235 = PyNumber_TrueDivide(cpy_r_r233, cpy_r_r234);
    CPy_DECREF(cpy_r_r233);
    CPy_DECREF(cpy_r_r234);
    if (unlikely(cpy_r_r235 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 339, CPyStatic_globals);
        goto CPyL208;
    }
    cpy_r_r236 = PyNumber_InPlaceAdd(cpy_r_dt, cpy_r_r235);
    CPy_DECREF(cpy_r_dt);
    CPy_DECREF(cpy_r_r235);
    if (unlikely(cpy_r_r236 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 339, CPyStatic_globals);
        goto CPyL209;
    }
    cpy_r_dt = cpy_r_r236;
    cpy_r_r237 = CPyDef_Simulation___n_vec_calculate(cpy_r_self, cpy_r_o, cpy_r_scint_plane, cpy_r_light_guide_planes, cpy_r_corner_center, cpy_r_corner_radius);
    if (unlikely(cpy_r_r237 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 341, CPyStatic_globals);
        goto CPyL208;
    }
    cpy_r_n = cpy_r_r237;
    cpy_r_r238 = CPyDef_Simulation___photon_interaction(cpy_r_self, cpy_r_u, cpy_r_n);
    CPy_DECREF(cpy_r_u);
    CPy_DECREF(cpy_r_n);
    if (unlikely(cpy_r_r238 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 342, CPyStatic_globals);
        goto CPyL210;
    }
    cpy_r_r239 = PyObject_GetIter(cpy_r_r238);
    CPy_DECREF(cpy_r_r238);
    if (unlikely(cpy_r_r239 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 342, CPyStatic_globals);
        goto CPyL210;
    }
    cpy_r_r240 = PyIter_Next(cpy_r_r239);
    if (cpy_r_r240 == NULL) {
        goto CPyL211;
    } else
        goto CPyL117;
CPyL115: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r241 = 0;
    if (unlikely(!cpy_r_r241)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 342, CPyStatic_globals);
        goto CPyL156;
    }
    CPy_Unreachable();
CPyL117: ;
    cpy_r_u = cpy_r_r240;
    cpy_r_r242 = PyIter_Next(cpy_r_r239);
    if (cpy_r_r242 == NULL) {
        goto CPyL212;
    } else
        goto CPyL120;
CPyL118: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r243 = 0;
    if (unlikely(!cpy_r_r243)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 342, CPyStatic_globals);
        goto CPyL156;
    }
    CPy_Unreachable();
CPyL120: ;
    cpy_r_notabsorbed = cpy_r_r242;
    cpy_r_r244 = PyIter_Next(cpy_r_r239);
    CPy_DECREF(cpy_r_r239);
    if (cpy_r_r244 == NULL) {
        goto CPyL123;
    } else
        goto CPyL213;
CPyL121: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r245 = 0;
    if (unlikely(!cpy_r_r245)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 342, CPyStatic_globals);
        goto CPyL156;
    }
    CPy_Unreachable();
CPyL123: ;
    cpy_r_r246 = PyObject_IsTrue(cpy_r_keepdata);
    cpy_r_r247 = cpy_r_r246 >= 0;
    if (unlikely(!cpy_r_r247)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 323, CPyStatic_globals);
        goto CPyL214;
    }
    cpy_r_r248 = cpy_r_r246;
    if (!cpy_r_r248) goto CPyL215;
    cpy_r_r249 = CPyStatics[244]; /* 0 */
    cpy_r_r250 = PyObject_GetItem(cpy_r_u, cpy_r_r249);
    if (unlikely(cpy_r_r250 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 343, CPyStatic_globals);
        goto CPyL214;
    }
    cpy_r_r251 = CPyStatics[247]; /* 1 */
    cpy_r_r252 = PyObject_GetItem(cpy_r_u, cpy_r_r251);
    if (unlikely(cpy_r_r252 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 343, CPyStatic_globals);
        goto CPyL216;
    }
    cpy_r_r253 = CPyStatics[257]; /* 2 */
    cpy_r_r254 = PyObject_GetItem(cpy_r_u, cpy_r_r253);
    if (unlikely(cpy_r_r254 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 343, CPyStatic_globals);
        goto CPyL217;
    }
    cpy_r_r255 = PyList_New(7);
    if (unlikely(cpy_r_r255 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 343, CPyStatic_globals);
        goto CPyL218;
    }
    cpy_r_r256 = (CPyPtr)&((PyListObject *)cpy_r_r255)->ob_item;
    cpy_r_r257 = *(CPyPtr *)cpy_r_r256;
    *(PyObject * *)cpy_r_r257 = cpy_r_x;
    cpy_r_r258 = cpy_r_r257 + 8;
    *(PyObject * *)cpy_r_r258 = cpy_r_y;
    cpy_r_r259 = cpy_r_r257 + 16;
    *(PyObject * *)cpy_r_r259 = cpy_r_z;
    cpy_r_r260 = cpy_r_r257 + 24;
    *(PyObject * *)cpy_r_r260 = cpy_r_r250;
    cpy_r_r261 = cpy_r_r257 + 32;
    *(PyObject * *)cpy_r_r261 = cpy_r_r252;
    cpy_r_r262 = cpy_r_r257 + 40;
    *(PyObject * *)cpy_r_r262 = cpy_r_r254;
    cpy_r_r263 = cpy_r_r257 + 48;
    CPy_INCREF(cpy_r_notabsorbed);
    *(PyObject * *)cpy_r_r263 = cpy_r_notabsorbed;
    cpy_r_r264 = CPyStatics[247]; /* 1 */
    cpy_r_r265 = PyNumber_Add(cpy_r_i, cpy_r_r264);
    if (unlikely(cpy_r_r265 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 343, CPyStatic_globals);
        goto CPyL219;
    }
    if (cpy_r_track_history == NULL) {
        goto CPyL220;
    } else
        goto CPyL133;
CPyL131: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"track_history\" referenced before assignment");
    cpy_r_r266 = 0;
    if (unlikely(!cpy_r_r266)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 343, CPyStatic_globals);
        goto CPyL156;
    }
    CPy_Unreachable();
CPyL133: ;
    cpy_r_r267 = PyObject_SetItem(cpy_r_track_history, cpy_r_r265, cpy_r_r255);
    CPy_DECREF(cpy_r_r265);
    CPy_DECREF(cpy_r_r255);
    cpy_r_r268 = cpy_r_r267 >= 0;
    if (unlikely(!cpy_r_r268)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 343, CPyStatic_globals);
        goto CPyL184;
    }
CPyL134: ;
    cpy_r_r269 = CPyStatics[247]; /* 1 */
    cpy_r_r270 = PyNumber_InPlaceAdd(cpy_r_i, cpy_r_r269);
    CPy_DECREF(cpy_r_i);
    if (unlikely(cpy_r_r270 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 344, CPyStatic_globals);
        goto CPyL221;
    }
    cpy_r_i = cpy_r_r270;
    goto CPyL50;
CPyL136: ;
    cpy_r_r271 = PyObject_IsTrue(cpy_r_keepdata);
    cpy_r_r272 = cpy_r_r271 >= 0;
    if (unlikely(!cpy_r_r272)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 323, CPyStatic_globals);
        goto CPyL222;
    }
    cpy_r_r273 = cpy_r_r271;
    if (cpy_r_r273) {
        goto CPyL223;
    } else
        goto CPyL224;
CPyL138: ;
    cpy_r_r274 = PyObject_RichCompare(cpy_r_i, cpy_r_N_max, 0);
    if (unlikely(cpy_r_r274 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 346, CPyStatic_globals);
        goto CPyL225;
    }
    cpy_r_r275 = PyObject_IsTrue(cpy_r_r274);
    CPy_DECREF(cpy_r_r274);
    cpy_r_r276 = cpy_r_r275 >= 0;
    if (unlikely(!cpy_r_r276)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 346, CPyStatic_globals);
        goto CPyL225;
    }
    cpy_r_r277 = cpy_r_r275;
    if (!cpy_r_r277) goto CPyL226;
    cpy_r_r278 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r279 = CPyStatics[247]; /* 1 */
    cpy_r_r280 = PyNumber_Add(cpy_r_i, cpy_r_r279);
    CPy_DECREF(cpy_r_i);
    if (unlikely(cpy_r_r280 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 347, CPyStatic_globals);
        goto CPyL227;
    }
    cpy_r_r281 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r282 = PySlice_New(cpy_r_r278, cpy_r_r280, cpy_r_r281);
    CPy_DECREF(cpy_r_r280);
    if (unlikely(cpy_r_r282 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", -1, CPyStatic_globals);
        goto CPyL227;
    }
    cpy_r_r283 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r284 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r285 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r286 = PySlice_New(cpy_r_r283, cpy_r_r284, cpy_r_r285);
    if (unlikely(cpy_r_r286 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", -1, CPyStatic_globals);
        goto CPyL228;
    }
    cpy_r_r287.f0 = cpy_r_r282;
    cpy_r_r287.f1 = cpy_r_r286;
    CPy_INCREF(cpy_r_r287.f0);
    CPy_INCREF(cpy_r_r287.f1);
    CPy_DECREF(cpy_r_r282);
    CPy_DECREF(cpy_r_r286);
    cpy_r_r288 = PyTuple_New(2);
    if (unlikely(cpy_r_r288 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp42 = cpy_r_r287.f0;
    PyTuple_SET_ITEM(cpy_r_r288, 0, __tmp42);
    PyObject *__tmp43 = cpy_r_r287.f1;
    PyTuple_SET_ITEM(cpy_r_r288, 1, __tmp43);
    if (cpy_r_track_history == NULL) {
        goto CPyL229;
    } else
        goto CPyL147;
CPyL145: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"track_history\" referenced before assignment");
    cpy_r_r289 = 0;
    if (unlikely(!cpy_r_r289)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 347, CPyStatic_globals);
        goto CPyL156;
    }
    CPy_Unreachable();
CPyL147: ;
    cpy_r_r290 = PyObject_GetItem(cpy_r_track_history, cpy_r_r288);
    CPy_XDECREF(cpy_r_track_history);
    CPy_DECREF(cpy_r_r288);
    if (unlikely(cpy_r_r290 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 347, CPyStatic_globals);
        goto CPyL230;
    }
    cpy_r_track_history = cpy_r_r290;
CPyL149: ;
    cpy_r_r291 = PyNumber_Add(cpy_r_t, cpy_r_dt);
    CPy_DECREF(cpy_r_dt);
    if (unlikely(cpy_r_r291 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 348, CPyStatic_globals);
        goto CPyL231;
    }
    if (cpy_r_track_history == NULL) {
        goto CPyL232;
    } else
        goto CPyL153;
CPyL151: ;
    PyErr_SetString(PyExc_UnboundLocalError, "local variable \"track_history\" referenced before assignment");
    cpy_r_r292 = 0;
    if (unlikely(!cpy_r_r292)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 348, CPyStatic_globals);
        goto CPyL156;
    }
    CPy_Unreachable();
CPyL153: ;
    cpy_r_r293.f0 = cpy_r_PMT_hit_condition;
    cpy_r_r293.f1 = cpy_r_r291;
    cpy_r_r293.f2 = cpy_r_track_history;
    CPy_INCREF(cpy_r_r293.f0);
    CPy_INCREF(cpy_r_r293.f1);
    CPy_INCREF(cpy_r_r293.f2);
    CPy_DECREF(cpy_r_PMT_hit_condition);
    CPy_DECREF(cpy_r_r291);
    CPy_XDECREF(cpy_r_track_history);
    cpy_r_r294 = PyTuple_New(3);
    if (unlikely(cpy_r_r294 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp44 = cpy_r_r293.f0;
    PyTuple_SET_ITEM(cpy_r_r294, 0, __tmp44);
    PyObject *__tmp45 = cpy_r_r293.f1;
    PyTuple_SET_ITEM(cpy_r_r294, 1, __tmp45);
    PyObject *__tmp46 = cpy_r_r293.f2;
    PyTuple_SET_ITEM(cpy_r_r294, 2, __tmp46);
    return cpy_r_r294;
CPyL154: ;
    cpy_r_r295 = PyNumber_Add(cpy_r_t, cpy_r_dt);
    if (unlikely(cpy_r_r295 == NULL)) {
        CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 350, CPyStatic_globals);
        goto CPyL233;
    }
    cpy_r_r296.f0 = cpy_r_PMT_hit_condition;
    cpy_r_r296.f1 = cpy_r_r295;
    cpy_r_r296.f2 = cpy_r_total_dist;
    cpy_r_r296.f3 = cpy_r_endpoint_dist;
    cpy_r_r296.f4 = cpy_r_i;
    cpy_r_r296.f5 = cpy_r_dt;
    CPy_INCREF(cpy_r_r296.f0);
    CPy_INCREF(cpy_r_r296.f1);
    CPy_INCREF(cpy_r_r296.f2);
    CPy_INCREF(cpy_r_r296.f3);
    CPy_INCREF(cpy_r_r296.f4);
    CPy_INCREF(cpy_r_r296.f5);
    CPy_DECREF(cpy_r_PMT_hit_condition);
    CPy_DECREF(cpy_r_r295);
    CPy_DECREF(cpy_r_total_dist);
    CPy_DECREF(cpy_r_endpoint_dist);
    CPy_DECREF(cpy_r_i);
    CPy_DECREF(cpy_r_dt);
    cpy_r_r297 = PyTuple_New(6);
    if (unlikely(cpy_r_r297 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp47 = cpy_r_r296.f0;
    PyTuple_SET_ITEM(cpy_r_r297, 0, __tmp47);
    PyObject *__tmp48 = cpy_r_r296.f1;
    PyTuple_SET_ITEM(cpy_r_r297, 1, __tmp48);
    PyObject *__tmp49 = cpy_r_r296.f2;
    PyTuple_SET_ITEM(cpy_r_r297, 2, __tmp49);
    PyObject *__tmp50 = cpy_r_r296.f3;
    PyTuple_SET_ITEM(cpy_r_r297, 3, __tmp50);
    PyObject *__tmp51 = cpy_r_r296.f4;
    PyTuple_SET_ITEM(cpy_r_r297, 4, __tmp51);
    PyObject *__tmp52 = cpy_r_r296.f5;
    PyTuple_SET_ITEM(cpy_r_r297, 5, __tmp52);
    return cpy_r_r297;
CPyL156: ;
    cpy_r_r298 = NULL;
    return cpy_r_r298;
CPyL157: ;
    CPy_XDecRef(cpy_r_track_history);
    goto CPyL156;
CPyL158: ;
    CPy_XDECREF(cpy_r_track_history);
    goto CPyL2;
CPyL159: ;
    CPy_DecRef(cpy_r_r7.f0);
    CPy_DecRef(cpy_r_r7.f1);
    goto CPyL156;
CPyL160: ;
    CPy_DecRef(cpy_r_r11);
    goto CPyL156;
CPyL161: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_r15);
    goto CPyL156;
CPyL162: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    goto CPyL156;
CPyL163: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_r30);
    goto CPyL156;
CPyL164: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_theta);
    goto CPyL156;
CPyL165: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_r49);
    goto CPyL156;
CPyL166: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    goto CPyL156;
CPyL167: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_r61);
    goto CPyL156;
CPyL168: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_r68);
    goto CPyL156;
CPyL169: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_theta);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_r68);
    CPy_DecRef(cpy_r_r74);
    goto CPyL156;
CPyL170: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_r68);
    goto CPyL156;
CPyL171: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_phi);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_r68);
    CPy_DecRef(cpy_r_r81);
    goto CPyL156;
CPyL172: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_r68);
    CPy_DecRef(cpy_r_r81);
    CPy_DecRef(cpy_r_r87);
    goto CPyL156;
CPyL173: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_r88);
    goto CPyL156;
CPyL174: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    goto CPyL156;
CPyL175: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_r103);
    goto CPyL156;
CPyL176: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_r103);
    CPy_DecRef(cpy_r_r105);
    goto CPyL156;
CPyL177: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_r103);
    CPy_DecRef(cpy_r_r105);
    CPy_DecRef(cpy_r_r107);
    goto CPyL156;
CPyL178: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_r103);
    CPy_DecRef(cpy_r_r105);
    CPy_DecRef(cpy_r_r107);
    CPy_DecRef(cpy_r_r109);
    goto CPyL156;
CPyL179: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_r103);
    CPy_DecRef(cpy_r_r105);
    CPy_DecRef(cpy_r_r107);
    CPy_DecRef(cpy_r_r109);
    CPy_DecRef(cpy_r_r111);
    goto CPyL156;
CPyL180: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_r103);
    CPy_DecRef(cpy_r_r105);
    CPy_DecRef(cpy_r_r107);
    CPy_DecRef(cpy_r_r109);
    CPy_DecRef(cpy_r_r111);
    CPy_DecRef(cpy_r_r113);
    goto CPyL156;
CPyL181: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_r114);
    goto CPyL156;
CPyL182: ;
    CPy_DECREF(cpy_r_endpoint_dist);
    CPy_DECREF(cpy_r_PMT_hit_condition);
    CPy_DECREF(cpy_r_total_dist);
    CPy_DECREF(cpy_r_dt);
    CPy_DECREF(cpy_r_u);
    CPy_DECREF(cpy_r_r114);
    CPy_DECREF(cpy_r_r129);
    goto CPyL46;
CPyL183: ;
    CPy_INCREF(cpy_r_o);
    CPy_INCREF(cpy_r_notabsorbed);
    goto CPyL50;
CPyL184: ;
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_notabsorbed);
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_i);
    goto CPyL156;
CPyL185: ;
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_notabsorbed);
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r134);
    goto CPyL156;
CPyL186: ;
    CPy_DecRef(cpy_r_o);
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_i);
    goto CPyL156;
CPyL187: ;
    CPy_DECREF(cpy_r_PMT_hit_condition);
    goto CPyL56;
CPyL188: ;
    CPy_DECREF(cpy_r_o);
    CPy_DECREF(cpy_r_u);
    goto CPyL136;
CPyL189: ;
    CPy_DecRef(cpy_r_o);
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_i);
    goto CPyL156;
CPyL190: ;
    CPy_DecRef(cpy_r_o);
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r148);
    goto CPyL156;
CPyL191: ;
    CPy_DecRef(cpy_r_o);
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r149);
    goto CPyL156;
CPyL192: ;
    CPy_DECREF(cpy_r_o);
    CPy_XDECREF(cpy_r_track_history);
    CPy_DECREF(cpy_r_endpoint_dist);
    CPy_DECREF(cpy_r_total_dist);
    CPy_DECREF(cpy_r_dt);
    CPy_DECREF(cpy_r_u);
    CPy_DECREF(cpy_r_i);
    CPy_DECREF(cpy_r_r163);
    goto CPyL63;
CPyL193: ;
    CPy_DECREF(cpy_r_o);
    CPy_XDECREF(cpy_r_track_history);
    CPy_DECREF(cpy_r_endpoint_dist);
    CPy_DECREF(cpy_r_total_dist);
    CPy_DECREF(cpy_r_dt);
    CPy_DECREF(cpy_r_u);
    CPy_DECREF(cpy_r_i);
    CPy_DECREF(cpy_r_r163);
    CPy_DECREF(cpy_r_ds);
    goto CPyL66;
CPyL194: ;
    CPy_DECREF(cpy_r_o);
    CPy_XDECREF(cpy_r_track_history);
    CPy_DECREF(cpy_r_endpoint_dist);
    CPy_DECREF(cpy_r_PMT_hit_condition);
    CPy_DECREF(cpy_r_total_dist);
    CPy_DECREF(cpy_r_dt);
    CPy_DECREF(cpy_r_u);
    CPy_DECREF(cpy_r_i);
    CPy_DECREF(cpy_r_ds);
    CPy_DECREF(cpy_r_r168);
    goto CPyL69;
CPyL195: ;
    CPy_DecRef(cpy_r_o);
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_ds);
    goto CPyL156;
CPyL196: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_ds);
    goto CPyL156;
CPyL197: ;
    CPy_XDECREF(cpy_r_track_history);
    CPy_DECREF(cpy_r_endpoint_dist);
    CPy_DECREF(cpy_r_PMT_hit_condition);
    CPy_DECREF(cpy_r_total_dist);
    CPy_DECREF(cpy_r_dt);
    CPy_DECREF(cpy_r_u);
    CPy_DECREF(cpy_r_i);
    CPy_DECREF(cpy_r_ds);
    CPy_DECREF(cpy_r_r172);
    goto CPyL75;
CPyL198: ;
    CPy_XDECREF(cpy_r_track_history);
    CPy_DECREF(cpy_r_endpoint_dist);
    CPy_DECREF(cpy_r_PMT_hit_condition);
    CPy_DECREF(cpy_r_total_dist);
    CPy_DECREF(cpy_r_dt);
    CPy_DECREF(cpy_r_u);
    CPy_DECREF(cpy_r_i);
    CPy_DECREF(cpy_r_ds);
    CPy_DECREF(cpy_r_r172);
    CPy_DECREF(cpy_r_x);
    goto CPyL78;
CPyL199: ;
    CPy_XDECREF(cpy_r_track_history);
    CPy_DECREF(cpy_r_endpoint_dist);
    CPy_DECREF(cpy_r_PMT_hit_condition);
    CPy_DECREF(cpy_r_total_dist);
    CPy_DECREF(cpy_r_dt);
    CPy_DECREF(cpy_r_u);
    CPy_DECREF(cpy_r_i);
    CPy_DECREF(cpy_r_ds);
    CPy_DECREF(cpy_r_r172);
    CPy_DECREF(cpy_r_x);
    CPy_DECREF(cpy_r_y);
    goto CPyL81;
CPyL200: ;
    CPy_XDECREF(cpy_r_track_history);
    CPy_DECREF(cpy_r_endpoint_dist);
    CPy_DECREF(cpy_r_PMT_hit_condition);
    CPy_DECREF(cpy_r_total_dist);
    CPy_DECREF(cpy_r_dt);
    CPy_DECREF(cpy_r_u);
    CPy_DECREF(cpy_r_i);
    CPy_DECREF(cpy_r_ds);
    CPy_DECREF(cpy_r_x);
    CPy_DECREF(cpy_r_y);
    CPy_DECREF(cpy_r_z);
    CPy_DECREF(cpy_r_r179);
    goto CPyL84;
CPyL201: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_ds);
    CPy_DecRef(cpy_r_x);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_z);
    goto CPyL156;
CPyL202: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_ds);
    CPy_DecRef(cpy_r_x);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_z);
    CPy_DecRef(cpy_r_r186);
    goto CPyL156;
CPyL203: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_ds);
    CPy_DecRef(cpy_r_x);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_z);
    goto CPyL156;
CPyL204: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_ds);
    CPy_DecRef(cpy_r_x);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_z);
    CPy_DecRef(cpy_r_r196);
    goto CPyL156;
CPyL205: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_ds);
    CPy_DecRef(cpy_r_x);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_z);
    CPy_DecRef(cpy_r_r216);
    goto CPyL156;
CPyL206: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_ds);
    CPy_DecRef(cpy_r_x);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_z);
    CPy_DecRef(cpy_r_r217);
    goto CPyL156;
CPyL207: ;
    CPy_DecRef(cpy_r_o);
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_ds);
    CPy_DecRef(cpy_r_x);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_z);
    goto CPyL156;
CPyL208: ;
    CPy_DecRef(cpy_r_o);
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_x);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_z);
    goto CPyL156;
CPyL209: ;
    CPy_DecRef(cpy_r_o);
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_x);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_z);
    goto CPyL156;
CPyL210: ;
    CPy_DecRef(cpy_r_o);
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_x);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_z);
    goto CPyL156;
CPyL211: ;
    CPy_DECREF(cpy_r_o);
    CPy_XDECREF(cpy_r_track_history);
    CPy_DECREF(cpy_r_endpoint_dist);
    CPy_DECREF(cpy_r_PMT_hit_condition);
    CPy_DECREF(cpy_r_total_dist);
    CPy_DECREF(cpy_r_dt);
    CPy_DECREF(cpy_r_i);
    CPy_DECREF(cpy_r_x);
    CPy_DECREF(cpy_r_y);
    CPy_DECREF(cpy_r_z);
    CPy_DECREF(cpy_r_r239);
    goto CPyL115;
CPyL212: ;
    CPy_DECREF(cpy_r_o);
    CPy_XDECREF(cpy_r_track_history);
    CPy_DECREF(cpy_r_endpoint_dist);
    CPy_DECREF(cpy_r_PMT_hit_condition);
    CPy_DECREF(cpy_r_total_dist);
    CPy_DECREF(cpy_r_dt);
    CPy_DECREF(cpy_r_u);
    CPy_DECREF(cpy_r_i);
    CPy_DECREF(cpy_r_x);
    CPy_DECREF(cpy_r_y);
    CPy_DECREF(cpy_r_z);
    CPy_DECREF(cpy_r_r239);
    goto CPyL118;
CPyL213: ;
    CPy_DECREF(cpy_r_o);
    CPy_DECREF(cpy_r_notabsorbed);
    CPy_XDECREF(cpy_r_track_history);
    CPy_DECREF(cpy_r_endpoint_dist);
    CPy_DECREF(cpy_r_PMT_hit_condition);
    CPy_DECREF(cpy_r_total_dist);
    CPy_DECREF(cpy_r_dt);
    CPy_DECREF(cpy_r_u);
    CPy_DECREF(cpy_r_i);
    CPy_DECREF(cpy_r_x);
    CPy_DECREF(cpy_r_y);
    CPy_DECREF(cpy_r_z);
    CPy_DECREF(cpy_r_r244);
    goto CPyL121;
CPyL214: ;
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_notabsorbed);
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_x);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_z);
    goto CPyL156;
CPyL215: ;
    CPy_DECREF(cpy_r_x);
    CPy_DECREF(cpy_r_y);
    CPy_DECREF(cpy_r_z);
    goto CPyL134;
CPyL216: ;
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_notabsorbed);
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_x);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_z);
    CPy_DecRef(cpy_r_r250);
    goto CPyL156;
CPyL217: ;
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_notabsorbed);
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_x);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_z);
    CPy_DecRef(cpy_r_r250);
    CPy_DecRef(cpy_r_r252);
    goto CPyL156;
CPyL218: ;
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_notabsorbed);
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_x);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_z);
    CPy_DecRef(cpy_r_r250);
    CPy_DecRef(cpy_r_r252);
    CPy_DecRef(cpy_r_r254);
    goto CPyL156;
CPyL219: ;
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_notabsorbed);
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r255);
    goto CPyL156;
CPyL220: ;
    CPy_DECREF(cpy_r_o);
    CPy_DECREF(cpy_r_notabsorbed);
    CPy_DECREF(cpy_r_endpoint_dist);
    CPy_DECREF(cpy_r_PMT_hit_condition);
    CPy_DECREF(cpy_r_total_dist);
    CPy_DECREF(cpy_r_dt);
    CPy_DECREF(cpy_r_u);
    CPy_DECREF(cpy_r_i);
    CPy_DECREF(cpy_r_r255);
    CPy_DECREF(cpy_r_r265);
    goto CPyL131;
CPyL221: ;
    CPy_DecRef(cpy_r_o);
    CPy_DecRef(cpy_r_notabsorbed);
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_u);
    goto CPyL156;
CPyL222: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_i);
    goto CPyL156;
CPyL223: ;
    CPy_DECREF(cpy_r_endpoint_dist);
    CPy_DECREF(cpy_r_total_dist);
    goto CPyL138;
CPyL224: ;
    CPy_XDECREF(cpy_r_track_history);
    goto CPyL154;
CPyL225: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_i);
    goto CPyL156;
CPyL226: ;
    CPy_DECREF(cpy_r_i);
    goto CPyL149;
CPyL227: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_dt);
    goto CPyL156;
CPyL228: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_r282);
    goto CPyL156;
CPyL229: ;
    CPy_DECREF(cpy_r_PMT_hit_condition);
    CPy_DECREF(cpy_r_dt);
    CPy_DECREF(cpy_r_r288);
    goto CPyL145;
CPyL230: ;
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_dt);
    goto CPyL156;
CPyL231: ;
    CPy_XDecRef(cpy_r_track_history);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    goto CPyL156;
CPyL232: ;
    CPy_DECREF(cpy_r_PMT_hit_condition);
    CPy_DECREF(cpy_r_r291);
    goto CPyL151;
CPyL233: ;
    CPy_DecRef(cpy_r_endpoint_dist);
    CPy_DecRef(cpy_r_PMT_hit_condition);
    CPy_DecRef(cpy_r_total_dist);
    CPy_DecRef(cpy_r_dt);
    CPy_DecRef(cpy_r_i);
    goto CPyL156;
}

PyObject *CPyPy_Simulation___scintillator_monte_carlo(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"o", "notabsorbed", "scint_radius", "scint_plane", "light_guide_planes", "pmt_center", "pmt_radius", "corner_center", "corner_radius", "N_max", "t", "keepdata", 0};
    static CPyArg_Parser parser = {"OOOOOOOOOOOO:scintillator_monte_carlo", kwlist, 0};
    PyObject *obj_o;
    PyObject *obj_notabsorbed;
    PyObject *obj_scint_radius;
    PyObject *obj_scint_plane;
    PyObject *obj_light_guide_planes;
    PyObject *obj_pmt_center;
    PyObject *obj_pmt_radius;
    PyObject *obj_corner_center;
    PyObject *obj_corner_radius;
    PyObject *obj_N_max;
    PyObject *obj_t;
    PyObject *obj_keepdata;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_o, &obj_notabsorbed, &obj_scint_radius, &obj_scint_plane, &obj_light_guide_planes, &obj_pmt_center, &obj_pmt_radius, &obj_corner_center, &obj_corner_radius, &obj_N_max, &obj_t, &obj_keepdata)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *arg_o = obj_o;
    PyObject *arg_notabsorbed = obj_notabsorbed;
    PyObject *arg_scint_radius = obj_scint_radius;
    PyObject *arg_scint_plane = obj_scint_plane;
    PyObject *arg_light_guide_planes = obj_light_guide_planes;
    PyObject *arg_pmt_center = obj_pmt_center;
    PyObject *arg_pmt_radius = obj_pmt_radius;
    PyObject *arg_corner_center = obj_corner_center;
    PyObject *arg_corner_radius = obj_corner_radius;
    PyObject *arg_N_max = obj_N_max;
    PyObject *arg_t = obj_t;
    PyObject *arg_keepdata = obj_keepdata;
    PyObject *retval = CPyDef_Simulation___scintillator_monte_carlo(arg_self, arg_o, arg_notabsorbed, arg_scint_radius, arg_scint_plane, arg_light_guide_planes, arg_pmt_center, arg_pmt_radius, arg_corner_center, arg_corner_radius, arg_N_max, arg_t, arg_keepdata);
    return retval;
fail: ;
    CPy_AddTraceback("modTof.py", "scintillator_monte_carlo", 323, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Simulation___photontoElectrons(PyObject *cpy_r_self, PyObject *cpy_r_photons) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_e;
    PyObject *cpy_r_r1;
    PyObject **cpy_r_r3;
    PyObject *cpy_r_r4;
    CPyTagged cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_i;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    int32_t cpy_r_r9;
    char cpy_r_r10;
    char cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    int32_t cpy_r_r20;
    char cpy_r_r21;
    char cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    CPyTagged cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    CPyTagged cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_dynode;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    int32_t cpy_r_r34;
    char cpy_r_r35;
    char cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_delta_voltage;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject **cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    CPyTagged cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    cpy_r_r0 = PyFloat_FromDouble(0.0);
    cpy_r_e = cpy_r_r0;
    cpy_r_r1 = (PyObject *)&PyLong_Type;
    PyObject *cpy_r_r2[1] = {cpy_r_photons};
    cpy_r_r3 = (PyObject **)&cpy_r_r2;
    cpy_r_r4 = _PyObject_Vectorcall(cpy_r_r1, cpy_r_r3, 1, 0);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("modTof.py", "photontoElectrons", 355, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r5 = 0;
    CPyTagged_INCREF(cpy_r_r5);
    cpy_r_r6 = CPyTagged_StealAsObject(cpy_r_r5);
    cpy_r_i = cpy_r_r6;
    CPy_DECREF(cpy_r_i);
CPyL2: ;
    CPyTagged_INCREF(cpy_r_r5);
    cpy_r_r7 = CPyTagged_StealAsObject(cpy_r_r5);
    cpy_r_r8 = PyObject_RichCompare(cpy_r_r7, cpy_r_r4, 0);
    CPy_DECREF(cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("modTof.py", "photontoElectrons", 355, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r9 = PyObject_IsTrue(cpy_r_r8);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r10 = cpy_r_r9 >= 0;
    if (unlikely(!cpy_r_r10)) {
        CPy_AddTraceback("modTof.py", "photontoElectrons", 355, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r11 = cpy_r_r9;
    if (!cpy_r_r11) goto CPyL35;
    cpy_r_r12 = CPyModule_numpy;
    cpy_r_r13 = CPyStatics[36]; /* 'random' */
    cpy_r_r14 = CPyObject_GetAttr(cpy_r_r12, cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("modTof.py", "photontoElectrons", 356, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r15 = CPyStatics[36]; /* 'random' */
    cpy_r_r16 = CPyObject_GetAttr(cpy_r_r14, cpy_r_r15);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("modTof.py", "photontoElectrons", 356, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r17 = _PyObject_Vectorcall(cpy_r_r16, 0, 0, 0);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("modTof.py", "photontoElectrons", 356, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r18 = ((modTof___SimulationObject *)cpy_r_self)->_QE;
    CPy_INCREF(cpy_r_r18);
    cpy_r_r19 = PyObject_RichCompare(cpy_r_r17, cpy_r_r18, 0);
    CPy_DECREF(cpy_r_r17);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("modTof.py", "photontoElectrons", 356, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r20 = PyObject_IsTrue(cpy_r_r19);
    CPy_DECREF(cpy_r_r19);
    cpy_r_r21 = cpy_r_r20 >= 0;
    if (unlikely(!cpy_r_r21)) {
        CPy_AddTraceback("modTof.py", "photontoElectrons", 356, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r22 = cpy_r_r20;
    if (!cpy_r_r22) goto CPyL13;
    cpy_r_r23 = CPyStatics[247]; /* 1 */
    cpy_r_r24 = PyNumber_InPlaceAdd(cpy_r_e, cpy_r_r23);
    CPy_DECREF(cpy_r_e);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("modTof.py", "photontoElectrons", 357, CPyStatic_globals);
        goto CPyL36;
    }
    cpy_r_e = cpy_r_r24;
CPyL13: ;
    cpy_r_r25 = CPyTagged_Add(cpy_r_r5, 2);
    CPyTagged_DECREF(cpy_r_r5);
    CPyTagged_INCREF(cpy_r_r25);
    cpy_r_r5 = cpy_r_r25;
    cpy_r_r26 = CPyTagged_StealAsObject(cpy_r_r25);
    cpy_r_i = cpy_r_r26;
    CPy_DECREF(cpy_r_i);
    goto CPyL2;
CPyL14: ;
    cpy_r_r27 = ((modTof___SimulationObject *)cpy_r_self)->_n_dynodes;
    CPy_INCREF(cpy_r_r27);
    cpy_r_r28 = CPyStatics[247]; /* 1 */
    cpy_r_r29 = PyNumber_Subtract(cpy_r_r27, cpy_r_r28);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("modTof.py", "photontoElectrons", 358, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r30 = 0;
    CPyTagged_INCREF(cpy_r_r30);
    cpy_r_r31 = CPyTagged_StealAsObject(cpy_r_r30);
    cpy_r_dynode = cpy_r_r31;
CPyL16: ;
    CPyTagged_INCREF(cpy_r_r30);
    cpy_r_r32 = CPyTagged_StealAsObject(cpy_r_r30);
    cpy_r_r33 = PyObject_RichCompare(cpy_r_r32, cpy_r_r29, 0);
    CPy_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("modTof.py", "photontoElectrons", 358, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r34 = PyObject_IsTrue(cpy_r_r33);
    CPy_DECREF(cpy_r_r33);
    cpy_r_r35 = cpy_r_r34 >= 0;
    if (unlikely(!cpy_r_r35)) {
        CPy_AddTraceback("modTof.py", "photontoElectrons", 358, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r36 = cpy_r_r34;
    if (!cpy_r_r36) goto CPyL38;
    cpy_r_r37 = ((modTof___SimulationObject *)cpy_r_self)->_V;
    CPy_INCREF(cpy_r_r37);
    cpy_r_r38 = CPyStatics[247]; /* 1 */
    cpy_r_r39 = PyNumber_Add(cpy_r_dynode, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("modTof.py", "photontoElectrons", 359, CPyStatic_globals);
        goto CPyL39;
    }
    cpy_r_r40 = PyObject_GetItem(cpy_r_r37, cpy_r_r39);
    CPy_DECREF(cpy_r_r37);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("modTof.py", "photontoElectrons", 359, CPyStatic_globals);
        goto CPyL37;
    }
    cpy_r_r41 = ((modTof___SimulationObject *)cpy_r_self)->_V;
    CPy_INCREF(cpy_r_r41);
    cpy_r_r42 = PyObject_GetItem(cpy_r_r41, cpy_r_dynode);
    CPy_DECREF(cpy_r_r41);
    CPy_DECREF(cpy_r_dynode);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("modTof.py", "photontoElectrons", 359, CPyStatic_globals);
        goto CPyL40;
    }
    cpy_r_r43 = PyNumber_Subtract(cpy_r_r40, cpy_r_r42);
    CPy_DECREF(cpy_r_r40);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("modTof.py", "photontoElectrons", 359, CPyStatic_globals);
        goto CPyL41;
    }
    cpy_r_delta_voltage = cpy_r_r43;
    cpy_r_r44 = PyNumber_Multiply(cpy_r_e, cpy_r_delta_voltage);
    CPy_DECREF(cpy_r_delta_voltage);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("modTof.py", "photontoElectrons", 360, CPyStatic_globals);
        goto CPyL41;
    }
    cpy_r_r45 = ((modTof___SimulationObject *)cpy_r_self)->_E_per_electron;
    CPy_INCREF(cpy_r_r45);
    cpy_r_r46 = PyNumber_TrueDivide(cpy_r_r44, cpy_r_r45);
    CPy_DECREF(cpy_r_r44);
    CPy_DECREF(cpy_r_r45);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("modTof.py", "photontoElectrons", 360, CPyStatic_globals);
        goto CPyL41;
    }
    cpy_r_r47 = CPyModule_numpy;
    cpy_r_r48 = CPyStatics[36]; /* 'random' */
    cpy_r_r49 = CPyObject_GetAttr(cpy_r_r47, cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("modTof.py", "photontoElectrons", 360, CPyStatic_globals);
        goto CPyL42;
    }
    cpy_r_r50 = CPyStatics[44]; /* 'poisson' */
    cpy_r_r51 = CPyObject_GetAttr(cpy_r_r49, cpy_r_r50);
    CPy_DECREF(cpy_r_r49);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("modTof.py", "photontoElectrons", 360, CPyStatic_globals);
        goto CPyL42;
    }
    PyObject *cpy_r_r52[1] = {cpy_r_r46};
    cpy_r_r53 = (PyObject **)&cpy_r_r52;
    cpy_r_r54 = _PyObject_Vectorcall(cpy_r_r51, cpy_r_r53, 1, 0);
    CPy_DECREF(cpy_r_r51);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("modTof.py", "photontoElectrons", 360, CPyStatic_globals);
        goto CPyL42;
    }
    CPy_DECREF(cpy_r_r46);
    cpy_r_r55 = PyNumber_InPlaceAdd(cpy_r_e, cpy_r_r54);
    CPy_DECREF(cpy_r_e);
    CPy_DECREF(cpy_r_r54);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("modTof.py", "photontoElectrons", 360, CPyStatic_globals);
        goto CPyL43;
    }
    cpy_r_e = cpy_r_r55;
    cpy_r_r56 = CPyTagged_Add(cpy_r_r30, 2);
    CPyTagged_DECREF(cpy_r_r30);
    CPyTagged_INCREF(cpy_r_r56);
    cpy_r_r30 = cpy_r_r56;
    cpy_r_r57 = CPyTagged_StealAsObject(cpy_r_r56);
    cpy_r_dynode = cpy_r_r57;
    goto CPyL16;
CPyL31: ;
    return cpy_r_e;
CPyL32: ;
    cpy_r_r58 = NULL;
    return cpy_r_r58;
CPyL33: ;
    CPy_DecRef(cpy_r_e);
    goto CPyL32;
CPyL34: ;
    CPy_DecRef(cpy_r_e);
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r5);
    goto CPyL32;
CPyL35: ;
    CPy_DECREF(cpy_r_r4);
    CPyTagged_DECREF(cpy_r_r5);
    goto CPyL14;
CPyL36: ;
    CPy_DecRef(cpy_r_r4);
    CPyTagged_DecRef(cpy_r_r5);
    goto CPyL32;
CPyL37: ;
    CPy_DecRef(cpy_r_e);
    CPy_DecRef(cpy_r_r29);
    CPyTagged_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_dynode);
    goto CPyL32;
CPyL38: ;
    CPy_DECREF(cpy_r_r29);
    CPyTagged_DECREF(cpy_r_r30);
    CPy_DECREF(cpy_r_dynode);
    goto CPyL31;
CPyL39: ;
    CPy_DecRef(cpy_r_e);
    CPy_DecRef(cpy_r_r29);
    CPyTagged_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_dynode);
    CPy_DecRef(cpy_r_r37);
    goto CPyL32;
CPyL40: ;
    CPy_DecRef(cpy_r_e);
    CPy_DecRef(cpy_r_r29);
    CPyTagged_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_r40);
    goto CPyL32;
CPyL41: ;
    CPy_DecRef(cpy_r_e);
    CPy_DecRef(cpy_r_r29);
    CPyTagged_DecRef(cpy_r_r30);
    goto CPyL32;
CPyL42: ;
    CPy_DecRef(cpy_r_e);
    CPy_DecRef(cpy_r_r29);
    CPyTagged_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_r46);
    goto CPyL32;
CPyL43: ;
    CPy_DecRef(cpy_r_r29);
    CPyTagged_DecRef(cpy_r_r30);
    goto CPyL32;
}

PyObject *CPyPy_Simulation___photontoElectrons(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"photons", 0};
    static CPyArg_Parser parser = {"O:photontoElectrons", kwlist, 0};
    PyObject *obj_photons;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_photons)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *arg_photons = obj_photons;
    PyObject *retval = CPyDef_Simulation___photontoElectrons(arg_self, arg_photons);
    return retval;
fail: ;
    CPy_AddTraceback("modTof.py", "photontoElectrons", 353, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Simulation___particle_task(PyObject *cpy_r_self, PyObject *cpy_r_mult) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    CPyPtr cpy_r_r15;
    CPyPtr cpy_r_r16;
    CPyPtr cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    CPyPtr cpy_r_r22;
    CPyPtr cpy_r_r23;
    CPyPtr cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    cpy_r_r0 = ((modTof___SimulationObject *)cpy_r_self)->_t_initial;
    CPy_INCREF(cpy_r_r0);
    cpy_r_r1 = ((modTof___SimulationObject *)cpy_r_self)->_seperation_time;
    CPy_INCREF(cpy_r_r1);
    cpy_r_r2 = PyNumber_Multiply(cpy_r_r1, cpy_r_mult);
    CPy_DECREF(cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_task", 367, CPyStatic_globals);
        goto CPyL9;
    }
    cpy_r_r3 = PyNumber_Add(cpy_r_r0, cpy_r_r2);
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_task", 367, CPyStatic_globals);
        goto CPyL8;
    }
    cpy_r_r4 = ((modTof___SimulationObject *)cpy_r_self)->_particle_init_angle_range;
    CPy_INCREF(cpy_r_r4);
    cpy_r_r5 = ((modTof___SimulationObject *)cpy_r_self)->_T1z;
    CPy_INCREF(cpy_r_r5);
    cpy_r_r6 = ((modTof___SimulationObject *)cpy_r_self)->_T1_width;
    CPy_INCREF(cpy_r_r6);
    cpy_r_r7 = ((modTof___SimulationObject *)cpy_r_self)->_T4z;
    CPy_INCREF(cpy_r_r7);
    cpy_r_r8 = ((modTof___SimulationObject *)cpy_r_self)->_T4_width;
    CPy_INCREF(cpy_r_r8);
    cpy_r_r9 = ((modTof___SimulationObject *)cpy_r_self)->_T1_radius;
    CPy_INCREF(cpy_r_r9);
    cpy_r_r10 = ((modTof___SimulationObject *)cpy_r_self)->_T4_radius;
    CPy_INCREF(cpy_r_r10);
    cpy_r_r11 = ((modTof___SimulationObject *)cpy_r_self)->_T4_radius;
    CPy_INCREF(cpy_r_r11);
    cpy_r_r12 = ((modTof___SimulationObject *)cpy_r_self)->_T4_radius;
    CPy_INCREF(cpy_r_r12);
    cpy_r_r13 = PyNumber_Negative(cpy_r_r12);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_task", 368, CPyStatic_globals);
        goto CPyL10;
    }
    cpy_r_r14 = PyList_New(2);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_task", 368, CPyStatic_globals);
        goto CPyL11;
    }
    cpy_r_r15 = (CPyPtr)&((PyListObject *)cpy_r_r14)->ob_item;
    cpy_r_r16 = *(CPyPtr *)cpy_r_r15;
    *(PyObject * *)cpy_r_r16 = cpy_r_r11;
    cpy_r_r17 = cpy_r_r16 + 8;
    *(PyObject * *)cpy_r_r17 = cpy_r_r13;
    cpy_r_r18 = ((modTof___SimulationObject *)cpy_r_self)->_T1_radius;
    CPy_INCREF(cpy_r_r18);
    cpy_r_r19 = ((modTof___SimulationObject *)cpy_r_self)->_T1_radius;
    CPy_INCREF(cpy_r_r19);
    cpy_r_r20 = PyNumber_Negative(cpy_r_r19);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_task", 369, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r21 = PyList_New(2);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_task", 369, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r22 = (CPyPtr)&((PyListObject *)cpy_r_r21)->ob_item;
    cpy_r_r23 = *(CPyPtr *)cpy_r_r22;
    *(PyObject * *)cpy_r_r23 = cpy_r_r18;
    cpy_r_r24 = cpy_r_r23 + 8;
    *(PyObject * *)cpy_r_r24 = cpy_r_r20;
    cpy_r_r25 = ((modTof___SimulationObject *)cpy_r_self)->_mean_free_path_scints;
    CPy_INCREF(cpy_r_r25);
    cpy_r_r26 = ((modTof___SimulationObject *)cpy_r_self)->_photons_produced_per_MeV;
    CPy_INCREF(cpy_r_r26);
    cpy_r_r27 = ((modTof___SimulationObject *)cpy_r_self)->_pr_of_scintillation;
    CPy_INCREF(cpy_r_r27);
    cpy_r_r28 = CPyDef_Simulation___particle_path(cpy_r_self, cpy_r_r3, cpy_r_r4, cpy_r_r5, cpy_r_r6, cpy_r_r7, cpy_r_r8, cpy_r_r9, cpy_r_r10, cpy_r_r14, cpy_r_r21, cpy_r_r25, cpy_r_r26, cpy_r_r27);
    CPy_DECREF(cpy_r_r3);
    CPy_DECREF(cpy_r_r4);
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r6);
    CPy_DECREF(cpy_r_r7);
    CPy_DECREF(cpy_r_r8);
    CPy_DECREF(cpy_r_r9);
    CPy_DECREF(cpy_r_r10);
    CPy_DECREF(cpy_r_r14);
    CPy_DECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r25);
    CPy_DECREF(cpy_r_r26);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("modTof.py", "particle_task", 367, CPyStatic_globals);
        goto CPyL8;
    }
    return cpy_r_r28;
CPyL8: ;
    cpy_r_r29 = NULL;
    return cpy_r_r29;
CPyL9: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL8;
CPyL10: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r11);
    goto CPyL8;
CPyL11: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r13);
    goto CPyL8;
CPyL12: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r18);
    goto CPyL8;
CPyL13: ;
    CPy_DecRef(cpy_r_r3);
    CPy_DecRef(cpy_r_r4);
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r6);
    CPy_DecRef(cpy_r_r7);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r10);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r18);
    CPy_DecRef(cpy_r_r20);
    goto CPyL8;
}

PyObject *CPyPy_Simulation___particle_task(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"mult", 0};
    static CPyArg_Parser parser = {"O:particle_task", kwlist, 0};
    PyObject *obj_mult;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, nargs, kwnames, &parser, &obj_mult)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *arg_mult = obj_mult;
    PyObject *retval = CPyDef_Simulation___particle_task(arg_self, arg_mult);
    return retval;
fail: ;
    CPy_AddTraceback("modTof.py", "particle_task", 366, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Simulation___scint_taskT1(PyObject *cpy_r_self, PyObject *cpy_r_xpoint, PyObject *cpy_r_ypoint, PyObject *cpy_r_zpoint, PyObject *cpy_r_time_i) {
    tuple_T3OOO cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_point_i;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    CPyPtr cpy_r_r12;
    CPyPtr cpy_r_r13;
    CPyPtr cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject **cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    CPyPtr cpy_r_r25;
    CPyPtr cpy_r_r26;
    CPyPtr cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    cpy_r_r0.f0 = cpy_r_xpoint;
    cpy_r_r0.f1 = cpy_r_ypoint;
    cpy_r_r0.f2 = cpy_r_zpoint;
    CPy_INCREF(cpy_r_r0.f0);
    CPy_INCREF(cpy_r_r0.f1);
    CPy_INCREF(cpy_r_r0.f2);
    cpy_r_r1 = CPyModule_numpy;
    cpy_r_r2 = CPyStatics[47]; /* 'hstack' */
    cpy_r_r3 = CPyObject_GetAttr(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_taskT1", 373, CPyStatic_globals);
        goto CPyL10;
    }
    cpy_r_r4 = PyTuple_New(3);
    if (unlikely(cpy_r_r4 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp53 = cpy_r_r0.f0;
    PyTuple_SET_ITEM(cpy_r_r4, 0, __tmp53);
    PyObject *__tmp54 = cpy_r_r0.f1;
    PyTuple_SET_ITEM(cpy_r_r4, 1, __tmp54);
    PyObject *__tmp55 = cpy_r_r0.f2;
    PyTuple_SET_ITEM(cpy_r_r4, 2, __tmp55);
    PyObject *cpy_r_r5[1] = {cpy_r_r4};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = _PyObject_Vectorcall(cpy_r_r3, cpy_r_r6, 1, 0);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_taskT1", 373, CPyStatic_globals);
        goto CPyL11;
    }
    CPy_DECREF(cpy_r_r4);
    cpy_r_point_i = cpy_r_r7;
    cpy_r_r8 = ((modTof___SimulationObject *)cpy_r_self)->_T1_radius;
    CPy_INCREF(cpy_r_r8);
    cpy_r_r9 = ((modTof___SimulationObject *)cpy_r_self)->_T1z;
    CPy_INCREF(cpy_r_r9);
    cpy_r_r10 = ((modTof___SimulationObject *)cpy_r_self)->_T1top;
    CPy_INCREF(cpy_r_r10);
    cpy_r_r11 = PyList_New(2);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_taskT1", 375, CPyStatic_globals);
        goto CPyL12;
    }
    cpy_r_r12 = (CPyPtr)&((PyListObject *)cpy_r_r11)->ob_item;
    cpy_r_r13 = *(CPyPtr *)cpy_r_r12;
    *(PyObject * *)cpy_r_r13 = cpy_r_r9;
    cpy_r_r14 = cpy_r_r13 + 8;
    *(PyObject * *)cpy_r_r14 = cpy_r_r10;
    cpy_r_r15 = CPyModule_numpy;
    cpy_r_r16 = CPyStatics[32]; /* 'array' */
    cpy_r_r17 = CPyObject_GetAttr(cpy_r_r15, cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_taskT1", 375, CPyStatic_globals);
        goto CPyL13;
    }
    PyObject *cpy_r_r18[1] = {cpy_r_r11};
    cpy_r_r19 = (PyObject **)&cpy_r_r18;
    cpy_r_r20 = _PyObject_Vectorcall(cpy_r_r17, cpy_r_r19, 1, 0);
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_taskT1", 375, CPyStatic_globals);
        goto CPyL13;
    }
    CPy_DECREF(cpy_r_r11);
    cpy_r_r21 = ((modTof___SimulationObject *)cpy_r_self)->_T1_radius;
    CPy_INCREF(cpy_r_r21);
    cpy_r_r22 = ((modTof___SimulationObject *)cpy_r_self)->_T1_radius;
    CPy_INCREF(cpy_r_r22);
    cpy_r_r23 = PyNumber_Negative(cpy_r_r22);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_taskT1", 376, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r24 = PyList_New(2);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_taskT1", 376, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r25 = (CPyPtr)&((PyListObject *)cpy_r_r24)->ob_item;
    cpy_r_r26 = *(CPyPtr *)cpy_r_r25;
    *(PyObject * *)cpy_r_r26 = cpy_r_r21;
    cpy_r_r27 = cpy_r_r26 + 8;
    *(PyObject * *)cpy_r_r27 = cpy_r_r23;
    cpy_r_r28 = ((modTof___SimulationObject *)cpy_r_self)->_PMT1_center;
    CPy_INCREF(cpy_r_r28);
    cpy_r_r29 = ((modTof___SimulationObject *)cpy_r_self)->_PMT1_radius;
    CPy_INCREF(cpy_r_r29);
    cpy_r_r30 = ((modTof___SimulationObject *)cpy_r_self)->_T1_corner_center;
    CPy_INCREF(cpy_r_r30);
    cpy_r_r31 = ((modTof___SimulationObject *)cpy_r_self)->_T1_corner_radius;
    CPy_INCREF(cpy_r_r31);
    cpy_r_r32 = ((modTof___SimulationObject *)cpy_r_self)->_max_simulated_reflections;
    CPy_INCREF(cpy_r_r32);
    cpy_r_r33 = 1 ? Py_True : Py_False;
    cpy_r_r34 = 0 ? Py_True : Py_False;
    cpy_r_r35 = CPyDef_Simulation___scintillator_monte_carlo(cpy_r_self, cpy_r_point_i, cpy_r_r33, cpy_r_r8, cpy_r_r20, cpy_r_r24, cpy_r_r28, cpy_r_r29, cpy_r_r30, cpy_r_r31, cpy_r_r32, cpy_r_time_i, cpy_r_r34);
    CPy_DECREF(cpy_r_point_i);
    CPy_DECREF(cpy_r_r8);
    CPy_DECREF(cpy_r_r20);
    CPy_DECREF(cpy_r_r24);
    CPy_DECREF(cpy_r_r28);
    CPy_DECREF(cpy_r_r29);
    CPy_DECREF(cpy_r_r30);
    CPy_DECREF(cpy_r_r31);
    CPy_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_taskT1", 374, CPyStatic_globals);
        goto CPyL9;
    }
    return cpy_r_r35;
CPyL9: ;
    cpy_r_r36 = NULL;
    return cpy_r_r36;
CPyL10: ;
    CPy_DecRef(cpy_r_r0.f0);
    CPy_DecRef(cpy_r_r0.f1);
    CPy_DecRef(cpy_r_r0.f2);
    goto CPyL9;
CPyL11: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL9;
CPyL12: ;
    CPy_DecRef(cpy_r_point_i);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r10);
    goto CPyL9;
CPyL13: ;
    CPy_DecRef(cpy_r_point_i);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r11);
    goto CPyL9;
CPyL14: ;
    CPy_DecRef(cpy_r_point_i);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r20);
    CPy_DecRef(cpy_r_r21);
    goto CPyL9;
CPyL15: ;
    CPy_DecRef(cpy_r_point_i);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r20);
    CPy_DecRef(cpy_r_r21);
    CPy_DecRef(cpy_r_r23);
    goto CPyL9;
}

PyObject *CPyPy_Simulation___scint_taskT1(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"xpoint", "ypoint", "zpoint", "time_i", 0};
    static CPyArg_Parser parser = {"OOOO:scint_taskT1", kwlist, 0};
    PyObject *obj_xpoint;
    PyObject *obj_ypoint;
    PyObject *obj_zpoint;
    PyObject *obj_time_i;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_xpoint, &obj_ypoint, &obj_zpoint, &obj_time_i)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *arg_xpoint = obj_xpoint;
    PyObject *arg_ypoint = obj_ypoint;
    PyObject *arg_zpoint = obj_zpoint;
    PyObject *arg_time_i = obj_time_i;
    PyObject *retval = CPyDef_Simulation___scint_taskT1(arg_self, arg_xpoint, arg_ypoint, arg_zpoint, arg_time_i);
    return retval;
fail: ;
    CPy_AddTraceback("modTof.py", "scint_taskT1", 371, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Simulation___scint_taskT4(PyObject *cpy_r_self, PyObject *cpy_r_xpoint, PyObject *cpy_r_ypoint, PyObject *cpy_r_zpoint, PyObject *cpy_r_time_i) {
    tuple_T3OOO cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_point_i;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    CPyPtr cpy_r_r12;
    CPyPtr cpy_r_r13;
    CPyPtr cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject **cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    CPyPtr cpy_r_r26;
    CPyPtr cpy_r_r27;
    CPyPtr cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    cpy_r_r0.f0 = cpy_r_xpoint;
    cpy_r_r0.f1 = cpy_r_ypoint;
    cpy_r_r0.f2 = cpy_r_zpoint;
    CPy_INCREF(cpy_r_r0.f0);
    CPy_INCREF(cpy_r_r0.f1);
    CPy_INCREF(cpy_r_r0.f2);
    cpy_r_r1 = CPyModule_numpy;
    cpy_r_r2 = CPyStatics[47]; /* 'hstack' */
    cpy_r_r3 = CPyObject_GetAttr(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_taskT4", 380, CPyStatic_globals);
        goto CPyL11;
    }
    cpy_r_r4 = PyTuple_New(3);
    if (unlikely(cpy_r_r4 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp56 = cpy_r_r0.f0;
    PyTuple_SET_ITEM(cpy_r_r4, 0, __tmp56);
    PyObject *__tmp57 = cpy_r_r0.f1;
    PyTuple_SET_ITEM(cpy_r_r4, 1, __tmp57);
    PyObject *__tmp58 = cpy_r_r0.f2;
    PyTuple_SET_ITEM(cpy_r_r4, 2, __tmp58);
    PyObject *cpy_r_r5[1] = {cpy_r_r4};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = _PyObject_Vectorcall(cpy_r_r3, cpy_r_r6, 1, 0);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_taskT4", 380, CPyStatic_globals);
        goto CPyL12;
    }
    CPy_DECREF(cpy_r_r4);
    cpy_r_point_i = cpy_r_r7;
    cpy_r_r8 = ((modTof___SimulationObject *)cpy_r_self)->_T4_radius;
    CPy_INCREF(cpy_r_r8);
    cpy_r_r9 = ((modTof___SimulationObject *)cpy_r_self)->_T4z;
    CPy_INCREF(cpy_r_r9);
    cpy_r_r10 = ((modTof___SimulationObject *)cpy_r_self)->_T4top;
    CPy_INCREF(cpy_r_r10);
    cpy_r_r11 = PyList_New(2);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_taskT4", 382, CPyStatic_globals);
        goto CPyL13;
    }
    cpy_r_r12 = (CPyPtr)&((PyListObject *)cpy_r_r11)->ob_item;
    cpy_r_r13 = *(CPyPtr *)cpy_r_r12;
    *(PyObject * *)cpy_r_r13 = cpy_r_r9;
    cpy_r_r14 = cpy_r_r13 + 8;
    *(PyObject * *)cpy_r_r14 = cpy_r_r10;
    cpy_r_r15 = CPyModule_numpy;
    cpy_r_r16 = CPyStatics[32]; /* 'array' */
    cpy_r_r17 = CPyObject_GetAttr(cpy_r_r15, cpy_r_r16);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_taskT4", 382, CPyStatic_globals);
        goto CPyL14;
    }
    PyObject *cpy_r_r18[1] = {cpy_r_r11};
    cpy_r_r19 = (PyObject **)&cpy_r_r18;
    cpy_r_r20 = _PyObject_Vectorcall(cpy_r_r17, cpy_r_r19, 1, 0);
    CPy_DECREF(cpy_r_r17);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_taskT4", 382, CPyStatic_globals);
        goto CPyL14;
    }
    CPy_DECREF(cpy_r_r11);
    cpy_r_r21 = ((modTof___SimulationObject *)cpy_r_self)->_T4_radius;
    CPy_INCREF(cpy_r_r21);
    cpy_r_r22 = PyNumber_Negative(cpy_r_r21);
    CPy_DECREF(cpy_r_r21);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_taskT4", 383, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r23 = ((modTof___SimulationObject *)cpy_r_self)->_T4_radius;
    CPy_INCREF(cpy_r_r23);
    cpy_r_r24 = PyNumber_Positive(cpy_r_r23);
    CPy_DECREF(cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_taskT4", 383, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r25 = PyList_New(2);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_taskT4", 383, CPyStatic_globals);
        goto CPyL17;
    }
    cpy_r_r26 = (CPyPtr)&((PyListObject *)cpy_r_r25)->ob_item;
    cpy_r_r27 = *(CPyPtr *)cpy_r_r26;
    *(PyObject * *)cpy_r_r27 = cpy_r_r22;
    cpy_r_r28 = cpy_r_r27 + 8;
    *(PyObject * *)cpy_r_r28 = cpy_r_r24;
    cpy_r_r29 = ((modTof___SimulationObject *)cpy_r_self)->_PMT4_center;
    CPy_INCREF(cpy_r_r29);
    cpy_r_r30 = ((modTof___SimulationObject *)cpy_r_self)->_PMT4_radius;
    CPy_INCREF(cpy_r_r30);
    cpy_r_r31 = ((modTof___SimulationObject *)cpy_r_self)->_T4_corner_center;
    CPy_INCREF(cpy_r_r31);
    cpy_r_r32 = ((modTof___SimulationObject *)cpy_r_self)->_T4_corner_radius;
    CPy_INCREF(cpy_r_r32);
    cpy_r_r33 = ((modTof___SimulationObject *)cpy_r_self)->_max_simulated_reflections;
    CPy_INCREF(cpy_r_r33);
    cpy_r_r34 = 1 ? Py_True : Py_False;
    cpy_r_r35 = 0 ? Py_True : Py_False;
    cpy_r_r36 = CPyDef_Simulation___scintillator_monte_carlo(cpy_r_self, cpy_r_point_i, cpy_r_r34, cpy_r_r8, cpy_r_r20, cpy_r_r25, cpy_r_r29, cpy_r_r30, cpy_r_r31, cpy_r_r32, cpy_r_r33, cpy_r_time_i, cpy_r_r35);
    CPy_DECREF(cpy_r_point_i);
    CPy_DECREF(cpy_r_r8);
    CPy_DECREF(cpy_r_r20);
    CPy_DECREF(cpy_r_r25);
    CPy_DECREF(cpy_r_r29);
    CPy_DECREF(cpy_r_r30);
    CPy_DECREF(cpy_r_r31);
    CPy_DECREF(cpy_r_r32);
    CPy_DECREF(cpy_r_r33);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("modTof.py", "scint_taskT4", 381, CPyStatic_globals);
        goto CPyL10;
    }
    return cpy_r_r36;
CPyL10: ;
    cpy_r_r37 = NULL;
    return cpy_r_r37;
CPyL11: ;
    CPy_DecRef(cpy_r_r0.f0);
    CPy_DecRef(cpy_r_r0.f1);
    CPy_DecRef(cpy_r_r0.f2);
    goto CPyL10;
CPyL12: ;
    CPy_DecRef(cpy_r_r4);
    goto CPyL10;
CPyL13: ;
    CPy_DecRef(cpy_r_point_i);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r9);
    CPy_DecRef(cpy_r_r10);
    goto CPyL10;
CPyL14: ;
    CPy_DecRef(cpy_r_point_i);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r11);
    goto CPyL10;
CPyL15: ;
    CPy_DecRef(cpy_r_point_i);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r20);
    goto CPyL10;
CPyL16: ;
    CPy_DecRef(cpy_r_point_i);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r20);
    CPy_DecRef(cpy_r_r22);
    goto CPyL10;
CPyL17: ;
    CPy_DecRef(cpy_r_point_i);
    CPy_DecRef(cpy_r_r8);
    CPy_DecRef(cpy_r_r20);
    CPy_DecRef(cpy_r_r22);
    CPy_DecRef(cpy_r_r24);
    goto CPyL10;
}

PyObject *CPyPy_Simulation___scint_taskT4(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"xpoint", "ypoint", "zpoint", "time_i", 0};
    static CPyArg_Parser parser = {"OOOO:scint_taskT4", kwlist, 0};
    PyObject *obj_xpoint;
    PyObject *obj_ypoint;
    PyObject *obj_zpoint;
    PyObject *obj_time_i;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_xpoint, &obj_ypoint, &obj_zpoint, &obj_time_i)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *arg_xpoint = obj_xpoint;
    PyObject *arg_ypoint = obj_ypoint;
    PyObject *arg_zpoint = obj_zpoint;
    PyObject *arg_time_i = obj_time_i;
    PyObject *retval = CPyDef_Simulation___scint_taskT4(arg_self, arg_xpoint, arg_ypoint, arg_zpoint, arg_time_i);
    return retval;
fail: ;
    CPy_AddTraceback("modTof.py", "scint_taskT4", 379, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Simulation___run(PyObject *cpy_r_self, PyObject *cpy_r_arg, PyObject *cpy_r_kwargs) {
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
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    int32_t cpy_r_r16;
    char cpy_r_r17;
    char cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject **cpy_r_r22;
    PyObject *cpy_r_r23;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject **cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    char cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject **cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    char cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_logstarttime;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_times;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_points;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_photons;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_particleID;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_i;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject **cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject **cpy_r_r81;
    PyObject *cpy_r_r82;
    char cpy_r_r83;
    PyObject *cpy_r_pool__redef__;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject **cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_res;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    char cpy_r_r97;
    PyObject *cpy_r_time_i;
    PyObject *cpy_r_r98;
    char cpy_r_r99;
    PyObject *cpy_r_point_i;
    PyObject *cpy_r_r100;
    char cpy_r_r101;
    PyObject *cpy_r_photon_i;
    PyObject *cpy_r_r102;
    char cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    CPyTagged cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject **cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    char cpy_r_r123;
    tuple_T3OOO cpy_r_r124;
    tuple_T3OOO cpy_r_r125;
    PyObject *cpy_r_r126;
    PyObject *cpy_r_r127;
    PyObject *cpy_r_r128;
    PyObject **cpy_r_r130;
    PyObject *cpy_r_r131;
    int32_t cpy_r_r132;
    char cpy_r_r133;
    char cpy_r_r134;
    char cpy_r_r135;
    tuple_T3OOO cpy_r_r136;
    tuple_T3OOO cpy_r_r137;
    tuple_T3OOO cpy_r_r138;
    PyObject *cpy_r_r139;
    PyObject **cpy_r_r141;
    PyObject *cpy_r_r142;
    char cpy_r_r143;
    PyObject *cpy_r_r144;
    PyObject *cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_logendparticle;
    PyObject *cpy_r_r148;
    PyObject *cpy_r_r149;
    PyObject *cpy_r_r150;
    PyObject **cpy_r_r152;
    PyObject *cpy_r_r153;
    PyObject *cpy_r_N;
    PyObject *cpy_r_r154;
    PyObject *cpy_r_r155;
    PyObject *cpy_r_r156;
    PyObject *cpy_r_r157;
    PyObject **cpy_r_r159;
    PyObject *cpy_r_r160;
    PyObject *cpy_r_r161;
    PyObject *cpy_r_r162;
    PyObject *cpy_r_r163;
    PyObject **cpy_r_r165;
    PyObject *cpy_r_r166;
    PyObject *cpy_r_r167;
    PyObject *cpy_r_r168;
    PyObject *cpy_r_r169;
    PyObject **cpy_r_r171;
    PyObject *cpy_r_r172;
    PyObject *cpy_r_r173;
    PyObject *cpy_r_r174;
    PyObject *cpy_r_r175;
    PyObject **cpy_r_r177;
    PyObject *cpy_r_r178;
    PyObject *cpy_r_r179;
    PyObject *cpy_r_r180;
    PyObject *cpy_r_r181;
    PyObject **cpy_r_r183;
    PyObject *cpy_r_r184;
    PyObject *cpy_r_r185;
    PyObject *cpy_r_T1_input_times;
    PyObject *cpy_r_r186;
    PyObject *cpy_r_T4_input_times;
    PyObject *cpy_r_r187;
    char cpy_r_r188;
    PyObject *cpy_r_r189;
    char cpy_r_r190;
    PyObject *cpy_r_r191;
    char cpy_r_r192;
    PyObject *cpy_r_r193;
    char cpy_r_r194;
    PyObject *cpy_r_r195;
    char cpy_r_r196;
    PyObject *cpy_r_r197;
    char cpy_r_r198;
    PyObject *cpy_r_r199;
    char cpy_r_r200;
    PyObject *cpy_r_r201;
    char cpy_r_r202;
    PyObject *cpy_r_r203;
    char cpy_r_r204;
    PyObject *cpy_r_r205;
    char cpy_r_r206;
    PyObject *cpy_r_r207;
    PyObject *cpy_r_r208;
    PyObject *cpy_r_r209;
    PyObject *cpy_r_r210;
    PyObject *cpy_r_r211;
    PyObject *cpy_r_r212;
    PyObject *cpy_r_r213;
    PyObject *cpy_r_r214;
    PyObject *cpy_r_r215;
    PyObject *cpy_r_r216;
    tuple_T2OO cpy_r_r217;
    PyObject *cpy_r_r218;
    PyObject *cpy_r_r219;
    PyObject *cpy_r_r220;
    PyObject *cpy_r_r221;
    PyObject *cpy_r_r222;
    PyObject *cpy_r_T1points;
    PyObject *cpy_r_r223;
    PyObject *cpy_r_r224;
    PyObject *cpy_r_r225;
    PyObject *cpy_r_r226;
    PyObject *cpy_r_r227;
    PyObject *cpy_r_r228;
    PyObject *cpy_r_r229;
    PyObject *cpy_r_r230;
    PyObject *cpy_r_r231;
    PyObject *cpy_r_r232;
    tuple_T2OO cpy_r_r233;
    PyObject *cpy_r_r234;
    PyObject *cpy_r_r235;
    PyObject *cpy_r_r236;
    PyObject *cpy_r_r237;
    PyObject *cpy_r_r238;
    PyObject *cpy_r_T1times;
    PyObject *cpy_r_r239;
    PyObject *cpy_r_r240;
    PyObject *cpy_r_r241;
    PyObject *cpy_r_r242;
    PyObject *cpy_r_r243;
    PyObject *cpy_r_r244;
    PyObject *cpy_r_r245;
    PyObject *cpy_r_r246;
    PyObject *cpy_r_r247;
    PyObject *cpy_r_r248;
    tuple_T2OO cpy_r_r249;
    PyObject *cpy_r_r250;
    PyObject *cpy_r_r251;
    PyObject *cpy_r_r252;
    PyObject *cpy_r_r253;
    PyObject *cpy_r_r254;
    PyObject *cpy_r_T1photons;
    PyObject *cpy_r_r255;
    PyObject *cpy_r_r256;
    PyObject *cpy_r_r257;
    PyObject *cpy_r_r258;
    PyObject *cpy_r_r259;
    PyObject *cpy_r_r260;
    PyObject *cpy_r_r261;
    PyObject *cpy_r_r262;
    PyObject *cpy_r_r263;
    PyObject *cpy_r_r264;
    tuple_T2OO cpy_r_r265;
    PyObject *cpy_r_r266;
    PyObject *cpy_r_r267;
    PyObject *cpy_r_r268;
    PyObject *cpy_r_r269;
    PyObject *cpy_r_r270;
    PyObject *cpy_r_T1part_ids;
    PyObject *cpy_r_r271;
    PyObject *cpy_r_r272;
    PyObject *cpy_r_r273;
    PyObject *cpy_r_r274;
    PyObject *cpy_r_r275;
    PyObject *cpy_r_r276;
    PyObject *cpy_r_r277;
    PyObject **cpy_r_r279;
    PyObject *cpy_r_r280;
    PyObject *cpy_r_r281;
    PyObject *cpy_r_r282;
    PyObject *cpy_r_r283;
    PyObject *cpy_r_r284;
    PyObject *cpy_r_r285;
    PyObject *cpy_r_r286;
    PyObject *cpy_r_r287;
    PyObject *cpy_r_r288;
    PyObject *cpy_r_r289;
    PyObject *cpy_r_r290;
    PyObject *cpy_r_r291;
    tuple_T2OO cpy_r_r292;
    PyObject *cpy_r_r293;
    PyObject *cpy_r_r294;
    PyObject *cpy_r_r295;
    PyObject *cpy_r_r296;
    PyObject *cpy_r_r297;
    PyObject *cpy_r_T4points;
    PyObject *cpy_r_r298;
    PyObject *cpy_r_r299;
    PyObject *cpy_r_r300;
    PyObject *cpy_r_r301;
    PyObject *cpy_r_r302;
    PyObject *cpy_r_r303;
    PyObject *cpy_r_r304;
    PyObject *cpy_r_r305;
    PyObject *cpy_r_r306;
    PyObject *cpy_r_r307;
    tuple_T2OO cpy_r_r308;
    PyObject *cpy_r_r309;
    PyObject *cpy_r_r310;
    PyObject *cpy_r_r311;
    PyObject *cpy_r_r312;
    PyObject *cpy_r_r313;
    PyObject *cpy_r_T4times;
    PyObject *cpy_r_r314;
    PyObject *cpy_r_r315;
    PyObject *cpy_r_r316;
    PyObject *cpy_r_r317;
    PyObject *cpy_r_r318;
    PyObject *cpy_r_r319;
    PyObject *cpy_r_r320;
    PyObject *cpy_r_r321;
    PyObject *cpy_r_r322;
    PyObject *cpy_r_r323;
    tuple_T2OO cpy_r_r324;
    PyObject *cpy_r_r325;
    PyObject *cpy_r_r326;
    PyObject *cpy_r_r327;
    PyObject *cpy_r_r328;
    PyObject *cpy_r_r329;
    PyObject *cpy_r_T4photons;
    PyObject *cpy_r_r330;
    PyObject *cpy_r_r331;
    PyObject *cpy_r_r332;
    PyObject *cpy_r_r333;
    PyObject *cpy_r_r334;
    PyObject *cpy_r_r335;
    PyObject *cpy_r_r336;
    PyObject *cpy_r_r337;
    PyObject *cpy_r_r338;
    PyObject *cpy_r_r339;
    tuple_T2OO cpy_r_r340;
    PyObject *cpy_r_r341;
    PyObject *cpy_r_r342;
    PyObject *cpy_r_r343;
    PyObject *cpy_r_r344;
    PyObject *cpy_r_r345;
    PyObject *cpy_r_T4part_ids;
    PyObject *cpy_r_r346;
    PyObject *cpy_r_r347;
    PyObject *cpy_r_r348;
    PyObject *cpy_r_r349;
    PyObject *cpy_r_r350;
    PyObject *cpy_r_r351;
    PyObject *cpy_r_r352;
    PyObject **cpy_r_r354;
    PyObject *cpy_r_r355;
    PyObject *cpy_r_r356;
    PyObject *cpy_r_r357;
    PyObject *cpy_r_r358;
    PyObject *cpy_r_r359;
    PyObject *cpy_r_r360;
    PyObject **cpy_r_r362;
    PyObject *cpy_r_r363;
    PyObject *cpy_r_r364;
    PyObject *cpy_r_r365;
    PyObject *cpy_r_r366;
    PyObject *cpy_r_r367;
    PyObject *cpy_r_r368;
    PyObject **cpy_r_r370;
    PyObject *cpy_r_r371;
    PyObject *cpy_r_r372;
    PyObject *cpy_r_r373;
    PyObject *cpy_r_r374;
    PyObject *cpy_r_r375;
    PyObject *cpy_r_r376;
    PyObject **cpy_r_r378;
    PyObject *cpy_r_r379;
    PyObject *cpy_r_r380;
    PyObject *cpy_r_r381;
    PyObject *cpy_r_r382;
    PyObject *cpy_r_r383;
    PyObject *cpy_r_r384;
    PyObject *cpy_r_r385;
    PyObject *cpy_r_r386;
    PyObject *cpy_r_r387;
    PyObject *cpy_r_r388;
    PyObject *cpy_r_r389;
    PyObject *cpy_r_r390;
    PyObject *cpy_r_logstartphoton;
    PyObject *cpy_r_r391;
    PyObject *cpy_r_r392;
    PyObject *cpy_r_r393;
    PyObject *cpy_r_r394;
    PyObject *cpy_r_r395;
    PyObject *cpy_r_r396;
    PyObject *cpy_r_r397;
    PyObject **cpy_r_r399;
    PyObject *cpy_r_r400;
    PyObject *cpy_r_r401;
    PyObject *cpy_r_r402;
    PyObject *cpy_r_r403;
    PyObject *cpy_r_r404;
    PyObject *cpy_r_r405;
    PyObject *cpy_r_r406;
    PyObject **cpy_r_r408;
    PyObject *cpy_r_r409;
    char cpy_r_r410;
    PyObject *cpy_r_pool;
    PyObject *cpy_r_r411;
    PyObject *cpy_r_r412;
    PyObject *cpy_r_r413;
    PyObject *cpy_r_r414;
    PyObject **cpy_r_r416;
    PyObject *cpy_r_r417;
    PyObject *cpy_r_r418;
    PyObject *cpy_r_r419;
    PyObject *cpy_r_r420;
    PyObject *cpy_r_r421;
    PyObject *cpy_r_r422;
    tuple_T2OO cpy_r_r423;
    PyObject *cpy_r_r424;
    PyObject *cpy_r_r425;
    PyObject *cpy_r_r426;
    PyObject *cpy_r_r427;
    PyObject *cpy_r_r428;
    PyObject *cpy_r_r429;
    PyObject *cpy_r_r430;
    PyObject *cpy_r_r431;
    PyObject *cpy_r_r432;
    PyObject **cpy_r_r434;
    PyObject *cpy_r_r435;
    PyObject *cpy_r_r436;
    PyObject *cpy_r_r437;
    PyObject *cpy_r_r438;
    PyObject *cpy_r_T1res;
    PyObject *cpy_r_r439;
    PyObject *cpy_r_r440;
    PyObject *cpy_r_r441;
    PyObject *cpy_r_r442;
    PyObject **cpy_r_r444;
    PyObject *cpy_r_r445;
    PyObject *cpy_r_r446;
    PyObject *cpy_r_r447;
    PyObject *cpy_r_r448;
    PyObject *cpy_r_r449;
    PyObject **cpy_r_r451;
    PyObject *cpy_r_r452;
    PyObject *cpy_r_r453;
    PyObject *cpy_r_r454;
    PyObject *cpy_r_r455;
    PyObject *cpy_r_r456;
    PyObject *cpy_r_r457;
    tuple_T2OO cpy_r_r458;
    PyObject *cpy_r_r459;
    PyObject *cpy_r_r460;
    PyObject *cpy_r_r461;
    PyObject *cpy_r_r462;
    PyObject *cpy_r_r463;
    PyObject *cpy_r_r464;
    PyObject *cpy_r_r465;
    PyObject *cpy_r_r466;
    PyObject *cpy_r_r467;
    PyObject **cpy_r_r469;
    PyObject *cpy_r_r470;
    PyObject *cpy_r_r471;
    PyObject *cpy_r_r472;
    PyObject *cpy_r_r473;
    PyObject *cpy_r_T4res;
    PyObject *cpy_r_r474;
    PyObject *cpy_r_r475;
    PyObject *cpy_r_r476;
    PyObject *cpy_r_r477;
    PyObject **cpy_r_r479;
    PyObject *cpy_r_r480;
    PyObject *cpy_r_r481;
    PyObject *cpy_r_r482;
    PyObject *cpy_r_r483;
    PyObject *cpy_r_r484;
    PyObject **cpy_r_r486;
    PyObject *cpy_r_r487;
    PyObject *cpy_r_r488;
    PyObject *cpy_r_r489;
    PyObject *cpy_r_r490;
    PyObject *cpy_r_r491;
    PyObject *cpy_r_r492;
    PyObject *cpy_r_r493;
    char cpy_r_r494;
    PyObject *cpy_r_T1hit_PMT;
    PyObject *cpy_r_r495;
    char cpy_r_r496;
    PyObject *cpy_r_T1travel_time;
    PyObject *cpy_r_r497;
    char cpy_r_r498;
    PyObject *cpy_r_T1tot_dist;
    PyObject *cpy_r_r499;
    char cpy_r_r500;
    PyObject *cpy_r_T1endpt;
    PyObject *cpy_r_r501;
    char cpy_r_r502;
    PyObject *cpy_r_T1bounces;
    PyObject *cpy_r_r503;
    char cpy_r_r504;
    PyObject *cpy_r_T1prop;
    PyObject *cpy_r_r505;
    char cpy_r_r506;
    PyObject *cpy_r_T1part_id;
    int32_t cpy_r_r507;
    char cpy_r_r508;
    char cpy_r_r509;
    PyObject *cpy_r_r510;
    PyObject *cpy_r_r511;
    PyObject *cpy_r_r512;
    PyObject *cpy_r_r513;
    PyObject *cpy_r_r514;
    PyObject *cpy_r_r515;
    PyObject *cpy_r_r516;
    PyObject *cpy_r_r517;
    PyObject *cpy_r_r518;
    PyObject *cpy_r_r519;
    PyObject *cpy_r_r520;
    PyObject *cpy_r_r521;
    PyObject *cpy_r_r522;
    PyObject *cpy_r_r523;
    PyObject *cpy_r_r524;
    PyObject *cpy_r_r525;
    PyObject *cpy_r_r526;
    char cpy_r_r527;
    char cpy_r_r528;
    PyObject *cpy_r_r529;
    PyObject *cpy_r_r530;
    PyObject *cpy_r_r531;
    PyObject *cpy_r_r532;
    PyObject *cpy_r_r533;
    PyObject *cpy_r_r534;
    char cpy_r_r535;
    PyObject *cpy_r_T4hit_PMT;
    PyObject *cpy_r_r536;
    char cpy_r_r537;
    PyObject *cpy_r_T4travel_time;
    PyObject *cpy_r_r538;
    char cpy_r_r539;
    PyObject *cpy_r_T4tot_dist;
    PyObject *cpy_r_r540;
    char cpy_r_r541;
    PyObject *cpy_r_T4endpt;
    PyObject *cpy_r_r542;
    char cpy_r_r543;
    PyObject *cpy_r_T4bounces;
    PyObject *cpy_r_r544;
    char cpy_r_r545;
    PyObject *cpy_r_T4prop;
    PyObject *cpy_r_r546;
    char cpy_r_r547;
    PyObject *cpy_r_T4part_id;
    int32_t cpy_r_r548;
    char cpy_r_r549;
    char cpy_r_r550;
    PyObject *cpy_r_r551;
    PyObject *cpy_r_r552;
    PyObject *cpy_r_r553;
    PyObject *cpy_r_r554;
    PyObject *cpy_r_r555;
    PyObject *cpy_r_r556;
    PyObject *cpy_r_r557;
    PyObject *cpy_r_r558;
    PyObject *cpy_r_r559;
    PyObject *cpy_r_r560;
    PyObject *cpy_r_r561;
    PyObject *cpy_r_r562;
    PyObject *cpy_r_r563;
    PyObject *cpy_r_r564;
    PyObject *cpy_r_r565;
    PyObject *cpy_r_r566;
    PyObject *cpy_r_r567;
    char cpy_r_r568;
    char cpy_r_r569;
    tuple_T3OOO cpy_r_r570;
    tuple_T3OOO cpy_r_r571;
    PyObject *cpy_r_r572;
    PyObject *cpy_r_r573;
    PyObject *cpy_r_r574;
    PyObject **cpy_r_r576;
    PyObject *cpy_r_r577;
    int32_t cpy_r_r578;
    char cpy_r_r579;
    char cpy_r_r580;
    char cpy_r_r581;
    tuple_T3OOO cpy_r_r582;
    tuple_T3OOO cpy_r_r583;
    tuple_T3OOO cpy_r_r584;
    PyObject *cpy_r_r585;
    PyObject **cpy_r_r587;
    PyObject *cpy_r_r588;
    char cpy_r_r589;
    PyObject *cpy_r_r590;
    PyObject *cpy_r_r591;
    PyObject *cpy_r_r592;
    PyObject *cpy_r_r593;
    PyObject *cpy_r_logendtime;
    PyObject *cpy_r_r594;
    PyObject *cpy_r_r595;
    PyObject *cpy_r_r596;
    PyObject *cpy_r_r597;
    PyObject **cpy_r_r599;
    PyObject *cpy_r_r600;
    PyObject *cpy_r_r601;
    PyObject *cpy_r_r602;
    PyObject *cpy_r_r603;
    PyObject *cpy_r_r604;
    PyObject **cpy_r_r606;
    PyObject *cpy_r_r607;
    PyObject *cpy_r_r608;
    PyObject *cpy_r_pgtime;
    PyObject *cpy_r_r609;
    PyObject *cpy_r_r610;
    PyObject *cpy_r_r611;
    PyObject *cpy_r_r612;
    PyObject **cpy_r_r614;
    PyObject *cpy_r_r615;
    PyObject *cpy_r_r616;
    PyObject *cpy_r_phtime;
    PyObject *cpy_r_r617;
    PyObject *cpy_r_r618;
    PyObject *cpy_r_r619;
    PyObject *cpy_r_r620;
    PyObject **cpy_r_r622;
    PyObject *cpy_r_r623;
    PyObject *cpy_r_r624;
    PyObject *cpy_r_ttime;
    PyObject *cpy_r_r625;
    PyObject *cpy_r_r626;
    PyObject *cpy_r_r627;
    PyObject *cpy_r_r628;
    PyObject *cpy_r_r629;
    PyObject *cpy_r_r630;
    PyObject *cpy_r_r631;
    PyObject **cpy_r_r633;
    PyObject *cpy_r_r634;
    PyObject *cpy_r_r635;
    PyObject *cpy_r_r636;
    PyObject *cpy_r_r637;
    PyObject *cpy_r_r638;
    PyObject *cpy_r_r639;
    PyObject *cpy_r_r640;
    PyObject *cpy_r_r641;
    PyObject **cpy_r_r643;
    PyObject *cpy_r_r644;
    PyObject *cpy_r_r645;
    PyObject *cpy_r_r646;
    PyObject *cpy_r_r647;
    PyObject *cpy_r_r648;
    PyObject *cpy_r_r649;
    PyObject *cpy_r_r650;
    PyObject *cpy_r_r651;
    PyObject **cpy_r_r653;
    PyObject *cpy_r_r654;
    PyObject *cpy_r_r655;
    PyObject *cpy_r_r656;
    PyObject *cpy_r_r657;
    PyObject *cpy_r_r658;
    PyObject **cpy_r_r660;
    PyObject *cpy_r_r661;
    PyObject *cpy_r_r662;
    CPyTagged cpy_r_r663;
    PyObject *cpy_r_r664;
    PyObject *cpy_r_r665;
    PyObject *cpy_r_r666;
    PyObject *cpy_r_r667;
    PyObject **cpy_r_r669;
    PyObject *cpy_r_r670;
    PyObject *cpy_r_r671;
    PyObject *cpy_r_r672;
    PyObject *cpy_r_r673;
    PyObject *cpy_r_r674;
    PyObject **cpy_r_r676;
    PyObject *cpy_r_r677;
    PyObject *cpy_r_r678;
    CPyTagged cpy_r_r679;
    PyObject *cpy_r_r680;
    PyObject *cpy_r_r681;
    PyObject *cpy_r_r682;
    PyObject *cpy_r_r683;
    PyObject *cpy_r_r684;
    PyObject *cpy_r_r685;
    PyObject *cpy_r_r686;
    PyObject **cpy_r_r688;
    PyObject *cpy_r_r689;
    CPyTagged cpy_r_r690;
    PyObject *cpy_r_r691;
    PyObject *cpy_r_r692;
    PyObject *cpy_r_r693;
    PyObject *cpy_r_r694;
    PyObject *cpy_r_r695;
    PyObject *cpy_r_r696;
    CPyPtr cpy_r_r697;
    CPyPtr cpy_r_r698;
    CPyPtr cpy_r_r699;
    PyObject *cpy_r_r700;
    PyObject *cpy_r_r701;
    PyObject *cpy_r_r702;
    PyObject *cpy_r_r703;
    PyObject **cpy_r_r705;
    PyObject *cpy_r_r706;
    PyObject *cpy_r_r707;
    CPyTagged cpy_r_r708;
    PyObject *cpy_r_r709;
    PyObject *cpy_r_r710;
    PyObject *cpy_r_r711;
    PyObject *cpy_r_r712;
    PyObject **cpy_r_r714;
    PyObject *cpy_r_r715;
    PyObject *cpy_r_r716;
    PyObject *cpy_r_r717;
    PyObject *cpy_r_r718;
    PyObject *cpy_r_r719;
    PyObject **cpy_r_r721;
    PyObject *cpy_r_r722;
    PyObject *cpy_r_r723;
    CPyTagged cpy_r_r724;
    PyObject *cpy_r_r725;
    PyObject *cpy_r_r726;
    PyObject *cpy_r_r727;
    PyObject *cpy_r_r728;
    PyObject *cpy_r_r729;
    PyObject *cpy_r_r730;
    PyObject *cpy_r_r731;
    PyObject **cpy_r_r733;
    PyObject *cpy_r_r734;
    CPyTagged cpy_r_r735;
    PyObject *cpy_r_r736;
    PyObject *cpy_r_r737;
    PyObject *cpy_r_r738;
    PyObject *cpy_r_r739;
    PyObject *cpy_r_r740;
    PyObject *cpy_r_r741;
    CPyPtr cpy_r_r742;
    CPyPtr cpy_r_r743;
    CPyPtr cpy_r_r744;
    PyObject *cpy_r_r745;
    PyObject *cpy_r_r746;
    PyObject *cpy_r_r747;
    PyObject *cpy_r_r748;
    PyObject **cpy_r_r750;
    PyObject *cpy_r_r751;
    PyObject *cpy_r_r752;
    PyObject *cpy_r_r753;
    PyObject *cpy_r_r754;
    PyObject *cpy_r_r755;
    PyObject **cpy_r_r757;
    PyObject *cpy_r_r758;
    PyObject *cpy_r_r759;
    PyObject *cpy_r_r760;
    PyObject *cpy_r_r761;
    PyObject *cpy_r_r762;
    PyObject *cpy_r_r763;
    PyObject *cpy_r_r764;
    PyObject *cpy_r_r765;
    PyObject *cpy_r_r766;
    PyObject *cpy_r_r767;
    PyObject *cpy_r_r768;
    PyObject *cpy_r_r769;
    PyObject *cpy_r_signals_channelT1;
    PyObject *cpy_r_r770;
    PyObject *cpy_r_signals_channelT4;
    PyObject *cpy_r_r771;
    PyObject *cpy_r_output_times_channelT1;
    PyObject *cpy_r_r772;
    PyObject *cpy_r_output_times_channelT4;
    PyObject *cpy_r_r773;
    PyObject *cpy_r_signals;
    PyObject *cpy_r_r774;
    PyObject *cpy_r_output_times;
    PyObject *cpy_r_r775;
    PyObject *cpy_r_r776;
    PyObject *cpy_r_t;
    PyObject *cpy_r_r777;
    PyObject *cpy_r_r778;
    PyObject *cpy_r_pmtSignal_i;
    PyObject *cpy_r_r779;
    PyObject *cpy_r_r780;
    PyObject *cpy_r_r781;
    PyObject *cpy_r_r782;
    PyObject *cpy_r_r783;
    PyObject *cpy_r_r784;
    PyObject *cpy_r_r785;
    PyObject *cpy_r_r786;
    PyObject *cpy_r_r787;
    PyObject *cpy_r_r788;
    PyObject *cpy_r_r789;
    PyObject *cpy_r_r790;
    char cpy_r_r791;
    PyObject *cpy_r_r792;
    PyObject *cpy_r_r793;
    PyObject *cpy_r_r794;
    PyObject *cpy_r_r795;
    PyObject *cpy_r_r796;
    PyObject *cpy_r_r797;
    PyObject *cpy_r_r798;
    PyObject *cpy_r_r799;
    PyObject *cpy_r_r800;
    PyObject *cpy_r_r801;
    PyObject *cpy_r_r802;
    PyObject *cpy_r_r803;
    PyObject *cpy_r_r804;
    PyObject *cpy_r_r805;
    PyObject *cpy_r_r806;
    PyObject *cpy_r_r807;
    char cpy_r_r808;
    PyObject *cpy_r_r809;
    PyObject *cpy_r_r810;
    PyObject *cpy_r_r811;
    PyObject **cpy_r_r813;
    PyObject *cpy_r_r814;
    PyObject *cpy_r_r815;
    PyObject *cpy_r_r816;
    PyObject *cpy_r_r817;
    PyObject *cpy_r_r818;
    PyObject *cpy_r_r819;
    PyObject *cpy_r_r820;
    char cpy_r_r821;
    PyObject *cpy_r_r822;
    PyObject *cpy_r_r823;
    PyObject *cpy_r_r824;
    PyObject **cpy_r_r826;
    PyObject *cpy_r_r827;
    char cpy_r_r828;
    PyObject *cpy_r_r829;
    PyObject *cpy_r_r830;
    PyObject *cpy_r_r831;
    PyObject **cpy_r_r833;
    PyObject *cpy_r_r834;
    PyObject *cpy_r_r835;
    PyObject *cpy_r_r836;
    PyObject *cpy_r_r837;
    PyObject *cpy_r_r838;
    PyObject *cpy_r_r839;
    PyObject *cpy_r_r840;
    char cpy_r_r841;
    PyObject *cpy_r_r842;
    PyObject *cpy_r_r843;
    PyObject *cpy_r_r844;
    PyObject **cpy_r_r846;
    PyObject *cpy_r_r847;
    PyObject *cpy_r_r848;
    PyObject *cpy_r_r849;
    PyObject *cpy_r_r850;
    PyObject *cpy_r_r851;
    PyObject *cpy_r_r852;
    PyObject *cpy_r_r853;
    PyObject *cpy_r_r854;
    PyObject *cpy_r_r855;
    char cpy_r_r856;
    PyObject *cpy_r_r857;
    PyObject *cpy_r_r858;
    PyObject *cpy_r_r859;
    PyObject **cpy_r_r861;
    PyObject *cpy_r_r862;
    char cpy_r_r863;
    PyObject *cpy_r_r864;
    PyObject *cpy_r_r865;
    PyObject *cpy_r_r866;
    PyObject **cpy_r_r868;
    PyObject *cpy_r_r869;
    char cpy_r_r870;
    PyObject *cpy_r_r871;
    PyObject *cpy_r_r872;
    PyObject *cpy_r_r873;
    PyObject *cpy_r_r874;
    PyObject *cpy_r_r875;
    PyObject *cpy_r_r876;
    PyObject *cpy_r_r877;
    PyObject *cpy_r_output_extra;
    PyObject *cpy_r_r878;
    PyObject *cpy_r_r879;
    PyObject *cpy_r_r880;
    PyObject *cpy_r_output_both;
    int32_t cpy_r_r881;
    char cpy_r_r882;
    char cpy_r_r883;
    int32_t cpy_r_r884;
    char cpy_r_r885;
    char cpy_r_r886;
    PyObject *cpy_r_r887;
    PyObject *cpy_r_r888;
    PyObject *cpy_r_r889;
    PyObject *cpy_r_r890;
    PyObject **cpy_r_r892;
    PyObject *cpy_r_r893;
    PyObject *cpy_r_r894;
    PyObject *cpy_r_r895;
    PyObject *cpy_r_r896;
    PyObject *cpy_r_r897;
    PyObject *cpy_r_r898;
    PyObject *cpy_r_r899;
    PyObject *cpy_r_r900;
    PyObject *cpy_r_r901;
    PyObject *cpy_r_r902;
    PyObject *cpy_r_r903;
    PyObject *cpy_r_r904;
    PyObject *cpy_r_r905;
    PyObject *cpy_r_r906;
    PyObject *cpy_r_r907;
    PyObject *cpy_r_r908;
    PyObject *cpy_r_r909;
    PyObject **cpy_r_r911;
    PyObject *cpy_r_r912;
    PyObject *cpy_r_dft1;
    PyObject *cpy_r_r913;
    PyObject *cpy_r_r914;
    PyObject *cpy_r_r915;
    PyObject *cpy_r_r916;
    PyObject *cpy_r_r917;
    PyObject *cpy_r_r918;
    PyObject *cpy_r_r919;
    PyObject *cpy_r_r920;
    PyObject *cpy_r_r921;
    PyObject *cpy_r_r922;
    PyObject *cpy_r_r923;
    PyObject *cpy_r_r924;
    PyObject *cpy_r_r925;
    PyObject *cpy_r_r926;
    PyObject *cpy_r_r927;
    PyObject *cpy_r_r928;
    PyObject **cpy_r_r930;
    PyObject *cpy_r_r931;
    PyObject *cpy_r_dft4;
    PyObject *cpy_r_r932;
    PyObject *cpy_r_r933;
    PyObject *cpy_r_r934;
    PyObject *cpy_r_r935;
    PyObject *cpy_r_r936;
    PyObject *cpy_r_r937;
    PyObject *cpy_r_r938;
    PyObject *cpy_r_r939;
    PyObject *cpy_r_r940;
    PyObject *cpy_r_r941;
    PyObject *cpy_r_r942;
    PyObject *cpy_r_r943;
    PyObject *cpy_r_r944;
    PyObject *cpy_r_r945;
    PyObject *cpy_r_r946;
    PyObject *cpy_r_r947;
    PyObject *cpy_r_r948;
    PyObject *cpy_r_r949;
    PyObject *cpy_r_r950;
    PyObject *cpy_r_r951;
    PyObject *cpy_r_r952;
    PyObject *cpy_r_r953;
    PyObject *cpy_r_r954;
    PyObject *cpy_r_r955;
    PyObject *cpy_r_r956;
    PyObject *cpy_r_r957;
    PyObject *cpy_r_r958;
    PyObject *cpy_r_r959;
    PyObject *cpy_r_r960;
    PyObject *cpy_r_r961;
    PyObject *cpy_r_r962;
    PyObject *cpy_r_r963;
    PyObject *cpy_r_r964;
    PyObject *cpy_r_r965;
    PyObject *cpy_r_r966;
    PyObject *cpy_r_r967;
    PyObject *cpy_r_r968;
    PyObject *cpy_r_r969;
    PyObject *cpy_r_r970;
    PyObject *cpy_r_r971;
    int32_t cpy_r_r972;
    char cpy_r_r973;
    char cpy_r_r974;
    PyObject *cpy_r_r975;
    PyObject *cpy_r_r976;
    PyObject *cpy_r_r977;
    PyObject *cpy_r_r978;
    PyObject *cpy_r_r979;
    PyObject **cpy_r_r981;
    PyObject *cpy_r_r982;
    PyObject *cpy_r_r983;
    PyObject *cpy_r_r984;
    PyObject *cpy_r_r985;
    CPyPtr cpy_r_r986;
    CPyPtr cpy_r_r987;
    CPyPtr cpy_r_r988;
    CPyTagged cpy_r_r989;
    PyObject *cpy_r_r990;
    PyObject *cpy_r_r991;
    PyObject *cpy_r_r992;
    CPyPtr cpy_r_r993;
    CPyPtr cpy_r_r994;
    CPyPtr cpy_r_r995;
    CPyTagged cpy_r_r996;
    PyObject *cpy_r_r997;
    PyObject *cpy_r_r998;
    PyObject *cpy_r_r999;
    CPyPtr cpy_r_r1000;
    CPyPtr cpy_r_r1001;
    CPyPtr cpy_r_r1002;
    CPyTagged cpy_r_r1003;
    CPyPtr cpy_r_r1004;
    int64_t cpy_r_r1005;
    CPyTagged cpy_r_r1006;
    char cpy_r_r1007;
    CPyPtr cpy_r_r1008;
    int64_t cpy_r_r1009;
    CPyTagged cpy_r_r1010;
    char cpy_r_r1011;
    CPyPtr cpy_r_r1012;
    int64_t cpy_r_r1013;
    CPyTagged cpy_r_r1014;
    char cpy_r_r1015;
    PyObject *cpy_r_r1016;
    PyObject *cpy_r_time;
    PyObject *cpy_r_r1017;
    PyObject *cpy_r_signal;
    PyObject *cpy_r_r1018;
    PyObject *cpy_r_ch;
    PyObject *cpy_r_r1019;
    PyObject *cpy_r_r1020;
    PyObject *cpy_r_r1021;
    PyObject *cpy_r_r1022;
    PyObject **cpy_r_r1024;
    PyObject *cpy_r_r1025;
    PyObject *cpy_r_r1026;
    PyObject *cpy_r_r1027;
    CPyPtr cpy_r_r1028;
    CPyPtr cpy_r_r1029;
    PyObject *cpy_r_t_binned;
    PyObject *cpy_r_r1030;
    PyObject *cpy_r_r1031;
    CPyPtr cpy_r_r1032;
    CPyPtr cpy_r_r1033;
    PyObject *cpy_r_y_binned;
    CPyTagged cpy_r_r1034;
    PyObject *cpy_r_r1035;
    PyObject *cpy_r_r1036;
    PyObject *cpy_r_r1037;
    PyObject *cpy_r_y;
    PyObject *cpy_r_r1038;
    PyObject *cpy_r_r1039;
    PyObject *cpy_r_r1040;
    PyObject *cpy_r_r1041;
    PyObject *cpy_r_r1042;
    PyObject *cpy_r_r1043;
    PyObject *cpy_r_r1044;
    int32_t cpy_r_r1045;
    char cpy_r_r1046;
    char cpy_r_r1047;
    PyObject *cpy_r_r1048;
    PyObject *cpy_r_r1049;
    PyObject *cpy_r_lower_bound;
    PyObject *cpy_r_r1050;
    PyObject *cpy_r_r1051;
    PyObject *cpy_r_r1052;
    PyObject *cpy_r_r1053;
    PyObject *cpy_r_r1054;
    PyObject *cpy_r_r1055;
    PyObject *cpy_r_r1056;
    PyObject *cpy_r_r1057;
    PyObject **cpy_r_r1059;
    PyObject *cpy_r_r1060;
    PyObject *cpy_r_r1061;
    PyObject *cpy_r_r1062;
    PyObject *cpy_r_r1063;
    PyObject *cpy_r_r1064;
    PyObject *cpy_r_r1065;
    int32_t cpy_r_r1066;
    char cpy_r_r1067;
    char cpy_r_r1068;
    PyObject *cpy_r_r1069;
    PyObject *cpy_r_upper_bound;
    PyObject *cpy_r_r1070;
    PyObject *cpy_r_r1071;
    PyObject *cpy_r_r1072;
    PyObject **cpy_r_r1074;
    PyObject *cpy_r_r1075;
    PyObject *cpy_r_r1076;
    int32_t cpy_r_r1077;
    char cpy_r_r1078;
    char cpy_r_r1079;
    PyObject *cpy_r_r1080;
    PyObject *cpy_r_r1081;
    PyObject *cpy_r_r1082;
    PyObject **cpy_r_r1084;
    PyObject *cpy_r_r1085;
    PyObject *cpy_r_r1086;
    PyObject *cpy_r_r1087;
    PyObject *cpy_r_r1088;
    PyObject *cpy_r_r1089;
    PyObject *cpy_r_r1090;
    PyObject *cpy_r_r1091;
    PyObject *cpy_r_r1092;
    PyObject *cpy_r_r1093;
    PyObject *cpy_r_r1094;
    PyObject **cpy_r_r1096;
    PyObject *cpy_r_r1097;
    PyObject *cpy_r_r1098;
    PyObject *cpy_r_r1099;
    PyObject *cpy_r_r1100;
    PyObject *cpy_r_r1101;
    PyObject *cpy_r_cur_x;
    PyObject *cpy_r_r1102;
    PyObject *cpy_r_r1103;
    PyObject *cpy_r_x;
    PyObject *cpy_r_r1104;
    PyObject *cpy_r_r1105;
    PyObject *cpy_r_r1106;
    PyObject **cpy_r_r1108;
    PyObject *cpy_r_r1109;
    PyObject *cpy_r_r1110;
    int32_t cpy_r_r1111;
    char cpy_r_r1112;
    char cpy_r_r1113;
    PyObject *cpy_r_r1114;
    PyObject *cpy_r_r1115;
    PyObject *cpy_r_r1116;
    PyObject *cpy_r_r1117;
    PyObject *cpy_r_r1118;
    PyObject *cpy_r_r1119;
    PyObject *cpy_r_r1120;
    PyObject *cpy_r_r1121;
    PyObject **cpy_r_r1123;
    PyObject *cpy_r_r1124;
    PyObject *cpy_r_r1125;
    PyObject *cpy_r_r1126;
    PyObject *cpy_r_r1127;
    PyObject *cpy_r_r1128;
    int32_t cpy_r_r1129;
    char cpy_r_r1130;
    char cpy_r_r1131;
    PyObject *cpy_r_r1132;
    PyObject *cpy_r_r1133;
    PyObject *cpy_r_r1134;
    PyObject **cpy_r_r1136;
    PyObject *cpy_r_r1137;
    CPyTagged cpy_r_r1138;
    PyObject *cpy_r_r1139;
    PyObject *cpy_r_r1140;
    int32_t cpy_r_r1141;
    char cpy_r_r1142;
    char cpy_r_r1143;
    PyObject *cpy_r_r1144;
    PyObject *cpy_r_r1145;
    PyObject *cpy_r_r1146;
    PyObject **cpy_r_r1148;
    PyObject *cpy_r_r1149;
    PyObject *cpy_r_index;
    PyObject *cpy_r_r1150;
    PyObject *cpy_r_r1151;
    PyObject *cpy_r_r1152;
    PyObject *cpy_r_r1153;
    PyObject *cpy_r_r1154;
    PyObject *cpy_r_r1155;
    PyObject *cpy_r_r1156;
    PyObject *cpy_r_r1157;
    int32_t cpy_r_r1158;
    char cpy_r_r1159;
    char cpy_r_r1160;
    PyObject *cpy_r_r1161;
    PyObject *cpy_r_r1162;
    PyObject *cpy_r_r1163;
    PyObject *cpy_r_r1164;
    PyObject *cpy_r_r1165;
    char cpy_r_r1166;
    PyObject *cpy_r_r1167;
    CPyTagged cpy_r_r1168;
    PyObject *cpy_r_r1169;
    PyObject *cpy_r_i_2;
    PyObject *cpy_r_r1170;
    PyObject *cpy_r_r1171;
    PyObject *cpy_r_t_2;
    PyObject *cpy_r_r1172;
    int32_t cpy_r_r1173;
    char cpy_r_r1174;
    char cpy_r_r1175;
    int32_t cpy_r_r1176;
    char cpy_r_r1177;
    CPyTagged cpy_r_r1178;
    PyObject *cpy_r_r1179;
    char cpy_r_r1180;
    PyObject *cpy_r_r1181;
    PyObject *cpy_r_index_lower;
    PyObject *cpy_r_r1182;
    CPyTagged cpy_r_r1183;
    PyObject *cpy_r_r1184;
    PyObject *cpy_r_i_3;
    PyObject *cpy_r_r1185;
    PyObject *cpy_r_r1186;
    PyObject *cpy_r_t_3;
    PyObject *cpy_r_r1187;
    int32_t cpy_r_r1188;
    char cpy_r_r1189;
    char cpy_r_r1190;
    int32_t cpy_r_r1191;
    char cpy_r_r1192;
    CPyTagged cpy_r_r1193;
    PyObject *cpy_r_r1194;
    char cpy_r_r1195;
    PyObject *cpy_r_r1196;
    PyObject *cpy_r_r1197;
    PyObject *cpy_r_index_upper;
    PyObject *cpy_r_r1198;
    PyObject *cpy_r_r1199;
    PyObject *cpy_r_r1200;
    PyObject *cpy_r_r1201;
    PyObject *cpy_r_r1202;
    PyObject *cpy_r_r1203;
    PyObject *cpy_r_r1204;
    PyObject *cpy_r_r1205;
    PyObject *cpy_r_r1206;
    PyObject *cpy_r_r1207;
    PyObject **cpy_r_r1209;
    PyObject *cpy_r_r1210;
    PyObject *cpy_r_r1211;
    PyObject *cpy_r_r1212;
    PyObject *cpy_r_r1213;
    PyObject *cpy_r_r1214;
    PyObject *cpy_r_r1215;
    PyObject *cpy_r_r1216;
    PyObject *cpy_r_gaussian;
    CPyTagged cpy_r_r1217;
    PyObject *cpy_r_r1218;
    PyObject *cpy_r_r1219;
    PyObject *cpy_r_r1220;
    PyObject *cpy_r_y_add;
    PyObject *cpy_r_r1221;
    PyObject *cpy_r_r1222;
    PyObject *cpy_r_r1223;
    PyObject *cpy_r_r1224;
    PyObject *cpy_r_r1225;
    int32_t cpy_r_r1226;
    char cpy_r_r1227;
    char cpy_r_r1228;
    PyObject *cpy_r_r1229;
    PyObject *cpy_r_r1230;
    PyObject *cpy_r_r1231;
    int32_t cpy_r_r1232;
    char cpy_r_r1233;
    PyObject *cpy_r_r1234;
    PyObject *cpy_r_r1235;
    int32_t cpy_r_r1236;
    char cpy_r_r1237;
    CPyTagged cpy_r_r1238;
    PyObject *cpy_r_r1239;
    char cpy_r_r1240;
    CPyTagged cpy_r_r1241;
    PyObject *cpy_r_r1242;
    char cpy_r_r1243;
    PyObject *cpy_r_r1244;
    PyObject *cpy_r_r1245;
    PyObject *cpy_r_r1246;
    PyObject *cpy_r_r1247;
    PyObject *cpy_r_r1248;
    PyObject *cpy_r_r1249;
    PyObject **cpy_r_r1251;
    PyObject *cpy_r_r1252;
    PyObject *cpy_r_r1253;
    PyObject *cpy_r_r1254;
    CPyPtr cpy_r_r1255;
    CPyPtr cpy_r_r1256;
    PyObject *cpy_r_r1257;
    PyObject *cpy_r_r1258;
    PyObject **cpy_r_r1260;
    PyObject *cpy_r_r1261;
    PyObject *cpy_r_r1262;
    PyObject *cpy_r_df;
    PyObject *cpy_r_r1263;
    PyObject *cpy_r_r1264;
    PyObject *cpy_r_r1265;
    PyObject *cpy_r_r1266;
    PyObject **cpy_r_r1268;
    PyObject *cpy_r_r1269;
    PyObject *cpy_r_r1270;
    PyObject *cpy_r_fill_data;
    PyObject *cpy_r_r1271;
    PyObject *cpy_r_r1272;
    PyObject *cpy_r_r1273;
    PyObject *cpy_r_r1274;
    PyObject *cpy_r_r1275;
    PyObject *cpy_r_r1276;
    PyObject *cpy_r_r1277;
    PyObject *cpy_r_r1278;
    PyObject *cpy_r_r1279;
    PyObject *cpy_r_r1280;
    PyObject *cpy_r_r1281;
    PyObject *cpy_r_r1282;
    CPyPtr cpy_r_r1283;
    CPyPtr cpy_r_r1284;
    CPyPtr cpy_r_r1285;
    PyObject *cpy_r_r1286;
    PyObject *cpy_r_r1287;
    PyObject *cpy_r_r1288;
    PyObject *cpy_r_r1289;
    CPyTagged cpy_r_r1290;
    PyObject *cpy_r_r1291;
    PyObject *cpy_r_r1292;
    PyObject *cpy_r_r1293;
    CPyTagged cpy_r_r1294;
    PyObject *cpy_r_r1295;
    PyObject *cpy_r_r1296;
    PyObject *cpy_r_r1297;
    int32_t cpy_r_r1298;
    char cpy_r_r1299;
    char cpy_r_r1300;
    PyObject *cpy_r_r1301;
    PyObject *cpy_r_r1302;
    PyObject *cpy_r_r1303;
    PyObject *cpy_r_r1304;
    PyObject *cpy_r_r1305;
    PyObject *cpy_r_r1306;
    PyObject *cpy_r_r1307;
    PyObject *cpy_r_r1308;
    PyObject *cpy_r_r1309;
    PyObject *cpy_r_r1310;
    PyObject *cpy_r_r1311;
    PyObject *cpy_r_r1312;
    PyObject *cpy_r_r1313;
    PyObject *cpy_r_r1314;
    PyObject *cpy_r_r1315;
    PyObject *cpy_r_r1316;
    int32_t cpy_r_r1317;
    char cpy_r_r1318;
    char cpy_r_r1319;
    PyObject *cpy_r_r1320;
    PyObject *cpy_r_r1321;
    PyObject *cpy_r_r1322;
    PyObject *cpy_r_r1323;
    PyObject *cpy_r_r1324;
    PyObject *cpy_r_r1325;
    PyObject *cpy_r_r1326;
    PyObject *cpy_r_r1327;
    PyObject *cpy_r_r1328;
    PyObject *cpy_r_r1329;
    PyObject *cpy_r_r1330;
    CPyPtr cpy_r_r1331;
    CPyPtr cpy_r_r1332;
    CPyPtr cpy_r_r1333;
    PyObject *cpy_r_r1334;
    PyObject *cpy_r_r1335;
    PyObject *cpy_r_r1336;
    PyObject *cpy_r_r1337;
    PyObject *cpy_r_r1338;
    PyObject *cpy_r_r1339;
    PyObject *cpy_r_r1340;
    PyObject *cpy_r_r1341;
    PyObject *cpy_r_r1342;
    PyObject *cpy_r_r1343;
    PyObject *cpy_r_r1344;
    PyObject *cpy_r_r1345;
    PyObject *cpy_r_r1346;
    PyObject *cpy_r_r1347;
    PyObject *cpy_r_r1348;
    CPyPtr cpy_r_r1349;
    CPyPtr cpy_r_r1350;
    CPyPtr cpy_r_r1351;
    PyObject *cpy_r_r1352;
    PyObject *cpy_r_r1353;
    CPyTagged cpy_r_r1354;
    PyObject *cpy_r_r1355;
    PyObject *cpy_r_r1356;
    PyObject *cpy_r_r1357;
    PyObject *cpy_r_r1358;
    PyObject *cpy_r_r1359;
    PyObject *cpy_r_r1360;
    PyObject *cpy_r_r1361;
    PyObject *cpy_r_r1362;
    PyObject *cpy_r_r1363;
    PyObject *cpy_r_r1364;
    PyObject *cpy_r_r1365;
    PyObject *cpy_r_r1366;
    PyObject *cpy_r_r1367;
    CPyPtr cpy_r_r1368;
    CPyPtr cpy_r_r1369;
    CPyPtr cpy_r_r1370;
    PyObject *cpy_r_r1371;
    PyObject *cpy_r_r1372;
    PyObject *cpy_r_r1373;
    PyObject *cpy_r_r1374;
    PyObject *cpy_r_r1375;
    PyObject **cpy_r_r1377;
    PyObject *cpy_r_r1378;
    PyObject *cpy_r_r1379;
    PyObject *cpy_r_r1380;
    PyObject *cpy_r_r1381;
    CPyPtr cpy_r_r1382;
    CPyPtr cpy_r_r1383;
    CPyPtr cpy_r_r1384;
    PyObject *cpy_r_r1385;
    PyObject *cpy_r_r1386;
    PyObject *cpy_r_r1387;
    PyObject **cpy_r_r1389;
    PyObject *cpy_r_r1390;
    PyObject *cpy_r_r1391;
    PyObject *cpy_r_fill;
    PyObject *cpy_r_r1392;
    CPyPtr cpy_r_r1393;
    CPyPtr cpy_r_r1394;
    CPyPtr cpy_r_r1395;
    PyObject *cpy_r_r1396;
    PyObject *cpy_r_r1397;
    PyObject *cpy_r_r1398;
    PyObject *cpy_r_r1399;
    PyObject **cpy_r_r1401;
    PyObject *cpy_r_r1402;
    PyObject *cpy_r_r1403;
    PyObject *cpy_r_r1404;
    PyObject *cpy_r_r1405;
    CPyPtr cpy_r_r1406;
    CPyPtr cpy_r_r1407;
    PyObject *cpy_r_r1408;
    PyObject *cpy_r_r1409;
    PyObject **cpy_r_r1411;
    PyObject *cpy_r_r1412;
    PyObject *cpy_r_r1413;
    PyObject *cpy_r_r1414;
    PyObject *cpy_r_r1415;
    PyObject *cpy_r_r1416;
    PyObject **cpy_r_r1418;
    PyObject *cpy_r_r1419;
    PyObject *cpy_r_r1420;
    PyObject *cpy_r_r1421;
    PyObject *cpy_r_r1422;
    PyObject *cpy_r_r1423;
    PyObject *cpy_r_r1424;
    PyObject *cpy_r_r1425;
    int32_t cpy_r_r1426;
    char cpy_r_r1427;
    PyObject *cpy_r_r1428;
    PyObject *cpy_r_r1429;
    PyObject *cpy_r_r1430;
    CPyPtr cpy_r_r1431;
    CPyPtr cpy_r_r1432;
    CPyPtr cpy_r_r1433;
    PyObject *cpy_r_r1434;
    PyObject *cpy_r_r1435;
    PyObject *cpy_r_r1436;
    PyObject *cpy_r_r1437;
    PyObject *cpy_r_r1438;
    PyObject *cpy_r_r1439;
    PyObject *cpy_r_r1440;
    PyObject *cpy_r_r1441;
    PyObject *cpy_r_r1442;
    PyObject *cpy_r_r1443;
    PyObject *cpy_r_r1444;
    PyObject *cpy_r_r1445;
    PyObject *cpy_r_r1446;
    PyObject *cpy_r_r1447;
    PyObject *cpy_r_r1448;
    PyObject *cpy_r_r1449;
    PyObject *cpy_r_r1450;
    PyObject *cpy_r_r1451;
    PyObject *cpy_r_r1452;
    PyObject *cpy_r_r1453;
    PyObject *cpy_r_r1454;
    PyObject *cpy_r_r1455;
    PyObject *cpy_r_r1456;
    PyObject *cpy_r_r1457;
    PyObject *cpy_r_r1458;
    PyObject *cpy_r_r1459;
    PyObject *cpy_r_r1460;
    PyObject *cpy_r_r1461;
    PyObject *cpy_r_r1462;
    PyObject **cpy_r_r1464;
    PyObject *cpy_r_r1465;
    PyObject *cpy_r_r1466;
    CPyTagged cpy_r_r1467;
    CPyTagged cpy_r_r1468;
    CPyTagged cpy_r_r1469;
    PyObject *cpy_r_r1470;
    PyObject *cpy_r_r1471;
    PyObject *cpy_r_r1472;
    PyObject *cpy_r_r1473;
    PyObject **cpy_r_r1475;
    PyObject *cpy_r_r1476;
    PyObject *cpy_r_r1477;
    PyObject *cpy_r_r1478;
    cpy_r_r0 = CPyStatic_globals;
    cpy_r_r1 = CPyModule_gc;
    cpy_r_r2 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r3 = cpy_r_r1 != cpy_r_r2;
    if (cpy_r_r3) goto CPyL3;
    cpy_r_r4 = CPyStatics[48]; /* 'gc' */
    cpy_r_r5 = PyImport_Import(cpy_r_r4);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 391, CPyStatic_globals);
        goto CPyL720;
    }
    CPyModule_gc = cpy_r_r5;
    CPy_INCREF(CPyModule_gc);
    CPy_DECREF(cpy_r_r5);
CPyL3: ;
    cpy_r_r6 = CPyStatics[48]; /* 'gc' */
    cpy_r_r7 = PyImport_GetModuleDict();
    cpy_r_r8 = CPyStatics[48]; /* 'gc' */
    cpy_r_r9 = CPyDict_GetItem(cpy_r_r7, cpy_r_r8);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 391, CPyStatic_globals);
        goto CPyL720;
    }
    cpy_r_r10 = CPyDict_SetItem(cpy_r_r0, cpy_r_r6, cpy_r_r9);
    CPy_DECREF(cpy_r_r9);
    cpy_r_r11 = cpy_r_r10 >= 0;
    if (unlikely(!cpy_r_r11)) {
        CPy_AddTraceback("modTof.py", "run", 391, CPyStatic_globals);
        goto CPyL720;
    }
    cpy_r_r12 = CPyStatic_globals;
    cpy_r_r13 = CPyStatics[49]; /* 'freeze_support' */
    cpy_r_r14 = CPyDict_GetItem(cpy_r_r12, cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 392, CPyStatic_globals);
        goto CPyL720;
    }
    cpy_r_r15 = _PyObject_Vectorcall(cpy_r_r14, 0, 0, 0);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 392, CPyStatic_globals);
        goto CPyL720;
    } else
        goto CPyL721;
CPyL7: ;
    cpy_r_r16 = PyObject_IsTrue(cpy_r_arg);
    cpy_r_r17 = cpy_r_r16 >= 0;
    if (unlikely(!cpy_r_r17)) {
        CPy_AddTraceback("modTof.py", "run", 390, CPyStatic_globals);
        goto CPyL720;
    }
    cpy_r_r18 = cpy_r_r16;
    if (!cpy_r_r18) goto CPyL16;
    cpy_r_r19 = CPySequenceTuple_GetItem(cpy_r_arg, 0);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 394, CPyStatic_globals);
        goto CPyL720;
    }
    cpy_r_r20 = (PyObject *)&PyLong_Type;
    PyObject *cpy_r_r21[1] = {cpy_r_r19};
    cpy_r_r22 = (PyObject **)&cpy_r_r21;
    cpy_r_r23 = _PyObject_Vectorcall(cpy_r_r20, cpy_r_r22, 1, 0);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 394, CPyStatic_globals);
        goto CPyL722;
    }
    CPy_DECREF(cpy_r_r19);
    CPy_DECREF(((modTof___SimulationObject *)cpy_r_self)->_num_particles);
    ((modTof___SimulationObject *)cpy_r_self)->_num_particles = cpy_r_r23;
    cpy_r_r25 = CPyStatics[50]; /* 'Generating ' */
    cpy_r_r26 = ((modTof___SimulationObject *)cpy_r_self)->_num_particles;
    CPy_INCREF(cpy_r_r26);
    cpy_r_r27 = PyObject_Str(cpy_r_r26);
    CPy_DECREF(cpy_r_r26);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 395, CPyStatic_globals);
        goto CPyL720;
    }
    cpy_r_r28 = CPyStatics[51]; /* ' particles now...' */
    cpy_r_r29 = CPyStr_Build(3, cpy_r_r25, cpy_r_r27, cpy_r_r28);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 395, CPyStatic_globals);
        goto CPyL720;
    }
    cpy_r_r30 = CPyModule_builtins;
    cpy_r_r31 = CPyStatics[8]; /* 'print' */
    cpy_r_r32 = CPyObject_GetAttr(cpy_r_r30, cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 395, CPyStatic_globals);
        goto CPyL723;
    }
    PyObject *cpy_r_r33[1] = {cpy_r_r29};
    cpy_r_r34 = (PyObject **)&cpy_r_r33;
    cpy_r_r35 = _PyObject_Vectorcall(cpy_r_r32, cpy_r_r34, 1, 0);
    CPy_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 395, CPyStatic_globals);
        goto CPyL723;
    } else
        goto CPyL724;
CPyL15: ;
    CPy_DECREF(cpy_r_r29);
    goto CPyL21;
CPyL16: ;
    cpy_r_r36 = CPyStatics[247]; /* 1 */
    CPy_INCREF(cpy_r_r36);
    CPy_DECREF(((modTof___SimulationObject *)cpy_r_self)->_num_particles);
    ((modTof___SimulationObject *)cpy_r_self)->_num_particles = cpy_r_r36;
    cpy_r_r38 = CPyStatics[50]; /* 'Generating ' */
    cpy_r_r39 = ((modTof___SimulationObject *)cpy_r_self)->_num_particles;
    CPy_INCREF(cpy_r_r39);
    cpy_r_r40 = PyObject_Str(cpy_r_r39);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 398, CPyStatic_globals);
        goto CPyL720;
    }
    cpy_r_r41 = CPyStatics[52]; /* ' particle now...' */
    cpy_r_r42 = CPyStr_Build(3, cpy_r_r38, cpy_r_r40, cpy_r_r41);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 398, CPyStatic_globals);
        goto CPyL720;
    }
    cpy_r_r43 = CPyModule_builtins;
    cpy_r_r44 = CPyStatics[8]; /* 'print' */
    cpy_r_r45 = CPyObject_GetAttr(cpy_r_r43, cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 398, CPyStatic_globals);
        goto CPyL725;
    }
    PyObject *cpy_r_r46[1] = {cpy_r_r42};
    cpy_r_r47 = (PyObject **)&cpy_r_r46;
    cpy_r_r48 = _PyObject_Vectorcall(cpy_r_r45, cpy_r_r47, 1, 0);
    CPy_DECREF(cpy_r_r45);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 398, CPyStatic_globals);
        goto CPyL725;
    } else
        goto CPyL726;
CPyL20: ;
    CPy_DECREF(cpy_r_r42);
CPyL21: ;
    cpy_r_r49 = CPyStatics[53]; /* 'delta_t' */
    cpy_r_r50 = ((modTof___SimulationObject *)cpy_r_self)->_seperation_time;
    CPy_INCREF(cpy_r_r50);
    cpy_r_r51 = CPyDict_Get(cpy_r_kwargs, cpy_r_r49, cpy_r_r50);
    CPy_DECREF(cpy_r_r50);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 399, CPyStatic_globals);
        goto CPyL720;
    }
    CPy_DECREF(((modTof___SimulationObject *)cpy_r_self)->_seperation_time);
    ((modTof___SimulationObject *)cpy_r_self)->_seperation_time = cpy_r_r51;
    cpy_r_r53 = CPyStatic_globals;
    cpy_r_r54 = CPyStatics[54]; /* 'perf_counter' */
    cpy_r_r55 = CPyDict_GetItem(cpy_r_r53, cpy_r_r54);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 400, CPyStatic_globals);
        goto CPyL720;
    }
    cpy_r_r56 = _PyObject_Vectorcall(cpy_r_r55, 0, 0, 0);
    CPy_DECREF(cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 400, CPyStatic_globals);
        goto CPyL720;
    }
    cpy_r_logstarttime = cpy_r_r56;
    cpy_r_r57 = PyList_New(0);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 402, CPyStatic_globals);
        goto CPyL727;
    }
    cpy_r_times = cpy_r_r57;
    cpy_r_r58 = PyList_New(0);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 403, CPyStatic_globals);
        goto CPyL728;
    }
    cpy_r_points = cpy_r_r58;
    cpy_r_r59 = PyList_New(0);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 404, CPyStatic_globals);
        goto CPyL729;
    }
    cpy_r_photons = cpy_r_r59;
    cpy_r_r60 = PyList_New(0);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 405, CPyStatic_globals);
        goto CPyL730;
    }
    cpy_r_particleID = cpy_r_r60;
    cpy_r_r61 = CPyStatics[244]; /* 0 */
    CPy_INCREF(cpy_r_r61);
    cpy_r_i = cpy_r_r61;
    CPy_DECREF(cpy_r_i);
    cpy_r_r62 = CPyStatic_globals;
    cpy_r_r63 = CPyStatics[55]; /* 'cpu_count' */
    cpy_r_r64 = CPyDict_GetItem(cpy_r_r62, cpy_r_r63);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 407, CPyStatic_globals);
        goto CPyL731;
    }
    cpy_r_r65 = _PyObject_Vectorcall(cpy_r_r64, 0, 0, 0);
    CPy_DECREF(cpy_r_r64);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 407, CPyStatic_globals);
        goto CPyL731;
    }
    cpy_r_r66 = CPyStatics[247]; /* 1 */
    cpy_r_r67 = PyNumber_Subtract(cpy_r_r65, cpy_r_r66);
    CPy_DECREF(cpy_r_r65);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 407, CPyStatic_globals);
        goto CPyL731;
    }
    cpy_r_r68 = CPyStatic_globals;
    cpy_r_r69 = CPyStatics[56]; /* 'Pool' */
    cpy_r_r70 = CPyDict_GetItem(cpy_r_r68, cpy_r_r69);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 407, CPyStatic_globals);
        goto CPyL732;
    }
    PyObject *cpy_r_r71[1] = {cpy_r_r67};
    cpy_r_r72 = (PyObject **)&cpy_r_r71;
    cpy_r_r73 = CPyStatics[265]; /* ('processes',) */
    cpy_r_r74 = _PyObject_Vectorcall(cpy_r_r70, cpy_r_r72, 0, cpy_r_r73);
    CPy_DECREF(cpy_r_r70);
    if (unlikely(cpy_r_r74 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 407, CPyStatic_globals);
        goto CPyL732;
    }
    CPy_DECREF(cpy_r_r67);
    cpy_r_r75 = PyObject_Type(cpy_r_r74);
    cpy_r_r76 = CPyStatics[58]; /* '__exit__' */
    cpy_r_r77 = CPyObject_GetAttr(cpy_r_r75, cpy_r_r76);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 407, CPyStatic_globals);
        goto CPyL733;
    }
    cpy_r_r78 = CPyStatics[59]; /* '__enter__' */
    cpy_r_r79 = CPyObject_GetAttr(cpy_r_r75, cpy_r_r78);
    CPy_DECREF(cpy_r_r75);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 407, CPyStatic_globals);
        goto CPyL734;
    }
    PyObject *cpy_r_r80[1] = {cpy_r_r74};
    cpy_r_r81 = (PyObject **)&cpy_r_r80;
    cpy_r_r82 = _PyObject_Vectorcall(cpy_r_r79, cpy_r_r81, 1, 0);
    CPy_DECREF(cpy_r_r79);
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 407, CPyStatic_globals);
        goto CPyL734;
    }
    cpy_r_r83 = 1;
    cpy_r_pool__redef__ = cpy_r_r82;
    cpy_r_r84 = CPyStatics[60]; /* 'particle_task' */
    cpy_r_r85 = CPyObject_GetAttr(cpy_r_self, cpy_r_r84);
    if (unlikely(cpy_r_r85 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 408, CPyStatic_globals);
        goto CPyL735;
    }
    cpy_r_r86 = ((modTof___SimulationObject *)cpy_r_self)->_num_particles;
    CPy_INCREF(cpy_r_r86);
    cpy_r_r87 = (PyObject *)&PyRange_Type;
    PyObject *cpy_r_r88[1] = {cpy_r_r86};
    cpy_r_r89 = (PyObject **)&cpy_r_r88;
    cpy_r_r90 = _PyObject_Vectorcall(cpy_r_r87, cpy_r_r89, 1, 0);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 408, CPyStatic_globals);
        goto CPyL736;
    }
    CPy_DECREF(cpy_r_r86);
    cpy_r_r91 = CPyStatics[61]; /* 'map' */
    cpy_r_r92 = CPyObject_CallMethodObjArgs(cpy_r_pool__redef__, cpy_r_r91, cpy_r_r85, cpy_r_r90, NULL);
    CPy_DECREF(cpy_r_pool__redef__);
    CPy_DECREF(cpy_r_r85);
    CPy_DECREF(cpy_r_r90);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 408, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_res = cpy_r_r92;
    cpy_r_r93 = PyObject_GetIter(cpy_r_res);
    CPy_DECREF(cpy_r_res);
    if (unlikely(cpy_r_r93 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 409, CPyStatic_globals);
        goto CPyL65;
    }
CPyL41: ;
    cpy_r_r94 = PyIter_Next(cpy_r_r93);
    if (cpy_r_r94 == NULL) goto CPyL737;
    cpy_r_r95 = PyObject_GetIter(cpy_r_r94);
    CPy_DECREF(cpy_r_r94);
    if (unlikely(cpy_r_r95 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 409, CPyStatic_globals);
        goto CPyL738;
    }
    cpy_r_r96 = PyIter_Next(cpy_r_r95);
    if (cpy_r_r96 == NULL) {
        goto CPyL739;
    } else
        goto CPyL46;
CPyL44: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r97 = 0;
    if (unlikely(!cpy_r_r97)) {
        CPy_AddTraceback("modTof.py", "run", 409, CPyStatic_globals);
        goto CPyL65;
    } else
        goto CPyL740;
CPyL45: ;
    CPy_Unreachable();
CPyL46: ;
    cpy_r_time_i = cpy_r_r96;
    cpy_r_r98 = PyIter_Next(cpy_r_r95);
    if (cpy_r_r98 == NULL) {
        goto CPyL741;
    } else
        goto CPyL49;
CPyL47: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r99 = 0;
    if (unlikely(!cpy_r_r99)) {
        CPy_AddTraceback("modTof.py", "run", 409, CPyStatic_globals);
        goto CPyL65;
    } else
        goto CPyL742;
CPyL48: ;
    CPy_Unreachable();
CPyL49: ;
    cpy_r_point_i = cpy_r_r98;
    cpy_r_r100 = PyIter_Next(cpy_r_r95);
    if (cpy_r_r100 == NULL) {
        goto CPyL743;
    } else
        goto CPyL52;
CPyL50: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r101 = 0;
    if (unlikely(!cpy_r_r101)) {
        CPy_AddTraceback("modTof.py", "run", 409, CPyStatic_globals);
        goto CPyL65;
    } else
        goto CPyL744;
CPyL51: ;
    CPy_Unreachable();
CPyL52: ;
    cpy_r_photon_i = cpy_r_r100;
    cpy_r_r102 = PyIter_Next(cpy_r_r95);
    CPy_DECREF(cpy_r_r95);
    if (cpy_r_r102 == NULL) {
        goto CPyL55;
    } else
        goto CPyL745;
CPyL53: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r103 = 0;
    if (unlikely(!cpy_r_r103)) {
        CPy_AddTraceback("modTof.py", "run", 409, CPyStatic_globals);
        goto CPyL65;
    } else
        goto CPyL746;
CPyL54: ;
    CPy_Unreachable();
CPyL55: ;
    cpy_r_r104 = CPyStatics[244]; /* 0 */
    CPy_INCREF(cpy_r_r104);
    cpy_r_i = cpy_r_r104;
    cpy_r_r105 = CPyStatics[62]; /* 'extend' */
    cpy_r_r106 = CPyObject_CallMethodObjArgs(cpy_r_times, cpy_r_r105, cpy_r_time_i, NULL);
    if (unlikely(cpy_r_r106 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 411, CPyStatic_globals);
        goto CPyL747;
    } else
        goto CPyL748;
CPyL56: ;
    cpy_r_r107 = CPyStatics[62]; /* 'extend' */
    cpy_r_r108 = CPyObject_CallMethodObjArgs(cpy_r_points, cpy_r_r107, cpy_r_point_i, NULL);
    CPy_DECREF(cpy_r_point_i);
    if (unlikely(cpy_r_r108 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 412, CPyStatic_globals);
        goto CPyL749;
    } else
        goto CPyL750;
CPyL57: ;
    cpy_r_r109 = CPyStatics[62]; /* 'extend' */
    cpy_r_r110 = CPyObject_CallMethodObjArgs(cpy_r_photons, cpy_r_r109, cpy_r_photon_i, NULL);
    CPy_DECREF(cpy_r_photon_i);
    if (unlikely(cpy_r_r110 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 413, CPyStatic_globals);
        goto CPyL751;
    } else
        goto CPyL752;
CPyL58: ;
    cpy_r_r111 = CPyObject_Size(cpy_r_time_i);
    CPy_DECREF(cpy_r_time_i);
    if (unlikely(cpy_r_r111 == CPY_INT_TAG)) {
        CPy_AddTraceback("modTof.py", "run", 414, CPyStatic_globals);
        goto CPyL753;
    }
    cpy_r_r112 = CPyTagged_StealAsObject(cpy_r_r111);
    cpy_r_r113 = CPyModule_numpy;
    cpy_r_r114 = CPyStatics[63]; /* 'repeat' */
    cpy_r_r115 = CPyObject_GetAttr(cpy_r_r113, cpy_r_r114);
    if (unlikely(cpy_r_r115 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 414, CPyStatic_globals);
        goto CPyL754;
    }
    PyObject *cpy_r_r116[2] = {cpy_r_i, cpy_r_r112};
    cpy_r_r117 = (PyObject **)&cpy_r_r116;
    cpy_r_r118 = _PyObject_Vectorcall(cpy_r_r115, cpy_r_r117, 2, 0);
    CPy_DECREF(cpy_r_r115);
    if (unlikely(cpy_r_r118 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 414, CPyStatic_globals);
        goto CPyL754;
    }
    CPy_DECREF(cpy_r_r112);
    cpy_r_r119 = CPyStatics[62]; /* 'extend' */
    cpy_r_r120 = CPyObject_CallMethodObjArgs(cpy_r_particleID, cpy_r_r119, cpy_r_r118, NULL);
    CPy_DECREF(cpy_r_r118);
    if (unlikely(cpy_r_r120 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 414, CPyStatic_globals);
        goto CPyL753;
    } else
        goto CPyL755;
CPyL62: ;
    cpy_r_r121 = CPyStatics[247]; /* 1 */
    cpy_r_r122 = PyNumber_InPlaceAdd(cpy_r_i, cpy_r_r121);
    CPy_DECREF(cpy_r_i);
    if (unlikely(cpy_r_r122 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 415, CPyStatic_globals);
        goto CPyL738;
    }
    cpy_r_i = cpy_r_r122;
    CPy_DECREF(cpy_r_i);
    goto CPyL41;
CPyL64: ;
    cpy_r_r123 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r123)) {
        CPy_AddTraceback("modTof.py", "run", 409, CPyStatic_globals);
    } else
        goto CPyL73;
CPyL65: ;
    cpy_r_r124 = CPy_CatchError();
    cpy_r_r83 = 0;
    cpy_r_r125 = CPy_GetExcInfo();
    cpy_r_r126 = cpy_r_r125.f0;
    CPy_INCREF(cpy_r_r126);
    cpy_r_r127 = cpy_r_r125.f1;
    CPy_INCREF(cpy_r_r127);
    cpy_r_r128 = cpy_r_r125.f2;
    CPy_INCREF(cpy_r_r128);
    CPy_DecRef(cpy_r_r125.f0);
    CPy_DecRef(cpy_r_r125.f1);
    CPy_DecRef(cpy_r_r125.f2);
    PyObject *cpy_r_r129[4] = {cpy_r_r74, cpy_r_r126, cpy_r_r127, cpy_r_r128};
    cpy_r_r130 = (PyObject **)&cpy_r_r129;
    cpy_r_r131 = _PyObject_Vectorcall(cpy_r_r77, cpy_r_r130, 4, 0);
    if (unlikely(cpy_r_r131 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 407, CPyStatic_globals);
        goto CPyL756;
    }
    CPy_DecRef(cpy_r_r126);
    CPy_DecRef(cpy_r_r127);
    CPy_DecRef(cpy_r_r128);
    cpy_r_r132 = PyObject_IsTrue(cpy_r_r131);
    CPy_DecRef(cpy_r_r131);
    cpy_r_r133 = cpy_r_r132 >= 0;
    if (unlikely(!cpy_r_r133)) {
        CPy_AddTraceback("modTof.py", "run", 407, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r134 = cpy_r_r132;
    if (cpy_r_r134) goto CPyL70;
    CPy_Reraise();
    if (!0) {
        goto CPyL71;
    } else
        goto CPyL757;
CPyL69: ;
    CPy_Unreachable();
CPyL70: ;
    CPy_RestoreExcInfo(cpy_r_r124);
    CPy_DecRef(cpy_r_r124.f0);
    CPy_DecRef(cpy_r_r124.f1);
    CPy_DecRef(cpy_r_r124.f2);
    goto CPyL73;
CPyL71: ;
    CPy_RestoreExcInfo(cpy_r_r124);
    CPy_DecRef(cpy_r_r124.f0);
    CPy_DecRef(cpy_r_r124.f1);
    CPy_DecRef(cpy_r_r124.f2);
    cpy_r_r135 = CPy_KeepPropagating();
    if (!cpy_r_r135) {
        goto CPyL74;
    } else
        goto CPyL758;
CPyL72: ;
    CPy_Unreachable();
CPyL73: ;
    tuple_T3OOO __tmp59 = { NULL, NULL, NULL };
    cpy_r_r136 = __tmp59;
    cpy_r_r137 = cpy_r_r136;
    goto CPyL75;
CPyL74: ;
    cpy_r_r138 = CPy_CatchError();
    cpy_r_r137 = cpy_r_r138;
CPyL75: ;
    if (!cpy_r_r83) goto CPyL759;
    cpy_r_r139 = (PyObject *)&_Py_NoneStruct;
    PyObject *cpy_r_r140[4] = {cpy_r_r74, cpy_r_r139, cpy_r_r139, cpy_r_r139};
    cpy_r_r141 = (PyObject **)&cpy_r_r140;
    cpy_r_r142 = _PyObject_Vectorcall(cpy_r_r77, cpy_r_r141, 4, 0);
    CPy_DECREF(cpy_r_r77);
    if (unlikely(cpy_r_r142 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 407, CPyStatic_globals);
        goto CPyL760;
    } else
        goto CPyL761;
CPyL77: ;
    CPy_DECREF(cpy_r_r74);
CPyL78: ;
    if (cpy_r_r137.f0 == NULL) {
        goto CPyL85;
    } else
        goto CPyL762;
CPyL79: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL81;
    } else
        goto CPyL763;
CPyL80: ;
    CPy_Unreachable();
CPyL81: ;
    if (cpy_r_r137.f0 == NULL) goto CPyL83;
    CPy_RestoreExcInfo(cpy_r_r137);
    CPy_XDECREF(cpy_r_r137.f0);
    CPy_XDECREF(cpy_r_r137.f1);
    CPy_XDECREF(cpy_r_r137.f2);
CPyL83: ;
    cpy_r_r143 = CPy_KeepPropagating();
    if (!cpy_r_r143) goto CPyL720;
    CPy_Unreachable();
CPyL85: ;
    cpy_r_r144 = CPyStatic_globals;
    cpy_r_r145 = CPyStatics[54]; /* 'perf_counter' */
    cpy_r_r146 = CPyDict_GetItem(cpy_r_r144, cpy_r_r145);
    if (unlikely(cpy_r_r146 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 416, CPyStatic_globals);
        goto CPyL731;
    }
    cpy_r_r147 = _PyObject_Vectorcall(cpy_r_r146, 0, 0, 0);
    CPy_DECREF(cpy_r_r146);
    if (unlikely(cpy_r_r147 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 416, CPyStatic_globals);
        goto CPyL731;
    }
    cpy_r_logendparticle = cpy_r_r147;
    cpy_r_r148 = CPyModule_numpy;
    cpy_r_r149 = CPyStatics[29]; /* 'sum' */
    cpy_r_r150 = CPyObject_GetAttr(cpy_r_r148, cpy_r_r149);
    if (unlikely(cpy_r_r150 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 417, CPyStatic_globals);
        goto CPyL764;
    }
    PyObject *cpy_r_r151[1] = {cpy_r_photons};
    cpy_r_r152 = (PyObject **)&cpy_r_r151;
    cpy_r_r153 = _PyObject_Vectorcall(cpy_r_r150, cpy_r_r152, 1, 0);
    CPy_DECREF(cpy_r_r150);
    if (unlikely(cpy_r_r153 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 417, CPyStatic_globals);
        goto CPyL764;
    }
    cpy_r_N = cpy_r_r153;
    cpy_r_r154 = CPyStatics[64]; /* 'Photons generated' */
    cpy_r_r155 = CPyModule_builtins;
    cpy_r_r156 = CPyStatics[8]; /* 'print' */
    cpy_r_r157 = CPyObject_GetAttr(cpy_r_r155, cpy_r_r156);
    if (unlikely(cpy_r_r157 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 418, CPyStatic_globals);
        goto CPyL765;
    }
    PyObject *cpy_r_r158[2] = {cpy_r_r154, cpy_r_N};
    cpy_r_r159 = (PyObject **)&cpy_r_r158;
    cpy_r_r160 = _PyObject_Vectorcall(cpy_r_r157, cpy_r_r159, 2, 0);
    CPy_DECREF(cpy_r_r157);
    if (unlikely(cpy_r_r160 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 418, CPyStatic_globals);
        goto CPyL765;
    } else
        goto CPyL766;
CPyL91: ;
    CPy_DECREF(cpy_r_N);
    cpy_r_r161 = CPyModule_numpy;
    cpy_r_r162 = CPyStatics[65]; /* 'asarray' */
    cpy_r_r163 = CPyObject_GetAttr(cpy_r_r161, cpy_r_r162);
    if (unlikely(cpy_r_r163 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 419, CPyStatic_globals);
        goto CPyL764;
    }
    PyObject *cpy_r_r164[1] = {cpy_r_times};
    cpy_r_r165 = (PyObject **)&cpy_r_r164;
    cpy_r_r166 = _PyObject_Vectorcall(cpy_r_r163, cpy_r_r165, 1, 0);
    CPy_DECREF(cpy_r_r163);
    if (unlikely(cpy_r_r166 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 419, CPyStatic_globals);
        goto CPyL764;
    }
    CPy_DECREF(cpy_r_times);
    cpy_r_times = cpy_r_r166;
    cpy_r_r167 = CPyModule_numpy;
    cpy_r_r168 = CPyStatics[65]; /* 'asarray' */
    cpy_r_r169 = CPyObject_GetAttr(cpy_r_r167, cpy_r_r168);
    if (unlikely(cpy_r_r169 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 419, CPyStatic_globals);
        goto CPyL764;
    }
    PyObject *cpy_r_r170[1] = {cpy_r_points};
    cpy_r_r171 = (PyObject **)&cpy_r_r170;
    cpy_r_r172 = _PyObject_Vectorcall(cpy_r_r169, cpy_r_r171, 1, 0);
    CPy_DECREF(cpy_r_r169);
    if (unlikely(cpy_r_r172 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 419, CPyStatic_globals);
        goto CPyL764;
    }
    CPy_DECREF(cpy_r_points);
    cpy_r_points = cpy_r_r172;
    cpy_r_r173 = CPyModule_numpy;
    cpy_r_r174 = CPyStatics[65]; /* 'asarray' */
    cpy_r_r175 = CPyObject_GetAttr(cpy_r_r173, cpy_r_r174);
    if (unlikely(cpy_r_r175 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 419, CPyStatic_globals);
        goto CPyL764;
    }
    PyObject *cpy_r_r176[1] = {cpy_r_photons};
    cpy_r_r177 = (PyObject **)&cpy_r_r176;
    cpy_r_r178 = _PyObject_Vectorcall(cpy_r_r175, cpy_r_r177, 1, 0);
    CPy_DECREF(cpy_r_r175);
    if (unlikely(cpy_r_r178 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 419, CPyStatic_globals);
        goto CPyL764;
    }
    CPy_DECREF(cpy_r_photons);
    cpy_r_photons = cpy_r_r178;
    cpy_r_r179 = CPyModule_numpy;
    cpy_r_r180 = CPyStatics[65]; /* 'asarray' */
    cpy_r_r181 = CPyObject_GetAttr(cpy_r_r179, cpy_r_r180);
    if (unlikely(cpy_r_r181 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 419, CPyStatic_globals);
        goto CPyL764;
    }
    PyObject *cpy_r_r182[1] = {cpy_r_particleID};
    cpy_r_r183 = (PyObject **)&cpy_r_r182;
    cpy_r_r184 = _PyObject_Vectorcall(cpy_r_r181, cpy_r_r183, 1, 0);
    CPy_DECREF(cpy_r_r181);
    if (unlikely(cpy_r_r184 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 419, CPyStatic_globals);
        goto CPyL764;
    }
    CPy_DECREF(cpy_r_particleID);
    cpy_r_particleID = cpy_r_r184;
    cpy_r_r185 = PyList_New(0);
    if (unlikely(cpy_r_r185 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 427, CPyStatic_globals);
        goto CPyL764;
    }
    cpy_r_T1_input_times = cpy_r_r185;
    cpy_r_r186 = PyList_New(0);
    if (unlikely(cpy_r_r186 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 428, CPyStatic_globals);
        goto CPyL767;
    }
    cpy_r_T4_input_times = cpy_r_r186;
    cpy_r_r187 = PyList_New(0);
    if (unlikely(cpy_r_r187 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 430, CPyStatic_globals);
        goto CPyL768;
    }
    if (((modTof___SimulationObject *)cpy_r_self)->_T1_prop_dist != NULL) {
        CPy_DECREF(((modTof___SimulationObject *)cpy_r_self)->_T1_prop_dist);
    }
    ((modTof___SimulationObject *)cpy_r_self)->_T1_prop_dist = cpy_r_r187;
    cpy_r_r188 = 1;
    if (unlikely(!cpy_r_r188)) {
        CPy_AddTraceback("modTof.py", "run", 430, CPyStatic_globals);
        goto CPyL768;
    }
    cpy_r_r189 = PyList_New(0);
    if (unlikely(cpy_r_r189 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 431, CPyStatic_globals);
        goto CPyL768;
    }
    if (((modTof___SimulationObject *)cpy_r_self)->_T4_prop_dist != NULL) {
        CPy_DECREF(((modTof___SimulationObject *)cpy_r_self)->_T4_prop_dist);
    }
    ((modTof___SimulationObject *)cpy_r_self)->_T4_prop_dist = cpy_r_r189;
    cpy_r_r190 = 1;
    if (unlikely(!cpy_r_r190)) {
        CPy_AddTraceback("modTof.py", "run", 431, CPyStatic_globals);
        goto CPyL768;
    }
    cpy_r_r191 = PyList_New(0);
    if (unlikely(cpy_r_r191 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 432, CPyStatic_globals);
        goto CPyL768;
    }
    if (((modTof___SimulationObject *)cpy_r_self)->_T1_endpoint_dist != NULL) {
        CPy_DECREF(((modTof___SimulationObject *)cpy_r_self)->_T1_endpoint_dist);
    }
    ((modTof___SimulationObject *)cpy_r_self)->_T1_endpoint_dist = cpy_r_r191;
    cpy_r_r192 = 1;
    if (unlikely(!cpy_r_r192)) {
        CPy_AddTraceback("modTof.py", "run", 432, CPyStatic_globals);
        goto CPyL768;
    }
    cpy_r_r193 = PyList_New(0);
    if (unlikely(cpy_r_r193 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 433, CPyStatic_globals);
        goto CPyL768;
    }
    if (((modTof___SimulationObject *)cpy_r_self)->_T4_endpoint_dist != NULL) {
        CPy_DECREF(((modTof___SimulationObject *)cpy_r_self)->_T4_endpoint_dist);
    }
    ((modTof___SimulationObject *)cpy_r_self)->_T4_endpoint_dist = cpy_r_r193;
    cpy_r_r194 = 1;
    if (unlikely(!cpy_r_r194)) {
        CPy_AddTraceback("modTof.py", "run", 433, CPyStatic_globals);
        goto CPyL768;
    }
    cpy_r_r195 = PyList_New(0);
    if (unlikely(cpy_r_r195 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 434, CPyStatic_globals);
        goto CPyL768;
    }
    if (((modTof___SimulationObject *)cpy_r_self)->_T1_prop_times != NULL) {
        CPy_DECREF(((modTof___SimulationObject *)cpy_r_self)->_T1_prop_times);
    }
    ((modTof___SimulationObject *)cpy_r_self)->_T1_prop_times = cpy_r_r195;
    cpy_r_r196 = 1;
    if (unlikely(!cpy_r_r196)) {
        CPy_AddTraceback("modTof.py", "run", 434, CPyStatic_globals);
        goto CPyL768;
    }
    cpy_r_r197 = PyList_New(0);
    if (unlikely(cpy_r_r197 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 435, CPyStatic_globals);
        goto CPyL768;
    }
    if (((modTof___SimulationObject *)cpy_r_self)->_T4_prop_times != NULL) {
        CPy_DECREF(((modTof___SimulationObject *)cpy_r_self)->_T4_prop_times);
    }
    ((modTof___SimulationObject *)cpy_r_self)->_T4_prop_times = cpy_r_r197;
    cpy_r_r198 = 1;
    if (unlikely(!cpy_r_r198)) {
        CPy_AddTraceback("modTof.py", "run", 435, CPyStatic_globals);
        goto CPyL768;
    }
    cpy_r_r199 = PyList_New(0);
    if (unlikely(cpy_r_r199 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 436, CPyStatic_globals);
        goto CPyL768;
    }
    if (((modTof___SimulationObject *)cpy_r_self)->_T1_interactions != NULL) {
        CPy_DECREF(((modTof___SimulationObject *)cpy_r_self)->_T1_interactions);
    }
    ((modTof___SimulationObject *)cpy_r_self)->_T1_interactions = cpy_r_r199;
    cpy_r_r200 = 1;
    if (unlikely(!cpy_r_r200)) {
        CPy_AddTraceback("modTof.py", "run", 436, CPyStatic_globals);
        goto CPyL768;
    }
    cpy_r_r201 = PyList_New(0);
    if (unlikely(cpy_r_r201 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 437, CPyStatic_globals);
        goto CPyL768;
    }
    if (((modTof___SimulationObject *)cpy_r_self)->_T4_interactions != NULL) {
        CPy_DECREF(((modTof___SimulationObject *)cpy_r_self)->_T4_interactions);
    }
    ((modTof___SimulationObject *)cpy_r_self)->_T4_interactions = cpy_r_r201;
    cpy_r_r202 = 1;
    if (unlikely(!cpy_r_r202)) {
        CPy_AddTraceback("modTof.py", "run", 437, CPyStatic_globals);
        goto CPyL768;
    }
    cpy_r_r203 = PyList_New(0);
    if (unlikely(cpy_r_r203 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 438, CPyStatic_globals);
        goto CPyL768;
    }
    if (((modTof___SimulationObject *)cpy_r_self)->_T1_part_ids != NULL) {
        CPy_DECREF(((modTof___SimulationObject *)cpy_r_self)->_T1_part_ids);
    }
    ((modTof___SimulationObject *)cpy_r_self)->_T1_part_ids = cpy_r_r203;
    cpy_r_r204 = 1;
    if (unlikely(!cpy_r_r204)) {
        CPy_AddTraceback("modTof.py", "run", 438, CPyStatic_globals);
        goto CPyL768;
    }
    cpy_r_r205 = PyList_New(0);
    if (unlikely(cpy_r_r205 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 439, CPyStatic_globals);
        goto CPyL768;
    }
    if (((modTof___SimulationObject *)cpy_r_self)->_T4_part_ids != NULL) {
        CPy_DECREF(((modTof___SimulationObject *)cpy_r_self)->_T4_part_ids);
    }
    ((modTof___SimulationObject *)cpy_r_self)->_T4_part_ids = cpy_r_r205;
    cpy_r_r206 = 1;
    if (unlikely(!cpy_r_r206)) {
        CPy_AddTraceback("modTof.py", "run", 439, CPyStatic_globals);
        goto CPyL768;
    }
    cpy_r_r207 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r208 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r209 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r210 = PySlice_New(cpy_r_r207, cpy_r_r208, cpy_r_r209);
    if (unlikely(cpy_r_r210 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 440, CPyStatic_globals);
        goto CPyL768;
    }
    cpy_r_r211 = PyObject_GetItem(cpy_r_points, cpy_r_r210);
    CPy_DECREF(cpy_r_r210);
    if (unlikely(cpy_r_r211 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 440, CPyStatic_globals);
        goto CPyL768;
    }
    cpy_r_r212 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r213 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r214 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r215 = PySlice_New(cpy_r_r212, cpy_r_r213, cpy_r_r214);
    if (unlikely(cpy_r_r215 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", -1, CPyStatic_globals);
        goto CPyL769;
    }
    cpy_r_r216 = CPyStatics[257]; /* 2 */
    cpy_r_r217.f0 = cpy_r_r215;
    cpy_r_r217.f1 = cpy_r_r216;
    CPy_INCREF(cpy_r_r217.f0);
    CPy_INCREF(cpy_r_r217.f1);
    CPy_DECREF(cpy_r_r215);
    cpy_r_r218 = PyTuple_New(2);
    if (unlikely(cpy_r_r218 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp60 = cpy_r_r217.f0;
    PyTuple_SET_ITEM(cpy_r_r218, 0, __tmp60);
    PyObject *__tmp61 = cpy_r_r217.f1;
    PyTuple_SET_ITEM(cpy_r_r218, 1, __tmp61);
    cpy_r_r219 = PyObject_GetItem(cpy_r_points, cpy_r_r218);
    CPy_DECREF(cpy_r_r218);
    if (unlikely(cpy_r_r219 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 440, CPyStatic_globals);
        goto CPyL769;
    }
    cpy_r_r220 = ((modTof___SimulationObject *)cpy_r_self)->_T1z;
    CPy_INCREF(cpy_r_r220);
    cpy_r_r221 = PyObject_RichCompare(cpy_r_r219, cpy_r_r220, 5);
    CPy_DECREF(cpy_r_r219);
    CPy_DECREF(cpy_r_r220);
    if (unlikely(cpy_r_r221 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 440, CPyStatic_globals);
        goto CPyL769;
    }
    cpy_r_r222 = PyObject_GetItem(cpy_r_r211, cpy_r_r221);
    CPy_DECREF(cpy_r_r211);
    CPy_DECREF(cpy_r_r221);
    if (unlikely(cpy_r_r222 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 440, CPyStatic_globals);
        goto CPyL768;
    }
    cpy_r_T1points = cpy_r_r222;
    cpy_r_r223 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r224 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r225 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r226 = PySlice_New(cpy_r_r223, cpy_r_r224, cpy_r_r225);
    if (unlikely(cpy_r_r226 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 441, CPyStatic_globals);
        goto CPyL770;
    }
    cpy_r_r227 = PyObject_GetItem(cpy_r_times, cpy_r_r226);
    CPy_DECREF(cpy_r_r226);
    if (unlikely(cpy_r_r227 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 441, CPyStatic_globals);
        goto CPyL770;
    }
    cpy_r_r228 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r229 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r230 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r231 = PySlice_New(cpy_r_r228, cpy_r_r229, cpy_r_r230);
    if (unlikely(cpy_r_r231 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", -1, CPyStatic_globals);
        goto CPyL771;
    }
    cpy_r_r232 = CPyStatics[257]; /* 2 */
    cpy_r_r233.f0 = cpy_r_r231;
    cpy_r_r233.f1 = cpy_r_r232;
    CPy_INCREF(cpy_r_r233.f0);
    CPy_INCREF(cpy_r_r233.f1);
    CPy_DECREF(cpy_r_r231);
    cpy_r_r234 = PyTuple_New(2);
    if (unlikely(cpy_r_r234 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp62 = cpy_r_r233.f0;
    PyTuple_SET_ITEM(cpy_r_r234, 0, __tmp62);
    PyObject *__tmp63 = cpy_r_r233.f1;
    PyTuple_SET_ITEM(cpy_r_r234, 1, __tmp63);
    cpy_r_r235 = PyObject_GetItem(cpy_r_points, cpy_r_r234);
    CPy_DECREF(cpy_r_r234);
    if (unlikely(cpy_r_r235 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 441, CPyStatic_globals);
        goto CPyL771;
    }
    cpy_r_r236 = ((modTof___SimulationObject *)cpy_r_self)->_T1z;
    CPy_INCREF(cpy_r_r236);
    cpy_r_r237 = PyObject_RichCompare(cpy_r_r235, cpy_r_r236, 5);
    CPy_DECREF(cpy_r_r235);
    CPy_DECREF(cpy_r_r236);
    if (unlikely(cpy_r_r237 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 441, CPyStatic_globals);
        goto CPyL771;
    }
    cpy_r_r238 = PyObject_GetItem(cpy_r_r227, cpy_r_r237);
    CPy_DECREF(cpy_r_r227);
    CPy_DECREF(cpy_r_r237);
    if (unlikely(cpy_r_r238 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 441, CPyStatic_globals);
        goto CPyL770;
    }
    cpy_r_T1times = cpy_r_r238;
    cpy_r_r239 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r240 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r241 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r242 = PySlice_New(cpy_r_r239, cpy_r_r240, cpy_r_r241);
    if (unlikely(cpy_r_r242 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 442, CPyStatic_globals);
        goto CPyL772;
    }
    cpy_r_r243 = PyObject_GetItem(cpy_r_photons, cpy_r_r242);
    CPy_DECREF(cpy_r_r242);
    if (unlikely(cpy_r_r243 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 442, CPyStatic_globals);
        goto CPyL772;
    }
    cpy_r_r244 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r245 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r246 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r247 = PySlice_New(cpy_r_r244, cpy_r_r245, cpy_r_r246);
    if (unlikely(cpy_r_r247 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", -1, CPyStatic_globals);
        goto CPyL773;
    }
    cpy_r_r248 = CPyStatics[257]; /* 2 */
    cpy_r_r249.f0 = cpy_r_r247;
    cpy_r_r249.f1 = cpy_r_r248;
    CPy_INCREF(cpy_r_r249.f0);
    CPy_INCREF(cpy_r_r249.f1);
    CPy_DECREF(cpy_r_r247);
    cpy_r_r250 = PyTuple_New(2);
    if (unlikely(cpy_r_r250 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp64 = cpy_r_r249.f0;
    PyTuple_SET_ITEM(cpy_r_r250, 0, __tmp64);
    PyObject *__tmp65 = cpy_r_r249.f1;
    PyTuple_SET_ITEM(cpy_r_r250, 1, __tmp65);
    cpy_r_r251 = PyObject_GetItem(cpy_r_points, cpy_r_r250);
    CPy_DECREF(cpy_r_r250);
    if (unlikely(cpy_r_r251 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 442, CPyStatic_globals);
        goto CPyL773;
    }
    cpy_r_r252 = ((modTof___SimulationObject *)cpy_r_self)->_T1z;
    CPy_INCREF(cpy_r_r252);
    cpy_r_r253 = PyObject_RichCompare(cpy_r_r251, cpy_r_r252, 5);
    CPy_DECREF(cpy_r_r251);
    CPy_DECREF(cpy_r_r252);
    if (unlikely(cpy_r_r253 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 442, CPyStatic_globals);
        goto CPyL773;
    }
    cpy_r_r254 = PyObject_GetItem(cpy_r_r243, cpy_r_r253);
    CPy_DECREF(cpy_r_r243);
    CPy_DECREF(cpy_r_r253);
    if (unlikely(cpy_r_r254 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 442, CPyStatic_globals);
        goto CPyL772;
    }
    cpy_r_T1photons = cpy_r_r254;
    cpy_r_r255 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r256 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r257 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r258 = PySlice_New(cpy_r_r255, cpy_r_r256, cpy_r_r257);
    if (unlikely(cpy_r_r258 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 443, CPyStatic_globals);
        goto CPyL774;
    }
    cpy_r_r259 = PyObject_GetItem(cpy_r_particleID, cpy_r_r258);
    CPy_DECREF(cpy_r_r258);
    if (unlikely(cpy_r_r259 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 443, CPyStatic_globals);
        goto CPyL774;
    }
    cpy_r_r260 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r261 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r262 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r263 = PySlice_New(cpy_r_r260, cpy_r_r261, cpy_r_r262);
    if (unlikely(cpy_r_r263 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", -1, CPyStatic_globals);
        goto CPyL775;
    }
    cpy_r_r264 = CPyStatics[257]; /* 2 */
    cpy_r_r265.f0 = cpy_r_r263;
    cpy_r_r265.f1 = cpy_r_r264;
    CPy_INCREF(cpy_r_r265.f0);
    CPy_INCREF(cpy_r_r265.f1);
    CPy_DECREF(cpy_r_r263);
    cpy_r_r266 = PyTuple_New(2);
    if (unlikely(cpy_r_r266 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp66 = cpy_r_r265.f0;
    PyTuple_SET_ITEM(cpy_r_r266, 0, __tmp66);
    PyObject *__tmp67 = cpy_r_r265.f1;
    PyTuple_SET_ITEM(cpy_r_r266, 1, __tmp67);
    cpy_r_r267 = PyObject_GetItem(cpy_r_points, cpy_r_r266);
    CPy_DECREF(cpy_r_r266);
    if (unlikely(cpy_r_r267 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 443, CPyStatic_globals);
        goto CPyL775;
    }
    cpy_r_r268 = ((modTof___SimulationObject *)cpy_r_self)->_T1z;
    CPy_INCREF(cpy_r_r268);
    cpy_r_r269 = PyObject_RichCompare(cpy_r_r267, cpy_r_r268, 5);
    CPy_DECREF(cpy_r_r267);
    CPy_DECREF(cpy_r_r268);
    if (unlikely(cpy_r_r269 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 443, CPyStatic_globals);
        goto CPyL775;
    }
    cpy_r_r270 = PyObject_GetItem(cpy_r_r259, cpy_r_r269);
    CPy_DECREF(cpy_r_r259);
    CPy_DECREF(cpy_r_r269);
    if (unlikely(cpy_r_r270 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 443, CPyStatic_globals);
        goto CPyL774;
    }
    cpy_r_T1part_ids = cpy_r_r270;
    cpy_r_r271 = (PyObject *)&PyLong_Type;
    cpy_r_r272 = CPyStatics[66]; /* 'astype' */
    cpy_r_r273 = CPyObject_CallMethodObjArgs(cpy_r_T1photons, cpy_r_r272, cpy_r_r271, NULL);
    if (unlikely(cpy_r_r273 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 444, CPyStatic_globals);
        goto CPyL776;
    }
    cpy_r_r274 = CPyModule_numpy;
    cpy_r_r275 = CPyStatics[63]; /* 'repeat' */
    cpy_r_r276 = CPyObject_GetAttr(cpy_r_r274, cpy_r_r275);
    if (unlikely(cpy_r_r276 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 444, CPyStatic_globals);
        goto CPyL777;
    }
    cpy_r_r277 = CPyStatics[244]; /* 0 */
    PyObject *cpy_r_r278[3] = {cpy_r_T1part_ids, cpy_r_r273, cpy_r_r277};
    cpy_r_r279 = (PyObject **)&cpy_r_r278;
    cpy_r_r280 = CPyStatics[266]; /* ('axis',) */
    cpy_r_r281 = _PyObject_Vectorcall(cpy_r_r276, cpy_r_r279, 2, cpy_r_r280);
    CPy_DECREF(cpy_r_r276);
    if (unlikely(cpy_r_r281 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 444, CPyStatic_globals);
        goto CPyL777;
    }
    CPy_DECREF(cpy_r_T1part_ids);
    CPy_DECREF(cpy_r_r273);
    cpy_r_T1part_ids = cpy_r_r281;
    cpy_r_r282 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r283 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r284 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r285 = PySlice_New(cpy_r_r282, cpy_r_r283, cpy_r_r284);
    if (unlikely(cpy_r_r285 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 445, CPyStatic_globals);
        goto CPyL776;
    }
    cpy_r_r286 = PyObject_GetItem(cpy_r_points, cpy_r_r285);
    CPy_DECREF(cpy_r_r285);
    if (unlikely(cpy_r_r286 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 445, CPyStatic_globals);
        goto CPyL776;
    }
    cpy_r_r287 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r288 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r289 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r290 = PySlice_New(cpy_r_r287, cpy_r_r288, cpy_r_r289);
    if (unlikely(cpy_r_r290 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", -1, CPyStatic_globals);
        goto CPyL778;
    }
    cpy_r_r291 = CPyStatics[257]; /* 2 */
    cpy_r_r292.f0 = cpy_r_r290;
    cpy_r_r292.f1 = cpy_r_r291;
    CPy_INCREF(cpy_r_r292.f0);
    CPy_INCREF(cpy_r_r292.f1);
    CPy_DECREF(cpy_r_r290);
    cpy_r_r293 = PyTuple_New(2);
    if (unlikely(cpy_r_r293 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp68 = cpy_r_r292.f0;
    PyTuple_SET_ITEM(cpy_r_r293, 0, __tmp68);
    PyObject *__tmp69 = cpy_r_r292.f1;
    PyTuple_SET_ITEM(cpy_r_r293, 1, __tmp69);
    cpy_r_r294 = PyObject_GetItem(cpy_r_points, cpy_r_r293);
    CPy_DECREF(cpy_r_r293);
    if (unlikely(cpy_r_r294 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 445, CPyStatic_globals);
        goto CPyL778;
    }
    cpy_r_r295 = ((modTof___SimulationObject *)cpy_r_self)->_T1z;
    CPy_INCREF(cpy_r_r295);
    cpy_r_r296 = PyObject_RichCompare(cpy_r_r294, cpy_r_r295, 0);
    CPy_DECREF(cpy_r_r294);
    CPy_DECREF(cpy_r_r295);
    if (unlikely(cpy_r_r296 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 445, CPyStatic_globals);
        goto CPyL778;
    }
    cpy_r_r297 = PyObject_GetItem(cpy_r_r286, cpy_r_r296);
    CPy_DECREF(cpy_r_r286);
    CPy_DECREF(cpy_r_r296);
    if (unlikely(cpy_r_r297 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 445, CPyStatic_globals);
        goto CPyL776;
    }
    cpy_r_T4points = cpy_r_r297;
    cpy_r_r298 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r299 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r300 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r301 = PySlice_New(cpy_r_r298, cpy_r_r299, cpy_r_r300);
    if (unlikely(cpy_r_r301 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 446, CPyStatic_globals);
        goto CPyL779;
    }
    cpy_r_r302 = PyObject_GetItem(cpy_r_times, cpy_r_r301);
    CPy_DECREF(cpy_r_times);
    CPy_DECREF(cpy_r_r301);
    if (unlikely(cpy_r_r302 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 446, CPyStatic_globals);
        goto CPyL780;
    }
    cpy_r_r303 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r304 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r305 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r306 = PySlice_New(cpy_r_r303, cpy_r_r304, cpy_r_r305);
    if (unlikely(cpy_r_r306 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", -1, CPyStatic_globals);
        goto CPyL781;
    }
    cpy_r_r307 = CPyStatics[257]; /* 2 */
    cpy_r_r308.f0 = cpy_r_r306;
    cpy_r_r308.f1 = cpy_r_r307;
    CPy_INCREF(cpy_r_r308.f0);
    CPy_INCREF(cpy_r_r308.f1);
    CPy_DECREF(cpy_r_r306);
    cpy_r_r309 = PyTuple_New(2);
    if (unlikely(cpy_r_r309 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp70 = cpy_r_r308.f0;
    PyTuple_SET_ITEM(cpy_r_r309, 0, __tmp70);
    PyObject *__tmp71 = cpy_r_r308.f1;
    PyTuple_SET_ITEM(cpy_r_r309, 1, __tmp71);
    cpy_r_r310 = PyObject_GetItem(cpy_r_points, cpy_r_r309);
    CPy_DECREF(cpy_r_r309);
    if (unlikely(cpy_r_r310 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 446, CPyStatic_globals);
        goto CPyL781;
    }
    cpy_r_r311 = ((modTof___SimulationObject *)cpy_r_self)->_T1z;
    CPy_INCREF(cpy_r_r311);
    cpy_r_r312 = PyObject_RichCompare(cpy_r_r310, cpy_r_r311, 0);
    CPy_DECREF(cpy_r_r310);
    CPy_DECREF(cpy_r_r311);
    if (unlikely(cpy_r_r312 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 446, CPyStatic_globals);
        goto CPyL781;
    }
    cpy_r_r313 = PyObject_GetItem(cpy_r_r302, cpy_r_r312);
    CPy_DECREF(cpy_r_r302);
    CPy_DECREF(cpy_r_r312);
    if (unlikely(cpy_r_r313 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 446, CPyStatic_globals);
        goto CPyL780;
    }
    cpy_r_T4times = cpy_r_r313;
    cpy_r_r314 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r315 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r316 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r317 = PySlice_New(cpy_r_r314, cpy_r_r315, cpy_r_r316);
    if (unlikely(cpy_r_r317 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 447, CPyStatic_globals);
        goto CPyL782;
    }
    cpy_r_r318 = PyObject_GetItem(cpy_r_photons, cpy_r_r317);
    CPy_DECREF(cpy_r_photons);
    CPy_DECREF(cpy_r_r317);
    if (unlikely(cpy_r_r318 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 447, CPyStatic_globals);
        goto CPyL783;
    }
    cpy_r_r319 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r320 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r321 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r322 = PySlice_New(cpy_r_r319, cpy_r_r320, cpy_r_r321);
    if (unlikely(cpy_r_r322 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", -1, CPyStatic_globals);
        goto CPyL784;
    }
    cpy_r_r323 = CPyStatics[257]; /* 2 */
    cpy_r_r324.f0 = cpy_r_r322;
    cpy_r_r324.f1 = cpy_r_r323;
    CPy_INCREF(cpy_r_r324.f0);
    CPy_INCREF(cpy_r_r324.f1);
    CPy_DECREF(cpy_r_r322);
    cpy_r_r325 = PyTuple_New(2);
    if (unlikely(cpy_r_r325 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp72 = cpy_r_r324.f0;
    PyTuple_SET_ITEM(cpy_r_r325, 0, __tmp72);
    PyObject *__tmp73 = cpy_r_r324.f1;
    PyTuple_SET_ITEM(cpy_r_r325, 1, __tmp73);
    cpy_r_r326 = PyObject_GetItem(cpy_r_points, cpy_r_r325);
    CPy_DECREF(cpy_r_r325);
    if (unlikely(cpy_r_r326 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 447, CPyStatic_globals);
        goto CPyL784;
    }
    cpy_r_r327 = ((modTof___SimulationObject *)cpy_r_self)->_T1z;
    CPy_INCREF(cpy_r_r327);
    cpy_r_r328 = PyObject_RichCompare(cpy_r_r326, cpy_r_r327, 0);
    CPy_DECREF(cpy_r_r326);
    CPy_DECREF(cpy_r_r327);
    if (unlikely(cpy_r_r328 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 447, CPyStatic_globals);
        goto CPyL784;
    }
    cpy_r_r329 = PyObject_GetItem(cpy_r_r318, cpy_r_r328);
    CPy_DECREF(cpy_r_r318);
    CPy_DECREF(cpy_r_r328);
    if (unlikely(cpy_r_r329 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 447, CPyStatic_globals);
        goto CPyL783;
    }
    cpy_r_T4photons = cpy_r_r329;
    cpy_r_r330 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r331 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r332 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r333 = PySlice_New(cpy_r_r330, cpy_r_r331, cpy_r_r332);
    if (unlikely(cpy_r_r333 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 448, CPyStatic_globals);
        goto CPyL785;
    }
    cpy_r_r334 = PyObject_GetItem(cpy_r_particleID, cpy_r_r333);
    CPy_DECREF(cpy_r_particleID);
    CPy_DECREF(cpy_r_r333);
    if (unlikely(cpy_r_r334 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 448, CPyStatic_globals);
        goto CPyL786;
    }
    cpy_r_r335 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r336 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r337 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r338 = PySlice_New(cpy_r_r335, cpy_r_r336, cpy_r_r337);
    if (unlikely(cpy_r_r338 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", -1, CPyStatic_globals);
        goto CPyL787;
    }
    cpy_r_r339 = CPyStatics[257]; /* 2 */
    cpy_r_r340.f0 = cpy_r_r338;
    cpy_r_r340.f1 = cpy_r_r339;
    CPy_INCREF(cpy_r_r340.f0);
    CPy_INCREF(cpy_r_r340.f1);
    CPy_DECREF(cpy_r_r338);
    cpy_r_r341 = PyTuple_New(2);
    if (unlikely(cpy_r_r341 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp74 = cpy_r_r340.f0;
    PyTuple_SET_ITEM(cpy_r_r341, 0, __tmp74);
    PyObject *__tmp75 = cpy_r_r340.f1;
    PyTuple_SET_ITEM(cpy_r_r341, 1, __tmp75);
    cpy_r_r342 = PyObject_GetItem(cpy_r_points, cpy_r_r341);
    CPy_DECREF(cpy_r_points);
    CPy_DECREF(cpy_r_r341);
    if (unlikely(cpy_r_r342 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 448, CPyStatic_globals);
        goto CPyL788;
    }
    cpy_r_r343 = ((modTof___SimulationObject *)cpy_r_self)->_T1z;
    CPy_INCREF(cpy_r_r343);
    cpy_r_r344 = PyObject_RichCompare(cpy_r_r342, cpy_r_r343, 0);
    CPy_DECREF(cpy_r_r342);
    CPy_DECREF(cpy_r_r343);
    if (unlikely(cpy_r_r344 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 448, CPyStatic_globals);
        goto CPyL788;
    }
    cpy_r_r345 = PyObject_GetItem(cpy_r_r334, cpy_r_r344);
    CPy_DECREF(cpy_r_r334);
    CPy_DECREF(cpy_r_r344);
    if (unlikely(cpy_r_r345 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 448, CPyStatic_globals);
        goto CPyL789;
    }
    cpy_r_T4part_ids = cpy_r_r345;
    cpy_r_r346 = (PyObject *)&PyLong_Type;
    cpy_r_r347 = CPyStatics[66]; /* 'astype' */
    cpy_r_r348 = CPyObject_CallMethodObjArgs(cpy_r_T4photons, cpy_r_r347, cpy_r_r346, NULL);
    if (unlikely(cpy_r_r348 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 449, CPyStatic_globals);
        goto CPyL790;
    }
    cpy_r_r349 = CPyModule_numpy;
    cpy_r_r350 = CPyStatics[63]; /* 'repeat' */
    cpy_r_r351 = CPyObject_GetAttr(cpy_r_r349, cpy_r_r350);
    if (unlikely(cpy_r_r351 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 449, CPyStatic_globals);
        goto CPyL791;
    }
    cpy_r_r352 = CPyStatics[244]; /* 0 */
    PyObject *cpy_r_r353[3] = {cpy_r_T4part_ids, cpy_r_r348, cpy_r_r352};
    cpy_r_r354 = (PyObject **)&cpy_r_r353;
    cpy_r_r355 = CPyStatics[266]; /* ('axis',) */
    cpy_r_r356 = _PyObject_Vectorcall(cpy_r_r351, cpy_r_r354, 2, cpy_r_r355);
    CPy_DECREF(cpy_r_r351);
    if (unlikely(cpy_r_r356 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 449, CPyStatic_globals);
        goto CPyL791;
    }
    CPy_DECREF(cpy_r_T4part_ids);
    CPy_DECREF(cpy_r_r348);
    cpy_r_T4part_ids = cpy_r_r356;
    cpy_r_r357 = CPyStatics[68]; /* 'Photons in T1: ' */
    cpy_r_r358 = CPyModule_numpy;
    cpy_r_r359 = CPyStatics[29]; /* 'sum' */
    cpy_r_r360 = CPyObject_GetAttr(cpy_r_r358, cpy_r_r359);
    if (unlikely(cpy_r_r360 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 450, CPyStatic_globals);
        goto CPyL790;
    }
    PyObject *cpy_r_r361[1] = {cpy_r_T1photons};
    cpy_r_r362 = (PyObject **)&cpy_r_r361;
    cpy_r_r363 = _PyObject_Vectorcall(cpy_r_r360, cpy_r_r362, 1, 0);
    CPy_DECREF(cpy_r_r360);
    if (unlikely(cpy_r_r363 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 450, CPyStatic_globals);
        goto CPyL790;
    }
    cpy_r_r364 = PyObject_Str(cpy_r_r363);
    CPy_DECREF(cpy_r_r363);
    if (unlikely(cpy_r_r364 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 450, CPyStatic_globals);
        goto CPyL790;
    }
    cpy_r_r365 = CPyStatics[69]; /* ' and Photons in T4: ' */
    cpy_r_r366 = CPyModule_numpy;
    cpy_r_r367 = CPyStatics[29]; /* 'sum' */
    cpy_r_r368 = CPyObject_GetAttr(cpy_r_r366, cpy_r_r367);
    if (unlikely(cpy_r_r368 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 450, CPyStatic_globals);
        goto CPyL792;
    }
    PyObject *cpy_r_r369[1] = {cpy_r_T4photons};
    cpy_r_r370 = (PyObject **)&cpy_r_r369;
    cpy_r_r371 = _PyObject_Vectorcall(cpy_r_r368, cpy_r_r370, 1, 0);
    CPy_DECREF(cpy_r_r368);
    if (unlikely(cpy_r_r371 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 450, CPyStatic_globals);
        goto CPyL792;
    }
    cpy_r_r372 = PyObject_Str(cpy_r_r371);
    CPy_DECREF(cpy_r_r371);
    if (unlikely(cpy_r_r372 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 450, CPyStatic_globals);
        goto CPyL792;
    }
    cpy_r_r373 = CPyStr_Build(4, cpy_r_r357, cpy_r_r364, cpy_r_r365, cpy_r_r372);
    CPy_DECREF(cpy_r_r364);
    CPy_DECREF(cpy_r_r372);
    if (unlikely(cpy_r_r373 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 450, CPyStatic_globals);
        goto CPyL790;
    }
    cpy_r_r374 = CPyModule_builtins;
    cpy_r_r375 = CPyStatics[8]; /* 'print' */
    cpy_r_r376 = CPyObject_GetAttr(cpy_r_r374, cpy_r_r375);
    if (unlikely(cpy_r_r376 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 450, CPyStatic_globals);
        goto CPyL793;
    }
    PyObject *cpy_r_r377[1] = {cpy_r_r373};
    cpy_r_r378 = (PyObject **)&cpy_r_r377;
    cpy_r_r379 = _PyObject_Vectorcall(cpy_r_r376, cpy_r_r378, 1, 0);
    CPy_DECREF(cpy_r_r376);
    if (unlikely(cpy_r_r379 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 450, CPyStatic_globals);
        goto CPyL793;
    } else
        goto CPyL794;
CPyL184: ;
    CPy_DECREF(cpy_r_r373);
    cpy_r_r380 = NULL;
    cpy_r_times = cpy_r_r380;
    CPy_XDECREF(cpy_r_times);
    cpy_r_r381 = NULL;
    cpy_r_points = cpy_r_r381;
    CPy_XDECREF(cpy_r_points);
    cpy_r_r382 = NULL;
    cpy_r_photons = cpy_r_r382;
    CPy_XDECREF(cpy_r_photons);
    cpy_r_r383 = CPyModule_gc;
    cpy_r_r384 = CPyStatics[70]; /* 'collect' */
    cpy_r_r385 = CPyObject_GetAttr(cpy_r_r383, cpy_r_r384);
    if (unlikely(cpy_r_r385 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 452, CPyStatic_globals);
        goto CPyL790;
    }
    cpy_r_r386 = _PyObject_Vectorcall(cpy_r_r385, 0, 0, 0);
    CPy_DECREF(cpy_r_r385);
    if (unlikely(cpy_r_r386 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 452, CPyStatic_globals);
        goto CPyL790;
    } else
        goto CPyL795;
CPyL186: ;
    cpy_r_r387 = CPyStatic_globals;
    cpy_r_r388 = CPyStatics[54]; /* 'perf_counter' */
    cpy_r_r389 = CPyDict_GetItem(cpy_r_r387, cpy_r_r388);
    if (unlikely(cpy_r_r389 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 453, CPyStatic_globals);
        goto CPyL790;
    }
    cpy_r_r390 = _PyObject_Vectorcall(cpy_r_r389, 0, 0, 0);
    CPy_DECREF(cpy_r_r389);
    if (unlikely(cpy_r_r390 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 453, CPyStatic_globals);
        goto CPyL790;
    }
    cpy_r_logstartphoton = cpy_r_r390;
    cpy_r_r391 = CPyStatic_globals;
    cpy_r_r392 = CPyStatics[55]; /* 'cpu_count' */
    cpy_r_r393 = CPyDict_GetItem(cpy_r_r391, cpy_r_r392);
    if (unlikely(cpy_r_r393 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 456, CPyStatic_globals);
        goto CPyL796;
    }
    cpy_r_r394 = _PyObject_Vectorcall(cpy_r_r393, 0, 0, 0);
    CPy_DECREF(cpy_r_r393);
    if (unlikely(cpy_r_r394 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 456, CPyStatic_globals);
        goto CPyL796;
    }
    cpy_r_r395 = CPyStatic_globals;
    cpy_r_r396 = CPyStatics[56]; /* 'Pool' */
    cpy_r_r397 = CPyDict_GetItem(cpy_r_r395, cpy_r_r396);
    if (unlikely(cpy_r_r397 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 456, CPyStatic_globals);
        goto CPyL797;
    }
    PyObject *cpy_r_r398[1] = {cpy_r_r394};
    cpy_r_r399 = (PyObject **)&cpy_r_r398;
    cpy_r_r400 = CPyStatics[265]; /* ('processes',) */
    cpy_r_r401 = _PyObject_Vectorcall(cpy_r_r397, cpy_r_r399, 0, cpy_r_r400);
    CPy_DECREF(cpy_r_r397);
    if (unlikely(cpy_r_r401 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 456, CPyStatic_globals);
        goto CPyL797;
    }
    CPy_DECREF(cpy_r_r394);
    cpy_r_r402 = PyObject_Type(cpy_r_r401);
    cpy_r_r403 = CPyStatics[58]; /* '__exit__' */
    cpy_r_r404 = CPyObject_GetAttr(cpy_r_r402, cpy_r_r403);
    if (unlikely(cpy_r_r404 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 456, CPyStatic_globals);
        goto CPyL798;
    }
    cpy_r_r405 = CPyStatics[59]; /* '__enter__' */
    cpy_r_r406 = CPyObject_GetAttr(cpy_r_r402, cpy_r_r405);
    CPy_DECREF(cpy_r_r402);
    if (unlikely(cpy_r_r406 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 456, CPyStatic_globals);
        goto CPyL799;
    }
    PyObject *cpy_r_r407[1] = {cpy_r_r401};
    cpy_r_r408 = (PyObject **)&cpy_r_r407;
    cpy_r_r409 = _PyObject_Vectorcall(cpy_r_r406, cpy_r_r408, 1, 0);
    CPy_DECREF(cpy_r_r406);
    if (unlikely(cpy_r_r409 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 456, CPyStatic_globals);
        goto CPyL799;
    }
    cpy_r_r410 = 1;
    cpy_r_pool = cpy_r_r409;
    cpy_r_r411 = CPyStatics[71]; /* 'T1 Photon Propagation working...' */
    cpy_r_r412 = CPyModule_builtins;
    cpy_r_r413 = CPyStatics[8]; /* 'print' */
    cpy_r_r414 = CPyObject_GetAttr(cpy_r_r412, cpy_r_r413);
    if (unlikely(cpy_r_r414 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 457, CPyStatic_globals);
        goto CPyL800;
    }
    PyObject *cpy_r_r415[1] = {cpy_r_r411};
    cpy_r_r416 = (PyObject **)&cpy_r_r415;
    cpy_r_r417 = _PyObject_Vectorcall(cpy_r_r414, cpy_r_r416, 1, 0);
    CPy_DECREF(cpy_r_r414);
    if (unlikely(cpy_r_r417 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 457, CPyStatic_globals);
        goto CPyL800;
    } else
        goto CPyL801;
CPyL198: ;
    cpy_r_r418 = CPyStatics[72]; /* 'scint_taskT1' */
    cpy_r_r419 = CPyObject_GetAttr(cpy_r_self, cpy_r_r418);
    if (unlikely(cpy_r_r419 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 458, CPyStatic_globals);
        goto CPyL800;
    }
    cpy_r_r420 = CPyModule_numpy;
    cpy_r_r421 = CPyStatics[73]; /* 'c_' */
    cpy_r_r422 = CPyObject_GetAttr(cpy_r_r420, cpy_r_r421);
    if (unlikely(cpy_r_r422 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 458, CPyStatic_globals);
        goto CPyL802;
    }
    cpy_r_r423.f0 = cpy_r_T1points;
    cpy_r_r423.f1 = cpy_r_T1times;
    CPy_INCREF(cpy_r_r423.f0);
    CPy_INCREF(cpy_r_r423.f1);
    CPy_DECREF(cpy_r_T1points);
    CPy_DECREF(cpy_r_T1times);
    cpy_r_r424 = PyTuple_New(2);
    if (unlikely(cpy_r_r424 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp76 = cpy_r_r423.f0;
    PyTuple_SET_ITEM(cpy_r_r424, 0, __tmp76);
    PyObject *__tmp77 = cpy_r_r423.f1;
    PyTuple_SET_ITEM(cpy_r_r424, 1, __tmp77);
    cpy_r_r425 = PyObject_GetItem(cpy_r_r422, cpy_r_r424);
    CPy_DECREF(cpy_r_r422);
    CPy_DECREF(cpy_r_r424);
    if (unlikely(cpy_r_r425 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 458, CPyStatic_globals);
        goto CPyL803;
    }
    cpy_r_r426 = (PyObject *)&PyLong_Type;
    cpy_r_r427 = CPyStatics[66]; /* 'astype' */
    cpy_r_r428 = CPyObject_CallMethodObjArgs(cpy_r_T1photons, cpy_r_r427, cpy_r_r426, NULL);
    if (unlikely(cpy_r_r428 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 458, CPyStatic_globals);
        goto CPyL804;
    }
    cpy_r_r429 = CPyModule_numpy;
    cpy_r_r430 = CPyStatics[63]; /* 'repeat' */
    cpy_r_r431 = CPyObject_GetAttr(cpy_r_r429, cpy_r_r430);
    if (unlikely(cpy_r_r431 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 458, CPyStatic_globals);
        goto CPyL805;
    }
    cpy_r_r432 = CPyStatics[244]; /* 0 */
    PyObject *cpy_r_r433[3] = {cpy_r_r425, cpy_r_r428, cpy_r_r432};
    cpy_r_r434 = (PyObject **)&cpy_r_r433;
    cpy_r_r435 = CPyStatics[266]; /* ('axis',) */
    cpy_r_r436 = _PyObject_Vectorcall(cpy_r_r431, cpy_r_r434, 2, cpy_r_r435);
    CPy_DECREF(cpy_r_r431);
    if (unlikely(cpy_r_r436 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 458, CPyStatic_globals);
        goto CPyL805;
    }
    CPy_DECREF(cpy_r_r425);
    CPy_DECREF(cpy_r_r428);
    cpy_r_r437 = CPyStatics[74]; /* 'starmap' */
    cpy_r_r438 = CPyObject_CallMethodObjArgs(cpy_r_pool, cpy_r_r437, cpy_r_r419, cpy_r_r436, NULL);
    CPy_DECREF(cpy_r_r419);
    CPy_DECREF(cpy_r_r436);
    if (unlikely(cpy_r_r438 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 458, CPyStatic_globals);
        goto CPyL806;
    }
    cpy_r_T1res = cpy_r_r438;
    cpy_r_r439 = CPyStatics[75]; /* 'Done!' */
    cpy_r_r440 = CPyModule_builtins;
    cpy_r_r441 = CPyStatics[8]; /* 'print' */
    cpy_r_r442 = CPyObject_GetAttr(cpy_r_r440, cpy_r_r441);
    if (unlikely(cpy_r_r442 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 459, CPyStatic_globals);
        goto CPyL807;
    }
    PyObject *cpy_r_r443[1] = {cpy_r_r439};
    cpy_r_r444 = (PyObject **)&cpy_r_r443;
    cpy_r_r445 = _PyObject_Vectorcall(cpy_r_r442, cpy_r_r444, 1, 0);
    CPy_DECREF(cpy_r_r442);
    if (unlikely(cpy_r_r445 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 459, CPyStatic_globals);
        goto CPyL807;
    } else
        goto CPyL808;
CPyL207: ;
    cpy_r_r446 = CPyStatics[76]; /* 'T4 Photon Propagation working...' */
    cpy_r_r447 = CPyModule_builtins;
    cpy_r_r448 = CPyStatics[8]; /* 'print' */
    cpy_r_r449 = CPyObject_GetAttr(cpy_r_r447, cpy_r_r448);
    if (unlikely(cpy_r_r449 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 460, CPyStatic_globals);
        goto CPyL807;
    }
    PyObject *cpy_r_r450[1] = {cpy_r_r446};
    cpy_r_r451 = (PyObject **)&cpy_r_r450;
    cpy_r_r452 = _PyObject_Vectorcall(cpy_r_r449, cpy_r_r451, 1, 0);
    CPy_DECREF(cpy_r_r449);
    if (unlikely(cpy_r_r452 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 460, CPyStatic_globals);
        goto CPyL807;
    } else
        goto CPyL809;
CPyL209: ;
    cpy_r_r453 = CPyStatics[77]; /* 'scint_taskT4' */
    cpy_r_r454 = CPyObject_GetAttr(cpy_r_self, cpy_r_r453);
    if (unlikely(cpy_r_r454 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 461, CPyStatic_globals);
        goto CPyL807;
    }
    cpy_r_r455 = CPyModule_numpy;
    cpy_r_r456 = CPyStatics[73]; /* 'c_' */
    cpy_r_r457 = CPyObject_GetAttr(cpy_r_r455, cpy_r_r456);
    if (unlikely(cpy_r_r457 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 461, CPyStatic_globals);
        goto CPyL810;
    }
    cpy_r_r458.f0 = cpy_r_T4points;
    cpy_r_r458.f1 = cpy_r_T4times;
    CPy_INCREF(cpy_r_r458.f0);
    CPy_INCREF(cpy_r_r458.f1);
    CPy_DECREF(cpy_r_T4points);
    CPy_DECREF(cpy_r_T4times);
    cpy_r_r459 = PyTuple_New(2);
    if (unlikely(cpy_r_r459 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp78 = cpy_r_r458.f0;
    PyTuple_SET_ITEM(cpy_r_r459, 0, __tmp78);
    PyObject *__tmp79 = cpy_r_r458.f1;
    PyTuple_SET_ITEM(cpy_r_r459, 1, __tmp79);
    cpy_r_r460 = PyObject_GetItem(cpy_r_r457, cpy_r_r459);
    CPy_DECREF(cpy_r_r457);
    CPy_DECREF(cpy_r_r459);
    if (unlikely(cpy_r_r460 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 461, CPyStatic_globals);
        goto CPyL811;
    }
    cpy_r_r461 = (PyObject *)&PyLong_Type;
    cpy_r_r462 = CPyStatics[66]; /* 'astype' */
    cpy_r_r463 = CPyObject_CallMethodObjArgs(cpy_r_T4photons, cpy_r_r462, cpy_r_r461, NULL);
    if (unlikely(cpy_r_r463 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 461, CPyStatic_globals);
        goto CPyL812;
    }
    cpy_r_r464 = CPyModule_numpy;
    cpy_r_r465 = CPyStatics[63]; /* 'repeat' */
    cpy_r_r466 = CPyObject_GetAttr(cpy_r_r464, cpy_r_r465);
    if (unlikely(cpy_r_r466 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 461, CPyStatic_globals);
        goto CPyL813;
    }
    cpy_r_r467 = CPyStatics[244]; /* 0 */
    PyObject *cpy_r_r468[3] = {cpy_r_r460, cpy_r_r463, cpy_r_r467};
    cpy_r_r469 = (PyObject **)&cpy_r_r468;
    cpy_r_r470 = CPyStatics[266]; /* ('axis',) */
    cpy_r_r471 = _PyObject_Vectorcall(cpy_r_r466, cpy_r_r469, 2, cpy_r_r470);
    CPy_DECREF(cpy_r_r466);
    if (unlikely(cpy_r_r471 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 461, CPyStatic_globals);
        goto CPyL813;
    }
    CPy_DECREF(cpy_r_r460);
    CPy_DECREF(cpy_r_r463);
    cpy_r_r472 = CPyStatics[74]; /* 'starmap' */
    cpy_r_r473 = CPyObject_CallMethodObjArgs(cpy_r_pool, cpy_r_r472, cpy_r_r454, cpy_r_r471, NULL);
    CPy_DECREF(cpy_r_pool);
    CPy_DECREF(cpy_r_r454);
    CPy_DECREF(cpy_r_r471);
    if (unlikely(cpy_r_r473 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 461, CPyStatic_globals);
        goto CPyL814;
    }
    cpy_r_T4res = cpy_r_r473;
    cpy_r_r474 = CPyStatics[75]; /* 'Done!' */
    cpy_r_r475 = CPyModule_builtins;
    cpy_r_r476 = CPyStatics[8]; /* 'print' */
    cpy_r_r477 = CPyObject_GetAttr(cpy_r_r475, cpy_r_r476);
    if (unlikely(cpy_r_r477 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 462, CPyStatic_globals);
        goto CPyL815;
    }
    PyObject *cpy_r_r478[1] = {cpy_r_r474};
    cpy_r_r479 = (PyObject **)&cpy_r_r478;
    cpy_r_r480 = _PyObject_Vectorcall(cpy_r_r477, cpy_r_r479, 1, 0);
    CPy_DECREF(cpy_r_r477);
    if (unlikely(cpy_r_r480 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 462, CPyStatic_globals);
        goto CPyL815;
    } else
        goto CPyL816;
CPyL218: ;
    cpy_r_r481 = CPyStatics[78]; /* 'Unzipping reuslts into arrays...' */
    cpy_r_r482 = CPyModule_builtins;
    cpy_r_r483 = CPyStatics[8]; /* 'print' */
    cpy_r_r484 = CPyObject_GetAttr(cpy_r_r482, cpy_r_r483);
    if (unlikely(cpy_r_r484 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 463, CPyStatic_globals);
        goto CPyL815;
    }
    PyObject *cpy_r_r485[1] = {cpy_r_r481};
    cpy_r_r486 = (PyObject **)&cpy_r_r485;
    cpy_r_r487 = _PyObject_Vectorcall(cpy_r_r484, cpy_r_r486, 1, 0);
    CPy_DECREF(cpy_r_r484);
    if (unlikely(cpy_r_r487 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 463, CPyStatic_globals);
        goto CPyL815;
    } else
        goto CPyL817;
CPyL220: ;
    cpy_r_r488 = PyObject_GetIter(cpy_r_T1res);
    CPy_DECREF(cpy_r_T1res);
    if (unlikely(cpy_r_r488 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 464, CPyStatic_globals);
        goto CPyL818;
    }
    cpy_r_r489 = PyObject_GetIter(cpy_r_T1part_ids);
    CPy_DECREF(cpy_r_T1part_ids);
    if (unlikely(cpy_r_r489 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 464, CPyStatic_globals);
        goto CPyL819;
    }
CPyL222: ;
    cpy_r_r490 = PyIter_Next(cpy_r_r488);
    if (cpy_r_r490 == NULL) goto CPyL820;
    cpy_r_r491 = PyIter_Next(cpy_r_r489);
    if (cpy_r_r491 == NULL) goto CPyL821;
    cpy_r_r492 = PyObject_GetIter(cpy_r_r490);
    CPy_DECREF(cpy_r_r490);
    if (unlikely(cpy_r_r492 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 464, CPyStatic_globals);
        goto CPyL822;
    }
    cpy_r_r493 = PyIter_Next(cpy_r_r492);
    if (cpy_r_r493 == NULL) {
        goto CPyL823;
    } else
        goto CPyL228;
CPyL226: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r494 = 0;
    if (unlikely(!cpy_r_r494)) {
        CPy_AddTraceback("modTof.py", "run", 464, CPyStatic_globals);
        goto CPyL302;
    } else
        goto CPyL824;
CPyL227: ;
    CPy_Unreachable();
CPyL228: ;
    cpy_r_T1hit_PMT = cpy_r_r493;
    cpy_r_r495 = PyIter_Next(cpy_r_r492);
    if (cpy_r_r495 == NULL) {
        goto CPyL825;
    } else
        goto CPyL231;
CPyL229: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r496 = 0;
    if (unlikely(!cpy_r_r496)) {
        CPy_AddTraceback("modTof.py", "run", 464, CPyStatic_globals);
        goto CPyL302;
    } else
        goto CPyL826;
CPyL230: ;
    CPy_Unreachable();
CPyL231: ;
    cpy_r_T1travel_time = cpy_r_r495;
    cpy_r_r497 = PyIter_Next(cpy_r_r492);
    if (cpy_r_r497 == NULL) {
        goto CPyL827;
    } else
        goto CPyL234;
CPyL232: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r498 = 0;
    if (unlikely(!cpy_r_r498)) {
        CPy_AddTraceback("modTof.py", "run", 464, CPyStatic_globals);
        goto CPyL302;
    } else
        goto CPyL828;
CPyL233: ;
    CPy_Unreachable();
CPyL234: ;
    cpy_r_T1tot_dist = cpy_r_r497;
    cpy_r_r499 = PyIter_Next(cpy_r_r492);
    if (cpy_r_r499 == NULL) {
        goto CPyL829;
    } else
        goto CPyL237;
CPyL235: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r500 = 0;
    if (unlikely(!cpy_r_r500)) {
        CPy_AddTraceback("modTof.py", "run", 464, CPyStatic_globals);
        goto CPyL302;
    } else
        goto CPyL830;
CPyL236: ;
    CPy_Unreachable();
CPyL237: ;
    cpy_r_T1endpt = cpy_r_r499;
    cpy_r_r501 = PyIter_Next(cpy_r_r492);
    if (cpy_r_r501 == NULL) {
        goto CPyL831;
    } else
        goto CPyL240;
CPyL238: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r502 = 0;
    if (unlikely(!cpy_r_r502)) {
        CPy_AddTraceback("modTof.py", "run", 464, CPyStatic_globals);
        goto CPyL302;
    } else
        goto CPyL832;
CPyL239: ;
    CPy_Unreachable();
CPyL240: ;
    cpy_r_T1bounces = cpy_r_r501;
    cpy_r_r503 = PyIter_Next(cpy_r_r492);
    if (cpy_r_r503 == NULL) {
        goto CPyL833;
    } else
        goto CPyL243;
CPyL241: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r504 = 0;
    if (unlikely(!cpy_r_r504)) {
        CPy_AddTraceback("modTof.py", "run", 464, CPyStatic_globals);
        goto CPyL302;
    } else
        goto CPyL834;
CPyL242: ;
    CPy_Unreachable();
CPyL243: ;
    cpy_r_T1prop = cpy_r_r503;
    cpy_r_r505 = PyIter_Next(cpy_r_r492);
    CPy_DECREF(cpy_r_r492);
    if (cpy_r_r505 == NULL) {
        goto CPyL246;
    } else
        goto CPyL835;
CPyL244: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r506 = 0;
    if (unlikely(!cpy_r_r506)) {
        CPy_AddTraceback("modTof.py", "run", 464, CPyStatic_globals);
        goto CPyL302;
    } else
        goto CPyL836;
CPyL245: ;
    CPy_Unreachable();
CPyL246: ;
    cpy_r_T1part_id = cpy_r_r491;
    cpy_r_r507 = PyObject_IsTrue(cpy_r_T1hit_PMT);
    CPy_DECREF(cpy_r_T1hit_PMT);
    cpy_r_r508 = cpy_r_r507 >= 0;
    if (unlikely(!cpy_r_r508)) {
        CPy_AddTraceback("modTof.py", "run", 464, CPyStatic_globals);
        goto CPyL837;
    }
    cpy_r_r509 = cpy_r_r507;
    if (!cpy_r_r509) goto CPyL838;
    cpy_r_r510 = CPyStatics[43]; /* 'append' */
    cpy_r_r511 = CPyObject_CallMethodObjArgs(cpy_r_T1_input_times, cpy_r_r510, cpy_r_T1travel_time, NULL);
    CPy_DECREF(cpy_r_T1travel_time);
    if (unlikely(cpy_r_r511 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 466, CPyStatic_globals);
        goto CPyL839;
    } else
        goto CPyL840;
CPyL249: ;
    cpy_r_r512 = ((modTof___SimulationObject *)cpy_r_self)->_T1_prop_dist;
    if (unlikely(cpy_r_r512 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "T1_prop_dist", 467, CPyStatic_globals);
        goto CPyL839;
    }
    CPy_INCREF(cpy_r_r512);
CPyL250: ;
    cpy_r_r513 = CPyStatics[43]; /* 'append' */
    cpy_r_r514 = CPyObject_CallMethodObjArgs(cpy_r_r512, cpy_r_r513, cpy_r_T1tot_dist, NULL);
    CPy_DECREF(cpy_r_r512);
    CPy_DECREF(cpy_r_T1tot_dist);
    if (unlikely(cpy_r_r514 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 467, CPyStatic_globals);
        goto CPyL841;
    } else
        goto CPyL842;
CPyL251: ;
    cpy_r_r515 = ((modTof___SimulationObject *)cpy_r_self)->_T1_endpoint_dist;
    if (unlikely(cpy_r_r515 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "T1_endpoint_dist", 468, CPyStatic_globals);
        goto CPyL841;
    }
    CPy_INCREF(cpy_r_r515);
CPyL252: ;
    cpy_r_r516 = CPyStatics[43]; /* 'append' */
    cpy_r_r517 = CPyObject_CallMethodObjArgs(cpy_r_r515, cpy_r_r516, cpy_r_T1endpt, NULL);
    CPy_DECREF(cpy_r_r515);
    CPy_DECREF(cpy_r_T1endpt);
    if (unlikely(cpy_r_r517 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 468, CPyStatic_globals);
        goto CPyL843;
    } else
        goto CPyL844;
CPyL253: ;
    cpy_r_r518 = ((modTof___SimulationObject *)cpy_r_self)->_T1_prop_times;
    if (unlikely(cpy_r_r518 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "T1_prop_times", 469, CPyStatic_globals);
        goto CPyL843;
    }
    CPy_INCREF(cpy_r_r518);
CPyL254: ;
    cpy_r_r519 = CPyStatics[43]; /* 'append' */
    cpy_r_r520 = CPyObject_CallMethodObjArgs(cpy_r_r518, cpy_r_r519, cpy_r_T1prop, NULL);
    CPy_DECREF(cpy_r_r518);
    CPy_DECREF(cpy_r_T1prop);
    if (unlikely(cpy_r_r520 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 469, CPyStatic_globals);
        goto CPyL845;
    } else
        goto CPyL846;
CPyL255: ;
    cpy_r_r521 = ((modTof___SimulationObject *)cpy_r_self)->_T1_interactions;
    if (unlikely(cpy_r_r521 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "T1_interactions", 470, CPyStatic_globals);
        goto CPyL845;
    }
    CPy_INCREF(cpy_r_r521);
CPyL256: ;
    cpy_r_r522 = CPyStatics[43]; /* 'append' */
    cpy_r_r523 = CPyObject_CallMethodObjArgs(cpy_r_r521, cpy_r_r522, cpy_r_T1bounces, NULL);
    CPy_DECREF(cpy_r_r521);
    CPy_DECREF(cpy_r_T1bounces);
    if (unlikely(cpy_r_r523 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 470, CPyStatic_globals);
        goto CPyL847;
    } else
        goto CPyL848;
CPyL257: ;
    cpy_r_r524 = ((modTof___SimulationObject *)cpy_r_self)->_T1_part_ids;
    if (unlikely(cpy_r_r524 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "T1_part_ids", 471, CPyStatic_globals);
        goto CPyL847;
    }
    CPy_INCREF(cpy_r_r524);
CPyL258: ;
    cpy_r_r525 = CPyStatics[43]; /* 'append' */
    cpy_r_r526 = CPyObject_CallMethodObjArgs(cpy_r_r524, cpy_r_r525, cpy_r_T1part_id, NULL);
    CPy_DECREF(cpy_r_r524);
    CPy_DECREF(cpy_r_T1part_id);
    if (unlikely(cpy_r_r526 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 471, CPyStatic_globals);
        goto CPyL849;
    } else
        goto CPyL850;
CPyL259: ;
    cpy_r_r527 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r527)) {
        CPy_AddTraceback("modTof.py", "run", 464, CPyStatic_globals);
        goto CPyL851;
    }
    cpy_r_r528 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r528)) {
        CPy_AddTraceback("modTof.py", "run", 464, CPyStatic_globals);
        goto CPyL851;
    }
    cpy_r_r529 = PyObject_GetIter(cpy_r_T4res);
    CPy_DECREF(cpy_r_T4res);
    if (unlikely(cpy_r_r529 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 472, CPyStatic_globals);
        goto CPyL852;
    }
    cpy_r_r530 = PyObject_GetIter(cpy_r_T4part_ids);
    CPy_DECREF(cpy_r_T4part_ids);
    if (unlikely(cpy_r_r530 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 472, CPyStatic_globals);
        goto CPyL853;
    }
CPyL263: ;
    cpy_r_r531 = PyIter_Next(cpy_r_r529);
    if (cpy_r_r531 == NULL) goto CPyL854;
    cpy_r_r532 = PyIter_Next(cpy_r_r530);
    if (cpy_r_r532 == NULL) goto CPyL855;
    cpy_r_r533 = PyObject_GetIter(cpy_r_r531);
    CPy_DECREF(cpy_r_r531);
    if (unlikely(cpy_r_r533 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 472, CPyStatic_globals);
        goto CPyL856;
    }
    cpy_r_r534 = PyIter_Next(cpy_r_r533);
    if (cpy_r_r534 == NULL) {
        goto CPyL857;
    } else
        goto CPyL269;
CPyL267: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r535 = 0;
    if (unlikely(!cpy_r_r535)) {
        CPy_AddTraceback("modTof.py", "run", 472, CPyStatic_globals);
        goto CPyL302;
    } else
        goto CPyL858;
CPyL268: ;
    CPy_Unreachable();
CPyL269: ;
    cpy_r_T4hit_PMT = cpy_r_r534;
    cpy_r_r536 = PyIter_Next(cpy_r_r533);
    if (cpy_r_r536 == NULL) {
        goto CPyL859;
    } else
        goto CPyL272;
CPyL270: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r537 = 0;
    if (unlikely(!cpy_r_r537)) {
        CPy_AddTraceback("modTof.py", "run", 472, CPyStatic_globals);
        goto CPyL302;
    } else
        goto CPyL860;
CPyL271: ;
    CPy_Unreachable();
CPyL272: ;
    cpy_r_T4travel_time = cpy_r_r536;
    cpy_r_r538 = PyIter_Next(cpy_r_r533);
    if (cpy_r_r538 == NULL) {
        goto CPyL861;
    } else
        goto CPyL275;
CPyL273: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r539 = 0;
    if (unlikely(!cpy_r_r539)) {
        CPy_AddTraceback("modTof.py", "run", 472, CPyStatic_globals);
        goto CPyL302;
    } else
        goto CPyL862;
CPyL274: ;
    CPy_Unreachable();
CPyL275: ;
    cpy_r_T4tot_dist = cpy_r_r538;
    cpy_r_r540 = PyIter_Next(cpy_r_r533);
    if (cpy_r_r540 == NULL) {
        goto CPyL863;
    } else
        goto CPyL278;
CPyL276: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r541 = 0;
    if (unlikely(!cpy_r_r541)) {
        CPy_AddTraceback("modTof.py", "run", 472, CPyStatic_globals);
        goto CPyL302;
    } else
        goto CPyL864;
CPyL277: ;
    CPy_Unreachable();
CPyL278: ;
    cpy_r_T4endpt = cpy_r_r540;
    cpy_r_r542 = PyIter_Next(cpy_r_r533);
    if (cpy_r_r542 == NULL) {
        goto CPyL865;
    } else
        goto CPyL281;
CPyL279: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r543 = 0;
    if (unlikely(!cpy_r_r543)) {
        CPy_AddTraceback("modTof.py", "run", 472, CPyStatic_globals);
        goto CPyL302;
    } else
        goto CPyL866;
CPyL280: ;
    CPy_Unreachable();
CPyL281: ;
    cpy_r_T4bounces = cpy_r_r542;
    cpy_r_r544 = PyIter_Next(cpy_r_r533);
    if (cpy_r_r544 == NULL) {
        goto CPyL867;
    } else
        goto CPyL284;
CPyL282: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r545 = 0;
    if (unlikely(!cpy_r_r545)) {
        CPy_AddTraceback("modTof.py", "run", 472, CPyStatic_globals);
        goto CPyL302;
    } else
        goto CPyL868;
CPyL283: ;
    CPy_Unreachable();
CPyL284: ;
    cpy_r_T4prop = cpy_r_r544;
    cpy_r_r546 = PyIter_Next(cpy_r_r533);
    CPy_DECREF(cpy_r_r533);
    if (cpy_r_r546 == NULL) {
        goto CPyL287;
    } else
        goto CPyL869;
CPyL285: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r547 = 0;
    if (unlikely(!cpy_r_r547)) {
        CPy_AddTraceback("modTof.py", "run", 472, CPyStatic_globals);
        goto CPyL302;
    } else
        goto CPyL870;
CPyL286: ;
    CPy_Unreachable();
CPyL287: ;
    cpy_r_T4part_id = cpy_r_r532;
    cpy_r_r548 = PyObject_IsTrue(cpy_r_T4hit_PMT);
    CPy_DECREF(cpy_r_T4hit_PMT);
    cpy_r_r549 = cpy_r_r548 >= 0;
    if (unlikely(!cpy_r_r549)) {
        CPy_AddTraceback("modTof.py", "run", 472, CPyStatic_globals);
        goto CPyL871;
    }
    cpy_r_r550 = cpy_r_r548;
    if (!cpy_r_r550) goto CPyL872;
    cpy_r_r551 = CPyStatics[43]; /* 'append' */
    cpy_r_r552 = CPyObject_CallMethodObjArgs(cpy_r_T4_input_times, cpy_r_r551, cpy_r_T4travel_time, NULL);
    CPy_DECREF(cpy_r_T4travel_time);
    if (unlikely(cpy_r_r552 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 474, CPyStatic_globals);
        goto CPyL873;
    } else
        goto CPyL874;
CPyL290: ;
    cpy_r_r553 = ((modTof___SimulationObject *)cpy_r_self)->_T4_prop_dist;
    if (unlikely(cpy_r_r553 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "T4_prop_dist", 475, CPyStatic_globals);
        goto CPyL873;
    }
    CPy_INCREF(cpy_r_r553);
CPyL291: ;
    cpy_r_r554 = CPyStatics[43]; /* 'append' */
    cpy_r_r555 = CPyObject_CallMethodObjArgs(cpy_r_r553, cpy_r_r554, cpy_r_T4tot_dist, NULL);
    CPy_DECREF(cpy_r_r553);
    CPy_DECREF(cpy_r_T4tot_dist);
    if (unlikely(cpy_r_r555 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 475, CPyStatic_globals);
        goto CPyL875;
    } else
        goto CPyL876;
CPyL292: ;
    cpy_r_r556 = ((modTof___SimulationObject *)cpy_r_self)->_T4_endpoint_dist;
    if (unlikely(cpy_r_r556 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "T4_endpoint_dist", 476, CPyStatic_globals);
        goto CPyL875;
    }
    CPy_INCREF(cpy_r_r556);
CPyL293: ;
    cpy_r_r557 = CPyStatics[43]; /* 'append' */
    cpy_r_r558 = CPyObject_CallMethodObjArgs(cpy_r_r556, cpy_r_r557, cpy_r_T4endpt, NULL);
    CPy_DECREF(cpy_r_r556);
    CPy_DECREF(cpy_r_T4endpt);
    if (unlikely(cpy_r_r558 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 476, CPyStatic_globals);
        goto CPyL877;
    } else
        goto CPyL878;
CPyL294: ;
    cpy_r_r559 = ((modTof___SimulationObject *)cpy_r_self)->_T4_prop_times;
    if (unlikely(cpy_r_r559 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "T4_prop_times", 477, CPyStatic_globals);
        goto CPyL877;
    }
    CPy_INCREF(cpy_r_r559);
CPyL295: ;
    cpy_r_r560 = CPyStatics[43]; /* 'append' */
    cpy_r_r561 = CPyObject_CallMethodObjArgs(cpy_r_r559, cpy_r_r560, cpy_r_T4prop, NULL);
    CPy_DECREF(cpy_r_r559);
    CPy_DECREF(cpy_r_T4prop);
    if (unlikely(cpy_r_r561 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 477, CPyStatic_globals);
        goto CPyL879;
    } else
        goto CPyL880;
CPyL296: ;
    cpy_r_r562 = ((modTof___SimulationObject *)cpy_r_self)->_T4_interactions;
    if (unlikely(cpy_r_r562 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "T4_interactions", 478, CPyStatic_globals);
        goto CPyL879;
    }
    CPy_INCREF(cpy_r_r562);
CPyL297: ;
    cpy_r_r563 = CPyStatics[43]; /* 'append' */
    cpy_r_r564 = CPyObject_CallMethodObjArgs(cpy_r_r562, cpy_r_r563, cpy_r_T4bounces, NULL);
    CPy_DECREF(cpy_r_r562);
    CPy_DECREF(cpy_r_T4bounces);
    if (unlikely(cpy_r_r564 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 478, CPyStatic_globals);
        goto CPyL881;
    } else
        goto CPyL882;
CPyL298: ;
    cpy_r_r565 = ((modTof___SimulationObject *)cpy_r_self)->_T4_part_ids;
    if (unlikely(cpy_r_r565 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "T4_part_ids", 479, CPyStatic_globals);
        goto CPyL881;
    }
    CPy_INCREF(cpy_r_r565);
CPyL299: ;
    cpy_r_r566 = CPyStatics[43]; /* 'append' */
    cpy_r_r567 = CPyObject_CallMethodObjArgs(cpy_r_r565, cpy_r_r566, cpy_r_T4part_id, NULL);
    CPy_DECREF(cpy_r_r565);
    CPy_DECREF(cpy_r_T4part_id);
    if (unlikely(cpy_r_r567 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 479, CPyStatic_globals);
        goto CPyL883;
    } else
        goto CPyL884;
CPyL300: ;
    cpy_r_r568 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r568)) {
        CPy_AddTraceback("modTof.py", "run", 472, CPyStatic_globals);
        goto CPyL302;
    }
    cpy_r_r569 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r569)) {
        CPy_AddTraceback("modTof.py", "run", 472, CPyStatic_globals);
    } else
        goto CPyL310;
CPyL302: ;
    cpy_r_r570 = CPy_CatchError();
    cpy_r_r410 = 0;
    cpy_r_r571 = CPy_GetExcInfo();
    cpy_r_r572 = cpy_r_r571.f0;
    CPy_INCREF(cpy_r_r572);
    cpy_r_r573 = cpy_r_r571.f1;
    CPy_INCREF(cpy_r_r573);
    cpy_r_r574 = cpy_r_r571.f2;
    CPy_INCREF(cpy_r_r574);
    CPy_DecRef(cpy_r_r571.f0);
    CPy_DecRef(cpy_r_r571.f1);
    CPy_DecRef(cpy_r_r571.f2);
    PyObject *cpy_r_r575[4] = {cpy_r_r401, cpy_r_r572, cpy_r_r573, cpy_r_r574};
    cpy_r_r576 = (PyObject **)&cpy_r_r575;
    cpy_r_r577 = _PyObject_Vectorcall(cpy_r_r404, cpy_r_r576, 4, 0);
    if (unlikely(cpy_r_r577 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 456, CPyStatic_globals);
        goto CPyL885;
    }
    CPy_DecRef(cpy_r_r572);
    CPy_DecRef(cpy_r_r573);
    CPy_DecRef(cpy_r_r574);
    cpy_r_r578 = PyObject_IsTrue(cpy_r_r577);
    CPy_DecRef(cpy_r_r577);
    cpy_r_r579 = cpy_r_r578 >= 0;
    if (unlikely(!cpy_r_r579)) {
        CPy_AddTraceback("modTof.py", "run", 456, CPyStatic_globals);
        goto CPyL308;
    }
    cpy_r_r580 = cpy_r_r578;
    if (cpy_r_r580) goto CPyL307;
    CPy_Reraise();
    if (!0) {
        goto CPyL308;
    } else
        goto CPyL886;
CPyL306: ;
    CPy_Unreachable();
CPyL307: ;
    CPy_RestoreExcInfo(cpy_r_r570);
    CPy_DecRef(cpy_r_r570.f0);
    CPy_DecRef(cpy_r_r570.f1);
    CPy_DecRef(cpy_r_r570.f2);
    goto CPyL310;
CPyL308: ;
    CPy_RestoreExcInfo(cpy_r_r570);
    CPy_DecRef(cpy_r_r570.f0);
    CPy_DecRef(cpy_r_r570.f1);
    CPy_DecRef(cpy_r_r570.f2);
    cpy_r_r581 = CPy_KeepPropagating();
    if (!cpy_r_r581) {
        goto CPyL311;
    } else
        goto CPyL887;
CPyL309: ;
    CPy_Unreachable();
CPyL310: ;
    tuple_T3OOO __tmp80 = { NULL, NULL, NULL };
    cpy_r_r582 = __tmp80;
    cpy_r_r583 = cpy_r_r582;
    goto CPyL312;
CPyL311: ;
    cpy_r_r584 = CPy_CatchError();
    cpy_r_r583 = cpy_r_r584;
CPyL312: ;
    if (!cpy_r_r410) goto CPyL888;
    cpy_r_r585 = (PyObject *)&_Py_NoneStruct;
    PyObject *cpy_r_r586[4] = {cpy_r_r401, cpy_r_r585, cpy_r_r585, cpy_r_r585};
    cpy_r_r587 = (PyObject **)&cpy_r_r586;
    cpy_r_r588 = _PyObject_Vectorcall(cpy_r_r404, cpy_r_r587, 4, 0);
    CPy_DECREF(cpy_r_r404);
    if (unlikely(cpy_r_r588 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 456, CPyStatic_globals);
        goto CPyL889;
    } else
        goto CPyL890;
CPyL314: ;
    CPy_DECREF(cpy_r_r401);
CPyL315: ;
    if (cpy_r_r583.f0 == NULL) {
        goto CPyL322;
    } else
        goto CPyL891;
CPyL316: ;
    CPy_Reraise();
    if (!0) {
        goto CPyL318;
    } else
        goto CPyL892;
CPyL317: ;
    CPy_Unreachable();
CPyL318: ;
    if (cpy_r_r583.f0 == NULL) goto CPyL320;
    CPy_RestoreExcInfo(cpy_r_r583);
    CPy_XDECREF(cpy_r_r583.f0);
    CPy_XDECREF(cpy_r_r583.f1);
    CPy_XDECREF(cpy_r_r583.f2);
CPyL320: ;
    cpy_r_r589 = CPy_KeepPropagating();
    if (!cpy_r_r589) goto CPyL720;
    CPy_Unreachable();
CPyL322: ;
    cpy_r_r590 = CPyStatic_globals;
    cpy_r_r591 = CPyStatics[54]; /* 'perf_counter' */
    cpy_r_r592 = CPyDict_GetItem(cpy_r_r590, cpy_r_r591);
    if (unlikely(cpy_r_r592 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 480, CPyStatic_globals);
        goto CPyL893;
    }
    cpy_r_r593 = _PyObject_Vectorcall(cpy_r_r592, 0, 0, 0);
    CPy_DECREF(cpy_r_r592);
    if (unlikely(cpy_r_r593 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 480, CPyStatic_globals);
        goto CPyL893;
    }
    cpy_r_logendtime = cpy_r_r593;
    cpy_r_r594 = CPyStatics[79]; /* 'TIME ANALYSIS:' */
    cpy_r_r595 = CPyModule_builtins;
    cpy_r_r596 = CPyStatics[8]; /* 'print' */
    cpy_r_r597 = CPyObject_GetAttr(cpy_r_r595, cpy_r_r596);
    if (unlikely(cpy_r_r597 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 482, CPyStatic_globals);
        goto CPyL894;
    }
    PyObject *cpy_r_r598[1] = {cpy_r_r594};
    cpy_r_r599 = (PyObject **)&cpy_r_r598;
    cpy_r_r600 = _PyObject_Vectorcall(cpy_r_r597, cpy_r_r599, 1, 0);
    CPy_DECREF(cpy_r_r597);
    if (unlikely(cpy_r_r600 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 482, CPyStatic_globals);
        goto CPyL894;
    } else
        goto CPyL895;
CPyL326: ;
    cpy_r_r601 = PyNumber_Subtract(cpy_r_logendparticle, cpy_r_logstarttime);
    CPy_DECREF(cpy_r_logendparticle);
    if (unlikely(cpy_r_r601 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 483, CPyStatic_globals);
        goto CPyL896;
    }
    cpy_r_r602 = CPyStatic_globals;
    cpy_r_r603 = CPyStatics[80]; /* 'timedelta' */
    cpy_r_r604 = CPyDict_GetItem(cpy_r_r602, cpy_r_r603);
    if (unlikely(cpy_r_r604 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 483, CPyStatic_globals);
        goto CPyL897;
    }
    PyObject *cpy_r_r605[1] = {cpy_r_r601};
    cpy_r_r606 = (PyObject **)&cpy_r_r605;
    cpy_r_r607 = CPyStatics[267]; /* ('seconds',) */
    cpy_r_r608 = _PyObject_Vectorcall(cpy_r_r604, cpy_r_r606, 0, cpy_r_r607);
    CPy_DECREF(cpy_r_r604);
    if (unlikely(cpy_r_r608 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 483, CPyStatic_globals);
        goto CPyL897;
    }
    CPy_DECREF(cpy_r_r601);
    cpy_r_pgtime = cpy_r_r608;
    cpy_r_r609 = PyNumber_Subtract(cpy_r_logendtime, cpy_r_logstartphoton);
    CPy_DECREF(cpy_r_logstartphoton);
    if (unlikely(cpy_r_r609 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 484, CPyStatic_globals);
        goto CPyL898;
    }
    cpy_r_r610 = CPyStatic_globals;
    cpy_r_r611 = CPyStatics[80]; /* 'timedelta' */
    cpy_r_r612 = CPyDict_GetItem(cpy_r_r610, cpy_r_r611);
    if (unlikely(cpy_r_r612 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 484, CPyStatic_globals);
        goto CPyL899;
    }
    PyObject *cpy_r_r613[1] = {cpy_r_r609};
    cpy_r_r614 = (PyObject **)&cpy_r_r613;
    cpy_r_r615 = CPyStatics[267]; /* ('seconds',) */
    cpy_r_r616 = _PyObject_Vectorcall(cpy_r_r612, cpy_r_r614, 0, cpy_r_r615);
    CPy_DECREF(cpy_r_r612);
    if (unlikely(cpy_r_r616 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 484, CPyStatic_globals);
        goto CPyL899;
    }
    CPy_DECREF(cpy_r_r609);
    cpy_r_phtime = cpy_r_r616;
    cpy_r_r617 = PyNumber_Subtract(cpy_r_logendtime, cpy_r_logstarttime);
    CPy_DECREF(cpy_r_logendtime);
    CPy_DECREF(cpy_r_logstarttime);
    if (unlikely(cpy_r_r617 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 485, CPyStatic_globals);
        goto CPyL900;
    }
    cpy_r_r618 = CPyStatic_globals;
    cpy_r_r619 = CPyStatics[80]; /* 'timedelta' */
    cpy_r_r620 = CPyDict_GetItem(cpy_r_r618, cpy_r_r619);
    if (unlikely(cpy_r_r620 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 485, CPyStatic_globals);
        goto CPyL901;
    }
    PyObject *cpy_r_r621[1] = {cpy_r_r617};
    cpy_r_r622 = (PyObject **)&cpy_r_r621;
    cpy_r_r623 = CPyStatics[267]; /* ('seconds',) */
    cpy_r_r624 = _PyObject_Vectorcall(cpy_r_r620, cpy_r_r622, 0, cpy_r_r623);
    CPy_DECREF(cpy_r_r620);
    if (unlikely(cpy_r_r624 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 485, CPyStatic_globals);
        goto CPyL901;
    }
    CPy_DECREF(cpy_r_r617);
    cpy_r_ttime = cpy_r_r624;
    cpy_r_r625 = CPyStatics[82]; /* 'Generation of Particles     ' */
    cpy_r_r626 = PyObject_Str(cpy_r_pgtime);
    CPy_DECREF(cpy_r_pgtime);
    if (unlikely(cpy_r_r626 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 486, CPyStatic_globals);
        goto CPyL902;
    }
    cpy_r_r627 = PyObject_Str(cpy_r_r626);
    CPy_DECREF(cpy_r_r626);
    if (unlikely(cpy_r_r627 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 486, CPyStatic_globals);
        goto CPyL902;
    }
    cpy_r_r628 = CPyStr_Build(2, cpy_r_r625, cpy_r_r627);
    CPy_DECREF(cpy_r_r627);
    if (unlikely(cpy_r_r628 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 486, CPyStatic_globals);
        goto CPyL902;
    }
    cpy_r_r629 = CPyModule_builtins;
    cpy_r_r630 = CPyStatics[8]; /* 'print' */
    cpy_r_r631 = CPyObject_GetAttr(cpy_r_r629, cpy_r_r630);
    if (unlikely(cpy_r_r631 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 486, CPyStatic_globals);
        goto CPyL903;
    }
    PyObject *cpy_r_r632[1] = {cpy_r_r628};
    cpy_r_r633 = (PyObject **)&cpy_r_r632;
    cpy_r_r634 = _PyObject_Vectorcall(cpy_r_r631, cpy_r_r633, 1, 0);
    CPy_DECREF(cpy_r_r631);
    if (unlikely(cpy_r_r634 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 486, CPyStatic_globals);
        goto CPyL903;
    } else
        goto CPyL904;
CPyL340: ;
    CPy_DECREF(cpy_r_r628);
    cpy_r_r635 = CPyStatics[83]; /* 'Simulation of Photon Travel ' */
    cpy_r_r636 = PyObject_Str(cpy_r_phtime);
    CPy_DECREF(cpy_r_phtime);
    if (unlikely(cpy_r_r636 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 487, CPyStatic_globals);
        goto CPyL905;
    }
    cpy_r_r637 = PyObject_Str(cpy_r_r636);
    CPy_DECREF(cpy_r_r636);
    if (unlikely(cpy_r_r637 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 487, CPyStatic_globals);
        goto CPyL905;
    }
    cpy_r_r638 = CPyStr_Build(2, cpy_r_r635, cpy_r_r637);
    CPy_DECREF(cpy_r_r637);
    if (unlikely(cpy_r_r638 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 487, CPyStatic_globals);
        goto CPyL905;
    }
    cpy_r_r639 = CPyModule_builtins;
    cpy_r_r640 = CPyStatics[8]; /* 'print' */
    cpy_r_r641 = CPyObject_GetAttr(cpy_r_r639, cpy_r_r640);
    if (unlikely(cpy_r_r641 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 487, CPyStatic_globals);
        goto CPyL906;
    }
    PyObject *cpy_r_r642[1] = {cpy_r_r638};
    cpy_r_r643 = (PyObject **)&cpy_r_r642;
    cpy_r_r644 = _PyObject_Vectorcall(cpy_r_r641, cpy_r_r643, 1, 0);
    CPy_DECREF(cpy_r_r641);
    if (unlikely(cpy_r_r644 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 487, CPyStatic_globals);
        goto CPyL906;
    } else
        goto CPyL907;
CPyL345: ;
    CPy_DECREF(cpy_r_r638);
    cpy_r_r645 = CPyStatics[84]; /* 'Total Time Elapsed:         ' */
    cpy_r_r646 = PyObject_Str(cpy_r_ttime);
    CPy_DECREF(cpy_r_ttime);
    if (unlikely(cpy_r_r646 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 488, CPyStatic_globals);
        goto CPyL908;
    }
    cpy_r_r647 = PyObject_Str(cpy_r_r646);
    CPy_DECREF(cpy_r_r646);
    if (unlikely(cpy_r_r647 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 488, CPyStatic_globals);
        goto CPyL908;
    }
    cpy_r_r648 = CPyStr_Build(2, cpy_r_r645, cpy_r_r647);
    CPy_DECREF(cpy_r_r647);
    if (unlikely(cpy_r_r648 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 488, CPyStatic_globals);
        goto CPyL908;
    }
    cpy_r_r649 = CPyModule_builtins;
    cpy_r_r650 = CPyStatics[8]; /* 'print' */
    cpy_r_r651 = CPyObject_GetAttr(cpy_r_r649, cpy_r_r650);
    if (unlikely(cpy_r_r651 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 488, CPyStatic_globals);
        goto CPyL909;
    }
    PyObject *cpy_r_r652[1] = {cpy_r_r648};
    cpy_r_r653 = (PyObject **)&cpy_r_r652;
    cpy_r_r654 = _PyObject_Vectorcall(cpy_r_r651, cpy_r_r653, 1, 0);
    CPy_DECREF(cpy_r_r651);
    if (unlikely(cpy_r_r654 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 488, CPyStatic_globals);
        goto CPyL909;
    } else
        goto CPyL910;
CPyL350: ;
    CPy_DECREF(cpy_r_r648);
    cpy_r_r655 = CPyStatics[85]; /* 'RESULTS SUMMARY:' */
    cpy_r_r656 = CPyModule_builtins;
    cpy_r_r657 = CPyStatics[8]; /* 'print' */
    cpy_r_r658 = CPyObject_GetAttr(cpy_r_r656, cpy_r_r657);
    if (unlikely(cpy_r_r658 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 489, CPyStatic_globals);
        goto CPyL908;
    }
    PyObject *cpy_r_r659[1] = {cpy_r_r655};
    cpy_r_r660 = (PyObject **)&cpy_r_r659;
    cpy_r_r661 = _PyObject_Vectorcall(cpy_r_r658, cpy_r_r660, 1, 0);
    CPy_DECREF(cpy_r_r658);
    if (unlikely(cpy_r_r661 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 489, CPyStatic_globals);
        goto CPyL908;
    } else
        goto CPyL911;
CPyL352: ;
    cpy_r_r662 = CPyStatics[86]; /* 'HITS on T1' */
    cpy_r_r663 = CPyObject_Size(cpy_r_T1_input_times);
    if (unlikely(cpy_r_r663 == CPY_INT_TAG)) {
        CPy_AddTraceback("modTof.py", "run", 490, CPyStatic_globals);
        goto CPyL908;
    }
    cpy_r_r664 = CPyTagged_StealAsObject(cpy_r_r663);
    cpy_r_r665 = CPyModule_builtins;
    cpy_r_r666 = CPyStatics[8]; /* 'print' */
    cpy_r_r667 = CPyObject_GetAttr(cpy_r_r665, cpy_r_r666);
    if (unlikely(cpy_r_r667 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 490, CPyStatic_globals);
        goto CPyL912;
    }
    PyObject *cpy_r_r668[2] = {cpy_r_r662, cpy_r_r664};
    cpy_r_r669 = (PyObject **)&cpy_r_r668;
    cpy_r_r670 = _PyObject_Vectorcall(cpy_r_r667, cpy_r_r669, 2, 0);
    CPy_DECREF(cpy_r_r667);
    if (unlikely(cpy_r_r670 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 490, CPyStatic_globals);
        goto CPyL912;
    } else
        goto CPyL913;
CPyL355: ;
    CPy_DECREF(cpy_r_r664);
    cpy_r_r671 = CPyStatics[87]; /* 'RATIO T1   total photons' */
    cpy_r_r672 = CPyModule_numpy;
    cpy_r_r673 = CPyStatics[29]; /* 'sum' */
    cpy_r_r674 = CPyObject_GetAttr(cpy_r_r672, cpy_r_r673);
    if (unlikely(cpy_r_r674 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 491, CPyStatic_globals);
        goto CPyL908;
    }
    PyObject *cpy_r_r675[1] = {cpy_r_T1photons};
    cpy_r_r676 = (PyObject **)&cpy_r_r675;
    cpy_r_r677 = _PyObject_Vectorcall(cpy_r_r674, cpy_r_r676, 1, 0);
    CPy_DECREF(cpy_r_r674);
    if (unlikely(cpy_r_r677 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 491, CPyStatic_globals);
        goto CPyL908;
    }
    cpy_r_r678 = CPyStatics[88]; /* 'total incident photons' */
    cpy_r_r679 = CPyObject_Size(cpy_r_T1_input_times);
    if (unlikely(cpy_r_r679 == CPY_INT_TAG)) {
        CPy_AddTraceback("modTof.py", "run", 491, CPyStatic_globals);
        goto CPyL914;
    }
    cpy_r_r680 = CPyTagged_StealAsObject(cpy_r_r679);
    cpy_r_r681 = CPyStatics[89]; /* '' */
    cpy_r_r682 = CPyStatics[90]; /* 'ratio=' */
    cpy_r_r683 = CPyStatics[91]; /* '{:{}}' */
    cpy_r_r684 = CPyModule_numpy;
    cpy_r_r685 = CPyStatics[29]; /* 'sum' */
    cpy_r_r686 = CPyObject_GetAttr(cpy_r_r684, cpy_r_r685);
    if (unlikely(cpy_r_r686 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 491, CPyStatic_globals);
        goto CPyL915;
    }
    PyObject *cpy_r_r687[1] = {cpy_r_T1photons};
    cpy_r_r688 = (PyObject **)&cpy_r_r687;
    cpy_r_r689 = _PyObject_Vectorcall(cpy_r_r686, cpy_r_r688, 1, 0);
    CPy_DECREF(cpy_r_r686);
    if (unlikely(cpy_r_r689 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 491, CPyStatic_globals);
        goto CPyL915;
    }
    CPy_DECREF(cpy_r_T1photons);
    cpy_r_r690 = CPyObject_Size(cpy_r_T1_input_times);
    if (unlikely(cpy_r_r690 == CPY_INT_TAG)) {
        CPy_AddTraceback("modTof.py", "run", 491, CPyStatic_globals);
        goto CPyL916;
    }
    cpy_r_r691 = CPyTagged_StealAsObject(cpy_r_r690);
    cpy_r_r692 = PyNumber_TrueDivide(cpy_r_r689, cpy_r_r691);
    CPy_DECREF(cpy_r_r689);
    CPy_DECREF(cpy_r_r691);
    if (unlikely(cpy_r_r692 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 491, CPyStatic_globals);
        goto CPyL917;
    }
    cpy_r_r693 = CPyStatics[92]; /* '.2f' */
    cpy_r_r694 = CPyStatics[93]; /* 'format' */
    cpy_r_r695 = CPyObject_CallMethodObjArgs(cpy_r_r683, cpy_r_r694, cpy_r_r692, cpy_r_r693, NULL);
    CPy_DECREF(cpy_r_r692);
    if (unlikely(cpy_r_r695 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 491, CPyStatic_globals);
        goto CPyL917;
    }
    cpy_r_r696 = PyList_New(2);
    if (unlikely(cpy_r_r696 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 491, CPyStatic_globals);
        goto CPyL918;
    }
    cpy_r_r697 = (CPyPtr)&((PyListObject *)cpy_r_r696)->ob_item;
    cpy_r_r698 = *(CPyPtr *)cpy_r_r697;
    CPy_INCREF(cpy_r_r682);
    *(PyObject * *)cpy_r_r698 = cpy_r_r682;
    cpy_r_r699 = cpy_r_r698 + 8;
    *(PyObject * *)cpy_r_r699 = cpy_r_r695;
    cpy_r_r700 = PyUnicode_Join(cpy_r_r681, cpy_r_r696);
    CPy_DECREF(cpy_r_r696);
    if (unlikely(cpy_r_r700 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 491, CPyStatic_globals);
        goto CPyL917;
    }
    cpy_r_r701 = CPyModule_builtins;
    cpy_r_r702 = CPyStatics[8]; /* 'print' */
    cpy_r_r703 = CPyObject_GetAttr(cpy_r_r701, cpy_r_r702);
    if (unlikely(cpy_r_r703 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 491, CPyStatic_globals);
        goto CPyL919;
    }
    PyObject *cpy_r_r704[5] = {cpy_r_r671, cpy_r_r677, cpy_r_r678, cpy_r_r680, cpy_r_r700};
    cpy_r_r705 = (PyObject **)&cpy_r_r704;
    cpy_r_r706 = _PyObject_Vectorcall(cpy_r_r703, cpy_r_r705, 5, 0);
    CPy_DECREF(cpy_r_r703);
    if (unlikely(cpy_r_r706 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 491, CPyStatic_globals);
        goto CPyL919;
    } else
        goto CPyL920;
CPyL367: ;
    CPy_DECREF(cpy_r_r677);
    CPy_DECREF(cpy_r_r680);
    CPy_DECREF(cpy_r_r700);
    cpy_r_r707 = CPyStatics[94]; /* 'HITS on T4' */
    cpy_r_r708 = CPyObject_Size(cpy_r_T4_input_times);
    if (unlikely(cpy_r_r708 == CPY_INT_TAG)) {
        CPy_AddTraceback("modTof.py", "run", 492, CPyStatic_globals);
        goto CPyL921;
    }
    cpy_r_r709 = CPyTagged_StealAsObject(cpy_r_r708);
    cpy_r_r710 = CPyModule_builtins;
    cpy_r_r711 = CPyStatics[8]; /* 'print' */
    cpy_r_r712 = CPyObject_GetAttr(cpy_r_r710, cpy_r_r711);
    if (unlikely(cpy_r_r712 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 492, CPyStatic_globals);
        goto CPyL922;
    }
    PyObject *cpy_r_r713[2] = {cpy_r_r707, cpy_r_r709};
    cpy_r_r714 = (PyObject **)&cpy_r_r713;
    cpy_r_r715 = _PyObject_Vectorcall(cpy_r_r712, cpy_r_r714, 2, 0);
    CPy_DECREF(cpy_r_r712);
    if (unlikely(cpy_r_r715 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 492, CPyStatic_globals);
        goto CPyL922;
    } else
        goto CPyL923;
CPyL370: ;
    CPy_DECREF(cpy_r_r709);
    cpy_r_r716 = CPyStatics[95]; /* 'RATIO T4   total photons ' */
    cpy_r_r717 = CPyModule_numpy;
    cpy_r_r718 = CPyStatics[29]; /* 'sum' */
    cpy_r_r719 = CPyObject_GetAttr(cpy_r_r717, cpy_r_r718);
    if (unlikely(cpy_r_r719 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 493, CPyStatic_globals);
        goto CPyL921;
    }
    PyObject *cpy_r_r720[1] = {cpy_r_T4photons};
    cpy_r_r721 = (PyObject **)&cpy_r_r720;
    cpy_r_r722 = _PyObject_Vectorcall(cpy_r_r719, cpy_r_r721, 1, 0);
    CPy_DECREF(cpy_r_r719);
    if (unlikely(cpy_r_r722 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 493, CPyStatic_globals);
        goto CPyL921;
    }
    cpy_r_r723 = CPyStatics[88]; /* 'total incident photons' */
    cpy_r_r724 = CPyObject_Size(cpy_r_T4_input_times);
    if (unlikely(cpy_r_r724 == CPY_INT_TAG)) {
        CPy_AddTraceback("modTof.py", "run", 493, CPyStatic_globals);
        goto CPyL924;
    }
    cpy_r_r725 = CPyTagged_StealAsObject(cpy_r_r724);
    cpy_r_r726 = CPyStatics[89]; /* '' */
    cpy_r_r727 = CPyStatics[90]; /* 'ratio=' */
    cpy_r_r728 = CPyStatics[91]; /* '{:{}}' */
    cpy_r_r729 = CPyModule_numpy;
    cpy_r_r730 = CPyStatics[29]; /* 'sum' */
    cpy_r_r731 = CPyObject_GetAttr(cpy_r_r729, cpy_r_r730);
    if (unlikely(cpy_r_r731 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 493, CPyStatic_globals);
        goto CPyL925;
    }
    PyObject *cpy_r_r732[1] = {cpy_r_T4photons};
    cpy_r_r733 = (PyObject **)&cpy_r_r732;
    cpy_r_r734 = _PyObject_Vectorcall(cpy_r_r731, cpy_r_r733, 1, 0);
    CPy_DECREF(cpy_r_r731);
    if (unlikely(cpy_r_r734 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 493, CPyStatic_globals);
        goto CPyL925;
    }
    CPy_DECREF(cpy_r_T4photons);
    cpy_r_r735 = CPyObject_Size(cpy_r_T4_input_times);
    if (unlikely(cpy_r_r735 == CPY_INT_TAG)) {
        CPy_AddTraceback("modTof.py", "run", 493, CPyStatic_globals);
        goto CPyL926;
    }
    cpy_r_r736 = CPyTagged_StealAsObject(cpy_r_r735);
    cpy_r_r737 = PyNumber_TrueDivide(cpy_r_r734, cpy_r_r736);
    CPy_DECREF(cpy_r_r734);
    CPy_DECREF(cpy_r_r736);
    if (unlikely(cpy_r_r737 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 493, CPyStatic_globals);
        goto CPyL927;
    }
    cpy_r_r738 = CPyStatics[92]; /* '.2f' */
    cpy_r_r739 = CPyStatics[93]; /* 'format' */
    cpy_r_r740 = CPyObject_CallMethodObjArgs(cpy_r_r728, cpy_r_r739, cpy_r_r737, cpy_r_r738, NULL);
    CPy_DECREF(cpy_r_r737);
    if (unlikely(cpy_r_r740 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 493, CPyStatic_globals);
        goto CPyL927;
    }
    cpy_r_r741 = PyList_New(2);
    if (unlikely(cpy_r_r741 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 493, CPyStatic_globals);
        goto CPyL928;
    }
    cpy_r_r742 = (CPyPtr)&((PyListObject *)cpy_r_r741)->ob_item;
    cpy_r_r743 = *(CPyPtr *)cpy_r_r742;
    CPy_INCREF(cpy_r_r727);
    *(PyObject * *)cpy_r_r743 = cpy_r_r727;
    cpy_r_r744 = cpy_r_r743 + 8;
    *(PyObject * *)cpy_r_r744 = cpy_r_r740;
    cpy_r_r745 = PyUnicode_Join(cpy_r_r726, cpy_r_r741);
    CPy_DECREF(cpy_r_r741);
    if (unlikely(cpy_r_r745 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 493, CPyStatic_globals);
        goto CPyL927;
    }
    cpy_r_r746 = CPyModule_builtins;
    cpy_r_r747 = CPyStatics[8]; /* 'print' */
    cpy_r_r748 = CPyObject_GetAttr(cpy_r_r746, cpy_r_r747);
    if (unlikely(cpy_r_r748 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 493, CPyStatic_globals);
        goto CPyL929;
    }
    PyObject *cpy_r_r749[5] = {cpy_r_r716, cpy_r_r722, cpy_r_r723, cpy_r_r725, cpy_r_r745};
    cpy_r_r750 = (PyObject **)&cpy_r_r749;
    cpy_r_r751 = _PyObject_Vectorcall(cpy_r_r748, cpy_r_r750, 5, 0);
    CPy_DECREF(cpy_r_r748);
    if (unlikely(cpy_r_r751 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 493, CPyStatic_globals);
        goto CPyL929;
    } else
        goto CPyL930;
CPyL382: ;
    CPy_DECREF(cpy_r_r722);
    CPy_DECREF(cpy_r_r725);
    CPy_DECREF(cpy_r_r745);
    cpy_r_r752 = CPyStatics[96]; /* 'DISTANCE: ' */
    cpy_r_r753 = CPyModule_builtins;
    cpy_r_r754 = CPyStatics[8]; /* 'print' */
    cpy_r_r755 = CPyObject_GetAttr(cpy_r_r753, cpy_r_r754);
    if (unlikely(cpy_r_r755 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 494, CPyStatic_globals);
        goto CPyL931;
    }
    PyObject *cpy_r_r756[1] = {cpy_r_r752};
    cpy_r_r757 = (PyObject **)&cpy_r_r756;
    cpy_r_r758 = _PyObject_Vectorcall(cpy_r_r755, cpy_r_r757, 1, 0);
    CPy_DECREF(cpy_r_r755);
    if (unlikely(cpy_r_r758 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 494, CPyStatic_globals);
        goto CPyL931;
    } else
        goto CPyL932;
CPyL384: ;
    cpy_r_r759 = NULL;
    cpy_r_T1points = cpy_r_r759;
    CPy_XDECREF(cpy_r_T1points);
    cpy_r_r760 = NULL;
    cpy_r_T1times = cpy_r_r760;
    CPy_XDECREF(cpy_r_T1times);
    cpy_r_r761 = NULL;
    cpy_r_T1photons = cpy_r_r761;
    CPy_XDECREF(cpy_r_T1photons);
    cpy_r_r762 = NULL;
    cpy_r_T4points = cpy_r_r762;
    CPy_XDECREF(cpy_r_T4points);
    cpy_r_r763 = NULL;
    cpy_r_T4times = cpy_r_r763;
    CPy_XDECREF(cpy_r_T4times);
    cpy_r_r764 = NULL;
    cpy_r_T4photons = cpy_r_r764;
    CPy_XDECREF(cpy_r_T4photons);
    cpy_r_r765 = CPyModule_gc;
    cpy_r_r766 = CPyStatics[70]; /* 'collect' */
    cpy_r_r767 = CPyObject_GetAttr(cpy_r_r765, cpy_r_r766);
    if (unlikely(cpy_r_r767 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 496, CPyStatic_globals);
        goto CPyL931;
    }
    cpy_r_r768 = _PyObject_Vectorcall(cpy_r_r767, 0, 0, 0);
    CPy_DECREF(cpy_r_r767);
    if (unlikely(cpy_r_r768 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 496, CPyStatic_globals);
        goto CPyL931;
    } else
        goto CPyL933;
CPyL386: ;
    cpy_r_r769 = PyList_New(0);
    if (unlikely(cpy_r_r769 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 499, CPyStatic_globals);
        goto CPyL931;
    }
    cpy_r_signals_channelT1 = cpy_r_r769;
    cpy_r_r770 = PyList_New(0);
    if (unlikely(cpy_r_r770 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 500, CPyStatic_globals);
        goto CPyL934;
    }
    cpy_r_signals_channelT4 = cpy_r_r770;
    cpy_r_r771 = PyList_New(0);
    if (unlikely(cpy_r_r771 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 501, CPyStatic_globals);
        goto CPyL935;
    }
    cpy_r_output_times_channelT1 = cpy_r_r771;
    cpy_r_r772 = PyList_New(0);
    if (unlikely(cpy_r_r772 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 502, CPyStatic_globals);
        goto CPyL936;
    }
    cpy_r_output_times_channelT4 = cpy_r_r772;
    cpy_r_r773 = PyList_New(0);
    if (unlikely(cpy_r_r773 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 503, CPyStatic_globals);
        goto CPyL937;
    }
    cpy_r_signals = cpy_r_r773;
    cpy_r_r774 = PyList_New(0);
    if (unlikely(cpy_r_r774 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 504, CPyStatic_globals);
        goto CPyL938;
    }
    cpy_r_output_times = cpy_r_r774;
    cpy_r_r775 = PyObject_GetIter(cpy_r_T1_input_times);
    CPy_DECREF(cpy_r_T1_input_times);
    if (unlikely(cpy_r_r775 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 505, CPyStatic_globals);
        goto CPyL939;
    }
CPyL393: ;
    cpy_r_r776 = PyIter_Next(cpy_r_r775);
    if (cpy_r_r776 == NULL) goto CPyL940;
    cpy_r_t = cpy_r_r776;
    cpy_r_r777 = CPyStatics[247]; /* 1 */
    cpy_r_r778 = CPyDef_Simulation___photontoElectrons(cpy_r_self, cpy_r_r777);
    if (unlikely(cpy_r_r778 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 506, CPyStatic_globals);
        goto CPyL941;
    }
    cpy_r_pmtSignal_i = cpy_r_r778;
    cpy_r_r779 = ((modTof___SimulationObject *)cpy_r_self)->_pmt_electron_travel_time;
    CPy_INCREF(cpy_r_r779);
    cpy_r_r780 = PyNumber_Add(cpy_r_r779, cpy_r_t);
    CPy_DECREF(cpy_r_r779);
    if (unlikely(cpy_r_r780 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 507, CPyStatic_globals);
        goto CPyL942;
    }
    cpy_r_r781 = CPyStatics[43]; /* 'append' */
    cpy_r_r782 = CPyObject_CallMethodObjArgs(cpy_r_output_times, cpy_r_r781, cpy_r_r780, NULL);
    CPy_DECREF(cpy_r_r780);
    if (unlikely(cpy_r_r782 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 507, CPyStatic_globals);
        goto CPyL942;
    } else
        goto CPyL943;
CPyL397: ;
    cpy_r_r783 = ((modTof___SimulationObject *)cpy_r_self)->_pmt_electron_travel_time;
    CPy_INCREF(cpy_r_r783);
    cpy_r_r784 = PyNumber_Add(cpy_r_r783, cpy_r_t);
    CPy_DECREF(cpy_r_r783);
    CPy_DECREF(cpy_r_t);
    if (unlikely(cpy_r_r784 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 508, CPyStatic_globals);
        goto CPyL944;
    }
    cpy_r_r785 = CPyStatics[43]; /* 'append' */
    cpy_r_r786 = CPyObject_CallMethodObjArgs(cpy_r_output_times_channelT1, cpy_r_r785, cpy_r_r784, NULL);
    CPy_DECREF(cpy_r_r784);
    if (unlikely(cpy_r_r786 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 508, CPyStatic_globals);
        goto CPyL944;
    } else
        goto CPyL945;
CPyL399: ;
    cpy_r_r787 = CPyStatics[43]; /* 'append' */
    cpy_r_r788 = CPyObject_CallMethodObjArgs(cpy_r_signals, cpy_r_r787, cpy_r_pmtSignal_i, NULL);
    if (unlikely(cpy_r_r788 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 509, CPyStatic_globals);
        goto CPyL944;
    } else
        goto CPyL946;
CPyL400: ;
    cpy_r_r789 = CPyStatics[43]; /* 'append' */
    cpy_r_r790 = CPyObject_CallMethodObjArgs(cpy_r_signals_channelT1, cpy_r_r789, cpy_r_pmtSignal_i, NULL);
    CPy_DECREF(cpy_r_pmtSignal_i);
    if (unlikely(cpy_r_r790 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 510, CPyStatic_globals);
        goto CPyL947;
    } else
        goto CPyL948;
CPyL401: ;
    cpy_r_r791 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r791)) {
        CPy_AddTraceback("modTof.py", "run", 505, CPyStatic_globals);
        goto CPyL939;
    }
    cpy_r_r792 = PyObject_GetIter(cpy_r_T4_input_times);
    CPy_DECREF(cpy_r_T4_input_times);
    if (unlikely(cpy_r_r792 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 511, CPyStatic_globals);
        goto CPyL949;
    }
CPyL403: ;
    cpy_r_r793 = PyIter_Next(cpy_r_r792);
    if (cpy_r_r793 == NULL) goto CPyL950;
    cpy_r_t = cpy_r_r793;
    cpy_r_r794 = CPyStatics[247]; /* 1 */
    cpy_r_r795 = CPyDef_Simulation___photontoElectrons(cpy_r_self, cpy_r_r794);
    if (unlikely(cpy_r_r795 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 512, CPyStatic_globals);
        goto CPyL951;
    }
    cpy_r_pmtSignal_i = cpy_r_r795;
    cpy_r_r796 = ((modTof___SimulationObject *)cpy_r_self)->_pmt_electron_travel_time;
    CPy_INCREF(cpy_r_r796);
    cpy_r_r797 = PyNumber_Add(cpy_r_r796, cpy_r_t);
    CPy_DECREF(cpy_r_r796);
    if (unlikely(cpy_r_r797 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 513, CPyStatic_globals);
        goto CPyL952;
    }
    cpy_r_r798 = CPyStatics[43]; /* 'append' */
    cpy_r_r799 = CPyObject_CallMethodObjArgs(cpy_r_output_times, cpy_r_r798, cpy_r_r797, NULL);
    CPy_DECREF(cpy_r_r797);
    if (unlikely(cpy_r_r799 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 513, CPyStatic_globals);
        goto CPyL952;
    } else
        goto CPyL953;
CPyL407: ;
    cpy_r_r800 = ((modTof___SimulationObject *)cpy_r_self)->_pmt_electron_travel_time;
    CPy_INCREF(cpy_r_r800);
    cpy_r_r801 = PyNumber_Add(cpy_r_r800, cpy_r_t);
    CPy_DECREF(cpy_r_r800);
    CPy_DECREF(cpy_r_t);
    if (unlikely(cpy_r_r801 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 514, CPyStatic_globals);
        goto CPyL954;
    }
    cpy_r_r802 = CPyStatics[43]; /* 'append' */
    cpy_r_r803 = CPyObject_CallMethodObjArgs(cpy_r_output_times_channelT4, cpy_r_r802, cpy_r_r801, NULL);
    CPy_DECREF(cpy_r_r801);
    if (unlikely(cpy_r_r803 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 514, CPyStatic_globals);
        goto CPyL954;
    } else
        goto CPyL955;
CPyL409: ;
    cpy_r_r804 = CPyStatics[43]; /* 'append' */
    cpy_r_r805 = CPyObject_CallMethodObjArgs(cpy_r_signals, cpy_r_r804, cpy_r_pmtSignal_i, NULL);
    if (unlikely(cpy_r_r805 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 515, CPyStatic_globals);
        goto CPyL954;
    } else
        goto CPyL956;
CPyL410: ;
    cpy_r_r806 = CPyStatics[43]; /* 'append' */
    cpy_r_r807 = CPyObject_CallMethodObjArgs(cpy_r_signals_channelT4, cpy_r_r806, cpy_r_pmtSignal_i, NULL);
    CPy_DECREF(cpy_r_pmtSignal_i);
    if (unlikely(cpy_r_r807 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 516, CPyStatic_globals);
        goto CPyL957;
    } else
        goto CPyL958;
CPyL411: ;
    cpy_r_r808 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r808)) {
        CPy_AddTraceback("modTof.py", "run", 511, CPyStatic_globals);
        goto CPyL949;
    }
    cpy_r_r809 = CPyModule_numpy;
    cpy_r_r810 = CPyStatics[32]; /* 'array' */
    cpy_r_r811 = CPyObject_GetAttr(cpy_r_r809, cpy_r_r810);
    if (unlikely(cpy_r_r811 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 519, CPyStatic_globals);
        goto CPyL949;
    }
    PyObject *cpy_r_r812[1] = {cpy_r_signals};
    cpy_r_r813 = (PyObject **)&cpy_r_r812;
    cpy_r_r814 = _PyObject_Vectorcall(cpy_r_r811, cpy_r_r813, 1, 0);
    CPy_DECREF(cpy_r_r811);
    if (unlikely(cpy_r_r814 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 519, CPyStatic_globals);
        goto CPyL949;
    }
    CPy_DECREF(cpy_r_signals);
    cpy_r_r815 = ((modTof___SimulationObject *)cpy_r_self)->_q;
    CPy_INCREF(cpy_r_r815);
    cpy_r_r816 = PyNumber_Multiply(cpy_r_r814, cpy_r_r815);
    CPy_DECREF(cpy_r_r814);
    CPy_DECREF(cpy_r_r815);
    if (unlikely(cpy_r_r816 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 519, CPyStatic_globals);
        goto CPyL959;
    }
    cpy_r_r817 = PyFloat_FromDouble(1e-12);
    cpy_r_r818 = PyNumber_TrueDivide(cpy_r_r816, cpy_r_r817);
    CPy_DECREF(cpy_r_r816);
    CPy_DECREF(cpy_r_r817);
    if (unlikely(cpy_r_r818 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 519, CPyStatic_globals);
        goto CPyL959;
    }
    cpy_r_r819 = ((modTof___SimulationObject *)cpy_r_self)->_artificial_gain;
    CPy_INCREF(cpy_r_r819);
    cpy_r_r820 = PyNumber_Multiply(cpy_r_r818, cpy_r_r819);
    CPy_DECREF(cpy_r_r818);
    CPy_DECREF(cpy_r_r819);
    if (unlikely(cpy_r_r820 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 519, CPyStatic_globals);
        goto CPyL959;
    }
    if (((modTof___SimulationObject *)cpy_r_self)->_signals != NULL) {
        CPy_DECREF(((modTof___SimulationObject *)cpy_r_self)->_signals);
    }
    ((modTof___SimulationObject *)cpy_r_self)->_signals = cpy_r_r820;
    cpy_r_r821 = 1;
    if (unlikely(!cpy_r_r821)) {
        CPy_AddTraceback("modTof.py", "run", 519, CPyStatic_globals);
        goto CPyL959;
    }
    cpy_r_r822 = CPyModule_numpy;
    cpy_r_r823 = CPyStatics[32]; /* 'array' */
    cpy_r_r824 = CPyObject_GetAttr(cpy_r_r822, cpy_r_r823);
    if (unlikely(cpy_r_r824 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 520, CPyStatic_globals);
        goto CPyL959;
    }
    PyObject *cpy_r_r825[1] = {cpy_r_output_times};
    cpy_r_r826 = (PyObject **)&cpy_r_r825;
    cpy_r_r827 = _PyObject_Vectorcall(cpy_r_r824, cpy_r_r826, 1, 0);
    CPy_DECREF(cpy_r_r824);
    if (unlikely(cpy_r_r827 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 520, CPyStatic_globals);
        goto CPyL959;
    }
    CPy_DECREF(cpy_r_output_times);
    if (((modTof___SimulationObject *)cpy_r_self)->_output_times != NULL) {
        CPy_DECREF(((modTof___SimulationObject *)cpy_r_self)->_output_times);
    }
    ((modTof___SimulationObject *)cpy_r_self)->_output_times = cpy_r_r827;
    cpy_r_r828 = 1;
    if (unlikely(!cpy_r_r828)) {
        CPy_AddTraceback("modTof.py", "run", 520, CPyStatic_globals);
        goto CPyL960;
    }
    cpy_r_r829 = CPyModule_numpy;
    cpy_r_r830 = CPyStatics[32]; /* 'array' */
    cpy_r_r831 = CPyObject_GetAttr(cpy_r_r829, cpy_r_r830);
    if (unlikely(cpy_r_r831 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 521, CPyStatic_globals);
        goto CPyL960;
    }
    PyObject *cpy_r_r832[1] = {cpy_r_signals_channelT1};
    cpy_r_r833 = (PyObject **)&cpy_r_r832;
    cpy_r_r834 = _PyObject_Vectorcall(cpy_r_r831, cpy_r_r833, 1, 0);
    CPy_DECREF(cpy_r_r831);
    if (unlikely(cpy_r_r834 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 521, CPyStatic_globals);
        goto CPyL960;
    }
    CPy_DECREF(cpy_r_signals_channelT1);
    cpy_r_r835 = ((modTof___SimulationObject *)cpy_r_self)->_q;
    CPy_INCREF(cpy_r_r835);
    cpy_r_r836 = PyNumber_Multiply(cpy_r_r834, cpy_r_r835);
    CPy_DECREF(cpy_r_r834);
    CPy_DECREF(cpy_r_r835);
    if (unlikely(cpy_r_r836 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 521, CPyStatic_globals);
        goto CPyL961;
    }
    cpy_r_r837 = PyFloat_FromDouble(1e-12);
    cpy_r_r838 = PyNumber_TrueDivide(cpy_r_r836, cpy_r_r837);
    CPy_DECREF(cpy_r_r836);
    CPy_DECREF(cpy_r_r837);
    if (unlikely(cpy_r_r838 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 521, CPyStatic_globals);
        goto CPyL961;
    }
    cpy_r_r839 = ((modTof___SimulationObject *)cpy_r_self)->_artificial_gain;
    CPy_INCREF(cpy_r_r839);
    cpy_r_r840 = PyNumber_Multiply(cpy_r_r838, cpy_r_r839);
    CPy_DECREF(cpy_r_r838);
    CPy_DECREF(cpy_r_r839);
    if (unlikely(cpy_r_r840 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 521, CPyStatic_globals);
        goto CPyL961;
    }
    if (((modTof___SimulationObject *)cpy_r_self)->_signals_channelT1 != NULL) {
        CPy_DECREF(((modTof___SimulationObject *)cpy_r_self)->_signals_channelT1);
    }
    ((modTof___SimulationObject *)cpy_r_self)->_signals_channelT1 = cpy_r_r840;
    cpy_r_r841 = 1;
    if (unlikely(!cpy_r_r841)) {
        CPy_AddTraceback("modTof.py", "run", 521, CPyStatic_globals);
        goto CPyL961;
    }
    cpy_r_r842 = CPyModule_numpy;
    cpy_r_r843 = CPyStatics[32]; /* 'array' */
    cpy_r_r844 = CPyObject_GetAttr(cpy_r_r842, cpy_r_r843);
    if (unlikely(cpy_r_r844 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 522, CPyStatic_globals);
        goto CPyL961;
    }
    PyObject *cpy_r_r845[1] = {cpy_r_signals_channelT4};
    cpy_r_r846 = (PyObject **)&cpy_r_r845;
    cpy_r_r847 = _PyObject_Vectorcall(cpy_r_r844, cpy_r_r846, 1, 0);
    CPy_DECREF(cpy_r_r844);
    if (unlikely(cpy_r_r847 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 522, CPyStatic_globals);
        goto CPyL961;
    }
    CPy_DECREF(cpy_r_signals_channelT4);
    cpy_r_r848 = ((modTof___SimulationObject *)cpy_r_self)->_q;
    CPy_INCREF(cpy_r_r848);
    cpy_r_r849 = PyNumber_Multiply(cpy_r_r847, cpy_r_r848);
    CPy_DECREF(cpy_r_r847);
    CPy_DECREF(cpy_r_r848);
    if (unlikely(cpy_r_r849 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 522, CPyStatic_globals);
        goto CPyL962;
    }
    cpy_r_r850 = PyFloat_FromDouble(1e-12);
    cpy_r_r851 = PyNumber_TrueDivide(cpy_r_r849, cpy_r_r850);
    CPy_DECREF(cpy_r_r849);
    CPy_DECREF(cpy_r_r850);
    if (unlikely(cpy_r_r851 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 522, CPyStatic_globals);
        goto CPyL962;
    }
    cpy_r_r852 = ((modTof___SimulationObject *)cpy_r_self)->_artificial_gain;
    CPy_INCREF(cpy_r_r852);
    cpy_r_r853 = PyNumber_Multiply(cpy_r_r851, cpy_r_r852);
    CPy_DECREF(cpy_r_r851);
    CPy_DECREF(cpy_r_r852);
    if (unlikely(cpy_r_r853 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 522, CPyStatic_globals);
        goto CPyL962;
    }
    cpy_r_r854 = PyFloat_FromDouble(0.6);
    cpy_r_r855 = PyNumber_Multiply(cpy_r_r853, cpy_r_r854);
    CPy_DECREF(cpy_r_r853);
    CPy_DECREF(cpy_r_r854);
    if (unlikely(cpy_r_r855 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 522, CPyStatic_globals);
        goto CPyL962;
    }
    if (((modTof___SimulationObject *)cpy_r_self)->_signals_channelT4 != NULL) {
        CPy_DECREF(((modTof___SimulationObject *)cpy_r_self)->_signals_channelT4);
    }
    ((modTof___SimulationObject *)cpy_r_self)->_signals_channelT4 = cpy_r_r855;
    cpy_r_r856 = 1;
    if (unlikely(!cpy_r_r856)) {
        CPy_AddTraceback("modTof.py", "run", 522, CPyStatic_globals);
        goto CPyL962;
    }
    cpy_r_r857 = CPyModule_numpy;
    cpy_r_r858 = CPyStatics[32]; /* 'array' */
    cpy_r_r859 = CPyObject_GetAttr(cpy_r_r857, cpy_r_r858);
    if (unlikely(cpy_r_r859 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 523, CPyStatic_globals);
        goto CPyL962;
    }
    PyObject *cpy_r_r860[1] = {cpy_r_output_times_channelT1};
    cpy_r_r861 = (PyObject **)&cpy_r_r860;
    cpy_r_r862 = _PyObject_Vectorcall(cpy_r_r859, cpy_r_r861, 1, 0);
    CPy_DECREF(cpy_r_r859);
    if (unlikely(cpy_r_r862 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 523, CPyStatic_globals);
        goto CPyL962;
    }
    CPy_DECREF(cpy_r_output_times_channelT1);
    if (((modTof___SimulationObject *)cpy_r_self)->_output_times_channelT1 != NULL) {
        CPy_DECREF(((modTof___SimulationObject *)cpy_r_self)->_output_times_channelT1);
    }
    ((modTof___SimulationObject *)cpy_r_self)->_output_times_channelT1 = cpy_r_r862;
    cpy_r_r863 = 1;
    if (unlikely(!cpy_r_r863)) {
        CPy_AddTraceback("modTof.py", "run", 523, CPyStatic_globals);
        goto CPyL963;
    }
    cpy_r_r864 = CPyModule_numpy;
    cpy_r_r865 = CPyStatics[32]; /* 'array' */
    cpy_r_r866 = CPyObject_GetAttr(cpy_r_r864, cpy_r_r865);
    if (unlikely(cpy_r_r866 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 524, CPyStatic_globals);
        goto CPyL963;
    }
    PyObject *cpy_r_r867[1] = {cpy_r_output_times_channelT4};
    cpy_r_r868 = (PyObject **)&cpy_r_r867;
    cpy_r_r869 = _PyObject_Vectorcall(cpy_r_r866, cpy_r_r868, 1, 0);
    CPy_DECREF(cpy_r_r866);
    if (unlikely(cpy_r_r869 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 524, CPyStatic_globals);
        goto CPyL963;
    }
    CPy_DECREF(cpy_r_output_times_channelT4);
    if (((modTof___SimulationObject *)cpy_r_self)->_output_times_channelT4 != NULL) {
        CPy_DECREF(((modTof___SimulationObject *)cpy_r_self)->_output_times_channelT4);
    }
    ((modTof___SimulationObject *)cpy_r_self)->_output_times_channelT4 = cpy_r_r869;
    cpy_r_r870 = 1;
    if (unlikely(!cpy_r_r870)) {
        CPy_AddTraceback("modTof.py", "run", 524, CPyStatic_globals);
        goto CPyL720;
    }
    cpy_r_r871 = CPyStatics[268]; /* ('norm',) */
    cpy_r_r872 = CPyStatics[97]; /* 'scipy.stats' */
    cpy_r_r873 = CPyStatic_globals;
    cpy_r_r874 = CPyImport_ImportFromMany(cpy_r_r872, cpy_r_r871, cpy_r_r871, cpy_r_r873);
    if (unlikely(cpy_r_r874 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 528, CPyStatic_globals);
        goto CPyL720;
    }
    CPyModule_scipy___stats = cpy_r_r874;
    CPy_INCREF(CPyModule_scipy___stats);
    CPy_DECREF(cpy_r_r874);
    cpy_r_r875 = CPyStatics[98]; /* 'extra_data_only' */
    cpy_r_r876 = 0 ? Py_True : Py_False;
    cpy_r_r877 = CPyDict_Get(cpy_r_kwargs, cpy_r_r875, cpy_r_r876);
    if (unlikely(cpy_r_r877 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 529, CPyStatic_globals);
        goto CPyL720;
    }
    cpy_r_output_extra = cpy_r_r877;
    cpy_r_r878 = CPyStatics[99]; /* 'output_both' */
    cpy_r_r879 = 0 ? Py_True : Py_False;
    cpy_r_r880 = CPyDict_Get(cpy_r_kwargs, cpy_r_r878, cpy_r_r879);
    if (unlikely(cpy_r_r880 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 530, CPyStatic_globals);
        goto CPyL964;
    }
    cpy_r_output_both = cpy_r_r880;
    cpy_r_r881 = PyObject_IsTrue(cpy_r_output_extra);
    CPy_DECREF(cpy_r_output_extra);
    cpy_r_r882 = cpy_r_r881 >= 0;
    if (unlikely(!cpy_r_r882)) {
        CPy_AddTraceback("modTof.py", "run", 529, CPyStatic_globals);
        goto CPyL965;
    }
    cpy_r_r883 = cpy_r_r881;
    if (cpy_r_r883) goto CPyL447;
    cpy_r_r884 = PyObject_IsTrue(cpy_r_output_both);
    cpy_r_r885 = cpy_r_r884 >= 0;
    if (unlikely(!cpy_r_r885)) {
        CPy_AddTraceback("modTof.py", "run", 530, CPyStatic_globals);
        goto CPyL965;
    }
    cpy_r_r886 = cpy_r_r884;
    if (!cpy_r_r886) goto CPyL966;
CPyL447: ;
    cpy_r_r887 = CPyStatics[100]; /* 'Exporting Extra Data...' */
    cpy_r_r888 = CPyModule_builtins;
    cpy_r_r889 = CPyStatics[8]; /* 'print' */
    cpy_r_r890 = CPyObject_GetAttr(cpy_r_r888, cpy_r_r889);
    if (unlikely(cpy_r_r890 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 533, CPyStatic_globals);
        goto CPyL965;
    }
    PyObject *cpy_r_r891[1] = {cpy_r_r887};
    cpy_r_r892 = (PyObject **)&cpy_r_r891;
    cpy_r_r893 = _PyObject_Vectorcall(cpy_r_r890, cpy_r_r892, 1, 0);
    CPy_DECREF(cpy_r_r890);
    if (unlikely(cpy_r_r893 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 533, CPyStatic_globals);
        goto CPyL965;
    } else
        goto CPyL967;
CPyL449: ;
    cpy_r_r894 = CPyStatics[101]; /* 'T1_part_ids' */
    cpy_r_r895 = ((modTof___SimulationObject *)cpy_r_self)->_T1_part_ids;
    if (unlikely(cpy_r_r895 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "T1_part_ids", 534, CPyStatic_globals);
        goto CPyL965;
    }
    CPy_INCREF(cpy_r_r895);
CPyL450: ;
    cpy_r_r896 = CPyStatics[102]; /* 'time' */
    cpy_r_r897 = ((modTof___SimulationObject *)cpy_r_self)->_output_times_channelT1;
    if (unlikely(cpy_r_r897 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "output_times_channelT1", 534, CPyStatic_globals);
        goto CPyL968;
    }
    CPy_INCREF(cpy_r_r897);
CPyL451: ;
    cpy_r_r898 = CPyStatics[103]; /* 'T1_prop_dist' */
    cpy_r_r899 = ((modTof___SimulationObject *)cpy_r_self)->_T1_prop_dist;
    if (unlikely(cpy_r_r899 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "T1_prop_dist", 534, CPyStatic_globals);
        goto CPyL969;
    }
    CPy_INCREF(cpy_r_r899);
CPyL452: ;
    cpy_r_r900 = CPyStatics[104]; /* 'T1_endpoint_dist' */
    cpy_r_r901 = ((modTof___SimulationObject *)cpy_r_self)->_T1_endpoint_dist;
    if (unlikely(cpy_r_r901 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "T1_endpoint_dist", 534, CPyStatic_globals);
        goto CPyL970;
    }
    CPy_INCREF(cpy_r_r901);
CPyL453: ;
    cpy_r_r902 = CPyStatics[105]; /* 'T1_prop_times' */
    cpy_r_r903 = ((modTof___SimulationObject *)cpy_r_self)->_T1_prop_times;
    if (unlikely(cpy_r_r903 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "T1_prop_times", 534, CPyStatic_globals);
        goto CPyL971;
    }
    CPy_INCREF(cpy_r_r903);
CPyL454: ;
    cpy_r_r904 = CPyStatics[106]; /* 'T1_interactions' */
    cpy_r_r905 = ((modTof___SimulationObject *)cpy_r_self)->_T1_interactions;
    if (unlikely(cpy_r_r905 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "T1_interactions", 534, CPyStatic_globals);
        goto CPyL972;
    }
    CPy_INCREF(cpy_r_r905);
CPyL455: ;
    cpy_r_r906 = CPyDict_Build(6, cpy_r_r894, cpy_r_r895, cpy_r_r896, cpy_r_r897, cpy_r_r898, cpy_r_r899, cpy_r_r900, cpy_r_r901, cpy_r_r902, cpy_r_r903, cpy_r_r904, cpy_r_r905);
    CPy_DECREF(cpy_r_r895);
    CPy_DECREF(cpy_r_r897);
    CPy_DECREF(cpy_r_r899);
    CPy_DECREF(cpy_r_r901);
    CPy_DECREF(cpy_r_r903);
    CPy_DECREF(cpy_r_r905);
    if (unlikely(cpy_r_r906 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 534, CPyStatic_globals);
        goto CPyL965;
    }
    cpy_r_r907 = CPyModule_pandas;
    cpy_r_r908 = CPyStatics[107]; /* 'DataFrame' */
    cpy_r_r909 = CPyObject_GetAttr(cpy_r_r907, cpy_r_r908);
    if (unlikely(cpy_r_r909 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 534, CPyStatic_globals);
        goto CPyL973;
    }
    PyObject *cpy_r_r910[1] = {cpy_r_r906};
    cpy_r_r911 = (PyObject **)&cpy_r_r910;
    cpy_r_r912 = _PyObject_Vectorcall(cpy_r_r909, cpy_r_r911, 1, 0);
    CPy_DECREF(cpy_r_r909);
    if (unlikely(cpy_r_r912 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 534, CPyStatic_globals);
        goto CPyL973;
    }
    CPy_DECREF(cpy_r_r906);
    cpy_r_dft1 = cpy_r_r912;
    cpy_r_r913 = CPyStatics[108]; /* 'T4_part_ids' */
    cpy_r_r914 = ((modTof___SimulationObject *)cpy_r_self)->_T4_part_ids;
    if (unlikely(cpy_r_r914 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "T4_part_ids", 535, CPyStatic_globals);
        goto CPyL974;
    }
    CPy_INCREF(cpy_r_r914);
CPyL459: ;
    cpy_r_r915 = CPyStatics[102]; /* 'time' */
    cpy_r_r916 = ((modTof___SimulationObject *)cpy_r_self)->_output_times_channelT4;
    if (unlikely(cpy_r_r916 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "output_times_channelT4", 535, CPyStatic_globals);
        goto CPyL975;
    }
    CPy_INCREF(cpy_r_r916);
CPyL460: ;
    cpy_r_r917 = CPyStatics[109]; /* 'T4_prop_dist' */
    cpy_r_r918 = ((modTof___SimulationObject *)cpy_r_self)->_T4_prop_dist;
    if (unlikely(cpy_r_r918 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "T4_prop_dist", 535, CPyStatic_globals);
        goto CPyL976;
    }
    CPy_INCREF(cpy_r_r918);
CPyL461: ;
    cpy_r_r919 = CPyStatics[110]; /* 'T4_endpoint_dist' */
    cpy_r_r920 = ((modTof___SimulationObject *)cpy_r_self)->_T4_endpoint_dist;
    if (unlikely(cpy_r_r920 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "T4_endpoint_dist", 535, CPyStatic_globals);
        goto CPyL977;
    }
    CPy_INCREF(cpy_r_r920);
CPyL462: ;
    cpy_r_r921 = CPyStatics[111]; /* 'T4_prop_times' */
    cpy_r_r922 = ((modTof___SimulationObject *)cpy_r_self)->_T4_prop_times;
    if (unlikely(cpy_r_r922 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "T4_prop_times", 535, CPyStatic_globals);
        goto CPyL978;
    }
    CPy_INCREF(cpy_r_r922);
CPyL463: ;
    cpy_r_r923 = CPyStatics[112]; /* 'T4_interactions' */
    cpy_r_r924 = ((modTof___SimulationObject *)cpy_r_self)->_T4_interactions;
    if (unlikely(cpy_r_r924 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "T4_interactions", 535, CPyStatic_globals);
        goto CPyL979;
    }
    CPy_INCREF(cpy_r_r924);
CPyL464: ;
    cpy_r_r925 = CPyDict_Build(6, cpy_r_r913, cpy_r_r914, cpy_r_r915, cpy_r_r916, cpy_r_r917, cpy_r_r918, cpy_r_r919, cpy_r_r920, cpy_r_r921, cpy_r_r922, cpy_r_r923, cpy_r_r924);
    CPy_DECREF(cpy_r_r914);
    CPy_DECREF(cpy_r_r916);
    CPy_DECREF(cpy_r_r918);
    CPy_DECREF(cpy_r_r920);
    CPy_DECREF(cpy_r_r922);
    CPy_DECREF(cpy_r_r924);
    if (unlikely(cpy_r_r925 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 535, CPyStatic_globals);
        goto CPyL974;
    }
    cpy_r_r926 = CPyModule_pandas;
    cpy_r_r927 = CPyStatics[107]; /* 'DataFrame' */
    cpy_r_r928 = CPyObject_GetAttr(cpy_r_r926, cpy_r_r927);
    if (unlikely(cpy_r_r928 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 535, CPyStatic_globals);
        goto CPyL980;
    }
    PyObject *cpy_r_r929[1] = {cpy_r_r925};
    cpy_r_r930 = (PyObject **)&cpy_r_r929;
    cpy_r_r931 = _PyObject_Vectorcall(cpy_r_r928, cpy_r_r930, 1, 0);
    CPy_DECREF(cpy_r_r928);
    if (unlikely(cpy_r_r931 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 535, CPyStatic_globals);
        goto CPyL980;
    }
    CPy_DECREF(cpy_r_r925);
    cpy_r_dft4 = cpy_r_r931;
    cpy_r_r932 = CPyStatics[113]; /* 'monte_carlo_extradata' */
    cpy_r_r933 = ((modTof___SimulationObject *)cpy_r_self)->_num_particles;
    CPy_INCREF(cpy_r_r933);
    cpy_r_r934 = PyObject_Str(cpy_r_r933);
    CPy_DECREF(cpy_r_r933);
    if (unlikely(cpy_r_r934 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 536, CPyStatic_globals);
        goto CPyL981;
    }
    cpy_r_r935 = PyUnicode_Concat(cpy_r_r932, cpy_r_r934);
    CPy_DECREF(cpy_r_r934);
    if (unlikely(cpy_r_r935 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 536, CPyStatic_globals);
        goto CPyL981;
    }
    cpy_r_r936 = CPyStatics[114]; /* 'chT1_' */
    cpy_r_r937 = PyUnicode_Concat(cpy_r_r935, cpy_r_r936);
    CPy_DECREF(cpy_r_r935);
    if (unlikely(cpy_r_r937 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 536, CPyStatic_globals);
        goto CPyL981;
    }
    cpy_r_r938 = CPyStatic_globals;
    cpy_r_r939 = CPyStatics[115]; /* 'datetime' */
    cpy_r_r940 = CPyDict_GetItem(cpy_r_r938, cpy_r_r939);
    if (unlikely(cpy_r_r940 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 536, CPyStatic_globals);
        goto CPyL982;
    }
    cpy_r_r941 = CPyStatics[116]; /* 'now' */
    cpy_r_r942 = CPyObject_CallMethodObjArgs(cpy_r_r940, cpy_r_r941, NULL);
    CPy_DECREF(cpy_r_r940);
    if (unlikely(cpy_r_r942 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 536, CPyStatic_globals);
        goto CPyL982;
    }
    cpy_r_r943 = CPyStatics[117]; /* '%m_%d_%Y' */
    cpy_r_r944 = CPyStatics[118]; /* 'strftime' */
    cpy_r_r945 = CPyObject_CallMethodObjArgs(cpy_r_r942, cpy_r_r944, cpy_r_r943, NULL);
    CPy_DECREF(cpy_r_r942);
    if (unlikely(cpy_r_r945 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 536, CPyStatic_globals);
        goto CPyL982;
    }
    cpy_r_r946 = PyObject_Str(cpy_r_r945);
    CPy_DECREF(cpy_r_r945);
    if (unlikely(cpy_r_r946 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 536, CPyStatic_globals);
        goto CPyL982;
    }
    cpy_r_r947 = PyUnicode_Concat(cpy_r_r937, cpy_r_r946);
    CPy_DECREF(cpy_r_r937);
    CPy_DECREF(cpy_r_r946);
    if (unlikely(cpy_r_r947 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 536, CPyStatic_globals);
        goto CPyL981;
    }
    cpy_r_r948 = CPyStatics[119]; /* '.txt' */
    cpy_r_r949 = PyUnicode_Concat(cpy_r_r947, cpy_r_r948);
    CPy_DECREF(cpy_r_r947);
    if (unlikely(cpy_r_r949 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 536, CPyStatic_globals);
        goto CPyL981;
    }
    cpy_r_r950 = CPyStatics[120]; /* 'to_csv' */
    cpy_r_r951 = CPyObject_CallMethodObjArgs(cpy_r_dft1, cpy_r_r950, cpy_r_r949, NULL);
    CPy_DECREF(cpy_r_dft1);
    CPy_DECREF(cpy_r_r949);
    if (unlikely(cpy_r_r951 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 536, CPyStatic_globals);
        goto CPyL983;
    } else
        goto CPyL984;
CPyL477: ;
    cpy_r_r952 = CPyStatics[113]; /* 'monte_carlo_extradata' */
    cpy_r_r953 = ((modTof___SimulationObject *)cpy_r_self)->_num_particles;
    CPy_INCREF(cpy_r_r953);
    cpy_r_r954 = PyObject_Str(cpy_r_r953);
    CPy_DECREF(cpy_r_r953);
    if (unlikely(cpy_r_r954 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 537, CPyStatic_globals);
        goto CPyL983;
    }
    cpy_r_r955 = PyUnicode_Concat(cpy_r_r952, cpy_r_r954);
    CPy_DECREF(cpy_r_r954);
    if (unlikely(cpy_r_r955 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 537, CPyStatic_globals);
        goto CPyL983;
    }
    cpy_r_r956 = CPyStatics[121]; /* 'chT4_' */
    cpy_r_r957 = PyUnicode_Concat(cpy_r_r955, cpy_r_r956);
    CPy_DECREF(cpy_r_r955);
    if (unlikely(cpy_r_r957 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 537, CPyStatic_globals);
        goto CPyL983;
    }
    cpy_r_r958 = CPyStatic_globals;
    cpy_r_r959 = CPyStatics[115]; /* 'datetime' */
    cpy_r_r960 = CPyDict_GetItem(cpy_r_r958, cpy_r_r959);
    if (unlikely(cpy_r_r960 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 537, CPyStatic_globals);
        goto CPyL985;
    }
    cpy_r_r961 = CPyStatics[116]; /* 'now' */
    cpy_r_r962 = CPyObject_CallMethodObjArgs(cpy_r_r960, cpy_r_r961, NULL);
    CPy_DECREF(cpy_r_r960);
    if (unlikely(cpy_r_r962 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 537, CPyStatic_globals);
        goto CPyL985;
    }
    cpy_r_r963 = CPyStatics[117]; /* '%m_%d_%Y' */
    cpy_r_r964 = CPyStatics[118]; /* 'strftime' */
    cpy_r_r965 = CPyObject_CallMethodObjArgs(cpy_r_r962, cpy_r_r964, cpy_r_r963, NULL);
    CPy_DECREF(cpy_r_r962);
    if (unlikely(cpy_r_r965 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 537, CPyStatic_globals);
        goto CPyL985;
    }
    cpy_r_r966 = PyObject_Str(cpy_r_r965);
    CPy_DECREF(cpy_r_r965);
    if (unlikely(cpy_r_r966 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 537, CPyStatic_globals);
        goto CPyL985;
    }
    cpy_r_r967 = PyUnicode_Concat(cpy_r_r957, cpy_r_r966);
    CPy_DECREF(cpy_r_r957);
    CPy_DECREF(cpy_r_r966);
    if (unlikely(cpy_r_r967 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 537, CPyStatic_globals);
        goto CPyL983;
    }
    cpy_r_r968 = CPyStatics[119]; /* '.txt' */
    cpy_r_r969 = PyUnicode_Concat(cpy_r_r967, cpy_r_r968);
    CPy_DECREF(cpy_r_r967);
    if (unlikely(cpy_r_r969 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 537, CPyStatic_globals);
        goto CPyL983;
    }
    cpy_r_r970 = CPyStatics[120]; /* 'to_csv' */
    cpy_r_r971 = CPyObject_CallMethodObjArgs(cpy_r_dft4, cpy_r_r970, cpy_r_r969, NULL);
    CPy_DECREF(cpy_r_dft4);
    CPy_DECREF(cpy_r_r969);
    if (unlikely(cpy_r_r971 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 537, CPyStatic_globals);
        goto CPyL965;
    } else
        goto CPyL986;
CPyL487: ;
    cpy_r_r972 = PyObject_IsTrue(cpy_r_output_both);
    CPy_DECREF(cpy_r_output_both);
    cpy_r_r973 = cpy_r_r972 >= 0;
    if (unlikely(!cpy_r_r973)) {
        CPy_AddTraceback("modTof.py", "run", 530, CPyStatic_globals);
        goto CPyL720;
    }
    cpy_r_r974 = cpy_r_r972;
    if (cpy_r_r974) goto CPyL490;
    cpy_r_r975 = Py_None;
    CPy_INCREF(cpy_r_r975);
    return cpy_r_r975;
CPyL490: ;
    cpy_r_r976 = CPyStatics[122]; /* 'Exporing to 2 channels...' */
    cpy_r_r977 = CPyModule_builtins;
    cpy_r_r978 = CPyStatics[8]; /* 'print' */
    cpy_r_r979 = CPyObject_GetAttr(cpy_r_r977, cpy_r_r978);
    if (unlikely(cpy_r_r979 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 540, CPyStatic_globals);
        goto CPyL720;
    }
    PyObject *cpy_r_r980[1] = {cpy_r_r976};
    cpy_r_r981 = (PyObject **)&cpy_r_r980;
    cpy_r_r982 = _PyObject_Vectorcall(cpy_r_r979, cpy_r_r981, 1, 0);
    CPy_DECREF(cpy_r_r979);
    if (unlikely(cpy_r_r982 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 540, CPyStatic_globals);
        goto CPyL720;
    } else
        goto CPyL987;
CPyL492: ;
    cpy_r_r983 = ((modTof___SimulationObject *)cpy_r_self)->_output_times_channelT1;
    if (unlikely(cpy_r_r983 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "output_times_channelT1", 542, CPyStatic_globals);
        goto CPyL720;
    }
    CPy_INCREF(cpy_r_r983);
CPyL493: ;
    cpy_r_r984 = ((modTof___SimulationObject *)cpy_r_self)->_output_times_channelT4;
    if (unlikely(cpy_r_r984 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "output_times_channelT4", 542, CPyStatic_globals);
        goto CPyL988;
    }
    CPy_INCREF(cpy_r_r984);
CPyL494: ;
    cpy_r_r985 = PyList_New(2);
    if (unlikely(cpy_r_r985 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 542, CPyStatic_globals);
        goto CPyL989;
    }
    cpy_r_r986 = (CPyPtr)&((PyListObject *)cpy_r_r985)->ob_item;
    cpy_r_r987 = *(CPyPtr *)cpy_r_r986;
    *(PyObject * *)cpy_r_r987 = cpy_r_r983;
    cpy_r_r988 = cpy_r_r987 + 8;
    *(PyObject * *)cpy_r_r988 = cpy_r_r984;
    cpy_r_r989 = 0;
    cpy_r_r990 = ((modTof___SimulationObject *)cpy_r_self)->_signals_channelT1;
    if (unlikely(cpy_r_r990 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "signals_channelT1", 542, CPyStatic_globals);
        goto CPyL990;
    }
    CPy_INCREF(cpy_r_r990);
CPyL496: ;
    cpy_r_r991 = ((modTof___SimulationObject *)cpy_r_self)->_signals_channelT4;
    if (unlikely(cpy_r_r991 == NULL)) {
        CPy_AttributeError("modTof.py", "run", "Simulation", "signals_channelT4", 542, CPyStatic_globals);
        goto CPyL991;
    }
    CPy_INCREF(cpy_r_r991);
CPyL497: ;
    cpy_r_r992 = PyList_New(2);
    if (unlikely(cpy_r_r992 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 542, CPyStatic_globals);
        goto CPyL992;
    }
    cpy_r_r993 = (CPyPtr)&((PyListObject *)cpy_r_r992)->ob_item;
    cpy_r_r994 = *(CPyPtr *)cpy_r_r993;
    *(PyObject * *)cpy_r_r994 = cpy_r_r990;
    cpy_r_r995 = cpy_r_r994 + 8;
    *(PyObject * *)cpy_r_r995 = cpy_r_r991;
    cpy_r_r996 = 0;
    cpy_r_r997 = PyList_New(2);
    if (unlikely(cpy_r_r997 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 542, CPyStatic_globals);
        goto CPyL993;
    }
    cpy_r_r998 = CPyStatics[247]; /* 1 */
    cpy_r_r999 = CPyStatics[248]; /* 4 */
    cpy_r_r1000 = (CPyPtr)&((PyListObject *)cpy_r_r997)->ob_item;
    cpy_r_r1001 = *(CPyPtr *)cpy_r_r1000;
    CPy_INCREF(cpy_r_r998);
    *(PyObject * *)cpy_r_r1001 = cpy_r_r998;
    cpy_r_r1002 = cpy_r_r1001 + 8;
    CPy_INCREF(cpy_r_r999);
    *(PyObject * *)cpy_r_r1002 = cpy_r_r999;
    cpy_r_r1003 = 0;
CPyL500: ;
    cpy_r_r1004 = (CPyPtr)&((PyVarObject *)cpy_r_r985)->ob_size;
    cpy_r_r1005 = *(int64_t *)cpy_r_r1004;
    cpy_r_r1006 = cpy_r_r1005 << 1;
    cpy_r_r1007 = (Py_ssize_t)cpy_r_r989 < (Py_ssize_t)cpy_r_r1006;
    if (!cpy_r_r1007) goto CPyL994;
    cpy_r_r1008 = (CPyPtr)&((PyVarObject *)cpy_r_r992)->ob_size;
    cpy_r_r1009 = *(int64_t *)cpy_r_r1008;
    cpy_r_r1010 = cpy_r_r1009 << 1;
    cpy_r_r1011 = (Py_ssize_t)cpy_r_r996 < (Py_ssize_t)cpy_r_r1010;
    if (!cpy_r_r1011) goto CPyL994;
    cpy_r_r1012 = (CPyPtr)&((PyVarObject *)cpy_r_r997)->ob_size;
    cpy_r_r1013 = *(int64_t *)cpy_r_r1012;
    cpy_r_r1014 = cpy_r_r1013 << 1;
    cpy_r_r1015 = (Py_ssize_t)cpy_r_r1003 < (Py_ssize_t)cpy_r_r1014;
    if (!cpy_r_r1015) goto CPyL994;
    cpy_r_r1016 = CPyList_GetItemUnsafe(cpy_r_r985, cpy_r_r989);
    cpy_r_time = cpy_r_r1016;
    cpy_r_r1017 = CPyList_GetItemUnsafe(cpy_r_r992, cpy_r_r996);
    cpy_r_signal = cpy_r_r1017;
    cpy_r_r1018 = CPyList_GetItemUnsafe(cpy_r_r997, cpy_r_r1003);
    cpy_r_ch = cpy_r_r1018;
    cpy_r_r1019 = CPyStatics[123]; /* 'Smoothing Signals...' */
    cpy_r_r1020 = CPyModule_builtins;
    cpy_r_r1021 = CPyStatics[8]; /* 'print' */
    cpy_r_r1022 = CPyObject_GetAttr(cpy_r_r1020, cpy_r_r1021);
    if (unlikely(cpy_r_r1022 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 549, CPyStatic_globals);
        goto CPyL995;
    }
    PyObject *cpy_r_r1023[1] = {cpy_r_r1019};
    cpy_r_r1024 = (PyObject **)&cpy_r_r1023;
    cpy_r_r1025 = _PyObject_Vectorcall(cpy_r_r1022, cpy_r_r1024, 1, 0);
    CPy_DECREF(cpy_r_r1022);
    if (unlikely(cpy_r_r1025 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 549, CPyStatic_globals);
        goto CPyL995;
    } else
        goto CPyL996;
CPyL505: ;
    cpy_r_r1026 = PyList_New(1);
    if (unlikely(cpy_r_r1026 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 550, CPyStatic_globals);
        goto CPyL995;
    }
    cpy_r_r1027 = PyFloat_FromDouble(0.0);
    cpy_r_r1028 = (CPyPtr)&((PyListObject *)cpy_r_r1026)->ob_item;
    cpy_r_r1029 = *(CPyPtr *)cpy_r_r1028;
    *(PyObject * *)cpy_r_r1029 = cpy_r_r1027;
    cpy_r_t_binned = cpy_r_r1026;
    cpy_r_r1030 = PyList_New(1);
    if (unlikely(cpy_r_r1030 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 551, CPyStatic_globals);
        goto CPyL997;
    }
    cpy_r_r1031 = PyFloat_FromDouble(0.0);
    cpy_r_r1032 = (CPyPtr)&((PyListObject *)cpy_r_r1030)->ob_item;
    cpy_r_r1033 = *(CPyPtr *)cpy_r_r1032;
    *(PyObject * *)cpy_r_r1033 = cpy_r_r1031;
    cpy_r_y_binned = cpy_r_r1030;
    cpy_r_r1034 = 0;
    cpy_r_r1035 = CPyStatics[244]; /* 0 */
    CPy_INCREF(cpy_r_r1035);
    cpy_r_i = cpy_r_r1035;
    cpy_r_r1036 = PyObject_GetIter(cpy_r_signal);
    CPy_DECREF(cpy_r_signal);
    if (unlikely(cpy_r_r1036 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 552, CPyStatic_globals);
        goto CPyL998;
    }
CPyL508: ;
    cpy_r_r1037 = PyIter_Next(cpy_r_r1036);
    if (cpy_r_r1037 == NULL) goto CPyL999;
    cpy_r_y = cpy_r_r1037;
    cpy_r_r1038 = PyObject_GetItem(cpy_r_time, cpy_r_i);
    if (unlikely(cpy_r_r1038 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 554, CPyStatic_globals);
        goto CPyL1000;
    }
    cpy_r_r1039 = ((modTof___SimulationObject *)cpy_r_self)->_sigma_smoothing;
    CPy_INCREF(cpy_r_r1039);
    cpy_r_r1040 = CPyStatics[257]; /* 2 */
    cpy_r_r1041 = PyNumber_Multiply(cpy_r_r1040, cpy_r_r1039);
    CPy_DECREF(cpy_r_r1039);
    if (unlikely(cpy_r_r1041 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 554, CPyStatic_globals);
        goto CPyL1001;
    }
    cpy_r_r1042 = PyNumber_Subtract(cpy_r_r1038, cpy_r_r1041);
    CPy_DECREF(cpy_r_r1038);
    CPy_DECREF(cpy_r_r1041);
    if (unlikely(cpy_r_r1042 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 554, CPyStatic_globals);
        goto CPyL1000;
    }
    cpy_r_r1043 = CPyStatics[244]; /* 0 */
    cpy_r_r1044 = PyObject_RichCompare(cpy_r_r1043, cpy_r_r1042, 4);
    if (unlikely(cpy_r_r1044 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 554, CPyStatic_globals);
        goto CPyL1002;
    }
    cpy_r_r1045 = PyObject_IsTrue(cpy_r_r1044);
    CPy_DECREF(cpy_r_r1044);
    cpy_r_r1046 = cpy_r_r1045 >= 0;
    if (unlikely(!cpy_r_r1046)) {
        CPy_AddTraceback("modTof.py", "run", 554, CPyStatic_globals);
        goto CPyL1002;
    }
    cpy_r_r1047 = cpy_r_r1045;
    if (cpy_r_r1047) {
        goto CPyL1003;
    } else
        goto CPyL516;
CPyL515: ;
    cpy_r_r1048 = CPyStatics[244]; /* 0 */
    CPy_INCREF(cpy_r_r1048);
    cpy_r_r1049 = cpy_r_r1048;
    goto CPyL517;
CPyL516: ;
    cpy_r_r1049 = cpy_r_r1042;
CPyL517: ;
    cpy_r_lower_bound = cpy_r_r1049;
    cpy_r_r1050 = PyObject_GetItem(cpy_r_time, cpy_r_i);
    if (unlikely(cpy_r_r1050 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 555, CPyStatic_globals);
        goto CPyL1004;
    }
    cpy_r_r1051 = ((modTof___SimulationObject *)cpy_r_self)->_sigma_smoothing;
    CPy_INCREF(cpy_r_r1051);
    cpy_r_r1052 = CPyStatics[257]; /* 2 */
    cpy_r_r1053 = PyNumber_Multiply(cpy_r_r1052, cpy_r_r1051);
    CPy_DECREF(cpy_r_r1051);
    if (unlikely(cpy_r_r1053 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 555, CPyStatic_globals);
        goto CPyL1005;
    }
    cpy_r_r1054 = PyNumber_Add(cpy_r_r1050, cpy_r_r1053);
    CPy_DECREF(cpy_r_r1050);
    CPy_DECREF(cpy_r_r1053);
    if (unlikely(cpy_r_r1054 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 555, CPyStatic_globals);
        goto CPyL1004;
    }
    cpy_r_r1055 = CPyModule_builtins;
    cpy_r_r1056 = CPyStatics[124]; /* 'max' */
    cpy_r_r1057 = CPyObject_GetAttr(cpy_r_r1055, cpy_r_r1056);
    if (unlikely(cpy_r_r1057 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 555, CPyStatic_globals);
        goto CPyL1006;
    }
    PyObject *cpy_r_r1058[1] = {cpy_r_time};
    cpy_r_r1059 = (PyObject **)&cpy_r_r1058;
    cpy_r_r1060 = _PyObject_Vectorcall(cpy_r_r1057, cpy_r_r1059, 1, 0);
    CPy_DECREF(cpy_r_r1057);
    if (unlikely(cpy_r_r1060 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 555, CPyStatic_globals);
        goto CPyL1006;
    }
    cpy_r_r1061 = ((modTof___SimulationObject *)cpy_r_self)->_sigma_smoothing;
    CPy_INCREF(cpy_r_r1061);
    cpy_r_r1062 = CPyStatics[257]; /* 2 */
    cpy_r_r1063 = PyNumber_Multiply(cpy_r_r1062, cpy_r_r1061);
    CPy_DECREF(cpy_r_r1061);
    if (unlikely(cpy_r_r1063 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 555, CPyStatic_globals);
        goto CPyL1007;
    }
    cpy_r_r1064 = PyNumber_Add(cpy_r_r1060, cpy_r_r1063);
    CPy_DECREF(cpy_r_r1060);
    CPy_DECREF(cpy_r_r1063);
    if (unlikely(cpy_r_r1064 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 555, CPyStatic_globals);
        goto CPyL1006;
    }
    cpy_r_r1065 = PyObject_RichCompare(cpy_r_r1064, cpy_r_r1054, 0);
    if (unlikely(cpy_r_r1065 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 555, CPyStatic_globals);
        goto CPyL1008;
    }
    cpy_r_r1066 = PyObject_IsTrue(cpy_r_r1065);
    CPy_DECREF(cpy_r_r1065);
    cpy_r_r1067 = cpy_r_r1066 >= 0;
    if (unlikely(!cpy_r_r1067)) {
        CPy_AddTraceback("modTof.py", "run", 555, CPyStatic_globals);
        goto CPyL1008;
    }
    cpy_r_r1068 = cpy_r_r1066;
    if (cpy_r_r1068) {
        goto CPyL1009;
    } else
        goto CPyL1010;
CPyL527: ;
    cpy_r_r1069 = cpy_r_r1064;
    goto CPyL529;
CPyL528: ;
    cpy_r_r1069 = cpy_r_r1054;
CPyL529: ;
    cpy_r_upper_bound = cpy_r_r1069;
    cpy_r_r1070 = CPyModule_builtins;
    cpy_r_r1071 = CPyStatics[124]; /* 'max' */
    cpy_r_r1072 = CPyObject_GetAttr(cpy_r_r1070, cpy_r_r1071);
    if (unlikely(cpy_r_r1072 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 557, CPyStatic_globals);
        goto CPyL1011;
    }
    PyObject *cpy_r_r1073[1] = {cpy_r_t_binned};
    cpy_r_r1074 = (PyObject **)&cpy_r_r1073;
    cpy_r_r1075 = _PyObject_Vectorcall(cpy_r_r1072, cpy_r_r1074, 1, 0);
    CPy_DECREF(cpy_r_r1072);
    if (unlikely(cpy_r_r1075 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 557, CPyStatic_globals);
        goto CPyL1011;
    }
    cpy_r_r1076 = PyObject_RichCompare(cpy_r_lower_bound, cpy_r_r1075, 0);
    CPy_DECREF(cpy_r_r1075);
    if (unlikely(cpy_r_r1076 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 557, CPyStatic_globals);
        goto CPyL1011;
    }
    cpy_r_r1077 = PyObject_IsTrue(cpy_r_r1076);
    CPy_DECREF(cpy_r_r1076);
    cpy_r_r1078 = cpy_r_r1077 >= 0;
    if (unlikely(!cpy_r_r1078)) {
        CPy_AddTraceback("modTof.py", "run", 557, CPyStatic_globals);
        goto CPyL1011;
    }
    cpy_r_r1079 = cpy_r_r1077;
    if (!cpy_r_r1079) goto CPyL540;
    cpy_r_r1080 = CPyModule_numpy;
    cpy_r_r1081 = CPyStatics[125]; /* 'digitize' */
    cpy_r_r1082 = CPyObject_GetAttr(cpy_r_r1080, cpy_r_r1081);
    if (unlikely(cpy_r_r1082 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 558, CPyStatic_globals);
        goto CPyL1011;
    }
    PyObject *cpy_r_r1083[2] = {cpy_r_lower_bound, cpy_r_t_binned};
    cpy_r_r1084 = (PyObject **)&cpy_r_r1083;
    cpy_r_r1085 = _PyObject_Vectorcall(cpy_r_r1082, cpy_r_r1084, 2, 0);
    CPy_DECREF(cpy_r_r1082);
    if (unlikely(cpy_r_r1085 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 558, CPyStatic_globals);
        goto CPyL1011;
    }
    CPy_DECREF(cpy_r_lower_bound);
    cpy_r_r1086 = PyObject_GetItem(cpy_r_t_binned, cpy_r_r1085);
    CPy_DECREF(cpy_r_r1085);
    if (unlikely(cpy_r_r1086 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 558, CPyStatic_globals);
        goto CPyL1012;
    }
    cpy_r_r1087 = ((modTof___SimulationObject *)cpy_r_self)->_output_bin_width;
    CPy_INCREF(cpy_r_r1087);
    cpy_r_r1088 = CPyStatics[257]; /* 2 */
    cpy_r_r1089 = PyNumber_TrueDivide(cpy_r_r1087, cpy_r_r1088);
    CPy_DECREF(cpy_r_r1087);
    if (unlikely(cpy_r_r1089 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 558, CPyStatic_globals);
        goto CPyL1013;
    }
    cpy_r_r1090 = PyNumber_Add(cpy_r_r1086, cpy_r_r1089);
    CPy_DECREF(cpy_r_r1086);
    CPy_DECREF(cpy_r_r1089);
    if (unlikely(cpy_r_r1090 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 558, CPyStatic_globals);
        goto CPyL1012;
    }
    cpy_r_lower_bound = cpy_r_r1090;
CPyL540: ;
    cpy_r_r1091 = ((modTof___SimulationObject *)cpy_r_self)->_output_bin_width;
    CPy_INCREF(cpy_r_r1091);
    cpy_r_r1092 = CPyModule_numpy;
    cpy_r_r1093 = CPyStatics[126]; /* 'arange' */
    cpy_r_r1094 = CPyObject_GetAttr(cpy_r_r1092, cpy_r_r1093);
    if (unlikely(cpy_r_r1094 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 559, CPyStatic_globals);
        goto CPyL1014;
    }
    PyObject *cpy_r_r1095[3] = {cpy_r_lower_bound, cpy_r_upper_bound, cpy_r_r1091};
    cpy_r_r1096 = (PyObject **)&cpy_r_r1095;
    cpy_r_r1097 = _PyObject_Vectorcall(cpy_r_r1094, cpy_r_r1096, 3, 0);
    CPy_DECREF(cpy_r_r1094);
    if (unlikely(cpy_r_r1097 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 559, CPyStatic_globals);
        goto CPyL1014;
    }
    CPy_DECREF(cpy_r_r1091);
    cpy_r_r1098 = ((modTof___SimulationObject *)cpy_r_self)->_output_bin_width;
    CPy_INCREF(cpy_r_r1098);
    cpy_r_r1099 = CPyStatics[257]; /* 2 */
    cpy_r_r1100 = PyNumber_TrueDivide(cpy_r_r1098, cpy_r_r1099);
    CPy_DECREF(cpy_r_r1098);
    if (unlikely(cpy_r_r1100 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 559, CPyStatic_globals);
        goto CPyL1015;
    }
    cpy_r_r1101 = PyNumber_Add(cpy_r_r1097, cpy_r_r1100);
    CPy_DECREF(cpy_r_r1097);
    CPy_DECREF(cpy_r_r1100);
    if (unlikely(cpy_r_r1101 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 559, CPyStatic_globals);
        goto CPyL1011;
    }
    cpy_r_cur_x = cpy_r_r1101;
    cpy_r_r1102 = PyObject_GetIter(cpy_r_cur_x);
    CPy_DECREF(cpy_r_cur_x);
    if (unlikely(cpy_r_r1102 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 562, CPyStatic_globals);
        goto CPyL1011;
    }
CPyL545: ;
    cpy_r_r1103 = PyIter_Next(cpy_r_r1102);
    if (cpy_r_r1103 == NULL) goto CPyL1016;
    cpy_r_x = cpy_r_r1103;
    cpy_r_r1104 = CPyModule_builtins;
    cpy_r_r1105 = CPyStatics[124]; /* 'max' */
    cpy_r_r1106 = CPyObject_GetAttr(cpy_r_r1104, cpy_r_r1105);
    if (unlikely(cpy_r_r1106 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 563, CPyStatic_globals);
        goto CPyL1017;
    }
    PyObject *cpy_r_r1107[1] = {cpy_r_t_binned};
    cpy_r_r1108 = (PyObject **)&cpy_r_r1107;
    cpy_r_r1109 = _PyObject_Vectorcall(cpy_r_r1106, cpy_r_r1108, 1, 0);
    CPy_DECREF(cpy_r_r1106);
    if (unlikely(cpy_r_r1109 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 563, CPyStatic_globals);
        goto CPyL1017;
    }
    cpy_r_r1110 = PyObject_RichCompare(cpy_r_x, cpy_r_r1109, 4);
    CPy_DECREF(cpy_r_r1109);
    if (unlikely(cpy_r_r1110 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 563, CPyStatic_globals);
        goto CPyL1017;
    }
    cpy_r_r1111 = PyObject_IsTrue(cpy_r_r1110);
    CPy_DECREF(cpy_r_r1110);
    cpy_r_r1112 = cpy_r_r1111 >= 0;
    if (unlikely(!cpy_r_r1112)) {
        CPy_AddTraceback("modTof.py", "run", 563, CPyStatic_globals);
        goto CPyL1017;
    }
    cpy_r_r1113 = cpy_r_r1111;
    if (!cpy_r_r1113) goto CPyL553;
    cpy_r_r1114 = CPyStatics[43]; /* 'append' */
    cpy_r_r1115 = CPyObject_CallMethodObjArgs(cpy_r_t_binned, cpy_r_r1114, cpy_r_x, NULL);
    CPy_DECREF(cpy_r_x);
    if (unlikely(cpy_r_r1115 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 564, CPyStatic_globals);
        goto CPyL1018;
    } else
        goto CPyL1019;
CPyL552: ;
    cpy_r_r1116 = CPyStatics[43]; /* 'append' */
    cpy_r_r1117 = CPyStatics[244]; /* 0 */
    cpy_r_r1118 = CPyObject_CallMethodObjArgs(cpy_r_y_binned, cpy_r_r1116, cpy_r_r1117, NULL);
    if (unlikely(cpy_r_r1118 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 565, CPyStatic_globals);
        goto CPyL1018;
    } else
        goto CPyL1020;
CPyL553: ;
    cpy_r_r1119 = CPyModule_numpy;
    cpy_r_r1120 = CPyStatics[125]; /* 'digitize' */
    cpy_r_r1121 = CPyObject_GetAttr(cpy_r_r1119, cpy_r_r1120);
    if (unlikely(cpy_r_r1121 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 566, CPyStatic_globals);
        goto CPyL1017;
    }
    PyObject *cpy_r_r1122[2] = {cpy_r_x, cpy_r_t_binned};
    cpy_r_r1123 = (PyObject **)&cpy_r_r1122;
    cpy_r_r1124 = _PyObject_Vectorcall(cpy_r_r1121, cpy_r_r1123, 2, 0);
    CPy_DECREF(cpy_r_r1121);
    if (unlikely(cpy_r_r1124 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 566, CPyStatic_globals);
        goto CPyL1017;
    }
    cpy_r_r1125 = CPyStatics[247]; /* 1 */
    cpy_r_r1126 = PyNumber_Subtract(cpy_r_r1124, cpy_r_r1125);
    CPy_DECREF(cpy_r_r1124);
    if (unlikely(cpy_r_r1126 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 566, CPyStatic_globals);
        goto CPyL1017;
    }
    cpy_r_r1127 = CPyStatics[244]; /* 0 */
    cpy_r_r1128 = PyObject_RichCompare(cpy_r_r1126, cpy_r_r1127, 4);
    CPy_DECREF(cpy_r_r1126);
    if (unlikely(cpy_r_r1128 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 566, CPyStatic_globals);
        goto CPyL1017;
    }
    cpy_r_r1129 = PyObject_IsTrue(cpy_r_r1128);
    CPy_DECREF(cpy_r_r1128);
    cpy_r_r1130 = cpy_r_r1129 >= 0;
    if (unlikely(!cpy_r_r1130)) {
        CPy_AddTraceback("modTof.py", "run", 566, CPyStatic_globals);
        goto CPyL1017;
    }
    cpy_r_r1131 = cpy_r_r1129;
    if (!cpy_r_r1131) goto CPyL1021;
    cpy_r_r1132 = CPyModule_numpy;
    cpy_r_r1133 = CPyStatics[125]; /* 'digitize' */
    cpy_r_r1134 = CPyObject_GetAttr(cpy_r_r1132, cpy_r_r1133);
    if (unlikely(cpy_r_r1134 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 566, CPyStatic_globals);
        goto CPyL1017;
    }
    PyObject *cpy_r_r1135[2] = {cpy_r_x, cpy_r_t_binned};
    cpy_r_r1136 = (PyObject **)&cpy_r_r1135;
    cpy_r_r1137 = _PyObject_Vectorcall(cpy_r_r1134, cpy_r_r1136, 2, 0);
    CPy_DECREF(cpy_r_r1134);
    if (unlikely(cpy_r_r1137 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 566, CPyStatic_globals);
        goto CPyL1017;
    }
    cpy_r_r1138 = CPyObject_Size(cpy_r_t_binned);
    if (unlikely(cpy_r_r1138 == CPY_INT_TAG)) {
        CPy_AddTraceback("modTof.py", "run", 566, CPyStatic_globals);
        goto CPyL1022;
    }
    cpy_r_r1139 = CPyTagged_StealAsObject(cpy_r_r1138);
    cpy_r_r1140 = PyObject_RichCompare(cpy_r_r1137, cpy_r_r1139, 0);
    CPy_DECREF(cpy_r_r1137);
    CPy_DECREF(cpy_r_r1139);
    if (unlikely(cpy_r_r1140 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 566, CPyStatic_globals);
        goto CPyL1017;
    }
    cpy_r_r1141 = PyObject_IsTrue(cpy_r_r1140);
    CPy_DECREF(cpy_r_r1140);
    cpy_r_r1142 = cpy_r_r1141 >= 0;
    if (unlikely(!cpy_r_r1142)) {
        CPy_AddTraceback("modTof.py", "run", 566, CPyStatic_globals);
        goto CPyL1017;
    }
    cpy_r_r1143 = cpy_r_r1141;
    if (!cpy_r_r1143) goto CPyL1021;
    cpy_r_r1144 = CPyModule_numpy;
    cpy_r_r1145 = CPyStatics[125]; /* 'digitize' */
    cpy_r_r1146 = CPyObject_GetAttr(cpy_r_r1144, cpy_r_r1145);
    if (unlikely(cpy_r_r1146 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 567, CPyStatic_globals);
        goto CPyL1017;
    }
    PyObject *cpy_r_r1147[2] = {cpy_r_x, cpy_r_t_binned};
    cpy_r_r1148 = (PyObject **)&cpy_r_r1147;
    cpy_r_r1149 = _PyObject_Vectorcall(cpy_r_r1146, cpy_r_r1148, 2, 0);
    CPy_DECREF(cpy_r_r1146);
    if (unlikely(cpy_r_r1149 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 567, CPyStatic_globals);
        goto CPyL1017;
    }
    cpy_r_index = cpy_r_r1149;
    cpy_r_r1150 = PyObject_GetItem(cpy_r_t_binned, cpy_r_index);
    if (unlikely(cpy_r_r1150 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 568, CPyStatic_globals);
        goto CPyL1023;
    }
    cpy_r_r1151 = CPyStatics[247]; /* 1 */
    cpy_r_r1152 = PyNumber_Subtract(cpy_r_index, cpy_r_r1151);
    if (unlikely(cpy_r_r1152 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 568, CPyStatic_globals);
        goto CPyL1024;
    }
    cpy_r_r1153 = PyObject_GetItem(cpy_r_t_binned, cpy_r_r1152);
    CPy_DECREF(cpy_r_r1152);
    if (unlikely(cpy_r_r1153 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 568, CPyStatic_globals);
        goto CPyL1024;
    }
    cpy_r_r1154 = PyNumber_Subtract(cpy_r_r1150, cpy_r_r1153);
    CPy_DECREF(cpy_r_r1150);
    CPy_DECREF(cpy_r_r1153);
    if (unlikely(cpy_r_r1154 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 568, CPyStatic_globals);
        goto CPyL1023;
    }
    cpy_r_r1155 = PyNumber_Absolute(cpy_r_r1154);
    CPy_DECREF(cpy_r_r1154);
    if (unlikely(cpy_r_r1155 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 568, CPyStatic_globals);
        goto CPyL1023;
    }
    cpy_r_r1156 = ((modTof___SimulationObject *)cpy_r_self)->_output_bin_width;
    CPy_INCREF(cpy_r_r1156);
    cpy_r_r1157 = PyObject_RichCompare(cpy_r_r1155, cpy_r_r1156, 4);
    CPy_DECREF(cpy_r_r1155);
    CPy_DECREF(cpy_r_r1156);
    if (unlikely(cpy_r_r1157 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 568, CPyStatic_globals);
        goto CPyL1023;
    }
    cpy_r_r1158 = PyObject_IsTrue(cpy_r_r1157);
    CPy_DECREF(cpy_r_r1157);
    cpy_r_r1159 = cpy_r_r1158 >= 0;
    if (unlikely(!cpy_r_r1159)) {
        CPy_AddTraceback("modTof.py", "run", 568, CPyStatic_globals);
        goto CPyL1023;
    }
    cpy_r_r1160 = cpy_r_r1158;
    if (!cpy_r_r1160) goto CPyL1025;
    cpy_r_r1161 = CPyStatics[127]; /* 'insert' */
    cpy_r_r1162 = CPyObject_CallMethodObjArgs(cpy_r_t_binned, cpy_r_r1161, cpy_r_index, cpy_r_x, NULL);
    CPy_DECREF(cpy_r_x);
    if (unlikely(cpy_r_r1162 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 569, CPyStatic_globals);
        goto CPyL1026;
    } else
        goto CPyL1027;
CPyL576: ;
    cpy_r_r1163 = CPyStatics[127]; /* 'insert' */
    cpy_r_r1164 = CPyStatics[244]; /* 0 */
    cpy_r_r1165 = CPyObject_CallMethodObjArgs(cpy_r_y_binned, cpy_r_r1163, cpy_r_index, cpy_r_r1164, NULL);
    CPy_DECREF(cpy_r_index);
    if (unlikely(cpy_r_r1165 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 570, CPyStatic_globals);
        goto CPyL1018;
    } else
        goto CPyL1028;
CPyL577: ;
    cpy_r_r1166 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r1166)) {
        CPy_AddTraceback("modTof.py", "run", 562, CPyStatic_globals);
        goto CPyL1011;
    }
    cpy_r_r1167 = PyList_New(0);
    if (unlikely(cpy_r_r1167 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 572, CPyStatic_globals);
        goto CPyL1011;
    }
    cpy_r_r1168 = 0;
    cpy_r_r1169 = CPyStatics[244]; /* 0 */
    CPy_INCREF(cpy_r_r1169);
    cpy_r_i_2 = cpy_r_r1169;
    cpy_r_r1170 = PyObject_GetIter(cpy_r_t_binned);
    if (unlikely(cpy_r_r1170 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 572, CPyStatic_globals);
        goto CPyL1029;
    }
CPyL580: ;
    cpy_r_r1171 = PyIter_Next(cpy_r_r1170);
    if (cpy_r_r1171 == NULL) goto CPyL1030;
    cpy_r_t_2 = cpy_r_r1171;
    cpy_r_r1172 = PyObject_RichCompare(cpy_r_t_2, cpy_r_lower_bound, 5);
    CPy_DECREF(cpy_r_t_2);
    if (unlikely(cpy_r_r1172 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 572, CPyStatic_globals);
        goto CPyL1031;
    }
    cpy_r_r1173 = PyObject_IsTrue(cpy_r_r1172);
    CPy_DECREF(cpy_r_r1172);
    cpy_r_r1174 = cpy_r_r1173 >= 0;
    if (unlikely(!cpy_r_r1174)) {
        CPy_AddTraceback("modTof.py", "run", 572, CPyStatic_globals);
        goto CPyL1031;
    }
    cpy_r_r1175 = cpy_r_r1173;
    if (!cpy_r_r1175) goto CPyL1032;
    cpy_r_r1176 = PyList_Append(cpy_r_r1167, cpy_r_i_2);
    CPy_DECREF(cpy_r_i_2);
    cpy_r_r1177 = cpy_r_r1176 >= 0;
    if (unlikely(!cpy_r_r1177)) {
        CPy_AddTraceback("modTof.py", "run", 572, CPyStatic_globals);
        goto CPyL1033;
    }
CPyL585: ;
    cpy_r_r1178 = cpy_r_r1168 + 2;
    cpy_r_r1168 = cpy_r_r1178;
    cpy_r_r1179 = CPyTagged_StealAsObject(cpy_r_r1178);
    cpy_r_i_2 = cpy_r_r1179;
    goto CPyL580;
CPyL586: ;
    cpy_r_r1180 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r1180)) {
        CPy_AddTraceback("modTof.py", "run", 572, CPyStatic_globals);
        goto CPyL1034;
    }
    cpy_r_r1181 = CPyList_GetItemShort(cpy_r_r1167, 0);
    CPy_DECREF(cpy_r_r1167);
    if (unlikely(cpy_r_r1181 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 572, CPyStatic_globals);
        goto CPyL1012;
    }
    cpy_r_index_lower = cpy_r_r1181;
    cpy_r_r1182 = PyList_New(0);
    if (unlikely(cpy_r_r1182 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 573, CPyStatic_globals);
        goto CPyL1035;
    }
    cpy_r_r1183 = 0;
    cpy_r_r1184 = CPyStatics[244]; /* 0 */
    CPy_INCREF(cpy_r_r1184);
    cpy_r_i_3 = cpy_r_r1184;
    cpy_r_r1185 = PyObject_GetIter(cpy_r_t_binned);
    if (unlikely(cpy_r_r1185 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 573, CPyStatic_globals);
        goto CPyL1036;
    }
CPyL590: ;
    cpy_r_r1186 = PyIter_Next(cpy_r_r1185);
    if (cpy_r_r1186 == NULL) goto CPyL1037;
    cpy_r_t_3 = cpy_r_r1186;
    cpy_r_r1187 = PyObject_RichCompare(cpy_r_t_3, cpy_r_upper_bound, 1);
    CPy_DECREF(cpy_r_t_3);
    if (unlikely(cpy_r_r1187 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 573, CPyStatic_globals);
        goto CPyL1038;
    }
    cpy_r_r1188 = PyObject_IsTrue(cpy_r_r1187);
    CPy_DECREF(cpy_r_r1187);
    cpy_r_r1189 = cpy_r_r1188 >= 0;
    if (unlikely(!cpy_r_r1189)) {
        CPy_AddTraceback("modTof.py", "run", 573, CPyStatic_globals);
        goto CPyL1038;
    }
    cpy_r_r1190 = cpy_r_r1188;
    if (!cpy_r_r1190) goto CPyL1039;
    cpy_r_r1191 = PyList_Append(cpy_r_r1182, cpy_r_i_3);
    CPy_DECREF(cpy_r_i_3);
    cpy_r_r1192 = cpy_r_r1191 >= 0;
    if (unlikely(!cpy_r_r1192)) {
        CPy_AddTraceback("modTof.py", "run", 573, CPyStatic_globals);
        goto CPyL1040;
    }
CPyL595: ;
    cpy_r_r1193 = cpy_r_r1183 + 2;
    cpy_r_r1183 = cpy_r_r1193;
    cpy_r_r1194 = CPyTagged_StealAsObject(cpy_r_r1193);
    cpy_r_i_3 = cpy_r_r1194;
    goto CPyL590;
CPyL596: ;
    cpy_r_r1195 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r1195)) {
        CPy_AddTraceback("modTof.py", "run", 573, CPyStatic_globals);
        goto CPyL1041;
    }
    cpy_r_r1196 = CPyStatics[260]; /* -1 */
    cpy_r_r1197 = PyObject_GetItem(cpy_r_r1182, cpy_r_r1196);
    CPy_DECREF(cpy_r_r1182);
    if (unlikely(cpy_r_r1197 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 573, CPyStatic_globals);
        goto CPyL1042;
    }
    cpy_r_index_upper = cpy_r_r1197;
    cpy_r_r1198 = CPyStatic_globals;
    cpy_r_r1199 = CPyStatics[28]; /* 'norm' */
    cpy_r_r1200 = CPyDict_GetItem(cpy_r_r1198, cpy_r_r1199);
    if (unlikely(cpy_r_r1200 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 575, CPyStatic_globals);
        goto CPyL1043;
    }
    cpy_r_r1201 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1202 = PySlice_New(cpy_r_index_lower, cpy_r_index_upper, cpy_r_r1201);
    CPy_DECREF(cpy_r_index_upper);
    if (unlikely(cpy_r_r1202 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 575, CPyStatic_globals);
        goto CPyL1044;
    }
    cpy_r_r1203 = PyObject_GetItem(cpy_r_t_binned, cpy_r_r1202);
    CPy_DECREF(cpy_r_r1202);
    if (unlikely(cpy_r_r1203 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 575, CPyStatic_globals);
        goto CPyL1044;
    }
    cpy_r_r1204 = PyObject_GetItem(cpy_r_time, cpy_r_i);
    CPy_DECREF(cpy_r_i);
    if (unlikely(cpy_r_r1204 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 575, CPyStatic_globals);
        goto CPyL1045;
    }
    cpy_r_r1205 = ((modTof___SimulationObject *)cpy_r_self)->_sigma_smoothing;
    CPy_INCREF(cpy_r_r1205);
    cpy_r_r1206 = CPyStatics[128]; /* 'pdf' */
    cpy_r_r1207 = CPyObject_GetAttr(cpy_r_r1200, cpy_r_r1206);
    CPy_DECREF(cpy_r_r1200);
    if (unlikely(cpy_r_r1207 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 575, CPyStatic_globals);
        goto CPyL1046;
    }
    PyObject *cpy_r_r1208[3] = {cpy_r_r1203, cpy_r_r1204, cpy_r_r1205};
    cpy_r_r1209 = (PyObject **)&cpy_r_r1208;
    cpy_r_r1210 = CPyStatics[269]; /* ('loc', 'scale') */
    cpy_r_r1211 = _PyObject_Vectorcall(cpy_r_r1207, cpy_r_r1209, 1, cpy_r_r1210);
    CPy_DECREF(cpy_r_r1207);
    if (unlikely(cpy_r_r1211 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 575, CPyStatic_globals);
        goto CPyL1046;
    }
    CPy_DECREF(cpy_r_r1203);
    CPy_DECREF(cpy_r_r1204);
    CPy_DECREF(cpy_r_r1205);
    cpy_r_r1212 = ((modTof___SimulationObject *)cpy_r_self)->_sigma_smoothing;
    CPy_INCREF(cpy_r_r1212);
    cpy_r_r1213 = PyNumber_Multiply(cpy_r_r1211, cpy_r_r1212);
    CPy_DECREF(cpy_r_r1211);
    CPy_DECREF(cpy_r_r1212);
    if (unlikely(cpy_r_r1213 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 575, CPyStatic_globals);
        goto CPyL1047;
    }
    cpy_r_r1214 = PyNumber_Multiply(cpy_r_r1213, cpy_r_y);
    CPy_DECREF(cpy_r_r1213);
    CPy_DECREF(cpy_r_y);
    if (unlikely(cpy_r_r1214 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 575, CPyStatic_globals);
        goto CPyL1048;
    }
    cpy_r_r1215 = CPyStatics[248]; /* 4 */
    cpy_r_r1216 = PyNumber_TrueDivide(cpy_r_r1214, cpy_r_r1215);
    CPy_DECREF(cpy_r_r1214);
    if (unlikely(cpy_r_r1216 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 575, CPyStatic_globals);
        goto CPyL1048;
    }
    cpy_r_gaussian = cpy_r_r1216;
    cpy_r_r1217 = 0;
    cpy_r_r1218 = CPyStatics[244]; /* 0 */
    CPy_INCREF(cpy_r_r1218);
    cpy_r_i = cpy_r_r1218;
    cpy_r_r1219 = PyObject_GetIter(cpy_r_gaussian);
    CPy_DECREF(cpy_r_gaussian);
    if (unlikely(cpy_r_r1219 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 577, CPyStatic_globals);
        goto CPyL1049;
    }
CPyL608: ;
    cpy_r_r1220 = PyIter_Next(cpy_r_r1219);
    if (cpy_r_r1220 == NULL) goto CPyL1050;
    cpy_r_y_add = cpy_r_r1220;
    cpy_r_r1221 = PyNumber_Add(cpy_r_index_lower, cpy_r_i);
    if (unlikely(cpy_r_r1221 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 578, CPyStatic_globals);
        goto CPyL1051;
    }
    cpy_r_r1222 = PyObject_GetItem(cpy_r_y_binned, cpy_r_r1221);
    CPy_DECREF(cpy_r_r1221);
    if (unlikely(cpy_r_r1222 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 578, CPyStatic_globals);
        goto CPyL1051;
    }
    cpy_r_r1223 = PyNumber_Add(cpy_r_r1222, cpy_r_y_add);
    CPy_DECREF(cpy_r_r1222);
    if (unlikely(cpy_r_r1223 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 578, CPyStatic_globals);
        goto CPyL1051;
    }
    cpy_r_r1224 = ((modTof___SimulationObject *)cpy_r_self)->_max_pmt_current_output;
    CPy_INCREF(cpy_r_r1224);
    cpy_r_r1225 = PyObject_RichCompare(cpy_r_r1223, cpy_r_r1224, 0);
    CPy_DECREF(cpy_r_r1223);
    CPy_DECREF(cpy_r_r1224);
    if (unlikely(cpy_r_r1225 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 578, CPyStatic_globals);
        goto CPyL1051;
    }
    cpy_r_r1226 = PyObject_IsTrue(cpy_r_r1225);
    CPy_DECREF(cpy_r_r1225);
    cpy_r_r1227 = cpy_r_r1226 >= 0;
    if (unlikely(!cpy_r_r1227)) {
        CPy_AddTraceback("modTof.py", "run", 578, CPyStatic_globals);
        goto CPyL1051;
    }
    cpy_r_r1228 = cpy_r_r1226;
    if (!cpy_r_r1228) goto CPyL1052;
    cpy_r_r1229 = PyNumber_Add(cpy_r_index_lower, cpy_r_i);
    CPy_DECREF(cpy_r_i);
    if (unlikely(cpy_r_r1229 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 579, CPyStatic_globals);
        goto CPyL1053;
    }
    cpy_r_r1230 = PyObject_GetItem(cpy_r_y_binned, cpy_r_r1229);
    if (unlikely(cpy_r_r1230 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 579, CPyStatic_globals);
        goto CPyL1054;
    }
    cpy_r_r1231 = PyNumber_InPlaceAdd(cpy_r_r1230, cpy_r_y_add);
    CPy_DECREF(cpy_r_r1230);
    CPy_DECREF(cpy_r_y_add);
    if (unlikely(cpy_r_r1231 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 579, CPyStatic_globals);
        goto CPyL1055;
    }
    cpy_r_r1232 = PyObject_SetItem(cpy_r_y_binned, cpy_r_r1229, cpy_r_r1231);
    CPy_DECREF(cpy_r_r1229);
    CPy_DECREF(cpy_r_r1231);
    cpy_r_r1233 = cpy_r_r1232 >= 0;
    if (unlikely(!cpy_r_r1233)) {
        CPy_AddTraceback("modTof.py", "run", 579, CPyStatic_globals);
        goto CPyL1056;
    } else
        goto CPyL621;
CPyL619: ;
    cpy_r_r1234 = ((modTof___SimulationObject *)cpy_r_self)->_max_pmt_current_output;
    CPy_INCREF(cpy_r_r1234);
    cpy_r_r1235 = PyNumber_Add(cpy_r_index_lower, cpy_r_i);
    CPy_DECREF(cpy_r_i);
    if (unlikely(cpy_r_r1235 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 581, CPyStatic_globals);
        goto CPyL1057;
    }
    cpy_r_r1236 = PyObject_SetItem(cpy_r_y_binned, cpy_r_r1235, cpy_r_r1234);
    CPy_DECREF(cpy_r_r1235);
    CPy_DECREF(cpy_r_r1234);
    cpy_r_r1237 = cpy_r_r1236 >= 0;
    if (unlikely(!cpy_r_r1237)) {
        CPy_AddTraceback("modTof.py", "run", 581, CPyStatic_globals);
        goto CPyL1056;
    }
CPyL621: ;
    cpy_r_r1238 = cpy_r_r1217 + 2;
    cpy_r_r1217 = cpy_r_r1238;
    cpy_r_r1239 = CPyTagged_StealAsObject(cpy_r_r1238);
    cpy_r_i = cpy_r_r1239;
    goto CPyL608;
CPyL622: ;
    cpy_r_r1240 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r1240)) {
        CPy_AddTraceback("modTof.py", "run", 577, CPyStatic_globals);
        goto CPyL1058;
    }
    cpy_r_r1241 = cpy_r_r1034 + 2;
    cpy_r_r1034 = cpy_r_r1241;
    cpy_r_r1242 = CPyTagged_StealAsObject(cpy_r_r1241);
    cpy_r_i = cpy_r_r1242;
    goto CPyL508;
CPyL624: ;
    cpy_r_r1243 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r1243)) {
        CPy_AddTraceback("modTof.py", "run", 552, CPyStatic_globals);
        goto CPyL1059;
    }
    cpy_r_r1244 = CPyStatics[102]; /* 'time' */
    cpy_r_r1245 = CPyStatics[131]; /* 'current' */
    cpy_r_r1246 = CPyDict_Build(2, cpy_r_r1244, cpy_r_t_binned, cpy_r_r1245, cpy_r_y_binned);
    CPy_DECREF(cpy_r_t_binned);
    CPy_DECREF(cpy_r_y_binned);
    if (unlikely(cpy_r_r1246 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 583, CPyStatic_globals);
        goto CPyL1060;
    }
    cpy_r_r1247 = CPyModule_pandas;
    cpy_r_r1248 = CPyStatics[107]; /* 'DataFrame' */
    cpy_r_r1249 = CPyObject_GetAttr(cpy_r_r1247, cpy_r_r1248);
    if (unlikely(cpy_r_r1249 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 583, CPyStatic_globals);
        goto CPyL1061;
    }
    PyObject *cpy_r_r1250[1] = {cpy_r_r1246};
    cpy_r_r1251 = (PyObject **)&cpy_r_r1250;
    cpy_r_r1252 = _PyObject_Vectorcall(cpy_r_r1249, cpy_r_r1251, 1, 0);
    CPy_DECREF(cpy_r_r1249);
    if (unlikely(cpy_r_r1252 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 583, CPyStatic_globals);
        goto CPyL1061;
    }
    CPy_DECREF(cpy_r_r1246);
    cpy_r_r1253 = CPyStatics[102]; /* 'time' */
    cpy_r_r1254 = PyList_New(1);
    if (unlikely(cpy_r_r1254 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 583, CPyStatic_globals);
        goto CPyL1062;
    }
    cpy_r_r1255 = (CPyPtr)&((PyListObject *)cpy_r_r1254)->ob_item;
    cpy_r_r1256 = *(CPyPtr *)cpy_r_r1255;
    CPy_INCREF(cpy_r_r1253);
    *(PyObject * *)cpy_r_r1256 = cpy_r_r1253;
    cpy_r_r1257 = CPyStatics[132]; /* 'sort_values' */
    cpy_r_r1258 = CPyObject_GetAttr(cpy_r_r1252, cpy_r_r1257);
    CPy_DECREF(cpy_r_r1252);
    if (unlikely(cpy_r_r1258 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 583, CPyStatic_globals);
        goto CPyL1063;
    }
    PyObject *cpy_r_r1259[1] = {cpy_r_r1254};
    cpy_r_r1260 = (PyObject **)&cpy_r_r1259;
    cpy_r_r1261 = CPyStatics[270]; /* ('by',) */
    cpy_r_r1262 = _PyObject_Vectorcall(cpy_r_r1258, cpy_r_r1260, 0, cpy_r_r1261);
    CPy_DECREF(cpy_r_r1258);
    if (unlikely(cpy_r_r1262 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 583, CPyStatic_globals);
        goto CPyL1063;
    }
    CPy_DECREF(cpy_r_r1254);
    cpy_r_df = cpy_r_r1262;
    cpy_r_r1263 = CPyStatics[134]; /* 'Formatting PWL dataframe...' */
    cpy_r_r1264 = CPyModule_builtins;
    cpy_r_r1265 = CPyStatics[8]; /* 'print' */
    cpy_r_r1266 = CPyObject_GetAttr(cpy_r_r1264, cpy_r_r1265);
    if (unlikely(cpy_r_r1266 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 584, CPyStatic_globals);
        goto CPyL1064;
    }
    PyObject *cpy_r_r1267[1] = {cpy_r_r1263};
    cpy_r_r1268 = (PyObject **)&cpy_r_r1267;
    cpy_r_r1269 = _PyObject_Vectorcall(cpy_r_r1266, cpy_r_r1268, 1, 0);
    CPy_DECREF(cpy_r_r1266);
    if (unlikely(cpy_r_r1269 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 584, CPyStatic_globals);
        goto CPyL1064;
    } else
        goto CPyL1065;
CPyL633: ;
    cpy_r_r1270 = PyList_New(0);
    if (unlikely(cpy_r_r1270 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 585, CPyStatic_globals);
        goto CPyL1064;
    }
    cpy_r_fill_data = cpy_r_r1270;
    cpy_r_r1271 = CPyStatics[102]; /* 'time' */
    cpy_r_r1272 = PyObject_GetItem(cpy_r_df, cpy_r_r1271);
    if (unlikely(cpy_r_r1272 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 587, CPyStatic_globals);
        goto CPyL1066;
    }
    cpy_r_r1273 = CPyStatics[135]; /* 'iloc' */
    cpy_r_r1274 = CPyObject_GetAttr(cpy_r_r1272, cpy_r_r1273);
    CPy_DECREF(cpy_r_r1272);
    if (unlikely(cpy_r_r1274 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 587, CPyStatic_globals);
        goto CPyL1066;
    }
    cpy_r_r1275 = CPyStatics[244]; /* 0 */
    cpy_r_r1276 = PyObject_GetItem(cpy_r_r1274, cpy_r_r1275);
    CPy_DECREF(cpy_r_r1274);
    if (unlikely(cpy_r_r1276 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 587, CPyStatic_globals);
        goto CPyL1066;
    }
    cpy_r_r1277 = ((modTof___SimulationObject *)cpy_r_self)->_output_bin_width;
    CPy_INCREF(cpy_r_r1277);
    cpy_r_r1278 = CPyStatics[263]; /* 5 */
    cpy_r_r1279 = PyNumber_TrueDivide(cpy_r_r1277, cpy_r_r1278);
    CPy_DECREF(cpy_r_r1277);
    if (unlikely(cpy_r_r1279 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 587, CPyStatic_globals);
        goto CPyL1067;
    }
    cpy_r_r1280 = PyNumber_Subtract(cpy_r_r1276, cpy_r_r1279);
    CPy_DECREF(cpy_r_r1276);
    CPy_DECREF(cpy_r_r1279);
    if (unlikely(cpy_r_r1280 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 587, CPyStatic_globals);
        goto CPyL1066;
    }
    cpy_r_r1281 = PyList_New(2);
    if (unlikely(cpy_r_r1281 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 587, CPyStatic_globals);
        goto CPyL1068;
    }
    cpy_r_r1282 = CPyStatics[244]; /* 0 */
    cpy_r_r1283 = (CPyPtr)&((PyListObject *)cpy_r_r1281)->ob_item;
    cpy_r_r1284 = *(CPyPtr *)cpy_r_r1283;
    *(PyObject * *)cpy_r_r1284 = cpy_r_r1280;
    cpy_r_r1285 = cpy_r_r1284 + 8;
    CPy_INCREF(cpy_r_r1282);
    *(PyObject * *)cpy_r_r1285 = cpy_r_r1282;
    cpy_r_r1286 = CPyStatics[43]; /* 'append' */
    cpy_r_r1287 = CPyObject_CallMethodObjArgs(cpy_r_fill_data, cpy_r_r1286, cpy_r_r1281, NULL);
    CPy_DECREF(cpy_r_r1281);
    if (unlikely(cpy_r_r1287 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 587, CPyStatic_globals);
        goto CPyL1066;
    } else
        goto CPyL1069;
CPyL641: ;
    cpy_r_r1288 = CPyStatics[102]; /* 'time' */
    cpy_r_r1289 = PyObject_GetItem(cpy_r_df, cpy_r_r1288);
    if (unlikely(cpy_r_r1289 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 588, CPyStatic_globals);
        goto CPyL1066;
    }
    cpy_r_r1290 = CPyObject_Size(cpy_r_r1289);
    CPy_DECREF(cpy_r_r1289);
    if (unlikely(cpy_r_r1290 == CPY_INT_TAG)) {
        CPy_AddTraceback("modTof.py", "run", 588, CPyStatic_globals);
        goto CPyL1066;
    }
    cpy_r_r1291 = CPyTagged_StealAsObject(cpy_r_r1290);
    cpy_r_r1292 = CPyStatics[247]; /* 1 */
    cpy_r_r1293 = PyNumber_Subtract(cpy_r_r1291, cpy_r_r1292);
    CPy_DECREF(cpy_r_r1291);
    if (unlikely(cpy_r_r1293 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 588, CPyStatic_globals);
        goto CPyL1066;
    }
    cpy_r_r1294 = 0;
    CPyTagged_INCREF(cpy_r_r1294);
    cpy_r_r1295 = CPyTagged_StealAsObject(cpy_r_r1294);
    cpy_r_i = cpy_r_r1295;
CPyL645: ;
    CPyTagged_INCREF(cpy_r_r1294);
    cpy_r_r1296 = CPyTagged_StealAsObject(cpy_r_r1294);
    cpy_r_r1297 = PyObject_RichCompare(cpy_r_r1296, cpy_r_r1293, 0);
    CPy_DECREF(cpy_r_r1296);
    if (unlikely(cpy_r_r1297 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 588, CPyStatic_globals);
        goto CPyL1070;
    }
    cpy_r_r1298 = PyObject_IsTrue(cpy_r_r1297);
    CPy_DECREF(cpy_r_r1297);
    cpy_r_r1299 = cpy_r_r1298 >= 0;
    if (unlikely(!cpy_r_r1299)) {
        CPy_AddTraceback("modTof.py", "run", 588, CPyStatic_globals);
        goto CPyL1070;
    }
    cpy_r_r1300 = cpy_r_r1298;
    if (!cpy_r_r1300) goto CPyL1071;
    cpy_r_r1301 = CPyStatics[102]; /* 'time' */
    cpy_r_r1302 = PyObject_GetItem(cpy_r_df, cpy_r_r1301);
    if (unlikely(cpy_r_r1302 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 589, CPyStatic_globals);
        goto CPyL1070;
    }
    cpy_r_r1303 = CPyStatics[135]; /* 'iloc' */
    cpy_r_r1304 = CPyObject_GetAttr(cpy_r_r1302, cpy_r_r1303);
    CPy_DECREF(cpy_r_r1302);
    if (unlikely(cpy_r_r1304 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 589, CPyStatic_globals);
        goto CPyL1070;
    }
    cpy_r_r1305 = PyObject_GetItem(cpy_r_r1304, cpy_r_i);
    CPy_DECREF(cpy_r_r1304);
    if (unlikely(cpy_r_r1305 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 589, CPyStatic_globals);
        goto CPyL1070;
    }
    cpy_r_r1306 = CPyStatics[102]; /* 'time' */
    cpy_r_r1307 = PyObject_GetItem(cpy_r_df, cpy_r_r1306);
    if (unlikely(cpy_r_r1307 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 589, CPyStatic_globals);
        goto CPyL1072;
    }
    cpy_r_r1308 = CPyStatics[135]; /* 'iloc' */
    cpy_r_r1309 = CPyObject_GetAttr(cpy_r_r1307, cpy_r_r1308);
    CPy_DECREF(cpy_r_r1307);
    if (unlikely(cpy_r_r1309 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 589, CPyStatic_globals);
        goto CPyL1072;
    }
    cpy_r_r1310 = CPyStatics[247]; /* 1 */
    cpy_r_r1311 = PyNumber_Add(cpy_r_i, cpy_r_r1310);
    if (unlikely(cpy_r_r1311 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 589, CPyStatic_globals);
        goto CPyL1073;
    }
    cpy_r_r1312 = PyObject_GetItem(cpy_r_r1309, cpy_r_r1311);
    CPy_DECREF(cpy_r_r1309);
    CPy_DECREF(cpy_r_r1311);
    if (unlikely(cpy_r_r1312 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 589, CPyStatic_globals);
        goto CPyL1072;
    }
    cpy_r_r1313 = PyNumber_Subtract(cpy_r_r1305, cpy_r_r1312);
    CPy_DECREF(cpy_r_r1305);
    CPy_DECREF(cpy_r_r1312);
    if (unlikely(cpy_r_r1313 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 589, CPyStatic_globals);
        goto CPyL1070;
    }
    cpy_r_r1314 = PyNumber_Absolute(cpy_r_r1313);
    CPy_DECREF(cpy_r_r1313);
    if (unlikely(cpy_r_r1314 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 589, CPyStatic_globals);
        goto CPyL1070;
    }
    cpy_r_r1315 = ((modTof___SimulationObject *)cpy_r_self)->_output_bin_width;
    CPy_INCREF(cpy_r_r1315);
    cpy_r_r1316 = PyObject_RichCompare(cpy_r_r1314, cpy_r_r1315, 4);
    CPy_DECREF(cpy_r_r1314);
    CPy_DECREF(cpy_r_r1315);
    if (unlikely(cpy_r_r1316 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 589, CPyStatic_globals);
        goto CPyL1070;
    }
    cpy_r_r1317 = PyObject_IsTrue(cpy_r_r1316);
    CPy_DECREF(cpy_r_r1316);
    cpy_r_r1318 = cpy_r_r1317 >= 0;
    if (unlikely(!cpy_r_r1318)) {
        CPy_AddTraceback("modTof.py", "run", 589, CPyStatic_globals);
        goto CPyL1070;
    }
    cpy_r_r1319 = cpy_r_r1317;
    if (!cpy_r_r1319) goto CPyL1074;
    cpy_r_r1320 = CPyStatics[102]; /* 'time' */
    cpy_r_r1321 = PyObject_GetItem(cpy_r_df, cpy_r_r1320);
    if (unlikely(cpy_r_r1321 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 590, CPyStatic_globals);
        goto CPyL1070;
    }
    cpy_r_r1322 = CPyStatics[135]; /* 'iloc' */
    cpy_r_r1323 = CPyObject_GetAttr(cpy_r_r1321, cpy_r_r1322);
    CPy_DECREF(cpy_r_r1321);
    if (unlikely(cpy_r_r1323 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 590, CPyStatic_globals);
        goto CPyL1070;
    }
    cpy_r_r1324 = PyObject_GetItem(cpy_r_r1323, cpy_r_i);
    CPy_DECREF(cpy_r_r1323);
    if (unlikely(cpy_r_r1324 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 590, CPyStatic_globals);
        goto CPyL1070;
    }
    cpy_r_r1325 = ((modTof___SimulationObject *)cpy_r_self)->_output_bin_width;
    CPy_INCREF(cpy_r_r1325);
    cpy_r_r1326 = CPyStatics[263]; /* 5 */
    cpy_r_r1327 = PyNumber_TrueDivide(cpy_r_r1325, cpy_r_r1326);
    CPy_DECREF(cpy_r_r1325);
    if (unlikely(cpy_r_r1327 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 590, CPyStatic_globals);
        goto CPyL1075;
    }
    cpy_r_r1328 = PyNumber_Add(cpy_r_r1324, cpy_r_r1327);
    CPy_DECREF(cpy_r_r1324);
    CPy_DECREF(cpy_r_r1327);
    if (unlikely(cpy_r_r1328 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 590, CPyStatic_globals);
        goto CPyL1070;
    }
    cpy_r_r1329 = PyList_New(2);
    if (unlikely(cpy_r_r1329 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 590, CPyStatic_globals);
        goto CPyL1076;
    }
    cpy_r_r1330 = CPyStatics[244]; /* 0 */
    cpy_r_r1331 = (CPyPtr)&((PyListObject *)cpy_r_r1329)->ob_item;
    cpy_r_r1332 = *(CPyPtr *)cpy_r_r1331;
    *(PyObject * *)cpy_r_r1332 = cpy_r_r1328;
    cpy_r_r1333 = cpy_r_r1332 + 8;
    CPy_INCREF(cpy_r_r1330);
    *(PyObject * *)cpy_r_r1333 = cpy_r_r1330;
    cpy_r_r1334 = CPyStatics[43]; /* 'append' */
    cpy_r_r1335 = CPyObject_CallMethodObjArgs(cpy_r_fill_data, cpy_r_r1334, cpy_r_r1329, NULL);
    CPy_DECREF(cpy_r_r1329);
    if (unlikely(cpy_r_r1335 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 590, CPyStatic_globals);
        goto CPyL1070;
    } else
        goto CPyL1077;
CPyL667: ;
    cpy_r_r1336 = CPyStatics[102]; /* 'time' */
    cpy_r_r1337 = PyObject_GetItem(cpy_r_df, cpy_r_r1336);
    if (unlikely(cpy_r_r1337 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 591, CPyStatic_globals);
        goto CPyL1070;
    }
    cpy_r_r1338 = CPyStatics[135]; /* 'iloc' */
    cpy_r_r1339 = CPyObject_GetAttr(cpy_r_r1337, cpy_r_r1338);
    CPy_DECREF(cpy_r_r1337);
    if (unlikely(cpy_r_r1339 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 591, CPyStatic_globals);
        goto CPyL1070;
    }
    cpy_r_r1340 = CPyStatics[247]; /* 1 */
    cpy_r_r1341 = PyNumber_Add(cpy_r_i, cpy_r_r1340);
    CPy_DECREF(cpy_r_i);
    if (unlikely(cpy_r_r1341 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 591, CPyStatic_globals);
        goto CPyL1078;
    }
    cpy_r_r1342 = PyObject_GetItem(cpy_r_r1339, cpy_r_r1341);
    CPy_DECREF(cpy_r_r1339);
    CPy_DECREF(cpy_r_r1341);
    if (unlikely(cpy_r_r1342 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 591, CPyStatic_globals);
        goto CPyL1079;
    }
    cpy_r_r1343 = ((modTof___SimulationObject *)cpy_r_self)->_output_bin_width;
    CPy_INCREF(cpy_r_r1343);
    cpy_r_r1344 = CPyStatics[263]; /* 5 */
    cpy_r_r1345 = PyNumber_TrueDivide(cpy_r_r1343, cpy_r_r1344);
    CPy_DECREF(cpy_r_r1343);
    if (unlikely(cpy_r_r1345 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 591, CPyStatic_globals);
        goto CPyL1080;
    }
    cpy_r_r1346 = PyNumber_Subtract(cpy_r_r1342, cpy_r_r1345);
    CPy_DECREF(cpy_r_r1342);
    CPy_DECREF(cpy_r_r1345);
    if (unlikely(cpy_r_r1346 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 591, CPyStatic_globals);
        goto CPyL1079;
    }
    cpy_r_r1347 = PyList_New(2);
    if (unlikely(cpy_r_r1347 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 591, CPyStatic_globals);
        goto CPyL1081;
    }
    cpy_r_r1348 = CPyStatics[244]; /* 0 */
    cpy_r_r1349 = (CPyPtr)&((PyListObject *)cpy_r_r1347)->ob_item;
    cpy_r_r1350 = *(CPyPtr *)cpy_r_r1349;
    *(PyObject * *)cpy_r_r1350 = cpy_r_r1346;
    cpy_r_r1351 = cpy_r_r1350 + 8;
    CPy_INCREF(cpy_r_r1348);
    *(PyObject * *)cpy_r_r1351 = cpy_r_r1348;
    cpy_r_r1352 = CPyStatics[43]; /* 'append' */
    cpy_r_r1353 = CPyObject_CallMethodObjArgs(cpy_r_fill_data, cpy_r_r1352, cpy_r_r1347, NULL);
    CPy_DECREF(cpy_r_r1347);
    if (unlikely(cpy_r_r1353 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 591, CPyStatic_globals);
        goto CPyL1079;
    } else
        goto CPyL1082;
CPyL675: ;
    cpy_r_r1354 = CPyTagged_Add(cpy_r_r1294, 2);
    CPyTagged_DECREF(cpy_r_r1294);
    CPyTagged_INCREF(cpy_r_r1354);
    cpy_r_r1294 = cpy_r_r1354;
    cpy_r_r1355 = CPyTagged_StealAsObject(cpy_r_r1354);
    cpy_r_i = cpy_r_r1355;
    goto CPyL645;
CPyL676: ;
    cpy_r_r1356 = CPyStatics[102]; /* 'time' */
    cpy_r_r1357 = PyObject_GetItem(cpy_r_df, cpy_r_r1356);
    if (unlikely(cpy_r_r1357 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 592, CPyStatic_globals);
        goto CPyL1066;
    }
    cpy_r_r1358 = CPyStatics[135]; /* 'iloc' */
    cpy_r_r1359 = CPyObject_GetAttr(cpy_r_r1357, cpy_r_r1358);
    CPy_DECREF(cpy_r_r1357);
    if (unlikely(cpy_r_r1359 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 592, CPyStatic_globals);
        goto CPyL1066;
    }
    cpy_r_r1360 = CPyStatics[260]; /* -1 */
    cpy_r_r1361 = PyObject_GetItem(cpy_r_r1359, cpy_r_r1360);
    CPy_DECREF(cpy_r_r1359);
    if (unlikely(cpy_r_r1361 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 592, CPyStatic_globals);
        goto CPyL1066;
    }
    cpy_r_r1362 = ((modTof___SimulationObject *)cpy_r_self)->_output_bin_width;
    CPy_INCREF(cpy_r_r1362);
    cpy_r_r1363 = CPyStatics[263]; /* 5 */
    cpy_r_r1364 = PyNumber_TrueDivide(cpy_r_r1362, cpy_r_r1363);
    CPy_DECREF(cpy_r_r1362);
    if (unlikely(cpy_r_r1364 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 592, CPyStatic_globals);
        goto CPyL1083;
    }
    cpy_r_r1365 = PyNumber_Add(cpy_r_r1361, cpy_r_r1364);
    CPy_DECREF(cpy_r_r1361);
    CPy_DECREF(cpy_r_r1364);
    if (unlikely(cpy_r_r1365 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 592, CPyStatic_globals);
        goto CPyL1066;
    }
    cpy_r_r1366 = PyList_New(2);
    if (unlikely(cpy_r_r1366 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 592, CPyStatic_globals);
        goto CPyL1084;
    }
    cpy_r_r1367 = CPyStatics[244]; /* 0 */
    cpy_r_r1368 = (CPyPtr)&((PyListObject *)cpy_r_r1366)->ob_item;
    cpy_r_r1369 = *(CPyPtr *)cpy_r_r1368;
    *(PyObject * *)cpy_r_r1369 = cpy_r_r1365;
    cpy_r_r1370 = cpy_r_r1369 + 8;
    CPy_INCREF(cpy_r_r1367);
    *(PyObject * *)cpy_r_r1370 = cpy_r_r1367;
    cpy_r_r1371 = CPyStatics[43]; /* 'append' */
    cpy_r_r1372 = CPyObject_CallMethodObjArgs(cpy_r_fill_data, cpy_r_r1371, cpy_r_r1366, NULL);
    CPy_DECREF(cpy_r_r1366);
    if (unlikely(cpy_r_r1372 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 592, CPyStatic_globals);
        goto CPyL1066;
    } else
        goto CPyL1085;
CPyL683: ;
    cpy_r_r1373 = CPyModule_numpy;
    cpy_r_r1374 = CPyStatics[32]; /* 'array' */
    cpy_r_r1375 = CPyObject_GetAttr(cpy_r_r1373, cpy_r_r1374);
    if (unlikely(cpy_r_r1375 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 593, CPyStatic_globals);
        goto CPyL1066;
    }
    PyObject *cpy_r_r1376[1] = {cpy_r_fill_data};
    cpy_r_r1377 = (PyObject **)&cpy_r_r1376;
    cpy_r_r1378 = _PyObject_Vectorcall(cpy_r_r1375, cpy_r_r1377, 1, 0);
    CPy_DECREF(cpy_r_r1375);
    if (unlikely(cpy_r_r1378 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 593, CPyStatic_globals);
        goto CPyL1066;
    }
    CPy_DECREF(cpy_r_fill_data);
    cpy_r_fill_data = cpy_r_r1378;
    cpy_r_r1379 = CPyStatics[102]; /* 'time' */
    cpy_r_r1380 = CPyStatics[131]; /* 'current' */
    cpy_r_r1381 = PyList_New(2);
    if (unlikely(cpy_r_r1381 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 594, CPyStatic_globals);
        goto CPyL1066;
    }
    cpy_r_r1382 = (CPyPtr)&((PyListObject *)cpy_r_r1381)->ob_item;
    cpy_r_r1383 = *(CPyPtr *)cpy_r_r1382;
    CPy_INCREF(cpy_r_r1379);
    *(PyObject * *)cpy_r_r1383 = cpy_r_r1379;
    cpy_r_r1384 = cpy_r_r1383 + 8;
    CPy_INCREF(cpy_r_r1380);
    *(PyObject * *)cpy_r_r1384 = cpy_r_r1380;
    cpy_r_r1385 = CPyModule_pandas;
    cpy_r_r1386 = CPyStatics[107]; /* 'DataFrame' */
    cpy_r_r1387 = CPyObject_GetAttr(cpy_r_r1385, cpy_r_r1386);
    if (unlikely(cpy_r_r1387 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 594, CPyStatic_globals);
        goto CPyL1086;
    }
    PyObject *cpy_r_r1388[2] = {cpy_r_fill_data, cpy_r_r1381};
    cpy_r_r1389 = (PyObject **)&cpy_r_r1388;
    cpy_r_r1390 = CPyStatics[271]; /* ('columns',) */
    cpy_r_r1391 = _PyObject_Vectorcall(cpy_r_r1387, cpy_r_r1389, 1, cpy_r_r1390);
    CPy_DECREF(cpy_r_r1387);
    if (unlikely(cpy_r_r1391 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 594, CPyStatic_globals);
        goto CPyL1086;
    }
    CPy_DECREF(cpy_r_fill_data);
    CPy_DECREF(cpy_r_r1381);
    cpy_r_fill = cpy_r_r1391;
    cpy_r_r1392 = PyList_New(2);
    if (unlikely(cpy_r_r1392 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 595, CPyStatic_globals);
        goto CPyL1087;
    }
    cpy_r_r1393 = (CPyPtr)&((PyListObject *)cpy_r_r1392)->ob_item;
    cpy_r_r1394 = *(CPyPtr *)cpy_r_r1393;
    *(PyObject * *)cpy_r_r1394 = cpy_r_fill;
    cpy_r_r1395 = cpy_r_r1394 + 8;
    *(PyObject * *)cpy_r_r1395 = cpy_r_df;
    cpy_r_r1396 = CPyModule_pandas;
    cpy_r_r1397 = CPyStatics[137]; /* 'concat' */
    cpy_r_r1398 = CPyObject_GetAttr(cpy_r_r1396, cpy_r_r1397);
    if (unlikely(cpy_r_r1398 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 595, CPyStatic_globals);
        goto CPyL1088;
    }
    cpy_r_r1399 = 1 ? Py_True : Py_False;
    PyObject *cpy_r_r1400[2] = {cpy_r_r1392, cpy_r_r1399};
    cpy_r_r1401 = (PyObject **)&cpy_r_r1400;
    cpy_r_r1402 = CPyStatics[272]; /* ('ignore_index',) */
    cpy_r_r1403 = _PyObject_Vectorcall(cpy_r_r1398, cpy_r_r1401, 1, cpy_r_r1402);
    CPy_DECREF(cpy_r_r1398);
    if (unlikely(cpy_r_r1403 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 595, CPyStatic_globals);
        goto CPyL1088;
    }
    CPy_DECREF(cpy_r_r1392);
    cpy_r_r1404 = CPyStatics[102]; /* 'time' */
    cpy_r_r1405 = PyList_New(1);
    if (unlikely(cpy_r_r1405 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 595, CPyStatic_globals);
        goto CPyL1089;
    }
    cpy_r_r1406 = (CPyPtr)&((PyListObject *)cpy_r_r1405)->ob_item;
    cpy_r_r1407 = *(CPyPtr *)cpy_r_r1406;
    CPy_INCREF(cpy_r_r1404);
    *(PyObject * *)cpy_r_r1407 = cpy_r_r1404;
    cpy_r_r1408 = CPyStatics[132]; /* 'sort_values' */
    cpy_r_r1409 = CPyObject_GetAttr(cpy_r_r1403, cpy_r_r1408);
    CPy_DECREF(cpy_r_r1403);
    if (unlikely(cpy_r_r1409 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 595, CPyStatic_globals);
        goto CPyL1090;
    }
    PyObject *cpy_r_r1410[1] = {cpy_r_r1405};
    cpy_r_r1411 = (PyObject **)&cpy_r_r1410;
    cpy_r_r1412 = CPyStatics[270]; /* ('by',) */
    cpy_r_r1413 = _PyObject_Vectorcall(cpy_r_r1409, cpy_r_r1411, 0, cpy_r_r1412);
    CPy_DECREF(cpy_r_r1409);
    if (unlikely(cpy_r_r1413 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 595, CPyStatic_globals);
        goto CPyL1090;
    }
    CPy_DECREF(cpy_r_r1405);
    cpy_r_r1414 = CPyStatics[139]; /* 'reset_index' */
    cpy_r_r1415 = CPyObject_GetAttr(cpy_r_r1413, cpy_r_r1414);
    CPy_DECREF(cpy_r_r1413);
    if (unlikely(cpy_r_r1415 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 595, CPyStatic_globals);
        goto CPyL1060;
    }
    cpy_r_r1416 = 1 ? Py_True : Py_False;
    PyObject *cpy_r_r1417[1] = {cpy_r_r1416};
    cpy_r_r1418 = (PyObject **)&cpy_r_r1417;
    cpy_r_r1419 = CPyStatics[273]; /* ('drop',) */
    cpy_r_r1420 = _PyObject_Vectorcall(cpy_r_r1415, cpy_r_r1418, 0, cpy_r_r1419);
    CPy_DECREF(cpy_r_r1415);
    if (unlikely(cpy_r_r1420 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 595, CPyStatic_globals);
        goto CPyL1060;
    }
    cpy_r_df = cpy_r_r1420;
    cpy_r_r1421 = CPyStatics[102]; /* 'time' */
    cpy_r_r1422 = PyObject_GetItem(cpy_r_df, cpy_r_r1421);
    if (unlikely(cpy_r_r1422 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 596, CPyStatic_globals);
        goto CPyL1064;
    }
    cpy_r_r1423 = PyFloat_FromDouble(1000000000000.0);
    cpy_r_r1424 = PyNumber_TrueDivide(cpy_r_r1422, cpy_r_r1423);
    CPy_DECREF(cpy_r_r1422);
    CPy_DECREF(cpy_r_r1423);
    if (unlikely(cpy_r_r1424 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 596, CPyStatic_globals);
        goto CPyL1064;
    }
    cpy_r_r1425 = CPyStatics[102]; /* 'time' */
    cpy_r_r1426 = PyObject_SetItem(cpy_r_df, cpy_r_r1425, cpy_r_r1424);
    CPy_DECREF(cpy_r_r1424);
    cpy_r_r1427 = cpy_r_r1426 >= 0;
    if (unlikely(!cpy_r_r1427)) {
        CPy_AddTraceback("modTof.py", "run", 596, CPyStatic_globals);
        goto CPyL1064;
    }
    cpy_r_r1428 = CPyStatics[102]; /* 'time' */
    cpy_r_r1429 = CPyStatics[131]; /* 'current' */
    cpy_r_r1430 = PyList_New(2);
    if (unlikely(cpy_r_r1430 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 597, CPyStatic_globals);
        goto CPyL1064;
    }
    cpy_r_r1431 = (CPyPtr)&((PyListObject *)cpy_r_r1430)->ob_item;
    cpy_r_r1432 = *(CPyPtr *)cpy_r_r1431;
    CPy_INCREF(cpy_r_r1428);
    *(PyObject * *)cpy_r_r1432 = cpy_r_r1428;
    cpy_r_r1433 = cpy_r_r1432 + 8;
    CPy_INCREF(cpy_r_r1429);
    *(PyObject * *)cpy_r_r1433 = cpy_r_r1429;
    cpy_r_r1434 = PyObject_GetItem(cpy_r_df, cpy_r_r1430);
    CPy_DECREF(cpy_r_df);
    CPy_DECREF(cpy_r_r1430);
    if (unlikely(cpy_r_r1434 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 597, CPyStatic_globals);
        goto CPyL1060;
    }
    cpy_r_df = cpy_r_r1434;
    cpy_r_r1435 = CPyStatics[141]; /* 'monte_carlo_input' */
    cpy_r_r1436 = ((modTof___SimulationObject *)cpy_r_self)->_num_particles;
    CPy_INCREF(cpy_r_r1436);
    cpy_r_r1437 = PyObject_Str(cpy_r_r1436);
    CPy_DECREF(cpy_r_r1436);
    if (unlikely(cpy_r_r1437 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 598, CPyStatic_globals);
        goto CPyL1064;
    }
    cpy_r_r1438 = PyUnicode_Concat(cpy_r_r1435, cpy_r_r1437);
    CPy_DECREF(cpy_r_r1437);
    if (unlikely(cpy_r_r1438 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 598, CPyStatic_globals);
        goto CPyL1064;
    }
    cpy_r_r1439 = CPyStatics[142]; /* 'ch' */
    cpy_r_r1440 = PyUnicode_Concat(cpy_r_r1438, cpy_r_r1439);
    CPy_DECREF(cpy_r_r1438);
    if (unlikely(cpy_r_r1440 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 598, CPyStatic_globals);
        goto CPyL1064;
    }
    cpy_r_r1441 = PyObject_Str(cpy_r_ch);
    CPy_DECREF(cpy_r_ch);
    if (unlikely(cpy_r_r1441 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 598, CPyStatic_globals);
        goto CPyL1091;
    }
    cpy_r_r1442 = PyUnicode_Concat(cpy_r_r1440, cpy_r_r1441);
    CPy_DECREF(cpy_r_r1440);
    CPy_DECREF(cpy_r_r1441);
    if (unlikely(cpy_r_r1442 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 598, CPyStatic_globals);
        goto CPyL1092;
    }
    cpy_r_r1443 = CPyStatics[143]; /* '_' */
    cpy_r_r1444 = PyUnicode_Concat(cpy_r_r1442, cpy_r_r1443);
    CPy_DECREF(cpy_r_r1442);
    if (unlikely(cpy_r_r1444 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 598, CPyStatic_globals);
        goto CPyL1092;
    }
    cpy_r_r1445 = CPyStatic_globals;
    cpy_r_r1446 = CPyStatics[115]; /* 'datetime' */
    cpy_r_r1447 = CPyDict_GetItem(cpy_r_r1445, cpy_r_r1446);
    if (unlikely(cpy_r_r1447 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 598, CPyStatic_globals);
        goto CPyL1093;
    }
    cpy_r_r1448 = CPyStatics[116]; /* 'now' */
    cpy_r_r1449 = CPyObject_CallMethodObjArgs(cpy_r_r1447, cpy_r_r1448, NULL);
    CPy_DECREF(cpy_r_r1447);
    if (unlikely(cpy_r_r1449 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 598, CPyStatic_globals);
        goto CPyL1093;
    }
    cpy_r_r1450 = CPyStatics[117]; /* '%m_%d_%Y' */
    cpy_r_r1451 = CPyStatics[118]; /* 'strftime' */
    cpy_r_r1452 = CPyObject_CallMethodObjArgs(cpy_r_r1449, cpy_r_r1451, cpy_r_r1450, NULL);
    CPy_DECREF(cpy_r_r1449);
    if (unlikely(cpy_r_r1452 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 598, CPyStatic_globals);
        goto CPyL1093;
    }
    cpy_r_r1453 = PyObject_Str(cpy_r_r1452);
    CPy_DECREF(cpy_r_r1452);
    if (unlikely(cpy_r_r1453 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 598, CPyStatic_globals);
        goto CPyL1093;
    }
    cpy_r_r1454 = PyUnicode_Concat(cpy_r_r1444, cpy_r_r1453);
    CPy_DECREF(cpy_r_r1444);
    CPy_DECREF(cpy_r_r1453);
    if (unlikely(cpy_r_r1454 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 598, CPyStatic_globals);
        goto CPyL1092;
    }
    cpy_r_r1455 = CPyStatics[119]; /* '.txt' */
    cpy_r_r1456 = PyUnicode_Concat(cpy_r_r1454, cpy_r_r1455);
    CPy_DECREF(cpy_r_r1454);
    if (unlikely(cpy_r_r1456 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 598, CPyStatic_globals);
        goto CPyL1092;
    }
    cpy_r_r1457 = CPyStatics[144]; /* '%.13f' */
    cpy_r_r1458 = CPyStatics[145]; /* ' ' */
    cpy_r_r1459 = CPyStatics[120]; /* 'to_csv' */
    cpy_r_r1460 = CPyObject_GetAttr(cpy_r_df, cpy_r_r1459);
    CPy_DECREF(cpy_r_df);
    if (unlikely(cpy_r_r1460 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 598, CPyStatic_globals);
        goto CPyL1094;
    }
    cpy_r_r1461 = 0 ? Py_True : Py_False;
    cpy_r_r1462 = 0 ? Py_True : Py_False;
    PyObject *cpy_r_r1463[5] = {cpy_r_r1456, cpy_r_r1457, cpy_r_r1461, cpy_r_r1462, cpy_r_r1458};
    cpy_r_r1464 = (PyObject **)&cpy_r_r1463;
    cpy_r_r1465 = CPyStatics[274]; /* ('float_format', 'header', 'index', 'sep') */
    cpy_r_r1466 = _PyObject_Vectorcall(cpy_r_r1460, cpy_r_r1464, 1, cpy_r_r1465);
    CPy_DECREF(cpy_r_r1460);
    if (unlikely(cpy_r_r1466 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 598, CPyStatic_globals);
        goto CPyL1094;
    } else
        goto CPyL1095;
CPyL715: ;
    CPy_DECREF(cpy_r_r1456);
    cpy_r_r1467 = cpy_r_r989 + 2;
    cpy_r_r989 = cpy_r_r1467;
    cpy_r_r1468 = cpy_r_r996 + 2;
    cpy_r_r996 = cpy_r_r1468;
    cpy_r_r1469 = cpy_r_r1003 + 2;
    cpy_r_r1003 = cpy_r_r1469;
    goto CPyL500;
CPyL717: ;
    cpy_r_r1470 = CPyStatics[75]; /* 'Done!' */
    cpy_r_r1471 = CPyModule_builtins;
    cpy_r_r1472 = CPyStatics[8]; /* 'print' */
    cpy_r_r1473 = CPyObject_GetAttr(cpy_r_r1471, cpy_r_r1472);
    if (unlikely(cpy_r_r1473 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 599, CPyStatic_globals);
        goto CPyL720;
    }
    PyObject *cpy_r_r1474[1] = {cpy_r_r1470};
    cpy_r_r1475 = (PyObject **)&cpy_r_r1474;
    cpy_r_r1476 = _PyObject_Vectorcall(cpy_r_r1473, cpy_r_r1475, 1, 0);
    CPy_DECREF(cpy_r_r1473);
    if (unlikely(cpy_r_r1476 == NULL)) {
        CPy_AddTraceback("modTof.py", "run", 599, CPyStatic_globals);
        goto CPyL720;
    } else
        goto CPyL1096;
CPyL719: ;
    cpy_r_r1477 = Py_None;
    CPy_INCREF(cpy_r_r1477);
    return cpy_r_r1477;
CPyL720: ;
    cpy_r_r1478 = NULL;
    return cpy_r_r1478;
CPyL721: ;
    CPy_DECREF(cpy_r_r15);
    goto CPyL7;
CPyL722: ;
    CPy_DecRef(cpy_r_r19);
    goto CPyL720;
CPyL723: ;
    CPy_DecRef(cpy_r_r29);
    goto CPyL720;
CPyL724: ;
    CPy_DECREF(cpy_r_r35);
    goto CPyL15;
CPyL725: ;
    CPy_DecRef(cpy_r_r42);
    goto CPyL720;
CPyL726: ;
    CPy_DECREF(cpy_r_r48);
    goto CPyL20;
CPyL727: ;
    CPy_DecRef(cpy_r_logstarttime);
    goto CPyL720;
CPyL728: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    goto CPyL720;
CPyL729: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    goto CPyL720;
CPyL730: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    goto CPyL720;
CPyL731: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    goto CPyL720;
CPyL732: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_r67);
    goto CPyL720;
CPyL733: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_r74);
    CPy_DecRef(cpy_r_r75);
    goto CPyL720;
CPyL734: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_r74);
    CPy_DecRef(cpy_r_r77);
    goto CPyL720;
CPyL735: ;
    CPy_DecRef(cpy_r_pool__redef__);
    goto CPyL65;
CPyL736: ;
    CPy_DecRef(cpy_r_pool__redef__);
    CPy_DecRef(cpy_r_r85);
    CPy_DecRef(cpy_r_r86);
    goto CPyL65;
CPyL737: ;
    CPy_DECREF(cpy_r_r93);
    goto CPyL64;
CPyL738: ;
    CPy_DecRef(cpy_r_r93);
    goto CPyL65;
CPyL739: ;
    CPy_DECREF(cpy_r_r93);
    CPy_DECREF(cpy_r_r95);
    goto CPyL44;
CPyL740: ;
    CPy_DECREF(cpy_r_logstarttime);
    CPy_DECREF(cpy_r_times);
    CPy_DECREF(cpy_r_points);
    CPy_DECREF(cpy_r_photons);
    CPy_DECREF(cpy_r_particleID);
    CPy_DECREF(cpy_r_r74);
    CPy_DECREF(cpy_r_r77);
    goto CPyL45;
CPyL741: ;
    CPy_DECREF(cpy_r_r93);
    CPy_DECREF(cpy_r_r95);
    CPy_DECREF(cpy_r_time_i);
    goto CPyL47;
CPyL742: ;
    CPy_DECREF(cpy_r_logstarttime);
    CPy_DECREF(cpy_r_times);
    CPy_DECREF(cpy_r_points);
    CPy_DECREF(cpy_r_photons);
    CPy_DECREF(cpy_r_particleID);
    CPy_DECREF(cpy_r_r74);
    CPy_DECREF(cpy_r_r77);
    goto CPyL48;
CPyL743: ;
    CPy_DECREF(cpy_r_r93);
    CPy_DECREF(cpy_r_r95);
    CPy_DECREF(cpy_r_time_i);
    CPy_DECREF(cpy_r_point_i);
    goto CPyL50;
CPyL744: ;
    CPy_DECREF(cpy_r_logstarttime);
    CPy_DECREF(cpy_r_times);
    CPy_DECREF(cpy_r_points);
    CPy_DECREF(cpy_r_photons);
    CPy_DECREF(cpy_r_particleID);
    CPy_DECREF(cpy_r_r74);
    CPy_DECREF(cpy_r_r77);
    goto CPyL51;
CPyL745: ;
    CPy_DECREF(cpy_r_r93);
    CPy_DECREF(cpy_r_time_i);
    CPy_DECREF(cpy_r_point_i);
    CPy_DECREF(cpy_r_photon_i);
    CPy_DECREF(cpy_r_r102);
    goto CPyL53;
CPyL746: ;
    CPy_DECREF(cpy_r_logstarttime);
    CPy_DECREF(cpy_r_times);
    CPy_DECREF(cpy_r_points);
    CPy_DECREF(cpy_r_photons);
    CPy_DECREF(cpy_r_particleID);
    CPy_DECREF(cpy_r_r74);
    CPy_DECREF(cpy_r_r77);
    goto CPyL54;
CPyL747: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r93);
    CPy_DecRef(cpy_r_time_i);
    CPy_DecRef(cpy_r_point_i);
    CPy_DecRef(cpy_r_photon_i);
    goto CPyL65;
CPyL748: ;
    CPy_DECREF(cpy_r_r106);
    goto CPyL56;
CPyL749: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r93);
    CPy_DecRef(cpy_r_time_i);
    CPy_DecRef(cpy_r_photon_i);
    goto CPyL65;
CPyL750: ;
    CPy_DECREF(cpy_r_r108);
    goto CPyL57;
CPyL751: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r93);
    CPy_DecRef(cpy_r_time_i);
    goto CPyL65;
CPyL752: ;
    CPy_DECREF(cpy_r_r110);
    goto CPyL58;
CPyL753: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r93);
    goto CPyL65;
CPyL754: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r93);
    CPy_DecRef(cpy_r_r112);
    goto CPyL65;
CPyL755: ;
    CPy_DECREF(cpy_r_r120);
    goto CPyL62;
CPyL756: ;
    CPy_DecRef(cpy_r_r126);
    CPy_DecRef(cpy_r_r127);
    CPy_DecRef(cpy_r_r128);
    goto CPyL71;
CPyL757: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_r74);
    CPy_DecRef(cpy_r_r77);
    CPy_DecRef(cpy_r_r124.f0);
    CPy_DecRef(cpy_r_r124.f1);
    CPy_DecRef(cpy_r_r124.f2);
    goto CPyL69;
CPyL758: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_r74);
    CPy_DecRef(cpy_r_r77);
    goto CPyL72;
CPyL759: ;
    CPy_DECREF(cpy_r_r74);
    CPy_DECREF(cpy_r_r77);
    goto CPyL78;
CPyL760: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_r74);
    goto CPyL81;
CPyL761: ;
    CPy_DECREF(cpy_r_r142);
    goto CPyL77;
CPyL762: ;
    CPy_DECREF(cpy_r_logstarttime);
    CPy_DECREF(cpy_r_times);
    CPy_DECREF(cpy_r_points);
    CPy_DECREF(cpy_r_photons);
    CPy_DECREF(cpy_r_particleID);
    goto CPyL79;
CPyL763: ;
    CPy_XDECREF(cpy_r_r137.f0);
    CPy_XDECREF(cpy_r_r137.f1);
    CPy_XDECREF(cpy_r_r137.f2);
    goto CPyL80;
CPyL764: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_logendparticle);
    goto CPyL720;
CPyL765: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_N);
    goto CPyL720;
CPyL766: ;
    CPy_DECREF(cpy_r_r160);
    goto CPyL91;
CPyL767: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    goto CPyL720;
CPyL768: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    goto CPyL720;
CPyL769: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_r211);
    goto CPyL720;
CPyL770: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    goto CPyL720;
CPyL771: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_r227);
    goto CPyL720;
CPyL772: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    goto CPyL720;
CPyL773: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_r243);
    goto CPyL720;
CPyL774: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    goto CPyL720;
CPyL775: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_r259);
    goto CPyL720;
CPyL776: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T1part_ids);
    goto CPyL720;
CPyL777: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_r273);
    goto CPyL720;
CPyL778: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_r286);
    goto CPyL720;
CPyL779: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    goto CPyL720;
CPyL780: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    goto CPyL720;
CPyL781: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_r302);
    goto CPyL720;
CPyL782: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_photons);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    goto CPyL720;
CPyL783: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    goto CPyL720;
CPyL784: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    CPy_DecRef(cpy_r_r318);
    goto CPyL720;
CPyL785: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_particleID);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    CPy_DecRef(cpy_r_T4photons);
    goto CPyL720;
CPyL786: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    CPy_DecRef(cpy_r_T4photons);
    goto CPyL720;
CPyL787: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_points);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_r334);
    goto CPyL720;
CPyL788: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_r334);
    goto CPyL720;
CPyL789: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    CPy_DecRef(cpy_r_T4photons);
    goto CPyL720;
CPyL790: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_T4part_ids);
    goto CPyL720;
CPyL791: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_r348);
    goto CPyL720;
CPyL792: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_r364);
    goto CPyL720;
CPyL793: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_r373);
    goto CPyL720;
CPyL794: ;
    CPy_DECREF(cpy_r_r379);
    goto CPyL184;
CPyL795: ;
    CPy_DECREF(cpy_r_r386);
    goto CPyL186;
CPyL796: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_logstartphoton);
    goto CPyL720;
CPyL797: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_logstartphoton);
    CPy_DecRef(cpy_r_r394);
    goto CPyL720;
CPyL798: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_logstartphoton);
    CPy_DecRef(cpy_r_r401);
    CPy_DecRef(cpy_r_r402);
    goto CPyL720;
CPyL799: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_logstartphoton);
    CPy_DecRef(cpy_r_r401);
    CPy_DecRef(cpy_r_r404);
    goto CPyL720;
CPyL800: ;
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_pool);
    goto CPyL302;
CPyL801: ;
    CPy_DECREF(cpy_r_r417);
    goto CPyL198;
CPyL802: ;
    CPy_DecRef(cpy_r_T1points);
    CPy_DecRef(cpy_r_T1times);
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_pool);
    CPy_DecRef(cpy_r_r419);
    goto CPyL302;
CPyL803: ;
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_pool);
    CPy_DecRef(cpy_r_r419);
    goto CPyL302;
CPyL804: ;
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_pool);
    CPy_DecRef(cpy_r_r419);
    CPy_DecRef(cpy_r_r425);
    goto CPyL302;
CPyL805: ;
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_pool);
    CPy_DecRef(cpy_r_r419);
    CPy_DecRef(cpy_r_r425);
    CPy_DecRef(cpy_r_r428);
    goto CPyL302;
CPyL806: ;
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_pool);
    goto CPyL302;
CPyL807: ;
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_pool);
    CPy_DecRef(cpy_r_T1res);
    goto CPyL302;
CPyL808: ;
    CPy_DECREF(cpy_r_r445);
    goto CPyL207;
CPyL809: ;
    CPy_DECREF(cpy_r_r452);
    goto CPyL209;
CPyL810: ;
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4points);
    CPy_DecRef(cpy_r_T4times);
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_pool);
    CPy_DecRef(cpy_r_T1res);
    CPy_DecRef(cpy_r_r454);
    goto CPyL302;
CPyL811: ;
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_pool);
    CPy_DecRef(cpy_r_T1res);
    CPy_DecRef(cpy_r_r454);
    goto CPyL302;
CPyL812: ;
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_pool);
    CPy_DecRef(cpy_r_T1res);
    CPy_DecRef(cpy_r_r454);
    CPy_DecRef(cpy_r_r460);
    goto CPyL302;
CPyL813: ;
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_pool);
    CPy_DecRef(cpy_r_T1res);
    CPy_DecRef(cpy_r_r454);
    CPy_DecRef(cpy_r_r460);
    CPy_DecRef(cpy_r_r463);
    goto CPyL302;
CPyL814: ;
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_T1res);
    goto CPyL302;
CPyL815: ;
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_T1res);
    CPy_DecRef(cpy_r_T4res);
    goto CPyL302;
CPyL816: ;
    CPy_DECREF(cpy_r_r480);
    goto CPyL218;
CPyL817: ;
    CPy_DECREF(cpy_r_r487);
    goto CPyL220;
CPyL818: ;
    CPy_DecRef(cpy_r_T1part_ids);
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_T4res);
    goto CPyL302;
CPyL819: ;
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_T4res);
    CPy_DecRef(cpy_r_r488);
    goto CPyL302;
CPyL820: ;
    CPy_DECREF(cpy_r_r488);
    CPy_DECREF(cpy_r_r489);
    goto CPyL259;
CPyL821: ;
    CPy_DECREF(cpy_r_r488);
    CPy_DECREF(cpy_r_r489);
    CPy_DECREF(cpy_r_r490);
    goto CPyL259;
CPyL822: ;
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_T4res);
    CPy_DecRef(cpy_r_r488);
    CPy_DecRef(cpy_r_r489);
    CPy_DecRef(cpy_r_r491);
    goto CPyL302;
CPyL823: ;
    CPy_DECREF(cpy_r_T4part_ids);
    CPy_DECREF(cpy_r_T4res);
    CPy_DECREF(cpy_r_r488);
    CPy_DECREF(cpy_r_r489);
    CPy_DECREF(cpy_r_r491);
    CPy_DECREF(cpy_r_r492);
    goto CPyL226;
CPyL824: ;
    CPy_DECREF(cpy_r_logstarttime);
    CPy_DECREF(cpy_r_logendparticle);
    CPy_DECREF(cpy_r_T1_input_times);
    CPy_DECREF(cpy_r_T4_input_times);
    CPy_DECREF(cpy_r_T1photons);
    CPy_DECREF(cpy_r_T4photons);
    CPy_DECREF(cpy_r_logstartphoton);
    CPy_DECREF(cpy_r_r401);
    CPy_DECREF(cpy_r_r404);
    goto CPyL227;
CPyL825: ;
    CPy_DECREF(cpy_r_T4part_ids);
    CPy_DECREF(cpy_r_T4res);
    CPy_DECREF(cpy_r_r488);
    CPy_DECREF(cpy_r_r489);
    CPy_DECREF(cpy_r_r491);
    CPy_DECREF(cpy_r_r492);
    CPy_DECREF(cpy_r_T1hit_PMT);
    goto CPyL229;
CPyL826: ;
    CPy_DECREF(cpy_r_logstarttime);
    CPy_DECREF(cpy_r_logendparticle);
    CPy_DECREF(cpy_r_T1_input_times);
    CPy_DECREF(cpy_r_T4_input_times);
    CPy_DECREF(cpy_r_T1photons);
    CPy_DECREF(cpy_r_T4photons);
    CPy_DECREF(cpy_r_logstartphoton);
    CPy_DECREF(cpy_r_r401);
    CPy_DECREF(cpy_r_r404);
    goto CPyL230;
CPyL827: ;
    CPy_DECREF(cpy_r_T4part_ids);
    CPy_DECREF(cpy_r_T4res);
    CPy_DECREF(cpy_r_r488);
    CPy_DECREF(cpy_r_r489);
    CPy_DECREF(cpy_r_r491);
    CPy_DECREF(cpy_r_r492);
    CPy_DECREF(cpy_r_T1hit_PMT);
    CPy_DECREF(cpy_r_T1travel_time);
    goto CPyL232;
CPyL828: ;
    CPy_DECREF(cpy_r_logstarttime);
    CPy_DECREF(cpy_r_logendparticle);
    CPy_DECREF(cpy_r_T1_input_times);
    CPy_DECREF(cpy_r_T4_input_times);
    CPy_DECREF(cpy_r_T1photons);
    CPy_DECREF(cpy_r_T4photons);
    CPy_DECREF(cpy_r_logstartphoton);
    CPy_DECREF(cpy_r_r401);
    CPy_DECREF(cpy_r_r404);
    goto CPyL233;
CPyL829: ;
    CPy_DECREF(cpy_r_T4part_ids);
    CPy_DECREF(cpy_r_T4res);
    CPy_DECREF(cpy_r_r488);
    CPy_DECREF(cpy_r_r489);
    CPy_DECREF(cpy_r_r491);
    CPy_DECREF(cpy_r_r492);
    CPy_DECREF(cpy_r_T1hit_PMT);
    CPy_DECREF(cpy_r_T1travel_time);
    CPy_DECREF(cpy_r_T1tot_dist);
    goto CPyL235;
CPyL830: ;
    CPy_DECREF(cpy_r_logstarttime);
    CPy_DECREF(cpy_r_logendparticle);
    CPy_DECREF(cpy_r_T1_input_times);
    CPy_DECREF(cpy_r_T4_input_times);
    CPy_DECREF(cpy_r_T1photons);
    CPy_DECREF(cpy_r_T4photons);
    CPy_DECREF(cpy_r_logstartphoton);
    CPy_DECREF(cpy_r_r401);
    CPy_DECREF(cpy_r_r404);
    goto CPyL236;
CPyL831: ;
    CPy_DECREF(cpy_r_T4part_ids);
    CPy_DECREF(cpy_r_T4res);
    CPy_DECREF(cpy_r_r488);
    CPy_DECREF(cpy_r_r489);
    CPy_DECREF(cpy_r_r491);
    CPy_DECREF(cpy_r_r492);
    CPy_DECREF(cpy_r_T1hit_PMT);
    CPy_DECREF(cpy_r_T1travel_time);
    CPy_DECREF(cpy_r_T1tot_dist);
    CPy_DECREF(cpy_r_T1endpt);
    goto CPyL238;
CPyL832: ;
    CPy_DECREF(cpy_r_logstarttime);
    CPy_DECREF(cpy_r_logendparticle);
    CPy_DECREF(cpy_r_T1_input_times);
    CPy_DECREF(cpy_r_T4_input_times);
    CPy_DECREF(cpy_r_T1photons);
    CPy_DECREF(cpy_r_T4photons);
    CPy_DECREF(cpy_r_logstartphoton);
    CPy_DECREF(cpy_r_r401);
    CPy_DECREF(cpy_r_r404);
    goto CPyL239;
CPyL833: ;
    CPy_DECREF(cpy_r_T4part_ids);
    CPy_DECREF(cpy_r_T4res);
    CPy_DECREF(cpy_r_r488);
    CPy_DECREF(cpy_r_r489);
    CPy_DECREF(cpy_r_r491);
    CPy_DECREF(cpy_r_r492);
    CPy_DECREF(cpy_r_T1hit_PMT);
    CPy_DECREF(cpy_r_T1travel_time);
    CPy_DECREF(cpy_r_T1tot_dist);
    CPy_DECREF(cpy_r_T1endpt);
    CPy_DECREF(cpy_r_T1bounces);
    goto CPyL241;
CPyL834: ;
    CPy_DECREF(cpy_r_logstarttime);
    CPy_DECREF(cpy_r_logendparticle);
    CPy_DECREF(cpy_r_T1_input_times);
    CPy_DECREF(cpy_r_T4_input_times);
    CPy_DECREF(cpy_r_T1photons);
    CPy_DECREF(cpy_r_T4photons);
    CPy_DECREF(cpy_r_logstartphoton);
    CPy_DECREF(cpy_r_r401);
    CPy_DECREF(cpy_r_r404);
    goto CPyL242;
CPyL835: ;
    CPy_DECREF(cpy_r_T4part_ids);
    CPy_DECREF(cpy_r_T4res);
    CPy_DECREF(cpy_r_r488);
    CPy_DECREF(cpy_r_r489);
    CPy_DECREF(cpy_r_r491);
    CPy_DECREF(cpy_r_T1hit_PMT);
    CPy_DECREF(cpy_r_T1travel_time);
    CPy_DECREF(cpy_r_T1tot_dist);
    CPy_DECREF(cpy_r_T1endpt);
    CPy_DECREF(cpy_r_T1bounces);
    CPy_DECREF(cpy_r_T1prop);
    CPy_DECREF(cpy_r_r505);
    goto CPyL244;
CPyL836: ;
    CPy_DECREF(cpy_r_logstarttime);
    CPy_DECREF(cpy_r_logendparticle);
    CPy_DECREF(cpy_r_T1_input_times);
    CPy_DECREF(cpy_r_T4_input_times);
    CPy_DECREF(cpy_r_T1photons);
    CPy_DECREF(cpy_r_T4photons);
    CPy_DECREF(cpy_r_logstartphoton);
    CPy_DECREF(cpy_r_r401);
    CPy_DECREF(cpy_r_r404);
    goto CPyL245;
CPyL837: ;
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_T4res);
    CPy_DecRef(cpy_r_r488);
    CPy_DecRef(cpy_r_r489);
    CPy_DecRef(cpy_r_T1travel_time);
    CPy_DecRef(cpy_r_T1tot_dist);
    CPy_DecRef(cpy_r_T1endpt);
    CPy_DecRef(cpy_r_T1bounces);
    CPy_DecRef(cpy_r_T1prop);
    CPy_DecRef(cpy_r_T1part_id);
    goto CPyL302;
CPyL838: ;
    CPy_DECREF(cpy_r_T1travel_time);
    CPy_DECREF(cpy_r_T1tot_dist);
    CPy_DECREF(cpy_r_T1endpt);
    CPy_DECREF(cpy_r_T1bounces);
    CPy_DECREF(cpy_r_T1prop);
    CPy_DECREF(cpy_r_T1part_id);
    goto CPyL222;
CPyL839: ;
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_T4res);
    CPy_DecRef(cpy_r_r488);
    CPy_DecRef(cpy_r_r489);
    CPy_DecRef(cpy_r_T1tot_dist);
    CPy_DecRef(cpy_r_T1endpt);
    CPy_DecRef(cpy_r_T1bounces);
    CPy_DecRef(cpy_r_T1prop);
    CPy_DecRef(cpy_r_T1part_id);
    goto CPyL302;
CPyL840: ;
    CPy_DECREF(cpy_r_r511);
    goto CPyL249;
CPyL841: ;
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_T4res);
    CPy_DecRef(cpy_r_r488);
    CPy_DecRef(cpy_r_r489);
    CPy_DecRef(cpy_r_T1endpt);
    CPy_DecRef(cpy_r_T1bounces);
    CPy_DecRef(cpy_r_T1prop);
    CPy_DecRef(cpy_r_T1part_id);
    goto CPyL302;
CPyL842: ;
    CPy_DECREF(cpy_r_r514);
    goto CPyL251;
CPyL843: ;
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_T4res);
    CPy_DecRef(cpy_r_r488);
    CPy_DecRef(cpy_r_r489);
    CPy_DecRef(cpy_r_T1bounces);
    CPy_DecRef(cpy_r_T1prop);
    CPy_DecRef(cpy_r_T1part_id);
    goto CPyL302;
CPyL844: ;
    CPy_DECREF(cpy_r_r517);
    goto CPyL253;
CPyL845: ;
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_T4res);
    CPy_DecRef(cpy_r_r488);
    CPy_DecRef(cpy_r_r489);
    CPy_DecRef(cpy_r_T1bounces);
    CPy_DecRef(cpy_r_T1part_id);
    goto CPyL302;
CPyL846: ;
    CPy_DECREF(cpy_r_r520);
    goto CPyL255;
CPyL847: ;
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_T4res);
    CPy_DecRef(cpy_r_r488);
    CPy_DecRef(cpy_r_r489);
    CPy_DecRef(cpy_r_T1part_id);
    goto CPyL302;
CPyL848: ;
    CPy_DECREF(cpy_r_r523);
    goto CPyL257;
CPyL849: ;
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_T4res);
    CPy_DecRef(cpy_r_r488);
    CPy_DecRef(cpy_r_r489);
    goto CPyL302;
CPyL850: ;
    CPy_DECREF(cpy_r_r526);
    goto CPyL222;
CPyL851: ;
    CPy_DecRef(cpy_r_T4part_ids);
    CPy_DecRef(cpy_r_T4res);
    goto CPyL302;
CPyL852: ;
    CPy_DecRef(cpy_r_T4part_ids);
    goto CPyL302;
CPyL853: ;
    CPy_DecRef(cpy_r_r529);
    goto CPyL302;
CPyL854: ;
    CPy_DECREF(cpy_r_r529);
    CPy_DECREF(cpy_r_r530);
    goto CPyL300;
CPyL855: ;
    CPy_DECREF(cpy_r_r529);
    CPy_DECREF(cpy_r_r530);
    CPy_DECREF(cpy_r_r531);
    goto CPyL300;
CPyL856: ;
    CPy_DecRef(cpy_r_r529);
    CPy_DecRef(cpy_r_r530);
    CPy_DecRef(cpy_r_r532);
    goto CPyL302;
CPyL857: ;
    CPy_DECREF(cpy_r_r529);
    CPy_DECREF(cpy_r_r530);
    CPy_DECREF(cpy_r_r532);
    CPy_DECREF(cpy_r_r533);
    goto CPyL267;
CPyL858: ;
    CPy_DECREF(cpy_r_logstarttime);
    CPy_DECREF(cpy_r_logendparticle);
    CPy_DECREF(cpy_r_T1_input_times);
    CPy_DECREF(cpy_r_T4_input_times);
    CPy_DECREF(cpy_r_T1photons);
    CPy_DECREF(cpy_r_T4photons);
    CPy_DECREF(cpy_r_logstartphoton);
    CPy_DECREF(cpy_r_r401);
    CPy_DECREF(cpy_r_r404);
    goto CPyL268;
CPyL859: ;
    CPy_DECREF(cpy_r_r529);
    CPy_DECREF(cpy_r_r530);
    CPy_DECREF(cpy_r_r532);
    CPy_DECREF(cpy_r_r533);
    CPy_DECREF(cpy_r_T4hit_PMT);
    goto CPyL270;
CPyL860: ;
    CPy_DECREF(cpy_r_logstarttime);
    CPy_DECREF(cpy_r_logendparticle);
    CPy_DECREF(cpy_r_T1_input_times);
    CPy_DECREF(cpy_r_T4_input_times);
    CPy_DECREF(cpy_r_T1photons);
    CPy_DECREF(cpy_r_T4photons);
    CPy_DECREF(cpy_r_logstartphoton);
    CPy_DECREF(cpy_r_r401);
    CPy_DECREF(cpy_r_r404);
    goto CPyL271;
CPyL861: ;
    CPy_DECREF(cpy_r_r529);
    CPy_DECREF(cpy_r_r530);
    CPy_DECREF(cpy_r_r532);
    CPy_DECREF(cpy_r_r533);
    CPy_DECREF(cpy_r_T4hit_PMT);
    CPy_DECREF(cpy_r_T4travel_time);
    goto CPyL273;
CPyL862: ;
    CPy_DECREF(cpy_r_logstarttime);
    CPy_DECREF(cpy_r_logendparticle);
    CPy_DECREF(cpy_r_T1_input_times);
    CPy_DECREF(cpy_r_T4_input_times);
    CPy_DECREF(cpy_r_T1photons);
    CPy_DECREF(cpy_r_T4photons);
    CPy_DECREF(cpy_r_logstartphoton);
    CPy_DECREF(cpy_r_r401);
    CPy_DECREF(cpy_r_r404);
    goto CPyL274;
CPyL863: ;
    CPy_DECREF(cpy_r_r529);
    CPy_DECREF(cpy_r_r530);
    CPy_DECREF(cpy_r_r532);
    CPy_DECREF(cpy_r_r533);
    CPy_DECREF(cpy_r_T4hit_PMT);
    CPy_DECREF(cpy_r_T4travel_time);
    CPy_DECREF(cpy_r_T4tot_dist);
    goto CPyL276;
CPyL864: ;
    CPy_DECREF(cpy_r_logstarttime);
    CPy_DECREF(cpy_r_logendparticle);
    CPy_DECREF(cpy_r_T1_input_times);
    CPy_DECREF(cpy_r_T4_input_times);
    CPy_DECREF(cpy_r_T1photons);
    CPy_DECREF(cpy_r_T4photons);
    CPy_DECREF(cpy_r_logstartphoton);
    CPy_DECREF(cpy_r_r401);
    CPy_DECREF(cpy_r_r404);
    goto CPyL277;
CPyL865: ;
    CPy_DECREF(cpy_r_r529);
    CPy_DECREF(cpy_r_r530);
    CPy_DECREF(cpy_r_r532);
    CPy_DECREF(cpy_r_r533);
    CPy_DECREF(cpy_r_T4hit_PMT);
    CPy_DECREF(cpy_r_T4travel_time);
    CPy_DECREF(cpy_r_T4tot_dist);
    CPy_DECREF(cpy_r_T4endpt);
    goto CPyL279;
CPyL866: ;
    CPy_DECREF(cpy_r_logstarttime);
    CPy_DECREF(cpy_r_logendparticle);
    CPy_DECREF(cpy_r_T1_input_times);
    CPy_DECREF(cpy_r_T4_input_times);
    CPy_DECREF(cpy_r_T1photons);
    CPy_DECREF(cpy_r_T4photons);
    CPy_DECREF(cpy_r_logstartphoton);
    CPy_DECREF(cpy_r_r401);
    CPy_DECREF(cpy_r_r404);
    goto CPyL280;
CPyL867: ;
    CPy_DECREF(cpy_r_r529);
    CPy_DECREF(cpy_r_r530);
    CPy_DECREF(cpy_r_r532);
    CPy_DECREF(cpy_r_r533);
    CPy_DECREF(cpy_r_T4hit_PMT);
    CPy_DECREF(cpy_r_T4travel_time);
    CPy_DECREF(cpy_r_T4tot_dist);
    CPy_DECREF(cpy_r_T4endpt);
    CPy_DECREF(cpy_r_T4bounces);
    goto CPyL282;
CPyL868: ;
    CPy_DECREF(cpy_r_logstarttime);
    CPy_DECREF(cpy_r_logendparticle);
    CPy_DECREF(cpy_r_T1_input_times);
    CPy_DECREF(cpy_r_T4_input_times);
    CPy_DECREF(cpy_r_T1photons);
    CPy_DECREF(cpy_r_T4photons);
    CPy_DECREF(cpy_r_logstartphoton);
    CPy_DECREF(cpy_r_r401);
    CPy_DECREF(cpy_r_r404);
    goto CPyL283;
CPyL869: ;
    CPy_DECREF(cpy_r_r529);
    CPy_DECREF(cpy_r_r530);
    CPy_DECREF(cpy_r_r532);
    CPy_DECREF(cpy_r_T4hit_PMT);
    CPy_DECREF(cpy_r_T4travel_time);
    CPy_DECREF(cpy_r_T4tot_dist);
    CPy_DECREF(cpy_r_T4endpt);
    CPy_DECREF(cpy_r_T4bounces);
    CPy_DECREF(cpy_r_T4prop);
    CPy_DECREF(cpy_r_r546);
    goto CPyL285;
CPyL870: ;
    CPy_DECREF(cpy_r_logstarttime);
    CPy_DECREF(cpy_r_logendparticle);
    CPy_DECREF(cpy_r_T1_input_times);
    CPy_DECREF(cpy_r_T4_input_times);
    CPy_DECREF(cpy_r_T1photons);
    CPy_DECREF(cpy_r_T4photons);
    CPy_DECREF(cpy_r_logstartphoton);
    CPy_DECREF(cpy_r_r401);
    CPy_DECREF(cpy_r_r404);
    goto CPyL286;
CPyL871: ;
    CPy_DecRef(cpy_r_r529);
    CPy_DecRef(cpy_r_r530);
    CPy_DecRef(cpy_r_T4travel_time);
    CPy_DecRef(cpy_r_T4tot_dist);
    CPy_DecRef(cpy_r_T4endpt);
    CPy_DecRef(cpy_r_T4bounces);
    CPy_DecRef(cpy_r_T4prop);
    CPy_DecRef(cpy_r_T4part_id);
    goto CPyL302;
CPyL872: ;
    CPy_DECREF(cpy_r_T4travel_time);
    CPy_DECREF(cpy_r_T4tot_dist);
    CPy_DECREF(cpy_r_T4endpt);
    CPy_DECREF(cpy_r_T4bounces);
    CPy_DECREF(cpy_r_T4prop);
    CPy_DECREF(cpy_r_T4part_id);
    goto CPyL263;
CPyL873: ;
    CPy_DecRef(cpy_r_r529);
    CPy_DecRef(cpy_r_r530);
    CPy_DecRef(cpy_r_T4tot_dist);
    CPy_DecRef(cpy_r_T4endpt);
    CPy_DecRef(cpy_r_T4bounces);
    CPy_DecRef(cpy_r_T4prop);
    CPy_DecRef(cpy_r_T4part_id);
    goto CPyL302;
CPyL874: ;
    CPy_DECREF(cpy_r_r552);
    goto CPyL290;
CPyL875: ;
    CPy_DecRef(cpy_r_r529);
    CPy_DecRef(cpy_r_r530);
    CPy_DecRef(cpy_r_T4endpt);
    CPy_DecRef(cpy_r_T4bounces);
    CPy_DecRef(cpy_r_T4prop);
    CPy_DecRef(cpy_r_T4part_id);
    goto CPyL302;
CPyL876: ;
    CPy_DECREF(cpy_r_r555);
    goto CPyL292;
CPyL877: ;
    CPy_DecRef(cpy_r_r529);
    CPy_DecRef(cpy_r_r530);
    CPy_DecRef(cpy_r_T4bounces);
    CPy_DecRef(cpy_r_T4prop);
    CPy_DecRef(cpy_r_T4part_id);
    goto CPyL302;
CPyL878: ;
    CPy_DECREF(cpy_r_r558);
    goto CPyL294;
CPyL879: ;
    CPy_DecRef(cpy_r_r529);
    CPy_DecRef(cpy_r_r530);
    CPy_DecRef(cpy_r_T4bounces);
    CPy_DecRef(cpy_r_T4part_id);
    goto CPyL302;
CPyL880: ;
    CPy_DECREF(cpy_r_r561);
    goto CPyL296;
CPyL881: ;
    CPy_DecRef(cpy_r_r529);
    CPy_DecRef(cpy_r_r530);
    CPy_DecRef(cpy_r_T4part_id);
    goto CPyL302;
CPyL882: ;
    CPy_DECREF(cpy_r_r564);
    goto CPyL298;
CPyL883: ;
    CPy_DecRef(cpy_r_r529);
    CPy_DecRef(cpy_r_r530);
    goto CPyL302;
CPyL884: ;
    CPy_DECREF(cpy_r_r567);
    goto CPyL263;
CPyL885: ;
    CPy_DecRef(cpy_r_r572);
    CPy_DecRef(cpy_r_r573);
    CPy_DecRef(cpy_r_r574);
    goto CPyL308;
CPyL886: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_logstartphoton);
    CPy_DecRef(cpy_r_r401);
    CPy_DecRef(cpy_r_r404);
    CPy_DecRef(cpy_r_r570.f0);
    CPy_DecRef(cpy_r_r570.f1);
    CPy_DecRef(cpy_r_r570.f2);
    goto CPyL306;
CPyL887: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_logstartphoton);
    CPy_DecRef(cpy_r_r401);
    CPy_DecRef(cpy_r_r404);
    goto CPyL309;
CPyL888: ;
    CPy_DECREF(cpy_r_r401);
    CPy_DECREF(cpy_r_r404);
    goto CPyL315;
CPyL889: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_logstartphoton);
    CPy_DecRef(cpy_r_r401);
    goto CPyL318;
CPyL890: ;
    CPy_DECREF(cpy_r_r588);
    goto CPyL314;
CPyL891: ;
    CPy_DECREF(cpy_r_logstarttime);
    CPy_DECREF(cpy_r_logendparticle);
    CPy_DECREF(cpy_r_T1_input_times);
    CPy_DECREF(cpy_r_T4_input_times);
    CPy_DECREF(cpy_r_T1photons);
    CPy_DECREF(cpy_r_T4photons);
    CPy_DECREF(cpy_r_logstartphoton);
    goto CPyL316;
CPyL892: ;
    CPy_XDECREF(cpy_r_r583.f0);
    CPy_XDECREF(cpy_r_r583.f1);
    CPy_XDECREF(cpy_r_r583.f2);
    goto CPyL317;
CPyL893: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_logstartphoton);
    goto CPyL720;
CPyL894: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_logendparticle);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_logstartphoton);
    CPy_DecRef(cpy_r_logendtime);
    goto CPyL720;
CPyL895: ;
    CPy_DECREF(cpy_r_r600);
    goto CPyL326;
CPyL896: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_logstartphoton);
    CPy_DecRef(cpy_r_logendtime);
    goto CPyL720;
CPyL897: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_logstartphoton);
    CPy_DecRef(cpy_r_logendtime);
    CPy_DecRef(cpy_r_r601);
    goto CPyL720;
CPyL898: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_logendtime);
    CPy_DecRef(cpy_r_pgtime);
    goto CPyL720;
CPyL899: ;
    CPy_DecRef(cpy_r_logstarttime);
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_logendtime);
    CPy_DecRef(cpy_r_pgtime);
    CPy_DecRef(cpy_r_r609);
    goto CPyL720;
CPyL900: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_pgtime);
    CPy_DecRef(cpy_r_phtime);
    goto CPyL720;
CPyL901: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_pgtime);
    CPy_DecRef(cpy_r_phtime);
    CPy_DecRef(cpy_r_r617);
    goto CPyL720;
CPyL902: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_phtime);
    CPy_DecRef(cpy_r_ttime);
    goto CPyL720;
CPyL903: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_phtime);
    CPy_DecRef(cpy_r_ttime);
    CPy_DecRef(cpy_r_r628);
    goto CPyL720;
CPyL904: ;
    CPy_DECREF(cpy_r_r634);
    goto CPyL340;
CPyL905: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_ttime);
    goto CPyL720;
CPyL906: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_ttime);
    CPy_DecRef(cpy_r_r638);
    goto CPyL720;
CPyL907: ;
    CPy_DECREF(cpy_r_r644);
    goto CPyL345;
CPyL908: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T4photons);
    goto CPyL720;
CPyL909: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_r648);
    goto CPyL720;
CPyL910: ;
    CPy_DECREF(cpy_r_r654);
    goto CPyL350;
CPyL911: ;
    CPy_DECREF(cpy_r_r661);
    goto CPyL352;
CPyL912: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_r664);
    goto CPyL720;
CPyL913: ;
    CPy_DECREF(cpy_r_r670);
    goto CPyL355;
CPyL914: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_r677);
    goto CPyL720;
CPyL915: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T1photons);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_r677);
    CPy_DecRef(cpy_r_r680);
    goto CPyL720;
CPyL916: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_r677);
    CPy_DecRef(cpy_r_r680);
    CPy_DecRef(cpy_r_r689);
    goto CPyL720;
CPyL917: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_r677);
    CPy_DecRef(cpy_r_r680);
    goto CPyL720;
CPyL918: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_r677);
    CPy_DecRef(cpy_r_r680);
    CPy_DecRef(cpy_r_r695);
    goto CPyL720;
CPyL919: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_r677);
    CPy_DecRef(cpy_r_r680);
    CPy_DecRef(cpy_r_r700);
    goto CPyL720;
CPyL920: ;
    CPy_DECREF(cpy_r_r706);
    goto CPyL367;
CPyL921: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T4photons);
    goto CPyL720;
CPyL922: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_r709);
    goto CPyL720;
CPyL923: ;
    CPy_DECREF(cpy_r_r715);
    goto CPyL370;
CPyL924: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_r722);
    goto CPyL720;
CPyL925: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_T4photons);
    CPy_DecRef(cpy_r_r722);
    CPy_DecRef(cpy_r_r725);
    goto CPyL720;
CPyL926: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_r722);
    CPy_DecRef(cpy_r_r725);
    CPy_DecRef(cpy_r_r734);
    goto CPyL720;
CPyL927: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_r722);
    CPy_DecRef(cpy_r_r725);
    goto CPyL720;
CPyL928: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_r722);
    CPy_DecRef(cpy_r_r725);
    CPy_DecRef(cpy_r_r740);
    goto CPyL720;
CPyL929: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_r722);
    CPy_DecRef(cpy_r_r725);
    CPy_DecRef(cpy_r_r745);
    goto CPyL720;
CPyL930: ;
    CPy_DECREF(cpy_r_r751);
    goto CPyL382;
CPyL931: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    goto CPyL720;
CPyL932: ;
    CPy_DECREF(cpy_r_r758);
    goto CPyL384;
CPyL933: ;
    CPy_DECREF(cpy_r_r768);
    goto CPyL386;
CPyL934: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_signals_channelT1);
    goto CPyL720;
CPyL935: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_signals_channelT1);
    CPy_DecRef(cpy_r_signals_channelT4);
    goto CPyL720;
CPyL936: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_signals_channelT1);
    CPy_DecRef(cpy_r_signals_channelT4);
    CPy_DecRef(cpy_r_output_times_channelT1);
    goto CPyL720;
CPyL937: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_signals_channelT1);
    CPy_DecRef(cpy_r_signals_channelT4);
    CPy_DecRef(cpy_r_output_times_channelT1);
    CPy_DecRef(cpy_r_output_times_channelT4);
    goto CPyL720;
CPyL938: ;
    CPy_DecRef(cpy_r_T1_input_times);
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_signals_channelT1);
    CPy_DecRef(cpy_r_signals_channelT4);
    CPy_DecRef(cpy_r_output_times_channelT1);
    CPy_DecRef(cpy_r_output_times_channelT4);
    CPy_DecRef(cpy_r_signals);
    goto CPyL720;
CPyL939: ;
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_signals_channelT1);
    CPy_DecRef(cpy_r_signals_channelT4);
    CPy_DecRef(cpy_r_output_times_channelT1);
    CPy_DecRef(cpy_r_output_times_channelT4);
    CPy_DecRef(cpy_r_signals);
    CPy_DecRef(cpy_r_output_times);
    goto CPyL720;
CPyL940: ;
    CPy_DECREF(cpy_r_r775);
    goto CPyL401;
CPyL941: ;
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_signals_channelT1);
    CPy_DecRef(cpy_r_signals_channelT4);
    CPy_DecRef(cpy_r_output_times_channelT1);
    CPy_DecRef(cpy_r_output_times_channelT4);
    CPy_DecRef(cpy_r_signals);
    CPy_DecRef(cpy_r_output_times);
    CPy_DecRef(cpy_r_r775);
    CPy_DecRef(cpy_r_t);
    goto CPyL720;
CPyL942: ;
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_signals_channelT1);
    CPy_DecRef(cpy_r_signals_channelT4);
    CPy_DecRef(cpy_r_output_times_channelT1);
    CPy_DecRef(cpy_r_output_times_channelT4);
    CPy_DecRef(cpy_r_signals);
    CPy_DecRef(cpy_r_output_times);
    CPy_DecRef(cpy_r_r775);
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_pmtSignal_i);
    goto CPyL720;
CPyL943: ;
    CPy_DECREF(cpy_r_r782);
    goto CPyL397;
CPyL944: ;
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_signals_channelT1);
    CPy_DecRef(cpy_r_signals_channelT4);
    CPy_DecRef(cpy_r_output_times_channelT1);
    CPy_DecRef(cpy_r_output_times_channelT4);
    CPy_DecRef(cpy_r_signals);
    CPy_DecRef(cpy_r_output_times);
    CPy_DecRef(cpy_r_r775);
    CPy_DecRef(cpy_r_pmtSignal_i);
    goto CPyL720;
CPyL945: ;
    CPy_DECREF(cpy_r_r786);
    goto CPyL399;
CPyL946: ;
    CPy_DECREF(cpy_r_r788);
    goto CPyL400;
CPyL947: ;
    CPy_DecRef(cpy_r_T4_input_times);
    CPy_DecRef(cpy_r_signals_channelT1);
    CPy_DecRef(cpy_r_signals_channelT4);
    CPy_DecRef(cpy_r_output_times_channelT1);
    CPy_DecRef(cpy_r_output_times_channelT4);
    CPy_DecRef(cpy_r_signals);
    CPy_DecRef(cpy_r_output_times);
    CPy_DecRef(cpy_r_r775);
    goto CPyL720;
CPyL948: ;
    CPy_DECREF(cpy_r_r790);
    goto CPyL393;
CPyL949: ;
    CPy_DecRef(cpy_r_signals_channelT1);
    CPy_DecRef(cpy_r_signals_channelT4);
    CPy_DecRef(cpy_r_output_times_channelT1);
    CPy_DecRef(cpy_r_output_times_channelT4);
    CPy_DecRef(cpy_r_signals);
    CPy_DecRef(cpy_r_output_times);
    goto CPyL720;
CPyL950: ;
    CPy_DECREF(cpy_r_r792);
    goto CPyL411;
CPyL951: ;
    CPy_DecRef(cpy_r_signals_channelT1);
    CPy_DecRef(cpy_r_signals_channelT4);
    CPy_DecRef(cpy_r_output_times_channelT1);
    CPy_DecRef(cpy_r_output_times_channelT4);
    CPy_DecRef(cpy_r_signals);
    CPy_DecRef(cpy_r_output_times);
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_r792);
    goto CPyL720;
CPyL952: ;
    CPy_DecRef(cpy_r_signals_channelT1);
    CPy_DecRef(cpy_r_signals_channelT4);
    CPy_DecRef(cpy_r_output_times_channelT1);
    CPy_DecRef(cpy_r_output_times_channelT4);
    CPy_DecRef(cpy_r_signals);
    CPy_DecRef(cpy_r_output_times);
    CPy_DecRef(cpy_r_t);
    CPy_DecRef(cpy_r_pmtSignal_i);
    CPy_DecRef(cpy_r_r792);
    goto CPyL720;
CPyL953: ;
    CPy_DECREF(cpy_r_r799);
    goto CPyL407;
CPyL954: ;
    CPy_DecRef(cpy_r_signals_channelT1);
    CPy_DecRef(cpy_r_signals_channelT4);
    CPy_DecRef(cpy_r_output_times_channelT1);
    CPy_DecRef(cpy_r_output_times_channelT4);
    CPy_DecRef(cpy_r_signals);
    CPy_DecRef(cpy_r_output_times);
    CPy_DecRef(cpy_r_pmtSignal_i);
    CPy_DecRef(cpy_r_r792);
    goto CPyL720;
CPyL955: ;
    CPy_DECREF(cpy_r_r803);
    goto CPyL409;
CPyL956: ;
    CPy_DECREF(cpy_r_r805);
    goto CPyL410;
CPyL957: ;
    CPy_DecRef(cpy_r_signals_channelT1);
    CPy_DecRef(cpy_r_signals_channelT4);
    CPy_DecRef(cpy_r_output_times_channelT1);
    CPy_DecRef(cpy_r_output_times_channelT4);
    CPy_DecRef(cpy_r_signals);
    CPy_DecRef(cpy_r_output_times);
    CPy_DecRef(cpy_r_r792);
    goto CPyL720;
CPyL958: ;
    CPy_DECREF(cpy_r_r807);
    goto CPyL403;
CPyL959: ;
    CPy_DecRef(cpy_r_signals_channelT1);
    CPy_DecRef(cpy_r_signals_channelT4);
    CPy_DecRef(cpy_r_output_times_channelT1);
    CPy_DecRef(cpy_r_output_times_channelT4);
    CPy_DecRef(cpy_r_output_times);
    goto CPyL720;
CPyL960: ;
    CPy_DecRef(cpy_r_signals_channelT1);
    CPy_DecRef(cpy_r_signals_channelT4);
    CPy_DecRef(cpy_r_output_times_channelT1);
    CPy_DecRef(cpy_r_output_times_channelT4);
    goto CPyL720;
CPyL961: ;
    CPy_DecRef(cpy_r_signals_channelT4);
    CPy_DecRef(cpy_r_output_times_channelT1);
    CPy_DecRef(cpy_r_output_times_channelT4);
    goto CPyL720;
CPyL962: ;
    CPy_DecRef(cpy_r_output_times_channelT1);
    CPy_DecRef(cpy_r_output_times_channelT4);
    goto CPyL720;
CPyL963: ;
    CPy_DecRef(cpy_r_output_times_channelT4);
    goto CPyL720;
CPyL964: ;
    CPy_DecRef(cpy_r_output_extra);
    goto CPyL720;
CPyL965: ;
    CPy_DecRef(cpy_r_output_both);
    goto CPyL720;
CPyL966: ;
    CPy_DECREF(cpy_r_output_both);
    goto CPyL490;
CPyL967: ;
    CPy_DECREF(cpy_r_r893);
    goto CPyL449;
CPyL968: ;
    CPy_DecRef(cpy_r_output_both);
    CPy_DecRef(cpy_r_r895);
    goto CPyL720;
CPyL969: ;
    CPy_DecRef(cpy_r_output_both);
    CPy_DecRef(cpy_r_r895);
    CPy_DecRef(cpy_r_r897);
    goto CPyL720;
CPyL970: ;
    CPy_DecRef(cpy_r_output_both);
    CPy_DecRef(cpy_r_r895);
    CPy_DecRef(cpy_r_r897);
    CPy_DecRef(cpy_r_r899);
    goto CPyL720;
CPyL971: ;
    CPy_DecRef(cpy_r_output_both);
    CPy_DecRef(cpy_r_r895);
    CPy_DecRef(cpy_r_r897);
    CPy_DecRef(cpy_r_r899);
    CPy_DecRef(cpy_r_r901);
    goto CPyL720;
CPyL972: ;
    CPy_DecRef(cpy_r_output_both);
    CPy_DecRef(cpy_r_r895);
    CPy_DecRef(cpy_r_r897);
    CPy_DecRef(cpy_r_r899);
    CPy_DecRef(cpy_r_r901);
    CPy_DecRef(cpy_r_r903);
    goto CPyL720;
CPyL973: ;
    CPy_DecRef(cpy_r_output_both);
    CPy_DecRef(cpy_r_r906);
    goto CPyL720;
CPyL974: ;
    CPy_DecRef(cpy_r_output_both);
    CPy_DecRef(cpy_r_dft1);
    goto CPyL720;
CPyL975: ;
    CPy_DecRef(cpy_r_output_both);
    CPy_DecRef(cpy_r_dft1);
    CPy_DecRef(cpy_r_r914);
    goto CPyL720;
CPyL976: ;
    CPy_DecRef(cpy_r_output_both);
    CPy_DecRef(cpy_r_dft1);
    CPy_DecRef(cpy_r_r914);
    CPy_DecRef(cpy_r_r916);
    goto CPyL720;
CPyL977: ;
    CPy_DecRef(cpy_r_output_both);
    CPy_DecRef(cpy_r_dft1);
    CPy_DecRef(cpy_r_r914);
    CPy_DecRef(cpy_r_r916);
    CPy_DecRef(cpy_r_r918);
    goto CPyL720;
CPyL978: ;
    CPy_DecRef(cpy_r_output_both);
    CPy_DecRef(cpy_r_dft1);
    CPy_DecRef(cpy_r_r914);
    CPy_DecRef(cpy_r_r916);
    CPy_DecRef(cpy_r_r918);
    CPy_DecRef(cpy_r_r920);
    goto CPyL720;
CPyL979: ;
    CPy_DecRef(cpy_r_output_both);
    CPy_DecRef(cpy_r_dft1);
    CPy_DecRef(cpy_r_r914);
    CPy_DecRef(cpy_r_r916);
    CPy_DecRef(cpy_r_r918);
    CPy_DecRef(cpy_r_r920);
    CPy_DecRef(cpy_r_r922);
    goto CPyL720;
CPyL980: ;
    CPy_DecRef(cpy_r_output_both);
    CPy_DecRef(cpy_r_dft1);
    CPy_DecRef(cpy_r_r925);
    goto CPyL720;
CPyL981: ;
    CPy_DecRef(cpy_r_output_both);
    CPy_DecRef(cpy_r_dft1);
    CPy_DecRef(cpy_r_dft4);
    goto CPyL720;
CPyL982: ;
    CPy_DecRef(cpy_r_output_both);
    CPy_DecRef(cpy_r_dft1);
    CPy_DecRef(cpy_r_dft4);
    CPy_DecRef(cpy_r_r937);
    goto CPyL720;
CPyL983: ;
    CPy_DecRef(cpy_r_output_both);
    CPy_DecRef(cpy_r_dft4);
    goto CPyL720;
CPyL984: ;
    CPy_DECREF(cpy_r_r951);
    goto CPyL477;
CPyL985: ;
    CPy_DecRef(cpy_r_output_both);
    CPy_DecRef(cpy_r_dft4);
    CPy_DecRef(cpy_r_r957);
    goto CPyL720;
CPyL986: ;
    CPy_DECREF(cpy_r_r971);
    goto CPyL487;
CPyL987: ;
    CPy_DECREF(cpy_r_r982);
    goto CPyL492;
CPyL988: ;
    CPy_DecRef(cpy_r_r983);
    goto CPyL720;
CPyL989: ;
    CPy_DecRef(cpy_r_r983);
    CPy_DecRef(cpy_r_r984);
    goto CPyL720;
CPyL990: ;
    CPy_DecRef(cpy_r_r985);
    goto CPyL720;
CPyL991: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r990);
    goto CPyL720;
CPyL992: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r990);
    CPy_DecRef(cpy_r_r991);
    goto CPyL720;
CPyL993: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    goto CPyL720;
CPyL994: ;
    CPy_DECREF(cpy_r_r985);
    CPy_DECREF(cpy_r_r992);
    CPy_DECREF(cpy_r_r997);
    goto CPyL717;
CPyL995: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_signal);
    CPy_DecRef(cpy_r_ch);
    goto CPyL720;
CPyL996: ;
    CPy_DECREF(cpy_r_r1025);
    goto CPyL505;
CPyL997: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_signal);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    goto CPyL720;
CPyL998: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    goto CPyL720;
CPyL999: ;
    CPy_DECREF(cpy_r_i);
    CPy_DECREF(cpy_r_time);
    CPy_DECREF(cpy_r_r1036);
    goto CPyL624;
CPyL1000: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    goto CPyL720;
CPyL1001: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_r1038);
    goto CPyL720;
CPyL1002: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_r1042);
    goto CPyL720;
CPyL1003: ;
    CPy_DECREF(cpy_r_r1042);
    goto CPyL515;
CPyL1004: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_lower_bound);
    goto CPyL720;
CPyL1005: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_lower_bound);
    CPy_DecRef(cpy_r_r1050);
    goto CPyL720;
CPyL1006: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_lower_bound);
    CPy_DecRef(cpy_r_r1054);
    goto CPyL720;
CPyL1007: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_lower_bound);
    CPy_DecRef(cpy_r_r1054);
    CPy_DecRef(cpy_r_r1060);
    goto CPyL720;
CPyL1008: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_lower_bound);
    CPy_DecRef(cpy_r_r1054);
    CPy_DecRef(cpy_r_r1064);
    goto CPyL720;
CPyL1009: ;
    CPy_DECREF(cpy_r_r1054);
    goto CPyL527;
CPyL1010: ;
    CPy_DECREF(cpy_r_r1064);
    goto CPyL528;
CPyL1011: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_lower_bound);
    CPy_DecRef(cpy_r_upper_bound);
    goto CPyL720;
CPyL1012: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_upper_bound);
    goto CPyL720;
CPyL1013: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_upper_bound);
    CPy_DecRef(cpy_r_r1086);
    goto CPyL720;
CPyL1014: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_lower_bound);
    CPy_DecRef(cpy_r_upper_bound);
    CPy_DecRef(cpy_r_r1091);
    goto CPyL720;
CPyL1015: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_lower_bound);
    CPy_DecRef(cpy_r_upper_bound);
    CPy_DecRef(cpy_r_r1097);
    goto CPyL720;
CPyL1016: ;
    CPy_DECREF(cpy_r_r1102);
    goto CPyL577;
CPyL1017: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_lower_bound);
    CPy_DecRef(cpy_r_upper_bound);
    CPy_DecRef(cpy_r_r1102);
    CPy_DecRef(cpy_r_x);
    goto CPyL720;
CPyL1018: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_lower_bound);
    CPy_DecRef(cpy_r_upper_bound);
    CPy_DecRef(cpy_r_r1102);
    goto CPyL720;
CPyL1019: ;
    CPy_DECREF(cpy_r_r1115);
    goto CPyL552;
CPyL1020: ;
    CPy_DECREF(cpy_r_r1118);
    goto CPyL545;
CPyL1021: ;
    CPy_DECREF(cpy_r_x);
    goto CPyL545;
CPyL1022: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_lower_bound);
    CPy_DecRef(cpy_r_upper_bound);
    CPy_DecRef(cpy_r_r1102);
    CPy_DecRef(cpy_r_x);
    CPy_DecRef(cpy_r_r1137);
    goto CPyL720;
CPyL1023: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_lower_bound);
    CPy_DecRef(cpy_r_upper_bound);
    CPy_DecRef(cpy_r_r1102);
    CPy_DecRef(cpy_r_x);
    CPy_DecRef(cpy_r_index);
    goto CPyL720;
CPyL1024: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_lower_bound);
    CPy_DecRef(cpy_r_upper_bound);
    CPy_DecRef(cpy_r_r1102);
    CPy_DecRef(cpy_r_x);
    CPy_DecRef(cpy_r_index);
    CPy_DecRef(cpy_r_r1150);
    goto CPyL720;
CPyL1025: ;
    CPy_DECREF(cpy_r_x);
    CPy_DECREF(cpy_r_index);
    goto CPyL545;
CPyL1026: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_lower_bound);
    CPy_DecRef(cpy_r_upper_bound);
    CPy_DecRef(cpy_r_r1102);
    CPy_DecRef(cpy_r_index);
    goto CPyL720;
CPyL1027: ;
    CPy_DECREF(cpy_r_r1162);
    goto CPyL576;
CPyL1028: ;
    CPy_DECREF(cpy_r_r1165);
    goto CPyL545;
CPyL1029: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_lower_bound);
    CPy_DecRef(cpy_r_upper_bound);
    CPy_DecRef(cpy_r_r1167);
    CPy_DecRef(cpy_r_i_2);
    goto CPyL720;
CPyL1030: ;
    CPy_DECREF(cpy_r_lower_bound);
    CPy_DECREF(cpy_r_i_2);
    CPy_DECREF(cpy_r_r1170);
    goto CPyL586;
CPyL1031: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_lower_bound);
    CPy_DecRef(cpy_r_upper_bound);
    CPy_DecRef(cpy_r_r1167);
    CPy_DecRef(cpy_r_i_2);
    CPy_DecRef(cpy_r_r1170);
    goto CPyL720;
CPyL1032: ;
    CPy_DECREF(cpy_r_i_2);
    goto CPyL585;
CPyL1033: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_lower_bound);
    CPy_DecRef(cpy_r_upper_bound);
    CPy_DecRef(cpy_r_r1167);
    CPy_DecRef(cpy_r_r1170);
    goto CPyL720;
CPyL1034: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_upper_bound);
    CPy_DecRef(cpy_r_r1167);
    goto CPyL720;
CPyL1035: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_upper_bound);
    CPy_DecRef(cpy_r_index_lower);
    goto CPyL720;
CPyL1036: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_upper_bound);
    CPy_DecRef(cpy_r_index_lower);
    CPy_DecRef(cpy_r_r1182);
    CPy_DecRef(cpy_r_i_3);
    goto CPyL720;
CPyL1037: ;
    CPy_DECREF(cpy_r_upper_bound);
    CPy_DECREF(cpy_r_i_3);
    CPy_DECREF(cpy_r_r1185);
    goto CPyL596;
CPyL1038: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_upper_bound);
    CPy_DecRef(cpy_r_index_lower);
    CPy_DecRef(cpy_r_r1182);
    CPy_DecRef(cpy_r_i_3);
    CPy_DecRef(cpy_r_r1185);
    goto CPyL720;
CPyL1039: ;
    CPy_DECREF(cpy_r_i_3);
    goto CPyL595;
CPyL1040: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_upper_bound);
    CPy_DecRef(cpy_r_index_lower);
    CPy_DecRef(cpy_r_r1182);
    CPy_DecRef(cpy_r_r1185);
    goto CPyL720;
CPyL1041: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_index_lower);
    CPy_DecRef(cpy_r_r1182);
    goto CPyL720;
CPyL1042: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_index_lower);
    goto CPyL720;
CPyL1043: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_index_lower);
    CPy_DecRef(cpy_r_index_upper);
    goto CPyL720;
CPyL1044: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_index_lower);
    CPy_DecRef(cpy_r_r1200);
    goto CPyL720;
CPyL1045: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_index_lower);
    CPy_DecRef(cpy_r_r1200);
    CPy_DecRef(cpy_r_r1203);
    goto CPyL720;
CPyL1046: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_index_lower);
    CPy_DecRef(cpy_r_r1203);
    CPy_DecRef(cpy_r_r1204);
    CPy_DecRef(cpy_r_r1205);
    goto CPyL720;
CPyL1047: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_y);
    CPy_DecRef(cpy_r_index_lower);
    goto CPyL720;
CPyL1048: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_index_lower);
    goto CPyL720;
CPyL1049: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_index_lower);
    goto CPyL720;
CPyL1050: ;
    CPy_DECREF(cpy_r_i);
    CPy_DECREF(cpy_r_index_lower);
    CPy_DECREF(cpy_r_r1219);
    goto CPyL622;
CPyL1051: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_index_lower);
    CPy_DecRef(cpy_r_r1219);
    CPy_DecRef(cpy_r_y_add);
    goto CPyL720;
CPyL1052: ;
    CPy_DECREF(cpy_r_y_add);
    goto CPyL619;
CPyL1053: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_index_lower);
    CPy_DecRef(cpy_r_r1219);
    CPy_DecRef(cpy_r_y_add);
    goto CPyL720;
CPyL1054: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_index_lower);
    CPy_DecRef(cpy_r_r1219);
    CPy_DecRef(cpy_r_y_add);
    CPy_DecRef(cpy_r_r1229);
    goto CPyL720;
CPyL1055: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_index_lower);
    CPy_DecRef(cpy_r_r1219);
    CPy_DecRef(cpy_r_r1229);
    goto CPyL720;
CPyL1056: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_index_lower);
    CPy_DecRef(cpy_r_r1219);
    goto CPyL720;
CPyL1057: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    CPy_DecRef(cpy_r_index_lower);
    CPy_DecRef(cpy_r_r1219);
    CPy_DecRef(cpy_r_r1234);
    goto CPyL720;
CPyL1058: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_time);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    CPy_DecRef(cpy_r_r1036);
    goto CPyL720;
CPyL1059: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_t_binned);
    CPy_DecRef(cpy_r_y_binned);
    goto CPyL720;
CPyL1060: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    goto CPyL720;
CPyL1061: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_r1246);
    goto CPyL720;
CPyL1062: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_r1252);
    goto CPyL720;
CPyL1063: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_r1254);
    goto CPyL720;
CPyL1064: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_df);
    goto CPyL720;
CPyL1065: ;
    CPy_DECREF(cpy_r_r1269);
    goto CPyL633;
CPyL1066: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_df);
    CPy_DecRef(cpy_r_fill_data);
    goto CPyL720;
CPyL1067: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_df);
    CPy_DecRef(cpy_r_fill_data);
    CPy_DecRef(cpy_r_r1276);
    goto CPyL720;
CPyL1068: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_df);
    CPy_DecRef(cpy_r_fill_data);
    CPy_DecRef(cpy_r_r1280);
    goto CPyL720;
CPyL1069: ;
    CPy_DECREF(cpy_r_r1287);
    goto CPyL641;
CPyL1070: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_df);
    CPy_DecRef(cpy_r_fill_data);
    CPy_DecRef(cpy_r_r1293);
    CPyTagged_DecRef(cpy_r_r1294);
    goto CPyL720;
CPyL1071: ;
    CPy_DECREF(cpy_r_i);
    CPy_DECREF(cpy_r_r1293);
    CPyTagged_DECREF(cpy_r_r1294);
    goto CPyL676;
CPyL1072: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_df);
    CPy_DecRef(cpy_r_fill_data);
    CPy_DecRef(cpy_r_r1293);
    CPyTagged_DecRef(cpy_r_r1294);
    CPy_DecRef(cpy_r_r1305);
    goto CPyL720;
CPyL1073: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_df);
    CPy_DecRef(cpy_r_fill_data);
    CPy_DecRef(cpy_r_r1293);
    CPyTagged_DecRef(cpy_r_r1294);
    CPy_DecRef(cpy_r_r1305);
    CPy_DecRef(cpy_r_r1309);
    goto CPyL720;
CPyL1074: ;
    CPy_DECREF(cpy_r_i);
    goto CPyL675;
CPyL1075: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_df);
    CPy_DecRef(cpy_r_fill_data);
    CPy_DecRef(cpy_r_r1293);
    CPyTagged_DecRef(cpy_r_r1294);
    CPy_DecRef(cpy_r_r1324);
    goto CPyL720;
CPyL1076: ;
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_df);
    CPy_DecRef(cpy_r_fill_data);
    CPy_DecRef(cpy_r_r1293);
    CPyTagged_DecRef(cpy_r_r1294);
    CPy_DecRef(cpy_r_r1328);
    goto CPyL720;
CPyL1077: ;
    CPy_DECREF(cpy_r_r1335);
    goto CPyL667;
CPyL1078: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_df);
    CPy_DecRef(cpy_r_fill_data);
    CPy_DecRef(cpy_r_r1293);
    CPyTagged_DecRef(cpy_r_r1294);
    CPy_DecRef(cpy_r_r1339);
    goto CPyL720;
CPyL1079: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_df);
    CPy_DecRef(cpy_r_fill_data);
    CPy_DecRef(cpy_r_r1293);
    CPyTagged_DecRef(cpy_r_r1294);
    goto CPyL720;
CPyL1080: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_df);
    CPy_DecRef(cpy_r_fill_data);
    CPy_DecRef(cpy_r_r1293);
    CPyTagged_DecRef(cpy_r_r1294);
    CPy_DecRef(cpy_r_r1342);
    goto CPyL720;
CPyL1081: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_df);
    CPy_DecRef(cpy_r_fill_data);
    CPy_DecRef(cpy_r_r1293);
    CPyTagged_DecRef(cpy_r_r1294);
    CPy_DecRef(cpy_r_r1346);
    goto CPyL720;
CPyL1082: ;
    CPy_DECREF(cpy_r_r1353);
    goto CPyL675;
CPyL1083: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_df);
    CPy_DecRef(cpy_r_fill_data);
    CPy_DecRef(cpy_r_r1361);
    goto CPyL720;
CPyL1084: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_df);
    CPy_DecRef(cpy_r_fill_data);
    CPy_DecRef(cpy_r_r1365);
    goto CPyL720;
CPyL1085: ;
    CPy_DECREF(cpy_r_r1372);
    goto CPyL683;
CPyL1086: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_df);
    CPy_DecRef(cpy_r_fill_data);
    CPy_DecRef(cpy_r_r1381);
    goto CPyL720;
CPyL1087: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_df);
    CPy_DecRef(cpy_r_fill);
    goto CPyL720;
CPyL1088: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_r1392);
    goto CPyL720;
CPyL1089: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_r1403);
    goto CPyL720;
CPyL1090: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_ch);
    CPy_DecRef(cpy_r_r1405);
    goto CPyL720;
CPyL1091: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_df);
    CPy_DecRef(cpy_r_r1440);
    goto CPyL720;
CPyL1092: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_df);
    goto CPyL720;
CPyL1093: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_df);
    CPy_DecRef(cpy_r_r1444);
    goto CPyL720;
CPyL1094: ;
    CPy_DecRef(cpy_r_r985);
    CPy_DecRef(cpy_r_r992);
    CPy_DecRef(cpy_r_r997);
    CPy_DecRef(cpy_r_r1456);
    goto CPyL720;
CPyL1095: ;
    CPy_DECREF(cpy_r_r1466);
    goto CPyL715;
CPyL1096: ;
    CPy_DECREF(cpy_r_r1476);
    goto CPyL719;
}

PyObject *CPyPy_Simulation___run(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {"%:run", kwlist, 0};
    PyObject *obj_arg;
    PyObject *obj_kwargs;
    if (!CPyArg_ParseStackAndKeywords(args, nargs, kwnames, &parser, &obj_arg, &obj_kwargs)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *arg_arg = obj_arg;
    PyObject *arg_kwargs = obj_kwargs;
    PyObject *retval = CPyDef_Simulation___run(arg_self, arg_arg, arg_kwargs);
    CPy_DECREF(obj_arg);
    CPy_DECREF(obj_kwargs);
    return retval;
fail: ;
    CPy_DECREF(obj_arg);
    CPy_DECREF(obj_kwargs);
    CPy_AddTraceback("modTof.py", "run", 390, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Simulation___time_at_thresh(PyObject *cpy_r_self, PyObject *cpy_r_rawtime, PyObject *cpy_r_rawVoltage, PyObject *cpy_r_num, PyObject *cpy_r_thresh, PyObject *cpy_r_ch) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_out;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_grad;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_limit;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_dtime;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_dtvoltage;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject **cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_tdiff;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_first_particle;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_condition_0;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_condition;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_count;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_start_index;
    CPyTagged cpy_r_r34;
    PyObject *cpy_r_r35;
    CPyTagged cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_i;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    int32_t cpy_r_r40;
    char cpy_r_r41;
    char cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    int32_t cpy_r_r46;
    char cpy_r_r47;
    char cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject **cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    int32_t cpy_r_r56;
    char cpy_r_r57;
    char cpy_r_r58;
    PyObject *cpy_r_r59;
    int32_t cpy_r_r60;
    char cpy_r_r61;
    char cpy_r_r62;
    int32_t cpy_r_r63;
    char cpy_r_r64;
    char cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_times;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_Voltages;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    CPyTagged cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    int32_t cpy_r_r84;
    char cpy_r_r85;
    char cpy_r_r86;
    CPyTagged cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    int32_t cpy_r_r91;
    char cpy_r_r92;
    char cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject **cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    char cpy_r_r104;
    PyObject *cpy_r_m;
    PyObject *cpy_r_r105;
    char cpy_r_r106;
    PyObject *cpy_r_b;
    PyObject *cpy_r_r107;
    char cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject *cpy_r_r113;
    PyObject *cpy_r_r114;
    CPyTagged cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject *cpy_r_r121;
    PyObject *cpy_r_r122;
    PyObject **cpy_r_r124;
    PyObject *cpy_r_r125;
    PyObject *cpy_r_r126;
    int32_t cpy_r_r127;
    char cpy_r_r128;
    char cpy_r_r129;
    PyObject *cpy_r_r130;
    PyObject *cpy_r_r131;
    PyObject *cpy_r_r132;
    PyObject *cpy_r_r133;
    PyObject *cpy_r_r134;
    PyObject *cpy_r_r135;
    PyObject **cpy_r_r137;
    PyObject *cpy_r_r138;
    PyObject *cpy_r_r139;
    PyObject *cpy_r_r140;
    PyObject *cpy_r_r141;
    PyObject *cpy_r_r142;
    PyObject **cpy_r_r144;
    PyObject *cpy_r_r145;
    PyObject *cpy_r_r146;
    PyObject *cpy_r_r147;
    PyObject *cpy_r_r148;
    PyObject **cpy_r_r150;
    PyObject *cpy_r_r151;
    PyObject *cpy_r_r152;
    cpy_r_r0 = PyList_New(0);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 606, CPyStatic_globals);
        goto CPyL84;
    }
    cpy_r_out = cpy_r_r0;
    cpy_r_r1 = CPyModule_numpy;
    cpy_r_r2 = CPyStatics[150]; /* 'gradient' */
    cpy_r_r3 = CPyObject_GetAttr(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 607, CPyStatic_globals);
        goto CPyL85;
    }
    PyObject *cpy_r_r4[1] = {cpy_r_rawVoltage};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = _PyObject_Vectorcall(cpy_r_r3, cpy_r_r5, 1, 0);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 607, CPyStatic_globals);
        goto CPyL85;
    }
    cpy_r_grad = cpy_r_r6;
    cpy_r_r7 = CPyStatics[244]; /* 0 */
    cpy_r_r8 = PyObject_RichCompare(cpy_r_grad, cpy_r_r7, 4);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 608, CPyStatic_globals);
        goto CPyL86;
    }
    cpy_r_r9 = PyFloat_FromDouble(0.1);
    cpy_r_r10 = PyObject_RichCompare(cpy_r_grad, cpy_r_r9, 5);
    CPy_DECREF(cpy_r_r9);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 608, CPyStatic_globals);
        goto CPyL87;
    }
    cpy_r_r11 = PyNumber_And(cpy_r_r8, cpy_r_r10);
    CPy_DECREF(cpy_r_r8);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 608, CPyStatic_globals);
        goto CPyL86;
    }
    cpy_r_limit = cpy_r_r11;
    cpy_r_r12 = PyObject_GetItem(cpy_r_rawtime, cpy_r_limit);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 609, CPyStatic_globals);
        goto CPyL88;
    }
    cpy_r_dtime = cpy_r_r12;
    cpy_r_r13 = PyObject_GetItem(cpy_r_rawVoltage, cpy_r_limit);
    CPy_DECREF(cpy_r_limit);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 610, CPyStatic_globals);
        goto CPyL89;
    }
    cpy_r_dtvoltage = cpy_r_r13;
    cpy_r_r14 = CPyModule_numpy;
    cpy_r_r15 = CPyStatics[151]; /* 'diff' */
    cpy_r_r16 = CPyObject_GetAttr(cpy_r_r14, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 611, CPyStatic_globals);
        goto CPyL90;
    }
    PyObject *cpy_r_r17[1] = {cpy_r_dtime};
    cpy_r_r18 = (PyObject **)&cpy_r_r17;
    cpy_r_r19 = _PyObject_Vectorcall(cpy_r_r16, cpy_r_r18, 1, 0);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 611, CPyStatic_globals);
        goto CPyL90;
    }
    cpy_r_tdiff = cpy_r_r19;
    cpy_r_r20 = 1 ? Py_True : Py_False;
    CPy_INCREF(cpy_r_r20);
    cpy_r_first_particle = cpy_r_r20;
    cpy_r_r21 = CPyStatics[244]; /* 0 */
    cpy_r_r22 = PyObject_RichCompare(cpy_r_grad, cpy_r_r21, 4);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 613, CPyStatic_globals);
        goto CPyL91;
    }
    cpy_r_r23 = PyFloat_FromDouble(0.001);
    cpy_r_r24 = PyObject_RichCompare(cpy_r_grad, cpy_r_r23, 0);
    CPy_DECREF(cpy_r_grad);
    CPy_DECREF(cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 613, CPyStatic_globals);
        goto CPyL92;
    }
    cpy_r_r25 = PyNumber_And(cpy_r_r22, cpy_r_r24);
    CPy_DECREF(cpy_r_r22);
    CPy_DECREF(cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 613, CPyStatic_globals);
        goto CPyL93;
    }
    cpy_r_condition_0 = cpy_r_r25;
    cpy_r_r26 = ((modTof___SimulationObject *)cpy_r_self)->_seperation_time;
    CPy_INCREF(cpy_r_r26);
    cpy_r_r27 = PyFloat_FromDouble(1000000000000.0);
    cpy_r_r28 = PyNumber_TrueDivide(cpy_r_r26, cpy_r_r27);
    CPy_DECREF(cpy_r_r26);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 614, CPyStatic_globals);
        goto CPyL94;
    }
    cpy_r_r29 = CPyStatics[258]; /* 10 */
    cpy_r_r30 = PyNumber_TrueDivide(cpy_r_r28, cpy_r_r29);
    CPy_DECREF(cpy_r_r28);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 614, CPyStatic_globals);
        goto CPyL94;
    }
    cpy_r_r31 = PyObject_RichCompare(cpy_r_tdiff, cpy_r_r30, 4);
    CPy_DECREF(cpy_r_r30);
    if (unlikely(cpy_r_r31 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 614, CPyStatic_globals);
        goto CPyL94;
    }
    cpy_r_condition = cpy_r_r31;
    cpy_r_r32 = CPyStatics[244]; /* 0 */
    CPy_INCREF(cpy_r_r32);
    cpy_r_count = cpy_r_r32;
    cpy_r_r33 = CPyStatics[244]; /* 0 */
    CPy_INCREF(cpy_r_r33);
    cpy_r_start_index = cpy_r_r33;
    cpy_r_r34 = CPyObject_Size(cpy_r_tdiff);
    CPy_DECREF(cpy_r_tdiff);
    if (unlikely(cpy_r_r34 == CPY_INT_TAG)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 617, CPyStatic_globals);
        goto CPyL95;
    }
    cpy_r_r35 = CPyTagged_StealAsObject(cpy_r_r34);
    cpy_r_r36 = 0;
    CPyTagged_INCREF(cpy_r_r36);
    cpy_r_r37 = CPyTagged_StealAsObject(cpy_r_r36);
    cpy_r_i = cpy_r_r37;
CPyL18: ;
    CPyTagged_INCREF(cpy_r_r36);
    cpy_r_r38 = CPyTagged_StealAsObject(cpy_r_r36);
    cpy_r_r39 = PyObject_RichCompare(cpy_r_r38, cpy_r_r35, 0);
    CPy_DECREF(cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 617, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r40 = PyObject_IsTrue(cpy_r_r39);
    CPy_DECREF(cpy_r_r39);
    cpy_r_r41 = cpy_r_r40 >= 0;
    if (unlikely(!cpy_r_r41)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 617, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r42 = cpy_r_r40;
    if (!cpy_r_r42) goto CPyL97;
    cpy_r_r43 = CPyStatics[247]; /* 1 */
    cpy_r_r44 = PyNumber_Subtract(cpy_r_num, cpy_r_r43);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 618, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r45 = PyObject_RichCompare(cpy_r_count, cpy_r_r44, 4);
    CPy_DECREF(cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 618, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r46 = PyObject_IsTrue(cpy_r_r45);
    CPy_DECREF(cpy_r_r45);
    cpy_r_r47 = cpy_r_r46 >= 0;
    if (unlikely(!cpy_r_r47)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 618, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r48 = cpy_r_r46;
    if (cpy_r_r48) {
        goto CPyL98;
    } else
        goto CPyL28;
CPyL25: ;
    cpy_r_r49 = CPyModule_numpy;
    cpy_r_r50 = CPyStatics[32]; /* 'array' */
    cpy_r_r51 = CPyObject_GetAttr(cpy_r_r49, cpy_r_r50);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 619, CPyStatic_globals);
        goto CPyL85;
    }
    PyObject *cpy_r_r52[1] = {cpy_r_out};
    cpy_r_r53 = (PyObject **)&cpy_r_r52;
    cpy_r_r54 = _PyObject_Vectorcall(cpy_r_r51, cpy_r_r53, 1, 0);
    CPy_DECREF(cpy_r_r51);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 619, CPyStatic_globals);
        goto CPyL85;
    }
    CPy_DECREF(cpy_r_out);
    return cpy_r_r54;
CPyL28: ;
    cpy_r_r55 = PyObject_GetItem(cpy_r_condition, cpy_r_i);
    if (unlikely(cpy_r_r55 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 620, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r56 = PyObject_IsTrue(cpy_r_r55);
    CPy_DECREF(cpy_r_r55);
    cpy_r_r57 = cpy_r_r56 >= 0;
    if (unlikely(!cpy_r_r57)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 620, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r58 = cpy_r_r56;
    if (cpy_r_r58) goto CPyL34;
    cpy_r_r59 = PyObject_GetItem(cpy_r_condition_0, cpy_r_i);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 620, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r60 = PyObject_IsTrue(cpy_r_r59);
    CPy_DECREF(cpy_r_r59);
    cpy_r_r61 = cpy_r_r60 >= 0;
    if (unlikely(!cpy_r_r61)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 620, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r62 = cpy_r_r60;
    if (!cpy_r_r62) goto CPyL99;
CPyL34: ;
    cpy_r_r63 = PyObject_IsTrue(cpy_r_first_particle);
    cpy_r_r64 = cpy_r_r63 >= 0;
    if (unlikely(!cpy_r_r64)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 612, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r65 = cpy_r_r63;
    if (cpy_r_r65) {
        goto CPyL100;
    } else
        goto CPyL37;
CPyL36: ;
    cpy_r_r66 = 0 ? Py_True : Py_False;
    CPy_INCREF(cpy_r_r66);
    cpy_r_condition_0 = cpy_r_r66;
    cpy_r_r67 = 0 ? Py_True : Py_False;
    CPy_INCREF(cpy_r_r67);
    cpy_r_first_particle = cpy_r_r67;
CPyL37: ;
    cpy_r_r68 = CPyStatics[247]; /* 1 */
    cpy_r_r69 = PyNumber_Add(cpy_r_i, cpy_r_r68);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 624, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r70 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r71 = PySlice_New(cpy_r_start_index, cpy_r_r69, cpy_r_r70);
    CPy_DECREF(cpy_r_r69);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 624, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_r72 = PyObject_GetItem(cpy_r_dtime, cpy_r_r71);
    CPy_DECREF(cpy_r_r71);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 624, CPyStatic_globals);
        goto CPyL96;
    }
    cpy_r_times = cpy_r_r72;
    cpy_r_r73 = CPyStatics[247]; /* 1 */
    cpy_r_r74 = PyNumber_Add(cpy_r_i, cpy_r_r73);
    if (unlikely(cpy_r_r74 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 625, CPyStatic_globals);
        goto CPyL101;
    }
    cpy_r_r75 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r76 = PySlice_New(cpy_r_start_index, cpy_r_r74, cpy_r_r75);
    CPy_DECREF(cpy_r_start_index);
    CPy_DECREF(cpy_r_r74);
    if (unlikely(cpy_r_r76 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 625, CPyStatic_globals);
        goto CPyL102;
    }
    cpy_r_r77 = PyObject_GetItem(cpy_r_dtvoltage, cpy_r_r76);
    CPy_DECREF(cpy_r_r76);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 625, CPyStatic_globals);
        goto CPyL102;
    }
    cpy_r_Voltages = cpy_r_r77;
    cpy_r_r78 = CPyStatics[247]; /* 1 */
    cpy_r_r79 = PyNumber_Add(cpy_r_i, cpy_r_r78);
    CPy_DECREF(cpy_r_i);
    if (unlikely(cpy_r_r79 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 626, CPyStatic_globals);
        goto CPyL103;
    }
    cpy_r_start_index = cpy_r_r79;
    cpy_r_r80 = CPyObject_Size(cpy_r_times);
    if (unlikely(cpy_r_r80 == CPY_INT_TAG)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 627, CPyStatic_globals);
        goto CPyL104;
    }
    cpy_r_r81 = CPyTagged_StealAsObject(cpy_r_r80);
    cpy_r_r82 = CPyStatics[247]; /* 1 */
    cpy_r_r83 = PyObject_RichCompare(cpy_r_r81, cpy_r_r82, 0);
    CPy_DECREF(cpy_r_r81);
    if (unlikely(cpy_r_r83 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 627, CPyStatic_globals);
        goto CPyL104;
    }
    cpy_r_r84 = PyObject_IsTrue(cpy_r_r83);
    CPy_DECREF(cpy_r_r83);
    cpy_r_r85 = cpy_r_r84 >= 0;
    if (unlikely(!cpy_r_r85)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 627, CPyStatic_globals);
        goto CPyL104;
    }
    cpy_r_r86 = cpy_r_r84;
    if (cpy_r_r86) goto CPyL105;
    cpy_r_r87 = CPyObject_Size(cpy_r_Voltages);
    if (unlikely(cpy_r_r87 == CPY_INT_TAG)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 627, CPyStatic_globals);
        goto CPyL104;
    }
    cpy_r_r88 = CPyTagged_StealAsObject(cpy_r_r87);
    cpy_r_r89 = CPyStatics[247]; /* 1 */
    cpy_r_r90 = PyObject_RichCompare(cpy_r_r88, cpy_r_r89, 0);
    CPy_DECREF(cpy_r_r88);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 627, CPyStatic_globals);
        goto CPyL104;
    }
    cpy_r_r91 = PyObject_IsTrue(cpy_r_r90);
    CPy_DECREF(cpy_r_r90);
    cpy_r_r92 = cpy_r_r91 >= 0;
    if (unlikely(!cpy_r_r92)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 627, CPyStatic_globals);
        goto CPyL104;
    }
    cpy_r_r93 = cpy_r_r91;
    if (cpy_r_r93) goto CPyL105;
    cpy_r_r94 = CPyModule_numpy;
    cpy_r_r95 = CPyStatics[152]; /* 'polyfit' */
    cpy_r_r96 = CPyObject_GetAttr(cpy_r_r94, cpy_r_r95);
    if (unlikely(cpy_r_r96 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 629, CPyStatic_globals);
        goto CPyL104;
    }
    cpy_r_r97 = CPyStatics[247]; /* 1 */
    PyObject *cpy_r_r98[3] = {cpy_r_times, cpy_r_Voltages, cpy_r_r97};
    cpy_r_r99 = (PyObject **)&cpy_r_r98;
    cpy_r_r100 = CPyStatics[275]; /* ('deg',) */
    cpy_r_r101 = _PyObject_Vectorcall(cpy_r_r96, cpy_r_r99, 2, cpy_r_r100);
    CPy_DECREF(cpy_r_r96);
    if (unlikely(cpy_r_r101 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 629, CPyStatic_globals);
        goto CPyL104;
    }
    CPy_DECREF(cpy_r_times);
    CPy_DECREF(cpy_r_Voltages);
    cpy_r_r102 = PyObject_GetIter(cpy_r_r101);
    CPy_DECREF(cpy_r_r101);
    if (unlikely(cpy_r_r102 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 629, CPyStatic_globals);
        goto CPyL106;
    }
    cpy_r_r103 = PyIter_Next(cpy_r_r102);
    if (cpy_r_r103 == NULL) {
        goto CPyL107;
    } else
        goto CPyL58;
CPyL56: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r104 = 0;
    if (unlikely(!cpy_r_r104)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 629, CPyStatic_globals);
        goto CPyL84;
    }
    CPy_Unreachable();
CPyL58: ;
    cpy_r_m = cpy_r_r103;
    cpy_r_r105 = PyIter_Next(cpy_r_r102);
    if (cpy_r_r105 == NULL) {
        goto CPyL108;
    } else
        goto CPyL61;
CPyL59: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r106 = 0;
    if (unlikely(!cpy_r_r106)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 629, CPyStatic_globals);
        goto CPyL84;
    }
    CPy_Unreachable();
CPyL61: ;
    cpy_r_b = cpy_r_r105;
    cpy_r_r107 = PyIter_Next(cpy_r_r102);
    CPy_DECREF(cpy_r_r102);
    if (cpy_r_r107 == NULL) {
        goto CPyL64;
    } else
        goto CPyL109;
CPyL62: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r108 = 0;
    if (unlikely(!cpy_r_r108)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 629, CPyStatic_globals);
        goto CPyL84;
    }
    CPy_Unreachable();
CPyL64: ;
    cpy_r_r109 = PyNumber_Subtract(cpy_r_thresh, cpy_r_b);
    CPy_DECREF(cpy_r_b);
    if (unlikely(cpy_r_r109 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 633, CPyStatic_globals);
        goto CPyL110;
    }
    cpy_r_r110 = PyNumber_TrueDivide(cpy_r_r109, cpy_r_m);
    CPy_DECREF(cpy_r_r109);
    CPy_DECREF(cpy_r_m);
    if (unlikely(cpy_r_r110 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 633, CPyStatic_globals);
        goto CPyL106;
    }
    cpy_r_r111 = CPyStatics[43]; /* 'append' */
    cpy_r_r112 = CPyObject_CallMethodObjArgs(cpy_r_out, cpy_r_r111, cpy_r_r110, NULL);
    CPy_DECREF(cpy_r_r110);
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 633, CPyStatic_globals);
        goto CPyL106;
    } else
        goto CPyL111;
CPyL67: ;
    cpy_r_r113 = CPyStatics[247]; /* 1 */
    cpy_r_r114 = PyNumber_InPlaceAdd(cpy_r_count, cpy_r_r113);
    CPy_DECREF(cpy_r_count);
    if (unlikely(cpy_r_r114 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 634, CPyStatic_globals);
        goto CPyL112;
    }
    cpy_r_count = cpy_r_r114;
CPyL69: ;
    cpy_r_r115 = CPyTagged_Add(cpy_r_r36, 2);
    CPyTagged_DECREF(cpy_r_r36);
    CPyTagged_INCREF(cpy_r_r115);
    cpy_r_r36 = cpy_r_r115;
    cpy_r_r116 = CPyTagged_StealAsObject(cpy_r_r115);
    cpy_r_i = cpy_r_r116;
    goto CPyL18;
CPyL70: ;
    cpy_r_r117 = CPyStatics[154]; /* 'Ch' */
    cpy_r_r118 = CPyStatics[155]; /* 'counted' */
    cpy_r_r119 = CPyStatics[156]; /* 'particles!' */
    cpy_r_r120 = CPyModule_builtins;
    cpy_r_r121 = CPyStatics[8]; /* 'print' */
    cpy_r_r122 = CPyObject_GetAttr(cpy_r_r120, cpy_r_r121);
    if (unlikely(cpy_r_r122 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 636, CPyStatic_globals);
        goto CPyL113;
    }
    PyObject *cpy_r_r123[5] = {cpy_r_r117, cpy_r_ch, cpy_r_r118, cpy_r_count, cpy_r_r119};
    cpy_r_r124 = (PyObject **)&cpy_r_r123;
    cpy_r_r125 = _PyObject_Vectorcall(cpy_r_r122, cpy_r_r124, 5, 0);
    CPy_DECREF(cpy_r_r122);
    if (unlikely(cpy_r_r125 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 636, CPyStatic_globals);
        goto CPyL113;
    } else
        goto CPyL114;
CPyL72: ;
    cpy_r_r126 = PyObject_RichCompare(cpy_r_count, cpy_r_num, 0);
    CPy_DECREF(cpy_r_count);
    if (unlikely(cpy_r_r126 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 637, CPyStatic_globals);
        goto CPyL85;
    }
    cpy_r_r127 = PyObject_IsTrue(cpy_r_r126);
    CPy_DECREF(cpy_r_r126);
    cpy_r_r128 = cpy_r_r127 >= 0;
    if (unlikely(!cpy_r_r128)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 637, CPyStatic_globals);
        goto CPyL85;
    }
    cpy_r_r129 = cpy_r_r127;
    if (!cpy_r_r129) goto CPyL81;
    cpy_r_r130 = CPyStatics[157]; /* 'Note: Counted less particles than the expected ' */
    cpy_r_r131 = PyObject_Str(cpy_r_num);
    if (unlikely(cpy_r_r131 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 638, CPyStatic_globals);
        goto CPyL85;
    }
    cpy_r_r132 = CPyStr_Build(2, cpy_r_r130, cpy_r_r131);
    CPy_DECREF(cpy_r_r131);
    if (unlikely(cpy_r_r132 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 638, CPyStatic_globals);
        goto CPyL85;
    }
    cpy_r_r133 = CPyModule_builtins;
    cpy_r_r134 = CPyStatics[8]; /* 'print' */
    cpy_r_r135 = CPyObject_GetAttr(cpy_r_r133, cpy_r_r134);
    if (unlikely(cpy_r_r135 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 638, CPyStatic_globals);
        goto CPyL115;
    }
    PyObject *cpy_r_r136[1] = {cpy_r_r132};
    cpy_r_r137 = (PyObject **)&cpy_r_r136;
    cpy_r_r138 = _PyObject_Vectorcall(cpy_r_r135, cpy_r_r137, 1, 0);
    CPy_DECREF(cpy_r_r135);
    if (unlikely(cpy_r_r138 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 638, CPyStatic_globals);
        goto CPyL115;
    } else
        goto CPyL116;
CPyL79: ;
    CPy_DECREF(cpy_r_r132);
    cpy_r_r139 = CPyStatics[158]; /* 'Check LTSpice that all particles were simulated.' */
    cpy_r_r140 = CPyModule_builtins;
    cpy_r_r141 = CPyStatics[8]; /* 'print' */
    cpy_r_r142 = CPyObject_GetAttr(cpy_r_r140, cpy_r_r141);
    if (unlikely(cpy_r_r142 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 639, CPyStatic_globals);
        goto CPyL85;
    }
    PyObject *cpy_r_r143[1] = {cpy_r_r139};
    cpy_r_r144 = (PyObject **)&cpy_r_r143;
    cpy_r_r145 = _PyObject_Vectorcall(cpy_r_r142, cpy_r_r144, 1, 0);
    CPy_DECREF(cpy_r_r142);
    if (unlikely(cpy_r_r145 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 639, CPyStatic_globals);
        goto CPyL85;
    } else
        goto CPyL117;
CPyL81: ;
    cpy_r_r146 = CPyModule_numpy;
    cpy_r_r147 = CPyStatics[32]; /* 'array' */
    cpy_r_r148 = CPyObject_GetAttr(cpy_r_r146, cpy_r_r147);
    if (unlikely(cpy_r_r148 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 640, CPyStatic_globals);
        goto CPyL85;
    }
    PyObject *cpy_r_r149[1] = {cpy_r_out};
    cpy_r_r150 = (PyObject **)&cpy_r_r149;
    cpy_r_r151 = _PyObject_Vectorcall(cpy_r_r148, cpy_r_r150, 1, 0);
    CPy_DECREF(cpy_r_r148);
    if (unlikely(cpy_r_r151 == NULL)) {
        CPy_AddTraceback("modTof.py", "time_at_thresh", 640, CPyStatic_globals);
        goto CPyL85;
    }
    CPy_DECREF(cpy_r_out);
    return cpy_r_r151;
CPyL84: ;
    cpy_r_r152 = NULL;
    return cpy_r_r152;
CPyL85: ;
    CPy_DecRef(cpy_r_out);
    goto CPyL84;
CPyL86: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_grad);
    goto CPyL84;
CPyL87: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_grad);
    CPy_DecRef(cpy_r_r8);
    goto CPyL84;
CPyL88: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_grad);
    CPy_DecRef(cpy_r_limit);
    goto CPyL84;
CPyL89: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_grad);
    CPy_DecRef(cpy_r_dtime);
    goto CPyL84;
CPyL90: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_grad);
    CPy_DecRef(cpy_r_dtime);
    CPy_DecRef(cpy_r_dtvoltage);
    goto CPyL84;
CPyL91: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_grad);
    CPy_DecRef(cpy_r_dtime);
    CPy_DecRef(cpy_r_dtvoltage);
    CPy_DecRef(cpy_r_tdiff);
    CPy_DecRef(cpy_r_first_particle);
    goto CPyL84;
CPyL92: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_dtime);
    CPy_DecRef(cpy_r_dtvoltage);
    CPy_DecRef(cpy_r_tdiff);
    CPy_DecRef(cpy_r_first_particle);
    CPy_DecRef(cpy_r_r22);
    goto CPyL84;
CPyL93: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_dtime);
    CPy_DecRef(cpy_r_dtvoltage);
    CPy_DecRef(cpy_r_tdiff);
    CPy_DecRef(cpy_r_first_particle);
    goto CPyL84;
CPyL94: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_dtime);
    CPy_DecRef(cpy_r_dtvoltage);
    CPy_DecRef(cpy_r_tdiff);
    CPy_DecRef(cpy_r_first_particle);
    CPy_DecRef(cpy_r_condition_0);
    goto CPyL84;
CPyL95: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_dtime);
    CPy_DecRef(cpy_r_dtvoltage);
    CPy_DecRef(cpy_r_first_particle);
    CPy_DecRef(cpy_r_condition_0);
    CPy_DecRef(cpy_r_condition);
    CPy_DecRef(cpy_r_count);
    CPy_DecRef(cpy_r_start_index);
    goto CPyL84;
CPyL96: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_dtime);
    CPy_DecRef(cpy_r_dtvoltage);
    CPy_DecRef(cpy_r_first_particle);
    CPy_DecRef(cpy_r_condition_0);
    CPy_DecRef(cpy_r_condition);
    CPy_DecRef(cpy_r_count);
    CPy_DecRef(cpy_r_start_index);
    CPy_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_r36);
    CPy_DecRef(cpy_r_i);
    goto CPyL84;
CPyL97: ;
    CPy_DECREF(cpy_r_dtime);
    CPy_DECREF(cpy_r_dtvoltage);
    CPy_DECREF(cpy_r_first_particle);
    CPy_DECREF(cpy_r_condition_0);
    CPy_DECREF(cpy_r_condition);
    CPy_DECREF(cpy_r_start_index);
    CPy_DECREF(cpy_r_r35);
    CPyTagged_DECREF(cpy_r_r36);
    CPy_DECREF(cpy_r_i);
    goto CPyL70;
CPyL98: ;
    CPy_DECREF(cpy_r_dtime);
    CPy_DECREF(cpy_r_dtvoltage);
    CPy_DECREF(cpy_r_first_particle);
    CPy_DECREF(cpy_r_condition_0);
    CPy_DECREF(cpy_r_condition);
    CPy_DECREF(cpy_r_count);
    CPy_DECREF(cpy_r_start_index);
    CPy_DECREF(cpy_r_r35);
    CPyTagged_DECREF(cpy_r_r36);
    CPy_DECREF(cpy_r_i);
    goto CPyL25;
CPyL99: ;
    CPy_DECREF(cpy_r_i);
    goto CPyL69;
CPyL100: ;
    CPy_DECREF(cpy_r_first_particle);
    CPy_DECREF(cpy_r_condition_0);
    goto CPyL36;
CPyL101: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_dtime);
    CPy_DecRef(cpy_r_dtvoltage);
    CPy_DecRef(cpy_r_first_particle);
    CPy_DecRef(cpy_r_condition_0);
    CPy_DecRef(cpy_r_condition);
    CPy_DecRef(cpy_r_count);
    CPy_DecRef(cpy_r_start_index);
    CPy_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_r36);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_times);
    goto CPyL84;
CPyL102: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_dtime);
    CPy_DecRef(cpy_r_dtvoltage);
    CPy_DecRef(cpy_r_first_particle);
    CPy_DecRef(cpy_r_condition_0);
    CPy_DecRef(cpy_r_condition);
    CPy_DecRef(cpy_r_count);
    CPy_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_r36);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_times);
    goto CPyL84;
CPyL103: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_dtime);
    CPy_DecRef(cpy_r_dtvoltage);
    CPy_DecRef(cpy_r_first_particle);
    CPy_DecRef(cpy_r_condition_0);
    CPy_DecRef(cpy_r_condition);
    CPy_DecRef(cpy_r_count);
    CPy_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_r36);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_Voltages);
    goto CPyL84;
CPyL104: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_dtime);
    CPy_DecRef(cpy_r_dtvoltage);
    CPy_DecRef(cpy_r_first_particle);
    CPy_DecRef(cpy_r_condition_0);
    CPy_DecRef(cpy_r_condition);
    CPy_DecRef(cpy_r_count);
    CPy_DecRef(cpy_r_start_index);
    CPy_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_r36);
    CPy_DecRef(cpy_r_times);
    CPy_DecRef(cpy_r_Voltages);
    goto CPyL84;
CPyL105: ;
    CPy_DECREF(cpy_r_times);
    CPy_DECREF(cpy_r_Voltages);
    goto CPyL69;
CPyL106: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_dtime);
    CPy_DecRef(cpy_r_dtvoltage);
    CPy_DecRef(cpy_r_first_particle);
    CPy_DecRef(cpy_r_condition_0);
    CPy_DecRef(cpy_r_condition);
    CPy_DecRef(cpy_r_count);
    CPy_DecRef(cpy_r_start_index);
    CPy_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_r36);
    goto CPyL84;
CPyL107: ;
    CPy_DECREF(cpy_r_out);
    CPy_DECREF(cpy_r_dtime);
    CPy_DECREF(cpy_r_dtvoltage);
    CPy_DECREF(cpy_r_first_particle);
    CPy_DECREF(cpy_r_condition_0);
    CPy_DECREF(cpy_r_condition);
    CPy_DECREF(cpy_r_count);
    CPy_DECREF(cpy_r_start_index);
    CPy_DECREF(cpy_r_r35);
    CPyTagged_DECREF(cpy_r_r36);
    CPy_DECREF(cpy_r_r102);
    goto CPyL56;
CPyL108: ;
    CPy_DECREF(cpy_r_out);
    CPy_DECREF(cpy_r_dtime);
    CPy_DECREF(cpy_r_dtvoltage);
    CPy_DECREF(cpy_r_first_particle);
    CPy_DECREF(cpy_r_condition_0);
    CPy_DECREF(cpy_r_condition);
    CPy_DECREF(cpy_r_count);
    CPy_DECREF(cpy_r_start_index);
    CPy_DECREF(cpy_r_r35);
    CPyTagged_DECREF(cpy_r_r36);
    CPy_DECREF(cpy_r_r102);
    CPy_DECREF(cpy_r_m);
    goto CPyL59;
CPyL109: ;
    CPy_DECREF(cpy_r_out);
    CPy_DECREF(cpy_r_dtime);
    CPy_DECREF(cpy_r_dtvoltage);
    CPy_DECREF(cpy_r_first_particle);
    CPy_DECREF(cpy_r_condition_0);
    CPy_DECREF(cpy_r_condition);
    CPy_DECREF(cpy_r_count);
    CPy_DECREF(cpy_r_start_index);
    CPy_DECREF(cpy_r_r35);
    CPyTagged_DECREF(cpy_r_r36);
    CPy_DECREF(cpy_r_m);
    CPy_DECREF(cpy_r_b);
    CPy_DECREF(cpy_r_r107);
    goto CPyL62;
CPyL110: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_dtime);
    CPy_DecRef(cpy_r_dtvoltage);
    CPy_DecRef(cpy_r_first_particle);
    CPy_DecRef(cpy_r_condition_0);
    CPy_DecRef(cpy_r_condition);
    CPy_DecRef(cpy_r_count);
    CPy_DecRef(cpy_r_start_index);
    CPy_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_r36);
    CPy_DecRef(cpy_r_m);
    goto CPyL84;
CPyL111: ;
    CPy_DECREF(cpy_r_r112);
    goto CPyL67;
CPyL112: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_dtime);
    CPy_DecRef(cpy_r_dtvoltage);
    CPy_DecRef(cpy_r_first_particle);
    CPy_DecRef(cpy_r_condition_0);
    CPy_DecRef(cpy_r_condition);
    CPy_DecRef(cpy_r_start_index);
    CPy_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_r36);
    goto CPyL84;
CPyL113: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_count);
    goto CPyL84;
CPyL114: ;
    CPy_DECREF(cpy_r_r125);
    goto CPyL72;
CPyL115: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_r132);
    goto CPyL84;
CPyL116: ;
    CPy_DECREF(cpy_r_r138);
    goto CPyL79;
CPyL117: ;
    CPy_DECREF(cpy_r_r145);
    goto CPyL81;
}

PyObject *CPyPy_Simulation___time_at_thresh(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"rawtime", "rawVoltage", "num", "thresh", "ch", 0};
    static CPyArg_Parser parser = {"OOOOO:time_at_thresh", kwlist, 0};
    PyObject *obj_rawtime;
    PyObject *obj_rawVoltage;
    PyObject *obj_num;
    PyObject *obj_thresh;
    PyObject *obj_ch;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_rawtime, &obj_rawVoltage, &obj_num, &obj_thresh, &obj_ch)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *arg_rawtime = obj_rawtime;
    PyObject *arg_rawVoltage = obj_rawVoltage;
    PyObject *arg_num = obj_num;
    PyObject *arg_thresh = obj_thresh;
    PyObject *arg_ch = obj_ch;
    PyObject *retval = CPyDef_Simulation___time_at_thresh(arg_self, arg_rawtime, arg_rawVoltage, arg_num, arg_thresh, arg_ch);
    return retval;
fail: ;
    CPy_AddTraceback("modTof.py", "time_at_thresh", 605, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Simulation___ToF_finalize(PyObject *cpy_r_self, PyObject *cpy_r_tofch1, PyObject *cpy_r_tofch4, PyObject *cpy_r_time_limit) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    CPyTagged cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject **cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    CPyTagged cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject **cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_out;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_i;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_j;
    PyObject *cpy_r_r22;
    char cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_lim;
    CPyTagged cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    int32_t cpy_r_r29;
    char cpy_r_r30;
    char cpy_r_r31;
    CPyTagged cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    int32_t cpy_r_r35;
    char cpy_r_r36;
    char cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_check;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    int32_t cpy_r_r43;
    char cpy_r_r44;
    char cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    CPyTagged cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    int32_t cpy_r_r58;
    char cpy_r_r59;
    char cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    CPyTagged cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    int32_t cpy_r_r66;
    char cpy_r_r67;
    char cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    int32_t cpy_r_r71;
    char cpy_r_r72;
    char cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    CPyTagged cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject **cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject **cpy_r_r92;
    PyObject *cpy_r_r93;
    char cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    if (cpy_r_time_limit != NULL) goto CPyL58;
    cpy_r_r0 = PyFloat_FromDouble(1e-08);
    cpy_r_time_limit = cpy_r_r0;
CPyL2: ;
    cpy_r_r1 = CPyStatics[159]; /* 'ch1 length' */
    cpy_r_r2 = CPyObject_Size(cpy_r_tofch1);
    if (unlikely(cpy_r_r2 == CPY_INT_TAG)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 643, CPyStatic_globals);
        goto CPyL59;
    }
    cpy_r_r3 = CPyTagged_StealAsObject(cpy_r_r2);
    cpy_r_r4 = CPyModule_builtins;
    cpy_r_r5 = CPyStatics[8]; /* 'print' */
    cpy_r_r6 = CPyObject_GetAttr(cpy_r_r4, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 643, CPyStatic_globals);
        goto CPyL60;
    }
    PyObject *cpy_r_r7[2] = {cpy_r_r1, cpy_r_r3};
    cpy_r_r8 = (PyObject **)&cpy_r_r7;
    cpy_r_r9 = _PyObject_Vectorcall(cpy_r_r6, cpy_r_r8, 2, 0);
    CPy_DECREF(cpy_r_r6);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 643, CPyStatic_globals);
        goto CPyL60;
    } else
        goto CPyL61;
CPyL5: ;
    CPy_DECREF(cpy_r_r3);
    cpy_r_r10 = CPyStatics[160]; /* 'ch4 length' */
    cpy_r_r11 = CPyObject_Size(cpy_r_tofch4);
    if (unlikely(cpy_r_r11 == CPY_INT_TAG)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 644, CPyStatic_globals);
        goto CPyL59;
    }
    cpy_r_r12 = CPyTagged_StealAsObject(cpy_r_r11);
    cpy_r_r13 = CPyModule_builtins;
    cpy_r_r14 = CPyStatics[8]; /* 'print' */
    cpy_r_r15 = CPyObject_GetAttr(cpy_r_r13, cpy_r_r14);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 644, CPyStatic_globals);
        goto CPyL62;
    }
    PyObject *cpy_r_r16[2] = {cpy_r_r10, cpy_r_r12};
    cpy_r_r17 = (PyObject **)&cpy_r_r16;
    cpy_r_r18 = _PyObject_Vectorcall(cpy_r_r15, cpy_r_r17, 2, 0);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 644, CPyStatic_globals);
        goto CPyL62;
    } else
        goto CPyL63;
CPyL8: ;
    CPy_DECREF(cpy_r_r12);
    cpy_r_r19 = PyList_New(0);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 645, CPyStatic_globals);
        goto CPyL59;
    }
    cpy_r_out = cpy_r_r19;
    cpy_r_r20 = CPyStatics[244]; /* 0 */
    CPy_INCREF(cpy_r_r20);
    cpy_r_i = cpy_r_r20;
    cpy_r_r21 = CPyStatics[244]; /* 0 */
    CPy_INCREF(cpy_r_r21);
    cpy_r_j = cpy_r_r21;
    cpy_r_r22 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r23 = cpy_r_time_limit != cpy_r_r22;
    if (!cpy_r_r23) goto CPyL64;
    cpy_r_r24 = cpy_r_time_limit;
    goto CPyL12;
CPyL11: ;
    cpy_r_r25 = PyFloat_FromDouble(1e-08);
    cpy_r_r24 = cpy_r_r25;
CPyL12: ;
    cpy_r_lim = cpy_r_r24;
CPyL13: ;
    cpy_r_r26 = CPyObject_Size(cpy_r_tofch1);
    if (unlikely(cpy_r_r26 == CPY_INT_TAG)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 648, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r27 = CPyTagged_StealAsObject(cpy_r_r26);
    cpy_r_r28 = PyObject_RichCompare(cpy_r_i, cpy_r_r27, 0);
    CPy_DECREF(cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 648, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r29 = PyObject_IsTrue(cpy_r_r28);
    CPy_DECREF(cpy_r_r28);
    cpy_r_r30 = cpy_r_r29 >= 0;
    if (unlikely(!cpy_r_r30)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 648, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r31 = cpy_r_r29;
    if (!cpy_r_r31) goto CPyL66;
    cpy_r_r32 = CPyObject_Size(cpy_r_tofch4);
    if (unlikely(cpy_r_r32 == CPY_INT_TAG)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 648, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r33 = CPyTagged_StealAsObject(cpy_r_r32);
    cpy_r_r34 = PyObject_RichCompare(cpy_r_j, cpy_r_r33, 0);
    CPy_DECREF(cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 648, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r35 = PyObject_IsTrue(cpy_r_r34);
    CPy_DECREF(cpy_r_r34);
    cpy_r_r36 = cpy_r_r35 >= 0;
    if (unlikely(!cpy_r_r36)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 648, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r37 = cpy_r_r35;
    if (!cpy_r_r37) goto CPyL66;
    cpy_r_r38 = PyObject_GetItem(cpy_r_tofch4, cpy_r_j);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 649, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r39 = PyObject_GetItem(cpy_r_tofch1, cpy_r_i);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 649, CPyStatic_globals);
        goto CPyL67;
    }
    cpy_r_r40 = PyNumber_Subtract(cpy_r_r38, cpy_r_r39);
    CPy_DECREF(cpy_r_r38);
    CPy_DECREF(cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 649, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_check = cpy_r_r40;
    cpy_r_r41 = PyNumber_Absolute(cpy_r_check);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 650, CPyStatic_globals);
        goto CPyL68;
    }
    cpy_r_r42 = PyObject_RichCompare(cpy_r_r41, cpy_r_lim, 0);
    CPy_DECREF(cpy_r_r41);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 650, CPyStatic_globals);
        goto CPyL68;
    }
    cpy_r_r43 = PyObject_IsTrue(cpy_r_r42);
    CPy_DECREF(cpy_r_r42);
    cpy_r_r44 = cpy_r_r43 >= 0;
    if (unlikely(!cpy_r_r44)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 650, CPyStatic_globals);
        goto CPyL68;
    }
    cpy_r_r45 = cpy_r_r43;
    if (!cpy_r_r45) goto CPyL33;
    cpy_r_r46 = PyNumber_Absolute(cpy_r_check);
    CPy_DECREF(cpy_r_check);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 651, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r47 = CPyStatics[43]; /* 'append' */
    cpy_r_r48 = CPyObject_CallMethodObjArgs(cpy_r_out, cpy_r_r47, cpy_r_r46, NULL);
    CPy_DECREF(cpy_r_r46);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 651, CPyStatic_globals);
        goto CPyL65;
    } else
        goto CPyL69;
CPyL30: ;
    cpy_r_r49 = CPyStatics[247]; /* 1 */
    cpy_r_r50 = PyNumber_InPlaceAdd(cpy_r_i, cpy_r_r49);
    CPy_DECREF(cpy_r_i);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 652, CPyStatic_globals);
        goto CPyL70;
    }
    cpy_r_i = cpy_r_r50;
    cpy_r_r51 = CPyStatics[247]; /* 1 */
    cpy_r_r52 = PyNumber_InPlaceAdd(cpy_r_j, cpy_r_r51);
    CPy_DECREF(cpy_r_j);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 653, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_j = cpy_r_r52;
    goto CPyL13;
CPyL33: ;
    cpy_r_r53 = CPyStatics[247]; /* 1 */
    cpy_r_r54 = PyNumber_Add(cpy_r_i, cpy_r_r53);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 654, CPyStatic_globals);
        goto CPyL68;
    }
    cpy_r_r55 = CPyObject_Size(cpy_r_tofch1);
    if (unlikely(cpy_r_r55 == CPY_INT_TAG)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 654, CPyStatic_globals);
        goto CPyL72;
    }
    cpy_r_r56 = CPyTagged_StealAsObject(cpy_r_r55);
    cpy_r_r57 = PyObject_RichCompare(cpy_r_r54, cpy_r_r56, 0);
    CPy_DECREF(cpy_r_r54);
    CPy_DECREF(cpy_r_r56);
    if (unlikely(cpy_r_r57 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 654, CPyStatic_globals);
        goto CPyL68;
    }
    cpy_r_r58 = PyObject_IsTrue(cpy_r_r57);
    CPy_DECREF(cpy_r_r57);
    cpy_r_r59 = cpy_r_r58 >= 0;
    if (unlikely(!cpy_r_r59)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 654, CPyStatic_globals);
        goto CPyL68;
    }
    cpy_r_r60 = cpy_r_r58;
    if (!cpy_r_r60) goto CPyL73;
    cpy_r_r61 = CPyStatics[247]; /* 1 */
    cpy_r_r62 = PyNumber_Add(cpy_r_j, cpy_r_r61);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 654, CPyStatic_globals);
        goto CPyL68;
    }
    cpy_r_r63 = CPyObject_Size(cpy_r_tofch4);
    if (unlikely(cpy_r_r63 == CPY_INT_TAG)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 654, CPyStatic_globals);
        goto CPyL74;
    }
    cpy_r_r64 = CPyTagged_StealAsObject(cpy_r_r63);
    cpy_r_r65 = PyObject_RichCompare(cpy_r_r62, cpy_r_r64, 0);
    CPy_DECREF(cpy_r_r62);
    CPy_DECREF(cpy_r_r64);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 654, CPyStatic_globals);
        goto CPyL68;
    }
    cpy_r_r66 = PyObject_IsTrue(cpy_r_r65);
    CPy_DECREF(cpy_r_r65);
    cpy_r_r67 = cpy_r_r66 >= 0;
    if (unlikely(!cpy_r_r67)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 654, CPyStatic_globals);
        goto CPyL68;
    }
    cpy_r_r68 = cpy_r_r66;
    if (!cpy_r_r68) goto CPyL73;
    cpy_r_r69 = CPyStatics[244]; /* 0 */
    cpy_r_r70 = PyObject_RichCompare(cpy_r_check, cpy_r_r69, 0);
    CPy_DECREF(cpy_r_check);
    if (unlikely(cpy_r_r70 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 654, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r71 = PyObject_IsTrue(cpy_r_r70);
    CPy_DECREF(cpy_r_r70);
    cpy_r_r72 = cpy_r_r71 >= 0;
    if (unlikely(!cpy_r_r72)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 654, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r73 = cpy_r_r71;
    if (!cpy_r_r73) goto CPyL48;
    cpy_r_r74 = CPyStatics[247]; /* 1 */
    cpy_r_r75 = PyNumber_InPlaceAdd(cpy_r_j, cpy_r_r74);
    CPy_DECREF(cpy_r_j);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 655, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_j = cpy_r_r75;
    goto CPyL13;
CPyL48: ;
    cpy_r_r76 = CPyStatics[247]; /* 1 */
    cpy_r_r77 = PyNumber_InPlaceAdd(cpy_r_i, cpy_r_r76);
    CPy_DECREF(cpy_r_i);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 657, CPyStatic_globals);
        goto CPyL70;
    }
    cpy_r_i = cpy_r_r77;
    goto CPyL13;
CPyL50: ;
    cpy_r_r78 = CPyStatics[161]; /* 'finished calculating,' */
    cpy_r_r79 = CPyObject_Size(cpy_r_out);
    if (unlikely(cpy_r_r79 == CPY_INT_TAG)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 658, CPyStatic_globals);
        goto CPyL75;
    }
    cpy_r_r80 = CPyTagged_StealAsObject(cpy_r_r79);
    cpy_r_r81 = CPyStatics[162]; /* 'particles' */
    cpy_r_r82 = CPyModule_builtins;
    cpy_r_r83 = CPyStatics[8]; /* 'print' */
    cpy_r_r84 = CPyObject_GetAttr(cpy_r_r82, cpy_r_r83);
    if (unlikely(cpy_r_r84 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 658, CPyStatic_globals);
        goto CPyL76;
    }
    PyObject *cpy_r_r85[3] = {cpy_r_r78, cpy_r_r80, cpy_r_r81};
    cpy_r_r86 = (PyObject **)&cpy_r_r85;
    cpy_r_r87 = _PyObject_Vectorcall(cpy_r_r84, cpy_r_r86, 3, 0);
    CPy_DECREF(cpy_r_r84);
    if (unlikely(cpy_r_r87 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 658, CPyStatic_globals);
        goto CPyL76;
    } else
        goto CPyL77;
CPyL53: ;
    CPy_DECREF(cpy_r_r80);
    cpy_r_r88 = CPyModule_numpy;
    cpy_r_r89 = CPyStatics[32]; /* 'array' */
    cpy_r_r90 = CPyObject_GetAttr(cpy_r_r88, cpy_r_r89);
    if (unlikely(cpy_r_r90 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 659, CPyStatic_globals);
        goto CPyL75;
    }
    PyObject *cpy_r_r91[1] = {cpy_r_out};
    cpy_r_r92 = (PyObject **)&cpy_r_r91;
    cpy_r_r93 = _PyObject_Vectorcall(cpy_r_r90, cpy_r_r92, 1, 0);
    CPy_DECREF(cpy_r_r90);
    if (unlikely(cpy_r_r93 == NULL)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 659, CPyStatic_globals);
        goto CPyL75;
    }
    CPy_DECREF(cpy_r_out);
    if (((modTof___SimulationObject *)cpy_r_self)->_FinalToF != NULL) {
        CPy_DECREF(((modTof___SimulationObject *)cpy_r_self)->_FinalToF);
    }
    ((modTof___SimulationObject *)cpy_r_self)->_FinalToF = cpy_r_r93;
    cpy_r_r94 = 1;
    if (unlikely(!cpy_r_r94)) {
        CPy_AddTraceback("modTof.py", "ToF_finalize", 659, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r95 = Py_None;
    CPy_INCREF(cpy_r_r95);
    return cpy_r_r95;
CPyL57: ;
    cpy_r_r96 = NULL;
    return cpy_r_r96;
CPyL58: ;
    CPy_INCREF(cpy_r_time_limit);
    goto CPyL2;
CPyL59: ;
    CPy_DecRef(cpy_r_time_limit);
    goto CPyL57;
CPyL60: ;
    CPy_DecRef(cpy_r_time_limit);
    CPy_DecRef(cpy_r_r3);
    goto CPyL57;
CPyL61: ;
    CPy_DECREF(cpy_r_r9);
    goto CPyL5;
CPyL62: ;
    CPy_DecRef(cpy_r_time_limit);
    CPy_DecRef(cpy_r_r12);
    goto CPyL57;
CPyL63: ;
    CPy_DECREF(cpy_r_r18);
    goto CPyL8;
CPyL64: ;
    CPy_DECREF(cpy_r_time_limit);
    goto CPyL11;
CPyL65: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_j);
    CPy_DecRef(cpy_r_lim);
    goto CPyL57;
CPyL66: ;
    CPy_DECREF(cpy_r_i);
    CPy_DECREF(cpy_r_j);
    CPy_DECREF(cpy_r_lim);
    goto CPyL50;
CPyL67: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_j);
    CPy_DecRef(cpy_r_lim);
    CPy_DecRef(cpy_r_r38);
    goto CPyL57;
CPyL68: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_j);
    CPy_DecRef(cpy_r_lim);
    CPy_DecRef(cpy_r_check);
    goto CPyL57;
CPyL69: ;
    CPy_DECREF(cpy_r_r48);
    goto CPyL30;
CPyL70: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_j);
    CPy_DecRef(cpy_r_lim);
    goto CPyL57;
CPyL71: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_lim);
    goto CPyL57;
CPyL72: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_j);
    CPy_DecRef(cpy_r_lim);
    CPy_DecRef(cpy_r_check);
    CPy_DecRef(cpy_r_r54);
    goto CPyL57;
CPyL73: ;
    CPy_DECREF(cpy_r_check);
    goto CPyL48;
CPyL74: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_j);
    CPy_DecRef(cpy_r_lim);
    CPy_DecRef(cpy_r_check);
    CPy_DecRef(cpy_r_r62);
    goto CPyL57;
CPyL75: ;
    CPy_DecRef(cpy_r_out);
    goto CPyL57;
CPyL76: ;
    CPy_DecRef(cpy_r_out);
    CPy_DecRef(cpy_r_r80);
    goto CPyL57;
CPyL77: ;
    CPy_DECREF(cpy_r_r87);
    goto CPyL53;
}

PyObject *CPyPy_Simulation___ToF_finalize(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"tofch1", "tofch4", "time_limit", 0};
    static CPyArg_Parser parser = {"OO|O:ToF_finalize", kwlist, 0};
    PyObject *obj_tofch1;
    PyObject *obj_tofch4;
    PyObject *obj_time_limit = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_tofch1, &obj_tofch4, &obj_time_limit)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *arg_tofch1 = obj_tofch1;
    PyObject *arg_tofch4 = obj_tofch4;
    PyObject *arg_time_limit;
    if (obj_time_limit == NULL) {
        arg_time_limit = NULL;
    } else {
        arg_time_limit = obj_time_limit; 
    }
    PyObject *retval = CPyDef_Simulation___ToF_finalize(arg_self, arg_tofch1, arg_tofch4, arg_time_limit);
    return retval;
fail: ;
    CPy_AddTraceback("modTof.py", "ToF_finalize", 642, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Simulation___calc_ToF(PyObject *cpy_r_self, PyObject *cpy_r_filedate, PyObject *cpy_r_filenum) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    char cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    int32_t cpy_r_r12;
    char cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_date;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_num_part;
    PyObject *cpy_r_r23;
    char cpy_r_r24;
    PyObject *cpy_r_r25;
    char cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject **cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject **cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_filename_ch1;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject **cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_filename_ch4;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    CPyPtr cpy_r_r68;
    CPyPtr cpy_r_r69;
    CPyPtr cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject **cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_ch1;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    CPyPtr cpy_r_r82;
    CPyPtr cpy_r_r83;
    CPyPtr cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject **cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_ch4;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_ch1ToF;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_ch4ToF;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    PyObject **cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    PyObject *cpy_r_r117;
    PyObject *cpy_r_r118;
    PyObject *cpy_r_r119;
    PyObject *cpy_r_r120;
    PyObject **cpy_r_r122;
    PyObject *cpy_r_r123;
    PyObject *cpy_r_r124;
    PyObject *cpy_r_r125;
    if (cpy_r_filedate != NULL) goto CPyL56;
    cpy_r_r0 = Py_None;
    CPy_INCREF(cpy_r_r0);
    cpy_r_filedate = cpy_r_r0;
CPyL2: ;
    if (cpy_r_filenum != NULL) goto CPyL57;
    cpy_r_r1 = Py_None;
    CPy_INCREF(cpy_r_r1);
    cpy_r_filenum = cpy_r_r1;
CPyL4: ;
    cpy_r_r2 = CPyStatic_globals;
    cpy_r_r3 = CPyModule_os;
    cpy_r_r4 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r5 = cpy_r_r3 != cpy_r_r4;
    if (cpy_r_r5) goto CPyL7;
    cpy_r_r6 = CPyStatics[163]; /* 'os' */
    cpy_r_r7 = PyImport_Import(cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 718, CPyStatic_globals);
        goto CPyL58;
    }
    CPyModule_os = cpy_r_r7;
    CPy_INCREF(CPyModule_os);
    CPy_DECREF(cpy_r_r7);
CPyL7: ;
    cpy_r_r8 = CPyStatics[163]; /* 'os' */
    cpy_r_r9 = PyImport_GetModuleDict();
    cpy_r_r10 = CPyStatics[163]; /* 'os' */
    cpy_r_r11 = CPyDict_GetItem(cpy_r_r9, cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 718, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r12 = CPyDict_SetItem(cpy_r_r2, cpy_r_r8, cpy_r_r11);
    CPy_DECREF(cpy_r_r11);
    cpy_r_r13 = cpy_r_r12 >= 0;
    if (unlikely(!cpy_r_r13)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 718, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r14 = CPyStatic_globals;
    cpy_r_r15 = CPyStatics[115]; /* 'datetime' */
    cpy_r_r16 = CPyDict_GetItem(cpy_r_r14, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 720, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r17 = CPyStatics[116]; /* 'now' */
    cpy_r_r18 = CPyObject_CallMethodObjArgs(cpy_r_r16, cpy_r_r17, NULL);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 720, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r19 = CPyStatics[117]; /* '%m_%d_%Y' */
    cpy_r_r20 = CPyStatics[118]; /* 'strftime' */
    cpy_r_r21 = CPyObject_CallMethodObjArgs(cpy_r_r18, cpy_r_r20, cpy_r_r19, NULL);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 720, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_date = cpy_r_r21;
    cpy_r_r22 = ((modTof___SimulationObject *)cpy_r_self)->_num_particles;
    CPy_INCREF(cpy_r_r22);
    cpy_r_num_part = cpy_r_r22;
    cpy_r_r23 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r24 = cpy_r_filedate != cpy_r_r23;
    if (cpy_r_r24) {
        goto CPyL59;
    } else
        goto CPyL60;
CPyL13: ;
    cpy_r_date = cpy_r_filedate;
CPyL14: ;
    cpy_r_r25 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r26 = cpy_r_filenum != cpy_r_r25;
    if (cpy_r_r26) {
        goto CPyL61;
    } else
        goto CPyL62;
CPyL15: ;
    cpy_r_r27 = (PyObject *)&PyLong_Type;
    PyObject *cpy_r_r28[1] = {cpy_r_filenum};
    cpy_r_r29 = (PyObject **)&cpy_r_r28;
    cpy_r_r30 = _PyObject_Vectorcall(cpy_r_r27, cpy_r_r29, 1, 0);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 725, CPyStatic_globals);
        goto CPyL63;
    }
    CPy_DECREF(cpy_r_filenum);
    cpy_r_num_part = cpy_r_r30;
CPyL17: ;
    cpy_r_r31 = CPyStatics[164]; /* 'output' */
    cpy_r_r32 = PyObject_Str(cpy_r_num_part);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 726, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r33 = PyUnicode_Concat(cpy_r_r31, cpy_r_r32);
    CPy_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 726, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r34 = CPyStatics[165]; /* 'ch1_' */
    cpy_r_r35 = PyUnicode_Concat(cpy_r_r33, cpy_r_r34);
    CPy_DECREF(cpy_r_r33);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 726, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r36 = PyObject_Str(cpy_r_date);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 726, CPyStatic_globals);
        goto CPyL65;
    }
    cpy_r_r37 = PyUnicode_Concat(cpy_r_r35, cpy_r_r36);
    CPy_DECREF(cpy_r_r35);
    CPy_DECREF(cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 726, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r38 = CPyStatics[119]; /* '.txt' */
    cpy_r_r39 = PyUnicode_Concat(cpy_r_r37, cpy_r_r38);
    CPy_DECREF(cpy_r_r37);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 726, CPyStatic_globals);
        goto CPyL64;
    }
    cpy_r_r40 = CPyModule_os;
    cpy_r_r41 = CPyStatics[166]; /* 'path' */
    cpy_r_r42 = CPyObject_GetAttr(cpy_r_r40, cpy_r_r41);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 726, CPyStatic_globals);
        goto CPyL66;
    }
    cpy_r_r43 = CPyStatics[167]; /* 'abspath' */
    cpy_r_r44 = CPyObject_GetAttr(cpy_r_r42, cpy_r_r43);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 726, CPyStatic_globals);
        goto CPyL66;
    }
    PyObject *cpy_r_r45[1] = {cpy_r_r39};
    cpy_r_r46 = (PyObject **)&cpy_r_r45;
    cpy_r_r47 = _PyObject_Vectorcall(cpy_r_r44, cpy_r_r46, 1, 0);
    CPy_DECREF(cpy_r_r44);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 726, CPyStatic_globals);
        goto CPyL66;
    }
    CPy_DECREF(cpy_r_r39);
    cpy_r_filename_ch1 = cpy_r_r47;
    cpy_r_r48 = CPyStatics[164]; /* 'output' */
    cpy_r_r49 = PyObject_Str(cpy_r_num_part);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 727, CPyStatic_globals);
        goto CPyL67;
    }
    cpy_r_r50 = PyUnicode_Concat(cpy_r_r48, cpy_r_r49);
    CPy_DECREF(cpy_r_r49);
    if (unlikely(cpy_r_r50 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 727, CPyStatic_globals);
        goto CPyL67;
    }
    cpy_r_r51 = CPyStatics[168]; /* 'ch4_' */
    cpy_r_r52 = PyUnicode_Concat(cpy_r_r50, cpy_r_r51);
    CPy_DECREF(cpy_r_r50);
    if (unlikely(cpy_r_r52 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 727, CPyStatic_globals);
        goto CPyL67;
    }
    cpy_r_r53 = PyObject_Str(cpy_r_date);
    CPy_DECREF(cpy_r_date);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 727, CPyStatic_globals);
        goto CPyL68;
    }
    cpy_r_r54 = PyUnicode_Concat(cpy_r_r52, cpy_r_r53);
    CPy_DECREF(cpy_r_r52);
    CPy_DECREF(cpy_r_r53);
    if (unlikely(cpy_r_r54 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 727, CPyStatic_globals);
        goto CPyL69;
    }
    cpy_r_r55 = CPyStatics[119]; /* '.txt' */
    cpy_r_r56 = PyUnicode_Concat(cpy_r_r54, cpy_r_r55);
    CPy_DECREF(cpy_r_r54);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 727, CPyStatic_globals);
        goto CPyL69;
    }
    cpy_r_r57 = CPyModule_os;
    cpy_r_r58 = CPyStatics[166]; /* 'path' */
    cpy_r_r59 = CPyObject_GetAttr(cpy_r_r57, cpy_r_r58);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 727, CPyStatic_globals);
        goto CPyL70;
    }
    cpy_r_r60 = CPyStatics[167]; /* 'abspath' */
    cpy_r_r61 = CPyObject_GetAttr(cpy_r_r59, cpy_r_r60);
    CPy_DECREF(cpy_r_r59);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 727, CPyStatic_globals);
        goto CPyL70;
    }
    PyObject *cpy_r_r62[1] = {cpy_r_r56};
    cpy_r_r63 = (PyObject **)&cpy_r_r62;
    cpy_r_r64 = _PyObject_Vectorcall(cpy_r_r61, cpy_r_r63, 1, 0);
    CPy_DECREF(cpy_r_r61);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 727, CPyStatic_globals);
        goto CPyL70;
    }
    CPy_DECREF(cpy_r_r56);
    cpy_r_filename_ch4 = cpy_r_r64;
    cpy_r_r65 = CPyStatics[169]; /* 't' */
    cpy_r_r66 = CPyStatics[170]; /* 'V' */
    cpy_r_r67 = PyList_New(2);
    if (unlikely(cpy_r_r67 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 728, CPyStatic_globals);
        goto CPyL71;
    }
    cpy_r_r68 = (CPyPtr)&((PyListObject *)cpy_r_r67)->ob_item;
    cpy_r_r69 = *(CPyPtr *)cpy_r_r68;
    CPy_INCREF(cpy_r_r65);
    *(PyObject * *)cpy_r_r69 = cpy_r_r65;
    cpy_r_r70 = cpy_r_r69 + 8;
    CPy_INCREF(cpy_r_r66);
    *(PyObject * *)cpy_r_r70 = cpy_r_r66;
    cpy_r_r71 = CPyStatics[171]; /* ',' */
    cpy_r_r72 = CPyModule_pandas;
    cpy_r_r73 = CPyStatics[172]; /* 'read_csv' */
    cpy_r_r74 = CPyObject_GetAttr(cpy_r_r72, cpy_r_r73);
    if (unlikely(cpy_r_r74 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 728, CPyStatic_globals);
        goto CPyL72;
    }
    PyObject *cpy_r_r75[3] = {cpy_r_filename_ch1, cpy_r_r67, cpy_r_r71};
    cpy_r_r76 = (PyObject **)&cpy_r_r75;
    cpy_r_r77 = CPyStatics[276]; /* ('names', 'sep') */
    cpy_r_r78 = _PyObject_Vectorcall(cpy_r_r74, cpy_r_r76, 1, cpy_r_r77);
    CPy_DECREF(cpy_r_r74);
    if (unlikely(cpy_r_r78 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 728, CPyStatic_globals);
        goto CPyL72;
    }
    CPy_DECREF(cpy_r_filename_ch1);
    CPy_DECREF(cpy_r_r67);
    cpy_r_ch1 = cpy_r_r78;
    cpy_r_r79 = CPyStatics[169]; /* 't' */
    cpy_r_r80 = CPyStatics[170]; /* 'V' */
    cpy_r_r81 = PyList_New(2);
    if (unlikely(cpy_r_r81 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 729, CPyStatic_globals);
        goto CPyL73;
    }
    cpy_r_r82 = (CPyPtr)&((PyListObject *)cpy_r_r81)->ob_item;
    cpy_r_r83 = *(CPyPtr *)cpy_r_r82;
    CPy_INCREF(cpy_r_r79);
    *(PyObject * *)cpy_r_r83 = cpy_r_r79;
    cpy_r_r84 = cpy_r_r83 + 8;
    CPy_INCREF(cpy_r_r80);
    *(PyObject * *)cpy_r_r84 = cpy_r_r80;
    cpy_r_r85 = CPyStatics[171]; /* ',' */
    cpy_r_r86 = CPyModule_pandas;
    cpy_r_r87 = CPyStatics[172]; /* 'read_csv' */
    cpy_r_r88 = CPyObject_GetAttr(cpy_r_r86, cpy_r_r87);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 729, CPyStatic_globals);
        goto CPyL74;
    }
    PyObject *cpy_r_r89[3] = {cpy_r_filename_ch4, cpy_r_r81, cpy_r_r85};
    cpy_r_r90 = (PyObject **)&cpy_r_r89;
    cpy_r_r91 = CPyStatics[276]; /* ('names', 'sep') */
    cpy_r_r92 = _PyObject_Vectorcall(cpy_r_r88, cpy_r_r90, 1, cpy_r_r91);
    CPy_DECREF(cpy_r_r88);
    if (unlikely(cpy_r_r92 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 729, CPyStatic_globals);
        goto CPyL74;
    }
    CPy_DECREF(cpy_r_filename_ch4);
    CPy_DECREF(cpy_r_r81);
    cpy_r_ch4 = cpy_r_r92;
    cpy_r_r93 = CPyStatics[169]; /* 't' */
    cpy_r_r94 = PyObject_GetItem(cpy_r_ch1, cpy_r_r93);
    if (unlikely(cpy_r_r94 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 730, CPyStatic_globals);
        goto CPyL75;
    }
    cpy_r_r95 = CPyStatics[170]; /* 'V' */
    cpy_r_r96 = PyObject_GetItem(cpy_r_ch1, cpy_r_r95);
    CPy_DECREF(cpy_r_ch1);
    if (unlikely(cpy_r_r96 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 730, CPyStatic_globals);
        goto CPyL76;
    }
    cpy_r_r97 = ((modTof___SimulationObject *)cpy_r_self)->_CMOS_thresh;
    CPy_INCREF(cpy_r_r97);
    cpy_r_r98 = CPyStatics[247]; /* 1 */
    cpy_r_r99 = CPyDef_Simulation___time_at_thresh(cpy_r_self, cpy_r_r94, cpy_r_r96, cpy_r_num_part, cpy_r_r97, cpy_r_r98);
    CPy_DECREF(cpy_r_r94);
    CPy_DECREF(cpy_r_r96);
    CPy_DECREF(cpy_r_r97);
    if (unlikely(cpy_r_r99 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 730, CPyStatic_globals);
        goto CPyL77;
    }
    cpy_r_ch1ToF = cpy_r_r99;
    cpy_r_r100 = CPyStatics[169]; /* 't' */
    cpy_r_r101 = PyObject_GetItem(cpy_r_ch4, cpy_r_r100);
    if (unlikely(cpy_r_r101 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 731, CPyStatic_globals);
        goto CPyL78;
    }
    cpy_r_r102 = CPyStatics[170]; /* 'V' */
    cpy_r_r103 = PyObject_GetItem(cpy_r_ch4, cpy_r_r102);
    CPy_DECREF(cpy_r_ch4);
    if (unlikely(cpy_r_r103 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 731, CPyStatic_globals);
        goto CPyL79;
    }
    cpy_r_r104 = ((modTof___SimulationObject *)cpy_r_self)->_CMOS_thresh;
    CPy_INCREF(cpy_r_r104);
    cpy_r_r105 = CPyStatics[248]; /* 4 */
    cpy_r_r106 = CPyDef_Simulation___time_at_thresh(cpy_r_self, cpy_r_r101, cpy_r_r103, cpy_r_num_part, cpy_r_r104, cpy_r_r105);
    CPy_DECREF(cpy_r_r101);
    CPy_DECREF(cpy_r_r103);
    CPy_DECREF(cpy_r_num_part);
    CPy_DECREF(cpy_r_r104);
    if (unlikely(cpy_r_r106 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 731, CPyStatic_globals);
        goto CPyL80;
    }
    cpy_r_ch4ToF = cpy_r_r106;
    cpy_r_r107 = NULL;
    cpy_r_r108 = CPyDef_Simulation___ToF_finalize(cpy_r_self, cpy_r_ch1ToF, cpy_r_ch4ToF, cpy_r_r107);
    CPy_DECREF(cpy_r_ch1ToF);
    CPy_DECREF(cpy_r_ch4ToF);
    if (unlikely(cpy_r_r108 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 732, CPyStatic_globals);
        goto CPyL55;
    } else
        goto CPyL81;
CPyL48: ;
    cpy_r_r109 = ((modTof___SimulationObject *)cpy_r_self)->_FinalToF;
    if (unlikely(cpy_r_r109 == NULL)) {
        CPy_AttributeError("modTof.py", "calc_ToF", "Simulation", "FinalToF", 733, CPyStatic_globals);
        goto CPyL55;
    }
    CPy_INCREF(cpy_r_r109);
CPyL49: ;
    cpy_r_r110 = CPyModule_pandas;
    cpy_r_r111 = CPyStatics[107]; /* 'DataFrame' */
    cpy_r_r112 = CPyObject_GetAttr(cpy_r_r110, cpy_r_r111);
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 733, CPyStatic_globals);
        goto CPyL82;
    }
    PyObject *cpy_r_r113[1] = {cpy_r_r109};
    cpy_r_r114 = (PyObject **)&cpy_r_r113;
    cpy_r_r115 = _PyObject_Vectorcall(cpy_r_r112, cpy_r_r114, 1, 0);
    CPy_DECREF(cpy_r_r112);
    if (unlikely(cpy_r_r115 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 733, CPyStatic_globals);
        goto CPyL82;
    }
    CPy_DECREF(cpy_r_r109);
    cpy_r_r116 = CPyStatics[174]; /* 'describe' */
    cpy_r_r117 = CPyObject_CallMethodObjArgs(cpy_r_r115, cpy_r_r116, NULL);
    CPy_DECREF(cpy_r_r115);
    if (unlikely(cpy_r_r117 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 733, CPyStatic_globals);
        goto CPyL55;
    }
    cpy_r_r118 = CPyModule_builtins;
    cpy_r_r119 = CPyStatics[8]; /* 'print' */
    cpy_r_r120 = CPyObject_GetAttr(cpy_r_r118, cpy_r_r119);
    if (unlikely(cpy_r_r120 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 733, CPyStatic_globals);
        goto CPyL83;
    }
    PyObject *cpy_r_r121[1] = {cpy_r_r117};
    cpy_r_r122 = (PyObject **)&cpy_r_r121;
    cpy_r_r123 = _PyObject_Vectorcall(cpy_r_r120, cpy_r_r122, 1, 0);
    CPy_DECREF(cpy_r_r120);
    if (unlikely(cpy_r_r123 == NULL)) {
        CPy_AddTraceback("modTof.py", "calc_ToF", 733, CPyStatic_globals);
        goto CPyL83;
    } else
        goto CPyL84;
CPyL54: ;
    CPy_DECREF(cpy_r_r117);
    cpy_r_r124 = Py_None;
    CPy_INCREF(cpy_r_r124);
    return cpy_r_r124;
CPyL55: ;
    cpy_r_r125 = NULL;
    return cpy_r_r125;
CPyL56: ;
    CPy_INCREF(cpy_r_filedate);
    goto CPyL2;
CPyL57: ;
    CPy_INCREF(cpy_r_filenum);
    goto CPyL4;
CPyL58: ;
    CPy_DecRef(cpy_r_filedate);
    CPy_DecRef(cpy_r_filenum);
    goto CPyL55;
CPyL59: ;
    CPy_DECREF(cpy_r_date);
    goto CPyL13;
CPyL60: ;
    CPy_DECREF(cpy_r_filedate);
    goto CPyL14;
CPyL61: ;
    CPy_DECREF(cpy_r_num_part);
    goto CPyL15;
CPyL62: ;
    CPy_DECREF(cpy_r_filenum);
    goto CPyL17;
CPyL63: ;
    CPy_DecRef(cpy_r_filenum);
    CPy_DecRef(cpy_r_date);
    goto CPyL55;
CPyL64: ;
    CPy_DecRef(cpy_r_date);
    CPy_DecRef(cpy_r_num_part);
    goto CPyL55;
CPyL65: ;
    CPy_DecRef(cpy_r_date);
    CPy_DecRef(cpy_r_num_part);
    CPy_DecRef(cpy_r_r35);
    goto CPyL55;
CPyL66: ;
    CPy_DecRef(cpy_r_date);
    CPy_DecRef(cpy_r_num_part);
    CPy_DecRef(cpy_r_r39);
    goto CPyL55;
CPyL67: ;
    CPy_DecRef(cpy_r_date);
    CPy_DecRef(cpy_r_num_part);
    CPy_DecRef(cpy_r_filename_ch1);
    goto CPyL55;
CPyL68: ;
    CPy_DecRef(cpy_r_num_part);
    CPy_DecRef(cpy_r_filename_ch1);
    CPy_DecRef(cpy_r_r52);
    goto CPyL55;
CPyL69: ;
    CPy_DecRef(cpy_r_num_part);
    CPy_DecRef(cpy_r_filename_ch1);
    goto CPyL55;
CPyL70: ;
    CPy_DecRef(cpy_r_num_part);
    CPy_DecRef(cpy_r_filename_ch1);
    CPy_DecRef(cpy_r_r56);
    goto CPyL55;
CPyL71: ;
    CPy_DecRef(cpy_r_num_part);
    CPy_DecRef(cpy_r_filename_ch1);
    CPy_DecRef(cpy_r_filename_ch4);
    goto CPyL55;
CPyL72: ;
    CPy_DecRef(cpy_r_num_part);
    CPy_DecRef(cpy_r_filename_ch1);
    CPy_DecRef(cpy_r_filename_ch4);
    CPy_DecRef(cpy_r_r67);
    goto CPyL55;
CPyL73: ;
    CPy_DecRef(cpy_r_num_part);
    CPy_DecRef(cpy_r_filename_ch4);
    CPy_DecRef(cpy_r_ch1);
    goto CPyL55;
CPyL74: ;
    CPy_DecRef(cpy_r_num_part);
    CPy_DecRef(cpy_r_filename_ch4);
    CPy_DecRef(cpy_r_ch1);
    CPy_DecRef(cpy_r_r81);
    goto CPyL55;
CPyL75: ;
    CPy_DecRef(cpy_r_num_part);
    CPy_DecRef(cpy_r_ch1);
    CPy_DecRef(cpy_r_ch4);
    goto CPyL55;
CPyL76: ;
    CPy_DecRef(cpy_r_num_part);
    CPy_DecRef(cpy_r_ch4);
    CPy_DecRef(cpy_r_r94);
    goto CPyL55;
CPyL77: ;
    CPy_DecRef(cpy_r_num_part);
    CPy_DecRef(cpy_r_ch4);
    goto CPyL55;
CPyL78: ;
    CPy_DecRef(cpy_r_num_part);
    CPy_DecRef(cpy_r_ch4);
    CPy_DecRef(cpy_r_ch1ToF);
    goto CPyL55;
CPyL79: ;
    CPy_DecRef(cpy_r_num_part);
    CPy_DecRef(cpy_r_ch1ToF);
    CPy_DecRef(cpy_r_r101);
    goto CPyL55;
CPyL80: ;
    CPy_DecRef(cpy_r_ch1ToF);
    goto CPyL55;
CPyL81: ;
    CPy_DECREF(cpy_r_r108);
    goto CPyL48;
CPyL82: ;
    CPy_DecRef(cpy_r_r109);
    goto CPyL55;
CPyL83: ;
    CPy_DecRef(cpy_r_r117);
    goto CPyL55;
CPyL84: ;
    CPy_DECREF(cpy_r_r123);
    goto CPyL54;
}

PyObject *CPyPy_Simulation___calc_ToF(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"filedate", "filenum", 0};
    static CPyArg_Parser parser = {"|OO:calc_ToF", kwlist, 0};
    PyObject *obj_filedate = NULL;
    PyObject *obj_filenum = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_filedate, &obj_filenum)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *arg_filedate;
    if (obj_filedate == NULL) {
        arg_filedate = NULL;
    } else {
        arg_filedate = obj_filedate; 
    }
    PyObject *arg_filenum;
    if (obj_filenum == NULL) {
        arg_filenum = NULL;
    } else {
        arg_filenum = obj_filenum; 
    }
    PyObject *retval = CPyDef_Simulation___calc_ToF(arg_self, arg_filedate, arg_filenum);
    return retval;
fail: ;
    CPy_AddTraceback("modTof.py", "calc_ToF", 717, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef_Simulation___save_ToF(PyObject *cpy_r_self, PyObject *cpy_r_filename) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_date;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_num_total;
    PyObject *cpy_r_r10;
    CPyTagged cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_counted;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
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
    PyObject *cpy_r_file;
    PyObject *cpy_r_r26;
    char cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject **cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject **cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    if (cpy_r_filename != NULL) goto CPyL26;
    cpy_r_r0 = Py_None;
    CPy_INCREF(cpy_r_r0);
    cpy_r_filename = cpy_r_r0;
CPyL2: ;
    cpy_r_r1 = CPyStatic_globals;
    cpy_r_r2 = CPyStatics[115]; /* 'datetime' */
    cpy_r_r3 = CPyDict_GetItem(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("modTof.py", "save_ToF", 738, CPyStatic_globals);
        goto CPyL27;
    }
    cpy_r_r4 = CPyStatics[116]; /* 'now' */
    cpy_r_r5 = CPyObject_CallMethodObjArgs(cpy_r_r3, cpy_r_r4, NULL);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r5 == NULL)) {
        CPy_AddTraceback("modTof.py", "save_ToF", 738, CPyStatic_globals);
        goto CPyL27;
    }
    cpy_r_r6 = CPyStatics[117]; /* '%m_%d_%Y' */
    cpy_r_r7 = CPyStatics[118]; /* 'strftime' */
    cpy_r_r8 = CPyObject_CallMethodObjArgs(cpy_r_r5, cpy_r_r7, cpy_r_r6, NULL);
    CPy_DECREF(cpy_r_r5);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("modTof.py", "save_ToF", 738, CPyStatic_globals);
        goto CPyL27;
    }
    cpy_r_date = cpy_r_r8;
    cpy_r_r9 = ((modTof___SimulationObject *)cpy_r_self)->_num_particles;
    CPy_INCREF(cpy_r_r9);
    cpy_r_num_total = cpy_r_r9;
    cpy_r_r10 = ((modTof___SimulationObject *)cpy_r_self)->_FinalToF;
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AttributeError("modTof.py", "save_ToF", "Simulation", "FinalToF", 740, CPyStatic_globals);
        goto CPyL28;
    }
    CPy_INCREF(cpy_r_r10);
CPyL6: ;
    cpy_r_r11 = CPyObject_Size(cpy_r_r10);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r11 == CPY_INT_TAG)) {
        CPy_AddTraceback("modTof.py", "save_ToF", 740, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r12 = CPyTagged_StealAsObject(cpy_r_r11);
    cpy_r_counted = cpy_r_r12;
    cpy_r_r13 = CPyStatics[175]; /* 'result_' */
    cpy_r_r14 = PyObject_Str(cpy_r_counted);
    CPy_DECREF(cpy_r_counted);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("modTof.py", "save_ToF", 741, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r15 = PyUnicode_Concat(cpy_r_r13, cpy_r_r14);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("modTof.py", "save_ToF", 741, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r16 = CPyStatics[176]; /* '_of_' */
    cpy_r_r17 = PyUnicode_Concat(cpy_r_r15, cpy_r_r16);
    CPy_DECREF(cpy_r_r15);
    if (unlikely(cpy_r_r17 == NULL)) {
        CPy_AddTraceback("modTof.py", "save_ToF", 741, CPyStatic_globals);
        goto CPyL28;
    }
    cpy_r_r18 = PyObject_Str(cpy_r_num_total);
    CPy_DECREF(cpy_r_num_total);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("modTof.py", "save_ToF", 741, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r19 = PyUnicode_Concat(cpy_r_r17, cpy_r_r18);
    CPy_DECREF(cpy_r_r17);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("modTof.py", "save_ToF", 741, CPyStatic_globals);
        goto CPyL30;
    }
    cpy_r_r20 = CPyStatics[143]; /* '_' */
    cpy_r_r21 = PyUnicode_Concat(cpy_r_r19, cpy_r_r20);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("modTof.py", "save_ToF", 741, CPyStatic_globals);
        goto CPyL30;
    }
    cpy_r_r22 = PyObject_Str(cpy_r_date);
    CPy_DECREF(cpy_r_date);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("modTof.py", "save_ToF", 741, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r23 = PyUnicode_Concat(cpy_r_r21, cpy_r_r22);
    CPy_DECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_r22);
    if (unlikely(cpy_r_r23 == NULL)) {
        CPy_AddTraceback("modTof.py", "save_ToF", 741, CPyStatic_globals);
        goto CPyL27;
    }
    cpy_r_r24 = CPyStatics[119]; /* '.txt' */
    cpy_r_r25 = PyUnicode_Concat(cpy_r_r23, cpy_r_r24);
    CPy_DECREF(cpy_r_r23);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("modTof.py", "save_ToF", 741, CPyStatic_globals);
        goto CPyL27;
    }
    cpy_r_file = cpy_r_r25;
    cpy_r_r26 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r27 = cpy_r_filename != cpy_r_r26;
    if (cpy_r_r27) {
        goto CPyL32;
    } else
        goto CPyL33;
CPyL17: ;
    cpy_r_file = cpy_r_filename;
CPyL18: ;
    cpy_r_r28 = CPyStatics[177]; /* 'Time-of-Flight [s]' */
    cpy_r_r29 = ((modTof___SimulationObject *)cpy_r_self)->_FinalToF;
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AttributeError("modTof.py", "save_ToF", "Simulation", "FinalToF", 745, CPyStatic_globals);
        goto CPyL34;
    }
    CPy_INCREF(cpy_r_r29);
CPyL19: ;
    cpy_r_r30 = CPyDict_Build(1, cpy_r_r28, cpy_r_r29);
    CPy_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("modTof.py", "save_ToF", 745, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r31 = CPyModule_pandas;
    cpy_r_r32 = CPyStatics[107]; /* 'DataFrame' */
    cpy_r_r33 = CPyObject_GetAttr(cpy_r_r31, cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("modTof.py", "save_ToF", 745, CPyStatic_globals);
        goto CPyL35;
    }
    PyObject *cpy_r_r34[1] = {cpy_r_r30};
    cpy_r_r35 = (PyObject **)&cpy_r_r34;
    cpy_r_r36 = _PyObject_Vectorcall(cpy_r_r33, cpy_r_r35, 1, 0);
    CPy_DECREF(cpy_r_r33);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("modTof.py", "save_ToF", 745, CPyStatic_globals);
        goto CPyL35;
    }
    CPy_DECREF(cpy_r_r30);
    cpy_r_r37 = CPyStatics[120]; /* 'to_csv' */
    cpy_r_r38 = CPyObject_GetAttr(cpy_r_r36, cpy_r_r37);
    CPy_DECREF(cpy_r_r36);
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("modTof.py", "save_ToF", 745, CPyStatic_globals);
        goto CPyL34;
    }
    cpy_r_r39 = 0 ? Py_True : Py_False;
    PyObject *cpy_r_r40[2] = {cpy_r_file, cpy_r_r39};
    cpy_r_r41 = (PyObject **)&cpy_r_r40;
    cpy_r_r42 = CPyStatics[277]; /* ('index',) */
    cpy_r_r43 = _PyObject_Vectorcall(cpy_r_r38, cpy_r_r41, 1, cpy_r_r42);
    CPy_DECREF(cpy_r_r38);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("modTof.py", "save_ToF", 745, CPyStatic_globals);
        goto CPyL34;
    } else
        goto CPyL36;
CPyL24: ;
    CPy_DECREF(cpy_r_file);
    cpy_r_r44 = Py_None;
    CPy_INCREF(cpy_r_r44);
    return cpy_r_r44;
CPyL25: ;
    cpy_r_r45 = NULL;
    return cpy_r_r45;
CPyL26: ;
    CPy_INCREF(cpy_r_filename);
    goto CPyL2;
CPyL27: ;
    CPy_DecRef(cpy_r_filename);
    goto CPyL25;
CPyL28: ;
    CPy_DecRef(cpy_r_filename);
    CPy_DecRef(cpy_r_date);
    CPy_DecRef(cpy_r_num_total);
    goto CPyL25;
CPyL29: ;
    CPy_DecRef(cpy_r_filename);
    CPy_DecRef(cpy_r_date);
    CPy_DecRef(cpy_r_r17);
    goto CPyL25;
CPyL30: ;
    CPy_DecRef(cpy_r_filename);
    CPy_DecRef(cpy_r_date);
    goto CPyL25;
CPyL31: ;
    CPy_DecRef(cpy_r_filename);
    CPy_DecRef(cpy_r_r21);
    goto CPyL25;
CPyL32: ;
    CPy_DECREF(cpy_r_file);
    goto CPyL17;
CPyL33: ;
    CPy_DECREF(cpy_r_filename);
    goto CPyL18;
CPyL34: ;
    CPy_DecRef(cpy_r_file);
    goto CPyL25;
CPyL35: ;
    CPy_DecRef(cpy_r_file);
    CPy_DecRef(cpy_r_r30);
    goto CPyL25;
CPyL36: ;
    CPy_DECREF(cpy_r_r43);
    goto CPyL24;
}

PyObject *CPyPy_Simulation___save_ToF(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"filename", 0};
    static CPyArg_Parser parser = {"|O:save_ToF", kwlist, 0};
    PyObject *obj_filename = NULL;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_filename)) {
        return NULL;
    }
    PyObject *arg_self = obj_self;
    PyObject *arg_filename;
    if (obj_filename == NULL) {
        arg_filename = NULL;
    } else {
        arg_filename = obj_filename; 
    }
    PyObject *retval = CPyDef_Simulation___save_ToF(arg_self, arg_filename);
    return retval;
fail: ;
    CPy_AddTraceback("modTof.py", "save_ToF", 736, CPyStatic_globals);
    return NULL;
}

char CPyDef___top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r5;
    PyObject **cpy_r_r6;
    void *cpy_r_r8;
    void *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r20;
    void *cpy_r_r22;
    void *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    char cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    char cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    PyObject *cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    PyObject *cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    PyObject *cpy_r_r78;
    PyObject *cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject *cpy_r_r84;
    PyObject *cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    PyObject *cpy_r_r89;
    PyObject *cpy_r_r90;
    PyObject *cpy_r_r91;
    PyObject *cpy_r_r92;
    PyObject *cpy_r_r93;
    PyObject *cpy_r_r94;
    PyObject *cpy_r_r95;
    PyObject *cpy_r_r96;
    PyObject *cpy_r_r97;
    PyObject *cpy_r_r98;
    PyObject *cpy_r_r99;
    PyObject *cpy_r_r100;
    PyObject *cpy_r_r101;
    PyObject *cpy_r_r102;
    PyObject *cpy_r_r103;
    PyObject *cpy_r_r104;
    PyObject *cpy_r_r105;
    PyObject *cpy_r_r106;
    PyObject *cpy_r_r107;
    PyObject *cpy_r_r108;
    PyObject *cpy_r_r109;
    PyObject *cpy_r_r110;
    PyObject *cpy_r_r111;
    PyObject *cpy_r_r112;
    int32_t cpy_r_r113;
    char cpy_r_r114;
    PyObject *cpy_r_r115;
    PyObject *cpy_r_r116;
    int32_t cpy_r_r117;
    char cpy_r_r118;
    char cpy_r_r119;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[178]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("modTof.py", "<module>", -1, CPyStatic_globals);
        goto CPyL15;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_numpy;
    cpy_r_r6 = (PyObject **)&CPyModule_pandas;
    PyObject **cpy_r_r7[2] = {cpy_r_r5, cpy_r_r6};
    cpy_r_r8 = (void *)&cpy_r_r7;
    int64_t cpy_r_r9[2] = {15, 16};
    cpy_r_r10 = (void *)&cpy_r_r9;
    cpy_r_r11 = CPyStatics[280]; /* (('numpy', 'numpy', 'np'), ('pandas', 'pandas', 'pd')) */
    cpy_r_r12 = CPyStatic_globals;
    cpy_r_r13 = CPyStatics[183]; /* 'modTof.py' */
    cpy_r_r14 = CPyStatics[184]; /* '<module>' */
    cpy_r_r15 = CPyImport_ImportMany(cpy_r_r11, cpy_r_r8, cpy_r_r12, cpy_r_r13, cpy_r_r14, cpy_r_r10);
    if (!cpy_r_r15) goto CPyL15;
    cpy_r_r16 = CPyStatics[281]; /* ('tqdm',) */
    cpy_r_r17 = CPyStatics[185]; /* 'tqdm' */
    cpy_r_r18 = CPyStatic_globals;
    cpy_r_r19 = CPyImport_ImportFromMany(cpy_r_r17, cpy_r_r16, cpy_r_r16, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("modTof.py", "<module>", 17, CPyStatic_globals);
        goto CPyL15;
    }
    CPyModule_tqdm = cpy_r_r19;
    CPy_INCREF(CPyModule_tqdm);
    CPy_DECREF(cpy_r_r19);
    cpy_r_r20 = (PyObject **)&CPyModule_random;
    PyObject **cpy_r_r21[1] = {cpy_r_r20};
    cpy_r_r22 = (void *)&cpy_r_r21;
    int64_t cpy_r_r23[1] = {19};
    cpy_r_r24 = (void *)&cpy_r_r23;
    cpy_r_r25 = CPyStatics[283]; /* (('random', 'random', 'random'),) */
    cpy_r_r26 = CPyStatic_globals;
    cpy_r_r27 = CPyStatics[183]; /* 'modTof.py' */
    cpy_r_r28 = CPyStatics[184]; /* '<module>' */
    cpy_r_r29 = CPyImport_ImportMany(cpy_r_r25, cpy_r_r22, cpy_r_r26, cpy_r_r27, cpy_r_r28, cpy_r_r24);
    if (!cpy_r_r29) goto CPyL15;
    cpy_r_r30 = CPyStatics[284]; /* ('perf_counter', 'perf_counter_ns') */
    cpy_r_r31 = CPyStatics[102]; /* 'time' */
    cpy_r_r32 = CPyStatic_globals;
    cpy_r_r33 = CPyImport_ImportFromMany(cpy_r_r31, cpy_r_r30, cpy_r_r30, cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("modTof.py", "<module>", 20, CPyStatic_globals);
        goto CPyL15;
    }
    CPyModule_time = cpy_r_r33;
    CPy_INCREF(CPyModule_time);
    CPy_DECREF(cpy_r_r33);
    cpy_r_r34 = CPyStatics[285]; /* ('timedelta', 'datetime') */
    cpy_r_r35 = CPyStatics[115]; /* 'datetime' */
    cpy_r_r36 = CPyStatic_globals;
    cpy_r_r37 = CPyImport_ImportFromMany(cpy_r_r35, cpy_r_r34, cpy_r_r34, cpy_r_r36);
    if (unlikely(cpy_r_r37 == NULL)) {
        CPy_AddTraceback("modTof.py", "<module>", 21, CPyStatic_globals);
        goto CPyL15;
    }
    CPyModule_datetime = cpy_r_r37;
    CPy_INCREF(CPyModule_datetime);
    CPy_DECREF(cpy_r_r37);
    cpy_r_r38 = CPyStatics[286]; /* ('Pool', 'cpu_count', 'freeze_support') */
    cpy_r_r39 = CPyStatics[187]; /* 'multiprocessing' */
    cpy_r_r40 = CPyStatic_globals;
    cpy_r_r41 = CPyImport_ImportFromMany(cpy_r_r39, cpy_r_r38, cpy_r_r38, cpy_r_r40);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("modTof.py", "<module>", 25, CPyStatic_globals);
        goto CPyL15;
    }
    CPyModule_multiprocessing = cpy_r_r41;
    CPy_INCREF(CPyModule_multiprocessing);
    CPy_DECREF(cpy_r_r41);
    cpy_r_r42 = NULL;
    cpy_r_r43 = CPyStatics[188]; /* 'modTof' */
    cpy_r_r44 = (PyObject *)CPyType_Simulation_template;
    cpy_r_r45 = CPyType_FromTemplate(cpy_r_r44, cpy_r_r42, cpy_r_r43);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("modTof.py", "<module>", 27, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r46 = CPyDef_Simulation_trait_vtable_setup();
    if (unlikely(cpy_r_r46 == 2)) {
        CPy_AddTraceback("modTof.py", "<module>", -1, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r47 = CPyStatics[189]; /* '__mypyc_attrs__' */
    cpy_r_r48 = CPyStatics[190]; /* 'c' */
    cpy_r_r49 = CPyStatics[191]; /* 'q' */
    cpy_r_r50 = CPyStatics[192]; /* 'n_1' */
    cpy_r_r51 = CPyStatics[193]; /* 'n_2' */
    cpy_r_r52 = CPyStatics[194]; /* 'T3z' */
    cpy_r_r53 = CPyStatics[195]; /* 'T1z' */
    cpy_r_r54 = CPyStatics[196]; /* 'T4z' */
    cpy_r_r55 = CPyStatics[197]; /* 'T1_radius' */
    cpy_r_r56 = CPyStatics[198]; /* 'T4_radius' */
    cpy_r_r57 = CPyStatics[199]; /* 'T1_width' */
    cpy_r_r58 = CPyStatics[200]; /* 'T4_width' */
    cpy_r_r59 = CPyStatics[201]; /* 'T1top' */
    cpy_r_r60 = CPyStatics[202]; /* 'T4top' */
    cpy_r_r61 = CPyStatics[203]; /* 'T1_corner_radius' */
    cpy_r_r62 = CPyStatics[204]; /* 'T4_corner_radius' */
    cpy_r_r63 = CPyStatics[205]; /* 'T1_corner_center' */
    cpy_r_r64 = CPyStatics[206]; /* 'T4_corner_center' */
    cpy_r_r65 = CPyStatics[207]; /* 'PMT1_center' */
    cpy_r_r66 = CPyStatics[208]; /* 'PMT4_center' */
    cpy_r_r67 = CPyStatics[209]; /* 'xPMT4' */
    cpy_r_r68 = CPyStatics[210]; /* 'yPMT4' */
    cpy_r_r69 = CPyStatics[211]; /* 'xPMT1' */
    cpy_r_r70 = CPyStatics[212]; /* 'yPMT1' */
    cpy_r_r71 = CPyStatics[213]; /* 'PMT1_radius' */
    cpy_r_r72 = CPyStatics[214]; /* 'PMT4_radius' */
    cpy_r_r73 = CPyStatics[215]; /* 'n_dynodes' */
    cpy_r_r74 = CPyStatics[170]; /* 'V' */
    cpy_r_r75 = CPyStatics[216]; /* 'E_per_electron' */
    cpy_r_r76 = CPyStatics[217]; /* 'QE' */
    cpy_r_r77 = CPyStatics[218]; /* 'sigma_smoothing' */
    cpy_r_r78 = CPyStatics[219]; /* 't_initial' */
    cpy_r_r79 = CPyStatics[220]; /* 'particle_init_angle_range' */
    cpy_r_r80 = CPyStatics[221]; /* 'particle_gen_area' */
    cpy_r_r81 = CPyStatics[222]; /* 'particle_gen_z' */
    cpy_r_r82 = CPyStatics[223]; /* 'mean_free_path_scints' */
    cpy_r_r83 = CPyStatics[224]; /* 'photons_produced_per_MeV' */
    cpy_r_r84 = CPyStatics[225]; /* 'pr_of_scintillation' */
    cpy_r_r85 = CPyStatics[226]; /* 'max_simulated_reflections' */
    cpy_r_r86 = CPyStatics[227]; /* 'pmt_electron_travel_time' */
    cpy_r_r87 = CPyStatics[228]; /* 'artificial_gain' */
    cpy_r_r88 = CPyStatics[229]; /* 'max_pmt_current_output' */
    cpy_r_r89 = CPyStatics[230]; /* 'pr_absorption' */
    cpy_r_r90 = CPyStatics[231]; /* 'seperation_time' */
    cpy_r_r91 = CPyStatics[232]; /* 'output_bin_width' */
    cpy_r_r92 = CPyStatics[233]; /* 'num_particles' */
    cpy_r_r93 = CPyStatics[234]; /* 'CMOS_thresh' */
    cpy_r_r94 = CPyStatics[235]; /* 'reemission_angle_factor' */
    cpy_r_r95 = CPyStatics[103]; /* 'T1_prop_dist' */
    cpy_r_r96 = CPyStatics[109]; /* 'T4_prop_dist' */
    cpy_r_r97 = CPyStatics[104]; /* 'T1_endpoint_dist' */
    cpy_r_r98 = CPyStatics[110]; /* 'T4_endpoint_dist' */
    cpy_r_r99 = CPyStatics[105]; /* 'T1_prop_times' */
    cpy_r_r100 = CPyStatics[111]; /* 'T4_prop_times' */
    cpy_r_r101 = CPyStatics[106]; /* 'T1_interactions' */
    cpy_r_r102 = CPyStatics[112]; /* 'T4_interactions' */
    cpy_r_r103 = CPyStatics[101]; /* 'T1_part_ids' */
    cpy_r_r104 = CPyStatics[108]; /* 'T4_part_ids' */
    cpy_r_r105 = CPyStatics[236]; /* 'signals' */
    cpy_r_r106 = CPyStatics[237]; /* 'output_times' */
    cpy_r_r107 = CPyStatics[238]; /* 'signals_channelT1' */
    cpy_r_r108 = CPyStatics[239]; /* 'signals_channelT4' */
    cpy_r_r109 = CPyStatics[240]; /* 'output_times_channelT1' */
    cpy_r_r110 = CPyStatics[241]; /* 'output_times_channelT4' */
    cpy_r_r111 = CPyStatics[242]; /* 'FinalToF' */
    cpy_r_r112 = PyTuple_Pack(64, cpy_r_r48, cpy_r_r49, cpy_r_r50, cpy_r_r51, cpy_r_r52, cpy_r_r53, cpy_r_r54, cpy_r_r55, cpy_r_r56, cpy_r_r57, cpy_r_r58, cpy_r_r59, cpy_r_r60, cpy_r_r61, cpy_r_r62, cpy_r_r63, cpy_r_r64, cpy_r_r65, cpy_r_r66, cpy_r_r67, cpy_r_r68, cpy_r_r69, cpy_r_r70, cpy_r_r71, cpy_r_r72, cpy_r_r73, cpy_r_r74, cpy_r_r75, cpy_r_r76, cpy_r_r77, cpy_r_r78, cpy_r_r79, cpy_r_r80, cpy_r_r81, cpy_r_r82, cpy_r_r83, cpy_r_r84, cpy_r_r85, cpy_r_r86, cpy_r_r87, cpy_r_r88, cpy_r_r89, cpy_r_r90, cpy_r_r91, cpy_r_r92, cpy_r_r93, cpy_r_r94, cpy_r_r95, cpy_r_r96, cpy_r_r97, cpy_r_r98, cpy_r_r99, cpy_r_r100, cpy_r_r101, cpy_r_r102, cpy_r_r103, cpy_r_r104, cpy_r_r105, cpy_r_r106, cpy_r_r107, cpy_r_r108, cpy_r_r109, cpy_r_r110, cpy_r_r111);
    if (unlikely(cpy_r_r112 == NULL)) {
        CPy_AddTraceback("modTof.py", "<module>", 27, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r113 = PyObject_SetAttr(cpy_r_r45, cpy_r_r47, cpy_r_r112);
    CPy_DECREF(cpy_r_r112);
    cpy_r_r114 = cpy_r_r113 >= 0;
    if (unlikely(!cpy_r_r114)) {
        CPy_AddTraceback("modTof.py", "<module>", 27, CPyStatic_globals);
        goto CPyL16;
    }
    CPyType_Simulation = (PyTypeObject *)cpy_r_r45;
    CPy_INCREF(CPyType_Simulation);
    cpy_r_r115 = CPyStatic_globals;
    cpy_r_r116 = CPyStatics[243]; /* 'Simulation' */
    cpy_r_r117 = CPyDict_SetItem(cpy_r_r115, cpy_r_r116, cpy_r_r45);
    CPy_DECREF(cpy_r_r45);
    cpy_r_r118 = cpy_r_r117 >= 0;
    if (unlikely(!cpy_r_r118)) {
        CPy_AddTraceback("modTof.py", "<module>", 27, CPyStatic_globals);
        goto CPyL15;
    }
    return 1;
CPyL15: ;
    cpy_r_r119 = 2;
    return cpy_r_r119;
CPyL16: ;
    CPy_DecRef(cpy_r_r45);
    goto CPyL15;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_modTof = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_numpy = Py_None;
    CPyModule_pandas = Py_None;
    CPyModule_tqdm = Py_None;
    CPyModule_random = Py_None;
    CPyModule_time = Py_None;
    CPyModule_datetime = Py_None;
    CPyModule_multiprocessing = Py_None;
    CPyModule_gc = Py_None;
    CPyModule_scipy___stats = Py_None;
    CPyModule_os = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[287];
const char * const CPyLit_Str[] = {
    "\004\aradians\003cos\003sin\blinspace",
    "\0026######################################################\005print",
    "\0016Generated Apparatus Simulation with following defaults",
    "\002\032PARTICLE: Mean Free Path =\002cm",
    "\001RPARTICLE: Time Seperation between sequential Particles if simulation more than 1 =",
    "\001\'SCINT:    Probability of Scintillaton =",
    "\002&PMT:      Quantum Efficiency is set to\036by default to keep more pulses",
    "\002,PMT:      Energy per Photoelectron is set to\022by best estimation",
    "\001-PMT:      Artificial Gain on Output Current =",
    "\002-OUTPUT:   Binning Width for PWL output file =\002ps",
    "\0018\nRun with .run() function given optional arguments below",
    "\003 integer n particles, \'delta_t\' =\033ps particle time seperation\003abs",
    "\r\005log10\005floor\006linalg\004norm\003sum\004sqrt\003dot\005array\003min\005cross\006arcsin\006random\002pi",
    "\v\auniform\afloat64\005dtype\005round\005clear\006append\apoisson\005zeros\003any\006hstack\002gc",
    "\005\016freeze_support\vGenerating \021 particles now...\020 particle now...\adelta_t",
    "\006\fperf_counter\tcpu_count\004Pool\tprocesses\b__exit__\t__enter__",
    "\b\rparticle_task\003map\006extend\006repeat\021Photons generated\aasarray\006astype\004axis",
    "\003\017Photons in T1: \024 and Photons in T4: \acollect",
    "\005 T1 Photon Propagation working...\fscint_taskT1\002c_\astarmap\005Done!",
    "\002 T4 Photon Propagation working...\fscint_taskT4",
    "\004 Unzipping reuslts into arrays...\016TIME ANALYSIS:\ttimedelta\aseconds",
    "\002\034Generation of Particles     \034Simulation of Photon Travel ",
    "\003\034Total Time Elapsed:         \020RESULTS SUMMARY:\nHITS on T1",
    "\006\030RATIO T1   total photons\026total incident photons\000\006ratio=\005{:{}}\003.2f",
    "\005\006format\nHITS on T4\031RATIO T4   total photons \nDISTANCE: \vscipy.stats",
    "\005\017extra_data_only\voutput_both\027Exporting Extra Data...\vT1_part_ids\004time",
    "\005\fT1_prop_dist\020T1_endpoint_dist\rT1_prop_times\017T1_interactions\tDataFrame",
    "\004\vT4_part_ids\fT4_prop_dist\020T4_endpoint_dist\rT4_prop_times",
    "\006\017T4_interactions\025monte_carlo_extradata\005chT1_\bdatetime\003now\b%m_%d_%Y",
    "\005\bstrftime\004.txt\006to_csv\005chT4_\031Exporing to 2 channels...",
    "\t\024Smoothing Signals...\003max\bdigitize\006arange\006insert\003pdf\003loc\005scale\acurrent",
    "\006\vsort_values\002by\033Formatting PWL dataframe...\004iloc\acolumns\006concat",
    "\b\fignore_index\vreset_index\004drop\021monte_carlo_input\002ch\001_\005%.13f\001 ",
    "\n\ffloat_format\006header\005index\003sep\bgradient\004diff\apolyfit\003deg\002Ch\acounted",
    "\002\nparticles!/Note: Counted less particles than the expected ",
    "\0020Check LTSpice that all particles were simulated.\nch1 length",
    "\a\nch4 length\025finished calculating,\tparticles\002os\006output\004ch1_\004path",
    "\n\aabspath\004ch4_\001t\001V\001,\bread_csv\005names\bdescribe\aresult_\004_of_",
    "\b\022Time-of-Flight [s]\bbuiltins\005numpy\002np\006pandas\002pd\tmodTof.py\b<module>",
    "\b\004tqdm\017perf_counter_ns\017multiprocessing\006modTof\017__mypyc_attrs__\001c\001q\003n_1",
    "\n\003n_2\003T3z\003T1z\003T4z\tT1_radius\tT4_radius\bT1_width\bT4_width\005T1top\005T4top",
    "\004\020T1_corner_radius\020T4_corner_radius\020T1_corner_center\020T4_corner_center",
    "\a\vPMT1_center\vPMT4_center\005xPMT4\005yPMT4\005xPMT1\005yPMT1\vPMT1_radius",
    "\006\vPMT4_radius\tn_dynodes\016E_per_electron\002QE\017sigma_smoothing\tt_initial",
    "\003\031particle_init_angle_range\021particle_gen_area\016particle_gen_z",
    "\003\025mean_free_path_scints\030photons_produced_per_MeV\023pr_of_scintillation",
    "\003\031max_simulated_reflections\030pmt_electron_travel_time\017artificial_gain",
    "\004\026max_pmt_current_output\rpr_absorption\017seperation_time\020output_bin_width",
    "\004\rnum_particles\vCMOS_thresh\027reemission_angle_factor\asignals",
    "\003\foutput_times\021signals_channelT1\021signals_channelT4",
    "\004\026output_times_channelT1\026output_times_channelT4\bFinalToF\nSimulation",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "\0240\00013\00018\0001\0004\000110\000-45\0008\000150\000850\00020\000400\00040\0002\00010\000100\000-1\000180\0007\0005",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {
    23, 1, 40, 1, 57, 1, 67, 1, 81, 1, 28, 2, 129, 130, 1, 133, 1, 136,
    1, 138, 1, 140, 4, 146, 147, 148, 149, 1, 153, 2, 173, 149, 1, 148, 3,
    179, 179, 180, 3, 181, 181, 182, 2, 278, 279, 1, 185, 3, 36, 36, 36,
    1, 282, 2, 54, 186, 2, 80, 115, 3, 56, 55, 49
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_modTof_internal = NULL;
CPyModule *CPyModule_modTof;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_numpy;
CPyModule *CPyModule_pandas;
CPyModule *CPyModule_tqdm;
CPyModule *CPyModule_random;
CPyModule *CPyModule_time;
CPyModule *CPyModule_datetime;
CPyModule *CPyModule_multiprocessing;
CPyModule *CPyModule_gc;
CPyModule *CPyModule_scipy___stats;
CPyModule *CPyModule_os;
PyTypeObject *CPyType_Simulation;
PyObject *CPyDef_Simulation(void);
char CPyDef_Simulation_____init__(PyObject *cpy_r_self);
PyObject *CPyPy_Simulation_____init__(PyObject *self, PyObject *args, PyObject *kw);
PyObject *CPyDef_Simulation___round_to_sig(PyObject *cpy_r_self, PyObject *cpy_r_x);
PyObject *CPyPy_Simulation___round_to_sig(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Simulation___normalize(PyObject *cpy_r_self, PyObject *cpy_r_x);
PyObject *CPyPy_Simulation___normalize(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Simulation___lg_condition(PyObject *cpy_r_self, PyObject *cpy_r_corner_pt, PyObject *cpy_r_scint_corner, PyObject *cpy_r_scint_num);
PyObject *CPyPy_Simulation___lg_condition(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Simulation___scint_condition(PyObject *cpy_r_self, PyObject *cpy_r_corner_pt, PyObject *cpy_r_scint_radius, PyObject *cpy_r_scint_num);
PyObject *CPyPy_Simulation___scint_condition(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Simulation___distance_circle(PyObject *cpy_r_self, PyObject *cpy_r_u, PyObject *cpy_r_o, PyObject *cpy_r_center, PyObject *cpy_r_radius, PyObject *cpy_r_quadrant);
PyObject *CPyPy_Simulation___distance_circle(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Simulation___distance_plane(PyObject *cpy_r_self, PyObject *cpy_r_u, PyObject *cpy_r_o, PyObject *cpy_r_plane, PyObject *cpy_r_dim);
PyObject *CPyPy_Simulation___distance_plane(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Simulation___distance_solver(PyObject *cpy_r_self, PyObject *cpy_r_u, PyObject *cpy_r_o, PyObject *cpy_r_center, PyObject *cpy_r_radius, PyObject *cpy_r_plane_z, PyObject *cpy_r_corner_center, PyObject *cpy_r_corner_radius, PyObject *cpy_r_pmt_center, PyObject *cpy_r_pmt_radius);
PyObject *CPyPy_Simulation___distance_solver(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Simulation___photon_interaction(PyObject *cpy_r_self, PyObject *cpy_r_u, PyObject *cpy_r_n);
PyObject *CPyPy_Simulation___photon_interaction(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Simulation___n_vec_calculate(PyObject *cpy_r_self, PyObject *cpy_r_o, PyObject *cpy_r_scint_plane, PyObject *cpy_r_light_guide_planes, PyObject *cpy_r_corner_center, PyObject *cpy_r_corner_radius);
PyObject *CPyPy_Simulation___n_vec_calculate(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Simulation___particle_path(PyObject *cpy_r_self, PyObject *cpy_r_t, PyObject *cpy_r_phi_range_deg, PyObject *cpy_r_T1_z, PyObject *cpy_r_T1_width, PyObject *cpy_r_T4_z, PyObject *cpy_r_T4_width, PyObject *cpy_r_T1_radius, PyObject *cpy_r_T4_radius, PyObject *cpy_r_T1_corner, PyObject *cpy_r_T4_corner, PyObject *cpy_r_mean_free_path, PyObject *cpy_r_photons_per_E, PyObject *cpy_r_prob_scint);
PyObject *CPyPy_Simulation___particle_path(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Simulation___scintillator_monte_carlo(PyObject *cpy_r_self, PyObject *cpy_r_o, PyObject *cpy_r_notabsorbed, PyObject *cpy_r_scint_radius, PyObject *cpy_r_scint_plane, PyObject *cpy_r_light_guide_planes, PyObject *cpy_r_pmt_center, PyObject *cpy_r_pmt_radius, PyObject *cpy_r_corner_center, PyObject *cpy_r_corner_radius, PyObject *cpy_r_N_max, PyObject *cpy_r_t, PyObject *cpy_r_keepdata);
PyObject *CPyPy_Simulation___scintillator_monte_carlo(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Simulation___photontoElectrons(PyObject *cpy_r_self, PyObject *cpy_r_photons);
PyObject *CPyPy_Simulation___photontoElectrons(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Simulation___particle_task(PyObject *cpy_r_self, PyObject *cpy_r_mult);
PyObject *CPyPy_Simulation___particle_task(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Simulation___scint_taskT1(PyObject *cpy_r_self, PyObject *cpy_r_xpoint, PyObject *cpy_r_ypoint, PyObject *cpy_r_zpoint, PyObject *cpy_r_time_i);
PyObject *CPyPy_Simulation___scint_taskT1(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Simulation___scint_taskT4(PyObject *cpy_r_self, PyObject *cpy_r_xpoint, PyObject *cpy_r_ypoint, PyObject *cpy_r_zpoint, PyObject *cpy_r_time_i);
PyObject *CPyPy_Simulation___scint_taskT4(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Simulation___run(PyObject *cpy_r_self, PyObject *cpy_r_arg, PyObject *cpy_r_kwargs);
PyObject *CPyPy_Simulation___run(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Simulation___time_at_thresh(PyObject *cpy_r_self, PyObject *cpy_r_rawtime, PyObject *cpy_r_rawVoltage, PyObject *cpy_r_num, PyObject *cpy_r_thresh, PyObject *cpy_r_ch);
PyObject *CPyPy_Simulation___time_at_thresh(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Simulation___ToF_finalize(PyObject *cpy_r_self, PyObject *cpy_r_tofch1, PyObject *cpy_r_tofch4, PyObject *cpy_r_time_limit);
PyObject *CPyPy_Simulation___ToF_finalize(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Simulation___calc_ToF(PyObject *cpy_r_self, PyObject *cpy_r_filedate, PyObject *cpy_r_filenum);
PyObject *CPyPy_Simulation___calc_ToF(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef_Simulation___save_ToF(PyObject *cpy_r_self, PyObject *cpy_r_filename);
PyObject *CPyPy_Simulation___save_ToF(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);
