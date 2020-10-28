#include <stdio.h>
#include <math.h>

#define MAXSIZE 10000

int getSize(char s[]);
void inplaceReversal(char s[]);

main()
{
    char line[MAXSIZE];
    int i;
    int c;
    int size;

    /* Get input */
    i = 0;
    while ((c=getchar()) != EOF){
        line[i] = c;
        ++i;
    }
    line[i] = '\n';
    line[i+1] = '\0';
    printf("REVERSING: \t%s", line);
    inplaceReversal(line);
    printf("REVERSED: \t%s", line); /* reversal */
}


void inplaceReversal(char s[]){

    int i;
    int charSize;
    int charTemp;
    int pos;
    charSize = getSize(s);

    i = 0;

    for (int n=0; n <= floor(charSize/2); ++n){
        pos = charSize-1-n;
        charTemp = s[pos];
        s[pos] = s[n];
        s[n] = charTemp;
    }
}

int getSize(char s[]){

    int size;
    size = 0;    

    while (s[size] != '\n' && s[size] != '\0')
        ++size;

    return size;
}