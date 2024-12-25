Node* dfs(Node* cur, unordered_map<Node*, Node*>& mp) {
    vector<Node*> neighbour;
    Node* clone = new Node(cur->val); // creates a new node (clone) with the same value as the current node (cur).
    mp[cur] = clone; // mark the current node as visited by storing the mapping of the original node (cur) to its clone in mp.
    
    for (auto it : cur->neighbors) {
        if (mp.find(it) != mp.end()) {
            neighbour.push_back(mp[it]);
        } else {
            neighbour.push_back(dfs(it, mp));
        }
    }
    clone->neighbors = neighbour;
    return clone;
}
Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> mp;
    if (node == NULL)
        return NULL;
    
    return dfs(node, mp);
}

//The graph nodes are objects (Node*).
//Instead of int node, it uses Node* cur because:

