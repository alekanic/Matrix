#include "s21_matrix.h"

/**
 * Функция создает обратную матрицу для матрицы А и
 * записывает ее в переменную result
 * Возвращаемые значения:
 * 0 - OK
 * 1 - INCORRECT_MATRIX
 * 2 - CALCULATION_ERROR
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  // проверки
  if (check_matrix(A) == FAILURE || result == NULL) {
    return INCORRECT_MATRIX;
  }
  if (is_matrix_square(A) == FAILURE) {
    return CALCULATION_ERROR;
  }

  int flag = OK;
  double determinant = 0;
  int res_det = s21_determinant(A, &determinant);

  // если что-то пошло не так с детерминантом
  if (res_det != OK) {
    return res_det;
  }

  // если детерминант не нулевой
  if (determinant) {
    matrix_t complements = {NULL, 0, 0}, transpose = {NULL, 0, 0};

    s21_calc_complements(A, &complements);
    s21_transpose(&complements, &transpose);

    double determinant_value = 1 / determinant;
    s21_mult_number(&transpose, determinant_value, result);

    s21_remove_matrix(&complements);
    s21_remove_matrix(&transpose);
  } else {
    flag = CALCULATION_ERROR;
  }
  return flag;
}
