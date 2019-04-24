namespace BaristaLabs.EspressoCore.ConsoleTest
{
    using System;
    using BaristaLabs.EspressoCore.JavaScript.Native;

    class Program
    {
        static void Main(string[] args)
        {
            V8.Initialize();

            for (int i = 0; i < 10; i++)
            {
                JsEngine.EvaluateScript("`${'Hello'} World! ${6*7}`");
            }

            V8.Shutdown();

            Console.WriteLine("All Done...");
            Console.ReadLine();
        }
    }
}
