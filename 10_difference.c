#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "00_structures.h"
#include "02_operations.h"




/*
 * Role: fill the defference tree with phrases
 * found in paragraph 1 that are not found in paragraph2
 */
void build_difference_tree(tree_node *p1, tree_node *p2, tree_node **difference_tree)
{
    if (p1 == NULL)
    {
        return;
    }
    build_difference_tree(p1->lc, p2, difference_tree);
    int found  = find_phrase(p2, p1->phrase);
    if (!found)
    {
        insert_copy(difference_tree, p1->phrase);
    }
    build_difference_tree(p1->rc, p2, difference_tree);

}



// Role: perform the difference operation and return  a new differece tree
tree_node *difference(tree_node *paragraph1, tree_node *paragraph2)
{
    if (paragraph1 == NULL)
    {
        return NULL;
    }

    tree_node *difference_tree = NULL;

    build_difference_tree(paragraph1, paragraph2, &difference_tree);
    return difference_tree;
}


