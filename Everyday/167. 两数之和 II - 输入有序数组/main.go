package main

import "fmt"

func twoSum(numbers []int, target int) []int {

	numbersMap := make(map[int]int)

	for idx, number := range numbers {
		numbersMap[number] = idx + 1
	}

	base := target / 2
	odd := target % 2

	count := len(numbers)

	for i := 0; i < count; i++ {
		for j := 0; j < count; j++ {
			little, littleOk := numbersMap[base-i]

			if littleOk {
				big, bigOk := numbersMap[base+j+odd]
				if bigOk {
					if little == big {
						break
					}

					if j-i == 0 {
						if little > big {
							return []int{big, little}
						}
						return []int{little, big}

					}

					if j-i > 0 {
						break
					}

					if j-i < 0 {
						continue
					}

				}
			}
		}
	}

	return []int{0, 0}
}

func main() {
	nums1 := []int{2, 7, 11, 15}
	target1 := 9

	nums2 := []int{2, 3, 4}
	target2 := 6

	nums3 := []int{-1, 0}
	target3 := -1

	nums4 := []int{0, 0, 3, 4}
	target4 := 0

	fmt.Println(twoSum(nums1, target1))
	fmt.Println(twoSum(nums2, target2))
	fmt.Println(twoSum(nums3, target3))
	fmt.Println(twoSum(nums4, target4))
}
