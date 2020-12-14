#![allow(dead_code)]
struct Solution;
use std::collections::HashSet;
impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let len = nums.len();
        return len != nums.into_iter().collect::<HashSet<_>>().len();
    }
}

fn main() {}
