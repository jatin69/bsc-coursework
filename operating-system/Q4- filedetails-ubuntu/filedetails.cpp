#include <iostream>
using namespace std;

#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    struct stat buffer;
    time_t atime;
    time_t modtime;
    int size, i;
    int status;
    if(argc<2){
        cout<<"Filename is needed";
    }
    for(i=1;i<argc;i++){
        status=stat(argv[i],&buffer);
        cout<<"\nChecking status for                : "<<argv[i]<<"\n";
        if(status<0)
        {
        cout<<"\n\nError in obtaining stats !! ";    
        }
        else if(status==0)
        {
            size= buffer.st_size;
            cout<<"\nSize of file in bytes is           : "<<size;
            
            atime=buffer.st_atime;
            modtime=buffer.st_mtime;
            
            char buff[20];
            struct tm * timeinfo;
            
            cout<<"\nLast access time is                : ";    //<<atime;
            
            timeinfo = localtime (&atime);
            strftime(buff, sizeof(buff), "%b %d %H:%M", timeinfo);
            cout<<buff;

            cout<<"\nLast modify time is                : ";    //<<modtime;
            timeinfo = localtime (&modtime);
            strftime(buff, sizeof(buff), "%b %d %H:%M", timeinfo);
            cout<<buff;

            cout<<"\n\nFile permissions are as follows    : ";
            
            cout<<(S_ISDIR(buffer.st_mode)?"d":"-");
            
            cout<<(buffer.st_mode & S_IRUSR?"r":"-");
            cout<<(buffer.st_mode & S_IWUSR?"w":"-");
            cout<<(buffer.st_mode & S_IXUSR?"x":"-");
            
            cout<<(buffer.st_mode & S_IRGRP?"r":"-");
            cout<<(buffer.st_mode & S_IWGRP?"w":"-");
            cout<<(buffer.st_mode & S_IXGRP?"x":"-");
            
            cout<<(buffer.st_mode & S_IROTH?"r":"-");
            cout<<(buffer.st_mode & S_IWOTH?"w":"-");
            cout<<(buffer.st_mode & S_IXOTH?"x":"-");

        }
        
    }
    cout<<"\n\n";
}