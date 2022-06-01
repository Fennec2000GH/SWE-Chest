
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Data;
using System.Windows.Forms;


namespace CollectionsNamespace {
    public class StackExample {
        static void Main(string[] args) {
            // CONSTRUCTORS
            Stack<double> stack = new Stack<double>();
            stack = new Stack<double>(new double[]{1.23, 4.56, 3.44, 7.88});
            stack = new Stack<double>(5);
            
            // PROPERTIES
            Console.WriteLine("Count = {0}", stack.Count); // 5
            
            // Console.WriteLine("Is stack synchronized? {0}", stack.IsSynchronized);

            // Console.WriteLine("SyncRoot {0}", stack.SyncRoot);
            
            // METHODS
            stack.Push(1.234);
            stack.Push(2.145);
            stack.Push(3.145);
            stack.Push(4.556);
            Console.WriteLine("Count before clear = {0}", stack.Count); // 5
            stack.Clear();
            Console.WriteLine("Count after clear = {0}", stack.Count); // 0
            
            stack = new Stack<double>(Enumerable.Range(start: 0, count: 5).Select(x => (double)x / 2)); // {0.0, 0.5, 1.0, 1.5, 2.0} top
            double[] arr = new double[10];
            stack.CopyTo(arr, 0); // {0.0, 0.5, 1.0, 1.5, 2.0} top
            Console.WriteLine("arr = ");
            foreach (double d in arr) { Console.WriteLine("{0}, ", d); }
            Console.WriteLine();
            
            Stack<double> stackCopy = new Stack<double>(arr);
            Console.WriteLine("stack equals stackCopy ? {0}", stack.Equals(stackCopy));

            Console.WriteLine("type = {0}", stack.GetType());

            stack.Push(3.141592654);
            Console.WriteLine("peek value = {0}", stack.Peek()); // 3.141592654

            double temp;
            temp = stack.Pop(); // 3.141592654
            Console.WriteLine("temp = {0}", temp);

            var objStack = new Stack<object>();
            objStack.Push("rat");
            objStack.Push(12);
            objStack.Push(true);
            // Stack<object> sstack = Stack<object>.Sychronized(objStack); // {0.0, 0.5, 1.0, 1.5, 2.0} top
            // Console.WriteLine(sstack.IsSynchronized); // true

            arr = stack.ToArray(); // {0.0, 0.5, 1.0, 1.5, 2.0} top
            Console.WriteLine("string version = {0}", stack.ToString());

        }
    }
}