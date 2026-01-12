//Kernighan&Ritchie 4.9

int buf; // buffer 

bool bufp = false; 

int getch(void) // take symbol
{
    if(bufp == true)
    {
        bufp = false;
        return buf;
    }
    else if (bufp == false)
    {
        return getchar();
    }
}

void ungetch(int c) 
{
    if(bufp == false)
    {
        buf = c;
        bufp = true;
    }
    else
    {
        printf("ungetch: too many characters\n");
    }
}
