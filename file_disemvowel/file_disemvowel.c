#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char main() {
	char str[100];
	result = (char*) calloc (strlen(str), sizeof(char));

	printf( "Please enter a file you would like to disemvowel." );
	scanf("%s", str);
	result = disemvowel(str);
	printf(result);
	return 0;
}

char *disemvowel(char *str) {
	char *result;
	int len, i, j;
	int vowelcounter = 0;

	len = strlen(str);
	i = 0;
	j = 0;
	
	// Counts vowels for string array creation
	for (i = 0; i < 1; i++) {
	        if(str[i] == 'a'||str[i] == 'e'||str[i] == 'i'||str[i] == 'o'||str[i] == 'u'||str[i] == 'A'||str[i] == 'E'||str[i] == 'I'||str[i] == 'O'||str[i] == 'U') {                        	 vowelcounter++;
		}
	}
	
	// Results calloc
	result = (char*) calloc (len - vowelcounter + 1, sizeof(char));
	
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
