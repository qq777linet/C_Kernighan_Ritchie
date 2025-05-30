
double atof (char s[])
{
  double val, power;
  int i, sign;
  int dec = 0;
  for (i = 0; isspace (s[i]); i++)
    ; 
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
  {
    i++;
  }
  for (val = 0.0; isdigit (s[i]); i++)
  {
    val = 10.0 * val + (s[i] - '0');
  }
  if (s[i] =='.')
  {
    i++;
  }
  for (power = 1.0; isdigit(s[i]); i++) 
  {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  if (s[i] == 'e')
  {
    i++;
    while(isdigit(s[i]))
    {
      dec = dec*10 + (s[i] - '0');
      i++;
    }
  }
  return sign * pow(10,dec) * val / power;
}
