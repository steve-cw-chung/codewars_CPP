/* Correct the given time to a valid format, where the minute and second position are less then 60.
The hours, minutes and seconds should always be represented with at least 2 digits (e.g. 02:02:01 is valid, 2:2:1 is not)
Input
Line 1: An integer N for the number of cases to solve.
Next N lines: A string representing the time, in the format h:m:s
Output
Line N: The repaired time string for case N.
Constraints
1 ≤ N ≤ 10
0 ≤ h,m,s ≤ 10.000
Example
Input
4
10:20:02
02:30:94
12:80:32
0:0000:00
Output
10:20:02
02:31:34
13:20:32
00:00:00 */

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

const N = parseInt(readline());
for (let i = 0; i < N; i++) {
    let [h,m,s] = readline().split(':').map(v => parseInt(v));
    if (s>=60) {
        m += Math.floor(s / 60);
        s = s % 60
    }
    if (m>=60) {
        h += Math.floor(m / 60);
        m = m % 60
    }

    console.log(`${h.toString().padStart(2, 0)}:${m.toString().padStart(2, 0)}:${s.toString().padStart(2, 0)}`)
    
}