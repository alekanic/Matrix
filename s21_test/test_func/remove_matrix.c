#include "../s21_test.h"

START_TEST(remove_1) {
  // success remove
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(5, 5, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_int_eq(A.rows, 0);
}
END_TEST

START_TEST(remove_2) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(0, 0, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_int_eq(A.rows, 0);
}
END_TEST

START_TEST(remove_3) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(5, -5, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_int_eq(A.rows, 0);
}
END_TEST

START_TEST(remove_4) {
  matrix_t A = {NULL, 0, 0};
  s21_create_matrix(-5, 5, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_int_eq(A.rows, 0);
}
END_TEST

Suite *suite_remove(void) {
  Suite *s1 = suite_create("REMOVE_MATRIX");
  TCase *tc1_1 = tcase_create("base");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, remove_1);
  tcase_add_test(tc1_1, remove_2);
  tcase_add_test(tc1_1, remove_3);
  tcase_add_test(tc1_1, remove_4);
  return s1;
}
