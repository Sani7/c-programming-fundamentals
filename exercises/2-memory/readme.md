## 2. Memory

### Pointers

A pointer is a variable that stores the memory address of another variable. In C, you can declare a pointer using the `*` operator. For example:
```c
int x = 42;
int* p = &x; // p is a pointer to x
```

You can dereference a pointer using the `*` operator to access the value stored at the memory address it points to. For example:
```c
int x = 42;
int* p = &x; // p is a pointer to x
printf("%d\n", *p); // prints 42
```

You can also create pointers to pointers, which are variables that store the memory address of another pointer. For example:
```c
int x = 42;
int* p = &x; // p is a pointer to x
int** pp = &p; // pp is a pointer to p
printf("%d\n", **pp); // prints 42
```

#### Const Pointers

A const pointer is a pointer that cannot be changed to point to a different memory address. You can declare a const pointer using the `const` keyword. For example:
```c
int x = 42;
int* const p = &x; // p is a const pointer to x
```
You also have the option to declare a pointer to a const value, which means that the value being pointed to cannot be changed through the pointer. For example:
```c
const int x = 42;
const int* p = &x; // p is a pointer to a const int
```
or you can combine both to create a const pointer to a const value:
```c
const int x = 42;
const int* const p = &x; // p is a const pointer to a const int
```

#### Pointer Arithmetic

You can perform arithmetic operations on pointers to navigate through memory. For example, you can increment a pointer to point to the next element in an array:
```c
int arr[5] = {1, 2, 3, 4, 5};
int* p = arr; // p points to the first element of arr
printf("%d\n", *p); // prints 1
printf("%d\n", *(p + 1)); // is equivalent to p[1], prints 2
```

### Array vs Pointer

In C, arrays and pointers are closely related, but they are not the same. An array is a collection of elements of the same type, while a pointer is a variable that stores the memory address of another variable. When you declare an array, the name of the array is a pointer to the first element of the array. For example:
```c
int arr[5] = {1, 2, 3, 4, 5};
int* p = arr; // p points to the first element of arr
printf("%d\n", *p); // prints 1
printf("%d\n", *(p + 1)); // is equivalent to p[1], prints 2
```

#### Passing Arrays to Functions

When you pass an array to a function, you are actually passing a pointer to the first element of the array. This means that any changes made to the array inside the function will affect the original array. For example:
```c
void modify_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2; // modify the array
    }
}
```

#### Multidimensional Arrays

There are 2 ways to create a 2D array in C: using a pointer to a pointer or using a single block of memory. The first method is more flexible, but the second method is more efficient.

```c
// Method 1: Pointer to pointer
int** arr = malloc(rows * sizeof(int*));
for (int i = 0; i < rows; i++) {
    arr[i] = malloc(cols * sizeof(int));
}

arr[0][0] = 1; // access the element

// Method 2: Single block of memory
int* arr = malloc(rows * cols * sizeof(int));
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        arr[i * cols + j] = i * cols + j; // access the element
    }
}

arr[0 * cols + 0] = 1; // access the element
```

### Memory Management

In C, you have 2 types of memory: stack and heap. The stack is used for static memory allocation, while the heap is used for dynamic memory allocation.
An example:
```c
#include <stdlib.h>

int main() {
    int w = 42; // w is allocated on the stack
    int x[10] = {42}; // x is allocated on the stack
    int* y = malloc(sizeof(int)); // y is allocated on the heap
    int* z = calloc(1, sizeof(int)); // z is allocated on the heap and initialized to 0
    *y = 42;
    *z = 42;
    free(y); // free the memory allocated on the heap
    free(z); // free the memory allocated on the heap
    return 0;
}
```

The safest way to allocate memory is to use `calloc`, as it initializes the memory to zero. However, if you want to allocate memory without initializing it, you can use `malloc`. If you want to change the size of an allocated memory block, you can use `realloc`. Finally, when you are done with the allocated memory, you should free it using `free`.

It is recommended to allocate memory without reallocating it. Instead, you can allocate a larger block of memory than you need and use it as a pool of memory. This way, you can avoid the overhead of reallocating memory and reduce the risk of memory fragmentation.

#### Memory functions

* `malloc(size_t size)`: allocates `size` bytes of memory on the heap and returns a pointer to the allocated memory. The memory is not initialized.
* `calloc(size_t num, size_t size)`: allocates memory for an array of `num` elements of `size` bytes each and returns a pointer to the allocated memory. The memory is initialized to zero.
* `realloc(void* ptr, size_t size)`: changes the size of the memory block pointed to by `ptr` to `size` bytes. The contents will be unchanged up to the minimum of the old and new sizes. If the new size is larger, the new memory will not be initialized.
* `free(void* ptr)`: deallocates the memory previously allocated by a call to `malloc`, `calloc`, or `realloc`. If `ptr` is NULL, no operation is performed.

### Common pitfalls and best practices

* Dangling pointers: A dangling pointer is a pointer that points to a memory location that has been freed. Accessing a dangling pointer can lead to undefined behavior. To avoid dangling pointers, you should set the pointer to NULL after freeing the memory it points to.
* Memory leaks: A memory leak occurs when a program allocates memory on the heap but fails to free it. This can lead to a program consuming more and more memory over time, eventually leading to a crash. To avoid memory leaks, you should always free the memory you allocate on the heap.
* Double free: A double free occurs when a program attempts to free the same memory location more than once. This can lead to undefined behavior and can be exploited by attackers to execute arbitrary code.
* Null pointer dereference: A null pointer dereference occurs when a program attempts to access memory through a null pointer. This can lead to a crash or undefined behavior. To avoid null pointer dereferences, you should always check if a pointer is NULL before dereferencing it.

#### Example of a dangling pointer:
```c
#include <stdlib.h>

int main() {
    int* p = malloc(sizeof(int)); // allocate memory on the heap
    *p = 42; // assign a value to the allocated memory
    free(p); // free the allocated memory
    printf("%d\n", *p); // dangling pointer, undefined behavior
    return 0;
}
```

#### Solution to double free:
```c
#include <stdlib.h>
#define free(ptr) do { free(ptr); ptr = NULL; } while(0)

int main() {
    int* p = malloc(sizeof(int)); // allocate memory on the heap
    *p = 42; // assign a value to the allocated memory
    free(p); // free the allocated memory
    free(p); // fixed double free, no operation is performed since p is NULL
    return 0;
}
```

#### Solution to null pointer dereference:
```c
#include <stdlib.h>
#define free(ptr) do { free(ptr); ptr = NULL; } while(0)

int main() {
    int* p = malloc(sizeof(int)); // allocate memory on the heap
    if (p != NULL) { // check if the pointer is NULL before dereferencing it
        *p = 42; // assign a value to the allocated memory
    }
    // Or
    int* p = malloc(sizeof(int)); // allocate memory on the heap
    int val = p != NULL ? *p = 42 : 0; // assign a value to the allocated memory if p is not NULL
    free(p); // free the allocated memory
    return 0;
}
```

### Variable Scope

In C, the scope of a variable is the region of the program where the variable is defined and can be accessed. There are three types of variable scope in C: global, local, and static scope.

* Global variables are defined outside of any function and can be accessed from any function in the program.
* Local variables are defined inside a function or a block and can only be accessed within that function or block.
* Static variables are defined inside a function with the `static` keyword and can only be accessed within that function. However, they retain their value between function calls, meaning that the value of a static variable is preserved even after the function has finished executing. (They are stored in a different memory segment than local variables, which is why they retain their value between function calls.)

```c
#include <stdio.h>
int global_var = 41; // global variable

void function() {
    int local_var = 42; // local variable
    static int static_var = 42; // static variable
    printf("Global variable: %d\n", global_var);
    printf("Local variable: %d\n", local_var);
    printf("Static variable: %d\n", static_var);
    static_var++;
}

int main() {
    function();
    function();
    return 0;
}

// Output:
// Global variable: 41
// Local variable: 42
// Static variable: 42
// Global variable: 41
// Local variable: 42
// Static variable: 43
```

### 1. Structs

In C, a struct or structure is a user-defined data type that allows you to group different types of variables together. For example:
```c
struct Point {
    int x;
    int y;
};
```

#### Typedef
You can use the `typedef` keyword to create an alias for a struct. This allows you to use the alias instead of the `struct` keyword when declaring variables of that type. It is also allowed to leave the struct name out of the typedef. For example:
```c
// with struct name
typedef struct Point {
    int x;
    int y;
} Point;

// without struct name
typedef struct {
    int x;
    int y;
} Point;

int main() {
    Point p; // instead of struct Point p;
    p.x = 42;
    p.y = 42;
    return 0;
}
```

#### Padding
When defining a struct, the compiler may add padding between the members to ensure that each member is aligned in memory according to its type. This can lead to unexpected behavior if you are not careful. To avoid this, you can use the `__attribute__((packed))` attribute to create an unaligned struct. For example:
```c
struct __attribute__((packed)) Point {
    int x;
    int y;
};
```
This example below is not padded, so the size of the struct will be equal to the sum of the sizes of its members. However, this can lead to performance issues on some architectures, so it is generally recommended to use padding unless you have a specific reason not to.
```c
struct Bad_Example {
  uint8_t a; // 1 byte
  uint32_t b;  // 4 bytes
  uint8_t c; // 1 byte
};

struct Good_Example {
  uint32_t b;  // 4 bytes
  uint8_t a; // 1 byte
  uint8_t c; // 1 byte
};

int main() {
  printf("Size of struct: %zu bytes\n", sizeof(struct Bad_Example));
  // Output will be 12 bytes due to padding
  printf("Size of struct: %zu bytes\n", sizeof(struct Good_Example));
  // Output will be 8 bytes without padding
  return 0;
}
```

TIP: In a struct it is good practice to put the largest members first, as this can reduce the amount of padding needed and improve performance.

#### Nested structs
You can also define nested structs, which are structs that contain other structs as members. For example:
```c
struct Point {
    int x;
    int y;
};

struct Rectangle {
    struct Point top_left;
    struct Point bottom_right;
};
```
This allows you to create more complex data structures that can represent more complex objects.

#### Object oriented programming in c

Using structs, you can implement object-oriented programming concepts in C. You can define methods that operate on the struct and use function pointers to achieve polymorphism. For example:
```c
struct Point {
    int x;
    int y;
};

void point_move(struct Point* this, int dx, int dy) {
    this->x += dx;
    this->y += dy;
}

void point_print(struct Point* this) {
    printf("Point(%d, %d)\n", this->x, this->y);
}
```

#### Flexible array members
A flexible array member is a special type of array that can have a variable size. It is defined as the last member of a struct and has no size specified. For example:
```c
typedef struct Array {
    size_t size;
    int data[]; // flexible array member
} Array;

Array* array_init(size_t size) {
    Array* arr = malloc(sizeof(Array) + size * sizeof(int));
    if (arr == NULL) {
        return NULL; // allocation failed
    }
    arr->size = size;
    return arr;
}
```

#### Assignment
##### 1
Using the provided struct, implement the functions:
* `array_init`: allocates an array of `size` elements of `type` and returns a pointer to the allocated memory. The memory is initialized to zero.
* `array_free`: deallocates the memory previously allocated by a call to `array_init`. If `ptr` is NULL, no operation is performed.
* `array_reduce`: This discards x elements from the beginning of the array and moves the remaining elements to the beginning of the array. The size of the array is reduced by x. Without reallocating the memory, the size of the array is reduced by x. Handle the case where x is greater than or equal to the size of the array by returning an array with a size of 0.
* `array_get`: returns the value of the element at index `index` of the array pointed to by `ptr`. If `index` is out of bounds, the function should return an error code.
Create a wrapper define for the `array_get` function that takes a pointer to the array and an index, and returns the value of the element at that index. The wrapper should check if the index is out of bounds and return an error code if it is.

##### 2
Do the same for the 2D array functions:
* `array_2d_init`: allocates a 2D array of `rows` rows and `cols` columns of `type` and returns a pointer to the allocated memory.
* `array_2d_free`: deallocates the memory previously allocated by a call to `array_2d_init`. If `ptr` is NULL, no operation is performed.
* `array_2d_get`: returns the value of the element at row `row` and column `col` of the 2D array pointed to by `ptr`. If `row` or `col` is out of bounds, the function should return an error code.

Tip: Use the ptr to access the data in the array, instead of using the array. This way, you can easily use reduce and not have to reallocate more memory.

Tip: For the 2D array, you can store the data in a single block of memory and calculate the index of the element at row `row` and column `col`.

### Unions

Unions are a special data type that allows storing different data types in the same memory location. Only one member of the union can be active at a time, and the size of the union is equal to the size of its largest member.

```c
union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;
    data.i = 10;
    printf("data.i: %d\n", data.i);
    data.f = 7.5;
    printf("data.f: %f\n", data.f);
    strcpy(data.str, "Hello");
    printf("data.str: %s\n", data.str);
    return 0;
}
```

#### Enums + Unions
You can use enums to keep track of which member of the union is currently active. This can be used to create a variant map. For example:
```c
enum DataType {
    INT,
    FLOAT,
    STRING
};

typedef struct {
    enum DataType type;
    union {
        int i;
        float f;
        char str[20];
    } data;
} Variant;
```