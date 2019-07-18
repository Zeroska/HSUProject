using.System;
using.Text;


namespace OOPExample
{
    class Program
    {
        class Weapon 
        {
            //Atr
            string name;
            int firePower;
            int movement;

            //constructor
            public Weapon(string name, int firePower, int movement)
            {
                this.name = name;
                this.firePower = firePower;
                this.movement = movement;
            }

            //method
            public virtual void fire()
            {
                Console.WriteLine($"{name}: pew pew pew");
            }
        }

        class Rife : Weapon
        {
            public Rife(string name, int firePower, int movement) : base(name, firePower, movement)
            {

            }
            public overide void fire()
            {
                Console.WriteLine($"{name}: Ratatatatat");
            }
        }

        class SMG : Weapon
        {
            public SMG(string name, int firePower, int movement) : base(name, firePower, movement)
            {

            }
        }

        class Shotgun : Weapon 
        {
            public Shotgun(string name, int firePower, int movement) : base(name,firePower, movement)
            {

            }

            public overide void fire()
            {
                Console.WriteLine($"{name}: POW");
            }
        }
        static void Main(string[] argv)
        {
            Weapon AK47 = new Rife("AK 47", 200, 100);
            Weapon SawOff = new Shotgun("SawOff",500, 150);
            Weapon Mp5 = new SMG("Mp5",150, 200);

            AK47.fire();
        }
    }
}
