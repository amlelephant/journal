

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int write_file(char ch);
int write_time();

FILE *fptr;

int main() {

   
    int vals[1000];
    int e;
    int result[1000];
    char name[1000] = ""; 
    printf("Encrypt : \n");
    
    scanf("%[^\n]s", name);
    //printf("%s", name);
    size_t len = strlen(name); 

    for (size_t i = 0; i < len; i++) { 
        e = name[i];
        
        vals[i] = e;
        
    }
    
    for (size_t j = 0; j < len; j++ ) {
        int l = vals[j];
        char fin;
        //printf("yes");
        //printf("Element[%d] = %d\n", j, vals[j] );
        if (l == 97)
        {
            fin = 'k';
            result[j] = fin;
        }
        if (l == 98)
        {
            fin = 'o';
            result[j] = fin;
        }
        if (l == 99)
        {
            fin = 'f';
            result[j] = fin;
        }
        if (l == 100)
        {
            fin = 'q';
            result[j] = fin;
        }
        if (l == 101)
        {
            fin = 'x';
            result[j] = fin;
        }
        if (l == 102)
        {
            fin = 'a';
            result[j] = fin;
        }
        if (l == 103)
        {
            fin = 'g';
            result[j] = fin;
        }
        if (l == 104)
        {
            fin = 't';
            result[j] = fin;
        }
        if (l == 105)
        {
            fin = 'y';
            result[j] = fin;
        }
        if (l == 106)
        {
            fin = 'd';
            result[j] = fin;
        }
        if (l == 107)
        {
            fin = 'c';
            result[j] = fin;
        }
        if (l == 108)
        {
            fin = 'v';
            result[j] = fin;
        }
        if (l == 109)
        {
            fin = 'r';
            result[j] = fin;
        }
        if (l == 110)
        {
            fin = 'z';
            result[j] = fin;
        }
        if (l == 111)
        {
            fin = 'e';
            result[j] = fin;
        }
        if (l == 112)
        {
            fin = 'h';
            result[j] = fin;
        }
        if (l == 113)
        {
            fin = 'p';
            result[j] = fin;
        }
        if (l == 114)
        {
            fin = 'w';
            result[j] = fin;
        }
        if (l == 115)
        {
            fin = 'u';
            result[j] = fin;
        }
        if (l == 116)
        {
            fin = 'i';
            result[j] = fin;
        }
        if (l == 117)
        {
            fin = 'm';
            result[j] = fin;
        }
        if (l == 118)
        {
            fin = 'b';
            result[j] = fin;
        }
        if (l == 119)
        {
            fin = 'n';
            result[j] = fin;
        }
        if (l == 120)
        {
            fin = 's';
            result[j] = fin;
        }
        if (l == 121)
        {
            fin = 'j';
            result[j] = fin;
        }
        if (l == 122)
        {
            fin = 'l';
            result[j] = fin;
        }
        if (l == 32)
        { 
            
            srand(time(NULL));
            int ran = rand() % 5;
            if (ran == 0)
            {   
                fin = 'R';
                result[j] = fin;
            }
            if (ran == 1)
            {   
                fin = 'A';
                result[j] = fin;
            }
            if (ran == 2)
            {   
                fin = 'N';
                result[j] = fin;
            }
            if (ran == 3)
            {   
                fin = 'I';
                result[j] = fin;
            }
            if (ran == 4)
            {   
                fin = 'L';
                result[j] = fin;
            }
            
            
            
        }
        if (l == 46)
        {
            fin = '.';
            result[j] = fin;
        }
        if (l == 33)
        {
            fin = '!';
            result[j] = fin;
        }
        if (l == 63)
        {
            fin = '?';
            result[j] = fin;
        }
        if (l == 49)
        {
            fin = '@';
            result[j] = fin;
        }
        if (l == 50)
        {
            fin = '#';
            result[j] = fin;
        }
        if (l == 51)
        {
            fin = '$';
            result[j] = fin;
        }
        if (l == 52)
        {
            fin = '%';
            result[j] = fin;
        }
        if (l == 53)
        {
            fin = '^';
            result[j] = fin;
        }
        if (l == 54)
        {
            fin = '&';
            result[j] = fin;
        }
        if (l == 55)
        {
            fin = '*';
            result[j] = fin;
        }
        if (l == 56)
        {
            fin = '(';
            result[j] = fin;
        }
        if (l == 57)
        {
            fin = ')';
            result[j] = fin;
        }
        if (l == 48)
        {
            fin = '0';
            result[j] = fin;
        }
        if (l == 40)
        {
            fin = '8';
            result[j] = fin;
        }
        if (l == 41)
        {
            fin = '+';
            result[j] = fin;
        }
        if (l == 42)
        {
            fin = '7';
            result[j] = fin;
        }
        if (l == 38)
        {
            fin = '6';
            result[j] = fin;
        }
        if (l == 94)
        {
            fin = '5';
            result[j] = fin;
        }
        if (l == 37)
        {
            fin = '4';
            result[j] = fin;
        }
        if (l == 36)
        {
            fin = '3';
            result[j] = fin;
        }
        if (l == 35)
        {
            fin = '2';
            result[j] = fin;
        }
        if (l == 64)
        {
            fin = '1';
            result[j] = fin;
        }
        if (l == 34)
        {
            fin = '|';
            result[j] = fin;
        }
        if (l == 65)
        {
            fin = 'K';
            result[j] = fin;
        }
        if (l == 66)
        {
            fin = 'O';
            result[j] = fin;
        }
        if (l == 67)
        {
            fin = 'F';
            result[j] = fin;
        }
        if (l == 68)
        {
            fin = 'Q';
            result[j] = fin;
        }
        if (l == 69)
        {
            fin = 'X';
            result[j] = fin;
        }
        if (l == 70)
        {
            fin = '<';
            result[j] = fin;
        }
        if (l == 71)
        {
            fin = 'G';
            result[j] = fin;
        }
        if (l == 72)
        {
            fin = 'T';
            result[j] = fin;
        }
        if (l == 73)
        {
            fin = 'Y';
            result[j] = fin;
        }
        if (l == 74)
        {
            fin = 'D';
            result[j] = fin;
        }
        if (l == 75)
        {
            fin = 'C';
            result[j] = fin;
        }
        if (l == 76)
        {
            fin = 'V';
            result[j] = fin;
        }
        if (l == 77)
        {
            fin = '>';
            result[j] = fin;
        }
        if (l == 78)
        {
            fin = 'Z';
            result[j] = fin;
        }
        if (l == 79)
        {
            fin = 'E';
            result[j] = fin;
        }
        if (l == 80)
        {
            fin = 'H';
            result[j] = fin;
        }
        if (l == 81)
        {
            fin = 'P';
            result[j] = fin;
        }
        if (l == 82)
        {
            fin = 'W';
            result[j] = fin;
        }
        if (l == 83)
        {
            fin = 'U';
            result[j] = fin;
        }
        if (l == 84)
        {
            fin = ']';
            result[j] = fin;
        }
        if (l == 85)
        {
            fin = 'M';
            result[j] = fin;
        }
        if (l == 86)
        {
            fin = 'B';
            result[j] = fin;
        }
        if (l == 87)
        {
            fin = '{';
            result[j] = fin;
        }
        if (l == 88)
        {
            fin = 'S';
            result[j] = fin;
        }
        if (l == 89)
        {
            fin = 'J';
            result[j] = fin;
        }
        if (l == 90)
        {
            fin = '[';
            result[j] = fin;
        }
        if (l == 58)
        {
            fin = '}';
            result[j] = fin;
        }
        if (l == 44)
        {
            fin = '/';
            result[j] = fin;
        }
        if (l == 47)
        {
            fin = ',';
            result[j] = fin;
        }
        if (l == 39)
        {
            fin = '_';
            result[j] = fin;
        }
        if (l == 61)
        {
            fin = '`';
            result[j] = fin;
        }



        
        
        
        
    }

    

   
    write_time();
    for (size_t k = 0; k < len; k++ ) 
    {   
        //putchar(result[k]);
        write_file(result[k]);
    }
    
    return 0;
}

int write_file(char ch)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    printf("%c", ch);
    
    
    
    fptr = fopen("REPLACE HERE","a+");
    

    if(fptr == NULL)
    {
        printf("Error!");   
        exit(1);             
    }

    

    fprintf(fptr,"%c",ch);
    
    

    return 0;
}

int write_time()
{

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fptr = fopen("REPLACE HERE","a+");

    if(fptr == NULL)
    {
        printf("Error!");   
        exit(1);             
    }

    fprintf(fptr,"\n%d/%02d/%02d- ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    return 0;
}




