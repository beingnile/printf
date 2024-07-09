# printf.

This project is a simple rewrite of the `printf` function in the `stdio.h` C library.  
>`man 3 printf` for more details.
PS: Not every conversion specifier is implemented.  

## Getting started
Here's the directory structure for the project:

```
.
├── README.md
├── _printf.c
├── makefile
├── main.h
├── print_helpers.c
└── utilities.c

```

### Prerequisites

* make: A build automation tool
* gcc: The GNU compiler collection for compiling C code
* git: For cloning this repo

#### Installing Prerequisites
On Ubuntu/Debian:

```sh

sudo apt-get update && sudo apt-get upgrade -y
sudo apt-get install gcc make git

```

### Installation and Setup
* Clone this repository  
Navigate to a directory of your choice on your system and clone this repo:

```sh

git clone https://github.com/beingnile/printf

```

* Navigate into the directory:

```sh

cd printf

```

* Copy the below content into a file `main.c`:

```c

#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
	void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
	addr = NULL;
    _printf("Empty addr:[%p]\n", addr);
    printf("Empty addr:[%p]\n", addr);
    addr = &ui;
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}

```

### Usage
* Build the project using `make`:

```sh

make

```
This will compile the source code files and generate an executable named `print`

* Run the executable to test the `_printf` function:

```sh

./print

```

You should see an output similar to this:

```

Let's try to printf a simple sentence.
Let's try to printf a simple sentence.
Empty addr:[(nil)]
Empty addr:[(nil)]
Address:[0x7ffdd08f7974]
Address:[0x7ffdd08f7974]
Length:[39, 39]
Length:[39, 39]
Negative:[-762534]
Negative:[-762534]
Unsigned:[2147484671]
Unsigned:[2147484671]
Unsigned octal:[20000001777]
Unsigned octal:[20000001777]
Unsigned hexadecimal:[800003ff, 800003FF]
Unsigned hexadecimal:[800003ff, 800003FF]
Character:[H]
Character:[H]
String:[I am a string !]
String:[I am a string !]
Percent:[%]
Percent:[%]
Len:[12]
Len:[12]
Unknown:[%r]
Unknown:[%r]

```

## Features
`_printf` handles the following conversion specifiers: `c`, `s`, `%`, `d`, `i`, `u`, `o`,  `p`, `x`, `X`
and a custom one `b` that converts `unsigned int` into it's binary representation.  
The function supports the basic functionalities of `printf`

## Limitations
As of writing this README file, the `_printf` function does not support some functionalities of
`printf`.  
The following features are not handled:  
* Flag characters (e.g `0`, `+` and `#`)
* Field width
* Precision
* Length modifiers
