#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "defines.h"
#include "network.h"
#include "log.h"
//#include "common.h"

// ascii socket send and receive functions

int send_all(int sockfd, char *buffer, int len){
	int numbytes;

	#if (DEBUG & D_SOCKET_BUFFER) 
		plog ("%s\n", buffer);
	#endif

	numbytes=send(sockfd, buffer, len, 0);
	if (numbytes == -1) {
		#if (DEBUG & D_SOCKET)
			plog("Error sending data in send_all()");
		#endif
		return(0);
	}
	return(1);
}

int recv_all(int sockfd, char *buffer, int len){
	int numbytes;
	char temp;
	int i;

	i=0;
	while(i<len-1){
		numbytes=recv(sockfd, &temp, 1, 0);
		if (numbytes  == -1) {
	        	if (errno==EAGAIN){
				#if (DEBUG & D_SOCKET) 
					plog ("Read would block in recv_all()");
				#endif
				return(0);
			}
			else {			
				#if (DEBUG & D_SOCKET)
					plog ("Error receiving data in recv_all()");
				#endif
				return(-1);
			}
		}	
		// if EOF encountered
		else if (numbytes == 0){
			#if (DEBUG & D_SOCKET)
				plog("Connection closed by remote host in recv_all()");
			#endif
			return(-1);
		}		
		else if (temp=='\r');
		else if (temp=='\n') break;
		else{
			buffer[i] = temp;
			i++;
		}
	}
	buffer[i]=0;
	#if (DEBUG & D_SOCKET_BUFFER)
		plog ("%s\n", buffer);
	#endif
	return(i);
}

int recv_line(int sockfd, char *buffer, int *currpos, int maxlen){
	int numbytes;
	char temp;
	int pos;

	/* get the incoming data until newline is received  */
	/* if no new bytes arrive, save existing buffer and */
	/* return later to complete the line                */

	// vprint_all("i = %d ; buf = %s\n", *currpos, buffer);
	
	pos = *currpos;

	while(pos < maxlen - 1){
		numbytes = recv(sockfd, &temp, 1, 0);
		if (numbytes  == -1) {
	        	if (errno == EAGAIN){
				#if (DEBUG & D_SOCKET) 
					plog ("Read would block in recv_line()");
				#endif
				*currpos = pos;
				return(0);
			}
			else {			
				#if (DEBUG & D_SOCKET)
					plog ("Error receiving data in recv_line()");
				#endif
				*currpos = 0;
				return(-1);
			}
		}	
		// if EOF encountered
		else if (numbytes == 0){
			#if (DEBUG & D_SOCKET)
				plog("Connection closed by remote host in recv_line()");
			#endif
			return(-1);
		}		
		else if (temp == '\r');

		/* return the number of bytes and reset the buffer pointer to 0 */
		else if (temp == '\n'){
			buffer[pos] = 0;
			*currpos = 0;
			return(pos);
		}
		else{
			buffer[pos++] = temp;
		}
	}
	
	#if (DEBUG & D_SOCKET_BUFFER)
		plog ("%s\n", buffer);
	#endif
	*currpos = 0;
	return(pos);
}

// binary versions

int send_ball(int sockfd, char *buffer, int len){
	int numbytes;

	#if (DEBUG & D_SOCKET_BUFFER)
		plog ("%s", buffer);
	#endif

	numbytes=send(sockfd, buffer, len, 0);
	if (numbytes == -1) {
		#if (DEBUG & D_SOCKET)
			plog("Error sending data in send_ball()\n");
		#endif
		return(0);
	}
	return(1);
}

int recv_ball(int sockfd, char *buffer, int len){
	int numbytes;
	char temp[MAXDATASIZE];
	int i;

	numbytes = recv(sockfd, &temp, len, 0);
	if (numbytes  == -1){ 
		if (errno==EAGAIN){
			#if (DEBUG & D_SOCKET) 
				plog ("Read would block in recv_all()");
			#endif
			return(0);
		}
		else {			
			#if (DEBUG & D_SOCKET)
				plog ("Error receiving data in recv_all()");
			#endif
			return(-1);
		}
	}
	// if EOF encountered
	else if (numbytes == 0){
		return(-1);
	}		
	else{
		memcpy(buffer, temp, numbytes); 
	}

	#if (DEBUG & D_SOCKET_BUFFER)
		plog("%s\n", buffer);
	#endif
	return(numbytes);
}

