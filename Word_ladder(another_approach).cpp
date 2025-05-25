class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string,vector<string>> mp;
    unordered_map<string,int> vis;
    //vis[beginWord]=1;
    unordered_set<string> s(wordList.begin(),wordList.end());
    if(s.find(endWord)==s.end())
    return 0;
    for(int i=0;i<wordList.size();i++)
    {
        string pattern=wordList[i];
        for(int j=0;j<pattern.size();j++)
        {
            string x=pattern.substr(0,j)+'*'+pattern.substr(j+1,pattern.size()-j-1);
            mp[x].push_back(pattern);
        }
    }
   
    queue<pair<string,int>> q;
    q.push({beginWord,1});
    vis[beginWord]=1;
    int res=0;
    while(!q.empty())
    {
        
        string now=q.front().first;
        res=q.front().second;
        q.pop();
        if(now==endWord)
        return res;
        
        for(int j=0;j<now.size();j++)
        {
            string x=now.substr(0,j)+'*'+now.substr(j+1,now.size()-j-1);
            for(int i=0;i<mp[x].size();i++)
            {
                string pat=mp[x][i];
                if(!vis[pat])
                {
                    vis[pat]=1;
                    q.push({pat,res+1});
                }
            }
        }
        }
      return 0;
    }
    
     
        
    
};
