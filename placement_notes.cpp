Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 1 (or true) then make all the cells of ith row and jth column as 1.


Instead of using O(m*n) space,it can be done in O(max(m,n)) space.
HINT:- just mark a1[i] as true and b[j] as true for each ma[i][j]=true.
while traversing mat[i][j],if either a[i] or b[j] is true,then mat[i][j] will also be true

It can even be done in O(1) space
