#include <bits/stdc++.h>

#define INF 100000

using namespace std;

struct WeightedGraph
{
    int dist[1000];

    struct element
    {
        int u, v, cost;
    };

    vector <element> edge;

    void input(int u, int v, int cost)
    {
        element temp;
        temp.u = u;
        temp.v = v;
        temp.cost = cost;

        edge.push_back(temp);
    }

    void bellman_ford(int root, int n, int E)
    {
        for(int i = 0; i < n; i++)
            dist[i] = INF;

        for(int i = 1; i <= n-1; i++)
        {
            for(int j = 0; j < E; j++)
            {
                if(dist[edge[j].u] + edge[j].cost < dist[edge[j].v])
                {
                    dist[edge[j].v] = dist[edge[j].u] + edge[j].cost;
                    printf("%d distance is %d ", edge[j].v, dist[edge[j].v])        ;
                }
            }
        }

        bool negCycle = false;
        /*
                for(int j = 0; j < E; j++){
                        if(dist[edge[j].u] + edge[j].cost < dist[edge[j].v]){
                            dist[edge[j].v] = dist[edge[j].u] + edge[j].cost;
                            negCycle = true;
                            break;
                        }
                    }*/

        if(negCycle)
            cout<<"Negative Cycle Detected"<<endl;

        else
        {
            for(int i = 0; i <n; i++)
            {
                if(dist[i] == INF)
                    printf("Node %d is not reachable\n", i);
                else printf("Shortest Distance of Node %d from %d\n", i, root);
            }
        }
    }

};

int main()
{
    WeightedGraph w1;
    int u, v, w, n, E, root;
    printf("Enter the Number of Nodes and Edges : \n");
    scanf("%d %d", &n, &E);

    for(int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        w1.input(u, v, w);
    }

    scanf("%d", &root);
    w1.bellman_ford(root, n, E);

    return 0;
}
