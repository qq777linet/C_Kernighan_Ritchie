int main(int argc, char* argv[])
{
  int stack[10];
  int i = 1; //argv counter
  int j = 0; //carriage in stack
  int result;
while (i < argc && !(strcmp(argv[i], "+") == 0 || strcmp(argv[i], "-") == 0 ||
                     strcmp(argv[i], "*") == 0 || strcmp(argv[i], "/") == 0))
  {
    stack[j] = atoi(argv[i]);
    i++;
    j++;
  }
  while(i < (argc))
  {
      if (strcmp(argv[i], "+") == 0)
      {
          result = stack[j - 1] + stack[j - 2];
          stack[j - 1] = result;
          i++;
          j--;
      }
      else if (strcmp(argv[i], "-") == 0)

      {
          result = stack[j - 1] - stack[j - 2];
          stack[j - 1] = result;
          i++;
          j--; 
      }
      else if (strcmp(argv[i], "*") == 0)

      {
          result = stack[j - 1] * stack[j - 2];
          stack[j - 1] = result;
          i++;
          j--; 
      }
      else if (strcmp(argv[i], "/") == 0)

      {
          result = stack[j - 1] / stack[j - 2];
          stack[j - 1] = result;
          i++;
          j--; 
      }
  }
  printf("%d\n",result);
  return result;
}
