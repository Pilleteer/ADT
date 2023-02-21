#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node_t;
typedef node_t queue_t; 

queue_t *enqueue(queue_t *qnode,int val){
    queue_t *temp = (queue_t *)malloc(sizeof(queue_t));
    temp->data=val;
    temp->next=NULL;
    queue_t *fndlast=qnode;
    if(qnode==NULL){
        qnode=temp;
    }else{
        while(fndlast->next!=NULL){
            fndlast=fndlast->next;
        }
        fndlast->next=temp;
    }
    return qnode;
}
queue_t *dequeue(queue_t *qnode){
    if(qnode!=NULL){
        printf("%d\n", qnode->data);
    }else{
        printf("Queue is empty.\n");
        return qnode;
    }
    queue_t *temp=qnode->next;
    return temp;
}
void show(queue_t *qnode){
    node_t *temp=qnode;
    if(qnode==NULL){
        printf("Queue is empty.");
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void empty(queue_t *qnode){
    if(qnode==NULL){
        printf("Queue is empty.\n");
    }else{
        printf("Queue is not empty.\n");
    }
}
void size(queue_t *qnode){
    int count=0;
    node_t *temp=qnode;
    while(temp!=NULL){
        count+=1;
        temp=temp->next;
    }
    printf("%d\n",count);
}
int main(void){
    queue_t *q=NULL;
    int n,i,command,value;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d", &command);
        switch (command){
        case 1:
            scanf("%d", &value);
            q=enqueue(q,value);
            break;
        case 2:
            q=dequeue(q);
            break;
        case 3:
            show(q);
            break;
        case 4:
            empty(q);
            break;
        case 5:
            size(q);
            break;
        }
    }
}