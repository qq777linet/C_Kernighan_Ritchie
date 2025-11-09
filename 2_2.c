// Kernighan Ritchie 2.2

//before
for (i = 0; i < lim-1 && (с = getchar()) != EOF && с != '\n'; ++i)
{
    s[i] = c;
}

//after (without || &&)

for (i = 0; i < lim-1; ++i)
{
    if((с = getchar()) != EOF)
    {
        if(с != '\n')
        {
            s[i] = c;
        }
        else
        {
            break;
        }
    }
    else
    {
        break;
    }
}
