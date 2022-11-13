# You are the main organiser of an annual running race, where partipants must complete  laps. The prizes are even larger than last year, and you have attracted more partipants than expected.

# Every participant has a unique start number for identification. In previous years, there was ample time to hand out start numbers on the day of the race. But this year, every contestant receives their start number already when they register. Starting numbers are handed out in increasing sequence, beginning from . As a consequence, cancellations lead to gaps in the sequence of start numbers on the day of the race.

# The large number of contestants also leads to other logistical challenges. One is that it would take several days to produce the final ranking by hand, so you have decided to use a computer. Write a program that computes the final ranking from the individual lap times. The race is planned in such a way that all participants will be too exhausted to continue after  laps.

# Input
# Three integers , , and : how many lap times were recorded, how many laps are needed to finish the race, and how many start numbers were handed out during registration. You can assume , , and .

# Then follow  lines, each consisting of a start number  and a lap time in the format mm.ss, where . This means that the participant with start number  has completed a lap in  minutes and  seconds.

# Output
# One line per participant who completed the race, identified by start number, and ranked from fastest to slowest. If two partipants have the same total time, rank them by start number; smallest first.

# Points
# There are three test groups.

# Group

# Points

# Constraints

# 1

# 32

# All partipants complete the race and 

# 2

# 33


# 3

# 35

'''
Sample Input 1	Sample Output 1
6 2 3
1 01.00
2 00.59
1 01.33
3 00.54
3 02.20
2 01.02
2
1
3
Sample Input 2	Sample Output 2
8 3 3
3 03.00
1 03.57
2 02.56
3 13.33
2 04.25
3 04.29
2 03.12
1 24.47
2
3
Sample Input 3	Sample Output 3
8 2 8
6 02.52
4 04.22
6 03.03
4 02.50
5 03.30
7 02.05
7 02.36
5 02.25
7
5
6
4
'''

if __name__ == '__main__':
    # read input
    n, m, k = map(int, input().split())
    times = {}
    for _ in range(n):
        s, t = input().split(' ')
        s = int(s)
        t = int(t[0])*600 + int(t[1])*60 + int(t[3])*10 + int(t[4])
        if s not in times:
            times[s] = [1, t]
        else:
            times[s][0] += 1
            times[s][1] += t
    # sort by time

    times = sorted(times.items(), key=lambda x: (x[1][1], x[0]))

    # print winners
    for s, t in times:
        if t[0] == m:
            print(s)