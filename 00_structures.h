#include <stdio.h>
#include <stdlib.h>



typedef struct tree_node 
{
    char *phrase;
    struct tree_node *lc;
    struct tree_node *rc;
}tree_node;


typedef struct text_file
{
    tree_node **paragraph_array;
    int paragraph_count;
    char *file_start; //points to the start of the file so we can free it later;
    char *index; // used to navigate inside the text file
} text_file;

