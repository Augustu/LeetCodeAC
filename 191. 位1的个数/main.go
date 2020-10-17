package main

import "fmt"

func hammingWeight(num uint32) int {
	var mask uint32 = 1

	count := 0
	for i := 0; i < 32; i++ {
		if (num & mask) == 1 {
			count++
		}
		num = num >> 1
	}

	return count
}

func main() {
	nums1 := uint32(00000000000000000000000000001011)
	// target1 := 9

	nums2 := uint32(00000000000000000000000010000000)
	// target2 := 6

	// nums3 := uint32(11111111111111111111111111111101)

	// nums3 := []int{-1, 0}
	// target3 := -1

	// nums4 := []int{0, 0, 3, 4}
	// target4 := 0

	fmt.Println(hammingWeight(nums1))
	fmt.Println(hammingWeight(nums2))
	// fmt.Println(hammingWeight(nums3))
	// fmt.Println(twoSum(nums3, target3))
	// fmt.Println(twoSum(nums4, target4))
}
