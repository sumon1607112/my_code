#include<bits/stdc++.h>
using namespace std;

map<int,int>dis;
map<int,int>parent;

int belmenford(int source,int vertix,int edge,vector<vector<pair<int,int> > > &g)
{
   for(int i=0;i<=vertix;i++)
   {

       dis[i]=INT_MAX;
       parent[i]=-1;
   }
   dis[source]=0;
   bool done=false;
   int temp;
   for(int i=0; !done && i<=vertix;i++)
   {
    done=true;

       for(int j=0;j<=vertix;j++)
       {
            int u=j;
            cout<<"u:"<<u<<endl;
            for(int k=0;k<g[j].size();k++)
            {

                int v=g[j][k].first;
                ///cout<<"v:"<<v<<endl;
                int w=g[j][k].second;
                ///cout<<"w:"<<w<<endl;
               if(dis[u]!=INT_MAX && dis[u]+w <dis[v])
               {
                   dis[v]=dis[u]+w;
                   parent[v]=u;
                   temp=v;
                   done=false;

               }


            }
       }
       ///cout<<"done:"<<done<<endl;
   }

/// "printing the cycle"

   int item=parent[temp];
   if(!done)
    {
         cout<<temp<<" ";
        while(item!=temp)
        {
            cout<<item<<" ";
            item=parent[item];
        }
        cout<<temp<<endl;
    }
    return -1;
}

int main()
{
    int n=100;
    int e=8;
    cout<<"checking the fucking git"<<endl;

vector<vector< pair<int,int> > >graph(n);
   graph[0].push_back(make_pair(1,1));
   graph[1].push_back(make_pair(2,1));
   graph[2].push_back(make_pair(3,3));
   graph[3].push_back(make_pair(4,-3));
   graph[4].push_back(make_pair(1,-3));

   belmenford(1,5,8,graph);



    return 0;
}
