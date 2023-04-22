#if 0
static int cntToSameChar(char *s, char c, int limit) {
    int cnt = 1;
    while (cnt < limit) {
        if (c != *(++s)) {
            cnt++;
        } else {
            break;
        }
    }
    return cnt;
}

int lengthOfLongestSubstring(char * s){
    char start = '\0';
    char *curr = s;
    int cnt;
    int tmp_max = 0;
    int max = 0;

    int str_len = strlen(s);
    
    for (int ofs = 0; ofs < str_len; ofs++) {
        int limit = cntToSameChar(&s[ofs], s[ofs], strlen(s) - ofs);
        tmp_max = limit;
        cnt = 0;
        while (cnt < limit) {
            cnt++;
            int num = cntToSameChar(&s[cnt+ofs], s[cnt+ofs], (limit - cnt));
            tmp_max = ((num + cnt) < tmp_max) ? (num + cnt) : tmp_max;
        }
        max = (tmp_max > max) ? tmp_max : max;
    }

    return max;
}
#endif

#if 0
int lengthOfLongestSubstring(char * s){
    int ascii_cnt[256];
    char right, left;
    int i = 0;
    int j = 0;
    int max = 0;
    memset(ascii_cnt, 0, sizeof(ascii_cnt));
    int str_len = strlen(s);
    
    while((i < str_len) && (j < str_len)) {
        right = s[j];
        ascii_cnt[right]++;
        
        while (ascii_cnt[right] > 1) {
            left = s[i];
            ascii_cnt[left]--;
            i++;
        }
        max = ((j - i + 1) > max) ? (j - i + 1) : max;
        j++;
    }

    return max;
}
#endif

int lengthOfLongestSubstring(char * s){
    int ascii_dict[256];
    for (int i = 0; i < 256; ++i) ascii_dict[i] = -1;
    int start = -1;
    int max = 0;
    for (int i = 0; s[i] != 0; ++i)
    {
        if (ascii_dict[s[i]] > start ) start = ascii_dict[s[i]];
        
        ascii_dict[s[i]] = i;
        max = fmax(i - start, max);
    }
    return max;
}


/*
987 / 987 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 5.9 MB
*/