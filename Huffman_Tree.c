#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
  char *word;
  int freq;
  struct node *left;
  struct node *right;
} tree_t;
typedef struct heap {
  tree_t **t;
  int last_index;
} heap_t;

heap_t *init_heap(int val) {
  heap_t *h = NULL;
  h = (heap_t *)malloc(sizeof(heap_t));
  h->t = (tree_t **)malloc(sizeof(tree_t *) * (val + 1));
  h->last_index = 0;
  return h;
}

void tree_insert(heap_t *h, tree_t *newt) {
  tree_t *temp_t;
  h->last_index += 1;
  h->t[h->last_index] = newt;
  int sortprog = h->last_index;
  // printf("%d %d %d\n",h->data[sortprog/2],h->t[sortprog]->freq,sortprog/2);
  while (sortprog > 1 && h->t[sortprog / 2]->freq > h->t[sortprog]->freq) {
    temp_t = h->t[sortprog / 2];
    h->t[sortprog / 2] = h->t[sortprog];
    h->t[sortprog] = temp_t;
    sortprog /= 2;
  }
}

void insert(heap_t *h, int f, char *w) {
  tree_t *temp_t;
  h->last_index += 1;
  h->t[h->last_index] = (tree_t *)malloc(sizeof(tree_t));
  h->t[h->last_index]->freq = f;
  h->t[h->last_index]->word = w;
  h->t[h->last_index]->left = NULL;
  h->t[h->last_index]->right = NULL;
  int sortprog = h->last_index;
  // printf("%d %d %d\n",h->data[sortprog/2],h->t[sortprog]->freq,sortprog/2);
  while (sortprog > 1 && h->t[sortprog / 2]->freq > h->t[sortprog]->freq) {
    temp_t = h->t[sortprog / 2];
    h->t[sortprog / 2] = h->t[sortprog];
    h->t[sortprog] = temp_t;
    sortprog /= 2;
  }
}

void print_heap(heap_t *h) {
  for (int i = 1; i <= h->last_index; i++) {
    printf("%s %d ", h->t[i]->word, h->t[i]->freq);
  }
}

void delete_min(heap_t *h) {
  tree_t *temp_t;
  h->t[1] = h->t[h->last_index];
  h->last_index -= 1;
  int sortprog = 1, progcase, a, b;
  while (sortprog * 2 <= h->last_index) {
    if (h->t[sortprog]->freq >= h->t[sortprog * 2]->freq ||
        h->t[sortprog]->freq >= h->t[sortprog * 2 + 1]->freq) {
      a = h->t[sortprog * 2]->freq;
      if (sortprog * 2 + 1 <= h->last_index) {
        b = h->t[sortprog * 2 + 1]->freq;
      } else {
        b = 100001;
      }
    } else {
      // printf("enterbreak1");
      break;
    }
    if (b >= a) {
      progcase = 1;
    } else if (b < a) {
      progcase = 2;
    }
    switch (progcase) {
    case 1:
      temp_t = h->t[sortprog];
      h->t[sortprog] = h->t[sortprog * 2];
      h->t[sortprog * 2] = temp_t;
      sortprog = sortprog * 2;
      break;
    case 2:
      temp_t = h->t[sortprog];
      h->t[sortprog] = h->t[sortprog * 2 + 1];
      h->t[sortprog * 2 + 1] = temp_t;
      sortprog = (sortprog * 2) + 1;
      break;
    }
    print_heap(h);
    printf("\n");
  }
  printf(" end\n");
}

void make_tree(heap_t *h) {
  tree_t *fst = NULL, *scnd = NULL;
  while (h->last_index > 1) {
    tree_t *new_t = (tree_t *)malloc(sizeof(tree_t));
    fst = h->t[1];
    delete_min(h);
    scnd = h->t[1];
    delete_min(h);
    new_t->left = fst;
    new_t->right = scnd;
    new_t->freq = fst->freq + scnd->freq;
    new_t->word = "H"; //->Header
    tree_insert(h, new_t);
    print_heap(h);
    printf("ins \n");
  }
}

void dfs(tree_t *t, char *huffman) {
  if (t != NULL) {
    if (t->word != "H") {
      printf("%s: %s\n", t->word, huffman);
    }
    char lhuff[18], rhuff[18];
    strcpy(lhuff, huffman);
    strcpy(rhuff, huffman);
    strcat(lhuff, "0");
    strcat(rhuff, "1");
    dfs(t->left, lhuff);
    dfs(t->right, rhuff);
  }
}
int main() {
  heap_t *min_heap = NULL;
  int i, n, f;

  scanf("%d", &n);
  min_heap = init_heap(n);
  for (i = 0; i < n; i++) {
    char *s = (char *)malloc(sizeof(char) * 15);
    scanf("%s %d", s, &f);
    insert(min_heap, f, s);
  }
  print_heap(min_heap);
  printf("\n");
  make_tree(min_heap);
  dfs(min_heap->t[1], "");
  return 0;
}
/*
6
i 3
am 3
ok 1
a 1
boy 1
how 1
*/