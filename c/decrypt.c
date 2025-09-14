
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int decrypt(char *sentence);



struct decrypted {
    int data;
    struct decrypted *next;
};

int main()
{
    char *path;
    char line[MAX_LINE_LENGTH];
    unsigned int line_count = 0;
    char c;
    int count = 0;
    int x = 0;
    
    
    
    path = "C:/Users/Aiden/Desktop/Christmas List/New folder/c/mineremake/homework.txt";
    
    /* Open file */
    FILE *file = fopen(path, "r");
    
    if (!file)
    {
        perror(path);
        return EXIT_FAILURE;
    }
    
    c = getc(file);
    
    
    
    
    char *linelist[100];

    //decrypt("k");
    
    while (fgets(line, sizeof(line), file)) {
        int len;
        for (len = 0; line[len] != '\n' && line[len] != 0; len++) { }
        char* new_line = malloc(len + 1);
        for (int i = 0; i < len; i++)
         new_line[i] = line[i];
        new_line[len] = 0;
        
        //puts(new_line);
        decrypt(new_line);
        linelist[x] = new_line;
        x += 1;
        //printf("%s", line); 
    }
    //printf("%s", linelist[0]);

    
    
    

    
    
    return 0;
    
}

int decrypt(char *sentence){
   
    
    

    struct decrypted *headNode, *currentNode, *temp;
    int len = strlen(sentence);
    int i;

    
    
    for (i = 0; i < len; i++)
    {
        int l = sentence[i];
        char fin;
        //printf("%c", l);


        if (l == 107)
        {
            fin = 'a';
        }
        if (l == 111)
        {
            fin = 'b';
        }
        if (l == 102)
        {
            fin = 'c';
        }
        if (l == 113)
        {
            fin = 'd';
        }
        if (l == 120)
        {
            fin = 'e';
        }
        if (l == 97)
        {
            fin = 'f';
        }
        if (l == 103)
        {
            fin = 'g';
        }
        if (l == 116)
        {
            fin = 'h';
        }
        if (l == 121)
        {
            fin = 'i';
        }
        if (l == 100)
        {
            fin = 'j';
        }
        if (l == 99)
        {
            fin = 'k';
        }
        if (l == 118)
        {
            fin = 'l';
        }
        if (l == 114)
        {
            fin = 'm';
        }
        if (l == 122)
        {
            fin = 'n';
        }
        if (l == 101)
        {
            fin = 'o';
        }
        if (l == 104)
        {
            fin = 'p';
        }
        if (l == 112)
        {
            fin = 'q';
        }
        if (l == 119)
        {
            fin = 'r';
        }
        if (l == 117)
        {
            fin = 's';
        }
        if (l == 105)
        {
            fin = 't';
        }
        if (l == 109)
        {
            fin = 'u';
        }
        if (l == 98)
        {
            fin = 'v';
        }
        if (l == 110)
        {
            fin = 'w';
        }
        if (l == 115)
        {
            fin = 'x';
        }
        if (l == 106)
        {
            fin = 'y';
        }
        if (l == 108)
        {
            fin = 'z';
        }
        if (l == 65)
        {
            fin = ' ';
        }
        if (l == 78)
        {
            fin = ' ';
        }
        if (l == 73)
        {
            fin = ' ';
        }
        if (l == 76)
        {
            fin = ' ';
        }
        if (l == 82)
        {
            fin = ' ';
        }


        currentNode = (struct decrypted *)malloc(sizeof(struct decrypted));

        
        currentNode->data = fin;

        //7
        if (i == 0)
        {
            headNode = temp = currentNode;
        }
        else
        {
            //8
            temp->next = currentNode;
            temp = currentNode;
        }

        temp->next = NULL;

    
        
    }
    //10
    temp = headNode;

    //11
    
    while (temp != NULL)
    {
        //12

        
        printf("letter: %c \n", temp->data);
        temp = temp->next;
    }
    
    
    
}
