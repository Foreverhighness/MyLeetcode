#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn erase_overlap_intervals(mut intervals: Vec<Vec<i32>>) -> i32 {
        let mut res = intervals.len() as i32;
        intervals.sort_unstable_by_key(|v| v[1]);
        intervals.into_iter().fold(i32::MIN, |r, v| {
            if r <= v[0] {
                res -= 1;
                v[1]
            } else {
                r
            }
        });
        res
    }
}

fn main() {}
