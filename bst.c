#include <stdio.h>
#include<stdlib.h>
typedef struct nodetype
{
    struct nodetype *left;
    int info;
    struct nodetype *right;
}bst;
int main() {
   bst *root = NULL;
   int choice,item;
    void insertion(bst **root,int item);
   void preorder(bst *root);
  void postorder(bst *root);
  void inorder(bst *root);
  while(1)
  {
  printf(" enter your choice\n1. insertion\n2. preordertraversal\n3. postordertraversal\n4.inorder traveersal");
  scanf("%d",&choice);
 
  switch(choice)
  {
      case 1:
      printf("enter number to insert");
      scanf("%d",&item);
      insertion( &root, item);
      break;
      case 2:
      preorder(root);
      break;
      case 3:
      postorder(root);
      break;
      case 4:
      inorder(root );
      break;
      default:
      exit(0);
  }
  }
  return 0;
}
  void insertion(bst **root,int item)
  {
      bst *loc;
      bst *parent=NULL;
      bst *ptr;
      ptr=(bst*)malloc(sizeof(bst));
      ptr->info=item;
      ptr->right=ptr->left=NULL;
      if(*root==NULL)
      {
          *root=ptr;
      }
      else
      {
          loc=*root;
          while(loc!=NULL)
          {
              parent=loc;
              if(item>loc->info)
              {
                  loc=loc->right;
              }
              else
              loc=loc->left;
          }
          if(item>parent->info)
          {
              parent->right=ptr;
          }
          else
          parent->left=ptr;
      }
      
  }
   void preorder(bst *root)
   {
       if(root!=NULL)
       {
           printf("%d ",root->info);
           preorder(root->left);
           preorder( root->right);
           
       }
       
   }
  void postorder(bst *root)
  {
      if(root!=NULL)
       {
          
           postorder( root->left);
           postorder( root->right);
            printf("%d ",root->info);
           
       }
  }
  void inorder(bst *root)
  {
      if(root!=NULL)
       {
           
           inorder(root->left);
           printf("%d ",root->info);
           inorder( root->right);
           
       }
      
  }
