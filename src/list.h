#ifndef __LIST_H
#define __LIST_H
#include <stdio.h>

int sub(int a, int b);
int add(int a, int b);

template <typename Object>
class List
{
private:
    struct Node
    {
        Object data;

        Node *prev;
        Node *next;

        Node(Object &d, Node *p, Node *n)
        {
            data = d;
            prev = p;
            next = n;

            printf("Node struct init\n");
        }
    };

public:
    List()
    {
        printf("list constructor\n");
    };

    void test();
};

template <typename Object>
void List<Object>::test(void)
{
    printf("this is a test\n");
    return;
}


#endif
