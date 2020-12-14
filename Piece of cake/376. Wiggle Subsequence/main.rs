#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn wiggle_max_length(nums: Vec<i32>) -> i32 {
        if nums.len() < 2 {
            return nums.len() as i32;
        }
        let (mut up, mut down) = (1, 1);
        for i in 1..nums.len() {
            if nums[i - 1] < nums[i] {
                up = down + 1;
            } else if nums[i - 1] > nums[i] {
                down = up + 1;
            }
        }
        up.max(down)
    }
}

fn main() {}
