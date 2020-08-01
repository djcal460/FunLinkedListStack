#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "func.h"

extern struct Node *global;

int count(struct Node *p)
{
    int c = 0;
    while (p)
    {
        c = c + 1;
        p = p->next; //move to next node
    }
    return c;
}

//don't need to pass anything to display globals list
void display()
{

    //need a reference to it, so we aren't actually moving global ptr
    struct Node *p;
    p = global;

    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
//not changing anything, so just pick up the ptr here
void display_local(struct Node *p)
{

    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int isEmpty()
{
    if (count(global) == 0)
        return 1;
    else
        return 0;
}
int isEmpty_local(struct Node *p)
{
    if (count(p) == 0)
        return 1;
    else
        return 0;
}
int isFull(int size)
{
    if (count(global) >= size)
        return 1;
    else
        return 0;
}
int isFull_local(struct Node *p, int size)
{
    if (count(p) >= size)
        return 1;
    else
        return 0;
}
int stackTop()
{
    if (isEmpty())
    {
        return -1;
    }
    else
        return global->data;
}
int stackTop_local(struct Node *p)
{
    if (isEmpty(p))
    {
        return -1;
    }
    else
        return p->data;
}

void push(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;      //save data to new node
    t->next = global; //old top is now t->next (insert on left)
    global = t;       //global is now t
}
void push_local(struct Node **p, int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;  //save data to new node
    t->next = *p; //old global is now t->next (insert on left)
    *p = t;       //global is now t
}

int pop()
{
    int x;
    //create new node
    struct Node *t;
    if (isEmpty())
        x = -1; //empty
    else
    {
        t = global;            //temp ptr to pt to top of stack
        global = global->next; // move top to next node on stack
        x = t->data;           //temp ptr save data
        free(t);               //free node pted to by t
    }
    return x;
}
int pop_local(struct Node **p)
{
    int x;
    //create new node
    struct Node *t;
    if (isEmpty_local((*p)))
        x = -1; //empty
    else
    {
        t = *p;          //temp ptr to pt to top of stack
        *p = (*p)->next; // move top to next node on stack
        x = t->data;     //temp ptr save data
        free(t);         //free node pted to by t
    }
    return x;
}

int peek(int size, int pos)
{

    int x = -1;
    //check if invalid pos
    if (pos < 0 || pos > size)
    {
        printf("Invalid Position\n");
        return x;
    }

    //iterate to position and return the data
    struct Node *t = global;
    for (int i = 1; i < pos; i++)
    {
        t = t->next;
    }
    x = t->data;

    return x;
}

int peek_local(struct Node *p, int size, int pos)
{

    int x = -1;
    //check if invalid pos
    if (pos < 0 || pos > size)
    {
        printf("Invalid Position\n");
        return x;
    }

    //iterate to position and return the data
    for (int i = 1; i < pos; i++)
    {
        p = p->next;
    }
    x = p->data;

    return x;
}

int reprompt(int flag)
{
    int fixin, input, ret = 0;
    if (flag == 1)
    { //check valid size
        while (ret != 1 || input > INT_MAX || input < 1)
        {
            printf("Enter a valid size: ");
            while ((fixin = getchar()) != EOF && fixin != '\n')
                ; // fix stdin
            fflush(stdin);
            ret = scanf("%d", &input);
        }
    }
    else if (flag == 2)
    { // check valid int
        while (ret != 1 || input > INT_MAX)
        {
            printf("Enter a valid integer: ");
            while ((fixin = getchar()) != EOF && fixin != '\n')
                ; // fix stdin
            fflush(stdin);
            ret = scanf("%d", &input);
        }
    }
    else if (flag == 3)
    { // check valid option 1-3
        while (ret != 1 || input > 3 || input < 1)
        {
            printf("\nEnter a valid option 1,2,3: ");
            while ((fixin = getchar()) != EOF && fixin != '\n')
                ; // fix stdin
            fflush(stdin);
            ret = scanf("%d", &input);
        }
    }
    else if (flag == 4)
    { // check valid option 1-2
        while (ret != 1 || input > 2 || input < 1)
        {
            printf("Enter a valid option 1,2: ");
            while ((fixin = getchar()) != EOF && fixin != '\n')
                ; // fix stdin
            fflush(stdin);
            ret = scanf("%d", &input);
        }
    }
    else if (flag == 5)
    { // check valid option 1-15
        while (ret != 1 || input > 15 || input < 1)
        {
            printf("Enter a valid option 1-15: ");
            while ((fixin = getchar()) != EOF && fixin != '\n')
                ; // fix stdin
            fflush(stdin);
            ret = scanf("%d", &input);
        }
    }
    return input;
}

int tryagain()
{
    int prompt, ret;
    printf("Press [Any Key][Enter] to Repeat or [1] to Return to Menu: ");
    ret = scanf("%d", &prompt);
    if (prompt != 1 || ret != 1)
        return 0;
    return 1; //if 1, continue loop
}

int menuloop()
{
    int prompt, ret;
    printf("Press [Any Key][Enter] for New Menu Item or [1] to Exit Program: ");
    ret = scanf("%d", &prompt);
    if (prompt != 1 || ret != 1)
        return 0;
    return 1; //if 1, continue loop
}

void globallist()
{

    //prompt user
    int input, size, ret;
    printf("\nEnter the size of desired global linked list stack: ");
    ret = scanf("%d", &size);
    if (size < 1 || size > INT_MAX || ret != 1)
        size = reprompt(1); //1 flag for size
    printf("Enter an integer for each element of the linked list.\n");
    for (int i = 0; i < size; i++)
    {
        printf("Please enter an integer: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > INT_MAX)
            input = reprompt(2); //2 flag for int only
        push(input);
    }
}
