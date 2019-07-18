using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Animal
{
    public class Cat
    {
        //Properties
        public int Age { get; set; }
        public string Name {get; set; }
        public char CatClass { get; set;}

        //Constructor
        
        public Cat(int age, string name, char catClass)
        {
            this.Age = age;
            this.Name = name;
            this.CatClass = catClass;
        }
        //Methods
        
        public static string Move(int Age, string Name, char CatClass)
        {
            return "Slow and steady"; // 
        }
        public static void Jump(char CatClass, string Name)
        {
            Console.WriteLine(CatClass+ ", "+ Name + "Jump");
        }

        public override string ToString()
        {
            return "Cat: "+ Name + " "+ Age+ " "+CatClass;
        }
    }
    public class Dog
    {
        //Properites
        public int Age { get; set; }
        public string Name { get ; set; }
        public char DogClass { get; set; }
        //Constructor
        public Dog(int age, string name, char dogClass)
        {
            this.Age = age;
            this.Name = name;
            this.DogClass = dogClass;
        }
        //Methods
        public static string Move(int Age, string Name, char DogClass)
        {
            if(Age > 10)
            {
                return "I'm at the age of "+ Age +" and name " + Name + ",I'm about to dieeeeeeeeee";
            }
            return "I'm move normally"; 
        }

        public static void Bark(string Name)
        {
            Console.WriteLine(Name + " Barkkk .. Barkkk");
        }

        public override string ToString()
        {
            return "Dog: "+ Name + " " + Age + " "+ DogClass;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            //Builde a queue
            
            Queue AQueue = new Queue();
            Dog dog = new Dog(15, "Chip", 'S');
            Cat cat = new Cat(21, "Zeroska", 'A');
            foreach(object animal in AQueue)
            {
                AQueue.Enqueue(cat);
                AQueue.Enqueue(dog);
            }
            AQueue.Dequeue();
            foreach(object animal in AQueue)
            {
                Console.WriteLine(animal);
            }
        }
    }
}
