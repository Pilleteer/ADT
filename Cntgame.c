#include <stdio.h>
} node_t;

// Write your code here

int main(void) {
node_t *startNode;
int n,i;
char command;

startNode = NULL;
scanf("%d", &n);
for (i=0; i<n; i++) {
scanf(" %c", &command) ;
switch (command) {
case ‘A’:
startNode = append(startNode) ;
break;
case 'G':
get(startNode) ;
break;
case 'S':
show(startNode) ;
break;
case 'R':
startNode = reverse(startNode) ;
break;
case 'C':
startNode = cut(startNode) ;
break;
default:
break;

}

}
return 0;
}