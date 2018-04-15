#ifndef __TOKENISATOR_H__
#define __TOKENISATOR_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

enum token_type{
	NOTHING = 0,
	NUM = 1,
	VAR = 2,
	OPER = 3,
	FUNC = 4,
	BRACE = 5,
	STACKF = 6
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
	SEMICOLON = 21,
	EQUAL = 22
};


class Token {
	public:
		int type;
		int value;
	
		Token();
		~Token();
		
		void SetValue(const char* str);
		void SetValue(const int v);
};

void Tokenisation(const char* str);
void SkipDelim(char* s,int* p);

#include "tokenisatorf.cpp"
#endif