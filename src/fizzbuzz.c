#include <fizzbuzz.h>

void fizzbuzz(char *dst, int n)
{
	if((n % 15) == 0)
	{
		sprintf(dst, "fizzbuzz");
	}
	else if((n % 5) == 0)
	{
		sprintf(dst, "buzz");
	}
	else if((n % 3) == 0)
	{
		sprintf(dst, "fizz");
	}
	else
	{
		sprintf(dst, "%d", n);
	}
}
