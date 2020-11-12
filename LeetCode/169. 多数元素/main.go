package main

import "fmt"

func majorityElement(nums []int) int {
	countMap := make(map[int]int)

	for _, num := range nums {
		_, ok := countMap[num]
		if ok {
			countMap[num]++
		} else {
			countMap[num] = 1
		}
	}

	max := nums[0]
	for k, v := range countMap {
		if countMap[max] < v {
			max = k
		}
	}

	return max
}

func main() {
	nums1 := []int{3, 2, 3}
	// target1 := 3

	nums2 := []int{2, 2, 1, 1, 1, 2, 2}
	// target2 := 2

	// nums3 := []int{-1, 0}
	// target3 := -1

	// nums4 := []int{0, 0, 3, 4}
	// target4 := 0

	fmt.Println(majorityElement(nums1))
	fmt.Println(majorityElement(nums2))
	// fmt.Println(twoSum(nums3, target3))
	// fmt.Println(twoSum(nums4, target4))
}
