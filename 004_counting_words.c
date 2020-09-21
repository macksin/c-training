#include <stdio.h>

#define IN  1 // inside a word
#define OUT 0 // outside a word

main()
{
    int state, c, nc, nw;

    state = OUT;

    nc = nw = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        
        if (c == ' ' || c == '\n' || c == '\t'){
            state = OUT;
        }
        else if (state == OUT){
            state = IN;
            ++nw;
        }
    }

    printf("Words %d\n", nw);
}