
use std::fmt;

#[derive(Clone)]
struct User {
    username: String,
    email: String,
    sign_in_account: u64,
    active: bool,
}

impl fmt::Display for User {
    fn fmt(&self, f: &mut fmt::Formatter<>) -> fmt::Result {
        write!(f, "{}\n{}\n{}\n{}\n", self.username, self.email, self.sign_in_account, self.active)
    }
}

impl User {
    fn new(username: String, email: String, sign_in_account: u64, active: bool) -> User {
        User {
            username,
            email,
            sign_in_account,
            active,
        }
    }
}

fn main() {

    // immutable instance
    let user1 = User {
        email: String::from("someone@example.com"),
        username: String::from("someusername123"),
        active: true,
        sign_in_account: 1,
    };
    println!("{}", user1);


    // mutable instance
    let mut user1 = user1.clone();
    user1.email = String::from("anotheremail@example.com");
    println!("{}", user1);

    let mut user2 = build_user(user1.email, String::from("newusername"));
    user2.active = false;
    println!("{}", user2);

    let mut user3 = User::new(String::from("user3@email.com"), String::from("username"), 5, false);
    user3.username = String::from("username3");
    println!("{}", user3);

    let mut user4 = User {
        username: String::from("user4"),
        email: String::from("user4@yahoo.com"),
        ..user3
    };
    user4.sign_in_account = 25;
    println!("{}", user4);

}

fn build_user(email: String, username: String) -> User {
    User {
        email,
        username,
        active: true,
        sign_in_account: 1,
    }
}
