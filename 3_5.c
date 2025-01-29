#include <math.h>

void itob(int n, char s[], int b) // n is a digit, s is a string, b is formar (decimal, binary or hexadecimal)
{
  int i = 0;
  if(n == 0)
  {
    s[i] = '0';
  }
  else
  {
    while(n > 0)
    {
      s[i] = (n%10) + '0';
      n = n/10;
      i++;
    }
  }
  s[i] = '\0';
  reverse(s);
}
