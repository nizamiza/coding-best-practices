# General Coding Best Practices

- [General Coding Best Practices](#general-coding-best-practices)
	- [Structured Programming](#structured-programming)
		- [Control Structures](#control-structures)
			- [Sequence](#sequence)
			- [Conditions](#conditions)
			- [Iterations](#iterations)
		- [Blocks](#blocks)
		- [Subroutines (procedures, functions)](#subroutines-procedures-functions)
			- [Function](#function)
		- [Recursion](#recursion)
			- [Recursion and Stack](#recursion-and-stack)
	- [Clean Code](#clean-code)
		- [DRY (Don’t Repeat Yourself)](#dry-dont-repeat-yourself)
		- [Code Smells](#code-smells)
		- [Consistency](#consistency)
		- [YAGNI (You ain’t gonna need it!)](#yagni-you-aint-gonna-need-it)
		- [Refactoring](#refactoring)
	- [Functional Programming](#functional-programming)
		- [Avoid Side Effects](#avoid-side-effects)
			- [Pure Functions](#pure-functions)
	- [References](#references)


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

One or more statements executed based on the state of the program. Implies usage of conditional statements such as:

```typescript
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

Sometimes we over-complicate conditions. Here is an example, originally written in [**Java** language][12], but converted to JavaScript for the purposes of this document, that is taken from [Wellesley College's CS course][11]:

```typescript
const hasWallsOnBothSides = () => {
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

```typescript
const hasWallsOnBothSides = () => {
  if (isWallToLeft()) {
    return isWallToRight();
  } else {
    return false;
  }
}
```

And simplified further:

```typescript
const hasWallsOnBothSides = () => {
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

There is a special type of functions, that are called *pure* functions. This term comes from the [Functional Programming][13]. These functions do not mutate their input arguments, they do not depend on the state of the program, and they always produce the same result for the same input. For example:

```typescript
const sayHello = (person: string) => `Hello, ${person}!`;

const addSayHelloToObject = (object: object) => ({
    ...object,
    sayHello,
});

const myObject = { name: 'Ozimandius' };

console.log(addSayHelloToObject(myObject)); // { name: 'Ozimandius', sayHello }
console.log(myObject); // { name: 'Ozimandius' }
```

> If you are not familiar with JavaScript or its [*destructuring assignment*][19] feature, here is the simple explanation of what is going on. `addSayHelloToObject` accepts one parameter - `object`, and it returns a new object (curly braces mean that this is a new instance of an object) that is composed of all properties of the input object + the `sayHello` method that is added to it.

From the console logs, we can see that original object is not mutated after the function call. Return value of this function depends only on its input argument. This function always accepts single object parameter, and it always returns a new object with the `sayHello` method attached to it. So this function is pure. Here is an example of an impure `addSayHelloToObject` function:

```typescript
const sayHello = (person: string) => `Hello, ${person}!`;

const addSayHelloToObject = (object: object) => {
	object.sayHello = sayHello;
};

const myObject = { name: 'Ozimandius' };

console.log(addSayHelloToObject(myObject)); // *no output*
console.log(myObject); // { name: 'Ozimandius', sayHello }
```

Essentially, this function does the same thing as the previous one, but unlike the first function, this one mutates its argument by directly attaching `sayHello` method to it. This may potentially lead to unexpected bugs.

### Recursion

Recursion, in programming, is when function or procedure calls itself. For example, our factorial function (now in javascript):

```typescript
const recursiveFactorial = (number = 1) => {
	if (number < 0)
		return -1;

	if (number === 1 || number === 0)
		return number;
    
	return number * recursiveFactorial(number - 1);
};
```

#### Recursion and Stack

Each function or procedure call creates a stack entry, so each recursion creates stack entry as well. For example, if we would call our `recursiveFactorial` function with `4` as an argument, stack call would look like this:

```typescript
=> recursiveFactorial, number = 4
	=> recursiveFactorial, number = 3
		=> recursiveFactorial, number = 2
			=> recursiveFactorial, number = 1

```

In contrast, call of the `iterative_factorial` function with the same argument would produce single stack entry:

```typescript
=> iterativeFactorial, number = 4
```
## [Clean Code][15]

> Non-redundant software code comprising of focussed task-specific modules and functions, written in a systematic manner so that another coder can easily interpret or modify it.

### DRY (Don’t Repeat Yourself)

If you catch yourself writing same code, or slightly different one, more than once, then that code needs to become a subroutine:

```typescript
let value = 0;

for (let i = 0; i < maxLimit; i++)
	value *= i * 5;

for (let i = 5; i < maxLimit - 1; i++)
	value *= i * 5;
```

This can be refactored to this:

```typescript
const calcValue = (value: number, index: number) => value * (index * 5);

let value = 0;

for (let i = 0; i < maxLimit; i++)
	value = calcValue(value, i)

for (let i = 5; i < maxLimit - 1; i++)
	value = calcValue(value, i)
```

### Code Smells

When you design any type of software, there is certain set of rules and idioms to follow based on your environment and language that you use. Throughout decades of software development, architecture and design patterns have evolved. They are meant to solve specific set of problems in the most efficient way.

Sometimes, you are not aware of these rules, patterns, and idioms. You start to do it in your own way, which doesn't mean that it is bad. Your own way of doing things may, in fact, follow those rules, patterns, and idioms. But most of the time, your code starts to *smell*. Of course, digital text does not emit any kind of physical smell, but you start to have a feeling that something is wrong.

And if you catch yourself having that feeling, than it is probably time tod study that problem more thoroughly and to look for a better solution.

### Consistency

Consistency, both in code style and in general approach of solving problems.

Nothing is more frustrating that to work with someone on your team who is not consistent in his programming. Bad indentation, alien naming convention for variables, and design patterns all over the place. This type of teammate produces unmaintainable codebase, which nor he, nor you understand.

If you had a bad codebase, then it needs refactoring before you start building a *good* codebase on top of it.

### YAGNI (You ain’t gonna need it!)

> I will create this utility class in case we need it...

**YAGNI** - You ain't gonna need it!

Stop building dead libraries out of your projects. Implement solutions only when you need them. Keep things simple when designing those solutions. Don't over-engineer your code to accommodate for every single scenario, consider only real world use cases, and keep line count to minimum. Goal is not to ship code, but to ship a product.

### Refactoring

After many hours, days, and months of development, your project may start to look like a mess:
  
- inconsistent code style
- duplicate code
- bad variable and function names
- *it smells so badly...*

If that is the case, then it is time for the refactoring!

Refactoring - is a process of improving existing code without change to its behavior.

During refactoring, you solve previously mentioned problems without changing how your program works. Refactoring is not for the clients, but for the developers. Although it may improve performance of your program, that is not its goal.

Simplest refactoring is renaming variables and functions to make clear what they are meant for. Example:

```typescript
const calc = (a: number, b: number, c: number) => {
	return a + b - c;
}
```

Versus:

```typescript
const calcSalary = (netIncome: number, bonusIncomes: number, taxes: number) {
	return netIncome + bonusIncomes - taxes;
}
```

Removing duplicate code by extracting it to subroutines (procedures and functions) is another form of refactoring.

Inconsistent code style includes bad variable and function naming, but it also refers to code indentation, column caps, file structure, and codebase structure.

## Functional Programming

[**Functional programming**][13] - is programming paradigm, that is developed around concepts of [pure functions][17] and [data immutability][18]. Although it is not widely used in the modern software development, it is highly valuable as a practice that helps to in building robust systems.

### Avoid Side Effects

One of the key elements of the functional programming is avoiding side effects. This is achieved through the usage pure functions and immutable data. It is worth noting that in the functional world, data is separated from the logic of the program, where in object oriented world, data is often mixed with the logic.

#### Pure Functions

Return value of a pure function depends only on its input arguments, and it always produces the same result for the same set of inputs. Pure functions minimize side affects produced by the program. General best practice is to use pure functions as much as possible. On top of that, because of their consistent nature, pure functions are easy to test with unit tests. 

## References

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
[14]: https://en.wikipedia.org/wiki/Robert_C._Martin
[15]: https://en.wiktionary.org/wiki/clean_code
[16]: https://en.wikipedia.org/wiki/Code_refactoring
[17]: https://en.wikipedia.org/wiki/Pure_function
[18]: https://en.wikipedia.org/wiki/Immutable_object
[19]: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Destructuring_assignment

* [Structured Programming, Wikipedia][1]
* [Goto, Wikipedia][2]
* [Conditional Jumps Instructions, Philadelphia University][3]
* [Edsger W. Dijkstra, Wikipedia][4]
* [C (programming language), Wikipedia][5]
* [Fortran, Wikipedia][6]
* [Anatomy of a goto fail, nakedsecurity.sophos.com][7]
* [JavaScript - Labeled Statements, Mozilla Developers Network][8]
* [Recursion (computer science), Wikipedia][9]
* [Boolean Algebra, Wikipedia][10]
* [Boolean Simplification, Wllesley Collage][11]
* [Java (programming language), Wikipedia][12]
* [Functional Programming, Wikipedia][13]
* [Robert C. Martin, Wikipedia][14]
* [Clean Code, Wiktionary][15]
* [Code Refactoring, Wikipedia][16]
* [Pure Function, Wikipedia][17]
* [Immutable Object, Wikipedia][18]
* [Destructuring Assignment, Mozilla Developers Network][19]