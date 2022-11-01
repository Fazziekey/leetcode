'''
Input
The first line of input contains two space-separated integers  and  , the number of people at your house and the number of available cars. Then follow  lines containing a single integer each; the th such integer is the number of seconds   that it takes person  to drive from your house to the stadium, or vice-versa.

Output
Print the minimum number of seconds it takes to move all  people from your house to the stadium, if all people coordinate and drive optimally.

Sample Input 1	
11 2
12000
9000
4500
10000
12000
11000
12000
18000
10000
9000
12000

Sample Output 1
13500

Sample Input 2	
6 2
1000
2000
3000
4000
5000
6000

Sample Output 2
2000

16 3
1000
1000
3000
4000
5000
6000
3000
4000
5000
6000
1500
3000
4000
5000
6000
9999

'''

import heapq
 
class Car():
    def __init__(self,a,b):
        self.a = a
        self.b = b
    def __lt__(self, other):
        if self.a < other.a:
            return True
        else:
            return False



if __name__ == "__main__":
    n, k = map(int, input().split())
    arr = [int(input()) for i in range(n)]
    arr.sort()

    if n < k:
        people = arr
    else:
        people = arr[:k]
    cars = []
    for i in range(len(people)):
        car = Car(people[i], people[i])
        heapq.heappush(cars, car)

    while n > 0 :
        
        car = heapq.heappop(cars)
        if car.a == car.b:
            n -= 5
        else:
            n -= 4
        car.a += 2 * car.b
        
        heapq.heappush(cars, car)

    max_time = 0
    while cars:
        car = heapq.heappop(cars)
        if car.a - 2 * car.b > max_time:
            max_time = car.a - 2 * car.b

    print(max_time)