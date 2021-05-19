fn main() {

    // creating new string
    let mut s = String::new();
    println!("{}", s);

    let s: String = "initial contents".to_string();
    println!("{}", s);

    let s: String = String::from("🎸");
    println!("{}", s);

    // updating a string
    let mut s = String::from("foo");
    s.push_str("bar");
    println!("{}", s);

    // push_str uses reference to string literal
    let mut s1 = String::from("foo");
    let s2 = "bar";
    s1.push_str(s2);
    println!("s1 is {}", s1);
    println!("s1 contains s2? {}", s1.contains(s2));

    // push single char
    let mut s = String::from("lo");
    s.push('l');
    println!("{}", s);

    let s1 = String::from("Hello, ");
    let s2 = String::from("wor1d!");
    let s3 = s1 + &s2; // note 51 has been moved here and can no longer be used
    // println!("s1 is {}", s1);
    println!("s2 is {}", s2);
    println!("s3 is {}", s3);

    let s1 = String::from("tic");
    let s2 = String::from("tac");
    let s3 = String::from("toe");
    let s = s1 + "-" + &s2 + "-" + &s3;
    // println!("s1 is {}", s1);
    println!("s2 is {}", s2);
    println!("s3 is {}", s3);
    println!("s is {}", s);

    let s1 = String::from("tic");
    let s2 = String::from("tac");
    let s3 = String::from("toe");
    let s = format!("{}-{}-{}", s1, s2, s3);
    println!("s1 is {}", s1);
    println!("s2 is {}", s2);
    println!("s3 is {}", s3);
    println!("s is {}", s);

    // string indexing
    let s1 = String::from("hello");
    // let h = s1[0];
    let s = &s1[0..2];
    println!("{}", s);

    // iterating over strings
    for c in s1.chars() {
        println!("{}", c);
    }

    for byte in s1.bytes() {
        println!("{}", byte);
    }
}
