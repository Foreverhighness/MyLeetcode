#![allow(dead_code)]
struct Solution;
use std::collections::HashMap;
impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut map = HashMap::new();
        strs.into_iter().for_each(|s| {
            let mut cnt = [0u8; 26];
            s.bytes().for_each(|b| cnt[(b - b'a') as usize] += 1);
            map.entry(cnt).or_insert(vec![]).push(s);
        });
        map.values().cloned().collect()
    }
}

fn main() {}
