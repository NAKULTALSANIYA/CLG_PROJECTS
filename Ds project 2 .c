#include <stdio.h>
#include <string.h>
#define mword 100
#define mlen 50

char stack[mword][mlen];
int top = 0,i;

// Push 
void push(char *word) 
{
    if (top == mword) 
	{  
        printf("Stack is full\n");
        return;
    }
    strcpy(stack[top], word);
    top++;
}

// Pop 
void pop() 
{
    if (top == 0) 
	{  
        printf("Nothing to undo!\n");
        return;
    }
    top--;  
    printf("Undo: Removed '%s'\n", stack[top]);
}

// Display 
void display() 
{
    if (top == 0) 
	{  
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for ( i = 0; i < top; i++) 
	{
        printf("%s ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    char word[mlen];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Word\n");
        printf("2. Undo Last Word\n");
        printf("3. Display Document\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a word: ");
                scanf("%s", word);
                push(word);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}


