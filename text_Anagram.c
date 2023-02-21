#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 50
typedef struct item {
  char *text;
  struct item *next;
} item_t;

typedef struct hash {
  item_t **table;
  int size;
} hash_t;

item_t **init_hashitem(int size) {
  item_t **it = (item_t **)malloc(sizeof(item_t *) * size);
  for (int i = 0; i < size; i++) {
    it[i] = NULL;
  }
  return it;
}
hash_t *init_hashtable(int m) {
  hash_t *h = (hash_t *)malloc(sizeof(hash_t));
  h->table = init_hashitem(m);
  h->size = m;
  return h;
}

unsigned int findfn(int size, char *str) {
  if (size == 1) {
    return str[0];
  } else {
    return str[size - 1] + (findfn(size - 1, str));
  }
}
int hash(unsigned int fn, int size) { return fn % (size); }

void insert_hash(hash_t *h, char *str) {
  unsigned int pos = hash(findfn(strlen(str), str), h->size);
  char *newstr = NULL;
  newstr = (char *)malloc(sizeof(char) * TEXTSIZE);
  strcpy(newstr, str);
  item_t *newit = (item_t *)malloc(sizeof(item_t));
  newit->text = newstr;
  if (h->table[pos] == NULL) {
    newit->next = NULL;
    h->table[pos] = newit;
  } else if (h->table[pos] != NULL) {
    newit->next = NULL;
    item_t *temp = h->table[pos];
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newit;
  }
  // printhash(h);
}

void swap(char *arr, int m, int n) {
  int temp = arr[m];
  arr[m] = arr[n];
  arr[n] = temp;
}
void insert(char *arr, int pos) {
  int i = pos;
  while (i >= 1 && arr[i] < arr[i - 1]) {
    swap(arr, i, i - 1);
    i -= 1;
  }
  if (arr[pos] < arr[pos - 1]) {
    insert(arr, pos);
  }
}
void insert_sort(char *arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    if (arr[i + 1] < arr[i]) {
      insert(arr, i + 1);
    }
  }
}

int check_ana(char *ana1, char *ana2) {
  char *a = (char *)malloc(sizeof(char) * TEXTSIZE);
  char *b = (char *)malloc(sizeof(char) * TEXTSIZE);
  strcpy(a, ana1);
  strcpy(b, ana2);
  if (strlen(a) != strlen(b)) {
    return 0;
  }
  insert_sort(a, strlen(a));
  insert_sort(b, strlen(b));
  for (int i = 0; i < strlen(a); i++) {
    if (a[i] != b[i]) {
      return 0;
    }
  }
  return 1;
}
void search(hash_t *h, char *str) {
  // printhash(h);
  int pos = hash(findfn(strlen(str), str), h->size);
  item_t *findtext = h->table[pos];
  // printhash(h);
  while (findtext != NULL) {
    if (check_ana(findtext->text, str) == 1) {
      printf("%s ", findtext->text);
    }
    findtext = findtext->next;
  }
  printf("\n");
}

void main() {
  int i, n, m;
  char *ana = (char *)malloc(sizeof(char) * TEXTSIZE);
  hash_t *hashtable = NULL;
  scanf("%d %d", &m, &n);
  hashtable = init_hashtable(m);
  for (i = 0; i < m; i++) {
    scanf("%s", ana);
    insert_hash(hashtable, ana);
  }
  for (int j = 0; j < n; j++) {
    scanf("%s", ana);
    search(hashtable, ana);
  }
}
/*
8 3
final
fnali
fnial
fianl
title
ttile
tilte
equal
fanil
reply
title

8 5
equal
tilte
porxy
stioc
sotic
prxoy
eauql
asybs
search
stoic
tilt
qual
proxy

4 4
fried
gainly
sadder
listen
fired
laying
dreads
silent
*/