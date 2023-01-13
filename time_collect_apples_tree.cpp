class Solution {
public:
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
  {
    vector<int> go(n,-1);
    std::map<int, int> map;
    int start = -1, end =-1;
    bool setted;
    
    go[0]=1;
    int apple_count = std::count(hasApple.begin(),hasApple.end(),true);
    if(!apple_count) return 0;
    map.clear();
    for(int i=0;i<n-1;i++)
    {
        int j=0;
        start = edges[i][j];
        end = edges[i][j+1];
        if(map.find(end) != map.end())
            setted= true;
     
        map[end]=start;
        cout << "start => " << map.find(end)->second << '\n';
        cout << "end => " << map.find(end)->first << '\n';
        if (hasApple[end] == true )
        {
            
            go[start]=1;
            go[end]=1;
            auto pos =map.find(end) ;
            while(end !=0) 
            {
                pos =map.find(end) ;
                go[pos->second]=1;
                end = pos->second;
            }
            
        }
        else
        {
            go[end]=0;
            if(hasApple[start] == true)
            {
                go[start]=1;
                auto pos =map.find(end) ;
                while(end !=0) 
                {
                    pos =map.find(end) ;
                    cout << map.count(end) << endl ;
                    if(setted)
                    {
                        cout << "I find " << pos->first << "setted before " << endl;
                        go[end]=1;
                        setted = false;
                    }
                    go[pos->second]=1;
                    end = pos->second;
                }
            }
           
        }
    }
    
    int one_count = std::count(go.begin(),go.end(),1);
    return ((one_count -1) *2);
    }
};
