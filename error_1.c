#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

void push(int value) {
    if (top >= STACK_SIZE - 1) {
        fprintf(stderr, "Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = value;
}

void pall() {
    int i;
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    char opcode[10];
    int value;

    while (1) {
        if (scanf("%s", opcode) == EOF) {
            break;
        }

        if (strcmp(opcode, "push") == 0) {
            if (scanf("%d", &value) != 1) {
                fprintf(stderr, "Usage: push integer\n");
                exit(EXIT_FAILURE);
            }
            push(value);
        } else if (strcmp(opcode, "pall") == 0) {
            pall();
        } else {
            fprintf(stderr, "Unknown opcode: %s\n", opcode);
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

