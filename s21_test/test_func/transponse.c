#include "../s21_test.h"

START_TEST(transponse_1) {
  // success with uninicialize
  matrix_t A = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(4, 2, &A);
  s21_create_matrix(2, 4, &check);
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transponse_2) {
  // success with inicialize with one value
  matrix_t A = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(4, 2, &A);
  s21_create_matrix(2, 4, &check);
  s21_initialize_matrix_one_value(&A, 1);
  s21_initialize_matrix_one_value(&check, 1);
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transponse_3) {
  // success with inicialize with different values
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(4, 5, &A);
  s21_initialize_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_double_eq(result.matrix[2][2], A.matrix[2][2]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transponse_4) {
  // wrong matrix
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(4, 5, &A);
  A.rows = -1;
  ck_assert_int_eq(s21_transpose(&A, &result), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(transponse_5) {
  // success with negative values
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(4, 5, &A);
  s21_initialize_matrix(&A, -1, -1);
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_double_eq(result.matrix[2][2], A.matrix[2][2]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transponse_6) {
  // success with one/one matrix
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(1, 1, &A);
  s21_initialize_matrix(&A, -1, -1);
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_double_eq(result.matrix[0][0], A.matrix[0][0]);
  ck_assert_int_eq(s21_eq_matrix(&A, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *suite_transponse(void) {
  Suite *s1 = suite_create("TRANSPONSE_MATRIX");
  TCase *tc1_1 = tcase_create("base");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, transponse_1);
  tcase_add_test(tc1_1, transponse_2);
  tcase_add_test(tc1_1, transponse_3);
  tcase_add_test(tc1_1, transponse_4);
  tcase_add_test(tc1_1, transponse_5);
  tcase_add_test(tc1_1, transponse_6);

  return s1;
}
