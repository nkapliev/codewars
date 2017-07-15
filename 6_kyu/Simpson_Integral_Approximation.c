#include <stdio.h>
#include <math.h>

#define SIMPSON_METHOD 1

double fun(double x) {
    return (3.0 / 2) * pow(sin(x), 3);
}

double simpson_helper(double (*f)(double), double from, double to, int steps) {
    double result = 0.0;
    double acc = 0.0;
    double h = (to - from) / steps;

    result += (*f)(from) + (*f)(to);

    acc = 0.0;
    for (int i = 1, limit = steps / 2; i <= limit; i++) {
        acc += (*f)(from + (2 * i - 1) * h);
    }
    result += 4 * acc;

    acc = 0.0;
    for (int i = 1, limit = steps / 2 - 1; i <= limit; i++) {
        acc += (*f)(from + 2 * i * h);
    }
    result += 2 * acc;

    return (h / 3) * result;
}

/*codewars task function*/
double simpson(int n) {
    return simpson_helper(fun, 0, M_PI, n);
}

double integral(double (*f)(double), double from, double to, int precision, int method) {
    switch(method) {
        case SIMPSON_METHOD:
        default:
            return simpson_helper(f, from, to, precision);
    }
}

int main () {
    unsigned int n;

    scanf("%d", &n);
    printf("%f", integral(fun, 0, M_PI, n, SIMPSON_METHOD));

    return 1;
}
