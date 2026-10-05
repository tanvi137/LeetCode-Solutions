void backtrack(char** result, int* returnSize, char* current,
               int open, int close, int n) {

    if (open == n && close == n) {
        current[open + close] = '\0';

        result[*returnSize] = malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);

        (*returnSize)++;
        return;
    }

    if (open < n) {
        current[open + close] = '(';

        backtrack(result, returnSize, current,
                  open + 1, close, n);
    }

    if (close < open) {
        current[open + close] = ')';

        backtrack(result, returnSize, current,
                  open, close + 1, n);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int capacity = 5000;

    char** result = malloc(capacity * sizeof(char*));
    char* current = malloc((2 * n + 1) * sizeof(char));

    *returnSize = 0;

    backtrack(result, returnSize, current, 0, 0, n);

    free(current);

    return result;
}
