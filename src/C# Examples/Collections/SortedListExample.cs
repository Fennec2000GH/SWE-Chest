
using System;
using System.Collections;
using System.Collections.Generic;

namespace CSharpSTL
{
    public class SortedListExample
    {
        static void Main(string[] args)
        {
            // CONSTRUCTORS
            SortedList<string, double> sl = new SortedList<string, double>();

            sl = new SortedList<string, double>(comparer: Comparer<string>.Create(comparison:
                                                            (key1, key2) => key1[key1.Length - 1] > key2[key2.Length - 1] ? 1 :
                                                            key1[key1.Length] < key2[key2.Length] ? -1 : 0));

            Dictionary<string, double> dict = new Dictionary<string, double>();
            dict.Add(key: "apple", value: 123.456);
            dict.Add(key: "banana", value: 3.412);
            dict.Add(key: "cactus", value: 1.66);
            dict.Add(key: "durian", value: 4.444);
            sl = new SortedList<string, double>(dictionary: dict);
            Console.Write("s1 keys = ");
            foreach(string key in sl.Keys) { Console.Write("{0}, ", key); }
            Console.WriteLine();

            sl = new SortedList<string, double>(capacity: 20);

            // s1 used for the rest of the code compares keys merely by length alone
            sl = new SortedList<string, double>(capacity: 18, comparer: Comparer<string>.Create(comparison:
                                                                        (key1, key2) => key1.Length > key2.Length ? 1 :
                                                                         key1.Length < key2.Length ? -1 : 0));

            // PROPERTIES
            Console.WriteLine("sl capacity = {0}", sl.Capacity);
            Console.WriteLine("sl comparer = {0}", sl.Comparer.ToString());

            SortedList slNonGeneric = new SortedList();
            Console.WriteLine("slNonGeneric fixed size or not? {0}", slNonGeneric.IsFixedSize);
            Console.WriteLine("slNonGeneric is read only? {0}", slNonGeneric.IsReadOnly);
            Console.WriteLine("slNonGeneric is synchronized? {0}", slNonGeneric.IsSynchronized);

            sl.Add(key: "Wendy's", value: 3.42);
            sl.Add(key: "Burger King", value: 2.34);
            sl.Add(key: "McDonald's", value: 4.12);
            sl.Add(key: "KFC", value: 6.66);
            Console.Write("sl keys = ");
            foreach (string key in sl.Keys) { Console.Write("{0}, ", key); } // {"KFC", "Wendy's", "McDonald's", "Burger King"}
            Console.WriteLine();
            Console.Write("sl values = "); // {6.66, 3.42, 4.12, 2.34}
            foreach (double val in sl.Values) { Console.Write("{0}, ", val); }
            Console.WriteLine();
            

            // METHODS
            sl.Clear();
            Console.WriteLine("sl count after clearing = {0}", sl.Count);

            sl.Add(key: "JollyBee", value: 12.12);
            Console.WriteLine("sl contains 'JollyBee' as key? {0}", sl.ContainsKey(key: "JollyBee")); // true

            Console.WriteLine("sl contains 'JollyBee' as value? {0}", sl.ContainsValue(value: 12.12)); // true

            // Adding back KV pairs before clearing
            sl.Add(key: "Wendy's", value: 3.42);
            sl.Add(key: "Burger King", value: 2.34);
            sl.Add(key: "McDonald's", value: 4.12);
            sl.Add(key: "KFC", value: 6.66);

            Console.WriteLine("index of 'JollyBee' key = {0}", sl.IndexOfKey(key: "JollyBee")); // 2

            Console.WriteLine("index of 'JollyBee' value = {0}", sl.IndexOfValue(value: 12.12)); // 2

            Console.WriteLine("remove 'Burger King' successful? {0}", sl.Remove(key: "Burger King")); // true

            sl.RemoveAt(index: 1);
            Console.WriteLine("remove item with index 1");

            double outValue;
            Console.WriteLine("getting 'JollyBee' successful? {0}", sl.TryGetValue(key: "JollyBee", value: out outValue));
            Console.WriteLine("outValue = {0}", outValue);

            sl.TrimExcess();
            Console.WriteLine("new capacity for sl after trimming excess = {0}", sl.Capacity);

            Console.Write("sl keys = ");
            foreach (string key in sl.Keys) { Console.Write("{0}, ", key); } // {"KFC", "Wendy's", "McDonald's", "Burger King"}
            Console.WriteLine();
            Console.Write("sl values = "); // {6.66, 3.42, 4.12, 2.34}
            foreach (double val in sl.Values) { Console.Write("{0}, ", val); }
            Console.WriteLine();

        }
    }
}







