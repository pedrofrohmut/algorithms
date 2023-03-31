use std::time::{Instant, Duration};
use rand::prelude::*;

fn main()
{
    let size = 40000;
    let mut arr = gen_rand_vals_arr(size);

    let time = bench_selection_sort(&mut arr);

    if ! is_sorted(&arr) {
        println!("The result array is NOT sorted as expected");
    } else {
        println!("Time to selection sort the array: {:?}", time);
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

fn selection_sort(arr: &mut Vec<u32>)
{
    for i in 0..arr.len() - 1 {
        let mut min_pos = i;
        for j in i + 1..arr.len() {
            if arr[j] < arr[min_pos] {
                min_pos = j;
            }
        }
        if min_pos != i {
            // Swap
            let tmp = arr[i];
            arr[i] = arr[min_pos];
            arr[min_pos] = tmp;
        }
    }
}

fn bench_selection_sort(arr: &mut Vec<u32>) -> Duration
{
    let start = Instant::now();
    selection_sort(arr);
    start.elapsed()
}

fn is_sorted(arr: &Vec<u32>) -> bool
{
    for i in 0..(arr.len() - 1) {
        if arr[i] > arr[i + 1] { return false; }
    }
    true
}
