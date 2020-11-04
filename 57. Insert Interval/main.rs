#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let mut res = Vec::new();
        let mut it = intervals.into_iter().peekable();
        let (mut l, mut r) = (new_interval[0], new_interval[1]);
        while let Some(iv) = it.peek() {
            if l <= iv[1] {
                break;
            }
            res.push(it.next().unwrap());
        }
        while let Some(iv) = it.peek() {
            if r < iv[0] {
                break;
            }
            l = l.min(iv[0]);
            r = r.max(it.next().unwrap()[1]);
        }
        res.push(vec![l, r]);
        while let Some(iv) = it.next() {
            res.push(iv);
        }
        res
    }
}

fn main() {
    let a = vec![
        vec![1, 2],
        vec![3, 4],
        vec![4, 5],
        vec![6, 7],
        vec![8, 10],
        vec![12, 16],
    ];
    let b = vec![4,8];
    Solution::insert(a, b);
}
