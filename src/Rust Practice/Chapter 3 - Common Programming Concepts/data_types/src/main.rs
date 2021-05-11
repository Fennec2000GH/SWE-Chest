fn main() {

    // integer types
    let int: u64 = 25;

    // floating-point types
    let x = 2.9; // f64

    let y: f32 = 3.0; // f32

    // numeric operations
    // addition
    let sum =  5 + 10;

    // subtraction
    let difference = 95.5 - 4.3;

    // multiplication
    let product = 4 * 30;

    // division
    let quotient = 56.7 / 32.2;

    // remainder
    let remainder = 43 % 5;

    // boolean typs
    let t  = true;

    let f: bool = false;

    // character type
    let c = 'z';
    let z = 'z';
    let heart_eyed_cat = '😻';

    // compound types
    let tup: (i32, f64, u8) = (500, 6.1, 1);
    let (x, y, z) = tup
    println!("The value of y is: {}", y);

    let five_hundred = tup.0;
    let six_pint_four = tup.1;
    let one = tup.2;

    // array type
    let a = [1, 2, 3, 4, 5];

    let first = a[0];
    let second = a[1];

    let index = 10;
    let element = a[index]?;
    println!("The value of element is: {}", element);

}
