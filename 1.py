cum_cycles = [0,10]

cycle_lengths = 10
f_max = 1.
f_min = 0.001
f_start = 1.e-6 
lr_warm_up_steps = 10000
n = 100

def find_in_interval(n):
    interval = 0
    for cl in cum_cycles[1:]:
        if n <= cl:
            return interval
        interval += 1

def schedule(n):
    cycle = find_in_interval(n)
    print("cycle",cycle)
    n = n - cum_cycles[cycle]
    print("n",n)


for i in range(1, 11):
    print("i:",i)
    schedule(i)

# for n in range(1, 11):
#     f = (f_max - f_start) / lr_warm_up_steps * n + f_start
    
#     print(f)

for n in range(1, 11):
    f = f_min + (f_max - f_min) * (cycle_lengths - n) / (cycle_lengths)
    print(f)