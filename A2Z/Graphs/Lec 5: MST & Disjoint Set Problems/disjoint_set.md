this is the most important topic in the graph series and commonly asked in almost all interview and online assessment. so you gotta master it. <br>
### Disjoint set
1. **Definition**: A disjoint set is a way to group items into separate groups where no group overlaps. Its called disjoint set because there are no common node between two sets. S1 ∩ S2 = ∅, where S1 = {1,2,3,4}, S2 = {5,6,7}
2. **Properties**:  
   - It has two main tasks:
   - 1. Find: Check which group an item belongs to.
   - 2. Union: Combine two groups into one.
   - It’s useful for solving problems like connecting things or finding if two things are in the same group.

3. **Better Understanding**:
   - suppose there is a graph with two separate components {1,2,3,4} and {5,6,7}
   - if it was asked that does 1 and 5 belong to the same component or not
   - what is brute force approach, we will pick up 1 and start dfs traversal, so since it couldnt find 5, means they dont belong to the same component
   - but it will take linear time complexity O(E+V)
   - this is where disjoint set comes in the scene and says im gonna do this is constant time
   - this works in dynamic graphs
   - look upon this following edges, (1,2), (2,3), (4,5), (6,7), (5,6), (3,7)
   - if we stop the graph formation in (6,7) and ask does 4 and 1 belong to the same component. till this point they are not
   - so at any stage there can be question like this and we need to answer this in constant time 







