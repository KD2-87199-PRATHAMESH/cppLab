		String s = new String("http://www.google.com/search");

		StringTokenizer(string, allDelimitersWithoutSpace, booleanForIncludingDelimiterAsToken)

		StringTokenizer tok = new StringTokenizer(s, "./:", true);
		while (tok.hasMoreTokens()) {
			String t = tok.nextToken();
			System.out.println(t);
		}

		String e = new String("");
		String s = "http://www.google.com/search";
		
		At runtime function call is resolved and s is resolved at runtime, any processing done at 
		runtime returns new String object on heap. 
		
		String ss = "".concat("http://www.google.com/search");
		String sss = s + "http://www.google.com/search";
		System.out.println(s == ss);
		System.out.println(s == sss);

		String s = "http://www.google.com/search";
		
		intern() will check for any type of String in String Literal/Constant Pool if not available
		then add it, returns new reference of string from SCP and if available then returns same 		r
		reference from SLP.
		
		String ss = new String("http://www.google.com/search").intern();
		System.out.println(s == ss);
