#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE 1024

bool is_vowel(char c) {
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
}

void *disemvowel(FILE* input, FILE* output) {

	char *result;
	int len, i, j;
	int size = 100;

	len = strlen(input);
	i = 0;
	j = 0;
	
	// Results calloc
	result = (char*) calloc (size, sizeof(char));
	
	// Creates disemvoweled string
	while(i < len) {
		if(str[i] == 'a'||str[i] == 'e'||str[i] == 'i'||str[i] == 'o'||str[i] == 'u'||str[i] == 'A'||str[i] == 'E'||str[i] == 'I'||str[i] == 'O'||str[i] == 'U') {
			i++;
		} else {
			result[j] = str[i];
			i++;
			j++;
		}
	}

	// Null terminator
	result[len] ='\0';
	return (char*) result;
}

int main() {
        char *result;
        char str[100];
        result = (char*) calloc (strlen(str), sizeof(char));

        printf( "Please enter a file you would like to disemvowel. " );
        scanf("%s", str);
	printf( "Your result: ");
        result = disemvowel(str);
        printf(result);
	printf("\n");
	return 0;
}
