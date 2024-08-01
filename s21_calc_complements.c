#include "s21_matrix.h"

/**
 * Функция создает матрицу алгебраических дополнений для
 * исходной матрицы А
 * Возвращаемые значения:
 * 0 - OK
 * 1 - INCORRECT_MATRIX
 * 2 - CALCULATION_ERROR
 */
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  // проверки
  if (check_matrix(A) == FAILURE || A->matrix == NULL || result == NULL) {
    return INCORRECT_MATRIX;
  }
  if (is_matrix_square(A) == FAILURE) {
    return CALCULATION_ERROR;
  }

  int flag = OK;
  s21_create_matrix(A->rows, A->columns, result);

  // для единичной матрицы отдельные условия
  if (A->rows == 1) {
    result->matrix[0][0] = A->matrix[0][0];
  } else {
    matrix_t minor = {NULL, 0, 0};
    s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
    for (int row_a = 0; row_a < A->rows; row_a++) {
      for (int col_a = 0; col_a < A->columns; col_a++) {
        create_matrix_for_complements(A, row_a, col_a, &minor);
        s21_determinant(&minor, &result->matrix[row_a][col_a]);
      }
    }
    if (A->rows > 1) {
      s21_remove_matrix(&minor);
      check_sign(A, result);
    }
  }
  return flag;
}
