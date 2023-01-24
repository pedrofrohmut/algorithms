#![allow(unused)]

fn print_array(arr: &[i32])
{
    for (i, x) in arr.iter().enumerate() {
        println!("[{0}]: {1}", i, x);
    }
}

fn get_left_and_right(arr: Vec<i32>) -> (Vec<i32>, Vec<i32>)
{
    let extra = if arr.len() % 2 == 0 { 0 } else { 1 };
    let size = arr.len() / 2;
    let left = &arr[0..size + extra];
    let right = &arr[size + extra..];
    return (left.to_vec(), right.to_vec());
}

fn order_array(arr: Vec<i32>) -> Vec<i32>
{
    let mut res = Vec::<i32>::new();
    if arr.len() < 2 { return arr };
    res.push(arr[0]);
    for i in 1..arr.len() {
        let mut j = 0;
        while j < i && res[j] < arr[i] { j += 1 };
        res.insert(j, arr[i]);
    }
    return res;
}

fn merge_sort(left: Vec<i32>, right: Vec<i32>) -> Vec<i32>
{
    let mut res = Vec::<i32>::new();
    let res_len = left.len() + right.len();
    let mut l = 0;
    let mut r = 0;
    for i in 0..res_len {
        if r >= right.len() || l >= left.len() { break; }
        if left[l] < right[r] {
            res.push(left[l]);
            l += 1;
        } else {
            res.push(right[r]);
            r += 1;
        }
    }
    // Add final remaining elements if there are any
    if l < left.len() {
        for i in l..left.len() { res[l + i] = left[i]; }
    }
    if r < right.len() {
        for i in r..right.len() { res[r + i] = right[i]; }
    }
    return res;
}

fn main()
{
    let arr = vec![5, 30, 34, 19, 20, 31, 33, 2, 15, 32, 25, 17, 38, 4, 6, 23, 29, 40, 14, 7, 36, 21, 1, 16, 39, 26, 35, 9, 12, 13, 24, 3, 37, 18, 27, 10, 8, 28, 11, 22];

    // Get Left And Right
    let (mut left, mut right) = get_left_and_right(arr);

    // Order Left And Right
    left = order_array(left);
    right = order_array(right);

    let res = merge_sort(left, right);

    // print_array(&res);
}
