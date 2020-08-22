import re

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

COMMENTS = re.compile(r'''
    (//[^\n]*(?:\n|$))    # Everything between // and the end of the line/file
    |                     # or
    (/\*.*?\*/)           # Everything between /* and */
''', re.VERBOSE)


def remove_comments(content):
    print(COMMENTS.sub('\n', content))


remove_comments(text)
