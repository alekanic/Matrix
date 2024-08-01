#include "s21_matrix.h"

/**
 * Очищает память, которая была выделена под матрицы
 * Вместо rows и columns устанавливаются 0
 * Вместо matrix - NULL
 */
void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);

    A->rows = 0;
    A->columns = 0;
    A->matrix = NULL;
  }
}