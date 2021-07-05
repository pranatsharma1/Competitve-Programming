// Date: 05/07/2021

// Problem Link: https://leetcode.com/problems/generate-parentheses/
// Youtube Link: https://www.youtube.com/watch?v=eyCj_u3PoJE&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=17&t=202s
// Submission Link: https://leetcode.com/submissions/detail/517770909/

//-----------------------------------Main Code Starts-------------------------------------------//

class Solution {
public:
    
    void generate(int open, int close, string op, vector<string>& ans)
    {
        if(open == 0 and close == 0)
        {
            ans.push_back(op);
            return ;
        }

        if(open != 0)
        {
            string op1 = op;
            op1.push_back('(');
            generate(open - 1, close, op1, ans);
        }

        if(close > open)
        {
            string op2 = op;
            op2.push_back(')');
            generate(open, close - 1, op2, ans);
        }

    }
    
    vector<string> generateParenthesis(int n) 
    {
        int open = n;
        int close = n;
        
        string op = "";
        
        vector<string> ans;
        generate(open, close, op, ans);    

        return ans;
        
    }
};