#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100 


typedef struct {
	int data[MAX];
	int top;
} Stack;

void initStack(Stack* s) {
	s->top = -1;
}

int isEmpty(Stack* s) {
	return s->top == -1;
}

void push(Stack* s, int value) {
	if (s->top < MAX - 1) {
		s->data[++(s->top)] = value;
	}
	else {
		printf("Stack Overflow\n");
		exit(1);
	}
}

int pop(Stack* s) {
	if (!isEmpty(s)) {
		return s->data[(s->top)--];
	}
	else {
		printf("Stack Underflow\n");
		exit(1);
	}
}

int peek(Stack* s) {
	if (!isEmpty(s)) {
		return s->data[s->top];
	}
	else {
		printf("Stack is empty\n");
		exit(1);
	}
}

int precedence(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return -1;
}
int evaluatePostfix(char* postfix) {
	Stack s;
	initStack(&s);

	for (int i = 0; postfix[i] != '\0'; i++) {
		char ch = postfix[i];

		if (isdigit(ch)) {
			push(&s, ch - '0');
		}
		else {
			int b = pop(&s);
			int a = pop(&s);
			int result;

			switch (ch) {
			case '+': result = a + b; break;
			case '-': result = a - b; break;
			case '*': result = a * b; break;
			case '/': result = a / b; break;
			default:
				printf("Error.\n");
				exit(1);
			}
			push(&s, result);
		}
	}
	return pop(&s);
}


int infixToPostfix(char* infix, char* postfix) {
	Stack s;
	initStack(&s);
	int j = 0;
	for (int i = 0; infix[i] != '\0'; i++) {
		char ch = infix[i];
		if (isalpha(ch) || isdigit(ch)) {
			postfix[j++] = ch;
		}
		else if (ch == '(') {
			push(&s, ch);
		}
		else if (ch == ')') {
			while (!isEmpty(&s) && peek(&s) != '(') {
				postfix[j++] = pop(&s);
			}
			pop(&s); 
		}
		else {
			while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
				postfix[j++] = pop(&s);
			}
			push(&s, ch);
		}
	}
	while (!isEmpty(&s)) {
		postfix[j++] = pop(&s);
	}
	postfix[j] = '\0';

	return evaluatePostfix(postfix);
}

int main(void) {
	char infix[MAX];
	char postfix[MAX];
	int result;

	printf("중위표기식 입력 : ");
	scanf("%s", infix);

	result = infixToPostfix(infix, postfix);

	printf("후위표기식 : %s\n", postfix);
	printf("후위표기식 계산 결과 : %d\n", result);

	return 0;
}