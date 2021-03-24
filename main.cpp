#include<bits/stdc++.h>

using namespace std;
struct  Node{
  int value;
  Node *left;
  Node *right;

  Node()
  {
      value=0;
      left=NULL;
      right=NULL;
  }


};
int PreIndex=0;
int findIndex(vector<int>&v,int start,int finish,int value)
{
    int result=-1;
    for(int i=start;i<=finish;i++)
    {
        if(value==v[i])
            return i;
    }
    return result;
}
Node *buildTree(vector<int>&in ,vector<int>&pr,int start,int finish)
{
    if(start>finish)
        return NULL;
    Node *temp=new Node();
    temp->value=pr[PreIndex++];
    temp->left=NULL;
    temp->right=NULL;
    if(start==finish)
    {
        return temp;
    }
    int inOrderIndex=findIndex(in,start,finish,temp->value);
    temp->left=buildTree(in,pr,start,inOrderIndex-1);
    temp->right=buildTree(in,pr,inOrderIndex+1,finish);
    return temp;
}
vector<int>ans;

void Inorder(Node *curr)
{

    if(curr==NULL)
        return;
    Inorder(curr->left);
    ans.push_back(curr->value);
    Inorder(curr->right);
}

int main()
{
    vector<int>inorder={7, 4, 3, 2, 8};
    vector<int>preorder={2, 4, 7, 3, 8};
    Node *root=new Node();
    root=buildTree(inorder,preorder,0,inorder.size()-1);
    Inorder(root);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";




    return 0;
}
