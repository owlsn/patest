# 1006. Sign In and Sign Out (25)

<table>
<thead>
<th>时间限制</th><th>内存限制</th><th>代码长度限制</th><th>判题程序</th><th>作者</th>
</thead>
<tbody>
<tr><td>400 ms</td><td>65536 kB</td><td>16000 B</td><td>Standard</td><td>CHEN, Yue</td></tr></tbody>
</table>

#### At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.

### Input Specification:

#### Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:

#### ID_number Sign_in_time Sign_out_time
#### where times are given in the format HH:MM:SS, and ID number is a string with no more than 15 characters.

### Output Specification:

#### For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.

#### Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.

<table>
<thead>
<th>Sample Input</th><th>Sample Output</th>
</thead>
<tbody>
<tr><td>3<br/>CS301111 15`:`30`:`28 17`:`00`:`10<br/>SC3021234 08`:`00`:`00 11`:`25`:`25<br/>CS301133 21`:`45`:`00 21`:`58`:`40</td><td>SC3021234 CS301133</td></tr></tbody>
</table>