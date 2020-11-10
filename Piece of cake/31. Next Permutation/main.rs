#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn next_permutation(nums: &mut Vec<i32>) {
        if nums.len() < 2 {
            return;
        }
        let mut right = nums.len() - 1;
        while right > 0 && nums[right - 1] >= nums[right] {
            right -= 1
        }
        if (right == 0) {
            nums.reverse();
            return;
        }
        let mut mid = nums.len() - 1;
        while right <= mid && !(nums[right - 1] < nums[mid]) {
            mid -= 1;
        }
        nums.swap(right - 1, mid);
        nums[right..].reverse();
    }
}

fn main() {}
