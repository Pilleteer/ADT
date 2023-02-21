#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    float data;
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
int size(stack_t *stnode){
    int count=0;
    stack_t *temp=stnode;
    while(temp!=NULL){
        count+=1;
        temp=temp->next;
    }
    return count;
}
int main(void){
    int n,i;
    float temp;
    char a;
    stack_t *s=NULL;
    scanf("%d\n",&n);
    for(i=0;i<n+1;i++){
        scanf("%c",&a);
        if(a>='0'&&a<='9'){
            s=push(s,a-'0');
        }else if(s!=NULL&&size(s)>=2){
            temp=s->data;
            switch(a){
            case '+':
                s=pop(s);
                s->data+=temp;
                break;
            case '-':  
                s=pop(s);
                s->data-=temp;
                break;
            case '*':
                s=pop(s);
                s->data*=temp;
                break;
            case '/':
                s=pop(s);
                s->data/=temp;
                break;
            }
        }
    }
    printf("%.2f",s->data);
}