
using System;
using System.Collections.Generic;
using System.Linq;

namespace CollectionsNamespace {
    public class QueueExample {
        static void Main(string[] args) {
            // CONSTRUCTORS
            Queue<char> charQ = new Queue<char>();
            Queue<double> doubleQ = new Queue<double>(Enumerable.Range(start: 0, count: 5).Select(x => (double)x));
            Queue<string> stringQ = new Queue<string>(20);
            
            // PROPERTIES
            foreach (char ch in "words") { charQ.Enqueue(ch); }
            Console.WriteLine("charQ Count = {0}", charQ.Count);
            
            // METHODS
            charQ.Clear();
            Console.WriteLine("charQ Count after Clear = {0}", charQ.Count);

            stringQ.Enqueue(item: "My");
            stringQ.Enqueue(item: "Chemical");
            stringQ.Enqueue(item: "Romance");
            stringQ.Enqueue(item: "Sleeping");
            stringQ.Enqueue(item: "With");
            stringQ.Enqueue(item: "Sirens");
            Console.WriteLine("stringQ Contains 'Sirens'? {0}", stringQ.Contains(item: "Sirens")); // true

            string[] arr = new string[20];
            stringQ.CopyTo(array: arr, arrayIndex: 0); // {"My", "Chemical", "Romance", "Sleeping", "With", "Sirens"}
            Console.Write("arr = ");
            foreach (string str in arr) { Console.Write(str + ", "); }
            Console.WriteLine();

            Console.WriteLine("stringQ Dequeue value = {0}", stringQ.Dequeue()); // "My"
            Console.WriteLine("stringQ Contains 'Sirens'? {0}", stringQ.Contains(item: "My")); // false
            
            Queue<string> temp = new Queue<string>(new string[]{"My", "Chemical", "Romance", "Sleeping", "With", "Sirens"});
            Console.WriteLine("stringQ equals temp ? {0}", stringQ.Equals(obj: temp));

            Console.WriteLine("stringQ type = {0}", stringQ.GetType()); // string

            Console.WriteLine("stringQ Peek = {0}", stringQ.Peek()); // "Chemical"

            arr = stringQ.ToArray();
            Console.Write("arr = ");
            foreach (string str in arr) { Console.Write(str + ", "); } // {"My", "Chemical", "Romance", "Sleeping", "With"}
            Console.WriteLine();

            Console.WriteLine("stringQ converted to string = {0}", stringQ.ToString());

            stringQ.TrimExcess();
            Console.WriteLine("stringQ Count = {0}", stringQ.Count);

            string top;
            Console.WriteLine(stringQ.TryDequeue(out top)); // true
            Console.WriteLine("TryDequeue value = {0}", top); // "Chemical"

            Console.WriteLine(stringQ.TryPeek(out top));
            Console.WriteLine("TryPeek value = {0}", top); // "Romance"
            
        }
    }
}