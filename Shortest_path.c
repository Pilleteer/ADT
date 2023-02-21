#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int weight;
  int nodenum;
  struct node *next;
} node_t;
typedef node_t queue_t;

typedef struct heap {
  node_t **adjalist;
  int last_index;
} heap_t;

node_t **init_adjalist(int size) {
  node_t **heaplist = (node_t **)malloc(sizeof(node_t *) * (size + 1));
  for (int i = 0; i < (size + 1); i++) {
    heaplist[i] = NULL;
  }
  return heaplist;
}
heap_t *init_heap(int size) {
  heap_t *graph = (heap_t *)malloc(sizeof(heap_t));
  graph->adjalist = init_adjalist(size);
  graph->last_index = size;
  return graph;
}
int *init_passed(int size) {
  int *pass = (int *)malloc(sizeof(int) * (size + 1));
  for (int i = 0; i < size + 1; i++) {
    pass[i] = 0;
  }
  return pass;
}

heap_t *getedge(heap_t *g, int u, int v, int w) {
  node_t *tempu = (node_t *)malloc(sizeof(node_t));
  node_t *tempv = (node_t *)malloc(sizeof(node_t));
  // get u edge
  tempu->nodenum = v;
  tempu->weight = w;
  tempu->next = NULL;
  tempv->nodenum = u;
  tempv->weight = w;
  tempv->next = NULL;
  if (g->adjalist[u] == NULL) {
    g->adjalist[u] = tempu;
  } else {
    node_t *fndulast = g->adjalist[u];
    while (fndulast->next != NULL) {
      fndulast = fndulast->next;
    }
    fndulast->next = tempu;
  }
  // get v edge
  if (g->adjalist[v] == NULL) {
    g->adjalist[v] = tempv;
  } else {
    node_t *fndvlast = g->adjalist[v];
    while (fndvlast->next != NULL) {
      fndvlast = fndvlast->next;
    }
    fndvlast->next = tempv;
  }
  return g;
}

int *copyarr(int *arr, int size) {
  int *new = (int *)malloc(sizeof(int) * (size + 1));
  for (int i = 0; i < size + 1; i++) {
    new[i] = arr[i];
  }
  return new;
}
int allpath(heap_t *g, int current, int curw, int target) {
  node_t *temp = g->adjalist[current];
  while (temp != NULL) {
    if (temp->nodenum == target) {
      return curw + temp->weight;
    }
    temp = temp->next;
  }
  return -1;
}
long int shortpath(heap_t *g, int *passed, long int ans, int current, int curw,
                   int target) {
  int iffound = allpath(g, current, curw, target);
  if (iffound != -1 && ans > iffound) {
    ans = iffound;
  }
  int compare;
  node_t *temp = g->adjalist[current];
  // int *new=copyarr(passed,g->last_index);
  passed[current] += 1;
  int *newpassed;
  while (temp != NULL && current != target) {
    newpassed = copyarr(passed, g->last_index);
    if (passed[temp->nodenum] == 0) {
      // new[temp->nodenum]+=1;
      compare = shortpath(g, newpassed, ans, temp->nodenum, curw + temp->weight,
                          target);
      if (ans > compare) {
        ans = compare;
      }
    }
    temp = temp->next;
  }
  return ans;
}
void pringraph(heap_t *g) {
  node_t *temp;
  for (int i = 0; i < g->last_index; i++) {
    temp = g->adjalist[i];
    while (temp != NULL) {
      printf("%d %d ", i, temp->nodenum);
      temp = temp->next;
    }
    printf("\n");
  }
}

void main() {
  int i, n, m, p, u, v, w, s, t;
  int *passed = NULL;
  long int ans;
  heap_t *graph = NULL;
  scanf("%d %d %d", &n, &m, &p);
  graph = init_heap(n);
  for (i = 0; i < m; i++) {
    scanf("%d %d %d", &u, &v, &w);
    graph = getedge(graph, u, v, w);
  }
  // pringraph(graph);
  for (int j = 0; j < p; j++) {
    passed = init_passed(n);
    scanf("%d %d", &s, &t);
    ans = shortpath(graph, passed, 10000000, s, 0, t);
    if (ans == 10000000) {
      ans = -1;
    }
    if (s == t) {
      ans = 0;
    }
    printf("%ld\n", ans);
  }
}