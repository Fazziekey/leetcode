'''
Modulo Solitaire is a game that can be played when you are bored. You can even play it without a phone, just on paper. First, you pick a number . Then you pick two sequences of numbers  and . Finally, you pick a starting number . Now, your goal is to go from  to  in as few moves as possible. In each move, you choose an , then multiply your current number by , add  to it, and reduce the result modulo . That is, .

Input
The first line of input contains three integers , , and . The next  lines each contain two integers, a pair  and .

Output
Output a single integer, the minimum number of moves needed to reach  starting from . If it is not possible to reach  in any number of moves, output .

Sample Input 1	
5 2 1
2 1
3 1

Sample Output 1
2

---
1000000 10 1
2 1
3 1
4 1
5 1
6 1
7 1
8 1
9 1
10 1
22 1

-----
2,1,2,2,1,4,-1,2,2,-1,4,5
'''
import time
if __name__ == "__main__":
    m, n, s = map(int, input().split())
    action = []
    for i in range(n):
        a, b = map(int, input().split())
        if a == 0 and b == 0:
            print(1)
            exit()
        action.append([a, b])
    action.sort(key=lambda x: x[0], reverse=True)
    f = [-1] * m
    f[s] = 0
    q = [s]
    # sets = set()
    # sets.add(s)
    while q:
        x = q.pop(0)
        for a, b in action:
            y = (x * a + b) % m
            if y == 0:
                print(f[x] + 1)
                exit()
            if f[y] == -1 and y != x:
                f[y] = f[x] + 1
                q.append(y)
                # sets.add(y)
    print(f[0])