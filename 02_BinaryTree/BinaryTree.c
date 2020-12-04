#include <stdio.h>
#include <stdlib.h>



struct Leaf {
  int n;
  struct Leaf* left;
  struct Leaf* right;
};

struct Leaf* root = NULL;

int getInput(){
  printf("Enter number: \nMy number = ");
  int i = 0;
  scanf("%d", &i);
  printf("\n");
  return i;
}

void printTree(struct Leaf* start){
  if(start != NULL){
    printf("%d, ", start->n);
    printTree(start->left);
    printTree(start->right);
  }
}

void addLeaf(struct Leaf* start, int n){
  if(root == NULL){
    printf("%d, ", __LINE__);
    root = malloc(sizeof(struct Leaf));
    if(root == NULL){
      return;
    }
    root->n = n;
    root->left = NULL;
    root->right = NULL;
  } else {
    if(start != NULL){
      if(start->n != n){
        struct Leaf** temp = start->n > n ? &(start->left) : &(start->right);
        if(*temp == NULL){
          *temp = malloc(sizeof(struct Leaf));
          if(*temp == NULL)
            return;
          (*temp)->n = n;
          (*temp)->left = NULL;
          (*temp)->right = NULL;
        } else
          addLeaf(*temp, n);
      }
    }
  }
}

void removeLeafWithPrev(struct Leaf* prev, struct Leaf* cur, int n){
  // struct L** t = (*s).n > n ? &((*s).l) : &((*s).r);
  if((cur) != NULL){
    if((cur)->n == n){
      (prev)->left = (cur)->left;
      (prev)->right = (cur)->right;
      free(cur);
    } else {
      removeLeafWithPrev(cur, n < (cur->n) ? (cur->left) : (cur->right), n);
    }
  }
}

void removeLeaf(struct Leaf* cur, int n){
  if(cur != NULL){
    if(n < cur->n) {
      removeLeafWithPrev(cur, (cur->left), n);
    } else {
      removeLeafWithPrev(cur, (cur->right), n);
    }
  }
}

int main(void){
  int method = 0;
  addLeaf(root, 5);
  addLeaf(root, 1);
  addLeaf(root, 3);
  addLeaf(root, 4);
  addLeaf(root, 0);
  addLeaf(root, 2);
  do {
    printf("1 - Print tree\n2 - Add node\n3 - Remove node\nMethod = ");
    scanf("%d", &method);
    printf("\n");
    switch(method) {
      case 1:
        printf("\nOutput: ");
        printTree(root);
        printf("\n\n");
        break;
      case 2:
        addLeaf(root, getInput());
        break;
      case 3:
        removeLeaf(root, getInput());
        break;
      default:
        break;
    }
    method = 0;
  } while(method == 0);
  
  return 0;
  return EXIT_SUCCESS;
}