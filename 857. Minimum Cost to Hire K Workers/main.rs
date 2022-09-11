#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn mincost_to_hire_workers(quality: Vec<i32>, wage: Vec<i32>, k: i32) -> f64 {
        use std::collections::BinaryHeap;
        let (k, len) = (k as usize, wage.len());
        let mut idx = (0..len).collect::<Vec<_>>();
        idx.sort_unstable_by(|&i, &j| (wage[i] * quality[j]).cmp(&(wage[j] * quality[i])));
        let mut res = f64::MAX;
        let mut q_sum = 0;
        let mut heap = BinaryHeap::with_capacity(k - 1);
        for i in 0..(k - 1) {
            heap.push(quality[idx[i]]);
            q_sum += quality[idx[i]];
        }
        for i in (k - 1)..len {
            heap.push(quality[idx[i]]);
            q_sum += quality[idx[i]];
            res = res.min(q_sum as f64 * wage[idx[i]] as f64 / quality[idx[i]] as f64);
            q_sum -= heap.pop().unwrap();
        }
        res
    }
}

fn main() {
    dbg!(
        Solution::mincost_to_hire_workers(vec![10, 20, 5], vec![70, 50, 30], 2),
        105_f64
    );
    dbg!(
        Solution::mincost_to_hire_workers(vec![3, 1, 10, 10, 1], vec![4, 8, 2, 2, 7], 3),
        30.66667_f64
    );
    dbg!(
        Solution::mincost_to_hire_workers(vec![2], vec![14], 1),
        14_f64
    );
}
