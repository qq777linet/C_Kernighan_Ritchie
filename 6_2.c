#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD 45


typedef struct node
{
    char ch;
    struct node* ptr_array[26];
    int pass_count;
    bool end;
} node; 
int i_gl = 0;
int j_gl = 0;

node* main_array[26]; //initialization inside main function


char var_name[45] = { '\0' }; 
node* temp_ptr = NULL;

int getword(char* word, const char** input); //prototype of function that gets word 
int add_to_trie(char* word); //function that store var. names in trie
node* create_node(void); //prototype of function that creates node
int read_trie(node* temp_ptr, int main_count); // prototyoe of funct that prints some words from trie

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Error!\n");
        return 1;
    }
    int main_count = atoi(argv[1]);
    for (int i = 0; i < 26; i++) 
    {
        main_array[i] = NULL;
    }
    
    while(getword(var_name, stdin) > 0)
    {
        if((strcmp(var_name,"asm") == 0) || (strcmp(var_name,"auto") == 0) || (strcmp(var_name,"break") == 0) || (strcmp(var_name,"case") == 0) || (strcmp(var_name,"catch") == 0) || (strcmp(var_name,"char") == 0) || (strcmp(var_name,"class") == 0) || (strcmp(var_name,"const") == 0) || (strcmp(var_name,"continue") == 0) || (strcmp(var_name,"default") == 0) || (strcmp(var_name,"delete") == 0) || (strcmp(var_name,"do") == 0) || (strcmp(var_name,"double") == 0) || (strcmp(var_name,"else") == 0) || (strcmp(var_name,"enum") == 0) || (strcmp(var_name,"extern") == 0) || (strcmp(var_name,"float") == 0) || (strcmp(var_name,"for") == 0) || (strcmp(var_name,"friend") == 0) || (strcmp(var_name,"goto") == 0) || (strcmp(var_name,"if") == 0) || (strcmp(var_name,"inline") == 0) || (strcmp(var_name,"int") == 0) || (strcmp(var_name,"long") == 0) || (strcmp(var_name,"new") == 0) || (strcmp(var_name,"operator") == 0) || (strcmp(var_name,"private") == 0) || (strcmp(var_name,"protected") == 0) || (strcmp(var_name,"public") == 0) || (strcmp(var_name,"register") == 0) || (strcmp(var_name,"return") == 0) || (strcmp(var_name,"short") == 0) || (strcmp(var_name,"signed") == 0) || (strcmp(var_name,"sizeof") == 0) || (strcmp(var_name,"static") == 0) || (strcmp(var_name,"struct") == 0) || (strcmp(var_name,"switch") == 0) || (strcmp(var_name,"template") == 0) || (strcmp(var_name,"this") == 0) || (strcmp(var_name,"throw") == 0) || (strcmp(var_name,"try") == 0) || (strcmp(var_name,"typedef") == 0) || (strcmp(var_name,"typeid") == 0) || (strcmp(var_name,"union") == 0) || (strcmp(var_name,"unsigned") == 0) || (strcmp(var_name,"virtual") == 0) || (strcmp(var_name,"void") == 0) || (strcmp(var_name,"volatile") == 0) || (strcmp(var_name,"while") == 0))
        {
            ;
        }
        else
        {
            add_to_trie(var_name);
        }
    }
    
    
    return 0; //success, end of programm
}
 // functions.h


//function that read words from programm's text
int getword(char* word, const char** input) 
{
    const char* ptr = *input;
    int i = 0;

    // skip spaces
    while (isspace(*ptr)) 
    {
        ptr++;
    }

    // skips comments
    if (*ptr == '/') 
    {
        if (*(ptr + 1) == '/') 
        { // "//" type of comment
            while (*ptr != '\0' && *ptr != '\n') 
            {
                ptr++;
            }
        } 
        else if (*(ptr + 1) == '*') 
        { // "/*...*/ type of comment"
            ptr += 2; // Skip /*
            while (*ptr != '\0' && !(*ptr == '*' && *(ptr + 1) == '/')) 
            {
                ptr++;
            }
            if (*ptr == '*' && *(ptr + 1) == '/') 
            {
                ptr += 2; // skip */
            }
        }
    }

    // Skips strings constants 
    if (*ptr == '"') 
    {
        ptr++; // skips starting qoutation mark
        while (*ptr != '\0' && *ptr != '"') 
        {
            if (*ptr == '\\' && *(ptr + 1) != '\0') 
            { // skips escaped characters
                ptr += 2;
            } 
            else 
            {
                ptr++;
            }
        }
        if (*ptr == '"') 
        {
            ptr++; // skip end quotation mark
        }
    }

    // skip character literals
    if (*ptr == '\'') 
    {
        ptr++; // skip starting apostrophe
        if (*ptr == '\\' && *(ptr + 1) != '\0') 
        { // skip escaped character
            ptr += 2;
        } 
        else if (*ptr != '\0') 
        {
            ptr++;
        }
        if (*ptr == '\'') 
        {
            ptr++; // skip apostrophe at end
        }
    }

    // read word
    while (isalnum(*ptr) || *ptr == '_') 
    {
        word[i++] = *ptr++;
        if (i >= MAX_WORD - 1) 
        { // protects from words bigger than allowed
            break;
        }
    }

    word[i] = '\0'; // end of string

    // updates pointer at local position
    *input = ptr;

    // return length of word 
    return i;
} 

node* create_node(void) //creates node
{
    node* pointer = malloc(sizeof(node));
    if(pointer == NULL)
    {
        return NULL;
    }
    for(int i = 0; i<26; i++)
    {
        pointer->ptr_array[i] = NULL;
    }
    pointer->end = false;
    pointer->ch = '\0';
    pointer->pass_count = 0;
    return pointer;
}

int add_to_trie(char* word) //function which store var. names to trie
{
    int i = 0; //counter
    int j = word[i] - 'a'; //char counter (ASCII)
    if(main_array[j] == NULL)
    {
        main_array[j] = create_node();
    }
    temp_ptr = main_array[j];
    temp_ptr->ch = word[i];
    temp_ptr->pass_count ++;
    i++;
    while(word[i] != '\0')
    {
        j = word[i] - 'a';
        if(temp_ptr->ptr_array[j] == NULL)
        {
            temp_ptr->ptr_array[j] = create_node();
        }
        temp_ptr = temp_ptr->ptr_array[j];
        temp_ptr->ch = word[i];
        temp_ptr->pass_count ++;
        temp_ptr->end = false;
        i++;
    }
    temp_ptr->end = true;
    return 0;
}

int read_trie(node* temp_ptr, int main_count)
{
    i_gl = 0;
    j_gl = 0;
    
    if (temp_ptr == NULL) 
    {
        return 0;
    }
    if((temp_ptr->pass_count>=main_count) && (temp_ptr->end == false)) //A
    {
        printf("%c",temp_ptr->ch);
        temp_ptr->pass_count--;
        i_gl++;
        j_gl = 0;
        return read_trie(temp_ptr->ptr_array[j_gl], main_count);
    }
    else if((temp_ptr->pass_count>=main_count) && (temp_ptr->end == true)) //B
    {
        printf("%c",temp_ptr->ch);
        temp_ptr->pass_count--;
        i_gl = 0;
        j_gl = 0;
        return 0;
    }
    else if((temp_ptr->pass_count<main_count) && (temp_ptr->end == false)) //C
    {
        j_gl++;
        if (temp_ptr->ptr_array[j_gl] != NULL)
        {
            return read_trie(temp_ptr->ptr_array[j_gl], main_count);
        }
        return 0;

    }
    else if((temp_ptr->pass_count<main_count) && (temp_ptr->end == true))
    {
        j_gl++;
        while (j_gl < 26 && temp_ptr->ptr_array[j_gl] == NULL) 
        {
            j_gl++;
        }
        if (j_gl < 26) 
        {
            return read_trie(temp_ptr->ptr_array[j_gl], main_count);
        }
        return 0;  // No more nodes
    }
}
