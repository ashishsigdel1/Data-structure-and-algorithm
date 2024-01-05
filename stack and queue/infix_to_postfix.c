#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack* operatorStack){
    return operatorStack->arr[operatorStack->top];
}

int isEmpty(struct stack*ptr) {
    if(ptr->top == -1) return 1;
    else return 0;
}

int isFull(struct stack*ptr){
    if(ptr->top == ptr->size -1) return 1;
    else return 0;
}

void push (struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack overflow! Cannot push %d to the stack.\n", val);
    }else{
        ptr -> top++;
        ptr -> arr[ptr->top] = val;
    }
}

int pop (struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack.\n");
        return -1;
    }else{
        char val = ptr -> arr[ptr->top];
        ptr -> top--;
        return val;
    }
}

int precedence(char ch){
    if(ch == '*' || ch == '/') return 3;
    else if(ch == '+' || ch == '-') return 2;
    else return 0;
}
int isOperator(char ch){
    if(ch == '*' || ch == '/' || ch == '+' || ch == '-') return 1;
    else return 0;
}

char * infixToPostfix(char * infix){
    struct stack * operatorStack = (struct stack*) malloc (sizeof(struct stack));
    operatorStack->size = 100;
    operatorStack->top = -1;
    operatorStack->arr = (char *) malloc (operatorStack->size * sizeof(char));
    char * postfix = (char *) malloc ((strlen(infix)+1) * sizeof(char));
    int i=0;
    int j=0;

    while(infix[i] != '\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }else {
            if(precedence(infix[i]) > precedence(stackTop(operatorStack))){
                push(operatorStack, infix[i]);
                i++;
            }else {
                postfix[j] = pop(operatorStack);
                j++;
            }
        }
    }
while(!isEmpty(operatorStack)){
    postfix[j] = pop(operatorStack);
    j++;
}
postfix[j] = '\0';
return postfix;
}



int main(){
    char * infix = "x-y/z-r*d";

    printf("Entered infix is %s \n", infix);
    printf("postfix is %s", infixToPostfix(infix));

    return 0;
}