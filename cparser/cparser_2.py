import re
import sys

text = r"""  

    /* this is a comment 1 */
    //this is a 
    //comment 2
    
    /* this is 
        a 
        multiline 
        comment 4
    */  
    
    struct car
    {
            char make[20];
            char model[30]; 
            int year;
        };

    void HashPrint() 
    {        
        struct car arr_car[2] = {
            {"Audi", "TT", 2016},
            {"Bentley", "Azure", 2002}
        };
    }
"""

def remove_comments(text):
    """ remove c-style comments.
        text: blob of text with comments (can include newlines)
        returns: text with comments removed
    """
    pattern = r"""
                            ##  --------- COMMENT ---------
           /\*              ##  Start of /* ... */ comment
           [^*]*\*+         ##  Non-* followed by 1-or-more *'s
           (                ##
             [^/*][^*]*\*+  ##
           )*               ##  0-or-more things which don't start with /
                            ##    but do end with '*'
           /                ##  End of /* ... */ comment
         |                  ##  -OR-  various things which aren't comments:
           (                ## 
                            ##  ------ " ... " STRING ------
             "              ##  Start of " ... " string
             (              ##
               \\.          ##  Escaped char
             |              ##  -OR-
               [^"\\]       ##  Non "\ characters
             )*             ##
             "              ##  End of " ... " string
           |                ##  -OR-
                            ##
                            ##  ------ ' ... ' STRING ------
             '              ##  Start of ' ... ' string
             (              ##
               \\.          ##  Escaped char
             |              ##  -OR-
               [^'\\]       ##  Non '\ characters
             )*             ##
             '              ##  End of ' ... ' string
           |                ##  -OR-
                            ##
                            ##  ------ ANYTHING ELSE -------
             .              ##  Anything other char
             [^/"'\\]*      ##  Chars which doesn't start a comment, string
           )                ##    or escape
    """
    regex = re.compile(pattern, re.VERBOSE | re.MULTILINE | re.DOTALL)
    noncomments = [m.group(2) for m in regex.finditer(text) if m.group(2)]

    return "".join(noncomments)


if __name__ == '__main__':
    #filename = sys.argv[1]
    #code_w_comments = open(filename).read()
    #code_wo_comments = remove_comments(code_w_comments)
    #fh = open(filename + ".nocomments", "w")
    #fh.write(code_wo_comments)
    #fh.close()
    print(remove_comments(text))
