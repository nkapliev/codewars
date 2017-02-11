#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char *series_sum(const size_t n);

char *series_sum(const size_t n)
{
    size_t res_size = 50;
    char * res = (char *)malloc(res_size * sizeof(char));
    if (!res) return NULL;

    double sum = n ? 1. : 0.;
    for (int i = 1; i < n; i++) sum += 1.0 / (1 + i * 3);
    snprintf(res, res_size, "%.2lf", sum);
    return res;
}

