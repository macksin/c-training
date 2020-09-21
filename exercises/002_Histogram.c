#include <stdio.h>

/* Draw a histogram with the length
   of the words, vertical is more
   challenging. */

#define IN  1
#define OUT 0

main()
{
    int c, w_state, w_counter, i, maxvalue, j;
    int digit_words[99];

    w_counter = maxvalue = 0;
    w_state = OUT;

    for (i = 0; i < 99; i++)
        digit_words[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t'){
            w_state = OUT;
        }
        else if (w_state == OUT){
            w_state = IN;
            ++w_counter;
        }

        // Counting characters per word
        if (c != ' ' & c != '\n' & c != '\t')
            digit_words[w_counter-1]++;

        if (maxvalue < digit_words[w_counter-1])
            maxvalue = digit_words[w_counter-1];

    }

    for (i = 0; i < w_counter; i++)
        printf("%d ", digit_words[i]);
    printf("\n");

    // We start at the top and check
    // if the logic holds
    
    for (i = maxvalue; i >= 1; i--){
        for (j = 0; j < w_counter; j++)
            if(digit_words[j] >= i)
                printf("*");
            else
                printf(" ");
        printf("\n");
    }
        
}