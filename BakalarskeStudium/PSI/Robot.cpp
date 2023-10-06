//============================================================================
// Name        : scirafra.cpp
// Author      : František Sciranka
// Version     :
// Copyright   : Your copyright notice
// Description : TCP server - demo upravený na podľa potrieb testovacieho servera
//============================================================================

#include <iostream>
using namespace std;

#include <cstdlib>
#include <cstdio>
#include <sys/socket.h> // socket(), bind(), connect(), listen()
#include <unistd.h> // close(), read(), write()
#include <netinet/in.h> // struct sockaddr_in
#include <strings.h> // bzero()
#include <wait.h> // waitpid()
#include <cstring> 
#define BUFFER_SIZE 10240
#define TIMEOUT 10


int main(int argc, char **argv) {

    if(argc < 2){
        cerr << "Usage: server port" << endl;
        return -1;
    }

    // Vytvoreni koncoveho bodu spojeni
    int l = socket(AF_INET, SOCK_STREAM, 0);
    if(l < 0){
        perror("Nemohu vytvorit socket: ");
        return -1;
    }

    int port = atoi(argv[1]);
    if(port == 0){
        cerr << "Usage: server port" << endl;
        close(l);
        return -1;
    }

    struct sockaddr_in adresa;
    bzero(&adresa, sizeof(adresa));
    adresa.sin_family = AF_INET;
    adresa.sin_port = htons(port);
    adresa.sin_addr.s_addr = htonl(INADDR_ANY);

    // Prirazeni socketu k rozhranim
    if(bind(l, (struct sockaddr *) &adresa, sizeof(adresa)) < 0){
        perror("Problem s bind(): ");
        close(l);
        return -1;
    }

    // Oznacim socket jako pasivni
    if(listen(l, 10) < 0){
        perror("Problem s listen()!");
        close(l);
        return -1;
    }

    struct sockaddr_in vzdalena_adresa;
    socklen_t velikost;

    while(true){
        // Cekam na prichozi spojeni
        int c = accept(l, (struct sockaddr *) &vzdalena_adresa, &velikost);
        if(c < 0){
            perror("Problem s accept()!");
            close(l);
            return -1;
        }
        pid_t pid = fork();
        if(pid == 0){
            // Kopie hlavniho vlakna ma vlastni referenci na naslouchajici soket.
            // Podproces, ktery obsluhuje klienta, tuto referenci nepotrebuje, takze je dobre
            // tuto referenci smazat. V hlavnim vlakne samozrejme reference na naslouchajici
            // soket zustava.
            close(l);

            struct timeval timeout;
            timeout.tv_sec = TIMEOUT;
            timeout.tv_usec = 0;

            fd_set sockets;

            int retval;
            char buffer [ BUFFER_SIZE];
            char buffer2[BUFFER_SIZE];
            int know_direction = 0, moved = 0, end = 0, messages [ 1000 ], m [ 1000 ], last_message_place = 0, phase = 0, hash = 0, hash1 = 0, hash2 = 0, done = 4, direction = -1, x, y, last_x = 11111111, last_y = 11111111, is_recharging = 0;

            for ( size_t i = 0; i < 1000; i++ )
            {
                messages [ i ] = -1;
                m [ i ] = 1;
            }
            while(true){
                FD_ZERO(&sockets);
                FD_SET(c, &sockets);
                // Prvnim parametrem je cislo nejvyssiho soketu v 'sockets' zvysene o jedna.
                // (Velka jednoduchost a efektivvnost funkce je vyvazena spatnou
                // ergonomii pro uzivatele.)
                // Posledni z parametru je samotny timeout. Je to struktura typu 'struct timeval',
                // ktera umoznuje casovani s presnosti na mikrosekundy (+/-). Funkci se predava
                // odkaz na promennou a funkce ji muze modifikovat. Ve vetsine implementaci
                // odecita funkce od hodnoty timeoutu cas straveny cekanim. Podle manualu na
                // to nelze spolehat na vsech platformach a ve vsech implementacich funkce
                // select()!!!
                retval = select(c + 1, &sockets, NULL, NULL, &timeout);
                if(retval < 0){
                    perror("Chyba v select(): ");
                    close(c);
                    return -1;
                }
                if(!FD_ISSET(c, &sockets)){
                    // Zde je jasne, ze funkce select() skoncila cekani kvuli timeoutu.
                    cout << "Connection timeout!" << endl;
                    close(c);
                    return 0;
                }
                int bytesRead = recv(c, buffer, BUFFER_SIZE - 1, 0);
                if(bytesRead <= 0){
                    perror("Chyba pri cteni ze socketu: ");
                    close(c);
                    return -3;
                }
                buffer[bytesRead] = '\0';
                // Pokud prijmu "konec" ukoncim aktualni dceriny proces
                if(string("konec") == buffer){
                    break;
                }

                
                

                //premazanie ,kontrola a prepisanie bufferov
                size_t buffer_end = 0;
                for ( size_t i = 0; i < BUFFER_SIZE; i++ )
                {
                    if ( buffer [ i ] != '\0' )
                    {
                        buffer_end = i + 1;
                    }
                    if ( int ( i ) >= end )
                    {
                        buffer2 [ i ] = '\0';
                    }
                }

                if ( buffer_end == 0 )
                {
                    continue;
                }

                for ( size_t i = 0; i < buffer_end; i++ )
                {
                    buffer2 [ end ] = buffer [ i ];
                    end++;
                }
                for ( size_t i = 0; i < BUFFER_SIZE; i++ )
                {
                    buffer [ i ] = '\0';
                }
                
                //Kontrola konca rechargingu
                if ( is_recharging > 0 )
                {   
                    if ( buffer2 [ is_recharging - 12 ] == 'F' && buffer2 [ is_recharging - 11 ] == 'U' && buffer2 [ is_recharging - 10 ] == 'L' && buffer2 [ is_recharging - 9 ] == 'L' && buffer2 [ is_recharging - 8 ] == ' ' && buffer2 [ is_recharging - 7 ] == 'P' && buffer2 [ is_recharging - 6 ] == 'O' && buffer2 [ is_recharging - 5 ] == 'W' && buffer2 [ is_recharging - 4 ] == 'E' && buffer2 [ is_recharging - 3 ] == 'R' && buffer2 [ is_recharging - 2 ] == '\a' && buffer2 [ is_recharging - 1 ] == '\b' )
                    {
                        is_recharging=0;
                        timeout.tv_sec = 1;
                        //odstranenie full power z buffera 
                        int i = 0, j = 0;
                        while ( j <= end )
                        {
                            if ( buffer2 [ i ] == 'F' )
                            {
                                j=j+12;
                            }
                            cout<<buffer2[j];
                            buffer2 [ i ] = buffer2 [ j ];
                            i++;
                            j++;
                        }
                        cout<<endl;
                        end = end - 12;
                    }
                    else if ( buffer2 [ end - 2 ] == '\a' && buffer2 [ end - 1 ] == '\b' )
                    {
                        send(c, "302 LOGIC ERROR\a\b", strlen("302 LOGIC ERROR\a\b"), MSG_NOSIGNAL);
                        close (c);
                        return 0; 
                    }
                    else
                    {
                        continue;
                    }
                }
                //spracovanie prijatych sprav
                last_message_place = 0;
                int have_key = -1;
                for ( int i = 0; i < end - 1; i++ )
                {
                    if ( buffer2 [ i ] == '\a' && buffer2 [ i + 1 ] != '\b' && i > 31 )
                    {        
                        send(c, "301 SYNTAX ERROR\a\b", strlen("301 SYNTAX ERROR\a\b"), MSG_NOSIGNAL);
                        close (c);
                        return 0; 
                    }
                    else if ( buffer2 [ i ] == '\a' && buffer2 [ i + 1 ] == '\b' )
                    {
                        messages [ last_message_place ] = int ( i );
                        int message_length = messages [ last_message_place ] - messages [ last_message_place - 1 ];     
                        if ( last_message_place > 0 )
                        {     
                            //kontrola dlzky key ID
                            if ( message_length != 12 && have_key == -1 )
                            {     
                                if ( message_length != 3 )
                                {     
                                    send(c, "301 SYNTAX ERROR\a\b", strlen("301 SYNTAX ERROR\a\b"), MSG_NOSIGNAL);
                                    close (c);
                                    return 0; 
                                }
                                have_key = last_message_place;
                            }
                            else
                            {   //kontrola prijatia sprav recharge a full power
                              /*  if (buffer2[i-10]=='F' && buffer2[i-9]=='U' && buffer2[i-8]=='L' && buffer2[i-7]=='L' && buffer2[i-6]==' ' && buffer2[i-5]=='P' && buffer2[i-4]=='O' && buffer2[i-3]=='W' && buffer2[i-2]=='E' && buffer2[i-1]=='R' )
                                {
                                    end = end - 12;
                                    messages [ last_message_place ] = -1;
                                }
                                else */
                                if (buffer2[i-10]=='R' && buffer2[i-9]=='E' && buffer2[i-8]=='C' && buffer2[i-7]=='H' && buffer2[i-6]=='A' && buffer2[i-5]=='R' && buffer2[i-4]=='G' && buffer2[i-3]=='I' && buffer2[i-2]=='N' && buffer2[i-1]=='G' )
                                {
                                    end = end - 12;
                                    is_recharging = i+2;
                                    timeout.tv_sec = 5;
                                    messages [ last_message_place ] = -1;
                                } 
                            }
                        }
                        else
                        {   
                            //kontrola dlzky login
                            if ( message_length > 18 )
                            {
                                send(c, "301 SYNTAX ERROR\a\b", strlen("301 SYNTAX ERROR\a\b"), MSG_NOSIGNAL);
                                close (c);
                                return 0; 
                            }
                        } 
                        last_message_place++;
                    }
                }
                if ( is_recharging > 0 )
                {
                    continue;
                }
                //kontrola dlzky login
                if (end>19 && messages[0]==-1)
                {
                    send(c, "301 SYNTAX ERROR\a\b", strlen("301 SYNTAX ERROR\a\b"), MSG_NOSIGNAL);
                    close (c);
                    return 0; 
                } 
                //spracovanie login
                if ( messages [ 0 ] != -1 && m [ 0 ] && phase == 0 )
                {
                    hash = 0;
                    for ( int i = 0; i < messages [ 0 ]; i++ )
                    {
                        hash = hash + int ( buffer2 [ i ] );
                    }
                    hash = ( hash * 1000 ) % 65536;
                    send(c, "107 KEY REQUEST\a\b", strlen("107 KEY REQUEST\a\b"), MSG_NOSIGNAL);
                    timeout.tv_sec = 1;
                    m [ 0 ] = 0;
                    phase = 1;
                }
                //spracovanie Key ID a vytvorenie hash
                if ( messages [ 1 ] != -1 && m [ 1 ] && phase == 1 )
                {
                    if ( buffer2 [ messages [ 1 ] -1 ] == '0' )
                    {
                        hash1 = ( hash + 23019 ) % 65536;
                        hash2 = ( hash + 32037 ) % 65536;
                    }
                    else if ( buffer2 [ messages [ 1 ] -1 ] == '1' )
                    {
                        hash1 = ( hash + 32037 ) % 65536;
                        hash2 = ( hash + 29295 ) % 65536;
                    }
                    else if ( buffer2 [ messages [ 1 ] -1 ] == '2' )
                    {
                        hash1 = ( hash + 18789 ) % 65536;
                        hash2 = ( hash + 13603 ) % 65536;
                    }
                    else if ( buffer2 [ messages [ 1 ] -1 ] == '3' )
                    {
                        hash1 = ( hash + 16443 ) % 65536;
                        hash2 = ( hash + 29533 ) % 65536;
                    }
                    else if ( buffer2 [ messages [ 1 ] -1 ] == '4' )
                    {
                        hash1 = ( hash + 18189 ) % 65536;
                        hash2 = ( hash + 21952 ) % 65536;
                    }
                    else 
                    {
                        send(c, "303 KEY OUT OF RANGE\a\b", strlen("303 KEY OUT OF RANGE\a\b"), MSG_NOSIGNAL);
                        close (c);
                        return 0; 
                    }
                    string strhash = to_string ( hash1 ) + "\a\b";
                    const char* tmpstring = strhash . c_str ();
                    send(c, tmpstring, strlen(tmpstring), MSG_NOSIGNAL);
                    timeout.tv_sec = 1;
                    m [ 1 ] = 0;
                    phase = 2;
                }
                //kontrola hash a prvy pohyb
                if ( messages [ 2 ] != -1 && m [ 2 ] && phase == 2 )
                {
                    string a = to_string ( hash2 );
                    int w = 1;
                    for ( size_t i = 0; i < a . length (); i++ )
                    {
                        if ( a [ i ] != buffer2 [ messages [ 1 ] + 2 + i ] )
                        {
                            w = 0;
                            break;
                        }
                    }
                    if ( w )
                    {
                        if ( buffer2 [ messages [ 1 ] + a . length () + 2 ] == '\a' && buffer2 [ messages [ 1 ] + a . length () + 3 ] == '\b' )
                        {
                            send(c, "200 OK\a\b", strlen("200 OK\a\b"), MSG_NOSIGNAL);
                            timeout.tv_sec = 1;
                        }
                        else
                        {
                            send(c, "301 SYNTAX ERROR\a\b", strlen("301 SYNTAX ERROR\a\b"), MSG_NOSIGNAL);
                            close (c);
                            return 0; 
                        }
                    }
                    else
                    {
                        send(c, "300 LOGIN FAILED\a\b", strlen("300 LOGIN FAILED\a\b"), MSG_NOSIGNAL);
                        close (c);
                        return 0;
                    }
                    send(c, "102 MOVE\a\b", strlen("102 MOVE\a\b"), MSG_NOSIGNAL);
                    timeout.tv_sec = 1;
                    moved = 1;
                    m [ 2 ] = 0;
                    phase = 3;
                }
                //kontrola dlzky vyzdvyhnuteho odkazu/logout
                else if ( phase == 4 ) 
                { 
                    if ( ( end - messages [ last_message_place -1 ] ) > 101 )
                    {
                        send(c, "301 SYNTAX ERROR\a\b", strlen("301 SYNTAX ERROR\a\b"), MSG_NOSIGNAL);
                        close(c);
                        return 0;
                    }
                    if ( buffer2 [ end - 2 ] == '\a' && buffer2 [ end - 1 ] == '\b' )
                    {
                        send(c, "106 LOGOUT\a\b", strlen("106 LOGOUT\a\b"), MSG_NOSIGNAL);
                        close(c);
                        return 0;
                    }
                }
                //Spracovanie pohybu
                if ( m [ 0 ] == 0 && m [ 1 ] == 0 && m [ 2 ] == 0 && messages [ done - 1 ] != -1 && last_message_place > 3 && phase == 3 )
                {
                    x = 0, y = 0;
                    int i = 0, krat = 1;
                    //extrakcia y
                    while ( buffer2 [ messages [ last_message_place -1 ] - 1 - i ] != ' ' && i < 10 )
                    {
                        if ( buffer2 [ messages [ last_message_place -1 ] - 1 - i ] == '-' )
                        {
                            y = y * ( 0 -1 );
                            i++;
                        }
                        else if ( buffer2 [ messages [ last_message_place -1 ] -1 - i ] == '.' )
                        {
                            send(c, "301 SYNTAX ERROR\a\b", strlen("301 SYNTAX ERROR\a\b"), MSG_NOSIGNAL);
                            close (c);
                            return 0; 
                        }
                        else
                        {
                            y = y + ( buffer2 [ messages [ last_message_place -1 ] -1 - i ] - '0' ) * krat;
                            krat = krat * 10;
                            i++;
                        }
                    }
                    //ak cyklus neprebehol ani raz tak chyba
                    if ( krat == 1 )
                    {
                        send(c, "301 SYNTAX ERROR\a\b", strlen("301 SYNTAX ERROR\a\b"), MSG_NOSIGNAL);
                        close (c);
                        return 0; 
                    }
                    krat = 1;
                    //extrakcia x
                    while ( buffer2 [ messages [ last_message_place -1 ] -2 - i ] != ' ' && i < 20 )
                    {
                        if ( buffer2 [ messages [ last_message_place -1 ] -2 - i ] == '-' )
                        {
                            x = x * ( 0 - 1 );
                            i++;
                        }
                        else if ( buffer2 [ messages [ last_message_place -1 ] -1 - i ] == '.' )
                        {
                            send(c, "301 SYNTAX ERROR\a\b", strlen("301 SYNTAX ERROR\a\b"), MSG_NOSIGNAL);
                            close (c);
                            return 0; 
                        }
                        else
                        {
                            x = x + ( buffer2 [ messages [ last_message_place -1 ] -2 - i ] - '0' ) * krat;
                            krat = krat * 10;
                            i++;
                        }
                    }
                    //ak cyklus neprebehol ani raz tak chyba
                    if ( krat == 1 )
                    {
                        send(c, "301 SYNTAX ERROR\a\b", strlen("301 SYNTAX ERROR\a\b"), MSG_NOSIGNAL);
                        close (c);
                        return 0; 
                    }
                    //premazanie bufferu prijmanych sprav
                    end = messages [ 2 ] + 2;
                    for ( int i = 3; i < last_message_place; i++ )
                    {
                        messages [ i ] = -1;
                    }
                    done = 3;
                    last_message_place = 3;
                    //vyzdvyhnutie spravy
                    if ( x == 0 && y == 0 )
                    {
                        send(c, "105 GET MESSAGE\a\b", strlen("105 GET MESSAGE\a\b"), MSG_NOSIGNAL);
                        timeout.tv_sec = 1;
                        phase = 4;
                    }
                    //ak narazil do prekazky
                    else if ( last_x == x && last_y == y && moved )
                    {
                        if ( direction == -1 )
                        {
                            send(c, "104 TURN RIGHT\a\b", strlen("104 TURN RIGHT\a\b"), MSG_NOSIGNAL);
                            send(c, "102 MOVE\a\b", strlen("102 MOVE\a\b"), MSG_NOSIGNAL);
                            timeout.tv_sec = 1;
                            done = done + 2;
                            moved = 1;
                        }
                        
                        else if ( ( direction == 1 && y < 0 ) || ( direction == 2 && x < 0 ) || ( direction == 3 && y > 0 ) || ( direction == 0 && x > 0 ) )
                        {
                            send(c, "103 TURN LEFT\a\b", strlen("103 TURN LEFT\a\b"), MSG_NOSIGNAL);
                            send(c, "102 MOVE\a\b", strlen("102 MOVE\a\b"), MSG_NOSIGNAL);
                            send(c, "104 TURN RIGHT\a\b", strlen("104 TURN RIGHT\a\b"), MSG_NOSIGNAL);
                            timeout.tv_sec = 1;
                            done = done + 3;
                            moved = 1;
                            know_direction = 1;
                        }
                        else if ( ( direction == 1 && y > 0 ) || ( direction == 2 && x > 0 ) || ( direction == 3 && y < 0 ) || ( direction == 0 && x < 0 ) )
                        {
                            send(c, "104 TURN RIGHT\a\b", strlen("104 TURN RIGHT\a\b"), MSG_NOSIGNAL);
                            send(c, "102 MOVE\a\b", strlen("102 MOVE\a\b"), MSG_NOSIGNAL);
                            send(c, "103 TURN LEFT\a\b", strlen("103 TURN LEFT\a\b"), MSG_NOSIGNAL);
                            timeout.tv_sec = 1;
                            done = done + 3;
                            moved = 1;
                            know_direction = 1;
                        }
                        else if ( ( direction == 1 && x < -1 ) || ( direction == 2 && y > 1 ) || ( direction == 3 && x > 1 ) || ( direction == 0 && y < -1 ) )
                        {
                            send(c, "104 TURN RIGHT\a\b", strlen("104 TURN RIGHT\a\b"), MSG_NOSIGNAL);
                            send(c, "102 MOVE\a\b", strlen("102 MOVE\a\b"), MSG_NOSIGNAL);
                            send(c, "103 TURN LEFT\a\b", strlen("103 TURN LEFT\a\b"), MSG_NOSIGNAL);
                            send(c, "102 MOVE\a\b", strlen("102 MOVE\a\b"), MSG_NOSIGNAL);
                            send(c, "102 MOVE\a\b", strlen("102 MOVE\a\b"), MSG_NOSIGNAL);
                            send(c, "103 TURN LEFT\a\b", strlen("103 TURN LEFT\a\b"), MSG_NOSIGNAL);
                            send(c, "102 MOVE\a\b", strlen("102 MOVE\a\b"), MSG_NOSIGNAL);
                            send(c, "104 TURN RIGHT\a\b", strlen("104 TURN RIGHT\a\b"), MSG_NOSIGNAL);
                            timeout.tv_sec = 1;
                            done = done + 8;
                            moved = 1;
                            know_direction = 1;
                        }
                    }
                    //ak uz sa robot hybal aspon 2 krat, vypocet smeru/ pohyb spravnym smerom
                    else if ( last_x < 10000000 && last_y < 10000000 )
                    {
                        if ( last_x < x && know_direction == 0 )
                        {
                            direction = 1;
                        }
                        else if ( last_x > x && know_direction == 0 ) 
                        {
                            direction = 3;
                        }
                        else if ( last_y < y && know_direction == 0 ) 
                        {
                            direction = 0;
                        }
                        else if ( last_y > y && know_direction == 0 ) 
                        {
                            direction = 2;
                        }
                        if ( x < 0 && direction != 1 )
                        {
                            send(c, "104 TURN RIGHT\a\b", strlen("104 TURN RIGHT\a\b"), MSG_NOSIGNAL);
                            timeout.tv_sec = 1;
                            done++;
                            direction++;
                            if ( direction == 4 )
                            {
                                direction = 0;
                            }
                            moved = 0;
                            know_direction = 1;
                        }
                        else if ( x < 0 && direction == 1 )
                        {
                            send(c, "102 MOVE\a\b", strlen("102 MOVE\a\b"), MSG_NOSIGNAL);
                            timeout.tv_sec = 1;
                            done++;
                            moved = 1;
                            know_direction = 0;
                        }
                        else if ( x > 0 && direction != 3 )
                        {
                            send(c, "104 TURN RIGHT\a\b", strlen("104 TURN RIGHT\a\b"), MSG_NOSIGNAL);
                            timeout.tv_sec = 1;
                            done++;
                            direction++;
                            if ( direction == 4 ) 
                            {
                                direction = 0;
                            }
                            moved = 0;
                            know_direction = 1;
                        }
                        else if ( x > 0 && direction == 3 )
                        {
                            send(c, "102 MOVE\a\b", strlen("102 MOVE\a\b"), MSG_NOSIGNAL);
                            timeout.tv_sec = 1;
                            done++;
                            moved = 1;
                            know_direction = 0;
                        }
                        else if ( y > 0 && direction != 2 )
                        {
                            send(c, "104 TURN RIGHT\a\b", strlen("104 TURN RIGHT\a\b"), MSG_NOSIGNAL);
                            timeout.tv_sec = 1;
                            done++;
                            direction++;
                            if ( direction == 4 )
                            {
                                direction = 0;
                            }
                            moved = 0;
                            know_direction = 1;
                        }
                        else if ( y > 0 && direction == 2 )
                        {
                            send(c, "102 MOVE\a\b", strlen("102 MOVE\a\b"), MSG_NOSIGNAL);
                            timeout.tv_sec = 1;
                            done++;
                            moved = 1;
                            know_direction = 0;
                        }
                        else if ( y < 0 && direction != 0 )
                        {
                            send(c, "104 TURN RIGHT\a\b", strlen("104 TURN RIGHT\a\b"), MSG_NOSIGNAL);
                            timeout.tv_sec = 1;
                            done++;
                            direction++;
                            if ( direction == 4 ) 
                            {
                                direction = 0;
                            }
                            moved = 0;
                            know_direction = 1;
                        }
                        else if ( y < 0 && direction == 0 )
                        {
                            send(c, "102 MOVE\a\b", strlen("102 MOVE\a\b"), MSG_NOSIGNAL);
                            timeout.tv_sec = 1;
                            done++;
                            know_direction = 0;
                            moved = 1;
                        }
                    }
                    else
                    {
                        send(c, "102 MOVE\a\b", strlen("102 MOVE\a\b"), MSG_NOSIGNAL);
                        timeout.tv_sec = 1;
                        done++;
                        moved = 1;
                    }
                    last_x = x;
                    last_y = y;
                }
                timeout.tv_sec = 1;
            }
            close(c);
            return 0;
        }

        // Aby nam nezustavaly v systemu zombie procesy po kazdem obslouzeneme klientovi,
        // je nutne otestovat, zda se uz nejaky podproces ukoncil.
        // Prvni argument rika, cekej na jakykoliv proces potomka, treti argument zajisti,
        // ze je funkce neblokujici (standardne blokujici je, coz ted opravdu nechceme).
        int status = 0;
        waitpid(0, &status, WNOHANG);

        close(c); // Nove vytvoreny socket je nutne zavrit v hlavnim procesu, protoze by na nem v systemu
        // zustala reference a jeho zavreni v novem procesu by nemelo zadny efekt.
    }

    close(l);
    return 0;
}
