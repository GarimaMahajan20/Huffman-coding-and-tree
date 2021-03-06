
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
struct bstnode
{
    struct bstnode *lc;
    int data;
    struct bstnode *rc;

};
struct sllnode
{
    struct bstnode *data;
    struct sllnode *next;
};
void enque(struct sllnode **f, struct sllnode **r,struct bstnode *data,int *z);
int deque(struct sllnode **f, struct sllnode **r,struct bstnode **fdata,int *z);
int isempty(struct sllnode *front);
void preorder(struct bstnode *root);
void disp(struct bstnode *root,int a[],int x);
void rtl(struct bstnode*root,int a[],int x);

int main(void)
{
    struct sllnode * front=NULL;
    struct sllnode * i=NULL;
    struct sllnode *rear =NULL;
    struct bstnode *root=NULL;
    struct bstnode *n1=NULL;
    struct bstnode *n2=NULL;
    struct bstnode *n3=NULL;
    int n =0;
    int data =0;
    int z=0;
    int *a=NULL;
    int x=0;

    printf("Enter no of nodes:\n");
    scanf("%d",&n);
    a=(int*)calloc(sizeof(int),n);
    while(n!=0)
    {
        printf("Enter data:\n");
        scanf("%d",&data);
        root=(struct bstnode *)calloc(sizeof(struct bstnode),1);
        root->data=data;
        enque(&front,&rear,root,&z);
        n--;
    }
    printf("Huffman codes are:\n");
    while(z!=1)  //condition
    {
        deque(&front,&rear,&n1,&z);
        deque(&front,&rear,&n2,&z);
        n3=(struct bstnode*)calloc (sizeof(struct bstnode),1);
        n3->lc=n1;
        n3->rc=n2;
        n3->data=n1->data+n2->data;
        enque(&front,&rear,n3,&z);
    }
    deque(&front,&rear,&root,&z);
   
    rtl(root,a,x);
   
    printf("Preorder traversal is:");
    preorder(root);

    return 0;
}
void enque(struct sllnode **f, struct sllnode **r,struct bstnode *data,int *z)
{
    struct sllnode *front = NULL;
    struct sllnode *rear = NULL;
    struct sllnode *node=NULL;
    struct sllnode *i =NULL;
    struct sllnode *j =NULL;

    front=*f;
    rear=*r;

    node = (struct sllnode *)calloc(sizeof(struct sllnode),1);
    node->data=data;
    if(front==NULL)
    {
        front=node;
        rear=node;
    }
    else
    {
        if(node->data->data<front->data->data)
        {
            node->next =front;
            front=node;
        }
        else
        {
            i = front;
            while (i->next!=NULL &&
                   i->next->data->data < node->data->data)
            {
                i = i->next;
            }
            node->next = i->next;
            i->next = node;

        }
    }

    *z=*z+1;

    *r=rear;
    *f=front;

}
int deque(struct sllnode **f, struct sllnode **r,struct bstnode **fdata,int *z)
{
    struct sllnode *dnode =NULL;
    struct sllnode *rear=NULL;
    struct sllnode *front =NULL;
    struct bstnode *data=NULL;
    int x=0;
    front =*f;
    rear=*r;
    data=*fdata;
    if(front==NULL)
    {
        x=1;
    }
    else
    {
        x=0;
        dnode=front;
        front =front->next;
        dnode->next=NULL;
        data=dnode->data;
        free(dnode);
        dnode=NULL;
        *z=*z-1;
    }
    *r=rear;
    *f=front;
    *fdata=data;
    return x;
}
int isempty(struct sllnode *front)
{
    int x=0;
    if(front ==NULL)
    {
        x=1;
    }
    else
    {
        x=0;
    }
    return x;
}
void preorder(struct bstnode *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->lc);
        preorder(root->rc);

    }
}
void rtl(struct bstnode*root,int a[],int x)
{
    if(root!=NULL)
    {
        if(root->lc==NULL&&root->rc==NULL)
        {
            disp(root,a,x);
        }
        else
        {
            if(root->lc!=NULL)
            {
                a[x]=0;
                x++;
                rtl(root->lc,a,x);
               
            }
            if(root->rc!=NULL)
            {
                x--;
                a[x]=1;
                x++;
                rtl(root->rc,a,x);
            }
        }
    }

}
void disp(struct bstnode *root,int a[],int x)
{
    int i =0;
    printf("%d: \t",root->data);
    for(i=0;i<x;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
