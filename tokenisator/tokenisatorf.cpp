#include "tokenisator.h"

Token :: Token(){
	value = 0;
	type = 0;
}

Token :: ~Token(){
	printf("Token deleted %d %d\n",value,type);
}

void Token :: SetValue(const int v){
	value = v;
	type = NUM;
}

void Token :: SetValue(const char* str){
	if(!strcmp(str,"eax")){
		value = EAX;
		type = VAR;
		return;
	}
	if(!strcmp(str,"=")){
		value = EQUAL;
		type = OPER;
		return;
	}
	if(!strcmp(str,"(")){
		value = BRACE_L;
		type = BRACE;
		return;
	}
	if(!strcmp(str,")")){
		value = BRACE_R;
		type = BRACE;
		return;
	}
	if(!strcmp(str,"sin")){
		value = SIN;
		type = FUNC;
		return;
	}
	if(!strcmp(str,"cos")){
		value = COS;
		type = FUNC;
		return;
	}
	if(!strcmp(str,"+")){
		value = PLUS;
		type = OPER;
		return;
	}
	if(!strcmp(str,"-")){
		value = MINUS;
		type = OPER;
		return;
	}
	if(!strcmp(str,"*")){
		value = MULT;
		type = OPER;
		return;
	}
	if(!strcmp(str,"/")){
		value = DIV;
		type = OPER;
		return;
	}
	if(!strcmp(str,";")){
		value = SEMICOLON;
		type = SEMICOLON;
		return;
	}
	
	if(strtol(str,NULL,10)) {
		value = atoi(str);
		type = NUM;
		return;
	}
	printf("ERR invalid sequense of symbols in Token(str), str = %s\n",str);
}

Token* Tokenisation(char* s){
	int n = strlen(s);
	int p = 0;		// pointer to the char in str with this number
	int val = 0;    // value that will be sent in token if sequense of characters is numbers 
	Token* token_array = new Token[n];
	for(int i = 0 ;s[p] != '\0';i++){
		SkipDelim(s,&p);
		switch(s[p]){
			case('e'):{
				p++;
				if(s[p] == 'a'){
					p++;
					if(s[p] == 'x'){
						p++;
						(token_array[i]).SetValue("eax");
					}
					else{
						printf("ERR invalid sequense of symbols, maybe you wanted eax \n");
						exit (EXIT_FAILURE);
					}
				}
				if(s[p] == 'b'){
					p++;
					if(s[p] == 'x'){
						p++;
						(token_array[i]).SetValue("eax");
					}
					else{
						printf("ERR invalid sequense of symbols, maybe you wanted ebx \n");
						exit (EXIT_FAILURE);
					}
				}
				if(s[p] == 'c'){
					p++;
					if(s[p] == 'x'){
						p++;
						(token_array[i]).SetValue("eax");
					}
					else{
						printf("ERR invalid sequense of symbols, maybe you wanted ecx \n");
						exit (EXIT_FAILURE);
					}
				}
				if(s[p] == 'd'){
					p++;
					if(s[p] == 'x'){
						p++;
						(token_array[i]).SetValue("eax");
					}
					else{
						printf("ERR invalid sequense of symbols, maybe you wanted edx \n");
						exit (EXIT_FAILURE);
					}
				}
				break;
			}
			case('='):{
				(token_array[i]).SetValue("=");
				p++;
				break;
			}
			case('+'):{
				(token_array[i]).SetValue("+");
				p++;
				break;
			}
			case('-'):{
				(token_array[i]).SetValue("-");
				p++;
				break;
			}
			case('*'):{
				(token_array[i]).SetValue("*");
				p++;
				break;
			}
			case('/'):{
				(token_array[i]).SetValue("/");
				p++;
				break;
			}
			case(';'):{
				(token_array[i]).SetValue(";");
				p++;
				break;
			}
		}
		if('0' <= s[p] && s[p]<='9'){
			while('0' <= s[p] && s[p]<='9'){
				val = s[p] - '0' + 10*val;
				p++; 
			}
			(token_array[i]).SetValue(val);
			val = 0;
		}
		
	}
	for(int j = 0;(token_array[j]).type != NOTHING;j++){
		printf("%d val  = %d , type = %d \n",j,(token_array[j]).value,(token_array[j]).type);
	}
	return token_array;
}




void SkipDelim(char* s,int* p){
	while(s[*p] == ' ' || s[*p] == '\n' || s[*p] == '\t' || s[*p] == '\r'){
		(*p)++;
	}
	printf("SD s[p] = %c\n",s[*p]);
}