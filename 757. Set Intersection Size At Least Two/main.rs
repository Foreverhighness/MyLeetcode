#![allow(dead_code)]
struct Solution;
impl Solution {
    pub fn intersection_size_two(mut intervals: Vec<Vec<i32>>) -> i32 {
        intervals.sort_unstable_by_key(|k| (k[1], -k[0]));
        intervals
            .into_iter()
            .map(|v| (v[0], v[1]))
            .fold((-1, -1, 0), |(mut a, mut b, mut res), (l, r)| {
                if b < l {
                    res += 2;
                    a = r - 1;
                    b = r;
                } else if a < l {
                    res += 1;
                    a = b;
                    b = r;
                }
                (a, b, res)
            })
            .2
    }
}

fn main() {
    let v = vec![vec![1, 3], vec![1, 4], vec![2, 5], vec![3, 5]];
    dbg!(Solution::intersection_size_two(v) == 3);
    let v = vec![vec![1, 2], vec![2, 3], vec![3, 4], vec![4, 5]];
    dbg!(Solution::intersection_size_two(v) == 5);
    let v = vec![
        vec![2, 10],
        vec![3, 7],
        vec![3, 15],
        vec![4, 11],
        vec![6, 12],
        vec![6, 16],
        vec![7, 8],
        vec![7, 11],
        vec![7, 15],
        vec![11, 12],
    ];
    dbg!(Solution::intersection_size_two(v) == 5);
}
