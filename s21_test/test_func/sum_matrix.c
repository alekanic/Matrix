#include "../s21_test.h"

START_TEST(sum_1) {
  // failure error with wrong matrices
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), INCORRECT_MATRIX);
}
END_TEST

START_TEST(sum_2) {
  // failure with different dimensions of matrices
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(5, 5, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_3) {
  // success
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_initialize_matrix(&A, 1, 1);
  s21_initialize_matrix(&B, 1, 1);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_4) {
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
  s21_initialize_matrix(&matrix_2, 2, 2);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &matrix_1), OK);
  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(sum_5) {
  // sucess with uninitialized values
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t matrix_1 = {NULL, 0, 0};
  matrix_t matrix_2 = {NULL, 0, 0};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &matrix_2);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &matrix_1), OK);
  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(sum_6) {
  // failure error with wrong matrices
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(5, 5, &A);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(sum_7) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t matrix_1 = {NULL, 0, 0};
  matrix_t matrix_2;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &matrix_2);

  A.matrix[0][0] = 2.9;
  A.matrix[0][1] = 1.2;
  A.matrix[1][0] = -4.5;
  A.matrix[1][1] = 7.1;

  B.matrix[0][0] = 1.1;
  B.matrix[0][1] = 2.3;
  B.matrix[1][0] = 3.5;
  B.matrix[1][1] = -2.1;

  matrix_2.matrix[0][0] = 4.0;
  matrix_2.matrix[0][1] = 3.5;
  matrix_2.matrix[1][0] = -1.0;
  matrix_2.matrix[1][1] = 5.0;

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &matrix_1), OK);
  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(sum_8) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t matrix_1 = {NULL, 0, 0};
  matrix_t matrix_2;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &matrix_2);

  A.matrix[0][0] = -2;
  A.matrix[0][1] = -2;
  A.matrix[1][0] = -2;
  A.matrix[1][1] = -2;

  B.matrix[0][0] = 2;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 2;

  matrix_2.matrix[0][0] = 0;
  matrix_2.matrix[0][1] = 0;
  matrix_2.matrix[1][0] = 0;
  matrix_2.matrix[1][1] = 0;

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &matrix_1), OK);
  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

Suite *suite_sum_matrix(void) {
  Suite *s1 = suite_create("SUMM_MATRIX");
  TCase *tc1_1 = tcase_create("base");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, sum_1);
  tcase_add_test(tc1_1, sum_2);
  tcase_add_test(tc1_1, sum_3);
  tcase_add_test(tc1_1, sum_4);
  tcase_add_test(tc1_1, sum_5);
  tcase_add_test(tc1_1, sum_6);
  tcase_add_test(tc1_1, sum_7);
  tcase_add_test(tc1_1, sum_8);

  return s1;
}
