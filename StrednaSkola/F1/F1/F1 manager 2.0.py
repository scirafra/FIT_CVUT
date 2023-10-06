import random
import tkinter
import time
import os
a=tkinter.Canvas(width=1700,height=800,bg='white')
a.pack()

ability=[36,37,38,39,40,41,42,43,44,45,46,47,48,49,
         36,37,38,39,40,41,42,43,44,45,46,47,48,
         36,37,38,39,40,41,42,43,44,45,46,47,
         36,37,38,39,40,41,42,43,44,45,46,
         36,37,38,39,40,41,42,43,44,45,
         36,37,38,39,40,41,42,43,44,
         36,37,38,39,40,41,42,43,
         36,37,38,39,40,41,42,
         36,37,38,39,40,41,
         36,37,38,39,40,
         36,37,38,39,
         36,37,38,
         36,37,
         36,
         ]
nations=[
    ['Argentina','Arg',25,
        ['Pablo','Roberto','Juan','Manuel','Clemar','Alberto','Jorge','Nasif','Norberto','Oscar','Alfredo','Jose','Florian','Miguel','Angel','Jesus','Onofre','Gaston','Carlos','Adolfo','Esteban','Ricardo','Alejandro'],
        ['Birger','Bonomi','Bordeu','Bucci','Crespo','Daponte','Estefano','Fangio','Fontana','Galvez','Gonzalez','Guerra','Iglesias','Larrauri','Marimon','Mazzacane','Menditeguy','Mieres','Pian','Reutemann','Rodriguez','Larreta','Cruz','Tuero','Zunino','de Tomaso'],[],[]],
    ['Australia','Aus',17,
        ['David','Gary','Jack','Warwick','Paul','Frank','Tony','Alan','Ken','Brian','Larry','Daniel','Tim','Vern','Mark'],
        ['Brabham','Brown','England','Gardner','Gaze','Hawkins','Jones','Kavanagh','McGuire','Perkins','Ricciardo','Schenken','Schnuppan','Walker','Webber'],[],[]],
    ['Austria','Aut',16,
        ['Gerhard','Hans','Harald','Patrick','Jo','Christian','Helmuth','Niki','Karl','Dieter','Roland','Jochen','Otto','Alexander'],
        ['Berger','Binder','Ertl','Friesacher','Gartner','Klien','Koinigg','Lauda','Marko','Oppitzhauser','Quester','Ratzenberger','Rindt','Stuppacher','Wendlinger','Wurz'],[],[]],
    ['Belgium','Bel',24,
        ['Philippe','Georges','Lucien','Thierry','Alain','Johnny','Jerome','Bernard','Paul','Olivier','Jacky','Roger','Arthur','Willy','Andre','Patrick','Teddy','Eric','Jacques','Charles','Stoffel','Bertrand'],
        ['Adams','Berger','Bianchi','Boutsen','de Changy','Claes','dAmbrosio','de Dryver','Frere','Gendebien','Goethals','Ickx','Laurent','Legat','Mairesse','Milhoux','Neve','Pilette','van de Poele','Swaters','de Tornaco','Vandoorne','Gachot'],[],[]],
    ['Brazil','Bra',31,
        ['Rubens','Enrique','Gino','Raul','Luiz','Luciano','Pedro','Christian','Emerson','Wilson','Lucas','Mauricio','Ingo','Chico','Tarso','Felipe','Cristiano','Roberto','Fritz','Carlos','Nelson','Antonio','Hermano','Alex','Ricardo','Ayrton','Bruno'],
        ['Barrichello','Bernoldi','Bianco','Boesel','Bueno','Burti','Diniz','Fittipaldi','di Grassi','Gugelmin','Hoffmann','Landi','Marques','Massa','da Matta','Moreno','Nasr','dOrey','Pace','Piquet','Pizzonia','Ramos','Silva','Ribeiro','Rosset','Senna','Serra','Zonta'],[],[]],
    ['Canada','Can',14,
        ['Allen','Bill','Peter','John','George','Al','Lance','Gilles','Jacques','Ernie','Eppie'],
        ['Berg','Brack','Broeker','Cannon','Cordts','Eaton','Pease','Ryan','Stroll','Villeneuve','de Vos','Wietzes'],[],[]],
    ['Chile','Chi',1,
        ['Eliseo'],
        ['Salazar'],[],[]],
    ['Colombia','Col',3,
        ['Roberto','Ricardo','Juan','Pablo'],
        ['Guerrero','Londono','Montoya'],[],[]],
    ['Czech Republic','Cze',1,
        ['Tomas','Michal','Lukas','Vojtech'],
        ['Enge','Simlik','Heger','Jelen','Novotny'],[],[]],
    ['Denmark','Den',5,
        ['Tom','Nicolas','Jan','Kevin'],
        ['Belso','Kiesa','Magnussen','Nellemann'],[],[]],
    ['Germany','Ger',56,
        ['Theo','Rudolf','Kurt','Michael','Erwin','Karl','Gunther','Stefan','Adolf','Christian','Ludwig','Heinz','Harald','Timo','Helm','Hubert','Willi','Nick','Hans','Nico','Oswald','Hermann','Ernst','Andre','Jochen','Harry','Gerhard','Helmut','Josef','Paul','Fritz','Bernd','Ralf','Wolfgang','Rolf','Joachim','Adrian','Toni','Sebastian','Pascal','Volker','Manfred','Markus','Edgar'],
        ['Fitzau','Klodwig','Krause','Adolff','Ahrens','Bartels','Bauer','Bechem','Bellof','Brudes','Danner','Fischer','Frentzen','Glock','Glocker','Hahne','Heeks','Heidfeld','Helfrich','Herrmann','Heyer','Hulkenberg','Karch','Klenk','Kling','Krakau','Kuhnke','Lang','Loof','Lotterer','Mass','Merkel','Mitter','Niedermayr','Peters','Pietsch','Riess','Rosberg','Schneider','Schumacher','Seidel','Seiffert','Stommelen','Stuck','Sutil','von Trips','Ulmen','Vettel','Wehrlein','Weidler','Winkelhock','Barth'],[],[]],
    ['Finlnd','Fin',9,
        ['Valtteri','Mikka','Leo','Heikki','Mikko','Jyrki','Juhani','Kimi','Keke','Mika'],
        ['Bottas','Hakkinen','Kinnunen','Kovalainen','Kozarowitzky','Raikkonen','Rosberg','Salo'],[],[]],
    ['France','Fra',71,
        ['Bertrand','Jean','Philippe','Rene','Marcel','Elie','Paul','Pierre','Eric','Jules','Christophe','Sebastien','Francois','Bernard','Erik','Yannick','Patrick','Jose','Pascal','Yves','Aldo','Marc','Georges','Romain','Olivier','Andre','Max','Jacques','Franck','Gerard','Michel','Guy','Henri','Roger','Robert','Eugene','Esteban','Charles','Didier','Alain','Louis','Stephane','Jo','Johnny','Raymond','Mike','Maurice'],
        ['Gachot','Alesi','Alliot','Arnoux','Balsa','Bayol','Behra','Belmondo','Beltoise','Bernard','Bianchi','Boullion','Bourdais','Cevert','Chaboud','Collomb','Comas','Dalmas','Depailler','Dolhem','Etacelin','Fabre','Gaillard','Gasly','Giraud','Cabantous','Gordini','Gounon','Grignard','Grosjean','Grouillard','Guelfi','Hesnault','Jabouille','Jarier','Jean','Laffite','Lagorce','Larrousse','Leclere','Levegh','Ligier','Louveau','Loyer','Lucas','Lucienbonnet','Mairesse','Manzon','Martin','Mazet','Migault','Montagny','Ocon','Panis','Pescarolo','Pic','Picard','Pironi','Pollet','Pozzi','Prost','Raphanel','Rosier','Sarrazin','Schlesser','Servoz','Gavin','Simon','Sommer','Sparken','Streiff','Tambay','Trintignant','Vergne'],[],[]],
    ['Hungary','Hun',1,
        ['Zsolt'],
        ['Baumgartner'],[],[]],
    ['India','Ind',2,
        ['Karun','Narain'],
        ['Chandok','Karthikeyan'],[],[]],
    ['Indonesia','Ina',1,
        ['Rio'],
        ['Haryanto'],[],[]],
    ['Ireland','Irl',5,
        ['Tommy','Derek','Ralph','Joe','David'],
        ['Byrne','Daly','Firman','Kelly','Kennedy'],[],[]],
    ['Italy','Ita',99,
        ['Carlo','Andrea','Michele','Giovanna','Elio','Marco','Alberto','Luca','Giancarlo','Mauro','Lorenzo','Fabrizio','Paolo','Giorgo','Enrico','Clemente','Menato','Felice','Vittorio','Gianfranco','Gianmaria','Roberto','Guilio','Alex','Ivan','Piero','Eugenio','Franco','Corrado','Teo','Luigi','Nino','Maria','Teresa','Beppe','Nanni','Gerino','Piercarlo','Bruno','Antonio','Ignazio','Claudio','Nicola','Giovanni','Lamberto','Vitantonio','Lella','Umberto','Sergio','Pierluigi','Arturo','Stefano','Gianni','Gino','Alessandro','Massimo','Nello','Riccardo','Max','Cesare','Renato','Emanuele','Ernesto','Conslavo','Ludovico','Domenico','Dorino','Vincenzo','Gaetano','Siegfried','Gabriele','Jarno','Renzo'],
        ['Abate','de Adamich','Alboreto','Amati','de Angelis','Apicella','Ascari','Badoer','Baghetti','Baldi','Bandini','Barbazza','Barilla','Bassi','Bertaggia','Biondetti','Boffa','Bonetto','Brambilla','Brancatelli','Bruni','Bussinello','Cabianca','Caffi','Capelli','Carini','Castellotti','de Cesaris','Colombo','Comotti','Drogo','Dusio','Fabi','Facetti','Fagioli','Farina','de Filippis','Fisichella','Francia','Gabbiani','Galli','Gerini','Ghinzani','Giacomelli','Giovinazzi','Giunti','Langes','Larini','Lavaggi','Leoni','Lippi','Lombardi','Maglioli','Mantovani','Martini','Merzario','Modena','Montermini','Morbidelli','Munaron','Musso','Nannini','Naspetti','Natili','Pagani','Paletti','Pantano','Papis','Patrese','Perdisa','Pesenti','Rossi','Piotti','Pirocchi','Pirro','Prinoth','Riu','Rol','Sanesi','Scarfiotti','Scarlatti','Schiattarella','Scotti','Serafini','Sospiri','Starrabba','Stohr','Taramazzo','Tarquini','Taruffi','Trulli','Vaccarella','Villoresi','Zanardi','Zorzi'],[],[]],
    ['Japan','Jap',20,
        ['Hiroshi','Masahiro','Naoki','Kazuyoshi','Yuki','Taki','Kamui','Ukyo','Masami','Kazuki','Satoru','Shinji','Hideki','Takuma','Aguri','Toshio','Toranosuke','Noritake','Kunimitsu','Sakon'],
        ['Fushida','Hasemi','Hattori','Hoshino','Ide','Inoue','Katayama','Kobayashi','Kuwashima','Nakajima','Nakano','Noda','Sato','Suzuki','Takagi','Takahara','Takahashi','Yamamoto'],[],[]],
    ['Liechtenstein','Lic',1,
        ['Rikky'],
        ['von Opel'],[],[]],
    ['Malaysia','Mal',1,
        ['Alex'],
        ['Yoong'],[],[]],
    ['Mexico','Mex',6,
        ['Esteban','Sergio','Hector','Pedro','Ricardo','Moises'],
        ['Gutierrez','Perez','Rebaque','Rodriguez','Solana'],[],[]],
    ['Monaco','Mon',5,
        ['Olivier','Louis','Charles','Andre','Robert'],
        ['Beretta','Chiron','Leclerc','Testut','Doornbos'],[],[]],
    ['Morocco','Mor',1,
        ['Robert'],
        ['La Caze'],[],[]],
    ['Netherlands','Net',16,
        ['Robert','Chrisijan','Michael','Jan','Giedo','Carel','Boy','Gijs','Dries','Ben','Huub','Jos','Rob','Max','Roelof','Godin'],
        ['Doornbos','Albers','Bleekemolen','Flintermann','van der Garde','de Baufort','Hayje','Lammers','Lennep','van der Lof','Pon','Rothengatter','Slotemaker','Verstappen','Wunderink'],[],[]],
    ['New Zeland','NZ',9,
        ['Chris','Howden','Brendon','Denny','Bruce','Graham','John','Tony','Mike'],
        ['Amon','Ganley','Hartley','Hulme','McLaren','McRae','Nicholson','Shelly','Thackwell'],[],[]],
    ['Poland','Pol',1,
        ['Robert'],
        ['Kubica'],[],[]],
    ['Portugal','Por',5,
        ['Mario','Pedro','Tiago','Casimiro'],
        ['de Araujo','Cabral','Matos','Chaves','Lamy','Monteiro','De Oliveira'],[],[]],
    ['Rhodesia','Rho',5,
        ['John','Clive','Ray','Sam','Gary'],
       ['Love','Puzey','Reed','Tingle','Hocking'],[],[]],
    ['Russia','Rus',3,
        ['Daniil','Vitaly','Sergey'],
        ['Kvyat','Petrov','Sirotkin'],[],[]],
    ['South Africa','SA',23,
        ['Trevor','Luki','Dave','David','Paddy','William','Mike','Bruce','Eddie','Peter','Neville','Tony','Alex','Brausch','Ernie','Jackie','Basil','Ian','Jody','Doug','Guy','Syd','Desire'],
        ['Blignaut','Blokdyk','Botha','Charlton','Clapham','Driver','Ferguson','Harris','Johnstone','Keizan','de Klerk','Lederle','Maggs','Niemann','Pieterse','Pretorius','Rooyen','Scheckter','Serrurier','Tunmer','van der Vyver','Wilson'],[],[]],
    ['Spain','Spa',15,
        ['Jaime','Fernando','Adrian','Antonio','Marc','Paco','Juan','Roberto','Luis','Alfonso','Pedro','Carlos','Alex','Emilio'],
        ['Alonso','Algersuari','Campos','Creus','Gene','Godia','Jover','Mehri','Perez','Sala','de Portago','de la Rosa','Sainz','Soler','Roig','de Villota','Zapico'],[],[]],
    ['Sweden','Swe',10,
        ['Conny','Jo','Slim','Marcus','Stefan','Gunnar','Torsten','Ronnie','Bertil','Reine'],
        ['Andersson','Bonnier','Borgudd','Ericsson','Johansson','Nilsson','Palm','Peterson','Roos','Wisell'],[],[]],
    ['Switzerland','Swi',24,
        ['Toni','Sebastien','Andrea','Jean','Denis','Rudi','Gregor','Franco','Emmanuel','Peter','Loris','Michael','Silvio','Clay','Claude','Albert','Heinz','Rudolf','Jo','Marc','Max','Heini'],
        ['Branca','Buemi','Chiesa','Deletraz','Fischer','Foitek','Forini','de Graffenried','Hirt','Kessel','May','Monteverdi','Moser','Regazzoni','Rudaz','Scherrer','Schiller','Schoeller','Siffert','Surer','de Terra','Volonterio','Vonlanthen','Walter'],[],[]],
    ['Thailand','Tha',1,
        ['Birabongse'],
        ['Bhanudej'],[],[]],
    ['United Kingdom','UK',161,
        ['George','Kenny','Cliff','Bob','Peter','Ian','Gerry','Bill','Richard','Julian','John','Don','Derek','Mark','Eric','Tony','Chris','Alan','Martin','Ivor','Jenson','Colin','Max','Jim','David','Piers','Geoffrey','Anthony','Ken','Johnny','Geoff','Bernie','Guy','Vic','Jack','Ron','Philip','Joe','Divina','Dick','Horace','Keith','Brian','Mike','Bruce','Duncan','Lewis','Cuth','Damon','Graham','James','Innes','Eddie','Leslie','Rupert','Les','Jackie','Stuart','Damien','Nigel','Kenneth','Perry','Allan','Robin','Dave','Stirling','Tiff','Rodney','Arthur','Joylon','Jonathan','Reg','Tim','Dennis','Tom','Paul','Roy','Archie','Stephen','Will','Jimmy','Andy','Henry','Trevor','Desmond','Ted','Roger','Justin'],
        ['Abecassis','Acheson','Allison','Anderson','Arundell','Ashdown','Ashley','Ashmore','Aston','Attwood','Bailey','Barber','Beauman','Bell','Beuttler','Blundell','Brandon','Bridger','Brise','Bristow','Brooks','Brown','Brundle','Bueb','Burgess','Button','Campbell','Jones','Chapman','Chilton','Clark','Collins','Coulthard','Courage','Craft','Crawford','Crook','Crossley','Davidson','Davis','Donnelly','Downing','Dumfries','Duke','Ecclestone','Edwards','Elford','Emery','Evans','Fairman','Flockhart','Fotheringham','Parker','Fry','Galica','Gerard','Gethin','Gibson','Gould','Greene','Gubby','Hailwood','Halford','Hamilton','Hampshire','Harrison','Hart','Hawthorn','Henton','Herbert','Hill','Hobbs','Hunt','Ireland','Irvine','Irwin','James','Johnson','Keegan','Lawrence','Lees','Leston','Lewis','MacDowel','Macklin','Magee','Mansell','Marr','Marsh','McAlpine','McCarthy','McNish','Miles','Montgomerie','Charrington','Morgan','Moss','Murray','Naylor','Needell','Nuckey','Oliver','Owen','Palmer','Parkes','Parnell','Piper','Poore','Prophet','Pryce','Purley','Raby','Redman','Rees','di Resta','Rhodes','Richardson','Riseley','Prichard','Robarts','Rollinson','Rolt','Salvadori','Shawe','South','Spence','Stacey','Stevens','Stewart','Surtees','Sutcliffe','Taylor','Thompson','Thorne','Titterington','Trimmer','Walker','Warwick','Watson','Westbury','Wharton','Whiteaway','Whitehead','Whitehouse','Widdows','Wilds','Williams','Williamson','Wilson'],[],[]],
    ['United States','USA',158,
        ['Walt','Fred','George','Red','Mario','Michael','Keith','Frank','Chuck','Manny','Bobby','Henry','Skip','Tony','Art','Harry','Bob','Johnny','Don','Ronnie','Phil','Bill','Duane','Jay','Eddie','Joie','Kevin','Ray','Larry','Jimmy','Duke','Mark','Len','Ed','Mike','John','Pat','Myron','Carl','Gene','A.J.','Billy','Elmer','Richie','Paul','Cecil','Masten','Cliff','Dan','Jim','Sam','Mack','Al','Jackie','Jerry','Gus','Joe','Tom','Bruce','Danny','Jud','Bayliss','Andy','Pete','Brett','Herbert','Timmy','Ernie','Jack','Chet','Thomas','Cal','Robert','Johnnie','Roger','Dick','Lance','Peter','Mauri','Alexander','Lloyd','Troy','Rob','Hap','Carroll','Scott','Marshall','Shorty','Alfonso','Bud','Lee','Rodger','Spider','Wayne','Dempsey'],
        ['Ader','Agabashian','Amick','Andretti','Andrews','Armi','Arnold','Ayulo','Ball','Banks','Barber','Bettenhausen','Bisch','Blanchard','Boundurant','Boyd','Branson','Brown','Bryan','Bucknum','Cade','Cantrell','Carter','Chamberlain','Cheesbourg','Cheever','Chitwood','Christie','Cogan','Connor','Constantine','Crawford','Crockett','Cross','Daigh','Davies','Daywalt','Dinsmore','Dochnal','Donohue','Drake','Duncan','Edmunds','Elisian','Faulkner','Fischer','Fitch','Flaherty','Fohr','Follmer','Fonder','Forberg','Force','Foyt','Freeland','Gamble','Garrett','George','Ginther','Goldsmith','Green','Gregory','Griffith','Grim','Gurney','Hall','Hanks','Hansgen','Hartley','Hellings','Herman','Hill','Holland','Holmes','Homeier','Hoyt','Hurtubise','Hutchison','Jackson','James','Johnson','Jones','Keller','Kessler','Kladis','Larson','Levrett','Linden','Lovely','Lunger','MacKay','Fraser','Magill','Mantz','Mayer','McCoy','McDowell','McGrath','McWithey','Miller','Monarch','Nalon','Nazaruk','Niday','OBrien','OConnor','Ongais','Parsons','Penske','Posey','Rahal','Rathmann','Reece','Reventlow','Revson','Rigsby','Rose','Rossi','Ruby','Russo','Ruttman','Sachs','Said','Scarborough','Schell','Schindler','Schroeder','Scott','Settember','Sharp','Shelby','Speed','Stevenson','Sullivan','Sutton','Sweikert','Teague','Templeman','Thiele','Thompson','Tingelstad','Tolan','Turner','Unser','Veith','Vukovich','Wacker','Wallard','Ward','Webb','Weiler','Weyant','Wilson'],[],[]],
    ['Uruguay','Uru',4,
        ['Eitel','Asdrubal','Oscar','Alberto'],
        ['Cantoni','Fontes','Bayardo','Gonzalez','Uria'],[],[]],
    ['Venezuela','Ven',3,
        ['Johnny','Ettore','Pastor'],
        ['Cecotto','Chimeri','Maldonado'],[],[]],
    ['Slovakia','Svk',1,
        ['Frantisek','Adam','David','Michal'],
        ['Szcirka','Molnar','Feco','Gyuras'],[],[]]
    ]
abilityupdate=[4,4,4,4,4,4,3,3,3,3,3,2,2,2,2,1,1,1,0,0,-1,-2,-2,-3,-3,-3,-4,-4,-4,-4,-5,-5,-5,-5,-5,-6,-6]
year=1950
startyear=1950
phase=0
newdrivers=[]
pointsystem=[]
drivers=[]
tf=[True,False]
teams=[]
series=[]
manufac=[]
retired=[]
dx=[]
jd=[]
sd=[]
dy=[]
dy2=[]
nationalities=[]
teamresults=[]
natdrivers=[]
manresults=[]
wdcu20=[]
wdcu20nats=[]
dz=[]
seasonresults=[]
d='a\n'
dd=0
cdrivers=[]
cteams=[]
cseries=[]
abledrivers=0
ableteams=0
ableseris=0
date=0
datex=100
ss1=0
ss2=0
adate=0
fmdbids=[]
jhost=[]
f1y=1950
indyy=1935
fjy=1932
calendar=[]
###Drivers load
def loaddatabase(savefile):
    ss=savefile+'info.txt'
    with open (ss,'r') as f:
        nd=[]
        global year
        global startyear
        global phase
        global adate
        global datex
        global jd
        global sd
        global newdrivers
        
        startyear=int(f.readline())
        year=int(f.readline())
        x=int(f.readline())
        for i in range(x):
            nd.append(int(f.readline()))
            nd.append(int(f.readline()))
            newdrivers.append(nd)
            nd=[]
        phase=int(f.readline())
        datex=int(f.readline())
        adate=int(f.readline())
        
        if phase==1:
            jd=[[],[]]
            sd=[[],[]]
            d=int(f.readline())
            for i in range(d):
                jd[0].append(int(f.readline()))
            d=int(f.readline())
            for i in range(d):
                jd[1].append(int(f.readline()))
            d=int(f.readline())
            for i in range(d):
                sd[0].append(int(f.readline()))
            d=int(f.readline())
            for i in range(d):
                sd[1].append(int(f.readline()))
    ss=savefile+'drivers.txt'   
    with open (ss,'r') as f:      
        global dx
        global fl1
        dx=[]
        dy=[]
        dy2=[]
        dz=[]
        fl1=int(f.readline())
        for i in range (fl1):
            for j in range (3):
                d=(f.readline())
                d=d.strip()
                dx.append(d)
            for j in range (2):
                dd=int(f.readline())
                dx.append(dd)
            dx.append(year-dx[3])    
            d=f.readline()
            d=d.strip()           
            if d==('x'):
                dx.append('x')
            else:
                dx.append(int(d))
            d=f.readline()
            d=d.strip()
            if d==('x'):                
                for j in range (4):        
                    dx.append('x')
                dy=[False,'x','x','x']
            else:
                dx.append(int(d))
                for h in range (2):
                    dd=int(f.readline())
                    dx.append(dd)
                dd=f.readline()
                dd=dd.strip()
                if dd==('x'):
                    dx.append('x')
                else:
                    dx.append(int(dd))
                
                dy=[]
                d=f.readline()
                d=d.strip()
                if d=='False':
                    dy=[False,'x','x','x']
                else:
                    dy=[True]
                    dy.append(int(d))
                    for j in range(2):
                        dd=int(f.readline())
                        dy.append(dd)
                
            
            dx.append(dy)
            dy=[]
            dx.append(False)
            #History
            x=int(f.readline())
            dx.append(x)
            dz2=[]
            for j in range(x):
                dz2.append(int(f.readline()))
                x2=int(f.readline())
                
                for s in range(x2):
                    for h in range (5):
                        dd=int(f.readline())
                        dy.append(dd)
                    dy.append(99)
                    dy.insert(0,dz2[0]-dx[3])
                    d=f.readline()
                    d=d.strip()
                    if d=='False':
                        dy2=[False,'x','x','x']
                    else:
                        dy2=[True]
                        dy2.append(int(d))
                        for j in range(2):
                            dd=int(f.readline())
                            dy2.append(dd)
                    dy.append(dy2)
                    for h in range (2):                    
                        dd=int(f.readline())
                        dy.append(dd)
                    y=int(f.readline())
                    dy.append(y)
                    y2=int(f.readline())
                    dy.append(y2)
                    for g in range (y,y2+1):
                        dd=int(f.readline())
                        dy.append(dd)   
                    dz2.append(dy)
                    dy=[]
                dz.append(dz2)
                dz2=[]
                
            dx.append(dz)
            dz=[]
            d=f.readline()
            d=d.strip()
            if d == 'x':
                dy=['x','x','x','x']
            else:
                dd=int(d)
                dy.append(dd)
                dd=int(f.readline())
                dy.append(dd)
                d=f.readline()
                d=d.strip()
                if d == 'x':
                    dy.append(d)
                    dy.append(d)
                else:
                    dd=int(d)
                    dy.append(dd)
                    dd=int(f.readline())
                    dy.append(dd)
            dx.append(dy)
            drivers.append(dx)
            dx=[]
 
###Teams load
    ss=savefile+'teams.txt'  
    with open (ss,'r') as f:
        global fl2
        fl2=int(f.readline())
        dy=[]
        x=0
        dy2=[]
        dz=[]
        dy3=[]
        for i in range (fl2):         
            d=(f.readline())
            d=d.strip()
            dx.append(d)
            for j in range(3):
                dd=int(f.readline())
                dx.append(dd)
            dx.append(dx[3])
            for j in range(4):
                dy.append(dy3)
            dx.append(dy)
            dy=[]
            dd=(f.readline())
            dd=dd.strip()
            if dd=='x':
                pass
            else:
                dd=int(dd)
                for h in range(dd):
                    dy.append(int(f.readline()))
                    d=(f.readline())
                    d=d.strip()
                    if d=='x':
                        dy.append(False)
                    else:
                        dy.append(d)
                    for j in range(2):
                        dy.append(int(f.readline()))
                    for j in range(9):
                        d=(f.readline())
                        d=d.strip()
                        if d=='x':
                            dy.append(d)
                        else:
                            dy.append(int(d))
                    dy.append(int(f.readline()))
                    dy2.append(dy)
                    dy=[]
            dx.append(dy2)
            dy2=[]
            d=int(f.readline())
            for j in range (d):
                dy2.append(int(f.readline()) )
                dd=int(f.readline())
                for h in range(dd):
                    dz.append(int(f.readline()))
                    x=(f.readline())
                    x=x.strip()
                    if x=='x':
                        dz.append(False)
                    else:
                        dz.append(x)
                    for g1 in range(3):
                        dd=(f.readline())
                        if dd=='x':
                            dz.append(dd,dd,dd)
                        else:
                            dz.append(int(dd))
                            
                            for g in range(2):
                                dz.append(int(f.readline()))
                    for g in range(2):
                        dz.append(0)
                    dy2.append(dz)
                    dz=[]
                dy.append(dy2)
                dy2=[]
                
            dx.append(dy)
            dy=[]
            dx.append(False)
            
            x=(f.readline())
            x=x.strip()
            if x=='True':
                dx.append(True)
            if x=='False':
                dx.append(False)
            dx.append(0)
            teams.append(dx)
            
            dx=[]         
            dy=[]
            dy2=[]
            dz=[]
            
            

###Series
    ss=savefile+'series.txt'
    with open (ss,'r') as f:
        global fl3
        fl3=int(f.readline())
        dy=[]
        s=0
        t=0
        for i in range (fl3):
            for j in range(2):
                d=(f.readline())
                d=d.strip()
                dx.append(d)
            s=int(f.readline())
            dx.append(s)
            t=int(f.readline())
            dx.append(t)
            for j in range (4):
                dd=int(f.readline())
                dx.append(dd)
            dz=[]
            for j in range(s,t+1):
                dz.append(j)
                dd=int(f.readline())
                for h in range(dd):
                    d=(f.readline())
                    d=d.strip()
                    dz.append(d)
                    
                for i in range(3):
                    dz.append([])
                dy.append(dz)
                dz=[]
            dx.append(dy)
            dy=[]
            dx.append(0)
            dx.append(int(f.readline()))
            for h in range(3):
                d=int(f.readline())
                for j in range(d):
                    dz.append(int(f.readline()))
                dy.append(dz)
                dz=[]
            dx.append(dy)
            dy=[]          
            
            dx.append(False)
            dx.append([])
            dx.append([])
            dx.append([[],[],[]])
            d=int(f.readline())
            for j in range(d):
                for h in range(2):
                    dz.append(int(f.readline()))
                dy.append(dz)
                dz=[]
            dx.append(dy)
            dy=[]
            series.append(dx)
            dx=[]


###Manufac
    ss=savefile+'manufac.txt'
    with open (ss,'r') as f:
        global fle
        global flc
        global flp
        global flm
        fle=int(f.readline())
        flc=int(f.readline())
        flp=int(f.readline())
        flm=[fle,flc,flp]
        dx=[]
        dy=[]
        dz=[]
        dy2=[]
        dy3=[]
        for x in range (3):
            for i in range (flm[x]):
                d=(f.readline())
                d=d.strip()
                dy.append(d)
                dy.append([])
                dy.append([])
                x=int(f.readline())
                for h in range(x):
                    for i in range(3):
                        d=int(f.readline())
                        dz.append(d)
                    dz.append(False)
                    d=int(f.readline())
                    dz.append(d)
                    for j in range(d*2):
                        dz.append(int(f.readline()))
                    dy[1].append(dz)
                    dz=[]
                dx.append(dy)
                dy=[]
            manufac.append(dx)
            dx=[]
               
###Point system
    ss=savefile+'points.txt'
    with open (ss,'r') as f:
        d=int(f.readline())
        for i in range(d):
            dx=[]
            p=int(f.readline())
            for j in range(p):
                dx.append(int(f.readline()))
            pointsystem.append(dx)
            dx=[]
    age()
    pickdrivers()
    pickteams()
    pickman()
    pickseries()
    drihis()
    teamhis()
    manhis()
    picknations()
    natselect()
    mtos()
    if adate!=0:
        dtos()
    calendarmaker()

def drihis():
    years=[]
    for i in range(len(drivers)):
        for j in range(len(drivers[i][14])):
            for h in range(1,len(drivers[i][14][j])):
                drivers[i][14][j][h][6]=series[drivers[i][14][j][h][5]][7]
            years.append(drivers[i][14][j][0])
    x=[]
    y=len(years)
    for i in range (y-1):
        if years[i] == years[i+1] :
            x.append(years[i])
    for i in (x):
        years.remove(i)
    tins=[]
    for i in range(len(years)):
        i2=years[i]
        for s in range(len(series)):
            tins=[]
            for t in range(len(drivers)):
                for r in range(len(drivers[t][14])):
                    for p in range(1,len(drivers[t][14][r])):
                        if drivers[t][14][r][0]== i2 and drivers[t][14][r][p][5]==s:
                                tins.append([t,r,j,drivers[t][14][r][p][9]])
            for h in range(1,len(tins)):
                value=tins[h]
                x=tins[h][3]
                k=h-1
                while k>=0:
                    if x<tins[k][3]:                  
                        tins[k+1]=tins[k]
                        tins[k]=value
                        k=k-1
                    else:
                        break
            tirs=[]
            for r in range(len(tins)):
                tirs.append(tins[r][0])
            for r in range(len(series[s][8])):
                if series[s][8][r][0]==i2:                 
                        series[s][8][r][-3]=tirs
                
def teamhis():
    dx=[]
    years=[]
    for t in range(len(teams)):       
        for i in range(len(drivers)):
            for j in range(len(drivers[i][14])):
                for h in range(1,len(drivers[i][14][j])):
                    if drivers[i][14][j][h][2]==t and drivers[i][14][j][h][7][0]==False:
                        dx.append([drivers[i][14][j][0],i,drivers[i][14][j][h][5],drivers[i][14][j][h][8]])
                    if drivers[i][14][j][h][7][0]==True and drivers[i][14][j][h][7][1]==t:
                        dx.append([drivers[i][14][j][0],i,drivers[i][14][j][h][5],drivers[i][14][j][h][8]])
        dy=[]
        for j in range(len(teams[t][7])):
            for s in range(1,len(teams[t][7][j])):
                teams[t][7][j][s].append([])
                for i in range(len(dx)):               
                    if teams[t][7][j][0]==dx[i][0] and teams[t][7][j][s][0]==dx[i][2]:
                        teams[t][7][j][s][13].append(dx[i][1])
                        dy.append(i)
                x=0
                for i in (dy):
                    x=x+dx[i][3]
                x=x//series[dx[i][2]][4]
                teams[t][7][j][s].append(x)
                dy=[]
        for i in range(len(dx)):
            years.append(dx[i][0])
        dx=[]
    years.sort()
    x=[]

    y=len(years)
    for i in range (y-1):
        if years[i] == years[i+1] :
            x.append(years[i])
    for i in (x):
        years.remove(i)
    tins=[]
    for i in range(len(years)):
        i2=years[i]
        for s in range(len(series)):
            tins=[]
            for t in range(len(teams)):
                for r in range(len(teams[t][7])):
                    for j in range(1,len(teams[t][7][r])):
                        if teams[t][7][r][j][0]== s and teams[t][7][r][0]==i2:
                            tins.append([t,r,j,teams[t][7][r][j][14]])
            
            for h in range(1,len(tins)):
                value=tins[h]
                x=tins[h][3]
                k=h-1
                while k>=0:
                    if x>tins[k][3]:                  
                        tins[k+1]=tins[k]
                        tins[k]=value
                        k=k-1
                    else:
                        break
            tirs=[]
            for r in range(len(tins)):
                tirs.append(tins[r][0])
            for h in range(len(tins)):
                t1=tins[h][0]
                i1=tins[h][1]
                j1=tins[h][2]
                h1=h+1
                teams[t1][7][i1][j1].append(h1)
                teamresults.append([s,tins])
            for r in range(len(series[s][8])):
                if series[s][8][r][0]==i2:                 
                        series[s][8][r][-2]=tirs
            

def manhis():
    years=[]
    for m in range(3):
        for i in range(len(manufac[m])):
            for r in range(len(manufac[m][i][1])):
                for j in range(manufac[m][i][1][r][4]):
                    for y in range(manufac[m][i][1][r][j*2+5],manufac[m][i][1][r][j*2+6]+1):
                        x=len(manufac[m][i][2])
                        if x==0:
                            manufac[m][i][2].append([y,[manufac[m][i][1][r][0],[],[],0]])
                        else:
                            xx=False
                            if y>year:
                                xx=True
                            else:
                                for h in range(x):
                                    if y==manufac[m][i][2][h][0]:
                                        xx=True
                                        manufac[m][i][2][h].append([manufac[m][i][1][r][0],[],[],0])
                            if xx==False:
                                manufac[m][i][2].append([y,[manufac[m][i][1][r][0],[],[],0]])                                
            manufac[m][i][2].sort()        
            for r in range(len(manufac[m][i][2])):
                years.append(manufac[m][i][2][r][0])
                for j in range(1,len(manufac[m][i][2][r])):
                    for t in range(len(teams)):
                        for h in range(len(teams[t][7])):
                            for s in range(1,len(teams[t][7][h])):
                                if manufac[m][i][2][r][0]==teams[t][7][h][0] and manufac[m][i][2][r][j][0]==teams[t][7][h][s][0] and i==teams[t][7][h][s][2+3*m]:
                                    manufac[m][i][2][r][j][1].append(t)
                                    for d in range(len(teams[t][7][h][s][13])):
                                        manufac[m][i][2][r][j][2].append(teams[t][7][h][s][13][d])
                    for s in range(len(series)):
                        for y in range(len (series[s][8])):
                            if manufac[m][i][2][r][0]==series[s][8][y][0] and manufac[m][i][2][r][j][0]==s:
                                dx=[]
                                if year == series[s][8][y][0]:
                                    x3=adate
                                else:
                                    x3=len(series[s][8][y])-4
                                for l in range(x3):
                                    x=[]
                                    for d in range(len(manufac[m][i][2][r][j][2])):
                                        for h in range(len(drivers[manufac[m][i][2][r][j][2][d]][14])):
                                            for h2 in range(1,len(drivers[manufac[m][i][2][r][j][2][d]][14][h])):
                                                if drivers[manufac[m][i][2][r][j][2][d]][14][h][0]==manufac[m][i][2][r][0]:                                                                                
                                                    yy=False
                                                    for xx in range(len(x)):                                     
                                                        if x[xx]==drivers[manufac[m][i][2][r][j][2][d]][14][h][h2][12+l]:
                                                            yy=True             
                                                    if (len(x)==0 or yy==False) and len(drivers[manufac[m][i][2][r][j][2][d]][14][h][h2])-12>l:
                                                        x.append(drivers[manufac[m][i][2][r][j][2][d]][14][h][h2][12+l])
                                                        x.sort()                       
                                                if len (x)>series[s][6]:
                                                    y=x[-1]
                                                    x.remove(y)
                                    if len(x)==0:
                                        x=[0,0]
                                    dx.append(x)
                                points=0
                                for h in range(len(series[s][16])):
                                    if series[s][16][h][0] <= manufac[m][i][2][r][0]:
                                        y=series[s][16][h][1]
                                for h in range(len(dx)):
                                    for l1 in range(len(dx[h])):
                                        for p in range(len(pointsystem[y])):
                                            if dx[h][l1]==p+1:
                                                points=pointsystem[y][p]+points
                                manufac[m][i][2][r][j][3]=points        



    years.sort()
    x=[]

    y=len(years)
    for i in range (y-1):
        if years[i] == years[i+1] :
            x.append(years[i])
    for i in (x):
        years.remove(i)
    mans=[]
    for i in range(len(years)):
        i2=years[i]
        for s in range(len(series)):
            for e in range(3):
                mans=[]
                for m in range(len(manufac[e])):
                    for ii in range(len(manufac[e][m][2])):
                        if manufac[e][m][2][ii][0]==i2:
                            for j in range(1,len(manufac[e][m][2][ii])):
                                if manufac[e][m][2][ii][j][0]== s and len(manufac[e][m][2][ii][j][2])>0:
                                    mans.append([m,ii,j,manufac[e][m][2][ii][j][3]])
            
                for h in range(1,len(mans)):
                    value=mans[h]
                    x=mans[h][3]
                    k=h-1
                    while k>=0:
                        if x>mans[k][3]:                  
                            mans[k+1]=mans[k]
                            mans[k]=value
                            k=k-1
                        else:
                            break
                manyresults=[]
                for h in range(len(mans)):
                    m1=mans[h][0]
                    i1=mans[h][1]
                    j1=mans[h][2]
                    manufac[e][m1][2][i1][j1].append(h+1)
                    manyresults.append(m1)
                manresults.append([s,mans])
                for r in range(len(series[s][8])):
                    if series[s][8][r][0]==i2:
                       series[s][8][r][-1].append(manyresults)
    for e in range(3):
        for m in range(len(manufac[e])):
            ff=[]
            for i in range(len(manufac[e][m][2])):
                if manufac[e][m][2][i][0]>year:
                    ff.append(manufac[e][m][2][i])
            for i in range(len(ff)):
                manufac[e][m][2].remove(ff[i])
                    

def draftlottery():
    global sd
    global jd
    global phase
    dz=[]
    jd=[[],[]]
    sd=[[],[]]
    dz2=[]
    dx2=[]
    dx=[]
    dy=[]
##Vyberhracov
    for i in range(len(drivers)):
        if drivers[i][5]==15:
            dy.append(i)
        
    
    jd[0]=dy
    y1=len(dy)
    d=1
##vyber timov

    for i in range(len(series[3][13])):
        dz.append(d)
        d=d*2
    dz2=(series[3][13])
    y2=len(dz2)
    if y1<y2:
        y2=y1
    for i in (dz2):

        for j in range(len(teams[i][7])):
            for h in range(1,len(teams[i][7][j])):
                if teams[i][7][j][h][0]==3:
                    d=teams[i][7][j][h][-1]
                    dx2.append(dz[d-1])
        if len(teams[i][7])<1:
            dx2.append(1)
    for i in range(1,len(dz2)):
        value=dx2[i]
        x=dx2[i]
        val=dz2[i]
        j=i-1
        while j>=0:
            if x<dx2[j]:                  
                dx2[j+1]=dx2[j]
                dx2[j]=value
                dz2[j+1]=dz2[j]
                dz2[j]=val
                j=j-1
            else:
                break
    if len (dz2)<len(dy):
        x=len(dz2)
    else:
        x=len(dy)
    for i in range(x):
        jd[1].append(dz2[i])
    phase=1
    
def draft():
    global phase

    for i in range(len(jd[1])):
        if teams[jd[1][i]][9]==True:
            x=int(input(teams[jd[1][i]][0],'Which do you want?'))
            for j in range(len(jd[0])):                
                if x == jd[0][j]:
                    drivers[jd[0][j]][6]=jd[1][i]
            jd[0].remove(d)
            teams[jd[1][i]][5][0].append(d)
                
        if teams[jd[1][i]][9]==False:
            x=35
            d=abledrivers
            for j in range(len(jd[0])): 
                if drivers[jd[0][j]][4]>x:
                    x=drivers[jd[0][j]][4]                   
                    d=jd[0][j]
            drivers[d][6]=jd[1][i]
            drivers[d][7]=jd[1][i]
            drivers[d][9]=3
            if drivers[d][9]<44:
                drivers[d][8]=1
            else:
                drivers[d][8]=2
            jd[0].remove(d)
            teams[jd[1][i]][5][0].append(d)

    
    pickseries()
    pickteams()
    phase=0

def age():
    for i in range (len(drivers)):
        drivers[i][5]=(year-drivers[i][3])
    
def pickdrivers():
    global abledrivers
    global cdrivers
    global retired
    cdrivers=[]
    abledrivers=0
    retired=[]
    for i in range(len(drivers)):
        if ((drivers[i][5]) >= 15) and ((drivers[i][4]) >= 36):
            drivers[i][12]=True
            abledrivers=abledrivers+1
            cdrivers.append(i)
        else:
            if drivers[i][12]==True:
                retired.append(i)
            drivers[i][12]=False
    

def pickteams():
    global ableteams
    global cteams
    cteams=[]
    dy=[]
    ableteams=0
    
    for i in range(len(teams)):
        teams[i][8]=False
        if ((teams[i][1]) <= year):
            teams[i][8]=True
            ableteams=ableteams+1
            cteams.append(i)
            
            
                
    for q in (cteams):
        if len(teams[q][6])>0:
            a=100
            for s in range(len(teams[q][6])):
                if series[teams[q][6][s][0]][7]<a and teams[q][6][s][2]<=year:
                    a=series[teams[q][6][s][0]][7]
        teams[q][10]=a
        for i in (cdrivers):
            if drivers[i][6]==q and drivers[i][7]!=q:
                dy.append(i)
        teams[q][5][0]=dy
        dy=[]
        for i in (cdrivers):
            if drivers[i][7]==q and drivers[i][11][0]==False:
                dy.append(i)
        teams[q][5][1]=dy
        dy=[]
        for i in (cdrivers):
            if drivers[i][7]==q and drivers[i][11][0]==True:
                dy.append(i)
        teams[q][5][2]=dy
        dy=[]
        for i in (cdrivers):
            if drivers[i][11][1]==q:
                dy.append(i)
        teams[q][5][3]=dy
        dy=[]
    for i in range(fl2):
        x=0
        for q in range(len(teams[i][6])-1,-1,-1):
            if teams[i][6][q][3]< year :
                ab=teams[i][6][q]
                teams[i][6].remove(ab)
        for d in (teams[i][5][1]):
            x=x+drivers[d][8]
        for d in (teams[i][5][2]):
            if drivers[d][11][3]==i:
               x=x+drivers[d][8]
        for d in (teams[i][5][3]):
            if drivers[d][11][3]==i:
               x=x+drivers[d][8]
        for s in range(len(teams[i][6])):           
            for e in range(6,13,3):
                if teams[i][6][s][e]!='x':
                    x=x+teams[i][6][s][e]*teams[i][6][s][13]
        if teams[i][9]==False:
            teams[i][3]=x
        teams[i][4]=teams[i][3]-x
        
        
def pickseries():
    global ableseries
    global cseries
    global date
    global series
    cseries=[]
    
    ableseries=0
    for i in range(fl3):
        series[i][12]=False
        series[i][9]=0
        if ((series[i][2]) <= year) and series[i][3]>=year:
            series[i][12]=True
            ableseries=ableseries+1
            cseries.append(i)
    date=0
    for i in (cseries):
        
        for j in range(len(series[i][8])):
            if series[i][8][j][0]==year:
                x=len(series[i][8][j])-4
                series[i][9]=x
                if x>date:
                    date=x
        dx=[]
        for t in range(len(teams)):
            for j in range(len(teams[t][6])):

                if teams[t][6][j][0]==i and teams[t][6][j][2]<=year and teams[t][6][j][3]>=year:
                    dx.append(t)
        series[i][13]=dx

    for h in range(1,len(cseries)):
        value=cseries[h]
        x=series[cseries[h]][7]
        k=h-1
        while k>=0:
            if x<series[cseries[k]][7]:                  
                cseries[k+1]=cseries[k]
                cseries[k]=value
                k=k-1
            else:
                break

def pickman():
    for e in range(3):
        for m in range(len(manufac[e])):
            for s in range(len(manufac[e][m][1])):
                manufac[e][m][1][s][3]=False
                for h in range(manufac[e][m][1][s][4]):
                    for y in range(manufac[e][m][1][s][h*2+5],manufac[e][m][1][s][h*2+6]+1):
                        if y==year:
                            
                            if manufac[e][m][1][s][1]==0:
                                x1=0
                                x2=0
                                for m2 in(series[manufac[e][m][1][s][0]][15][e]):
                                    for s2 in range(len(manufac[e][m2][1])):
                                        if manufac[e][m2][1][s2][0]==manufac[e][m][1][s][0]:         
                                            if x1==0 and x2==0 and manufac[e][m2][1][s2][1]!=0:
                                                x1=manufac[e][m2][1][s2][1]
                                                x2=manufac[e][m2][1][s2][1]
                                            elif manufac[e][m2][1][s2][1]!=0:
                                                if manufac[e][m2][1][s2][1]>x1:
                                                    x1=manufac[e][m2][1][s2][1]
                                                if manufac[e][m2][1][s2][1]<x2:
                                                    x2=manufac[e][m2][1][s2][1]
                                if x2<x1*0.9:
                                    manufac[e][m][1][s][1]=random.randrange(x2,x1+1)
                                else:
                                    x2=int(x1*0.9)
                                    manufac[e][m][1][s][1]=random.randrange(x2,x1+1)
                            manufac[e][m][1][s][3]=True
                if  manufac[e][m][1][s][3]==False:
                    manufac[e][m][1][s][2]=1
                    manufac[e][m][1][s][1]=0
def natselect():
    global natdrivers
    global wdcu20
    global wdcu20nats
    wdcu20=[]
    natdrivers=[]
    wdcu20nats=[]
    dx=[]
    dy=[]
    d=999999
    for j in range(len(nationalities)):
        for i in range(len(drivers)):
            if drivers[i][2]==nationalities[j] :
                dx.append(i)
                if drivers[i][5]<=20 and drivers[i][5]>=15:
                    dy.append(i)
        d=dx[0]
        for i in (dx):
            if drivers[d][4]<drivers[i][4]:
                d=i
            if drivers[d][4]==drivers[i][4]:
                if drivers[d][5]>drivers[i][5]:
                    d=i
        natdrivers.append(d)
        if len(dy)>0:
            d=dy[0]
            for i in (dy):
                if drivers[d][4]<drivers[i][4]:
                    d=i
                if drivers[d][4]==drivers[i][4]:
                    if drivers[d][5]>drivers[i][5]:
                        d=i
            wdcu20.append(d)
            wdcu20nats.append(drivers[d][2])
        dy=[]
        dx=[]
    
def picknations():
    global nationalities
    nationalities=[]
    x=[]
    for i in (cdrivers):
        nationalities.append(drivers[i][2])
    nationalities.sort()
    for i in range (len(cdrivers)-1):
        if nationalities[i] == nationalities[i+1] :
            x.append(nationalities[i])
    for i in (x):
        nationalities.remove(i)
        
def teamstoseries():
    for i in (cteams):
        if teams[i][6] != [] :
            teams[i][7].append(teams[i][6])
            teams[i][6]=[year]
        for j in (cseries):
            dx=[j]
            r=random.choice(tf)
            if r == True :
                teams[i][6].append(r)

def reability():
    dx=[]
    for h in range(0,37,3):
        for i in (seasonresults):
            if drivers[i][5]==h+15 or drivers[i][5]==h+16 or drivers[i][5]==h+17:                
                dx.append(i)
        x=len(dx)//3
        y=len(dx)//3
        z=len(dx)//3
        if len(dx)-(len(dx)//3*3)==2:
            x=x+1
            z=z+1
        if len(dx)-(len(dx)//3*3)==1:
            y=y+1
        for i in range(x):
            if drivers[dx[i]][5]==h+15:
                drivers[dx[i]][4]=drivers[dx[i]][4]+abilityupdate[h]
            if drivers[dx[i]][5]==h+16:
                drivers[dx[i]][4]=drivers[dx[i]][4]+abilityupdate[h+1]
            if drivers[dx[i]][5]==h+17:
                drivers[dx[i]][4]=drivers[dx[i]][4]+abilityupdate[h+2]
        for i in range(x,x+y):
            if drivers[dx[i]][5]==h+15:
                drivers[dx[i]][4]=drivers[dx[i]][4]+abilityupdate[h]-1
            if drivers[dx[i]][5]==h+16:
                drivers[dx[i]][4]=drivers[dx[i]][4]+abilityupdate[h+1]-1
            if drivers[dx[i]][5]==h+17:
                drivers[dx[i]][4]=drivers[dx[i]][4]+abilityupdate[h+2]-1
        for i in range(x+y,x+y+z):
            if drivers[dx[i]][5]==h+15:
                drivers[dx[i]][4]=drivers[dx[i]][4]+abilityupdate[h]-2
            if drivers[dx[i]][5]==h+16:
                drivers[dx[i]][4]=drivers[dx[i]][4]+abilityupdate[h+1]-2
            if drivers[dx[i]][5]==h+17:
                drivers[dx[i]][4]=drivers[dx[i]][4]+abilityupdate[h+2]-2
        dx=[]

def manreability():
    manresults=[]
    for s in (cseries):
        for e in range(3):
            mans=[]
            for m in range(len(manufac[e])):
                for i in range(len(manufac[e][m][2])):
                    for j in range(1,len(manufac[e][m][2][i])):
                        dri=len(manufac[e][m][2][i][j][2])
                        if manufac[e][m][2][i][j][0]== s and manufac[e][m][2][i][0]==year and dri>0:
                            mans.append([m,i,j,manufac[e][m][2][i][j][4]])
                        if dri==0:
                            if e==0:
                                x1=random.randrange(5)
                            else:
                                x1=random.randrange(4)
                            for j1 in range(len(manufac[e][m][1])):
                                if manufac[e][m][1][j1][0]==s:
                                    manufac[e][m][1][j1][2]=1
                                    manufac[e][m][1][j1][1]=manufac[e][m][1][j1][1]+x1
            
            for h in range(1,len(mans)):
                value=mans[h]
                x=mans[h][3]
                k=h-1
                while k>=0:
                    if x<mans[k][3]:                  
                        mans[k+1]=mans[k]
                        mans[k]=value
                        k=k-1
                    else:
                        break
            for h in range(len(mans)):
                m1=mans[h][0]
                i1=mans[h][1]
                j1=mans[h][2]
            if mans != []:
                manresults=mans
            mans=[]         
            xx=len(manresults)//3
            x=xx
            y=xx
            z=xx
            if len(manresults)-(xx*3)==1:
                y=y+1
            if len(manresults)-(xx*3)==2:
                x=x+1
                z=z+1
            ###podla vysledkov
        
            for h in range(x):
                if e==0:
                    #x1=random.randrange(3)
                    x1=random.randrange(5)
                    for j in range(len(manufac[e][manresults[h][0]][1])):
                        if manufac[e][manresults[h][0]][1][j][0]==s:
                            manufac[e][manresults[h][0]][1][j][2]=3
                            manufac[e][manresults[h][0]][1][j][1]=manufac[e][manresults[h][0]][1][j][1]+x1                            
                else:
                    #x1=random.randrange(2)
                    x1=random.randrange(4)
                    for j in range(len(manufac[e][manresults[h][0]][1])):
                        if manufac[e][manresults[h][0]][1][j][0]==s:
                            manufac[e][manresults[h][0]][1][j][2]=3
                            manufac[e][manresults[h][0]][1][j][1]=manufac[e][manresults[h][0]][1][j][1]+x1
            for h in range(x,x+y):              
                if e==0:
                    #x1=random.randrange(4)
                    x1=random.randrange(5)
                    for j in range(len(manufac[e][manresults[h][0]][1])):
                        if manufac[e][manresults[h][0]][1][j][0]==s:
                            manufac[e][manresults[h][0]][1][j][2]=2
                            manufac[e][manresults[h][0]][1][j][1]=manufac[e][manresults[h][0]][1][j][1]+x1
                else:
                    #x1=random.randrange(3)
                    x1=random.randrange(4)
                    for j in range(len(manufac[e][manresults[h][0]][1])):
                        if manufac[e][manresults[h][0]][1][j][0]==s:
                            manufac[e][manresults[h][0]][1][j][2]=2
                            manufac[e][manresults[h][0]][1][j][1]=manufac[e][manresults[h][0]][1][j][1]+x1
            for h in range(x+y,x+y+z):       
                if e==0:
                    x1=random.randrange(5)
                    for j in range(len(manufac[e][manresults[h][0]][1])):
                        if manufac[e][manresults[h][0]][1][j][0]==s:
                            manufac[e][manresults[h][0]][1][j][2]=1
                            manufac[e][manresults[h][0]][1][j][1]=manufac[e][manresults[h][0]][1][j][1]+x1
                else:
                    x1=random.randrange(4)
                    for j in range(len(manufac[e][manresults[h][0]][1])):
                        if manufac[e][manresults[h][0]][1][j][0]==s:
                            manufac[e][manresults[h][0]][1][j][2]=1
                            manufac[e][manresults[h][0]][1][j][1]=manufac[e][manresults[h][0]][1][j][1]+x1
             #manresults=[]
 
def seasonr():
    global seasonresults
    seasonresults=[]
    dx=[]
    for i in (cdrivers):
        seasonresults.append(i)
    dx=[]
    dx=seasonresults
        
# Vek
    for i in range(1,len(seasonresults)):
        value=seasonresults[i]
        x=drivers[seasonresults[i]][5]
        j=i-1
        while j>=0:
            if x<drivers[seasonresults[j]][5]:                  
                dx[j+1]=dx[j]
                dx[j]=value
                j=j-1
            else:
                break
#Poziciavsampionate
    for p in range(30,0,-1):
        for i in range(1,len(seasonresults)):
            value=seasonresults[i]
            for h in range(1,len(drivers[seasonresults[i]][14][-1])):
                x=drivers[seasonresults[i]][14][-1][h][12:-1].count(p)
                j=i-1
            while j>=0:
                if x<drivers[seasonresults[j]][14][-1][h][12:-1].count(p):                  
                    dx[j+1]=dx[j]
                    dx[j]=value
                    j=j-1
                else:
                    break
#Pozicia
    for i in range(1,len(seasonresults)):
        value=seasonresults[i]
        for h in range(1,len(drivers[seasonresults[i]][14][-1])):
            x=drivers[seasonresults[i]][14][-1][h][9]
            j=i-1
        while j>=0:
            if x<drivers[seasonresults[j]][14][-1][h][9]:                  
                dx[j+1]=dx[j]
                dx[j]=value
                j=j-1
            else:
                break
#Tier
    for i in range(1,len(seasonresults)):
        value=seasonresults[i]
        for h in range(1,len(drivers[seasonresults[i]][14][-1])):
            x=drivers[seasonresults[i]][14][-1][h][6]
            j=i-1
        while j>=0:
            if x<drivers[seasonresults[j]][14][-1][h][6]:                  
                dx[j+1]=dx[j]
                dx[j]=value
                j=j-1
            else:
                break
    reability()

def conlenghts():
    pickman()
    for i in (cdrivers):
        drivers[i][9]=drivers[i][9]-1
        
        if drivers[i][11][0]==True:
            drivers[i][11][2]=drivers[i][11][2]-1
        if drivers[i][11][2]==0:
            drivers[i][11]=[False,'x','x','x']
        aa=0
        for f in range(len(teams[drivers[i][7]][6])):
            if teams[drivers[i][7]][6][f][2]<=year and teams[drivers[i][7]][6][f][3]>=year:
                aa=aa+1
        if drivers[i][9]<1 or aa==0:
            if teams[drivers[i][6]][10]==1 and teams[drivers[i][6]][9]==True:
                drivers[i][7]='x'
                drivers[i][8]='x'
                drivers[i][9]='x'
            else:
                drivers[i][6]='x'
                drivers[i][7]='x'
                drivers[i][8]='x'
                drivers[i][9]='x'
        drivers[i][10]='x'
    for t in range(len(teams)):
        for s in range(len(teams[t][6])):
            for e in range(3):
                teams[t][6][s][5+e*3]=teams[t][6][s][5+e*3]-1
                if teams[t][6][s][5+e*3]<1:
                    teams[t][6][s][4+e*3]='x'
                    teams[t][6][s][5+e*3]=0
                    teams[t][6][s][6+e*3]=0
                else:
                    m=teams[t][6][s][4+e*3]
                    for i in range(len(manufac[e][m][1])):
                        
                        if manufac[e][m][1][i][0]==teams[t][6][s][0] and manufac[e][m][1][i][3]==False:
                 
                            teams[t][6][s][4+e*3]='x'
                            teams[t][6][s][5+e*3]=0
                            teams[t][6][s][6+e*3]=0
               

def reteammoney():
    pickteams()
    for t in range(len(teams)):
        for j in range(len(teams[t][6])):
            if teams[t][6][j][2]<=year and teams[t][6][j][3]>=year:
                teams[t][4]=teams[t][4]+series[teams[t][6][j][0]][10]
            teams[t][6][j][13]=series[teams[t][6][j][0]][5]
        if len(teams[t][7])>0 and teams[t][7][-1][0]==year-1:
            x=0
            for j in range(1,len(teams[t][7][-1])):
                y=0
                for d in (teams[t][7][-1][j][13]):
                    for h in range(1,len(drivers[d][14][-1])):
                        for r in range (drivers[d][14][-1][h][10],drivers[d][14][-1][h][11]+1):
                            if drivers[d][14][-1][h][r+11]==1:
                                y=y+2
                            if drivers[d][14][-1][h][r+11]==2 or drivers[d][14][-1][h][r+11]==3:
                                y=y+1
                y=y//series[teams[t][7][-1][j][0]][4]
                x=x+y
            teams[t][4]=teams[t][4]+x
        teams[t][3]=teams[t][4]
        
def ownsasi():
    for t in (cteams):
        for s in range(len(teams[t][6])):
            s1=teams[t][6][s][0]
            for e in range(3):
                if teams[t][6][s][4+e*3]=='x':
                    for m in (series[s1][15][e]):
                        if teams[t][0]==manufac[e][m][0] :
                            for i in range(len(manufac[e][m][1])):
                                if manufac[e][m][1][i][0]==s1 and manufac[e][m][1][i][3]==True:
                                    teams[t][6][s][4+e*3]=m
                                    teams[t][6][s][5+e*3]=1
                                    teams[t][6][s][6+e*3]=1
                                    break
                        
def host(driv,tot,long,whop):
    drivers[driv][11][0]=True
    drivers[driv][11][1]=tot
    drivers[driv][11][2]=long
    drivers[driv][11][3]=whop
suciastky=[]#[seria, suciastka, vyrobca, dlzka]
sux=0
suf=2

def f1manresign(t):
    global suciastky
    global sux
    global suf
    sux=0
    suf=2
    suciastky=[]
    pickseries()
    mmm=['Engine','Chassi','Pneu']
    for s in range(len(teams[t][6])):
        s1=teams[t][6][s][0]
        printmprice(s1) 
        for e in range(3):
            if (teams[t][6][s][4+e*3]=='x' or teams[t][6][s][5+e*3]<1) and year>=teams[t][6][s][2] and year<=teams[t][6][s][3]:
                for m in (series[s1][15][e]):
                    if teams[t][0]==manufac[e][m][0]:
                        for s2 in range(len(manufac[e][m][1])):
                            if manufac[e][m][1][s2][0]==s1 and manufac[e][m][1][s2][3]==True:
                    
                                teams[t][6][s][4+e*3]=m
                                teams[t][6][s][5+e*3]=1
                                teams[t][6][s][6+e*3]=1
                                break
                else:
                    suciastky.append([teams[t][6][s][0],e,'x','x'])

    pickteams()

def f1mant():
    for i in range(len(suciastky)):
        if suciastky[i][0]==0:
            s=0
            s1=0
        else:
            s=1
            s1=2
        e=suciastky[i][1]
        x=suciastky[i][2]
        teams[0][6][s][4+e*3]=x
        teams[0][6][s][5+e*3]=suciastky[i][3]
        print(manufac[e][x][1])
        for s1 in range(len(manufac[e][x][1])):
            if manufac[e][x][1][s1][0]==teams[0][6][s][0]:
                teams[0][6][s][6+e*3]=manufac[e][x][1][s1][2]
fdrivers=[]
otry=0
drp=0
drx=0
def f1resign(t):
    global frivers
    global drx
    drx=0
    fdrivers=[]      

    for d in(teams[t][5][0]):          
        if drivers[d][7]!=t:
            right=False
            fdrivers.append(d)

def f1offer(d,x):
    global otry
    global drx
    global drp
    dp=(drivers[d][4]-28)//8
    if x>=dp and teams[0][4]>=x:
        drivers[d][6]=0
        drivers[d][7]=0
        drivers[d][8]=x
        #otry=0
        drx=1
        pickteams()
        
    #else:
        #otry=otry+1
    #if otry>1:
        #drivers[d][6]='x'
        #otry=0
        #drp=drp+1
    pickmtdb()
    
def f1ol(d,x):
    global drx
    global drp
    drivers[d][9]=x
    drx=0
    drp=drp+1
    pickmtdb()
def dbx():
    global otry
    global drp
    d=frivers[drp]
    drivers[d][6]='x'
    otry=0
    drp=drp+1
    
def db1():
    d=int(g.get())
    if drx==0:
        f1offer(d,1)
    else:
        f1ol(d,1)

def db2():
    d=int(g.get())
    if drx==0:
        f1offer(d,2)
    else:
        f1ol(d,2)

def db3():
    d=int(g.get())
    if drx==0:
        f1offer(d,3)
    else:
        f1ol(d,3)

def db4():
    d=int(g.get())
    if drx==0:
        f1offer(d,4)
    else:
        f1ol(d,4)

def db5():
    d=int(g.get())
    f1offer(d,5)


def db6():
    d=int(g.get())
    f1offer(d,6)

def db7():
    d=int(g.get())
    f1offer(d,7)

def db8():
    d=int(g.get())
    f1offer(d,8)


def pickmtdb():
    global drx
    #if len(fdrivers)<1 or drp==len(fdrivers):
        #drx=2
    if year>1949:
        printfm(0)
    else:
        printfm(2)
    b1=tkinter.Button(text='1', command=bu1,width=2,state='disabled')
    b1.place(x=1340,y=300)
    b2=tkinter.Button(text='2', command=bu2,width=2,state='disabled')
    b2.place(x=1370,y=300)
    b3=tkinter.Button(text='3', command=bu3,width=2,state='disabled')
    b3.place(x=1400,y=300)
    b4=tkinter.Button(text='4', command=bu4,width=2,state='disabled')
    b4.place(x=1430,y=300)
    b5=tkinter.Button(text='5', command=bu5,width=2,state='disabled')
    b5.place(x=1340,y=330)
    b6=tkinter.Button(text='6', command=bu6,width=2,state='disabled')
    b6.place(x=1370,y=330)
    b7=tkinter.Button(text='7', command=bu7,width=2,state='disabled')
    b7.place(x=1400,y=330)
    b8=tkinter.Button(text='8', command=bu8,width=2,state='disabled')
    b8.place(x=1430,y=330)
    bx=tkinter.Button(text='X', command=bjm,width=2,state='disabled')
    bx.place(x=1460,y=300)
    b0=tkinter.Button(text='0', command=bu0,width=2,state='disabled')
    b0.place(x=1460,y=330)
    if drx==0:
        b1=tkinter.Button(text='1', command=db1,width=2,state='normal')
        b1.place(x=1340,y=300)
        b2=tkinter.Button(text='2', command=db2,width=2,state='normal')
        b2.place(x=1370,y=300)
        b3=tkinter.Button(text='3', command=db3,width=2,state='normal')
        b3.place(x=1400,y=300)
        b4=tkinter.Button(text='4', command=db4,width=2,state='normal')
        b4.place(x=1430,y=300)
        b5=tkinter.Button(text='5', command=db5,width=2,state='normal')
        b5.place(x=1340,y=330)
        b6=tkinter.Button(text='6', command=db6,width=2,state='normal')
        b6.place(x=1370,y=330)
        b7=tkinter.Button(text='7', command=db7,width=2,state='normal')
        b7.place(x=1400,y=330)
        b8=tkinter.Button(text='8', command=db8,width=2,state='normal')
        b8.place(x=1430,y=330)
        bx=tkinter.Button(text='X', command=dbx,width=2,state='disabled')
        bx.place(x=1460,y=300)
        b0=tkinter.Button(text='0', command=bjm,width=2,state='disabled')
        b0.place(x=1460,y=330)
    elif drx==1:
        b1=tkinter.Button(text='1', command=db1,width=2,state='normal')
        b1.place(x=1340,y=300)
        b2=tkinter.Button(text='2', command=db2,width=2,state='normal')
        b2.place(x=1370,y=300)
        b3=tkinter.Button(text='3', command=db3,width=2,state='normal')
        b3.place(x=1400,y=300)
        b4=tkinter.Button(text='4', command=db4,width=2,state='normal')
        b4.place(x=1430,y=300)
        b5=tkinter.Button(text='5', command=db5,width=2,state='disabled')
        b5.place(x=1340,y=330)
        b6=tkinter.Button(text='6', command=db6,width=2,state='disabled')
        b6.place(x=1370,y=330)
        b7=tkinter.Button(text='7', command=db7,width=2,state='disabled')
        b7.place(x=1400,y=330)
        b8=tkinter.Button(text='8', command=db8,width=2,state='disabled')
        b8.place(x=1430,y=330)
        bx=tkinter.Button(text='X', command=dbx,width=2,state='disabled')
        bx.place(x=1460,y=300)
        b0=tkinter.Button(text='0', command=bjm,width=2,state='disabled')
    elif drx==2:
        bnext=tkinter.Button(text='Next', command=dalej,state='normal')
        bnext.place(x=1450,y=730)
                        #right=True
            #for i in range(3):
                #x=input('How much?')
                #if x=='x':
                    #if drivers[d][5]!= 18:
                        #drivers[d][6]='x'
                    #else:
                        #pass
                    #break
                #else:
                    #x=int(x)
                    #dp=(drivers[d][4]-28)//8
                    #if x>=dp :
                        #drivers[d][7]=drivers[d][6]
                        #drivers[d][8]=x
                        #x=int(input('How long?'))
                        #drivers[d][9]=x
                        #right=True
                        #break
            #if right==False and  drivers[d][5]!= 18:
                #drivers[d][6]='x'
            
    pickteams()
drivx=0
def fff():
    global drivx
    drivx=drivx+1
    if drivx==len(teams[0][5][1]):
        bnext=tkinter.Button(text='Next', command=dalej,state='normal')
        bnext.place(x=1450,y=730)
        b1=tkinter.Button(text='1', command=f1s,width=2,state='disabled')
        b1.place(x=1340,y=300)
        b2=tkinter.Button(text='2', command=indys,width=2,state='disabled')
        b2.place(x=1370,y=300)
        bx=tkinter.Button(text='X', command=hosts,width=2,state='disabled')
        bx.place(x=1460,y=300)
    pteams(0)
        
def f1s():
    global ss1
    if ss1<2:
        drivers[teams[0][5][1][drivx]][10]=0
        ss1=ss1+1
    else:
        jhost.append(teams[0][5][1][drivx])
    fff()
        
def indys():
    global ss2
    if ss2<4:  
        drivers[teams[0][5][1][drivx]][10]=2
        ss2=ss2+1
    else:
        jhost.append(teams[0][5][1][drivx])
    fff()
def hosts():
    jhost.append(teams[0][5][1][drivx])
    fff()
def asdf():
    b1=tkinter.Button(text='1', command=f1s,width=2,state='disabled')
    b1.place(x=1340,y=300)    
    b2=tkinter.Button(text='2', command=indys,width=2,state='disabled')
    b2.place(x=1370,y=300)
    b3=tkinter.Button(text='3', command=bu3,width=2,state='disabled')
    b3.place(x=1400,y=300)
    b4=tkinter.Button(text='4', command=bu4,width=2,state='disabled')
    b4.place(x=1430,y=300)
    b5=tkinter.Button(text='5', command=bu5,width=2,state='disabled')
    b5.place(x=1340,y=330)
    b6=tkinter.Button(text='6', command=bu6,width=2,state='disabled')
    b6.place(x=1370,y=330)
    b7=tkinter.Button(text='7', command=bu7,width=2,state='disabled')
    b7.place(x=1400,y=330)
    b8=tkinter.Button(text='8', command=bu8,width=2,state='disabled')
    b8.place(x=1430,y=330)
    bx=tkinter.Button(text='X', command=hosts,width=2,state='disabled')
    bx.place(x=1460,y=300)
    b0=tkinter.Button(text='0', command=bu0,width=2,state='disabled')
    b0.place(x=1460,y=330)
def pickefs():
    global drivx
    #if len(fdrivers)<1 or drp==len(fdrivers):
        #drx=2
    
    b1=tkinter.Button(text='1', command=f1s,width=2,state='disabled')
    b1.place(x=1340,y=300)
    if year>1949:
        b1=tkinter.Button(text='1', command=f1s,width=2,state='normal')
        b1.place(x=1340,y=300)
        
    b2=tkinter.Button(text='2', command=indys,width=2,state='normal')
    b2.place(x=1370,y=300)
    b3=tkinter.Button(text='3', command=bu3,width=2,state='disabled')
    b3.place(x=1400,y=300)
    b4=tkinter.Button(text='4', command=bu4,width=2,state='disabled')
    b4.place(x=1430,y=300)
    b5=tkinter.Button(text='5', command=bu5,width=2,state='disabled')
    b5.place(x=1340,y=330)
    b6=tkinter.Button(text='6', command=bu6,width=2,state='disabled')
    b6.place(x=1370,y=330)
    b7=tkinter.Button(text='7', command=bu7,width=2,state='disabled')
    b7.place(x=1400,y=330)
    b8=tkinter.Button(text='8', command=bu8,width=2,state='disabled')
    b8.place(x=1430,y=330)
    bx=tkinter.Button(text='X', command=hosts,width=2,state='normal')
    bx.place(x=1460,y=300)
    b0=tkinter.Button(text='0', command=bu0,width=2,state='disabled')
    b0.place(x=1460,y=330)
manmarket=[]

def manufmarket():
    global manmarket
    manmarket=[]
    for s in range(len(series)):
        manmarket.append(printmprice(s))

def printmprice(s):
    xx=[]
    x=['Engine','Chassi','Pneu']
    for e in range(3):
        y=[]
        for m in (series[s][15][e]):
            for s1 in range(len(manufac[e][m][1])):
                if manufac[e][m][1][s1][0]==s:
                    y.append(m)
        xx.append(y)
    return(xx)
                    

def freemarket(s):
    
    global fm
    fm=[]
    for d in (cdrivers):

        true=False  
        for t in (series[s][13]):
            for i in range(len(fm)):
                if fm[i][0]==d:
                    true=True
            if (drivers[d][7]=='x' or drivers[d][7]!=t) and drivers[d][5]>17 and true==False:
                if drivers[d][6]=='x':
                    fm.append([d,0])
                elif drivers[d][6]==t:
                    fm.append([d,1])
                elif teams[drivers[d][6]][10]>series[s][7]:
                    fm.append([d,0])
                elif teams[drivers[d][6]][10]<series[s][7] and drivers[d][7]=='x':
                    fm.append([d,1])

    
def mtot():
    for t in (cteams):
        if teams[t][7] != []:
            
            for s1 in range(1,len(teams[t][7][-1])):
                if teams[t][7][-1][s1]!=[]:
                    s=teams[t][7][-1][s1][0]
                    hod=0
                    for e in range(3):
                        for m in range(len(manufac[e][teams[t][7][-1][s1][2+3*e]][1])):
                            if manufac[e][teams[t][7][-1][s1][2+3*e]][1][m][0]==s:
                                hod=hod+manufac[e][teams[t][7][-1][s1][2+3*e]][1][m][1]
                    teams[t][7][-1][s1][11]=hod
                    
def mtos():
    for s in (cseries):
        for e in range(3):
            series[s][15][e]=[]
            for m in range(len(manufac[e])):
                for s1 in range(len(manufac[e][m][1])):
                    if manufac[e][m][1][s1][5]<=year and manufac[e][m][1][s1][6]>=year and manufac[e][m][1][s1][0]==s:
                        series[s][15][e].append(m)
                
def dtos():
    mtot()
    for s in (cseries):
        series[s][14]=[]
    for d in (cdrivers):
        series[drivers[d][10]][14].append(d)
    for s in (cseries):
        sss=[]
        
        for d in (series[s][14]):
            sss.append([d])
        
        t=0
        for d in range(len(sss)):
            if drivers[sss[d][0]][11][0]==True:
                T=drivers[sss[d][0]][11][1]
            else:
                T=drivers[sss[d][0]][7]
            for i in range(1,len(teams[T][7][-1])):
                if teams[T][7][-1][i][0]==s:
                    sss[d].append(teams[T][7][-1][i][11]*drivers[sss[d][0]][4])
                    sss[d].append(drivers[sss[d][0]][5])
        for i in range(1,len(sss)):
            value=sss[i]
            for h in range(1,len(sss)):
                x=sss[i][2]
                j=i-1
            while j>=0:
                if x<sss[j][2]:                  
                    sss[j+1]=sss[j]
                    sss[j]=value
                    j=j-1
                else:
                    break
        for i in range(1,len(sss)):
            value=sss[i]
            for h in range(1,len(sss)):
                x=sss[i][1]
                j=i-1
            while j>=0:
                if x>sss[j][1]:                  
                    sss[j+1]=sss[j]
                    sss[j]=value
                    j=j-1
                else:
                    break
        for i in range(len(sss)):
            sss[i]=sss[i][0]
        series[s][14]=sss

def fmcalculate():
    ### driver, money, lenght, team
    a=[]
    global fmdbids
    #a.append(0)
    dr=[]
    if len(fmdbids)>0:
        dr.append(fmdbids[0][0])
    for b in range(1,len(fmdbids)):
        true=False
        for x in range(len(dr)):
            if fmdbids[b][0]==dr[x]:
                true=True
        if true==False:
            dr.append(fmdbids[b][0])
    
    for d in range(len(dr)):
        a=[]
        for b in range(len(fmdbids)):
            if fmdbids[b][0]==dr[d]:
                a.append(b)
        x=a[0]
        for b in range(1,len(a)):
            if fmdbids[a[b]][1]>fmdbids[x][1]:
                x=a[b]
        dp=(drivers[fmdbids[x][0]][4]-28)//8
        if fmdbids[x][1]>=dp:
            drivers[fmdbids[x][0]][6]=fmdbids[x][3]
            drivers[fmdbids[x][0]][7]=fmdbids[x][3]
            drivers[fmdbids[x][0]][8]=fmdbids[x][1]
            drivers[fmdbids[x][0]][9]=fmdbids[x][2]
            drivers[fmdbids[x][0]][10]='x'
            
    fmdbids=[]

def llman():
    
    for t in(cteams):
        for s in range(len(teams[t][6])):
            if teams[t][6][s][2]<=year and teams[t][6][s][3]>=year:
                for e in range(3):
                    if (teams[t][6][s][4+e*3]=='x' or teams[t][6][s][5+e*3]<1) and year>=teams[t][6][s][2] and year<=teams[t][6][s][3]:
                        for m in (series[teams[t][6][s][0]][15][e]):
                            if teams[t][0]==manufac[e][m][0]:
                                teams[t][6][s][4+e*3]=m
                                teams[t][6][s][5+e*3]=1
                                teams[t][6][s][6+e*3]=3
                                break
                            elif teams[t][9]==False:
                                xx=len(series[teams[t][6][s][0]][15][e])
                                x=random.randrange(xx)
                                m=series[teams[t][6][s][0]][15][e][x]
                                teams[t][6][s][4+e*3]=m
                                x=random.randrange(4)
                                teams[t][6][s][5+e*3]=1+x
                                for p in range(len(manufac[e][m][1])):
                                    if manufac[e][m][1][p][0]==teams[t][6][s][0]:
                                        teams[t][6][s][6+e*3]=manufac[e][m][1][p][2]
                            
def lowerleagues():
###0=Volny 1=Obmedzeny volny 2=hostovanie
    global jhost
    
    for t in (cteams):
        y=0
        if teams[t][9]==False:
#Manufac


#Drivers            
            for s in range(len(teams[t][6])):
                if teams[t][6][s][2]<=year and teams[t][6][s][3]>=year:
                    y=y+series[teams[t][6][s][0]][6]
            if y<(len(teams[t][5][1])+len(teams[t][5][3])):
                
                for i in range(1,len(teams[t][5][1])):
                    value=teams[t][5][1][i]
                    x=drivers[teams[t][5][1][i]][5]
                    j=i-1
                    while j>=0:
                        if x>drivers[teams[t][5][1][j]][5]:                  
                            teams[t][5][1][j+1]=teams[t][5][1][j]
                            teams[t][5][1][j]=value
                            j=j-1
                        else:
                            break
                for i in range(1,len(teams[t][5][1])):
                    value=teams[t][5][1][i]
                    x=drivers[teams[t][5][1][i]][4]
                    j=i-1
                    while j>=0:
                        if x<drivers[teams[t][5][1][j]][4]:                  
                            teams[t][5][1][j+1]=teams[t][5][1][j]
                            teams[t][5][1][j]=value
                            j=j-1
                        else:
                            break
                       
                y=len(teams[t][5][1])+len(teams[t][5][3])-y                 
                for i in range(y):
                    jhost.append(teams[t][5][1][i])                     
    for s in (cseries):
        
        if s != 3 and series[s][2]<=year and series[s][3]>=year:
            level=series[s][7]
            freemarket(s)
            team=[]
            teamscore=[]
            score=0
            
            for i in range(len(jhost)):
                fm.append([jhost[i],2])
            for h in range(len(series[s][8])):
                if series[s][8][h][0]==year-1:
                    team=series[s][8][h][-2]
                    team.reverse()
            for t in (series[s][13]):
                if teams[t][9]==False:
                    true=False
                    for i in range(len(team)):
                        if team[i]==t and teams[team[i]][9]==False:
                            teamscore.append([t,i+1])
                            true=True
                    if true==False:
                        teamscore.append([t,1])
            for i in range(1,len(fm)):
                value=fm[i]
                x=drivers[fm[i][0]][5]
                j=i-1
                while j>=0:
                    if x<drivers[fm[j][0]][5]:                  
                        fm[j+1]=fm[j]
                        fm[j]=value
                        j=j-1
                    else:
                        break
            for i in range(1,len(fm)):
                value=fm[i]
                x=drivers[fm[i][0]][4]
                j=i-1
                while j>=0:
                    if x>drivers[fm[j][0]][4]:                  
                        fm[j+1]=fm[j]
                        fm[j]=value
                        j=j-1
                    else:
                        break
            fm.reverse()
            for i in range(len(fm)-1,-1,-1):
                helper=0
                totalch=0
                for j in range(len(teamscore)-1,-1,-1):
                    x=0
                    pickteams()
                    for t in range(len(teams[teamscore[j][0]][6])):
                        if series[teams[teamscore[j][0]][6][t][0]][7]<=level and teams[teamscore[j][0]][6][t][2]<=year:
                            x=x+series[teams[teamscore[j][0]][6][t][0]][6]
                    if teams[teamscore[j][0]][9]==False and len(teams[teamscore[j][0]][5][1])+len(teams[teamscore[j][0]][5][3])<x:
                        totalch=totalch+teamscore[j][1]
                    else:
                        teamscore.remove(teamscore[j])
                if totalch>0:
                    x=random.randrange(1,totalch+1)
                    w=0
                    for j in range(len(teamscore)):
                        helper=helper+teamscore[j][1]
                        if x<=helper:
                            w=j
                            x=helper+totalch
                    if fm[i][1]<2:
                        salary=(drivers[fm[i][0]][4]-28)//8
                        psalary=random.randrange(1,9)
                        while psalary < salary:
                            psalary=random.randrange(1,9)
                        
                        drivers[fm[i][0]][8]=psalary
                        drivers[fm[i][0]][9]=random.randrange(1,5)
                        drivers[fm[i][0]][7]=teamscore[w][0]
                        
                        if fm[i][1]==0:
                            drivers[fm[i][0]][6]=teamscore[w][0]
                        fm.remove(fm[i])
                    elif fm[i][1]==2:
                        drivers[fm[i][0]][11][0]=True
                        drivers[fm[i][0]][11][1]=teamscore[w][0]
                        drivers[fm[i][0]][11][3]=drivers[fm[i][0]][7]
                        drivers[fm[i][0]][11][2]=1
                        jhost.remove(fm[i][0])
                    
                    pickteams()
                        
#######
def rand():
    sl=[]
    sr=[]
    for s in range(len(series)):
        
        for p in range(len(series[s][8])):
            if series[s][8][p][0]==year:
                x=[]
                for f in range(3):
                    if len(series[s][8])>f+1:
                        x.append(len(series[s][8][p-f][-3]))
        sl.append([s,series[s][7],x])
    top=0
    tp=[0,0,0]
    
    for i in range(3):
        xx=0
        for y in range(len(sl)):
            if sl[y][1]>xx:
                xx=sl[y][1]
        top=top+xx
        tp[i]=xx+1
    for d in (cdrivers):
        y=0
        for f in range(3):
            if len(drivers[d][14])>f+1:
                s=drivers[d][14][0-1-f][1][5]
                i=drivers[d][14][0-1-f][1][9]-1
                for ff in range(len(sl)):
                    if sl[ff][0]==s:
                        x=sl[ff][2][f]
                        ss=sl[ff][1]
                        ss=tp[f]-ss
                y=y+(x-i)/x*ss
        sr.append([d,s,y])
    for i in range(1,len(sr)):
                value=sr[i]
                x=sr[i][2]
                j=i-1
                while j>=0:
                    if x>sr[j][2]:                  
                        sr[j+1]=sr[j]
                        sr[j]=value
                        j=j-1
                    else:
                        break

    for i in range(len(sr)):
        for f in range(9):
            if sr[i][2]*100/top>=(100-(f*12.5)):
                break
#####
def rulechangeman():
    for e in range(3):
        x=0
        sx=100
        s1='x'
        for s in (cseries):
            if series[s][7]<sx and year>series[s][2]:
                sx=series[s][7]
                s1=s
        if s1!='x':
            for m in (series[s1][15][e]):
                for i in range(len(manufac[e][m][1])):
                    if manufac[e][m][1][i][1]>x:
                        x=manufac[e][m][1][i][1]
            for s in (cseries):
                for y in (series[s][11][e]):
                    if y==year:
                        xx=1
                        for i in range(series[s][7]):
                            xx=xx*0.9
                        x2=int(x*xx)
                        xx=xx*0.9
                        x1=int(x*xx)
                        for m in(series[s][15][e]):
                            for i in range(len(manufac[e][m][1])):
                                manufac[e][m][1][i][1]=random.randrange(x1,x2+1)
        else:
            for s in (cseries):
                for y in (series[s][11][e]):
                    if y==year:
                        for m in(series[s][15][e]):
                            for i in range(len(manufac[e][m][1])):
                                manufac[e][m][1][i][1]=1
def llreadyforseason():
    for t in (cteams):
        if teams[t][9]==False:
            driv=[]
            seri=[]
        
            for d in (teams[t][5][1]):
                driv.append(d)
            for d in (teams[t][5][3]):
                driv.append(d)
            for i in range(len(teams[t][6])):
                if teams[t][6][i][2]<=year and teams[t][6][i][3]>=year:
                    seri.append(teams[t][6][i][0])
                    teams[t][6][i][13]=0
            for i in range(1,len(driv)):
                value=driv[i]
                x=drivers[driv[i]][5]
                j=i-1
                while j>=0:
                    if x<drivers[driv[j]][5]:                  
                        driv[j+1]=driv[j]
                        driv[j]=value
                        j=j-1
                    else:
                        break
            for i in range(1,len(driv)):
                value=driv[i]
                x=drivers[driv[i]][4]
                j=i-1
                while j>=0:
                    if x>drivers[driv[j]][4]:                  
                        driv[j+1]=driv[j]
                        driv[j]=value
                        j=j-1
                    else:
                        break
            for i in range(1,len(seri)):
                value=seri[i]
                x=series[seri[i]][7]
                j=i-1
                while j>=0:
                    if x<series[seri[j]][7]:                  
                        seri[j+1]=seri[j]
                        seri[j]=value
                        j=j-1
                    else:
                        break
            if len(driv)>0 and len(seri)>0:
                slevel=series[seri[0]][6]
                spicked=0
                for i in range(len(driv)):
                    if slevel<i+1:
                        spicked=spicked+1
                        slevel=slevel+series[seri[spicked]][6]
                    drivers[driv[i]][10]=seri[spicked]
                    for ii in range(len(teams[t][6])):
                        if teams[t][6][ii][0]==seri[spicked]:
                            teams[t][6][ii][13]=teams[t][6][ii][13]+1


def rfs(t):
    driv=[]
    
    for d in (teams[t][5][1]):
        driv.append(d)
    for d in (teams[t][5][3]):
        driv.append(d)
    for i in range(len(teams[t][6])):
        teams[t][6][i][13]=0
    for d in (driv):
        x=int(input('Which series?'))
        drivers[d][10]=x
        pickteams()
        if teams[t][4]>0:
            for i in range(len(teams[t][6])):
                if teams[t][6][i][0]==x:
                    teams[t][6][i][13]=teams[t][6][i][13]+1
        else:
            drivers[d][10]='x'
    pickteams()

def addnewyear():
    dx=[]
    dy=[]
    dz=[]
    for d in (cdrivers):
        dx.append(year)
        dy.append(drivers[d][5])
        dy.append(drivers[d][6])
        dy.append(drivers[d][7])
        dy.append(drivers[d][8])
        dy.append(drivers[d][9])
        dy.append(drivers[d][10])
        dy.append(series[drivers[d][10]][7])
        dy.append(drivers[d][11])
        dy.append(0)
        dy.append(0)
        dy.append(0)
        dy.append(0)
        dx.append(dy)
        drivers[d][14].append(dx)
        dx=[]
        dy=[]
    for t in (cteams):
        dx.append(year)
        xxx=False
        for i in range(len(teams[t][6])):
            if teams[t][6][i][2]<=year and teams[t][6][i][3]>=year:
                xxx=True
                dy.append(teams[t][6][i][0])
                dy.append(teams[t][6][i][1])
                dy.append(teams[t][6][i][4])
                dy.append(teams[t][6][i][5])
                dy.append(teams[t][6][i][6])
                dy.append(teams[t][6][i][7])
                dy.append(teams[t][6][i][8])
                dy.append(teams[t][6][i][9])
                dy.append(teams[t][6][i][10])
                dy.append(teams[t][6][i][11])
                dy.append(teams[t][6][i][12])
                dy.append(0)
                dy.append(0)
                for d in (teams[t][5][1]):
                    if drivers[d][10]==teams[t][6][i][0]:
                        dz.append(d)
                for d in (teams[t][5][3]):
                    if drivers[d][10]==teams[t][6][i][0]:
                        dz.append(d) 
                dy.append(dz)
                dz=[]
                dy.append(0)
                dy.append(0)
                dx.append(dy)
                dy=[]
        if xxx==True:
            teams[t][7].append(dx)
        dx=[]
    for e in range(3):
        for m in range(len(manufac[e])):
            dx.append(year)
            fff=[]
            for i in range(len(manufac[e][m][2])):
                if manufac[e][m][2][i][0]==year:
                    fff.append(manufac[e][m][2][i])
            for i in range(len(fff)):
                manufac[e][m][2].remove(fff[i])
            fff=[]
            for i in range(len(manufac[e][m][1])):
                legal=False
                for y in range(manufac[e][m][1][i][4]):
                    if manufac[e][m][1][i][5+y*2]<=year and manufac[e][m][1][i][6+y*2]>=year:
                        legal=True
                if legal==True:
                    dy.append(manufac[e][m][1][i][0])
                    for t in (series[manufac[e][m][1][i][0]][13]):
                        for s in range(len(teams[t][6])):
                            if manufac[e][m][1][i][0]==teams[t][6][s][0] and m==teams[t][6][s][4+e*3]:
                                dz.append(t)
                    dy.append(dz)
                    dz=[]
                    for t in (dy[1]):
                        for d in (teams[t][5][1]):
                            if drivers[d][10]==manufac[e][m][1][i][0]:
                                dz.append(d)
                        for d in (teams[t][5][3]):
                            if drivers[d][10]==manufac[e][m][1][i][0]:
                                dz.append(d)
                    dy.append(dz)
                    dz=[]
                    dy.append(0)
                    dy.append(0)
                    dx.append(dy)
                    dy=[]
            manufac[e][m][2].append(dx)
            dx=[]
            
    
                

def seasondranking():
    dx=[]
    x='x'
    for s in (cseries):
        for d in (series[s][14]):
            if drivers[d][11][0]==True:
                x=drivers[d][11][1]
                
            else:
                x=drivers[d][7]
            for i in range(1,len(teams[x][7][-1])):
                if teams[x][7][-1][i][0]==s:
                    dx.append([d,teams[x][7][-1][i][11]*drivers[d][4]])
        for i in range(1,len(dx)):
            value=dx[i]
            x=dx[i][1]
            j=i-1
            while j>=0:
                if x>dx[j][1]:                  
                    dx[j+1]=dx[j]
                    dx[j]=value
                    j=j-1
                else:
                    break
        series[s][14]=[]
        for i in range(len(dx)):
            series[s][14].append(dx[i][0])
        dx=[]

def calendarmaker():
    x=0
    global calendar
    calendar=[]
    for i in range(date):
        calendar.append([])
    for s in (cseries):
        for i in range(1,series[s][9]+1):
            x=i/series[s][9]*date
            x=round(x)
            calendar[x-1].append(s)
def races(s):
    global results
    d=len(series[s][14])
    group=d//4
    group1=d-(group*4)
    rac = [50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50]
    rx = [50,50,50,50,50,50,50,50]
    results = [50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50]
    for i in range (d):
        rac[i]=i+1
    for i in range (group1):
        for j in range (group+1):
            r=random.randrange(d-i)  
            rx[j]=rac[r]            
        for j in range (group):
            if rx[0] > rx[j+1] :
                rx[0] = rx[j+1]
        results[i]=rx[0]
        for j in range (d-i):
            if rac[j] == rx[0] :
                rac[j]=50
                rac.sort()
    for i in range (group1,d):
        for j in range (group):
            r=random.randrange(d-i)
            rx[j]=rac[r]
        for j in range (group-1):
            if rx[0] > rx[j+1] :
                rx[0] = rx[j+1]
        results[i]=rx[0]
        for j in range (d-i):
            if rac[j] == rx[0] :
                rac[j]=50
                rac.sort()
        if ((i-group1+1)%4) == 0 :
            group=group-1
    
    
def nextrace():
    x=0
    xx=0
    y=20
    h=1
    seasonresults=[]
    global adate
    if adate<date:
        adate=adate+1

        for s in (calendar[adate-1]):
            races(s)
            for i in range(len(series[s][16])):
                if series[s][16][i][0]<=year:
                    y=i
            xx=series[s][16][y][1]
            for j in range(len(series[s][14])):
                d=series[s][14][j]
                drivers[d][14][-1][1][11]=1+drivers[d][14][-1][1][11]
                if drivers[d][14][-1][1][10]==0:
                    drivers[d][14][-1][1][10]=1
                drivers[d][14][-1][1].append(results[j])
                y=results[j]-1
                if len(pointsystem[xx])>y:
                    drivers[d][14][-1][1][8]=drivers[d][14][-1][1][8]+pointsystem[xx][y]
                    if drivers[d][11][0]==True:
                        t=drivers[d][11][1]
                    else:
                        t=drivers[d][7]
                    for f in range(len(teams[t][7])):
                        if teams[t][7][f][0]==year:
                            for f2 in range(1,len(teams[t][7][f])):
                                if teams[t][7][f][f2][0]==s:
                                    teams[t][7][f][f2][14]=teams[t][7][f][f2][14]+pointsystem[xx][y]
            seasonresults=[]
            seasonteams=[]
            for i in (series[s][14]):
                seasonresults.append(i)
            
# Vek
            for i in range(1,len(seasonresults)):
                value=seasonresults[i]
                x=drivers[seasonresults[i]][5]
                j=i-1
                while j>=0:
                    if x<drivers[seasonresults[j]][5]:                  
                        seasonresults[j+1]=seasonresults[j]
                        seasonresults[j]=value
                        j=j-1
                    else:
                        break
            
#Poziciavsampionate
            for p in range(30,0,-1):
                for i in range(1,len(seasonresults)):
                    value=seasonresults[i]
                    for h in range(1,len(drivers[seasonresults[i]][14][-1])):
                        xx1=len(drivers[seasonresults[i]][14][-1][h])
                        x=drivers[seasonresults[i]][14][-1][h][12:xx1].count(p)
                        j=i-1
                    while j>=0:
                        xx2=len(drivers[seasonresults[j]][14][-1][h])
                        if x>drivers[seasonresults[j]][14][-1][h][12:xx2].count(p):                  
                            seasonresults[j+1]=seasonresults[j]
                            seasonresults[j]=value
                            j=j-1
                        else:
                            break

#Pozicia
            for i in range(1,len(seasonresults)):
                value=seasonresults[i]
                for h in range(1,len(drivers[seasonresults[i]][14][-1])):
                    x=drivers[seasonresults[i]][14][-1][h][8]
                    j=i-1
                while j>=0:
                    if x>drivers[seasonresults[j]][14][-1][h][8]:                  
                        seasonresults[j+1]=seasonresults[j]
                        seasonresults[j]=value
                        j=j-1
                    else:
                        break
            for i in range(len(seasonresults)):
                d=seasonresults[i]
                drivers[d][14][-1][1][9]=i+1
##Teams
            for i in range(len(series[s][13])):
                t=series[s][13][i]

                for f in range(1,len(teams[t][7][-1])):
                    if teams[t][7][-1][f][0]==s:
                        p=teams[t][7][-1][f][14]
                        pp=100
                        for d in(teams[t][7][-1][f][13]):
                            if pp>drivers[d][14][-1][1][9]:
                                pp=drivers[d][14][-1][1][9]
                seasonteams.append([t,pp,p])
###team driver
            for i in range(1,len(seasonteams)):
                value=seasonteams[i]
                x=seasonteams[i][1]
                j=i-1
                while j>=0:
                    if x<seasonteams[j][1]:                  
                        seasonteams[j+1]=seasonteams[j]
                        seasonteams[j]=value
                        j=j-1
                    else:
                        break
            for i in range(1,len(seasonteams)):
                value=seasonteams[i]
                x=seasonteams[i][2]
                j=i-1
                while j>=0:
                    if x>seasonteams[j][2]:                  
                        seasonteams[j+1]=seasonteams[j]
                        seasonteams[j]=value
                        j=j-1
                    else:
                        break
            for i in range(len(seasonteams)):
                t=seasonteams[i][0]
                for j in range(1,len(teams[t][7][-1])):
                    if teams[t][7][-1][j][0]==s:
                        teams[t][7][-1][j][15]=i+1
            for i in range(len(series[s][8])):
                if series[s][8][i][0]==year:
                    series[s][8][i][-3]=seasonresults
                    series[s][8][i][-2]=[]
                    for j in range(len(seasonteams)):
                        if seasonteams[j][1]!=100:
                            series[s][8][i][-2].append(seasonteams[j][0])
                            series[s][8][i][-1]=[[],[],[]]
###seasonman
            maxcars=0
            maxcars=series[s][6]
            xxP=[]
            xxSP=100
            for e in range(3):
                seasonman=[]
                for m in (series[s][15][e]):
                    xxP=[]
                    xxSP=100
                    for i in range(1,len(manufac[e][m][2][-1])):
                        if manufac[e][m][2][-1][i][0]==s:
                            j=i
                            for d in (manufac[e][m][2][-1][i][2]):
                                xxP.append(drivers[d][14][-1][1][-1])
                                if drivers[d][14][-1][1][9]<xxSP:
                                    xxSP=drivers[d][14][-1][1][9]
                    xxP.sort()
                    if len(xxP)>maxcars:
                        for i in range(maxcars):
                            if xxP[i]<=len(pointsystem[xx]):
                                
                                manufac[e][m][2][-1][j][3]=manufac[e][m][2][-1][j][3]+pointsystem[xx][xxP[i]-1]
                    else:
                        for i in range(len(xxP)):
                            if xxP[i]<=len(pointsystem[xx]):
                                
                                manufac[e][m][2][-1][j][3]=manufac[e][m][2][-1][j][3]+pointsystem[xx][xxP[i]-1]
                    xxP=[m,xxSP,manufac[e][m][2][-1][j][3]]
                    seasonman.append(xxP)
                    
                for i in range(1,len(seasonman)):
                    value=seasonman[i]
                    x=seasonman[i][1]
                    j=i-1
                    while j>=0:
                        if x<seasonman[j][1]:                  
                            seasonman[j+1]=seasonman[j]
                            seasonman[j]=value
                            j=j-1
                        else:
                            break
                for i in range(1,len(seasonman)):
                    value=seasonman[i]
                    x=seasonman[i][2]
                    j=i-1
                    while j>=0:
                        if x>seasonman[j][2]:                  
                            seasonman[j+1]=seasonman[j]
                            seasonman[j]=value
                            j=j-1
                        else:
                            break
                for i in range(len(seasonman)):
                    m=seasonman[i][0]
                    for j in range(1,len(manufac[e][m][2][-1])):
                        if manufac[e][m][2][-1][j][0]==s and len(manufac[e][m][2][-1][j][2])>0:
                            manufac[e][m][2][-1][j][4]=i+1
                for i in range(len(series[s][8])):
                    if series[s][8][i][0]==year:
                        for j in range(len(seasonman)):
                            if seasonman[j][1]!=100:
                                series[s][8][i][-1][e].append(seasonman[j][0])
                
            

def newdriv():
    nat=0
    for i in range(len(nations)):
        nat=nat+nations[i][2]
    for i in range(1,len(newdrivers)):
        value=newdrivers[i]
        x=newdrivers[i][0]
        j=i-1
        while j>=0:
            if x<newdrivers[j][0]:                  
                newdrivers[j+1]=newdrivers[j]
                newdrivers[j]=value
                j=j-1
            else:
                break
    if len(newdrivers)>1:        
        if newdrivers[1][0]>=year:
            x=newdrivers[1]
            newdrivers.remove(x)
    for i in range(newdrivers[0][1]):
        x=0
        newd=random.randrange(nat)
        for i in range(len(nations)):
            x=x+nations[i][2]
            if newd<x:
                xx=[]
                d1=random.randrange(len(nations[i][3]))
                d1=nations[i][3][d1]
                d2=random.randrange(len(nations[i][4]))
                d2=nations[i][4][d2]
                d4=random.randrange(len(ability))
                d4=ability[d4]
                xx=[d1,d2,nations[i][1],year-15,d4,15,'x','x','x','x','x',[False,'x','x','x'],False,0,[],['x','x','x','x']]
                drivers.append(xx)
                break
        
def newyear():
    global year
    global adate
    seasonr()
    manreability()
    year=year+1
    newdriv()
    reteammoney()
    conlenghts()
    age()
    pickdrivers()
    pickteams()
    pickseries()
    pickman()
    mtos()
    picknations()
    natselect()
    calendarmaker()
    rulechangeman()
    draftlottery()
    ownsasi()
    adate=0

def hmc():
    for t in (cteams):
        for i in range(len(teams[t][6])):
            x=0
            for d in (cdrivers):
                if drivers[d][14][-1][1][5]==teams[t][6][i][0]:
                    if drivers[d][14][-1][1][2]==t and drivers[d][14][-1][1][7][0]==False:
                        x=x+1
                    elif drivers[d][14][-1][1][7][1]==t and drivers[d][14][-1][1][7][0]==True:
                        x=x+1
            teams[t][6][i][13]=x
        
def preseason():
    global jhost
    for d in (cdrivers):
        if drivers[d][10]=='x' and drivers[d][6]!='x':
            if teams[drivers[d][6]][9]==True:
                jhost.append(d)
    llman()
    lowerleagues()
    llreadyforseason()
    for s in (cseries):
        series[s][14]=[]
    for d in (cdrivers):
        series[drivers[d][10]][14].append(d)
        
    for t in (cteams):
        if teams[t][9]==False:
            teams[t][4]=0
    addnewyear()
    mtot()
    hmc()
    seasondranking()
    global adate
    adate=0
    jhost=[]
#Date

####Graphic
def season(s,year1):
    y=0
    for i in range(len(series[s][8])):
        if series[s][8][i][0]==year1:
            y=i
            S=len(series[s][8][i])-4
            J=len(series[s][8][i][-3])
            T=len(series[s][8][i][-2])
            if len(series[s][8][i][-1])==0:
                E=0
                C=0
                P=0
            else:
                E=len(series[s][8][i][-1][0])
                C=len(series[s][8][i][-1][1])
                P=len(series[s][8][i][-1][2])
    sezona(S,J,T,E,C,P,s,y,year1)
def sezona(S,J,T,E,C,P,s,ye,year1):
    a.create_rectangle(0,0,1512,800,fill='white')
    y=0
    for i in range(J):
        a.create_line(1,26+y,310+S*30,26+y,width=1)
        D=series[s][8][ye][-3][i]
        a.create_text(50,38+y,text=(drivers[D][0][0],drivers[D][1]), font='Arial 11')
        for j in range(len(drivers[D][14])):
            if drivers[D][14][j][0]==series[s][8][ye][0]:
                if drivers[D][14][j][1][7][0]==True:
                    Te=drivers[D][14][j][1][7][1]
                else:
                    Te=drivers[D][14][j][1][2]
                a.create_text(145,38+y,text=teams[Te][0], font='Arial 11')
                for r in range(drivers[D][14][j][1][10],drivers[D][14][j][1][11]+1):
                    if drivers[D][14][j][1][11+r]==1:
                        a.create_rectangle(160+30*r,y+26,190+30*r,y+50,fill='yellow')
                    if drivers[D][14][j][1][11+r]==2:
                        a.create_rectangle(160+30*r,y+26,190+30*r,y+50,fill='silver')
                    if drivers[D][14][j][1][11+r]==3:
                        a.create_rectangle(160+30*r,y+26,190+30*r,y+50,fill='brown2')
                    a.create_text(175+30*r,38+y,text=drivers[D][14][j][1][11+r], font='Arial 11')
                a.create_text(220+30*S,38+y,text=drivers[D][14][j][1][8], font='Arial 11')
                a.create_text(280+30*S,38+y,text=drivers[D][14][j][1][9], font='Arial 11')
        a.create_text(50,38+y,text=(drivers[D][0][0],drivers[D][1]), font='Arial 11')
        y=y+24
    a.create_line(1,26+y,310+S*30,26+y,width=1)
    a.create_line(100,0,100,26+y,width=1)
    a.create_line(2,0,2,26+y,width=1)
    a.create_line(1,2,310+S*30,2,width=1)
    a.create_text(50,14,text=(series[s][1],year1), font='Arial 11')#### jazdci/year
    x=0
    for i in range(1):
        a.create_line(190+x,1,190+x,26+y,width=1)
        x=x+90
    for i in range(1,S+1):
        a.create_line(130+x,1,130+x,26+y,width=1)
        a.create_text(115+x,14,text=i, font='Arial 11')
        x=x+30
    x=x+30
    for i in range(1):
        a.create_line(130+x,1,130+x,26+y,width=1)
        a.create_text(100+x,14,text='Points', font='Arial 11')
        x=x+60
    for i in range(1):
        a.create_line(130+x,1,130+x,26+y,width=1)
        a.create_text(100+x,14,text='Position', font='Arial 11')
        x=x+60
    a.create_text(145,14,text='Team', font='Arial 11')

    y=0
    x=x+90
    xt=x
    for i in range(T):
        a.create_line(xt,26+y,xt+220,26+y,width=1)
        Te=series[s][8][ye][-2][i]
        a.create_text(xt+50,38+y,text=teams[Te][0], font='Arial 11')
        for j in range(len(teams[Te][7])):
            if teams[Te][7][j][0]==series[s][8][ye][0]:
                for h in range(1,len(teams[Te][7][j])):
                    if teams[Te][7][j][h][0]==s:
                        a.create_text(xt+130,38+y,text=teams[Te][7][j][h][14], font='Arial 11')
                        a.create_text(xt+190,38+y,text=teams[Te][7][j][h][15], font='Arial 11')
        y=y+24
    a.create_line(xt,26+y,xt+220,26+y,width=1)
    a.create_line(xt+100,1,xt+100,26+y,width=1)
    a.create_line(xt,2,xt+220,2,width=1)
    a.create_line(xt,1,xt,26+y,width=1)
    a.create_text(xt+50,14,text=(series[s][1],'Teams'), font='Arial 11')
    x=0
    #for i in range(2):
     #   x=x+90
      #  a.create_line(xt+100+x,1,xt+100+x,26+y,width=1)
        
    x=x+30
    for i in range(1):
        a.create_line(xt+130+x,1,xt+130+x,26+y,width=1)
        a.create_text(xt+100+x,14,text='Points', font='Arial 11')
        x=x+60
    for i in range(1):
        a.create_line(xt+130+x,1,xt+130+x,26+y,width=1)
        a.create_text(xt+100+x,14,text='Position', font='Arial 11')
        x=x+60

        
    a.create_text(xt+50,50+y,text=(series[s][1],'Engines'), font='Arial 11')
    y2=y+26
    for i in range(E):
        a.create_line(xt,62+y,xt+220,62+y,width=1)
        Ma=series[s][8][ye][-1][0][i]
        a.create_text(xt+50,74+y,text=manufac[0][Ma][0], font='Arial 11')
        for j in range(len(manufac[0][Ma][2])):
            if manufac[0][Ma][2][j][0]==series[s][8][ye][0]:
                for h in range(1,len(manufac[0][Ma][2][j])):
                    if manufac[0][Ma][2][j][h][0]==s:
                        a.create_text(xt+130,74+y,text=manufac[0][Ma][2][j][h][3], font='Arial 11')
                        a.create_text(xt+190,74+y,text=manufac[0][Ma][2][j][h][4], font='Arial 11')
        y=y+24
    a.create_line(xt,12+y2,xt+220,12+y2,width=1)
    a.create_line(xt+100,y2+12,xt+100,62+y,width=1)
    
    a.create_line(xt,y2+12,xt,62+y,width=1)
    x=0
    #for i in range(2):
     #   x=x+90
      #  a.create_line(xt+100+x,1,xt+100+x,26+y,width=1)
        
    x=x+30
    for i in range(1):
        a.create_line(xt+130+x,y2+12,xt+130+x,62+y,width=1)
        a.create_text(xt+100+x,24+y2,text='Points', font='Arial 11')
        x=x+60
    for i in range(1):
        a.create_line(xt+130+x,y2+12,xt+130+x,62+y,width=1)
        a.create_text(xt+100+x,24+y2,text='Position', font='Arial 11')
        x=x+60
    a.create_line(xt,y2+12,xt+220,y2+12,width=1)
    a.create_line(xt,y+62,xt+220,y+62,width=1)

    y=y+32
    a.create_text(xt+50,50+y,text=(series[s][1],'Chassi'), font='Arial 11')
    y2=y+26
    for i in range(C):
        a.create_line(xt,62+y,xt+220,62+y,width=1)
        Ma=series[s][8][ye][-1][1][i]
        a.create_text(xt+50,74+y,text=manufac[1][Ma][0], font='Arial 11')
        for j in range(len(manufac[1][Ma][2])):
            if manufac[1][Ma][2][j][0]==series[s][8][ye][0]:
                for h in range(1,len(manufac[1][Ma][2][j])):
                    if manufac[1][Ma][2][j][h][0]==s:
                        a.create_text(xt+130,74+y,text=manufac[1][Ma][2][j][h][3], font='Arial 11')
                        a.create_text(xt+190,74+y,text=manufac[1][Ma][2][j][h][4], font='Arial 11')
        y=y+24
    a.create_line(xt,12+y2,xt+220,12+y2,width=1)
    a.create_line(xt+100,y2+12,xt+100,62+y,width=1)
    
    a.create_line(xt,y2+12,xt,62+y,width=1)
    x=0

    x=x+30
    for i in range(1):
        a.create_line(xt+130+x,y2+12,xt+130+x,62+y,width=1)
        a.create_text(xt+100+x,24+y2,text='Points', font='Arial 11')
        x=x+60
    for i in range(1):
        a.create_line(xt+130+x,y2+12,xt+130+x,62+y,width=1)
        a.create_text(xt+100+x,24+y2,text='Position', font='Arial 11')
        x=x+60
    a.create_line(xt,y2+12,xt+220,y2+12,width=1)
    a.create_line(xt,y+62,xt+220,y+62,width=1)

    y=y+32
    a.create_text(xt+50,50+y,text=(series[s][1],'Pneu'), font='Arial 11')
    y2=y+26
    for i in range(P):
        a.create_line(xt,62+y,xt+220,62+y,width=1)
        Ma=series[s][8][ye][-1][2][i]
        a.create_text(xt+50,74+y,text=manufac[2][Ma][0], font='Arial 11')
        for j in range(len(manufac[2][Ma][2])):
            if manufac[2][Ma][2][j][0]==series[s][8][ye][0]:
                for h in range(1,len(manufac[2][Ma][2][j])):
                    if manufac[2][Ma][2][j][h][0]==s:
                        a.create_text(xt+130,74+y,text=manufac[2][Ma][2][j][h][3], font='Arial 11')
                        a.create_text(xt+190,74+y,text=manufac[2][Ma][2][j][h][4], font='Arial 11')
        #a.create_text(xt+50,74+y,text=i, font='Arial 11')
        y=y+24
    a.create_line(xt,12+y2,xt+220,12+y2,width=1)
    a.create_line(xt+100,y2+12,xt+100,62+y,width=1)
    
    a.create_line(xt,y2+12,xt,62+y,width=1)
    x=0
    #for i in range(2):
     #   x=x+90
      #  a.create_line(xt+100+x,1,xt+100+x,26+y,width=1)
        
    x=x+30
    for i in range(1):
        a.create_line(xt+130+x,y2+12,xt+130+x,62+y,width=1)
        a.create_text(xt+100+x,24+y2,text='Points', font='Arial 11')
        x=x+60
    for i in range(1):
        a.create_line(xt+130+x,y2+12,xt+130+x,62+y,width=1)
        a.create_text(xt+100+x,24+y2,text='Position', font='Arial 11')
        x=x+60
    a.create_line(xt,y2+12,xt+220,y2+12,width=1)
    a.create_line(xt,y+62,xt+220,y+62,width=1)
    #a.create_text(xt+145,14,text='Driver 1', font='Arial 11')
    #a.create_text(xt+235,14,text='Driver 2', font='Arial 11')

    
def timy(T):
    a.create_rectangle(0,0,1512,800,fill='white')
    y=0
    for i in range(T*2):
        a.create_line(1,26+y,290,26+y,width=1)
        a.create_text(50,38+y,text=i, font='Arial 11')
        y=y+24
    a.create_line(1,26+y,290,26+y,width=1)
    a.create_line(2,0,2,26+y,width=1)
    a.create_line(1,2,290,2,width=1)
    a.create_text(50,14,text='Team', font='Arial 11')
    a.create_text(150,14,text='Driver', font='Arial 11')
    x=0
    for i in range(2):
        x=x+100
        a.create_line(x,0,x,26+y,width=1) 
    for i in range(3):
        x=x+30
        a.create_line(x,1,x,26+y,width=1)
    x=x+30
    a.create_text(215,14,text='A', font='Arial 11')
    a.create_text(245,14,text='S', font='Arial 11')
    a.create_text(275,14,text='Y', font='Arial 11')

# Preteky
#rac = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
#rx = [0,0,0,0,0,0,0,0]
#results = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
def funguj (q,w):    
    sezona(q,w)
    x=0
    for p in range(w):
        race(q*2,x)
        x=x+30
        
def race(d,xx):   
    group=d//4
    group1=d-(group*4)
    rac = [50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50]
    rx = [50,50,50,50,50,50,50,50]
    results = [50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50,50]
    for i in range (d):
        rac[i]=i+1
    for i in range (group1):
        for j in range (group+1):
            r=random.randrange(d-i)  
            rx[j]=rac[r]            
        for j in range (group):
            if rx[0] > rx[j+1] :
                rx[0] = rx[j+1]
        results[i]=rx[0]
        for j in range (d-i):
            if rac[j] == rx[0] :
                rac[j]=50
                rac.sort()
    for i in range (group1,d):
        for j in range (group):
            r=random.randrange(d-i)
            rx[j]=rac[r]
        for j in range (group-1):
            if rx[0] > rx[j+1] :
                rx[0] = rx[j+1]
        results[i]=rx[0]
        for j in range (d-i):
            if rac[j] == rx[0] :
                rac[j]=50
                rac.sort()
        if ((i-group1+1)%4) == 0 :
            group=group-1

        
    y=38
    for i in range (d):
        if results[i] == 1 :
            a.create_rectangle(190+xx,y-12,220+xx,y+12,fill='yellow')
        if results[i] == 2 :
            a.create_rectangle(190+xx,y-12,220+xx,y+12,fill='silver')
        if results[i] == 3 :
            a.create_rectangle(190+xx,y-12,220+xx,y+12,fill='brown2')
        a.create_text(205+xx,y,text=results[i], font='Arial 11')
        y=y+24
           
save='sv'
def save (sv):
    dx=[fl1,fl2,fl3]
    ss=(sv+'info.txt')
    with open (ss,'w') as f:
        f.writelines((str(startyear)+'\n'))
        f.writelines((str(year)+'\n'))
        f.writelines((str(len(newdrivers))+'\n'))
        for i in range(len(newdrivers)):
            f.writelines((str(newdrivers[i][0])+'\n'))
            f.writelines((str(newdrivers[i][1])+'\n'))
        f.writelines((str(phase)+'\n'))
        f.writelines((str(datex)+'\n'))
        f.writelines((str(adate)+'\n'))
        
        if phase==1:
            f.writelines(str(len(jd[0]))+'\n')
            for d in range(len(jd[0])):
                f.writelines((str(jd[0][d])+'\n'))
            f.writelines(str(len(jd[1]))+'\n')
            for d in range(len(jd[1])):
                f.writelines((str(jd[1][d])+'\n'))
            f.writelines(str(len(sd[0]))+'\n')
            for d in range(len(sd[0])):
                f.writelines((str(sd[0][d])+'\n'))
            f.writelines(str(len(sd[1]))+'\n')
            for d in range(len(sd[1])):
                f.writelines((str(sd[1][d])+'\n'))
    ss=(sv+'drivers.txt')
    with open (ss,'w') as f:
        f.writelines(str(len(drivers))+'\n')
        for i in range (len (drivers)):
            for j in (0,1,2,3,4,6):
                f.writelines(str(drivers[i][j])+'\n')
            if drivers[i][7]=='x':
                f.writelines('x\n')
            else:
                for j in range (7,11):
                    f.writelines(str(drivers[i][j])+'\n')
                if drivers[i][11][0]==False:
                    f.writelines('False\n')
                else:
                    for j in range(1,4):
                        f.writelines(str(drivers[i][11][j])+'\n')
            y=(len(drivers[i][14]))
            f.writelines(str(y)+'\n')
            for j in range (y):
                f.writelines(str(drivers[i][14][j][0])+'\n')
                f.writelines(str(len(drivers[i][14][j])-1)+'\n')
                for h in range (1,6):
                    f.writelines(str(drivers[i][14][j][1][h])+'\n')
                if drivers[i][14][j][1][7][0]==False:
                    f.writelines('False\n')
                else:
                    for g in range(1,4):
                        f.writelines(str(drivers[i][14][j][1][7][g])+'\n')
                for h in range (8,10):
                    f.writelines(str(drivers[i][14][j][1][h])+'\n')
                f.writelines(str(drivers[i][14][j][1][10])+'\n')
                f.writelines(str(drivers[i][14][j][1][11])+'\n')
                for h in range (drivers[i][14][j][1][10],drivers[i][14][j][1][11]+1):
                    f.writelines(str(drivers[i][14][j][1][h+11])+'\n')
            if drivers[i][15][0]=='x':
                f.writelines('x\n')
            else:
                for h in range (2):
                    f.writelines(str(drivers[i][15][h])+'\n')
                if drivers[i][15][2]==('x'):
                    f.writelines('x\n')
                else:
                    for h in range (2,4):
                        f.writelines(str(drivers[i][15][h])+'\n')
    ss=(sv+'teams.txt')
    with open (ss,'w') as f:
        f.writelines(str(len(teams))+'\n')
        for t in range(len(teams)):
            for i in range(4):
                f.writelines(str(teams[t][i])+'\n')
            f.writelines(str(len(teams[t][6]))+'\n')
            for i in range(len(teams[t][6])):
                f.writelines(str(teams[t][6][i][0])+'\n')
                if teams[t][6][i][1]==False:
                    f.writelines('x\n')
                else:
                    f.writelines(str(teams[t][6][i][1])+'\n')
                for j in range(2,14):
                    f.writelines(str(teams[t][6][i][j])+'\n')
            f.writelines(str(len(teams[t][7]))+'\n')
            for i in range(len(teams[t][7])):
                f.writelines(str(teams[t][7][i][0])+'\n')
                f.writelines(str(len(teams[t][7][i])-1)+'\n')
                for h in range(1,len(teams[t][7][i])):                
                    f.writelines(str(teams[t][7][i][h][0])+'\n')
                    if teams[t][7][i][h][1]==False:
                        f.writelines('x\n')
                    else:
                        f.writelines(str(teams[t][7][i][h][1])+'\n')
                    for j in range(2,11):
                        f.writelines(str(teams[t][7][i][h][j])+'\n')
            f.writelines(str(teams[t][9])+'\n')
    ss=(sv+'series.txt')
    with open (ss,'w') as f:
        f.writelines(str(len(series))+'\n')
        for s in range(len(series)):
            for i in range(8):
                f.writelines(str(series[s][i])+'\n')
            for i in range(len(series[s][8])):
                f.writelines(str(len(series[s][8][i])-4)+'\n')
                for h in range(1,len(series[s][8][i])-3):
                    f.writelines(str(series[s][8][i][h])+'\n')
            f.writelines(str(series[s][10])+'\n')
            for e in range(3):
                f.writelines(str(len(series[s][11][e]))+'\n')
                for i in range(len(series[s][11][e])):
                    f.writelines(str(series[s][11][e][i])+'\n')
            f.writelines(str(len(series[s][16]))+'\n')
            for i in range(len(series[s][16])):
                f.writelines(str(series[s][16][i][0])+'\n')
                f.writelines(str(series[s][16][i][1])+'\n')
    ss=(sv+'manufac.txt')
    with open (ss,'w') as f:
        for e in range(3):
            f.writelines(str(len(manufac[e]))+'\n')
        for e in range(3):
            for m in range(len(manufac[e])):
                f.writelines(str(manufac[e][m][0])+'\n')
                f.writelines(str(len(manufac[e][m][1]))+'\n')
                for i in range(len(manufac[e][m][1])):
                    for h in range(3):
                        f.writelines(str(manufac[e][m][1][i][h])+'\n')
                    f.writelines(str(manufac[e][m][1][i][4])+'\n')
                    for h in range(manufac[e][m][1][i][4]):
                        f.writelines(str(manufac[e][m][1][i][5+2*h])+'\n')
                        f.writelines(str(manufac[e][m][1][i][6+2*h])+'\n')
    ss=(sv+'points.txt')
    with open (ss,'w') as f:
        f.writelines(str(len(pointsystem))+'\n')
        for i in range(len(pointsystem)):
            f.writelines(str(len(pointsystem[i]))+'\n')
            for j in range(len(pointsystem[i])):
                f.writelines(str(pointsystem[i][j])+'\n')
def pdrivers(d):
    pickdrivers()
    a.create_rectangle(0,0,1512,800,fill='white')
    #a.create_rectangle(0,0,1512,800,fill='white')
    a.create_rectangle(10,10,210,35)
    a.create_text(110,23,text=(drivers[d][0],drivers[d][1]), font='Arial 11')
    a.create_rectangle(220,10,320,35)
    a.create_text(270,23,text=drivers[d][2], font='Arial 11')
    a.create_rectangle(330,10,380,35)
    a.create_text(355,23,text=drivers[d][3], font='Arial 11')
    y=40
    for i in range(len(drivers[d][14])):
        a.create_rectangle(10,y,60,y+22)
        a.create_text(35,y+11,text=(drivers[d][14][i][0],i+1), font='Arial 11')
        y=y+27
    
def pteams(t):
    pickteams()
    a.create_rectangle(0,0,1512,800,fill='white')
    a.create_rectangle(10,10,120,35)
    a.create_text(65,23,text=teams[t][0], font='Arial 11')
    a.create_rectangle(130,10,155,35)
    a.create_text(143,23,text=teams[t][3], font='Arial 11')
    a.create_rectangle(165,10,190,35)
    a.create_text(178,23,text=teams[t][4], font='Arial 11')
    y=0
    for i in range(len(teams[t][6])):
        if teams[t][6][i][2]<=year and teams[t][6][i][3]>=year:
            y=y+35
            a.create_rectangle(10,10+y,240,35+y)
            SS=teams[t][6][i][0]
            a.create_text(125,23+y,text=series[teams[t][6][i][0]][0], font='Arial 11')
            x=0
            f=0
            manf=['Motor','Karoseria','Pneumatiky']
            for e in range(3):
                a.create_rectangle(250+x,10,420+x,35)
                a.create_text(335+x,23,text=manf[e], font='Arial 11')
                a.create_rectangle(250+x,10+y,340+x,35+y)
                if teams[t][6][i][4+e*3]=='x':
                    #a.create_text(295+x,23+y,text='x', font='Arial 11')
                    for ff in range(1,len(teams[t][7][-1])):
                        if teams[t][7][-1][ff][0]==SS:
                            a.create_text(295+x,23+y,text=manufac[e][teams[t][7][-1][ff][2+e*3]][0], font='Arial 11', fill='Red')
                else:
                    a.create_text(295+x,23+y,text=manufac[e][teams[t][6][i][4+e*3]][0], font='Arial 11')
                a.create_rectangle(350+x,10+y,375+x,35+y)
                a.create_text(363+x,23+y,text=teams[t][6][i][5+e*3], font='Arial 11')
                a.create_rectangle(385+x,10+y,420+x,35+y)
                a.create_text(403+x,23+y,text=(teams[t][6][i][6+e*3],'M'), font='Arial 11')
                x=x+180
                f=f+teams[t][6][i][6+e*3]
            a.create_rectangle(790,10+y,815,35+y)
            a.create_text(803,23+y,text=teams[t][6][i][13], font='Arial 11')
            a.create_rectangle(825,10+y,865,35+y)
            a.create_text(845,23+y,text=(teams[t][6][i][13]*f,'M'), font='Arial 11')
            dx=[]
            for f in(1,3):
                for d in(teams[t][5][f]):
                    if drivers[d][10]==teams[t][6][i][0]:
                        dx.append(d)
            x=0
            for d in (dx):
                a.create_rectangle(875+x,10+y,985+x,35+y)
                a.create_text(930+x,23+y,text=(drivers[d][0][0],drivers[d][1]), font='Arial 11')
                x=x+120
    
    kde=['Prava','Podpisani','Hostovanie','Pozicani']
    for i in range(4):
        if i ==0:
            x=550
            if adate==0:
                yer=-1
            else:
                yer=0
            for j in range(3):
                a.create_rectangle(x,y+45,x+125,y+70)
                a.create_text(x+63,57+y,text=year+yer-j, font='Arial 11')
                x=x+140
        y=y+35
        a.create_text(65,23+y,text=kde[i], font='Arial 11')
        y=y+10
        for d in(teams[t][5][i]):
            y=y+25
            a.create_rectangle(10,10+y,120,35+y)
            a.create_text(65,23+y,text=(drivers[d][0][0],drivers[d][1]), font='Arial 11')
            a.create_rectangle(130,10+y,170,35+y)
            a.create_text(150,23+y,text=drivers[d][2], font='Arial 11')
            a.create_rectangle(180,10+y,205,35+y)
            a.create_text(193,23+y,text=drivers[d][5], font='Arial 11')
            a.create_rectangle(215,10+y,240,35+y)
            a.create_text(228,23+y,text=drivers[d][9], font='Arial 11')
            a.create_rectangle(250,10+y,280,35+y)
            if drivers[d][8]=='x':
                a.create_text(265,23+y,text=(drivers[d][14][-1][1][3],'M'), font='Arial 11',fill='red')
            else:
                a.create_text(265,23+y,text=(drivers[d][8],'M'), font='Arial 11')
            a.create_rectangle(290,10+y,340,35+y)
            if drivers[d][10]!='x':
               a.create_text(315,23+y,text=series[drivers[d][10]][1], font='Arial 11') 
            if i==3:
                a.create_rectangle(350,10+y,460,35+y)
                a.create_text(405,23+y,text=teams[drivers[d][7]][0], font='Arial 11')
                a.create_rectangle(470,10+y,495,35+y)
                a.create_text(483,23+y,text=drivers[d][11][2], font='Arial 11')
                a.create_rectangle(505,10+y,530,35+y)
                if drivers[d][11][3]==drivers[d][7]:
                    a.create_text(518,23+y,text='N', font='Arial 11')
                if drivers[d][11][3]==t:
                    a.create_text(518,23+y,text='P', font='Arial 11')
            if i==2:
                a.create_rectangle(350,10+y,460,35+y)
                a.create_text(405,23+y,text=teams[drivers[d][11][1]][0], font='Arial 11')
                a.create_rectangle(470,10+y,495,35+y)
                a.create_text(483,23+y,text=drivers[d][11][2], font='Arial 11')
                a.create_rectangle(505,10+y,530,35+y)
                if drivers[d][11][3]==t:
                    a.create_text(518,23+y,text='P', font='Arial 11')
                else:
                    a.create_text(518,23+y,text='N', font='Arial 11')
            #a.create_rectangle(x,y,x+110,y+24)

            y=y+10
            x=550
            if len(drivers[d][14])>2:
                x3=-4
            elif len(drivers[d][14])==2:
                x3=-3
            elif len(drivers[d][14])==1:
                x3=-2
            else:
                x3=-1
            for e in range(-1,x3,-1):
            
                a.create_rectangle(x,y,x+50,y+24)
                ss=drivers[d][14][e][1][5]
                a.create_text(x+25,y+12,text=series[ss][1], font='Arial 11')
                x=x+60
                a.create_rectangle(x,y,x+30,y+24)
                a.create_text(x+15,y+12,text=drivers[d][14][e][1][8], font='Arial 11')
                x=x+40
                if drivers[d][14][e][1][9]==1:
                    a.create_rectangle(x,y,x+25,y+24, fill='yellow')
                elif drivers[d][14][e][1][9]==2:
                    a.create_rectangle(x,y,x+25,y+24, fill='silver')
                elif drivers[d][14][e][1][9]==3:
                    a.create_rectangle(x,y,x+25,y+24, fill='brown2')
                else:
                    a.create_rectangle(x,y,x+25,y+24, fill='lightgreen')
                a.create_text(x+12,y+12,text=drivers[d][14][e][1][9], font='Arial 11')
                x=x+40
            #a.create_rectangle(540,10+y,600,35+y)
    
def printmanprices(s):
    a.create_rectangle(0,0,1512,800,fill='white')
    printmprice(s)
    parts=['Engine','Chassi','Pneu']
    for e in range(3):
        a.create_rectangle(20+e*500,10,46+e*500,36)
        a.create_rectangle(56+e*500,10,500+e*500,36)
        a.create_text(35+e*500,23,text='ID', font='Arial 11')
        if e!=0 :    
            a.create_text(278+e*500,23,text=parts[e], font='Arial 11')
        if e==0 :
            a.create_line(296+e*500,10,296+e*500,36)
            a.create_text(398+e*500,23,text=parts[e], font='Arial 11')
            a.create_text(158+e*500,23,text=series[s][1], font='Arial 11')
        for i in range(len(series[s][15][e])):
            m=series[s][15][e][i]
            a.create_rectangle(20+e*500,46+i*36,46+e*500,72+i*36)
            a.create_rectangle(56+e*500,46+i*36,236+e*500,72+i*36)
            a.create_rectangle(246+e*500,46+i*36,272+e*500,72+i*36)
            a.create_text(145+e*500,59+i*36,text=manufac[e][m][0], font='Arial 11')
            a.create_text(35+e*500,59+i*36,text=m, font='Arial 11')
            
            for j in range(len(manufac[e][m][1])):
                if manufac[e][m][1][j][0]==s:
                    a.create_text(260+e*500,59+i*36,text=manufac[e][m][1][j][2], font='Arial 11')

def printfm(s):
    freemarket(s)
    a.create_rectangle(0,0,1512,800,fill='white')
    a.create_rectangle(10,5,150,29)
    a.create_text(80,17,text=series[s][1], font='Arial 11')
    x=165
    for e in range(-1,-5,-1):
        a.create_rectangle(x,5,x+125,29)
        if e==-4:
            a.create_text(x+62,17,text='Prava', font='Arial 11')
        else:
            a.create_text(x+62,17,text=year+e, font='Arial 11')
        x=x+140
    x=x-5
    a.create_rectangle(x,5,x+25,29)
    a.create_text(x+13,17,text='ID', font='Arial 11')

    if len(fm)>26:
        x=925
        for e in range(-1,-5,-1):
            a.create_rectangle(x,5,x+125,29)
            if e==-4:
                a.create_text(x+62,17,text='Prava', font='Arial 11')
            else:
                a.create_text(x+62,17,text=year+e, font='Arial 11')
            x=x+140
        x=x-5
        a.create_rectangle(x,5,x+25,29)
        a.create_text(x+13,17,text='ID', font='Arial 11')
    x1=0
    x2=0
    if len(fm)>52:
        x1=int(input('From'))
        x2=int(input('To'))
    if x2==0:
        x2=len(fm)
    y=34
    for i in range(x1,x2):
        if i<26:
            x=10
        else:
            x=770
        if i==26:
            y=34
        d=fm[i][0]
        a.create_rectangle(x,y,x+110,y+24)
        a.create_text(x+55,y+12,text=(drivers[d][0][0],drivers[d][1]), font='Arial 11')
        x=x+115
        a.create_rectangle(x,y,x+25,y+24)
        
        a.create_text(x+12,y+12,text=drivers[d][5], font='Arial 11')
        x=x+40
        if len(drivers[d][14])>2:
            x3=-4
        elif len(drivers[d][14])==2:
            x3=-3
        elif len(drivers[d][14])==1:
            x3=-2
        else:
            x3=-1
        for e in range(-1,x3,-1):
            if drivers[d][14][e][0]==year+e:
                a.create_rectangle(x,y,x+50,y+24)
                ss=drivers[d][14][e][1][5]
                a.create_text(x+25,y+12,text=series[ss][1], font='Arial 11')
                x=x+60
                a.create_rectangle(x,y,x+30,y+24)
                a.create_text(x+15,y+12,text=drivers[d][14][e][1][8], font='Arial 11')
                x=x+40
                if drivers[d][14][e][1][9]==1:
                    a.create_rectangle(x,y,x+25,y+24, fill='yellow')
                elif drivers[d][14][e][1][9]==2:
                    a.create_rectangle(x,y,x+25,y+24, fill='silver')
                elif drivers[d][14][e][1][9]==3:
                    a.create_rectangle(x,y,x+25,y+24, fill='brown2')
                else:
                    a.create_rectangle(x,y,x+25,y+24, fill='lightgreen')
                #a.create_rectangle(x,y,x+25,y+24, fill='lightgreen')
                a.create_text(x+12,y+12,text=drivers[d][14][e][1][9], font='Arial 11')
                x=x+40
            else:
                x=x+140
        if x3==-3:
            x=x+140
        if x3==-2:
            x=x+280
        if fm[i][1]==1:
            a.create_rectangle(x,y,x+125,y+24)
            a.create_text(x+62,y+12,text=teams[drivers[d][6]][0], font='Arial 11')
        x=x+135
        a.create_rectangle(x,y,x+25,y+24)
        a.create_text(x+13,y+12,text=d, font='Arial 11')
        y=y+29
                    
##### Program

picknations()
natselect()
aa=0

def pt():
    pteams(0)

def pm():
    if sux<len(suciastky):
        printmanprices(suciastky[sux][0])
    
def buf1():
    global f1y
    if (datex==7 or datex==0) :
        f1y=year
    else:
        f1y=year-1
    season(0,f1y)

def b1p():
    global f1y
    if f1y<year-1 :
        f1y=f1y+1
    elif f1y==year-1 and (datex==7 or datex==0):
        f1y=f1y+1
    season(0,f1y)

def b1m():
    global f1y
    if f1y>1950 :
        f1y=f1y-1
    season(0,f1y)

def buindy():
    global indyy
    if (datex==7 or datex==0):
        indyy=year
    else:
        indyy=year-1
    season(2,indyy)

def bip():
    global indyy
    if indyy<year-1 :
        indyy=indyy+1
    elif indyy==year-1 and (datex==7 or datex==0):
        indyy=indyy+1
    season(2,indyy)

def bim():
    global indyy
    if indyy>1935 :
        indyy=indyy-1
    season(2,indyy)
    
def bufj():
    global fjy
    if (datex==7 or datex==0) :
        fjy=year
    else:
        fjy=year-1
    season(3,fjy)

def bjp():
    global fjy
    if fjy<year-1 :
        fjy=fjy+1
    elif fjy==year-1 and (datex==7 or datex==0):
        fjy=fjy+1
    season(3,fjy)

def bjm():
    global fjy
    if fjy>1932 :
        fjy=fjy-1
    season(3,fjy)

def pickbutton():
    global suf
    if len(suciastky)<1:
        suf=1
    b1=tkinter.Button(text='1', command=bu1,width=2,state='disabled')
    b1.place(x=1340,y=300)
    b2=tkinter.Button(text='2', command=bu2,width=2,state='disabled')
    b2.place(x=1370,y=300)
    b3=tkinter.Button(text='3', command=bu3,width=2,state='disabled')
    b3.place(x=1400,y=300)
    b4=tkinter.Button(text='4', command=bu4,width=2,state='disabled')
    b4.place(x=1430,y=300)
    b5=tkinter.Button(text='5', command=bu5,width=2,state='disabled')
    b5.place(x=1340,y=330)
    b6=tkinter.Button(text='6', command=bu6,width=2,state='disabled')
    b6.place(x=1370,y=330)
    b7=tkinter.Button(text='7', command=bu7,width=2,state='disabled')
    b7.place(x=1400,y=330)
    b8=tkinter.Button(text='8', command=bu8,width=2,state='disabled')
    b8.place(x=1430,y=330)
    bx=tkinter.Button(text='X', command=bjm,width=2,state='disabled')
    bx.place(x=1460,y=300)
    b0=tkinter.Button(text='0', command=bu0,width=2,state='disabled')
    b0.place(x=1460,y=330)
    if suf==3:
        b1=tkinter.Button(text='1', command=bu1,width=2,state='normal')
        b1.place(x=1340,y=300)
        b2=tkinter.Button(text='2', command=bu2,width=2,state='normal')
        b2.place(x=1370,y=300)
        b3=tkinter.Button(text='3', command=bu3,width=2,state='normal')
        b3.place(x=1400,y=300)
        b4=tkinter.Button(text='4', command=bu4,width=2,state='normal')
        b4.place(x=1430,y=300)
        b5=tkinter.Button(text='5', command=bjm,width=2,state='disabled')
        b5.place(x=1340,y=330)
        b6=tkinter.Button(text='6', command=bjm,width=2,state='disabled')
        b6.place(x=1370,y=330)
        b7=tkinter.Button(text='7', command=bjm,width=2,state='disabled')
        b7.place(x=1400,y=330)
        b8=tkinter.Button(text='8', command=bjm,width=2,state='disabled')
        b8.place(x=1430,y=330)
        bx=tkinter.Button(text='X', command=bjm,width=2,state='disabled')
        bx.place(x=1460,y=300)
        b0=tkinter.Button(text='0', command=bjm,width=2,state='disabled')
        b0.place(x=1460,y=330)
    elif suf==2:
        
        x=manmarket[suciastky[sux][0]][suciastky[sux][1]]
        for i in x :
            if i ==0:
                b0=tkinter.Button(text='0', command=bu0,width=2,state='normal')
                b0.place(x=1460,y=330)
            if i ==1:
                b1=tkinter.Button(text='1', command=bu1,width=2,state='normal')
                b1.place(x=1340,y=300)
            if i ==2:
                b2=tkinter.Button(text='2', command=bu2,width=2,state='normal')
                b2.place(x=1370,y=300)
            if i ==3:
                b3=tkinter.Button(text='3', command=bu3,width=2,state='normal')
                b3.place(x=1400,y=300)
            if i ==4:
                b4=tkinter.Button(text='4', command=bu4,width=2,state='normal')
                b4.place(x=1430,y=300)
            if i ==5:
                b5=tkinter.Button(text='5', command=bu5,width=2,state='normal')
                b5.place(x=1340,y=330)
            if i ==6:
                b6=tkinter.Button(text='6', command=bu6,width=2,state='normal')
                b6.place(x=1370,y=330)
            if i ==7:
                b7=tkinter.Button(text='7', command=bu7,width=2,state='normal')
                b7.place(x=1400,y=330)
    elif suf==1:
        bnext=tkinter.Button(text='Next', command=dalej,state='normal')
        bnext.place(x=1450,y=730)

def bu0():
    numtoman(0)        
def bu1():
    numtoman(1)
def bu2():
    numtoman(2)
def bu3():
    numtoman(3)
def bu4():
    numtoman(4)
def bu5():
    numtoman(5)
def bu6():
    numtoman(6)
def bu7():
    numtoman(7)
def bu8():
    numtoman(8)
    
def numtoman(x):
    global sux
    global suf
    suciastky[sux][suf]=x
    if suf==2:
        suf=3
    elif suf==3:
        suf=2
        sux = sux+1
        if sux == len(suciastky):
            suf=1
    pickbutton()
    
def fyear():
    
    
    
    preseason()
    for i in range(date):
        nextrace()
    newyear()
    draft()
    for i in (cteams):
        if teams[i][9]==True:
            f1manresign(i)
    for i in (cteams):
        if teams[i][9]==True:
            f1resign(i)
    for i in (cteams):
        if teams[i][9]==True:
            rfs(i)
            
def fullyear():
    newyear()
    draft()
    for i in (cteams):
        if teams[i][9]==True:
            f1manresign(i)
    for i in (cteams):
        if teams[i][9]==True:
            f1resign(i)
    for i in (cteams):
        if teams[i][9]==True:
            rfs(i)
    
    preseason()
    for i in range(date):
        nextrace()
def fm1():
    if year>1949:
        printfm(0)
    else:
        printfm(2)

def save1():
    save(g.get())
def dalej():
    global datex
    global drx
    global drivx
    global ss1
    global ss2
    if datex==100:
        loaddatabase(g.get())
        if year==1931:
            for i in range(3):
                fullyear()
        if year>1936:
            bindy=tkinter.Button(text='Indy', command=buindy,width=10,state='normal')
            bindy.place(x=1400,y=230)
            bindyplus=tkinter.Button(text='+', command=bip,width=2,state='normal')
            bindyplus.place(x=1340,y=230)
            bindyminus=tkinter.Button(text='-', command=bim,width=2,state='normal')
            bindyminus.place(x=1370,y=230)
            s(2)
        if year>1951:
            bf1=tkinter.Button(text='F1', command=buf1,width=10,state='normal')
            bf1.place(x=1400,y=200)
            bf1plus=tkinter.Button(text='+', command=b1p,width=2,state='normal')
            bf1plus.place(x=1340,y=200)
            bf1minus=tkinter.Button(text='-', command=b1m,width=2,state='normal')
            bf1minus.place(x=1370,y=200)
            s(0)
        
    if datex==0:
        newyear()
        bfj=tkinter.Button(text='FJ', command=bufj,width=10)
        bfj.place(x=1400,y=260)
        bfjplus=tkinter.Button(text='+', command=bjp,width=2,state='normal')
        bfjplus.place(x=1340,y=260)
        bfjminus=tkinter.Button(text='-', command=bjm,width=2,state='normal')
        bfjminus.place(x=1370,y=260)
        bsave=tkinter.Button(text='Save', command=save1,state='disabled')
        bsave.place(x=1400,y=730)
        datex=datex+1
    elif datex==1:
        draft()
        
        manufmarket()
        for i in (cteams):
            if teams[i][9]==True:
                f1manresign(i)
        pickbutton()
        pm()
        buni=tkinter.Button(text='Manufac', command=pm,width=10)
        buni.place(x=1400,y=130)
        if len(suciastky)>0:
            bnext=tkinter.Button(text='Next', command=dalej,state='disabled')
            bnext.place(x=1450,y=730)
        datex=datex+1
    elif datex==2:
        asdf()
        f1mant()
        buni=tkinter.Button(text='Manufac', command=pm,width=10,state='disabled')
        buni.place(x=1400,y=130)
        bufm=tkinter.Button(text='Free Market', command=fm1,width=10)
        bufm.place(x=1400,y=160)
        bteam=tkinter.Button(text='Team', command=pt,width=10)
        bteam.place(x=1400,y=100)
        drx=0
        fm1()
        pickmtdb()
        datex=datex+1
    elif datex==3:
        asdf()
        ss1=0
        ss2=0
        bufm=tkinter.Button(text='Free Market', command=fm1,width=10,state='disabled')
        bufm.place(x=1400,y=160)
        pteams(0)
        if len(teams[0][5][1])>0:
            drivx=0
            pickefs()
            bnext=tkinter.Button(text='Next', command=dalej,state='disabled')
            bnext.place(x=1450,y=730)
        
        datex=datex+1
    elif datex==4:
        asdf()
        preseason()
        datex=datex+3
    elif datex==7:
        nextrace()
        if adate==1:
            if year>1949:
                bf1=tkinter.Button(text='F1', command=buf1,width=10,state='normal')
                bf1.place(x=1400,y=200)
                bf1plus=tkinter.Button(text='+', command=b1p,width=2,state='normal')
                bf1plus.place(x=1340,y=200)
                bf1minus=tkinter.Button(text='-', command=b1m,width=2,state='normal')
                bf1minus.place(x=1370,y=200)
                s(0)
            elif year>1934:
                bindy=tkinter.Button(text='Indy', command=buindy,width=10,state='normal')
                bindy.place(x=1400,y=230)
                bindyplus=tkinter.Button(text='+', command=bip,width=2,state='normal')
                bindyplus.place(x=1340,y=230)
                bindyminus=tkinter.Button(text='-', command=bim,width=2,state='normal')
                bindyminus.place(x=1370,y=230)
                s(2)
            
        
        
        if date==adate:
            bsave=tkinter.Button(text='Save', command=save1,state='normal')
            bsave.place(x=1400,y=730)
            datex=0
            if year>2018:
                series[0][3]=series[0][3]+1
                series[2][3]=series[2][3]+1
                series[3][3]=series[3][3]+1
                series[0][8].append([year+1,'1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20',[],[],[]])
                series[2][8].append([year+1,'1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20',[],[],[]])
                series[3][8].append([year+1,'1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20',[],[],[]])


	
def s(s):
    season(s,year)

bnext=tkinter.Button(text='Next', command=dalej)
bnext.place(x=1450,y=730)

g=tkinter.Entry(width=20)
g.place(x=1350,y=760)
#img=tkinter.PhotoImage(width=152, height=152, file='logo_upjs.gif')
#a.create_image((1400, 600), image=img)
