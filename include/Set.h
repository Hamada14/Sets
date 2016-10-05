#ifndef SET_H
#define SET_H

#include<vector>
#include<string>
using namespace std;

class Set
{
    public:
        Set();
        void printSet();
        void init(string setName);
        Set getIntersection(Set curSet);
        Set getUnion(Set curSet);
        Set getDif(Set curSet);
    protected:
    private:
        vector<string> setElements;
        string setName;
        bool hasElement(string curElement);
        bool addElement(string curElement);
};

#endif // SET_H
