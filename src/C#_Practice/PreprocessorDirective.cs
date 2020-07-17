
// https://www.tutorialspoint.com/csharp/csharp_preprocessor_directives.htm
#define PI
#define DEBUG
#define VC_V10
using System;

namespace PreprocessorDAppl {
    class Program {
        static void Main(string[] args) {
            #if (PI)
                Console.WriteLine("PI is defined");
            #else
                Console.WriteLine("PI is not defined");
            #endif

            #if (DEBUG && !VC_V10)
                Console.WriteLine("DEBUG is defined");
            #elif (!DEBUG && VC_V10)
                Console.WriteLine("VC_V10 is defined");
            #elif (DEBUG && VC_V10)
                Console.WriteLine("DEBUG and VC_V10 are defined");
            #else
                Console.WriteLine("DEBUG and VC_V10 are not defined");
            #endif
            Console.ReadKey();
        }
    }
}
