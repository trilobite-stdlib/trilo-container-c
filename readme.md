# Trilobite Continaers C

## overview

* * *

In computer science, a container is a class or a data structure whose instances are
collections of other objects. In other words, they store objects in an organized way
that follows specific access rules.

The size of the container depends on the number of objects (elements) it contains.
Underlying (inherited) implementations of various container types may vary in size,
complexity and type of language, but in many cases they provide flexibility in choosing
the right implementation for any given scenario.

Container data structures are commonly used in many types of programming languages. Here
we provide a handy collection of containers for use in your apps.

## tooling

* * *

The targeted audience we are building for is *Windows 10*, *MacOSX*, *ChromeOS*
and *Linux* users. This project uses [Meson](https://mesonbuild.com/) `1.0.0`
and newer, uses `c11` standards for initial implementation of the package. The
objective by far is usability, security, transparency, and lightweight, packages
for any if not most of your application development needs.

## Setup, Compile and Install

* * *

Using this package should be fairly simple just add the git wrap file
in your subprojects directory and include the dependency in your project.

```console
[wrap-git]
directory = trilo-container-c
url = https://github.com/trilobite-stdlib/trilo-container-c.git
revision = main

[provide]
trilo-container-c = trilo_container_dep
```


The next step should be to add the package to your Meson project:

```meson
trilo_dep = dependency('trilo-container-c')

executable('prog', 'main.c',
    dependencies : [trilo_dep])

```

And finally we setup, and compile the project just like normal.

## usage

* * *

Here is a simple sample application that should get you up and
running with using this library as soon as possible but to learn
more please view the API documentation thanks.

**Usage in C**:

```c
/*
   under:   trilobite stdlib
   author:  Michael Gene Ridge Brockus
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include <stdio.h>
#include <trilobite/package.h>


//
// main is where all good examples start
//
int main(void)
{
    StackOf *m_stack = tril_container_stack_create();
    if (tril_container_stack_its_empty(m_stack))
    {
        return EXIT_FAILURE;
    } // end if
    tril_container_stack_push(m_stack, "and eggs.");
    tril_container_stack_push(m_stack, "coffee,");
    tril_container_stack_push(m_stack, "to have");
    tril_container_stack_push(m_stack, "good day");
    tril_container_stack_push(m_stack, "Its a");

    while (tril_container_stack_not_empty(m_stack))
    {
        printf("%s ", tril_container_stack_peek(m_stack));
        tril_container_stack_pop(m_stack);
    } // end while
    tril_container_stack_prase(&m_stack);
    return EXIT_SUCCESS;
} // end of func

```

## contact

If you want to contact me and have a few questions
regarding the solutions in the programming you can
find a method on my [website](https://trilobite.code.blog/contact/).
