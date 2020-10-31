#![allow(dead_code)]
use rand::prelude::*;
use std::collections::{HashMap, HashSet};
#[derive(Default)]
struct RandomizedCollection {
  dict: HashMap<i32, HashSet<usize>>,
  data: Vec<i32>,
  rng: ThreadRng,
}
/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RandomizedCollection {
  /** Initialize your data structure here. */
  fn new() -> Self {
    Default::default()
  }

  /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
  fn insert(&mut self, val: i32) -> bool {
    let elem = self.dict.entry(val).or_default();
    elem.insert(self.data.len());
    self.data.push(val);
    elem.len() == 1
  }

  /** Removes a value from the collection. Returns true if the collection contained the specified element. */
  fn remove(&mut self, val: i32) -> bool {
    if let Some(rset) = self.dict.get_mut(&val) {
      if let Some(idx) = rset.iter().nth(0).cloned().map(|val| rset.take(&val).unwrap()) {
        if idx + 1 == self.data.len() {
          self.data.pop();
        } else {
          self.data[idx] = self.data.pop().unwrap();
          let aset = self.dict.get_mut(&self.data[idx]).unwrap();
          aset.remove(&self.data.len());
          aset.insert(idx);
        }
        return true;
      }
    }
    false
  }

  /** Get a random element from the collection. */
  fn get_random(&mut self) -> i32 {
    *self.data.choose(&mut self.rng).unwrap()
  }
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * let obj = RandomizedCollection::new();
 * let ret_1: bool = obj.insert(val);
 * let ret_2: bool = obj.remove(val);
 * let ret_3: i32 = obj.get_random();
 */

fn main() {}
