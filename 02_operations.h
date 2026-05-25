#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include "00_structures.h"


//union operation
tree_node *union_op(tree_node *paragraph1, tree_node *paragraph2);
void merge_tree(tree_node **r1, tree_node *r2);
void insert_copy(tree_node **r, char *phrase);
tree_node *create_phrase(char *phrase);

//intersection operation
tree_node *intersection(tree_node *paragraph1, tree_node *paragraph2);
void build_intersection_tree(tree_node *p1, tree_node *p2, tree_node **intersection_tree);
int find_phrase(tree_node *paragraph, char *phrase);

//difference operation
tree_node *difference(tree_node *paragraph1, tree_node *paragraph2);
void build_difference_tree(tree_node *paragraph1, tree_node *paragraph2, tree_node **difference_tree);

#endif
