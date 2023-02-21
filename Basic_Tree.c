#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node* firstchild;
  struct node* nextsibling;
  struct node* parent;
} node_t;
typedef node_t tree_t;

typedef struct node2 {
  int value;
  struct node2* next;
} stack_t;
typedef stack_t queue_t;
stack_t *push(stack_t* stnode,int val){
    stack_t *temp;
    temp=(stack_t *)malloc(sizeof(stack_t));
    temp->next=NULL;
    temp->next=stnode;
    temp->value=val;
    stnode=temp;
    //printf("%p",stnode);
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

queue_t *enqueue(queue_t *qnode,int val){
    queue_t *temp = (queue_t *)malloc(sizeof(queue_t));
    temp->value=val;
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
        printf("%d ", qnode->value);
    }else{
        printf("Queue is empty.\n");
        return qnode;
    }
    queue_t *temp=qnode->next;
    return temp;
}

tree_t *searchpos(tree_t *t,int val){
  if(t==NULL||t->value==val){
    return t;
  }
  tree_t *pos=searchpos(t->firstchild,val);
  if(pos!=NULL){
    return pos;
  }
  return searchpos(t->nextsibling,val);
}

int search(tree_t *t,int val){
  if(searchpos(t,val)->value==val){
    return 1;
  } else{
    return 0;
  }
}

tree_t *attach(tree_t *t,int parentval,int val){
  tree_t *child=(tree_t *)malloc(sizeof(tree_t));
  child->firstchild=NULL;
  child->nextsibling=NULL;
  child->value=val;
  if(parentval==-1){
    child->parent=NULL;
    return child;
  }
  tree_t *parpos=searchpos(t,parentval);
  child->parent=parpos;
  if(parpos->firstchild==NULL){
    parpos->firstchild=child;
  } else{
    tree_t *sibpos=parpos->firstchild;
    while(sibpos->nextsibling!=NULL){
      sibpos=sibpos->nextsibling;
    }
    sibpos->nextsibling=child;
    }
  return t;
}

tree_t *detach(tree_t *t,int val){
  tree_t *depos=searchpos(t,val);
  tree_t *temppos=depos->parent;
  if(depos->parent==NULL){
    free(depos);
    return NULL;
  } else{
    if(temppos->firstchild->value==val){
      temppos->firstchild=depos->nextsibling;
    } else{
      temppos=temppos->firstchild;
      while(temppos->nextsibling->value!=val){
        temppos=temppos->nextsibling;
      }
      temppos->nextsibling=depos->nextsibling;
    }
    free(depos);
  }
  return t;
}

int degree(tree_t *t,int node){
  tree_t *fndpos;
  int cnt=0;
  fndpos=searchpos(t,node)->firstchild;
  while(fndpos!=NULL){
    fndpos=fndpos->nextsibling;
    cnt+=1;
  }
  return cnt;
}

int is_root(tree_t *t,int val){
  tree_t *checkpos=searchpos(t,val);
  if(checkpos->parent==NULL){
    return 1;
  } else{
    return 0;
  }
}

int is_leaf(tree_t *t,int val){
  tree_t *checkpos=searchpos(t,val);
  if(checkpos->firstchild==NULL){
    return 1;
  } else{
    return 0;
  }
}

void siblings(tree_t *t,int val){
  tree_t *sibpos=searchpos(t,val)->parent;
  sibpos=sibpos->firstchild;
  while (sibpos!=NULL){
    if(sibpos->value==val){
      sibpos=sibpos->nextsibling;
      continue;
    }
    printf("%d", sibpos->value);
    sibpos=sibpos->nextsibling;
  }
}

int depth(tree_t *t,int val){
  tree_t *markpos=searchpos(t,val);
  int cnt=0;
  while(markpos->parent!=NULL){
    cnt+=1;
    markpos=markpos->parent;
  }
  return cnt;
}

void print_path(tree_t *t,int start,int end){
  tree_t *markpos=searchpos(t,end);
  stack_t *mustprint=NULL;
  while(1==1){
    mustprint=push(mustprint,markpos->value);
    markpos=markpos->parent;
    if(markpos->value==start){
      mustprint=push(mustprint,start);
      break;
    }
  }
  while(mustprint!=NULL){
    printf("%d ", mustprint->value);
    mustprint=pop(mustprint);
  }
}

int path_length(tree_t *t,int start,int end){
  tree_t *markpos=searchpos(t,end);
  int cnt=0;
  while(1==1){
    markpos=markpos->parent;
    cnt+=1;
    if(markpos->value==start){
      cnt+=1;
      break;
    }
  }
  return cnt;
}

void ancestor(tree_t *t,int val){
  tree_t *markpos=searchpos(t,val);
  stack_t *mustprint=NULL;
  while(markpos!=NULL){
    mustprint=push(mustprint,markpos->value);
    markpos=markpos->parent;
  }
  while(mustprint!=NULL){
    printf("%d ", mustprint->value);
    mustprint=pop(mustprint);
  }
}

void bfsqprocess(tree_t *t,queue_t *q){
  tree_t *tchild=searchpos(t,q->value);
  tchild=tchild->firstchild;
  q=dequeue(q);
  while(tchild!=NULL){
    q=enqueue(q,tchild->value);
    tchild=tchild->nextsibling;
  }
  if(q!=NULL){
    bfsqprocess(t,q);
  } else{
    printf("\n");
  }
}

void bfs(tree_t *t){
  queue_t *printq=NULL;
  printq=enqueue(printq,t->value);
  bfsqprocess(t,printq);
}

void descendant(tree_t *t,int val){
  tree_t *pos=searchpos(t,val);
  bfs(pos);
}

void dfsstprocess(tree_t *t,stack_t *s){
  tree_t *tchild=searchpos(t,s->value);
  stack_t *temp=NULL;
  tchild=tchild->firstchild;
  printf("%d ",s->value);
  s=pop(s);
  while(tchild!=NULL){
    temp=push(temp,tchild->value);
    tchild=tchild->nextsibling;
  }
  while(temp!=NULL){
    s=push(s,temp->value);
    temp=pop(temp);
  }
  if(s!=NULL){
    dfsstprocess(t,s);
  } else{
    printf("\n");
    }
}

void dfs(tree_t *t){
  stack_t *printst=NULL;
  printst=push(printst,t->value);
  dfsstprocess(t,printst);
}

void print_tprocess(tree_t *t,stack_t *s){
  tree_t *tchild=searchpos(t,s->value);
  stack_t *temp=NULL;
  int deep=depth(t,tchild->value);
  for(deep;deep>0;deep--){
    printf("    ");
  }
  tchild=tchild->firstchild;
  printf("%d\n",s->value);
  s=pop(s);
  while(tchild!=NULL){
    temp=push(temp,tchild->value);
    tchild=tchild->nextsibling;
  }
  while(temp!=NULL){
    s=push(s,temp->value);
    temp=pop(temp);
  }
  if(s!=NULL){
    print_tprocess(t,s);
  } else{
    printf("\n");
    }
}

void print_tree(tree_t *t){
  stack_t *print_t=NULL;
  print_t=push(print_t,t->value);
  print_tprocess(t,print_t);
}

int main(void) {
  tree_t *t = NULL;
  int n, i, command;
  int parent, child, node, start, end;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &command);
    switch(command) {
      case 1:
        scanf("%d %d", &parent, &child);
        t = attach(t, parent, child);
        break;
      case 2:
        scanf("%d", &node);
        t = detach(t, node);
        break;
      case 3:
        scanf("%d", &node);
        printf("%d\n", search(t, node));
        break;
      case 4:
        scanf("%d", &node);
        printf("%d\n", degree(t, node));
        break;
      case 5:
        scanf("%d", &node);
        printf("%d\n", is_root(t, node));
        break;
      case 6:
        scanf("%d", &node);
        printf("%d\n", is_leaf(t, node));
        break;
      case 7:
        scanf("%d", &node);
        siblings(t, node);
        break;
      case 8:
        scanf("%d", &node);
        printf("%d\n", depth(t, node));
        break;
      case 9:
        scanf("%d %d", &start, &end);
        print_path(t, start, end);
        break;
      case 10:
        scanf("%d %d", &start, &end);
        printf("%d\n", path_length(t, start, end));
        break;
      case 11:
        scanf("%d", &node);
        ancestor(t, node);
        break;
      case 12:
        scanf("%d", &node);
        descendant(t, node);
        break;
      case 13:
        bfs(t);
        break;
      case 14:
        dfs(t);
        break;
      case 15:
        print_tree(t);
        break;
    }
  }
  return 0;
}