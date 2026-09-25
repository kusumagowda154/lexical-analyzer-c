#include <stdio.h>
#include <ctype.h>
#include <string.h>

// List of keywords
char keywords[][10] = {
    "int", "float", "if", "else", "while", "return", "char", "for", "void"
};

int isKeyword(char *word) {
    for (int i = 0; i < 9; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char input[200], token[50];
    int i = 0, j = 0;

    printf("Enter source code:\n");
    fgets(input, sizeof(input), stdin);

    while (input[i] != '\0') {

       
        if (isspace(input[i])) {
            i++;
            continue;
        }

        
        if (isalpha(input[i])) {
            j = 0;
            while (isalnum(input[i])) {
                token[j++] = input[i++];
            }
            token[j] = '\0';

            if (isKeyword(token))
                printf("%s → Keyword\n", token);
            else
                printf("%s → Identifier\n", token);
        }

        
        else if (isdigit(input[i])) {
            j = 0;
            while (isdigit(input[i])) {
                token[j++] = input[i++];
            }
            token[j] = '\0';

            printf("%s → Constant\n", token);
        }

        
        else if (strchr("+-*/=%", input[i])) {
            printf("%c → Operator\n", input[i]);
            i++;
        }

       
        else if (strchr(";{}()", input[i])) {
            printf("%c → Symbol\n", input[i]);
            i++;
        }
//ukonws
        else {
            printf("%c → Unknown\n", input[i]);
            i++;
        }
    }

    return 0;
}