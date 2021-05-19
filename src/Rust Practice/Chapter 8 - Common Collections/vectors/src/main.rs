

#[derive(Debug)]
enum SpreadSheetCell {
    Int(i32),
    Float(f64),
    Text(String),
}

fn main() {

    // vector initialization and creation
    let v: Vec<i32> = Vec::new();
    println!("{:?}", v);

    let v = vec![1, 2, 3];
    println!("{:?}", v);

    let mut v: Vec<i32> = Vec::new();
    v.push(5);
    v.push(6);
    v.push(7);
    v.push(8);
    println!("{:?}", v);

    // dropping a vector for going out of scope
    {
        let v = vec![1, 2, 3, 4];
        println!("Size of v: {}", v.len());
    } // <- v goes out of scope and is freed here

    // reading from vector
    let v = vec![1, 2, 3, 4, 5];
    let third: &i32 = &v[2];
    println!("{}", third);

    let third: Option<&i32> = v.get(2);
    println!("{:?}", third);

    let v = vec![1, 2, 3, 4, 5];
    // let does_not_exist = &v[100];
    // println!("{}", does_not_exist);

    let does_not_exist = v.get(100);
    println!("{:?}", does_not_exist);

    let mut v = vec![1, 2, 3, 4, 5];
    let first = &v[0];
    v.push(6);
    println!("{:?}", v);

    let row = vec![
        SpreadSheetCell::Int(3),
        SpreadSheetCell::Text(String::from("blue")),
        SpreadSheetCell::Float(10.12),
    ];
    println!("{:?}", row);
}
