#include "StringProduction.h"
#include "Dictionary.h"
#include <iostream>

#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::set;
using std::map;
using std::cerr;



int main(int argc, const char *argv[])
{
    if(argc !=3){
        cout<<"Prog word1 word2"<<endl;
        return 0;
        }
    Dictionary dic(3);
    dic.addElement("lob");
    dic.addElement("dag");
    dic.addElement("log");
    dic.addElement("car");
    dic.addElement("dog");
    dic.addElement("cat");
    dic.addElement("cob");
    dic.addElement("cab");
    dic.addElement("cag");

    dic.buildAdjancencyMatrix();

    vector<string> path;
    StringProduction sp(dic);
    if (sp.produces(argv[1], argv[2], path)){
        cout<<"--the first string produces the second"<<endl;
        cout<<"--that path has size"<<path.size()<<":\n";
        for (unsigned i=0; i<path.size(); ++i){
            cout<<path[i]<<";";
        }
    }else{
        cout<<"the second string does not produce the second"<<endl;
    }
    return 0;
}
