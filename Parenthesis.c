#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    char data;
    struct node *next;
} stack_t;
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
int isempty(stack_t *stnode){
    if(stnode==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int main(void){
    int n,i;
    stack_t *s=NULL;
    scanf("%d",&n);
    char a;
    for(i=0;i<n+1;i++){
        scanf("%c",&a);
        if(a=='('||a=='['||a=='{'){
            s=push(s,a);
        }else if(a==')'&&isempty(s)==0&&(s->data)+1==a){
            s=pop(s);
        }else if(a==']'||a=='}'){
            if(isempty(s)==0&&(s->data)+2==a){
                s=pop(s);
            }
        }
    }
    printf("%d",isempty(s));
}