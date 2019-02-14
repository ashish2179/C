#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <assert.h>

//node structure in the list
struct node
{
    int data;
    struct node *next;
};

//insert at beginning of the list
void insertatfirst(struct node** href,int data)
{
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=*href;
    *href=newnode;
}

//insert after given node in the list
void insertafter(struct node* prevnode,int data)
{
    if(prevnode==NULL)
    {
        printf("List is empty");
        return;
    }
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=prevnode->next;
    prevnode->next=newnode;
}

//insert at the end of the list
void insertatlast(struct node** href,int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;

    struct node* last = *href;

    if(href==NULL)
    {
        *href=newnode;
        return;
    }

    while(last->next!=NULL)
        last=last->next;

    last->next=newnode;
    return;
}

//insert after given key in the list
void insertafterkey(struct node** href,int data,int after)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;

    if(href==NULL)
    {
        printf("List is empty");
        return;
    }
     struct node* tmp=*href;
     while(tmp->data!=after)
        tmp=tmp->next;
     newnode->next=tmp->next;
     tmp->next=newnode;
     return;
}

//delete a given key node in the list
void deletekeynode(struct node** href,int key)
{
    struct node* tmp=*href,*prev;

    while(tmp!=NULL && tmp->data==key)
    {
        *href=tmp->next;
        free(tmp);
        return;
    }

    while(tmp!=NULL && tmp->data!=key)
    {
        prev=tmp;
        tmp=tmp->next;
    }

    if(tmp==NULL)
        return;

    prev->next=tmp->next;

    free(tmp);

}

//delete after given position in list
void deleteatpos(struct node** href,int pos)
{
    if(*href==NULL)
    {
        printf("List is empty");
        return;
    }

    struct node* tmp=*href;

    if(pos==0)
    {
        *href=tmp->next;
        free(tmp);
        return;
    }
    int i;
    for(i=0;tmp!=NULL && i<pos-1;i++)
        tmp=tmp->next;

    if(tmp==NULL || tmp->next==NULL)
        return;

    struct node* next=tmp->next->next;

    free(tmp->next);
    tmp->next=next;
}

//Delete a list
void deletelist(struct node** href )
{
    struct node* current=*href,*next;

    while(current!=NULL)
    {
        next=current->next;
        free(current);
        current=next;
    }

    *href=NULL;
}

//find length using iterative method
int leniter(struct node* href)
{
    int count=0;
    struct node* tmp=href;
    while(tmp!=NULL)
    {
        count++;
        tmp=tmp->next;
    }
    return count;
}

//find length using recursive method
int lenrecu(struct node* href)
{
    //base case
    if(href==NULL)
        return 0;
    return 1+lenrecu(href->next);
}

//search element iterative way
bool searchiter(struct node* href,int data)
{
    struct node* current=href;
    while(current!=NULL)
    {
        if(current->data==data)
            return true;
        current=current->next;
    }
    return false;
}

//search element recursive way
bool searchrecu(struct node* href,int data)
{
    //base class
    if(href==NULL)
        return false;
    if(href->data==data)
        return true;

    return searchrecu(href->next,data);
}

//reverse the list
void reverse(struct node** href) 
{ 
    struct node* prev   = NULL; 
    struct node* current = *href; 
    struct node* next; 
    while (current != NULL) 
    { 
        next  = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    *href = prev; 
} 

//get nth element 
int getnth(struct node* href,int index)
{
    struct node* current=href;
    int count=0;
    while(current!=NULL)
    {
        if(count==index)
            return current->data;;
        count++;
        current=current->next;
    }
    assert(0);
}
//print list
void printlist(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ",node->data);
        node= node->next;
    }
}
int main()
{
    struct node* head=NULL;

    //todo:- make a command line interface here

    //insert at first in the list
    insertatfirst(&head,10);
    insertatfirst(&head,7);
    insertatfirst(&head,11);
    insertatfirst(&head,502);
    insertatfirst(&head,45);
    insertatfirst(&head,456);
    insertatfirst(&head,423);
    insertatfirst(&head,8);

    //insert after given node
    insertafter(head->next->next,12323);

    //insert at last in the list
    insertatlast(&head,989);
    insertatlast(&head,98);
    insertatlast(&head,99);
    insertatlast(&head,19);
    insertatlast(&head,119);
    insertatlast(&head,109);

    //insert after given key value
    insertafterkey(&head,1079,119);

    //delete node of given key value
    deletekeynode(&head,119);

    //delete node at position given
    deleteatpos(&head,4);
    deleteatpos(&head,20);

    //print the screen
    printf("created linklist is :-\n");
    printlist(head);
    printf("\n");

    //print length
    printf("Length using iterative = %d\n",leniter(head));
    printf("Length using recursive = %d\n",lenrecu(head));

    //search element
    printf("search using iterative = %d\n",searchiter(head,322));
    printf("search using recursive = %d\n",searchrecu(head,1079));

    //get nth element
    printf("nth element = %d\n",getnth(head,5));

    //reverse the list
    reverse(&head);
    //print the screen
    printf("created linklist is :-\n");
    printlist(head);
    printf("\n");

/*
    //delete list
    deletelist(&head);

    //print the screen
    printf("created linklist is :-\n");
    printlist(head);
*/
    return 0;
}
