#include <stdio.h>
#include "list.h"
#include <iostream>
#include "binary_tree.h"
#include <time.h>
#include <stdlib.h>

#define SIZE 10

#define random(x) (rand()%x)


int main(void)
{
    srand((int)time(NULL));
    
    /*List<int> test_list;

    for(int i = 0; i < SIZE; i++)
    {
        test_list.insert(random(9999999));
    }
    

    debug("list has %d items", test_list.get_size());
    test_list.print_list();
    debug("pop value is %d", test_list.pop());
    debug("pop value is %d", test_list.pop());
    //debug("pop value is %d", test_list.pop());
    //printf("test result is %d\n", sub(3, 5));
    debug("list has %d items", test_list.get_size());
    test_list.print_list();*/

    BinarySearchTree<unsigned int> my_tree;
    /*time_t start = time(NULL);
    for(int i = 0; i < SIZE; i++)
    {
        my_tree.insert(random(9999999));
    }
    time_t end = time(NULL);
    debug("insert elements cosume %d s", end-start);
*/
    
    my_tree.insert(20);
    my_tree.insert(40);
    my_tree.insert(10);
    my_tree.insert(20);
    my_tree.insert(40);
    my_tree.insert(10);
    my_tree.insert(20);
    my_tree.insert(40);
    my_tree.insert(10);
    my_tree.printTree();
    my_tree.remove(40);

    // my_tree.insert(31);
    // my_tree.insert(21);
    // my_tree.insert(41);
    // my_tree.insert(11);

    // if(my_tree.contains(20))
    // {
    //     debug("found 20");
    // }
    // else
    // {
    //     debug("not found");
    // }

    my_tree.printTree();
    printf("\n");


    time_t start1 = time(NULL);
    debug("min element is %d", my_tree.findMin());
    debug("max element is %d", my_tree.findMax());
    time_t end1 = time(NULL);
    debug("cosume time is %d s", end1-start1);

    return 0;
}
