'''
The other day Unnar was playing the video game Geezer Scripts, Geezer Scripts V to be precise. He opened a door (in the game) and before he knew he was in a large and complicated cave-system, full of enemies who will attack as soon as Unnar gets to close to them. What’s worse is that the game doesn’t remember which enemies the player has already defeated so if the player leaves and comes back again the enemy will have respawned. Since Unnar is quite prone to getting lost he needs your help to find a way through the cave which incurs minimal damage to him.

Unnar’s character has some  attack points and  health points. The same is true for his enemies. When Unnar fights an enemy Unnar goes first. He subtracts his attack points from the enemies health points and the enemy then does the same. This process is repeated until either Unnar or the enemy has fewer than  health points. The loser is the one who ran out of health points. If Unnar loses it’s Game Over, but if Unnar wins he can continue traversing the cave-system but his lost health points do not regenerate.

The cave-system is not evenly elevated so its passages are one-way. The cave-system can be modelled using  areas connected with  one-way passages. Unnar starts in area  and wants to get to area . Every passage contains an enemy but the areas are safe.

Input
The first line of the input contains two integers  where  denotes Unnar’s attack points and  his health points. The second line contains  where  is the number of ares in the cave and  the number of passages. The next  lines contain four integers  and , indicating a passage from area  to  whose enemy has  attack points and  health points.

Output
If Unnar can’t get through the cave-system output ‘Oh no’, without the quotes. Otherwise output the maximum health Unnar can have after getting through the cave-system.

Sample Input 1	
1 2
3 2
1 2 1 2
2 3 1 2

Sample Output 1
Oh no
Sample Input 2	
1 3
3 2
1 2 1 2
2 3 1 2

Sample Output 2
1
Sample Input 3	
5 20
5 6
1 2 10 6
1 3 2 15
1 4 1 33
2 5 1 7
3 4 1000 5
4 2 5 9

Sample Output 3
10
'''
from heapq import heappush, heappop
if __name__ == "__main__":

    A, H = map(int, input().split())
    n, m = map(int,input().split())

    graph = [[] for i in range(n+1)]
    for i in range(m):
        u, v, a, h = map(int,input().split())
        w = (h - 1) // A * a
        graph[u].append((v, w))

    # print(graph)
    INF = int(1e9)
    dist = [INF] * (n + 1)

    dist[1] = 0
    pq = []
    heappush(pq, (0, 1))

    # sort the pairs by non-decreasing distance from s
    while (len(pq) > 0):                    # main loop
        d, u = heappop(pq)                  # shortest unvisited u
        if (d > dist[u]): continue          # a very important check
        for v, w in graph[u]:                  # all edges from u
            if (dist[u]+w >= dist[v]): continue # not improving, skip
            dist[v] = dist[u]+w             # relax operation
            if H - dist[v] < 0:
                continue
            heappush(pq, (dist[v], v))  

    if dist[n] == INF or dist[n] >= H:
        print("Oh no")
    else:
        print(H - dist[n])