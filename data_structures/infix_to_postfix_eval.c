#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int size = 50, top = -1, topsp = -1;
char s[50];
int sp[50];

void push(char c) {
    if (top >= size - 1) {
        printf("overflow");
    } else {
        top++;
        s[top] = c;
    }
}

char pop() {
    if (top < 0) {
        printf("underflow");
    } else {
        top--;
        return (s[top + 1]);
    }
    return '\0';
}

void pushsp(int value) {
    if (topsp >= size - 1) {
        printf("overflow");
        exit(1);
    } else {
        sp[++topsp] = value;
    }
}

int popsp() {
    if (topsp == -1) {
        printf("underflow");
        exit(1);
    }
    return sp[topsp--];
}

int ISP(char c) {
    if (c == '+' || c == '-')
        return 2;
    else if (c == '*' || c == '/')
        return 4;
    else if (c == '^')
        return 5;
    else if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return 8;
    else if (c == '(')
        return 0;
    else
        return -1;
}

int ICP(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 3;
    else if (c == '^')
        return 6;
    else if ((c >= 65 && c <= 90) || (c >= 97))
        return 7;
    else if (c == '(')
        return 9;
    else if (c == ')')
        return 0;
    else
        return -1;
}

void main() {
    char E[50], P[50], item, x, op;
    int i = 0, num = 0;
    int j = 0, val, op1, op2, res;

    printf("Enter infix expression: ");
    gets(E);

    E[strlen(E)] = ')';
    push('(');

    printf("The postfix expression is: ");
    while (top >= 0) {
        item = E[i++];
        x = pop();

        if ((item >= 65 && item <= 90) || (item >= 97 && item <= 122)) {
            printf("%c", item);
            push(x);
        } else if (item == ')') {
            while (x != '(') {
                printf("%c", x);
                x = pop();
            }
        } else if (ICP(item) != -1 && ISP(x) >= ICP(item)) {
            while (ISP(x) >= ICP(item)) {
                printf("%c", x);
                x = pop();
            }
            push(x);
            push(item);
        } else if (ICP(item) != -1 && ISP(x) < ICP(item)) {
            push(x);
            push(item);
        } else {
            printf("%c is invalid symbol", item);
            exit(1);
        }
    }

    printf("\nEnter the postfix evaluation expression, for multi-digit numbers, enclose them in parentheses: ");
    gets(P);
    P[strlen(P)] = '#';
 
    while (P[j] != '#') {
        item = P[j];
        if (isdigit(item)) {
            val = item - 48;
            pushsp(val);
        } else if (item == '(') {  
            item = P[++j];
            num = 0;
            while (item != ')') {
                if (isdigit(item)) {
                    val = item - 48;
                    num = num * 10 + val;
                } else {
                    printf("Invalid operand");
                }
                item = P[++j];
            }
            pushsp(num);
        } else {
            op = item;
            op2 = popsp();
            op1 = popsp();

            switch (op) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': res = op1 / op2; break;
                case '^': res = (int)pow((double)op1, (double)op2); break;
                default: 
                    printf("Invalid operator");
                    exit(1);
            }
            pushsp(res);
        }
        j++;
    }

    printf("\nResult of the postfix expression is %d\n", popsp());
}