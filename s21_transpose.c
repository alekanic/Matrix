#include "s21_matrix.h"

/**
 * Транспонирование матрицы А заключается в замене строк этой матрицы
 * ее столбцами с теми же номеромами
 */
int s21_transpose(matrix_t *A, matrix_t *result) {
  int flag = OK;
  if (check_matrix(A) == SUCCESS && A->matrix != NULL) {
    s21_create_matrix(A->columns, A->rows, result);
    for (int a_row = 0; a_row < A->rows; a_row++) {
      for (int a_column = 0; a_column < A->columns; a_column++) {
        result->matrix[a_column][a_row] = A->matrix[a_row][a_column];
      }
    }
  } else {
    flag = INCORRECT_MATRIX;
  }
  return flag;
}