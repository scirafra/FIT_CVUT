from tkinter import *
a=Canvas(height=1100,width=1100,bg='white')
a.pack()
plan=[]
poradie=0
pis=3
n=0
win=False
c=3
vel=3
moje=0
p=[['A','B','C','X'],['1','2','3'],['L','M','S','X']]
far=['green','blue','red','purple','white']
panak=[]
velkosti=[80,50,8]
pos=[[[350,125],[550,125],[750,125]],[[350,975],[550,975],[750,975]],[[975,350],[975,550],[975,750]],[[125,350],[125,550],[125,750]]]


for i in range(3):
        plan.append([])
        for j in range(3):
            plan[i].append([4,4,4])

def plocha():
    
    for i in range(3):
        a.create_text(230,350+i*200,text=p[1][i],font='Arial20')
        a.create_text(350+i*200,230,text=p[0][i],font='Arial20')
        for j in range(3):
            a.create_rectangle(250+i*200,250+j*200,450+i*200,450+j*200,fill='white')

for i in range(n):
    panak.append([[True,True,True],[True,True,True],[True,True,True]])
    
def panaci(n):
    
    for i in range(n):
        
        for j in range(3):
            for h in range(3):
                f=far[i]
                if panak[i][j][h]!=True:
                    f='white'
                a.create_oval(pos[i][j][0]-velkosti[h],pos[i][j][1]-velkosti[h],pos[i][j][0]+velkosti[h],pos[i][j][1]+velkosti[h],fill=f)
                if h<2:
                    a.create_oval(pos[i][j][0]-velkosti[h]+8,pos[i][j][1]-velkosti[h]+8,pos[i][j][0]+velkosti[h]-8,pos[i][j][1]+velkosti[h]-8,fill='white')
def pnp():
    a.create_rectangle(0,0,1100,1100,fill='white')
    plocha()
    for i in range(3):
        for j in range(3):
            for h in range(3):
                        if plan[i][j][h]>3:
                                x=4
                        else:
                                x=plan[i][j][h]
                        
                        a.create_oval(350+i*200-velkosti[h],350+j*200-velkosti[h],350+i*200+velkosti[h],350+j*200+velkosti[h],fill=far[x])
                        if h<2:
                                a.create_oval(350+i*200-velkosti[h]+8,350+j*200-velkosti[h]+8,350+i*200+velkosti[h]-8,350+j*200+velkosti[h]-8,fill='white')


def polickoA():
        global pis
        global c
        global vel
        pis=0
        l1=Label(text=p[0][pis]+str(c+1)+p[2][vel],width=4)
        l1.place(x=110,y=10)

def polickoB():
        global pis
        global c
        global vel
        pis=1
        l1=Label(text=p[0][pis]+str(c+1)+p[2][vel],width=4)
        l1.place(x=110,y=10)

def polickoC():
        global pis
        global c
        global vel
        pis=2
        l1=Label(text=p[0][pis]+str(c+1)+p[2][vel],width=4)
        l1.place(x=110,y=10)

def policko1():
        global pis
        global c
        global v
        c=0
        l1=Label(text=p[0][pis]+str(c+1)+p[2][vel],width=4)
        l1.place(x=110,y=10)

def policko2():
        global pis
        global c
        global v
        c=1
        l1=Label(text=p[0][pis]+str(c+1)+p[2][vel],width=4)
        l1.place(x=110,y=10)

def policko3():
        global pis
        global c
        global vel
        c=2
        l1=Label(text=p[0][pis]+str(c+1)+p[2][vel],width=4)
        l1.place(x=110,y=10)

def polickov1():
        global pis
        global c
        global vel
        vel=0
        l1=Label(text=p[0][pis]+str(c+1)+p[2][vel],width=4)
        l1.place(x=110,y=10)

def polickov2():
        global pis
        global c
        global vel
        vel=1
        l1=Label(text=p[0][pis]+str(c+1)+p[2][vel],width=4)
        l1.place(x=110,y=10)

def polickov3():
        global pis
        global c
        global vel
        vel=2
        l1=Label(text=p[0][pis]+str(c+1)+p[2][vel],width=4)
        l1.place(x=110,y=10)

def counter():
        global poradie
        poradie=poradie+1
        if poradie>n-1:
                poradie=0
                
def tah1():
        global pis
        global vel
        global c
        counter()
        pis=3
        c=3
        vel=3
        l1=Label(text='X4X',width=4)
        l1.place(x=110,y=10)
        l2=Label(text=('Player '+str(poradie+1)+' '+far[poradie]),width=10)
        l2.place(x=900,y=20)
        

def tah2():
        global panak
        f=True
        plan[pis][c][vel]=poradie
        for x in range(3):
                if panak[poradie][x][vel]==f:
                        panak[poradie][x][vel]=False
                        f=False
        a.create_rectangle(0,0,1100,1100,fill='white')  
        pnp()             
        panaci(n)
        
        thewin()
        if win==False:
                tah1()
        else:
                a.create_rectangle(0,0,1100,1100,fill='white')
                a.create_text(550,550,text=('Player'+str(poradie+1)+' '+far[poradie]+' wins'),font='Arial 40')

        
        
def done():
        global d
        x=mameste()
        if c<3 and pis<3 and x==True and plan[pis][c][vel]>3:
                tah2()
        #a.create_image((1000, 950), image=img)

def mameste():
        x=False
        for i in range(3):
                if panak[poradie][i][vel]==True:
                        x=True
        return x
                
def newgame():
        global plan
        global panak
        panak=[]
        plan=[]
        x=3
        for i in range(3):
                plan.append([])
                for j in range(3):
                        plan[i].append([])
                        for h in range(3):      
                                x=x+1
                                plan[i][j].append(x)
        b1=Button(text='A',width=3,command=polickoA)
        b1.place(x=40,y=40)
        b2=Button(text='B',width=3,command=polickoB)
        b2.place(x=110,y=40)
        b3=Button(text='C',width=3,command=polickoC)
        b3.place(x=180,y=40)
        b4=Button(text='1',width=3,command=policko1)
        b4.place(x=40,y=80)
        b5=Button(text='2',width=3,command=policko2)
        b5.place(x=110,y=80)
        b6=Button(text='3',width=3,command=policko3)
        b6.place(x=180,y=80)
        b7=Button(text='L',width=3,command=polickov1)
        b7.place(x=40,y=120)
        b8=Button(text='M',width=3,command=polickov2)
        b8.place(x=110,y=120)
        b9=Button(text='S',width=3,command=polickov3)
        b9.place(x=180,y=120)
        b10=Button(text='Done',width=6,command=done)
        b10.place(x=100,y=160)
        
        
        
def hraci2():
        newgame()
        global n
        n=2
        ready()

def hraci3():
        newgame()
        global n
        n=3
        ready()

def hraci4():
        newgame()
        global n
        n=4
        ready()
        

def ready():
        global panak
        global poradie
        for i in range(n):
            panak.append([[True,True,True],[True,True,True],[True,True,True]])
        pnp()
        panaci(n)
        
        poradie=4
        tah1()
        #a.create_image((1000, 950), image=img)

def thewin():
        global win
        x=False
        for p in range(3):
                for c in range(3):
                        if plan[p][c][0]== plan[p][c][1] and plan[p][c][1]== plan[p][c][2]:
                                x=True
                                break  

        for p in range(3):
                for v in range(3):
                        if plan[p][0][v]== plan[p][1][v] and plan[p][1][v]== plan[p][2][v]:
                                x=True
                                break
                if plan[p][0][0]== plan[p][1][1] and plan[p][1][1]== plan[p][2][2]:
                        x=True
                        break
                elif plan[p][0][2]== plan[p][1][1] and plan[p][1][1]== plan[p][2][0]:
                        x=True
                        break
        for c in range(3):
                for v in range(3):
                        if plan[0][c][v]== plan[1][c][v] and plan[1][c][v]== plan[2][c][v]:
                                x=True
                                break
                if plan[0][c][0]== plan[1][c][1] and plan[1][c][1]== plan[2][c][2]:
                        x=True
                        break
                elif plan[0][c][2]== plan[1][c][1] and plan[1][c][1]== plan[2][c][0]:
                        x=True
                        break
        for v in range(3):
                if plan[0][0][v]== plan[1][1][v] and plan[1][1][v]== plan[2][2][v]:
                        x=True
                        break
                elif plan[2][0][v]== plan[1][1][v] and plan[1][1][v]== plan[0][2][v]:
                        x=True
                        break
        if plan[0][0][0]== plan[1][1][1] and plan[1][1][1]== plan[2][2][2]:
                x=True
        elif plan[2][0][0]== plan[1][1][1] and plan[1][1][1]== plan[0][2][2]:
                x=True
        elif plan[0][0][2]== plan[1][1][1] and plan[1][1][1]== plan[2][2][0]:
                x=True
        elif plan[2][0][2]== plan[1][1][1] and plan[1][1][1]== plan[0][2][0]:
                x=True
        win=x
                                
l1=Label(text='X4X',width=4)
l1.place(x=110,y=10)
l2=Label(text=('Player '+str(poradie+1)+' '+far[poradie]),width=10)
l2.place(x=900,y=20)
l3=Label(text='Kolko Hracov?',width=10)
l3.place(x=900,y=60)






b12=Button(text='2',width=3,command=hraci2)
b13=Button(text='3',width=3,command=hraci3)
b14=Button(text='4',width=3,command=hraci4)
b12.place(x=900,y=100)
b13.place(x=970,y=100)
b14.place(x=1040,y=100)
#img=PhotoImage(width=152, height=152, file='logo_upjs.gif')
#a.create_image((1000, 950), image=img)
