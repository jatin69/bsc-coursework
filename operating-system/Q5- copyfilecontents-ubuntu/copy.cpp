#include<iostream>
#include<cstdlib>
#include<fcntl.h>
#include<unistd.h>

using namespace std;

int main(int argc, char* argv[])
{
        /* Program needs two arguments. SOURCE and DESTINATION file names*/
	if(argc!=3)
	{
		cout << "Invalid no' of arguments !! Supply SOURCE and DESTINATION file names.\n";
		exit(1);
	}

	/* Open SOURCE file in Read only mode. */
	int file_descriptor1 = open(argv[1], O_RDONLY);
	if(file_descriptor1 == -1)
	{
		cout << "Error in opening file. Please try again\n";
		exit(1);
	}

	/* Open DESTINATION file in WRITE only mode. If not exists, create the file with read-write permissions.*/
	int file_descriptor2 = open(argv[2], O_WRONLY|O_CREAT,00600);
        if(file_descriptor2 == -1)
	{
		cout << "Error in creating the file.\n";
		exit(1);
	}

	
	char buf[1024];
	int count;
        
        /* 'read' takes 3 parameters: file_descriptor, buffer, count-> how many bytes to read
           returns the number of bytes read & -1 if error occurs. */
	while(count = read(file_descriptor1, buf, sizeof(buf)))
	{
               if(count == -1)
		{
			cout << "Reading from file failed\n";
			exit(1);
		}
		else
                {       /* 'write' takes 3 parameters: file_descriptor, buffer, count-> how many bytes to write
                          returns the number of bytes written to file & -1 if error occurs. */
                        if(write(file_descriptor2, buf, count)==-1)
			{
				cout << "Writing to the file failed\n";
				exit(1);
			}
		}
	}

	cout <<"\nCopying contents to the file was successful!!\n\n";

        /* closing the file file_descriptors */
	close(file_descriptor1);
	close(file_descriptor2);

return 0;
}
