//#define DEBUG (D_SOCKET | D_SOCKET_BUFFER)
//#define DEBUG (D_SOCKET_BUFFER | D_PARSER)
//#define DEBUG D_ALL
#define DEBUG 0

#define CODE_NAME "Rhapsody IRC"
#define CODE_VERSION PROGRAM_VERSION
#define CODE_STATE "Beta"
#define CODE_BUILD ""
#define CODE_COPYRIGHT "2004"
#define CODE_DEVELOPER "Adrian Gonera"
#define CODE_ID CODE_NAME" Version "CODE_VERSION" "CODE_STATE

#define DEFAULT_CONFIG_FILE ".rhapsodyrc"
#define DEFAULT_NICKNAME "unnamed"
#define DEFAULT_ALTNICKNAME "_unnamed_"
#define DEFAULT_HOSTNAME "localhost"
#define DEFAULT_DOMAIN "localdomain"
#define DEFAULT_USERDESC "me"
#define DEFAULT_DCCHOSTNAME "localhost"
#define DEFAULT_DCCSTARTPORT 24000
#define DEFAULT_DCCENDPORT 24010
#define DEFAULT_DCCBLOCKSIZE 1024
#define DEFAULT_HOMEPATH "."
#define DEFAULT_AUTOSAVE 1
#define DEFAULT_CTCPREPLY 1
#define DEFAULT_CTCPTHROTTLE 20
#define DEFAULT_CTCPUSERINFO "No user information has been entered."
#define DEFAULT_CTCPFINGER "No user information has been entered"
#define DEFAULT_CTCPVERSION CODE_ID
#define DEFAULT_CTCPCLIENTINFO "The following CTCP commands are supported: CLIENTINFO VERSION FINGER USERINFO SOURCE TIME ERROR PING DCC"
#define DEFAULT_CTCPSOURCE "Source is available at http://rhapsody.sourceforge.net"

#define D_SOCKET 0x01
#define D_SOCKET_BUFFER 0x02
#define D_STDIN 0x10
#define D_PARSER 0x20
#define D_MEM 0x40
#define D_ALL 0xffffffff

#define NCURSES
#define RESIZE_CAPABLE

#define MAXDATASIZE 1024
#define MAXDCCPACKET 4096
#define BUFFERLINES 1000
#define LISTLINES 1000
#define CONNECTTIMEOUT 10
#define TRANSFERTIMEOUT 500

#define MINWINDOWWIDTH 80
#define MINWINDOWHEIGHT 24
#define MINWINDOWWIDTHSTR "MINWINDOWWIDTH"
#define MINWINDOWHEIGHTSTR "MINWINDOWHEIGHT"

