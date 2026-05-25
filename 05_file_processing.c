#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include "00_structures.h"
#include "01_text_processing.h"






text_file process_file()
{
    text_file new_file;
    new_file.file_start = read_file(); /* 
                                        * now the file_start field points the
                                        * the first character of the text file
                                        */  
    if (new_file.file_start == NULL)
    {
        printf("\n ERROR: check file path and try again.\n");

        printf("Press ENTER to close the program...");
        while(getchar() != '\n');
        getchar();
        exit(1);
    }

    new_file.index = new_file.file_start; /*
                                           * initializing the index to use it 
                                           * to navigate inside the file without loosing
                                           * the start of the file
                                           */
    new_file.paragraph_array = NULL;
    int j = 0;

    while (*new_file.index != '\0')
    {
        new_file.paragraph_array = realloc(new_file.paragraph_array, (j + 1) * sizeof(tree_node *));
        new_file.paragraph_array[j] = extract_paragraph(&new_file.index); /* populating the paragraph array 
                                                                           * of the current file
                                                                           */

        while (*new_file.index == '\n' || *new_file.index == '\r')
        {
            new_file.index++; // skipping continuous new lines
        }
        j++;    }
    new_file.paragraph_count = j;

    return new_file; /* returning the modified text_file structure 
                      *  to get stored as the i'th element of the file array
                      */ 
}

char *read_file()
{
    /* Actually, when the user paste the the text file, in the majority of 
        operating systems the absolute path will be inside double quotes
        (""). We need to remove the quotes first so that our C functions 
            can open the file properly*/

    char file_path[256];
    char clean_path[256];

    printf("Paste your file path here:\n> ");

    char loading_msg[50];
    sprintf(loading_msg, "Processing file...");
    
    if (fgets(file_path, sizeof(file_path), stdin) == NULL)
    {
        return NULL;
    }
    file_path[strcspn(file_path, "\r\n")] = '\0';

    int j = 0;
    for (int i = 0; file_path[i] != '\0'; i++)
    {
        if (file_path[i] != '\"')
        {
            clean_path[j++] =  file_path[i];
        }
    }
    clean_path[j] = '\0';

    FILE *file = fopen(clean_path, "r");
        if (file == NULL) 
    {
        printf("Couldn't open file at: %s\n", clean_path);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file,  0, SEEK_SET);

    if (file_size < 0)
    {
        printf("Error reading file size.\n");
        fclose(file);
        return NULL;
    }

    //allocating memory to read the file
    char *buffer = malloc((file_size + 1) * sizeof(char));
    /* 
     * Here a memory area is being allocated in to store the 
     * whole text of the file in one memory block. size + 1 becuase
     * we need an extra byte to store the null terminator '\0'
     * that indicates the ond of the text 
     */
      if (buffer == NULL)
      {
        printf("Memory allocation error.\n");
        fclose(file);
        return NULL;
      }
      size_t bytes_read = fread(buffer, sizeof(char), file_size, file);
      buffer[bytes_read] = '\0'; // to indicate the end of the file

      fclose(file);
      return buffer; // returning the start of the meory block to initialize file_start pointer

}


// printing the paragraphs
void display_inorder(tree_node *r)
{
    if (r != NULL)
    {
        display_inorder(r->lc);
        printf("%s", r->phrase);
        printf("\n");
        display_inorder(r->rc);
    }
    return;
}

void free_struct(text_file *file)
{
    for (int i = 0; i < (*file).paragraph_count; i++)
    {
        free_tree(&((file)->paragraph_array[i]));
    }
    free((*file).paragraph_array);
    if (file->file_start != NULL)
    {
    free((*file).file_start);
    }
}


void free_tree(tree_node **r)
{
    if (*r != NULL)
    {
        free_tree(&((*r)->lc));
        free_tree(&((*r)->rc));

        if ((*r)->phrase != NULL)
        {
            free((*r)->phrase);
        }

        free(*r);
    }
}