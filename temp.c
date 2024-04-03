#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data{
int age;
char name[100];
struct data *next;
struct data *prev;
};

struct data *head = NULL;
struct data *tail = NULL;

struct data *create_node(int age, char name[]){
struct data *node = (struct data*)malloc(sizeof(struct data));
node->next = NULL;
node->prev = NULL;
node->age = age;
strcpy(node->name, name);
return node;
};

void puh(int age, char name[]){
struct data *node = create_node(age, name);
node->next = head;
head->prev = node;
head = node;
}

void put(int age, char name[]){
struct data *node = create_node(age, name);
node->prev = tail;
tail->next = node;
tail = node;
}

void pushIndex(int age, char name[], int pos){
struct data *node = create_node(age, name);
struct data *temp = head;
int count = 1;
if(pos == 1){
    puh(age, name);
    return;
}
while(temp!=NULL && count<pos-1){
    temp = temp->next;
    count++;
}
node->next = temp->next;
if(temp->next!=NULL)
    temp->next->prev = node;
temp->next = node;
node->prev = temp;
if(node->next == NULL){
    tail = node;
}
}

void poh(){
struct data *temp = head;
head = head->next;
head->prev = NULL;
free(temp);
}

void pot(){
struct data *temp = tail;
tail = tail->prev;
tail->next = NULL;
free(temp);
}

void popin(int age, char name[]){
struct data *temp = head;
//while(temp!=NULL && temp->age!=age && strcpy(temp->name, name)!=0)
while(temp!=NULL && (temp->age!=age || strcmp(temp->name, name)!=0)){
    temp = temp->next;
}
if(temp!=NULL){
    if(temp->prev!=NULL){
        temp->prev->next = temp->next;
    }else{
        head = temp->next;
    }
    if(temp->next!=NULL){
        temp->next->prev = temp->prev;
    }else{
        tail = temp->prev;
    }
    free(temp);
}
}

void print(){
struct data *temp = head;
int count = 1;
while(temp!=NULL){
    printf("Data %d is: Name: %s, Age: %d\n", count, temp->name, temp->age);
    temp = temp->next;
    count++;
}
}


int main(){
head = create_node(19, "Alex");
tail = create_node(22, "Coop");
head->next = tail;
tail->prev = head;
puh(25, "Olive"); put(27, "Anna");
pushIndex(24, "Jamie", 3);

//poh(); pot();
popin(22, "Coop");
print();

}
