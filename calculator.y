%{
    #include<stdio.h>
    int flag=0;
    int yylex();
    void yyerror();

%}

%token NUMBER
%left '+' '-'
%right '*''/''%'
%left '('')'

%%
ArthmeticExpression:E{
    printf("\n Result=%d\n",$$);
    return 0;
};
E:E'+'E{$$=$1+$3;}
|E'-'E{$$=$1-$3;}
|E'*'E{$$=$1*$3;}
|E'/'E{$$=$1/$3;}
|'('E')'{$$=$2;}
|NUMBER {$$=$1;}
;
%%

void main(){
    printf("Enter any arithmetic expression\n");
    yyparse();
    if(flag==0){
        printf("Valid expression\n");
    }
}

void yyerror(){
    printf("Error\n");

}
