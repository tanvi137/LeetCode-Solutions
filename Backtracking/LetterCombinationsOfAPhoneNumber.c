char *phoneMap[] = {
    "", "", "abc", "def", "ghi",
    "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void backtrack(char *digits, int pos, int n, char *current,
               char **result, int *returnSize) {

    if (pos == n) {
        current[n] = '\0';
        result[*returnSize] = malloc((n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    char *letters = phoneMap[digits[pos] - '0'];

    for (int i = 0; letters[i] != '\0'; i++) {
        current[pos] = letters[i];
        backtrack(digits, pos + 1, n, current, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    int n = strlen(digits);

    *returnSize = 0;

    if (n == 0)
        return NULL;

    char **result = malloc(256 * sizeof(char*));
    char *current = malloc((n + 1) * sizeof(char));

    backtrack(digits, 0, n, current, result, returnSize);

    free(current);

    return result;
}
