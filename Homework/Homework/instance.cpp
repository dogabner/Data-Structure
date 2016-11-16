#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdio.h>
using namespace std;

class list
{
    struct node
    {
        int data;
        node *next, *pre;

        node(int d, node *n = NULL, node *p = NULL)
        {
            data = d;
            next = n;
            pre = p;
        }
        node()
        {
            next = NULL;
            pre = NULL;
        }
    };

    node *head, *rear;

  public:
    list()
    {
        head = new node;
        rear = new node;
        head->next = rear;
        rear->pre = head;
    }

    void insert(int n)
    {
        node *temp;
        temp = new node(n, head->next, head);
        temp->next->pre = temp;
        temp->pre->next = temp;
    }

    list add(list num2)
    {
        node *num1_temp = head->next;
        node *num2_temp = num2.head->next;
        int carry = 0;
        list result;
        while ((num1_temp->next != NULL) || (num2_temp->next != NULL))
        {
            int t1, t2;
            if (num1_temp->next == NULL)
                t1 = 0;
            else
            {
                t1 = num1_temp->data;
                num1_temp = num1_temp->next;
            }
            if (num2_temp->next == NULL)
                t2 = 0;
            else
            {
                t2 = num2_temp->data;
                num2_temp = num2_temp->next;
            }

            result.insert((t1 + t2 + carry) % 10);
            carry = (t1 + t2 + carry) / 10;
        }
        if (carry == 1)
            result.insert(carry);
        return result;
    }

    void print()
    {
        node *temp = head->next;
        while (temp->next != NULL)
        {
            printf("%d", temp->data);
            temp = temp->next;
        }
    }
};

int main()
{
    char a[1000000], b[1000000];
    scanf("%s", a);
    scanf("%s", b);

    list num1, num2;
    for (int i = 0; i < 1000000 && a[i] != '\0'; ++i)
    {
        num1.insert((a[i] - '0'));
    }
    for (int i = 0; i < 1000000 && b[i] != '\0'; ++i)
    {
        num2.insert((b[i] - '0'));
    }

    list result = num1.add(num2);
    result.print();
}