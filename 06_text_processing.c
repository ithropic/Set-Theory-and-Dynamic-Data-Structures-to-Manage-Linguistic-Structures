#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "00_structures.h"




tree_node *create_node(char *phrase) 
{
    tree_node *n = (tree_node *)malloc(sizeof(tree_node));
    if (n == NULL)
    {
        return NULL;
    }
    n->phrase = phrase;
    n->lc = NULL;
    n->rc = NULL;

    return n;
}

char *extract_phrase(char **index) 
{
    char *extracted = NULL;
    char *delimiters = ".?!;";

   while ((**index == ' ' || **index == '\t' || strchr(delimiters, **index) != NULL) && **index != '\0')
    {
        (*index)++; // skip spaces and delimiters found at the begenning for safety 
    }
    int j = 0;
    while (strchr(delimiters, **(index)) == NULL && **(index) != '\0' && **index != '\n' && **index != '\r')
    {   // while not a delimiter or end of paragraph
        extracted = realloc(extracted, (j + 1) * sizeof(char));
            extracted[j] = **index; // copy the phrase character by character
            (*index)++;
            j++;
    }

    if (j == 0) // empty word
    {
        return NULL;
    }

    if (j > 0 && isspace(extracted[j - 1]))
    {
        j--;
    }
    
    extracted = realloc(extracted, (j + 1) * sizeof(char));
    extracted[j] = '\0';
  
        return extracted;
    
}

void insert_phrase(tree_node **r, tree_node *t) 
{
    if (*r == NULL)
    {
        *r = t;
        return;
    }
    int i = 0;
    int location = strcmp(t->phrase, (*r)->phrase);
    if (location == 0)
    {   
        free(t->phrase);
        free(t);
        return;
    }
    else
    {
        if (location < 0)
    {
        insert_phrase(&((*r)->lc), t);
        return;
    }
    else
    {
        insert_phrase(&((*r)->rc), t);
        return;
    }
    }   
}

void add_phrase(tree_node **r , char *phrase) /* tree_node **r here is 
                                                actually what's getting stored in the paragraph array
                                                ie, the pointer to the paragraph */
{
    tree_node *t = create_node(phrase);
    insert_phrase(r, t);
}


tree_node *extract_paragraph(char **index)
{
    tree_node *r = NULL;

    while (**index == '\n' || **index == '\r')
    {
        (*index)++; // skip new lines found at the beginning for safety
    }

    if (**index == '\0')
    {
        return r;
    }
    while (**index != '\n' && **index != '\r' && **index != '\0')
    {
        char *phrase = extract_phrase(index);
        if (phrase != NULL)
        {
        add_phrase(&r, phrase);
        }

        if (**index == '\n' || **index == '\r' || **index == '\0') 
        {
            break;
        }

        (*index)++;
        
    }
    return r;

}




