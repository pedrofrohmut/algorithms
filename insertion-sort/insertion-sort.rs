fn print_arrays(arr: [i32; 21], res: [i32; 21])
{
    for (i, x) in arr.iter().enumerate() {
        println!("Arr[{0}] = {1}", i, x);
    }
    println!("\n");
    for (i, x) in res.iter().enumerate() {
        println!("Res[{0}] = {1}", i, x);
    }
}

fn main()
{
    let arr: [i32; 21] = [5, 19, 20, 2, 15, 17, 4, 6, 14, 7, 21, 1, 16, 9, 12, 13, 3, 18, 10, 8, 11];
    let mut res: [i32; 21] = Default::default();

    if arr[0] < arr[1] {
        res[0] = arr[0];
        res[1] = arr[1];
    } else {
        res[0] = arr[1];
        res[1] = arr[0];
    }

    for i in 2..arr.len() {
        let mut j = 0;
        while j < res.len() && res[j] < arr[i] { j += 1; }
        if j == res.len() {
            res[i] = arr[i];
        } else {
            let mut k = res.len() - 1;
            while k > j {
                res[k] = res[k - 1];
                k -= 1;
            }
            res[j] = arr[i];
        }
    }

    // print_arrays(arr, res);
}
