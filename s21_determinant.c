#include "s21_matrix.h"

/**
 * Функция высчитывает определитель (детерминант) матрицы А
 * и записывает результат в переменную result
 * Возвращаемые значения:
 * 0 - OK
 * 1 - INCORRECT_MATRIX
 * 2 - CALCULATION_ERROR
 */
int s21_determinant(matrix_t *A, double *result) {
  // проверки
  if (check_matrix(A) == FAILURE) {
    return INCORRECT_MATRIX;
  } else if (is_matrix_square(A) == FAILURE) {
    return CALCULATION_ERROR;
  }
  // основная часть
  if (A->columns == 1) {
    *result = A->matrix[0][0];
  } else if (A->columns == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
  } else {
    calc_determinant(A, result);
  }
  return OK;
}

/**
 * Высчитывает определитель (детерминант) в матрице
 * Записывает детерминант в переменную result
 */
void calc_determinant(matrix_t *A, double *result) {
  // внешний цикл - для каждого столбца матрицы А создается подматрица,
  // которая будет использоваться для вычисления определителя
  for (int src_col = 0; src_col < A->columns; src_col++) {
    // создаем подматрицу
    matrix_t minor_matrix = {NULL, 0, 0};
    int check = s21_create_matrix(A->rows - 1, A->columns - 1, &minor_matrix);
    // перекидываем туда значения
    // проходимся по всем строкам матрицы, и заполняем их значениями из А,
    // игнорируя элемент в текущем столбце [src_col] (см. первый цикл)
    for (int row_det = 0, src_row = 0; row_det < A->rows - 1;
         row_det++, src_row++) {
      int col_det = 0;
      // повторно прогоняемся по столбцам A-матрицы
      for (int col = 0; col < A->columns; col++) {
        if (col != src_col) {
          minor_matrix.matrix[row_det][col_det] = A->matrix[src_row + 1][col];
          // если это не игнорируемый столбец в данной итерации - мы присваиваем
          // значение если нет - то мы присваиваем на это место следующее
          // значение из A-matrix
          col_det++;
        }
      }
    }
    // ищем детерминант
    double determinant = 0;
    s21_determinant(&minor_matrix, &determinant);
    *result += pow(-1, src_col) * A->matrix[0][src_col] * determinant;
    s21_remove_matrix(&minor_matrix);
  }
}
