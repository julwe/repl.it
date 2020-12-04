#include <stdio.h>
#include <stdlib.h>

struct L {
  int n;
  struct L* l;
  struct L* r;
};

struct L* r = NULL;

int getInput(){
  printf("Enter number: \nMy number = ");
  int i = 0;
  scanf("%d", &i);
  printf("\n");
  return i;
}

void printTree(struct L* s){
  if(s != NULL){
    printf("%d, ", s->n);
    printTree(s->l);
    printTree(s->r);
  }
}

void aL(struct L* s, int n){
  if(r == NULL){
    printf("%d, ", __LINE__);
    r = malloc(sizeof(struct L));
    if(r == NULL){
      return;
    }
    r->n = n;
    r->l = NULL;
    r->r = NULL;
  } else {
    if(s != NULL){
      if((*s).n != n){
        struct L** t = (*s).n > n ? &((*s).l) : &((*s).r);
        if(*t == NULL){
          *t = malloc(sizeof(struct L));
          if(*t == NULL)
            return;
          (**t).n = n;
          (**t).l = NULL;
          (**t).r = NULL;
        } else
          aL(*t, n);
      }
    }
  }
}

void rL(struct L* s, int n){
  
}

int main(void){
  int method = 0;
  do {
    printf("1 - Print tree\n2 - a node\n3 - r node\nMethod = ");
    scanf("%d", &method);
    printf("\n");
    switch(method) {
      case 1:
        printf("\nOutput: ");
        printTree(r);
        printf("\n\n");
        break;
      case 2:
        aL(r, getInput());
        break;
      case 3:
        rL(r, getInput());
        break;
      default:
        break;
    }
    method = 0;
  } while(method == 0);
  
  return 0;
  return EXIT_SUCCESS;
}