%{
    #include<stdio.h>
    int a,b,c;

%}

%%
"a" printf("Enter a");scanf("%d",&a);
"b" printf("Enter b");scanf("%d",&b);
"c" printf("%d",a+b);

%%

int main(){
    yylex();
    return 0;
}

int yywrap(){
    return 0;
}