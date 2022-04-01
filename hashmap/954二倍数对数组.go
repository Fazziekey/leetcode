func canReorderDoubled(arr []int) bool {
    sort.Ints(arr)
    double_map := make(map[int]int,len(arr))
    for _,num := range arr{
        if num >= 0{
            break
        }
        if _, ok := double_map[num*2]; ok {
            if double_map[num*2] > 0{
                double_map[num*2]--
            }else{
                double_map[num]++ 
            }

        }else{
            double_map[num]++  
            
        }
    }
    for i := len(arr)-1;i >= 0;i--{
        if arr[i] < 0{
            break
        }
        if _, ok := double_map[arr[i]*2]; ok {
            if double_map[arr[i]*2] > 0{
                double_map[arr[i]*2]--
            }else{
                double_map[arr[i]]++ 
            }
            
        }else{
            double_map[arr[i]]++  
        }
    }
    for _, value := range double_map {
        if value != 0{
            return false
        }
    }
    return true
}