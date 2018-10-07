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

void *disemvowel(FILE* input, FILE* output) {
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

// Code that processes the command line arguments 
// and sets up inputFile and outputFile




	
disemvowel(input, output);

	return 0;
}
