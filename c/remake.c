#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

//vars
char divider[100] = "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ \n";
FILE *fptr;

int mainboot();
int patch();
int scource();
int encrypt();
int write_time();
int write_file(char ch);
int archives();


int main()
{
    char pass[50];
    char pass2[20];
    printf("Let me take your hand and I will give you mine: ");
    scanf(" %[^\n]s", pass);
    
    if (strcmp(pass, "lead the way") == 0)
    {   
        
        printf("Password: ");
        scanf(" %[^\n]s", pass2);
        
        
        if (strcmp(pass2, "cam") == 0)
        {
            printf("access granted... \n");
            printf("Booting software... \n");
            mainboot();
        }
        
        
        
    }
    
    return 0;
}

int mainboot(){


    //vars
    int op;



    
    /*
    printf("                .__________________________.\n");
    sleep(1);
    printf("                | .___________________. |==|\n");
    sleep(1);
    printf("                | |     [ Apple ]     | |  |\n");
    sleep(1);
    printf("                | |        {          | |  |\n");
    sleep(1);
    printf("                | |  A hidden library | |  |\n");
    sleep(1);
    printf("                | |with secrets untold| |  |\n");
    sleep(1);
    printf("                | |  you must promise | |  |\n");
    sleep(1);
    printf("                | |    it's mystery   | |  |\n");
    sleep(1);
    printf("                | |   you must hold   | | ,|\n");
    sleep(1);
    printf("                | |         }         | |  |\n");
    sleep(1);
    printf("                | !___________________! |(c|\n");
    sleep(1);
    printf("                !_______________________!__!\n");
    sleep(1);
    printf("                |    ___ -=      ___ -= | ,|\n");
    sleep(1);
    printf("                | ---[_]---   ---[_]--- |(c|\n");
    sleep(1);
    printf("\n");
    printf("                !_______________________!__!\n");
    sleep(1);
    printf("               /                            \ \n");
    sleep(1);
    printf("              /  [][][][][][][][][][][][][]  \ \n");
    sleep(1);
    printf("             /  [][][][][][][][][][][][][][]  \ \n");
    sleep(1);
    printf("            (  [][][][][____________][][][][]  ) \n");
    sleep(1);
    printf("             \ ------------------------------ / \n");
    sleep(1);
    printf("              \______________________________/ \n");
    */



    sleep(1);
    printf("\n");
    printf("Welcome back Aiden or another authorised user \n");
    printf("Options: \n");
    printf("[1] The Archives\n");
    printf("[2] extra\n");
    printf("[3] extra\n");
    printf("[4] Scource Code\n");
    printf("[5] patch notes\n");
    printf("[6] Screen Saver\n");
    printf("[7] Exit\n");
    printf("\n");

    printf("--> ");
    
    scanf("%d", &op);
    
    
    printf("\n");
    if (op == 1)
    {
        archives();
    }
    
    if (op == 4)
    {
        scource();
    }
    if (op == 5)
    {
        patch();
    }
    if (op == 6)
    {
        printf("Feature coming soon\n");
    }
    if (op == 7)
    {
        exit(0);
    }
    
    
}


/*--------------------secondary options--------------------*/

int patch(){

    
    
    printf(divider);

    printf("Please note that these are only the patch notes for the version you are currently using (C) \n");
    printf("\n");
    printf("-----Software framework----- \n");
    printf("\n");
    printf("v1.0 - To make this is had to learn the basic syntax of the language C. Parts of this was the preliminary passwords and the navagation system used to search through the system. It took me about 2 hours to complete this stage. This was completed on 5/14/22.\n");
    printf("v1.2 - Some bug fixes with the user input. After you finish your task you now loop back to the main boot of the software. This took me about 30 minutes. This was completed on 5/21/22.\n");
    printf("\n");
    printf("-----Archives-----\n");
    printf("\n");
    printf("Journal Logger\n");
    printf("v1.0 - For this I basically had all of the logic stuff covered in python so I just basically had to just translate it to c. I had some trouble with input reading previous line endings. I fixed that but it caused me a lot of trouble. I also implemented writing to a file with the date that is properly formated. It took me about 1 hour. This was completed on 5/19/22.\n");
    printf("\n");
    mainboot();
}

int scource(){

    //vars
    int scrop;

    printf(divider);


    printf("\n");
    printf("The version you are currently using is v2.0, written in C \n");
    printf("\n");


    printf("[1] Python \n");
    printf("[2] C\n");
    printf("[3] Home\n");
    printf("\n");


    printf("--> ");
    scanf("%d", &scrop);

    if (scrop == 1)
    {
        printf("Scource code here");
    }
    if (scrop == 2)
    {
        printf("Scource code here");
    }
    if (scrop == 3)
    {
        mainboot();
    }
    mainboot();
    
}

int archives()
{
    int archopt;
    char test[100];

    printf(divider);

    printf("\n");
    printf("[1] Write Journal Entry\n");
    printf("[2] Search Journal Entries\n");
    printf("[3] Home\n");
    printf("\n");


    printf("--> ");
    
    scanf("%d", &archopt);

    if (archopt == 1)
    {
        encrypt();
    }
    if (archopt == 2)
    {
        printf("feature coming soon");
    }
    if (archopt == 3)
    {
        mainboot();
    }
    mainboot();
    
    
}


/*-------------------end secondary options--------------*/

/*------------------encrypt function-------------------*/


int encrypt() {


    int vals[1000];
    int e;
    int result[1000];
    char name[1000] = ""; 
    printf(divider);
    printf("\n");
    printf("What would you like me to encrypt for you today sir : ");

    scanf(" %[^\n]s", &name);
    printf("\n");
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
    
    
    
    fptr = fopen("C:/Users/Aiden/Desktop/Christmas List/New folder/c/mineremake/homework.txt","a+");
    

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
    fptr = fopen("C:/Users/Aiden/Desktop/Christmas List/New folder/c/mineremake/homework.txt","a+");

    if(fptr == NULL)
    {
        printf("Error!");   
        exit(1);             
    }

    fprintf(fptr,"\n%d/%02d/%02d- ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    return 0;
}

/*------------------end encrypt funciton------------------*/