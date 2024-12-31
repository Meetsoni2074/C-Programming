#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int item;
    struct node *left;
    struct node *right;
};

void inoredertraversal(struct node *root)
{
    if(root==NULL)return;
    inoredertraversal(root->left);
    printf("%d->",root->item);
    inoredertraversal(root->right);
}

void preoredertraversal(struct node *root)
{
    if(root==NULL)return;
    printf("%d->",root->item);
    preoredertraversal(root->left);
    preoredertraversal(root->right);
}

void postoredertraversal(struct node *root)
{
    if(root==NULL)return;
    postoredertraversal(root->left);
    postoredertraversal(root->right);
    printf("%d->",root->item);
}

struct node *cueatenode(value)
{
    struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));
    nn->item=value;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}

struct node *insertleft(struct node *root,int value)
{
    root->left->item=createnode(value);
    return root->left;
}

struct node *insertright(struct node *root,int value)
{
    root->right->item=createnode(value);
    return root->right;
}

int main()
{
    struct node *root;
	root->item=createnode(1);
    insertleft(root,12);
    insertright(root,9);

    insertleft(root,5);
    insertright(root,6);
    printf("\ninorder traversal\n");
    inoredertraversal(root);

    printf("\npreorder traversal\n");
    preoredertraversal(root);

    printf("\npostorder traversal\n");
    postoredertraversal(root);
}