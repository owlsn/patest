# 1012. The Best Rank (25)

<table>
<thead>
<th>时间限制</th><th>内存限制</th><th>代码长度限制</th><th>判题程序</th><th>作者</th>
</thead>
<tbody>
<tr><td>400 ms</td><td>65536 kB</td><td>16000 B</td><td>Standard</td><td>CHEN, Yue</td></tr></tbody>
</table>

#### To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algebra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.

#### For example, The grades of C, M, E and A - Average of 4 students are given as the following:

<pre>
StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
</pre>
#### Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

### Input

#### Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (<=2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.

### Output

#### For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.

#### The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.

#### If a student is not on the grading list, simply output "N/A".

<table>
<thead>
<th>Sample Input</th><th>Sample Output</th>
</thead>
<tbody>
<tr><td>5 6<br/>310101 98 85 88<br/>
310102 70 95 88<br/>310103 82 87 94<br/>310104 91 91 91<br/>310105 85 90 90<br/>310101<br/>310102<br/>310103<br/>310104<br/>310105<br/>999999</td><td>1 C<br/>1 M<br/>1 E<br/>1 A<br/>3 A<br/>N/A</td></tr></tbody>
</table>