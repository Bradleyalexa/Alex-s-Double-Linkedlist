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
if(head==NULL){
    head = node;
    tail = node;
}else{
node->next = head;
head->prev = node;
head = node;
}
}

void put(int age, char name[]){
struct data *node = create_node(age, name);
if(tail == NULL){
    tail = node;
    head = node;
}else{
node->prev = tail;
tail->next = node;
tail = node;
}
}

void pushIndex(int age, char name[], int pos){
struct data *node = create_node(age, name);
struct data *temp = head;
int count = 1;
if(pos == 1){
    puh(age, name);
    return;
}
while(count<pos-1 && temp!=NULL){
    count++;
    temp = temp->next;
}

node->next = temp->next;
node->prev = temp;
if(temp->next!=NULL){
    temp->next->prev = node;
}
temp->next = node;
}

void poh(){
struct data *temp = head;
head = head->next;
head->prev = NULL;
free(temp);
}

void pot(){
struct data *del = tail;
tail = tail->prev;
tail->next = NULL;
free(del);
}

void popin(int age, char name[]){
struct data *temp = head;
while(temp!=NULL && (temp->age!=age || strcmp(temp->name, name)!=0)){
    temp = temp->next;
}
if(temp!=NULL){
    if(temp->prev!=NULL){
        temp->prev->next = temp->next;
    }else{
        head = temp->next;
    }if(temp->next!=NULL){
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
    //reverse(temp->name);
    printf("Data %d, name: %s - age: %d\n", count, temp->name, temp->age);
    temp = temp->next;
    count++;
}
}

void reverse(char *str){
int length = strlen(str);
for(int i=0;i<length/2;i++){
    char x = str[i];
    str[i] = str[length-i-1];
    str[length-i-1] = x;
}
}

int main(){
head = create_node(29, "Hae-in");
tail = create_node(35, "Hyun-woo");
head->next = tail;
tail->prev = head;
puh(5, "Soo-bin");
put(75, "Man-dae");
pushIndex(24, "Soo-cheol", 5);
//poh(); pot();
//popin(35, "Hyun-woo");
print();
}
