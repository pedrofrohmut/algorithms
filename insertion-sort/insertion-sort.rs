use rand::Rng;
use std::time::Instant;

const SIZE: usize = 30_000;

fn generate_array() -> [usize; SIZE]
{
    let mut rng = rand::thread_rng(); // Caching rng for loop
    let mut arr: [usize; SIZE] = core::array::from_fn(|_| 0);
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

fn insertion_sort(arr: &mut [usize; SIZE])
{
    for i in 1..SIZE {
        let key = arr[i];
        let mut j = i - 1;
        while j > 0 && arr[j] > key {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        // You need assistant part because rust wont let 'j: usize' goes negative
        // in C you just get an extra loop and j == -1
        let mut assistant: i32 = j as i32;
        if j == 0 && arr[j] > key {
            arr[j + 1] = arr[j];
            assistant -= 1;
        }
        arr[(assistant + 1) as usize] = key;
    }
}

fn compare_arrays(arr: &[usize], expected: &[usize]) -> bool
{
    for i in 0..arr.len() {
        if arr[i] != expected[i] { return false; }
    }
    return true;
}

fn main()
{
    // Generate array
    let gen_start = Instant::now();
    let mut arr = generate_array();
    let gen_elapsed = gen_start.elapsed().as_millis();

    // Sort array
    let sort_start = Instant::now();
    insertion_sort(&mut arr);
    let sort_elapsed = sort_start.elapsed().as_millis();

    // Eval sorted array with an expected result
    let expected: [usize; SIZE] = core::array::from_fn(|i| i + 1);
    let are_equal = compare_arrays(&arr, &expected);

    // Output results
    println!("1. Time to generate array: {} ms", gen_elapsed);
    if ! are_equal {
        println!("FAIL!\n2. The result array is NOT sorted as expected");
    } else {
        println!("SUCCESS!\n2. The result array is sorted as expected");
        println!("3. Time to sort the array: {} ms", sort_elapsed);
    }
}
