
fn main() {
    // String data type
    let s  = "hello";  // string literal, stored in stack
    let s = String::from("hello");  // immutable string, soted in heap
    let mut s = String::from("hello");  // mutable version of s above

    s.push_str(", world!");
    println!("{}", s);

    // move
    let x = 5;
    let y  = x;

    println!("x = {}, y = {}", x, y);

    let s1 = String::from("hello");
    let s2 = s1;

    println!("s1 = {}, s2 = {}", s1, s2);
}
