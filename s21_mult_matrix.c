#include "s21_matrix.h"

/**
 * Входая проверка через функцию check_matrix_for_mult()
 * Перемножает значения матриц по правилам для умножения матриц (сложно
 * объяснять) Возвращаемые значения: 0 - OK 1 - INCORRECT_MATRIX 2 -
 * CALCULATION_ERROR
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int check = check_matrix_for_mult(A, B);
  int flag = OK;
  if (check == OK) {
    s21_create_matrix(A->rows, B->columns, result);
    for (int row_a = 0; row_a < A->rows; row_a++) {
      for (int column_b = 0; column_b < B->columns; column_b++) {
        for (int column_a = 0; column_a < A->columns; column_a++) {
          result->matrix[row_a][column_b] +=
              A->matrix[row_a][column_a] * B->matrix[column_a][column_b];
        }
      }
    }

  } else if (check == CALCULATION_ERROR) {
    flag = CALCULATION_ERROR;
  } else {
    flag = INCORRECT_MATRIX;
  }
  return flag;
}

/**
 * Проверяет, что матрицы A и B существуют, и что кол-во столбцов первой
 * матрицы равно кол-во строк второй матрицы (условие для умножения матриц).
 * Возвращаемые значения:
 * 0 - OK
 * 1 - INCORRECT_MATRIX
 * 2 - CALCULATION_ERROR
 */
int check_matrix_for_mult(matrix_t *A, matrix_t *B) {
  int result = OK;
  if (check_matrix(A) == SUCCESS && check_matrix(B) == SUCCESS) {
    if (A->columns != B->rows) {
      result = CALCULATION_ERROR;
    }
  } else {
    result = INCORRECT_MATRIX;
  }
  return result;
}
