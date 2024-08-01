#include "s21_test.h"

void run_testcase(Suite *testcase) {
  SRunner *sr = srunner_create(testcase);
  // srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}

void run_all_tests(void) {
  Suite *list_cases[] = {
      suite_create_matrix(),    suite_sum_matrix(),     suite_sub_matrix(),
      suite_equal_matrix(),     suite_remove(),         suite_mult_number(),
      suite_mult_matrix(),      suite_transponse(),     suite_determinant(),
      suite_calc_complements(), suite_inverse_matrix(), NULL};

  for (int i = 0; list_cases[i] != NULL; i++) {
    run_testcase(list_cases[i]);
  }
}

int main(void) {
  run_all_tests();
  return 0;
}
