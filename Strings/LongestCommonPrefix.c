char* longestCommonPrefix(char** strs, int strsSize) {
    char* prefix = strs[0];
    int i = 0;

    while (prefix[i] != '\0') {
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != prefix[i] || strs[j][i] == '\0') {
                prefix[i] = '\0';
                return prefix;
            }
        }
        i++;
    }

    return prefix;
}
