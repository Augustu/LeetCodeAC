package main

import "fmt"

/* solution 1
func singleNumber(nums []int) int {

	statistics := make(map[int]int)
	for _, num := range nums {
		count, ok := statistics[num]
		if ok {
			statistics[num] = count + 1
		} else {
			statistics[num] = 1
		}
	}

	for k, v := range statistics {
		if v == 1 {
			return k
		}
	}

	return 0
}
*/

/* solution 2
func singleNumber(nums []int) int {

	result := nums[0]

	for i := 1; i < len(nums); i++ {
		result = result ^ nums[i]
	}

	return result
}
*/

/* solution 3 */
func singleNumber(nums []int) int {

	var result int

	for _, num := range nums {
		result = result ^ num
	}

	return result
}

func main() {
	nums1 := []int{2, 2, 1}
	nums2 := []int{4, 1, 2, 1, 2}

	fmt.Println(singleNumber(nums1))
	fmt.Println(singleNumber(nums2))
}
