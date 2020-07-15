
// https://www.tutorialspoint.com/csharp/csharp_data_types.htm
using System;

namespace DataTypeApplication {
    class Program {
        static void Main(string[] args) {
            Console.WriteLine("Size of int: {0}", sizeof(int));
            Console.ReadLine();

            //------------------------------------------------------------------------------------------------------------------------------------------------------------
            //Reference Types
            //Object Type
            Object obj;
            obj = 100;  // this is boxing
            Console.WriteLine("obj: {0}", obj);

            //Dynamic Type
            dynamic d = 20;
            Console.WriteLine("d: {0}", d);

            //String Type
            String str = "TutorialsPoint";
            Console.WriteLine("str: " + str);
            char[] c = {'c', 'h', 'a', 'r'};
            str = new String(c);
            Console.WriteLine("str: {0}", str);
            str = @"quoted";
            Console.WriteLine("str: {0}", str);

            //------------------------------------------------------------------------------------------------------------------------------------------------------------
            //Pointer Types
            unsafe {
                char character = 'c';
                int i = 1;
                char * cptr = &character;
                int * iptr = &i;
            }
        }
    }
}
