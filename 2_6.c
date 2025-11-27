//Kernighan&Ritchie 2.6 

int setbits(int x, unsigned int p, unsigned int n, int y) 
{
    unsigned int temp = 0; 
    
    temp = ~temp; 
    
    temp = temp << n; 
    
    temp = ~temp; 
    
    temp = y&temp; 
    
    temp = temp << p; 
    
    unsigned int temp2 = 0;
    
    temp2 = ~temp2; 
    
    temp2 = temp2 << n;
    
    temp2 = ~temp2;
    
    temp2 = temp2 << p; 
    
    temp2 = ~temp2; 
    
    unsigned int temp3 = x&temp2;
    
    return temp3|temp;
}
