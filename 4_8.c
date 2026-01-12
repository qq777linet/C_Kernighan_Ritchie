//Kernighan&Ritchie 4.8 

char buf; // buffer 

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

    buf = с;
    bufp = true;
}
