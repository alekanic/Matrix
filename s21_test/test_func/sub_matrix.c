#include "../s21_test.h"

START_TEST(sub_1) {
  // failure error with wrong matrices
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(sub_2) {
  // failure with different dimensions of matrices
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(5, 5, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_3) {
  // sucess with initialized values
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t matrix_1 = {NULL, 0, 0};
  matrix_t matrix_2 = {NULL, 0, 0};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &matrix_2);
  s21_initialize_matrix(&A, 1, 1);
  s21_initialize_matrix(&B, 1, 1);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &matrix_1), OK);
  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(sub_4) {
  // sucess with uninitialized values
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t matrix_1 = {NULL, 0, 0};
  matrix_t matrix_2 = {NULL, 0, 0};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &matrix_2);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &matrix_1), OK);
  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(sub_5) {
  // sucess with task refence
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t matrix_1 = {NULL, 0, 0};
  matrix_t matrix_2 = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &matrix_2);

  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 5;
  A.matrix[2][0] = 0, A.matrix[2][1] = 0, A.matrix[2][2] = 6;

  B.matrix[0][0] = 1, B.matrix[0][1] = 0, B.matrix[0][2] = 0;
  B.matrix[1][0] = 2, B.matrix[1][1] = 0, B.matrix[1][2] = 0;
  B.matrix[2][0] = 3, B.matrix[2][1] = 4, B.matrix[2][2] = 1;

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &matrix_1), OK);

  matrix_2.matrix[0][0] = 0, matrix_2.matrix[0][1] = 2,
  matrix_2.matrix[0][2] = 3;

  matrix_2.matrix[1][0] = -2, matrix_2.matrix[1][1] = 4,
  matrix_2.matrix[1][2] = 5;

  matrix_2.matrix[2][0] = -3, matrix_2.matrix[2][1] = -4,
  matrix_2.matrix[2][2] = 5;

  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(sub_6) {
  // failure error with wrong matrice
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(sub_7) {
  // failure with different dimensions of matrices
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(10, 10, &A);
  s21_create_matrix(5, 10, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *suite_sub_matrix(void) {
  Suite *s1 = suite_create("SUB_MATRIX");
  TCase *tc1_1 = tcase_create("base");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, sub_1);
  tcase_add_test(tc1_1, sub_2);
  tcase_add_test(tc1_1, sub_3);
  tcase_add_test(tc1_1, sub_4);
  tcase_add_test(tc1_1, sub_5);
  tcase_add_test(tc1_1, sub_6);
  tcase_add_test(tc1_1, sub_7);

  return s1;
}
