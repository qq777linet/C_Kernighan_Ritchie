#define HASHSIZE 101
static struct nlist* hashtab[HASHSIZE];

unsigned hash(char* s)
{
    unsigned int hashval;
    for (hashval = 0; *s != '\0'; s++)
    {
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

struct nlist 
{ 
    struct nlist* next; //pointer to next element
    char* name; //name
    char* defn; //text
};


struct nlist* lookup(char* s)
{
    struct nlist* np; //new pointer
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    {
        if (strcmp(s, np->name) == 0)
        {
            return np; // name is founded, returns pointer to structure with that name
        }
    }
    return NULL; // name is not founded
}

// puts name and text to table
struct nlist* install(char* name, char* defn)
{
    struct nlist* np; //new pointer
    unsigned int hashval; // hashvalue
    if ((np = lookup(name)) == NULL) //if name is not founded
    { 
        np = (struct nlist*) malloc(sizeof(*np)); //creates now structure ant pointer to it
        if (np == NULL || (np->name = strdup(name)) == NULL)
        {
            return NULL; //memory error
        }
        hashval = hash(name); //hash new name
        np->next = hashtab[hashval]; 
        hashtab[hashval] = np;
    } 
    else //name already exists
    {
        free((void*) np->defn);  
    }
    if ((np->defn = strdup(defn)) == NULL)
    {
        return NULL;
    }
    return np;
}

int undef(char* name)
{
    struct nlist* tmp_ptr; 
    struct nlist* tmp_ptr_2 = NULL;
    struct nlist* start_ptr = NULL;
    if((tmp_ptr = lookup(name)) == NULL)
    {
        printf("Name does not exists in table\n");
        return 1;
    }
    else
    {
        unsigned int hashvalue = hash(name);
        start_ptr = hashtab[hashvalue];
        if(start_ptr == tmp_ptr)
        {
            if(start_ptr->next == NULL)
            {
                free(tmp_ptr->name);
                free(tmp_ptr->defn);
                free(tmp_ptr);  
                hashtab[hashvalue] = NULL;
                return 0;
            }
            else
            {
                hashtab[hashvalue] = tmp_ptr->next;
                free(tmp_ptr->name);
                free(tmp_ptr->defn);
                free(tmp_ptr);  
                return 0;
            }
        }
        while(start_ptr->next != tmp_ptr)
        {
            tmp_ptr_2 = start_ptr;
            start_ptr = tmp_ptr_2->next;
        }
        if(tmp_ptr->next == NULL)
        {
            start_ptr->next = NULL;
            free(tmp_ptr->name);
            free(tmp_ptr->defn);
            free(tmp_ptr);  
            return 0;
        }
        else
        {
            start_ptr->next = tmp_ptr->next;
            free(tmp_ptr->name);
            free(tmp_ptr->defn);
            free(tmp_ptr);  
            return 0;
        }
    }
}
