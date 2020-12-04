#include <stdio.h>
#include <stdlib.h>

struct Node {
  int n;
  struct Node* next;
};

struct Node* s = NULL; 

void printList() {
  printf("Output: ");
  struct Node* c = s;
  while(c != NULL){
    printf("%d, ", c->n);
    c = c->next;
  }
  printf("\n\n");
}

void addNode(){
  printf("Enter number: \nMy number = ");
  int i = 0;
  scanf("%d", &i);
  printf("\n");

  if(s == NULL){
    s = malloc(sizeof(struct Node));
     if(s == NULL){
      printf("\nCould not allocate memory.\n");
      return;
    }
    s->n = i;
    s->next = NULL;
  } else {
    struct Node* c = s;
    while(c->next != NULL){
      c = c->next;
	}
    c->next = malloc(sizeof(struct Node));
    if(s == NULL){
      printf("\nCould not allocate memory.\n");
      return;
    }
    c->next->n = i;
    c->next->next = NULL;
  }
}

void removeNode() {
  printf("Enter number: \nMy number = ");
  int i = 0;
  scanf("%d", &i);
  printf("\n");

  if(s != NULL) {
    if(s->n == i){
      struct Node* h = s->next;
      free(s);
      s = h;
    } else {
      struct Node* c = s;
      while(c->next != NULL){
        if(c->next->n == i){
          struct Node* h1 = c;
          struct Node* h2 = c->next;
          h1->next = h2->next;
          free(h2);
          return;
        }
        c = c->next;
      }
    }
  }
}

int main(void) {
  int method = 0;
  do {
    printf("1 - Print list\n2 - Add node\n3 - Remove node\nMethod = ");
    scanf("%d", &method);
    printf("\n");
    switch(method) {
      case 1:
        printList();
        break;
      case 2:
        addNode();
        break;
      case 3:
        removeNode();
        break;
      default:
        break;
    }
    method = 0;
  } while(method == 0);
  
  return 0;
}