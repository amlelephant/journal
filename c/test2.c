/*
#include <stdio.h>

int main(){
    char str[50];

    scanf("%s", str);

    while (str) {
        printf("%c %u\n", str, str);
        str++;
    }
}
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main()
{
    
    
    int i, x;
    char name[1000] = ""; 
    
    
    
    scanf(" %[^\n]s", &name);
    
    
    size_t f = strlen(name); 
    struct Node *headNode, *currentNode, *temp;

    

    for (i = 0; i < f; i++)
    {
        //5
        currentNode = (struct Node *)malloc(sizeof(struct Node));

        
        currentNode->data = name[i];

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
    }

    temp->next = NULL;

    //10
    temp = headNode;

    //11
    printf("Iterating through the elements of the linked list : \n");
    while (temp != NULL)
    {
        //12

        //decrypt(temp->data)
        printf("%c \n", temp->data);
        temp = temp->next;
    }

   return 0;
}
