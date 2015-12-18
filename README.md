# String Matching
###### Small programs to overview the process of three string matching algorithm:
1. Brute Force,
2. Boyer Moore, and
3. Horspool

### Example result of Brute Force
String = *Hello world! Hello world! Hello world!*<br />
Pattern = *ello*<br />
Result:
<pre>
Hello world! Hello world! Hello world!<br />
ello<br />
 ello<br />
Found at index 1.<br />
  ello<br />
   ello<br />
    ello<br />
     ello<br />
      ello<br />
       ello<br />
        ello<br />
         ello<br />
          ello<br />
           ello<br />
            ello<br />
             ello<br />
              ello<br />
Found at index 14.<br />
               ello<br />
                ello<br />
                 ello<br />
                  ello<br />
                   ello<br />
                    ello<br />
                     ello<br />
                      ello<br />
                       ello<br />
                        ello<br />
                         ello<br />
                          ello<br />
                           ello<br />
Found at index 27.<br />
                            ello<br />
                             ello<br />
                              ello<br />
                               ello<br />
                                ello<br />
                                 ello<br />
                                  ello<br />
                                   ello<br />
                                    ello<br />
                                     ello<br />
</pre>
