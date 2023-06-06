// link: https://leetcode.com/problems/valid-palindrome/
class Solution {
public:
    bool isPalindrome(string s) {
        string s2="";
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(isalnum(s[i])) 
                s2+=toupper(s[i]);
        }
        string s3=s2;
        reverse(s3.begin(),s3.end());
        if(s3==s2)
            return true;
        return false;
       
    }
};
