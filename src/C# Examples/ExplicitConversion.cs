
// https://www.tutorialspoint.com/csharp/csharp_type_conversion.htm
using System;

namespace TypeConversionApplication {
    class ExplicitConversion {
        static void Main(string[] args) {
            double d = 5673.74;
            int i;

            // cast double to int
            i = (int)d;
            Console.WriteLine(i);
            Console.ReadKey();
        }
    }
}
