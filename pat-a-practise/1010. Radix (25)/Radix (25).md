# 1010. Radix (25)

<table>
<thead>
<th>时间限制</th><th>内存限制</th><th>代码长度限制</th><th>判题程序</th><th>作者</th>
</thead>
<tbody>
<tr><td>400 ms</td><td>65536 kB</td><td>16000 B</td><td>Standard</td><td>CHEN, Yue</td></tr></tbody>
</table>

#### Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is "yes", if 6 is a decimal number and 110 is a binary number.

#### Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while that of the other is given.

### Input Specification:

#### Each input file contains one test case. Each case occupies a line which contains 4 positive integers:
#### N1 N2 tag radix
#### Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set {0-9, a-z} where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number "radix" is the radix of N1 if "tag" is 1, or of N2 if "tag" is 2.

### Output Specification:

#### For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print "Impossible". If the solution is not unique, output the smallest possible radix.

<table>
<thead>
<th>Sample Input1</th><th>Sample Output1</th>
</thead>
<tbody>
<tr><td>6 110 1 10</td><td>2</td></tr></tbody>
</table>
<table>
<thead>
<th>Sample Input2</th><th>Sample Output2</th>
</thead>
<tbody>
<tr><td>1 ab 1 2</td><td>Impossible</td></tr></tbody>
</table>