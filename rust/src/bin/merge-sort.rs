//# Steps

// 1. devide arg arr into left and rigth halves until you got to 1 elem
// 2. merge sorting the the left and right in a alloc arr
// 3. write the alloc arr (merged_left_right) into the main arr
// 4. do it will tail recursion so the stack doesnt go to shit

use std::time::{Instant, Duration};

use rand::Rng;

fn main()
{
    const SIZE: usize = 40000;
    let mut arr = gen_rand_vals_arr(SIZE);

    let time = bench_merge_sort(&mut arr);

    if ! is_sorted(arr) {
        println!("The result array is NOT sorted as expected");
    } else {
        println!("Time merge sort the array: {:?}", time);
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

fn bench_merge_sort(arr: &mut Vec<u32>) -> Duration
{
    let start = Instant::now();
    merge_sort(arr, 0, arr.len() - 1);
    start.elapsed()
}

fn is_sorted(arr: Vec<u32>) -> bool
{
    for i in 0..arr.len() -1 {
        if arr[i] > arr[i + 1] { return false; }
    }
    true
}

fn merge_sort(arr: &mut Vec<u32>, begin: usize, end: usize)
{
    // Escape clause for arr len of 1
    if begin == end { return; }

    let left_end = ((end - begin) / 2 ) + begin;

    // Recursive call left chunk
    merge_sort(arr, begin, left_end);

    // Recursive call right chunk
    merge_sort(arr, left_end + 1, end);

    // merge the two halves into an sorted chunk of the final array
    merge(arr, begin, left_end, end);
}

fn merge(arr: &mut Vec<u32>, left_begin: usize, left_end: usize, right_end: usize)
{
    let combined_size = right_end - left_begin + 1;
    let mut merged = Vec::with_capacity(combined_size);

    let mut left_index = left_begin;
    let mut right_index = left_end + 1;

    // merge both side in a sorting way until one of them reaches last index
    while left_index <= left_end && right_index <= right_end {
        if arr[left_index] < arr[right_index] {
            merged.push(arr[left_index]);
            left_index += 1;
        } else {
            merged.push(arr[right_index]);
            right_index += 1;
        }
    }

    // append remainders of left if any
    while left_index <= left_end {
        merged.push(arr[left_index]);
        left_index += 1;
    }

    // append remainders of right if any
    while right_index <= right_end {
        merged.push(arr[right_index]);
        right_index += 1;
    }

    // Write the allocated array into the final array
    for i in 0..combined_size {
        arr[left_begin + i] = merged[i];
    }
}
