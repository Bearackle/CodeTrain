class Solution {
public:
    int strStr(string haystack, string needle) {
        int x = 0,y = 0,pos = 0;
        while (needle[x] !='\0' && haystack[pos] != '\0')
        {
              if (haystack[y] == needle[x])
              {
                  ++x;
                  ++y;
              }
              else 
              { 
                   x = 0;
                   y=++pos;
              }
        }
        if (pos == haystack.length() || haystack.length() < needle.length()) return -1;
        return pos;
    }
};