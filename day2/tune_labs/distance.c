#include <math.h>
#include "distance.h"

#ifdef ARRAY_OF_STRUCTS
double
distance(particle_t *p, int n)
{

    double sum_dist = 0; // total sum of all distances
    for (int i = 0; i < n; i++)
    {
        p[i].dist = sqrt(pow(p[i].x, 2) + pow(p[i].y, 2) + pow(p[i].z, 2));
        sum_dist += p[i].dist;
    }
    return sum_dist;
}
#else
double
distance(particle_t p, int n)
{

    double sum_dist = 0; // total sum of all distances
    for (int i = 0; i < n; i++)
    {
        p.dist[i] = sqrt(pow(p.x[i], 2) + pow(p.y[i], 2) + pow(p.z[i], 2));
        sum_dist += p.dist[i];
    }
    return sum_dist;
}
#endif
