#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
struct Stu
{
    int num;
    Stu *next;
};
class List2
{
    public:
    Stu *head = NULL;
    void add(int num)
    {
        Stu *record=new Stu;
        record->num=num;
        record->next==NULL;
        if (head == NULL)
        {
            head = record;
        }
        else
        {
            Stu *temp = getLastRecord(head);
            temp->next = record;
        }
    }
    Stu *getRecord(int num)
    {
        Stu *temp=head;
        int count=0;
        while (temp->next != NULL || count==num)
        {
            temp = temp->next;
            count++;
        }
        return temp;
    }
    Stu *getLastRecord(Stu *temp)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        return temp;
    }
    void display()
    {
        Stu *temp = head;
        while (temp != NULL)
        {
            cout<<temp->num<<',';
            temp = temp->next;
        }
    }
    int size()
    {
        Stu *temp = head;
        int count=0;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
    bool contains(int num)
    {
        Stu *temp = head;
        while (temp != NULL)
        {
            if(temp->num==num)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};
List2 dubli(List2 list1)
{
    int num;
    Stu *p=list1.getRecord(0);
    List2 newlist;
    for(int i=0;i<list1.size();i++)
    {
        if(!newlist.contains(p->num))
        {
            newlist.add(p->num);
        }
    }
    return newlist;
}
main()
{
    List2 list1;
    list1.add(4);
    list1.add(3);
    list1.add(2);
    list1.add(6);
    list1.add(1);
    // list1.display();
}