1. if theres n number of vertices, there will be nC2 edges, and 2 ^ (nC2) number of total combination of graphs that can be made 

2. vector<int> adj [N] is wrong , absolutely wrong, cause standard c++ doesnt get VLAs... it should be
3. vector<vector<int>> adj (n) or vector<vector<int>> adj (n, vector<int>(n,0))
