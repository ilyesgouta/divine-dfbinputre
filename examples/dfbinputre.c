// DFbInputRe, a tool for redirecting the local mouse and keyboard input
// to a remote target over the network using UDP datagrams.
//
// Copyright (C) 2012, Ilyes Gouta, ilyes.gouta@gmail.com
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <divine.h>

#include "dfbinputre.h"

static int     fd;
static DiVine *divine;

void sig_term(int sig)
{
     if (divine)
          divine_close( divine );
     divine = NULL;

     close( fd );
}

int
main( int argc, char *argv[] )
{
     struct sockaddr_in addr_in;
     DFbInputPacket     packet;

     struct sigaction   act;

     /* open the connection to the input driver */
     divine = divine_open( "/tmp/divine" );
     if (!divine)
          return -1;

     fd = socket( AF_INET, SOCK_DGRAM, 0 );

     if (fd < 0) {
          perror("failed creating socket");
          return -1;
     }

     memset( &addr_in, 0, sizeof( addr_in ) );

     addr_in.sin_family = AF_INET;
     addr_in.sin_port = htons(5556);
     addr_in.sin_addr.s_addr = INADDR_ANY;

     if (bind( fd, &addr_in, sizeof( addr_in ) ) < 0) {
          perror("couldn't bind socket");
          return -1;
     }

     sigaction(SIGTERM, NULL, &act);
     act.sa_handler = sig_term;
     sigaction(SIGTERM, &act, NULL);

     sigaction(SIGINT, NULL, &act);
     act.sa_handler = sig_term;
     sigaction(SIGINT, &act, NULL);

     while (divine) {
          unsigned char key;

          unsigned int addrlen = sizeof( addr_in );

          int len = recvfrom( fd, &packet, sizeof( packet ), 0,
                              (struct sockaddr*)&addr_in, &addrlen );

          if (!divine)
               break;

          if (len < sizeof( packet ))
               continue;

          if (packet.magic != MAGIC)
               continue;

          if (packet.type != DFBINPUT_MOUSE_MOTION
              && packet.type != DFBINPUT_MOUSE_CLICK
              && packet.type != DFBINPUT_MOUSE_DBLCLICK
              && packet.type != DFBINPUT_KEYPRESS)
               continue;

          switch (packet.type) {
          case DFBINPUT_MOUSE_MOTION:
               divine_send_motion_absolute( divine,
                                            packet.cursor[0],
                                            packet.cursor[1] );
               break;
          case DFBINPUT_MOUSE_CLICK:
               divine_send_button_press( divine,
                                         packet.button == 1 ? DIBI_LEFT :
                                         (packet.button == 2 ? DIBI_RIGHT : 0) );
               divine_send_button_release( divine,
                                           packet.button == 1 ? DIBI_LEFT :
                                           (packet.button == 2 ? DIBI_RIGHT : 0) );
               break;
          case DFBINPUT_MOUSE_DBLCLICK:
               break;
          case DFBINPUT_KEYPRESS:
               key = packet.keyascii;
               divine_send_vt102( divine, 1, (char*)&key );
               break;
          default:
               break;
          }
     }

     printf("exiting.\n");
     return 0;
}
