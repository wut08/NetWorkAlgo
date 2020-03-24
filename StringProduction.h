#ifndef __StringProduction__StringProduction__
#define __StringProduction__StringProduction__
#include <vector>
#include <string>

class Dictionary;
class StringProduction{
public:
    StringProduction(Dictionary &d);
    StringProduction(const StringProduction &p);
    ~StringProduction();
    StringProduction &operator=(const StringProduction &p);

    bool produces(const std::string &src, const std::string &dest, std::vector<std::string> &path);
    void shortest_path(int v, int dest, int n, std::vector<std::string> &path);
    std::vector<int> recoverPath(int src, int dest, const std::vector<int> &P, std::vector<int> &path);
private:
    Dictionary &m_dic;
};
#endif // __StringProduction__StringProduction__
