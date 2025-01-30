int strindex (char s[], char t[])
{
  int i, j, k;
  int current_enter = -1;
  for (i = 0; s[i] != '\0'; i++) 
  {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
    {
      ;
    }
    if (k > 0 && t[k] == '\0')
    {
      current_enter = i;
    }
 }
if(current_enter != -1)
{
  return current_enter;
}
  return -1;
}
