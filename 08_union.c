#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "00_structures.h"
#include "02_operations.h"



/* 
 * Role: create a new tree node 
 * that contains the input phrase.
 */
tree_node *create_phrase(char *phrase)
{
    tree_node *n = (tree_node *)malloc(sizeof(tree_node));
    if (n == NULL)
    {
        return NULL;
    }
    n->phrase = strdup(phrase); //to create a copy of the phrase
                            // and avoid passing the original node
    n->lc = NULL;
    n->rc = NULL;
   
    return n;
}

/* 
 * Role: insert input phrase inside the target tree
 * according to binary search principle
 */
void insert_copy(tree_node **r, char *phrase)
{
    if (*r == NULL)
    {
        *r = create_phrase(phrase);
        return;
    }
    
    int location = strcmp(phrase, (*r)->phrase);
    if (location == 0)
    {
        return; // the phrase already exists in the tree.
    }
    else
    {
        if (location < 0)
    {
        insert_copy(&((*r)->lc), phrase);
        return;
    }
    else
    {
        insert_copy(&((*r)->rc), phrase);
        return;
    }
    }   
}


/* 
 * Role: merge tree r2 with r1 
 * (r1 contains the final tree)
 */
void merge_tree(tree_node **r1, tree_node *r2)
{
    if (r2 == NULL)
    {
        return;
    }
    merge_tree(r1, r2->lc);
    insert_copy(r1, r2->phrase);
    merge_tree(r1, r2->rc);
}


 /* 
  * Role: perform unoin operation beween two paragraphs
  * result in a new unoin tree
  */
tree_node *union_op(tree_node *paragraph1, tree_node *paragraph2)
{
    tree_node *union_tree = NULL;

    merge_tree(&union_tree, paragraph1);
    merge_tree(&union_tree, paragraph2);

    return union_tree;
}