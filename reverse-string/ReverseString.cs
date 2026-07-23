/* With tail recurse function and accumulator */
string ReverseString(string source)
{
    string Aux(string acc, string source)
    {
        if (source == null || source == "") {
            return acc;
        }
        string newAcc = source[0] + acc;
        string newSource = source.Length > 1 ? source.Substring(1) : "";
        return Aux(newAcc, newSource);
    }

    return Aux("", source);
}

/* Regular CSharp Way */
string ReverseString2(string source)
{
    string acc = "";
    foreach (var ch in source) {
        acc = ch + acc;
    }
    return acc;
}

void Test(Func<string, string> reverseFunction, string source, string expected)
{
    string reversed = reverseFunction(source);
    if (reversed != expected) {
        Console.WriteLine($"[Error] Expected '{expected}' but got '{reversed}' instead.");
    }
}

void Main()
{
    Test(ReverseString, "hello", "olleh");
    Test(ReverseString, "foobar", "raboof");
    Test(ReverseString, "racecar", "racecar");
    Test(ReverseString, "a", "a");
    Test(ReverseString, "", "");
    Test(ReverseString, "ab", "ba");
    Test(ReverseString, "this is my super long string", "gnirts gnol repus ym si siht");
    Test(ReverseString, "12345", "54321");

    Test(ReverseString2, "hello", "olleh");
    Test(ReverseString2, "foobar", "raboof");
    Test(ReverseString2, "racecar", "racecar");
    Test(ReverseString2, "a", "a");
    Test(ReverseString2, "", "");
    Test(ReverseString2, "ab", "ba");
    Test(ReverseString2, "this is my super long string", "gnirts gnol repus ym si siht");
    Test(ReverseString2, "12345", "54321");
}

Main();
