#include <iostream> 
using namespace std;

struct PERSON
{
    string name;
    int year_of_birth = 0;
    struct PERSON* pFather = NULL;
};

struct FAMILY 
{
    PERSON* pYoungest;
    PERSON* pOldest;
};

PERSON* CreatePerson(string name, int year_of_birth) 
{
    PERSON* p;
    p = new PERSON;
    if (p == NULL) exit(1); 
    p->name = name;
    p->year_of_birth = year_of_birth;
    //p->pF = NULL; bổ sung
    return p;
}

int main()
{
    PERSON* pB, * pA, * pC;
    pB = CreatePerson("H", 1970); 

    FAMILY f;
    f.pYoungest = pB;
    f.pOldest = f.pYoungest;

    pA = CreatePerson("P", 2000);
    pA->pFather = f.pYoungest;
    f.pYoungest = pA;

    pC = CreatePerson("J", 1945);
    f.pOldest->pFather = pC;
    f.pOldest = pC;

    PERSON* pTemp;
    pTemp = f.pYoungest;
    while (pTemp != NULL)
    {
        cout << pTemp->name << " ";
        cout << pTemp->year_of_birth << endl;
        pTemp = pTemp->pFather;
    }
}
