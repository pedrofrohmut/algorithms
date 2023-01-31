use rand::Rng;
use std::time::Instant;

fn generate_array(size: usize) -> Vec<usize>
{
    let mut rng = rand::thread_rng();
    let mut arr = Vec::new();
    for i in 1..size + 1  {
        let index = rng.gen_range(0..i);
        arr.insert(index, i);
    }
    return arr;
}

fn insertion_sort(arr: Vec<usize>) -> Vec<usize>
{
    let mut res = Vec::new();
    res.push(arr[0]);
    for i in 1..arr.len() {
        let mut j = 0;
        while j < i && res[j] < arr[i] { j += 1; }
        res.insert(j, arr[i]);
    }
    return res;
}

fn compare_arrays(subject: Vec<usize>, expected: Vec<usize>) -> bool
{
    for i in 0..subject.len() {
        if subject[i] != expected[i] { return false; }
    }
    return true;
}

fn main() {
    let size = 30000;

    // Generate array
    let gen_start = Instant::now();
    let arr = generate_array(size);
    let gen_elapsed = gen_start.elapsed().as_millis();

    // Sort array
    let sort_start = Instant::now();
    let sorted = insertion_sort(arr);
    let sort_elapsed = sort_start.elapsed().as_millis();

    // Eval sorted array with an expected result
    let expected = (1..=size).collect::<Vec<usize>>();
    let are_equal = compare_arrays(sorted, expected);

    // Output results
    println!("1. Time to generate vector: {} ms", gen_elapsed);
    if ! are_equal {
        println!("FAIL!\n2. The result vector is NOT sorted as expected");
    } else {
        println!("SUCCESS!\n2. The result vector is sorted as expected");
        println!("3. Time to sort the vector: {} ms", sort_elapsed);
    }
}
