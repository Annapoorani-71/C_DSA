#include <stdio.h>
#include <string.h>
void computeLPSArray(char *pattern, int patternLength, int *lps)
{
    int length = 0;
    lps[0] = 0;
    int i = 1; // 4
    while (i < patternLength)
    {
        if (pattern[i] == pattern[length]) // c==A
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if (length != 0) // 0!=0
            {
                length = lps[length - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMPSearch(char *text, char *pattern)
{
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    int lps[patternLength];
    computeLPSArray(pattern, patternLength, lps);
    // A B A B D A B A B C
    // A B A B C     5    [0,0,1,2,0]
    int i = 0; // 4
    int j = 0; // 4
    while (i < textLength)
    {
        if (pattern[j] == text[i]) // A==A
        {
            i++;
            j++;
        }
        if (j == patternLength)
        {
            printf("Found pattern at index %d\n", i - j);
            j = lps[j - 1];
        }
        else if (i < textLength && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}
int main()
{
    char text[] = "ABABDABABC";
    char pattern[] = "ABABC";
    KMPSearch(text, pattern);
    return 0;
}