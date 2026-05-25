#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "00_structures.h"
#include "02_operations.h"


/* 
 * Role: search for a phrase in a given paragraph
 * according to the binary search pronciple
 */
int find_phrase(tree_node *paragraph, char *phrase) 
{
    if (paragraph == NULL)
    {
        return 0; //word does not exist in this paragraph
    }
        int location = strcmp(paragraph->phrase, phrase);
        if (location == 0)
        {
            return 1; //word found
        }
        if (location < 0)
        {
            return find_phrase(paragraph->rc, phrase);
        }
        else
        {
            return find_phrase(paragraph->lc, phrase);
        }
        
}

/*
 * Role: find common prases between paragraph 1 and two
 * and insert them in a new intersection tree 
 */
void build_intersection_tree(tree_node *p1, tree_node *p2, tree_node **intersection_tree)
{
    if (p1 == NULL)
    {
        return;
    }
    build_intersection_tree(p1->lc, p2, intersection_tree);
    int found  = find_phrase(p2, p1->phrase);
    if (found)
    {
        insert_copy(intersection_tree, p1->phrase);
    }
    build_intersection_tree(p1->rc, p2, intersection_tree);

}

/*
 * Role: perform the intersection operation 
 * between paragraph 1 and 2 
 * result found in a new intersection tree
 */
tree_node *intersection(tree_node *paragraph1, tree_node *paragraph2)
{
    if (paragraph1 == NULL || paragraph2 == NULL)
    {
        return NULL;
    }

    tree_node *intersection_tree = NULL;

    build_intersection_tree(paragraph1, paragraph2, &intersection_tree);

    return intersection_tree;
}


