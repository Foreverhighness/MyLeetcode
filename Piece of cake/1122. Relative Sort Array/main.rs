#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn relative_sort_array(mut arr1: Vec<i32>, arr2: Vec<i32>) -> Vec<i32> {
        use std::collections::HashMap;
        let map: HashMap<_, _> = arr2
            .into_iter()
            .enumerate()
            .map(|(i, v)| (v, i as i32))
            .collect();
        arr1.sort_unstable_by_key(|&v| *map.get(&v).unwrap_or(&(v + 1024)));
        arr1
    }
}

fn main() {}