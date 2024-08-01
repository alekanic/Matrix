#include "s21_matrix.h"

/**
 * Сравнивает размеры матриц A и B, если они идентичны -
 * выделяет необходимую память под матрицу result и вычитает B из A
 * Возвращаемые значения:
 * 0 - OK
 * 1 - INCORRECT_MATRIX
 * 2 - СALCULATION_ERROR
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;
  if (!check_matrix(A) || !check_matrix(B)) {
    flag = INCORRECT_MATRIX;
  } else if (compare_the_size_of_matrix(A, B) == FAILURE) {
    flag = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    s21_sub(A, B, result);
  }
  return flag;
}

/**
 * Функция вычитает из А[i][j] B[i][j] и записывает значение в
 * result[i][j]
 */
void s21_sub(matrix_t *A, matrix_t *B, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
}
