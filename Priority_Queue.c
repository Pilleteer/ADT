#include<stdio.h>
#include<stdlib.h>

typedef struct heap {
    int *data;
    int last_index;
} heap_t;

heap_t *init_heap(int val){
    heap_t *h=NULL;
    h=(heap_t *)malloc(sizeof(heap_t));
    h->data=(int *)malloc(sizeof(int)*(val+1));
    h->last_index=0;
    return h;
}

void insert(heap_t *h,int val){
    int temp;
    h->last_index+=1;
    h->data[h->last_index]=val;
    int sortprog=h->last_index;
    //printf("%d %d %d\n",h->data[sortprog/2],h->data[sortprog],sortprog/2);
    while(h->data[sortprog/2]<h->data[sortprog]&&sortprog>1){
        temp=h->data[(sortprog/2)];
        h->data[(sortprog/2)]=h->data[sortprog];
        h->data[sortprog]=temp;
        sortprog/=2;
    }
}

void delete_max(heap_t *h){
    int temp;
    h->data[1]=h->data[h->last_index];
    h->last_index-=1;
    int sortprog=1,progcase,a,b;
    while(1){
        if(h->data[sortprog]<h->data[sortprog*2]||h->data[sortprog]<h->data[sortprog*2+1]){
            a=h->data[sortprog*2];
            if(sortprog*2+1<=h->last_index){
                b=h->data[sortprog*2+1];
            } else{
                b=0;
            }
        } else{
            break;
        }
        if(a>b){
            progcase=1;
        } else if(b>a){
            progcase=2;
        }
        switch (progcase) {
            case 1:
                temp=h->data[sortprog];
                h->data[sortprog]=h->data[sortprog*2];
                h->data[sortprog*2]=temp;
                sortprog=sortprog*2;
                break;
            case 2:
                temp=h->data[sortprog];
                h->data[sortprog]=h->data[(sortprog*2)+1];
                h->data[(sortprog*2)+1]=temp;
                sortprog=(sortprog*2)+1;
                break;
        }
    }
}

int find_max(heap_t *h){
    if(h->last_index<1){
        return -1;
    }
    return h->data[1];
}

void update_key(heap_t *h,int ok,int nk){
    int indexcnt=1,temp;
    while(h->data[indexcnt]!=ok){
        indexcnt+=1;
    }
    h->data[indexcnt]=nk;
    int sortprog=indexcnt;
    while(h->data[sortprog/2]<h->data[sortprog]&&sortprog>1){
        temp=h->data[(sortprog/2)];
        h->data[(sortprog/2)]=h->data[sortprog];
        h->data[sortprog]=temp;
        sortprog/=2;
    }
}

void bfs(heap_t *h){
    for(int i=1;i<=h->last_index;i++){
        printf("%d ",h->data[i]);
    }
    printf("\n");
}
int main() {
    heap_t *max_heap=NULL;
    int m, n, i;
    int command, data;
    int old_key, new_key;

    scanf("%d %d",&m ,&n);
    max_heap = init_heap(m);
    for (i=0; i<n; i++){
        scanf("%d", &command);
        switch (command) {
        case 1:
            scanf("%d", &data);
            insert(max_heap, data);
            break;
        case 2:
            delete_max(max_heap);
            break;
        case 3:
            printf("%d\n", find_max(max_heap));
            break;
        case 4:
            scanf("%d %d", &old_key, &new_key);
            update_key(max_heap, old_key, new_key);
            break;
        case 5:
            bfs(max_heap);
            break;
        }
    }
    return 0;
}