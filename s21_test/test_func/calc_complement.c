#include "../s21_test.h"

START_TEST(complements_1) {
  // failure with INCORRECT_MATRIX
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_calc_complements(&A, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(complements_2) {
  // failure with vector matrix (rows or cols == 1)
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(1, 3, &A);
  s21_initialize_matrix(&A, 1, 3);
  ck_assert_int_eq(s21_calc_complements(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(complements_3) {
  // success with task reference values
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t eq_matrix = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &eq_matrix);
  s21_create_matrix(3, 3, &result);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 5, A.matrix[2][1] = 2, A.matrix[2][2] = 1;
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  eq_matrix.matrix[0][0] = 0, eq_matrix.matrix[0][1] = 10,
  eq_matrix.matrix[0][2] = -20;
  eq_matrix.matrix[1][0] = 4, eq_matrix.matrix[1][1] = -14,
  eq_matrix.matrix[1][2] = 8;
  eq_matrix.matrix[2][0] = -8, eq_matrix.matrix[2][1] = -2,
  eq_matrix.matrix[2][2] = 4;
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(complements_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &R);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  R.matrix[0][0] = 4;
  R.matrix[0][1] = -3;
  R.matrix[1][0] = -2;
  R.matrix[1][1] = 1;

  ck_assert_int_eq(0, s21_calc_complements(&A, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(complements_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &R);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  R.matrix[0][0] = 0;
  R.matrix[0][1] = 10;
  R.matrix[0][2] = -20;
  R.matrix[1][0] = 4;
  R.matrix[1][1] = -14;
  R.matrix[1][2] = 8;
  R.matrix[2][0] = -8;
  R.matrix[2][1] = -2;
  R.matrix[2][2] = 4;

  ck_assert_int_eq(0, s21_calc_complements(&A, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(complements_6) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &R);
  A.matrix[0][0] = 37.33;
  A.matrix[0][1] = -4;
  A.matrix[0][2] = -373.4;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3673.4;
  A.matrix[1][2] = -637.4;
  A.matrix[2][0] = 89.8;
  A.matrix[2][1] = -6737.5;
  A.matrix[2][2] = 0;

  R.matrix[0][0] = -4294482.5;
  R.matrix[0][1] = -57238.52;
  R.matrix[0][2] = -329871.32;
  R.matrix[1][0] = 2515782.5;
  R.matrix[1][1] = 33531.32;
  R.matrix[1][2] = 251151.675;
  R.matrix[2][0] = 1374197.16;
  R.matrix[2][1] = 23794.142;
  R.matrix[2][2] = 137128.022;

  ck_assert_int_eq(0, s21_calc_complements(&A, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(complements_7) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 5, &A);
  ck_assert_int_eq(2, s21_calc_complements(&A, &result));
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(complements_8) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_calc_complements(&A, &result));
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(complements_9) {
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(1, s21_calc_complements(NULL, &result));
}
END_TEST

START_TEST(complements_10) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &R);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  R.matrix[0][0] = -3;
  R.matrix[0][1] = 6;
  R.matrix[0][2] = -3;
  R.matrix[1][0] = 6;
  R.matrix[1][1] = -12;
  R.matrix[1][2] = 6;
  R.matrix[2][0] = -3;
  R.matrix[2][1] = 6;
  R.matrix[2][2] = -3;

  ck_assert_int_eq(0, s21_calc_complements(&A, &result));
  ck_assert_int_eq(1, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

Suite *suite_calc_complements(void) {
  Suite *s1 = suite_create("CALC_COMPLEMENTS");
  TCase *tc1_1 = tcase_create("base");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, complements_1);
  tcase_add_test(tc1_1, complements_2);
  tcase_add_test(tc1_1, complements_3);
  tcase_add_test(tc1_1, complements_4);
  tcase_add_test(tc1_1, complements_5);
  tcase_add_test(tc1_1, complements_6);
  tcase_add_test(tc1_1, complements_7);
  tcase_add_test(tc1_1, complements_8);
  tcase_add_test(tc1_1, complements_9);
  tcase_add_test(tc1_1, complements_10);

  return s1;
}
