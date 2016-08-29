#include <fizzbuzz.h>

void fizzbuzz(char *dst, int n)
{
	if((n % 5) == 0)
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
