/*Find smallest character by recursive method*/
#include <stdio.h>
#include <assert.h>
#include <time.h>
char smallest_character(char str[],char c);
static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000.0);
}
int main()
{
    struct timespec start, end;
    double cpu_time;
    char testStr[] = {'c','a','x','b'};
    char testChar = 'z';
    assert(testStr != NULL);     /* cannot be NULL */
    assert(*testStr != '\0');    /* cannot be empty */
    clock_gettime(CLOCK_REALTIME, &start);
    char result = smallest_character(testStr,testChar);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_second(start, end);
    printf("result : %c\n",result);
    printf("execution time of smallest_character() : %lf micro sec\n", cpu_time);
    return 0;
}
char smallest_character(char str[], char c)
{
    char tmp = *str;
    if(*str > 0) {
        if(*str > c)
            return *str;
        else {
            tmp = smallest_character(str+1,c);
            if(tmp < *str)
                return *str;
            else
                return tmp;
        }
    }
    return tmp;
}
