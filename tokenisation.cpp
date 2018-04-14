#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

enum token_type{
	NUM = 1,
	VAR = 2,
	OPER = 3,
	FUNC = 4,
	BRACE = 5,
	STACKF = 6,
	SEMICOLON = 7
};

enum functions_and_vars{
	PLUS = 1,
	MINUS = 2,
	MULT = 3,
	DIV = 4,
	ELEV = 5,
	LN = 6,
	x = 7,
	SIN = 8,
	COS = 9,
	SH = 10,
	TG = 11,
	CH = 12,
	BRACE_L = 13,
	BRACE_R = 14,
	PUSH = 15,
	POP = 16,
	EAX = 17,
	EBX = 18,
	ECX = 19,
	EDX = 20,
	SEMICOLON = 21
};


class Token {
	public:
		int type;
		int value;
	
	Token(char* value);
	~Token();
}

void SkipDelim(char* s,int* p);

Token :: Token(char* str){
	if(!strcmp(str,"eax")){
		value = EAX;
		type = VAR;
	}
	if(!strcmp(str,"(")){
		value = BRACE_L;
		type = BRACE;
	}
	if(!strcmp(str,")")){
		value = BRACE_R;
		type = BRACE;
	}
	if(!strcmp(str,"sin")){
		value = SIN;
		type = FUNC;
	}
	if(!strcmp(str,"cos")){
		value = COS;
		type = FUNC;
	}
	if(!strcmp(str,"+")){
		value = PLUS;
		type = OPER;
	}
	if(!strcmp(str,"-")){
		value = MINUS;
		type = OPER;
	}
	if(!strcmp(str,"*")){
		value = MULT;
		type = OPER;
	}
	if(!strcmp(str,"/")){
		value = DIV;
		type = OPER;
	}
	if(!strcmp(str,";")){
		value = SEMICOLON;
		type = SEMICOLON;
	}
	
	else {
		value = atoi(str);
		type = NUM;
	}
	
}

Tokenisation(char* str){
	int p = 0;		// pointer to the char in str with this number
	SkipDelim(str,&p);
	
	
}




void SkipDelim(char* s,int* p){
	while(s[*p] == ' ' || s[*p] == '\n' || s[*p] == '\t' || s[*p] == '\r'){
		(*p)++;
	}
	printf("SD s[p] = %c",s[*p]);
}