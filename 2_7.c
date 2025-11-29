//Kernighan&Ritchie 2.7 

int invert(int x, unsigned int p, unsigned int n) //invert n bits from p position, other bits are not changed
{
    
    unsigned int MASK_1 = 0;
    unsigned int temp_x = ~x;
    
    MASK_1 = ~MASK_1;
    
    MASK_1 = MASK_1<<n;
    
    MASK_1 = ~MASK_1;
    
    MASK_1 = MASK_1<<p;
    
    temp_x = MASK_1&temp_x; //inverted diapason, other zero

    MASK_1 = ~MASK_1;
    
    MASK_1 = x&MASK_1;
    
    temp_x = temp_x|MASK_1;
    
    return temp_x;
    
}
