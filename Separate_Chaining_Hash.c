#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef struct item {
  char *text;
  struct item *next;
} item_t;

typedef struct hash {
  item_t **table;
  int size;
  int hash_key;
} hash_t;

item_t **init_hashitem(int size) {
  item_t **it = (item_t **)malloc(sizeof(item_t *) * size);
  for (int i = 0; i < size; i++) {
    it[i] = NULL;
  }
  return it;
}
hash_t *init_hashtable(int m, int hk) {
  hash_t *h = (hash_t *)malloc(sizeof(hash_t));
  h->table = init_hashitem(m);
  h->hash_key = hk;
  h->size = m;
  return h;
}

unsigned int findfn(int hash_key, int size, char *str) {
  if (size == 1) {
    return str[0];
  } else {
    return hash_key * (findfn(hash_key, size - 1, str)) + str[size - 1];
  }
}
int hash(unsigned int fn, int size) { return fn % (size); }

void printitem(item_t *it) {
  item_t *temp = it;
  while (temp != NULL) {
    printf("%s ", temp->text);
    temp = temp->next;
  }
  printf("\n");
}
void printhash(hash_t *h) {
  printf("startprinthash");
  for (int i = 0; i < h->size; i++) {
    printitem(h->table[i]);
  }
  printf("end\n");
}

void insert(hash_t *h, char *str) {
  unsigned int pos = hash(findfn(h->hash_key, strlen(str), str), h->size);
  char *newstr = NULL;
  newstr = (char *)malloc(sizeof(char) * TEXTSIZE);
  strcpy(newstr, str);
  item_t *newit = (item_t *)malloc(sizeof(item_t));
  newit->text = newstr;
  if (h->table[pos] == NULL) {
    newit->next = NULL;
    h->table[pos] = newit;
  } else if (h->table[pos] != NULL) {
    newit->next = h->table[pos];
    h->table[pos] = newit;
  }
  // printhash(h);
}

int comparestr(char *str1, char *str2) {
  int a = strlen(str1), b = strlen(str2);
  if (strlen(str1) != strlen(str2)) {
    return 1;
  } else {
    for (int i = 0; i < strlen(str1); i++) {
      if (str1[i] != str2[i]) {
        return 1;
      }
    }
  }
  return 0;
}
int search(hash_t *h, char *str) {
  // printhash(h);
  int pos = hash(findfn(h->hash_key, strlen(str), str), h->size);
  item_t *findtext = h->table[pos];
  // printhash(h);
  while (findtext != NULL) {
    if (comparestr(findtext->text, str) == 0) {
      return pos;
    } else {
      findtext = findtext->next;
    }
  }
  return -1;
}
int main(void) {
  hash_t *hashtable = NULL;
  char *text = NULL;
  int m, n, i, hash_key;
  int command;

  scanf("%d %d %d", &m, &n, &hash_key);
  hashtable = init_hashtable(m, hash_key);
  text = (char *)malloc(sizeof(char) * TEXTSIZE);

  for (i = 0; i < n; i++) {
    scanf("%d %s", &command, text);
    switch (command) {
    case 1:
      insert(hashtable, text);
      break;
    case 2:
      printf("%d\n", search(hashtable, text));
      break;
    }
  }
  return 0;
} /*
 13 10 19
 1 qwert
 1 asdf
 1 zklwo
 1 a
 2 qwert
 2 qwerty
 2 a
 2 asdf
 2 omg
 2 abcd

 211 20 93
 1 abcd
 1 abdc
 1 afnc
 1 oog
 1 ozg
 1 obg
 1 obp
 1 fjdlo
 1 auyun
 1 adzlr
 2 abcd
 2 abdc
 2 afnc
 2 oog
 2 ozg
 2 obg
 2 obp
 2 fjdlo
 2 auyun
 2 adzlr

 31 14 19
 1 mhewrv
 1 rkrfni
 1 wtabik
 1 ibpffi
 1 hwrthu
 1 mcpsnn
 1 xmyprx
 2 mhewrv
 2 rkrfni
 2 wtabik
 2 ibpffi
 2 hwrthu
 2 mcpsnn
 2 xmyprx
 */