#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn find_pairs(mut nums: Vec<i32>, k: i32) -> i32 {
        let (mut l, mut ret, n) = (0, 0, nums.len());
        nums.sort_unstable();
        for r in 1..n {
            while nums[r] - nums[l] > k {
                l += 1;
            }
            if l != r && nums[r] - nums[l] == k && (r == n - 1 || nums[r] != nums[r + 1]) {
                ret += 1;
            }
        }
        ret
    }
}

fn main() {}
