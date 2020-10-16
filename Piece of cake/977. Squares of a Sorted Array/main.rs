#![allow(dead_code)]
impl Solution {impl Solution {
    fn lower_bound(a: &Vec<i32>) -> usize {
        let (mut l, mut r) = (0, a.len());
        while l < r {
            let m = (l + r) / 2;
            if a[m] < 0 {
                l = m + 1;
            } else {
                r = m; 
            }
        }
        l
    }
    pub fn sorted_squares(a: Vec<i32>) -> Vec<i32> {
        let n = a.len();
        let mut res = Vec::with_capacity(n);
        
        let pos = Self::lower_bound(&a);
        let (mut l, mut r) = (pos - 1, pos);
        while l < n || r < n {
            if r >= n || (l < n && a[l].abs() < a[r].abs()) {
                res.push(a[l] * a[l]);
                l -= 1;
            } else {
                res.push(a[r] * a[r]);
                r += 1;
            }
        }
        res
    }
}

    pub fn sorted_squares0(a: Vec<i32>) -> Vec<i32> {
        let n = a.len();
        let mut res = vec![0; n];
        let (mut i, mut j, mut pos) = (0, n - 1, n - 1);
        while i <= j {
            if a[i].abs() < a[j].abs() {
                res[pos] = a[j] * a[j];
                j -= 1;
            } else {
                res[pos] = a[i] * a[i];
                i += 1;
            }
            pos -= 1;
        }
        res
    }
}

fn main() {
    
}
struct Solution;