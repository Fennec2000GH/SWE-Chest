
using System;
using System.Collections.Generic;
using System.Collections.Concurrent;
using System.Threading;

namespace ConcurrentNamespace {
    public class ConcurrentBagExample {
        static void Main(string[] args) {
            // CONSTRUCTORS
            ConcurrentBag<int> cbag = new ConcurrentBag<int>(new int[]{1, 2, 4, 7, 12, 222});
            ConcurrentBag<string> cb = new ConcurrentBag<string>();

            // PROPERTIES
            Console.WriteLine("Count = {0}", cb.Count); // 0
            Console.WriteLine("Is cb empty? {0}", cb.IsEmpty); // true

            // FUNCTIONS
            cb.Add(item: "cow");
            cb.Add(item: "chicken");
            cb.Add(item: "duck");
            cb.Add(item: "sheep");

            Console.WriteLine("cb = ");
            foreach (string s in cb) { Console.Write("{0}, ", s); } // {"cow", "chicken", "duck", "sheep"}
            Console.WriteLine();

            // cb.Clear();
            cb = new ConcurrentBag<string>();
            Console.WriteLine("cb after clear is empty? {0}", cb.IsEmpty); // true
            
            cb.Add(item: "Germany");
            cb.Add(item: "Spain");
            cb.Add(item: "Sweden");
            cb.Add(item: "Serbia");
            
            string[] arr = new string[cb.Count];
            cb.CopyTo(array: arr, index: 0);
            Console.WriteLine("arr = ");
            foreach (string s in arr) { Console.Write("{0}, ", s); } // {"Germany", "Spain", "Sweden", "Serbia"}
            Console.WriteLine();
            
            ConcurrentBag<string> cb_copy = new ConcurrentBag<string>(cb);
            Console.WriteLine("cb is equal to its copy? {0}", cb.Equals(cb_copy)); // true

            IEnumerator<string> en = cb.GetEnumerator();
            Console.Write("cb = ");
            while (en.MoveNext()) { Console.Write("{0}, ", en.Current); }
            Console.WriteLine();

            Console.WriteLine("cb hashcode = {0}", cb.GetHashCode());

            Console.WriteLine("cb type = {0}", cb.GetType().FullName);
            
            arr = cb.ToArray();
            Console.WriteLine("arr afteer using ToArray on cb = ");
            foreach (string s in arr) { Console.Write("{0}, ", s); } // {"Germany", "Spain", "Sweden", "Serbia"}
            Console.WriteLine();

            Console.WriteLine("string version of cb = {0}", cb.ToString());

            string result_str;
            Console.WriteLine("peeking = {0}", cb.TryPeek(result: out result_str)); // true
            Console.WriteLine("peeking result = {0}", result_str);
            
            // Console.WriteLine("taking = {0}", cb.TryTaking(result: out result_str)); // true
            // Console.WriteLine("taking result = {0}", result_str);
            
            // Threading
            int num = 0;
            Thread threadAdd = new Thread(() => {
                for (int i = num; i < num + 10; i++) {
                    cb.Add(item: i.ToString());
                    Console.WriteLine("threadAdd: {0}", i);
                }
                num += 10;
                Console.WriteLine();
            });
            Thread threadAddWord = new Thread(() => {
                for (int i = 1; i < 10; i++) {
                    cb.Add(item: "Word");
                    Console.WriteLine("threadAddWord: {0}", i);
                }
                Console.WriteLine();
            });

            Thread threadFinal = new Thread(() => {
                Console.WriteLine("cb after threading = ");
                foreach (string s in cb) { Console.Write("{0}, ", s); }
                Console.WriteLine();
            });

            threadAdd.Start();
            threadAddWord.Start();
            threadAdd.Join();
            threadAddWord.Join();
            threadFinal.Start();
        }
        
    }
}


