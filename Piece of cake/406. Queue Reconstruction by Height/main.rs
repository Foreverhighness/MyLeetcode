#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn reconstruct_queue(mut people: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut res = Vec::with_capacity(people.len());
        people.sort_unstable_by_key(|v| (-v[0], v[1]));
        for vec in people {
            res.insert(vec[1] as usize, vec);
        }
        res
    }
}

fn main() {
    assert_eq!(
        Solution::reconstruct_queue(vec![
            vec![7, 0],
            vec![4, 4],
            vec![7, 1],
            vec![5, 0],
            vec![6, 1],
            vec![5, 2]
        ]),
        vec![
            vec![5, 0],
            vec![7, 0],
            vec![5, 2],
            vec![6, 1],
            vec![4, 4],
            vec![7, 1]
        ]
    );
}
