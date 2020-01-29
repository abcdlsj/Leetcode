// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        st.push("");
        string ns="";
        string nns="";
        for(auto c : s){
            if(c=='(')
                st.push("");
            else if(c==')')
            {
                ns=st.top();st.pop();
                reverse(ns.begin(),ns.end());
                nns=st.top();st.pop();
                st.push(nns+ns);
            }
            else {
                ns=st.top();st.pop();
                st.push(ns+c);
            }
        }
        string ans;
        if(!st.empty()){
            ans = ans+st.top();st.pop();
        }
        return ans;
        
    }
};
