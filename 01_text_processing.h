#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "00_structures.h"

void display_inorder(tree_node *r);
tree_node *create_node(char *word);
char *extract_phrase(char **index);
void add_phrase(tree_node **r , char *word);
void insert_phrase(tree_node **r, tree_node *t);
tree_node *extract_paragraph(char **index);

char *read_file();
text_file process_file();
void free_struct(text_file *file);
void free_tree(tree_node **r);


