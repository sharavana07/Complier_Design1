#include <stdio.h>
#include <string.h>

int main() {
    char prod[100];
    char lhs;
    char alpha[100] = "";
    char beta[100] = "";
    char newProd1[100] = "";
    char newProd2[100] = "";
    int i, j = 0, k = 0;
    int isLeftRecursive = 0;
    int pipeIndex = -1;
    int len;

    printf("Enter the production (Example: E->E+T|T): ");
    scanf("%s", prod);

    len = strlen(prod);
    lhs = prod[0];

    // Find position of '|'
    for (i = 0; i < len; i++) {
        if (prod[i] == '|') {
            pipeIndex = i;
            break;
        }
    }

    // Check for direct left recursion
    if (prod[3] == lhs) {
        isLeftRecursive = 1;
    }

    if (isLeftRecursive) {

        // Extract alpha (after A->A)
        for (i = 4; i < pipeIndex; i++) {
            alpha[j++] = prod[i];
        }
        alpha[j] = '\0';

        // Extract beta (after |)
        for (i = pipeIndex + 1; i < len; i++) {
            beta[k++] = prod[i];
        }
        beta[k] = '\0';

        // Form new production A -> beta A'
        sprintf(newProd1, "%c->%s%c'", lhs, beta, lhs);

        // Form new production A' -> alpha A' | e
        sprintf(newProd2, "%c'->%s%c'|e", lhs, alpha, lhs);

        printf("\nAfter removing Left Recursion:\n");
        printf("%s\n", newProd1);
        printf("%s\n", newProd2);
    }
    else {
        printf("\nNo Left Recursion detected.\n");
    }

    return 0;
}
