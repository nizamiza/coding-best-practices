#include <stdio.h>
#include <assert.h>

int factorial_with_goto(const int n)
{
	if (n < 0)
		return -1;
	
	if (n == 0 || n == 1)
		return 1;
	
	int result = n;
	int current = n;

loop:
	result *= --current;

	if (current == 1)
		return result;

	goto loop;
}

int iterative_factorial(const int n)
{
	if (n < 0)
		return -1;

	if (n == 0 || n == 1)
		return 1;

	int result = n;

	for (int i = n - 1; i > 1; i--)
		result *= i;
	
	return result;
}

int recursive_factorial(const int n)
{
	if (n < 0)
		return -1;

	if (n == 0 || n == 1)
		return 1;

	return n * recursive_factorial(n - 1);
}

void test_factorial_fn(int (*fn)(const int))
{
	printf("\n::: Testing factorial function... :::\n");
	
	assert(fn(0) == 1 && fn(1) == 1);
	assert(fn(-15) == -1);
	assert(fn(5) == 120);
	assert(fn(3) == 6);
	assert(fn(8) == 40320);
	assert(fn(10) == 3628800);

	printf("\n::: Tests ran successfully! :::\n");
}

int main(void)
{
	test_factorial_fn(factorial_with_goto);
	test_factorial_fn(iterative_factorial);
	test_factorial_fn(recursive_factorial);

	return 0;
}