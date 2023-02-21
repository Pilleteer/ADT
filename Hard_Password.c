#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    char data;
    struct node *next;
} stack_t;
typedef stack_t queue_t; 

queue_t *enqueue(queue_t *qnode,char val){
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
        //printf("%d\n", qnode->data);
    }else{
        return qnode;
    }
    queue_t *temp=qnode->next;
    return temp;
}
stack_t *push(stack_t* stnode,char val){
    stack_t *temp;
    temp=(stack_t *)malloc(sizeof(stack_t));
    temp->next=NULL;
    temp->next=stnode;
    temp->data=val;
    stnode=temp;
    return stnode;
}
stack_t *pop(stack_t* stnode){
    if(stnode==NULL){
        return stnode;
    }
    stack_t *temp;
    temp=stnode->next;
    return temp;
}
int checkparen(queue_t *qnode,stack_t *stnode,int ispass){
    while(qnode!=NULL&&stnode!=NULL&&qnode->data==stnode->data){
        stnode=pop(stnode);
        qnode=dequeue(qnode);
    }
    if(qnode==NULL&&stnode==NULL&&ispass==2){
        return 1;
    }else{
        return 0;
    }
}
int main(void){
    int i,tilx=0,pasxy;
    char a[10000];
    stack_t *s=NULL;
    queue_t *q=NULL;
    scanf("%s",&a);
    for(i=0;i<strlen(a);i++){
        if(a[i]=='x'){ //get stack when found 'x'
            tilx=i;
            pasxy+=1;
            break;
        }else{
            s=push(s,a[i]);
        }
    }
    for(i=tilx+1;i<strlen(a);i++){
        if(a[i]=='y'){ //get queue when found 
            pasxy+=1;
            if(i!=strlen(a)-1){
                pasxy=0;
            }
            break;
        }
        else{
            q=enqueue(q,a[i]);
        }
    }
    printf("%d", checkparen(q,s,pasxy));
}