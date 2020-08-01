/*
 * Author: Derek Calzadillas
 * Purpose: To demonstrate knowledge of linked lists
 */
#ifndef __func_h__
#define __func_h__

struct Node
{
  int data;
  struct Node *next;
};

int count(struct Node *);
void display();
void display_local(struct Node *);
int isEmpty();
int isEmpty_local(struct Node *);
int isFull(int);
int isFull_local(struct Node *, int);
int stackTop();
int stackTop_local(struct Node *);
void push(int);
void push_local(struct Node **, int);
int pop();
int pop_local(struct Node **);
int peek(int, int);
int peek_local(struct Node *, int, int);
int reprompt(int);
int tryagain();
int menuloop();
void globallist();
void pushMenu(struct Node **, int, int);
void popMenu(struct Node **, int);
void isEmptyMenu(struct Node *, int);
void isFullMenu(struct Node *, int, int);
void stackTopMenu(struct Node *, int);
void peekMenu(struct Node *, int, int);

#endif
