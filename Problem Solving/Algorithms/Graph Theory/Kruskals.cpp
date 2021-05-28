#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kruskals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

class Edge{
public:      
    int src;
    int dest;
    int weight;
};

bool sort_weight(const Edge &e1, const Edge &e2){
    if(e1.weight < e2.weight){
        return true;
    }
    else{
        return false;
    }
}

int parent_finder(int src, int *parent){
    if(parent[src] == src){
        return src;
    }
    else{
        while(parent[src] != src){
                src = parent[src];
        }
        return src;
    }
}

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    Edge *input = new Edge[g_from.size()];
     for(int i = 0; i < g_from.size(); i++){
        
        input[i].src = g_from[i];
        input[i].dest = g_to[i];
        input[i].weight = g_weight[i];
    }
     int *parent = new int[g_nodes];
      for(int i = 0; i < g_nodes; i++){
        parent[i] = i;
    }
     
     int count = 0, minwt=0;
     int size=g_from.size();
    sort(input, input + size, sort_weight);
    Edge *output = new Edge[g_nodes - 1];
    
    for(int i = 0; i < size; i++){
        if(count == g_nodes - 1){
            break;
        }
        int v1 = input[i].src, v2 = input[i].dest;
        int parent_src = parent_finder(v1, parent);
        int parent_dest = parent_finder(v2, parent);
        if(parent_src == parent_dest){
            continue;
        }
        else{
            parent[parent_src] = parent_dest;
            output[count] = input[i];
            minwt+=input[i].weight;
            count++;
        }
    }
    return minwt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    int res = kruskals(g_nodes, g_from, g_to, g_weight);

    // Write your code here.
    fout << res << "\n";
    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
