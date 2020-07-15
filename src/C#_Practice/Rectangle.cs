// https://www.tutorialspoint.com/csharp/csharp_basic_syntax.htm
using System;

namespace RectangleApplication {
    class Rectangle {

        //member variables
        double length;
        double width;

        public void AcceptDetails() {
            length = 4.5;
            width = 3.5;
        }

        public double GetArea() { return length * width; }
        
        public void Display() { 
            Console.WriteLine("Length: {0}", length);
            Console.WriteLine("Width: {0}", width);
            Console.WriteLine("Area: {0}", GetArea());
        }
    }

    class ExecuteRectangle {
        static void Main(string[] args) {
            Rectangle r = new Rectangle();
            r.AcceptDetails();
            r.Display();
            Console.ReadLine();
        }
    }
}
