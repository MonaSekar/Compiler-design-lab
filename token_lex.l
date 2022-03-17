%{
    #include<stdio.h>
    #include<string.h>
    char str[20];
    int opc=0,dc=0,idc=0;
%}

digit [0-9]
op [%|*|+|-|=]
id [for|if|while|do|const|break|default]

%%
{digit} dc++;
{op} opc++;
{id} idc++;
"\n" {printf("digit %d\n operator %d\n identifier%d",dc,opc,idc);
return 0;
};
%%

int main(){
    yylex();
    return 0;
}

int yywrap(){
    return 0;
}