class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long,long>>> edge(n);
        for(int i=0; i<roads.size(); i++){
            edge[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            edge[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        } 

        priority_queue <pair<long,long>, vector<pair<long,long>>, greater<pair<long,long>>> pq;
        vector<long long> dist(n,LLONG_MAX);
        vector<long long> ways(n,0);

        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});

        while(!pq.empty()){
            pair<long,long> top = pq.top();

            long long currDist = top.first;
            long long currNode = top.second;
            pq.pop();
            if(currDist>dist[currNode]) continue;

            for(auto& it: edge[currNode]){
                if(currDist+it.second<dist[it.first]){
                    dist[it.first]=currDist+it.second;
                    ways[it.first] = ways[currNode];
                    pq.push({dist[it.first],it.first});
                }else if(currDist+it.second==dist[it.first]){
                    ways[it.first] += ways[currNode];
                    ways[it.first] %= ((int)1e9+7);
                }
            }
        }
        return ways[n-1];
    }
};