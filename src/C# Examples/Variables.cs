
// https://www.tutorialspoint.com/csharp/csharp_variables.htm
using System;

namespace VariableDefinition {
    class Program {
        static void Main(string[] args) {
            short a;
            int b ;
            double c;

            // defining variables
            int i, j, k;
            char c_1, c_2;
            float f, salary;
            double d;

            // actual initialization
            a = 10;
            b = 20;
            c = a + b;
            Console.WriteLine("a = {0}, b = {1}, c = {2}", a, b, c);
            Console.ReadLine();

            // accepting values from users
            int num;
            num = Convert.ToInt32(Console.ReadLine());

        }
    }
}
