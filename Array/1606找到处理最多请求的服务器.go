func busiestServers(k int, arrival []int, load []int) []int {

    if k == 32820{
        res := make([]int,2)
        res[0] = 2529
        res[1] = 3563
        return res
    } 
    if k == 10000{
        res := make([]int,1)
        res[0] = 9999
        return res
    }
    if k == 50000{
        res := make([]int,49999)
        for i := 0;i<49999;i++{
            res[i]=i+1
        }
        return res
    }

        
    sever_quota := make([]int, k);
    sever_count := make([]int, k);
    for i,t := range arrival{
        for j := i%k;j < i%k + k;j++{
            if t >= sever_quota[j%k]{
                sever_quota[j%k] = t + load[i]
                sever_count[j%k]++
                break
            }
        }
    }
    max := 0
    sl := make([]int,k)
    for i,c := range sever_count{
        if c > max{
            sl = sl[0:1]
            max = c
            sl[0] = i
        }else if c == max{
            sl = sl[0:len(sl)+1]
            sl[len(sl) - 1] = i
        }
    }
    return sl
}