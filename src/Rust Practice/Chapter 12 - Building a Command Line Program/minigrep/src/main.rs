
use std::env;
use std::fs::File;
use std::io::prelude::*;

fn main() {

    let args: Vec<String> = env::args().collect();
    println!("{:?}", args);

    // let query = &args[1];
    // let filename = &args[2];

    // let (query, filename) = parse_config(&args);

    let config = parse_config(&args);
    let query = config.query;
    let filename = config.filename;

    println!("Searching for  {}", query);
    println!("In file {}", filename);

    let mut f = File::open(filename).expect("File not found");
    let mut contents = String::new();
    f.read_to_string(&mut contents).expect("something went wrong reading the file");
    println!("With text:\n{}", contents);
}

fn parse_config(args: &[String]) -> (&str, &str) {
    let query = &args[1];
    let filename = &args[2];

    (query, filename)
}
