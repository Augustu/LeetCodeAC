package main

import "fmt"

// solution 1
func missingNumber(nums []int) int {
	missing := len(nums)
	for idx, num := range nums {
		missing ^= idx ^ num
	}
	return missing
}

func main() {
	fmt.Println(missingNumber([]int{3, 0, 1}))
	fmt.Println(missingNumber([]int{9, 6, 4, 2, 3, 5, 7, 0, 1}))
}
