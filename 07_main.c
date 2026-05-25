#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h> // for menu animations
#include "03_interface.h"
#include "00_structures.h"
#include "02_operations.h"
#include "01_text_processing.h"


int main(int argc, char *argv[]) //free the allocated memory.
{
    // initializing the terminal
    if (argc == 1) {
        char command[512];
        
        
        snprintf(command, sizeof(command), "start \"\" /max cmd /k \"%s\" launched", argv[0]);
        
        system(command);
        return 0; 
        }  
    int choice;
    int number_files;

    // Animation start
    system("cls");
    print_banner();
    loading_bar("Initializing...");

    // Requesting number of files
    printf("Enter the number of files: ");
    scanf("%d", &number_files);
    if (number_files <= 0)
    {
        printf("Invalid input.\n");
        return 1;
    }


    while (getchar() != '\n'); //this removes the '\n' caused by hitting the enter key
                                // so that fgets() can work properly

    text_file file[number_files];

    for (int i = 0; i < number_files; i++)
    {
        // storing each file in the file array
        file[i] = process_file();
    }
    Sleep(1000);

    // displaying the main menu
    int first_menu_load = 1;
    do {
        // menu animation code
        system("cls");
        print_banner();

        char menu_header[50];
        sprintf(menu_header, "   [ %d FILES LOADED ]\n", number_files);

       if (first_menu_load == 1) {
            animate_text(menu_header, 5);
            animate_text("═════════════════════════════\n", 5);
            animate_text(" 1. Intersection (A n B)\n", 5);
            animate_text(" 2. Union (A u B)\n", 5);
            animate_text(" 3. Difference (A \\ B)\n", 5);
            animate_text(" 4. Exit\n", 5);
            animate_text("═════════════════════════════\n", 5);

            first_menu_load = 0;
       }
       else
       {
        printf("%s", menu_header);
            printf("═════════════════════════════\n");
            printf(" 1. Intersection (A n B)\n");
            printf(" 2. Union (A u B)\n");
            printf(" 3. Difference (A \\ B)\n");
            printf(" 4. Exit\n");
            printf("═════════════════════════════\n");
       }
        choice = get_flickering_choice();

        if (choice >= 1 && choice <= 3)
        {
        int f1, f2, p1, p2;
            if (number_files != 1)
            {
                printf("Select which file for set A: ");
                scanf("%d", &f1);
                printf("Select a paragraph: ");
                scanf("%d", &p1);

                printf("Select which file for set B: ");
                scanf("%d", &f2);
                printf("Select a paragraph: ");
                scanf("%d", &p2);
                f1--; // zero based indexing 
                f2--; // paragraph n is located in index n - 1
            }
            else
            {
                f1 = 0;
                f2 = 0; // f1 = f2 (only one file)
                printf("Select paragraph A: ");
                scanf("%d", &p1);
                printf("Select paragraph B: ");
                scanf("%d", &p2);
            }
            p1--;
            p2--;

            if (f1 < 0 || f1 >= number_files || f2 < 0 || f2 >= number_files)
            {
                printf("\nFile doesn't exist. Press Enter to continue...\n");
                printf("\n");
                while(getchar() != '\n');
                getchar(); 
            }
            else
            {
            if ((p1 >= 0 && p1 < file[f1].paragraph_count) && (p2 >= 0 && p2 < file[f2].paragraph_count))
            {
                // O(1) access time.
            tree_node *paragraphA = file[f1].paragraph_array[p1]; 
            tree_node *paragraphB = file[f2].paragraph_array[p2]; 
            tree_node *result = NULL; // contains final result   
            
                  

        switch(choice) 
        {
            case 1:
            result = intersection(paragraphA, paragraphB);
            break;
            case 2:
            result = union_op(paragraphA, paragraphB);
            break;
            case 3:
            result = difference(paragraphA, paragraphB);
            break; 
        }
        printf("\n");

        if (result != NULL)
        {
        display_inorder(result);
        free_tree(&result);
        }
        else
        {
            if (choice == 1)
            {
            printf("The insersection is empty ∅\n");
            }
            else
            {
                if (choice == 3)
                {
                    printf("The difference is empty ∅\n");
                }
            }
        }

         printf("\nOperation complete! Press Enter to continue...\n");
        printf("\n");
        while(getchar() != '\n');
        getchar();
    
    } else
    {
        printf("\nParagraph doesn't exist. Press Enter to continue...\n");
         printf("\n");
        while(getchar() != '\n');
        getchar();      
    } 
}
}
        
    } while (choice != 4);

     for (int i = 0; i < number_files; i++)
        {
            free_struct(&file[i]);
        }


    return 0;
 
}

