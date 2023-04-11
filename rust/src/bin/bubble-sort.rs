#![allow(dead_code)]

use std::time::{Instant, Duration};

use rand::Rng;

fn main()
{
    let size = 40000;
    let mut arr = gen_rand_vals_arr(size);

    let time = bench_bubble_sort(&mut arr);

    if ! is_sorted(&arr) {
        println!("The result array is NOT sorted as expected");
    } else {
        println!("Time to bubble sort the array: {:?}", time);
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

fn bubble_sort2(arr: &mut Vec<u32>)
{
    for i in 0..arr.len() - 1 {
        for j in 1..arr.len() - i {
            if arr[j - 1] > arr[j] {
                let temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

fn bubble_sort(arr: &mut Vec<u32>)
{
    for i in 0..arr.len() {
        let mut swap_count = 0;
        for j in (i + 1..arr.len()).rev() {
            if arr[j] < arr[j - 1] {
                let tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
                swap_count += 1;
            }
        }
        if swap_count == 0 { return; }
    }
}

fn bench_bubble_sort(arr: &mut Vec<u32>) -> Duration
{
    let start = Instant::now();
    bubble_sort2(arr);
    start.elapsed()
}

fn is_sorted(arr: &Vec<u32>) -> bool
{
    for i in 0..arr.len() - 1 {
        if arr[i] > arr[i + 1] { return false; }
    }
    true
}
