1043. Is It a Binary Search Tree (25)

<table>
<thead>
<th>时间限制</th><th>内存限制</th><th>代码长度限制</th><th>判题程序</th><th>作者</th>
</thead>
<tbody>
<tr><td>400 ms</td><td>65536 kB</td><td>16000 B</td><td>Standard</td><td>CHEN, Yue</td></tr></tbody>
</table>

#### A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

#### The left subtree of a node contains only nodes with keys less than the node's key.
#### The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
#### Both the left and right subtrees must also be binary search trees.
#### If we swap the left and right subtrees of every node, then the resulting tree is called the Mirror Image of a BST.

#### Now given a sequence of integer keys, you are supposed to tell if it is the preorder traversal sequence of a BST or the mirror image of a BST.

### Input Specification:

#### Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N integer keys are given in the next line. All the numbers in a line are separated by a space.

### Output Specification:

#### For each test case, first print in a line "YES" if the sequence is the preorder traversal sequence of a BST or the mirror image of a BST, or "NO" if not. Then if the answer is "YES", print in the next line the postorder traversal sequence of that tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

<table>
<thead>
<th>Sample Input1</th><th>Sample Output1</th>
</thead>
<tbody>
<tr><td>7<br/>8 6 5 7 10 8 11</td><td>YES<br/>5 7 6 8 11 10 8</td></tr></tbody>
</table>
<table>
<thead>
<th>Sample Input2</th><th>Sample Output2</th>
</thead>
<tbody>
<tr><td>7<br/>8 10 11 8 6 7 5</td><td>YES<br/>11 8 10 7 5 6 8</td></tr></tbody>
</table>
<table>
<thead>
<th>Sample Input3</th><th>Sample Output3</th>
</thead>
<tbody>
<tr><td>7<br/>8 6 8 5 10 9 11</td><td>NO</td></tr></tbody>
</table>