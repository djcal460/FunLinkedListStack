#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "func.h"

void pushMenu(struct Node **p, int size, int type){//type local/global indicator
    int ret, input,f = 0;
    while (!f) //loop to allow continued pushing
    {
        printf("\nPush to the top of the stack\n");
        printf("Enter an integer to push: ");
        //get valid input
        ret = scanf("%d", &input);
        if (ret != 1 || input > INT_MAX || input < INT_MIN)
            input = reprompt(2); //Flag#2 valid int
        //push if not full
        if(!isFull(size) && type == 1){
            push(input);
            printf("Global Pushed: %d\n",input);
            display((*p));
        }
        else if(!isFull_local((*p),size) && type == 2){
            push_local(&(*p),input);
            printf("Local Pushed: %d\n",input);
            display_local((*p));
        }
        else{
            printf("Stack is full. No more room to push.\n");
            break;
        }
        

        f = tryagain();
    }
}

void popMenu(struct Node **p, int type)
{
    int f = 0;
    while (!f) //loop to allow continued popping
    {
        printf("\nPop the top of the stack\n");
        if(type == 2) {//local
            int k = pop_local(&(*p));
            if(k==-1){
                printf("The linked list stack is empty. Nothing left to pop.\n");
                break;
            }
            else{
                printf("Local Popped: %d\n",k);
                display_local(*p);
            }
        }
        else if(type == 1) {
            int k = pop();
            if(k==-1){
                printf("The linked list stack is empty. Nothing left to pop.\n");
                break;
            }
            else{
            printf("Global Popped: %d\n",k);
            display(*p);
            }
        }

        f = tryagain();
    }
}

void isEmptyMenu(struct Node *p, int type)
{
    //check if empty
    int ret, input;

    printf("\nCheck if linked list stack is empty?\n");
    printf("Enter 1 for yes, 2 for no: ");
    ret = scanf("%d", &input);
    if (ret != 1 || input > 2 || input < 1)
        input = reprompt(4); //Flag#4 valid option 1/2
    int k;
    if(input==1){
        if (type==1)
            k = isEmpty();
        else if(type==2)
            k = isEmpty_local(p);
        if(k==0)
            printf("Stack is not Empty\n");
        else
            printf("Stack is Empty\n");
    }
    else if (input==2){
        printf("Exiting to Main Menu...");
        return;
    }
}

void isFullMenu(struct Node *p, int size, int type)
{
    int ret, input;
    printf("\nCheck if linked list stack is full?\n");
    printf("Enter 1 for yes, 2 for no: ");
    ret = scanf("%d", &input);
    if (ret != 1 || input > 2 || input < 1)
        input = reprompt(4); //Flag#4 valid option 1/2
    if(input==1){
        int k;
        if (type==1)
            k = isFull(size);
        else if(type==2)
            k = isFull_local(p,size);
        if(k==0)
            printf("Stack is not Full\n");
        else
            printf("Stack is Full\n");
    }
    else if (input==2){
        printf("Exiting to Main Menu...");
        return;
    }
}

void stackTopMenu(struct Node *p, int type)
{
    int ret, input;
    printf("\nCheck top of the stack?\n");
    printf("Enter 1 for yes, 2 for no: ");
    ret = scanf("%d", &input);
    if (ret != 1 || input > 2 || input < 1)
        input = reprompt(4); //Flag#4 valid option 1/2
    if(input==1){
        int k;
        if (type==1)
            k = stackTop();
        else if(type==2)
            k = stackTop_local(p);
        if(k==-1)
            printf("Stack is empty, nothing at the top\n");
        else
            printf("%d is at the top of the stack.\n",k);
    }
    else if (input==2){
        printf("Exiting to Main Menu...");
        return;
    }
    
}

void peekMenu(struct Node *p, int size, int type)
{
    int ret, input;
    printf("\nPeek into the stack?\n");
    printf("Enter how far down you want to peek: ");
    ret = scanf("%d", &input);
    if (ret != 1 || input > INT_MAX || input < 0)
        input = reprompt(2); //Flag#2 valid int
    int k;
    if (type==1)
        k = peek(size,input);
    else if(type==2)
        k = peek_local(p,size,input);
    if(k==-1)
        printf("There is nothing at this position.\n");
    else
        printf("%d is at pos %d of the stack.\n",k,input);
}
