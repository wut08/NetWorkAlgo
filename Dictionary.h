#ifndef _StringProduction_Dictionary
#define _StringProduction_Dictionary

#include <string>
#include <vector>
#include <map>

class Dictionary{
public:
    Dictionary(int wordSize);
    ~Dictionary(){}
    Dictionary &operator=(const Dictionary &p);
private:
    Dictionary(const Dictionary &p);
public:
    void addElement(const std::string &s);
    void buildAdjancencyMatrix();
    bool contains(const std::string &s);
    const std::vector<std::vector<bool>> &adjList();
    int elemPosition(const std::string &s);
    int size(){return (int)m_values.size();}
    std::string elemAtPos(int i);
private:
    std::vector<std::string> m_values;
    std::map<std::string, int> m_valuePositions;
    std::vector<std::vector<bool>> m_adjacencyList;
    int m_wordSize;
};

#endif // StringProduction_Dictionary
