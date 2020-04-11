#include <iostream>
using namespace std;

struct NODE
{
    long long info; // long long int
    NODE* pNext;
};
struct LIST
{
    NODE* pHead;
    NODE* pTail;
};

void CreateList(LIST& List)
{
    List.pHead = NULL;
    List.pTail = NULL;
}
NODE* CreateNode(long long x)
{
    NODE* p;
    p = new NODE;
    if (p == NULL) exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}

void AddHead(LIST& List, NODE* p)
{
    if (List.pHead == NULL)
    {
        List.pHead = p;
        List.pTail = List.pHead;
    }
    else
    {
        p->pNext = List.pHead;
        List.pHead = p;
    }
}
void AddTail(LIST& List, NODE* p)
{
    if (List.pHead == NULL)
    {
        List.pHead = p;
        List.pTail = List.pHead;
    }
    else
    {
        List.pTail->pNext = p;
        List.pTail = p;
    }
}
void RemoveAfterQ(LIST& List, NODE* p, NODE* q)
{
    if (p == List.pHead)
    {
        List.pHead = List.pHead->pNext;
        delete p;
    }
    else
    {
        q->pNext = p->pNext;
        if (p == List.pTail)
            List.pTail = q;
        delete p;
    }
}
void RemoveX(LIST& List, long long x)
{
    NODE* p = List.pHead;
    NODE* q = NULL;
    while (p != NULL)
    {
        if (p->info == x)
        {
            RemoveAfterQ(List, p, q);
            if (q == NULL)
                p = List.pHead;
            else
                p = q->pNext;
        }
        else
        {
            q = p;
            p = p->pNext;
        }
    }
}
void InputList(LIST& List)
{
    while (1)
    {
        long long x;
        cin >> x;
        if (x == 0)
            return;
        NODE* p = CreateNode(x);
        AddTail(List, p);
    }
}

void PrintList(LIST List)
{
    if (List.pHead == NULL)
    {
       cout << "null";
       return;
    }
    NODE* p = List.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }

}

void RemoveList(LIST& List)
{
    NODE* p;
    while (List.pHead != NULL)
    {
        p = List.pHead;
        List.pHead = p->pNext;
        delete p;
    }
}

int main()
{
    LIST List;
    CreateList(List);
    InputList(List);
    while (1)
    {
        long long q, k;
        cin >> q;
        if (q == 0)
            break;
        cin >> k;
        NODE* p = CreateNode(k);
        if (q == 1)
            AddHead(List, p);
        else if (q == 2)
            AddTail(List, p);
        else
            RemoveX(List, k);
    }
    PrintList(List);
    RemoveList(List);
    return 0;
}
