#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn k_closest(mut points: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let (a, _, _) = points.select_nth_unstable_by_key(k as usize, |x| x[0] * x[0] + x[1] * x[1]);
        a.into()
    }
}

fn main() {
    println!("{:?}", Solution::k_closest(vec![vec![1,3],vec![-2,2]], 1));
    println!("{:?}", Solution::k_closest(vec![vec![3,3],vec![5,-1],vec![-2,4]], 2));
}