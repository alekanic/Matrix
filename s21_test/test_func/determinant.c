#include "../s21_test.h"

START_TEST(determinant_1) {
  matrix_t A = {NULL, 0, 0};
  double result = 0;
  double my_res = 13;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 6;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 8;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 9;
  A.matrix[2][1] = 10;
  A.matrix[2][2] = 0;
  ck_assert_int_eq(OK, s21_determinant(&A, &result));
  ck_assert_int_eq(my_res, result);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_2) {
  matrix_t A = {NULL, 0, 0};
  double result = 0;
  double my_res = 0;
  s21_create_matrix(3, 3, &A);
  s21_initialize_matrix_one_value(&A, 5);
  ck_assert_int_eq(OK, s21_determinant(&A, &result));
  ck_assert_int_eq(my_res, result);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_3) {
  matrix_t A = {NULL, 0, 0};
  double result = 0;
  s21_create_matrix(3, 5, &A);
  ck_assert_int_eq(2, s21_determinant(&A, &result));
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_4) {
  // некорректная матрица
  matrix_t A = {NULL, 0, 0};
  double result = 0;
  ck_assert_int_eq(INCORRECT_MATRIX, s21_determinant(&A, &result));
}
END_TEST

START_TEST(determinant_5) {
  //
  matrix_t A = {NULL, 0, 0};
  double result = 0;
  double my_res = -2;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  ck_assert_int_eq(OK, s21_determinant(&A, &result));
  ck_assert_int_eq(my_res, result);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_6) {
  // failure with INCORRECT_MATRIX
  matrix_t A = {NULL, 0, 0};
  double det = 0;
  ck_assert_int_eq(s21_determinant(&A, &det), INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_7) {
  // failure with non-square matrix
  matrix_t A = {NULL, 0, 0};
  double det = 0;
  s21_create_matrix(3, 2, &A);
  s21_initialize_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_determinant(&A, &det), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_8) {
  // success with task reference values
  matrix_t A = {NULL, 0, 0};
  double det = 0;
  s21_create_matrix(3, 3, &A);
  s21_initialize_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_9) {
  // success with 2x2 matrix
  matrix_t A = {NULL, 0, 0};
  double det = 0;
  s21_create_matrix(2, 2, &A);
  s21_initialize_matrix(&A, 3, 3);
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, -18);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_10) {
  // success with 1x1 matrix
  matrix_t A = {NULL, 0, 0};
  double det = 0;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 21;
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, 21);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_determinant(void) {
  Suite *s1 = suite_create("DETERMINANT");
  TCase *tc1_1 = tcase_create("base");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, determinant_1);
  tcase_add_test(tc1_1, determinant_2);
  tcase_add_test(tc1_1, determinant_3);
  tcase_add_test(tc1_1, determinant_4);
  tcase_add_test(tc1_1, determinant_5);
  tcase_add_test(tc1_1, determinant_6);
  tcase_add_test(tc1_1, determinant_7);
  tcase_add_test(tc1_1, determinant_8);
  tcase_add_test(tc1_1, determinant_9);
  tcase_add_test(tc1_1, determinant_10);

  return s1;
}
