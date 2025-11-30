//Kernighan&Ritchie 3.1

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    while(low<=high&&x!=v[mid])
    {
        (x > v[mid])?(low = mid + 1):(high = mid - 1);
        mid = (low + high) / 2;
    }
    
    if(v[mid] == x)
    {
        return mid;
    }
    else
    {
        return -1;
    }
        
} 
