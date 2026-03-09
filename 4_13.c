//Kernighan&Ritchie 4/13 reverse with recursion 

void reverse_r(char s[], int left, int right)
{
    if((right-left) < 1)
    {
        ;
    }
    else
    {
        swap(s[left], s[right]);
        left++;
        right--;
        reverse_r(s, left, right);
    }
}

void reverse(char s[])
{
    int length = strlen(s);
    int left = 0;
    int right = length - 1;
   
    reverse_r(s, left, right);
   
}
