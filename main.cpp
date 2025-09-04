#include <stdio.h>
#include <assert.h>

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

    //char str2[10];
    //my_fgets(str2, 10, stdin);

    char str1[50] = "teleb";
    //char *str2 = "bobdsmdnmfg";
    //my_strncat(str1, str2, 3);
    //printf("%s\n", str1);

    my_fgets(str1, 10, stdin);
    printf("%s\n", str1);

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
    assert(str1 != NULL);

    char* end_str1 = str1 + my_strlen(str1);
    while(*str2 != '\0')
    {
        *(end_str1++) = *(str2++);
    }
    end_str1 = '\0';
}

// +
void my_strncat(char *str1, const char* str2, int lent)
{
    assert(str1 != NULL);

    char* end_str1 = str1 + my_strlen(str1);
    int j = 0;
    while(*str2 != '\0' && (j++)<lent)
    {
        *(end_str1++) = *(str2++);
    }
    end_str1 = '\0';
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
    assert(str1 != NULL);

    int i = 0;
    char last_char;
    while((i++) < cnt && (last_char = (char)fgetc(file)) != EOF && last_char != '\n')
    {
        *(str++) = last_char;
    }
    *str = '\0';
}
