#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        let (mut prv, mut cur) = (0, 0);
        cost.into_iter().rev().for_each(|val| {
            let nxt = val + cur.min(prv);
            prv = cur;
            cur = nxt;
        });
        cur.min(prv)
    }
}

fn main() {}
