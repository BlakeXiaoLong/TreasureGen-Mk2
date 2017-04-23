of = open("armor.txt","w")
with open("armor.csv","r") as fp:
    for line in fp:
        if line != "\n":
            a,x,y = line.split("?")
            if len(a) > 3:
                a=a.replace("-",",")
                print("atlas.push_back(Item(" + a + r',"' + x + r'"' + "));", file=of)
            else:
                print("atlas.push_back(Item(" + a + "," + a + "," + x + "));", file=of)
        else:
            print("",file=of)

fp.close()