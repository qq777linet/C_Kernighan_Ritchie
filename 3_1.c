int binsearch(int x, int array[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1 ;
    mid = (low + high) / 2;
    while (x != array[mid] && high>low) 
    {
        mid = (low + high) / 2;
        if (x > array[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return mid; 
}
