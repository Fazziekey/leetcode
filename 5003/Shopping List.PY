# Kelly, being the great programmer that she is, is frequently thinking of “the next big thing” for apps. One morning Kelly thought of the brilliant idea to create a social network for grocery shopping lists. Kelly wants to make her social network connect people that buy the same things from the grocery store so she needs your help coming up with a program to figure out when users are buying the same things at the grocery store so her site can run relevant ads. Kelly wants to compare a user’s latest shopping list to all of their previous shopping lists and find out which items they buy every time they go to the store.

# Input
# The first line of the input will contain two space separated integers:  (), the number of shopping lists, and  (), the number of items on each of those lists. Each of the following  lines is one of the shopping lists, containing  space-separated items each. Each item is less than  characters long and made only of lowercase English characters.

# Output
# Output an integer  giving the number of items that are found on every list on the first line. On the next  lines, print these items in alphabetical order, one item per line.

# Sample Input 1	Sample Output 1
# 4 5
# bread carrots cheese eggs milk
# milk carrots bread pasta yogurt
# corn bread kale spinach carrots
# milk bread cheese carrots yogurt
# 2
# bread
# carrots

if __name__ == '__main__':
    n, m = map(int, input().split())
    a = []
    for i in range(n):
        a.append(set(input().split()))
    b = a[0]
    for i in range(1, n):
        b = b.intersection(a[i])
    print(len(b))
    for i in b:
        print(i)