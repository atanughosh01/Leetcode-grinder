**Idea:**

For `grid[i][j]`, it can't be higher than the maximun of its row nor the maximum of its col.\
So the maximum increasing height for a building at (i, j) is `min(row[i], col[j]) - grid[i][j]`.
​

<br>

**Codes:**

`rows`: maximum for every row\
`cols`: maximum for every col\
The fisrt loop of grid calcule maximum for every row and every col.\
The second loop calculate the maximum increasing height for every building.

<br>

**Complexity**

O(N^2)
