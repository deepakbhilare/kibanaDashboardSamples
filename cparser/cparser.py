import re

text = r"""    

    /* this is one line comment */
    /* 
    this is one 
    line 
    comment */
    //this is also 
    
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

pattern = re.compile('(?:/\*(.*?)\*/)|(?://(.*?)\n)', re.S)
print(pattern.findall(text))
