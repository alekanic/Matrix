#include "../s21_test.h"

START_TEST(create_1) {
  // success creation
  matrix_t A = {NULL, 0, 0};
  ck_assert_int_eq(s21_create_matrix(5, 5, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_2) {
  // failure null pointer ERROR
  ck_assert_int_eq(s21_create_matrix(5, 5, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_3) {
  // failure incorrect rows/columns
  matrix_t A = {NULL, 0, 0};
  ck_assert_int_eq(s21_create_matrix(5, -5, &A), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_4) {
  // failure incorrect rows/columns
  matrix_t A = {NULL, 0, 0};
  ck_assert_int_eq(s21_create_matrix(0, 1, &A), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_5) {
  // failure incorrect rows/columns
  matrix_t A = {NULL, 0, 0};
  ck_assert_int_eq(s21_create_matrix(1, 0, &A), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_6) {
  // succcess
  matrix_t A = {NULL, 0, 0};
  ck_assert_int_eq(s21_create_matrix(5, 5, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_7) {
  // succcess
  matrix_t A = {NULL, -5, -5};
  ck_assert_int_eq(s21_create_matrix(5, 5, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(create_8) {
  // succcess
  matrix_t A = {NULL, 0, 0};
  ck_assert_int_eq(s21_create_matrix(-5, 5, &A), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_create_matrix(void) {
  Suite *s1 = suite_create("CREATE_MATRIX");
  TCase *tc1_1 = tcase_create("base");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, create_1);
  tcase_add_test(tc1_1, create_2);
  tcase_add_test(tc1_1, create_3);
  tcase_add_test(tc1_1, create_4);
  tcase_add_test(tc1_1, create_5);
  tcase_add_test(tc1_1, create_6);
  tcase_add_test(tc1_1, create_7);
  tcase_add_test(tc1_1, create_8);

  return s1;
}
