#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node_t; 

typedef node_t stack_t;
stack_t *push(stack_t* stnode,int val){
    stack_t *temp;
    temp=(stack_t *)malloc(sizeof(stack_t));
    temp->next=NULL;
    temp->next=stnode;
    temp->data=val;
    stnode=temp;
    //printf("%p",stnode);
    return stnode;
}
void top(stack_t* stnode){
    if(stnode==NULL){
        printf("Stack is empty.\n");
    }else {
        printf("%d\n", stnode->data);
        }
}
stack_t *pop(stack_t* stnode){
    if(stnode==NULL){
        return stnode;
    }
    stack_t *temp;
    temp=stnode->next;
    return temp;
}
void empty(stack_t *stnode){
    if(stnode==NULL){
        printf("Stack is empty.\n");
    }
    else{
        printf("Stack is not empty.\n");
    }
}
void size(stack_t *stnode){
    int count=0;
    stack_t *temp=stnode;
    while(temp!=NULL){
        count+=1;
        temp=temp->next;
    }
    printf("%d\n",count);
}
int main(void){
    stack_t *s=NULL;
    int n,i,command,value;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d", &command);
        switch (command){
        case 1:
            scanf("%d", &value);
            s=push(s,value);
            break;
        case 2:
            top(s);
            break;
        case 3:
            s=pop(s);
            break;
        case 4:
            empty(s);
            break;
        case 5:
            size(s);
            break;
        }
    }
}