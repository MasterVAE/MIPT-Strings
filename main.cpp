#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void my_puts(const char *str);
char *my_strchr(const char *str, char c);
size_t my_strlen(const char *str);
char *my_strcat(char* str1, const char* str2);
char *my_strncat(char str1[], const char* str2, int lent);
int my_atoi(const char* str);
void my_fgets(char* str, int cnt, FILE* file);
char *my_getline(char **str, int *n, FILE *file);
char *my_strstr(char *str1, const char *str2);
char *my_strdup(const char *str1);

int main()
{
    int y = 5;
    char *str = (char *)calloc(y, sizeof(char));
    char **bob = &str;
    printf("%s\n", my_getline(bob, &y, stdin));

    printf("%d\n", my_atoi("       +12g6"));
    return 1;
}

// +
void my_puts(const char *str)
{
    while(*str != '\0' && *str != EOF)
    {
        putchar(*(str++));
    }
    putchar('\n');
}

// +
char *my_strchr(const char *str, char c)
{
    while(*str != '\0')
    {
        if(*str == c)
        {
            return((char *)str);
        }
        str++;
    }

    if(*str == c)
    {
        return((char *)str);
    }

    return(NULL);
}

// +
size_t my_strlen(const char *str)
{
    size_t size = 0;
    while(*(str++) != '\0')
    {
        size++;
    }
    return size;
}

// +
char *my_strcat(char *str1, const char *str2)
{
    assert(str1 != NULL);

    char* end_str1 = str1 + my_strlen(str1);
    while(*str2 != '\0')
    {
        *(end_str1++) = *(str2++);
    }
    *end_str1 = '\0';

    return str1;
}

// +
char *my_strncat(char *str1, const char* str2, int lent)
{
    assert(str1 != NULL);

    char* end_str1 = str1 + my_strlen(str1);
    int counter = 0;
    while(*str2 != '\0' && (counter++)<lent)
    {
        *(end_str1++) = *(str2++);
    }
    *end_str1 = '\0';

    return str1;
}

// +
int my_atoi(const char *str)
{
    int negative = 0;
    int ans = 0;

    while(*str == ' ' && *str != '\0')
    {
        str++;
    }
    if(*str == '-')
    {
        negative = 1;
        str++;
    }
    else if(*str == '+')
    {
        str++;
    }
    while(*str != '\0')
    {
        if(*str <= '9' && *str >= '0')
        {
            ans *= 10;
            ans += *str - '0';
        }
        else
        {
            return negative ? -ans : ans;
        }
        str++;
    }

    return negative ? -ans : ans;
}

// + 
void my_fgets(char *str, int cnt, FILE *file)
{
    assert(str != NULL);

    int i = 0;
    char last_char;
    while((i++) < cnt && (last_char = (char)fgetc(file)) != EOF && last_char != '\n')
    {
        *(str++) = last_char;
    }
    *str = '\0';
}

// +
char *my_getline(char **str, int *n, FILE *file)
{
    assert(str != NULL);
    assert(file != NULL);

    char *string = *str;

    assert(string != NULL);


    char last_char;
    int counter = 0;

    while((last_char = (char)fgetc(file)) != EOF && last_char != '\n')
    {
        if(counter >= *n)
        {
            *n += 100;
            string = (char *)realloc(string, (*n) * sizeof(char));

        }

        string[counter++] = last_char;
    }
    string[counter] = '\0';
    str = &string;
    return string;
}

// +
char *my_strstr(char *str1, const char *str2)
{
    assert(str1 != NULL);

    int i = 0;
    while(*str1 != '\0')
    {
        i = 0;

        int flag = 1;
        while(str1[i] != '\0' &&  str2[i] != '\0')
        {
             if(str1[i] != str2[i])
             {
                flag = 0;
                break;
             }
             i++;
        }

        if(flag)
        {
            return(str1);
        }
        str1++;
    }

    return NULL;
}

//  +
char *my_strdup(const char *str1)
{
    size_t len = my_strlen(str1) + 1;
    int counter = 0;
    char *str2 = (char *)calloc(len, sizeof(char));

    assert(str2 != NULL);

    while(counter++ < len)
    {
        *(str2++) = *(str1++);
    }

    return str2-len;
}
