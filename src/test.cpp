#include <stdio.h>
#include "list.h"
#include "binary_tree.h"

int main(void)
{
    List<int> test_list;
    
    test_list.push_front(10);
    test_list.push_front(20);
    test_list.push_front(30);
    test_list.push_front(40);
    test_list.print_list();

    //printf("hello\n");
    //printf("test result is %d\n", sub(3, 5));
    return 0;
}