#include <stdio.h>
#include <string.h>

char* minWindow(char* s, char* t) {
    if (s == NULL || t == NULL) return "";
    
    int lenS = strlen(s);
    int lenT = strlen(t);
    if (lenS == 0 || lenT == 0 || lenS < lenT) return "";

    int mapT[128] = {0};
    int windowCounts[128] = {0};

    int required = 0;
    for (int i = 0; i < lenT; i++) {
        if (mapT[(unsigned char)t[i]] == 0) {
            required++; // Count unique characters needed
        }
        mapT[(unsigned char)t[i]]++;
    }

    int left = 0, right = 0;
    int formed = 0;
    
    int minLen = INT_MAX;
    int startIdx = 0;

    while (right < lenS) {
        char c = s[right];
        windowCounts[(unsigned char)c]++;

        // If current character matches target requirements, track it
        if (mapT[(unsigned char)c] > 0 && windowCounts[(unsigned char)c] == mapT[(unsigned char)c]) {
            formed++;
        }

        while (left <= right && formed == required) {
            char leftChar = s[left];

            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                startIdx = left;
            }

            windowCounts[(unsigned char)leftChar]--;
            if (mapT[(unsigned char)leftChar] > 0 && windowCounts[(unsigned char)leftChar] < mapT[(unsigned char)leftChar]) {
                formed--;
            }
            left++;
        }
        right++;
    }


    if (minLen == INT_MAX) return "";

    static char result[100005]; // Large enough buffer based on constraints (10^5)
    strncpy(result, s + startIdx, minLen);
    result[minLen] = '\0';
    
    return result;
}
