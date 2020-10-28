#![allow(dead_code)]
use std::collections::HashMap;
use std::collections::HashSet;
impl Solution {
    pub fn unique_occurrences(arr: Vec<i32>) -> bool {
        let mut counter = HashMap::new();
        arr.into_iter().for_each(|key| { *counter.entry(key).or_insert(0) += 1; });
        let set: HashSet<_> = counter.values().collect();
        set.len() == counter.len()
    }
}

fn main() {}
struct Solution;
