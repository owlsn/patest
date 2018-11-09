# 1032. Sharing (25)

<table>
<thead>
<th>时间限制</th><th>内存限制</th><th>代码长度限制</th><th>判题程序</th><th>作者</th>
</thead>
<tbody>
<tr><td>100 ms</td><td>65536 kB</td><td>16000 B</td><td>Standard</td><td>CHEN, Yue</td></tr></tbody>
</table>

#### To store English words, one method is to use linked lists and store a word letter by letter. To save some space, we may let the words share the same sublist if they share the same suffix. For example, "loading" and "being" are stored as showed in Figure 1.

<image src="https://raw.githubusercontent.com/owlsn/patest/master/pat-a-practise/1032.%20Sharing%20(25)/1w_m16pjsommxz.jpg"/>
Figure 1

#### You are supposed to find the starting position of the common suffix (e.g. the position of "i" in Figure 1).

### Input Specification:

#### Each input file contains one test case. For each case, the first line contains two addresses of nodes and a positive N (<= 105), where the two addresses are the addresses of the first nodes of the two words, and N is the total number of nodes. The address of a node is a 5-digit positive integer, and NULL is represented by -1.

#### Then N lines follow, each describes a node in the format:

#### Address Data Next

#### where Address is the position of the node, Data is the letter contained by this node which is an English letter chosen from {a-z, A-Z}, and Next is the position of the next node.

### Output Specification:

#### For each case, simply output the 5-digit starting position of the common suffix. If the two words have no common suffix, output "-1" instead.


<table>
<thead>
<th>Sample Input1</th><th>Sample Output1</th>
</thead>
<tbody>
<tr><td>11111 22222 9<br/>67890 i 00002<br/>00010 a 12345<br/>00003 g -1<br/>12345 D 67890<br/>00002 n 00003<br/>22222 B 23456<br/>11111 L 00001<br/>23456 e 67890<br/>00001 o 00010</td><td>67890</td></tr></tbody>
</table>
<table>
<thead>
<th>Sample Input1</th><th>Sample Output1</th>
</thead>
<tbody>
<tr><td>00001 00002 4<br/>00001 a 10001<br/>10001 s -1<br/>00002 a 10002<br/>10002 t -1</td><td>-1</td></tr></tbody>
</table>