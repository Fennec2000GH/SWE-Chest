
using System;
using System.Collections.Generic;
using System.Linq;
using System.Diagnostics;

namespace CollectionsNamespace {
    public class DictionaryExample {
        static void Main(string[] args) {
            // CONSTRUCTORS
            Dictionary<string, double> dict = new Dictionary<string, double>();
            // dict = new Dictionary<string, double>(new KeyValuePair<string, double>[]
            // {
            //     new KeyValuePair<string, double>("apple", 4),
            //     new KeyValuePair<string, double>("banana", 14),
            //     new KeyValuePair<string, double>("cauliflower", 8),
            //     new KeyValuePair<string, double>("dandelion", 9) 
            // });
            //
            dict = new Dictionary<String,Double>(capacity: 10);
            Dictionary<string, double> temp = new Dictionary<string, double>();
            temp.Add("aardvark", 1.22);
            temp.Add("bear", 2.31);
            temp.Add("cat", 3.45);
            temp.Add("duck", 4.44);
            dict = new Dictionary<string, double>(dictionary: temp);
            
            // PROPERTIES
            Console.WriteLine("count = {0}", dict.Count);

            Console.Write("keys = ");
            foreach (string key in dict.Keys) { Console.Write("{0}, ", key); } // {"aardvark", "bear","cat", "duck"}
            Console.WriteLine();
            
            Console.Write("values = ");
            foreach (double value in dict.Values) { Console.Write("{0}, ", value); } // {1.22, 2.31, 3.45, 4.44}
            Console.WriteLine();

            dict.Clear();
            Console.WriteLine("count after clear = {0}", dict.Count); // 0

            Console.Write("cat exists as key ? {0}", dict.ContainsKey(key: "cat")); // true
            
            Console.Write("1.22 exists as value ? {0}", dict.ContainsValue(value: 1.22)); // true

            Console.WriteLine("type = {0}", dict.GetType()); // Dictionary

            string out_str;
            dict.Remove(key: "duck");
            dict.Remove(key: "cat", value: out out_str);
            Console.WriteLine("dict has 'duck'? {0}", dict.ContainsKey(key: "duck")); // false
            Console.WriteLine("out_str = {0}", out_str); // cat

            dict.EnsureCapacity(capacity: 5);
            
            Console.WriteLine("string version of dict = {0}", dict.ToString());

            dict.TrimExcess();
            dict.TrimExcess(capacity: 10);
            
            Console.WriteLine("try adding aardvark as key again = {0}", dict.TryAdd(key: "aardvark", value: 3.44)); // false
            Console.WriteLine("try getting value for bear = {0}", dict.TryGetValue(key: "bear", value: out out_str)); // true
            Console.WriteLine("out_str = {0}", out_str);

        }
    }
}