
use std::fmt;

#[derive(Clone, Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }

    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }
}

impl fmt::Display for Rectangle {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "width: {}\nheight: {}\n", self.width, self.height)
    }
}

fn main() {
    let width1 = 30;
    let height1 = 50;
    let rect1 = Rectangle { width: width1, height: height1 };

    println!("The area of the rectangle is {} square pixels.", area(width1, height1));
    println!("The area of the rectangle is {} square pixels.", area_by_tuple((width1, height1)));
    println!("The area of the rectangle is {} square pixels.", area_by_struct(&rect1));
    println!("The area of the rectangle is {} square pixels.", area_by_struct(&rect1.clone()));
    println!("The area of the rectangle is {} square pixels.", rect1.area());
    area_by_struct(&rect1);
    println!("rect1 is {:?}", rect1);

    let rect1 = Rectangle { width: 30, height: 50 };
    let rect2 = Rectangle { width: 10, height: 40 };
    let rect3 = Rectangle { width: 60, height: 45 };
    println!("Can rect1 hold rect2? {}", rect1.can_hold(&rect2));
    println!("Can rectl hold rect3? {}", rect1.can_hold(&rect3));

}

fn area(width: u32, height: u32) -> u32 {
    width * height
}

fn area_by_tuple(dimension: (u32, u32)) -> u32 {
    dimension.0 * dimension.1
}

fn area_by_struct(rectangle: &Rectangle) -> u32 {
    rectangle.width * rectangle.height
}
