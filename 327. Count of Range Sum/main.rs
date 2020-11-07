#![allow(dead_code)]
struct Solution;
use std::collections::BTreeSet;
use std::iter::once;
use std::ops::Bound::Included;
impl Solution {
    pub fn count_range_sum(nums: Vec<i32>, lower: i32, upper: i32) -> i32 {
        let (lower, upper) = (lower as i64, upper as i64);
        let (mut sum, mut res) = (0, 0);
        let mut set = BTreeSet::new();
        for (i, v) in once(0).chain(nums.into_iter()).enumerate() {
            sum += v as i64;
            res += set.range((Included(&(sum - upper, 0)), Included(&(sum - lower, i)))).count();
            set.insert((sum, i));
        }
        res as i32
    }
}

fn main() {}
