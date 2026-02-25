#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int iskeyword(char buf[])
{
    char keyword[11][10] = {
        "int","float","for","while","if",
        "else","do","double","return","void","main"
    };

    int i;

    for(i = 0; i < 11; i++)
    {
        if(strcmp(keyword[i], buf) == 0)
            return 1;
    }
    return 0;
}

int main()
{
    char op[7] = {'+','-','=','*','/','%','&'};
    char pun[3] = {',',';','!'};

    char ch, buf[15], name[20];
    FILE *fp;

    int i, j = 0;

    clrscr();

    printf("Enter file name: ");
    scanf("%s", name);

    fp = fopen(name, "r");

    if(fp == NULL)
    {
        printf("\nFile not found!");
        getch();
        return 1;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        /* Check operators */
        for(i = 0; i < 7; i++)
        {
            if(ch == op[i])
                printf("\n%c : operator", ch);
        }

        /* Check punctuation */
        for(i = 0; i < 3; i++)
        {
            if(ch == pun[i])
                printf("\n%c : punctuation", ch);
        }

        /* Build token */
        if(isalnum(ch))
        {
            if(j < 14)   /* Prevent overflow */
                buf[j++] = ch;
        }
        else if((ch == ' ' || ch == '\n') && j != 0)
        {
            buf[j] = '\0';
            j = 0;

            if(iskeyword(buf))
                printf("\n%s : keyword", buf);
            else if(isdigit(buf[0]))
                printf("\n%s : digit", buf);
            else
                printf("\n%s : identifier", buf);
        }
    }

    /* Handle last token */
    if(j != 0)
    {
        buf[j] = '\0';

        if(iskeyword(buf))
            printf("\n%s : keyword", buf);
        else if(isdigit(buf[0]))
            printf("\n%s : digit", buf);
        else
            printf("\n%s : identifier", buf);
    }

    fclose(fp);

    getch();
    return 0;
}
