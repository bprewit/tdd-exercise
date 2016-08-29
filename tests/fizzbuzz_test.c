/* vim: set ts=4 sw=4; */
#include <stdlib.h>
#include <check.h>
#include "../src/fizzbuzz.h"

char *result;

void setup(void)
{
	result = calloc((strlen("fizzbuzz") + 1), sizeof(char));
}

void teardown(void)
{
	free(result);
}

START_TEST(fizzbuzz_returns_number)
{
	result = calloc((strlen("fizzbuzz") + 1), sizeof(char));
	fizzbuzz(result, 1);
	ck_assert_str_eq(result, "1");
}
END_TEST

START_TEST(fizzbuzz_returns_two)
{
	fizzbuzz(result, 2);
	ck_assert_str_eq(result, "2");
}
END_TEST

START_TEST(fizzbuzz_returns_fizz)
{
	fizzbuzz(result, 3);
	ck_assert_str_eq(result, "fizz");
	fizzbuzz(result, 6);
	ck_assert_str_eq(result, "fizz");
}
END_TEST

Suite *fizzbuzz_suite(void)
{
	Suite *s;

	s = suite_create("FizzBuzz");

	TCase *tc_core = tcase_create("FizzBuzz Core");
	tcase_add_unchecked_fixture(tc_core, setup, teardown);

	tcase_add_test(tc_core, fizzbuzz_returns_number);
	tcase_add_test(tc_core, fizzbuzz_returns_two);
	tcase_add_test(tc_core, fizzbuzz_returns_fizz);

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

	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
