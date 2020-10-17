package main

import "fmt"

func singleNumber(nums []int) int {
	var (
		seenOnce  int
		seenTwice int
	)

	for _, num := range nums {
		seenOnce = ^seenTwice & (seenOnce ^ num)
		seenTwice = ^seenOnce & (seenTwice ^ num)
	}

	return seenOnce
}

func main() {
	nums1 := []int{2, 2, 3, 2}
	nums2 := []int{0, 1, 0, 1, 0, 1, 99}

	fmt.Println(singleNumber(nums1))
	fmt.Println(singleNumber(nums2))
}
