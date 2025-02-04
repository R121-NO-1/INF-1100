#include <stdio.h>
#include <stdlib.h>

// Define the Stack structure
typedef struct
{
    int *array;  // Dynamic array to store stack elements
    int maxSize; // Maximum size of the stack
    int top;     // Index of the top element
} Stack;

// Function prototypes, what should be in the header file

void initialize(Stack *s, int size)
{
    s->array = (int *)malloc(size * sizeof(int));
    s->maxSize = size;
    s->top = -1; // intialize as -1 to get the starter value at exactly 0
} // Initialize stack with a size of 5 to understand how the base functions
int isEmpty(Stack * s)
    { // if stack is empty it should exist at -1 in  array size, conduct size check
        if (s->top == -1)
            {
                return s->top;
            }
    }

    int isFull(Stack * s)
    { // check if the stack is full
        if (s->top == s->maxSize){
            
        }
        if (s->top == s->maxSize - 1)
            return s->top;
    }

    // operations start

    void push(Stack * s)
    { // pushes stacks ontop of the list, cannot push if stack is full
        if (isFull)
        {
            printf("Cannot push, Stack is full"); // visual feedback
            return;

                        
        }
        else
        {
            s->top++; // addition of 1 //incrementation of 1 to the size counter
            printf("A stack has been pushed on top of the stack");
        }
    }

    int Pop(Stack * s)
    { // check if top==null stack is empty cannot delete,
        if (isEmpty)
        {
            printf("Cannot pop, stack is empty");
            return;
            // pop stack "execution" here.

            // use tmp variable for temporary variable allocation
        }else{}
    }

int main()
{
    Stack myStack;
    initialize(&myStack, 5); // refferring to the memory address of the stack, and setting it to 5 max

    // implement functions here

    
    // operators end

    return 0;
}
