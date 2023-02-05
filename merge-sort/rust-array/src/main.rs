use rand::Rng;
use std::time::Instant;
use core::array;

const SIZE: usize = 30000;
const EXTRA: usize = if SIZE % 2 == 0 { 0 } else { 1 };

fn generate_array() -> [usize; SIZE]
{
    let mut rng = rand::thread_rng(); // Caching rand for loop speed
    let mut arr = core::array::from_fn(|_| 0);
    for i in 1..SIZE + 1 {
        let index = rng.gen_range(0..i);
        let mut j = SIZE - 1;
        while j > index {
            arr[j] = arr[j - 1];
            j -= 1;
        }
        arr[index] = i;
    }
    return arr;
}

fn compare_arrays(sorted: [usize; SIZE], expected: [usize; SIZE]) -> bool
{
    for i in 0..sorted.len() {
        if sorted[i] != expected[i] { return false; }
    }
    return true;
}

fn get_left_and_right(arr: &[usize; SIZE]) -> ([usize; SIZE / 2 + EXTRA], [usize; SIZE / 2])
{
    let left_size = SIZE / 2 + EXTRA;
    let left = arr[0..left_size].try_into().unwrap();
    let right = arr[left_size..].try_into().unwrap();
    return (left, right);
}

fn insertion_sort(arr: &mut [usize])
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

fn merge_sort(left: &[usize], right: &[usize]) -> [usize; SIZE]
{
    let mut merged = core::array::from_fn(|_| usize::max_value());
    let mut l = 0; // left index
    let mut r = 0; // right index
    for i in 0..SIZE {
        if l >= left.len() {
            for i in r..right.len() {
                merged[i + l] = right[i];
            }
            break;
        }
        if r >= right.len() {
            for i in l..left.len() {
                merged[r + i] = left[i];
            }
            break;
        }
        if left[l] < right[r] {
            merged[i] = left[l];
            l += 1;
        } else {
            merged[i] = right[r];
            r += 1;
        }
    }
    return merged;
}

fn main()
{
    // Generate array
    let gen_start = Instant::now();
    let arr = generate_array();
    let gen_elapsed = gen_start.elapsed().as_millis();

    let sort_start = Instant::now();

    // Get left and right. Tha halves of the array
    let (mut left, mut right) = get_left_and_right(&arr);

    // Sort left and right (insertion sort)
    insertion_sort(&mut left);
    insertion_sort(&mut right);

    // Merge left and right
    let merged = merge_sort(&left, &right);

    let sort_elapsed = sort_start.elapsed().as_millis();

    // Eval sorted array with an expected result
    let expected = array::from_fn(|i| i + 1);
    let are_equal = compare_arrays(merged, expected);

    // Output the results
    println!("1. Time to generate array: {} ms", gen_elapsed);
    if ! are_equal {
        println!("2. FAIL! The result array is NOT sorted as expected");
    } else {
        println!("2. SUCCESS! The result array is sorted as expected");
        println!("3. Time to sort the array: {} ms", sort_elapsed);
    }
}
