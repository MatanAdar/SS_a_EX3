#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30
#define Line_in_txt 250

int get_line(char s[])
{
    for (int i = 0; i < LINE; i++)
    {
        s[i] = (char) 0;
    }

    int count = 0;

    for (int i = 0; i < LINE; i++)
    {
        if(scanf("%c", &s[i])<1){
            break;
        }
        else{
            count++;
            if (s[i] == '\n'||s[i]=='\r')
            {
                s[i] = '\0';
                break;
            }
        }
    }
    return count;
}

int getword(char w[])
{
    for (int i = 0; i < WORD; i++)
    {
        w[i] = (char) 0;
    }

    int count = 0;
   
    for (int i = 0; i < WORD; i++)
    {
        if(scanf("%c", &w[i])<1){
            break;
        }
        else{
            if (w[i] == '\n' || w[i] == '\t' || w[i] == ' '||w[i]=='\r')
            {
                w[i] = '\0';
                break;
            }
            else
            {
                count++;
            }
        }
    }
    
    return count;
}

int substring(char *str1, char *str2)
{
    if (strlen(str1) < strlen(str2)) // checking if the length of str 1 lower then str2 return 0 because it cant be cointained in str1
    {
        return 0;
    }

    int count = 0;

    for (int i = 0; i < strlen(str1); i++)
    {
        for (int j = 0; j < strlen(str2); j++)
        {
            if (str1[i + j] == str2[j])
            {
                count++;
            }
            else
            {
                count = 0;
                break;
            }
        }
        if (count == strlen(str2))
        {
            return 1;
        }
    }

    return 0;

}

int similar(char *s, char *t, int n)
{
    if (strlen(s) - n != strlen(t))
    {
        return 0;
    }
    int i = 0;
    int j = 0;
    while (i < strlen(s) && j < strlen(t)) // checking if t cointained in s (we know that len of t is lower then s)
    {
        if (s[i] == t[j]) // if they have the same char we moving the index togheter
        {
            i++;
            j++;
            if (j == strlen(t))
            {
                return 1;
            }
        }
        else // if they dont have the same char in this index we move the index in the longer string and lower the n by one
        {
            i++;
            n--;
        }
    }
    // if the index j is the same as the size of min len string so its mean that we move all over the lower string and its in the longer string
    // and if index i as the same as the size of the larger string len and n

    if (j == strlen(t) && i == strlen(s) && n == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void print_lines(char *str)
{

    char check[LINE]={0};
    int i = 0;
    while (i < Line_in_txt)
    {
        i++;
        get_line(check);
        if(feof(stdin))
        {
            break;
        }
        else{
            if (substring(check, str) == 1)
            {
                printf("%s\n", check);
            }
        }
    }
}

void print_similar_words(char *str)
{
    char word[WORD]={0};
    int i = 0;
    while (i<Line_in_txt)
    {
        if (similar(word, str, 1) == 1 || similar(word, str, 0) == 1)
        {
            printf("%s\n", word);
        }
        getword(word);
        i++;
    }
}

int main()
{
    // char str1[]= "aagabahj";
    // char str2[] ="aba";

    // printf("%d\n",substring(str1,str2));

    // char s[]="hello";
    // char t[]="elo";
    // printf("%d\n",similar(s,t,2));

    // for (int i = 0; i < 50; i++)
    // {
    //     char first_word[WORD];
    //     getword(first_word);
    //     printf("%s\n", first_word);
    //     /* code */
    // }

    char first_word[WORD];
    getword(first_word);
    //printf("The word that we need to check on is: %s\n", first_word);

    char check_what_func[LINE];
    get_line(check_what_func);
    //printf("The func is: %s\n", check_what_func);

    char input[LINE];
    get_line(input);

    // char check_what_func = first_line_func[strlen(first_line_func) - 1];

    if (check_what_func[0] == 'a')
    {
        print_lines(first_word);
    }
    else if (check_what_func[0] == 'b')
    {
        print_similar_words(first_word);
    }

    return 0;
}
