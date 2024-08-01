#define SUCCESS 1
#define FAILURE 0

#include "s21_matrix.h"

/**
 * Сравнивает значения 2-х матриц
 * Возвращаемые значения:
 * 1 - SUCCESS
 * 0 - FAILURE
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;

  if (check_matrix(A) == FAILURE || check_matrix(B) == FAILURE ||
      A->matrix == NULL || B->matrix == NULL) {
    flag = FAILURE;
  } else if (compare_the_size_of_matrix(A, B) == FAILURE) {
    flag = FAILURE;
  } else {
    for (int row = 0; row < A->rows; row++) {
      for (int column = 0; column < A->columns; column++) {
        if (fabs(A->matrix[row][column] - B->matrix[row][column]) >=
            1e-7) {  // 0.0000001
          flag = FAILURE;
          break;
        }
      }
    }
  }
  return flag;
}
