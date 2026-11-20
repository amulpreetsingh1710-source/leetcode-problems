class Solution {
public:

    bool isCycleDfs(int src, vector<vector<int>>& edges,vector<bool> &vis, vector<bool> &recPath){
        vis[src] = true;
        recPath[src] = true;

        for(int i = 0; i< edges.size(); i++){
            int u = edges[i][1];
            int v = edges[i][0];

            if(u == src){
                if(!vis[v]){
                    if(isCycleDfs(v, edges, vis, recPath)){
                        return true;
                    }
                }
                else if(recPath[v]){
                    return true;
                }
            }

        }
        
        recPath[src] = false;
        return false;
    }


    void topoOrder(int curr, vector<vector<int>>& p, vector<bool> &vis, stack<int> &s){

        vis[curr] = true;

        for(int i = 0; i< p.size(); i++){
            if(p[i][1] == curr){
                if(!vis[p[i][0]]){
                    topoOrder(p[i][0], p, vis, s);
                }
            }
        }

        s.push(curr);

    }

    vector<int> findOrder(int n, vector<vector<int>>& p) {
        
        vector<bool> recPath(n, false);
        vector<bool> vis(n, false);
        vector<int> ans;

        for(int i = 0; i< n; i++){
            if(!vis[i]){
                if(isCycleDfs(i, p, vis, recPath)){
                    return ans;
                }
            }
        }

        stack<int> s;
        vis.assign(n, false);

        for(int i = 0; i< n; i++){
            if(!vis[i]){
                topoOrder(i, p, vis, s);
                    
            }
        }
    
        while(s.size()!= 0){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;

        
    }
};