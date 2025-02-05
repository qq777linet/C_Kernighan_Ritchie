int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Error!\n");
        return 1;
    }
    
    int tail_count = atoi(argv[1]);
    if(tail_count>=1000)
    {
        printf("Error!\n");
        return 1; 
    }
    char* strings[1000];
    for(int i = 0; i<1000; i++)
    {
        strings[i] = NULL;
    }
    int str_count = 0;
    size_t len[1000] = {0};
    
    printf("Enter text:\n");
    
    while(getline(&strings[str_count], &len[str_count], stdin) != (-1))
    {
        str_count ++;
        if(str_count == 1000)
        {
            break;
        }
    }
    
    for(int i = 0; i < tail_count; i++)
    {
        printf("%s\n", strings[str_count - i]);
    }
    
    for(int i = 0; i < str_count; i++)
    {
        free(strings[i]);
    }
    return 0;
}
