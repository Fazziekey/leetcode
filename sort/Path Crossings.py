# Yraglac is the developer of a popular Android/iOS racing game that also happens to collect location data from its players all the time, even when the player is not using the app. He has now amassed a large database of the precise location  of players over time . We will refer to a triplet  as a “ping”.

# Now Yraglac wants to analyze this data to determine which players are likely to have met in person. He will probably sell this information and also use it to send targeted advertisements encouraging players to purchase a new co-op game mode add-on. Players are considered to have likely met if they have “crossed paths”, meaning that they were within  meter of each other within  seconds. Precisely, players A and B have crossed paths if there exists a ping  from player A and a ping  from player B such that the Euclidean distance from  to  is at most  meter and .

# Can you help Yraglac find all players who crossed paths?

# Input
# The first line contains two integers  and  (, ), the number of players and the total number of pings in Yraglac’s database. Next will follow  lines with one ping per line. The th line contains four integers of , , , and  (, , ).  is the player,  is the location in millimeters (where  millimeters =  meter), and  is the time in seconds. Pings may be given in any order. For a given player, there will not be two pings with the same time. Some players may not have any pings.

# It is guaranteed that there are at most  pings in any -second time window. That is, for any integer , there will be at most  pings from any player with a time between  and  inclusive.

# Output
# Output a line containing an integer  which is the total number of distinct player pairs who cross paths at least once. Note that  is possible. Then output  lines, where the th line contains two integers ,  (, ), identifying a player pair who crossed paths. The player pairs must be output in ascending order of , and if two pairs have the same , then ascending order of .

# Sample Input 1	
# 3 4
# 1 0 0 0
# 3 -1000 -1000 6
# 3 5 5 17
# 2 5 5 6

# Sample Output 1
# 1
# 1 2

if __name__ == '__main__':
    n, m = map(int, input().split())
    arr = []
    for i in range(m):
        arr.append(list(map(int, input().split())))
    arr.sort(key=lambda x: (x[3], x[0]))
    ans = []
    for i in range(m):
        for j in range(i + 1, m):
            if arr[j][3] - arr[i][3] > 10:
                break
            if arr[i][0] == arr[j][0]:
                continue
            if (arr[i][1] - arr[j][1]) ** 2 + (arr[i][2] - arr[j][2]) ** 2 <= 1000000:
                if arr[i][0] < arr[j][0]:
                    ans.append((arr[i][0], arr[j][0]))
                else:
                    ans.append((arr[j][0], arr[i][0]))
    ans = list(set(map(tuple, ans)))
    ans.sort(key = lambda x: (x[0], x[1]))
    print(len(ans))
    for i in ans:
        print(*i)