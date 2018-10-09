#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 1024

bool is_vowel(char c) {
	bool result = false;

	if(c == 'a'||c == 'e'||c == 'i'||c == 'o'||c == 'u'||c == 'A'||c == 'E'||c == 'I'||c == 'O'||c == 'U') {
		result = true;
	}

	return result;	
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
	int i = 0;
	int j = 0;

	while(i < num_chars) {
		if(is_vowel(in_buf[i]) == false) {
			out_buf[j] = in_buf[i];
			j++;
		}
		i++;
	}

	return j;
}

void disemvowel(FILE* input, FILE* output) {
	char* in_buf = (char*) calloc(BUF_SIZE, sizeof(char));
	char* out_buf = (char*) calloc(BUF_SIZE, sizeof(char));

	int in_len = fread(in_buf, sizeof(char), BUF_SIZE, input);
	while (in_len != 0) {
		int non_vowels = copy_non_vowels(strlen(in_buf), in_buf, out_buf);
		fwrite(out_buf, sizeof(char), non_vowels, output);
		in_len = fread(in_buf, sizeof(char), BUF_SIZE, input);
	}
}

int main(int argc, char *argv[]) {
	FILE *input; 
	FILE *output;
	//char* lineIn = (char*) calloc(BUF_SIZE, sizeof(char));
	//char* lineOut = (char*) calloc(BUF_SIZE, sizeof(char));

	// when only an input is given - works like old disemvowel 
	if (argc == 1){
		input = stdin;
		output = stdout;
		//lineIn = stdin;
		//lineOut = disemvowel(lineIn, stdout);
		//print(result);
	}

	// when input file is given but we are printing out to the terminal
	if (argc == 2){
		input = fopen(argv[1], "r");
		output = stdout;
		//disemvowel(input, output);
	}

	// when input file is given and also an output file to print out to
	if (argc == 3){
		input = fopen(argv[1], "r");
		output = fopen(argv[2], "w");
		//disemvowel(input, output);

	// should never reach here since the function is not suppose to take more than 1 input and 1 output
	} else {
		return 0;
	} 	
	
	disemvowel(input, output);

	return 0;
}
