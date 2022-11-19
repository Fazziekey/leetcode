'''
Input
The input consists of a single line containing two integers  and  (, ).

Output
If it is not possible to construct a graph with the given properties, print “-1”. Otherwise, print  lines where the ’th line contains two integers , , the endpoints of the ’th edge. If there are many possible solutions, any one of them will be accepted.

Sample Input 1	
4 4
Sample Output 1
2 1
2 3
4 3
4 2
Sample Input 2	
10 100
Sample Output 2
-14950

Sample Input 3	
10 1
Sample Output 3
-1
'''

if __name__ == '__main__':
    n, m = map(int, input().split())
    if m < n - 1 or m > n + (n - 3): 
        print(-1)
        exit()
    else:
        for i in range(1, n):
            print(1, i + 1)
        m -= n - 1
        for i in range(2, n):
            if m == 0:
                break
            print(n, i)
            m -= 1