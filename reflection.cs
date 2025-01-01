
using System.Reflection;

namespace reflection
{
    internal class Reflection {
        static void Main(string[] args) {
            string path = "C:\\Users\\Ganesh\\Desktop\\dotnet\\Classwork\\MathLib\\bin\\Debug\\net6.0\\MathLib.dll";
            Assembly assembly = Assembly.LoadFrom(path);
            Type[] types = assembly.GetTypes();

            foreach (Type type in types) {
                object dynamicallyCreatedObject = assembly.CreateInstance(type.FullName);

                MethodInfo[] methods = type.GetMethods();
                foreach (MethodInfo method in methods) { 
                    Console.WriteLine("\ncalling method {0}:", method.Name);
                    ParameterInfo[] parameters = method.GetParameters();

                    object[] passingParameters = new object[parameters.Length];
                    for(int i = 0; i < passingParameters.Length; i++){
                        Console.Write("\nEnter {0} of type {1}: ", parameters[i].Name, parameters[i].ParameterType);
                        string readParameter = Console.ReadLine();
                        object parameterType = Convert.ChangeType(readParameter, parameters[i].ParameterType);
                        passingParameters[i] = parameterType;
                    }
                    object returnedFromMethod = type.InvokeMember(method.Name,
                        BindingFlags.Public|
                        BindingFlags.Instance|
                        BindingFlags.InvokeMethod,
                        null,
                        dynamicallyCreatedObject,
                        passingParameters
                    );
                    Console.WriteLine("Returned From Method: " + returnedFromMethod);
                }
            }
        }
    }
}
