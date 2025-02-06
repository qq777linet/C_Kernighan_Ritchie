#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 //max number of strings

char* lineptr[MAXLINES]; //pointers at strings

int readlines(char* lineptr[], int nlines);
void writelines(char* lineptr[], int nlines);
void qsort(void* lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char*, char*);
int case_sens = 1; // case sensitivity

//strings sort
int main(int argc, char* argv[])
{
    int nlines; //counter of read strings
    int numeric = 0; 
    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
        
    if (strcmp(argv[2],"-f") == 0)
    {
        case_sens = 0;
    }
    
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) 
    {
        if(numeric == 1)
        {
            qsort((void **) lineptr, 0, nlines-1, (int (*)(void*, void*))(numcmp));
        }
        else if (case_sens == 0)
        {
            qsort((void **) lineptr, 0, nlines-1, (int (*)(void*, void*))(case_uns_strcmp));
        }
        else
        {
            qsort((void **) lineptr, 0, nlines-1, (int (*)(void*, void*))(strcmp));
        }
        writelines(lineptr, nlines);
        return 0;
    } 
    else 
    {
        printf("Введено слишком много строк\n");
        return 1;
    }
}

void qsort(void* v[], int left, int right, int (*comp)(void *, void *)) 
{
    int i, last;
    void swap(void* v[], int, int);

    if (left >= right)  
    {
        return;
    }
    
    swap(v, left, (left + right) / 2);  
    last = left;

    for (i = left + 1; i <= right; i++) 
    {
        if ((*comp)(v[i], v[left]) < 0)  
        {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);
    qsort(v, left, last - 1, comp);
    qsort(v, last + 1, right, comp);
}

int strcmp(const char *str1, const char *str2) 
{
    while (*str1 && (*str1 == *str2)) 
    {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

int case_uns_strcmp(const char *str1, const char *str2) 
{
    while (*str1 && (tolower(*str1) == tolower(*str2))) 
    {
        str1++;
        str2++;
    }
    return tolower(*(unsigned char*)str1) - tolower(*(unsigned char*)str2);
}


