#include "s21_matrix.h"

/**
 * Сравнивает размеры матриц A и B, если они идентичны -
 * выделяет необходимую память под матрицу result и суммирует матрицы
 * Возвращаемые значения:
 * 0 - OK
 * 1 - INCORRECT_MATRIX
 * 2 - СALCULATION_ERROR
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;
  if (!check_matrix(A) || !check_matrix(B)) {
    flag = INCORRECT_MATRIX;
  } else if (compare_the_size_of_matrix(A, B) == 0) {
    flag = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    s21_sum(A, B, result);
  }
  return flag;
}

/**
 * Функция складывает значения матриц А и В с одинаковыми координатами
 * и записывает значения в матрицу result на ту же позицию
 */
void s21_sum(matrix_t *A, matrix_t *B, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
}