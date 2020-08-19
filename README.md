# General Coding Best Practices

## Structured Programming
[**Structured Programming**][1] - is a programming paradigm, designed towards improving program code through usage of control structures, such as sequential execution of statements or subroutines, conditional statements, iterations (loops), blocks, subroutines, and recursion. The term was coined by [Edgar W. Dijkstra][4].
### Control Structures
#### Sequence
*Ordered execution of statements or subroutines*. In the modern day programming this principle is rarely violated. Its origins lay in languages such as [Fortran][6] and [C][5], where usage of [`goto` statement][2] (replica of [`JUMP` statement][3] from assembly languages) had caused controversy in programming world because of its nature.

`goto` statement:

> performs a one-way transfer of control to another line of code,
 
which makes code more confusing and may become the cause of [various bugs][7].

JavaScript has similar structure called [*labeled statements*][8]. Similarly to `goto`, it is recommended to avoid using it, as it makes code harder to understand and maintain.

Here is an example of **C** code that uses `goto` to calculate factorial of a number:

```c
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
```

And here is how this function can be rewritten without `goto`, using `for` loop:

```c
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
```

And here is how this function can be rewritten using [recursion][9]:

```c
int recursive_factorial(const int n)
{
	if (n < 0)
		return -1;

	if (n == 0 || n == 1)
		return 1;

	return n * recursive_factorial(n - 1);
}
```

#### Conditions

One or more statements executed based on the state of the program Implies usage of conditional statements such as:

```c
if (condition_a) {
	...
} else if (condition_b) {
	...
} else {
	...
}
```

Conditional statements are essential tools in creating programs. They serve much like road forks, and allow us to create software that can adapt to various scenarios.

Most of the programming languages have similar keywords for conditional statements - `if, else (elif in python), else`.

[Logical operators][10] such as *or* (**||**), *and* (**&&**), *not* (**!**) are used for creating conditions.

Sometimes we overcomplicate conditions. Here is an example in [**Java** language][12], taken from [Wellesley College's CS course][11]:

```java
public boolean hasWallsOnBothSides() {
  if (isWallToLeft()) {
    if (isWallToRight()) {
      return true;
    } else {
      return false;
    }
  } else {
      return false;
  }
}
```

This can simplified to this:

```java
public boolean hasWallsOnBothSides() {
  if (isWallToLeft()) {
    return isWallToRight();
  } else {
    return false;
  }
}
```

And simplified further:

```java
public boolean hasWallsOnBothSides() {
  return isWallToLeft() && isWallToRight();
}
```

#### Iterations

Single statement or code block executed until certain condition is reached. Expressed using keywords `for, while, do...while, forEach` and etc.

Examples in **C** language:

```c
int arr = [-3, 0, 12, 5];

for (int i = 0; i < 4; i++) {
	printf("%d: %d\n", i, arr[i]);
}
```

```c
int i = 0;

while (i++ < 10) {
	printf("%d\n", i * i);
}
```

```c
int i = 0;

do {
	int j = i * i;
	printf("%d\n", j);
} while (i++ < 15);
```

### Blocks

> Blocks are used to enable groups of statements to be treated as if they were one statement. Block-structured languages have a syntax for enclosing structures in some formal way, such as an if-statement bracketed by if..fi as in ALGOL 68, or a code section bracketed by BEGIN..END, as in PL/I and Pascal, whitespace indentation as in Python - or the curly braces {...} of C and many later languages.
> -- [Wikipedia, Structured Programming][1]

Example in JavaScript:

```typescript
let number = 0;

{
	let number = 1;
	console.log(`Number is ${number}`); // > Number is 1
}

console.log(`Number is ${number}`); // > Number is 0
```
### Subroutines (procedures, functions)

When same code needs to be executed in several places subroutines are a tool for that.

```typescript
const sayMyName = (name: string): => {
	console.log(`Your name is ${name}!`);
};

sayMyName(); // Your name is John
sayMyName('Jakub'); // Your name is Jakub
```

#### Function

Similar to mathematical function - accepts arguments and returns a result, just like an example before.

There is a special type of functions, that are called *pure* functions. This term comes from the [Functional Programming][13]. These functions do not mutate their input arguments, they do not depend on the state of the program and they always produce the same result for the same input. For example:

```typescript
const add = (a: number, b: number) => a + b;
```

Return value of this function depends only on its input arguments. It does not mutate any values and does not depend on the state of the program. This function always accepts 2 number arguments, and it always returns their sum. So this function is pure. Here is an example of an impure function:

```typescript
const addImpure = (a: number, b: number) => {
	a = a + b;
	return a;
};
```

Essentially, this function does the same thing as the previous one, but unlike the first function, this one mutates its first argument by adding the second argument to it. This may potentially lead to unexpected bugs, because this function changes value of the first argument, which may be later referenced in some other part of the program.

### Recursion

Recursion, in programming, is when function or procedure calls itself. For example, our factorial function:

```c
int recursive_factorial(const int n)
{
	if (n < 0)
		return -1;

	if (n == 0 || n == 1)
		return 1;

	return n * recursive_factorial(n - 1);
}
```

#### Recursion and Stack

Each function or procedure call creates a stack entry, so each recursion creates stack entry as well. For example, if we would call our `recursiove_factorial` function with `4` as an argument, stack call would look like this:

```
recursive_factorial(4)
	|- recursive_factorial(3)
		|- recursive_factorial(2)
			|- recursive_factorial(1)

```

In contrast, call of the `iterative_factorial` function with the same argument would produce single stack entry:

```
iterative_factorial(4)
```
## Clean Code
### DRY (Don’t Repeat Yourself)
### Code Smells
### Consistency
### YAGNI (You ain’t gonna need it!)
### Refactoring
## Functional Programming
### Avoid Side Effects
#### Pure Functions

[1]: https://en.wikipedia.org/wiki/Structured_programming
[2]: https://en.wikipedia.org/wiki/Goto
[3]: http://www.philadelphia.edu.jo/academics/qhamarsheh/uploads/Lecture%2018%20Conditional%20Jumps%20Instructions.pdf
[4]: https://en.wikipedia.org/wiki/Edsger_W._Dijkstra
[5]: https://en.wikipedia.org/wiki/C_(programming_language)
[6]: https://en.wikipedia.org/wiki/Fortran
[7]: https://nakedsecurity.sophos.com/2014/02/24/anatomy-of-a-goto-fail-apples-ssl-bug-explained-plus-an-unofficial-patch/
[8]: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/label
[9]: https://en.wikipedia.org/wiki/Recursion_(computer_science)
[10]: https://en.wikipedia.org/wiki/Boolean_algebra
[11]: http://cs111.wellesley.edu/~cs111/archive/cs111_spring00/public_html/lectures/boolean-simplification.html
[12]: https://en.wikipedia.org/wiki/Java_(programming_language)
[13]: https://en.wikipedia.org/wiki/Functional_programming