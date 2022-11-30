'''
Nomads, Kingdoms, and Tribes are on the islands of the great seas. Bridges span between islands allowing travel between them. It is possible to get from every island to every other island through some sequence of bridges. The islands were at peace until everything changed when the Spanning Nation attacked!

Initially the Spanning Nation occupies island 1. From that point forward, the Spanning Nation can attack any island that is directly connected to some island already conquered by the Spanning Nation. Thankfully wars are resolved without any fighting. The Spanning Nation only attacks an island if the island’s army is strictly smaller than the Spanning Nation’s army. The smaller island army will simply concede and join the Spanning Nation’s army.

As the tactical advisor of the Spanning Nation, determine the maximum possible army size the Spanning Nation can have after making a series of attacks.

Input
The first line contains the integer  (), which is the number of islands, and  (), the number of bridges.

The next  lines describe the bridges. Each of these lines contains two distinct integers  and  (), indicating that there is a bridge between the islands  and . There is at most one bridge between any pair of islands.

The next  lines describe the islands’ army size in order. Each of these lines contains a single integer  (), which is the army size of this island.

Output
Display the maximum possible army size of the Spanning Nation.

Sample Input 1	
6 5
1 4
3 4
2 4
6 3
5 4
2
4
1
0
10
2
Sample Output 1
9

Sample Input 2	
6 5
3 4
3 1
2 3
6 1
5 3
2
3
0
1
3
3
Sample Output 2
3

'''
import heapq
 
class Army():
    def __init__(self,a,b):
        self.a = a
        self.b = b
    def __lt__(self, other):
        if self.b < other.b:
            return True
        else:
            return False

if __name__ == '__main__':
    n, m = map(int, input().split())
    graph = {}
    for i in range(1, n+1):
        graph[i] = []
    for i in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    army = [0] + [int(input()) for i in range(n)]

    fix = [i for i in range(2, n+1)]
    fix.sort(key=lambda x: army[x])

    # print(fix)

    tmp = army[1]
    index = n-1
    for i in range(n-1):
        if tmp > army[fix[i]]:
           tmp += army[fix[i]]
        else:
            index = i
            break

    visited = [False] * (n+1)

    for i in range(index, n-1):
        visited[fix[i]] = True

    queue = []

    ans = army[1]
    visited[1] = True

    set = set()
    # print(army)
    # print(visited)
    for i in graph[1]:
        if not visited[i]:
            heapq.heappush(queue, Army(i, army[i]))
            set.add(i)

    while queue:
        island = heapq.heappop(queue)
        if island.b < ans:
            ans += island.b
            visited[island.a] = True
            for i in graph[island.a]:
                if not visited[i]:
                    if i not in set:
                        heapq.heappush(queue, Army(i, army[i]))
                        set.add(i)
        else:
            break

    print(ans)