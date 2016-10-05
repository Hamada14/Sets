#include "Set.h"
#include<iostream>

Set::Set()
{

}

bool Set::addElement(string curElement)
{
    if(hasElement(curElement))
        return false;
    setElements.push_back(curElement);
    int curPos = setElements.size() - 1;
    while(curPos > 0 && setElements[curPos] < setElements[curPos - 1])
        swap(setElements[curPos--], setElements[curPos - 1]);
    return true;
}

bool Set::hasElement(string curElemnt)
{
    int low = 0, high = setElements.size() - 1;
    if(high < low) return false;
    while(low < high)
    {
        int mid = low + (high - low) / 2;
        if(setElements[mid] >= curElemnt)
            high = mid;
        else
            low = mid + 1;
    }
    return setElements[low] == curElemnt;
}

Set Set::getIntersection(Set curSet)
{
    Set resultSet;
    int firstSetSize = setElements.size();
    for(int i = 0; i < firstSetSize; i++)
    {
        if(curSet.hasElement(setElements[i]))
            resultSet.addElement(setElements[i]);
    }
    return resultSet;
}

Set Set::getUnion(Set curSet)
{
    Set resultSet;
    int fSize = setElements.size();
    int sSize = curSet.setElements.size();
    for(int i = 0; i < fSize; i++)
    {
        resultSet.addElement(setElements[i]);
    }
    for(int i = 0; i < sSize; i++)
    {
        if(!resultSet.hasElement(curSet.setElements[i]))
            resultSet.addElement(curSet.setElements[i]);
    }
    return resultSet;
}

Set Set::getDif(Set curSet)
{
    int setSize = curSet.setElements.size();
    Set result;
    for(int i = 0; i < setSize; i++)
    {
        if(!hasElement(curSet.setElements[i]))
        {
            cout << "HERE " << curSet.setElements[i] << " \n";
            result.addElement(curSet.setElements[i]);
        }
    }
    return result;
}

void Set::printSet()
{
    cout << setName <<  " = {";
    for(int i = 0; i < (int)setElements.size(); i++)
        cout << setElements[i] << (i < (int)setElements.size() - 1 ? ", " : "");
    cout << "}\n";
}

void Set::init(string setN)
{
    int curSize;
    setName = setN;
    cout << "Enter the number of elements in " << setName << " set: ";
    cin >> curSize;
    cout << "Enter the elements separated by an enter button press\n";
    for(int i = 0; i < curSize; i++)
    {
        string element;
        cin >> element;
        addElement(element);
    }
}
