use std::time::{Instant, Duration};
use rand::prelude::*;

fn main()
{
    let size = 40000;
    let mut arr = gen_rand_vals_arr(size);

    let time = bench_insertion_sort(&mut arr);

    if ! is_sorted(&arr) {
        println!("The result array is NOT sorted as expected");
    } else {
        println!("Time to insertion sort the array: {:?}", time);
    }
}

fn gen_rand_vals_arr(size: usize) -> Vec<u32>
{
    let mut rng = rand::thread_rng();
    let mut arr = Vec::with_capacity(size);
    for _ in 0..size {
        let rand_num = rng.gen_range(0..std::u32::MAX);
        arr.push(rand_num);
    }
    arr
}

fn insertion_sort(arr: &mut Vec<u32>)
{
    for i in 1..arr.len() {
        let key = arr[i];
        let mut j = i;
        while j > 0 && arr[j - 1] > key {
            arr[j] = arr[j - 1];
            j -= 1;
        }
        arr[j] = key;
    }
}

fn bench_insertion_sort(arr: &mut Vec<u32>) -> Duration
{
    let start = Instant::now();
    insertion_sort(arr);
    start.elapsed()
}

fn is_sorted(arr: &Vec<u32>) -> bool
{
    for i in 0..(arr.len() - 1) {
        if arr[i] > arr[i + 1] { return false; }
    }
    true
}
