# String Matching
###### Small programs to overview the process of three string matching algorithm:
1. [Brute Force](#example-result-of-brute-force),
2. [Boyer Moore](#example-result-of-boyer-moore), and
3. [Horspool](#example-result-of-horspool)

### Example result of Brute Force
String = *Hello world! Hello world! Hello world!*<br />
Pattern = *ello*<br />
<pre>
Hello world! Hello world! Hello world!
ello
 ello
Found at index 1.
  ello
   ello
    ello
     ello
      ello
       ello
        ello
         ello
          ello
           ello
            ello
             ello
              ello
Found at index 14.
               ello
                ello
                 ello
                  ello
                   ello
                    ello
                     ello
                      ello
                       ello
                        ello
                         ello
                          ello
                           ello
Found at index 27.
                            ello
                             ello
                              ello
                               ello
                                ello
                                 ello
                                  ello
                                   ello
                                    ello
                                     ello
</pre>

### Example result of Boyer Moore
String = *Hello world! Hello world! Hello world!*<br />
Pattern = *ello*<br />
<pre>
Hello world! Hello world! Hello world!
ello
 ello
Found at index 1.
     ello
         ello
             ello
              ello
Found at index 14.
                  ello
                      ello
                          ello
                           ello
Found at index 27.
                               ello
</pre>

### Example result of Horspool
String = *Hello world! Hello world! Hello world!*<br />
Pattern = *ello*<br />
<pre>
Hello world! Hello world! Hello world!
ello
 ello
Found at index 1.
     ello
         ello
             ello
              ello
Found at index 14.
                  ello
                      ello
                          ello
                           ello
Found at index 27.
                               ello
</pre>
