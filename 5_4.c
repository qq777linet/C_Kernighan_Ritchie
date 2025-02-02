void strend(char* s, char* t)
{
  int length_1 = strlen(s);
  int length_2 = strlen(t);

  for(int i = 0; i < length_2; i ++)
  {
    if(s[length_1 - length_2 + i] != t[i])
    {
      return 0; 
    }
  }
  return 1;
}
