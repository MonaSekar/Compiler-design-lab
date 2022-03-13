#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>

size_t len = 0;
void token_seperator(char *ptr, char str[100], char to_print[100])
{
    int declare = 0;
    int conditional = 0;
    if (ptr != NULL)
    {
        declare = 1;
        printf("%s-keyword\n", to_print);
        char *p = ptr;
        char str[10];
        int slen = 0;
        char *t = p;
        int jumplen = strlen(str);
        t += strlen(str);
        while (*t != '\0')
        {
            char c = *t;
            str[slen++] = c;
            t++;
            if (*t == '=')
            {
                t++;
                str[slen] = '\0';
                slen = 0;
                str[0] = '\0';
                while (isdigit(*t) || *t == '.')
                {
                    char c = *t;
                    str[slen++] = c;
                    t++;
                }
                str[len] = '\0';
                slen = 0;
            }
            if (*t == ',' || *t == ';')
            {
                t++;
            }
        }
    }
}

int main()
{
    FILE *fp;
    char *line = NULL;
    int count = 0;
    ssize_t linelen;
    fp = fopen("sample.c", "r");
    char store1[10][100];
    char store2[10][100];
    int dtype[10], cnt = 0;
    while ((linelen = getline(&line, &len, fp)) != -1)
    {    int declare = 0;
        int conditional = 0;
        char *int1 = strstr(line, "int ");
        char *float1 = strstr(line, "float");
        if(float1!=NULL){
            declare=1;
        }
        if(int1!=NULL){
            declare=1;
        }
        char *for1 = strstr(line, "for(");
        char *if1 = strstr(line, "if(");
        if(if1!=NULL){
            conditional=1;
        }
        char *else1 = strstr(line, "else");
        token_seperator(int1, "int ", "int");
        token_seperator(float1, "float", "float");
        token_seperator(for1, "for(", "for");
        token_seperator(if1, "if(", "if");
        token_seperator(else1, "else", "else");
        char *templine;
        templine = line;
        int first = 1;
        if (declare == 1)
        {
            while (templine != NULL)
            {
                if (first == 1)
                {
                    templine = strstr(templine, " ");
                    first = 0;
                }
                else
                {
                    printf(", - special character\n");
                }
                int equindex;
                for (int z = 0; z < strlen(templine); z++)
                {
                    if (*(templine + z) == '=')
                    {  
                        equindex = z;
                        break;
                    }
                }
                for (int j = 1; j < equindex; j++)
                {
                    printf("%c", *(templine + j));
                }
                printf(" - variable\n");
                printf("= - assignment operator\n");
                templine = strstr(templine, "=");
                int commaindex;
                for (int z = 0; z < strlen(templine); z++)
                {
                    if (*(templine + z) == ',')
                    {
                        commaindex = z;
                        break;
                    }
                }
                for (int j = 1; j < commaindex; j++)
                    {
                        printf("%c", *(templine + j));
                    }
                printf(" - constant\n");
                templine = strstr(templine, ",");
            }
        }
        char* main1 = strstr(line, "main(");
        char* printf1 = strstr(line, "printf(");
        char *popen = strstr(line, "{");
        if (popen != NULL)
            printf("{ - special character\n");
        char *semicolon = strstr(line, ";");
        if (semicolon != NULL)
            printf("; - special character\n");
        char *pclose = strstr(line, "}");
        if (pclose != NULL)
            printf("} - special character\n");
        char *bracket_open = strstr(line, "(");
        if (bracket_open != NULL && main1 == NULL && printf1 == NULL)
            printf("( - special character\n");
        char *tempvar;
        if (conditional == 1)
        {
            tempvar = strstr(line, "(");
            int i;
            int condition;
            for (int z = 0; z < strlen(tempvar); z++)
            {
                if (*(tempvar + z) == '<' || *(tempvar + z) == '>')
                {
                    condition = z;
                    break;
                }
            }
            for (int j = 1; j < condition; j++)
            {
                printf("%c", *(tempvar + j));
            }
            printf(" - variable\n");
            char *tempvar1 = strstr(tempvar, "<");
            char *tempvar2 = strstr(tempvar, ">");
            if (tempvar1 != NULL)
                tempvar = tempvar1;
            if (tempvar2 != NULL)
                tempvar = tempvar2;
            printf("%c - condition\n", *(tempvar));
            for (int z = 1; z < strlen(tempvar); z++)
            {
                if (*(tempvar + z) == ')')
                {
                    condition = z;
                    break;
                }
                else
                {
                    printf("%c", *(tempvar + z));
                }
            }
            printf(" - variable\n");
        }
        char *bracket_close = strstr(line, ")");
        if (bracket_close != NULL && main1 == NULL && printf1 == NULL)
            printf(") - special character\n");
    }
    fclose(fp);
    return 0;
}