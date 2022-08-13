#![allow(dead_code)]
struct Solution;
use std::cmp::Reverse;
use std::collections::BinaryHeap;
impl Solution {
    pub fn max_chunks_to_sorted(arr: Vec<i32>) -> i32 {
        let mut stack = Vec::new();
        for v in arr.into_iter() {
            if stack.is_empty() || v >= *stack.last().unwrap() {
                stack.push(v);
            } else {
                let max = stack.pop().unwrap();
                while let Some(top) = stack.pop() {
                    if top <= v {
                        stack.push(top);
                        break;
                    }
                }
                stack.push(max)
            }
        }
        stack.len() as i32
    }

    pub fn max_chunks_to_sorted_nlogn(arr: Vec<i32>) -> i32 {
        let mut sorted = arr.clone();
        sorted.sort_unstable();
        let mut heap = BinaryHeap::new();
        let mut i = 0;
        let mut ans = 0;

        for v in arr.into_iter() {
            heap.push(Reverse(v));
            while let Some(&Reverse(v)) = heap.peek() {
                if v == sorted[i] {
                    i += 1;
                    heap.pop();
                    continue;
                }
                break;
            }
            if heap.is_empty() {
                ans += 1;
            }
        }
        ans
    }
}

fn main() {
    dbg!(Solution::max_chunks_to_sorted(vec![5, 4, 3, 2, 1]), 1);
    dbg!(Solution::max_chunks_to_sorted(vec![2, 1, 3, 4, 4]), 4);
}
