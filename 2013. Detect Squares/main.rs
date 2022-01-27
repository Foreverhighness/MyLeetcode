use std::collections::{HashMap, HashSet};
struct DetectSquares {
    ys: HashMap<i32, HashSet<i32>>,
    points: HashMap<(i32, i32), i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl DetectSquares {
    fn new() -> Self {
        DetectSquares {
            ys: HashMap::new(),
            points: HashMap::new(),
        }
    }

    fn add(&mut self, point: Vec<i32>) {
        let (x, y) = (point[0], point[1]);
        self.ys.entry(x).or_default().insert(y);
        *self.points.entry((x, y)).or_default() += 1;
    }

    fn count(&self, point: Vec<i32>) -> i32 {
        let mut ret = 0;
        let (x, y) = (point[0], point[1]);
        if !self.ys.contains_key(&x) {
            return 0;
        }

        let ys = self.ys.get(&x).unwrap();

        for &ny in ys.iter() {
            if ny == y {
                continue;
            }
            let mut d = ny - y;
            for _ in 0..2 {
                let (x1, y1) = (x + d, y);
                let (x2, y2) = (x + d, ny);

                let a = self.points.get(&(x1, y1)).unwrap_or(&0);
                let b = self.points.get(&(x2, y2)).unwrap_or(&0);
                let c = self.points.get(&(x, ny)).unwrap_or(&0);

                ret += a * b * c;
                d = -d
            }
        }
        ret
    }
}

/**
 * Your DetectSquares object will be instantiated and called as such:
 * let obj = DetectSquares::new();
 * obj.add(point);
 * let ret_2: i32 = obj.count(point);
 */
fn main() {
    let mut detect_squares = DetectSquares::new();
    detect_squares.add(vec![3, 10]);
    detect_squares.add(vec![11, 2]);
    detect_squares.add(vec![3, 2]);
    dbg!(detect_squares.count(vec![11, 10]) == 1);
    dbg!(detect_squares.count(vec![14, 8]) == 0);
    detect_squares.add(vec![11, 2]);
    dbg!(detect_squares.count(vec![11, 10]) == 2);
}
