(If the data range in the problem description is small, like 12 or 15. The problem is most likely to be solved by "state compression dp" )
​
In my solution,
​
`dis[x][y]` represents the minimun distance between node x and node y.
​
`dp[group][dst]` represents the shortest distance that a man could walk through all nodes in the "group", and finally finished at the node "dst" ("dst" is one of the node in "group").
​
To calculate `dp[][]`, enumerate every possible state (which is "group". For example, If group only has node 0 and node 2, the value of group is 101 in binary). Pick a node that is in the "group"(for example, node u), and pick a node that is not in the "group"(for example, node v). Then update `dp[group+v][v]` by getting the minimum value between `dp[group+v][v]` and `dp[group][u] + dis[u][v]`.
​