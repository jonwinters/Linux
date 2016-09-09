#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define STACKSIZE 20

typedef struct person {
	char fname[20];
	char lname[20];
	int id;
}Person;

typedef struct stack {
	Person persons[STACKSIZE];
	int top;
}Stack;

bool push(Person *p ,Stack *st) {
	if (st->top == STACKSIZE) {
		sprintf(stderr,"stack overflow!");
		return false;
	}
	st->top++;
	st->persons[s->top] = p;
}

bool pop(Person *get ,Stack *st) {
	if (st->top == 0) {
		sprintf(stderr,"stack is 
