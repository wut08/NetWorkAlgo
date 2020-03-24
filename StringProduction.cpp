#include "StringProduction.h"
#include "Dictionary.h""
#include <map>
#include <set>
#include <algorithm>
#include <iostream>


using std::vector;
using std::string;
using std::map;
using std::set;
using std::reverse;

StringProduction::StringProduction(Dictionary &d)
: m_dic(d)
{
}

StringProduction::StringProduction(const StringProduction &p)
: m_dic(p.m_dic)
{
}

StringProduction::~StringProduction()
{
}

StringProduction &StringProduction::operator=(const StringProduction &p)
{
    if(&p !=this){
        m_dic=p.m_dic;
    }
    return *this;
}

vector<int> StringProduction::recoverPath(int src, int dest, const vector<int> &P, vector<int> &path){
    int v=dest;
    while (v !=src){
        path.push_back(v);
        v=P[v];
    }
    path.push_back(src);
    std::reverse(path.begin(),path.end());
    return path;
}

void StringProduction::shortest_path(int v, int dest, int n, vector<string> &path)
{
    const std::vector<std::vector<bool>> &A=m_dic.adjList();
    path.clear();

    vector<int> dist(n,0);
    vector<int> prev(n,0);
    set<int> Q;
    const int INF=INT_MAX;

    for (int i=0; i<n; i++){
        Q.insert(i);
        if(i !=v){
            dist[i]=INF;
        }
    }
    //Dijkstra's algo
    while(!Q.empty()){
        int min=INF;
        int u=-1;
        for (set<int>::iterator it=Q.begin(); it !=Q.end(); ++it){
            if (dist[*it]<min){
                min = dist[*it];
                u=*it;
            }
        }
        Q.erase(u);
        for(int i=0; i<n; ++i){
            if (A[u][i]){
                int d = dist[u] +1;
                if (d<dist[i]){
                    dist[i]=d;
                    prev[i]=u;
                }
            }
        }

    }
    vector<int> npath;
    recoverPath(v, dest, prev, npath);
    for (unsigned i=0; i<npath.size(); ++i){
        path.push_back(m_dic.elemAtPos(npath[i]));
    }
}
bool StringProduction::produces(const string &src, const string &dest, vector<string> &path)
{
    if(!m_dic.contains(src) || !m_dic.contains(dest)) return false;
    shortest_path(m_dic.elemPosition(src), m_dic.elemPosition(dest), m_dic.size(), path);
    return path.size() >0;
}
