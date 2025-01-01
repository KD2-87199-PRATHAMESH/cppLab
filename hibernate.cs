using System.Reflection;
using ORMAnnotations;

namespace CreatingSqlDDLCommand
{
    internal class Program {
        static void Main(string[] args) { 
            string path = "C:\\Users\\Ganesh\\Desktop\\dotnet\\Classwork\\POCO\\bin\\Debug\\net6.0\\POCO.dll";

            Assembly assembly = Assembly.LoadFile(path);

            Type[] types = assembly.GetTypes();
            
            foreach (Type type in types) {
                if (!type.Name.Contains("Attribute")) {
                    string query = "CREATE TABLE ";
                    Attribute[] attributes = type.GetCustomAttributes().ToArray();

                    foreach (Attribute attribute in attributes) {
                        if (attribute is Table) { 
                            Table table = (Table)attribute;
                            query = query + table.name + "(";
                            break;
                        }
                    }

                    PropertyInfo[] properties = type.GetProperties();
                    foreach (PropertyInfo property in properties) {
                        Attribute[] propertyAttribute = property.GetCustomAttributes().ToArray();
                        foreach (Attribute attr in propertyAttribute)
                        {
                            if (attr is Column)
                            {
                                Column column = (Column)attr;
                                query = query + column.name + " " + column.datatype + ", ";
                                break;
                            }
                        }
                    }
                    query = query.TrimEnd(',', ' ') + ");";

                    string hibfile = "C:\\Users\\Ganesh\\Desktop\\New folder\\TableSchema.sql";
                    FileStream fileStream = null;
                    if (File.Exists(hibfile)) {
                        fileStream = new FileStream(hibfile, FileMode.Append, FileAccess.Write);
                    }
                    else { 
                        fileStream = new FileStream(hibfile, FileMode.OpenOrCreate, FileAccess.Write);
                    }
                    StreamWriter streamWriter = new StreamWriter(fileStream);
                    streamWriter.Write(query);
                    streamWriter.Close();
                    fileStream.Close();
                }
            }
        }
    }
}
