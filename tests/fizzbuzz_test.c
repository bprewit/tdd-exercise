/* vim: set ts=4 sw=4; */
#include <stdlib.h>
#include <check.h>
#include "../src/fizzbuzz.h"

START_TEST(test_fizzbuzz_returns_number)
{
	char *result;
	result = calloc((strlen("fizzbuzz") + 1), sizeof(char));
	fizzbuzz(result, 1);
	ck_assert_str_eq(result, "1");
	free(*result);
}
END_TEST

START_TEST(test_fizzbuzz_returns_two)
{
	char *result;
	result = calloc((strlen("fizzbuzz") + 1), sizeof(char));
	fizzbuzz(result, 2);
	ck_assert_str_eq(result, "2");
	free(*result);
}
END_TEST

Suite *fizzbuzz_suite(void)
{
	Suite *s;

	s = suite_create("FizzBuzz");

	TCase *tc_001 = tcase_create("FizzBuzz returns number");
	tcase_add_test(tc_001, test_fizzbuzz_returns_number);
	suite_add_tcase(s, tc_001);

	TCase *tc_002 = tcase_create("FizzBuzz returns two");
	tcase_add_test(tc_002, test_fizzbuzz_returns_two);
	suite_add_tcase(s, tc_002);

	return(s);
}

int main (void)
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = fizzbuzz_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
