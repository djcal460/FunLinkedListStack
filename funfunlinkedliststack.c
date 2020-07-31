#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "func.h"
struct Node* global=NULL;

int main(){
    
    //welcome to this prog
    int input, localsize, ret;
    printf("\nWelcome to Fun Fun Linked List Stack. Demonstrating Knowledge of Linked Lists Stacks.\n");
    printf("To start, let's create two linked lists stacks (one global and one local).\n");
   
    //create global and local linked list
    globallist();
    int globalsize = count(global);
    struct Node *local = (struct Node *)malloc(sizeof(struct Node)); 
    
    printf("\nEnter the size of the desired local linked list stack: ");
    ret = scanf("%d", &localsize);
    if (localsize < 1 || localsize > INT_MAX || ret != 1)
        localsize = reprompt(1); //flag#1 for size
    printf("Enter an integer for each element of the local linked list stack.\n");
    for (int i = 0; i < localsize; i++)
    {
        printf("Please enter an integer: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > INT_MAX)
            input = reprompt(2); //2 flag for int only
        if(i == 0)
            local->data = input; //first node set
        else
            push_local(&local,input);//ptr to ptr funct
    
    }

    //display the lists to the user
    printf("\nThis is your global linked list stack: ");
    display(global);
    printf("global has %d nodes.",count(global));
    printf("This is your local linked list stack: ");
    display_local(local);
    printf("local has %d nodes.",count(local));
    
    

    //prompt user for what they would like to do with the linked list stacks
    do
    {
        printf("\nWhat Do You Want to Do with the Linked List Stacks?\n");
        printf("1.  Display global stack\n");
        printf("2.  Display local stack\n");        
        printf("3.  Push to global stack\n");
        printf("4.  Push to local stack\n");
        printf("5.  Pop from global stack\n");
        printf("6.  Pop from local stack\n");
        printf("7.  Check if global stack empty\n");
        printf("8.  Check if local stack empty\n");
        printf("9.  Check if global stack full\n");
        printf("10.  Check if local stack full\n");
        printf("11.  Check top of global stack\n");
        printf("12.  Check top of local stack\n");
        printf("13.  Look under global stack\n");
        printf("14.  Look under local stack\n");
        printf("15. Exit Program.\n");

        printf("\nEnter your choice: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 15 || input < 1)
            input = reprompt(5); //flag#5 for 1-15 choices
        switch (input)
        {
        
        case 1:
            printf("Display global\n");
            printf("Global Stack: ");display(global);
            printf("Press any key to continue: ");getchar();getchar();
            fflush(stdin);
            break;
        case 2:
            printf("Display local\n");
            printf("Local Stack: ");display_local(local);
            printf("Press any key to continue: ");getchar();getchar();
            fflush(stdin);
            break;
        case 3:
            printf("Push global");
            pushMenu(&global,globalsize,1);
            printf("Global Stack: ");display(global);
            printf("Press any key to continue: ");getchar();getchar();
            fflush(stdin);
            break;
        case 4:
            printf("Push local");
            pushMenu(&local,localsize,2);
            printf("Local Stack: ");display_local(local);
            printf("Press any key to continue: ");getchar();getchar();
            fflush(stdin);
            break;
        case 5:
            printf("Pop global");
            popMenu(&global,1);
            printf("Global Stack: ");display(global);
            printf("Press any key to continue: ");getchar();getchar();
            fflush(stdin);
            break;
        case 6:
            printf("Pop local");
            popMenu(&local,2);
            printf("Local Stack: ");display_local(local);
            printf("Press any key to continue: ");getchar();getchar();
            fflush(stdin);
            break;
        case 7:
            printf("Global empty?");
            isEmptyMenu(global,1);
            printf("Press any key to continue: ");getchar();getchar();
            fflush(stdin);
            break;
        case 8:
            printf("Local empty?");
            isEmptyMenu(local,2);
            printf("Press any key to continue: ");getchar();getchar();
            fflush(stdin);
            break;
        case 9:
            printf("Global full?");
            isFullMenu(global,globalsize,1);
            printf("Press any key to continue: ");getchar();getchar();
            fflush(stdin);
            break;
        case 10:
            printf("Local full?");
            isFullMenu(local,localsize,2);
            printf("Press any key to continue: ");getchar();getchar();
            fflush(stdin);
            break;
        case 11:
            printf("Look at top of global");
            stackTopMenu(global,1);
            printf("Press any key to continue: ");getchar();getchar();
            fflush(stdin);
            break;
        case 12:
            printf("Look at top of local");
            stackTopMenu(local,2);
            printf("Press any key to continue: ");getchar();getchar();
            fflush(stdin);
            break;
        case 13:
            printf("Look under global");
            peekMenu(global,globalsize,1);
            printf("Press any key to continue: ");getchar();getchar();
            fflush(stdin);
            break;
        case 14:
            printf("Look under local");
            peekMenu(local,localsize,2);
            printf("Press any key to continue: ");getchar();getchar();
            fflush(stdin);
            break;
        case 15:
            printf("Exiting Program\n");
            exit(0);
        default:
            printf("Invalid option.\n");
        }
    } while (input != 15);
    return 0;
}
    
