#include "../s21_test.h"

START_TEST(mult_number_1) {
  // failure with INCORRECT_MATRIX
  matrix_t A = {NULL, 0, 0};
  double number = 3.14;
  s21_initialize_matrix_one_value(&A, 1);
  ck_assert_int_eq(s21_mult_number(&A, number, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_number_2) {
  // success with uninitialized values
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};
  double number = 3;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_number_3) {
  // success with initialized values
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};
  double number = 3;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);
  s21_initialize_matrix_one_value(&A, 1);
  s21_initialize_matrix_one_value(&check, 3);
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
  s21_mult_number(&A, number, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_number_4) {
  // success with change the sign
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};
  double number = -5;
  s21_create_matrix(3, 4, &A);
  s21_create_matrix(3, 4, &check);
  s21_initialize_matrix_one_value(&check, -5);
  s21_initialize_matrix_one_value(&A, 1);
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_number_5) {
  // success with zero multiple
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};
  double number = 0;
  s21_create_matrix(3, 4, &A);
  s21_create_matrix(3, 4, &check);
  s21_initialize_matrix_one_value(&A, 5);
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

Suite *suite_mult_number(void) {
  Suite *s1 = suite_create("MULT_NUMBER");
  TCase *tc1_1 = tcase_create("base");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, mult_number_1);
  tcase_add_test(tc1_1, mult_number_2);
  tcase_add_test(tc1_1, mult_number_3);
  tcase_add_test(tc1_1, mult_number_4);
  tcase_add_test(tc1_1, mult_number_5);

  return s1;
}
