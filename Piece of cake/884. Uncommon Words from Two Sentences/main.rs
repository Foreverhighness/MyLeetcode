#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn uncommon_from_sentences(s1: String, s2: String) -> Vec<String> {
        // ref: https://stackoverflow.com/questions/36971516/how-can-i-convert-a-collection-of-values-into-a-hashmap-that-counts-them
        use std::collections::HashMap;
        s1.split_ascii_whitespace()
            .chain(s2.split_ascii_whitespace())
            .fold(HashMap::new(), |mut counter, word| {
                *counter.entry(word.to_owned()).or_insert(0) += 1;
                counter
            })
            .into_iter()
            .filter(|(_, v)| *v == 1)
            .map(|(k, _)| k)
            .collect()
    }
}

fn main() {
    dbg!(
        Solution::uncommon_from_sentences(
            "this apple is sweet".to_owned(),
            "this apple is sour".to_owned()
        ) == ["sweet", "sour"]
    );
    dbg!(
        Solution::uncommon_from_sentences("apple apple".to_owned(), "banana".to_owned())
            == ["banana"]
    );
}
