
// https://www.tutorialspoint.com/csharp/csharp_constants.htm
using System;

namespace Constant {
    class Program {
        static void Main(string[] args) {
            // integer literals
            Object constant = 212;
            Console.WriteLine(constant);
            constant = 215U;
            Console.WriteLine(constant);
            constant = 0xFeeL; // 4078
            Console.WriteLine(constant);
            constant = 0x4b;
            Console.WriteLine(constant);
            constant = 85;         /* decimal */
            Console.WriteLine(constant);
            constant = 0x4b;       /* hexadecimal */
            Console.WriteLine(constant);
            constant = 30;         /* int */
            Console.WriteLine(constant);
            constant = 30U;        /* unsigned int */
            Console.WriteLine(constant);
            constant = 30L;        /* long */
            Console.WriteLine(constant);
            constant = 30UL;       /* unsigned long */
            Console.WriteLine(constant);

            // floating point literals
            constant = 3.14159;
            Console.WriteLine(constant);
            constant = 314159E-5F;
            Console.WriteLine(constant);

        }
    }
}
