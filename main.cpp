#include <bits/stdc++.h>
#define ll long long int
using namespace std;
struct link_list{
  ll value;
  struct link_list *next;


};
typedef struct link_list node;
node *Head=NULL ,*Last=NULL;
///Delete a Node
void DeleteNode(node *currentNode,ll source)
{
    currentNode=Head;
    node *tempNode,*itemNode;
    if(Head->value==source)
    {
        Head=currentNode->next;
        return;
    }
    while(currentNode!=NULL)
    {


        if(currentNode->value==source)
        {

            tempNode->next=currentNode->next;
            break;
        }
        tempNode=currentNode;
        currentNode=currentNode->next;
    }
}
///Delete a Node when Head is not given
void DeleteNodeWhenHeadNotGiven(ll source)
{
    node *currentNode;
    currentNode=Head;
    while(currentNode!=NULL)
    {
        node *tempNode;
        if(currentNode->value==source)
        {
            if(currentNode->next==NULL)
            {
                cout<<"it is not possible without Head pointer"<<endl;
            }
            else
            {
                tempNode=currentNode->next;
                currentNode->value=tempNode->value;
                tempNode=tempNode->next;
                currentNode->next=tempNode;
                break;

            }
        }
        currentNode=currentNode->next;
    }


}
///Delete After Node ;
void DeleteNodeAfter(node *currentNode,ll source)
{
    currentNode=Head;
    node *tempNode,*itemNode;
    while(currentNode!=NULL)
    {
        if(currentNode->value==source)
        {
            ///cout<<"cu:"<<currentNode->value<<endl;
            tempNode=currentNode->next;
            ///cout<<"te:"<<tempNode->value<<endl;
            itemNode=tempNode->next;
            ///cout<<"ite:"<<itemNode->value<<endl;
            currentNode->next=itemNode;
            break;
        }
        currentNode=currentNode->next;
    }
}
///Search Node ;
void SearchNode(node *currentNode,ll source)
{
    currentNode==Head;
    ll flag=0;
    while(currentNode!=NULL)
    {
        if(currentNode->value==source)
        {
            flag=1;
            break;
        }
        currentNode=currentNode->next;
    }
    if(flag)
        cout<<"Yes the node is found"<<endl;
    else
        cout<<"No the node is not found"<<endl;


}
///Print  Node;
void PrintNode(node *currentNode)
{
   /* while(currentNode!=NULL)
    {
        cout<<currentNode->value<<" ";
        currentNode=currentNode->next;

    }*/
    if(currentNode==NULL)
        return;
 cout<<currentNode->value<<" ";
   return PrintNode(currentNode->next);


}
///Insert  Node
void InsertNode(ll source)
{

    node *tempNode;
    tempNode=(node *) malloc(sizeof(node));
    tempNode->value=source;
    tempNode->next=NULL;
    if(Head==NULL)
    {
        Head=tempNode;
        Last=tempNode;
    }
    else
    {
        Last->next=tempNode;
        Last=tempNode;
    }
}
int main()
{
    InsertNode(10);
    InsertNode(20);
    InsertNode(30);
    InsertNode(2);
    InsertNode(44);
    InsertNode(0);

    cout<<endl;
    DeleteNode(Head,30);
     PrintNode(Head);
    cout<<endl;
    SearchNode(Head,10);
    cout<<endl;
    SearchNode(Head,100);
    cout<<endl;
    DeleteNodeAfter(Head,30);
    PrintNode(Head);
    cout<<endl;
    DeleteNodeWhenHeadNotGiven(30);
    PrintNode(Head);



    return 0;
}
