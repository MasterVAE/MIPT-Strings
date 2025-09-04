#include <stdio.h>

void my_puts(const char *str);
char *my_strchr(const char *str, char c);
size_t my_strlen(const char *str);
void my_strcat(char* str1, const char* str2);
void my_strncat(char str1[], const char* str2, int lent);
int my_atoi(const char* str);
void my_fgets(char* str, int cnt, FILE* file);

int main()
{
    //const char* str = "abcdefg";
    //my_puts(str);
    //printf("%c\n", *(my_strchr(str, 'e')));
    //printf("%d\n", my_strlen(str));

    //char str1[10] = "string1";
    //my_strncat(str1, "string2", 2);
    //printf("%s\n", str1);

    //printf("%d\n", my_atoi("14f23"));

    char str2[10];
    my_fgets(str2, 10, stdin);
    printf("%s\n", str2);

    return 1;
}

// +
void my_puts(const char *str)
{
    while(*str != '\0')
    {
        putchar(*str);
        str++;
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
    return(NULL);
}

// +
size_t my_strlen(const char *str)
{
    int size = 0;
    while(*(str++) != '\0')
    {
        size++;
    }
    return size;
}

// +
void my_strcat(char *str1, const char *str2)
{
    while(*str1 != '\0')
    {
        str1++;
    }
    while(*str2 != '\0')
    {
        str1 = str2;
        str1++;
        str2++;
    }
    str1 = '\0';
}

// +
void my_strncat(char *str1, const char* str2, int lent)
{
    // FIXME assert
    while(*str1 != '\0')
    {
        str1++;
    }
    char* end_str2 = str2 + strlen(str1);
    while(str2[j] != '\0' && j<lent)
    {
        *str1 = str2[j];
        str1++;
        j++;
    }
    str1 = '\0';
}

// +
int my_atoi(const char* str)
{
    int negative = 0;
    int ans = 0;
    while(*str != '\0')
    {

        if(*str == '-')
        {
            negative = 1;
        }
        else if(*str <= '9' && *str >= '0')
        {
            ans *= 10;
            ans += *str - '0';
        }
        str++;
    }

    return negative ? -ans : ans;
}


// FIXME
void my_fgets(char* str, int cnt, FILE* file)
{
    int i = 0;
    while((i++) < cnt)
    {
        *(str++) = (char)fgetc(file);
    }
    *str = '\0';
}
