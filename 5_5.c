void strncpy(char* s, const char* t, int n)
{
  int length_s = strlen(s);
  int length_t = strlen(t);
  
  for(int i = 0; i < n; i++)
  {
    
      s[i] = t[i]; 
  }
  if(length_s >= length_t)
  {
    s[length_s] = '\0';
}
