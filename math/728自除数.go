func selfDividingNumbers(left int, right int) []int {
    natrue_num := make([]int,right - left + 1)
    natrue_num = natrue_num[:0]
    for num := left ; num <= right;num++{
        flag := 1
        i := num
        for ;i > 0;i /= 10{
            j := i%10
            if j == 0 || num % j != 0{
                flag = 0
                break
            }
        }
        if flag == 1{
            natrue_num = natrue_num[0:len(natrue_num)+1]
            natrue_num[len(natrue_num) - 1] = num
        }
    }
    return natrue_num
}