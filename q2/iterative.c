/*Find smallest character by iterative method*/

#include <stdio.h>
char smallest_character(char str[],char c);
int main()
{
    char const testStr[] = {'c','a','x','b'};
    char const testChar = 'z';
    assert(testStr != NULL);     /* cannot be NULL */
    assert(*testStr != '\0');    /* cannot be empty */
    char result = smallest_character(test,'z');
    printf("%c\n",result);
    return 0;
}
char smallest_character(char str[], char c)
{
    char tmp = str[0];
    for(int i =0 ; str[i]>0; i++) {
        if(str[i] > c)
            return str[i];
        if(str[i] > tmp)
            tmp = str[i];
    }
    return tmp;
}
