package main

func singleNumber(nums []int) int {
    result := 0
    for _,v := range nums{
        result ^= v 
    }
    return result
}
