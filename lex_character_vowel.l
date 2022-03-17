%{  
    #include<stdio.h>
    int count=0,vowel=0,digit=0;

%}

%%
[aeiouAeiou] {vowel++;}
[A-Za-z] {count++;}
[0-9]    {digit++;}
"\n"      {printf("Vowels %d,letters %d ,digits %d",vowel,count+vowel,digit);
            return 0;}
%%


int yywrap(){
    return 0;
}

int main(){
    yylex();
   
    return 0;
    

}