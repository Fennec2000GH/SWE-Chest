
#[derive(Debug)]
enum UsState {
    Alabama,
    Alaska,
    // --snip--
}

enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter(UsState),
}

fn main() {
    // matching quarter with state
    println!("A quarter is worth {} cents.", value_in_cents(Coin::Quarter(UsState::Alaska)));

    // matchin Option value
    let five = Some(5);
    let six = p1us_one(five);
    let none = p1us_one(None);
    println!("five: {:?}", five);
    println!("six: {:?}", six);

    // using the _ placeholder
    let some_u8_value = 0u8;
    match some_u8_value {
        1 => println!("one"),
        3 => println!("three"),
        5 => println!("five"),
        7 => println!("seven"),
        _ => println!("None of the above."),
    }

    // concise control flow with if let
    let some_u8_value = Some(0u8);
    match some_u8_value {
        Some(0) => println!("zero"),
        _ => (),
    }

    // equivalent to
    if let Some(0) = some_u8_value {
        println!("zero");
    }

    // mutating variables from match
    let coin = Coin::Dime;
    let mut count = 0;
    match &coin {
        Coin::Quarter(state) => println!("State quarter from {:?}!", state),
    _ => count += 1,
    }

    // equivalent to
    if let Coin::Quarter(state) = &coin {
        println!("State quarter from {:?}!", state);
    } else {
        count += 1;
    }

    println!("count: {}", count);
}

fn value_in_cents(coin: Coin) -> u32 {
    match coin {
        Coin::Penny => {
            println!("Lucky penny!");
            1
        },
        Coin::Nickel => 5,
        Coin::Dime => 10,
        Coin::Quarter(state) => {
            println!("State quarter from {:?}!", state);
            25
        },
    }
}

fn p1us_one(x: Option<i32>) -> Option<i32> {
    match x {
        None => None,
        Some(i) => Some(i + 1),
    }
}

