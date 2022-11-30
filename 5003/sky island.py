'''
Alex wants to build a sky base consisting of  sky islands, numbered . There are a total of  bridges, directly connecting certain islands to others. Because she does not have an elytra (wings that enable players to fly) and cannot fly, she needs to make sure that there exists a way for her to travel from one island to any other island. It is fine if she needs to travel through other islands to get to the destination. We call her islands connected if it exhibits such property. Note: a single island is always connected.

Given the number of islands  and all the bridges , would you be able to determine whether Alex’s islands are connected?



Input
The first line of input consists of two space-separated integers,  and , representing the number of islands and the number of bridges respectively. The following  lines each consist of two space-separated integers , representing a bridge between island  and island .

Output
Output “YES” if all of Alex’s islands are connected. Output “NO” otherwise.

Sample Input 1	
4 3
1 2
2 3
3 4
Sample Output 1
YES
Sample Input 2	
4 4
1 2
2 3
3 4
4 1
Sample Output 2
YES
Sample Input 3	
4 3
1 2
2 1
3 4
Sample Output 3
NO
'''

if __name__ == '__main__':
    n, m = map(int, input().split())
    graph = {}
    for i in range(1, n+1):
        graph[i] = []
    for i in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    visited = [False] * (n+1)
    def dfs(node):
        visited[node] = True
        for i in graph[node]:
            if not visited[i]:
                dfs(i)
    dfs(1)
    if False in visited[1:]:
        print('NO')
    else:
        print('YES')
