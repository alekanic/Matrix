#include "s21_matrix.h"

/**
 * Возвращает SUCCESS (1), если матрицы прошли проверку
 * Возвращает FAILURE (0), если матрицы не прошли проверку
 */
int check_matrix(matrix_t *A) {
  int result = SUCCESS;
  if (A == NULL || A->matrix == NULL || A->columns <= 0 || A->rows <= 0) {
    result = FAILURE;
  }
  return result;
}

/**
 * Возвращает SUCCESS (1), если у матриц одинаковый размер
 * Возвращает FAILURE (0), если у матриц разный размер
 */
int compare_the_size_of_matrix(matrix_t *A, matrix_t *B) {
  int flag = FAILURE;
  // проверка, что такие матрицы существуют
  if (check_matrix(A) && check_matrix(B)) {
    // проверка на одинаковую размерность матриц
    if (A->columns == B->columns && A->rows == B->rows) {
      flag = SUCCESS;
    }
  }
  return flag;
}

/**
 * Функция заполняет матрицу minor значениями на основании исходной матрицы А,
 * игноруя значения из строки row и столбца column матрицы А
 */
void create_matrix_for_complements(matrix_t *A, int row, int column,
                                   matrix_t *minor) {
  for (int src_row = 0, det_rows = 0; src_row < A->rows; src_row++) {
    for (int src_col = 0, det_col = 0; src_col < A->columns; src_col++) {
      if (src_row != row && src_col != column) {
        minor->matrix[det_rows][det_col] = A->matrix[src_row][src_col];
        det_col++;

        if (det_col == minor->columns) {
          det_rows++;
          det_col = 0;
        }
      }
    }
  }
}

/**
 * Проверяет знак в таблице алгебраических дополнений
 * Если сумма номеров строки и столбца - нечетная, то элемент результирующей
 * матрицы умножается на -1
 */
void check_sign(matrix_t *A, matrix_t *result) {
  for (int row = 0; row < A->rows; row++) {
    for (int col = 0; col < A->columns; col++) {
      if ((row + col) % 2) {
        result->matrix[row][col] *= -1;
      }
    }
  }
}

/**
 * Определитель (детерминант) можно вычислить только для квадратной матрицы
 * Функция проверяет, является ли матрица квадратной
 * Возвращаемые значения:
 * SUCCESS (1) - в случае положительного результата
 * FAILURE (0) - в случае отрицательного результата
 */
int is_matrix_square(matrix_t *A) {
  int flag = FAILURE;
  if (check_matrix(A) == SUCCESS) {
    if (A->columns == A->rows) {
      flag = SUCCESS;
    }
  }
  return flag;
}

// ============================================
// For tests
// ============================================

/**
 * Заполняет уже созданную (и проверенную!) матрицу значениями, начиная со
 * start_value и далее увеличивая это значение на step
 */
void s21_initialize_matrix(matrix_t *A, double start_value, double step) {
  double value = start_value;
  for (int row = 0; row < A->rows; row++) {
    for (int column = 0; column < A->columns; column++) {
      A->matrix[row][column] = value;
      value += step;
    }
  }
}

/**
 * Заполняет уже созданную (и проверенную!) матрицу значениeм
 * из параметра value
 */
void s21_initialize_matrix_one_value(matrix_t *A, double value) {
  for (int row = 0; row < A->rows; row++) {
    for (int column = 0; column < A->columns; column++) {
      A->matrix[row][column] = value;
    }
  }
}

/**
 * Функция выводит в терминал все значения A->matrix
 */
// void print_matrix(matrix_t *A) {
//   for (int row = 0; row < A->rows; row++) {
//     for (int column = 0; column < A->columns; column++) {
//       printf("%f", A->matrix[row][column]);
//       printf(" ");
//     }
//     printf("\n");
//   }
// }