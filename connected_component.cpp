#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int src;
    int nbr;
    int wt;

    Edge(int src, int nbr, int wt)
    {
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
    }
};

void haspath(vector<Edge> gh[], vector<bool> &visited, int src, vector<int> &com)
{

    // vector<int> v;
    // cout << src << endl;
    // v.push_back(src);
    visited[src] = true;
    for (Edge it : gh[src])
    {
        if (visited[it.nbr] == false)
        {
            com.push_back(it.nbr);
            haspath(gh, visited, it.nbr, com);
        }
    }
}

int main()
{
    int vtces;
    cin >> vtces;
    vector<Edge> graph[vtces];

    int edges;
    cin >> edges;
    for (int i = 0; i < edges; i++)
    {
        int v1;
        int v2;
        int wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back(Edge(v1, v2, wt));
        graph[v2].push_back(Edge(v2, v1, wt));
    }

    vector<bool> visited(vtces, false);
    vector<vector<int>> comps;

    for (int i = 0; i < vtces; i++)
    {
        if (visited[graph[i][0].src] == false)
        {
            // cout << graph[i][0].src << endl;

            vector<int> v1;
            v1.push_back(graph[i][0].src);
            haspath(graph, visited, graph[i][0].src, v1);
            // v1.insert(v1.begin(),);
            comps.push_back(v1);
        }
    }
    // write your code here

    cout << "[";
    for (int i = 0; i < comps.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < comps[i].size(); j++)
        {
            if (j != comps[i].size() - 1)
                cout << comps[i][j] << ", ";
            else
                cout << comps[i][j];
        }
        cout << "]";
        if (i != comps.size() - 1)
            cout << ", ";
    }
    cout << "]";
}