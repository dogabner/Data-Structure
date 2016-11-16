#include <iostream>
using namespace std;

class LinkRec
{
    friend LinkRec operator+(const LinkRec &l1, const LinkRec &l2);
    friend ostream &operator<<(ostream &os, const LinkRec &link);

  public:
    LinkRec() { createLinkRec(); }
    ~LinkRec() { clear(); }
    void createLinkRec();
    void insert(const int &d);

  private:
    struct Node
    {
        int data;
        Node *next, *pre;
        Node(const int &d) : data(d), next(NULL), pre(NULL){};
    };
    Node *head, *rear;
    void clear()
    {
        Node *p = head;
        while (p)
        {
            Node *q = p->next;
            delete p;
            p = q;
        }
    }
};

void LinkRec::createLinkRec()
{
    head = new Node(0);
    rear = new Node(0);
    head->next = rear;
    rear->pre = head;
}

void LinkRec::insert(const int &d)
{
    Node *p = new Node(d);
    p->next = head->next;
    p->pre = head;
    p->next->pre = p;
    p->pre->next = p;
}
LinkRec operator+(const LinkRec &l1, const LinkRec &l2)
{
    LinkRec::Node *num1Temp = l1.head->next;
    LinkRec::Node *num2Temp = l2.head->next;
    int up = 0;
    LinkRec result;
    while ((num1Temp->next != NULL) || (num2Temp->next != NULL))
    {
        int temp1, temp2;
        if (num1Temp->next == NULL)
            temp1 = 0;
        else
        {
            temp1 = num1Temp->data;
            num1Temp = num1Temp->next;
        }
        if (num2Temp->next == NULL)
            temp2 = 0;
        else
        {
            temp2 = num2Temp->data;
            num2Temp = num2Temp->next;
        }
        result.insert((temp1 + temp2 + up) % 10);
        up = (temp1 + temp2 + up) / 10;
    }
    if (up == 1)
        result.insert(up);
    return result;
}
ostream & operator << (ostream & os, const LinkRec & link){
    LinkRec::Node *p = link.head->next;
    while(p->next != NULL){
        os << (p->data);
        p = p->next;
    }
    return os;
}

int main()
{
    int x;
    int sum;
    LinkRec linkrecA, linkrecB;

    char a[1000000], b[1000000];
    cin >> a >> b;
    for (int i = 0; i < 1000000 && a[i] != '\0'; ++i)
    {
        linkrecA.insert(a[i]-'0');
    }
    for (int i = 0; i < 1000000 && b[i] != '\0'; ++i)
    {
        linkrecB.insert(b[i]-'0');
    }

    LinkRec result = linkrecA + linkrecB;
    cout << result;

    return 0;
}
