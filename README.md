# FunLinkedListStack

### Interactive terminal app demonstrating linked list stack

FunLinkedListStack was developed in c language to demonstrate how a globally or locally created singly linked list can be manipulated using pointers in many many ways.

- Enter your own elements to create a magically-numbered linked list stack
- 14 fun fun menu options to manipulate the stacks
- Repeat menu options to continually change the list

# Features!

Menu options include for both global and local stacks to display, push elements, pop elements, check if stack is full, check stack top, and finally look at a position under the stack!

### Tech

Tech uses the very very very advanced terminal shell and gcc compiler.

### Installation

The program comes with a swanky Makefile for you to automagically compile the .c extensions into .o binaries. Exciting? Make the file and run the file in bash.

```sh
$ make
$ ./funfunlinkedliststack
```

Don't have all that time to type in "make"? Well, I have another solution for you...

```sh
$ gcc -I./ -o funfunlinkedliststack funfunlinkedliststack.c menufunc.c func.c
```
