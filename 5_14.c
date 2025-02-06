#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 //max number of strings

char* lineptr[MAXLINES]; //pointers at strings

int readlines(char* lineptr[], int nlines);
void writelines(char* lineptr[], int nlines);
void r_writelines(char* lineptr[], int nlines);
void qsort(void* lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char*, char*);
int reverse = 0;

// strings sort
int main(int argc, char* argv[])
{
    int nlines; //counter of read strings
    int numeric = 0; /* 1, если сорт, по числ. знач. */
    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if (strcmp(argv[2], "-r") == 0)
    {
        reverse = 1;
    }
    
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) 
    {
        qsort((void **) lineptr, 0, nlines-1, (int (*)(void*, void*))(numeric ? numcmp : strcmp));
        if(reverse == 1)
        {
            r_writelines(lineptr, nlines);
            return 0;
        }
        else
        {
            writelines(lineptr, nlines);
            return 0;
        }
    } 
    else 
    {
        printf("Введено слишком много строк\n");
        return 1;
    }
}

void qsort(void* v[], int left, int right, int (*comp)(void *, void *)) 
{
    int i; // counter for sorting loop
    int last; // work element
    void swap(void* v[], int, int); //function that swaps two elements

    if (left >= right)  // Если элементов 1 или 0, выход
    {
        return;
    }
    
    swap(v, left, (left + right) / 2);  // first element becomes middle element 
    last = left; // defines work element (that element firstly was middle)

    for (i = left + 1; i <= right; i++) 
    {
        if ((*comp)(v[i], v[left]) < 0)  // if i-element is smaller that work element
        {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last); // now work element(pivot) is at his place (elements left are smaller,right are bigger)
    qsort(v, left, last - 1, comp);
    qsort(v, last + 1, right, comp);
}

void r_writelines(char* lineptr[], int nlines) 
{
    for (int i = nlines - 1; i >= 0; i--) 
    {
        printf("%s\n", lineptr[i]);
    }
}


