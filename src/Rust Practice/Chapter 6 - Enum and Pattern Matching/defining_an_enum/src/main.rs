
use std::vec::Vec;

enum IpAddrKind {
    V4,
    V6,
}

enum IpAddrCompact {
    V4(String),
    V6(String),
}

impl IpAddrCompact {
    fn v4(&self) -> String {
        if let IpAddrCompact::V4(address) = self { address.to_string() } else { panic!("Invalid V4"); }
    }

    fn v6(&self) -> String {
        if let IpAddrCompact::V6(address) = self { address.to_string() } else { panic!("Invalid V6"); }
    }
}

enum IpAddrMoreCompact {
    V4(u8, u8, u8, u8),
    V6(String),
}

struct IpAddr {
    kind: IpAddrKind,
    address: String,
}

struct Ipv4Addr {
// --snip--

}

struct Ipv6Addr {
// --snip--

}

enum IpAddrFromStruct {
    V4(Ipv4Addr),
    V6(Ipv6Addr),
}

// variants of enum
enum Message {
    Quit,
    Move {x: i32, y: i32},
    Write(String),
    ChangeColor(i32, i32, i32),
}

impl Message {
    fn call(&self) {
        // method body would be defined here
    }
}

fn main() {

    // enum basics
    let four = IpAddrKind::V4;
    let six = IpAddrKind::V6;

    let home = IpAddr { kind: IpAddrKind::V4, address: String::from("127.0.0.1") };
    let loopback = IpAddr { kind: IpAddrKind::V6, address: String::from("::1") };

    let home = IpAddrCompact::V4(home.address);
    let loopback = IpAddrCompact::V6(loopback.address);

    let home_address: Vec::<u8> = home.v4().as_str().split(".").collect::<Vec<&str>>().iter().map(|x| x.parse::<u8>().unwrap()).collect();
    let home = IpAddrMoreCompact::V4(home_address[0], home_address[1], home_address[2], home_address[3]);
    let loopback = IpAddrMoreCompact::V6(loopback.v6());

    let home = IpAddrFromStruct::V4(Ipv4Addr{});
    let loopback = IpAddrFromStruct::V6(Ipv6Addr{});

    // enum variant example
    let mut m = Message::Write(String::from("hello"));
    m.call();

    // Option special enum
    let some_number = Some(5);
    let some_string = Some("a string");
    let absent_number: Option<i32> = None;

}

fn route(ip_type: IpAddrKind) {}
