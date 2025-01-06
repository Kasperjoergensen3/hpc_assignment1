/*data.h*/
double **dmalloc_2d(int m, int n);
void free_2d(double **A);

double **copy_matrix(int m, int n, double **A);
double **zero_matrix(int m, int n, double **A);

double **random_matrix(int m, int n);
double *random_vector(int n);

void print_vector(int n, double *v);
void print_matrix(int m, int n, double **A);
