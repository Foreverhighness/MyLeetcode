#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn candy(ratings: Vec<i32>) -> i32 {
        let mut pq: Vec<(usize, i32)> = ratings.iter().copied().enumerate().collect();
        pq.sort_unstable_by_key(|(_, v)| *v);
        let mut res = vec![0; ratings.len()];
        for (i, v) in pq {
            let l = i.saturating_sub(1);
            let r = if i + 1 == ratings.len() { i } else { i + 1 };
            let mut val = 1;
            if ratings[l] < v {
                val = val.max(res[l] + 1);
            }
            if ratings[r] < v {
                val = val.max(res[r] + 1);
            }
            res[i] = val;
        }
        println!("{:?}", res);
        res.into_iter().sum()
    }
}

fn main() {
    dbg!(Solution::candy(vec![1, 0, 2]));
    dbg!(Solution::candy(vec![1, 2, 2]));
}
