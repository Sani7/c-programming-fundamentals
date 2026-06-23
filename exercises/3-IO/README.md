## 3. IO advanced
### Command line arguments

In c programming, command line arguments are parameters passed to a program when it is executed. They allow users to provide input to the program without requiring interactive input during execution. Command line arguments are typically accessed through the `main` function's parameters: `int argc` and `char *argv[]`.

```c
int main(int argc, char *argv[]) {
    // argc: argument count
    // argv: argument vector (array of strings)
    
    // Example usage:
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }
    
    return 0;
}
```

The `argc` parameter represents the number of command line arguments passed to the program, including the program's name itself. The `argv` parameter is an array of strings (character pointers) that holds the actual arguments.

The first argument (`argv[0]`) is always the name of the program being executed, while subsequent arguments (`argv[1]`, `argv[2]`, etc.) are the additional parameters provided by the user.

#### Assignement

