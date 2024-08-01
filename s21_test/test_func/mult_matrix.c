#include "../s21_test.h"

START_TEST(mult_matrix_1) {
  // failure with INCORRECT_MATRIX
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_initialize_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_mult_matrix(&A, NULL, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_matrix_2) {
  // failure with different dimensions of matrices
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_3) {  // ПАДАЕТ на eq matrix
  // success with uninitialized values
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t matrix_1 = {};
  matrix_t matrix_2 = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &matrix_2);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &matrix_1), OK);
  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(mult_matrix_4) {
  // success with initialized values
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t matrix_1 = {NULL, 0, 0};
  matrix_t matrix_2 = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &matrix_2);
  s21_initialize_matrix(&B, 1, 1);
  s21_initialize_matrix(&A, 1, 1);

  matrix_2.matrix[0][0] = 30, matrix_2.matrix[0][1] = 36,
  matrix_2.matrix[0][2] = 42;

  matrix_2.matrix[1][0] = 66, matrix_2.matrix[1][1] = 81,
  matrix_2.matrix[1][2] = 96;

  matrix_2.matrix[2][0] = 102, matrix_2.matrix[2][1] = 126,
  matrix_2.matrix[2][2] = 150;

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &matrix_1), OK);
  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(mult_matrix_5) {
  // success with initialized values
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t matrix_1 = {NULL, 0, 0};
  matrix_t matrix_2 = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &matrix_2);
  s21_initialize_matrix(&B, 1, 1);
  s21_initialize_matrix_one_value(&A, 0);
  s21_initialize_matrix_one_value(&matrix_2, 0);

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &matrix_1), OK);
  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(mult_matrix_6) {
  // with change the sign
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t matrix_1 = {NULL, 0, 0};
  matrix_t matrix_2 = {NULL, 0, 0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 3, &matrix_2);
  s21_initialize_matrix_one_value(&B, 1);
  s21_initialize_matrix_one_value(&A, 1);
  s21_initialize_matrix_one_value(&matrix_2, 2);
  s21_mult_matrix(&A, &B, &matrix_1);

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &matrix_1), OK);
  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

Suite *suite_mult_matrix(void) {
  Suite *s1 = suite_create("MULT_MATRIX");
  TCase *tc1_1 = tcase_create("base");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, mult_matrix_1);
  tcase_add_test(tc1_1, mult_matrix_2);
  tcase_add_test(tc1_1, mult_matrix_3);
  tcase_add_test(tc1_1, mult_matrix_4);
  tcase_add_test(tc1_1, mult_matrix_5);
  tcase_add_test(tc1_1, mult_matrix_6);

  return s1;
}
