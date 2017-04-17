of = open("effects.txt","w")
with open("effects.csv","r") as fp:
    for line in fp:
        if line != "\n":
            a,x = line.split("?")
            if len(a) > 3:
                a=a.replace("-",",")
                print("atlas.push_back(Item(" + a + r',"' + x + r'"' + "));", file=of)
            else:
                print("atlas.push_back(Item(" + a + "," + a + "," + x + "));", file=of)
        else:
            print("",file=of)

fp.close()