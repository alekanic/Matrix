#include "s21_matrix.h"

/**
 * Функция умножает матрицу A на число number
 * Создает матрицу result же размерности, каждый элемент которой является
 * результатом произведения соответствующего элемента исходной матрицы на
 * заданное число Возвращаемые значения: 0 - OK 1 - INCORRECT_MATRIX
 */

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int flag = OK;
  if (check_matrix(A) == SUCCESS) {
    s21_create_matrix(A->rows, A->columns, result);
    if (number == 0) {
      s21_initialize_matrix_one_value(A, 0);
    } else {
      for (int row = 0; row < A->rows; row++) {
        for (int column = 0; column < A->columns; column++) {
          double old_value = A->matrix[row][column];
          result->matrix[row][column] = old_value * number;
        }
      }
    }
  } else {
    flag = INCORRECT_MATRIX;
  }
  return flag;
}
