# 1052. Linked List Sorting (25)

<table>
<thead>
<th>时间限制</th><th>内存限制</th><th>代码长度限制</th><th>判题程序</th><th>作者</th>
</thead>
<tbody>
<tr><td>400 ms</td><td>65536 kB</td><td>16000 B</td><td>Standard</td><td>CHEN, Yue</td></tr></tbody>
</table>

#### A linked list consists of a series of structures, which are not necessarily adjacent in memory. We assume that each structure contains an integer key and a Next pointer to the next structure. Now given a linked list, you are supposed to sort the structures according to their key values in increasing order.

### Input Specification:

#### Each input file contains one test case. For each case, the first line contains a positive N (< 105) and an address of the head node, where N is the total number of nodes in memory and the address of a node is a 5-digit positive integer. NULL is represented by -1.

#### Then N lines follow, each describes a node in the format:

#### Address Key Next

#### where Address is the address of the node in memory, Key is an integer in [-105, 105], and Next is the address of the next node. It is guaranteed that all the keys are distinct and there is no cycle in the linked list starting from the head node.

### Output Specification:

#### For each test case, the output format is the same as that of the input, where N is the total number of nodes in the list and all the nodes must be sorted order.

<table>
<thead>
<th>Sample Input</th><th>Sample Output</th>
</thead>
<tbody>
<tr><td>5 00001<br/>11111 100 -1<br/>00001 0 22222<br/>33333 100000 11111<br/>12345 -1 33333<br/>22222 1000 12345</td><td>5 12345<br/>12345 -1 00001<br/>00001 0 11111<br/>11111 100 22222<br/>22222 1000 33333<br/>33333 100000 -1</td></tr></tbody>
</table>