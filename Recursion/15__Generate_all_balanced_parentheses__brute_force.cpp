// Date: 05/07/2021

// Problem Link: https://leetcode.com/problems/generate-parentheses/
// Youtube Link: https://www.youtube.com/watch?v=eyCj_u3PoJE&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=17&t=202s
// Submission Link: https://leetcode.com/submissions/detail/517763170/

//-----------------------------------Main Code Starts-------------------------------------------//

class Solution {
public:
    
    void generate(int n, string op, vector<string>& all)
    {
        if(n == 0)
        {
            all.push_back(op);
            return ;
        }

        string op1 = op + "(";
        string op2 = op + ")";

        n--;

        generate(n, op1, all);
        generate(n, op2, all);

    }
    
    bool check(string& s)
    {
        stack<char> st;

        for(int i = 0; i < (int)s.size(); i++)
        {
            if(st.empty())
            {
                if(s[i] == ')')
                    return false;
                else
                    st.push('(');
            }
            else
            {
                if(st.top() == '(' and s[i] == ')')
                    st.pop();
                else
                    st.push(s[i]);
            }
        }

        if(st.empty())
            return true;

        return false;

    }
    
    vector<string> generateParenthesis(int n) 
    {
        n *= 2;

        vector<string> all;
        string op = "";

        generate(n, op, all);

        vector<string> ans;

        for(int i = 0; i < (int)all.size(); i++)
        {
            string s = all[i];

            if(check(s))
                ans.push_back(s);
        }

        return ans;
        
    }
};