#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
    char ch;
    char password[20];
    char saved_pass[20] = "";
    int i = 0;
    int attempts = 0;
    const int max_attempts = 3;
    // First, check if password.txt exists and has content
    FILE * ptr = fopen("password.txt", "r");
    if(ptr == NULL || fscanf(ptr, "%s", saved_pass) != 1 || strlen(saved_pass) == 0){
        if(ptr != NULL) fclose(ptr);
        printf("No saved password found. Please set a new password: ");
        i = 0;
        while (1)
        {
            ch = getch();
            if (ch == 13)//ascii of enter(\n)
            {
                saved_pass[i] = '\0';
                break;
            }
            else if (ch == 8)//ascii of backspace
            {
                if (i > 0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            else
            {
                if(i < 19)
                {
                    saved_pass[i++] = ch;
                    printf("*");
                }
            }
        }
        printf("\n");
        ptr = fopen("password.txt", "w");
        if(ptr == NULL){
            printf("Error: Cannot create password.txt\n");
            return 1;
        }
        fprintf(ptr, "%s", saved_pass);
        fclose(ptr);
        printf("Password set successfully. Please login.\n");
    }
    else{
        fclose(ptr);
    }

    // Now, login loop
    while(attempts < max_attempts){
        i = 0;
        printf("Enter Password: ");
        while (1)
        {
            ch = getch();
            if (ch == 13)
            {
                password[i] = '\0';
                break;
            }
            else if (ch == 8)
            {
                if (i > 0)
                {
                    i--;
                    printf("\b \b");
                }
            }
            else
            {
                if(i < 19)
                {
                    password[i++] = ch;
                    printf("*");
                }
            }
        }
        printf("\nEntered password : %s\n", password);
        int l = strcmp(password, saved_pass);
        if(l == 0){
            printf("LOGIN SUCCESS\n");
            return 0;
        }
        else{
            attempts++;
            if(attempts < max_attempts){
                printf("WRONG PASSWORD\n");
            }
            else{
                printf("Too many failed attempts. Exiting.\n");
            }
        }
    }

    return 0;
}