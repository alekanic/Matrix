#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"

Suite *suite_create_matrix(void);
Suite *suite_sum_matrix(void);
Suite *suite_sub_matrix(void);
Suite *suite_equal_matrix(void);
Suite *suite_remove(void);
Suite *suite_mult_number(void);
Suite *suite_mult_matrix(void);
Suite *suite_transponse(void);
Suite *suite_determinant(void);
Suite *suite_calc_complements(void);
Suite *suite_inverse_matrix(void);

void run_all_tests(void);
void run_testcase(Suite *testcase);