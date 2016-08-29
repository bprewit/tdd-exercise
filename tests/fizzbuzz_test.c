/* vim: set ts=4 sw=4; */
#include <stdlib.h>
#include <check.h>
#include "../src/fizzbuzz.h"

START_TEST(test_fizzbuzz_returns_number)
{
	char *result;
	result = calloc(strlen("fizzbuzz") + 1, sizeof(char));
	fizzbuzz(result, 1);
	ck_assert_str_eq(result, "1");
}
END_TEST


Suite *fizzbuzz_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("FizzBuzz");

	/* Core test case */
	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_fizzbuzz_returns_number);
	suite_add_tcase(s, tc_core);

	return(s);
}

int main (void)
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = fizzbuzz_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
