#include <fizzbuzz.h>

void fizzbuzz(char *dst, int n)
{
	if((n % 3) == 0)
	{
		sprintf(dst, "fizz");
	}
	else
	{
		sprintf(dst, "%d", n);
	}
}
