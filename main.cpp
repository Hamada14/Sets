#include <iostream>
#include "Set.h"

using namespace std;

Set universeSet;
Set allSets[25];
int setCount;

void getInput()
{
    universeSet.init("Universe");
    cout << "Enter the number of Sets : ";
    cin >> setCount;
    for(int i = 0; i < setCount; i++)
    {
        string curName;
        curName += ('A' + i);
        allSets[i].init(curName);
    }
}

Set unionOperation()
{
    char firstSet, secondSet;
    cout << "enter the names of the desired sets each separated by enter press ";
    cin >> firstSet >> secondSet;
    return allSets[firstSet - 'A'].getUnion(allSets[secondSet - 'A']);
}

Set interOperation()
{
    char firstSet, secondSet;
    cout << "enter the names of the desired sets each separated by enter press ";
    cin >> firstSet >> secondSet;
    return allSets[firstSet - 'A'].getIntersection(allSets[secondSet - 'A']);
}

Set complementOperation()
{
    char firstSet;
    cout << "enter the names of the desired sets each separated by enter press ";
    cin >> firstSet;
    return allSets[firstSet - 'A'].getDif(universeSet);
}

void doOperations()
{
    bool exitProgram = false;
    int curOperation;
    while(!exitProgram)
    {
        cout << "Enter the number of the desired operations : \n1-union\n2-intersection\n3-complement\n4-quit\n";
        cin >> curOperation;
        switch(curOperation)
        {
        case 1:
            unionOperation().printSet();
            break;
        case 2:
            interOperation().printSet();
            break;
        case 3:
            complementOperation().printSet();
            break;
        default:
            exitProgram = true;
        }
    }
}

int main()
{
    getInput();
    cout << "FUCKE " << endl;
    allSets[0].printSet();
    allSets[1].printSet();
    doOperations();
    return 0;
}
