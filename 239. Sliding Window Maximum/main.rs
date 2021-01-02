#![allow(dead_code)]
struct Solution;
use std::collections::VecDeque;
impl Solution {
    pub fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut que = VecDeque::with_capacity(nums.len() + 1 - k as usize);
        let mut deq = VecDeque::with_capacity(nums.len() + 1 - k as usize);
        let mut res = Vec::with_capacity(nums.len());
        let mut it = nums.into_iter();
        for _ in 0..k {
            let v = it.next().unwrap();
            que.push_back(v);
            while let Some(&b) = deq.back() {
                if b < v {
                    deq.pop_back();
                } else {
                    break;
                }
            }
            deq.push_back(v);
        }
        res.push(deq.front().copied().unwrap());
        for v in it {
            let f = que.pop_front().unwrap();
            if deq.front().copied().unwrap() == f {
                deq.pop_front();
            }
            while let Some(&b) = deq.back() {
                if b < v {
                    deq.pop_back();
                } else {
                    break;
                }
            }
            deq.push_back(v);
            que.push_back(v);
            res.push(deq.front().copied().unwrap());
        }
        res
    }
}

fn main() {}
