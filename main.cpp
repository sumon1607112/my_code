#include <bits/stdc++.h>
#define ll long long int


using namespace std;
struct double_linked_list{

 ll value;
 struct double_linked_list *next;
 struct double_linked_list *previous;

};
typedef struct double_linked_list node;
node *Head=NULL,*Tail=NULL;

void At_first_insert(ll value)
{

    node *newNode=(node *)malloc(sizeof(node));
    newNode->value=value;
    newNode->next=NULL;
    newNode->previous=NULL;
    if(Head==NULL)
    {

        Head=newNode;
        Tail=newNode;
        return;
    }
    newNode->next=Head;
    Head->previous=newNode;
    Head=newNode;

}
void At_last_insert(ll value)
{
     node *newNode=(node *)malloc(sizeof(node));
    newNode->value=value;
    newNode->next=NULL;
    newNode->previous=NULL;
    if(Head==NULL)
    {
        Head=newNode;
        Tail=newNode;
        return;
    }
    Tail->next=newNode;
    newNode->previous=Tail;
    Tail=newNode;
}
void At_middle_insert(ll value,ll position)
{

    node *newNode=(node *)malloc(sizeof(node));
    newNode->value=value;
    newNode->next=NULL;
    newNode->previous=NULL;
    ll i=1;
   /// node *temp=(node *)malloc(sizeof(node));
   node *temp;
    temp=Head;
    while((i<position-1) && temp->next!=NULL )
    {

        temp=temp->next;
        i++;
    }
    newNode->next=temp->next;
    newNode->previous=temp;
    temp->next=newNode;
    if(newNode->next)
      newNode->next->previous=newNode;


}
void Print_node(node *currentNode)
{
    if(currentNode==NULL)
        return;
         cout<<currentNode->value<<" ";
     Print_node(currentNode->next);

}
void DeleteNode(ll position)
{

    if(Head==NULL)
        return;

    if(position==1)
    {
        Head=Head->next;
        if(Head==NULL)
        {
            Tail=NULL;

        }
        else
        {
            Head->previous=NULL;
        }
    }
    else
    {
        ///cout<<"In"<<endl;

       node *tempNode =Head,*item;
       ll i=1;
       while(i<position && tempNode!=NULL)
       {
           i++;
           tempNode=tempNode->next;

       }
       if(i==position)
       {
           item=tempNode->previous;
           item->next=tempNode->next;
           if(tempNode->next==NULL)
            Tail=item;
           else
            tempNode->next->previous=item;

       }
       else
       {
           cout<<"it is not found"<<endl;
       }
    }
}
int main()
{
    At_first_insert(5);
    At_last_insert(7);
    At_middle_insert(4,2);
    Print_node(Head);
    DeleteNode(3);
    cout<<"Yes"<<endl;
    Print_node(Head);


    return 0;
}
