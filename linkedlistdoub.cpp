//Alexander Bradley - 2702332753 - LF01
#include<stdio.h>
#include<stdlib.h>

struct data{
	int age;
	struct data *next;
	struct data *prev;
};

struct data *head = NULL;
struct data *tail = NULL;

struct data *create_node(int age){
	struct data *node = (struct data*)malloc(sizeof(struct data));
	node->next = NULL;
	node->prev = NULL;
	node->age = age;

	return node;
}

void push_head(int age){
	struct data *node = create_node(age);
	node->next = head;
	head->prev = node;
	head = node;
}

void push_tail(int age){
	struct data *node = create_node(age);
	node->prev = tail;
	tail->next = node;

	tail = node;
}

void pushIndex(int age, int index) {
    if (index <= 0) {
        printf("Invalid index\n");
        return;
    }

    if (index == 1) {
        push_head(age);
        return;
    }

    struct data *temp = head;
    struct data *node = create_node(age);
    int count = 1;

    while (temp != NULL && count < index - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Index out of range\n");
        return;
    }

    node->next = temp->next;
    if (temp->next != NULL)//no semicolon!!
        temp->next->prev = node;
    temp->next = node;
    node->prev = temp;

    if (node->next == NULL)
        tail = node;
}


void pop_head(){
	struct data *temp = head;
	head= head->next;
	head->prev = NULL;
	free(temp);
}

void pop_tail(){
	struct data *temp = tail;
	tail = tail->prev;
	tail->next=NULL;

	free(temp);
}

void pop_search(int age) {
    struct data *temp = head;

    while (temp != NULL && temp->age != age) {
        temp = temp->next;
    }

    if (temp != NULL) {
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;
        }

        free(temp);
    } else {
        printf("Data with age %d not found\n", age);
    }
}

void print_linked_list(){
	struct data *temp = head;
	int count = 1;
	while(temp!=NULL){

	printf("data ke %d: %d \n", count, temp->age);
	temp = temp->next;
	count++;
	}
}

int main(){
	head = create_node(2);
	tail = create_node(5);

	head->next = tail;
	tail->prev = head;

	push_head(1);
	push_tail(10);
    pushIndex(7, 5);

	pop_head();
	pop_tail();
    pop_search(7);

	print_linked_list();

}
