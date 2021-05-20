
use std::fs::File;
use std::io::{Error, ErrorKind, Read};

// enum Result<T, E> {
//     Ok(T),
//     Err(E),
// }

fn main() {

    // basic panic example
    // let f: u32 = File::open("hello.txt");
    // let f = File::open("hello.txt");
    // println!("{:?}", &f);

    // let f_result = match f {
    //     Ok(file) => file,
    //     Err(error) => {
    //         panic!("There was a problem opening the file: {:?}", error);
    //     },
    // };
    // println!("{:?}", f_result);

    // complex panic depending on error type
    let f = File::open("hello.txt");
    println!("{:?}", &f);

    let f_result = match f {
        Ok(file) => file,
        Err(ref error) if error.kind() == ErrorKind::NotFound => {
            match File::create("hello.txt") {
                Ok(fc) => fc,
                Err(error) => {
                    panic!("Tried to create file but there was a problem: {:?}", error)
                },
            }
        },
        Err(error) => {
            panic!("There was a problem opening the file: {:?}", error)
        },
    };

    let dotted_line = (0..100).map(|_| ".".to_string()).collect::<Vec<String>>().join("");
    println!("{}", dotted_line);
    println!("{:?}", f_result);

    // shortcuts for panic
    let f = File::open("hello.txt").unwrap();
    println!("{:?}", f);

    let f = File::open("hello.txt").expect("Failed to open hello.txt");
    println!("{:?}", f);

    println!("username: {}", read_username_from_file().unwrap());

    // shortcut to propagate errors
    println!("username: {}", read_username_from_file_shortened().unwrap());
}

fn read_username_from_file() -> Result<String, Error> {
    let f = File::open("hello.txt");
    let mut f = match f {
        Ok(file) => file,
        Err(e) => return Err(e),
    };

    let mut s = String::new();
    match f.read_to_string(&mut s) {
        Ok(_) => Ok(s),
        Err(e) => Err(e),
    }
}

fn read_username_from_file_shortened() -> Result<String, Error> {
    let mut f = File::open("hello.txt")?;
    let mut s = String::new();
    f.read_to_string(&mut s)?;
    Ok(s)
}