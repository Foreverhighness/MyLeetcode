#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn maximum_gap(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        if len < 2 {
            return 0;
        }
        let (mut min, mut max) = (i32::MAX, i32::MIN);
        nums.iter().for_each(|&x| {
            min = min.min(x);
            max = max.max(x);
        });
        let d = 1.max((max - min) as usize / (len - 1));
        let size = 1 + (max - min) as usize / d;
        let mut buckets = vec![None; size];
        nums.into_iter().for_each(|val| {
            let b = &mut buckets[(val - min) as usize / d];
            if let Some((x, y)) = b {
                *x = val.min(*x);
                *y = val.max(*y);
            } else {
                *b = Some((val, val));
            }
        });
        buckets
            .into_iter()
            .filter_map(|x| x)
            .fold((0, min), |(res, prv), (min, max)| (res.max(min - prv), max))
            .0
    }
}

fn main() {}
