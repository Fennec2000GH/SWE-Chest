
use std::collections::HashMap;

fn main() {

    // creating new hashmap
    let mut scores = HashMap::new();
    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Yellow"), 50);
    println!("{:?}", scores);

    // initializing hasmap with zipped elements
    let teams = vec![String::from("Blue"), String::from("Yellow")];
    let initial_scores = vec![10, 50];
    let scores: HashMap<_, _> = teams.iter().zip(initial_scores.iter()).collect();
    println!("{:?}", scores);

    // ownership for hashmaps
    let field_name = String::from("Favorite color");
    let field_value = String::from("Blue");

    let mut map = HashMap::new();
    map.insert(field_name, field_value);
    println!("{:?}", map);

    // field_name and field_value are invalid at this point, try using them and
    // see what compiler error you get!
    // println!("{}, {}", field_name, field_value);

    // accessing values in hashmap
    let mut scores = HashMap::new();
    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Yellow"), 50);

    let team_name = String::from("Blue");
    let score = scores.get(&team_name);
    println!("team_name: {}, score: {:?}", team_name, score);

    // iterating over KV pairs
    for (key, value) in &scores {
        println!("{}: {}", key, value);
    }

    // updating hashmaps
    // overwriting existing value for same key
    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Blue"), 25);
    println!("{:?}", scores);

    // idk whether key exits or not
    scores.entry(String::from("Pink")).or_insert(25);
    scores.entry(String::from("Blue")).or_insert(50);
    println!("{:?}", scores);

    // update value based on old value
    let text = "hello world wonderful world";

    let mut map = HashMap::new();

    for word in text.split_whitespace() {
        let count = map.entry(word).or_insert(0);
        *count += 1;
    }

    println!("{:?}", map);

}
