# 1053. Path of Equal Weight (30)

<table>
<thead>
<th>时间限制</th><th>内存限制</th><th>代码长度限制</th><th>判题程序</th><th>作者</th>
</thead>
<tbody>
<tr><td>100 ms</td><td>65536 kB</td><td>16000 B</td><td>Standard</td><td>CHEN, Yue</td></tr></tbody>
</table>

#### Given a non-empty tree with root R, and with weight Wi assigned to each tree node Ti. The weight of a path from R to L is defined to be the sum of the weights of all the nodes along the path from R to any leaf node L.

#### Now given any weighted tree, you are supposed to find all the paths with their weights equal to a given number. For example, let's consider the tree showed in Figure 1: for each node, the upper number is the node ID which is a two-digit number, and the lower number is the weight of that node. Suppose that the given number is 24, then there exists 4 different paths which have the same given weight: {10 5 2 7}, {10 4 10}, {10 3 3 6 2} and {10 3 3 6 2}, which correspond to the red edges in Figure 1.

<image src="https://raw.githubusercontent.com/owlsn/patest/master/pat-a-practise/1032.%20Sharing%20(25)/5b_mj58f84v11w"/>
Figure 1
### Input Specification:

#### Each input file contains one test case. Each case starts with a line containing 0 < N <= 100, the number of nodes in a tree, M (< N), the number of non-leaf nodes, and 0 < S < 230, the given weight number. The next line contains N positive numbers where Wi (<1000) corresponds to the tree node Ti. Then M lines follow, each in the format:

#### ID K ID[1] ID[2] ... ID[K]
#### where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 00.

### Output Specification:

#### For each test case, print all the paths with weight S in non-increasing order. Each path occupies a line with printed weights from the root to the leaf in order. All the numbers must be separated by a space with no extra space at the end of the line.

#### Note: sequence {A1, A2, ..., An} is said to be greater than sequence {B1, B2, ..., Bm} if there exists 1 <= k < min{n, m} such that Ai = Bi for i=1, ... k, and Ak+1 > Bk+1.

<table>
<thead>
<th>Sample Input1</th><th>Sample Output1</th>
</thead>
<tbody>
<tr><td>20 9 24<br/>10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2<br/>00 4 01 02 03 04<br/>02 1 05<br/>04 2 06 07<br/>03 3 11 12 13<br/>06 1 09<br/>07 2 08 10<br/>16 1 15<br/>13 3 14 16 17<br/>17 2 18 19</td><td>10 5 2 7<br/>10 4 10<br/>10 3 3 6 2<br/>10 3 3 6 2</td></tr></tbody>
</table>