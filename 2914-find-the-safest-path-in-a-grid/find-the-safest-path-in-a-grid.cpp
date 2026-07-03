class Solution {
public:
    bool canReach(vector<vector<int>>& dist, int mid){
        int n = dist.size();

        if(dist[0][0] < mid) return false;

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(n,0));

        q.push({0,0});
        vis[0][0] = 1;

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!q.empty()){

            auto curr = q.front();
            q.pop();

            int r = curr.first;
            int c = curr.second;

            if(r == n-1 && c == n-1)
                return true;

            for(int k=0;k<4;k++){

                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr>=0 && nr<n &&
                   nc>=0 && nc<n &&
                   !vis[nr][nc] &&
                   dist[nr][nc] >= mid){

                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }

        return false;
        
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();

            int r = curr.first;
            int c = curr.second;

            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == INT_MAX){
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }
        int low = 0;
        int high = n*n;
        int ans = 0;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(canReach(dist,mid)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;   
    }
};