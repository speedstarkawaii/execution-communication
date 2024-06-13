using System;
using System.IO;

class execution_communication
{
    static void Main() // Console app because bro really thought I was gonna leak my execution! (not sigma)
    {
        Console.WriteLine("Execute script > ");
        string script = Console.ReadLine();
        File.WriteAllText("executescript.lua", script); // Writes the new script

    }
}
