#include "data.h"

#ifdef ARRAY_OF_STRUCTS
double
distcheck(particle_t *p, int n)
{

    double sum_dist = 0; // total sum of all distances
    for (int i = 0; i < n; i++)
    {
        sum_dist += p[i].dist;
    }
    return sum_dist;
}
#else
double
distcheck(particle_t p, int n)
{

    double sum_dist = 0; // total sum of all distances
    for (int i = 0; i < n; i++)
    {
        sum_dist += p.dist[i];
    }
    return sum_dist;
}
#endif
