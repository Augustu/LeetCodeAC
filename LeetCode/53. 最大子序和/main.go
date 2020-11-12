package main

import "fmt"

func maxSubArray(nums []int) int {

	var max int = nums[0]

	for i := 1; i < len(nums); i++ {
		if nums[i-1]+nums[i] > nums[i] {
			nums[i] += nums[i-1]
		}
		if max < nums[i] {
			max = nums[i]
		}
	}

	return max

}

func main() {
	nums1 := []int{-2, 1, -3, 4, -1, 2, 1, -5, 4}
	// nums2 := []int{9, 6, 4, 2, 3, 5, 7, 0, 1}

	fmt.Println(maxSubArray(nums1))
	// fmt.Println(missingNumber(nums2))
}
