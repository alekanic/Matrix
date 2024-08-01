#include "s21_matrix.h"

/**
 * Создает матрицу с заданными rows и columns
 * Возвращаемые значения:
 * 0 - ОК
 * 1 - INCORRECT_MATRIX
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int flag = OK;
  // проверка на входные значения
  if (result != NULL && rows > 0 && columns > 0) {
    result->columns = columns;
    result->rows = rows;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    for (int ptr = 0; ptr < rows; ptr++) {
      result->matrix[ptr] = (double *)calloc(columns, sizeof(double));
      // проверка на успешное выделение памяти
      if (result->matrix == NULL || result->matrix[ptr] == NULL) {
        flag = INCORRECT_MATRIX;
        free(result->matrix);  // ОЧИСТКА ПАМЯТИ, если были ошибки
      }
    }
  } else {
    flag = INCORRECT_MATRIX;
  }
  return flag;
}