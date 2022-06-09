#![allow(dead_code)]
use rand::prelude::*;
struct Solution {
    rects: Vec<Vec<i32>>,
    acc: Vec<i32>,
    rng: ThreadRng,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {
    fn new(rects: Vec<Vec<i32>>) -> Self {
        let mut acc = vec![0];
        for rect in rects.iter() {
            let area = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            acc.push(acc[acc.len() - 1] + area);
        }
        Self {
            rects,
            acc,
            rng: thread_rng(),
        }
    }

    fn pick(&self) -> Vec<i32> {
        let mut rnd = self.rng.gen_range(0..self.acc[self.acc.len() - 1]);
        let idx = self.acc.binary_search(&rnd).unwrap();
        rnd -= self.acc[idx - 1];
        let (a, b, c) = (self.rects[idx][0], self.rects[idx][1], self.rects[idx][3]);
        let x = rnd % (c - b + 1) + a;
        let y = rnd / (c - b + 1) + b;
        vec![x, y]
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution::new(rects);
 * let ret_1: Vec<i32> = obj.pick();
 */

fn main() {
    let sol = Solution::new(vec![vec![-2, -2, 1, 1], vec![2, 2, 4, 6]]);
    dbg!(sol.pick());
    dbg!(sol.pick());
    dbg!(sol.pick());
    dbg!(sol.pick());
    dbg!(sol.pick());
}
