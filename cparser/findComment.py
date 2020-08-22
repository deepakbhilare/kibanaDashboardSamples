import re

text = r"""    
    
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

print(type(re.compile('(?:/\*(.*?)\*/)|(?://(.*?)\n)', re.S)))

    #print(pattern.findall(text))

