#include <stdio.h>
#include <string.h>
#include <ctype.h>

int state = 1;

void transition(int from, char symbol, int to)
{
    printf("%d ---> %c ---> %d\n", from, symbol, to);
}

int main()
{
    char re[50];
    int i;

    printf("\nEnter the regular expression: ");
    fgets(re, sizeof(re), stdin);

    // Remove newline if present
    re[strcspn(re, "\n")] = '\0';

    printf("\nstate  input  state\n");

    for(i = 0; re[i] != '\0'; i++)
    {
        if(isalpha(re[i]))
        {
            transition(state, re[i], state+1);
            state++;
        }

        else if(re[i] == '.')
        {
            // Concatenation handled automatically
        }

        else if(re[i] == '+')
        {
            int start = state - 1;
            char next = re[i+1];

            transition(1, next, state+1);
            state++;
            i++;  
        }

        else if(re[i] == '*')
        {
            transition(state, 'e', state-1);
            transition(state-1, 'e', state);
        }
    }

    return 0;
}
