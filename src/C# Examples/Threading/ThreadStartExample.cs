
using System;
using System.Threading;

namespace ThreadingNamespace {
    public class ThreadStartExample {
        static void Main(string[] args) {
            Car audi = new Car(make: "Audi", model: "R8", year: 2020, odometerReading: 0);
            ThreadStart ts = new ThreadStart(Car.Parking);
            Thread thread = new Thread(ts);
            thread.Start();
            
            ParameterizedThreadStart pts = new ParameterizedThreadStart(audi.Drive);
            thread = new Thread(pts);
            thread.Start(20);

        }
    }

    public class Car {
        // MEMBER VARIABLES
        private string make;
        private string model;
        private uint year;
        private uint odometerReading;

        // CONSTRUCTORS
        public Car(string make, string model, uint year, uint odometerReading) {
            // Error checking
            try {
                if (make.Length == 0) { throw new ArgumentException("make cannot be empty"); }
                if (model.Length == 0) { throw new ArgumentException("model cannot be empty"); }
                if (year > 2020) { throw new ArgumentException("year cannot be more than present year (2020)"); }
                if (odometerReading > 50000) { throw new ArgumentException("car needs to be scrapped due to kilo/mileage"); }
            }
            catch (ArgumentException error) { Console.WriteLine("{0}: {1}", error.GetType().Name, error.Message); }

            this.make = make;
            this.model = model;
            this.year = year;
            this.odometerReading = odometerReading;
        }
        
        // ACCESSORS
        public static void Parking() { Console.WriteLine("Currently parking..."); }
        
        // MUTATORS
        public void Drive(object kilometers) {
            uint kilo = (uint)Convert.ToUInt64(kilometers ??= 0);
            this.odometerReading += kilo;
            for (uint i = 0; i < kilo; i++) { Console.Write("{0}, ", i); }
            Console.WriteLine();
            Console.WriteLine("Driving for {0} kilometers...", kilo);
        }
    }
}