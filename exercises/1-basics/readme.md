## Basics
### 1. Simplest C Program

#### The simplest C program is essentially:
```c
int main() {
    return 0;
}
```

But a lot is happening here...

* A function named main is always the entry point to a C program (unlike Python, which enters at the top of the file).
* int is the return type of the function and is short for "integer". Because this is the main function, the return value is the exit code of the program. 0 means success, anything else means failure.
    * You'll find a lot of abbreviations in C because 1) programmers are lazy, and 2) it used to matter how many bytes your source code was.
* The opening bracket, { is the start of the function's body (C ignores whitespace, so indentation is just for style, not for syntax)
* return 0 returns the 0 value (an integer) from the function. Again, this is the exit code because it's the main function.
    * 0 represents "nothing bad happened" as a return value.
* The pesky ; at the end of return 0; is required in C to terminate statements.
* The closing bracket, } denotes the end of the function's body.

#### Print

It feels very different coming from Python, but printing in C is done with a function called printf from the stdio.h (standard input/output) library with a lot of weird formatting rules. To use it, you need an #include at the top of your file:

#include <stdio.h>

Then you can use printf from inside a function:

printf("Hello, world!\n");

Notice the \n: it's required to print a newline character (and flush the buffer in the terminal).

In case you're wondering, the f in printf stands for "print formatted".

#### Compiling and Running

C is a compiled language. You write source code (`.c` files) and turn it into an executable.

```bash
gcc -o hello hello.c          # Basic compile
./hello                       # Run on Linux/macOS
# or
clang -o hello hello.c
# Run on Linux/macOS
./hello
```

#### Usefull compiler flags

* -Wall: enables all compiler's warning messages
* -Werror: makes all warnings into errors
* -Wextra: enables extra warning flags that are not enabled by -Wall
* -pedantic: issues all the warnings demanded by strict ISO C and ISO C++; rejects all programs that use forbidden extensions
* -g: generates debug information to be used by GDB debugger

#### Assignment

Write a small C program that prints:

Program in C!

### 2. Data Types
#### C has a lot of data types, but the most common ones are:
* int: a whole number (e.g. 42)
* float: a decimal number (e.g. 3.14)
* char: a single character (e.g. 'a')
* char*: a string (e.g. "Hello, world!")
* size_t: an unsigned integer type that is used to represent the size of an object in memory. It is defined in the stddef.h header file and is typically used for array indexing and loop counters.
* bool: a boolean value (true or false) provided by stdbool.h

C is a statically typed language, which means you need to declare the type of a variable before you can use it. For example:
```c
int x = 42;
float y = 3.14;
char c = 'a';
char* s = "Hello, world!";
```

#### Keywords for data types

There are a few keywords that can be used to modify the behavior of data types:
* signed: allows negative values (e.g. signed int)
* unsigned: only allows positive values (e.g. unsigned int)
* short: a smaller version of a data type (e.g. short int)
* long: a larger version of a data type (e.g. long int)
* static: a variable that retains its value between function calls (e.g. static int)
* static can also be used to limit the scope of a variable or function to the file it's defined in (e.g. static int my_function()).
* const: a variable that cannot be modified after it's initialized (e.g. const int)

Remark: Instead of using signed, unsigned, short, and long, you can use the stdint.h header file to get fixed-width integer types (e.g. int8_t, int16_t, int32_t, int64_t). This is useful when you need to ensure that your integers have a specific size (e.g. for binary file formats or network protocols).

#### Exercise
For this exercise, complete the provided C program by fixing the missing types.

### 3. Simple Strings
Most programming languages these days (even compiled ones) have a built-in string type of some sort. C... doesn't.

Instead, C strings are just arrays (like lists) of characters. We'll talk more about the specifics when we talk about arrays and pointers later, but for now know that this is how you get a "string" in C:

```c
char *msg_from_dax = "You still have 0 users";
```

Very (I repeat, very) loosely speaking, char * means string. Also note that it is required to use double quotes ". Single quotes (') make char, not char *.

#### Assignment
Fix the provided C program.

### 4. Printing Variables

You've already seen me do a printf() magic a few times. Unfortunately, in C it isn't as easy to do string interpolation. We have to tell C how we want particular values to be printed using "format specifiers".

Common format specifiers are:

* %d – digit (integer)
* %u – unsigned integer
* %X – hexadecimal (integer)
* %c – character
* %f – floating point number
* %s – string (char *)
* %p – pointer (memory address)

You can add extra formatting options to these specifiers:
* l - long (e.g. %ld for long int)
* h - short (e.g. %hd for short int)
* .N - N decimal places (e.g. %.2f for 2 decimal places)
* 0N - pad with zeros to N digits (e.g. %05d for 5 digits, padded with zeros)
* N - pad with spaces to N digits (e.g. %5d for 5 digits, padded with spaces)

```c
printf("Hello, %s. You're %d years old.\n", name, age);
fprintf(stdout, "Hello, %s. You're %d years old.\n", name, age); // This is the same as printf, but you can specify the output stream (stdout, stderr, or a file)
fprintf(stderr, "Error: %s\n", error_message);
```

#### Newline Character

The print() function in Python automatically adds a newline character (\n) at the end of the string. In C, we have to do this manually.
```c
printf("Hello, world!\n");
```
#### Assignment

In the space provided print:

* Default max threads: A
* Custom perms: B
* Constant pi value: C
* Sneklang title: D

Use format specifiers to replace A-D with the already provided variables.

### Comments

In C, there are two ways to write comments:
```c
// This is a single-line comment

/*
This is a multi-line comment
I can just keep adding lines
and it will still be a comment
*/
```

/* and */ are used to denote the beginning and end of a multi-line comment.

### Variables

Variables in C must be declared with a specific type before they can be used and cannot be redeclared in the same scope. For example, this is not allowed:
```c
int main() {
    int x = 5;
    float x = 3.14; // error
}
```
However, a variable's value can change:
```c
int main() {
    int x = 5;
    x = 10; // this is ok
    x = 15; // still ok
}
```
Redeclaring a variable with the same name in the same scope is not allowed, but you can shadow it in a different scope:
```c
int main() {
    int x = 5;
    {
        int x = 10; // this is ok, it's a different variable
        printf("%d\n", x); // prints 10
    }
    printf("%d\n", x); // prints 5
}
```

### Enums

In C you can define your own types using enums. An enum is a user-defined type that consists of a set of named integer constants. For example:
```c
enum Color {
    RED,
    GREEN,
    BLUE
};
```

This defines an enum type called Color with three possible values: RED, GREEN, and BLUE. By default, the first value (RED) is assigned the integer value 0, the second value (GREEN) is assigned the integer value 1, and the third value (BLUE) is assigned the integer value 2. You can also explicitly assign values to the enum constants if you want:
```c
enum Color {
    RED = 1,
    GREEN = 2,
    BLUE = 4
};
```

Be careful when choosing names for your enum constants, because they are in the same namespace as other variables and functions. It's common practice to use uppercase letters for enum constants to distinguish them from other identifiers.
Some programmers also prefix enum constants with the name of the enum type (e.g. COLOR_RED, COLOR_GREEN, COLOR_BLUE) to avoid naming conflicts.

### Type Sizes

In C, the "size" (in memory) of a type is not guaranteed to be the same on all systems. That's because the size of a type is dependent on the system's architecture. For example, on a 32-bit system, the size of an int is usually 4 bytes, while on a 64-bit system, the size of an int can sometimes be 8 bytes – of course, you never know until you run sizeof with the compiler you plan on using.

However, some types are always guaranteed to be the same. Here's a list of the basic C data types along with their typical sizes in bytes. Note that sizes can vary based on the platform (e.g., 32-bit vs. 64-bit systems):
Basic C Types and Sizes

* char
    * Size: 1 byte
    * Represents: Single character.
    * Notes: Always 1 byte, but can be signed or unsigned.
* float
    * Size: 4 bytes
    * Represents: Single-precision floating-point number.
* double
    * Size: 8 bytes
    * Represents: Double-precision floating-point number.

The actual sizes of these types can be determined using the sizeof operator in C for a specific platform, which we'll learn about next.

#### stdint
C also has a header called stdint.h that defines fixed-width integer types, such as int8_t, int16_t, int32_t, and int64_t. These are useful when you need to ensure that your integers have a specific size (e.g. for binary file formats or network protocols).

These types are defined as follows:
* int8_t: a signed 8-bit integer (range: -128 to 127)
* uint8_t: an unsigned 8-bit integer (range: 0 to 255)
* int16_t: a signed 16-bit integer (range: -32,768 to 32,767)
* uint16_t: an unsigned 16-bit integer (range: 0 to 65,535)
* int32_t: a signed 32-bit integer (range: -2,147,483,648 to 2,147,483,647)
* uint32_t: an unsigned 32-bit integer (range: 0 to 4,294,967,295)
* int64_t: a signed 64-bit integer (range: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807)
* uint64_t: an unsigned 64-bit integer (range: 0 to 18,446,744,073,709,551,615)

#### Sizeof

C gives us a way to check the size of a type or a variable: sizeof.

You can use sizeof like a function (although, technically it's a unary operator, but that distinction is generally only useful for winning super important internet arguments).

We'll use the sizeof operator in the next few lessons to give us insight into the memory layout of different types in C. This will be particularly useful as we move deeper into C, and essential for understanding pointers.

#### size_t

The size_t type is a special type that is guaranteed to be able to represent the size of the largest possible object in the target platform's address space (i.e. can fit any single, non-struct value inside of it).

It's also the type that sizeof returns.

### Type Conversions

Sometimes, you might want to convert a value from one type to another. This is called type conversion or type casting. In C, you can do this using the (type) syntax. For example:
```c
int x = 42;
float y = (float)x; // convert int to float
```

### 5. Functions
In C, functions specify the types for their arguments and return value.
```c
float add(int x, int y) {
    return (float)(x + y);
}
```

* The first type, float is the return type.
* add is the name of the function.
* int x, int y are the parameters to the function, and their types are specified.
* x + y adds the two arguments together.
* (float) casts the result to a float.
    * We'll talk more about what cast means later, and the rules for casting to and from certain types.
    * The simple version is that it instructs C to convert the result of x + y to a float value.

Here's how you would call this function:
```c
int main() {
    float result = add(10, 5);
    printf("result: %f\n", result);
    // result: 15.000000
    return 0;
}
```

#### Function Prototypes

In C, functions must be declared before they are used. This is done with a function prototype, which is a declaration of the function's signature (name, return type, and parameters) without the body.
```c
float add(int x, int y);
```

#### Function Definitions
The function definition is the actual implementation of the function, which includes the body of the function.
```c
float add(int x, int y) {
    return (float)(x + y);
}
```

#### Assignment

Write a max_memory function in the space provided. It should:

* accept two arguments:
    * int max_threads
    * int memory_per_thread
* return an integer representing the total memory available to the Sneklang interprete

### Void

In C, there's a special type for function signatures: void. There are two primary ways you'll use void:

To explicitly state that a function takes no arguments:

```c
int get_integer(void) {
    return 42;
}
```

When a function doesn't return anything:

```c
void print_integer(int x) {
    printf("this is an int: %d", x);
}
```

It's important to note that void in C is not like None in Python. It's not a value that can be assigned to a variable. It's just a way to say that a function doesn't return anything or doesn't take any arguments.

### File layout and types
C programs are typically split into multiple files. The main file is usually called main.c, and it contains the main function. Other files can contain functions that are used by the main function or other functions.

To use functions from other files, you need to declare them in a header file (with a .h extension). The header file contains the function signatures, and the source file (with a .c extension) contains the function definitions.

An example of a header file (max_memory.h):
```c
int max_memory(int max_threads, int memory_per_thread);
```

### The Preprocessor

The preprocessor is a tool that runs before the compiler. It processes the source code and performs tasks like including header files, defining macros, and conditional compilation. And start with a # symbol. For example, the #include directive tells the preprocessor to include the contents of a header file in the source code.
```c
#include <stdio.h>
```

#### Directives
* #include – includes the contents of a file
* #define – defines a macro, It literally replaces all instances of the macro with the value you define. For example, #define PI 3.14 will replace all instances of PI in your code with 3.14.
* #ifdef – checks if a macro is defined
* #ifndef – checks if a macro is not defined
* #if – checks if a condition is true
* #elif – checks if a condition is true, and if not, checks the next condition
* #else – provides an alternative if the condition is false
* #endif – ends a conditional directive

#### Common macros

* \_\_FILE\_\_ – the name of the current source file
* \_\_LINE\_\_ – the current line number in the source file
* \_\_FUNCTION\_\_ – the name of the current function
* MIN(a, b) – a macro that returns the minimum of a and b
* MAX(a, b) – a macro that returns the maximum of a and b


#### Pragma Once

One simple solution (and the one we'll use for the rest of this course) is #pragma once. Adding this line to the top of a header file tells the compiler to include the file only once, even if it's referenced multiple times across your program.
```c
// my_header.h

#pragma once

struct Point {
    int x;
    int y;
};
```
#### Header Guards

Another common way to avoid multiple inclusions is with include guards, which use preprocessor directives like this:

```c
#ifndef MY_HEADER_H
#define MY_HEADER_H

// some cool code

#endif
```

This method works by defining a unique macro for the header file. If it's already been included, the guard prevents it from being processed again.

Throughout this course, you'll see #pragma once in our header files. It's quicker and less error-prone than traditional include guards, and it works well with most modern compilers.

#### Documentation using doxygen

Most documentation in C is done using comments and live mostly in header files (.h). However, there is a tool called doxygen that can generate documentation from specially formatted comments. Doxygen uses a special syntax to denote comments that should be included in the documentation.
```c
/**
 * @brief This function calculates the maximum memory available to the Sneklang interpreter.
 * @param max_threads The maximum number of threads that can be used by the interpreter.
 * @param memory_per_thread The amount of memory available to each thread.
 * @return The total amount of memory available to the interpreter.
 */
int max_memory(int max_threads, int memory_per_thread);
```

The @brief tag is used to provide a brief description of the function. The @param tag is used to describe each parameter, and the @return tag is used to describe the return value.

When you run doxygen on the source code, it will generate documentation in HTML, LaTeX, or other formats. The generated documentation will include the function signatures, descriptions, and any other comments that are included in the source code. It can also include diagrams and other visualizations of the code structure.

### Testing / Unit tests
Up to this point printing has been the only way to check if your code is working. This is not ideal, because it requires you to manually check the output of your program. A better way to check if your code is working is to write unit tests.

Unit tests are small functions that test a specific piece of functionality in your code. They are usually written in a separate file (e.g. test_max_memory.c) and use a testing framework (e.g. Google Test) to run the tests and check the results.

#### GDB GNU Debugger

The GNU Debugger (GDB) is a powerful tool that allows you to debug your C programs. It allows you to run your program step by step, inspect variables, and see what is happening in your code. You can use GDB to find bugs in your code and understand how your program is working. But your code must be compiled with the -g flag to include debug information.

#### Valgrind

Valgrind is a tool that can help you find memory leaks and other memory-related bugs in your C programs. It can also help you find uninitialized memory reads, invalid memory accesses, and other issues. You can use Valgrind to check your code for memory leaks and other issues.

#### Assignment
Write the get_average (mathematical average) function in exercise.c based on the function prototype expected in ex1_7.h.

### 7. Math Operators

All the same operators you'd expect exist in C:
```c
    x + y;
    x - y;
    x * y;
    x / y;
    x % y; // modulus (remainder of x divided by y)
```
If an = sign is added, it becomes an assignment operator:

```c
    x += y; // x = x + y
    x -= y; // x = x - y
    x *= y; // x = x * y
    x /= y; // x = x / y
    x %= y; // x = x % y
```

In addition, there are also the ++ and -- operators:

x++; // += 1
x--; // -= 1

The name of C++ is a bit of a joke by the creator, it's meant to be "incremented C" or "better C".

These increment (++) and decrement (--) operators can be used in two forms: postfix and prefix.

Postfix (x++ or x--): The value of x is used in the expression first, and then x is incremented or decremented. For example:

int a = 5;
int b = a++; // b is assigned 5, then a becomes 6

Prefix (++x or --x): x is incremented or decremented first, and then the new value of x is used in the expression. For example:

int a = 5;
int b = ++a; // a becomes 6, then b is assigned 6

Generally avoid prefix operators. If you want to increment a variable but keep the original value, do it in two steps. Postfix is more common, especially in loops, which we'll get to.

#### Assignment

Complete the score function in ex1_7.c. 
The score is calculated as follows:

* Multiply the number of files by the number of commits to get the size factor
* Add the size factor to the number of contributors to get the complexity factor
* Multiply the complexity factor by the average bug criticality (a number between 0 and 1) to get the final score

### 8. If Statements

if statements are the most basic form of control flow in C: very similar to other languages. Basic syntax:

```c
if (x > 3) {
    printf("x is greater than 3\n");
}
```

if/else/else if are also available:

```c
if (x > 3) {
    printf("x is greater than 3\n");
} else if (x == 3) {
    printf("x is 3\n");
} else {
    printf("x is less than 3\n");
}
```
#### Janky Syntax

You can write an if statement without braces if you only have one statement in the body:

```c
if (x > 3) printf("x is greater than 3\n");
```

However, this is generally considered bad style and can lead to bugs if you later add more statements to the body without adding braces.

#### Assignment

Take a look at ex1_8.h. Write the implementation for the function prototype found there back in ex1_8.c. It should calculate whether the given temperature is too cold or too hot (it's already in Fahrenheit of course, the most reasonable scale for regular living).

* Less than 70 returns "too cold".
* More than 90 returns "too hot".
* Otherwise return "just right".

### 9. Logical Operators

Logical operators let you combine multiple conditions in C. There are three main logical operators you'll use all the time:

* && – Logical AND: true if both conditions are true
* || – Logical OR: true if either condition is true
* ! – Logical NOT: inverts a boolean value

```c
int age = 25;
bool has_license = true;

if (age >= 18 && has_license) {
    printf("Can drive\n");
}
```

Short-Circuit Evaluation

C uses short-circuit evaluation with logical operators. This means:

* With &&, if the first condition is false, the second isn't even checked (because the whole thing is already false)
* With ||, if the first condition is true, the second isn't checked (because the whole thing is already true)
```c
if (x != 0 && 10 / x > 2) {
    // The division only happens if x != 0
    // This prevents a division by zero error
    printf("Safe!\n");
}
```
#### Operator Precedence

Logical NOT (!) has higher precedence than AND (&&), which has higher precedence than OR (||). When in doubt, use parentheses to make your intent crystal clear:

```c
// without parentheses – might be confusing
if (!is_raining && is_sunny || is_weekend)

// with parentheses – much clearer
if ((!is_raining && is_sunny) || is_weekend)
```

#### Switch case

C also has a switch statement, which is a more concise way to write multiple if/else if statements when you're checking the same variable against different values.

```c
switch (day) {
    case 0:
        printf("Sunday\n");
        break;
    case 1:
        printf("Monday\n");
        break;
    case 2:
        printf("Tuesday\n");
        break;
    case 3:
        printf("Wednesday\n");
        break;
    case 4:
        printf("Thursday\n");
        break;
    case 5:
        printf("Friday\n");
        break;
    case 6:
        printf("Saturday\n");
        break;
    default:
        printf("Invalid day\n");
        break;
}
```
The default case is optional, but it's good practice to include it to handle unexpected values.

#### Assignment

The can_access_registry function should return 1 (true) if a user can access the private registry, or 0 (false) if they cannot.

A user can access the private registry if any of these conditions are met:

* They have is_premium set to 1 (true)
* They have both reputation >= 100 AND has_2fa (two-factor authentication) set to 1 (true)

### Ternary

C has a ternary operator:
```c
int a = 5;
int b = 10;
int max = a > b ? a : b;
printf("max: %d\n", max);
// max: 10
```
Let's break down the syntax:

a > b ? a : b

* a > b is the condition
* ? begins the "then" value
* a is the final value if the condition is true
* : separates the "else" value
* b is the final value if the condition is false
* The entire expression (a > b ? a : b) evaluates to either a or b, which is then assigned to max in our example.

Ternaries are a way to write a simple if/else statement in one line

### 10. For Loop

A for loop in C is a control flow statement for repeated execution of a block of code. Very similar to Python, but with a different syntax.

The syntax of a for loop in C consists of three main parts:

* Initialization
* Condition
* Final-expression.

There is no "for each" (iterables) in C. For example, there is no way to do:
```python
for car in cars:
    print(car)
```

Instead, we have to iterate over the numbers of indices in a list, and then we can access the item using the index.
Syntax
```c
for (initialization; condition; final-expression) {
    // Loop Body
}
```
#### Parts of a for Loop

* Initialization
    * Executed only once at the beginning of the loop.
    * Is typically used to initialize the loop counter: int i = 0; for example
    Condition
    * Checked before each iteration.
    * If true, execute the body. If false, terminate the loop
    * Often checks to ensure i is less than some value: i < 5; for example
* Final-expression
    * Executed after each iteration of the loop body.
    * Can be used to update the loop counter or run any other code: i++ for example
* Loop Body
    * The block of code that is executed while the condition is true.

Example: Basic Loop
```c
#include <stdio.h>

int main() {
  for (int i = 0; i < 5; i++) {
    printf("%d\n", i);
  }
  return 0;
}

// Prints:
// 0
// 1
// 2
// 3
// 4
```
#### Assignment

Implement the print_numbers prototyped in exercise.h that takes a starting number and an ending number and prints all the numbers in that range inclusive (using a for-loop).

### While loop

A while loop in C is a control flow statement that allows code to be executed repeatedly based on a given boolean condition. The syntax of a while loop in C is as follows:
```c
while (condition) {
    // Loop Body
}
```

Parts of a while Loop

* Loop Body
    * The block of code that is executed while the condition is true.
* Condition
    * Checked before each iteration.
    * If true, execute the body. If false, terminate the loop
#### Example
```c
#include <stdio.h>

int main() {
    int i = 0;
    while (i < 5) {
        printf("%d\n", i);
        i++;
    }
    return 0;
}
// Prints:
// 0
// 1
// 2
// 3
// 4
```

### 11. Do While Loop

A do while loop in C is a control flow statement that allows code to be executed repeatedly based on a given boolean condition.

Unlike the while loop, the do while loop checks the condition after executing the loop body, so the loop body is always executed at least once.
Syntax

```c
do {
    // Loop Body
} while (condition);
```

Parts of a do while Loop

* Loop Body
    * The block of code that is executed before checking the condition, and then repeatedly as long as the condition is true.
* Condition:
    * Checked after each iteration.
    * If true, execute the body again.
    * If false, terminate the loop

#### Examples
```c
#include <stdio.h>

int main() {
    int i = 0;
    do {
        printf("i = %d\n", i);
        i++;
    } while (i < 5);
    return 0;
}
// Prints:
// i = 0
// i = 1
// i = 2
// i = 3
// i = 4
```
```c
#include <stdio.h>

int main() {
    int i = 100;
    do {
        printf("i = %d\n", i);
        i++;
    } while (i < 5);
    return 0;
}
// Prints:
// i = 100
```
#### Key Points

The do while loop guarantees that the loop body is executed at least once, even if the condition is false initially.

The most common scenario you will see a do-while loop used is in C macros – they let you define a block of code and execute it exactly once in a way that is safe across different compilers, and ensures that the variables created/referenced within the macro do not leak to the surrounding environment.

If you end up looking at any source code for macros, you will probably see a few do-while loops. For example:
```c
#define INCREMENT_BOTH(a, b) \
do { \
    a++; \
    b++; \
} while (0)
```
It creates a do-while loop, creates a few new variables and then checks that the assertion is valid. If it is not, then it errors and formats a (complicated) error message (If this code doesn't make any sense, that's fine too! I just wanted to show you where they most often occur).

There is no semi-colon after while(0) in the loop above. This lets the macro be used in a block of code without causing syntax errors.

When writing a normal do-while loop in your C code (not in a macro), you must include the semicolon after the loop.

#### Assignment

Run the code. Notice that it prints numbers from 5 to 1 in descending order. However, when the starting number is less than the ending number, it doesn't print anything because the condition of the while loop is never true. Modify the print_numbers_reverse function to use a do-while loop so that it always prints the starting number at least once, even if the condition is initially false.

### Break Continue

We can use break and continue statements to control the flow of loops in C.
The break statement is used to exit a loop prematurely, while the continue statement is used to skip the current iteration and move on to the next one.

```c
#include <stdio.h>

int main() {
    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            break; // exit the loop when i is 5
        }
        printf("%d\n", i);
    }
    return 0;
}
// Prints:
// 0
// 1
// 2
// 3
// 4
```

```c
#include <stdio.h>

int main() {
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            continue; // skip even numbers
        }
        printf("%d\n", i);
    }
    return 0;
}
// Prints:
// 1
// 3
// 5
// 7
// 9
```

### 12. Arrays

An array is a data structure, used to store a collection of elements of the same type. Although an array is used to store a collection of data, it is often more useful to think of an array as a collection of variables of the same type. Each of those elements are identified by the same array name but with a different array index.

#### Array Declaration

Arrays are declared by specifying the type of elements they will hold, followed by the array name and the number of elements in square brackets.

    type <array_name>[number_of_elements];

For example, to declare an array of integers with 5 elements, you would write:
```c
int my_array[5];
```

#### Initialization
You can initialize an array at the time of declaration by providing a comma-separated list of values enclosed in curly braces. For example, to initialize an array of integers with 5 elements, you would write:
```c
int my_array[5] = {1, 2, 3, 4, 5};
```

Most of the time you want to zeroinitialize an array, which can be done like this:
```c
int my_array[5] = {0}; // initializes all elements to 0
```

#### Using Arrays
You can access individual elements of an array using their index, which starts at 0. For example, to assign a value to the first element of the array, you would write:
```c
int my_array[5] = {0};
my_array[0] = 10;
my_array[1] = 20;
printf("%d\n", my_array[0]); // prints 10
printf("%d\n", my_array[1]); // prints 20
```

#### Passing arrays to functions
When you pass an array to a function, what is actually passed is a pointer to the first element of the array. This means that if you modify the array inside the function, the changes will be reflected in the original array. To illustrate this, consider the following example:

```c
// These 2 functions demonstrate different ways to pass arrays to functions in C.
void modify_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] += 10; // modifies the original array
    }
}

void modify_array_pointer(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] += 10; // modifies the original array
    }
}

int main() {
    int my_array[5] = {1, 2, 3, 4, 5};
    modify_array(my_array, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d\n", my_array[i]); // prints 11, 12, 13, 14, 15
    }
    return 0;
}
```

#### Writing out of bound

Sometimes, you might accidentally write to an index that is out of bounds of the array. This can lead to undefined behavior, which means that your program might crash, produce incorrect results, or even seem to work correctly. Always make sure to check the size of the array before accessing its elements. This is why it's important to pass the size of the array to functions that operate on it, so they can ensure they don't go out of bounds.

#### Assignment

Create 5 functions that takes an array of n integers and returns
2. the maximum value in that array
3. the minimum value in that array
4. the sum of those integers
5. the product of those integers
6. the average of those integers (as a float)
7. the median of those integers (as a float)

Hint for median:
Sort the array by using qsort:
```c
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

qsort(arr, size, sizeof(int), compare);
```

Then, if the size of the array is odd, return the middle element. If it's even, return the average of the two middle elements.

### 13. Strings

You have 2 types of strings, constants and mutable strings. Constant strings are string literals, which are stored in read-only memory and cannot be modified. While mutable strings are arrays of characters that can be modified.

#### Null-terminated Strings
In C, strings are represented as arrays of characters terminated by a null character ('\0'). This means that the end of the string is marked by a special character, which allows functions to determine where the string ends. For example, the string "Hello" would be represented in memory as:
```
'H' 'e' 'l' 'l' 'o' '\0'
```

#### Assigning Strings
You can assign a string literal to a char pointer, which points to the first character of the string. For example:
```c
char *str = "Hello, world!";
```
But you can not reassign a string literal to a char pointer, because string literals are stored in read-only memory. For example:
```c
char *str = "Hello, world!";
str = "New string"; // This is allowed, but it points to a new string literal
```

When you want to modify a string, you should use a character array instead of a char pointer. For example:
```c
char str[] = "Hello, world!";
str[0] = 'h'; // This is allowed, and modifies the first character of the string
```
#### Passing a string to a function
This is the same as passing an array to a function. If you want to modify the string inside that function, also pass the maximum length of that array.

#### String Functions
Most of the time, you'll be using the string.h library to work with strings. Some common functions include:
* size_t strlen(const char *s) – returns the length of a string (not including the null terminator)
* int strncmp(const char *s1, const char *s2, size_t n) – compares two strings up to a specified number of characters
* char *strncpy(char *dst, const char *restrict src, size_t dsize) - copies a string to another string, but does not guarantee that the destination string is null-terminated
* size_t strlcpy(char *dst, const char *restrict src, size_t dsize); – copies a string to another string, ensuring that the destination string is null-terminated and does not overflow but is not part of the C standard library (it's available on some systems like BSD and Linux)
* int snprintf(char *str, size_t size, const char *restrict format, ...); – formats a string and stores it in a buffer, ensuring that the buffer is not overflowed (same as printf but for writing to a string instead of stdout)

Some functions are in ctype.h, which is used for character classification and conversion. Some common functions include:
* int isalpha(int c) – checks if a character is an alphabetic letter
* int isalnum(int c) – checks if a character is alphanumeric (a letter or a digit)
* int isdigit(int c) – checks if a character is a digit
* int isspace(int c) – checks if a character is a whitespace character
* int isupper(int c) – checks if a character is an uppercase letter
* int islower(int c) – checks if a character is a lowercase letter
* int tolower(int c) – converts a character to lowercase
* int toupper(int c) – converts a character to uppercase

#### Assignment
Create 5 functions that takes a string and returns:
1. 1 if the string is a palindrome as in a word (a string that reads the same forwards and backwards), 0 if it is not. Ex noon, racecar, level, rotor, etc. Return 1 if it is a palindrome, 0 if it is not.
2. 1 if the string is a palindrome as in a sentence (ignoring spaces, punctuation, and capitalization), 0 if it is not. Ex "Was it a car or a cat I saw", "Eva, can I stab bats in a cave?"
3. 1 if the string is a pangram (a sentence that contains every letter of the alphabet at least once), 0 if it is not. Ex "The quick brown fox jumps over the lazy dog"

### 14. Bitwise Operators

Like the logical operators, bitwise operators allow you to manipulate individual bits of values. The most common bitwise operators are:
* & – Bitwise AND: performs a logical AND operation on each pair of corresponding bits of two values.
* | – Bitwise OR: performs a logical OR operation on each pair of corresponding bits of two values.
* ^ – Bitwise XOR: performs a logical exclusive OR operation on each pair of corresponding bits of two values.
* ~ – Bitwise NOT: inverts the bits of a value

* << – Left Shift: shifts the bits of a value to the left by a specified number of positions, filling in with zeros on the right.
* \>> – Right Shift: shifts the bits of a value to the right by a specified number of positions, filling in with the sign bit on the left (for signed values) or zeros (for unsigned values).

#### Bitmasks

Bitmasks are a common technique used in C programming to manipulate specific bits within a value. A bitmask is a binary pattern that can be used to isolate, set, or clear specific bits in a value using bitwise operators.

An example of using a bitmask to check if a specific bit is set in an integer:
```c
#include <stdio.h>

int main() {
    int value = 0b10101010; // binary representation of 170
    int mask  = 0b00000100; // binary representation of 4 (we want to check the 3rd bit)

    if (value & mask) {
        printf("The 3rd bit is set.\n");
    } else {
        printf("The 3rd bit is not set.\n");
    }

    value |= mask; // Set the 3rd bit
    printf("New value after setting the 3rd bit: %X\n", value);

    value &= ~mask; // Clear the 3rd bit
    printf("New value after clearing the 3rd bit: %X\n", value);

    value ^= mask; // Toggle the 3rd bit
    printf("New value after toggling the 3rd bit: %X\n", value);

    return 0;
}
```

#### Assignment
Complete 2 functions that take an array of uint64_t use the function prototypes from the header file and:
* Be able to set a specific bit in each element of the array to 1 or 0.
* Be able to check if a specific bit in each element of the array is set to 1 or 0.

For both functions, the least significant bit (LSB) is considered to be at index 0, and the most significant bit (MSB) is considered to be at index 63.
And the next index is considered to be at index 64, and so on.