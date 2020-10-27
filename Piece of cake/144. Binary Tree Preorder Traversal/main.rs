#![allow(dead_code)]
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
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
  pub fn preorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
    let mut res = Vec::new();
    let mut visit = |cur: &TreeNode| {res.push(cur.val);};
    let mut cur = root.clone();
    while let Some(curr) = cur.clone() {
      let curr = curr.borrow();
      let most_right = curr.left.clone();
      if let None = most_right {
        visit(&curr);
        cur = curr.right.clone();
      } else {
        let mut most_right = most_right.unwrap();
        while most_right.borrow().right.is_some() && most_right.borrow().right != cur {
          let tmp = most_right.borrow().right.clone().unwrap();
          most_right = tmp;
        }
        if most_right.borrow().right.is_none() {
          most_right.borrow_mut().right = cur.clone();
          cur = curr.left.clone();
        } else {
          visit(&curr);
          cur = curr.right.clone();
          most_right.borrow_mut().right = None;
        }
      }
    }
    res
  }
}

fn main() {

}
struct Solution;