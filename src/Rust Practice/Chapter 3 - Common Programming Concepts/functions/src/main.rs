
fn main() {
    println!("Hello, world!");

    // number of parameters
    another_function();
    single_param(5);
    multi_param(5, 6);

    // statements and expressions in function bodies
    let y = {
        let x  = 3;
        x + 1
    };

    println!("The value of y is: {}", y);

    // functions with return values
    let x  = five();
    println!("The value of x is: {}", x);

    let x = plus_one(5);
    println!("The value of x is: {}", x);

}

fn another_function() {
    println!("Another function.");
}

fn single_param(x: i32) {
    println!("The value of x is: {}", x);
}

fn multi_param(x: i32, y: i32) {
    println!("The value of x is: {}", x);
    println!("The value of y is: {}", y);
}

fn five() -> i32 {
    5
}

fn plus_one(x: i32) -> i32 {
    x + 1
}
