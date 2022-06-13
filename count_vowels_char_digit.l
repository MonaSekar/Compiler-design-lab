%{
    #include<stdio.h>
    int v=0,d=0,c=0;

%}

%%
[aeiouAeiou] {v++;}
[A-Za-z]    {c++;}
[0-9]       {d++;}
"\n"    {printf("Vowels %d digit %d charecters %d",v,d,v+c);
            return 0;}



%%

int yywrap(){
    return 0;
}

int main(){
    yylex();
    return 0;
}