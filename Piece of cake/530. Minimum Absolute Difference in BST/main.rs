#![allow(dead_code)]
use std::rc::Rc;
use std::cell::RefCell;
use std::cmp::min;
impl Solution {
    pub fn get_minimum_difference(root: Option<Rc<RefCell<TreeNode>>>) -> i32 { 
        let mut res = i32::MAX;
        let mut prv_val = -100000;
        let mut curr = root.clone();
        while let Some(cur) = curr.clone() {
            let cur = cur.borrow();
            if let None = cur.left {
                res = min(res, cur.val - prv_val);
                prv_val = cur.val;
                curr = cur.right.clone();
            } else {
                let mut most_right = cur.left.clone().unwrap();
                while most_right.borrow().right.is_some() && most_right.borrow().right != curr {
                    let tmp = most_right.borrow().right.clone().unwrap();
                    most_right = tmp;
                }
                if most_right.borrow().right.is_some() {
                    res = min(res, cur.val - prv_val);
                    prv_val = cur.val;
                    most_right.borrow_mut().right = None;
                    curr = cur.right.clone();
                } else {
                    most_right.borrow_mut().right = curr;
                    curr = cur.left.clone();
                }
            }
        }
        res
    }
}

fn to_string(root : &Option<Rc<RefCell<TreeNode>>>) -> String {
    if let None = *root {
        "[]".to_string()
    } else {
        let mut ret = String::new();
        let mut que = Vec::new();
        que.push(root.clone());
        while !que.is_empty() {
            if let Some(cur) = que.remove(0) {
                que.push(cur.borrow().left.clone());
                que.push(cur.borrow().right.clone());
                ret.push_str(&format!("{}, ", cur.borrow().val.to_string()));
            } else {
                ret.push_str("null, ");
            }
        }
        format!("[{}]", ret.trim_end_matches("null, ").trim_end_matches(", "))
    }
}
fn main() {
    let mut one = TreeNode::new(1);
    let two = TreeNode::new(2);
    let mut three = TreeNode::new(3);
    three.left = Some(Rc::new(RefCell::new(two)));
    one.right = Some(Rc::new(RefCell::new(three)));
    let input = Some(Rc::new(RefCell::new(one)));
    println!("{}", to_string(&input));
    println!("{}", Solution::get_minimum_difference(input));
}
// #[cfg(test)]
// mod tests {
//     #[test]
//     fn main() {
//         let mut one = TreeNode::new(1);
//         let mut two = TreeNode::new(2);
//         let mut three = TreeNode::new(3);
//         two.left = Some(Rc::new(RefCell::new(three)));
//         one.right = Some(Rc::new(RefCell::new(two)));
//         let input = Some(Rc::new(RefCell::new(one)));
//         println!("{}", to_string(&input));
//         println!("{}", Solution::get_minimum_difference(input));
//     }
// }
struct Solution;

// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None
        }
    }
}
