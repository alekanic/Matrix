#define SUCCESS 1
#define FAILURE 0

#define ONE_NUMBER_MATRIX 10

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum result_code {
  OK = 0,
  INCORRECT_MATRIX,  // код 1
  CALCULATION_ERROR  // код 2
};

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// доп функции

int check_matrix(matrix_t *A);
void s21_sum(matrix_t *A, matrix_t *B, matrix_t *result);
void s21_sub(matrix_t *A, matrix_t *B, matrix_t *result);
int compare_the_size_of_matrix(matrix_t *A, matrix_t *B);
int is_nan(matrix_t *A);
int check_matrix_for_mult(matrix_t *A, matrix_t *B);
void s21_initialize_matrix(matrix_t *A, double start_value,
                           double iteration_step);
void s21_initialize_matrix_one_value(matrix_t *A, double value);
void print_matrix(matrix_t *A);
int is_matrix_square(matrix_t *A);
void calc_determinant(matrix_t *A, double *result);
int create_matrix_for_minor(matrix_t *A, int row, matrix_t *result);
void create_matrix_for_complements(matrix_t *A, int row, int column,
                                   matrix_t *minor);
void check_sign(matrix_t *A, matrix_t *result);