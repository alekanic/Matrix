#include "../s21_test.h"

START_TEST(eq_1) {
  // success with initialized values
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_initialize_matrix(&A, 21, 21);
  s21_initialize_matrix(&B, 21, 21);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_2) {
  // success with uninitialized values
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_3) {
  // success with a difference of less than 1e-7
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_initialize_matrix(&A, 1, 0.000000001);
  s21_initialize_matrix(&B, 1, 0.000000002);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_4) {
  // failure with different dimensions of matrices
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(3, 4, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_5) {
  // failure with INCORRECT_MATRIX
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(5, 5, &A);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(eq_6) {
  // failure with different values
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_initialize_matrix(&A, 21, 1);
  s21_initialize_matrix(&B, 42, 1);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *suite_equal_matrix(void) {
  Suite *s1 = suite_create("EQUAL_MATRIX");
  TCase *tc1_1 = tcase_create("base");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, eq_1);
  tcase_add_test(tc1_1, eq_2);
  tcase_add_test(tc1_1, eq_3);
  tcase_add_test(tc1_1, eq_4);
  tcase_add_test(tc1_1, eq_5);
  tcase_add_test(tc1_1, eq_6);

  return s1;
}
