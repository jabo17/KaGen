#pragma once

#include <mpi.h>
#include <stdbool.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

struct kagen_gen;
typedef struct kagen_gen kagen_gen_t;

struct kagen_result;
typedef struct kagen_result kagen_result_t;

struct kagen_edge {
    unsigned long long target, source;
};
typedef struct kagen_edge kagen_edge_t;

kagen_gen_t* kagen_create(MPI_Comm comm);
void         kagen_free(kagen_gen_t* gen);

void          kagen_result_vertex_range(kagen_result_t* result, unsigned long long* begin, unsigned long long* end);
kagen_edge_t* kagen_result_edge_list(kagen_result_t* result, size_t* nedges);
void          kagen_result_free(kagen_result_t* result);

void kagen_set_seed(kagen_gen_t* gen, int seed);
void kagen_enable_undirected_graph_verification(kagen_gen_t* gen);
void kagen_enable_basic_statistics(kagen_gen_t* gen);
void kagen_enable_advanced_statistics(kagen_gen_t* gen);
void kagen_enable_output(kagen_gen_t* gen, bool header);
void kagen_use_hpf_floats(kagen_gen_t* gen, bool state);
void kagen_set_numer_of_chunks(kagen_gen_t* gen, unsigned long long k);

kagen_result_t*
kagen_generate_directed_gnm(kagen_gen_t* gen, unsigned long long n, unsigned long long m, bool self_loops);
kagen_result_t*
kagen_generate_undirected_gnm(kagen_gen_t* gen, unsigned long long n, unsigned long long m, bool self_loops);
kagen_result_t* kagen_generate_directed_gnp(kagen_gen_t* gen, unsigned long long n, double p, bool self_loops);
kagen_result_t* kagen_generate_undirected_gnp(kagen_gen_t* gen, unsigned long long n, double p, bool self_loops);

kagen_result_t* kagen_generate_rgg2d(kagen_gen_t* gen, unsigned long long n, double r);
kagen_result_t* kagen_generate_rgg2d_nm(kagen_gen_t* gen, unsigned long long n, unsigned long long m);
kagen_result_t* kagen_generate_rgg2d_mr(kagen_gen_t* gen, unsigned long long m, double r);

kagen_result_t* kagen_generate_rgg3d(kagen_gen_t* gen, unsigned long long n, double r);
kagen_result_t* kagen_generate_rgg3d_nm(kagen_gen_t* gen, unsigned long long n, unsigned long long m);
kagen_result_t* kagen_generate_rgg3d_mr(kagen_gen_t* gen, unsigned long long m, double r);

kagen_result_t* kagen_generate_rdg2d(kagen_gen_t* gen, unsigned long long n, bool periodic);
kagen_result_t* kagen_generate_rdg2d_m(kagen_gen_t* gen, unsigned long long m, bool periodic);
kagen_result_t* kagen_generate_rdg3d(kagen_gen_t* gen, unsigned long long n);
kagen_result_t* kagen_generate_rdg3d_m(kagen_gen_t* gen, unsigned long long m);

kagen_result_t*
kagen_generate_ba(kagen_gen_t* gen, unsigned long long n, unsigned long long d, bool directed, bool self_loops);
kagen_result_t*
kagen_generate_ba_nm(kagen_gen_t* gen, unsigned long long n, unsigned long long m, bool directed, bool self_loops);
kagen_result_t*
kagen_generate_ba_md(kagen_gen_t* gen, unsigned long long m, unsigned long long d, bool directed, bool self_loops);

kagen_result_t* kagen_generate_rhg(kagen_gen_t* gen, double gamma, unsigned long long n, double d);
kagen_result_t* kagen_generate_rhg_nm(kagen_gen_t* gen, double gamma, unsigned long long n, unsigned long long m);
kagen_result_t* kagen_generate_rhg_md(kagen_gen_t* gen, double gamma, unsigned long long m, double d);

kagen_result_t*
kagen_generate_grid2d(kagen_gen_t* gen, unsigned long long grid_x, unsigned long long grid_y, double p, bool periodic);
kagen_result_t* kagen_generate_grid2d_n(kagen_gen_t* gen, unsigned long long n, double p, bool periodic);
kagen_result_t* kagen_generate_grid3d(
    kagen_gen_t* gen, unsigned long long grid_x, unsigned long long grid_y, unsigned long long grid_z, double p,
    bool periodic);
kagen_result_t* kagen_generate_grid3d_n(kagen_gen_t* gen, unsigned long long n, double p, bool periodic);

kagen_result_t*
kagen_generate_kronecker(kagen_gen_t* gen, unsigned long long n, unsigned long long m, bool directed, bool self_loops);

kagen_result_t* kagen_generate_rmat(
    kagen_gen_t* gen, unsigned long long n, unsigned long long m, double a, double b, double c, bool directed,
    bool self_loops);

void kagen_build_vertex_distribution(kagen_result_t* result, unsigned long long* dist, MPI_Comm comm);
void kagen_build_csr(kagen_result_t* result, unsigned long long* xadj, unsigned long long* adjncy);

#ifdef __cplusplus
}
#endif
