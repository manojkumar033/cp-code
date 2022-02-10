#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Edge
{
public:
    int src = 0;
    int nbr = 0;

    Edge(int src, int nbr)
    {
        this->src = src;
        this->nbr = nbr;
    }
};
class pr
{
public:
    int first;
    string second;

    pr(int first, string second)
    {
        this->first = first;
        this->second = second;
    }
};
void bst(vector<vector<Edge>> &graph, vector<bool> &visited, int src, vector<int> &r)
{
    queue<int> q;
    q.push(src);

    while (q.size() > 0)
    {
        int e = q.front();
        //  cout << e.first << endl;
        q.pop();
        if (visited[e] == true)
        {
            continue;
        }
        visited[e] = true;
        // cout << e.first << "@" << e.second << endl;
        r.push_back(e);
        for (Edge it : graph[e])
        {

            if (visited[it.nbr] == false)
            {
                q.push(it.nbr);
            }
        }
    }
}

int main()
{
    int vtces;
    cin >> vtces;
    vector<vector<Edge>> graph(vtces, vector<Edge>());

    int edges;
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(Edge(u, v));
        graph[v].push_back(Edge(v, u));
    }

    int src;
    cin >> src;
    // write your code here
    vector<bool> visited(vtces, false);
    vector<int> r;
    bst(graph, visited, src, r);
    for (int i = 0; i < r.size(); i++)
    {
        cout << r[i] << " ";
    }
    return 0;
}