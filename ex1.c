#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int iskeyword(char buf[])
{
    char keyword[11][10]={"int","float","for","while","if","else","do","double","return","void","main"};
    for(int i=0;i<11;i++)
    {
        if(strcmp(keyword[i],buf)==0)
            return 1;
    }
    return 0;
}

int main()
{
    char op[7]={'+','-','=','*','/','%','&'};
    char pun[3]={',',';','!'};
    char ch,buf[15],name[20];
    FILE *fp;
    int i,j=0;

    printf("Enter file name: ");
    scanf("%s",name);

    fp=fopen(name,"r");

    if(fp==NULL)
    {
        printf("File not found\n");
        return 1;
    }

    while((ch=fgetc(fp))!=EOF)
    {
        for(i=0;i<7;i++)
            if(ch==op[i])
                printf("\n%c: operator",ch);

        for(i=0;i<3;i++)
            if(ch==pun[i])
                printf("\n%c: punctuation",ch);

        if(isalnum(ch))
        {
            if(j < 14)
                buf[j++]=ch;
        }
        else if((ch==' '||ch=='\n') && j!=0)
        {
            buf[j]='\0';
            j=0;

            if(iskeyword(buf))
                printf("\n%s: keyword",buf);
            else if(isdigit(buf[0]))
                printf("\n%s: digit",buf);
            else
                printf("\n%s: identifier",buf);
        }
    }

    fclose(fp);
    return 0;
}
