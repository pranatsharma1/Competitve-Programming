// Date: 05/07/2021

// Problem Link: https://leetcode.com/problems/letter-case-permutation/
// Youtube Link: https://www.youtube.com/watch?v=4eOPYDOiwFo&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=16
// Submission Link: https://leetcode.com/submissions/detail/517690365/

// Time Complexity: O(2^n)
// Space Complexity: O(n)

//-----------------------------------Main Code Starts-------------------------------------------//

class Solution {
public:
    
    void find_permutation(string ip, string op, vector<string>& ans)
    {
        if((int)ip.size() == 0)
        {
            ans.push_back(op);
            return ;
        }
        
        if(ip[0] >= '0' and ip[0] <= '9')
        {
            string op1 = op;
            op.push_back(ip[0]);
            ip.erase(ip.begin());
            find_permutation(ip, op, ans);
        }
        else
        {
            string op1 = op;
            string op2 = op;
            
            op1.push_back(toupper(ip[0]));
            op2.push_back(tolower(ip[0]));
            ip.erase(ip.begin());
            
            find_permutation(ip, op1, ans);
            find_permutation(ip, op2, ans);
            
        }
        
    }
    
    vector<string> letterCasePermutation(string s) 
    {
        string ip = s;
        string op = "";
        
        vector<string> ans;
        find_permutation(ip, op, ans);
        
        return ans;
    }
};