# You and a friend have been playing a card game for a while. In the game, a player has a list of cards, each containing an integer. The goal is to guess exactly what cards the opponent has. To accomplish this, they take turns asking the opponent how many of the integers on their cards are in a given range.

# Normally, answering this question is simple – just count the cards. To make the game a bit harder, your friend proposed instead playing a massive variant of the game, where each player can have up to  cards! Answering the opponent’s questions by counting cards one at a time is now quite slow... Perhaps you could write a computer program to answer these questions a bit faster?

# Input
# The first line of the input contains an integer  (), the number of cards one of the players has. The next line contains the  integers written on the player’s cards, each between  and .

# The next line contains an integer  (), the number of ranges to count cards in. The next  lines each contains two integers  and  (), the integer range given in a question.

# Output
# For each range , output the number of cards with an integer  such that .

# Sample Input 1	Sample Output 1
# 5
# 1 2 3 4 5
# 5
# 1 5
# 3 4
# 2 2
# 6 6
# 0 0
# 5
# 2
# 1
# 0
# 0
# Sample Input 2	Sample Output 2
# 10
# 4 2 4 2 4 2 4 2 4 2
# 2
# 2 2
# 4 4
# 5
# 5
import random

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    # arr = [random.randint(0,1000000000) for x in range(n)]
    arr.sort()
    m = int(input())
    for i in range(m):
        a, b = map(int, input().split())
        # a, b = random.randint(0,1000000000), random.randint(0,1000000000)
        left = 0
        right = n
        while left < right:
            mid = (left + right) // 2
            if arr[mid] >= a:
                right = mid
            else:
                left = mid + 1
        left2 = 0
        right2 = n
        while left2 < right2:
            mid = (left2 + right2) // 2
            if arr[mid] > b:
                right2 = mid
            else:
                left2 = mid + 1
        print(left2 - left)


