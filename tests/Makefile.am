## Process this file with automake to produce Makefile.in

TESTS = fizzbuzz_test
check_PROGRAMS = fizzbuzz_test
fizzbuzz_test_SOURCES = fizzbuzz_test.c $(top_builddir)/src/fizzbuzz.h
fizzbuzz_test_CFLAGS = @CHECK_CFLAGS@
fizzbuzz_test_LDADD = $(top_builddir)/src/libfizzbuzz.la @CHECK_LIBS@
