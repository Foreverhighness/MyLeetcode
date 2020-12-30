#![allow(dead_code)]
struct Solution;
use std::collections::BinaryHeap;
impl Solution {
    pub fn last_stone_weight(stones: Vec<i32>) -> i32 {
        let mut heap: BinaryHeap<i32> = stones.into_iter().collect();
        while heap.len() > 1 {
            let diff = heap.pop().unwrap() - heap.pop().unwrap();
            if diff > 0 {
                heap.push(diff);
            }
        }
        heap.pop().unwrap_or(0)
    }
}

fn main() {}
