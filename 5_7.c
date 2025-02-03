#define MAXLEN 1000

char strings[5000000];

int readlines(char* lineptr[], int maxlines)
{
  int len;
  int nlines = 0;
  char line[MAXLEN];
  int i = 0;

  while ((len = getline(line, MAXLEN)) > 0)
  {
    if (nlines >= maxlines)
    {
      return -1;
    }
    else 
    {
      line[len-1] = '\0';
      strcpy(&strings[i*1000], line);
      i ++;
      nlines ++;
    }
  }
  return nlines;
}
